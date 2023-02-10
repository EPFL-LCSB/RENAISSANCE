from configparser import ConfigParser
from kinetics.bioreactor import simulator

# parse arguments from configfile
configs = ConfigParser()
configs.read('configfile.ini')

met_model = configs['PATHS']['met_model']
ss_idx = int(configs['EVOSTRAT']['ss_idx'])

path_to_parameters = configs['BIOREACTOR_SIMULATION']['path_to_parameter_set']
output_name = configs['BIOREACTOR_SIMULATION']['name_output']
output_path = configs['BIOREACTOR_SIMULATION']['path_output']
initiator_path = configs['BIOREACTOR_SIMULATION']['path_to_initiator']

simulator(path_to_parameters, met_model, ss_idx, initiator_path,  output_path, output_name)