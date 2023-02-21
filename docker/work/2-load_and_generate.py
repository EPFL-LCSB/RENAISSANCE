import helper as hp
import numpy as np
from configparser import ConfigParser
from evostrat.init_mlp import MLP
from kinetics.npy_to_hdf5 import store_as_hdf5

# parse arguments from configfile
configs = ConfigParser()
configs.read('configfile.ini')

lnminkm = float(configs['CONSTRAINTS']['min_km'])
lnmaxkm = float(configs['CONSTRAINTS']['max_km'])

pf_flag = int(configs['PARAMETER_FIXING']['pf_flag'])
met_model = configs['PATHS']['met_model']
names_km = hp.load_pkl(f'models/{met_model}/parameter_names_km_fdp1.pkl')

n_sets = int(configs['LOAD_AND_GENERATE']['n_sets'])
path_to_weights = configs['LOAD_AND_GENERATE']['path_to_weights']
output_name = configs['LOAD_AND_GENERATE']['name_output']
output_path = configs['LOAD_AND_GENERATE']['path_output']
ss_idx = int(configs['EVOSTRAT']['ss_idx'])

# Call neural network agent
cond_class = 1
mlp = MLP(cond_class, lnminkm, lnmaxkm, n_sets, names_km, param_fixing=pf_flag, latent=True)

# Load saved weights and generate
opt_weights = hp.load_pkl(path_to_weights)
mlp.generator.set_weights(opt_weights)
gen_params, noise = mlp.sample_parameters()

# Calculate corresponding Vmaxs and save as .hdf5 for further downstream studies
store_as_hdf5(gen_params, met_model, names_km, ss_idx, output_path, output_name)
np.save(f'{output_path}{output_name}.npy', noise)
