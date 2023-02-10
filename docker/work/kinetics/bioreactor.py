from pytfa.io.json import load_json_model
from skimpy.io.yaml import load_yaml_model
from skimpy.analysis.oracle.load_pytfa_solution import load_concentrations
from skimpy.core.parameters import load_parameter_population
from skimpy.simulations.reactor import make_batch_reactor
from skimpy.core.solution import ODESolutionPopulation
#from skimpy.io.regulation import load_enzyme_regulation
import matplotlib.pyplot as plt
import numpy as np
from sys import argv
import pandas as pd
import os

def simulator(path_to_parameters,met_model,ss_idx, initiator_path, path_to_output, output_name):

    # Simulation Parameters
    TOTAL_TIME = 60
    N_STEPS = 1000

    exp_id = 'fdp1'
    path_to_kmodel = f'models/{met_model}/kinetic/kin_varma_curated.yaml'
    path_to_tmodel = f'models/{met_model}/thermo/varma_{exp_id}.json'
    path_to_samples = f'models/{met_model}/steady_state_samples/steady_states.csv'

    # Load tfa and kinetic models
    tmodel = load_json_model(path_to_tmodel)
    kmodel = load_yaml_model(path_to_kmodel)
    tfa_sample = pd.read_csv(path_to_samples).iloc[ss_idx]

    # Initialize reactor
    reactor = make_batch_reactor(initiator_path)
    reactor.compile_ode(add_dilution=False)
    reactor_volume = reactor.models.strain_1.parameters.strain_1_volume_e.value

    # Initial biomass : from the paper it seemed to be 0.037 g/L - wt of a cell is 0.28e-12 g - vol of reactor is 50 mL
    reactor.initial_conditions['biomass_strain_1'] = 0.037 * 0.05 / 0.28e-12

    # Load generated kinetic parameters (must be .hdf5 file)
    parameter_population = load_parameter_population(path_to_parameters)
    n_sets = len(list(parameter_population._index.keys()))
    reference_concentrations = load_concentrations(tfa_sample, tmodel, kmodel,
                                                   concentration_scaling=reactor.concentration_scaling)
    all_solutions = []

    # For each parameter set, conduct a reactor simulation
    for params_ix in range(n_sets):

        reactor.parametrize(parameter_population[str(params_ix)], 'strain_1')
        reactor.initialize(reference_concentrations, 'strain_1')

        for met_ in reactor.medium.keys():
            LC_id = 'LC_' + met_
            LC_id = LC_id.replace('_L', '-L')
            LC_id = LC_id.replace('_D', '-D')
            reactor.initial_conditions[met_] = np.exp(tfa_sample.loc[LC_id]) * 1e6

        # Not nice but necessary
        reactor.models.strain_1.parameters.strain_1_volume_e.value = reactor_volume
        reactor.models.strain_1.parameters.strain_1_cell_volume_e.value = 1.0  # 1.0 #(mum**3) look up cell volume bionumbers
        reactor.models.strain_1.parameters.strain_1_cell_volume_c.value = 1.0  # 1.0 #(mum**3)
        reactor.models.strain_1.parameters.strain_1_cell_volume_p.value = 1.0  # 1.0 #(mum**3)
        reactor.models.strain_1.parameters.strain_1_volume_c.value = 0.9 * 1.0  # (mum**3)
        reactor.models.strain_1.parameters.strain_1_volume_p.value = 0.1 * 1.0  # (mum**3)

        import time
        if hasattr(reactor, 'solver'):
            delattr(reactor, 'solver')

        # Function to stop integration
        def rootfn(t, y, g, user_data):
            t_0 = user_data['time_0']
            t_max = user_data['max_time']
            t = time.time()
            if (t - t_0) >= t_max:
                g[0] = 0
                print('Oops - did not converge in time')
            else:
                g[0] = 1

        t0 = time.time()
        user_data = {'time_0': t0,
                     'max_time': 300}  # 4 minutes in seconds

        # Solve the ODEs
        sol = reactor.solve_ode(np.linspace(0, TOTAL_TIME, N_STEPS),
                                solver_type='cvode',
                                rtol=1e-9,
                                atol=1e-9,
                                max_steps=1e9,
                                rootfn=rootfn,
                                nr_rootfns=1,
                                user_data=user_data
                                )

        final_biomass = sol.concentrations.iloc[-1]['biomass_strain_1'] * 0.28e-12 / 0.05
        final_anthranilate = sol.concentrations.iloc[-1]['anth_e'] * 1e-6 * 136.13
        final_glucose = sol.concentrations.iloc[-1]['glc_D_e'] * 1e-6 * 180.156
        print("Final biomass is : {}, final anthranilate is : {}, final glucose is : {}".format(final_biomass,
                                                                                                final_anthranilate,
                                                                                                final_glucose))
        all_solutions.append(sol)

    solpop = ODESolutionPopulation(all_solutions, np.arange(0, len(all_solutions)))

    output_folder = f'{path_to_output}bioreactor_simulations/{output_name}/'
    os.makedirs(output_folder, exist_ok=True)
    solpop.data.to_csv(f'{output_folder}/solutions.csv')
    del solpop