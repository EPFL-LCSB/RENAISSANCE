# --------------------------------------------------------------------------
# File: _aux_functions.py 
# ---------------------------------------------------------------------------
# Licensed Materials - Property of IBM
# 5725-A06 5725-A29 5724-Y48 5724-Y49 5724-Y54 5724-Y55 5655-Y21
# Copyright IBM Corporation 2008, 2017. All Rights Reserved.
#
# US Government Users Restricted Rights - Use, duplication or
# disclosure restricted by GSA ADP Schedule Contract with
# IBM Corp.
# ------------------------------------------------------------------------
"""


"""
import functools
import inspect
import warnings

from ..exceptions import CplexError, WrongNumberOfArgumentsError
from .. import six
from ..six.moves import (map, zip, range)


class deprecated(object):
    """A decorator that marks methods/functions as deprecated."""

    def __init__(self, version):
        self.version = version

    def __call__(self, cls_or_func):
        if (inspect.isfunction(cls_or_func) or
            inspect.ismethod(cls_or_func)):
            fmt = "{0} function or method"
        # NOTE: Doesn't work for classes .. haven't figured that out yet.
        #       Specifically, when a decorated class is used as a base
        #       class.
        # elif inspect.isclass(cls_or_func):
        #     fmt = "{0} class"
        else:
            raise TypeError(type(cls_or_func))
        msg = _getdeprecatedmsg(fmt.format(cls_or_func.__name__),
                                self.version)
        @functools.wraps(cls_or_func)
        def wrapped(*args, **kwargs):
            warnings.warn(msg, DeprecationWarning, stacklevel=2)
            return cls_or_func(*args, **kwargs)
        return wrapped

def deprecated_class(name, version, stacklevel=3):
    """Emits a warning for a deprecated class.

    This should be called in __init__.

    name - the name of the class (e.g., PresolveCallback).

    version - the version at which the class was deprecated (e.g.,
              "V12.7.1").

    stacklevel - indicates how many levels up the stack is the caller.
    """
    msg = _getdeprecatedmsg("{0} class".format(name), version)
    warnings.warn(msg, DeprecationWarning, stacklevel=stacklevel)

def _getdeprecatedmsg(item, version):
    return "the {0} is deprecated since {1}".format(item, version)

def validate_arg_lengths(arg_list, allow_empty=True):
    """non-public"""
    arg_lengths = [len(x) for x in arg_list]
    max_length = max(arg_lengths)
    for arg_length in arg_lengths:
        if ((not allow_empty or arg_length != 0) and
            arg_length != max_length):
            raise CplexError("Inconsistent arguments")
    return max_length

def make_ranges(indices):
    """non-public"""
    ranges = []
    i = 0
    j = 0
    while i < len(indices):
        while j < len(indices) - 1 and indices[j + 1] == indices[j] + 1:
            j += 1
        ranges.append((indices[i], indices[j]))
        i = j + 1
        j = i
    return ranges

def apply_freeform_two_args(fn, convert, args):
    """non-public"""
    def con(a):
        if isinstance(a, six.string_types):
            return convert(a)
        else:
            return a
    if len(args) == 2:
        conarg0, conarg1 = (con(args[0]), con(args[1]))
        if (isinstance(conarg0, six.integer_types) and
            isinstance(conarg1, six.integer_types)):
            return fn(conarg0, conarg1)
        else:
            raise TypeError("expecting names or indices")
    elif len(args) == 1:
        if isinstance(args[0], (list, tuple)):
            retval = []
            for member in map(fn, *zip(*make_ranges(list(map(con, args[0]))))):
                retval.extend(member)
            return retval
        conarg0 = con(args[0])
        if isinstance(conarg0, six.integer_types):
            return fn(conarg0, conarg0)[0]
        else:
            raise TypeError("expecting name or index")
    elif len(args) == 0:
        return fn(0)
    else:
        raise WrongNumberOfArgumentsError()

def apply_freeform_one_arg(fn, convert, maxval, args):
    """non-public"""
    def con(a):
        if isinstance(a, six.string_types):
            return convert(a)
        else:
            return a
    if len(args) == 2:
        conarg0, conarg1 = (con(args[0]), con(args[1]))
        if (isinstance(conarg0, six.integer_types) and
            isinstance(conarg1, six.integer_types)):
            return [fn(x) for x in range(conarg0, conarg1 + 1)]
        else:
            raise TypeError("expecting names or indices")
    elif len(args) == 1:
        if isinstance(args[0], (list, tuple)):
            return [fn(x) for x in map(con, args[0])]
        conarg0 = con(args[0])
        if isinstance(conarg0, six.integer_types):
            return fn(conarg0)
        else:
            raise TypeError("expecting name or index")
    elif len(args) == 0:
        return apply_freeform_one_arg(fn, convert, 0,
                                      (list(range(maxval)),))
    else:
        raise WrongNumberOfArgumentsError()

def apply_pairs(fn, convert, *args):
    """non-public"""
    def con(a):
        if isinstance(a, six.string_types):
            return convert(a)
        else:
            return a
    if len(args) == 2:
        fn([con(args[0])], [args[1]])
    else:
        a1, a2 = zip(*args[0])
        fn(list(map(con, a1)), list(a2))

def delete_set_by_range(fn, convert, max_num, *args):
    """non-public"""
    if len(args) == 0:
        # Delete All:
        if max_num > 0:
            fn(0, max_num-1)
    elif len(args) == 1:
        # Delete all items from a possibly unordered list of mixed types:
        if isinstance(convert(args[0]), six.integer_types):
            args = [convert(args[0])]
        else:
            args = [convert(i) for i in args[0]]
        for i in sorted(args, reverse=True):
            fn(i, i)
    elif len(args) == 2:
        # Delete range from arg[0] to arg[1]:
        fn(convert(args[0]), convert(args[1]))
    else:
        raise WrongNumberOfArgumentsError()

class _group:
    """Object to contain constraint groups"""

    def __init__(self, gp):
        """Constructor for the _group object

        gp is a list of tuples of length two (the first entry of which
        is the preference for the group (a float), the second of which
        is a tuple of pairs (type, id), where type is an attribute of
        conflict.constraint_type and id is either an index or a valid
        name for the type).

        Example input: [(1.0, ((2, 0),)), (1.0, ((3, 0), (3, 1)))]
        """
        self._gp = gp

        
def make_group(conv, max_num, c_type, *args):
    """Returns a _group object

    input:
    conv    - a function that will convert names to indices
    max_num - number of existing constraints of a given type
    c_type  - constraint type
    args    - arbitrarily many arguments (see description below)

    If args is empty, every constraint/bound is assigned weight 1.0.

    If args is of length one or more, every constraint/bound is assigned
    a weight equal to the float passed in as the first item.

    If args contains additional items, they determine a subset of
    constraints/bounds to be included.  If one index or name is
    specified, it is the only one that will be included.  If two indices
    or names are specified, all constraints between the first and the
    second, inclusive, will be included.  If a sequence of names or
    indices is passed in, all of their constraints/bounds will be
    included.

    See example usage in _subinterfaces.ConflictInterface.
    """
    if len(args) <= 1:
        cons = list(range(max_num))
    if len(args) == 0:
        weight = 1.0
    else:
        weight = args[0]
    if len(args) == 2:
        weight = args[0]
        if isinstance(conv(args[1]), six.integer_types):
            cons = [conv(args[1])]
        else:
            cons = map(conv, args[1])
    elif len(args) == 3:
        cons = list(range(conv(args[1]), conv(args[2]) + 1))
    return _group([(weight, ((c_type, i),)) for i in cons])
