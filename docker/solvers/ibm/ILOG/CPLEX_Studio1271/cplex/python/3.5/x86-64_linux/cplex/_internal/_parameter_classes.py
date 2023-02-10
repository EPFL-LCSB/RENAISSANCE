# --------------------------------------------------------------------------
# File: _parameter_classes.py 
# ---------------------------------------------------------------------------
# Licensed Materials - Property of IBM
# 5725-A06 5725-A29 5724-Y48 5724-Y49 5724-Y54 5724-Y55 5655-Y21
# Copyright IBM Corporation 2008, 2017. All Rights Reserved.
#
# US Government Users Restricted Rights - Use, duplication or
# disclosure restricted by GSA ADP Schedule Contract with
# IBM Corp.
# ------------------------------------------------------------------------
"""Parameters for the CPLEX Python API.

This module defines classes for parameters_1, groups of parameters_1, and
parameter constants used in the CPLEX Python API.  For more detail, see also
the corresponding commands of the Interactive Optimizer documented in the
CPLEX Parameters Reference Manual.
"""

import weakref

from . import _procedural as CPX_PROC
from ._parameters_auto import *
from . import _constants
from .. import exceptions
from .. import six

class Parameter(object):
    """Base class for Cplex parameters_1.

    """

    def __init__(self, env, about, parent, name, constants = None):
        """non-public"""
        self._env = weakref.proxy(env)
        self._id = about[0]
        self._help = lambda : about[1]
        self._parent = parent
        self._name = name
        if constants is not None:
            self.values = constants()

    def __repr__(self):
        """Returns the name of the parameter within the hierarchy."""
        return "".join([self._parent.__repr__(), '.', self._name])

    def set(self, value):
        """Sets the parameter to value."""
        if self._id == _constants.CPX_PARAM_APIENCODING:
            if not self._isvalid(value):
                self._raiseInvalidArgument()
            self._apiencoding_value = value
            value = CPX_PROC.default_encoding
        if self._id == _constants.CPX_PARAM_FILEENCODING:
            if not self._isvalid(value):
                self._raiseInvalidArgument()
        if self._isvalid(value):
            self._env.parameters._set(self._id, value)
        else:
            self._raiseInvalidArgument()

    def get(self):
        """Returns the current value of the parameter."""
        if self._id == _constants.CPX_PARAM_APIENCODING:
            if hasattr(self, "_apiencoding_value"):
                return self._apiencoding_value
        if self._id == _constants.CPX_PARAM_FILEENCODING:
            return CPX_PROC.cpx_encode(self._env.parameters._get(self._id),
                                       self._env._apienc)
        return self._env.parameters._get(self._id)

    def reset(self):
        """Sets the parameter to its default value."""
        try:
            self.set(self._defval)
        except exceptions.CplexSolverError as cse:
            errcodes = exceptions.error_codes
            if ((self._id == _constants.CPX_PARAM_CPUMASK) and
                cse.args[2] == errcodes.CPXERR_UNSUPPORTED_OPERATION):
                pass
            else:
                raise

    def default(self):
        """Returns the default value of the parameter."""
        if self._id == _constants.CPX_PARAM_DATACHECK:
            return _constants.CPX_DATACHECK_WARN
        elif self._id == _constants.CPX_PARAM_APIENCODING:
            return CPX_PROC.default_encoding
        else:
            return self._defval

    def type(self):
        """Returns the type of the parameter.

        Allowed types are float, int, and string.
        """
        return type(self._defval)

    def help(self):
        """Returns the documentation for the parameter."""
        return self._help()

    def _raiseInvalidArgument(self):
        """Raise invalid argument exception."""
        raise exceptions.CplexError("Invalid argument to "+self.__repr__()+".set")

class NumParameter(Parameter):
    """Class for integer and float parameters_1.

    """

    def __init__(self, env, about, parent, name, constants = None):
        """non-public"""
        Parameter.__init__(self, env, about, parent, name, constants)
        (self._defval, self._minval, self._maxval) = self._env.parameters._get_info(self._id)
        if self._id == _constants.CPX_PARAM_CLONELOG:
            self._minval = 0
            
    def _isvalid(self, value):
        """Returns whether value is a valid value for the parameter."""
        # If value is not a number then return False (thus avoiding an ugly TypeError).
        for i in six.integer_types:
            if isinstance(value, i):
                break
        else:
            if not isinstance(value, float):
                return False
        # As we define a special min value for CPX_PARAM_CLONELOG in the Python API
        # we have to have special handling for it.
        if (self._id == _constants.CPX_PARAM_CLONELOG and
            value < self._minval):
            return False
        return True

    def min(self):
        """Returns the minimum value for the parameter."""
        return self._minval

    def max(self):
        """Returns the maximum value for the parameter."""
        return self._maxval


class StrParameter(Parameter):
    """Class for string parameters_1.

    """

    def __init__(self, env, about, parent, name, constants = None):
        """non-public"""
        Parameter.__init__(self, env, about, parent, name, constants)
        self._defval = self._env.parameters._get_info(self._id)

    def _isvalid(self, value):
        """Returns whether value is a valid value for the parameter."""
        if isinstance(value, self.type()):
            if self._id == _constants.CPX_PARAM_APIENCODING:
                if (value.lower().startswith("utf") and value.find("7") != -1):
                    return False
            return True
        else:
            return False


class ParameterGroup(object):
    """Class containing a group of Cplex parameters_1.

    """

    def __init__(self, env, members, parent):
        """non-public"""
        self._env = weakref.proxy(env)
        self._parent = parent
        self.__dict__.update(members(env, self))

    def __repr__(self):
        """Returns the name of the parameter group within the hierarchy."""
        return "".join([self._parent.__repr__(), '.', self._name])

    def reset(self):
        """Sets the parameters_1 in the group to their default values."""
        for member in self.__dict__.values():
            if (isinstance(member, ParameterGroup) or isinstance(member, Parameter)) and member != self._parent:
                member.reset()

    def get_changed(self):
        """Returns a list of the changed parameters_1 in the group.

        Returns a list of (parameter, value) pairs.  Each parameter is
        an instance of the Parameter class, and thus the parameter
        value can be changed via its set method, or this object can be
        passed to the tuning functions.
        """
        retval = []
        for member in self.__dict__.values():
            if isinstance(member, ParameterGroup) and member != self._parent:
                retval.extend(member.get_changed())
            if isinstance(member, Parameter):
                if member.get() != member.default():
                    retval.append((member, member.get()))
        return retval
                    

class TuningConstants:
    """Status codes returned by tuning methods.

    For an explanation of tuning, see that topic in
    the CPLEX User's Manual.
    """

    abort      = _constants.CPX_TUNE_ABORT
    time_limit = _constants.CPX_TUNE_TILIM
    dettime_limit = _constants.CPX_TUNE_DETTILIM
    
    def __getitem__(self, item):
        """Converts a constant to a string.

        Example usage:

        >>> import cplex
        >>> c = cplex.Cplex()
        >>> c.parameters_1.tuning_status.abort
        1
        >>> c.parameters_1.tuning_status[1]
        'abort'
        """
        if item == 0:
            return 'completed'
        if item == _constants.CPX_TUNE_ABORT:
            return 'abort'
        if item == _constants.CPX_TUNE_TILIM:
            return 'time_limit'
        if item == _constants.CPX_TUNE_DETTILIM:
            return 'dettime_limit'
        

class RootParameterGroup(ParameterGroup):
    """Class containing all the Cplex parameters_1.

    """

    tuning_status = TuningConstants()

    def __init__(self, env, members):
        if env is None and members is None:
            return
        env.parameters = self
        ParameterGroup.__init__(self, env, members, None)
        self._override_defaults()

    def _get_overrides(self):
        """non-public"""
        # These parameters_1 are overridden for the Python API and should always
        # retain these values no matter what (except for datacheck, which can
        # be turned off if the user desires).
        return {_constants.CPX_PARAM_APIENCODING : CPX_PROC.default_encoding,
                _constants.CPX_PARAM_DATACHECK : _constants.CPX_DATACHECK_WARN,
                # turn off access to presolved problem in callbacks
                _constants.CPX_PARAM_MIPCBREDLP : 0}

    def _check_overrides(self):
        """non-public"""
        # After every reset, tune_problem, and tune_problem_set, verify that
        # the default overrides have been applied.
        overrides = self._get_overrides()
        for key in overrides:
            actual = self._get(key)
            expected = overrides[key]
            assert (actual == expected), "Unexpected value for overridden parameter!"
        # Make sure that the Parameter._apiencoding_value has been overridden too.
        assert (self._env._apienc == CPX_PROC.default_encoding), \
            "Expecting value for read.apiencoding to have been overridden!"

    def _override_defaults(self):
        """non-public"""
        overrides = self._get_overrides()
        for key in overrides:
            self._set(key, overrides[key])
        # This is required to make sure that the Parameter._apiencoding_value
        # attribute is overridden too.
        self.read.apiencoding.set(CPX_PROC.default_encoding)

    def reset(self):
        """Sets the parameters_1 in the group to their default values."""
        ParameterGroup.reset(self)
        self._override_defaults()
        self._check_overrides()

    def __repr__(self):
        """Return 'parameters_1'."""
        return self._name

    def _set(self, which_parameter, value):
        """non-public"""
        if which_parameter in intParameterSet:
            if isinstance(value, type(float())):
                value = int(value) # will upconvert to long, if necc.
            # prevent access to presolved problem in MIP callbacks
            if which_parameter == 2055 and value != 0:
                return
            param_type = CPX_PROC.getparamtype(self._env._e, which_parameter)
            if param_type == _constants.CPX_PARAMTYPE_INT:
                CPX_PROC.setintparam(self._env._e, which_parameter, value)
            else:
                CPX_PROC.setlongparam(self._env._e, which_parameter, value)
        elif which_parameter in dblParameterSet:
            if isinstance(value, six.integer_types):
                value = float(value)
            CPX_PROC.setdblparam(self._env._e, which_parameter, value)
        elif which_parameter in strParameterSet:
            CPX_PROC.setstrparam(self._env._e, which_parameter, value)
        else:
            raise exceptions.CplexError("Bad parameter identifier")

    def _get(self, which_parameter):
        """non-public"""
        if which_parameter in intParameterSet:
            param_type = CPX_PROC.getparamtype(self._env._e, which_parameter)
            if param_type == _constants.CPX_PARAMTYPE_INT:
                return CPX_PROC.getintparam(self._env._e, which_parameter)
            else:
                return CPX_PROC.getlongparam(self._env._e, which_parameter)
        elif which_parameter in dblParameterSet:
            return CPX_PROC.getdblparam(self._env._e, which_parameter)
        elif which_parameter in strParameterSet:
            return CPX_PROC.getstrparam(self._env._e, which_parameter)
        else:
            raise exceptions.CplexError("Bad parameter identifier")

    def _get_info(self, which_parameter):
        """non-public"""
        if which_parameter in intParameterSet:
            param_type = CPX_PROC.getparamtype(self._env._e, which_parameter)
            if param_type == _constants.CPX_PARAMTYPE_INT:
                return CPX_PROC.infointparam(self._env._e, which_parameter)
            else:
                return CPX_PROC.infolongparam(self._env._e, which_parameter)
        elif which_parameter in dblParameterSet:
            return CPX_PROC.infodblparam(self._env._e, which_parameter)
        elif which_parameter in strParameterSet:
            return CPX_PROC.infostrparam(self._env._e, which_parameter)
        else:
            raise exceptions.CplexError("Bad parameter identifier")

    def _process_fixed_args(self, fixed_parameters_and_values):
        """non-public"""
        # Make sure that we always pass in the default overrides to
        # the tuning tool.
        result = {}
        overrides = self._get_overrides()
        isincluded = set()
        for (param, value) in fixed_parameters_and_values:
            if param._id in result:
                raise exceptions.CplexError("Duplicate parameters_1 detected!")
            if param._id in overrides:
                result[param._id] = overrides[param._id];
                isincluded.add(param._id)
            else:
                result[param._id] = value
        for key in overrides:
            if key not in isincluded:
                result[key] = overrides[key]
        return result

    def tune_problem_set(self, filenames, filetypes = [], fixed_parameters_and_values= []):
        """Tunes parameters_1 for a set of problems.

        filenames must be a sequence of strings specifying a set of
        problems to tune.
        
        If filetypes is given, it must be a sequence of the same
        length as filenames also consisting of strings that specify
        the types of the corresponding files.
        
        fixed_parameters_and_values is a sequence of sequences of
        length 2 containing instances of the Parameter class that are
        to be fixed during the tuning process and the values at which
        they are to be fixed.

        tune_problem_set returns the status of the tuning procedure,
        which is an attribute of parameters_1.tuning.

        >>> import cplex
        >>> c = cplex.Cplex()
        >>> out = c.set_results_stream(None)
        >>> out = c.set_log_stream(None)
        >>> status = c.parameters_1.tune_problem_set(["lpex.mps", "example.mps"],\
                                                   fixed_parameters_and_values = [(c.parameters_1.lpmethod, 0)])
        >>> c.parameters_1.tuning_status[status]
        'completed'
        """
        int_params_and_values = []
        dbl_params_and_values = []
        str_params_and_values = []
        fixedpvs = self._process_fixed_args(fixed_parameters_and_values)
        for param_id in fixedpvs:
            if param_id in intParameterSet:
                int_params_and_values.append((param_id, fixedpvs[param_id]))
            elif param_id in dblParameterSet:
                dbl_params_and_values.append((param_id, fixedpvs[param_id]))
            elif param_id in strParameterSet:
                str_params_and_values.append((param_id, fixedpvs[param_id]))
            else:
                raise exceptions.CplexError("Bad input to parameters_1.tune_problem_set")
        status = CPX_PROC.tuneparamprobset(self._env._e, filenames, filetypes, int_params_and_values,
                                           dbl_params_and_values, str_params_and_values)
        self._check_overrides()
        return status

    def tune_problem(self, fixed_parameters_and_values = []):
        """Tunes parameters_1 for a Cplex problem.

        fixed_parameters_and_values is a sequence of sequences of
        length 2 containing instances of the Parameter class that are
        to be fixed during the tuning process and the values at which
        they are to be fixed.

        tune_problem returns the status of the tuning procedure, which
        is an attribute of parameters_1.tuning.

        >>> import cplex
        >>> c = cplex.Cplex()
        >>> out = c.set_results_stream(None)
        >>> status = c.parameters_1.tune_problem([(c.parameters_1.lpmethod, 0)])
        >>> c.parameters_1.tuning_status[status]
        'completed'
        >>> status = c.parameters_1.tune_problem()
        >>> c.parameters_1.tuning_status[status]
        'completed'
        """
        int_params_and_values = []
        dbl_params_and_values = []
        str_params_and_values = []
        fixedpvs = self._process_fixed_args(fixed_parameters_and_values)
        for param_id in fixedpvs:
            if param_id in  intParameterSet:
                int_params_and_values.append((param_id, fixedpvs[param_id]))
            elif param_id in dblParameterSet:
                dbl_params_and_values.append((param_id, fixedpvs[param_id]))
            elif param_id in strParameterSet:
                str_params_and_values.append((param_id, fixedpvs[param_id]))
            else:
                raise exceptions.CplexError("Bad input to parameters_1.tune_problem")
        status = CPX_PROC.tuneparam(self._env._e, self._cplex._lp,
                                    int_params_and_values,
                                    dbl_params_and_values,
                                    str_params_and_values)
        self._check_overrides()
        return status
    
    def read_file(self, filename):
        """Reads a set of parameters_1 from the file filename."""
        CPX_PROC.readcopyparam(self._env._e, filename,
                               enc=self._env._apienc)

    def write_file(self, filename):
        """Writes a set of parameters_1 to the file filename."""
        CPX_PROC.writeparam(self._env._e, filename,
                            enc=self._env._apienc)


class off_on_constants:
    off = _constants.CPX_OFF
    on  = _constants.CPX_ON
    def __getitem__(self, item):
        """Converts a constant to a string.

        Example usage:

        >>> import cplex
        >>> c = cplex.Cplex()
        >>> c.parameters_1.output.mpslong.values.on
        1
        >>> c.parameters_1.output.mpslong.values[1]
        'on'
        """
        if item == _constants.CPX_OFF:
            return 'off'
        if item == _constants.CPX_ON:
            return 'on'

class auto_off_on_constants:
    auto = _constants.CPX_AUTO
    off = _constants.CPX_OFF
    on = _constants.CPX_ON
    def __getitem__(self, item):
        """Converts a constant to a string.

        Example usage:

        >>> import cplex
        >>> c = cplex.Cplex()
        >>> c.parameters_1.preprocessing.qtolin.values.on
        1
        >>> c.parameters_1.preprocessing.qtolin.values[1]
        'on'
        """
        if item == _constants.CPX_AUTO:
            return 'auto'
        if item == _constants.CPX_OFF:
            return 'off'
        if item == _constants.CPX_ON:
            return 'on'

class writelevel_constants:
    auto                       = _constants.CPX_WRITELEVEL_AUTO
    all_variables              = _constants.CPX_WRITELEVEL_ALLVARS
    discrete_variables         = _constants.CPX_WRITELEVEL_DISCRETEVARS
    nonzero_variables          = _constants.CPX_WRITELEVEL_NONZEROVARS
    nonzero_discrete_variables = _constants.CPX_WRITELEVEL_NONZERODISCRETEVARS
    def __getitem__(self, item):
        """Converts a constant to a string.

        Example usage:

        >>> import cplex
        >>> c = cplex.Cplex()
        >>> c.parameters_1.output.writelevel.values.auto
        0
        >>> c.parameters_1.output.writelevel.values[0]
        'auto'
        """
        if item == _constants.CPX_WRITELEVEL_AUTO:
            return 'auto'
        if item == _constants.CPX_WRITELEVEL_ALLVARS:
            return 'all_variables'
        if item == _constants.CPX_WRITELEVEL_DISCRETEVARS:
            return 'discrete_variables'
        if item == _constants.CPX_WRITELEVEL_NONZEROVARS:
            return 'nonzero_variables'
        if item == _constants.CPX_WRITELEVEL_NONZERODISCRETEVARS:
            return 'nonzero_discrete_variables'

class scale_constants:
    none = -1
    equilibration = 0
    aggressive = 1
    def __getitem__(self, item):
        """Converts a constant to a string.

        Example usage:

        >>> import cplex
        >>> c = cplex.Cplex()
        >>> c.parameters_1.read.scale.values.none
        -1
        >>> c.parameters_1.read.scale.values[-1]
        'none'
        """
        if item == -1:
            return 'none'
        if item == 0:
            return 'equilibration'
        if item == 1:
            return 'aggressive'

class mip_emph_constants:
    balanced    = _constants.CPX_MIPEMPHASIS_BALANCED
    optimality  = _constants.CPX_MIPEMPHASIS_OPTIMALITY
    feasibility = _constants.CPX_MIPEMPHASIS_FEASIBILITY
    best_bound   = _constants.CPX_MIPEMPHASIS_BESTBOUND
    hidden_feasibility  = _constants.CPX_MIPEMPHASIS_HIDDENFEAS 
    def __getitem__(self, item):
        """Converts a constant to a string.

        Example usage:

        >>> import cplex
        >>> c = cplex.Cplex()
        >>> c.parameters_1.emphasis.mip.values.balanced
        0
        >>> c.parameters_1.emphasis.mip.values[0]
        'balanced'
        """
        if item == _constants.CPX_MIPEMPHASIS_BALANCED:
            return 'balanced'
        if item == _constants.CPX_MIPEMPHASIS_OPTIMALITY:
            return 'optimality'
        if item == _constants.CPX_MIPEMPHASIS_FEASIBILITY:
            return 'feasibility'
        if item == _constants.CPX_MIPEMPHASIS_BESTBOUND:
            return 'best_bound'
        if item == _constants.CPX_MIPEMPHASIS_HIDDENFEAS :
            return 'hidden_feasibility'

class brdir_constants:
    down = _constants.CPX_BRDIR_DOWN
    auto = _constants.CPX_BRDIR_AUTO
    up   = _constants.CPX_BRDIR_UP
    def __getitem__(self, item):
        """Converts a constant to a string.

        Example usage:

        >>> import cplex
        >>> c = cplex.Cplex()
        >>> c.parameters_1.mip.strategy.branch.values.down
        -1
        >>> c.parameters_1.mip.strategy.branch.values[-1]
        'down'
        """
        if item == _constants.CPX_BRDIR_DOWN:
            return 'down'
        if item == _constants.CPX_BRDIR_AUTO:
            return 'auto'
        if item == _constants.CPX_BRDIR_UP:
            return 'up'

class search_constants:
    auto        = _constants.CPX_MIPSEARCH_AUTO
    traditional = _constants.CPX_MIPSEARCH_TRADITIONAL
    dynamic     = _constants.CPX_MIPSEARCH_DYNAMIC      
    def __getitem__(self, item):
        """Converts a constant to a string.

        Example usage:

        >>> import cplex
        >>> c = cplex.Cplex()
        >>> c.parameters_1.mip.strategy.search.values.auto
        0
        >>> c.parameters_1.mip.strategy.search.values[0]
        'auto'
        """
        if item == _constants.CPX_MIPSEARCH_AUTO:
            return 'auto'
        if item == _constants.CPX_MIPSEARCH_TRADITIONAL:
            return 'traditional'
        if item == _constants.CPX_MIPSEARCH_DYNAMIC      :
            return 'dynamic'

class subalg_constants:
    auto       = _constants.CPX_ALG_AUTOMATIC
    primal     = _constants.CPX_ALG_PRIMAL
    dual       = _constants.CPX_ALG_DUAL
    network    = _constants.CPX_ALG_NET
    barrier    = _constants.CPX_ALG_BARRIER
    sifting    = _constants.CPX_ALG_SIFTING
    def __getitem__(self, item):
        """Converts a constant to a string.

        Example usage:

        >>> import cplex
        >>> c = cplex.Cplex()
        >>> c.parameters_1.mip.strategy.subalgorithm.values.auto
        0
        >>> c.parameters_1.mip.strategy.subalgorithm.values[0]
        'auto'
        """
        if item == _constants.CPX_ALG_AUTOMATIC:
            return 'auto'
        if item == _constants.CPX_ALG_PRIMAL:
            return 'primal'
        if item == _constants.CPX_ALG_DUAL:
            return 'dual'
        if item == _constants.CPX_ALG_NET:
            return 'network'
        if item == _constants.CPX_ALG_BARRIER:
            return 'barrier'
        if item == _constants.CPX_ALG_SIFTING:
            return 'sifting'

class nodesel_constants:
    depth_first       = _constants.CPX_NODESEL_DFS
    best_bound        = _constants.CPX_NODESEL_BESTBOUND
    best_estimate     = _constants.CPX_NODESEL_BESTEST
    best_estimate_alt = _constants.CPX_NODESEL_BESTEST_ALT     
    def __getitem__(self, item):
        """Converts a constant to a string.

        Example usage:

        >>> import cplex
        >>> c = cplex.Cplex()
        >>> c.parameters_1.mip.strategy.nodeselect.values.depth_first
        0
        >>> c.parameters_1.mip.strategy.nodeselect.values[0]
        'depth_first'
        """
        if item == _constants.CPX_NODESEL_DFS:
            return 'depth_first'
        if item == _constants.CPX_NODESEL_BESTBOUND:
            return 'best_bound'
        if item == _constants.CPX_NODESEL_BESTEST:
            return 'best_estimate'
        if item == _constants.CPX_NODESEL_BESTEST_ALT     :
            return 'best_estimate_alt'

class alg_constants:
    auto       = _constants.CPX_ALG_AUTOMATIC
    primal     = _constants.CPX_ALG_PRIMAL
    dual       = _constants.CPX_ALG_DUAL
    barrier    = _constants.CPX_ALG_BARRIER
    sifting    = _constants.CPX_ALG_SIFTING
    network    = _constants.CPX_ALG_NET
    concurrent = _constants.CPX_ALG_CONCURRENT
    def __getitem__(self, item):
        """Converts a constant to a string.

        Example usage:

        >>> import cplex
        >>> c = cplex.Cplex()
        >>> c.parameters_1.mip.strategy.startalgorithm.values.auto
        0
        >>> c.parameters_1.mip.strategy.startalgorithm.values[0]
        'auto'
        """
        if item == _constants.CPX_ALG_AUTOMATIC:
            return 'auto'
        if item == _constants.CPX_ALG_PRIMAL:
            return 'primal'
        if item == _constants.CPX_ALG_DUAL:
            return 'dual'
        if item == _constants.CPX_ALG_BARRIER:
            return 'barrier'
        if item == _constants.CPX_ALG_SIFTING:
            return 'sifting'
        if item == _constants.CPX_ALG_NET:
            return 'network'
        if item == _constants.CPX_ALG_CONCURRENT:
            return 'concurrent'

class varsel_constants:
    min_infeasibility    = _constants.CPX_VARSEL_MININFEAS
    default              = _constants.CPX_VARSEL_DEFAULT
    max_infeasibility    = _constants.CPX_VARSEL_MAXINFEAS
    pseudo_costs         = _constants.CPX_VARSEL_PSEUDO
    strong_branching     = _constants.CPX_VARSEL_STRONG
    pseudo_reduced_costs = _constants.CPX_VARSEL_PSEUDOREDUCED 
    def __getitem__(self, item):
        """Converts a constant to a string.

        Example usage:

        >>> import cplex
        >>> c = cplex.Cplex()
        >>> c.parameters_1.mip.strategy.variableselect.values.default
        0
        >>> c.parameters_1.mip.strategy.variableselect.values[0]
        'default'
        """
        if item == _constants.CPX_VARSEL_MININFEAS:
            return 'min_infeasibility'
        if item == _constants.CPX_VARSEL_DEFAULT:
            return 'default'
        if item == _constants.CPX_VARSEL_MAXINFEAS:
            return 'max_infeasibility'
        if item == _constants.CPX_VARSEL_PSEUDO:
            return 'pseudo_costs'
        if item == _constants.CPX_VARSEL_STRONG:
            return 'strong_branching'
        if item == _constants.CPX_VARSEL_PSEUDOREDUCED :
            return 'pseudo_reduced_costs'

class dive_constants:
    auto = 0
    traditional = 1
    probing = 2
    guided = 3
    def __getitem__(self, item):
        """Converts a constant to a string.

        Example usage:

        >>> import cplex
        >>> c = cplex.Cplex()
        >>> c.parameters_1.mip.strategy.dive.values.auto
        0
        >>> c.parameters_1.mip.strategy.dive.values[0]
        'auto'
        """
        if item == 0:
            return 'auto'
        if item == 1:
            return 'traditional'
        if item == 2:
            return 'probing'
        if item == 3:
            return 'guided'

class file_constants:
    auto = 0
    memory = 1
    disk = 2
    disk_compressed = 3
    def __getitem__(self, item):
        """Converts a constant to a string.

        Example usage:

        >>> import cplex
        >>> c = cplex.Cplex()
        >>> c.parameters_1.mip.strategy.file.values.auto
        0
        >>> c.parameters_1.mip.strategy.file.values[0]
        'auto'
        """
        if item == 0:
            return 'auto'
        if item == 1:
            return 'memory'
        if item == 2:
            return 'disk'
        if item == 3:
            return 'disk_compressed'

class fpheur_constants:
    none = -1
    auto = 0
    feas = 1
    obj_and_feas = 2
    def __getitem__(self, item):
        """Converts a constant to a string.

        Example usage:

        >>> import cplex
        >>> c = cplex.Cplex()
        >>> c.parameters_1.mip.strategy.fpheur.values.auto
        0
        >>> c.parameters_1.mip.strategy.fpheur.values[0]
        'auto'
        """
        if item == -1:
            return 'none'
        if item == 0:
            return 'auto'
        if item == 1:
            return 'feas'
        if item == 2:
            return 'obj_and_feas'

class miqcp_constants:
    auto = 0
    QCP_at_node = 1
    LP_at_node = 2
    def __getitem__(self, item):
        """Converts a constant to a string.

        Example usage:

        >>> import cplex
        >>> c = cplex.Cplex()
        >>> c.parameters_1.mip.strategy.miqcpstrat.values.auto
        0
        >>> c.parameters_1.mip.strategy.miqcpstrat.values[0]
        'auto'
        """
        if item == 0:
            return 'auto'
        if item == 1:
            return 'QCP_at_node'
        if item == 2:
            return 'LP_at_node'

class presolve_constants:
    none = -1
    auto = 0
    force = 1
    probe = 2
    def __getitem__(self, item):
        """Converts a constant to a string.

        Example usage:

        >>> import cplex
        >>> c = cplex.Cplex()
        >>> c.parameters_1.mip.strategy.presolvenode.values.auto
        0
        >>> c.parameters_1.mip.strategy.presolvenode.values[0]
        'auto'
        """
        if item == -1:
            return 'none'
        if item == 0:
            return 'auto'
        if item == 1:
            return 'force'
        if item == 2:
            return 'probe'

class v_agg_constants:
    none            = -1
    auto            = 0
    moderate        = 1
    aggressive      = 2
    very_aggressive = 3
    def __getitem__(self, item):
        """Converts a constant to a string.

        Example usage:

        >>> import cplex
        >>> c = cplex.Cplex()
        >>> c.parameters_1.mip.strategy.probe.values.auto
        0
        >>> c.parameters_1.mip.strategy.probe.values[0]
        'auto'
        """
        if item == -1:
            return 'none'
        if item == 0:
            return 'auto'
        if item == 1:
            return 'moderate'
        if item == 2:
            return 'aggressive'
        if item == 3:
            return 'very_aggressive'

class kappastats_constants:
    none   = -1
    auto   = 0
    sample = 1
    full   = 2
    def __getitem__(self, item):
        """Converts a constant to a string.

        Example usage:

        >>> import cplex
        >>> c = cplex.Cplex()
        >>> c.parameters_1.mip.strategy.kappastats.values.full
        2
        >>> c.parameters_1.mip.strategy.kappastats.values[2]
        'full'
        """
        if item == -1:
            return 'none'
        if item == 0:
            return 'auto'
        if item == 1:
            return 'sample'
        if item == 2:
            return 'full'

class agg_constants:
    none            = -1
    auto            = 0
    moderate        = 1
    aggressive      = 2
    def __getitem__(self, item):
        """Converts a constant to a string.

        Example usage:

        >>> import cplex
        >>> c = cplex.Cplex()
        >>> c.parameters_1.mip.cuts.gomory.values.auto
        0
        >>> c.parameters_1.mip.cuts.gomory.values[0]
        'auto'
        """
        if item == -1:
            return 'none'
        if item == 0:
            return 'auto'
        if item == 1:
            return 'moderate'
        if item == 2:
            return 'aggressive'

class replace_constants:
    firstin_firstout = _constants.CPX_SOLNPOOL_FIFO
    worst_objective  = _constants.CPX_SOLNPOOL_OBJ
    diversity        = _constants.CPX_SOLNPOOL_DIV
    def __getitem__(self, item):
        """Converts a constant to a string.

        Example usage:

        >>> import cplex
        >>> c = cplex.Cplex()
        >>> c.parameters_1.mip.pool.replace.values.diversity
        2
        >>> c.parameters_1.mip.pool.replace.values[2]
        'diversity'
        """
        if item == _constants.CPX_SOLNPOOL_FIFO:
            return 'firstin_firstout'
        if item == _constants.CPX_SOLNPOOL_OBJ:
            return 'worst_objective'
        if item == _constants.CPX_SOLNPOOL_DIV:
            return 'diversity'

class ordertype_constants:
    default     = 0
    cost        = _constants.CPX_MIPORDER_COST
    bounds      = _constants.CPX_MIPORDER_BOUNDS
    scaled_cost = _constants.CPX_MIPORDER_SCALEDCOST
    def __getitem__(self, item):
        """Converts a constant to a string.

        Example usage:

        >>> import cplex
        >>> c = cplex.Cplex()
        >>> c.parameters_1.mip.ordertype.values.cost
        1
        >>> c.parameters_1.mip.ordertype.values[1]
        'cost'
        """
        if item == 0:
            return 'default'
        if item == _constants.CPX_MIPORDER_COST:
            return 'cost'
        if item == _constants.CPX_MIPORDER_BOUNDS:
            return 'bounds'
        if item == _constants.CPX_MIPORDER_SCALEDCOST:
            return 'scaled_cost'
        
class mip_display_constants:
    none = 0
    integer_feasible = 1
    mip_interval_nodes = 2
    node_cuts = 3
    LP_root = 4
    LP_all = 5
    def __getitem__(self, item):
        """Converts a constant to a string.

        Example usage:

        >>> import cplex
        >>> c = cplex.Cplex()
        >>> c.parameters_1.mip.display.values.none
        0
        >>> c.parameters_1.mip.display.values[0]
        'none'
        """
        if item == 0:
            return 'none'
        if item == 1:
            return 'integer_feasible'
        if item == 2:
            return 'mip_interval_nodes'
        if item == 3:
            return 'node_cuts'
        if item == 4:
            return 'LP_root'
        if item == 5:
            return 'LP_all'

class conflict_algorithm_constants:
    auto          = _constants.CPX_CONFLICTALG_AUTO
    fast          = _constants.CPX_CONFLICTALG_FAST
    propagate     = _constants.CPX_CONFLICTALG_PROPAGATE
    presolve      = _constants.CPX_CONFLICTALG_PRESOLVE
    iis           = _constants.CPX_CONFLICTALG_IIS
    limitedsolve  = _constants.CPX_CONFLICTALG_LIMITSOLVE
    solve         = _constants.CPX_CONFLICTALG_SOLVE
    def __getitem__(self, item):
        """Converts a constant to a string.

        Example usage:

        >>> import cplex
        >>> c = cplex.Cplex()
        >>> c.parameters_1.conflict.algorithm.values.fast
        1
        >>> c.parameters_1.conflict.algorithm.values[1]
        'fast'
        """
        if item == _constants.CPX_CONFLICTALG_AUTO:
           return 'auto'
        if item == _constants.CPX_CONFLICTALG_FAST:
           return 'fast'
        if item == _constants.CPX_CONFLICTALG_PROPAGATE:
           return 'propagate'
        if item == _constants.CPX_CONFLICTALG_PRESOLVE:
           return 'presolve'
        if item == _constants.CPX_CONFLICTALG_IIS:
           return 'iis'
        if item == _constants.CPX_CONFLICTALG_LIMITSOLVE:
           return 'limitedsolve'
        if item == _constants.CPX_CONFLICTALG_SOLVE:
           return 'solve'

class dual_pricing_constants:
    auto          = _constants.CPX_DPRIIND_AUTO
    full          = _constants.CPX_DPRIIND_FULL
    steep         = _constants.CPX_DPRIIND_STEEP
    full_steep    = _constants.CPX_DPRIIND_FULLSTEEP
    steep_Q_start = _constants.CPX_DPRIIND_STEEPQSTART
    devex         = _constants.CPX_DPRIIND_DEVEX 
    def __getitem__(self, item):
        """Converts a constant to a string.

        Example usage:

        >>> import cplex
        >>> c = cplex.Cplex()
        >>> c.parameters_1.simplex.dgradient.values.full
        1
        >>> c.parameters_1.simplex.dgradient.values[1]
        'full'
        """
        if item == _constants.CPX_DPRIIND_AUTO:
            return 'auto'
        if item == _constants.CPX_DPRIIND_FULL:
            return 'full'
        if item == _constants.CPX_DPRIIND_STEEP:
            return 'steep'
        if item == _constants.CPX_DPRIIND_FULLSTEEP:
            return 'full_steep'
        if item == _constants.CPX_DPRIIND_STEEPQSTART:
            return 'steep_Q_start'
        if item == _constants.CPX_DPRIIND_DEVEX :
            return 'devex'

class primal_pricing_constants:
    partial       = _constants.CPX_PPRIIND_PARTIAL
    auto          = _constants.CPX_PPRIIND_AUTO
    devex         = _constants.CPX_PPRIIND_DEVEX
    steep         = _constants.CPX_PPRIIND_STEEP
    steep_Q_start = _constants.CPX_PPRIIND_STEEPQSTART
    full          = _constants.CPX_PPRIIND_FULL
    def __getitem__(self, item):
        """Converts a constant to a string.

        Example usage:

        >>> import cplex
        >>> c = cplex.Cplex()
        >>> c.parameters_1.simplex.pgradient.values.full
        4
        >>> c.parameters_1.simplex.pgradient.values[4]
        'full'
        """
        if item == _constants.CPX_PPRIIND_PARTIAL:
            return 'partial'
        if item == _constants.CPX_PPRIIND_AUTO:
            return 'auto'
        if item == _constants.CPX_PPRIIND_DEVEX:
            return 'devex'
        if item == _constants.CPX_PPRIIND_STEEP:
            return 'steep'
        if item == _constants.CPX_PPRIIND_STEEPQSTART:
            return 'steep_Q_start'
        if item == _constants.CPX_PPRIIND_FULL:
            return 'full'

class display_constants:
    none = 0
    normal = 1
    detailed = 2
    def __getitem__(self, item):
        """Converts a constant to a string.

        Example usage:

        >>> import cplex
        >>> c = cplex.Cplex()
        >>> c.parameters_1.simplex.display.values.normal
        1
        >>> c.parameters_1.simplex.display.values[1]
        'normal'
        """
        if item == 0:
            return 'none'
        if item == 1:
            return 'normal'
        if item == 2:
            return 'detailed'

class prered_constants:
    none            = _constants.CPX_PREREDUCE_NOPRIMALORDUAL
    primal          = _constants.CPX_PREREDUCE_PRIMALONLY
    dual            = _constants.CPX_PREREDUCE_DUALONLY
    primal_and_dual = _constants.CPX_PREREDUCE_PRIMALANDDUAL
    def __getitem__(self, item):
        """Converts a constant to a string.

        Example usage:

        >>> import cplex
        >>> c = cplex.Cplex()
        >>> c.parameters_1.preprocessing.reduce.values.dual
        2
        >>> c.parameters_1.preprocessing.reduce.values[2]
        'dual'
        """
        if item == _constants.CPX_PREREDUCE_NOPRIMALORDUAL:
            return 'none'
        if item == _constants.CPX_PREREDUCE_PRIMALONLY:
            return 'primal'
        if item == _constants.CPX_PREREDUCE_DUALONLY:
            return 'dual'
        if item == _constants.CPX_PREREDUCE_PRIMALANDDUAL:
            return 'primal_and_dual'

class coeffreduce_constants:
    none = 0
    integral = 1
    any = 2
    def __getitem__(self, item):
        """Converts a constant to a string.

        Example usage:

        >>> import cplex
        >>> c = cplex.Cplex()
        >>> c.parameters_1.preprocessing.coeffreduce.values.any
        2
        >>> c.parameters_1.preprocessing.coeffreduce.values[2]
        'any'
        """
        if item == 0:
            return 'none'
        if item == 1:
            return 'integral'
        if item == 2:
            return 'any'

class dependency_constants:
    auto = -1
    off = 0
    begin = 1
    end = 2
    begin_and_end = 3
    def __getitem__(self, item):
        """Converts a constant to a string.

        Example usage:

        >>> import cplex
        >>> c = cplex.Cplex()
        >>> c.parameters_1.preprocessing.dependency.values.end
        2
        >>> c.parameters_1.preprocessing.dependency.values[2]
        'end'
        """
        if item == -1:
            return 'auto'
        if item == 0:
            return 'off'
        if item == 1:
            return 'begin'
        if item == 2:
            return 'end'
        if item == 3:
            return 'begin_and_end'

class dual_constants:
    no = -1
    auto = 0
    yes = 1
    def __getitem__(self, item):
        """Converts a constant to a string.

        Example usage:

        >>> import cplex
        >>> c = cplex.Cplex()
        >>> c.parameters_1.preprocessing.dual.values.no
        -1
        >>> c.parameters_1.preprocessing.dual.values[-1]
        'no'
        """
        if item == -1:
            return 'no'
        if item == 0:
            return 'auto'
        if item == 1:
            return 'yes'

class linear_constants:
    only_linear = 0
    full = 1
    def __getitem__(self, item):
        """Converts a constant to a string.

        Example usage:

        >>> import cplex
        >>> c = cplex.Cplex()
        >>> c.parameters_1.preprocessing.linear.values.full
        1
        >>> c.parameters_1.preprocessing.linear.values[1]
        'full'
        """
        if item == 0:
            return 'only_linear'
        if item == 1:
            return 'full'

class repeatpre_constants:
    auto = -1
    off = 0
    without_cuts = 1
    with_cuts = 2
    new_root_cuts = 3
    def __getitem__(self, item):
        """Converts a constant to a string.

        Example usage:

        >>> import cplex
        >>> c = cplex.Cplex()
        >>> c.parameters_1.preprocessing.relax.values.off
        0
        >>> c.parameters_1.preprocessing.relax.values[0]
        'off'
        """
        if item == -1:
            return 'auto'
        if item == 0:
            return 'off'
        if item == 1:
            return 'without_cuts'
        if item == 2:
            return 'with_cuts'
        if item == 3:
            return 'new_root_cuts'

class sym_constants:
    auto = -1
    off   = 0
    mild = 1
    moderate = 2
    aggressive = 3
    more_aggressive = 4
    very_aggressive = 5
    def __getitem__(self, item):
        """Converts a constant to a string.

        Example usage:

        >>> import cplex
        >>> c = cplex.Cplex()
        >>> c.parameters_1.preprocessing.symmetry.values.off
        0
        >>> c.parameters_1.preprocessing.symmetry.values[0]
        'off'
        """
        if item == -1:
            return 'auto'
        if item == 0:
            return 'off'
        if item == 1:
            return 'mild'
        if item == 2:
            return 'moderate'
        if item == 3:
            return 'aggressive'
        if item == 4:
            return 'more_aggressive'
        if item == 5:
            return 'very_aggressive'

class qcpduals_constants:
    no = 0
    if_possible = 1
    force = 2
    def __getitem__(self, item):
        """Converts a constant to a string.

        Example usage:

        >>> import cplex
        >>> c = cplex.Cplex()
        >>> c.parameters_1.preprocessing.qcpduals.values.no
        0
        >>> c.parameters_1.preprocessing.qcpduals.values[0]
        'no'
        """
        if item == 0:
            return 'no'
        if item == 1:
            return 'if_possible'
        if item == 2:
            return 'force'

class sift_alg_constants:
    auto       = _constants.CPX_ALG_AUTOMATIC
    primal     = _constants.CPX_ALG_PRIMAL
    dual       = _constants.CPX_ALG_DUAL
    barrier    = _constants.CPX_ALG_BARRIER
    network    = _constants.CPX_ALG_NET
    def __getitem__(self, item):
        """Converts a constant to a string.

        Example usage:

        >>> import cplex
        >>> c = cplex.Cplex()
        >>> c.parameters_1.sifting.algorithm.values.dual
        2
        >>> c.parameters_1.sifting.algorithm.values[2]
        'dual'
        """
        if item == _constants.CPX_ALG_AUTOMATIC:
            return 'auto'
        if item == _constants.CPX_ALG_PRIMAL:
            return 'primal'
        if item == _constants.CPX_ALG_DUAL:
            return 'dual'
        if item == _constants.CPX_ALG_BARRIER:
            return 'barrier'
        if item == _constants.CPX_ALG_NET:
            return 'network'
    
class feasopt_mode_constants:
    min_sum  = _constants.CPX_FEASOPT_MIN_SUM
    opt_sum  = _constants.CPX_FEASOPT_OPT_SUM
    min_inf  = _constants.CPX_FEASOPT_MIN_INF
    opt_inf  = _constants.CPX_FEASOPT_OPT_INF
    min_quad = _constants.CPX_FEASOPT_MIN_QUAD
    opt_quad = _constants.CPX_FEASOPT_OPT_QUAD         
    def __getitem__(self, item):
        """Converts a constant to a string.

        Example usage:

        >>> import cplex
        >>> c = cplex.Cplex()
        >>> c.parameters_1.feasopt.mode.values.min_sum
        0
        >>> c.parameters_1.feasopt.mode.values[0]
        'min_sum'
        """
        if item == _constants.CPX_FEASOPT_MIN_SUM:
            return 'min_sum'
        if item == _constants.CPX_FEASOPT_OPT_SUM:
            return 'opt_sum'
        if item == _constants.CPX_FEASOPT_MIN_INF:
            return 'min_inf'
        if item == _constants.CPX_FEASOPT_OPT_INF:
            return 'opt_inf'
        if item == _constants.CPX_FEASOPT_MIN_QUAD:
            return 'min_quad'
        if item == _constants.CPX_FEASOPT_OPT_QUAD         :
            return 'opt_quad'
    
class measure_constants:
    average  = _constants.CPX_TUNE_AVERAGE
    minmax   = _constants.CPX_TUNE_MINMAX
    def __getitem__(self, item):
        """Converts a constant to a string.

        Example usage:

        >>> import cplex
        >>> c = cplex.Cplex()
        >>> c.parameters_1.tune.measure.values.minmax
        2
        >>> c.parameters_1.tune.measure.values[2]
        'minmax'
        """
        if item == _constants.CPX_TUNE_AVERAGE:
            return 'average'
        if item == _constants.CPX_TUNE_MINMAX:
            return 'minmax'

class tune_display_constants:
    none = 0
    minimal = 1
    settings = 2
    settings_and_logs = 3
    def __getitem__(self, item):
        """Converts a constant to a string.

        Example usage:

        >>> import cplex
        >>> c = cplex.Cplex()
        >>> c.parameters_1.tune.display.values.minimal
        1
        >>> c.parameters_1.tune.display.values[1]
        'minimal'
        """
        if item == 0:
            return 'none'
        if item == 1:
            return 'minimal'
        if item == 2:
            return 'settings'
        if item == 3:
            return 'settings_and_logs'

class bar_order_constants:
    approx_min_degree = _constants.CPX_BARORDER_AMD
    approx_min_fill   = _constants.CPX_BARORDER_AMF
    nested_dissection = _constants.CPX_BARORDER_ND
    def __getitem__(self, item):
        """Converts a constant to a string.

        Example usage:

        >>> import cplex
        >>> c = cplex.Cplex()
        >>> c.parameters_1.barrier.ordering.values.nested_dissection
        3
        >>> c.parameters_1.barrier.ordering.values[3]
        'nested_dissection'
        """
        if item == _constants.CPX_BARORDER_AMD:
            return 'approx_min_degree'
        if item == _constants.CPX_BARORDER_AMF:
            return 'approx_min_fill'
        if item == _constants.CPX_BARORDER_ND:
            return 'nested_dissection'
    
class crossover_constants:
    none   = _constants.CPX_ALG_NONE
    auto   = _constants.CPX_ALG_AUTOMATIC
    primal = _constants.CPX_ALG_PRIMAL
    dual   = _constants.CPX_ALG_DUAL
    def __getitem__(self, item):
        """Converts a constant to a string.

        Example usage:

        >>> import cplex
        >>> c = cplex.Cplex()
        >>> c.parameters_1.barrier.crossover.values.dual
        2
        >>> c.parameters_1.barrier.crossover.values[2]
        'dual'
        """
        if item == _constants.CPX_ALG_NONE:
            return 'none'
        if item == _constants.CPX_ALG_AUTOMATIC:
            return 'auto'
        if item == _constants.CPX_ALG_PRIMAL:
            return 'primal'
        if item == _constants.CPX_ALG_DUAL:
            return 'dual'

class bar_alg_constants:
    default = 0
    infeas_estimate = 1
    infeas_constant = 2
    standard = 3
    def __getitem__(self, item):
        """Converts a constant to a string.

        Example usage:

        >>> import cplex
        >>> c = cplex.Cplex()
        >>> c.parameters_1.barrier.algorithm.values.standard
        3
        >>> c.parameters_1.barrier.algorithm.values[3]
        'standard'
        """
        if item == 0:
            return 'default'
        if item == 1:
            return 'infeas_estimate'
        if item == 2:
            return 'infeas_constant'
        if item == 3:
            return 'standard'

class bar_start_alg_constants:
    zero_dual = 1
    estimated_dual = 2
    average_primal_zero_dual = 3
    average_primal_estimated_dual = 4
    def __getitem__(self, item):
        """Converts a constant to a string.

        Example usage:

        >>> import cplex
        >>> c = cplex.Cplex()
        >>> c.parameters_1.barrier.startalg.values.zero_dual
        1
        >>> c.parameters_1.barrier.startalg.values[1]
        'zero_dual'
        """
        if item == 1:
            return 'zero_dual'
        if item == 2:
            return 'estimated_dual'
        if item == 3:
            return 'average_primal_zero_dual'
        if item == 4:
            return 'average_primal_estimated_dual'

class par_constants:
    opportunistic  = _constants.CPX_PARALLEL_OPPORTUNISTIC
    auto   = _constants.CPX_PARALLEL_AUTO
    deterministic  = _constants.CPX_PARALLEL_DETERMINISTIC      
    def __getitem__(self, item):
        """Converts a constant to a string.

        Example usage:

        >>> import cplex
        >>> c = cplex.Cplex()
        >>> c.parameters_1.parallel.values.auto
        0
        >>> c.parameters_1.parallel.values[0]
        'auto'
        """
        if item == _constants.CPX_PARALLEL_OPPORTUNISTIC:
            return 'opportunistic'
        if item == _constants.CPX_PARALLEL_AUTO:
            return 'auto'
        if item == _constants.CPX_PARALLEL_DETERMINISTIC:
            return 'deterministic'

class qp_alg_constants:
    auto       = _constants.CPX_ALG_AUTOMATIC
    primal     = _constants.CPX_ALG_PRIMAL
    dual       = _constants.CPX_ALG_DUAL
    network    = _constants.CPX_ALG_NET
    barrier    = _constants.CPX_ALG_BARRIER
    def __getitem__(self, item):
        """Converts a constant to a string.

        Example usage:

        >>> import cplex
        >>> c = cplex.Cplex()
        >>> c.parameters_1.qpmethod.values.auto
        0
        >>> c.parameters_1.qpmethod.values[0]
        'auto'
        """
        if item == _constants.CPX_ALG_AUTOMATIC:
            return 'auto'
        if item == _constants.CPX_ALG_PRIMAL:
            return 'primal'
        if item == _constants.CPX_ALG_DUAL:
            return 'dual'
        if item == _constants.CPX_ALG_NET:
            return 'network'
        if item == _constants.CPX_ALG_BARRIER:
            return 'barrier'

class advance_constants:
    none = 0
    standard = 1
    alternate = 2
    def __getitem__(self, item):
        """Converts a constant to a string.

        Example usage:

        >>> import cplex
        >>> c = cplex.Cplex()
        >>> c.parameters_1.advance.values.none
        0
        >>> c.parameters_1.advance.values[0]
        'none'
        """
        if item == 0:
            return 'none'
        if item == 1:
            return 'standard'
        if item == 2:
            return 'alternate'

class clocktype_constants:
    auto = 0
    CPU  = 1
    wall = 2
    def __getitem__(self, item):
        if item == 0:
            return 'auto'
        if item == 1:
            return 'CPU'
        if item == 2:
            return 'wall'

class solutiontype_constants:
    auto      = 0
    basic     = 1
    non_basic = 2
    def __getitem__(self, item):
        if item == 0:
            return 'auto'
        if item == 1:
            return 'basic'
        if item == 2:
            return 'non_basic'

class optimalitytarget_constants:
    auto           = 0
    optimal_convex = 1
    first_order    = 2
    optimal_global = 3
    def __getitem__(self, item):
        if item == 0:
            return 'auto'
        if item == 1:
            return 'optimal_convex'
        if item == 2:
            return 'first_order'
        if item == 3:
            return 'optimal_global'


class rampup_duration_constants:
    disabled   = _constants.CPX_RAMPUP_DISABLED
    auto       = _constants.CPX_RAMPUP_AUTO
    dynamic    = _constants.CPX_RAMPUP_DYNAMIC
    infinite   = _constants.CPX_RAMPUP_INFINITE
    def __getitem__(self, item):
        """Converts a constant to a string.

        Example usage:

        >>> import cplex
        >>> c = cplex.Cplex()
        >>> c.parameters_1.distmip.rampup.duration.values.dynamic
        1
        >>> c.parameters_1.distmip.rampup.duration.values[1]
        'dynamic'
        """
        if item == _constants.CPX_RAMPUP_DISABLED:
            return 'disabled'
        if item == _constants.CPX_RAMPUP_AUTO:
            return 'auto'
        if item == _constants.CPX_RAMPUP_DYNAMIC:
            return 'dynamic'
        if item == _constants.CPX_RAMPUP_INFINITE:
            return 'infinite'

class datacheck_constants:
    off = _constants.CPX_DATACHECK_OFF
    warn = _constants.CPX_DATACHECK_WARN
    assist = _constants.CPX_DATACHECK_ASSIST
    def __getitem__(self, item):
        """Converts a constant to a string.

        Example usage:

        >>> import cplex
        >>> c = cplex.Cplex()
        >>> c.parameters_1.read.datacheck.values.warn
        1
        >>> c.parameters_1.read.datacheck.values[1]
        'warn'
        """
        if item == _constants.CPX_DATACHECK_OFF:
            return 'off'
        if item == _constants.CPX_DATACHECK_WARN:
            return 'warn'
        if item == _constants.CPX_DATACHECK_ASSIST:
            return 'assist'

class benders_strategy_constants:
    none = _constants.CPX_BENDERSSTRATEGY_OFF
    auto = _constants.CPX_BENDERSSTRATEGY_AUTO
    user = _constants.CPX_BENDERSSTRATEGY_USER
    workers = _constants.CPX_BENDERSSTRATEGY_WORKERS
    full = _constants.CPX_BENDERSSTRATEGY_FULL
    def __getitem__(self, item):
        """Converts a constant to a string.

        Example usage:

        >>> import cplex
        >>> c = cplex.Cplex()
        >>> c.parameters_1.benders.strategy.values.auto
        0
        >>> c.parameters_1.benders.strategy.values[0]
        'auto'
        """
        if item == _constants.CPX_BENDERSSTRATEGY_OFF:
            return 'off'
        if item == _constants.CPX_BENDERSSTRATEGY_AUTO:
            return 'auto'
        if item == _constants.CPX_BENDERSSTRATEGY_USER:
            return 'user'
        if item == _constants.CPX_BENDERSSTRATEGY_WORKERS:
            return 'workers'
        if item == _constants.CPX_BENDERSSTRATEGY_FULL:
            return 'full'
