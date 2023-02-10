# --------------------------------------------------------------------------
# File: _list_array_utils.py
# ---------------------------------------------------------------------------
# Licensed Materials - Property of IBM
# 5725-A06 5725-A29 5724-Y48 5724-Y49 5724-Y54 5724-Y55 5655-Y21
# Copyright IBM Corporation 2008, 2017. All Rights Reserved.
#
# US Government Users Restricted Rights - Use, duplication or
# disclosure restricted by GSA ADP Schedule Contract with
# IBM Corp.
# ------------------------------------------------------------------------

from contextlib import contextmanager
from . import _pycplex as CPX
from ..six.moves import range

# int_list_to_C_array    = CPX.int_list_to_C_array
# double_list_to_C_array = CPX.double_list_to_C_array


def int_list_to_array(inputlist):
    length = len(inputlist)
    if length == 0:
        return CPX.cvar.CPX_NULL
    output = CPX.intArray(length)
    for i in range(length):
        output[i] = inputlist[i]
    return output


def long_list_to_array(inputlist):
    length = len(inputlist)
    if length == 0:
        return CPX.cvar.CPX_NULL
    output = CPX.longArray(length)
    for i in range(length):
        output[i] = inputlist[i]
    return output

# FIXME: Is this function really necessary?


def int_list_to_array_trunc_int32(inputlist):
    int32_min = -2147483648
    int32_max = 2147483647
    length = len(inputlist)
    if length == 0:
        return CPX.cvar.CPX_NULL
    output = CPX.intArray(length)
    for i in range(length):
        if inputlist[i] > int32_max:
            output[i] = int32_max
        elif inputlist[i] < int32_min:
            output[i] = int32_min
        else:
            output[i] = inputlist[i]
    return output


def double_list_to_array(inputlist):
    length = len(inputlist)
    if length == 0:
        return CPX.cvar.CPX_NULL
    output = CPX.doubleArray(length)
    for i in range(length):
        output[i] = inputlist[i]
    return output


def array_to_list(inputarray, length):
    """Converts an "array" to a list.

    That is, an array created by `int_list_to_array`,
    `double_list_to_array`, etc.
    """
    return [inputarray[i] for i in range(length)]


@contextmanager
def int_c_array(seq):
    """See matrix_conversion.c:int_list_to_C_array.()"""
    array = CPX.int_list_to_C_array(seq)
    try:
        yield array
    finally:
        CPX.free_int_C_array(array)


@contextmanager
def double_c_array(seq):
    """See matrix_conversion.c:double_list_to_C_array()."""
    array = CPX.double_list_to_C_array(seq)
    try:
        yield array
    finally:
        CPX.free_double_C_array(array)
