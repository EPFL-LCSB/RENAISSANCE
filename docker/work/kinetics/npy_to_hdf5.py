# -*- coding: utf-8 -*-
"""
.. module:: skimpy
   :platform: Unix, Windows
   :synopsis: Simple Kinetic Models in Python

.. moduleauthor:: SKiMPy team

[---------]

Copyright 2017 Laboratory of Computational Systems Biotechnology (LCSB),
Ecole Polytechnique Federale de Lausanne (EPFL), Switzerland

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIE CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

"""
from pytfa.io.json import load_json_model
from skimpy.io.yaml import load_yaml_model
from skimpy.analysis.oracle.load_pytfa_solution import load_fluxes, \
    load_concentrations, load_equilibrium_constants
from skimpy.sampling.simple_parameter_sampler import SimpleParameterSampler
from skimpy.core import *
from skimpy.mechanisms import *
from scipy.linalg import eigvals as eigenvalues
from sympy import Symbol
from skimpy.core.parameters import ParameterValues,ParameterValuePopulation
import pandas as pd
import numpy as np
import pickle

import helper as hp
from skimpy.core.parameters import load_parameter_population

#sys.path.append("..")
def store_as_hdf5(gen_params, met_model, names_km, ss_idx, output_path, output_name):

    #Convenience factors
    NCPU = 36
    CONCENTRATION_SCALING = 1e6  # 1 mol to 1 mmol
    TIME_SCALING = 1  # 1hr
    # Parameters of the E. Coli cell
    DENSITY = 1105  # g/L
    GDW_GWW_RATIO = 0.38  # Assumes 70% Water

    exp_id = 'fdp1'
    exp_id = 'fdp1'

    path_to_tmodel = f'models/{met_model}/thermo/varma_{exp_id}'
    path_to_kmodel = f'models/{met_model}/kinetic/kin_varma_curated.yaml'
    path_to_samples = f'models/{met_model}/steady_state_samples/steady_states.csv'

    tmodel = load_json_model(path_to_tmodel)
    kmodel = load_yaml_model(path_to_kmodel)
    kmodel.prepare()
    kmodel.compile_jacobian(sim_type=QSSA)
    samples = pd.read_csv(path_to_samples, header=0, index_col=0).iloc[ss_idx, 0:]

    parameter_set = pd.DataFrame(np.exp(gen_params))
    parameter_set.columns = names_km

    # Load ss fluxes and concentrations
    flux_series = load_fluxes(samples, tmodel, kmodel,
                              density=DENSITY,
                              ratio_gdw_gww=GDW_GWW_RATIO,
                              concentration_scaling=CONCENTRATION_SCALING,
                              time_scaling=TIME_SCALING)

    conc_series = load_concentrations(samples, tmodel, kmodel,
                                      concentration_scaling=CONCENTRATION_SCALING)
    # Fetch equilibrium constants
    k_eq = load_equilibrium_constants(samples, tmodel, kmodel,
                                      concentration_scaling=CONCENTRATION_SCALING,
                                      in_place=True)

    symbolic_concentrations_dict = {Symbol(k): v for k, v in conc_series.items()}

    sampling_parameters = SimpleParameterSampler.Parameters(n_samples=1)
    sampler = SimpleParameterSampler(sampling_parameters)

    sampler._compile_sampling_functions(kmodel, symbolic_concentrations_dict, [])
    model_param = kmodel.parameters

    param_pop = []
    max_eig = []
    min_eig = []

    for j in range(len(parameter_set.index)):
        param_val = parameter_set.loc[j] * CONCENTRATION_SCALING
        param_val = ParameterValues(param_val, kmodel)
        kmodel.parameters = k_eq
        kmodel.parameters = param_val
        parameter_sample = {v.symbol: v.value for k, v in kmodel.parameters.items()}
        # Set all vmax/flux parameters to 1.
        # TODO Generalize into Flux and Saturation parameters
        for this_reaction in kmodel.reactions.values():
            vmax_param = this_reaction.parameters.vmax_forward
            parameter_sample[vmax_param.symbol] = 1
            # Calculate the Vmax's

        kmodel.flux_parameter_function(
            kmodel,
            parameter_sample,
            symbolic_concentrations_dict,
            flux_series
        )
        for c in conc_series.index:
            if c in model_param:
                c_sym = kmodel.parameters[c].symbol
                parameter_sample[c_sym] = conc_series[c]

        this_jacobian = kmodel.jacobian_fun(flux_series[kmodel.reactions],
                                            conc_series[kmodel.reactants], parameter_sample)

        this_real_eigenvalues = sorted(np.real(eigenvalues(this_jacobian.todense())))
        max_eig.append(this_real_eigenvalues[-1])
        min_eig.append(this_real_eigenvalues[0])

        # print(f'min eig {min_eig}; max eig: {max_eig}')
        this_param_sample = ParameterValues(parameter_sample, kmodel)
        param_pop.append(this_param_sample)

    param_pop2 = ParameterValuePopulation(param_pop, kmodel=kmodel)
    param_pop2.save(f'{output_path}/{output_name}.hdf5')
    pd.DataFrame(max_eig).to_csv(f'{output_path}/{output_name}_max_eig.csv')
    pd.DataFrame(min_eig).to_csv(f'{output_path}/{output_name}_min_eig.csv')
