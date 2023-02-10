from configparser import ConfigParser
from kinetics.integrate_ODEs import integrate_ODEs

# parse arguments from configfile
configs = ConfigParser()
configs.read('configfile.ini')

met_model = configs['PATHS']['met_model']
ss_idx = int(configs['EVOSTRAT']['ss_idx'])

path_to_parameters = configs['ODE_INTEGRATION']['path_to_parameter_set']
output_name = configs['ODE_INTEGRATION']['name_output']
output_path = configs['ODE_INTEGRATION']['path_output']
pc_perturb = float(configs['ODE_INTEGRATION']['pc_perturbed'])

integrate_ODEs(path_to_parameters, met_model, ss_idx, pc_perturb, output_path, output_name)
