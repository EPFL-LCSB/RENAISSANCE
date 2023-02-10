import sys
import numpy as np
import pandas as pd
from configparser import ConfigParser
from keras.layers import Input, Dense, Reshape, Flatten, Dropout, multiply, concatenate
from keras.layers.advanced_activations import LeakyReLU
from keras.models import Sequential, Model
from keras.optimizers import Adam

sys.path.append('../')
import helper as hp

#Parse arguments from configfile
configs = ConfigParser()
configs.read('configfile.ini')

class MLP():
    def __init__(self, cond_class, min_x, max_x, n_samples, NAMES_km, param_fixing):
        self.latent_dim = int(configs['MLP']['latent_dim'])
        print(self.latent_dim)
        self.cond_class = cond_class
        self.min_x = min_x
        self.max_x = max_x
        self.label_shape = 1
        self.param_fixing = param_fixing
        self.names_km = NAMES_km

        self.n_samples = n_samples
        self.n_parameters = int(configs['MLP']['no_kms'])

        # Parameter fixing constraints
        if self.param_fixing==1:
            path_names = configs['PARAMETER_FIXING']['fixed_parameter_names']
            path_values = configs['PARAMETER_FIXING']['fixed_parameter_ranges']
            fixed_param_names = pd.read_csv(path_names).iloc[:, 1].values
            fixed_ranges = np.log(np.load(path_values) * 1e-3)
            self.fixed_param_names = fixed_param_names
            self.fixed_ranges = fixed_ranges
            self.param_shape = self.n_parameters - len(fixed_ranges)
        else:
            self.param_shape = self.n_parameters

        optimizer = Adam(0.0002, 0.5)

        # Build and compile the generator
        self.generator = self.build_generator()
        self.generator.compile(loss=['binary_crossentropy'],
                               optimizer=optimizer)
        self.generator.summary()
        # The generator takes noise and the target label as input
        # and generates the corresponding digit of that label
        noise = Input(shape=(self.latent_dim,))
        label = Input(shape=(self.label_shape,))
        param = self.generator([noise, label])

    def build_generator(self):

        # get architecture from config
        layer_1 = int(configs['MLP']['layer_1'])
        layer_2 = int(configs['MLP']['layer_2'])
        layer_3 = int(configs['MLP']['layer_3'])

        model = Sequential()
        model.add(Dense(layer_1, input_dim=self.latent_dim + self.label_shape))
        model.add(LeakyReLU(alpha=0.2))
        # model.add(BatchNormalization(momentum=0.8))
        model.add(Dropout(0.5))
        model.add(Dense(layer_2))
        model.add(LeakyReLU(alpha=0.2))
        # model.add(BatchNormalization(momentum=0.8))
        model.add(Dropout(0.5))
        model.add(Dense(layer_3))
        model.add(LeakyReLU(alpha=0.2))
        # model.add(BatchNormalization(momentum=0.8))
        model.add(Dropout(0.5))
        model.add(Dense(self.n_parameters))  # , activation = 'tanh'))

        noise = Input(shape=(self.latent_dim,))
        label = Input(shape=(self.label_shape,))

        model_input = concatenate([noise, label])

        param = model(model_input)

        return Model([noise, label], param)

    def sample_parameters(self):

        noise = np.random.normal(0, 1, (self.n_samples, self.latent_dim))

        # we just try to generate stable models
        sampled_labels = np.ones(self.n_samples).reshape(-1, 1) * self.cond_class

        gen_par = self.generator.predict([noise, sampled_labels])
        # Rescale parameters according to previous scaling on X_train
        x_new, new_min, new_max = hp.unscale_range(gen_par, np.min(gen_par), np.max(gen_par), self.min_x, self.max_x)

        if self.param_fixing:
            return self.param_fixer(x_new)
        else:
            return x_new

    def param_fixer(self, gen_params):

        copy_NAMES_km = self.names_km.copy()
        for name in self.names_km:
            if name in self.fixed_param_names: copy_NAMES_km.remove(name)

        reduced_names = copy_NAMES_km
        gen_params = pd.DataFrame(gen_params, columns=reduced_names)

        for this_param, this_range in zip(self.fixed_param_names, self.fixed_ranges):
            sampled_params = np.random.uniform(this_range[0], this_range[1], self.n_samples)
            gen_params[this_param] = sampled_params

        gen_params = gen_params[self.names_km]

        return gen_params.values
