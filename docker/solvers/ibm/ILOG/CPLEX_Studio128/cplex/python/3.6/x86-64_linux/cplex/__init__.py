# --------------------------------------------------------------------------
# File: __init__.py
# ---------------------------------------------------------------------------
# Licensed Materials - Property of IBM
# 5725-A06 5725-A29 5724-Y48 5724-Y49 5724-Y54 5724-Y55 5655-Y21
# Copyright IBM Corporation 2008, 2017. All Rights Reserved.
#
# US Government Users Restricted Rights - Use, duplication or
# disclosure restricted by GSA ADP Schedule Contract with
# IBM Corp.
# --------------------------------------------------------------------------

"""The CPLEX Python API.

This package contains classes for accessing CPLEX from the Python
programming language.  The most important class defined by this
package is the Cplex class, which provides methods for creating,
modifying, querying, or solving an optimization problem, and for
querying aspects of a solution.

The exceptions module defines the exception classes that are raised
during abnormal operation by the CPLEX Python API.

The callbacks module within this package defines callback classes that
can be used to alter the behavior of the algorithms used by CPLEX.

The constant infinity, defined in the cplex package, should be used to
set infinite upper and lower bounds.

The classes SparsePair and SparseTriple are used as input and output
classes for sparse vector and sparse matrix output, respectively.  See
the documentation for individual methods for details about the usage
of these classes.
"""


__all__ = ["Cplex", "Aborter", "callbacks", "exceptions", "infinity",
           "SparsePair", "SparseTriple"]
__version__ = "12.8.0.0"

import weakref

from .aborter import Aborter
from . import _internal
from . import callbacks
from . import exceptions
from ._internal._aux_functions import deprecated
from ._internal._matrices import SparsePair, SparseTriple
from ._internal import _procedural as _proc
from . import six

infinity = _internal._constants.CPX_INFBOUND


class Stats(object):
    """A class whose data members reflect statistics about a CPLEX problem.

    An instance of this class is returned by the Cplex.get_stats() method.

    The __str__ method of this class displays the problem statistics
    in human readable form.

    An instance of this class always has the following integer members:

    num_variables
    num_nonnegative
    num_fixed
    num_boxed
    num_free
    num_other
    num_binary
    num_integer
    num_semicontinuous
    num_semiinteger
    num_quadratic_variables
    num_linear_objective_nz
    num_quadratic_objective_nz
    num_linear_constraints
    num_linear_less
    num_linear_equal
    num_linear_greater
    num_linear_range
    num_linear_nz
    num_linear_rhs_nz
    num_indicator_constraints
    num_indicator_less
    num_indicator_equal
    num_indicator_greater
    num_indicator_complemented
    num_indicator_nz
    num_indicator_rhs_nz
    num_quadratic_constraints
    num_quadratic_less
    num_quadratic_greater
    num_quadratic_linear_nz
    num_quadratic_nz
    num_quadratic_rhs_nz
    num_SOS_constraints
    num_SOS1
    num_SOS1_members
    type_SOS1
    num_SOS2
    num_SOS2_members
    type_SOS2
    num_lazy_constraints
    num_lazy_nnz
    num_lazy_lt
    num_lazy_eq
    num_lazy_gt
    num_lazy_rhs_nnz
    num_user_cuts
    num_user_cuts_nnz
    num_user_cuts_lt
    num_user_cuts_eq
    num_user_cuts_gt
    num_user_cuts_rhs_nnz
    num_pwl_constraints
    num_pwl_breaks

    An instance of this class always has the following float members:

    min_lower_bound
    max_upper_bound
    min_linear_objective
    max_linear_objective
    min_linear_constraints
    max_linear_constraints
    min_linear_constraints_rhs
    max_linear_constraints_rhs

    An instance of this class returned by an instance of the Cplex
    class with a quadratic objective also has the following float
    members:

    min_quadratic_objective
    max_quadratic_objective

    An instance of this class returned by an instance of the Cplex
    class with ranged constraints also has the following float
    members:

    min_linear_range
    max_linear_range

    An instance of this class returned by an instance of the Cplex
    class with quadratic constraints also has the following float
    members:

    min_quadratic_linear
    max_quadratic_linear
    min_quadratic
    max_quadratic
    min_quadratic_rhs
    max_quadratic_rhs

    An instance of this class returned by an instance of the Cplex
    class with indicator constraints also has the following float
    members:

    min_indicator
    max_indicator
    min_indicator_rhs
    max_indicator_rhs

    An instance of this class returned by an instance of the Cplex
    class with lazy constraints also has the following float members:

    min_lazy_constraint
    max_lazy_constraint
    min_lazy_constraint_rhs
    max_lazy_constraint_rhs

    An instance of this class returned by an instance of the Cplex
    class with user cuts also has the following float members:

    min_user_cut
    max_user_cut
    min_user_cut_rhs
    max_user_cut_rhs
    """

    def __init__(self, c):
        self.name = c.get_problem_name()
        self.sense = c.objective.sense[c.objective.get_sense()].capitalize()

        raw_stats = _proc.getprobstats(c._env._e, c._lp)

        # counts of problem objects
        # variable data
        self.num_variables = raw_stats[1]
        self.num_nonnegative = raw_stats[9]
        self.num_fixed = raw_stats[11]
        self.num_boxed = raw_stats[12]
        self.num_free = raw_stats[10]
        self.num_other = raw_stats[13]
        self.num_binary = raw_stats[14]
        self.num_integer = raw_stats[15]
        self.num_semicontinuous = raw_stats[16]
        self.num_semiinteger = raw_stats[17]
        self.num_quadratic_variables = raw_stats[18]
        self.num_linear_objective_nz = raw_stats[2]
        self.num_quadratic_objective_nz = raw_stats[19]

        # linear constraint data
        self.num_linear_constraints = raw_stats[0]
        self.num_linear_less = raw_stats[7]
        self.num_linear_equal = raw_stats[5]
        self.num_linear_greater = raw_stats[6]
        self.num_linear_range = raw_stats[8]
        self.num_linear_nz = raw_stats[4]
        self.num_linear_rhs_nz = raw_stats[3]

        # indicator data
        self.num_indicator_constraints = raw_stats[26]
        self.num_indicator_less = raw_stats[30]
        self.num_indicator_equal = raw_stats[31]
        self.num_indicator_greater = raw_stats[32]
        self.num_indicator_complemented = raw_stats[29]
        self.num_indicator_nz = raw_stats[28]
        self.num_indicator_rhs_nz = raw_stats[27]

        # quadratic constraints
        self.num_quadratic_constraints = raw_stats[20]
        self.num_quadratic_less = raw_stats[22]
        self.num_quadratic_greater = raw_stats[23]
        self.num_quadratic_linear_nz = raw_stats[25]
        self.num_quadratic_nz = raw_stats[24]
        self.num_quadratic_rhs_nz = raw_stats[21]

        # SOS data
        self.num_SOS_constraints = raw_stats[63]
        sos_string_list = ["",
                           "all continuous",
                           "all binary",
                           "all integer",
                           "continuous, binary, and integer",
                           "continuous and binary",
                           "continuous and integer",
                           "binary and integer", ]
        self.num_SOS1 = raw_stats[64]
        self.num_SOS1_members = raw_stats[65]
        self.type_SOS1 = sos_string_list[raw_stats[66]]
        self.num_SOS2 = raw_stats[67]
        self.num_SOS2_members = raw_stats[68]
        self.type_SOS2 = sos_string_list[raw_stats[69]]

        # lazy constraint data
        self.num_lazy_constraints = raw_stats[74]
        self.num_lazy_nnz = raw_stats[75]
        self.num_lazy_lt = raw_stats[72]
        self.num_lazy_eq = raw_stats[73]
        self.num_lazy_gt = raw_stats[71]
        self.num_lazy_rhs_nnz = raw_stats[70]

        # user cut data
        self.num_user_cuts = raw_stats[80]
        self.num_user_cuts_nnz = raw_stats[81]
        self.num_user_cuts_lt = raw_stats[78]
        self.num_user_cuts_eq = raw_stats[79]
        self.num_user_cuts_gt = raw_stats[77]
        self.num_user_cuts_rhs_nnz = raw_stats[76]

        # PWL constraints
        self.num_pwl_constraints = raw_stats[82]
        self.num_pwl_breaks = raw_stats[83]

        # min and max data
        # variables
        self.min_lower_bound = raw_stats[41]
        self.max_upper_bound = raw_stats[42]
        self.min_linear_objective = raw_stats[39]
        self.max_linear_objective = raw_stats[40]
        if self.num_quadratic_objective_nz > 0:
            self.min_quadratic_objective = raw_stats[43]
            self.max_quadratic_objective = raw_stats[44]

        # linear constraints
        self.min_linear_constraints = raw_stats[34]
        self.max_linear_constraints = raw_stats[33]
        self.min_linear_constraints_rhs = raw_stats[35]
        self.max_linear_constraints_rhs = raw_stats[36]
        if self.num_linear_range > 0:
            self.min_linear_range = raw_stats[37]
            self.max_linear_range = raw_stats[38]

        # quadratic constraints
        if self.num_quadratic_constraints > 0:
            self.min_quadratic_linear = raw_stats[47]
            self.max_quadratic_linear = raw_stats[48]
            self.min_quadratic = raw_stats[45]
            self.max_quadratic = raw_stats[46]
            self.min_quadratic_rhs = raw_stats[49]
            self.max_quadratic_rhs = raw_stats[50]

        # indicator constraints
        if self.num_indicator_constraints > 0:
            self.min_indicator = raw_stats[51]
            self.max_indicator = raw_stats[52]
            self.min_indicator_rhs = raw_stats[53]
            self.max_indicator_rhs = raw_stats[54]

        # lazy constraints
        if self.num_lazy_constraints > 0:
            self.min_lazy_constraint = raw_stats[55]
            self.max_lazy_constraint = raw_stats[56]
            self.min_lazy_constraint_rhs = raw_stats[57]
            self.max_lazy_constraint_rhs = raw_stats[58]

        # user cuts
        if self.num_user_cuts > 0:
            self.min_user_cut = raw_stats[59]
            self.max_user_cut = raw_stats[60]
            self.min_user_cut_rhs = raw_stats[61]
            self.max_user_cut_rhs = raw_stats[62]

    def __str__(self):
        allinf = "all infinite"
        allzero = "all zero"
        sep = ",  "
        ret = ""
        ret = ret + "Problem name         : " + self.name + "\n"
        ret = ret + "Objective sense      : " + self.sense + "\n"
        ret = ret + "Variables            : %7d" % self.num_variables
        if self.num_nonnegative != self.num_variables or self.num_quadratic_variables > 0:
            ret = ret + "  ["
            sep_ind = 0
            if self.num_nonnegative > 0:
                if sep_ind:
                    ret = ret + sep
                ret = ret + "Nneg: %d" % self.num_nonnegative
                sep_ind = 1
            if self.num_fixed > 0:
                if sep_ind:
                    ret = ret + sep
                ret = ret + "Fix: %d" % self.num_fixed
                sep_ind = 1
            if self.num_boxed > 0:
                if sep_ind:
                    ret = ret + sep
                ret = ret + "Box: %d" % self.num_boxed
                sep_ind = 1
            if self.num_free > 0:
                if sep_ind:
                    ret = ret + sep
                ret = ret + "Free: %d" % self.num_free
                sep_ind = 1
            if self.num_binary > 0:
                if sep_ind:
                    ret = ret + sep
                ret = ret + "Binary: %d" % self.num_binary
                sep_ind = 1
            if self.num_integer > 0:
                if sep_ind:
                    ret = ret + sep
                ret = ret + "General Integer: %d" % self.num_integer
                sep_ind = 1
            if self.num_semicontinuous > 0:
                if sep_ind:
                    ret = ret + sep
                ret = ret + "Semi-continuous: %d" % self.num_semicontinuous
                sep_ind = 1
            if self.num_semiinteger > 0:
                if sep_ind:
                    ret = ret + sep
                ret = ret + "Semi-integer: %d" % self.num_semiinteger
                sep_ind = 1
            if self.num_other > 0:
                if sep_ind:
                    ret = ret + sep
                ret = ret + "Other: %d" % self.num_other
                sep_ind = 1
            if self.num_quadratic_variables > 0:
                if sep_ind:
                    ret = ret + sep
                ret = ret + "Qobj: %d" % self.num_quadratic_variables
                sep_ind = 1
            ret = ret + "]"
        ret = ret + "\n"
        ret = ret + "Objective nonzeros   : %7d" % self.num_linear_objective_nz + "\n"
        if self.num_quadratic_objective_nz > 0:
            ret = ret + "Objective Q nonzeros : %7d" % self.num_quadratic_objective_nz + "\n"
        ret = ret + "Linear constraints   : %7d" % self.num_linear_constraints
        if self.num_linear_constraints > 0:
            ret = ret + "  ["
            sep_ind = 0
            if self.num_linear_less > 0:
                if sep_ind:
                    ret = ret + sep
                ret = ret + "Less: %d" % self.num_linear_less
                sep_ind = 1
            if self.num_linear_greater > 0:
                if sep_ind:
                    ret = ret + sep
                ret = ret + "Greater: %d" % self.num_linear_greater
                sep_ind = 1
            if self.num_linear_equal > 0:
                if sep_ind:
                    ret = ret + sep
                ret = ret + "Equal: %d" % self.num_linear_equal
                sep_ind = 1
            if self.num_linear_range > 0:
                if sep_ind:
                    ret = ret + sep
                ret = ret + "Range: %d" % self.num_linear_range
                sep_ind = 1
            ret = ret + "]"
        ret = ret + "\n"
        ret = ret + "  Nonzeros           : %7d\n" % self.num_linear_nz
        ret = ret + "  RHS nonzeros       : %7d\n" % self.num_linear_rhs_nz
        if self.num_indicator_constraints > 0:
            ret = ret + \
                "Indicator constraints: %7d  [" % self.num_indicator_constraints
            sep_ind = 0
            if self.num_indicator_less > 0:
                if sep_ind:
                    ret = ret + sep
                ret = ret + "Less: %d" % self.num_indicator_less
                sep_ind = 1
            if self.num_indicator_equal > 0:
                if sep_ind:
                    ret = ret + sep
                ret = ret + "Equal: %d" % self.num_indicator_equal
                sep_ind = 1
            if self.num_indicator_greater > 0:
                if sep_ind:
                    ret = ret + sep
                ret = ret + "Greater: %d" % self.num_indicator_greater
                sep_ind = 1
            ret = ret + "]\n"
            if self.num_indicator_complemented:
                ret = ret + "  Complemented       : %7d\n" % self.num_indicator_complemented
                ret = ret + "  Nonzeros           : %7d\n" % self.num_indicator_nz
                ret = ret + "  RHS nonzeros       : %7d\n" % self.num_indicator_rhs_nz
        if self.num_quadratic_constraints > 0:
            ret = ret + \
                "Quadratic constraints: %7d  [" % self.num_quadratic_constraints
            sep_ind = 0
            if self.num_quadratic_less > 0:
                if sep_ind:
                    ret = ret + sep
                ret = ret + "Less: %d" % self.num_quadratic_less
                sep_ind = 1
            if self.num_quadratic_greater > 0:
                if sep_ind:
                    ret = ret + sep
                ret = ret + "Greater: %d" % self.num_quadratic_greater
                sep_ind = 1
            ret = ret + "]\n"
            ret = ret + "  Linear terms       : %7d\n" % self.num_quadratic_linear_nz
            ret = ret + "  Quadratic terms    : %7d\n" % self.num_quadratic_nz
            ret = ret + "  RHS nonzeros       : %7d\n" % self.num_quadratic_rhs_nz
        if self.num_SOS_constraints > 0:
            ret = ret + \
                "SOS                  : %7d  [" % self.num_SOS_constraints
            sep_ind = 0
            if self.num_SOS1 > 0:
                if sep_ind:
                    ret = ret + sep
                ret = ret + "SOS1: %d, %d members" % (self.num_SOS1,
                                                      self.num_SOS1_members)
                if self.type_SOS1:
                    ret += ", %s" % self.type_SOS1
                sep_ind = 1
            if self.num_SOS2 > 0:
                if sep_ind:
                    ret = ret + ";  "
                ret = ret + "SOS2: %d, %d members" % (self.num_SOS2,
                                                      self.num_SOS2_members)
                if self.type_SOS2:
                    ret += ", %s" % self.type_SOS2
                sep_ind = 1
            ret = ret + "]\n"
        if self.num_pwl_constraints > 0:
            ret = ret + \
                "PWL                  : %7d  [" % self.num_pwl_constraints
            if self.num_pwl_breaks > 0:
                ret = ret + "Breaks: %d" % self.num_pwl_breaks
            ret = ret + "]\n"
        ret = ret + "\n"
        if self.min_lower_bound > -infinity:
            valstr1 = str("%#-15.7g" % self.min_lower_bound)
        else:
            valstr1 = allinf
        if self.max_upper_bound < infinity:
            valstr2 = str("%#-15.7g" % self.max_upper_bound)
        else:
            valstr2 = allinf
        ret = ret + \
            "Variables            : Min LB: %-15s  Max UB: %-15s\n" % (
                valstr1, valstr2)
        if self.min_linear_objective > -infinity:
            valstr1 = str("%#-15.7g" % self.min_linear_objective)
        else:
            valstr1 = allzero
        if self.max_linear_objective < infinity:
            valstr2 = str("%#-15.7g" % self.max_linear_objective)
        else:
            valstr2 = allzero
        ret = ret + \
            "Objective nonzeros   : Min   : %-15s  Max   : %-15s\n" % (
                valstr1, valstr2)
        if self.num_quadratic_objective_nz > 0:
            if self.min_quadratic_objective > -infinity:
                valstr1 = str("%#-15.7g" % self.min_quadratic_objective)
            else:
                valstr1 = allzero
            if self.max_quadratic_objective < infinity:
                valstr2 = str("%#-15.7g" % self.max_quadratic_objective)
            else:
                valstr2 = allzero
            ret = ret + \
                "Objective Q nonzeros : Min   : %-15s  Max   : %-15s\n" % (
                    valstr1, valstr2)
        ret = ret + "Linear constraints   :\n"
        if self.min_linear_constraints > -infinity:
            valstr1 = str("%#-15.7g" % self.min_linear_constraints)
        else:
            valstr1 = allzero
        if self.max_linear_constraints < infinity:
            valstr2 = str("%#-15.7g" % self.max_linear_constraints)
        else:
            valstr2 = allzero
        ret = ret + \
            "  Nonzeros           : Min   : %-15s  Max   : %-15s\n" % (
                valstr1, valstr2)
        if self.min_linear_constraints_rhs > -infinity:
            valstr1 = str("%#-15.7g" % self.min_linear_constraints_rhs)
        else:
            valstr1 = allzero
        if self.max_linear_constraints_rhs < infinity:
            valstr2 = str("%#-15.7g" % self.max_linear_constraints_rhs)
        else:
            valstr2 = allzero
        ret = ret + \
            "  RHS nonzeros       : Min   : %-15s  Max   : %-15s\n" % (
                valstr1, valstr2)
        if self.num_linear_range > 0:
            ret = ret + "  Range values       : Min   : %#-15.7g  Max   : %#-15.7g\n" % (
                self.min_linear_range, self.max_linear_range)
        if self.num_quadratic_constraints > 0:
            ret = ret + "Quadratic constraints:\n"
            if self.min_quadratic_linear > -infinity:
                valstr1 = str("%#-15.7g" % self.min_quadratic_linear)
            else:
                valstr1 = allzero
            if self.max_quadratic_linear < infinity:
                valstr2 = str("%#-15.7g" % self.max_quadratic_linear)
            else:
                valstr2 = allzero
            ret = ret + \
                "  Linear terms       : Min   : %-15s  Max   : %-15s\n" % (
                    valstr1, valstr2)
            if self.min_quadratic > -infinity:
                valstr1 = str("%#-15.7g" % self.min_quadratic)
            else:
                valstr1 = allzero
            if self.max_quadratic < infinity:
                valstr2 = str("%#-15.7g" % self.max_quadratic)
            else:
                valstr2 = allzero
            ret = ret + \
                "  Quadratic terms    : Min   : %-15s  Max   : %-15s\n" % (
                    valstr1, valstr2)
            if self.min_quadratic_rhs > -infinity:
                valstr1 = str("%#-15.7g" % self.min_quadratic_rhs)
            else:
                valstr1 = allzero
            if self.max_quadratic_rhs < infinity:
                valstr2 = str("%#-15.7g" % self.max_quadratic_rhs)
            else:
                valstr2 = allzero
            ret = ret + \
                "  RHS nonzeros       : Min   : %-15s  Max   : %-15s\n" % (
                    valstr1, valstr2)
        if self.num_indicator_constraints > 0:
            ret = ret + "Indicator constraints:\n"
            if self.min_indicator > -infinity:
                valstr1 = str("%#-15.7g" % self.min_indicator)
            else:
                valstr1 = allzero
            if self.max_indicator < infinity:
                valstr2 = str("%#-15.7g" % self.max_indicator)
            else:
                valstr2 = allzero
            ret = ret + \
                "  Nonzeros           : Min   : %-15s  Max   : %-15s\n" % (
                    valstr1, valstr2)
            if self.min_indicator_rhs > -infinity:
                valstr1 = str("%#-15.7g" % self.min_indicator_rhs)
            else:
                valstr1 = allzero
            if self.max_indicator_rhs < infinity:
                valstr2 = str("%#-15.7g" % self.max_indicator_rhs)
            else:
                valstr2 = allzero
            ret = ret + \
                "  RHS nonzeros       : Min   : %-15s  Max   : %-15s\n" % (
                    valstr1, valstr2)
        if self.num_lazy_constraints > 0:
            ret = ret + "Lazy constraints     :\n"
            if self.min_lazy_constraint > -infinity:
                valstr1 = str("%#-15.7g" % self.min_lazy_constraint)
            else:
                valstr1 = allzero
            if self.max_lazy_constraint < infinity:
                valstr2 = str("%#-15.7g" % self.max_lazy_constraint)
            else:
                valstr2 = allzero
            ret = ret + \
                "  Nonzeros           : Min   : %-15s  Max   : %-15s\n" % (
                    valstr1, valstr2)
            if self.min_lazy_constraint_rhs > -infinity:
                valstr1 = str("%#-15.7g" % self.min_lazy_constraint_rhs)
            else:
                valstr1 = allzero
            if self.max_lazy_constraint_rhs < infinity:
                valstr2 = str("%#-15.7g" % self.max_lazy_constraint_rhs)
            else:
                valstr2 = allzero
            ret = ret + \
                "  RHS nonzeros       : Min   : %-15s  Max   : %-15s\n" % (
                    valstr1, valstr2)
        if self.num_user_cuts > 0:
            ret = ret + "User cuts            :\n"
            if self.min_user_cut > -infinity:
                valstr1 = str("%#-15.7g" % self.min_user_cut)
            else:
                valstr1 = allzero
            if self.max_user_cut < infinity:
                valstr2 = str("%#-15.7g" % self.max_user_cut)
            else:
                valstr2 = allzero
            ret = ret + \
                "  Nonzeros           : Min   : %-15s  Max   : %-15s\n" % (
                    valstr1, valstr2)
            if self.min_user_cut_rhs > -infinity:
                valstr1 = str("%#-15.7g" % self.min_user_cut_rhs)
            else:
                valstr1 = allzero
            if self.max_user_cut_rhs < infinity:
                valstr2 = str("%#-15.7g" % self.max_user_cut_rhs)
            else:
                valstr2 = allzero
            ret = ret + \
                "  RHS nonzeros       : Min   : %-15s  Max   : %-15s\n" % (
                    valstr1, valstr2)
        return ret


class Cplex(object):
    """A class encapsulating a CPLEX Problem.

    An instance of the Cplex class provides methods for creating,
    modifying, and querying an optimization problem, solving it, and
    querying aspects of the solution.

    Most of the methods are provided within categories of methods: for
    example, methods for adding, modifying, and querying data
    associated with variables are within the Cplex.variables category,
    and methods for querying the solution are within the
    Cplex.solution category.

    """

    problem_type = _internal.ProblemType()
    """See `_internal.ProblemType()` """

    def __init__(self, *args):
        """Constructor of the Cplex class.

        The Cplex constructor accepts four types of argument lists.

        cpx = cplex.Cplex()
        cpx is a new problem with no data

        cpx = cplex.Cplex("filename")
        cpx is a new problem containing the data in filename.  If
        filename does not exist, an exception is raised.

        cpx = cplex.Cplex("filename", "filetype")
        same as form 2, but cplex reads the file filename as a file of
        type filetype, rather than inferring the file type from its
        extension.

        cpx = cplex.Cplex(old_cpx)
        cpx contains the same problem data as old_cpx, but is a
        different object and contains no solution data.  Future
        changes to one do not affect the other.

        The Cplex object is a context manager and can be used, like so:

        with cplex.Cplex() as cpx:
            # do stuff
            cpx.solve()

        When the with block is finished, the end() method will be called
        automatically.
        """
        # Declare and initialize attributes
        self._disposed = False
        self._aborter = None
        self._env = None
        self._lp = None
        # Initialize data strucutures associated with CPLEX
        if len(args) > 2:
            raise exceptions.CplexError("Too many arguments to Cplex()")
        if len(args) > 0 and isinstance(args[-1], _internal.Environment):
            raise exceptions.CplexError("shared Environment not supported")
        else:
            env = _internal.Environment()
        if len(args) > 0 and isinstance(args[0], Cplex):
            self.__copy_init(args[0], env)
        else:
            if len(args) > 0 and isinstance(args[0], six.string_types):
                filename = args[0]
                filetype = ""
                if len(args) > 1 and isinstance(args[1], six.string_types):
                    filetype = args[1]
                self._lp = _proc.createprob(
                    env._e, filename, enc=env._apienc)
                _proc.readcopyprob(env._e, self._lp, filename, filetype,
                                   enc=env._apienc)
            else:
                self._lp = _proc.createprob(
                    env._e, "", enc=env._apienc)
        self._env = env
        self._env_lp_ptr = _proc.pack_env_lp_ptr(self._env._e, self._lp)

        self.parameters = env.parameters
        """See `_internal._parameter_classes.RootParameterGroup` """
        self.parameters._cplex = weakref.proxy(self)

        self.variables = _internal._subinterfaces.VariablesInterface(self)
        """See `_internal._subinterfaces.VariablesInterface()` """

        self.linear_constraints = _internal._subinterfaces.LinearConstraintInterface(
            self)
        """See `_internal._subinterfaces.LinearConstraintInterface()` """

        self.quadratic_constraints = _internal._subinterfaces.QuadraticConstraintInterface(
            self)
        """See `_internal._subinterfaces.QuadraticConstraintInterface()` """

        self.indicator_constraints = _internal._subinterfaces.IndicatorConstraintInterface(
            self)
        """See `_internal._subinterfaces.IndicatorConstraintInterface()` """

        self.SOS = _internal._subinterfaces.SOSInterface(self)
        """See `_internal._subinterfaces.SOSInterface()` """

        self.objective = _internal._subinterfaces.ObjectiveInterface(self)
        """See `_internal._subinterfaces.ObjectiveInterface()` """

        self.MIP_starts = _internal._subinterfaces.MIPStartsInterface(self)
        """See `_internal._subinterfaces.MIPStartsInterface()` """

        self.solution = _internal._subinterfaces.SolutionInterface(self)
        """See `_internal._subinterfaces.SolutionInterface()` """

        self.presolve = _internal._subinterfaces.PresolveInterface(self)
        """See `_internal._subinterfaces.PresolveInterface()` """

        self.order = _internal._subinterfaces.OrderInterface(self)
        """See `_internal._subinterfaces.OrderInterface()` """

        self.conflict = _internal._subinterfaces.ConflictInterface(self)
        """See `_internal._subinterfaces.ConflictInterface()` """

        self.advanced = _internal._subinterfaces.AdvancedCplexInterface(self)
        """See `_internal._subinterfaces.AdvancedCplexInterface()` """

        self.start = _internal._subinterfaces.InitialInterface(self)
        """See `_internal._subinterfaces.InitialInterface()` """

        self.feasopt = _internal._subinterfaces.FeasoptInterface(self)
        """See `_internal._subinterfaces.FeasoptInterface()` """

        self.long_annotations = _internal._anno.LongAnnotationInterface(self)
        """See `_internal._anno.LongAnnotationInterface()`"""

        self.double_annotations = _internal._anno.DoubleAnnotationInterface(
            self)
        """See `_internal._anno.DoubleAnnotationInterface()`"""

        self.pwl_constraints = _internal._pwl.PWLConstraintInterface(self)
        """See `_internal._pwl.PWLConstraintInterface()`"""

    def end(self):
        """Releases the Cplex object.

        Frees all data structures associated with CPLEX.  After a call of
        the method end(), the invoking Cplex object and all objects that
        have been created with it (such as variables and constraints) can
        no longer be used.  Attempts to use them subsequently raise a
        ValueError.
        """
        if self._disposed:
            return
        self._disposed = True
        # free prob
        if self._env and self._lp:
            try:
                _proc.setgenericcallbackfunc(self._env._e, self._lp, 0, None)
            except:  # Ignore exception in destructor, in particular we may
                pass  # get CPXERR_NOT_ONE_PROBLEM here.
            _proc.freeprob(self._env._e, self._lp)
        # free aborter if necc.
        if self._aborter:
            self.remove_aborter()
        # free env
        if self._env:
            self._env._end()

    def __del__(self):
        """non-public"""
        self.end()

    def __enter__(self):
        """Enter the runtime context related to this object.

        The with statement will bind this method's return value to the
        target specified in the as clause of the statement, if any.

        Cplex objects return themselves.
        """
        return self

    def __exit__(self, exc_type, exc_value, traceback):
        """Exit the runtime context.

        When we exit the with block, the end() method is called.
        """
        self.end()

    def __copy_init(self, old_cplex, env):
        """non-public"""
        self._lp = _proc.cloneprob(env._e, old_cplex._lp)

    def read(self, filename, filetype=""):
        """Reads a problem from file.

        The first argument is a string specifying the filename from
        which the problem will be read.

        If the method is called with two arguments, 
        the second argument is a string
        specifying the file type.  If this argument is omitted,
        filetype is taken to be the extension of the filename.

        >>> import cplex
        >>> c = cplex.Cplex()
        >>> out = c.set_results_stream(None)
        >>> out = c.set_log_stream(None)
        >>> c.read("lpex.mps")
        """
        _proc.readcopyprob(self._env._e, self._lp, filename, filetype,
                           enc=self._env._apienc)

    def write(self, filename, filetype=""):
        """Writes a problem to file.

        The first argument is a string specifying the filename to
        which the problem will be written.

        If the filename ends with .bz2 (for BZip2) or .gz (for GNU Zip),
        a compressed file is written.

        If the method is called with two arguments, 
        the second argument is a string
        specifying the file type.  If this argument is omitted,
        filetype is taken to be the extension of the filename.

        If filetype is any of "sav", "mps", "lp", the problem is
        written in the corresponding format.  If filetype is either
        "rew" or "rlp" the problem is written with generic names in
        mps or lp format, respectively.  If filetype is "alp" the
        problem is written with generic names in lp format, where the
        variable names are annotated to indicate the type and bounds
        of each variable.

        If filetype is "dua", the dual problem is written to file.  If
        filetype is "emb", an embedded network problem is written to
        file.  If filetype is "ppe", the perturbed problem is written
        to file.  If filetype is "dpe", the perturbed dual problem is
        written to file.

        For documentation of the file types, see the CPLEX File Format
        Reference Manual.
        """
        if self._is_special_filetype(filename, filetype, 'dua'):
            _proc.dualwrite(self._env._e, self._lp, filename,
                            enc=self._env._apienc)
        elif self._is_special_filetype(filename, filetype, 'emb'):
            _proc.embwrite(self._env._e, self._lp, filename,
                           enc=self._env._apienc)
        elif self._is_special_filetype(filename, filetype, 'dpe'):
            epsilon = self.parameters.simplex.perturbation.constant.get()
            _proc.dperwrite(self._env._e, self._lp, filename, epsilon,
                            enc=self._env._apienc)
        elif self._is_special_filetype(filename, filetype, 'ppe'):
            epsilon = self.parameters.simplex.perturbation.constant.get()
            _proc.pperwrite(self._env._e, self._lp, filename, epsilon,
                            enc=self._env._apienc)
        else:
            _proc.writeprob(self._env._e, self._lp, filename, filetype,
                            enc=self._env._apienc)

    def _is_special_filetype(self, filename, filetype, ext):
        if filetype is None or filetype == "":
            for extra_ext in ('', '.gz', '.bz2'):
                if (isinstance(filename, six.string_types) and
                        filename.endswith('.' + ext + extra_ext)):
                    return True
        else:
            if filetype == ext:
                return True
        return False

    def read_annotations(self, filename):
        """Reads annotations from a file.

        Example usage:

        >>> import cplex
        >>> c = cplex.Cplex()
        >>> idx = c.long_annotations.add('ann1', 0)
        >>> objtype = c.long_annotations.object_type.variable
        >>> indices = c.variables.add(names=['v1', 'v2', 'v3'])
        >>> c.long_annotations.set_values(idx, objtype,
        ...                               [(i, 1) for i in indices])
        >>> idx = c.double_annotations.add('ann1', 0)
        >>> objtype = c.double_annotations.object_type.variable
        >>> indices = c.variables.add(names=['v1', 'v2', 'v3'])
        >>> c.double_annotations.set_values(idx, objtype,
        ...                                 [(i, 1) for i in indices])
        >>> c.write_annotations('example.ann')
        >>> c.long_annotations.delete()
        >>> c.double_annotations.delete()
        >>> c.long_annotations.get_num()
        0
        >>> c.double_annotations.get_num()
        0
        >>> c.read_annotations('example.ann')
        >>> c.long_annotations.get_num()
        1
        >>> c.double_annotations.get_num()
        1
        """
        _proc.readcopyanno(self._env._e, self._lp, filename,
                           enc=self._env._apienc)

    def write_annotations(self, filename):
        """Writes the annotations to a file.

        Example usage:

        >>> import cplex
        >>> c = cplex.Cplex()
        >>> idx = c.long_annotations.add('ann1', 0)
        >>> objtype = c.long_annotations.object_type.variable
        >>> indices = c.variables.add(names=['v1', 'v2', 'v3'])
        >>> c.long_annotations.set_values(idx, objtype,
        ...                               [(i, 1) for i in indices])
        >>> c.write_annotations('example.ann')
        """
        _proc.writeanno(self._env._e, self._lp, filename,
                        enc=self._env._apienc)

    def write_benders_annotation(self, filename):
        """Writes the annotation of the auto-generated decomposition.

        Writes the annotation of the decompostion CPLEX automatically
        generates for the model of the CPLEX problem object to the
        specified file.

        Example usage:

        >>> import cplex
        >>> c = cplex.Cplex()
        >>> out = c.set_results_stream(None)
        >>> out = c.set_log_stream(None)
        >>> c.read('UFL_25_35_1.mps')
        >>> c.write_benders_annotation('UFL_25_35_1.ann')
        """
        _proc.writebendersanno(self._env._e, self._lp, filename,
                               enc=self._env._apienc)

    def get_problem_type(self):
        """Returns the problem type.

        The return value is an attribute of self.problem_type.

        >>> import cplex
        >>> c = cplex.Cplex()
        >>> out = c.set_results_stream(None)
        >>> out = c.set_log_stream(None)
        >>> c.read("lpex.mps")
        >>> c.get_problem_type()
        0
        >>> c.problem_type[c.get_problem_type()]
        'LP'
        """
        return _proc.getprobtype(self._env._e, self._lp)

    def set_problem_type(self, type, soln=None):
        """Changes the problem type.

        If only one argument is given, that argument specifies the new
        problem type.  It must be one of the following:

        Cplex.problem_type.LP
        Cplex.problem_type.MILP
        Cplex.problem_type.fixed_MILP
        Cplex.problem_type.QP
        Cplex.problem_type.MIQP
        Cplex.problem_type.fixed_MIQP
        Cplex.problem_type.QCP
        Cplex.problem_type.MIQCP

        If an optional second argument is given, it is taken to be an
        identifier of a member of the solution pool.  In this case,
        the first argument must be one of the following:

        Cplex.problem_type.fixed_MILP
        Cplex.problem_type.fixed_MIQP
        """
        if soln is None:
            _proc.chgprobtype(self._env._e, self._lp, type)
        else:
            _proc.chgprobtypesolnpool(self._env._e, self._lp, type, soln)

    def copy_vmconfig(self, xmlstring):
        """Read a virtual machine configuration from a string and install it in this instance.

        The content of the string passed to this function must conform to the
        VMC file specification.
        If the string can be successfully parsed, then the virtual machine
        configuration specified by it is installed in this instance.
        In case of error, a previously installed virtual machine configuration
        is not touched.
        """
        _proc.copyvmconfig(self._env._e, xmlstring)

    def read_copy_vmconfig(self, filename):
        """Read a virtual machine configuration from a file and install it in this instance.

        The filename argument to this function must specify a file that
        conforms to the VMC file format.
        If the file can be successfully parsed, then the virtual machine
        configuration specified by it is installed in this instance.
        In case of error, a previously installed virtual machine configuration
        is not touched.
        """
        _proc.readcopyvmconfig(self._env._e, filename,
                               enc=self._env._apienc)

    def del_vmconfig(self):
        """Delete the virtual machine configuration in this instance (if there is any)."""
        _proc.delvmconfig(self._env._e)

    def has_vmconfig(self):
        """Test whether this instance has a virtual machine configuration installed."""
        return _proc.hasvmconfig(self._env._e)

    def _is_MIP(self):
        """non-public"""
        if (self.variables.get_num_integer() > 0 or
                self.variables.get_num_binary() > 0):
            return True
        if (self.variables.get_num_semicontinuous() > 0 or
                self.variables.get_num_semiinteger() > 0):
            return True
        if self.SOS.get_num() > 0:
            return True
        if self.linear_constraints.advanced.get_num_user_cuts() > 0:
            return True
        if self.linear_constraints.advanced.get_num_lazy_constraints() > 0:
            return True
        return _proc._hasgeneralconstraints(self._env._e, self._lp)

    def solve(self):
        """Solves the problem.

        Note
          The solve method returning normally does not necessarily mean
          that an optimal or feasible solution has been found.  Use
          Cplex.solution.get_status() to query the status of the current
          solution.
        """
        # Setup the callbacks
        for cb in self._env._callbacks:
            cb._env_lp_ptr = self._env_lp_ptr
            if hasattr(cb, "_setup"):
                cb._setup(self._env._e, self._lp)
        if self._is_MIP():
            if _proc.hasvmconfig(self._env._e):
                _proc.distmipopt(self._env._e, self._lp)
            else:
                _proc.mipopt(self._env._e, self._lp)
        elif self.quadratic_constraints.get_num() > 0:
            lpmethod = self.parameters.lpmethod.get()
            if (lpmethod == _internal._constants.CPX_ALG_BARRIER or
                    lpmethod == _internal._constants.CPX_ALG_AUTOMATIC):
                _proc.hybbaropt(self._env._e, self._lp,
                                _internal._constants.CPX_ALG_NONE)
            else:
                _proc.qpopt(self._env._e, self._lp)
        elif not self.objective.get_num_quadratic_nonzeros() > 0:
            try:
                _proc.lpopt(self._env._e, self._lp)
            except exceptions.CplexSolverError as exc:
                if exc.args[2] == _internal._pycplex.CPXERR_NOT_FOR_MIP:
                    _proc.mipopt(self._env._e, self._lp)
                else:
                    raise
        else:
            _proc.qpopt(self._env._e, self._lp)

    def runseeds(self, cnt=30):
        """Evaluates the variability of the problem.

        Solves the same problem instance multiple times using different
        random seeds allowing the user to evaluate the variability of the
        problem class the instance belongs to.

        The optional cnt argument specifies the number of times
        optimization should be performed (the default is 30).

        A problem must be an MILP, MIQP, or MIQCP and must exist in
        memory.
        """
        _proc.runseeds(self._env._e, self._lp, cnt)

    def populate_solution_pool(self):
        """Generates a variety of solutions to a discrete problem (MIP, MIQP, MIQCP).

        The algorithm that populates the solution pool works in two
        phases.

        In the first phase, it solves the problem to optimality (or
        some stopping criterion set by the user) while it sets up a
        branch and cut tree for the second phase.

        In the second phase, it generates multiple solutions by using
        the information computed and stored in the first phase and by
        continuing to explore the tree.

        For more information, see the function CPXpopulate in the
        Callable Library Reference Manual and the topic solution pool
        in the CPLEX User's Manual.
        """
        _proc.populate(self._env._e, self._lp)

    def get_problem_name(self):
        """Returns the problem name."""
        return _proc.getprobname(self._env._e, self._lp,
                                 enc=self._env._apienc)

    def set_problem_name(self, name):
        """Sets the problem name."""
        _proc.chgprobname(self._env._e, self._lp, name,
                          enc=self._env._apienc)

    def cleanup(self, epsilon):
        """Deletes values from the problem data with absolute value smaller than epsilon."""
        _proc.cleanup(self._env._e, self._lp, epsilon)

    def register_callback(self, callback_class):
        """Registers a callback class for use during optimization.

        callback_class must be a proper subclass of one of the
        callback classes defined in the module callbacks.  It must
        override the __call__ method with a method that has signature
        __call__(self) -> None.  If callback_class is a subclass of
        more than one callback class, it will only be called when its
        first superclass is called.  register_callback returns the
        instance of callback_class registered for use.  Any previously
        registered callback of the same class will no longer be
        registered.
        """
        return self._env.register_callback(callback_class)

    def unregister_callback(self, callback_class):
        """Stops a callback class from being used.

        callback_class must be one of the callback classes defined in
        the module callback or a subclass of one of them.  This method 
        unregisters any previously registered callback of the same
        class.  If callback_class is a subclass of more than one
        callback class, this method will unregister only the callback of the
        same type as its first superclass.  unregister_callback
        returns the instance of callback_class just unregistered.
        """
        return self._env.unregister_callback(callback_class)

    def set_results_stream(self, results_file, fn=None):
        """Specifies where results will be printed.

        The first argument must be either a file-like object (i.e., an
        object with a write method and a flush method) or the name of
        a file to be written to.  Use None as the first argument to
        suppress output.

        The second optional argument is a function that takes a string
        as input and returns a string.  If specified, strings sent to
        this stream will be processed by this function before being
        written.

        Returns the stream to which results will be written.  To write
        to this stream, use this object's write() method.
        """
        return self._env.set_results_stream(results_file, fn)

    def set_warning_stream(self, warning_file, fn=None):
        """Specifies where warnings will be printed.

        The first argument must be either a file-like object (i.e., an
        object with a write method and a flush method) or the name of
        a file to be written to.  Use None as the first argument to
        suppress output.

        The second optional argument is a function that takes a string
        as input and returns a string.  If specified, strings sent to
        this stream will be processed by this function before being
        written.

        Returns the stream to which warnings will be written.  To write
        to this stream, use this object's write() method.
        """
        return self._env.set_warning_stream(warning_file, fn)

    def set_error_stream(self, error_file, fn=None):
        """Specifies where errors will be printed.

        The first argument must be either a file-like object (i.e., an
        object with a write method and a flush method) or the name of
        a file to be written to.  Use None as the first argument to
        suppress output.

        The second optional argument is a function that takes a string
        as input and returns a string.  If specified, strings sent to
        this stream will be processed by this function before being
        written.

        Returns the stream to which errors will be written.  To write
        to this stream, use this object's write() method.
        """
        return self._env.set_error_stream(error_file, fn)

    def set_log_stream(self, log_file, fn=None):
        """Specifies where the log will be printed.

        The first argument must be either a file-like object (i.e., an
        object with a write method and a flush method) or the name of
        a file to be written to.  Use None as the first argument to
        suppress output.

        The second optional argument is a function that takes a string
        as input and returns a string.  If specified, strings sent to
        this stream will be processed by this function before being
        written.

        Returns the stream to which the log will be written.  To write
        to this stream, use this object's write() method.
        """
        return self._env.set_log_stream(log_file, fn)

    def get_version(self):
        """Returns a string specifying the version of CPLEX."""
        return self._env.get_version()

    def get_versionnumber(self):
        """Returns an integer specifying the version of CPLEX.

        The version of CPLEX is in the format vvrrmmff, where vv is
        the version, rr is the release, mm is the modification, and ff
        is the fixpack number. For example, for CPLEX version 12.5.0.1
        the returned value is 12050001.
        """
        return self._env.get_versionnumber()

    def get_num_cores(self):
        """Returns the number of cores on this machine."""
        return self._env.get_num_cores()

    def get_stats(self):
        """Returns an object containing problem statistics."""
        return Stats(self)

    def get_time(self):
        """Returns a time stamp in seconds.

        To measure time spent between a starting point and ending point of
        an operation, take the result of this method at the starting point;
        take the result of this method at the end point; subtract the starting
        time stamp from the ending time stamp; the subtraction yields elapsed
        time in seconds.

        The interpretation of this value as wall clock time or CPU
        time is controlled by the parameter clocktype.

        The absolute value of the time stamp is not meaningful.
        """
        return self._env.get_time()

    def get_dettime(self):
        """Returns a deterministic time stamp in ticks.

        To measure elapsed deterministic time in ticks between a starting
        point and ending point of an operation, take the deterministic time
        stamp at the starting point; take the deterministic time stamp at the
        ending point; subtract the starting deterministic time stamp from the
        ending deterministic time stamp.

        The absolute value of the deterministic time stamp is not meaningful.
        """
        return self._env.get_dettime()

    def use_aborter(self, aborter):
        """Use an aborter to control termination of solve methods.

        Instructs the invoking object to use the aborter to control
        termination of its solving and tuning methods.

        If another aborter is already being used by the invoking object,
        then this method overrides the previously used aborter.

        Returns the aborter installed in the invoking object or None.

        Example usage:

        >>> import cplex
        >>> c = cplex.Cplex()
        >>> aborter = c.use_aborter(cplex.Aborter())
        """
        self.remove_aborter()
        self._aborter = aborter
        if not self._aborter is None:
            _proc.setterminate(self._env._e, self._env_lp_ptr,
                               self._aborter._p)
            self._aborter._register(self)
        return self._aborter

    def remove_aborter(self):
        """Removes the aborter being used by the invoking object.

        Returns the aborter that was removed or None.

        Example usage:

        >>> import cplex
        >>> c = cplex.Cplex()
        >>> aborter = c.use_aborter(cplex.Aborter())
        >>> aborter = c.remove_aborter()
        """
        aborter = self._aborter
        self._aborter = None
        _proc.setterminate(self._env._e, self._env_lp_ptr, None)
        if not aborter is None:
            aborter._unregister(self)
        return aborter

    def get_aborter(self):
        """Returns the aborter being used by the invoking object.

        Example usage:

        >>> import cplex
        >>> c = cplex.Cplex()
        >>> aborter = c.use_aborter(cplex.Aborter())
        >>> aborter = c.get_aborter()
        """
        return self._aborter

    def set_callback(self, functor=None, contextmask=0):
        """Set callback function to use during optimization.

        Sets the callback that CPLEX invokes during optimization. If functor
        is None then contextmask will be treated as 0 and the callback is
        effectively cleared from CPLEX.

        In all other cases functor must be a reference to an object that has
        a callable member called 'invoke' (if that does not exist or
        is not a callable an exception will occur the first time CPLEX attempts
        to invoke the callback). Whenever CPLEX needs to invoke the callback
        it calls this member with exactly one argument: an instance of
        cplex.callbacks.Context.

        Note that in the 'invoke' function you must not invoke any functions
        of the Cplex instance that is performing the current solve. All
        functions that can be invoked from a callback are members of the
        cplex.callbacks.Context class.

        contextmask must be the bitwise OR of values from
        cplex.callbacks.Context.id and specifies in which contexts CPLEX shall
        invoke the callback: the callback is invoked in all contexts for which
        the corresponding bit is set in contextmask.

        Note about cplex.callbacks.Context.id.thread_down: This is considered
        a "destructor" function and should not raise any exception. Any exception
        raised from the callback in this context will just be ignored.
        """
        # First of all, clear any existing callback
        self._genericcallback = None
        self._genericcontextmask = None
        _proc.setgenericcallbackfunc(self._env._e, self._lp, contextmask, None)
        # TODO: Use hasattr() or similar to check whether 'functor' has
        #        a method called 'invoke'? This is never a complete
        #        guard since the attribute may be deleted from the instance
        #        later. So for now we just don't do it.
        # FIXME: This is very shaky since the callback will be deleted
        #        whenever we create a new self._lp :-( So far I don't see us
        #        deleting/recreating self._lp anywhere, but if that ever
        #        happens we have to be careful.
        if contextmask != 0 and not functor is None:
            _proc.setgenericcallbackfunc(self._env._e, self._lp, contextmask,
                                         self)
            self._genericcallback = functor
            self._genericcontextmask = contextmask

    def _invoke_generic_callback(self, contextptr, contextid):
        """non-public"""
        # This is invoked by the cpxpygenericcallbackfuncwrap() trampoline
        # function in the native code and is responsible for invoking the
        # user callback.
        context = callbacks.Context(weakref.proxy(self), contextptr, contextid)
        if context.get_id() == callbacks.Context.id.thread_down:
            # For thread_down we ignore any exception
            try:
                self._genericcallback.invoke(context)
            except:
                pass
        else:
            self._genericcallback.invoke(context)
