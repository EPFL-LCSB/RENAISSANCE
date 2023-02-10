# --------------------------------------------------------------------------
# File: _anno.py
# ---------------------------------------------------------------------------
# Licensed Materials - Property of IBM
# 5725-A06 5725-A29 5724-Y48 5724-Y49 5724-Y54 5724-Y55 5655-Y21
# Copyright IBM Corporation 2008, 2017. All Rights Reserved.
#
# US Government Users Restricted Rights - Use, duplication or
# disclosure restricted by GSA ADP Schedule Contract with
# IBM Corp.
# ------------------------------------------------------------------------
"""Annotation API"""
from ._subinterfaces import BaseInterface
from . import _procedural as _proc
from . import _aux_functions as _aux
from . import _constants


class AnnotationObjectType(object):
    """Constants defining annotation object types."""
    objective = _constants.CPX_ANNOTATIONOBJ_OBJ
    variable = _constants.CPX_ANNOTATIONOBJ_COL
    row = _constants.CPX_ANNOTATIONOBJ_ROW
    sos_constraint = _constants.CPX_ANNOTATIONOBJ_SOS
    indicator_constraint = _constants.CPX_ANNOTATIONOBJ_IND
    quadratic_constraint = _constants.CPX_ANNOTATIONOBJ_QC

    def __getitem__(self, item):
        """Converts a constant to a string.

        Example usage:

        >>> import cplex
        >>> c = cplex.Cplex()
        >>> c.long_annotations.object_type.objective
        0
        >>> c.long_annotations.object_type[0]
        'objective'
        """
        if item == _constants.CPX_ANNOTATIONOBJ_OBJ:
            return "objective"
        if item == _constants.CPX_ANNOTATIONOBJ_COL:
            return "variable"
        if item == _constants.CPX_ANNOTATIONOBJ_ROW:
            return "row"
        if item == _constants.CPX_ANNOTATIONOBJ_SOS:
            return "sos_constraint"
        if item == _constants.CPX_ANNOTATIONOBJ_IND:
            return "indicator_constraint"
        if item == _constants.CPX_ANNOTATIONOBJ_QC:
            return "quadratic_constraint"


class AnnotationInterface(BaseInterface):
    """Methods for adding, querying, and modifying annotations."""

    object_type = AnnotationObjectType()
    """See `AnnotationObjectType()` """

    def _getnumobjtype(self, objtype):
        if objtype == self.object_type.objective:
            return 1
        elif objtype == self.object_type.variable:
            return _proc.getnumcols(self._env._e, self._cplex._lp)
        elif objtype == self.object_type.row:
            return _proc.getnumrows(self._env._e, self._cplex._lp)
        elif objtype == self.object_type.sos_constraint:
            return _proc.getnumsos(self._env._e, self._cplex._lp)
        elif objtype == self.object_type.indicator_constraint:
            return _proc.getnumindconstrs(self._env._e, self._cplex._lp)
        elif objtype == self.object_type.quadratic_constraint:
            return _proc.getnumqconstrs(self._env._e, self._cplex._lp)
        else:
            raise ValueError("invalid objtype")


class LongAnnotationInterface(AnnotationInterface):
    """Methods for adding, querying, and modifying long annotations."""

    benders_annotation = _constants.CPX_BENDERS_ANNOTATION
    """String constant for the name of the Benders annotation."""

    benders_mastervalue = _constants.CPX_BENDERS_MASTERVALUE
    """Default value for the Benders master partition."""

    def __init__(self, cpx):
        """Creates a new LongAnnotationInterface.

        The long annotation interface is exposed by the top-level `Cplex`
        class as `Cplex.long_annotations`.  This constructor is not meant
        to be used externally.
        """
        super(LongAnnotationInterface, self).__init__(
            cplex=cpx, getindexfunc=_proc.getlongannoindex)

    def get_num(self):
        """Returns the number of long annotations in the problem.

        Example usage:

        >>> import cplex
        >>> c = cplex.Cplex()
        >>> c.long_annotations.get_num()
        0
        >>> idx = c.long_annotations.add('ann1', 0)
        >>> c.long_annotations.get_num()
        1
        """
        return _proc.getnumlonganno(self._env._e, self._cplex._lp)

    def add(self, name, defval):
        """Adds an annotation to the problem.

        name: the name of the annotation.

        defval: the default value for annotation objects.

        Returns the index of the added annotation.

        Example usage:

        >>> import cplex
        >>> c = cplex.Cplex()
        >>> idx = c.long_annotations.add(name='ann1', defval=0)
        >>> c.long_annotations.get_num()
        1
        """
        # For Python 2.7, int() will automatically upconvert to long
        # if necessary.  For 3.x, there is only int (they have been
        # unified).
        def _add(name, defval):
            _proc.newlonganno(
                self._env._e, self._cplex._lp, name, int(defval),
                self._env._apienc)
        return self._add_single(self.get_num, _add, name, defval)

    def delete(self, *args):
        """Deletes a set of long annotations.

        May be called by four forms.

        long_annotations.delete()
          deletes all long annotations from the problem.

        long_annotations.delete(i)
          i must be an annotation name or index.  Deletes the long
          annotation whose index or name is i.

        long_annotations.delete(seq)
          seq must be a sequence of annotation names or indices.
          Deletes the long annotations with names or indices in s.
          Equivalent to
          [long_annotations.delete(i) for i in s]

        long_annotations.delete(begin, end)
          begin and end must be annotation indices with begin <= end
          or annotation names whose indices respect this order.  Deletes
          the long annotations with indices between begin and end,
          inclusive of end.  Equivalent to
          long_annotations.delete(list(range(begin, end + 1)))

        Example usage:

        >>> import cplex
        >>> c = cplex.Cplex()
        >>> idx = c.long_annotations.add('ann1', 0)
        >>> c.long_annotations.get_num()
        1
        >>> c.long_annotations.delete(idx)
        >>> c.long_annotations.get_num()
        0
        """
        def _delete(begin, end=None):
            _proc.dellonganno(self._env._e, self._cplex._lp, begin, end)
        _aux.delete_set_by_range(_delete, self._conv, self.get_num(), *args)

    def get_names(self, *args):
        """Returns the names of a set of long annotations.

        May be called by four forms.

        long_annotations.get_names()
          return the names of all long annotations in the problem.

        long_annotations.get_names(i)
          i must be an annotation name or index.  Returns the name of
          long annotation i.

        long_annotations.get_names(seq)
          seq must be a sequence of annotation names or indices.
          Returns the names of long annotations with names or indices in
          s.  Equivalent to
          [long_annotations.get_names(i) for i in s]

        long_annotations.get_names(begin, end)
          begin and end must be annotation indices with begin <= end
          or annotation names whose indices respect this order.  Returns
          the names of long annotations with indices between begin and
          end, inclusive of end.  Equivalent to
          long_annotations.get_names(range(begin, end + 1))

        Example usage:

        >>> import cplex
        >>> c = cplex.Cplex()
        >>> [c.long_annotations.add('ann{0}'.format(i), i)
        ...  for i in range(1, 6)]
        [0, 1, 2, 3, 4]
        >>> c.long_annotations.get_names()
        ['ann1', 'ann2', 'ann3', 'ann4', 'ann5']
        >>> c.long_annotations.get_names(0)
        'ann1'
        >>> c.long_annotations.get_names([0, 2, 4])
        ['ann1', 'ann3', 'ann5']
        >>> c.long_annotations.get_names(1, 3)
        ['ann2', 'ann3', 'ann4']
        """
        def _get_names(idx):
            return _proc.getlongannoname(
                self._env._e, self._cplex._lp, idx,
                self._env._apienc)
        return _aux.apply_freeform_one_arg(
            _get_names, self._conv, self.get_num(), args)

    def get_default_values(self, *args):
        """Returns the default value of a set of long annotations.

        May be called by four forms.

        long_annotations.get_default_values()
          return the default values of all long annotations in the
          problem.

        long_annotations.get_default_values(i)
          i must be an annotation name or index.  Returns the default
          value of long annotation i.

        long_annotations.get_default_values(seq)
          seq must be a sequence of annotation names or indices.
          Returns the default values of long annotations with names or
          indices in s.  Equivalent to
          [long_annotations.get_default_values(i) for i in s]

        long_annotations.get_default_values(begin, end)
          begin and end must be annotation indices with begin <= end
          or annotation names whose indices respect this order.  Returns
          the default values of long annotations with indices between
          begin and end, inclusive of end.  Equivalent to
          long_annotations.get_default_values(list(range(begin, end + 1)))

        Example usage:

        >>> import cplex
        >>> c = cplex.Cplex()
        >>> idx1 = c.long_annotations.add(name='ann1', defval=0)
        >>> idx2 = c.long_annotations.add(name='ann2', defval=1)
        >>> c.long_annotations.get_default_values()
        [0, 1]
        """
        def _getdefval(idx):
            return _proc.getlongannodefval(
                self._env._e, self._cplex._lp, idx)
        return _aux.apply_freeform_one_arg(
            _getdefval, self._conv, self.get_num(), args)

    def set_values(self, idx, objtype, *args):
        """Sets the values for objects in the specified long annotation.

        idx: the long annotation index or name.

        objtype: the annotation object type.

        Can be called by two forms:

        long_annotations.set_values(idx, objtype, i, val)
          i must be a name or index.  Changes the long annotation value
          of the object identified by i.

        long_annotations.set_values(idx, objtype, seq)
          seq is a sequence of pairs (i, val) as described above.
          Changes the long annotation values for the specified objects.

        Example usage:

        >>> import cplex
        >>> c = cplex.Cplex()
        >>> idx = c.long_annotations.add('ann1', 0)
        >>> objtype = c.long_annotations.object_type.objective
        >>> c.long_annotations.set_values(idx, objtype, 0, 1)
        >>> c.long_annotations.get_values(idx, objtype, 0)
        1
        >>> indices = c.variables.add(names=['v1', 'v2', 'v3'])
        >>> objtype = c.long_annotations.object_type.variable
        >>> c.long_annotations.set_values(idx, objtype,
        ...                               [(i, 1) for i in indices])
        >>> c.long_annotations.get_values(idx, objtype)
        [1, 1, 1]
        """
        def _set_values(ind, val):
            _proc.setlonganno(self._env._e, self._cplex._lp,
                              self._conv(idx), objtype, ind, val)
        _aux.apply_pairs(_set_values, self._conv, *args)

    def get_values(self, idx, objtype, *args):
        """Returns the long annotation values for the specified objects.

        idx: the long annotation index or name.

        objtype: the annotation object type.

        Can be called by four forms:

        long_annotations.get_values(idx, objtype)
          return the values of all objects for a given annotation.

        long_annotations.get_values(idx, objtype, i)
          i must be a name or index.  Returns the long annotation value
          of the object identified by i.

        long_annotations.get_values(idx, objtype, seq)
          seq is a sequence of object names or indices.  Returns the
          long annotation values for the specified objects.  Equivalent
          to
          [long_annotations.get_values(idx, objtype, i) for i in seq]

        long_annotations.get_values(idx, objtype, begin, end)
          begin and end must be object indices with begin <= end or
          object names whose indices respect this order.  Returns the
          long annotation values of objects with indices between begin
          and end, inclusive of end.  Equivalent to
          long_annotations.get_values(range(begin, end + 1))

        Example usage:

        >>> import cplex
        >>> c = cplex.Cplex()
        >>> idx = c.long_annotations.add('ann1', 0)
        >>> objtype = c.long_annotations.object_type.objective
        >>> c.long_annotations.set_values(idx, objtype, 0, 1)
        >>> c.long_annotations.get_values(idx, objtype, 0)
        1
        >>> indices = c.variables.add(names=['v1', 'v2', 'v3'])
        >>> objtype = c.long_annotations.object_type.variable
        >>> c.long_annotations.set_values(idx, objtype,
        ...                               [(i, 1) for i in indices])
        >>> c.long_annotations.get_values(idx, objtype, list(indices))
        [1, 1, 1]
        """
        def _get_values(begin, end=self._getnumobjtype(objtype) - 1):
            return _proc.getlonganno(self._env._e, self._cplex._lp,
                                     self._conv(idx), objtype,
                                     begin, end)
        return _aux.apply_freeform_two_args(
            _get_values, self._conv, args)


class DoubleAnnotationInterface(AnnotationInterface):
    """Methods for adding, querying, and modifying double annotations."""

    def __init__(self, cpx):
        """Creates a new DoubleAnnotationInterface.

        The double annotation interface is exposed by the top-level
        `Cplex` class as `Cplex.double_annotations`.  This constructor is
        not meant to be used externally.
        """
        super(DoubleAnnotationInterface, self).__init__(
            cplex=cpx, getindexfunc=_proc.getdblannoindex)

    def get_num(self):
        """Returns the number of double annotations in the problem.

        Example usage:

        >>> import cplex
        >>> c = cplex.Cplex()
        >>> c.double_annotations.get_num()
        0
        >>> idx = c.double_annotations.add('ann1', 0.0)
        >>> c.double_annotations.get_num()
        1
        """
        return _proc.getnumdblanno(self._env._e, self._cplex._lp)

    def add(self, name, defval):
        """Adds an annotation to the problem.

        name: the name of the annotation.

        defval: the default value for annotation objects.

        Returns the index of the added annotation.

        Example usage:

        >>> import cplex
        >>> c = cplex.Cplex()
        >>> idx = c.double_annotations.add(name='ann1', defval=0.0)
        >>> c.double_annotations.get_num()
        1
        """
        def _add(name, defval):
            _proc.newdblanno(
                self._env._e, self._cplex._lp, name, float(defval),
                self._env._apienc)
        return self._add_single(self.get_num, _add, name, defval)

    def delete(self, *args):
        """Deletes a set of double annotations.

        May be called by four forms.

        double_annotations.delete()
          deletes all double annotations from the problem.

        double_annotations.delete(i)
          i must be an annotation name or index.  Deletes the double
          annotation whose index or name is i.

        double_annotations.delete(seq)
          seq must be a sequence of annotation names or indices.
          Deletes the double annotations with names or indices in s.
          Equivalent to
          [double_annotations.delete(i) for i in s]

        double_annotations.delete(begin, end)
          begin and end must be annotation indices with begin <= end
          or annotation names whose indices respect this order.  Deletes
          the double annotations with indices between begin and end,
          inclusive of end.  Equivalent to
          double_annotations.delete(list(range(begin, end + 1)))

        Example usage:

        >>> import cplex
        >>> c = cplex.Cplex()
        >>> idx = c.double_annotations.add('ann1', 0.0)
        >>> c.double_annotations.get_num()
        1
        >>> c.double_annotations.delete(idx)
        >>> c.double_annotations.get_num()
        0
        """
        def _delete(begin, end=None):
            _proc.deldblanno(self._env._e, self._cplex._lp, begin, end)
        _aux.delete_set_by_range(_delete, self._conv, self.get_num(), *args)

    def get_names(self, *args):
        """Returns the names of a set of double annotations.

        May be called by four forms.

        double_annotations.get_names()
          return the names of all double annotations in the problem.

        double_annotations.get_names(i)
          i must be an annotation name or index.  Returns the name of
          double annotation i.

        double_annotations.get_names(seq)
          seq must be a sequence of annotation names or indices.
          Returns the names of double annotations with names or indices
          in s.  Equivalent to
          [double_annotations.get_names(i) for i in s]

        double_annotations.get_names(begin, end)
          begin and end must be annotation indices with begin <= end
          or annotation names whose indices respect this order.  Returns
          the names of double annotations with indices between begin and
          end, inclusive of end.  Equivalent to
          double_annotations.get_names(range(begin, end + 1))

        Example usage:

        >>> import cplex
        >>> c = cplex.Cplex()
        >>> [c.double_annotations.add('ann{0}'.format(i), i)
        ...  for i in range(1, 6)]
        [0, 1, 2, 3, 4]
        >>> c.double_annotations.get_names()
        ['ann1', 'ann2', 'ann3', 'ann4', 'ann5']
        >>> c.double_annotations.get_names(0)
        'ann1'
        >>> c.double_annotations.get_names([0, 2, 4])
        ['ann1', 'ann3', 'ann5']
        >>> c.double_annotations.get_names(1, 3)
        ['ann2', 'ann3', 'ann4']
        """
        def _get_names(idx):
            return _proc.getdblannoname(
                self._env._e, self._cplex._lp, idx,
                self._env._apienc)
        return _aux.apply_freeform_one_arg(
            _get_names, self._conv, self.get_num(), args)

    def get_default_values(self, *args):
        """Returns the default value of a set of double annotations.

        May be called by four forms.

        double_annotations.get_default_values()
          return the default values of all double annotations in the
          problem.

        double_annotations.get_default_values(i)
          i must be an annotation name or index.  Returns the default
          value of double annotation i.

        double_annotations.get_default_values(seq)
          seq must be a sequence of annotation names or indices.
          Returns the default values of double annotations with names or
          indices in s.  Equivalent to
          [double_annotations.get_default_values(i) for i in s]

        double_annotations.get_default_values(begin, end)
          begin and end must be annotation indices with begin <= end
          or annotation names whose indices respect this order.  Returns
          the default values of double annotations with indices between
          begin and end, inclusive of end.  Equivalent to
          double_annotations.get_default_values(list(range(begin, end + 1)))

        Example usage:

        >>> import cplex
        >>> c = cplex.Cplex()
        >>> idx1 = c.double_annotations.add(name='ann1', defval=0.0)
        >>> idx2 = c.double_annotations.add(name='ann2', defval=1.0)
        >>> c.double_annotations.get_default_values()
        [0.0, 1.0]
        """
        def _getdefval(idx):
            return _proc.getdblannodefval(
                self._env._e, self._cplex._lp, idx)
        return _aux.apply_freeform_one_arg(
            _getdefval, self._conv, self.get_num(), args)

    def set_values(self, idx, objtype, *args):
        """Sets the values for objects in the specified double annotation.

        idx: the double annotation index or name.

        objtype: the annotation object type.

        Can be called by two forms:

        double_annotations.set_values(idx, objtype, i, val)
          i must be a name or index.  Changes the double annotation
          value of the object identified by i.

        double_annotations.set_values(idx, objtype, seq)
          seq is a sequence of pairs (i, val) as described above.
          Changes the double annotation values for the specified
          objects.

        Example usage:

        >>> import cplex
        >>> c = cplex.Cplex()
        >>> idx = c.double_annotations.add('ann1', 0.0)
        >>> objtype = c.double_annotations.object_type.objective
        >>> c.double_annotations.set_values(idx, objtype, 0, 1.0)
        >>> c.double_annotations.get_values(idx, objtype, 0)
        1.0
        >>> indices = c.variables.add(names=['v1', 'v2', 'v3'])
        >>> objtype = c.double_annotations.object_type.variable
        >>> c.double_annotations.set_values(idx, objtype,
        ...                                 [(i, 1.0) for i in indices])
        >>> c.double_annotations.get_values(idx, objtype)
        [1.0, 1.0, 1.0]
        """
        def _set_values(ind, val):
            _proc.setdblanno(self._env._e, self._cplex._lp,
                             self._conv(idx), objtype, ind, val)
        _aux.apply_pairs(_set_values, self._conv, *args)

    def get_values(self, idx, objtype, *args):
        """Returns the double annotation values for the specified objects.

        idx: the double annotation index or name.

        objtype: the annotation object type.

        Can be called by four forms:

        double_annotations.get_values(idx, objtype)
          return the values of all objects for a given annotation.

        double_annotations.get_values(idx, objtype, i)
          i must be a name or index.  Returns the double annotation
          value of the object identified by i.

        double_annotations.get_values(idx, objtype, seq)
          seq is a sequence of object names or indices.  Returns the
          double annotation values for the specified objects.
          Equivalent to
          [double_annotations.get_values(idx, objtype, i) for i in seq]

        double_annotations.get_values(idx, objtype, begin, end)
          begin and end must be object indices with begin <= end or
          object names whose indices respect this order.  Returns the
          double annotation values of objects with indices between begin
          and end, inclusive of end.  Equivalent to
          double_annotations.get_values(range(begin, end + 1))

        Example usage:

        >>> import cplex
        >>> c = cplex.Cplex()
        >>> idx = c.double_annotations.add('ann1', 0.0)
        >>> objtype = c.double_annotations.object_type.objective
        >>> c.double_annotations.set_values(idx, objtype, 0, 1.0)
        >>> c.double_annotations.get_values(idx, objtype, 0)
        1.0
        >>> indices = c.variables.add(names=['v1', 'v2', 'v3'])
        >>> objtype = c.double_annotations.object_type.variable
        >>> c.double_annotations.set_values(idx, objtype,
        ...                                 [(i, 1.0) for i in indices])
        >>> c.double_annotations.get_values(idx, objtype, list(indices))
        [1.0, 1.0, 1.0]
        """
        def _get_values(begin, end=self._getnumobjtype(objtype) - 1):
            return _proc.getdblanno(self._env._e, self._cplex._lp,
                                    self._conv(idx), objtype,
                                    begin, end)
        return _aux.apply_freeform_two_args(
            _get_values, self._conv, args)
