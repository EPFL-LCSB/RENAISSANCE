import math
import pickle
import numpy as np
import pandas as pd
from scipy.special import kl_div

def read_with_pd(path, delimiter='\t', header=None):
    data_pd = pd.read_csv(path, delimiter=delimiter, header=header)
    return data_pd[0].tolist()

def save_pkl(name, obj):
    """save obj with pickle"""
    name = name.replace('.pkl', '')
    with open(name + '.pkl', 'wb') as f:
        pickle.dump(obj, f, pickle.HIGHEST_PROTOCOL)

def load_pkl(name):
    """load a pickle object"""
    name = name.replace('.pkl', '')
    with open(name + '.pkl', 'rb') as f:
        return pickle.load(f)

def write_in_file(path_to_file, data):
    with open(path_to_file, 'w+') as f:
        for item in data:
            f.write("%s\n" % item)

def scale_range(x, a, b):
    """scale an input between a and b, b>a"""
    assert b>a

    min_x = np.min(x)
    max_x = np.max(x)

    x_scaled = (b-a) * np.divide(x-min_x, max_x-min_x) + a

    return x_scaled, min_x, max_x


def unscale_range(x_scaled, a, b, min_x, max_x):
    """unscale a scaled input"""
    assert b>a
    assert max_x > min_x

    x = np.divide(x_scaled-a, b-a) * (max_x-min_x) + min_x

    new_min = np.min(x)
    new_max = np.max(x)

    return x, new_min, new_max

def plot_distribution(params,given_bins):
    params = params[np.where(params<=0)[0]]
    fig,ax = plt.subplots()

    if given_bins == 'Default':
        n,bins = np.histogram(params,50,density=True)
    else:
        n,bins = np.histogram(params,bins = given_bins,density=True)
    bincenters = 0.5*(bins[1:]+bins[:-1])

    return bincenters, n

def get_bounds(ar_list):
    l = len(ar_list)
    upper_bound, lower_bound = np.empty(l),np.empty(l)
    for j in range(l):
        this_ar = ar_list[j]
        upper_bound[j]=np.max(this_ar)
        lower_bound[j]=np.min(this_ar)

    bounds = [np.min(lower_bound), np.max(upper_bound)]
    return bounds

def get_distributions(arr):

    if len(arr)!=2:
        raise ValueError('Please enter only two arrays')

    temp_arr = np.hstack((arr[0],arr[1]))
    l_bound,u_bound = np.min(temp_arr),np.max(temp_arr)

    bins = np.arange(math.floor(l_bound),math.ceil(u_bound));

    p,_ = np.histogram(arr[0], bins = bins, density = True)
    q,_ = np.histogram(arr[1], bins = bins, density = True)

    return p,q

def KL_div(p,q):
    return sum(np.nan_to_num(kl_div(p,q),posinf=0))


def JS_div(p,q):
    M = 0.5*(p+q)
    return 0.5*(KL_div(p,M)+KL_div(q,M))

def mathmode( param_name):

    [_, type_, RXN] = param_name.split('_',2)

    if type_[-1]=='t' or type_[-1]=='e':
        new_name = rf'{RXN}($k^{type_[0]}$)'
    else: new_name = rf'{RXN}($k^{type_[0]}_{type_[-1]}$)'


    return new_name

#Hyperparameters
LATENT_DIM = 128
OUTPUT_DIM = 259
PROJECT = 'kinvarma_small_fdp1'
GENERATION = 9
[MIN_KM, MAX_KM] = [-5,5]
NO_SAMPLES = 100

def mul_dict_by_float(f, some_dict):
    """
    multiplies an ordereddict by a float
    :param f: float
    :param some_dict: dict
    :return: f*dict
    """
    new_dict = {}
    for k, v in some_dict.items():
        new_dict[k] = f * v

    return new_dict


def save_pickle(object, name, dir):
    """
    dump as pickle
    """
    with open(f'{dir}{name}.pkl', 'wb') as f:
        pickle.dump(object, f)


def load_pickle(path):
    """
    load pickle objects
    """
    with open(f'{path}', 'rb') as f:
        loaded_object = pickle.load(f)
    return loaded_object


def rescale_global(gen_params):
    """
    :param gen_params: generated params by agent
    :return: globally rescaled params
    """
    # Rescale parameters
    rescaled_params = gen_params.flatten(order='C')
    rescaled_params = np.interp(rescaled_params, (gen_params.min(), gen_params.max()), (MIN_KM, MAX_KM))
    rescaled_params = np.reshape(rescaled_params, (NO_SAMPLES, OUTPUT_DIM))
    return rescaled_params

def rescale_local(gen_params):
    """

    :param gen_params: generated parameters by agent
    :return: parameters rescaled by Km
    """

    rescaled_params = np.empty((NO_SAMPLES, OUTPUT_DIM))
    for j in range(OUTPUT_DIM):
        this_Km = gen_params[:,j]
        rescaled_params[:,j] = np.interp(this_Km, (this_Km.min(), this_Km.max()) , (MIN_KM, MAX_KM))
    return rescaled_params

def rescale_custom(gen_params, scaling_df):
    """
    :param gen_params: generated parameters by agent
    :return: parameters rescaled by Km
    """

    rescaled_params = np.empty((NO_SAMPLES, OUTPUT_DIM))
    for j in range(OUTPUT_DIM):
        this_Km = gen_params[:,j]
        [min_km, max_km ] = scaling_df.iloc[:,j]
        rescaled_params[:,j] = np.interp(this_Km, (this_Km.min(), this_Km.max()) , (min_km, max_km))
    return rescaled_params

def ravel_agent(agent):
    '''
    :param agent: model
    :return: list of all the model weights and biases
    '''
    all_weights=[]
    for param in agent.parameters():
        for j in param.detach().numpy().ravel():
            all_weights.append(j)
    return all_weights
