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


class SolutionStrategy(object):
    check_feasible = _constantsenum.CPXCALLBACKSOLUTION_CHECKFEAS
    propagate = _constantsenum.CPXCALLBACKSOLUTION_PROPAGATE

    def __getitem__(self, item):
        """Converts a constant to a string."""
        if item == _constantsenum.CPXCALLBACKSOLUTION_CHECKFEAS:
            return 'check_feasible'
        if item == _constantsenum.CPXCALLBACKSOLUTION_PROPAGATE:
            return 'propagate'
        raise KeyError(item)
