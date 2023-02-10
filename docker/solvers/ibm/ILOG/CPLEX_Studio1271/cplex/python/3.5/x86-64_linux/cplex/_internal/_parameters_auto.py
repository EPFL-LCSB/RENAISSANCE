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


from ._constants import *


setAdvance  = [ CPX_PARAM_ADVIND  ,  "indicator for advanced starting information  :\n  0 = no advanced start\n  1 = standard advanced start\n  2 = alternate advanced start" ]
BarrierAlgorithm  = [ CPX_PARAM_BARALG  ,  "barrier algorithm choice  :\n  0 = default\n  1 = infeasibility - estimate start\n  2 = infeasibility - constant start\n  3 = standard barrier" ]
BarrierColNonzeros  = [ CPX_PARAM_BARCOLNZ  ,  "minimum number of entries to consider a column dense  :\n  0 = dynamically calculated\n  >0 = specific number of column entries" ]
BarrierConvergeTol  = [ CPX_PARAM_BAREPCOMP  ,  "tolerance on complementarity for convergence " ]
BarrierCrossover  = [ CPX_PARAM_BARCROSSALG  ,  "barrier crossover choice  :\n  -1 = no crossover\n  0 = automatic\n  1 = primal crossover\n  2 = dual crossover" ]
BarrierDisplay  = [ CPX_PARAM_BARDISPLAY  ,  "barrier display level  :\n  0 = no display\n  1 = display normal information\n  2 = display detailed (diagnostic) output" ]
BarrierLimitsCorrections  = [ CPX_PARAM_BARMAXCOR  ,  "maximum correction limit  :\n  -1 = automatically determined\n  0 = none\n  >0 = maximum correction limit" ]
BarrierLimitsGrowth  = [ CPX_PARAM_BARGROWTH  ,  "factor used to determine unbounded optimal face " ]
BarrierLimitsIteration  = [ CPX_PARAM_BARITLIM  ,  "barrier iteration limit " ]
BarrierLimitsObjRange  = [ CPX_PARAM_BAROBJRNG  ,  "barrier objective range (above and below zero) " ]
BarrierOrdering  = [ CPX_PARAM_BARORDER  ,  "barrier ordering algorithm  :\n  0 = automatic\n  1 = approximate minimum degree\n  2 = approximate minimum fill\n  3 = nested dissection" ]
BarrierQCPConvergeTol  = [ CPX_PARAM_BARQCPEPCOMP  ,  "tolerance on complementarity for QCP convergence " ]
BarrierStartAlg  = [ CPX_PARAM_BARSTARTALG  ,  "barrier starting point algorithm  :\n  1 = dual is 0\n  2 = estimate dual\n  3 = primal avg, dual is 0\n  4 = primal avg, dual estimate" ]
BendersStrategy  = [ CPX_PARAM_BENDERSSTRATEGY  ,  "choice of benders decomposition to use  :\n  -1 = do not use benders decomposition\n  0 = automatic\n  1 = use the decomposition specified by annotation\n  2 = auto-decompose workers specified by annotation\n  3 = ignore annotation and auto-decompose cobra_model (for MIP only)" ]
BendersTolerancesfeasibilitycut  = [ CPX_PARAM_BENDERSFEASCUTTOL  ,  "tolerance for considering a feasibility cut violated " ]
BendersTolerancesoptimalitycut  = [ CPX_PARAM_BENDERSOPTCUTTOL  ,  "tolerance for considering an optimality cut violated " ]
BendersWorkerAlgorithm  = [ CPX_PARAM_WORKERALG  ,  "method for optimizing benders subproblems  :\n  0 = automatic\n  1 = primal simplex\n  2 = dual simplex\n  3 = network simplex\n  4 = barrier\n  5 = sifting" ]
setClockType  = [ CPX_PARAM_CLOCKTYPE  ,  "type of clock used to measure time  :\n  0 = automatic\n  1 = CPU time\n  2 = wall-clock time" ]
ConflictAlgorithm  = [ CPX_PARAM_CONFLICTALG  ,  "algorithm used to find minimal conflicts  :\n  0 = automatic\n  1 = fast\n  2 = propagation\n  3 = presolve\n  4 = IIS\n  5 = limited solve\n  6 = solve" ]
ConflictDisplay  = [ CPX_PARAM_CONFLICTDISPLAY  ,  "level of the conflict display  :\n  0 = no display\n  1 = summary display\n  2 = display every cobra_model being solved" ]
setCPUmask  = [ CPX_PARAM_CPUMASK  ,  "cpubinding mask (off, auto, or a hex mask) " ]
setDetTimeLimit  = [ CPX_PARAM_DETTILIM  ,  "deterministic time limit in ticks " ]
DistMIPRampupDetTimeLimit  = [ CPX_PARAM_RAMPUPDETTILIM  ,  "deterministic time limit on rampup " ]
DistMIPRampupDuration  = [ CPX_PARAM_RAMPUPDURATION  ,  "duration of the rampup phase in distributed MIP  :\n  -1 = rampup is disabled\n  0 = automatic\n  1 = rampup is followed by distributed tree search\n  2 = infinite horizon rampup" ]
DistMIPRampupTimeLimit  = [ CPX_PARAM_RAMPUPTILIM  ,  "wall-clock time limit on rampup " ]
EmphasisMemory  = [ CPX_PARAM_MEMORYEMPHASIS  ,  "reduced memory emphasis " ]
EmphasisMIP  = [ CPX_PARAM_MIPEMPHASIS  ,  "emphasis for MIP optimization  :\n  0 = balance optimality and integer feasibility\n  1 = integer feasibility\n  2 = optimality\n  3 = moving best bound\n  4 = finding hidden feasible solutions" ]
EmphasisNumerical  = [ CPX_PARAM_NUMERICALEMPHASIS  ,  "extreme numerical caution emphasis " ]
FeasoptMode  = [ CPX_PARAM_FEASOPTMODE  ,  "relaxation measure  :\n  0 = find minimum-sum relaxation\n  1 = find optimal minimum-sum relaxation\n  2 = find minimum number of relaxations\n  3 = find optimal relaxation with minimum number of relaxations\n  4 = find minimum quadratic-sum relaxation\n  5 = find optimal minimum quadratic-sum relaxation" ]
FeasoptTolerance  = [ CPX_PARAM_EPRELAX  ,  "minimum amount of accepted relaxation " ]
setLPMethod  = [ CPX_PARAM_LPMETHOD  ,  "method for linear optimization  :\n  0 = automatic\n  1 = primal simplex\n  2 = dual simplex\n  3 = network simplex\n  4 = barrier\n  5 = sifting\n  6 = concurrent optimizers" ]
MIPCutsBQP  = [ CPX_PARAM_BQPCUTS  ,  "type of BQP cut generation (only applies to non-convex models solved to global optimality)  :\n  -1 = do not generate\n  0 = automatic\n  1 = moderate\n  2 = aggressive\n  3 = very aggressive" ]
MIPCutsCliques  = [ CPX_PARAM_CLIQUES  ,  "type of clique cut generation  :\n  -1 = do not generate\n  0 = automatic\n  1 = moderate\n  2 = aggressive\n  3 = very aggressive" ]
MIPCutsCovers  = [ CPX_PARAM_COVERS  ,  "type of cover cut generation  :\n  -1 = do not generate\n  0 = automatic\n  1 = moderate\n  2 = aggressive\n  3 = very aggressive" ]
MIPCutsDisjunctive  = [ CPX_PARAM_DISJCUTS  ,  "type of disjunctive cut generation  :\n  -1 = do not generate\n  0 = automatic\n  1 = moderate\n  2 = aggressive\n  3 = very aggressive" ]
MIPCutsFlowCovers  = [ CPX_PARAM_FLOWCOVERS  ,  "type of flow cover cut generation  :\n  -1 = do not generate\n  0 = automatic\n  1 = moderate\n  2 = aggressive" ]
MIPCutsGomory  = [ CPX_PARAM_FRACCUTS  ,  "type of Gomory fractional cut generation  :\n  -1 = do not generate\n  0 = automatic\n  1 = moderate\n  2 = aggressive" ]
MIPCutsGUBCovers  = [ CPX_PARAM_GUBCOVERS  ,  "type of GUB cover cut generation  :\n  -1 = do not generate\n  0 = automatic\n  1 = moderate\n  2 = aggressive" ]
MIPCutsImplied  = [ CPX_PARAM_IMPLBD  ,  "type of implied bound cut generation  :\n  -1 = do not generate\n  0 = automatic\n  1 = moderate\n  2 = aggressive" ]
MIPCutsLiftProj  = [ CPX_PARAM_LANDPCUTS  ,  "type of Lift and Project cut generation  :\n  -1 = do not generate\n  0 = automatic\n  1 = moderate\n  2 = aggressive\n  3 = very aggressive" ]
MIPCutsLocalImplied  = [ CPX_PARAM_LOCALIMPLBD  ,  "type of local implied bound cut generation  :\n  -1 = do not generate\n  0 = automatic\n  1 = moderate\n  2 = aggressive\n  3 = very aggressive" ]
MIPCutsMCFCut  = [ CPX_PARAM_MCFCUTS  ,  "type of MCF cut generation  :\n  -1 = do not generate\n  0 = automatic\n  1 = moderate\n  2 = aggressive" ]
MIPCutsMIRCut  = [ CPX_PARAM_MIRCUTS  ,  "type of mixed integer rounding cut generation  :\n  -1 = do not generate\n  0 = automatic\n  1 = moderate\n  2 = aggressive" ]
MIPCutsPathCut  = [ CPX_PARAM_FLOWPATHS  ,  "type of flow path cut generation  :\n  -1 = do not generate\n  0 = automatic\n  1 = moderate\n  2 = aggressive" ]
MIPCutsRLT  = [ CPX_PARAM_RLTCUTS  ,  "type of RLT cut generation (only applies to non-convex models solved to global optimality)  :\n  -1 = do not generate\n  0 = automatic\n  1 = moderate\n  2 = aggressive\n  3 = very aggressive" ]
MIPCutsZeroHalfCut  = [ CPX_PARAM_ZEROHALFCUTS  ,  "type of zero-half cut generation  :\n  -1 = do not generate\n  0 = automatic\n  1 = moderate\n  2 = aggressive" ]
MIPDisplay  = [ CPX_PARAM_MIPDISPLAY  ,  "level of mixed integer node display  :\n  0 = no display\n  1 = display integer feasible solutions\n  2 = display nodes under 'mip interval' control\n  3 = same as 2, but add information on node cuts and solution times\n  4 = same as 3, but add LP display for root node\n  5 = same as 3, but add LP display for all nodes" ]
MIPInterval  = [ CPX_PARAM_MIPINTERVAL  ,  "interval for printing mixed integer node display  :\n  0 = automatic (equivalent to -1000)\n  n>0 = display every n nodes and new incumbents\n  n<0 = progressively less log output over time (closer to 0: more frequent)" ]
MIPLimitsAggForCut  = [ CPX_PARAM_AGGCUTLIM  ,  "constraint aggregation limit for cut generation  :\n  0 = no constraint aggregation for cut generation\n  positive values at this limit" ]
MIPLimitsAuxRootThreads  = [ CPX_PARAM_AUXROOTTHREADS  ,  "number of threads to use for auxiliary root tasks  :\n  -1 = off\n  0 = automatic\n  n>0 = use n threads for auxiliary root tasks" ]
MIPLimitsCutPasses  = [ CPX_PARAM_CUTPASS  ,  "number of cutting plane passes  :\n  -1 = none\n  0 = automatic\n  positive values give number of passes to perform" ]
MIPLimitsCutsFactor  = [ CPX_PARAM_CUTSFACTOR  ,  "rows multiplier factor to limit cuts  :\n  n<0 = automatic (dynamically calculated)\n  0<=n<=1 = disable cutting plane generation\n  n>1 = number of cuts limited to (n-1) times the original number of rows" ]
MIPLimitsEachCutLimit  = [ CPX_PARAM_EACHCUTLIM  ,  "limit on number of cuts for each type per pass " ]
MIPLimitsGomoryCand  = [ CPX_PARAM_FRACCAND  ,  "candidate limit for generating Gomory fractional cuts " ]
MIPLimitsGomoryPass  = [ CPX_PARAM_FRACPASS  ,  "pass limit for generating Gomory fractional cuts  :\n  0 = automatic\n  positive values at this limit" ]
MIPLimitsNodes  = [ CPX_PARAM_NODELIM  ,  "branch and cut node limit " ]
MIPLimitsPolishTime  = [ CPX_PARAM_POLISHTIME  ,  "time limit for polishing best solution " ]
MIPLimitsPopulate  = [ CPX_PARAM_POPULATELIM  ,  "solutions limit for each populate call " ]
MIPLimitsProbeDetTime  = [ CPX_PARAM_PROBEDETTIME  ,  "deterministic time limit for probing " ]
MIPLimitsProbeTime  = [ CPX_PARAM_PROBETIME  ,  "time limit for probing " ]
MIPLimitsRepairTries  = [ CPX_PARAM_REPAIRTRIES  ,  "number of times to try repair heuristic  :\n  -1 = none\n  0 = automatic\n  positive values give number of repair attempts" ]
MIPLimitsSolutions  = [ CPX_PARAM_INTSOLLIM  ,  "mixed integer solutions limit " ]
MIPLimitsStrongCand  = [ CPX_PARAM_STRONGCANDLIM  ,  "strong branching candidate limit " ]
MIPLimitsStrongIt  = [ CPX_PARAM_STRONGITLIM  ,  "strong branching iteration limit  :\n  0 = automatic\n  positive values at this limit" ]
MIPLimitsSubMIPNodeLim  = [ CPX_PARAM_SUBMIPNODELIM  ,  "sub-MIP node limit " ]
MIPLimitsTreeMemory  = [ CPX_PARAM_TRELIM  ,  "upper limit on size of tree in megabytes " ]
MIPOrderType  = [ CPX_PARAM_MIPORDTYPE  ,  "type of generated priority order  :\n  0 = none\n  1 = decreasing cost\n  2 = increasing bound range\n  3 = increasing cost per coefficient count" ]
MIPPolishAfterAbsMIPGap  = [ CPX_PARAM_POLISHAFTEREPAGAP  ,  "absolute MIP gap after which to start solution polishing " ]
MIPPolishAfterDetTime  = [ CPX_PARAM_POLISHAFTERDETTIME  ,  "deterministic time after which to start solution polishing " ]
MIPPolishAfterMIPGap  = [ CPX_PARAM_POLISHAFTEREPGAP  ,  "relative MIP gap after which to start solution polishing " ]
MIPPolishAfterNodes  = [ CPX_PARAM_POLISHAFTERNODE  ,  "node count after which to start solution polishing " ]
MIPPolishAfterSolutions  = [ CPX_PARAM_POLISHAFTERINTSOL  ,  "solution count after which to start solution polishing " ]
MIPPolishAfterTime  = [ CPX_PARAM_POLISHAFTERTIME  ,  "time after which to start solution polishing " ]
MIPPoolAbsGap  = [ CPX_PARAM_SOLNPOOLAGAP  ,  "absolute objective gap " ]
MIPPoolCapacity  = [ CPX_PARAM_SOLNPOOLCAPACITY  ,  "capacity of solution pool " ]
MIPPoolIntensity  = [ CPX_PARAM_SOLNPOOLINTENSITY  ,  "intensity for populating the MIP solution pool  :\n  0 = automatic\n  1 = mild: generate few solutions quickly\n  2 = moderate: generate a larger number of solutions\n  3 = aggressive: generate many solutions and expect performance penalty\n  4 = very aggressive: enumerate all practical solutions" ]
MIPPoolRelGap  = [ CPX_PARAM_SOLNPOOLGAP  ,  "relative objective gap " ]
MIPPoolReplace  = [ CPX_PARAM_SOLNPOOLREPLACE  ,  "solution pool replacement strategy  :\n  0 = replace oldest solutions\n  1 = replace solutions with worst objective\n  2 = replace least diverse solutions" ]
MIPStrategyBacktrack  = [ CPX_PARAM_BTTOL  ,  "factor for backtracking, lower values give more " ]
MIPStrategyBBInterval  = [ CPX_PARAM_BBINTERVAL  ,  "interval to select best bound node " ]
MIPStrategyBranch  = [ CPX_PARAM_BRDIR  ,  "direction of first branch  :\n  -1 = down branch first\n  0 = automatic\n  1 = up branch first " ]
MIPStrategyDive  = [ CPX_PARAM_DIVETYPE  ,  "dive strategy  :\n  0 = automatic\n  1 = traditional dive\n  2 = probing dive\n  3 = guided dive " ]
MIPStrategyFile  = [ CPX_PARAM_NODEFILEIND  ,  "file for node storage when tree memory limit is reached  :\n  0 = no node file\n  1 = node file in memory and compressed\n  2 = node file on disk\n  3 = node file on disk and compressed" ]
MIPStrategyFPHeur  = [ CPX_PARAM_FPHEUR  ,  "feasibility pump heuristic  :\n  -1 = none\n  0 = automatic\n  1 = feasibility\n  2 = objective and feasibility" ]
MIPStrategyHeuristicFreq  = [ CPX_PARAM_HEURFREQ  ,  "frequency to apply periodic heuristic algorithm  :\n  -1 = none\n  0 = automatic\n  positive values at this frequency" ]
MIPStrategyKappaStats  = [ CPX_PARAM_MIPKAPPASTATS  ,  "strategy to gather statistics on the kappa of subproblems  :\n  -1 = never\n  0 = automatic\n  1 = sample\n  2 = always" ]
MIPStrategyLBHeur  = [ CPX_PARAM_LBHEUR  ,  "indicator for local branching heuristic " ]
MIPStrategyMIQCPStrat  = [ CPX_PARAM_MIQCPSTRAT  ,  "MIQCP strategy  :\n  0 = automatic\n  1 = solve QCP relaxation at each node\n  2 = solve LP relaxation at each node" ]
MIPStrategyNodeSelect  = [ CPX_PARAM_NODESEL  ,  "node selection strategy  :\n  0 = depth-first search\n  1 = best-bound search\n  2 = best-estimate search\n  3 = alternate best-estimate search" ]
MIPStrategyOrder  = [ CPX_PARAM_MIPORDIND  ,  "indicator to use priority orders " ]
MIPStrategyPresolveNode  = [ CPX_PARAM_PRESLVND  ,  "node presolve strategy  :\n  -1 = no node presolve\n  0 = automatic\n  1 = force node presolve\n  2 = node probing\n  3 = aggressive node probing" ]
MIPStrategyProbe  = [ CPX_PARAM_PROBE  ,  "probing strategy  :\n  -1 = no probing\n  0 = automatic\n  1 = moderate\n  2 = aggressive\n  3 = very aggressive" ]
MIPStrategyRINSHeur  = [ CPX_PARAM_RINSHEUR  ,  "frequency to apply RINS heuristic  :\n  -1 = none\n  0 = automatic\n  positive values at this frequency" ]
MIPStrategySearch  = [ CPX_PARAM_MIPSEARCH  ,  "indicator for search method  :\n  0 = automatic\n  1 = traditional branch-and-cut search\n  2 = dynamic search" ]
MIPStrategyStartAlgorithm  = [ CPX_PARAM_STARTALG  ,  "algorithm to solve initial relaxation  :\n  0 = automatic\n  1 = primal simplex\n  2 = dual simplex\n  3 = network simplex\n  4 = barrier\n  5 = sifting\n  6 = concurrent optimizers" ]
MIPStrategySubAlgorithm  = [ CPX_PARAM_SUBALG  ,  "algorithm to solve subproblems  :\n  0 = automatic\n  1 = primal simplex\n  2 = dual simplex\n  3 = network simplex\n  4 = barrier\n  5 = sifting" ]
MIPStrategyVariableSelect  = [ CPX_PARAM_VARSEL  ,  "variable selection strategy  :\n  -1 = minimum integer infeasibility\n  0 = automatic\n  1 = maximum integer infeasibility\n  2 = pseudo costs\n  3 = strong branching\n  4 = pseudo reduced costs" ]
MIPTolerancesAbsMIPGap  = [ CPX_PARAM_EPAGAP  ,  "absolute mixed integer optimality gap tolerance " ]
MIPTolerancesIntegrality  = [ CPX_PARAM_EPINT  ,  "integrality tolerance " ]
MIPTolerancesLowerCutoff  = [ CPX_PARAM_CUTLO  ,  "lower objective cutoff " ]
MIPTolerancesMIPGap  = [ CPX_PARAM_EPGAP  ,  "mixed integer optimality gap tolerance " ]
MIPTolerancesObjDifference  = [ CPX_PARAM_OBJDIF  ,  "absolute amount successive objective values should differ " ]
MIPTolerancesRelObjDifference  = [ CPX_PARAM_RELOBJDIF  ,  "relative amount successive objective values should differ " ]
MIPTolerancesUpperCutoff  = [ CPX_PARAM_CUTUP  ,  "upper objective cutoff " ]
setOptimalityTarget  = [ CPX_PARAM_OPTIMALITYTARGET  ,  "type of solution CPLEX will attempt to compute  :\n  0 = auto\n  1 = optimal solution to convex problem\n  2 = first-order optimal solution\n  3 = global optimal solution" ]
OutputCloneLog  = [ CPX_PARAM_CLONELOG  ,  "control the creation of clone log files  :\n  0 = no clone log\n  1 = create clone log" ]
OutputIntSolFilePrefix  = [ CPX_PARAM_INTSOLFILEPREFIX  ,  "file name prefix for storing incumbents when they arrive " ]
OutputMPSLong  = [ CPX_PARAM_MPSLONGNUM  ,  "indicator for long numbers in MPS output files " ]
OutputWriteLevel  = [ CPX_PARAM_WRITELEVEL  ,  "variables to include in .sol and .mst files  :\n  0 = auto\n  1 = all values\n  2 = discrete values\n  3 = non-zero values\n  4 = non-zero discrete values" ]
setParallel  = [ CPX_PARAM_PARALLELMODE  ,  "parallel optimization mode  :\n  -1 = opportunistic\n  0 = automatic\n  1 = deterministic" ]
PreprocessingAggregator  = [ CPX_PARAM_AGGIND  ,  "limit on applications of the aggregator  :\n  -1 = automatic (1 for LP, infinite for MIP)\n  0 = none\n  >0 = aggregator application limit" ]
PreprocessingBoundStrength  = [ CPX_PARAM_BNDSTRENIND  ,  "type of bound strengthening  :\n  -1 = automatic\n  0 = off\n  1 = on" ]
PreprocessingCoeffReduce  = [ CPX_PARAM_COEREDIND  ,  "level of coefficient reduction  :\n  -1 = automatic\n  0 = none\n  1 = reduce only to integral coefficients\n  2 = reduce any potential coefficient\n  3 = aggressive reduction with tilting" ]
PreprocessingDependency  = [ CPX_PARAM_DEPIND  ,  "indicator for preprocessing dependency checker  :\n  -1 = automatic\n  0 = off\n  1 = at beginning\n  2 = at end\n  3 = at both beginning and end" ]
PreprocessingDual  = [ CPX_PARAM_PREDUAL  ,  "take dual in preprocessing  :\n  -1 = no\n  0 = automatic\n  1 = yes" ]
PreprocessingFill  = [ CPX_PARAM_AGGFILL  ,  "limit on fill in aggregation " ]
PreprocessingLinear  = [ CPX_PARAM_PRELINEAR  ,  "indicator for linear reductions  :\n  0 = only linear reductions\n  1 = full reductions" ]
PreprocessingNumPass  = [ CPX_PARAM_PREPASS  ,  "limit on applications of presolve  :\n  -1 = automatic\n  0 = none\n  >0 = presolve application limit" ]
PreprocessingPresolve  = [ CPX_PARAM_PREIND  ,  "presolve indicator " ]
PreprocessingQCPDuals  = [ CPX_PARAM_CALCQCPDUALS  ,  "dual calculation for QCPs  :\n  0 = do not calculate\n  1 = calculate only if it does not interfere with presolve reductions\n  2 = calculate and disable interfering presolve reductions" ]
PreprocessingQPMakePSD  = [ CPX_PARAM_QPMAKEPSDIND  ,  "indicator to make a binary qp psd or tighter " ]
PreprocessingQToLin  = [ CPX_PARAM_QTOLININD  ,  "indicator to linearize products in the objective involving binary variables (for convex MIQP), or all products of bounded variables (for global QP)  :\n  -1 = automatic\n  0 = off\n  1 = on" ]
PreprocessingReduce  = [ CPX_PARAM_REDUCE  ,  "type of primal and dual reductions  :\n  0 = no primal and dual reductions\n  1 = only primal reductions\n  2 = only dual reductions\n  3 = both primal and dual reductions" ]
PreprocessingRelax  = [ CPX_PARAM_RELAXPREIND  ,  "indicator for additional presolve of lp relaxation of mip  :\n  -1 = automatic\n  0 = off\n  1 = on" ]
PreprocessingRepeatPresolve  = [ CPX_PARAM_REPEATPRESOLVE  ,  "repeat mip presolve  :\n  -1 = automatic\n  0 = off\n  1 = repeat presolve without cuts\n  2 = repeat presolve with cuts\n  3 = repeat presolve with cuts and allow new root cuts" ]
PreprocessingSymmetry  = [ CPX_PARAM_SYMMETRY  ,  "indicator for symmetric reductions  :\n  -1 = automatic\n  0 = off\n  1-5 = increasing aggressive levels" ]
setQPMethod  = [ CPX_PARAM_QPMETHOD  ,  "method for quadratic optimization  :\n  0 = automatic\n  1 = primal simplex\n  2 = dual simplex\n  3 = network simplex\n  4 = barrier\n  5 = sifting\n  6 = concurrent optimizers" ]
setRandomSeed  = [ CPX_PARAM_RANDOMSEED  ,  "seed to initialize the random number generator " ]
ReadAPIEncoding  = [ CPX_PARAM_APIENCODING  ,  "code page for API strings " ]
ReadConstraints  = [ CPX_PARAM_ROWREADLIM  ,  "constraint read size " ]
ReadDataCheck  = [ CPX_PARAM_DATACHECK  ,  "indicator to check data consistency  :\n  0 = data checking off\n  1 = data checking on input\n  2 = provide modeling assistance" ]
ReadFileEncoding  = [ CPX_PARAM_FILEENCODING  ,  "code page for file reading and writing " ]
ReadNonzeros  = [ CPX_PARAM_NZREADLIM  ,  "constraint nonzero read size " ]
ReadQPNonzeros  = [ CPX_PARAM_QPNZREADLIM  ,  "quadratic nonzero read size " ]
ReadScale  = [ CPX_PARAM_SCAIND  ,  "type of scaling used  :\n  -1 = no scaling\n  0 = equilibration scaling\n  1 = aggressive scaling" ]
ReadVariables  = [ CPX_PARAM_COLREADLIM  ,  "variable read size " ]
SiftingAlgorithm  = [ CPX_PARAM_SIFTALG  ,  "algorithm used to solve sifting subproblems  :\n  0 = automatic\n  1 = primal simplex\n  2 = dual simplex\n  3 = network simplex\n  4 = barrier" ]
SiftingSimplex  = [ CPX_PARAM_SIFTSIM  ,  "allow sifting to be called from simplex " ]
SiftingDisplay  = [ CPX_PARAM_SIFTDISPLAY  ,  "level of the sifting iteration display  :\n  0 = no display\n  1 = display major sifting iterations\n  2 = display work LP logs" ]
SiftingIterations  = [ CPX_PARAM_SIFTITLIM  ,  "sifting iteration limit " ]
SimplexCrash  = [ CPX_PARAM_CRAIND  ,  "type of crash used  :\n  LP primal: 0 = ignore objective coefficients during crash\n  LP primal: 1 or -1 = alternate ways of using objective coefficients\n  LP dual: 1 = default starting basis\n  LP dual: 0 or -1 = aggressive starting basis\n  QP primal: -1 = slack basis\n  QP primal: 0 = ignore Q terms and use LP solver for crash\n  QP primal: 1 = ignore objective and use LP solver for crash\n  QP dual: -1 = slack basis\n  QP dual: 0 or 1 = use Q terms for crash" ]
SimplexDGradient  = [ CPX_PARAM_DPRIIND  ,  "type of dual gradient used in pricing  :\n  0 = determined automatically\n  1 = standard dual pricing\n  2 = steepest-edge pricing\n  3 = steepest-edge pricing in slack space\n  4 = steepest-edge pricing, unit initial norms\n  5 = devex pricing" ]
SimplexDisplay  = [ CPX_PARAM_SIMDISPLAY  ,  "level of the iteration display  :\n  0 = no display\n  1 = display after refactorization\n  2 = display every iteration" ]
SimplexLimitsIterations  = [ CPX_PARAM_ITLIM  ,  "upper limit on primal and dual simplex iterations " ]
SimplexLimitsLowerObj  = [ CPX_PARAM_OBJLLIM  ,  "lower limit on value of objective " ]
SimplexLimitsPerturbation  = [ CPX_PARAM_PERLIM  ,  "upper limit on iterations with no progress  :\n  0 = automatic\n  >0 = user specified limit" ]
SimplexLimitsSingularity  = [ CPX_PARAM_SINGLIM  ,  "upper limit on repaired singularities " ]
SimplexLimitsUpperObj  = [ CPX_PARAM_OBJULIM  ,  "upper limit on value of objective " ]
SimplexPerturbationConstant  = [ CPX_PARAM_EPPER  ,  "perturbation constant " ]
SimplexPerturbationIndicator  = [ CPX_PARAM_PERIND  ,  "perturbation indicator " ]
SimplexPGradient  = [ CPX_PARAM_PPRIIND  ,  "type of primal gradient used in pricing  :\n  -1 = reduced-cost pricing\n  0 = hybrid reduced-cost and devex pricing\n  1 = devex pricing\n  2 = steepest-edge pricing\n  3 = steepest-edge pricing, 1 initial norms\n  4 = full pricing" ]
SimplexPricing  = [ CPX_PARAM_PRICELIM  ,  "size of the pricing candidate list " ]
SimplexRefactor  = [ CPX_PARAM_REINV  ,  "refactorization interval " ]
SimplexTolerancesFeasibility  = [ CPX_PARAM_EPRHS  ,  "feasibility tolerance " ]
SimplexTolerancesMarkowitz  = [ CPX_PARAM_EPMRK  ,  "Markowitz threshold tolerance " ]
SimplexTolerancesOptimality  = [ CPX_PARAM_EPOPT  ,  "reduced cost optimality tolerance " ]
setSolutionType  = [ CPX_PARAM_SOLUTIONTYPE  ,  "solution information CPLEX will attempt to compute  :\n  0 = auto\n  1 = basic solution\n  2 = primal dual vector pair" ]
setThreads  = [ CPX_PARAM_THREADS  ,  "default parallel thread count  :\n  0 = automatic\n  1 = sequential\n  >1 = parallel" ]
setTimeLimit  = [ CPX_PARAM_TILIM  ,  "time limit in seconds " ]
TuneDetTimeLimit  = [ CPX_PARAM_TUNINGDETTILIM  ,  "deterministic time limit per cobra_model and per test setting " ]
TuneDisplay  = [ CPX_PARAM_TUNINGDISPLAY  ,  "level of the tuning display  :\n  0 = no display\n  1 = minimal display\n  2 = display settings being tried\n  3 = display settings and logs" ]
TuneMeasure  = [ CPX_PARAM_TUNINGMEASURE  ,  "method used to compare across multiple problems  :\n  1 = average\n  2 = minmax" ]
TuneRepeat  = [ CPX_PARAM_TUNINGREPEAT  ,  "number of times to permute the cobra_model and repeat " ]
TuneTimeLimit  = [ CPX_PARAM_TUNINGTILIM  ,  "time limit per cobra_model and per test setting " ]
setWorkDir  = [ CPX_PARAM_WORKDIR  ,  "directory for CPLEX working files " ]
setWorkMem  = [ CPX_PARAM_WORKMEM  ,  "memory available for working storage (in megabytes) " ]

intParameterSet = [
CPX_PARAM_ADVIND,
CPX_PARAM_BARALG,
CPX_PARAM_BARCOLNZ,
CPX_PARAM_BARCROSSALG,
CPX_PARAM_BARDISPLAY,
CPX_PARAM_BARMAXCOR,
CPX_PARAM_BARITLIM,
CPX_PARAM_BARORDER,
CPX_PARAM_BARSTARTALG,
CPX_PARAM_BENDERSSTRATEGY,
CPX_PARAM_WORKERALG,
CPX_PARAM_CLOCKTYPE,
CPX_PARAM_CONFLICTALG,
CPX_PARAM_CONFLICTDISPLAY,
CPX_PARAM_RAMPUPDURATION,
CPX_PARAM_MEMORYEMPHASIS,
CPX_PARAM_MIPEMPHASIS,
CPX_PARAM_NUMERICALEMPHASIS,
CPX_PARAM_FEASOPTMODE,
CPX_PARAM_LPMETHOD,
CPX_PARAM_BQPCUTS,
CPX_PARAM_CLIQUES,
CPX_PARAM_COVERS,
CPX_PARAM_DISJCUTS,
CPX_PARAM_FLOWCOVERS,
CPX_PARAM_FRACCUTS,
CPX_PARAM_GUBCOVERS,
CPX_PARAM_IMPLBD,
CPX_PARAM_LANDPCUTS,
CPX_PARAM_LOCALIMPLBD,
CPX_PARAM_MCFCUTS,
CPX_PARAM_MIRCUTS,
CPX_PARAM_FLOWPATHS,
CPX_PARAM_RLTCUTS,
CPX_PARAM_ZEROHALFCUTS,
CPX_PARAM_MIPDISPLAY,
CPX_PARAM_MIPINTERVAL,
CPX_PARAM_AGGCUTLIM,
CPX_PARAM_AUXROOTTHREADS,
CPX_PARAM_CUTPASS,
CPX_PARAM_EACHCUTLIM,
CPX_PARAM_FRACCAND,
CPX_PARAM_FRACPASS,
CPX_PARAM_NODELIM,
CPX_PARAM_POPULATELIM,
CPX_PARAM_REPAIRTRIES,
CPX_PARAM_INTSOLLIM,
CPX_PARAM_STRONGCANDLIM,
CPX_PARAM_STRONGITLIM,
CPX_PARAM_SUBMIPNODELIM,
CPX_PARAM_MIPORDTYPE,
CPX_PARAM_POLISHAFTERNODE,
CPX_PARAM_POLISHAFTERINTSOL,
CPX_PARAM_SOLNPOOLCAPACITY,
CPX_PARAM_SOLNPOOLINTENSITY,
CPX_PARAM_SOLNPOOLREPLACE,
CPX_PARAM_BBINTERVAL,
CPX_PARAM_BRDIR,
CPX_PARAM_DIVETYPE,
CPX_PARAM_NODEFILEIND,
CPX_PARAM_FPHEUR,
CPX_PARAM_HEURFREQ,
CPX_PARAM_MIPKAPPASTATS,
CPX_PARAM_LBHEUR,
CPX_PARAM_MIQCPSTRAT,
CPX_PARAM_NODESEL,
CPX_PARAM_MIPORDIND,
CPX_PARAM_PRESLVND,
CPX_PARAM_PROBE,
CPX_PARAM_RINSHEUR,
CPX_PARAM_MIPSEARCH,
CPX_PARAM_STARTALG,
CPX_PARAM_SUBALG,
CPX_PARAM_VARSEL,
CPX_PARAM_OPTIMALITYTARGET,
CPX_PARAM_CLONELOG,
CPX_PARAM_MPSLONGNUM,
CPX_PARAM_WRITELEVEL,
CPX_PARAM_PARALLELMODE,
CPX_PARAM_AGGIND,
CPX_PARAM_BNDSTRENIND,
CPX_PARAM_COEREDIND,
CPX_PARAM_DEPIND,
CPX_PARAM_PREDUAL,
CPX_PARAM_AGGFILL,
CPX_PARAM_PRELINEAR,
CPX_PARAM_PREPASS,
CPX_PARAM_PREIND,
CPX_PARAM_CALCQCPDUALS,
CPX_PARAM_QPMAKEPSDIND,
CPX_PARAM_QTOLININD,
CPX_PARAM_REDUCE,
CPX_PARAM_RELAXPREIND,
CPX_PARAM_REPEATPRESOLVE,
CPX_PARAM_SYMMETRY,
CPX_PARAM_QPMETHOD,
CPX_PARAM_RANDOMSEED,
CPX_PARAM_ROWREADLIM,
CPX_PARAM_DATACHECK,
CPX_PARAM_NZREADLIM,
CPX_PARAM_QPNZREADLIM,
CPX_PARAM_SCAIND,
CPX_PARAM_COLREADLIM,
CPX_PARAM_SIFTALG,
CPX_PARAM_SIFTSIM,
CPX_PARAM_SIFTDISPLAY,
CPX_PARAM_SIFTITLIM,
CPX_PARAM_CRAIND,
CPX_PARAM_DPRIIND,
CPX_PARAM_SIMDISPLAY,
CPX_PARAM_ITLIM,
CPX_PARAM_PERLIM,
CPX_PARAM_SINGLIM,
CPX_PARAM_PERIND,
CPX_PARAM_PPRIIND,
CPX_PARAM_PRICELIM,
CPX_PARAM_REINV,
CPX_PARAM_SOLUTIONTYPE,
CPX_PARAM_THREADS,
CPX_PARAM_TUNINGDISPLAY,
CPX_PARAM_TUNINGMEASURE,
CPX_PARAM_TUNINGREPEAT,
CPX_PARAM_MIPCBREDLP,
]

dblParameterSet = [
CPX_PARAM_BAREPCOMP,
CPX_PARAM_BARGROWTH,
CPX_PARAM_BAROBJRNG,
CPX_PARAM_BARQCPEPCOMP,
CPX_PARAM_BENDERSFEASCUTTOL,
CPX_PARAM_BENDERSOPTCUTTOL,
CPX_PARAM_DETTILIM,
CPX_PARAM_RAMPUPDETTILIM,
CPX_PARAM_RAMPUPTILIM,
CPX_PARAM_EPRELAX,
CPX_PARAM_CUTSFACTOR,
CPX_PARAM_POLISHTIME,
CPX_PARAM_PROBEDETTIME,
CPX_PARAM_PROBETIME,
CPX_PARAM_TRELIM,
CPX_PARAM_POLISHAFTEREPAGAP,
CPX_PARAM_POLISHAFTERDETTIME,
CPX_PARAM_POLISHAFTEREPGAP,
CPX_PARAM_POLISHAFTERTIME,
CPX_PARAM_SOLNPOOLAGAP,
CPX_PARAM_SOLNPOOLGAP,
CPX_PARAM_BTTOL,
CPX_PARAM_EPAGAP,
CPX_PARAM_EPINT,
CPX_PARAM_CUTLO,
CPX_PARAM_EPGAP,
CPX_PARAM_OBJDIF,
CPX_PARAM_RELOBJDIF,
CPX_PARAM_CUTUP,
CPX_PARAM_OBJLLIM,
CPX_PARAM_OBJULIM,
CPX_PARAM_EPPER,
CPX_PARAM_EPRHS,
CPX_PARAM_EPMRK,
CPX_PARAM_EPOPT,
CPX_PARAM_TILIM,
CPX_PARAM_TUNINGDETTILIM,
CPX_PARAM_TUNINGTILIM,
CPX_PARAM_WORKMEM,
]

strParameterSet = [
CPX_PARAM_CPUMASK,
CPX_PARAM_INTSOLFILEPREFIX,
CPX_PARAM_APIENCODING,
CPX_PARAM_FILEENCODING,
CPX_PARAM_WORKDIR,
]

