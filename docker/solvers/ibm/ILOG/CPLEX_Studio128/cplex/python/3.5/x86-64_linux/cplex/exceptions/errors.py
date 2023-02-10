# ------------------------------------------------------------------------
# File: errors.py
# ------------------------------------------------------------------------
# Licensed Materials - Property of IBM
# 5725-A06 5725-A29 5724-Y48 5724-Y49 5724-Y54 5724-Y55 5655-Y21
# Copyright IBM Corporation 2008, 2017. All Rights Reserved.
#
# US Government Users Restricted Rights - Use, duplication or
# disclosure restricted by GSA ADP Schedule Contract with
# IBM Corp.
# ------------------------------------------------------------------------
"""Exceptions raised by the CPLEX Python API."""


class CplexError(Exception):
    """Class for exceptions raised by the CPLEX Python API."""
    pass


class CplexSolverError(CplexError):
    """Class for errors returned by the Callable Library functions.

    self.args[0] : A string describing the error.

    self.args[1] : The address of the environment that raised the error.

    self.args[2] : The integer status code of the error.
    """

    def __str__(self):
        return self.args[0]


class WrongNumberOfArgumentsError(CplexError, TypeError):
    """Class for errors involving the wrong number of arguments.

    This exception is generally raised by methods that can accept a
    dynamic number of arguments, but also enforce certain rules (e.g., to
    be grouped in pairs, requires at least one argument, etc.).
    """
    pass


class ErrorChannelMessage(CplexError):
    """Class for storing the last message on the error channel.

    For internal use only.
    """
    pass
