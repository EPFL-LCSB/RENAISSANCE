RENAISSANCE: Generation of kinetic models using Evolutionary Strategies
==========================================
|Build Status| |Codecov| |Codacy branch grade| |license| 

RENAISSANCE is a workflow to generate valid kinetic models of metabolism using evolutionary strategies on Neural Networks.
Here are the instructions for installing and using the Python implementation of RENAISSANCE. This RENAISSANCE implementation uses SKimPy in the backend, however all SKimPy functionalities are installed automatically in the container based install and there is no need to install SKimPy seperately. Using this package you can do the following analyses:


    - Generate experimentally valid kinetic parameter sets around a predetermined steady state of metabolites and reaction fluxes using evolutionary strategies on neural networks.
    - Test parameterized kinetic models for stability using Linear Stability Analysis. 
    - Perform non-linear integration of parameterized ordinary differential equations.
    - Perform Bioareactor simulations of a population of organisms from a parameterized kinetic model.

Requirements
------------

You will need to have `Git-LFS <https://git-lfs.github.com/>`_ in order to properly download some binary files:

.. code:: bash

    git clone https://github.com/EPFL-LCSB/renaissance.git /path/to/renaissance
    cd /path/to/renaissance
    git lfs install
    git lfs pull
 


This module was developed in Python 3.6, and it is recommended to run Python 3.6.
The module also was tested in Python 3.7 and Microsoft Windows 11.

Container-based install
-----------------------
Currently, RENAISSANCE is only available through a container based install.The docker
subfolder has all the necessary information and source files to set it
up.

Setup
=====

*This step is not required if you're using the container, which bundles all this.*

You can install this module with ``pip``:

*For Python 3, you might have to use* ``pip3`` *instead of* ``pip``

.. code:: bash

    pip3 install skimpy

or from source

.. code:: bash

    git clone https://github.com/EPFL-LCSB/skimpy.git /path/to/skimpy
    pip3 install -e /path/to/skimpy


Quick start
===========
To get right into building kinetic models please find below a simple example to get started:

.. code-block:: python

    import numpy as np
    from skimpy.core import *
    from skimpy.mechanisms import *

    name = 'pfk'
    metabolites = ReversibleMichaelisMenten.Reactants(substrate = 'A',
                                                       product = 'B')

    parameters = ReversibleMichaelisMenten.Parameters(
        vmax_forward = 1.0,
        k_equilibrium=2.0,
        km_substrate = 10.0,
        km_product = 10.0,
        total_enzyme_concentration = 1.0,
    )


    pfk = Reaction(name=name,
                   mechanism = ReversibleMichaelisMenten,
                   reactants=metabolites,
                   )

    this_model = KineticModel()
    this_model.add_reaction(pfk)
    this_model.parametrize_by_reaction({pfk.name:parameters})
    this_model.compile_ode(sim_type = QSSA)

    this_model.initial_conditions['A'] = 1.0
    this_model.initial_conditions['B'] = 1.0

    this_sol_qssa = this_model.solve_ode(np.linspace(0.0, 100.0, 1000), solver_type='cvode')

    this_sol_qssa.plot('output/uni_uni_base_out_qssa.html')


More information can be found
`here <http://skimpy.readthedocs.io/en/latest/quickstart.html>`__.


   
License
========

The software in this repository is put under an APACHE-2.0 licensing scheme - please see the `LICENSE <https://github.com/EPFL-LCSB/skimpy/blob/master/LICENSE.txt>`_ file for more details.

.. |license| image:: http://img.shields.io/badge/license-APACHE2-blue.svg
   :target: https://github.com/EPFL-LCSB/skimpy/blob/master/LICENSE.txt
.. |Build Status| image:: https://travis-ci.org/EPFL-LCSB/skimpy.svg?branch=master
   :target: https://travis-ci.org/EPFL-LCSB/skimpy
.. |Codecov| image:: https://img.shields.io/codecov/c/github/EPFL-LCSB/skimpy.svg
   :target: https://codecov.io/gh/EPFL-LCSB/skimpy
.. |Codacy branch grade| image:: https://img.shields.io/codacy/grade/d56d598a8a3b444e8ea5fb1f7eee6e2a
   :target: https://www.codacy.com/app/realLCSB/skimpy
