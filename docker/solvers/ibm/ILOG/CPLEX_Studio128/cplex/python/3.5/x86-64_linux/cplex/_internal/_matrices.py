# -----------------------------------------------------------------------
# File: _matrices.py
# -----------------------------------------------------------------------
# Licensed Materials - Property of IBM
# 5725-A06 5725-A29 5724-Y48 5724-Y49 5724-Y54 5724-Y55 5655-Y21
# Copyright IBM Corporation 2008, 2017. All Rights Reserved.
#
# US Government Users Restricted Rights - Use, duplication or
# disclosure restricted by GSA ADP Schedule Contract with
# IBM Corp.
# -----------------------------------------------------------------------
"""
"""

from ._aux_functions import init_list_args, validate_arg_lengths
from ..exceptions import CplexError
from .. import six


class SparsePair(object):
    """A class for storing sparse vector data.

    An instance of this class has two attributes, ind and val.  ind
    specifies the indices and val specifies the values.  ind and val
    must be sequences of the same length.  In general, ind may contain
    any identifier; for example, when a SparsePair object is passed to
    Cplex.linear_constraints.add, its ind attribute may be a list
    containing both variable names and variable indices.
    """

    def __init__(self, ind=None, val=None):
        """Constructor for SparsePair.

        Takes two arguments, ind and val; ind specifies the indices that
        the SparsePair refers to, and val specifies the float values 
        associated with those indices; ind and val must have the same
        length.  If ind or val is omitted, they will default to an empty
        list.

        >>> spair = SparsePair(ind=[0], val=[1.0])
        """
        ind, val = init_list_args(ind, val)
        self.ind = ind
        self.val = val
        if not self.isvalid():
            raise CplexError("Inconsistent input data to SparsePair")

    def __repr__(self):
        """Representation method of SparsePair.

        Example usage:

        >>> SparsePair(ind=[0], val=[1.0])
        SparsePair(ind = [0], val = [1.0])
        """
        return "".join(["SparsePair(ind = ",
                        repr(self.ind),
                        ", val = ",
                        repr(self.val), ")"])

    def isvalid(self):
        """Tests that ind and val have the same length.

        Example usage:

        >>> spair = SparsePair(ind=[0, 1, 2], val=[1.0, 1.0, 1.0])
        >>> spair.isvalid()
        True
        """
        return len(self.ind) == len(self.val)

    def unpack(self):
        """Extracts the indices and values sequences as a tuple.

        Returns ind and val as given in __init__.

        >>> spair = SparsePair(ind=[0, 1, 2], val=[1.0, 1.0, 1.0])
        >>> ind, val = spair.unpack()
        """
        return self.ind, self.val


class _HBMatrix(object):
    """non-public

    """

    def __init__(self, matrix=None):
        """non-public"""
        self.matbeg = []
        self.matind = []
        self.matval = []
        if matrix is not None:
            for vector in matrix:
                if isinstance(vector, SparsePair):
                    v0 = vector.ind
                    v1 = vector.val
                else:
                    v0 = vector[0]
                    v1 = vector[1]
                if len(v0) != len(v1):
                    raise CplexError("Inconsistent input data to _HBMatrix")
                self.matbeg.append(len(self.matind))
                self.matind.extend(v0)
                self.matval.extend(v1)

    def __len__(self):
        """non-public"""
        return len(self.matbeg)

    def __getitem__(self, key):
        """non-public"""
        if isinstance(key, six.integer_types):
            if key < 0:
                key += len(self)
            begin = self.matbeg[key]
            if key == len(self) - 1:
                end = len(self.matind)
            else:
                end = self.matbeg[key + 1]
            return SparsePair(self.matind[begin:end], self.matval[begin:end])
        elif isinstance(key, slice):
            start, stop, step = key.start, key.stop, key.step
            if start is None:
                start = 0
            if stop is None or stop > len(self):
                stop = len(self)
            if step is None:
                step = 1
            return [self[i] for i in range(start, stop, step)]
        else:
            raise TypeError

    def __iter__(self):
        for i in range(len(self)):
            yield self[i]


class SparseTriple(object):
    """A class for storing sparse matrix data.

    An instance of this class has three attributes, ind1, ind2, and val.
    ind1 and ind2 specify the indices and val specifies the values.
    ind1, ind2, and val must be sequences of the same length.  In
    general, ind1 and ind2 may contain any identifier; for example, when
    a SparseTriple object is passed to Cplex.quadratic_constraints.add,
    its ind1 attribute may be a list containing both variable names and
    variable indices.
    """

    def __init__(self, ind1=None, ind2=None, val=None):
        """Constructor for SparseTriple.

        Takes three arguments, ind1, ind2 and val, specifying the
        indices that the SparseTriple refers to and the float values
        associated with those indices, respectively.  ind1, ind2, and
        val must all have the same length.  If ind1, ind2, or val is
        omitted, they will default to an empty list.

        >>> striple = SparseTriple(ind1=[0], ind2=[0], val=[1.0])
        """
        ind1, ind2, val = init_list_args(ind1, ind2, val)
        self.ind1 = ind1
        self.ind2 = ind2
        self.val = val
        if not self.isvalid():
            raise CplexError("Inconsistent input data to SparseTriple")

    def __repr__(self):
        """Representation method of SparseTriple.

        Example usage:

        >>> SparseTriple(ind1=[0], ind2=[0], val=[1.0])
        SparseTriple(ind1 = [0], ind2 = [0], val = [1.0])
        """
        return "".join(["SparseTriple(ind1 = ",
                        repr(self.ind1),
                        ", ind2 = ",
                        repr(self.ind2),
                        ", val = ",
                        repr(self.val), ")"])

    def isvalid(self):
        """Tests that ind1, ind2, and val have the same length.

        Example usage:

        >>> striple = SparseTriple(ind1=[0, 1], ind2=[0, 1],
        ...                        val=[1.0, 1.0])
        >>> striple.isvalid()
        True
        """
        return (len(self.ind1) == len(self.ind2) and
                len(self.ind1) == len(self.val))

    def unpack(self):
        """Extracts the indices and values sequences as a tuple.

        Returns ind1, ind2, and val as given in __init__.

        >>> striple = SparseTriple(ind1=[0, 1], ind2=[0, 1],
        ...                        val=[1.0, 1.0])
        >>> ind1, ind2, val = striple.unpack()
        """
        return self.ind1, self.ind2, self.val


def unpack_pair(item):
    """Extracts the indices and values from an object.

    The argument item can either be an instance of SparsePair or a
    sequence of length two.

    Example usage:

    >>> sp = SparsePair()
    >>> ind, val = unpack_pair(sp)
    >>> lin_expr = [[], []]
    >>> ind, val = unpack_pair(lin_expr)
    """
    try:
        assert item.isvalid()
        ind, val = item.unpack()
    except AttributeError:
        ind, val = item[0:2]
    validate_arg_lengths([ind, val])
    return ind, val


def unpack_triple(item):
    """Extracts the indices and values from an object.

    The argument item can either be an instance of SparseTriple or a
    sequence of length three.

    Example usage:

    >>> st = SparseTriple()
    >>> ind1, ind2, val = unpack_triple(st)
    >>> quad_expr = [[], [], []]
    >>> ind1, ind2, val = unpack_triple(quad_expr)
    """
    try:
        assert item.isvalid()
        ind1, ind2, val = item.unpack()
    except AttributeError:
        ind1, ind2, val = item[0:3]
    validate_arg_lengths([ind1, ind2, val])
    return ind1, ind2, val
