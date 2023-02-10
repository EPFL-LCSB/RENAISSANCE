# --------------------------------------------------------------------------
# Version 12.8.0
# --------------------------------------------------------------------------
# Licensed Materials - Property of IBM
# 5725-A06 5725-A29 5724-Y48 5724-Y49 5724-Y54 5724-Y55 5655-Y21
# Copyright IBM Corporation 2000, 2017. All Rights Reserved.
# 
# US Government Users Restricted Rights - Use, duplication or
# disclosure restricted by GSA ADP Schedule Contract with
# IBM Corp.
# --------------------------------------------------------------------------
from . import _constantsenum


class CallbackInfo(object):
    thread_id = _constantsenum.CPXCALLBACKINFO_THREADID
    node_count = _constantsenum.CPXCALLBACKINFO_NODECOUNT
    iteration_count = _constantsenum.CPXCALLBACKINFO_ITCOUNT
    best_solution = _constantsenum.CPXCALLBACKINFO_BEST_SOL
    best_bound = _constantsenum.CPXCALLBACKINFO_BEST_BND
    threads = _constantsenum.CPXCALLBACKINFO_THREADS
    feasible = _constantsenum.CPXCALLBACKINFO_FEASIBLE
    time = _constantsenum.CPXCALLBACKINFO_TIME
    deterministic_time = _constantsenum.CPXCALLBACKINFO_DETTIME

    def __getitem__(self, item):
        """Converts a constant to a string."""
        if item == _constantsenum.CPXCALLBACKINFO_THREADID:
            return 'thread_id'
        if item == _constantsenum.CPXCALLBACKINFO_NODECOUNT:
            return 'node_count'
        if item == _constantsenum.CPXCALLBACKINFO_ITCOUNT:
            return 'iteration_count'
        if item == _constantsenum.CPXCALLBACKINFO_BEST_SOL:
            return 'best_solution'
        if item == _constantsenum.CPXCALLBACKINFO_BEST_BND:
            return 'best_bound'
        if item == _constantsenum.CPXCALLBACKINFO_THREADS:
            return 'threads'
        if item == _constantsenum.CPXCALLBACKINFO_FEASIBLE:
            return 'feasible'
        if item == _constantsenum.CPXCALLBACKINFO_TIME:
            return 'time'
        if item == _constantsenum.CPXCALLBACKINFO_DETTIME:
            return 'deterministic_time'
        raise KeyError(item)
