# --------------------------------------------------------------------------
# File: _pwl.py
# ---------------------------------------------------------------------------
# Licensed Materials - Property of IBM
# 5725-A06 5725-A29 5724-Y48 5724-Y49 5724-Y54 5724-Y55 5655-Y21
# Copyright IBM Corporation 2008, 2017. All Rights Reserved.
#
# US Government Users Restricted Rights - Use, duplication or
# disclosure restricted by GSA ADP Schedule Contract with
# IBM Corp.
# ------------------------------------------------------------------------
"""Piecewise Linear API"""
from ._subinterfaces import BaseInterface
from . import _procedural as _proc
from . import _aux_functions as _aux


class PWLConstraintInterface(BaseInterface):
    """Methods for adding, querying, and modifying PWL constraints.

    A PWL constraint describes a piecewise linear relationship between
    two variables: vary=pwl(varx).  The PWL constraint is described by
    specifying the index of the vary and varx variables involved and by
    providing the breakpoints of the PWL function (specified by the
    (breakx[i],breaky[i]) coordinate pairs).  Before the first segment of
    the PWL function there may be a half-line; its slope is specified by
    preslope.  After the last segment of the the PWL function there may
    be a half-line; its slope is specified by postslope.  Two consecutive
    breakpoints may have the same x coordinate, in such cases there is a
    discontinuity in the PWL function.  Three consecutive breakpoints
    may not have the same x coordinate.
    """

    def __init__(self, cpx):
        """Creates a new PWLConstraintInterface.

        The PWL constraint interface is exposed by the top-level `Cplex`
        class as `Cplex.pwl_constraints`.  This constructor is not meant
        to be used externally.
        """
        super(PWLConstraintInterface, self).__init__(
            cplex=cpx, getindexfunc=_proc.getpwlindex)

    def get_num(self):
        """Returns the number of PWL constraints in the problem.

        Example usage:

        >>> import cplex
        >>> c = cplex.Cplex()
        >>> c.pwl_constraints.get_num()
        0
        >>> indices = c.variables.add(names=['y', 'x'])
        >>> idx = c.pwl_constraints.add(vary='y', varx='x',
        ...                             preslope=0.5, postslope=2.0,
        ...                             breakx=[0.0, 1.0, 2.0],
        ...                             breaky=[0.0, 1.0, 4.0],
        ...                             name='pwl1')
        >>> c.pwl_constraints.get_num()
        1
        """
        return _proc.getnumpwl(self._env._e, self._cplex._lp)

    def add(self, vary, varx, preslope, postslope, breakx, breaky, name=""):
        """Adds a PWL constraint to the problem.

        vary: the index of the 'y' variable in the vary=pwl(varx)
        function.

        varx: the index of the 'x' variable in the vary=pwl(varx)
        function.

        preslope: before the first segment of the PWL function there is
        a half-line; its slope is specified by preslope.

        postslope: after the last segment of the the PWL function there
        is a half-line; its slope is specified by postslope.

        breakx: A list containing the indices of the 'x' variables
        involved.

        breaky: A list containing the indices of the 'y' variables
        involved.

        name: the name of the PWL constraint; defaults to the empty
        string.

        Returns the index of the PWL constraint.

        Example usage:

        >>> import cplex
        >>> c = cplex.Cplex()
        >>> indices = c.variables.add(names=['y', 'x'])
        >>> idx = c.pwl_constraints.add(vary='y', varx='x',
        ...                             preslope=0.5, postslope=2.0,
        ...                             breakx=[0.0, 1.0, 2.0],
        ...                             breaky=[0.0, 1.0, 4.0],
        ...                             name='pwl1')
        >>> c.pwl_constraints.get_num()
        1
        """
        # FIXME: Should we provide defaults for any of the other arguments?
        yidx = self._cplex.variables._conv(vary)
        xidx = self._cplex.variables._conv(varx)
        arg_list = [breakx, breaky]
        nbreaks = _aux.max_arg_length(arg_list)
        _aux.validate_arg_lengths(arg_list, allow_empty=False)

        def _add(vary, varx, preslope, postslope, breakx, breaky, name):
            _proc.addpwl(self._env._e, self._cplex._lp,
                         vary, varx,
                         preslope, postslope,
                         nbreaks, breakx, breaky,
                         name, self._env._apienc)
        return self._add_single(self.get_num, _add, yidx, xidx,
                                preslope, postslope, breakx, breaky,
                                name)

    def delete(self, *args):
        """Deletes a set of PWL constraints.

        May be called by four forms.

        pwl_constraints.delete()
          deletes all PWL constraints from the problem.

        pwl_constraints.delete(i)
          i must be a PWL constraint name or index.  Deletes the PWL
          constraint whose index or name is i.

        pwl_constraints.delete(seq)
          seq must be a sequence of PWL constraint names or indices.
          Deletes the PWL constraints with names or indices in s.
          Equivalent to
          [pwl_constraints.delete(i) for i in s]

        pwl_constraints.delete(begin, end)
          begin and end must be PWL constraint indices with begin <= end
          or PWL constraint names whose indices respect this order.
          Deletes the PWL constraints with indices between begin and end,
          inclusive of end.  Equivalent to
          pwl_constraints.delete(list(range(begin, end + 1)))

        Example usage:

        >>> import cplex
        >>> c = cplex.Cplex()
        >>> indices = c.variables.add(names=['y', 'x'])
        >>> idx = c.pwl_constraints.add(vary='y', varx='x',
        ...                             preslope=0.5, postslope=2.0,
        ...                             breakx=[0.0, 1.0, 2.0],
        ...                             breaky=[0.0, 1.0, 4.0],
        ...                             name='pwl1')
        >>> c.pwl_constraints.get_num()
        1
        >>> c.pwl_constraints.delete(idx)
        >>> c.pwl_constraints.get_num()
        0
        """
        def _delete(begin, end=None):
            _proc.delpwl(self._env._e, self._cplex._lp, begin, end)
        _aux.delete_set_by_range(_delete, self._conv, self.get_num(), *args)

    def get_names(self, *args):
        """Returns the names of a set of PWL constraints.

        May be called by four forms.

        pwl_constraints.get_names()
          return the names of all PWL constraints in the problem.

        pwl_constraints.get_names(i)
          i must be a PWL constraint name or index.  Returns the name of
          PWL constraint i.

        pwl_constraints.get_names(seq)
          seq must be a sequence of PWL constraint names or indices.
          Returns the names of PWL constraints with names or indices in
          s.  Equivalent to
          [pwl_constraints.get_names(i) for i in s]

        pwl_constraints.get_names(begin, end)
          begin and end must be PWL constraint indices with begin <= end
          or PWL constraint names whose indices respect this order.
          Returns the names of PWL constraints with indices between begin
          and end, inclusive of end.  Equivalent to
          pwl_constraints.get_names(range(begin, end + 1))

        Example usage:

        >>> import cplex
        >>> c = cplex.Cplex()
        >>> indices = c.variables.add(names=['y', 'x'])
        >>> idx = c.pwl_constraints.add(vary='y', varx='x',
        ...                             preslope=0.5, postslope=2.0,
        ...                             breakx=[0.0, 1.0, 2.0],
        ...                             breaky=[0.0, 1.0, 4.0],
        ...                             name='pwl1')
        >>> c.pwl_constraints.get_names(idx)
        'pwl1'
        """
        def _get_names(idx):
            return _proc.getpwlname(
                self._env._e, self._cplex._lp, idx,
                self._env._apienc)
        return _aux.apply_freeform_one_arg(
            _get_names, self._conv, self.get_num(), args)

    def get_definitions(self, *args):
        """Returns the definitions of a set of PWL constraints.

        Returns a list of PWL definitions, where each definition is a
        list containing the following components: vary, varx, preslope,
        postslope, breakx, breaky (see `add`).

        May be called by four forms.

        pwl_constraints.get_definitions()
          return the definitions of all PWL constraints in the
          problem.

        pwl_constraints.get_definitions(i)
          i must be a PWL constraint name or index.  Returns the
          definition of PWL constraint i.

        pwl_constraints.get_definitions(seq)
          seq must be a sequence of PWL constraint names or indices.
          Returns the definitions of PWL constraints with names or
          indices in s.  Equivalent to
          [pwl_constraints.get_definitions(i) for i in s]

        pwl_constraints.get_definitions(begin, end)
          begin and end must be PWL constraint indices with begin <= end
          or PWL constraint names whose indices respect this order.  Returns
          the definitions of PWL constraints with indices between
          begin and end, inclusive of end.  Equivalent to
          pwl_constraints.get_definitions(list(range(begin, end + 1)))

        Example usage:

        >>> import cplex
        >>> c = cplex.Cplex()
        >>> indices = c.variables.add(names=['y', 'x'])
        >>> idx = c.pwl_constraints.add(vary='y', varx='x',
        ...                             preslope=0.5, postslope=2.0,
        ...                             breakx=[0.0, 1.0, 2.0],
        ...                             breaky=[0.0, 1.0, 4.0],
        ...                             name='pwl1')
        >>> c.pwl_constraints.get_definitions(idx)
        [0, 1, 0.5, 2.0, [0.0, 1.0, 2.0], [0.0, 1.0, 4.0]]
        """
        def _getpwl(idx):
            return _proc.getpwl(self._env._e, self._cplex._lp, idx)
        return _aux.apply_freeform_one_arg(_getpwl, self._conv,
                                           self.get_num(), args)
