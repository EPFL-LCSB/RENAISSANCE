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
"""setup.py file for the CPLEX Python API"""

import platform

from distutils.core import setup
from sys import version_info

PLATFORM_ERROR = 'The CPLEX Python API is not supported on this platform.'
VERSION_ERROR = 'CPLEX 12.8.0.0 is not compatible with this version of Python.'


def is_supported_platform():
    return platform.system() in ('Darwin', 'Linux', 'AIX') or is_windows()


def is_windows():
    return platform.system() in ('Windows', 'Microsoft')


def is_supported_version():
    major, minor, _, _, _ = version_info
    return (major == 2 and minor == 7) or (major == 3 and minor in (5, 6))


def get_data():
    major, minor, _, _, _ = version_info
    if is_windows():
        ext = '.pyd'
        extra = ['cplex1280.dll']
    else:
        ext = '.so'
        extra = []
    data = ['py%d%d_cplex1280%s' % (major, minor, ext)]
    data.extend(extra)
    return data


def main():
    if not is_supported_platform():
        raise Exception(PLATFORM_ERROR)

    if not is_supported_version():
        raise Exception(VERSION_ERROR)

    setup(name='cplex',
          version='12.8.0.0',
          author='IBM',
          description='A Python interface to the CPLEX Callable Library.',
          packages=['cplex',
                    'cplex._internal',
                    'cplex.exceptions'],
          package_dir={'cplex': 'cplex',
                       'cplex._internal': 'cplex/_internal',
                       'cplex.exceptions': 'cplex/exceptions'},
          package_data={'cplex._internal': get_data()},
          url='http://www-01.ibm.com/software/websphere/products/optimization/')


if __name__ == '__main__':
    main()
