# --------------------------------------------------------------------------
# File: aborter.py
# ---------------------------------------------------------------------------
# Licensed Materials - Property of IBM
# 5725-A06 5725-A29 5724-Y48 5724-Y49 5724-Y54 5724-Y55 5655-Y21
# Copyright IBM Corporation 2008, 2017. All Rights Reserved.
#
# US Government Users Restricted Rights - Use, duplication or
# disclosure restricted by GSA ADP Schedule Contract with
# IBM Corp.
# --------------------------------------------------------------------------
"""Aborter API"""
from ._internal import _procedural as _proc


class Aborter(object):
    """Gracefully terminates the solve and tuning methods of CPLEX.

    You can pass an instance of this class to one or more Cplex objects.

    Calling the method abort() will then terminate the solve or tuning
    method of the Cplex object.
    """

    def __init__(self):
        """Constructor of the Aborter class.

        The Aborter object is a context manager and can be used, like so:

        with Aborter() as aborter:
            # do stuff

        When the with block is finished, the end() method will be called
        automatically.
        """
        self._disposed = False
        self._p = _proc.new_native_int()
        self._cpxlst = set()

    def _register(self, cpx):
        self._cpxlst.add(cpx)

    def _unregister(self, cpx):
        self._cpxlst.discard(cpx)

    def _throw_if_disposed(self):
        if self._disposed:
            raise ValueError(
                'illegal method invocation after Aborter.end()')

    def abort(self):
        """Aborts the solving and tuning methods.

        Example usage:

        >>> aborter = cplex.Aborter()
        >>> aborter.abort()
        """
        self._throw_if_disposed()
        _proc.set_native_int(self._p, 1)

    def clear(self):
        """Clears the invoking aborter.

        Example usage:

        >>> aborter = cplex.Aborter()
        >>> aborter.clear()
        """
        self._throw_if_disposed()
        _proc.set_native_int(self._p, 0)

    def is_aborted(self):
        """Returns True if the method to abort has been called.

        Example usage:

        >>> aborter = cplex.Aborter()
        >>> aborter.is_aborted()
        False
        """
        self._throw_if_disposed()
        return _proc.get_native_int(self._p) != 0

    def end(self):
        """Ends the invoking aborter.

        Example usage:

        >>> aborter = cplex.Aborter()
        >>> aborter.end()
        """
        if self._disposed:
            return
        self._disposed = True
        while len(self._cpxlst) > 0:
            cpx = self._cpxlst.pop()
            cpx.remove_aborter()
        _proc.delete_native_int(self._p)
        self._p = None

    def __del__(self):
        self.end()

    def __enter__(self):
        """Enter the runtime context related to this object.

        The with statement will bind this method's return value to the
        target specified in the as clause of the statement, if any.

        Aborter objects return themselves.
        """
        return self

    def __exit__(self, exc_type, exc_value, traceback):
        """Exit the runtime context.

        When we exit the with block, the end() method is called.
        """
        self.end()
