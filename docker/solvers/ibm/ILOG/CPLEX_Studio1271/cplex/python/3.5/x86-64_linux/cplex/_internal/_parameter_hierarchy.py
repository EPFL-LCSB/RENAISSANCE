# --------------------------------------------------------------------------
# Version 12.7.1
# --------------------------------------------------------------------------
# Licensed Materials - Property of IBM
# 5725-A06 5725-A29 5724-Y48 5724-Y49 5724-Y54 5724-Y55 5655-Y21
# Copyright IBM Corporation 2000, 2017. All Rights Reserved.
# 
# US Government Users Restricted Rights - Use, duplication or
# disclosure restricted by GSA ADP Schedule Contract with
# IBM Corp.
# --------------------------------------------------------------------------
"""


"""

from ._parameters_auto import *
from ._parameter_classes import *

def barrier_limits_members(env, parent):
    return dict(_name = "limits",
                help = lambda : "Limits for barrier optimization.",
                corrections = NumParameter(env, BarrierLimitsCorrections, parent, 'corrections'),
                growth = NumParameter(env, BarrierLimitsGrowth, parent, 'growth'),
                iteration = NumParameter(env, BarrierLimitsIteration, parent, 'iteration'),
                objrange = NumParameter(env, BarrierLimitsObjRange, parent, 'objrange'),
                )

def barrier_members(env, parent):
    return dict(_name = "barrier",
                help = lambda : "Parameters for barrier optimization.",
                algorithm = NumParameter(env, BarrierAlgorithm, parent, 'algorithm', bar_alg_constants),
                colnonzeros = NumParameter(env, BarrierColNonzeros, parent, 'colnonzeros'),
                convergetol = NumParameter(env, BarrierConvergeTol, parent, 'convergetol'),
                crossover = NumParameter(env, BarrierCrossover, parent, 'crossover', crossover_constants),
                display = NumParameter(env, BarrierDisplay, parent, 'display', display_constants),
                limits = ParameterGroup(env, barrier_limits_members, parent),
                ordering = NumParameter(env, BarrierOrdering, parent, 'ordering', bar_order_constants),
                qcpconvergetol = NumParameter(env, BarrierQCPConvergeTol, parent, 'qcpconvergetol'),
                startalg = NumParameter(env, BarrierStartAlg, parent, 'startalg', bar_start_alg_constants),
                )

def benders_tolerances_members(env, parent):
    return dict(_name = "tolerances",
                help = lambda : "Numerical tolerances for Benders cuts.",
                feasibilitycut = NumParameter(env, BendersTolerancesfeasibilitycut, parent, 'feasibilitycut'),
                optimalitycut = NumParameter(env, BendersTolerancesoptimalitycut, parent, 'optimalitycut'),
                )

def benders_members(env, parent):
    return dict(_name = "benders",
                help = lambda : "Parameters for benders optimization.",
                strategy = NumParameter(env, BendersStrategy, parent, 'strategy', benders_strategy_constants),
                tolerances = ParameterGroup(env, benders_tolerances_members, parent),
                workeralgorithm = NumParameter(env, BendersWorkerAlgorithm, parent, 'workeralgorithm', subalg_constants),
                )

def conflict_members(env, parent):
    return dict(_name = "conflict",
                help = lambda : "Parameters for finding conflicts.",
                algorithm = NumParameter(env, ConflictAlgorithm, parent, 'algorithm', conflict_algorithm_constants),
                display = NumParameter(env, ConflictDisplay, parent, 'display', display_constants),
                )

def distmip_rampup_members(env, parent):
    return dict(_name = "rampup",
                help = lambda : "Rampup related parameters_1 in distributed MIP.",
                dettimelimit = NumParameter(env, DistMIPRampupDetTimeLimit, parent, 'dettimelimit'),
                duration = NumParameter(env, DistMIPRampupDuration, parent, 'duration', rampup_duration_constants),
                timelimit = NumParameter(env, DistMIPRampupTimeLimit, parent, 'timelimit'),
                )

def distmip_members(env, parent):
    return dict(_name = "distmip",
                help = lambda : "Distributed parallel mixed integer optimization.",
                rampup = ParameterGroup(env, distmip_rampup_members, parent),
                )

def emphasis_members(env, parent):
    return dict(_name = "emphasis",
                help = lambda : "Optimization emphasis.",
                memory = NumParameter(env, EmphasisMemory, parent, 'memory', off_on_constants),
                mip = NumParameter(env, EmphasisMIP, parent, 'mip', mip_emph_constants),
                numerical = NumParameter(env, EmphasisNumerical, parent, 'numerical', off_on_constants),
                )

def feasopt_members(env, parent):
    return dict(_name = "feasopt",
                help = lambda : "Parameters for feasopt.",
                mode = NumParameter(env, FeasoptMode, parent, 'mode', feasopt_mode_constants),
                tolerance = NumParameter(env, FeasoptTolerance, parent, 'tolerance'),
                )

def mip_cuts_members(env, parent):
    return dict(_name = "cuts",
                help = lambda : "Types of cuts used during mixed integer optimization.",
                bqp = NumParameter(env, MIPCutsBQP, parent, 'bqp', v_agg_constants),
                cliques = NumParameter(env, MIPCutsCliques, parent, 'cliques', v_agg_constants),
                covers = NumParameter(env, MIPCutsCovers, parent, 'covers', v_agg_constants),
                disjunctive = NumParameter(env, MIPCutsDisjunctive, parent, 'disjunctive', v_agg_constants),
                flowcovers = NumParameter(env, MIPCutsFlowCovers, parent, 'flowcovers', agg_constants),
                gomory = NumParameter(env, MIPCutsGomory, parent, 'gomory', agg_constants),
                gubcovers = NumParameter(env, MIPCutsGUBCovers, parent, 'gubcovers', agg_constants),
                implied = NumParameter(env, MIPCutsImplied, parent, 'implied', agg_constants),
                liftproj = NumParameter(env, MIPCutsLiftProj, parent, 'liftproj', v_agg_constants),
                localimplied = NumParameter(env, MIPCutsLocalImplied, parent, 'localimplied', v_agg_constants),
                mcfcut = NumParameter(env, MIPCutsMCFCut, parent, 'mcfcut', agg_constants),
                mircut = NumParameter(env, MIPCutsMIRCut, parent, 'mircut', agg_constants),
                pathcut = NumParameter(env, MIPCutsPathCut, parent, 'pathcut', agg_constants),
                rlt = NumParameter(env, MIPCutsRLT, parent, 'rlt', v_agg_constants),
                zerohalfcut = NumParameter(env, MIPCutsZeroHalfCut, parent, 'zerohalfcut', agg_constants),
                )

def mip_limits_members(env, parent):
    return dict(_name = "limits",
                help = lambda : "Limits for mixed integer optimization.",
                aggforcut = NumParameter(env, MIPLimitsAggForCut, parent, 'aggforcut'),
                auxrootthreads = NumParameter(env, MIPLimitsAuxRootThreads, parent, 'auxrootthreads'),
                cutpasses = NumParameter(env, MIPLimitsCutPasses, parent, 'cutpasses'),
                cutsfactor = NumParameter(env, MIPLimitsCutsFactor, parent, 'cutsfactor'),
                eachcutlimit = NumParameter(env, MIPLimitsEachCutLimit, parent, 'eachcutlimit'),
                gomorycand = NumParameter(env, MIPLimitsGomoryCand, parent, 'gomorycand'),
                gomorypass = NumParameter(env, MIPLimitsGomoryPass, parent, 'gomorypass'),
                nodes = NumParameter(env, MIPLimitsNodes, parent, 'nodes'),
                polishtime = NumParameter(env, MIPLimitsPolishTime, parent, 'polishtime'),
                populate = NumParameter(env, MIPLimitsPopulate, parent, 'populate'),
                probedettime = NumParameter(env, MIPLimitsProbeDetTime, parent, 'probedettime'),
                probetime = NumParameter(env, MIPLimitsProbeTime, parent, 'probetime'),
                repairtries = NumParameter(env, MIPLimitsRepairTries, parent, 'repairtries'),
                solutions = NumParameter(env, MIPLimitsSolutions, parent, 'solutions'),
                strongcand = NumParameter(env, MIPLimitsStrongCand, parent, 'strongcand'),
                strongit = NumParameter(env, MIPLimitsStrongIt, parent, 'strongit'),
                submipnodelim = NumParameter(env, MIPLimitsSubMIPNodeLim, parent, 'submipnodelim'),
                treememory = NumParameter(env, MIPLimitsTreeMemory, parent, 'treememory'),
                )

def mip_polishafter_members(env, parent):
    return dict(_name = "polishafter",
                help = lambda : "Starting conditions for solution polishing.",
                absmipgap = NumParameter(env, MIPPolishAfterAbsMIPGap, parent, 'absmipgap'),
                dettime = NumParameter(env, MIPPolishAfterDetTime, parent, 'dettime'),
                mipgap = NumParameter(env, MIPPolishAfterMIPGap, parent, 'mipgap'),
                nodes = NumParameter(env, MIPPolishAfterNodes, parent, 'nodes'),
                solutions = NumParameter(env, MIPPolishAfterSolutions, parent, 'solutions'),
                time = NumParameter(env, MIPPolishAfterTime, parent, 'time'),
                )

def mip_pool_members(env, parent):
    return dict(_name = "pool",
                help = lambda : "Solution pool characteristics.",
                absgap = NumParameter(env, MIPPoolAbsGap, parent, 'absgap'),
                capacity = NumParameter(env, MIPPoolCapacity, parent, 'capacity'),
                intensity = NumParameter(env, MIPPoolIntensity, parent, 'intensity', v_agg_constants),
                relgap = NumParameter(env, MIPPoolRelGap, parent, 'relgap'),
                replace = NumParameter(env, MIPPoolReplace, parent, 'replace', replace_constants),
                )

def mip_strategy_members(env, parent):
    return dict(_name = "strategy",
                help = lambda : "Strategy for mixed integer optimization.",
                backtrack = NumParameter(env, MIPStrategyBacktrack, parent, 'backtrack'),
                bbinterval = NumParameter(env, MIPStrategyBBInterval, parent, 'bbinterval'),
                branch = NumParameter(env, MIPStrategyBranch, parent, 'branch', brdir_constants),
                dive = NumParameter(env, MIPStrategyDive, parent, 'dive', dive_constants),
                file = NumParameter(env, MIPStrategyFile, parent, 'file', file_constants),
                fpheur = NumParameter(env, MIPStrategyFPHeur, parent, 'fpheur', fpheur_constants),
                heuristicfreq = NumParameter(env, MIPStrategyHeuristicFreq, parent, 'heuristicfreq'),
                kappastats = NumParameter(env, MIPStrategyKappaStats, parent, 'kappastats', kappastats_constants),
                lbheur = NumParameter(env, MIPStrategyLBHeur, parent, 'lbheur', off_on_constants),
                miqcpstrat = NumParameter(env, MIPStrategyMIQCPStrat, parent, 'miqcpstrat', miqcp_constants),
                nodeselect = NumParameter(env, MIPStrategyNodeSelect, parent, 'nodeselect', nodesel_constants),
                order = NumParameter(env, MIPStrategyOrder, parent, 'order', off_on_constants),
                presolvenode = NumParameter(env, MIPStrategyPresolveNode, parent, 'presolvenode', presolve_constants),
                probe = NumParameter(env, MIPStrategyProbe, parent, 'probe', v_agg_constants),
                rinsheur = NumParameter(env, MIPStrategyRINSHeur, parent, 'rinsheur'),
                search = NumParameter(env, MIPStrategySearch, parent, 'search', search_constants),
                startalgorithm = NumParameter(env, MIPStrategyStartAlgorithm, parent, 'startalgorithm', alg_constants),
                subalgorithm = NumParameter(env, MIPStrategySubAlgorithm, parent, 'subalgorithm', subalg_constants),
                variableselect = NumParameter(env, MIPStrategyVariableSelect, parent, 'variableselect', varsel_constants),
                )

def mip_tolerances_members(env, parent):
    return dict(_name = "tolerances",
                help = lambda : "Tolerances for mixed integer optimization.",
                absmipgap = NumParameter(env, MIPTolerancesAbsMIPGap, parent, 'absmipgap'),
                integrality = NumParameter(env, MIPTolerancesIntegrality, parent, 'integrality'),
                lowercutoff = NumParameter(env, MIPTolerancesLowerCutoff, parent, 'lowercutoff'),
                mipgap = NumParameter(env, MIPTolerancesMIPGap, parent, 'mipgap'),
                objdifference = NumParameter(env, MIPTolerancesObjDifference, parent, 'objdifference'),
                relobjdifference = NumParameter(env, MIPTolerancesRelObjDifference, parent, 'relobjdifference'),
                uppercutoff = NumParameter(env, MIPTolerancesUpperCutoff, parent, 'uppercutoff'),
                )

def mip_members(env, parent):
    return dict(_name = "mip",
                help = lambda : "Parameters for mixed integer optimization.",
                cuts = ParameterGroup(env, mip_cuts_members, parent),
                display = NumParameter(env, MIPDisplay, parent, 'display', mip_display_constants),
                interval = NumParameter(env, MIPInterval, parent, 'interval'),
                limits = ParameterGroup(env, mip_limits_members, parent),
                ordertype = NumParameter(env, MIPOrderType, parent, 'ordertype', ordertype_constants),
                polishafter = ParameterGroup(env, mip_polishafter_members, parent),
                pool = ParameterGroup(env, mip_pool_members, parent),
                strategy = ParameterGroup(env, mip_strategy_members, parent),
                tolerances = ParameterGroup(env, mip_tolerances_members, parent),
                )

def output_members(env, parent):
    return dict(_name = "output",
                help = lambda : "Extent and destinations of outputs.",
                clonelog = NumParameter(env, OutputCloneLog, parent, 'clonelog', off_on_constants),
                intsolfileprefix = StrParameter(env, OutputIntSolFilePrefix, parent, 'intsolfileprefix'),
                mpslong = NumParameter(env, OutputMPSLong, parent, 'mpslong', off_on_constants),
                writelevel = NumParameter(env, OutputWriteLevel, parent, 'writelevel', writelevel_constants),
                )

def preprocessing_members(env, parent):
    return dict(_name = "preprocessing",
                help = lambda : "Parameters for preprocessing.",
                aggregator = NumParameter(env, PreprocessingAggregator, parent, 'aggregator'),
                boundstrength = NumParameter(env, PreprocessingBoundStrength, parent, 'boundstrength', auto_off_on_constants),
                coeffreduce = NumParameter(env, PreprocessingCoeffReduce, parent, 'coeffreduce', coeffreduce_constants),
                dependency = NumParameter(env, PreprocessingDependency, parent, 'dependency', dependency_constants),
                dual = NumParameter(env, PreprocessingDual, parent, 'dual', dual_constants),
                fill = NumParameter(env, PreprocessingFill, parent, 'fill'),
                linear = NumParameter(env, PreprocessingLinear, parent, 'linear', linear_constants),
                numpass = NumParameter(env, PreprocessingNumPass, parent, 'numpass'),
                presolve = NumParameter(env, PreprocessingPresolve, parent, 'presolve', off_on_constants),
                qcpduals = NumParameter(env, PreprocessingQCPDuals, parent, 'qcpduals', qcpduals_constants),
                qpmakepsd = NumParameter(env, PreprocessingQPMakePSD, parent, 'qpmakepsd', off_on_constants),
                qtolin = NumParameter(env, PreprocessingQToLin, parent, 'qtolin', auto_off_on_constants),
                reduce = NumParameter(env, PreprocessingReduce, parent, 'reduce', prered_constants),
                relax = NumParameter(env, PreprocessingRelax, parent, 'relax', auto_off_on_constants),
                repeatpresolve = NumParameter(env, PreprocessingRepeatPresolve, parent, 'repeatpresolve', repeatpre_constants),
                symmetry = NumParameter(env, PreprocessingSymmetry, parent, 'symmetry', sym_constants),
                )

def read_members(env, parent):
    return dict(_name = "read",
                help = lambda : "Problem read parameters_1.",
                apiencoding = StrParameter(env, ReadAPIEncoding, parent, 'apiencoding'),
                constraints = NumParameter(env, ReadConstraints, parent, 'constraints'),
                datacheck = NumParameter(env, ReadDataCheck, parent, 'datacheck', datacheck_constants),
                fileencoding = StrParameter(env, ReadFileEncoding, parent, 'fileencoding'),
                nonzeros = NumParameter(env, ReadNonzeros, parent, 'nonzeros'),
                qpnonzeros = NumParameter(env, ReadQPNonzeros, parent, 'qpnonzeros'),
                scale = NumParameter(env, ReadScale, parent, 'scale', scale_constants),
                variables = NumParameter(env, ReadVariables, parent, 'variables'),
                )

def sifting_members(env, parent):
    return dict(_name = "sifting",
                help = lambda : "Parameters for sifting optimization.",
                algorithm = NumParameter(env, SiftingAlgorithm, parent, 'algorithm', sift_alg_constants),
                simplex = NumParameter(env, SiftingSimplex, parent, 'simplex', off_on_constants),
                display = NumParameter(env, SiftingDisplay, parent, 'display', display_constants),
                iterations = NumParameter(env, SiftingIterations, parent, 'iterations'),
                )

def simplex_limits_members(env, parent):
    return dict(_name = "limits",
                help = lambda : "Limits for simplex optimization.",
                iterations = NumParameter(env, SimplexLimitsIterations, parent, 'iterations'),
                lowerobj = NumParameter(env, SimplexLimitsLowerObj, parent, 'lowerobj'),
                perturbation = NumParameter(env, SimplexLimitsPerturbation, parent, 'perturbation'),
                singularity = NumParameter(env, SimplexLimitsSingularity, parent, 'singularity'),
                upperobj = NumParameter(env, SimplexLimitsUpperObj, parent, 'upperobj'),
                )

def simplex_perturbation_members(env, parent):
    return dict(_name = "perturbation",
                help = lambda : "Perturbation controls.",
                constant = NumParameter(env, SimplexPerturbationConstant, parent, 'constant'),
                indicator = NumParameter(env, SimplexPerturbationIndicator, parent, 'indicator', off_on_constants),
                )

def simplex_tolerances_members(env, parent):
    return dict(_name = "tolerances",
                help = lambda : "Numerical tolerances for simplex optimization.",
                feasibility = NumParameter(env, SimplexTolerancesFeasibility, parent, 'feasibility'),
                markowitz = NumParameter(env, SimplexTolerancesMarkowitz, parent, 'markowitz'),
                optimality = NumParameter(env, SimplexTolerancesOptimality, parent, 'optimality'),
                )

def simplex_members(env, parent):
    return dict(_name = "simplex",
                help = lambda : "Parameters for primal and dual simplex optimizations.",
                crash = NumParameter(env, SimplexCrash, parent, 'crash'),
                dgradient = NumParameter(env, SimplexDGradient, parent, 'dgradient', dual_pricing_constants),
                display = NumParameter(env, SimplexDisplay, parent, 'display', display_constants),
                limits = ParameterGroup(env, simplex_limits_members, parent),
                perturbation = ParameterGroup(env, simplex_perturbation_members, parent),
                pgradient = NumParameter(env, SimplexPGradient, parent, 'pgradient', primal_pricing_constants),
                pricing = NumParameter(env, SimplexPricing, parent, 'pricing'),
                refactor = NumParameter(env, SimplexRefactor, parent, 'refactor'),
                tolerances = ParameterGroup(env, simplex_tolerances_members, parent),
                )

def tune_members(env, parent):
    return dict(_name = "tune",
                help = lambda : "Parameters for parameter tuning.",
                dettimelimit = NumParameter(env, TuneDetTimeLimit, parent, 'dettimelimit'),
                display = NumParameter(env, TuneDisplay, parent, 'display', tune_display_constants),
                measure = NumParameter(env, TuneMeasure, parent, 'measure', measure_constants),
                repeat = NumParameter(env, TuneRepeat, parent, 'repeat'),
                timelimit = NumParameter(env, TuneTimeLimit, parent, 'timelimit'),
                )

def root_members(env, parent):
    return dict(_name = "parameters_1",
                help = lambda : "CPLEX parameter hierarchy.",
                advance = NumParameter(env, setAdvance, parent, 'advance', advance_constants),
                barrier = ParameterGroup(env, barrier_members, parent),
                benders = ParameterGroup(env, benders_members, parent),
                clocktype = NumParameter(env, setClockType, parent, 'clocktype', clocktype_constants),
                conflict = ParameterGroup(env, conflict_members, parent),
                cpumask = StrParameter(env, setCPUmask, parent, 'cpumask'),
                dettimelimit = NumParameter(env, setDetTimeLimit, parent, 'dettimelimit'),
                distmip = ParameterGroup(env, distmip_members, parent),
                emphasis = ParameterGroup(env, emphasis_members, parent),
                feasopt = ParameterGroup(env, feasopt_members, parent),
                lpmethod = NumParameter(env, setLPMethod, parent, 'lpmethod', alg_constants),
                mip = ParameterGroup(env, mip_members, parent),
                optimalitytarget = NumParameter(env, setOptimalityTarget, parent, 'optimalitytarget', optimalitytarget_constants),
                output = ParameterGroup(env, output_members, parent),
                parallel = NumParameter(env, setParallel, parent, 'parallel', par_constants),
                preprocessing = ParameterGroup(env, preprocessing_members, parent),
                qpmethod = NumParameter(env, setQPMethod, parent, 'qpmethod', qp_alg_constants),
                randomseed = NumParameter(env, setRandomSeed, parent, 'randomseed'),
                read = ParameterGroup(env, read_members, parent),
                sifting = ParameterGroup(env, sifting_members, parent),
                simplex = ParameterGroup(env, simplex_members, parent),
                solutiontype = NumParameter(env, setSolutionType, parent, 'solutiontype', solutiontype_constants),
                threads = NumParameter(env, setThreads, parent, 'threads'),
                timelimit = NumParameter(env, setTimeLimit, parent, 'timelimit'),
                tune = ParameterGroup(env, tune_members, parent),
                workdir = StrParameter(env, setWorkDir, parent, 'workdir'),
                workmem = NumParameter(env, setWorkMem, parent, 'workmem'),
                )

