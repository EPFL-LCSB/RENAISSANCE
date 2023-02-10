#!/usr/bin/env python
# ------------------------------------------------------------------------------
# Licensed Materials - Property of IBM
# 5725-A06 5725-A29 5724-Y48 5724-Y49 5724-Y54 5724-Y55 5655-Y21
# Copyright IBM Corporation 2008, 2017. All Rights Reserved.
#
# US Government Users Restricted Rights - Use, duplication or
# disclosure restricted by GSA ADP Schedule Contract with
# IBM Corp.
# ------------------------------------------------------------------------------
"""
setup.py file for the CPLEX Python API
"""

import platform

from distutils.core import setup
from sys import version_info

ERROR_STRING = "CPLEX 12.7.1.0 is not compatible with this version of Python."

platform_system = platform.system()
if platform_system in ('Darwin', 'Linux', 'AIX', 'Windows', 'Microsoft'):
    if version_info < (3, 5, 0):
        raise Exception(ERROR_STRING)
    elif version_info < (3, 7, 0):
        if platform_system in ('Windows', 'Microsoft'):
            DATA = ['py35_cplex1271.pyd', 'cplex1271.dll']
        else:
            DATA = ['py35_cplex1271.so']
    else:
        raise Exception(ERROR_STRING)
else:
    raise Exception("The CPLEX Python API is not supported on this platform.")

setup(name = 'cplex',
      version = '12.7.1.0',
      author = "IBM",
      description = """A Python interface to the CPLEX Callable Library.""",
      packages = ['cplex',
                  'cplex._internal',
                  'cplex.exceptions'],
      package_dir = {'cplex': 'cplex',
                     'cplex._internal': 'cplex/_internal',
                     'cplex.exceptions': 'cplex/exceptions'},
      package_data = {'cplex._internal': DATA},
      url = 'http://www-01.ibm.com/software/websphere/products/optimization/',
      )
