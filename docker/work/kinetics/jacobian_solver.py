from pytfa.io.json import load_json_model
from skimpy.io.yaml import load_yaml_model
from skimpy.analysis.oracle.load_pytfa_solution import load_fluxes, \
    load_concentrations, load_equilibrium_constants
from skimpy.sampling.simple_parameter_sampler import SimpleParameterSampler
from skimpy.core import *
from skimpy.mechanisms import *
from scipy.linalg import eigvals as eigenvalues
from scipy.sparse.linalg import eigs as eigwhich
from sympy import Symbol
from skimpy.core.parameters import ParameterValues
import pandas as pd
import numpy as np
from skimpy.core.parameters import load_parameter_population
from multiprocessing import Pool
from sys import argv
import time



class check_jacobian():

    def __init__(self):

        self.NCPU = 32
        self.CONCENTRATION_SCALING = 1e9 # 1 mol to 1 mmol
        self.TIME_SCALING = 1 # 1hr
        # Parameters of the E. Coli cell
        self.DENSITY = 1200 # g/L
        self.GDW_GWW_RATIO = 0.25 # Assumes 70% Water
        self.n_samples = 100
        pool = Pool()
        #print(f'FLux scaling factor: {1e-3*(self.GDW_GWW_RATIO*self.DENSITY)*self.CONCENTRATION_SCALING/self.TIME_SCALING}')

    def calc_eigenvalues_recal_vmax(self):

        #print('Calculating eigenvalues.....')
        #self.parameter_set = self.parameter_set.drop('Unnamed: 0', axis=1)
        store_eigen = []
        param_pop=[]

        for j in range(len(self.parameter_set.index)):

            param_val = self.parameter_set.loc[j]*self.CONCENTRATION_SCALING  ####
            param_val = ParameterValues(param_val,self.kmodel)

            self.kmodel.parameters = self.k_eq
            self.kmodel.parameters = param_val   #######
            self.parameter_sample= {v.symbol: v.value for k,v in self.kmodel.parameters.items()}
            #Set all vmax/flux parameters to 1.
            # TODO Generalize into Flux and Saturation parameters
            for this_reaction in self.kmodel.reactions.values():
                vmax_param = this_reaction.parameters.vmax_forward
                self.parameter_sample[vmax_param.symbol] = 1
                # Calculate the Vmax's

            self.kmodel.flux_parameter_function(
                    self.kmodel,
                    self.parameter_sample,
                    self.sym_conc_dict,
                    self.flux_series
                )
            for c in self.conc_series.index:
                if c in self.model_param:
                    c_sym = self.kmodel.parameters[c].symbol
                    self.parameter_sample[c_sym]=self.conc_series[c]

            this_jacobian = self.kmodel.jacobian_fun(self.flux_series[self.kmodel.reactions],
                                    self.conc_series[self.kmodel.reactants],self.parameter_sample)

            this_real_eigenvalues = np.max(np.real(eigenvalues(this_jacobian.todense())))
            store_eigen.append(this_real_eigenvalues)
            this_param_sample = ParameterValues(self.parameter_sample, self.kmodel)
            param_pop.append(this_param_sample)

            del(this_param_sample)
            del(param_val)
            del(this_jacobian)
            del(this_real_eigenvalues)


        return store_eigen

    def calc_eigenvalues(self):

        store_eigen = []
        store_jacobian = []
        stable_percent = 0
        #print('Calculating eigenvalues.....')
        for j in range(len(self.parameter_set.index)):

            #if j%100==0:
            #   #print(f'curr. set processed : {j}')

            param_val = self.parameter_set.loc[j]
            param_val = ParameterValues(param_val,self.kmodel)
            self.kmodel.parameters = param_val
            self.parameter_sample = {v.symbol: v.value for k,v in self.kmodel.parameters.items()}

            this_jacobian = self.kmodel.jacobian_fun(self.flux_series[self.kmodel.reactions],
                                            self.conc_series[self.kmodel.reactants],param_val)
            this_real_eigenvalues = sorted(np.real(eigenvalues(this_jacobian.todense())))

            store_jacobian.append(this_jacobian)
            store_eigen.append(this_real_eigenvalues)
            is_stable = this_real_eigenvalues[-1] <= 0
            if is_stable == True: stable_percent+=1

        store_eigen = np.array(store_eigen)
        maximal_eigen = store_eigen[:,-1]

        return store_eigen, maximal_eigen, store_jacobian

    def _load_models(self,met_model,exp_id, ss_idx):

        path_to_tmodel = f'models/{met_model}/thermo/varma_{exp_id}'
        path_to_kmodel = f'models/{met_model}/kinetic/kin_varma_curated.yaml'
        path_to_samples = f'models/{met_model}/steady_state_samples/samples_{exp_id}.csv'

        self.tmodel = load_json_model(path_to_tmodel)
        self.kmodel = load_yaml_model(path_to_kmodel)
        self.kmodel.prepare()
        self.kmodel.compile_jacobian(sim_type = QSSA, ncpu = self.NCPU)

        self.samples = pd.read_csv(path_to_samples, header=0, index_col=0).iloc[ss_idx,0:]

        flux_series = load_fluxes(self.samples, self.tmodel, self.kmodel,
                                 density=self.DENSITY,
                                 ratio_gdw_gww=self.GDW_GWW_RATIO,
                                 concentration_scaling=self.CONCENTRATION_SCALING,
                                 time_scaling=self.TIME_SCALING)

        conc_series = load_concentrations(self.samples, self.tmodel, self.kmodel,
                                        concentration_scaling=self.CONCENTRATION_SCALING)
        # Fetch equilibrium constants
        k_eq = load_equilibrium_constants(self.samples, self.tmodel, self.kmodel,
                                       concentration_scaling=self.CONCENTRATION_SCALING,
                                       in_place=True)

        sym_conc_dict = {Symbol(k):v for k,v in conc_series.items()}


        sampling_parameters = SimpleParameterSampler.Parameters(n_samples=1)
        sampler = SimpleParameterSampler(sampling_parameters)
        sampler._compile_sampling_functions(self.kmodel, sym_conc_dict,  [])
        model_param = self.kmodel.parameters

        self.flux_series = flux_series
        self.conc_series = conc_series
        self.k_eq = k_eq
        self.sym_conc_dict = sym_conc_dict
        self.model_param = model_param

        print('All models loaded')

    def _load_ktmodels(self, met_model, exp_id):

        path_to_tmodel = f'models/{met_model}/thermo/varma_{exp_id}'
        path_to_kmodel = f'models/{met_model}/kinetic/kin_varma_curated.yaml'

        self.tmodel = load_json_model(path_to_tmodel)
        self.kmodel = load_yaml_model(path_to_kmodel)
        self.kmodel.prepare()
        self.kmodel.compile_jacobian(sim_type = QSSA, ncpu = self.NCPU)

    def _load_ssprofile(self, met_model,exp_id,ss_idx):

        path_to_samples = f'models/{met_model}/steady_state_samples/steady_states.csv'
        self.samples = pd.read_csv(path_to_samples, header=0, index_col=0).iloc[ss_idx, 0:]

        flux_series = load_fluxes(self.samples, self.tmodel, self.kmodel,
                                 density=self.DENSITY,
                                 ratio_gdw_gww=self.GDW_GWW_RATIO,
                                 concentration_scaling=self.CONCENTRATION_SCALING,
                                 time_scaling=self.TIME_SCALING)

        conc_series = load_concentrations(self.samples, self.tmodel, self.kmodel,
                                        concentration_scaling=self.CONCENTRATION_SCALING)

        # Fetch equilibrium constants
        k_eq = load_equilibrium_constants(self.samples, self.tmodel, self.kmodel,
                                       concentration_scaling=self.CONCENTRATION_SCALING,
                                       in_place=True)
        sym_conc_dict = {Symbol(k):v for k,v in conc_series.items()}


        sampling_parameters = SimpleParameterSampler.Parameters(n_samples=1)
        sampler = SimpleParameterSampler(sampling_parameters)
        sampler._compile_sampling_functions(self.kmodel, sym_conc_dict,  [])
        model_param = self.kmodel.parameters

        self.flux_series = flux_series
        self.conc_series = conc_series
        self.k_eq = k_eq
        self.sym_conc_dict = sym_conc_dict
        self.model_param = model_param

    def _prepare_parameters(self, parameters, parameter_names, GAN = True):

        if GAN: parameters = np.exp(parameters)
        self.parameter_set = pd.DataFrame(parameters, columns = parameter_names)

