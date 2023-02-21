RENAISSANCE: Generation of kinetic models using Evolutionary Strategies
==========================================

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

Installation steps
==================
On command line, go to the docker folder of the repository and run the build bash script (build.bat for Windows) as follows,

.. code:: bash

    cd /path/to/renaissance/docker
    ./build
    
This will create a docker container already containing all the dependencies one needs to run RENAISSANCE. This may take several minutes depending on your system and PC specifications. After succesfull a build you will be returned to the command line. Run the docker container using the run bas script (run.bat for Windows)

.. code:: bash

    ./run
    
Configfile
===========
The configuration file (configfile.ini) in the docker/work folder contains all the hyperparameters and file paths that are used in RENAISSANCE. The file contains an explanation of each hyperparameter and how it is used. 

Quick start
===========
To get right into building kinetic models you can follow the following steps:

1. Download the kinetic models and associated steady state samples used in the manuscript from [here](https://doi.org/10.5281/zenodo.7628650) and store them in the RENAISSANCE/docker/work/ folder.

2. Open Ipython inside the docker container,

.. code:: bash

    ipython
    
3. Run the following command to start RENAISSANCE workflow,

.. code:: bash

    run 1-renaissance.py
    
Further Information
===================
Once the generator neural networks are optimised using RENAISSANCE you can load it and generate SKimPy compatible kinetic parameter sets by running using,

.. code:: bash

    run 2-load_and_generate.py
    
The resulting parameter sets can now be used for downstream studies like non-linear ODE simulations and bioreactor fermentations using the rest of the scripts by setting appropriate paths in the configuration file (configfile.ini)
   
License
========

The software in this repository is put under an APACHE-2.0 licensing scheme - please see the `LICENSE <https://github.com/EPFL-LCSB/RENAISSANCE/blob/master/LICENSE.txt>`_ file for more details.
