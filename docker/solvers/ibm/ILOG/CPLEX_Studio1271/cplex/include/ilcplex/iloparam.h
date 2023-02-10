// -------------------------------------------------------------- -*- C++ -*-
// File: iloparam.h
// Version 12.7.1
// --------------------------------------------------------------------------
// Licensed Materials - Property of IBM
// 5725-A06 5725-A29 5724-Y48 5724-Y49 5724-Y54 5724-Y55 5655-Y21
// Copyright IBM Corporation 2000, 2017. All Rights Reserved.
// 
// US Government Users Restricted Rights - Use, duplication or
// disclosure restricted by GSA ADP Schedule Contract with
// IBM Corp.
// --------------------------------------------------------------------------

struct Param {
  static const IloCplex::IntParam Advance = IntParam(CPX_PARAM_ADVIND);
  struct Barrier {
    static const IloCplex::IntParam Algorithm = IntParam(CPX_PARAM_BARALG);
    static const IloCplex::IntParam ColNonzeros = IntParam(CPX_PARAM_BARCOLNZ);
    static const IloCplex::NumParam ConvergeTol = NumParam(CPX_PARAM_BAREPCOMP);
    static const IloCplex::IntParam Crossover = IntParam(CPX_PARAM_BARCROSSALG);
    static const IloCplex::IntParam Display = IntParam(CPX_PARAM_BARDISPLAY);
    struct Limits {
      static const IloCplex::LongParam Corrections = LongParam(CPX_PARAM_BARMAXCOR);
      static const IloCplex::NumParam Growth = NumParam(CPX_PARAM_BARGROWTH);
      static const IloCplex::LongParam Iteration = LongParam(CPX_PARAM_BARITLIM);
      static const IloCplex::NumParam ObjRange = NumParam(CPX_PARAM_BAROBJRNG);
    };
    static const IloCplex::IntParam Ordering = IntParam(CPX_PARAM_BARORDER);
    static const IloCplex::NumParam QCPConvergeTol = NumParam(CPX_PARAM_BARQCPEPCOMP);
    static const IloCplex::IntParam StartAlg = IntParam(CPX_PARAM_BARSTARTALG);
  };
  struct Benders {
    static const IloCplex::IntParam Strategy = IntParam(CPX_PARAM_BENDERSSTRATEGY);
    struct Tolerances {
      static const IloCplex::NumParam feasibilitycut = NumParam(CPX_PARAM_BENDERSFEASCUTTOL);
      static const IloCplex::NumParam optimalitycut = NumParam(CPX_PARAM_BENDERSOPTCUTTOL);
    };
    static const IloCplex::IntParam WorkerAlgorithm = IntParam(CPX_PARAM_WORKERALG);
  };
  static const IloCplex::IntParam ClockType = IntParam(CPX_PARAM_CLOCKTYPE);
  struct Conflict {
    static const IloCplex::IntParam Algorithm = IntParam(CPX_PARAM_CONFLICTALG);
    static const IloCplex::IntParam Display = IntParam(CPX_PARAM_CONFLICTDISPLAY);
  };
  static const IloCplex::StringParam CPUmask = StringParam(CPX_PARAM_CPUMASK);
  static const IloCplex::NumParam DetTimeLimit = NumParam(CPX_PARAM_DETTILIM);
  struct DistMIP {
    struct Rampup {
      static const IloCplex::NumParam DetTimeLimit = NumParam(CPX_PARAM_RAMPUPDETTILIM);
      static const IloCplex::IntParam Duration = IntParam(CPX_PARAM_RAMPUPDURATION);
      static const IloCplex::NumParam TimeLimit = NumParam(CPX_PARAM_RAMPUPTILIM);
    };
  };
  struct Emphasis {
    static const IloCplex::BoolParam Memory = BoolParam(CPX_PARAM_MEMORYEMPHASIS);
    static const IloCplex::IntParam MIP = IntParam(CPX_PARAM_MIPEMPHASIS);
    static const IloCplex::BoolParam Numerical = BoolParam(CPX_PARAM_NUMERICALEMPHASIS);
  };
  struct Feasopt {
    static const IloCplex::IntParam Mode = IntParam(CPX_PARAM_FEASOPTMODE);
    static const IloCplex::NumParam Tolerance = NumParam(CPX_PARAM_EPRELAX);
  };
  struct MIP {
    struct Cuts {
      static const IloCplex::IntParam BQP = IntParam(CPX_PARAM_BQPCUTS);
      static const IloCplex::IntParam Cliques = IntParam(CPX_PARAM_CLIQUES);
      static const IloCplex::IntParam Covers = IntParam(CPX_PARAM_COVERS);
      static const IloCplex::IntParam Disjunctive = IntParam(CPX_PARAM_DISJCUTS);
      static const IloCplex::IntParam FlowCovers = IntParam(CPX_PARAM_FLOWCOVERS);
      static const IloCplex::IntParam Gomory = IntParam(CPX_PARAM_FRACCUTS);
      static const IloCplex::IntParam GUBCovers = IntParam(CPX_PARAM_GUBCOVERS);
      static const IloCplex::IntParam Implied = IntParam(CPX_PARAM_IMPLBD);
      static const IloCplex::IntParam LiftProj = IntParam(CPX_PARAM_LANDPCUTS);
      static const IloCplex::IntParam LocalImplied = IntParam(CPX_PARAM_LOCALIMPLBD);
      static const IloCplex::IntParam MCFCut = IntParam(CPX_PARAM_MCFCUTS);
      static const IloCplex::IntParam MIRCut = IntParam(CPX_PARAM_MIRCUTS);
      static const IloCplex::IntParam PathCut = IntParam(CPX_PARAM_FLOWPATHS);
      static const IloCplex::IntParam RLT = IntParam(CPX_PARAM_RLTCUTS);
      static const IloCplex::IntParam ZeroHalfCut = IntParam(CPX_PARAM_ZEROHALFCUTS);
    };
    static const IloCplex::IntParam Display = IntParam(CPX_PARAM_MIPDISPLAY);
    static const IloCplex::LongParam Interval = LongParam(CPX_PARAM_MIPINTERVAL);
    struct Limits {
      static const IloCplex::IntParam AggForCut = IntParam(CPX_PARAM_AGGCUTLIM);
      static const IloCplex::IntParam AuxRootThreads = IntParam(CPX_PARAM_AUXROOTTHREADS);
      static const IloCplex::LongParam CutPasses = LongParam(CPX_PARAM_CUTPASS);
      static const IloCplex::NumParam CutsFactor = NumParam(CPX_PARAM_CUTSFACTOR);
      static const IloCplex::IntParam EachCutLimit = IntParam(CPX_PARAM_EACHCUTLIM);
      static const IloCplex::IntParam GomoryCand = IntParam(CPX_PARAM_FRACCAND);
      static const IloCplex::LongParam GomoryPass = LongParam(CPX_PARAM_FRACPASS);
      static const IloCplex::LongParam Nodes = LongParam(CPX_PARAM_NODELIM);
      static const IloCplex::NumParam PolishTime = NumParam(CPX_PARAM_POLISHTIME);
      static const IloCplex::IntParam Populate = IntParam(CPX_PARAM_POPULATELIM);
      static const IloCplex::NumParam ProbeDetTime = NumParam(CPX_PARAM_PROBEDETTIME);
      static const IloCplex::NumParam ProbeTime = NumParam(CPX_PARAM_PROBETIME);
      static const IloCplex::LongParam RepairTries = LongParam(CPX_PARAM_REPAIRTRIES);
      static const IloCplex::LongParam Solutions = LongParam(CPX_PARAM_INTSOLLIM);
      static const IloCplex::IntParam StrongCand = IntParam(CPX_PARAM_STRONGCANDLIM);
      static const IloCplex::LongParam StrongIt = LongParam(CPX_PARAM_STRONGITLIM);
      static const IloCplex::LongParam SubMIPNodeLim = LongParam(CPX_PARAM_SUBMIPNODELIM);
      static const IloCplex::NumParam TreeMemory = NumParam(CPX_PARAM_TRELIM);
    };
    static const IloCplex::IntParam OrderType = IntParam(CPX_PARAM_MIPORDTYPE);
    struct PolishAfter {
      static const IloCplex::NumParam AbsMIPGap = NumParam(CPX_PARAM_POLISHAFTEREPAGAP);
      static const IloCplex::NumParam DetTime = NumParam(CPX_PARAM_POLISHAFTERDETTIME);
      static const IloCplex::NumParam MIPGap = NumParam(CPX_PARAM_POLISHAFTEREPGAP);
      static const IloCplex::LongParam Nodes = LongParam(CPX_PARAM_POLISHAFTERNODE);
      static const IloCplex::LongParam Solutions = LongParam(CPX_PARAM_POLISHAFTERINTSOL);
      static const IloCplex::NumParam Time = NumParam(CPX_PARAM_POLISHAFTERTIME);
    };
    struct Pool {
      static const IloCplex::NumParam AbsGap = NumParam(CPX_PARAM_SOLNPOOLAGAP);
      static const IloCplex::IntParam Capacity = IntParam(CPX_PARAM_SOLNPOOLCAPACITY);
      static const IloCplex::IntParam Intensity = IntParam(CPX_PARAM_SOLNPOOLINTENSITY);
      static const IloCplex::NumParam RelGap = NumParam(CPX_PARAM_SOLNPOOLGAP);
      static const IloCplex::IntParam Replace = IntParam(CPX_PARAM_SOLNPOOLREPLACE);
    };
    struct Strategy {
      static const IloCplex::NumParam Backtrack = NumParam(CPX_PARAM_BTTOL);
      static const IloCplex::LongParam BBInterval = LongParam(CPX_PARAM_BBINTERVAL);
      static const IloCplex::IntParam Branch = IntParam(CPX_PARAM_BRDIR);
      static const IloCplex::IntParam Dive = IntParam(CPX_PARAM_DIVETYPE);
      static const IloCplex::IntParam File = IntParam(CPX_PARAM_NODEFILEIND);
      static const IloCplex::IntParam FPHeur = IntParam(CPX_PARAM_FPHEUR);
      static const IloCplex::LongParam HeuristicFreq = LongParam(CPX_PARAM_HEURFREQ);
      static const IloCplex::IntParam KappaStats = IntParam(CPX_PARAM_MIPKAPPASTATS);
      static const IloCplex::BoolParam LBHeur = BoolParam(CPX_PARAM_LBHEUR);
      static const IloCplex::IntParam MIQCPStrat = IntParam(CPX_PARAM_MIQCPSTRAT);
      static const IloCplex::IntParam NodeSelect = IntParam(CPX_PARAM_NODESEL);
      static const IloCplex::BoolParam Order = BoolParam(CPX_PARAM_MIPORDIND);
      static const IloCplex::IntParam PresolveNode = IntParam(CPX_PARAM_PRESLVND);
      static const IloCplex::IntParam Probe = IntParam(CPX_PARAM_PROBE);
      static const IloCplex::LongParam RINSHeur = LongParam(CPX_PARAM_RINSHEUR);
      static const IloCplex::IntParam Search = IntParam(CPX_PARAM_MIPSEARCH);
      static const IloCplex::IntParam VariableSelect = IntParam(CPX_PARAM_VARSEL);
    };
    struct Tolerances {
      static const IloCplex::NumParam AbsMIPGap = NumParam(CPX_PARAM_EPAGAP);
      static const IloCplex::NumParam Linearization = NumParam(CPX_PARAM_EPLIN);
      static const IloCplex::NumParam Integrality = NumParam(CPX_PARAM_EPINT);
      static const IloCplex::NumParam LowerCutoff = NumParam(CPX_PARAM_CUTLO);
      static const IloCplex::NumParam MIPGap = NumParam(CPX_PARAM_EPGAP);
      static const IloCplex::NumParam ObjDifference = NumParam(CPX_PARAM_OBJDIF);
      static const IloCplex::NumParam RelObjDifference = NumParam(CPX_PARAM_RELOBJDIF);
      static const IloCplex::NumParam UpperCutoff = NumParam(CPX_PARAM_CUTUP);
    };
  };
  struct Network {
    static const IloCplex::IntParam Display = IntParam(CPX_PARAM_NETDISPLAY);
    static const IloCplex::LongParam Iterations = LongParam(CPX_PARAM_NETITLIM);
    static const IloCplex::IntParam NetFind = IntParam(CPX_PARAM_NETFIND);
    static const IloCplex::IntParam Pricing = IntParam(CPX_PARAM_NETPPRIIND);
    struct Tolerances {
      static const IloCplex::NumParam Feasibility = NumParam(CPX_PARAM_NETEPRHS);
      static const IloCplex::NumParam Optimality = NumParam(CPX_PARAM_NETEPOPT);
    };
  };
  static const IloCplex::IntParam NodeAlgorithm = IntParam(CPX_PARAM_SUBALG);
  static const IloCplex::IntParam OptimalityTarget = IntParam(CPX_PARAM_OPTIMALITYTARGET);
  struct Output {
    static const IloCplex::BoolParam CloneLog = BoolParam(CPX_PARAM_CLONELOG);
    static const IloCplex::StringParam IntSolFilePrefix = StringParam(CPX_PARAM_INTSOLFILEPREFIX);
    static const IloCplex::BoolParam MPSLong = BoolParam(CPX_PARAM_MPSLONGNUM);
    static const IloCplex::IntParam WriteLevel = IntParam(CPX_PARAM_WRITELEVEL);
  };
  static const IloCplex::IntParam Parallel = IntParam(CPX_PARAM_PARALLELMODE);
  struct Preprocessing {
    static const IloCplex::IntParam Aggregator = IntParam(CPX_PARAM_AGGIND);
    static const IloCplex::IntParam BoundStrength = IntParam(CPX_PARAM_BNDSTRENIND);
    static const IloCplex::IntParam CoeffReduce = IntParam(CPX_PARAM_COEREDIND);
    static const IloCplex::IntParam Dependency = IntParam(CPX_PARAM_DEPIND);
    static const IloCplex::IntParam Dual = IntParam(CPX_PARAM_PREDUAL);
    static const IloCplex::LongParam Fill = LongParam(CPX_PARAM_AGGFILL);
    static const IloCplex::IntParam Linear = IntParam(CPX_PARAM_PRELINEAR);
    static const IloCplex::IntParam NumPass = IntParam(CPX_PARAM_PREPASS);
    static const IloCplex::BoolParam Presolve = BoolParam(CPX_PARAM_PREIND);
    static const IloCplex::IntParam QCPDuals = IntParam(CPX_PARAM_CALCQCPDUALS);
    static const IloCplex::BoolParam QPMakePSD = BoolParam(CPX_PARAM_QPMAKEPSDIND);
    static const IloCplex::IntParam QToLin = IntParam(CPX_PARAM_QTOLININD);
    static const IloCplex::IntParam Reduce = IntParam(CPX_PARAM_REDUCE);
    static const IloCplex::IntParam Relax = IntParam(CPX_PARAM_RELAXPREIND);
    static const IloCplex::IntParam RepeatPresolve = IntParam(CPX_PARAM_REPEATPRESOLVE);
    static const IloCplex::IntParam Symmetry = IntParam(CPX_PARAM_SYMMETRY);
  };
  static const IloCplex::IntParam RandomSeed = IntParam(CPX_PARAM_RANDOMSEED);
  struct Read {
    static const IloCplex::StringParam APIEncoding = StringParam(CPX_PARAM_APIENCODING);
    static const IloCplex::IntParam Constraints = IntParam(CPX_PARAM_ROWREADLIM);
    static const IloCplex::IntParam DataCheck = IntParam(CPX_PARAM_DATACHECK);
    static const IloCplex::StringParam FileEncoding = StringParam(CPX_PARAM_FILEENCODING);
    static const IloCplex::LongParam Nonzeros = LongParam(CPX_PARAM_NZREADLIM);
    static const IloCplex::LongParam QPNonzeros = LongParam(CPX_PARAM_QPNZREADLIM);
    static const IloCplex::IntParam Scale = IntParam(CPX_PARAM_SCAIND);
    static const IloCplex::IntParam Variables = IntParam(CPX_PARAM_COLREADLIM);
  };
  static const IloCplex::IntParam RootAlgorithm = IntParam(CPX_PARAM_LPMETHOD);
  struct Sifting {
    static const IloCplex::IntParam Algorithm = IntParam(CPX_PARAM_SIFTALG);
    static const IloCplex::BoolParam Simplex = BoolParam(CPX_PARAM_SIFTSIM);
    static const IloCplex::IntParam Display = IntParam(CPX_PARAM_SIFTDISPLAY);
    static const IloCplex::LongParam Iterations = LongParam(CPX_PARAM_SIFTITLIM);
  };
  struct Simplex {
    static const IloCplex::IntParam Crash = IntParam(CPX_PARAM_CRAIND);
    static const IloCplex::IntParam DGradient = IntParam(CPX_PARAM_DPRIIND);
    static const IloCplex::IntParam Display = IntParam(CPX_PARAM_SIMDISPLAY);
    struct Limits {
      static const IloCplex::LongParam Iterations = LongParam(CPX_PARAM_ITLIM);
      static const IloCplex::NumParam LowerObj = NumParam(CPX_PARAM_OBJLLIM);
      static const IloCplex::IntParam Perturbation = IntParam(CPX_PARAM_PERLIM);
      static const IloCplex::IntParam Singularity = IntParam(CPX_PARAM_SINGLIM);
      static const IloCplex::NumParam UpperObj = NumParam(CPX_PARAM_OBJULIM);
    };
    struct Perturbation {
      static const IloCplex::NumParam Constant = NumParam(CPX_PARAM_EPPER);
      static const IloCplex::BoolParam Indicator = BoolParam(CPX_PARAM_PERIND);
    };
    static const IloCplex::IntParam PGradient = IntParam(CPX_PARAM_PPRIIND);
    static const IloCplex::IntParam Pricing = IntParam(CPX_PARAM_PRICELIM);
    static const IloCplex::IntParam Refactor = IntParam(CPX_PARAM_REINV);
    struct Tolerances {
      static const IloCplex::NumParam Feasibility = NumParam(CPX_PARAM_EPRHS);
      static const IloCplex::NumParam Markowitz = NumParam(CPX_PARAM_EPMRK);
      static const IloCplex::NumParam Optimality = NumParam(CPX_PARAM_EPOPT);
    };
  };
  static const IloCplex::IntParam SolutionType = IntParam(CPX_PARAM_SOLUTIONTYPE);
  static const IloCplex::IntParam Threads = IntParam(CPX_PARAM_THREADS);
  static const IloCplex::NumParam TimeLimit = NumParam(CPX_PARAM_TILIM);
  struct Tune {
    static const IloCplex::NumParam DetTimeLimit = NumParam(CPX_PARAM_TUNINGDETTILIM);
    static const IloCplex::IntParam Display = IntParam(CPX_PARAM_TUNINGDISPLAY);
    static const IloCplex::IntParam Measure = IntParam(CPX_PARAM_TUNINGMEASURE);
    static const IloCplex::IntParam Repeat = IntParam(CPX_PARAM_TUNINGREPEAT);
    static const IloCplex::NumParam TimeLimit = NumParam(CPX_PARAM_TUNINGTILIM);
  };
  static const IloCplex::StringParam WorkDir = StringParam(CPX_PARAM_WORKDIR);
  static const IloCplex::NumParam WorkMem = NumParam(CPX_PARAM_WORKMEM);
};
