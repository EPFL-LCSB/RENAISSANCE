# --------------------------------------------------------------------------
# File: callback.py
# ---------------------------------------------------------------------------
# Licensed Materials - Property of IBM
# 5725-A06 5725-A29 5724-Y48 5724-Y49 5724-Y54 5724-Y55 5655-Y21
# Copyright IBM Corporation 2008, 2017. All Rights Reserved.
#
# US Government Users Restricted Rights - Use, duplication or
# disclosure restricted by GSA ADP Schedule Contract with
# IBM Corp.
# --------------------------------------------------------------------------
"""Callback classes for the CPLEX Python API.

This module defines a hierarchy of classes, many of which can be
subclassed to define alternative behavior for the algorithms in 
CPLEX.  The methods provided by the classes allow you to query
information about the optimization in progress and to control the
optimization algorithm.

To use a subclassable callback class, define a subclass of it that
defines a __call__ method.  Then pass that class name to the
register_callback method of an instance of the Cplex class.  The Cplex
class will instantiate the class and return the instance of the class
to you.  If you wish to associate additional data with your callback
class, you may do so after it has been registered with the Cplex
object.

See the following examples for more information.

- admipex1.py
- admipex2.py
- admipex3.py
- admipex4.py
- admipex6.py
- lpex4.py
- mipex4.py

Note
  If you operate the CPLEX Python API in parallel mode with
  callbacks registered, there will be a single instance of each of your
  callback classes shared among all threads.
"""


import math
import weakref

from . import _internal
from ._internal import _procedural as _proc
from ._internal._aux_functions import (apply_freeform_two_args,
                                       apply_freeform_one_arg,
                                       deprecated_class)
from ._internal._matrices import SparsePair, SparseTriple, _HBMatrix
from .exceptions import (CplexError, CplexSolverError,
                         WrongNumberOfArgumentsError)

from . import six
from .six.moves import map
from .six.moves import zip

# Dynamically import based on C extension name.
exec("from ._internal." + _internal._pycplex.ext_name + " import fast_getcallbackinfo")
exec("from ._internal." + _internal._pycplex.ext_name + " import cb_getcolindex")
exec("from ._internal." + _internal._pycplex.ext_name + " import cb_getrowindex")
exec("from ._internal." + _internal._pycplex.ext_name + " import cb_getqconstrindex")
exec("from ._internal." + _internal._pycplex.ext_name + " import cb_getsosindex")
exec("from ._internal." + _internal._pycplex.ext_name + " import cb_getnumcols")
exec("from ._internal." + _internal._pycplex.ext_name + " import cb_getnumrows")
exec("from ._internal." + _internal._pycplex.ext_name + " import cb_getnumqconstrs")
exec("from ._internal." + _internal._pycplex.ext_name + " import cb_getnumsos")
exec("from ._internal." + _internal._pycplex.ext_name + " import cb_gettime")
exec("from ._internal." + _internal._pycplex.ext_name + " import cb_getdettime")
exec("from ._internal." + _internal._pycplex.ext_name + " import cb_getstat")
exec("from ._internal." + _internal._pycplex.ext_name + " import cb_solninfo")
exec("from ._internal." + _internal._pycplex.ext_name + " import cb_primopt")
exec("from ._internal." + _internal._pycplex.ext_name + " import cb_dualopt")
exec("from ._internal." + _internal._pycplex.ext_name + " import cb_hybbaropt")
exec("from ._internal." + _internal._pycplex.ext_name + " import cb_hybnetopt")
exec("from ._internal." + _internal._pycplex.ext_name + " import cb_copystart")
exec("from ._internal." + _internal._pycplex.ext_name + " import cb_chgbds")
exec("from ._internal." + _internal._pycplex.ext_name + " import cb_slackfromx")
exec("from ._internal." + _internal._pycplex.ext_name + " import cb_qconstrslackfromx")
exec("from ._internal." + _internal._pycplex.ext_name + " import cb_crushx")
exec("from ._internal." + _internal._pycplex.ext_name + " import cb_crushpi")
exec("from ._internal." + _internal._pycplex.ext_name + " import cb_getobj")
exec("from ._internal." + _internal._pycplex.ext_name + " import cb_getprestat_c")

from ._internal._constants import CPX_CALLBACK_INFO_ENDTIME
from ._internal._constants import CPX_CALLBACK_INFO_ENDDETTIME
from ._internal._constants import CPX_CALLBACK_INFO_DUAL_INFMEAS
from ._internal._constants import CPX_CALLBACK_INFO_PRIMAL_INFMEAS
from ._internal._constants import CPX_CALLBACK_INFO_ITCOUNT_LONG
from ._internal._constants import CPX_CALLBACK_INFO_PRIMAL_OBJ
from ._internal._constants import CPX_CALLBACK_INFO_DUAL_FEAS
from ._internal._constants import CPX_CALLBACK_INFO_PRIMAL_FEAS
from ._internal._constants import CPX_CALLBACK_INFO_DUAL_OBJ
from ._internal._constants import CPX_CALLBACK_INFO_CROSSOVER_DEXCH_LONG
from ._internal._constants import CPX_CALLBACK_INFO_CROSSOVER_DPUSH_LONG
from ._internal._constants import CPX_CALLBACK_INFO_CROSSOVER_PEXCH_LONG
from ._internal._constants import CPX_CALLBACK_INFO_CROSSOVER_PPUSH_LONG
from ._internal._constants import CPX_CALLBACK_INFO_CROSSOVER_SBCNT
from ._internal._constants import CPX_CALLBACK_INFO_BEST_REMAINING
from ._internal._constants import CPX_CALLBACK_INFO_CUTOFF
from ._internal._constants import CPX_CALLBACK_INFO_BEST_INTEGER
from ._internal._constants import CPX_CALLBACK_INFO_MIP_REL_GAP
from ._internal._constants import CPX_CALLBACK_INFO_MIP_ITERATIONS_LONG
from ._internal._constants import CPX_CALLBACK_INFO_NODE_COUNT_LONG
from ._internal._constants import CPX_CALLBACK_INFO_NODES_LEFT_LONG
from ._internal._constants import CPX_CALLBACK_INFO_MIP_FEAS
from ._internal._constants import CPX_CALLBACK_INFO_DISJCUT_PROGRESS
from ._internal._constants import CPX_CALLBACK_INFO_FLOWMIR_PROGRESS
from ._internal._constants import CPX_CALLBACK_INFO_FRACCUT_PROGRESS
from ._internal._constants import CPX_CALLBACK_INFO_PROBE_PHASE
from ._internal._constants import CPX_CALLBACK_INFO_PROBE_PROGRESS
from ._internal._constants import CPX_CALLBACK_INFO_CLIQUE_COUNT
from ._internal._constants import CPX_CALLBACK_INFO_COVER_COUNT
from ._internal._constants import CPX_CALLBACK_INFO_FLOWCOVER_COUNT
from ._internal._constants import CPX_CALLBACK_INFO_GUBCOVER_COUNT
from ._internal._constants import CPX_CALLBACK_INFO_IMPLBD_COUNT
from ._internal._constants import CPX_CALLBACK_INFO_FRACCUT_COUNT
from ._internal._constants import CPX_CALLBACK_INFO_DISJCUT_COUNT
from ._internal._constants import CPX_CALLBACK_INFO_FLOWPATH_COUNT
from ._internal._constants import CPX_CALLBACK_INFO_MIRCUT_COUNT
from ._internal._constants import CPX_CALLBACK_INFO_ZEROHALFCUT_COUNT
from ._internal._constants import CPX_CALLBACK_INFO_MCFCUT_COUNT
from ._internal._constants import CPX_CALLBACK_INFO_LANDPCUT_COUNT
from ._internal._constants import CPX_CALLBACK_INFO_USERCUT_COUNT
from ._internal._constants import CPX_CALLBACK_INFO_TABLECUT_COUNT
from ._internal._constants import CPX_CALLBACK_INFO_SOLNPOOLCUT_COUNT
from ._internal._constants import CPX_CALLBACK_INFO_PRESOLVE_AGGSUBST_LONG
from ._internal._constants import CPX_CALLBACK_INFO_PRESOLVE_COEFFS_LONG
from ._internal._constants import CPX_CALLBACK_INFO_PRESOLVE_COLSGONE
from ._internal._constants import CPX_CALLBACK_INFO_PRESOLVE_ROWSGONE
from ._internal._constants import CPX_CALLBACK_INFO_TUNING_PROGRESS
from ._internal._constants import CPX_CALLBACK_INFO_KAPPA_STABLE
from ._internal._constants import CPX_CALLBACK_INFO_KAPPA_SUSPICIOUS
from ._internal._constants import CPX_CALLBACK_INFO_KAPPA_UNSTABLE
from ._internal._constants import CPX_CALLBACK_INFO_KAPPA_ILLPOSED
from ._internal._constants import CPX_CALLBACK_INFO_KAPPA_MAX
from ._internal._constants import CPX_CALLBACK_INFO_KAPPA_ATTENTION
from ._internal._constants import CPX_CALLBACK_INFO_STARTTIME
from ._internal._constants import CPX_CALLBACK_INFO_STARTDETTIME


class Callback:
    """Base class for Cplex callback classes.

    """

    def __init__(self, env):
        """non-public"""
        self._env = weakref.proxy(env)
        self._cb_type_string  = None
        self._cb_set_function = None

    def __call__(self):
        """Method to be overridden by user-defined callback class."""
        raise CplexError("Callback.__call__ is a pure virtual method")

    def _get_col_index(self, name):
        """non-public"""
        status = cb_getcolindex(
            self._cbstruct, self._env_lp_ptr,
            _proc.cpx_transcode(name, self._env._apienc))
        _proc.check_status(self._cbstruct, status[0], from_cb=True)
        return status[1]
        
    def _get_row_index(self, name):
        """non-public"""
        status = cb_getrowindex(
            self._cbstruct, self._env_lp_ptr,
            _proc.cpx_transcode(name, self._env._apienc))
        _proc.check_status(self._cbstruct, status[0], from_cb=True)
        return status[1]
        
    def _get_quad_index(self, name):
        """non-public"""
        status = cb_getqconstrindex(
            self._cbstruct, self._env_lp_ptr,
            _proc.cpx_transcode(name, self._env._apienc))
        _proc.check_status(self._cbstruct, status[0], from_cb=True)
        return status[1]
        
    def _get_sos_index(self, name):
        """non-public"""
        status = cb_getsosindex(
            self._cbstruct, self._env_lp_ptr,
            _proc.cpx_transcode(name, self._env._apienc))
        _proc.check_status(self._cbstruct, status[0], from_cb=True)
        return status[1]
    
    def abort(self):
        """Terminates optimization.

        Note
          A call to abort should be followed immediately by a return
          statement. Calling other callback methods may override the
          effect of the abort statement.
        """
        if hasattr(self, "_useraction"):
            self._useraction = _internal._constants.CPX_CALLBACK_FAIL
            self._status     = 0
        else:
            self._status     = 1

    def get_end_time(self):
        """Returns a time stamp for computing the time limit.
        
        Subtracting the return value of Callback.get_time() from the
        return value of this method yields the time remaining in
        seconds.

        The interpretation of this value as wall clock time or CPU
        time is controlled by the parameter clocktype.
        """
        return fast_getcallbackinfo(self._cbstruct, CPX_CALLBACK_INFO_ENDTIME, CplexSolverError)

    def get_end_dettime(self):
        """Returns a deterministic time stamp in ticks.
        
        Subtracting the return value of Callback.get_dettime() from the
        return value of this method yields the time remaining in
        deterministic ticks.
        """
        return fast_getcallbackinfo(self._cbstruct, CPX_CALLBACK_INFO_ENDDETTIME, CplexSolverError)

    def get_start_time(self):
        """Returns a time stamp specifying when the solving process started.
        
        To compute elapsed time in seconds, subtract the result of
        Callback.get_time() from the result of this method. This computation
        yields either wallclock time (also known as real time) or CPU time,
        depending on the clock set by the clocktype parameter.
        """
        return fast_getcallbackinfo(self._cbstruct, CPX_CALLBACK_INFO_STARTTIME, CplexSolverError)

    def get_start_dettime(self):
        """Returns a deterministic time stamp specifying when the solving process started.
       
        To compute elapsed deterministic time in ticks, subtract the result of
        Callback.get_dettime() from the result of this method.
        """
        return fast_getcallbackinfo(self._cbstruct, CPX_CALLBACK_INFO_STARTDETTIME, CplexSolverError)

    def get_time(self):
        """Returns a time stamp for the current time.
        
        Subtracting the return value of this method from the return
        value of Callback.get_end_time() yields the time remaining in
        seconds.

        The interpretation of this value as wall clock time or CPU
        time is controlled by the parameter clocktype.
        """
        status = cb_gettime(self._cbstruct)
        _proc.check_status(self._cbstruct, status[0], from_cb=True)
        return status[1]

    def get_dettime(self):
        """Returns a deterministic time stamp for the current time.
       
        Subtracting the return value of this method from the return
        value of Callback.get_end_dettime() yields the time remaining in
        deterministic ticks.
        """
        status = cb_getdettime(self._cbstruct)
        _proc.check_status(self._cbstruct, status[0], from_cb=True)
        return status[1]

        
class OptimizationCallback(Callback):
    """Base class for Cplex optimization callback classes."""

    def _wherefrom(self):
        """non-public"""
        return _proc.get_wherefrom(self._cbstruct)
        
    def get_num_quadratic_constraints(self):
        """Returns the number of quadratic constraints in the problem."""
        return cb_getnumqconstrs(self._cbstruct, self._env_lp_ptr)

    def get_num_cols(self):
        """Returns the number of variables in the problem."""
        return cb_getnumcols(self._cbstruct, self._env_lp_ptr)

    def get_num_rows(self):
        """Returns the number of linear constraints in the problem."""
        return cb_getnumrows(self._cbstruct, self._env_lp_ptr)


class ContinuousCallback(OptimizationCallback):
    """Subclassable class for Cplex continuous callbacks.

    When Cplex is solving a problem by a simplex or barrier method,
    this callback will be called after the simplex or barrier
    callback, if any such callbacks are registered.

    During concurrent optimization, CPLEX calls the user-written
    callback only in the main thread, not in other concurrent threads.

    """

    def __init__(self, env):
        """non-public"""
        Callback.__init__(self, env)
        self._cb_type_string  = "continuous"
        self._cb_set_function = _proc.setlpcallbackfunc

    def get_dual_infeasibility(self):
        """Returns a measure of the dual infeasibility of the problem."""
        return fast_getcallbackinfo(self._cbstruct, CPX_CALLBACK_INFO_DUAL_INFMEAS, CplexSolverError)

    def get_primal_infeasibility(self):
        """Returns a measure of the primal infeasibility of the problem."""
        return fast_getcallbackinfo(self._cbstruct, CPX_CALLBACK_INFO_PRIMAL_INFMEAS, CplexSolverError)

    def get_num_iterations(self):
        """Returns the number of iterations completed."""
        return fast_getcallbackinfo(self._cbstruct, CPX_CALLBACK_INFO_ITCOUNT_LONG, CplexSolverError)

    def get_objective_value(self):
        """Returns the current value of the objective function."""
        if self._wherefrom() == _internal._constants.CPX_CALLBACK_DUAL:
            return fast_getcallbackinfo(self._cbstruct, CPX_CALLBACK_INFO_DUAL_OBJ, CplexSolverError)
        else:
            return fast_getcallbackinfo(self._cbstruct, CPX_CALLBACK_INFO_PRIMAL_OBJ, CplexSolverError)

    def is_dual_feasible(self):
        """Returns whether or not the current solution is dual feasible."""
        if self._wherefrom() == _internal._constants.CPX_CALLBACK_PRIMAL:
            return self.get_dual_infeasibility() <= 0.0
        else:
            return fast_getcallbackinfo(self._cbstruct, CPX_CALLBACK_INFO_DUAL_FEAS, CplexSolverError)
        
    def is_primal_feasible(self):
        """Returns whether or not the current solution is primal feasible."""
        if self._wherefrom() == _internal._constants.CPX_CALLBACK_DUAL:
            return self.get_primal_infeasibility() <= 0.0
        else:
            return fast_getcallbackinfo(self._cbstruct, CPX_CALLBACK_INFO_PRIMAL_FEAS, CplexSolverError)


class SimplexCallback(ContinuousCallback):
    """Subclassable class for Cplex simplex callback classes.

    This callback will be used during execution of the primal simplex,
    dual simplex, or quadratic simplex algorithms.

    """

    def __init__(self, env):
        """non-public"""
        ContinuousCallback.__init__(self, env)
        self._cb_type_string  = "simplex"
        

class BarrierCallback(ContinuousCallback):
    """Subclassable class for Cplex barrier callback classes.

    This callback will be used during execution of the barrier or
    quadratic barrier algorithms.

    """

    def __init__(self, env):
        """non-public"""
        ContinuousCallback.__init__(self, env)
        self._cb_type_string  = "barrier"
        
    def get_dual_objective_value(self):
        """Returns the current dual value of the objective function."""
        return fast_getcallbackinfo(self._cbstruct, CPX_CALLBACK_INFO_DUAL_OBJ, CplexSolverError)
        

class CrossoverCallback(OptimizationCallback):
    """Subclassable class for Cplex crossover callback classes.

    This callback will be used during execution of a crossover
    algorithm.

    """

    def __init__(self, env):
        """non-public"""
        Callback.__init__(self, env)
        self._cb_type_string  = "crossover"
        self._cb_set_function = _proc.setlpcallbackfunc
        
    def get_num_dual_exchanges(self):
        """Returns the number of dual exchanges performed so far."""
        return fast_getcallbackinfo(self._cbstruct, CPX_CALLBACK_INFO_CROSSOVER_DEXCH_LONG, CplexSolverError)
        
    def get_num_dual_pushes(self):
        """Returns the number of dual pushes performed so far."""
        return fast_getcallbackinfo(self._cbstruct, CPX_CALLBACK_INFO_CROSSOVER_DPUSH_LONG, CplexSolverError)
        
    def get_num_primal_exchanges(self):
        """Returns the number of primal exchanges performed so far."""
        return fast_getcallbackinfo(self._cbstruct, CPX_CALLBACK_INFO_CROSSOVER_PEXCH_LONG, CplexSolverError)
        
    def get_num_primal_pushes(self):
        """Returns the number of primal pushes performed so far."""
        return fast_getcallbackinfo(self._cbstruct, CPX_CALLBACK_INFO_CROSSOVER_PPUSH_LONG, CplexSolverError)

    def get_num_superbasics(self):
        """Returns the number of superbasic variables in the basis."""
        return fast_getcallbackinfo(self._cbstruct, CPX_CALLBACK_INFO_CROSSOVER_SBCNT, CplexSolverError)


class MIPInfoCallback(OptimizationCallback):
    """Subclassable class for MIP informational callback classes.

    This callback will be used when CPLEX is solving a MIP problem.

    """

    class quality_metric:
        """Constants defining metrics for the quality of the MIP solve."""
        kappa_stable     = CPX_CALLBACK_INFO_KAPPA_STABLE
        kappa_suspicious = CPX_CALLBACK_INFO_KAPPA_SUSPICIOUS
        kappa_unstable   = CPX_CALLBACK_INFO_KAPPA_UNSTABLE
        kappa_illposed   = CPX_CALLBACK_INFO_KAPPA_ILLPOSED
        kappa_max        = CPX_CALLBACK_INFO_KAPPA_MAX
        kappa_attention  = CPX_CALLBACK_INFO_KAPPA_ATTENTION

    class cut_type:
        """Arguments to MIPInfoCallback.get_num_cuts()."""
        # NB: If you edit these, look at _subinterfaces.py:CutType too!
        cover                = CPX_CALLBACK_INFO_COVER_COUNT
        GUB_cover            = CPX_CALLBACK_INFO_GUBCOVER_COUNT
        flow_cover           = CPX_CALLBACK_INFO_FLOWCOVER_COUNT
        clique               = CPX_CALLBACK_INFO_CLIQUE_COUNT
        fractional           = CPX_CALLBACK_INFO_FRACCUT_COUNT
        MIR                  = CPX_CALLBACK_INFO_MIRCUT_COUNT
        flow_path            = CPX_CALLBACK_INFO_FLOWPATH_COUNT
        disjunctive          = CPX_CALLBACK_INFO_DISJCUT_COUNT
        implied_bound        = CPX_CALLBACK_INFO_IMPLBD_COUNT
        zero_half            = CPX_CALLBACK_INFO_ZEROHALFCUT_COUNT
        multi_commodity_flow = CPX_CALLBACK_INFO_MCFCUT_COUNT
        lift_and_project     = CPX_CALLBACK_INFO_LANDPCUT_COUNT
        user                 = CPX_CALLBACK_INFO_USERCUT_COUNT
        table                = CPX_CALLBACK_INFO_TABLECUT_COUNT
        solution_pool        = CPX_CALLBACK_INFO_SOLNPOOLCUT_COUNT
        # Not Implemented:
        # local_implied_bound
        # BQP
        # RLT
        # benders

    def __init__(self, env):
        """non-public"""
        Callback.__init__(self, env)
        self._cb_type_string  = "MIP_info"
        self._cb_set_function = _proc.setinfocallbackfunc

    def _setup(self, e, lp):
        self.num_cols = _proc.getnumcols(e, lp)
        self.num_rows = _proc.getnumrows(e, lp)
        self.num_quad = _proc.getnumqconstrs(e, lp)

    def get_num_cols(self):
        return self.num_cols

    def get_num_rows(self):
        return self.num_rows

    def get_num_quadratic_constraints(self):
        return self.num_quad

    def get_num_cuts(self, cut_type):
        """Returns the number of cuts of type cut_type added so far."""
        return fast_getcallbackinfo(self._cbstruct, cut_type, CplexSolverError)

    def get_best_objective_value(self):
        """Returns the best objective value among unexplored nodes."""
        return fast_getcallbackinfo(self._cbstruct, CPX_CALLBACK_INFO_BEST_REMAINING, CplexSolverError)

    def get_cutoff(self):
        """Returns the current cutoff value."""
        return fast_getcallbackinfo(self._cbstruct, CPX_CALLBACK_INFO_CUTOFF, CplexSolverError)

    def get_incumbent_objective_value(self):
        """Returns the objective value of the incumbent solution."""
        return fast_getcallbackinfo(self._cbstruct, CPX_CALLBACK_INFO_BEST_INTEGER, CplexSolverError)

    def get_incumbent_linear_slacks(self, *args):
        """Returns a set of linear slacks for the incumbent solution.

        Can be called by four forms.

        self.get_incumbent_linear_slacks()
          return all linear slack values from the incumbent solution.

        self.get_incumbent_linear_slacks(i)
          i must be a linear constraint name or index.  Returns the
          slack values associated with the linear constraint whose
          index or name is i.

        self.get_incumbent_linear_slacks(s)
          s must be a sequence of linear constraint names or indices.
          Returns the slack values associated with the linear
          constraints with indices the members of s.  Equivalent to
          [self.get_incumbent_linear_slacks(i) for i in s]

        self.get_incumbent_linear_slacks(begin, end)
          begin and end must be linear constraint indices with begin
          <= end or linear constraint names whose indices respect
          this order.  Returns the slack values associated with the
          linear constraints with indices between begin and end,
          inclusive of end.  Equivalent to
          self.get_incumbent_linear_slacks(range(begin, end + 1)).
        """
        status = cb_slackfromx(self._cbstruct, self._env_lp_ptr, self.get_incumbent_values())
        _proc.check_status(self._cbstruct, status[0], from_cb=True)
        slacks = status[1]
        def getslack(a, b = self.num_rows - 1):
            return slacks[a:b+1]
        return apply_freeform_two_args(
            getslack, self._get_row_index, args)

    def get_incumbent_quadratic_slacks(self, *args):
        """Returns a set of quadratic slacks for the incumbent solution.

        Can be called by four forms.

        self.get_incumbent_quadratic_slacks()
          return all quadratic slack values from the incumbent
           solution.

        self.get_incumbent_quadratic_slacks(i)
          i must be a quadratic constraint name or index.  Returns
          the slack values associated with the quadratic constraint
          whose index or name is i.

        self.get_incumbent_quadratic_slacks(s)
          s must be a sequence of quadratic constraint names or
          indices.  Returns the slack values associated with the
          quadratic constraints with indices the members of s.
          Equivalent to
          [self.get_incumbent_quadratic_slacks(i) for i in s]

        self.get_incumbent_quadratic_slacks(begin, end)
          begin and end must be quadratic constraint indices with
          begin <= end or quadratic constraint names whose indices
          respect this order.  Returns the slack values associated
          with the quadratic constraints with indices between begin
          and end, inclusive of end.  Equivalent to
          self.get_incumbent_quadratic_slacks(range(begin, end + 1)).
        """
        status = cb_qconstrslackfromx(self._cbstruct, self._env_lp_ptr, self.get_incumbent_values())
        _proc.check_status(self._cbstruct, status[0], from_cb=True)
        slacks = status[1]
        def getslack(a, b = self.num_quad - 1):
            return slacks[a:b+1]
        return apply_freeform_two_args(
            getslack, self._get_quad_index, args)

    def get_incumbent_values(self, *args):
        """Returns the variable values of the incumbent solution.

        There are four forms by which get_incumbent_values may be
        called.

        self.get_incumbent_values()
          returns the entire incumbent solution

        self.get_incumbent_values(i)
          i must be a variable index or name.  Returns the value
          of the variable with index i in the incumbent solution.

        self.get_incumbent_values(s)
          s must be a sequence of variables indices or names.
          Returns a list of the values of the variables with indices
          the members of s, in the same order as they appear in s.
          Equivalent to [self.get_incumbent_values(i) for i in s]
          
        self.get_incumbent_values(begin, end)
          begin and end must be integers with begin <= end or
          variable names with the same property.  Returns a list of
          the values of the variables with indices between begin and
          end, inclusive of end.  Equivalent to
          self.get_incumbent_values(range(begin, end + 1))
        """
        def getcallbackincumbent(begin, end = self.num_cols - 1):
            return _proc.getcallbackincumbent(self._cbstruct, begin, end)
        return apply_freeform_two_args(
            getcallbackincumbent, self._get_col_index, args)

    def get_MIP_relative_gap(self):
        """Returns the current relative MIP gap."""
        return fast_getcallbackinfo(self._cbstruct, CPX_CALLBACK_INFO_MIP_REL_GAP, CplexSolverError)

    def get_num_iterations(self):
        """Returns the number of iterations performed so far."""
        return fast_getcallbackinfo(self._cbstruct, CPX_CALLBACK_INFO_MIP_ITERATIONS_LONG, CplexSolverError)

    def get_num_nodes(self):
        """Returns the number of nodes processed so far."""
        return fast_getcallbackinfo(self._cbstruct, CPX_CALLBACK_INFO_NODE_COUNT_LONG, CplexSolverError)

    def get_num_remaining_nodes(self):
        """Returns the number of unexplored nodes remaining."""
        return fast_getcallbackinfo(self._cbstruct, CPX_CALLBACK_INFO_NODES_LEFT_LONG, CplexSolverError)

    def has_incumbent(self):
        """Returns whether or not an incumbent solution has been found."""
        return fast_getcallbackinfo(self._cbstruct, CPX_CALLBACK_INFO_MIP_FEAS, CplexSolverError)

    def get_float_quality(self, which):
        """Returns a measure of the quality of the MIP solution as a floating point value.

        The measure of the quality of a solution must be an attribute
        of self.quality_metric corresponding to a floating point
        quality metric.  Such metrics include:

        self.quality_metric.kappa_stable
        self.quality_metric.kappa_suspicious
        self.quality_metric.kappa_unstable
        self.quality_metric.kappa_illposed
        self.quality_metric.kappa_max
        self.quality_metric.kappa_attention
        """
        return fast_getcallbackinfo(self._cbstruct, which, CplexSolverError)


class MIPCallback(MIPInfoCallback):
    """Subclassable class for MIP callback classes.

    This callback will be used when CPLEX is solving a MIP problem.

    """

    def __init__(self, env):
        """non-public"""
        Callback.__init__(self, env)
        self._cb_type_string  = "MIP"
        self._cb_set_function = _proc.setmipcallbackfunc
        
    def _get_node_info(self, which_info, which_node):
        """non-public"""
        return _proc.getcallbacknodeinfo(self._cbstruct, which_node, which_info)

    def _get_seq_info(self, which_info, which_node):
        """non-public"""
        return _proc.getcallbackseqinfo(self._cbstruct, which_node, which_info)

    def get_objective_coefficients(self, *args):
        """Returns the coefficients of the linear objective function.

        There are four forms by which get_objective_coefficients may
        be called.

        self.get_objective_coefficients()
          returns the entire objective function. 

        self.get_objective_coefficients(i)
          i must be a variable index or name.  Returns the objective
          coefficient of the variable with index i.

        self.get_objective_coefficients(s)
          s must be a sequence of variable indices or names.  Returns
          a list of the objective coefficients of the variables with
          indices the members of s, in the same order as they appear
          in s.  Equivalent to [self.get_objective_coefficients(i)
          for i in s]

        self.get_objective_coefficients(begin, end)
          begin and end must be integers with begin <= end or
          variable names with the same property.  Returns a list of
          the objective coefficients of variables with indices
          between begin and end, inclusive of end.  Equivalent to
          self.get_objective_coefficients(range(begin, end + 1))
        """
        def getobj(begin, end = self.get_num_cols() - 1):
            status = cb_getobj(self._cbstruct, self._env_lp_ptr, begin, end)
            _proc.check_status(self._cbstruct, status[0], from_cb=True)
            return status[1]
        return apply_freeform_two_args(
            getobj, self._get_col_index, args)


class ControlCallback(MIPCallback):
    """Base class for Cplex MIP control callback classes.

    """

    class feasibility_status:
        feasible          = _internal._constants.CPX_INTEGER_FEASIBLE
        implied_feasible  = _internal._constants.CPX_IMPLIED_INTEGER_FEASIBLE 
        infeasible        = _internal._constants.CPX_INTEGER_INFEASIBLE

    def __init__(self, env):
        """non-public"""
        Callback.__init__(self, env)

    def _conv_col_index(self, name):
        """non-public"""
        if isinstance(name, six.string_types):
            return self._get_col_index(name)
        else:
            return name
        
    def get_pseudo_costs(self, *args):
        """Returns the current pseudo costs.

        There are four forms by which get_pseudo_costs may be
        called.

        self.get_pseudo_costs()
          returns a list of pairs with the pseudo costs for all the
           variables.

        self.get_pseudo_costs(i)
          i must be a variable index or name.  Returns a pair (up,
          down), where up is the up pseudo cost and down is the down
          pseudo cost of branching on the variable i.
        
        self.get_pseudo_costs(s)
          s must be a sequence of variable indices or names.  Returns
          a list of pairs (up, down) of pseudo costs of branching on
          the variables with indices the members of s, in the same
          order as they appear in s.  Equivalent to
          [self.get_pseudo_costs(i) for i in s]

        self.get_pseudo_costs(begin, end)
          begin and end must be integers with begin <= end or
          variable names with the same property.  Returns a list of
          pairs (up, down) of pseudo costs of branching on the
          variables with indices between begin and end, inclusive of
          end.  Equivalent to
          self.get_pseudo_costs(range(begin, end + 1))
        """
        def getcallbackpseudocosts(begin, end = self.get_num_cols() - 1):
            return list(zip(*_proc.getcallbackpseudocosts(self._cbstruct, begin, end)))
        return apply_freeform_two_args(
            getcallbackpseudocosts, self._get_col_index, args)
        
    def get_feasibilities(self, *args):
        """Returns the current integer feasibility status.

        There are four forms by which get_feasibilities may be
        called.

        The return values are attributes of self.feasibility_status.

        self.get_feasibilities()
          returns a list with the feasibility status for all the
          variables.

        self.get_feasibilities(i)
          i must be a variable index or name.  Returns the
          feasibility status of the variable with index i.

        self.get_feasibilities(s)
          s must be a sequence of variable indices or names.  Returns
          a list of the feasibility statuses of the variables with
          indices the members of s, in the same order as they appear
          in s.  Equivalent to [self.get_feasibilities(i) for i in s]

        self.get_feasibilities(begin, end)
          begin and end must be integers with begin <= end or
          variable names with the same property.  Returns a list of
          the feasibility statuses of the variables with indices
          between begin and end, inclusive of end.  Equivalent to
          self.get_feasibilities(range(begin, end + 1))

        Note
          Before you call this method from a solve callback, a
          solution must exist. That is, you must first create the
          solution by calling a CPLEX optimization method, and then
          you must verify that this optimization method generated a
          solution by checking its return value before you call the
          method get_feasibilities.
        """
        def getcallbacknodeintfeas(begin, end = self.get_num_cols() - 1):
            return _proc.getcallbacknodeintfeas(self._cbstruct, begin, end)
        return apply_freeform_two_args(
            getcallbacknodeintfeas, self._get_col_index, args)

    def get_lower_bounds(self, *args):
        """Returns the lower bounds at the current node.

        There are four forms by which get_lower_bounds may be
        called.

        self.get_lower_bounds()
          returns a list with the lower bounds for all the variables.

        self.get_lower_bounds(i)
          i must be a variable index or name.  Returns the lower
          bound of the variable with index i.

        self.get_lower_bounds(s)
          s must be a sequence of variable indices or names.  Returns
          a list of the lower bounds of the variables with indices
          the members of s, in the same order as they appear in s.
          Equivalent to [self.get_lower_bounds(i) for i in s]

        self.get_lower_bounds(begin, end)
          begin and end must be integers with begin <= end or
          variable names with the same property.  Returns a list of
          the lower bounds of the variables with indices between
          begin and end, inclusive of end.  Equivalent to
          self.get_lower_bounds(range(begin, end + 1))
        """
        def getcallbacknodelb(begin, end = self.get_num_cols() - 1):
            return _proc.getcallbacknodelb(self._cbstruct, begin, end)
        return apply_freeform_two_args(
            getcallbacknodelb, self._get_col_index, args)

    def get_upper_bounds(self, *args):
        """Returns the upper bounds at the current node.

        There are four forms by which get_upper_bounds may be
        called.

        self.get_upper_bounds()
          returns a list with the upper bounds for all the variables.

        self.get_upper_bounds(i)
          i must be a variable index or name.  Returns the upper
          bound of the variable with index i.

        self.get_upper_bounds(s)
          s must be a sequence of variable indices or names.  Returns
          a list of the upper bounds of the variables with indices
          the members of s, in the same order as they appear in s.
          Equivalent to [self.get_upper_bounds(i) for i in s]

        self.get_upper_bounds(begin, end)
          begin and end must be integers with begin <= end or
          variable names with the same property.  Returns a list of
          the upper bounds of the variables with indices between
          begin and end, inclusive of end.  Equivalent to
          self.get_upper_bounds(range(begin, end + 1))
        """
        def getcallbacknodeub(begin, end = self.get_num_cols() - 1):
            return _proc.getcallbacknodeub(self._cbstruct, begin, end)
        return apply_freeform_two_args(
            getcallbacknodeub, self._get_col_index, args)

    def get_node_data(self):
        """Returns the user handle for the current node.

        Returns None if no handle is set for the node.
        """
        return self._get_node_info(_internal._constants.CPX_CALLBACK_INFO_NODE_USERHANDLE, 0)


    def set_node_data(self,data):
        """Set the user handle for the current node.

        Returns the user handle previously set for this node (or None
        if no handle was set).
        """
        return _proc.callbacksetuserhandle(self._cbstruct, data)

    def get_node_ID(self):
        """Return the sequence number of this node."""
        return self._get_node_info(_internal._constants.CPX_CALLBACK_INFO_NODE_SEQNUM_LONG, 0)

    def get_objective_value(self):
        """Returns the value of the objective function at the current node."""
        return _proc.getcallbacknodeobjval(self._cbstruct)

    def get_linear_slacks(self, *args):
        """Returns a set of linear slacks for the solution at the current node.

        Can be called by four forms.

        self.get_linear_slacks()
          return all linear slack values from the problem at the
          current node.

        self.get_linear_slacks(i)
          i must be a linear constraint name or index.  Returns the
          slack values associated with the linear constraint whose
          index or name is i.

        self.get_linear_slacks(s)
          s must be a sequence of linear constraint names or indices.
          Returns the slack values associated with the linear
          constraints with indices the members of s.  Equivalent to
          [self.get_linear_slacks(i) for i in s]

        self.get_linear_slacks(begin, end)
          begin and end must be linear constraint indices with begin
          <= end or linear constraint names whose indices respect
          this order.  Returns the slack values associated with the
          linear constraints with indices between begin and end,
          inclusive of end.  Equivalent to
          self.get_linear_slacks(range(begin, end + 1)).
        """
        status = cb_slackfromx(self._cbstruct, self._env_lp_ptr, self.get_values())
        _proc.check_status(self._cbstruct, status[0], from_cb=True)
        slacks = status[1]
        def getslack(a, b = self.get_num_rows() - 1):
            return slacks[a:b+1]
        return apply_freeform_two_args(
            getslack, self._get_row_index, args)
        
    def get_quadratic_slacks(self, *args):
        """Returns a set of quadratic slacks for the solution at the current node.

        Can be called by four forms.

        self.get_quadratic_slacks()
          return all quadratic slack values from the problem at the
          current node.

        self.get_quadratic_slacks(i)
          i must be a quadratic constraint name or index.  Returns
          the slack values associated with the quadratic constraint
          whose index or name is i.
          
        self.get_quadratic_slacks(s)
          s must be a sequence of quadratic constraint names or
          indices.  Returns the slack values associated with the
          quadratic constraints with indices the members of s.
          Equivalent to [self.get_quadratic_slacks(i) for i in s]
          
        self.get_quadratic_slacks(begin, end)
          begin and end must be quadratic constraint indices with
          begin <= end or quadratic constraint names whose indices
          respect this order.  Returns the slack values associated
          with the quadratic constraints with indices between begin
          and end, inclusive of end.  Equivalent to
          self.get_quadratic_slacks(range(begin, end + 1)).
        """
        status = cb_qconstrslackfromx(self._cbstruct, self._env_lp_ptr, self.get_values())
        _proc.check_status(self._cbstruct, status[0], from_cb=True)
        slacks = status[1]
        def getslack(a, b = self.get_num_quadratic_constraints() - 1):
            return slacks[a:b+1]
        return apply_freeform_two_args(
            getslack, self._get_quad_index, args)

    def get_values(self, *args):
        """Returns the solution values at the current node.

        In the case that the node LP is unbounded, this method returns
        a vector that corresponds to an unbounded direction, scaled so
        that at least one of its elements has magnitude
        cplex.infinity.  Thus, often the vector can be used directly,
        for example to separate a lazy constraint.  However, due to
        the presence of large values in the vector care must be taken
        to avoid potential numerical errors.  If in doubt, 
        rescale the vector, and use it as an unbounded ray
        rather than a primal vector.

        There are four forms by which get_values may be called.

        self.get_values()
          returns the entire primal solution vector.

        self.get_values(i)
          i must be a variable index or name.  Returns the solution
          value of the variable with index i.

        self.get_values(s)
          s must be a sequence of variable indices or names.  Returns
          a list of the solution values of the variables with indices
          the members of s, in the same order as they appear in s.
          Equivalent to [self.get_values(i) for i in s]

        self.get_values(begin, end)
          begin and end must be integers with begin <= end or
          variable names with the same property.  Returns a list of
          the solution values of variables with indices between begin
          and end, inclusive of end.  Equivalent to
          self.get_values(range(begin, end + 1))
        """
        def getcallbacknodex(begin, end = self.get_num_cols() - 1):
            return _proc.getcallbacknodex(self._cbstruct, begin, end)
        return apply_freeform_two_args(
            getcallbacknodex, self._get_col_index, args)

    def get_SOS_feasibilities(self, *args):
        """Returns the current special ordered set feasibility status.

        There are four forms by which get_SOS_feasibilities may be
        called.

        Returns 1 if the SOS is feasible and 0 if it is not.

        self.get_SOS_feasibilties()
          Returns the feasibility statuses of all the special ordered
          sets.

        self.get_SOS_feasibilities(i)
          i must be a SOS index or name.  Returns the feasibility
          status of the special ordered set with index i.

        self.get_SOS_feasibilities(s)
          s must be a sequence of SOS indices or names.  Returns a
          list of the feasibility statuses of the special ordered
          sets with indices the members of s, in the same order as
          they appear in s.  Equivalent to
          [self.get_SOS_feasibilities(i) for i in s]

        self.get_SOS_feasibilities(begin, end)
          begin and end must be integers with begin <= end or SOS
          names with the same property.  Returns a list of the
          feasibility statuses of the special ordered sets with
          indices between begin and end, inclusive of end.
          Equivalent to self.get_SOS_feasibilities(range(begin, end + 1))

        Note
          Before you call this method from a solve callback, a
          solution must exist. That is, you must first create the
          solution by calling a CPLEX optimization method, and then
          you must verify that this optimization method generated a
          solution by checking its return value before you call the
          method get_SOS_feasibilities.
        """
        def is_sos_feasible(index):
            return _proc.getcallbacksosinfo(self._cbstruct, index, 0, _internal._constants.CPX_CALLBACK_INFO_SOS_IS_FEASIBLE)
        return apply_freeform_one_arg(
            is_sos_feasible, self._get_sos_index,
            cb_getnumsos(self._cbstruct, self._env_lp_ptr), args)


class BranchCallback(ControlCallback):
    """Subclassable class for branch callback classes.

    This callback will be used prior to branching at a node in the
    branch and cut tree.

    """

    class branch_type:
        """Constants defining types of branches."""
        any       = _internal._constants.CPX_TYPE_ANY
        SOS1      = _internal._constants.CPX_TYPE_SOS1
        SOS2      = _internal._constants.CPX_TYPE_SOS2
        variable  = _internal._constants.CPX_TYPE_VAR
        
    def __init__(self, env):
        """non-public"""
        Callback.__init__(self, env)
        self._cb_type_string  = "branch"
        def fn(a, b):
            _proc.setbranchcallbackfunc(a, b)
            _proc.setbranchnosolncallbackfunc(a, b)
        self._cb_set_function = fn
        
    def get_branch(self, which_branch):
        """Returns one of the candidate branches at the current node.

        which_branch must be an integer such that 0 <= which_branch <
        self.get_num_branches().

        The return value of get_branch is a tuple t with two entries.
        The first entry is the node estimate for the specified branch.
        The second entry is a list of (var, dir, bnd) triples, where
        var is the index of a variable whose bound will change, bnd is
        the new bound, and dir is one of "L", "U", and "B", indicating
        that the branch will change the lower bound, the upper bound,
        or both, respectively.
        """
        if which_branch >= 0 and which_branch < self._node_count:
            if which_branch == self._node_count - 1:
                end = self._bound_count
            else:
                end = self._node_begin[which_branch+1]
            vars = self._index[self._node_begin[which_branch] : end]
            bnds = self._bounds[self._node_begin[which_branch] : end]
            dirs = self._lu[self._node_begin[which_branch] : end]
            return (self._node_estimate[which_branch], list(zip(vars, dirs, bnds)))
        else:
            raise CplexError("BranchCallback.get_branch: Bad branch index")

    def get_branch_type(self):
        """Returns the type of the branch.

        One of the following:
        self.branch_type.any
        self.branch_type.SOS1
        self.branch_type.SOS2
        self.branch_type.variable
        """
        cpx_encode = _proc.cpx_encode
        enc = _proc.default_encoding
        return cpx_encode(self._branch_type, enc)

    def get_num_branches(self):
        """Return the number of nodes Cplex will create from this branch."""
        return self._node_count

    def is_integer_feasible(self):
        """Return whether or not the current node is integer feasible."""
        return self.get_num_branches() == 0

    def make_branch(self, objective_estimate, variables = [], constraints = [], node_data = None):
        """Makes a new branch with the specified data.

        objective_estimate is a float representing the estimated
        objective value resulting from the specified branch.

        variables is a sequence of (var, dir, bnd) triples specifying
        the variables on which to branch.  var must be an index of a
        variable, dir must be one of "L" and "U", indicating that the
        bound is a lower or upper bound, respectively, and bnd is an
        integer specifying the new bound for the variable.

        constraints is a sequence of (vec, sense, rhs) triples
        specifying the constraints with which to branch.  vec must be
        either an instance of SparsePair or a sequence with two
        entries, the first of which specifies the indices and the
        second of which specifies the values of the constraint.  rhs
        must be a float determining the righthand side of the
        constraint.  sense must be one of "L", "G", or "E", specifying
        whether the constraint is a less-than, greater-than, or
        equality constraint.

        node_data may be any object to be associated with the created
        node.  It can be queried by the get_node_data methods of the
        IncumbentCallback class and the NodeCallback class.
        """
        obje = objective_estimate
        if len(variables) == 0:
            a = [[], [], []]
        else:
            a = list(zip(*variables))
        vars = list(a[0])
        dirs = ''.join(list(a[1]))
        bnds = list(a[2])
        if len(constraints) == 0:
            a = [[], [], []]
        else:
            a = list(zip(*constraints))
        rmat  = _HBMatrix(a[0])
        sense = ''.join(list(a[1]))
        rhs   = list(a[2])
        seqnum = _proc.branchcallbackbranchgeneral(
            self._cbstruct, vars, dirs, bnds, rhs, sense, rmat.matbeg,
            rmat.matind, rmat.matval, obje, node_data)
        self._useraction = _internal._constants.CPX_CALLBACK_SET
        return (seqnum,)

    def make_cplex_branch(self, which_branch, node_data = None):
        """Replicates a CPLEX branch.

        The function replicates the n-th branch that CPLEX would create
        at the current node. The purpose of this function is to branch
        exactly like CPLEX, but at the same time attach a user object to
        the newly created node.

        which_branch must be an integer such that 0 <= which_branch <
        self.get_num_branches().
        
        node_data may be any object to be associated with the created
        node.  It can be queried by the get_node_data methods of various
        callback classes.

        The function returns the sequence number of the newly created
        node.
        """
        seqnum = _proc.branchcallbackbranchasCPLEX(self._cbstruct,
                                                   which_branch,
                                                   node_data)
        self._useraction = _internal._constants.CPX_CALLBACK_SET
        return seqnum

    def prune(self):
        """Removes the current node from the search tree.

        Note
          Prune may not be called in combination with make_branch.
        """
        self._useraction = _internal._constants.CPX_CALLBACK_SET
        self._status     = 0


class CutCallback(ControlCallback):
    """Base class for user cut and lazy constraint callback classes.

    """

    def add(self, cut, sense, rhs, use_cut):
        """non-public"""
        if isinstance(cut, SparsePair):
            indices = cut.ind
            values  = cut.val
        else:
            indices = cut[0]
            values  = cut[1]
        if len(indices) != len(values):
            raise CplexError("Inconsistent input to CutCallback.add")
        if use_cut is True:
            use_cut = 1
        if use_cut is False:
            use_cut = 0
        _proc.cutcallbackadd(
            self._cbstruct, rhs, sense,
            list(map(self._conv_col_index, indices)),
            values, use_cut)

    def add_local(self, cut, sense, rhs):
        """non-public"""
        if isinstance(cut, SparsePair):
            indices = cut.ind
            values  = cut.val
        else:
            indices = cut[0]
            values  = cut[1]
        if len(indices) != len(values):
            raise CplexError("Inconsistent input to CutCallback.add_local")
        _proc.cutcallbackaddlocal(
            self._cbstruct, rhs, sense,
            list(map(self._conv_col_index, indices)), values)


class LazyConstraintCallback(CutCallback):
    """Subclassable class for lazy constraint callback classes.

    This callback will be used when CPLEX finds a new integer
    feasible solution and when CPLEX finds that the LP relaxation
    at the current node is unbounded.

    Note:
      The lazy constraint callback may be invoked during MIP start
      processing.  In that case get_solution_source returns
      mip_start_solution.  When this value is returned some special
      considerations apply:

        - MIP start processing occurs very early in the solution process.
          At this point no search tree is setup yet and there are no
          search tree nodes yet.  Consequently, a lot of the callback
          functions that require a node context will fail in this
          situation.
        - Lazy constraints separated when processing a MIP start will be
          discarded after that MIP start has been processed. This means
          that the callback may have to separate the same constraint
          again for the next MIP start or for a solution that is found
          later in the solution process.

    """

    class use_constraint:
        """Constants to specify when to use the added constraint"""
        force = _internal._constants.CPX_USECUT_FORCE
        purge = _internal._constants.CPX_USECUT_PURGE

    def __init__(self, env):
        """non-public"""
        Callback.__init__(self, env)
        self._cb_type_string  = "lazycon"
        self._cb_set_function = _proc.setlazyconstraintcallbackfunc

    def add(self, constraint, sense, rhs, use=use_constraint.force):
        """Adds a linear constraint to the current subproblem.

        constraint must be either a SparsePair instance or a list of
        two lists, the first of which specifies variables, the second
        of which specifies the values of the constraint.

        sense must be a single-character string; ("L", "G", "E")

        rhs is a float, specifying the righthand side of the constraint.

        use indicates under what circumstances the constraint should
        be used.  It can take the following values:

        self.use_constraint.force (default) : force CPLEX to use the constraint
        self.use_constraint.purge           : allow CPLEX to purge the constraint

        When you add a lazy constraint with the nondefault value purge,
        you authorize CPLEX to purge (that is, to eliminate) the lazy
        constraint under certain circumstances, for example, if the 
        lazy constraint becomes slack. Consequently, in view of such
        purging, you must not assume that any previously added constraints
        are still in current relaxation. In other words, the purged
        lazy constraint may be violated in subsequent relaxations.
        """
        CutCallback.add(self, constraint, sense, rhs, use)

    def add_local(self, constraint, sense, rhs):
        """Adds a linear local constraint to the current subproblem.

        A local constraint is a constraint that will only be added to
        the problem at the current node and the subtree rooted by the
        current node. It will not be added to the constraint matrix of
        the original cobra_model.

        constraint must be either a SparsePair instance or a list of
        two lists, the first of which specifies variables, the second
        of which specifies the values of the constraint.

        sense must be a single-character string; ("L", "G", "E")

        rhs is a float, specifying the righthand side of the constraint.
        """
        CutCallback.add_local(self, constraint, sense, rhs)

    def is_unbounded_node(self):
        """Returns True if the current LP relaxation is unbounded, False otherwise."""
        return (self._wherefrom() ==
                _internal._constants.CPX_CALLBACK_MIP_CUT_UNBD)

    def get_solution_source(self):
        """Returns the source of the solution for which the lazy constraint callback was invoked.

        The possible return values are:

        IncumbentCallback.solution_source.node_solution: The integral solution is
        the solution to the LP relaxation of a node in the MIP search
        tree.

        IncumbentCallback.solution_source.heuristic_solution: The integral solution
        has been found by a CPLEX internal heuristic.

        IncumbentCallback.solution_source.mipstart_solution: The integral solution has been
        found during MIP start processing.
        """
        if _internal._constants.CPX_LAZYCONSTRAINTCALLBACK_NODE == self._get_node_info(_internal._constants.CPX_CALLBACK_INFO_LAZY_SOURCE, 0):
            return IncumbentCallback.solution_source.node_solution
        elif _internal._constants.CPX_LAZYCONSTRAINTCALLBACK_HEUR == self._get_node_info(_internal._constants.CPX_CALLBACK_INFO_LAZY_SOURCE, 0):
            return IncumbentCallback.solution_source.heuristic_solution
        elif _internal._constants.CPX_LAZYCONSTRAINTCALLBACK_MIPSTART == self._get_node_info(_internal._constants.CPX_CALLBACK_INFO_LAZY_SOURCE, 0):
            return IncumbentCallback.solution_source.mipstart_solution
        else:
            raise CplexError("Unexpected wherefrom value in LazyConstraintCallback.get_solution_source()")
            
class UserCutCallback(CutCallback):
    """Subclassable class for lazy constraint callback classes.

    This callback will be used within the cut loop that CPLEX calls at
    each node of the branch and cut algorithm.  It will be called once
    after CPLEX has ended its own cut generation loop so that the user
    can specify additional cuts to be added to the cut pool.

    """

    class use_cut:
        """Constants to specify when to use the added cut."""
        force  = _internal._constants.CPX_USECUT_FORCE
        purge  = _internal._constants.CPX_USECUT_PURGE
        filter = _internal._constants.CPX_USECUT_FILTER

    def __init__(self, env):
        """non-public"""
        Callback.__init__(self, env)
        self._cb_type_string  = "usercut"
        self._cb_set_function = _proc.setusercutcallbackfunc

    def add(self, cut, sense, rhs, use=use_cut.force):
        """Adds a linear cut to to the current subproblem.

        cut must be either a SparsePair instance or a list of two
        lists, the first of which specifies variables, the second of
        which specifies the values of the cut.

        sense must be  a single-character string; ("L", "G", "E")

        rhs is a float, specifying the righthand side of the cut.

        use indicates under what circumstances the cut should be used.
        It can take the following values

        self.use_cut.force (default) : force CPLEX to use the cut
        self.use_cut.purge           : allow CPLEX to purge the cut
        self.use_cut.filter          : treat as cuts CPLEX creates
        """
        CutCallback.add(self, cut, sense, rhs, use)
        
    def add_local(self, cut, sense, rhs):
        """Adds a linear local cut to the current subproblem.

        A local cut is a cut that is only valid at the current
        node and the subtree rooted by the current node. It does 
        not need to be globally valid.

        cut must be either a SparsePair instance or a list of two
        lists, the first of which specifies variables, the second of
        which specifies the values of the cut.

        sense must be  a single-character string; ("L", "G", "E")

        rhs is a float, specifying the righthand side of the cut.
        """
        CutCallback.add_local(self, cut, sense, rhs)
        
    def is_after_cut_loop(self):
        """Returns True if called after the cut loop, False otherwise."""
        return (self._wherefrom() ==
                _internal._constants.CPX_CALLBACK_MIP_CUT_LAST)
            
    def abort_cut_loop(self):
        """Terminate the cut loop and proceed with branching."""
        self._useraction = _internal._constants.CPX_CALLBACK_ABORT_CUT_LOOP

        

class HSCallback(ControlCallback):

    status = _internal._subinterfaces.SolutionStatus()
    """See `_internal._subinterfaces.SolutionStatus()` """

    """Base class for heuristic and solve callback classes."""

    class method:
        """Constants defining methods for solving the node LP."""
        primal            = _internal._constants.CPX_ALG_PRIMAL
        dual              = _internal._constants.CPX_ALG_DUAL
        barrier           = _internal._constants.CPX_ALG_BARRIER
        network           = _internal._constants.CPX_ALG_NET

    def get_cplex_status(self):
        """Returns the solution status of the current subproblem.

        Returns an attribute of self.status.
        """
        status = cb_getstat(self._cbstruct)
        _proc.check_status(self._cbstruct, status[0], from_cb=True)
        return status[1]

    def is_dual_feasible(self):
        """Returns whether the solution of the current subproblem is dual feasible."""
        status = cb_solninfo(self._cbstruct)
        _proc.check_status(self._cbstruct, status[0], from_cb=True)
        return bool(status[2])

    def is_primal_feasible(self):
        """Returns whether the solution of the current subproblem is primal feasible."""
        status = cb_solninfo(self._cbstruct)
        _proc.check_status(self._cbstruct, status[0], from_cb=True)
        return bool(status[1])
    
    def solve(self, alg = _internal._constants.CPX_ALG_DUAL):
        """Solves the current subproblem.

        The value of alg, if specified, determines the algorithm to
        use to solve the current subproblem.

        self.method.primal  : primal simplex

        self.method.dual    : dual simplex

        self.method.barrier : barrier

        self.method.network : network

        If this method generates a feasible solution it returns True,
        otherwise it returns False.
        """
        if alg == _internal._constants.CPX_ALG_PRIMAL:
            status = cb_primopt(self._cbstruct)
            _proc.check_status(self._cbstruct, status, from_cb=True)
        elif alg == _internal._constants.CPX_ALG_DUAL or alg == _internal._constants.CPX_ALG_AUTOMATIC:
            status = cb_dualopt(self._cbstruct)
            _proc.check_status(self._cbstruct, status, from_cb=True)
        elif alg == _internal._constants.CPX_ALG_BARRIER:
            status = cb_hybbaropt(self._cbstruct)
            _proc.check_status(self._cbstruct, status, from_cb=True)
        elif alg == _internal._constants.CPX_ALG_NET:
            status = cb_hybnetopt(self._cbstruct)
            _proc.check_status(self._cbstruct, status, from_cb=True)
        else:
            raise CplexError("HSCallback.solve: bad algorithm identifier")
        return self.get_cplex_status() in (self.status.optimal,
                                           self.status.feasible,
                                           self.status.MIP_optimal,
                                           self.status.MIP_feasible)


class HeuristicCallback(HSCallback):
    """Subclassable class for heuristic callback classes.

    This callback will be used after solving each subproblem and at
    the root node before each round of cuts is added to the problem
    and resolved.

    """

    def __init__(self, env):
        """non-public"""
        Callback.__init__(self, env)
        self._cb_type_string  = "heuristic"
        self._cb_set_function = _proc.setheuristiccallbackfunc

    def set_bounds(self, *args):
        """Sets the bounds for a set of variables.

        Can be called by two forms.

        self.set_bounds(i, lb, ub)
          i must be a variable name or index and lb and ub must be
          real numbers.  Sets the lower bound and upper bound of the
          variable whose index or name is i to lb and ub,
          respectively.

        self.set_lower_bounds(seq_of_triples)
          seq_of_triples must be a list or tuple of tuples (i, lb, ub),
          each of which consists of a variable name or index and
          two real numbers.  Sets the bounds of the specified
          variables to the corresponding values.  Equivalent to
          [self.set_lower_bounds(triple[0], triple[1], triple[2]) for
          triple in seq_of_triples].
          
        Note
          The variables specified must not have been removed by
          presolve.

        Note
          These bound changes affect only the problem at the current
          node.
        """
        if len(args) == 1:
            vars, lb, ub = list(zip(*args))
        elif len(args) == 3:
            vars = [args[0]]
            lb   = [args[1]]
            ub   = [args[2]]
        else:
            raise WrongNumberOfArgumentsError()
        vars = list(map(self._conv_col_index, vars))
        status = cb_getprestat_c(self._cbstruct, self._env_lp_ptr)
        if status is not None:
            _proc.check_status(self._cbstruct, status[0], from_cb=True)
            pstat = status[1]
            for i in vars:
                if pstat[i] == 0:
                    raise CplexError("Variable removed by presolve: cannot change bounds")
        ind = []
        lu  = ""
        bd  = []
        for i, v in enumerate(vars):
            ind.append(v)
            if lb[i] == ub[i]:
                lu = ''.join([lu, "B"])
                bd.append(lb[i])
            else:
                ind.append(v)
                lu = ''.join([lu, "LU"])
                bd.extend([lb[i], ub[i]])
        cpx_decode = _proc.cpx_decode
        enc = _proc.default_encoding
        status = cb_chgbds(self._cbstruct, ind, cpx_decode(lu, enc), bd)
        _proc.check_status(self._cbstruct, status, from_cb=True)

    def set_solution(self, solution, objective_value = None):
        """Sets a solution to be used as the incumbent.

        solution is either an instance of SparsePair or a sequence of
        length two.  If it is a sequence, the first entry is a
        sequence of variable indices or names whose values are to be
        changed and the second entry is a sequence of floats with the
        corresponding new solution values.  Variables whose indices
        are not specified remain unchanged.

        If objective_value is specified, it is taken as the objective
        value of the new solution.  Otherwise, the objective value is
        computed.
       
        Do not call this method multiple times. 
        Calling it again will overwrite any previously specified solution.
        """
        if isinstance(solution, SparsePair):
            vars = solution.ind
            vals = solution.val
        else:
            vars = solution[0]
            vals = solution[1]
        if len(vars) != len(vals):
            raise CplexError("Inconsistent input data to HeuristicCallback.set_solution")
        vars = list(map(self._conv_col_index, vars))
        for i, v in enumerate(vars):
            self._x[v] = vals[i]
        if objective_value is None:
            objective_value = 0.0
            obj_coef = self.get_objective_coefficients()
            for i, v in enumerate(self._x):
                objective_value += v * obj_coef[i]
        self._objective_value   = objective_value
        self._useraction        = _internal._constants.CPX_CALLBACK_SET
        self._check_feasibility = 1
        self._status            = 0


class SolveCallback(HSCallback):
    """Subclassable class for solve callback classes.

    This callback can be used to solve node relaxations during branch
    and cut search.

    """

    def __init__(self, env):
        """non-public"""
        Callback.__init__(self, env)
        self._cb_type_string  = "solve"
        self._cb_set_function = _proc.setsolvecallbackfunc
        
    def _conv_row_index(self, name):
        """non-public"""
        if isinstance(name, six.string_types):
            return self._get_row_index(name)
        else:
            return name
        
    def set_vectors(self, primal = SparsePair([], []), dual = SparsePair([], [])):
        """Sets the starting vectors for the next solve.

        Deprecated as of version 12.5. Use set_start instead.

        The arguments primal and dual must either be instances of
        SparsePair or sequences of length two.  If they are sequences,
        the first entry is a sequence of indices or names specifying
        the columns or rows whose values are to be set, and the second
        entry is a sequence of floats with the corresponding new
        values.

        If primal is specified but dual is not, no dual values will be
        stored.  If dual is specified but primal is not, no primal
        values will be stored.

        Variables whose indices are not specified will be set to 0.0.

        Note
          If presolve is enabled, attempting to set dual values in
          this method will raise an exception.
        """
        if isinstance(primal, SparsePair):
            var = primal.ind
            x   = primal.val
        else:
            var = primal[0]
            x   = primal[1]
        if isinstance(dual, SparsePair):
            rng = dual.ind
            pi  = dual.val
        else:
            rng = dual[0]
            pi  = dual[1]
        prim = [0.0] * self.get_num_cols()
        dual = [0.0] * self.get_num_rows()
        var = list(map(self._conv_col_index, var))
        rng = list(map(self._conv_row_index, rng))
        for i, val in enumerate(x):
            prim[var[i]] = val
        for i, val in enumerate(pi):
            dual[rng[i]] = val
        if len(var) > 0:
            status = cb_crushx(self._cbstruct, self._env_lp_ptr, prim)
            if status is not None:
                _proc.check_status(self._cbstruct,
                                   status[0], from_cb=True)
                prim = status[1]
        if len(rng) > 0:
            status = cb_crushpi(self._cbstruct, self._env_lp_ptr, dual)
            if status is not None:
                _proc.check_status(self._cbstruct, status, from_cb=True)
                raise CplexError("Presolve must be disabled to set dual vectors in SolveCallback.set_vectors")
        status = cb_copystart(self._cbstruct, prim, dual)
        _proc.check_status(self._cbstruct, status, from_cb=True)

    def set_start(self, primal = SparsePair([], []), dual = SparsePair([], [])):
        """Sets the starting vectors for the next solve.

        The arguments primal and dual must either be instances of
        SparsePair or sequences of length two.  If they are sequences,
        the first entry is a sequence of indices or names specifying
        the columns or rows whose values are to be set, and the second
        entry is a sequence of floats with the corresponding new
        values.

        If primal is specified but dual is not, no dual values will be
        stored.  If dual is specified but primal is not, no primal
        values will be stored.

        Variables whose indices are not specified will be set to 0.0.

        Note
          If presolve is enabled, attempting to set dual values in
          this method will raise an exception.
        """
        if isinstance(primal, SparsePair):
            var = primal.ind
            x   = primal.val
        else:
            var = primal[0]
            x   = primal[1]
        if isinstance(dual, SparsePair):
            rng = dual.ind
            pi  = dual.val
        else:
            rng = dual[0]
            pi  = dual[1]
        prim = [0.0] * self.get_num_cols()
        dual = [0.0] * self.get_num_rows()
        var = list(map(self._conv_col_index, var))
        rng = list(map(self._conv_row_index, rng))
        for i, val in enumerate(x):
            prim[var[i]] = val
        for i, val in enumerate(pi):
            dual[rng[i]] = val
        if len(var) > 0:
            status = cb_crushx(self._cbstruct, self._env_lp_ptr, prim)
            if status is not None:
                _proc.check_status(self._cbstruct,
                                   status[0], from_cb=True)
                prim = status[1]
        if len(rng) > 0:
            status = cb_crushpi(self._cbstruct, self._env_lp_ptr, dual)
            if status is not None:
                _proc.check_status(self._cbstruct,
                                   status, from_cb=True)
                raise CplexError("Presolve must be disabled to set dual vectors in SolveCallback.set_start")
        status = cb_copystart(self._cbstruct, prim, dual)
        _proc.check_status(self._cbstruct, status, from_cb=True)

    def use_solution(self):
        """Tell CPLEX to use the resident solution after calling solve."""
        self._useraction = _internal._constants.CPX_CALLBACK_SET
        self._status     = 0


class IncumbentCallback(MIPCallback):
    """Subclassable class for incumbent callback classes.

    This callback will be used after each new potential incumbent is found.
    If the callback is used to reject incumbents, the user must set 
    the parameter 
    c.parameters_1.preprocessing.reduce either to the value
    1 (one) to restrict presolve to primal reductions only or to 0 (zero)
    to disable all presolve reductions. This setting of the parameter is
    not necessary if the incumbent callback is used for other purposes. 

    Note
      The incumbent callback may be invoked during MIP start processing.
      In that case get_solution_source will return mip_start_solution.
      In this situation the following special consideration applies:

      - MIP start processing occurs very early in the solution process.
        At this point no search tree is setup yet and there are no search
        tree nodes yet.  Consequently, a lot of the callback functions
        that require a node context will fail in this situation.

    """
    
    class solution_source:
        """Attributes defining possible solution sources."""
        node_solution      = _internal._constants.CPX_CALLBACK_MIP_INCUMBENT_NODESOLN
        heuristic_solution = _internal._constants.CPX_CALLBACK_MIP_INCUMBENT_HEURSOLN
        user_solution      = _internal._constants.CPX_CALLBACK_MIP_INCUMBENT_USERSOLN
        mipstart_solution  = _internal._constants.CPX_CALLBACK_MIP_INCUMBENT_MIPSTART

    def __init__(self, env):
        """non-public"""
        Callback.__init__(self, env)
        self._cb_type_string  = "incumbent"
        self._cb_set_function = _proc.setincumbentcallbackfunc
        
    def get_node_data(self):
        """Returns the user handle for the current node.

        Returns None if no handle is set for the node.
        """
        return self._get_node_info(_internal._constants.CPX_CALLBACK_INFO_NODE_USERHANDLE, 0)

    def set_node_data(self,data):
        """Set the user handle for the current node.

        Returns the user handle previously set for this node (or None
        if no handle was set).
        """
        return _proc.callbacksetuserhandle(self._cbstruct, data)

    def get_node_ID(self):
        """Returns the sequence number of the current node."""
        return self._get_node_info(_internal._constants.CPX_CALLBACK_INFO_NODE_SEQNUM_LONG, 0)

    def get_objective_value(self):
        """Returns the objective value of the potential incumbent."""
        return self._objective_value

    def get_linear_slacks(self, *args):
        """Returns a set of linear slacks for the solution at the current node.

        Can be called by four forms.

        self.get_linear_slacks()
          return all linear slack values from the problem at the
          current node.

        self.get_linear_slacks(i)
          i must be a linear constraint name or index.  Returns the
          slack values associated with the linear constraint whose
          index or name is i.

        self.get_linear_slacks(s)
          s must be a sequence of linear constraint names or indices.
          Returns the slack values associated with the linear
          constraints with indices the members of s.  Equivalent to
          [self.get_linear_slacks(i) for i in s]

        self.get_linear_slacks(begin, end)
          begin and end must be linear constraint indices with begin
          <= end or linear constraint names whose indices respect
          this order.  Returns the slack values associated with the
          linear constraints with indices between begin and end,
          inclusive of end.  Equivalent to
          self.get_linear_slacks(range(begin, end + 1)).
        """
        status = cb_slackfromx(self._cbstruct, self._env_lp_ptr, self._x)
        _proc.check_status(self._cbstruct, status[0], from_cb=True)
        slacks = status[1]
        def getslack(a, b = self.get_num_rows() - 1):
            return slacks[a:b+1]
        return apply_freeform_two_args(
            getslack, self._get_row_index, args)
        
    def get_quadratic_slacks(self, *args):
        """Return a set of quadratic slacks for the solution at the current node.

        Can be called by four forms.

        self.get_quadratic_slacks()
          return all quadratic slack values from the problem at the
          current node.

        self.get_quadratic_slacks(i)
          i must be a quadratic constraint name or index.  Returns
          the slack values associated with the quadratic constraint
          whose index or name is i.
          
        self.get_quadratic_slacks(s)
          s must be a sequence of quadratic constraint names or
          indices.  Returns the slack values associated with the
          quadratic constraints with indices the members of s.
          Equivalent to [self.get_quadratic_slacks(i) for i in s]

        self.get_quadratic_slacks(begin, end)
          begin and end must be quadratic constraint indices with
          begin <= end or quadratic constraint names whose indices
          respect this order.  Returns the slack values associated
          with the quadratic constraints with indices between begin
          and end, inclusive of end.  Equivalent to
          self.get_quadratic_slacks(range(begin, end + 1)).
        """
        status = cb_qconstrslackfromx(self._cbstruct, self._env_lp_ptr, self._x)
        _proc.check_status(self._cbstruct, status[0], from_cb=True)
        slacks = status[1]
        def getslack(a, b = self.get_num_quadratic_constraints() - 1):
            return slacks[a:b+1]
        return apply_freeform_two_args(
            getslack, self._get_quad_index, args)

    def get_values(self, *args):
        """Return the potential incumbent solution values.

        There are four forms by which get_values may be called.

        self.get_values()
          returns the entire potential incumbent.

        self.get_values(i)
          i must be a variable index or name.  Returns the potential
          incumbent value of the variable with index i.

        self.get_values(s)
          s must be a sequence of variable indices or names.  Returns
          a list of the potential incumbent values of the variables
          with indices the members of s, in the same order as they
          appear in s.  Equivalent to [self.get_values(i) for i in s]

        self.get_values(begin, end)
          begin and end must be integers with begin <= end or
          variable names with this property.  Returns a list of the
          potential incumbent values of variables with indices
          between begin and end, inclusive of end.  Equivalent to
          self.get_values(range(begin, end + 1))
        """
        def getx(begin, end = self.get_num_cols() - 1):
            return self._x[begin:end + 1]
        return apply_freeform_two_args(
            getx, self._get_col_index, args)

    def get_solution_source(self):
        """Returns the source of the solution for which the incumbent callback was invoked.

        The possible return values are:

        self.solution_source.node_solution: The integral solution is
        the solution to the LP relaxation of a node in the MIP search
        tree.

        self.solution_source.heuristic_solution: The integral solution
        has been found by a CPLEX internal heuristic.

        self.solution_source.user_solution: The integral solution has been
        found by the user in the heuristic callback.

        self.solution_source.mipstart_solution: The integral solution has been
        found during MIP start processing.
        """
        if self._wherefrom() == _internal._constants.CPX_CALLBACK_MIP_INCUMBENT_NODESOLN:
            return self.solution_source.node_solution
        elif self._wherefrom() == _internal._constants.CPX_CALLBACK_MIP_INCUMBENT_HEURSOLN:
            return self.solution_source.heuristic_solution
        elif self._wherefrom() == _internal._constants.CPX_CALLBACK_MIP_INCUMBENT_USERSOLN:
            return self.solution_source.user_solution
        elif self._wherefrom() == _internal._constants.CPX_CALLBACK_MIP_INCUMBENT_MIPSTART:
            return self.solution_source.mipstart_solution
        else:
            raise CplexError("Unexpected wherefrom value in IncumbentCallback.get_solution_source()")
        
        
    def reject(self):
        """Tells Cplex not to use the potential incumbent."""
        self._useraction  = _internal._constants.CPX_CALLBACK_SET
        self._is_feasible = False
    

class NodeCallback(MIPCallback):
    """Subclassable class for node callback classes.

    This callback will be used before CPLEX enters a node, and can select
    a different node to be entered instead.

    """

    def __conditionally_convert(self, which_node):
        if isinstance(which_node, type(())):
            return self.get_node_number(which_node)
        else:
            return which_node

    def __init__(self, env):
        """non-public"""
        Callback.__init__(self, env)
        self._cb_type_string  = "node"
        self._cb_set_function = _proc.setnodecallbackfunc
        
    def get_branch_variable(self, which_node):
        """Returns the index of the variable used to branch at node which_node.

        which_node may either be an integer specifying the index
        number of the desired node, or a 1-tuple whose entry is an
        integer specifying the sequence number of the desired node.
        """
        return self._get_node_info(_internal._constants.CPX_CALLBACK_INFO_NODE_VAR,
                                   self.__conditionally_convert(which_node))

    def get_depth(self, which_node):
        """Returns the depth in the search tree of node which_node.

        which_node may either be an integer specifying the index
        number of the desired node, or a 1-tuple whose entry is an
        integer specifying the sequence number of the desired node.
        """
        return self._get_node_info(_internal._constants.CPX_CALLBACK_INFO_NODE_DEPTH_LONG,
                                   self.__conditionally_convert(which_node))

    def get_estimated_objective_value(self, which_node):
        """Returns the estimated objective function value at node which_node.

        which_node may either be an integer specifying the index
        number of the desired node, or a 1-tuple whose entry is an
        integer specifying the sequence number of the desired node.
        """
        return self._get_node_info(_internal._constants.CPX_CALLBACK_INFO_NODE_ESTIMATE,
                                   self.__conditionally_convert(which_node))

    def get_infeasibility_sum(self, which_node):
        """Returns the sum of infeasibilities at node which_node.

        which_node may either be an integer specifying the index
        number of the desired node, or a 1-tuple whose entry is an
        integer specifying the sequence number of the desired node.
        """
        return self._get_node_info(_internal._constants.CPX_CALLBACK_INFO_NODE_SIINF,
                                   self.__conditionally_convert(which_node))

    def get_num_infeasibilities(self, which_node):
        """Returns the number of infeasibilities at node which_node.

        which_node may either be an integer specifying the index
        number of the desired node, or a 1-tuple whose entry is an
        integer specifying the sequence number of the desired node.
        """
        return self._get_node_info(_internal._constants.CPX_CALLBACK_INFO_NODE_NIINF,
                                   self.__conditionally_convert(which_node))

    def get_node_data(self, which_node):
        """Returns the handle set by the user for node which_node.

        Returns None if no handle was set when the node was created.
        
        which_node may either be an integer specifying the index
        number of the desired node, or a 1-tuple whose entry is an
        integer specifying the sequence number of the desired node.
        """
        return self._get_node_info(_internal._constants.CPX_CALLBACK_INFO_NODE_USERHANDLE,
                                   self.__conditionally_convert(which_node))

    def set_node_data(self, which_node, data):
        """Set the user handle for the specified node.

        Returns the user handle previously set for that node (or None
        if no handle was set).
        """
        return _proc.callbacksetnodeuserhandle(self._cbstruct,
                                               which_node, data)

    def get_node_ID(self, which_node):
        """Returns a one-tuple containing the sequence number of node which_node.

        which_node must be an integer specifying the index
        number of the desired node.
        """
        return (self._get_node_info(_internal._constants.CPX_CALLBACK_INFO_NODE_SEQNUM_LONG, which_node),)

    def get_node_number(self, which_node):
        """Returns the index number of node which_node.
        
        which_node must be a 1-tuple whose entry is an integer
        specifying the sequence number of the desired node.
        """
        return self._get_seq_info(_internal._constants.CPX_CALLBACK_INFO_NODE_NODENUM_LONG, which_node[0])

    def get_objective_value(self, which_node):
        """Returns the objective function value for node which_node.

        which_node may either be an integer specifying the index
        number of the desired node, or a 1-tuple whose entry is an
        integer specifying the sequence number of the desired node.
        """
        return self._get_node_info(_internal._constants.CPX_CALLBACK_INFO_NODE_OBJVAL,
                                   self.__conditionally_convert(which_node))

    def select_node(self, which_node):
        """Tells Cplex to enter node which_node next.

        which_node may either be an integer specifying the index
        number of the desired node, or a 1-tuple whose entry is an
        integer specifying the sequence number of the desired node.
        """
        self._node_number = self.__conditionally_convert(which_node)
        self._useraction = _internal._constants.CPX_CALLBACK_SET
        self._status     = 0


class PresolveCallback(OptimizationCallback):
    """Subclassable class for presolve callback classes.

    This callback will be used during presolve.

    :deprecated: Since 12.7.1.
    """

    def __init__(self, env):
        """non-public"""
        Callback.__init__(self, env)
        self._cb_type_string  = "presolve"
        self._cb_set_function = _proc.setlpcallbackfunc
        deprecated_class(PresolveCallback.__name__, "V12.7.1", stacklevel=3)

    def get_num_aggregations(self):
        """Return the number of aggregations performed."""
        return fast_getcallbackinfo(self._cbstruct, CPX_CALLBACK_INFO_PRESOLVE_AGGSUBST_LONG, CplexSolverError)

    def get_num_modified_coefficients(self):
        """Return the number of modified coefficients."""
        return fast_getcallbackinfo(self._cbstruct, CPX_CALLBACK_INFO_PRESOLVE_COEFFS_LONG, CplexSolverError)

    def get_num_removed_cols(self):
        """Return the number of removed variables."""
        return fast_getcallbackinfo(self._cbstruct, CPX_CALLBACK_INFO_PRESOLVE_COLSGONE, CplexSolverError)

    def get_num_removed_rows(self):
        """Return the number of removed linear constraints."""
        return fast_getcallbackinfo(self._cbstruct, CPX_CALLBACK_INFO_PRESOLVE_ROWSGONE, CplexSolverError)


class TuningCallback(Callback):
    """Subclassable class for tuning callback classes.

    This callback will be used during tuning.

    For general information about tuning callbacks, see that topic
    in the CPLEX User's Manual.

    """

    def __init__(self, env):
        """non-public"""
        Callback.__init__(self, env)
        self._cb_type_string  = "tuning"
        self._cb_set_function = _proc.settuningcallbackfunc
        
    def get_progress(self):
        """Returns the fraction of the tuning process that is done."""
        return fast_getcallbackinfo(self._cbstruct, CPX_CALLBACK_INFO_TUNING_PROGRESS, CplexSolverError)
