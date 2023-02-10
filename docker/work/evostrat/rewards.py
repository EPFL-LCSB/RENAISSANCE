






def get_reward(weights):
    """
    evaluate reward for a set of generated kinetic parameter sets
    :param gen_params: agent generated kinetic parameter sets
    :return: reward
    """

    global calc_eig

    def calc_eig(gen_param):

        checkstability._prepare_parameters(gen_param, NAMES_km)
        max_eig = checkstability.calc_eigenvalues_recal_vmax()
        return max_eig

    n_sample = 100
    lambda_max = -0.9
    pool = mp.Pool()

    cgen.generator.set_weights(weights)
    gen_params = cgen.sample_parameters()
    gen_params = [[params] for params in gen_params]

    max_eig = pool.map(calc_eig, gen_params)
    max_eig = np.array([this_eig for eig in max_eig for this_eig in eig])
    max_neg_eig = np.min(max_eig)
    if max_neg_eig > lambda_max:
        this_reward = 0.01 / (1 + np.exp(max_neg_eig - lambda_max))
    else:
        #upper_lim = -5
        #lower_lim = -6
        #this_reward = len(np.intersect1d(
        #            np.where(max_eig <= upper_lim)[0],
        #            np.where(max_eig >= lower_lim)[0]
        #            )) / n_sample
        this_reward = len(np.where(max_eig <= lambda_max)[0]) / n_sample
    pool.close()
    return this_reward


def get_reward_push(weights):
    """
    evaluate reward for a set of generated kinetic parameter sets
    :param gen_params: agent generated kinetic parameter sets
    :return: reward
    """
    global calc_eig

    checkstability = CheckStability()

    def calc_eig(gen_param):
        checkstability._prepare_parameters(gen_param, NAMES_km)
        max_eig = checkstability.calc_eigenvalues_recal_vmax()
        return max_eig

    global NAMES_km
    n_sample = 100
    pool = mp.Pool()

    cgen.generator.set_weights(weights)
    gen_params = cgen.sample_parameters(n_sample)
    gen_params = [[params] for params in gen_params]

    max_eig = pool.map(calc_eig, gen_params)
    max_eig = np.array([this_eig for eig in max_eig for this_eig in eig])
    neg_eig = max_eig[np.where(max_eig <= 0)[0]]

    mean_neg_eig = np.mean(neg_eig)
    this_reward = 1 / (1 + np.exp(mean_neg_eig + 5))

    return this_reward