import numpy as np


def receive_noise_input(n_samples, latent_dim):
    noise = np.random.normal(0, 1, (n_samples, latent_dim))
    return noise
