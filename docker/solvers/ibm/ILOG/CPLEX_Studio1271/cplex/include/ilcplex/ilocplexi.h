// -------------------------------------------------------------- -*- C++ -*-
// File: ilocplexi.h
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

#ifndef _ILOCPLEXI_H
#define _ILOCPLEXI_H

#ifdef _WIN32
#pragma pack(push, 8)
#endif

#include <ilconcert/ilomodel.h>
#include <ilconcert/iloalgi.h>
#include <ilcplex/ilocarray.h>

#define CPXNEW(x,t)     try {x=t;} catch(...) {x=0;}

extern "C" {
#include <ilcplex/cplex.h>
#if CPX_FEATURE_REMOTE_OBJECT < 1
#   define ILOG_CPLEX_NO_REMOTE_API
#endif
#if CPX_FEATURE_DISTRIBUTED_MIP < 1
#   define ILOG_CPLEX_NO_DISTRIBUTED_MIP_API
#endif
#ifndef ILOG_CPLEX_NO_REMOTE_API
#   include <ilcplex/cplexremotemaster.h>
#endif
#ifndef ILOG_CPLEX_NO_DISTRIBUTED_MIP_API
#   include <ilcplex/cplexdistmip.h>
    typedef int CPXPUBLIC IloCplexCopyVMConfig (CPXENVptr, char const *);
    typedef int CPXPUBLIC IloCplexReadVMConfig (CPXENVptr, char const *);
    typedef int CPXPUBLIC IloCplexDelVMConfig (CPXENVptr);
    typedef int CPXPUBLIC IloCplexDistmipopt (CPXCENVptr, CPXLPptr);
#endif
#include <ilcplex/cplexx.h>
struct cpxenv;
struct cpxlp;
class IloCplexCache;
typedef CPXENVptr CPXPUBLIC IloCplexInitFunction (char const *,
                                                  int, char const *const *,
                                                  int *);
}

class IloCplexI;
class IloLPExtractor;
class IloExprExtractor;
class IloDefaultLPExtractor;
class IloLogicalExtractor;
class IloColumnExtractor;
class IloExprLinearizer;
class IloExprParser;
class IloLPExtractorManager;
class IloLinearizerI;
class IloCallbackManager;
class IloCplexCallbackManager;
class IloCplexRow;
class IloCplexColumn;
class IloCplexSOS;
class IloCplexSolutionOpsNumVarAux;
class IloCplexSolutionOpsObjectiveAux;
class IloCplexAborterI;

#ifdef USE_SET_VARS
class IloSetConstraintExtractor;
class IloIntSetVarI;
#endif

// For the Goal API
class CpxNodeI;
class CpxBranchAsCplexI;
// END:: For the Goal API

class IloBoundI;

typedef CPXLONG IloInt64;

class ILO_EXPORTED IloBound : public IloConstraint {
  ILOEXTRHANDLE(IloBound,IloConstraint)
public:
  enum Type { Lower, Upper };

  IloBound (IloNumVar var, Type type);

  IloNumVar getVar();

  Type getType();
};


/* Helpers for 64 to 32 bit conversion, since we cannot rely on
 * std::numeric_limits<> working across all compilers and platforms.
 */
#define CPXINT_MAX  2147483647              /* This is 2^31 - 1 */
#define CPXINT_MIN  (-CPXINT_MAX-1)
#define CPXLONG_MAX 9223372036854775807LL   /* This is 2^63 - 1 */
#define CPXLONG_MIN (-CPXLONG_MAX-1)

template<unsigned int> struct CPXLIM {};
template<> struct CPXLIM<4> {
   static CPXINT maxVal() { return CPXINT_MAX; }
   static CPXINT minVal() { return CPXINT_MIN; }
};

template<> struct CPXLIM<8> {
   static CPXLONG maxVal() { return CPXLONG_MAX; }
   static CPXLONG minVal() { return CPXLONG_MIN; }
};

class IloCplex : public IloAlgorithm {
public:
  class UserCutCallbackI;
  class LazyConstraintCallbackI;
  class NodeEvaluatorI;
  class SearchLimitI;
  IloCplexI* getImpl() const {
    return (IloCplexI*)(void*)IloAlgorithm::getImpl();
  }

#ifndef ILOG_CPLEX_NO_REMOTE_API
  class AsyncHandleI {
  public:
    virtual IloBool test() const = 0;
    virtual void kill() = 0;
    virtual void join() = 0;
    virtual ~AsyncHandleI() {}
  };
  class AsyncHandle {
  protected:
    AsyncHandleI *impl;
  public:
    AsyncHandle(AsyncHandleI *i = 0) : impl(i) {}
    virtual ~AsyncHandle() throw() {}
    AsyncHandleI *getImpl() { return impl; }
    operator bool() const { return impl != 0; }
    virtual IloBool test() const { return impl->test(); }
    virtual void kill() const { impl->kill(); }
    void join() { impl->join(); delete impl; impl = 0; }
  };

  class RemoteInfoHandler {
  public:
    virtual ~RemoteInfoHandler() {}
  protected:
    RemoteInfoHandler() {}
    virtual void main(CPXINFOTYPE type, int tag, CPXLONG length,
                      void const *data) = 0;
  private:
    // No copying or assignment.
    RemoteInfoHandler(RemoteInfoHandler const&);
    RemoteInfoHandler &operator=(RemoteInfoHandler const&);
    friend class IloCplexIRemoteInfoHandlerInvoke;
  };
  RemoteInfoHandler *setRemoteInfoHandler(RemoteInfoHandler *handler);
  RemoteInfoHandler *getRemoteInfoHandler() const;
  RemoteInfoHandler *removeRemoteInfoHandler();

  class Serializer {
  public:
    Serializer();
    ~Serializer();
    void add(CPXBYTE b);
    void add(CPXBYTE const *b, CPXLONG cnt);
    void add(CPXSHORT s);
    void add(CPXSHORT const *s, CPXLONG cnt);
    void add(CPXINT i);
    void add(CPXINT const *i, CPXLONG cnt);
    void add(CPXLONG l);
    void add(CPXLONG const *l, CPXLONG cnt);
    void add(float f);
    void add(float const *f, CPXLONG cnt);
    void add(double d);
    void add(double const *d, CPXLONG cnt);

    void const *getRawData() const;
    CPXLONG getRawLength() const;
  private:
    Serializer(Serializer const&);
    Serializer& operator=(Serializer const&);
    CPXSERIALIZERptr s;
  };

  class Deserializer {
  public:
    Deserializer(void const *data, CPXLONG len);
    ~Deserializer();

    void get(CPXBYTE * b, CPXLONG cnt);
    void get(CPXSHORT * s, CPXLONG cnt);
    void get(CPXINT * i, CPXLONG cnt);
    void get(CPXLONG * l, CPXLONG cnt);
    void get(float * f, CPXLONG cnt);
    void get(double * d, CPXLONG cnt);
  private:
    Deserializer(Deserializer const&);
    Deserializer& operator=(Deserializer const&);
    CPXDESERIALIZERptr d;
  };

  int userfunction (int id, CPXLONG inlen, void const *in,
                    CPXLONG outcap, CPXLONG *outlen_p, void *out);

  void transportctrl(int ctrl, CPXINT &data) const;
  void transportctrl(int ctrl, CPXLONG &data) const;
  void transportctrl(int ctrl, double &data) const;

#else
  class AsyncHandle;
#endif /* !ILOG_CPLEX_NO_REMOTE_API */

private:
  friend class IloLPExtractor;
  friend class NodeEvaluatorI;
  friend class SearchLimitI;
  friend class CpxApplyGoalI;
  friend class CpxLimitGoalI;

  static inline IloInt int64to32(IloInt64 val)
  {
     /* Not using std::numeric_limits<> since it may not work
      * across all compilers and platforms.
      */
     if      ( val >= CPXLIM<sizeof(IloInt)>::maxVal() )
        return (IloInt)CPXLIM<sizeof(IloInt)>::maxVal();
     else if ( val <= CPXLIM<sizeof(IloInt)>::minVal() )
        return (IloInt)CPXLIM<sizeof(IloInt)>::minVal();
     else
        return (IloInt)val;
  }

  void construct(IloEnv env, bool isRemote,
                 IloCplexInitFunction *initFunction,
                 char const *transport = 0, int argc = 0,
                 char const *const *argv = 0,
                 void const *asynctab = 0);

public:
  IloCplex(IloEnv env);

  IloCplex(const IloModel model);

  IloCplex(IloCplexI* impl = 0);

#ifndef ILOG_CPLEX_NO_REMOTE_API
  template<typename I>
  IloCplex(IloEnv env, char const *transport, I argc, char const *const *argv)
    : IloAlgorithm(0)
  {
    // This function is a template so that it does not produce references
    // to CPXopenCPLEXremote() or CPXgetasynctab() unless it is actually
    // used.
    this->construct(env, true, CPXopenCPLEXremote, transport, argc, argv,
                    CPXgetasynctab ());
  }

  template<typename I>
  IloCplex(IloModel model, char const *transport, I argc, char const *const *argv)
    : IloAlgorithm(0)
  {
    // This function is a template so that it does not produce references
    // to CPXopenCPLEXremote() or CPXgetasynctab() unless it is actually
    // used.
    this->construct(model.getImpl()->getEnv(), true, CPXopenCPLEXremote,
                    transport, argc, argv, CPXgetasynctab ());
    try { this->extract(model); }
    catch (...) { end(); throw; }
  }
#endif // !ILOG_CPLEX_NO_REMOTE_API

#ifndef ILOG_CPLEX_NO_DISTRIBUTED_MIP_API
  inline bool hasVMConfig () const;
  template<typename T> inline void copyVMConfig(T xmlstring);
  template<typename T> inline void readVMConfig(T file);
  inline void delVMConfig();
#endif // !ILOG_CPLEX_NO_REMOTE_API

  void clearModel();
  using IloAlgorithm::clear;

  static void GetVersion(char* buffer, IloInt len);
   
  static void GetAcademicMsg(char* buffer, IloInt len);
   
  static void GetPreviewMsg(char* buffer, IloInt len);
   

  static const int IncumbentId = CPX_INCUMBENT_ID;

  void deleteNames();

  IloConstraint            addUserCut(IloConstraint con);

  const IloConstraintArray addUserCuts(const IloConstraintArray con);

  void                clearUserCuts();

  IloConstraint            addCut(IloConstraint con);

  const IloConstraintArray addCuts(const IloConstraintArray con);

  void                clearCuts();

  IloConstraint            addLazyConstraint(IloConstraint con);

  const IloConstraintArray addLazyConstraints(const IloConstraintArray con);

  void                clearLazyConstraints();

  void importModel(IloModel&      model,
                          const char*    filename,
                          IloObjective&  obj,
                          IloNumVarArray vars,
                          IloRangeArray  rngs,
                          IloSOS1Array   sos1,
                          IloSOS2Array   sos2,
                          IloRangeArray  lazy = 0,
                          IloRangeArray  cuts = 0) const;

  void importModel(IloModel&      m,
                          const char*    filename,
                          IloObjective&  obj,
                          IloNumVarArray vars,
                          IloRangeArray  rngs,
                          IloRangeArray  lazy = 0,
                          IloRangeArray  cuts = 0) const;

  void importModel(IloModel& m, const char* filename) const;

  void exportModel(const char* filename) const;

  void writeOrder (const char* filename) const;

  void writeConflict (const char* filename) const;

  void writeParam(const char* name) const;

  void writeBasis(const char* name) const;

  enum WriteLevelType {
     Auto                = CPX_WRITELEVEL_AUTO,
     AllVars             = CPX_WRITELEVEL_ALLVARS,
     DiscreteVars        = CPX_WRITELEVEL_DISCRETEVARS,
     NonzeroVars         = CPX_WRITELEVEL_NONZEROVARS,
     NonZeroDiscreteVars = CPX_WRITELEVEL_NONZERODISCRETEVARS
  };

  void writeSolution(const char* name, IloInt soln=IncumbentId) const;

  void writeSolutions(const char* name) const;

  void writeMIPStarts(const char* name, IloInt first=0,
                      IloInt num=IloIntMax) const;


  void readOrder (const char* filename) const;

  void readParam(const char* name) const;

  void readBasis(const char* name) const;

  void readSolution(const char* name) const;

  void readMIPStarts(const char* name) const;

  typedef int* Index;
  typedef IloCarray<Index> IndexArray;

  class LongAnnotation {
     friend class IloCplexI;
     IloCplex::Index annoidx;
  public:
     LongAnnotation(Index idx=0) : annoidx(idx) {}
     bool isValid () const   { return (annoidx != 0 && *annoidx >= 0); }
  };

  class NumAnnotation {
     friend class IloCplexI;
     IloCplex::Index annoidx;
  public:
     NumAnnotation(Index idx=0) : annoidx(idx) {}
     bool isValid () const   { return (annoidx != 0 && *annoidx >= 0); }
  };

  void writeBendersAnnotation (const char *name) const;

  void readAnnotations (const char* name);
  void writeAnnotations(const char* name) const;

  IloInt     numLongAnnotations () const;
  void       delAnnotation (LongAnnotation anno);
  const char *getName(const LongAnnotation annotation) const;

  LongAnnotation newLongAnnotation  (const char *name, IloInt64 defval = -1);
  LongAnnotation findLongAnnotation (const char *name) const;
  LongAnnotation findLongAnnotation (IloInt num) const;
  IloBool        hasLongAnnotation  (const char *name) const;

  IloInt64 getDefaultValue (const LongAnnotation annotation) const;

  IloInt64 getAnnotation (const LongAnnotation annotation, const IloNumVar var) const;
  IloInt64 getAnnotation (const LongAnnotation annotation, const IloIntVar var) const;
  IloInt64 getAnnotation (const LongAnnotation annotation, const IloObjective obj) const;
  IloInt64 getAnnotation (const LongAnnotation annotation, const IloConstraint ctr) const;

  void getAnnotation (const LongAnnotation annotation, const IloNumVarArray var,     IloArray<IloInt64>& value) const;
  void getAnnotation (const LongAnnotation annotation, const IloIntVarArray var,     IloArray<IloInt64>& value) const;
  void getAnnotation (const LongAnnotation annotation, const IloConstraintArray ctr, IloArray<IloInt64>& value) const;

  void setAnnotation (const LongAnnotation annotation, const IloNumVar var,     IloInt64 value);
  void setAnnotation (const LongAnnotation annotation, const IloIntVar var,     IloInt64 value);
  void setAnnotation (const LongAnnotation annotation, const IloObjective obj,  IloInt64 value);
  void setAnnotation (const LongAnnotation annotation, const IloConstraint ctr, IloInt64 value);

  void setAnnotation (const LongAnnotation annotation, const IloNumVarArray var,     const IloArray<IloInt64> value);
  void setAnnotation (const LongAnnotation annotation, const IloIntVarArray var,     const IloArray<IloInt64> value);
  void setAnnotation (const LongAnnotation annotation, const IloConstraintArray ctr, const IloArray<IloInt64> value);

  IloInt     numNumAnnotations () const;
  void       delAnnotation (NumAnnotation anno);
  const char *getName(const NumAnnotation annotation) const;

  NumAnnotation   newNumAnnotation  (const char *name, IloNum defval = 0.0);
  NumAnnotation   findNumAnnotation (const char *name) const;
  NumAnnotation   findNumAnnotation (IloInt num) const;
  IloBool         hasNumAnnotation  (const char *name) const;

  IloNum   getDefaultValue (const NumAnnotation annotation) const;

  IloNum   getAnnotation (const NumAnnotation annotation, const IloNumVar var) const;
  IloNum   getAnnotation (const NumAnnotation annotation, const IloIntVar var) const;
  IloNum   getAnnotation (const NumAnnotation annotation, const IloObjective obj) const;
  IloNum   getAnnotation (const NumAnnotation annotation, const IloConstraint ctr) const;

  void getAnnotation (const NumAnnotation annotation, const IloNumVarArray var,     IloNumArray& value) const;
  void getAnnotation (const NumAnnotation annotation, const IloIntVarArray var,     IloNumArray& value) const;
  void getAnnotation (const NumAnnotation annotation, const IloConstraintArray ctr, IloNumArray& value) const;

  void setAnnotation (const NumAnnotation annotation, const IloNumVar var,     IloNum value);
  void setAnnotation (const NumAnnotation annotation, const IloIntVar var,     IloNum value);
  void setAnnotation (const NumAnnotation annotation, const IloObjective obj,  IloNum value);
  void setAnnotation (const NumAnnotation annotation, const IloConstraint ctr, IloNum value);

  void setAnnotation (const NumAnnotation annotation, const IloNumVarArray var,     const IloNumArray value);
  void setAnnotation (const NumAnnotation annotation, const IloIntVarArray var,     const IloNumArray value);
  void setAnnotation (const NumAnnotation annotation, const IloConstraintArray ctr, const IloNumArray value);

  IloObjective getObjective() const;

  const char* getVersion() const;

  int getVersionNumber() const;

  IloInt64 getNiterations64() const;

  IloInt getNiterations() const;

  IloInt64 getNbarrierIterations64() const;

  IloInt getNbarrierIterations() const;

  IloInt64 getNsiftingIterations64() const;

  IloInt getNsiftingIterations() const;

  IloInt64 getNsiftingPhaseOneIterations64() const;

  IloInt getNsiftingPhaseOneIterations() const;

  IloInt getNcols () const;

  IloInt getNrows () const;

  IloInt getNQCs () const;

  IloInt getNSOSs () const;

  IloInt getNindicators () const;

  IloInt getNLCs () const;

  IloInt getNUCs () const;

  IloInt getNNZs  () const;

  IloInt64 getNNZs64() const;

  IloInt getNintVars() const;

  IloInt getNbinVars() const;

  IloInt getNsemiContVars() const;

  IloInt getNsemiIntVars() const;

   enum BasisStatus {
     NotABasicStatus  = -1,
     Basic            =  1,
     AtLower          =  0,
     AtUpper          =  2,
     FreeOrSuperbasic =  3
   };


  typedef IloArray<BasisStatus> BasisStatusArray;

  IloBool solveFixed(IloInt soln=IloCplex::IncumbentId);
#ifndef ILOG_CPLEX_NO_REMOTE_API
  class SolveFixedHandleI : public AsyncHandleI {
  public:
    virtual IloBool joinSolveFixed() = 0;
  };
  class SolveFixedHandle : public AsyncHandle {
  public:
    SolveFixedHandle(SolveFixedHandleI *i) : AsyncHandle(i) {}
    IloBool joinSolveFixed();
  };
  SolveFixedHandle solveFixed(IloInt soln, bool async);
#endif

  IloBool isMIP() const;

  IloBool isQC() const;

  IloBool isQO() const;


  IloNum getBestObjValue() const;

  IloNum getMIPRelativeGap() const;

  IloNum getCutoff() const;

  IloInt64 getIncumbentNode64() const;

  IloInt getIncumbentNode() const;

  IloInt getNprimalSuperbasics() const;

  IloInt getNdualSuperbasics() const;

  IloInt64 getNphaseOneIterations64() const;

  IloInt getNphaseOneIterations() const;

  IloInt64 getNnodes64() const;

  IloInt getNnodes() const;

  IloInt64 getNnodesLeft64() const;

  IloInt getNnodesLeft() const;

  enum CutType {
    CutCover      = CPX_CUT_COVER,
    CutGubCover   = CPX_CUT_GUBCOVER,
    CutFlowCover  = CPX_CUT_FLOWCOVER,
    CutClique     = CPX_CUT_CLIQUE,
    CutFrac       = CPX_CUT_FRAC,
    CutMir        = CPX_CUT_MIR,
    CutFlowPath   = CPX_CUT_FLOWPATH,
    CutDisj       = CPX_CUT_DISJ,
    CutImplBd     = CPX_CUT_IMPLBD,
    CutZeroHalf   = CPX_CUT_ZEROHALF,
    CutMCF        = CPX_CUT_MCF,
    CutLocalCover = CPX_CUT_LOCALCOVER,
    CutTighten    = CPX_CUT_TIGHTEN,
    CutObjDisj    = CPX_CUT_OBJDISJ,
    CutLiftProj   = CPX_CUT_LANDP,
    CutUser       = CPX_CUT_USER,
    CutTable      = CPX_CUT_TABLE,
    CutSolnPool   = CPX_CUT_SOLNPOOL,
    CutLocalImplBd = CPX_CUT_LOCALIMPLBD,
    CutBQP        = CPX_CUT_BQP,
    CutRLT        = CPX_CUT_RLT,
    CutBenders    = CPX_CUT_BENDERS
  };

  IloInt getNcuts(CutType which) const;

  IloInt64 getNcrossPPush64() const;

  IloInt getNcrossPPush() const;

  IloInt64 getNcrossPExch64() const;

  IloInt getNcrossPExch() const;

  IloInt64 getNcrossDPush64() const;

  IloInt getNcrossDPush() const;

  IloInt64 getNcrossDExch64() const;

  IloInt getNcrossDExch() const;

  using IloAlgorithm::getValue;
  using IloAlgorithm::getValues;
  using IloAlgorithm::getObjValue;

  void getValues (IloNumArray val, const IloNumVarArray var) const {
    IloAlgorithm::getValues(var, val);
  }

  void getValues (const IloNumVarArray var, IloNumArray val) const {
    IloAlgorithm::getValues(var, val);
  }

  void getValues (IloNumArray val, const IloIntVarArray var) const {
    IloAlgorithm::getValues(var, val);
  }

  void getValues (const IloIntVarArray var, IloNumArray val) const {
    IloAlgorithm::getValues(var, val);
  }

  void getValues(IloNumArray val, const IloNumVarArray var,
                 IloInt soln) const;

  void getValues(const IloNumVarArray var, IloNumArray val,
                 IloInt soln) const;

  void getValues(IloNumArray val, const IloIntVarArray var,
                 IloInt soln) const;

  void getValues(const IloIntVarArray var, IloNumArray val,
                 IloInt soln) const;

  IloNum getValue(const IloNumVar var, IloInt soln) const;

  IloNum getValue(const IloIntVar var, IloInt soln) const;

  IloNum getValue(const IloNumExprArg expr, IloInt soln) const;

  IloNum getValue(const IloObjective ob, IloInt soln) const;

  IloNum getObjValue(IloInt soln) const;


#ifdef USE_SET_VARS
  void getIntSetValue (const IloIntSetVar var, IloIntSet set) const;
#endif

  IloNum getDual(const IloRange range) const;

  IloNum getSlack (const IloRange range, IloInt soln=IncumbentId) const;

  IloNum getInfeasibility (const IloConstraint con) const;

  IloNum getAX    (const IloRange range) const;

  IloNum getReducedCost(const IloNumVar var) const;

  IloNum getReducedCost(const IloIntVar var) const;

  void getQCDSlack (const IloRange range, IloNumArray& vals, IloNumVarArray& vars) const;
  void getQCDSlack (const IloForAllRange range, IloNumArray& vals, IloNumVarArray& vars) const;

  IloNum getInfeasibility (const IloNumVar var) const;

  IloNum getInfeasibility (const IloIntVar var) const;

  BasisStatus getBasisStatus(const IloNumVar var) const;

  BasisStatus getBasisStatus(const IloIntVar var) const;

  BasisStatus getBasisStatus(const IloConstraint con) const;

  void getDuals  (IloNumArray val, const IloRangeArray con) const;

  void getSlacks (IloNumArray val, const IloRangeArray con,
                  IloInt soln=IncumbentId) const;

  IloNum getInfeasibilities (      IloNumArray        infeas,
                             const IloConstraintArray con) const;

  void getAX(IloNumArray val, const IloRangeArray con) const;

  void getReducedCosts(IloNumArray val, const IloNumVarArray var) const;

  void getReducedCosts(IloNumArray val, const IloIntVarArray var) const;

  IloNum getInfeasibilities (      IloNumArray    infeas,
                             const IloNumVarArray var) const;

  IloNum getInfeasibilities (      IloNumArray    infeas,
                             const IloIntVarArray var) const;

  void getBasisStatuses(      BasisStatusArray stat,
                        const IloNumVarArray   var) const;

  void getBasisStatuses(      BasisStatusArray stat,
                        const IloIntVarArray   var) const;

  void getBasisStatuses(      BasisStatusArray   stat,
                        const IloConstraintArray con) const;

  void getBasisStatuses(      BasisStatusArray   cstat,
                        const IloNumVarArray     var,
                              BasisStatusArray   rstat,
                        const IloConstraintArray con) const;
  void getBasisStatuses(      BasisStatusArray   cstat,
                        const IloIntVarArray     var,
                              BasisStatusArray   rstat,
                        const IloConstraintArray con) const;

  void getBoundSA(      IloNumArray    lblower,
                        IloNumArray    lbupper,
                        IloNumArray    ublower,
                        IloNumArray    ubupper,
                  const IloNumVarArray vars) const;

  void getBoundSA(      IloNumArray    lblower,
                        IloNumArray    lbupper,
                        IloNumArray    ublower,
                        IloNumArray    ubupper,
                  const IloIntVarArray vars) const;

  void getRangeSA(      IloNumArray   lblower,
                        IloNumArray   lbupper,
                        IloNumArray   ublower,
                        IloNumArray   ubupper,
                  const IloRangeArray con) const;

  void getRHSSA  (      IloNumArray   lower,
                        IloNumArray   upper,
                  const IloRangeArray cons) const;

  void getObjSA  (      IloNumArray    lower,
                        IloNumArray    upper,
                  const IloNumVarArray vars) const;

  void getObjSA  (IloNumArray lower, IloNumArray upper,
                         const IloIntVarArray cols) const;

  IloNum getAX(const IloForAllRange range) const;
  IloNum getDual(const IloForAllRange range) const;
  IloNum getSlack(const IloForAllRange range, IloInt soln=IncumbentId) const;
  void getAX  (IloNumArray val, const IloForAllRangeArray con) const;
  void getDuals  (IloNumArray val, const IloForAllRangeArray con) const;
  void getSlacks (IloNumArray val, const IloForAllRangeArray con,
                  IloInt soln=IncumbentId) const;
  void getForAllRanges (IloForAllRangeArray rows,
                        IloConstraint       forall) const;
  IloNum getLB(const IloForAllRange range) const;
  IloNum getUB(const IloForAllRange range) const;
  IloBool feasOpt(const IloRangeArray       rngs,
                  const IloNumArray         rnglb,
                  const IloNumArray         rngub,
                  const IloForAllRangeArray rngf,
                  const IloNumArray         frnglb,
                  const IloNumArray         frngub,
                  const IloNumVarArray      vars,
                  const IloNumArray         varlb,
                  const IloNumArray         varub);

#ifndef ILOG_CPLEX_NO_REMOTE_API
  class FeasOptHandleI : public AsyncHandleI {
  public:
    virtual IloBool joinFeasOpt() = 0;
  };
  class FeasOptHandle : public AsyncHandle {
  public:
    FeasOptHandle(FeasOptHandleI *i = 0) : AsyncHandle(i) {}
    IloBool joinFeasOpt();
  };
  FeasOptHandle feasOpt(const IloRangeArray       rngs,
                        const IloNumArray         rnglb,
                        const IloNumArray         rngub,
                        const IloForAllRangeArray rngf,
                        const IloNumArray         frnglb,
                        const IloNumArray         frngub,
                        const IloNumVarArray      vars,
                        const IloNumArray         varlb,
                        const IloNumArray         varub,
                        bool async);
#else // !ILOG_CPLEX_NO_REMOTE_API
  struct FeasOptHandleI;
#endif // ILOG_CPLEX_NO_REMOTE_API

  void setBasisStatuses(const BasisStatusArray   cstat,
                        const IloNumVarArray     var,
                        const BasisStatusArray   rstat,
                        const IloConstraintArray con);

  void setBasisStatuses(const BasisStatusArray   cstat,
                        const IloIntVarArray     var,
                        const BasisStatusArray   rstat,
                        const IloConstraintArray con);

  void setStart(const IloNumArray    x,
                const IloNumArray    dj,
                const IloNumVarArray var,
                const IloNumArray    slack,
                const IloNumArray    pi,
                const IloRangeArray  rng);

  void setStart(const IloNumArray    x,
                const IloNumArray    dj,
                const IloIntVarArray var,
                const IloNumArray    slack,
                const IloNumArray    pi,
                const IloRangeArray  rng);


  /* MIPstart API */

  enum MIPStartEffort {
     MIPStartAuto        = CPX_MIPSTART_AUTO,
     MIPStartCheckFeas   = CPX_MIPSTART_CHECKFEAS,
     MIPStartSolveFixed  = CPX_MIPSTART_SOLVEFIXED,
     MIPStartSolveMIP    = CPX_MIPSTART_SOLVEMIP,
     MIPStartRepair      = CPX_MIPSTART_REPAIR,
     MIPStartNoCheck     = CPX_MIPSTART_NOCHECK
  };

  int getNMIPStarts() const;

  IloInt addMIPStart (IloNumVarArray vars=0, IloNumArray values=0,
                      MIPStartEffort effort=MIPStartAuto,
                      const char *name=0);
  void changeMIPStart (IloInt mipstartindex, IloNumVarArray vars, 
                       IloNumArray values);
  void changeMIPStart (IloInt mipstartindex, IloNumVarArray vars, 
                       IloNumArray values,
                       MIPStartEffort effortlevel);
  void deleteMIPStarts    (IloInt first, IloInt num=1);

  IloCplex::MIPStartEffort getMIPStart (IloInt               mipstartindex,
                                        const IloNumVarArray vars,
                                        IloNumArray          vals,
                                        IloBoolArray         isset);
  const char* getMIPStartName (IloInt mipstartindex);

  IloInt getMIPStartIndex(const char *lname_str) const;


  enum NumParam {
    NumParam_MIN    = 0,
    NumParam_MAX    = INT_MAX,
    EpMrk           = CPX_PARAM_EPMRK, /**< = CPX_PARAM_EPMRK */
    EpOpt           = CPX_PARAM_EPOPT, /**< = CPX_PARAM_EPOPT */
    EpPer           = CPX_PARAM_EPPER, /**< = CPX_PARAM_EPPER */
    EpRHS           = CPX_PARAM_EPRHS, /**< = CPX_PARAM_EPRHS */
    NetEpOpt        = CPX_PARAM_NETEPOPT, /**< = CPX_PARAM_NETEPOPT */
    NetEpRHS        = CPX_PARAM_NETEPRHS, /**< = CPX_PARAM_NETEPRHS */

    TiLim           = CPX_PARAM_TILIM, /**< = CPX_PARAM_TILIM */
    DetTiLim        = CPX_PARAM_DETTILIM, /**< = CPX_PARAM_DETTILIM */
    TuningTiLim     = CPX_PARAM_TUNINGTILIM, /**< = CPX_PARAM_TUNINGTILIM */
    TuningDetTiLim  = CPX_PARAM_TUNINGDETTILIM, /**< = CPX_PARAM_TUNINGDETTILIM */
    BtTol           = CPX_PARAM_BTTOL, /**< = CPX_PARAM_BTTOL */
    CutLo           = CPX_PARAM_CUTLO, /**< = CPX_PARAM_CUTLO */
    CutUp           = CPX_PARAM_CUTUP, /**< = CPX_PARAM_CUTUP */
    EpGap           = CPX_PARAM_EPGAP, /**< = CPX_PARAM_EPGAP */
    EpInt           = CPX_PARAM_EPINT, /**< = CPX_PARAM_EPINT */
    EpAGap          = CPX_PARAM_EPAGAP, /**< = CPX_PARAM_EPAGAP */
    EpRelax         = CPX_PARAM_EPRELAX, /**< = CPX_PARAM_EPRELAX */
    ObjDif          = CPX_PARAM_OBJDIF, /**< = CPX_PARAM_OBJDIF */
    ObjLLim         = CPX_PARAM_OBJLLIM, /**< = CPX_PARAM_OBJLLIM */
    ObjULim         = CPX_PARAM_OBJULIM, /**< = CPX_PARAM_OBJULIM */
    PolishTime      = CPX_PARAM_POLISHTIME, /**< = CPX_PARAM_POLISHTIME */
    PolishAfterEpAGap = CPX_PARAM_POLISHAFTEREPAGAP, /**< = CPX_PARAM_POLISHAFTEREPAGAP */    
    PolishAfterEpGap  = CPX_PARAM_POLISHAFTEREPGAP, /**< = CPX_PARAM_POLISHAFTEREPGAP */
    PolishAfterTime   = CPX_PARAM_POLISHAFTERTIME, /**< = CPX_PARAM_POLISHAFTERTIME */
    PolishAfterDetTime = CPX_PARAM_POLISHAFTERDETTIME, /**< = CPX_PARAM_POLISHAFTERDETTIME */
    ProbeTime       = CPX_PARAM_PROBETIME, /**< = CPX_PARAM_PROBETIME */
    ProbeDetTime    = CPX_PARAM_PROBEDETTIME, /**< = CPX_PARAM_PROBEDETTIME */
    RelObjDif       = CPX_PARAM_RELOBJDIF, /**< = CPX_PARAM_RELOBJDIF */
    CutsFactor      = CPX_PARAM_CUTSFACTOR, /**< = CPX_PARAM_CUTSFACTOR */
    TreLim          = CPX_PARAM_TRELIM, /**< = CPX_PARAM_TRELIM */
    SolnPoolGap     = CPX_PARAM_SOLNPOOLGAP, /**< = CPX_PARAM_SOLNPOOLGAP */
    SolnPoolAGap    = CPX_PARAM_SOLNPOOLAGAP, /**< = CPX_PARAM_SOLNPOOLAGAP */
    WorkMem         = CPX_PARAM_WORKMEM, /**< = CPX_PARAM_WORKMEM */

    BarEpComp       = CPX_PARAM_BAREPCOMP, /**< = CPX_PARAM_BAREPCOMP */
    BarQCPEpComp    = CPX_PARAM_BARQCPEPCOMP, /**< = CPX_PARAM_BARQCPEPCOMP */
    BarGrowth       = CPX_PARAM_BARGROWTH, /**< = CPX_PARAM_BARGROWTH */
    BarObjRng       = CPX_PARAM_BAROBJRNG, /**< = CPX_PARAM_BAROBJRNG */
    EpLin           = CPX_PARAM_EPLIN, /**< = CPX_PARAM_EPLIN */
    RampupDettimeLim  = CPX_PARAM_RAMPUPDETTILIM, /**< = CPX_PARAM_RAMPUPDETTILIM */
    RampupWalltimeLim = CPX_PARAM_RAMPUPTILIM /**< = CPX_PARAM_RAMPUPTILIM */
  };

  enum BoolParam {
    BoolParam_MIN   = 0,
    BoolParam_MAX   = INT_MAX,
    CloneLog        = CPX_PARAM_CLONELOG, 
    PreInd          = CPX_PARAM_PREIND, 
    MIPOrdInd       = CPX_PARAM_MIPORDIND,
    MPSLongNum      = CPX_PARAM_MPSLONGNUM, 
    LBHeur          = CPX_PARAM_LBHEUR,    
    PerInd          = CPX_PARAM_PERIND,   
    QPmakePSDInd    = CPX_PARAM_QPMAKEPSDIND,
    MemoryEmphasis  = CPX_PARAM_MEMORYEMPHASIS,
    NumericalEmphasis = CPX_PARAM_NUMERICALEMPHASIS
  };

  enum IntParam {
    IntParam_MIN    = 0,
    IntParam_MAX    = INT_MAX,
    AdvInd          = CPX_PARAM_ADVIND, 
    RootAlg         = CPX_PARAM_LPMETHOD,
    NodeAlg         = CPX_PARAM_SUBALG, 
    MIPEmphasis     = CPX_PARAM_MIPEMPHASIS, 
    AggInd          = CPX_PARAM_AGGIND, 
    ClockType       = CPX_PARAM_CLOCKTYPE, 
    CraInd          = CPX_PARAM_CRAIND, 
    DataCheck       = CPX_PARAM_DATACHECK,
    DepInd          = CPX_PARAM_DEPIND, 
    PreDual         = CPX_PARAM_PREDUAL, 
    PrePass         = CPX_PARAM_PREPASS, 
    PreLinear       = CPX_PARAM_PRELINEAR, 
    RelaxPreInd     = CPX_PARAM_RELAXPREIND, 
    RepeatPresolve  = CPX_PARAM_REPEATPRESOLVE, 
    Symmetry        = CPX_PARAM_SYMMETRY, 
    DPriInd         = CPX_PARAM_DPRIIND, 
    PriceLim        = CPX_PARAM_PRICELIM,
    SimDisplay      = CPX_PARAM_SIMDISPLAY, 
    NetFind         = CPX_PARAM_NETFIND, 
    PerLim          = CPX_PARAM_PERLIM, 
    PPriInd         = CPX_PARAM_PPRIIND, 
    ReInv           = CPX_PARAM_REINV, 
    ScaInd          = CPX_PARAM_SCAIND, 
    Threads         = CPX_PARAM_THREADS, 
    AuxRootThreads  = CPX_PARAM_AUXROOTTHREADS, 
    ParallelMode    = CPX_PARAM_PARALLELMODE, 
    SingLim         = CPX_PARAM_SINGLIM, 
    Reduce          = CPX_PARAM_REDUCE, 
    CalcQCPDuals    = CPX_PARAM_CALCQCPDUALS, 
    ColReadLim      = CPX_PARAM_COLREADLIM, 
    RowReadLim      = CPX_PARAM_ROWREADLIM, 
    WriteLevel      = CPX_PARAM_WRITELEVEL, 
    RandomSeed      = CPX_PARAM_RANDOMSEED, 

    SiftDisplay     = CPX_PARAM_SIFTDISPLAY, 
    SiftAlg         = CPX_PARAM_SIFTALG, 

    BrDir           = CPX_PARAM_BRDIR, 
    Cliques         = CPX_PARAM_CLIQUES, 
    CoeRedInd       = CPX_PARAM_COEREDIND, 
    Covers          = CPX_PARAM_COVERS, 
    MIPDisplay      = CPX_PARAM_MIPDISPLAY, 
    NodeFileInd     = CPX_PARAM_NODEFILEIND, 
    NodeSel         = CPX_PARAM_NODESEL, 
    VarSel          = CPX_PARAM_VARSEL, 
    BndStrenInd     = CPX_PARAM_BNDSTRENIND, 
    FPHeur          = CPX_PARAM_FPHEUR, 
    MIPOrdType      = CPX_PARAM_MIPORDTYPE, 
    FlowCovers      = CPX_PARAM_FLOWCOVERS, 
    ImplBd          = CPX_PARAM_IMPLBD, 
    Probe           = CPX_PARAM_PROBE, 
    GUBCovers       = CPX_PARAM_GUBCOVERS, 
    StrongCandLim   = CPX_PARAM_STRONGCANDLIM, 
    FracCand        = CPX_PARAM_FRACCAND, 
    FracCuts        = CPX_PARAM_FRACCUTS, 
    PreslvNd        = CPX_PARAM_PRESLVND, 
    FlowPaths       = CPX_PARAM_FLOWPATHS, 
    MIRCuts         = CPX_PARAM_MIRCUTS, 
    DisjCuts        = CPX_PARAM_DISJCUTS, 
    ZeroHalfCuts    = CPX_PARAM_ZEROHALFCUTS, 
    MCFCuts         = CPX_PARAM_MCFCUTS, 
    LiftProjCuts    = CPX_PARAM_LANDPCUTS, 
    AggCutLim       = CPX_PARAM_AGGCUTLIM, 
    EachCutLim      = CPX_PARAM_EACHCUTLIM, 
    DiveType        = CPX_PARAM_DIVETYPE, 
    MIPSearch       = CPX_PARAM_MIPSEARCH, 
    MIQCPStrat      = CPX_PARAM_MIQCPSTRAT, 

    SolnPoolCapacity  = CPX_PARAM_SOLNPOOLCAPACITY, 
    SolnPoolReplace   = CPX_PARAM_SOLNPOOLREPLACE, 
    SolnPoolIntensity = CPX_PARAM_SOLNPOOLINTENSITY, 
    PopulateLim       = CPX_PARAM_POPULATELIM, 

    BarAlg          = CPX_PARAM_BARALG, 
    BarColNz        = CPX_PARAM_BARCOLNZ, 
    BarDisplay      = CPX_PARAM_BARDISPLAY, 
    BarOrder        = CPX_PARAM_BARORDER, 
    BarCrossAlg     = CPX_PARAM_BARCROSSALG, 
    BarStartAlg     = CPX_PARAM_BARSTARTALG, 

    NetPPriInd      = CPX_PARAM_NETPPRIIND, 
    NetDisplay      = CPX_PARAM_NETDISPLAY, 

    ConflictDisplay = CPX_PARAM_CONFLICTDISPLAY, 
    FeasOptMode     = CPX_PARAM_FEASOPTMODE, 
    TuningMeasure   = CPX_PARAM_TUNINGMEASURE, 
    TuningRepeat    = CPX_PARAM_TUNINGREPEAT,  
    TuningDisplay   = CPX_PARAM_TUNINGDISPLAY, 

    MIPKappaStats   = CPX_PARAM_MIPKAPPASTATS,  

    OptimalityTarget  = CPX_PARAM_OPTIMALITYTARGET,  

    RampupDuration  = CPX_PARAM_RAMPUPDURATION
  };

  enum LongParam {
    LongParam_MIN   = 0,
    LongParam_MAX   = INT_MAX,
    // Parameters that have the same dimension as non-zero counts.
    AggFill         = CPX_PARAM_AGGFILL, 
    NzReadLim       = CPX_PARAM_NZREADLIM, 
    QPNzReadLim     = CPX_PARAM_QPNZREADLIM, 
    // Parameters that are big counters.
    ItLim           = CPX_PARAM_ITLIM, 
    SiftItLim       = CPX_PARAM_SIFTITLIM, 
    BarItLim        = CPX_PARAM_BARITLIM, 
    BarMaxCor       = CPX_PARAM_BARMAXCOR, 
    BBInterval      = CPX_PARAM_BBINTERVAL, 
    CutPass         = CPX_PARAM_CUTPASS, 
    FracPass        = CPX_PARAM_FRACPASS, 
    HeurFreq        = CPX_PARAM_HEURFREQ, 
    MIPInterval     = CPX_PARAM_MIPINTERVAL, 
    NodeLim         = CPX_PARAM_NODELIM, 
    IntSolLim       = CPX_PARAM_INTSOLLIM, 
    StrongItLim     = CPX_PARAM_STRONGITLIM, 
    RINSHeur        = CPX_PARAM_RINSHEUR, 
    SubMIPNodeLim   = CPX_PARAM_SUBMIPNODELIM, 
    RepairTries     = CPX_PARAM_REPAIRTRIES, 
    PolishAfterNode   = CPX_PARAM_POLISHAFTERNODE, 
    PolishAfterIntSol = CPX_PARAM_POLISHAFTERINTSOL, 
    NetItLim        = CPX_PARAM_NETITLIM  
  };

  enum StringParam {
    StringParam_MIN  = 0,
    StringParam_MAX  = INT_MAX,
    WorkDir          = CPX_PARAM_WORKDIR,     
    FileEncoding     = CPX_PARAM_FILEENCODING, 
    APIEncoding      = CPX_PARAM_APIENCODING, 
    IntSolFilePrefix = CPX_PARAM_INTSOLFILEPREFIX  
  };

#include <ilcplex/iloparam.h>

  void        setDefaults();

  void        setParam(IntParam    parameter, CPXINT value);

  void        setParam(LongParam    parameter, CPXLONG value);

  void        setParam(BoolParam   parameter, IloBool value);

  void        setParam(NumParam  parameter, IloNum value);

  void        setParam(StringParam parameter, const char* value);

  CPXINT      getParam(IntParam    parameter) const;

  CPXLONG     getParam(LongParam   parameter) const;

  IloBool     getParam(BoolParam   parameter) const;

  IloNum      getParam(NumParam  parameter) const;

  const char* getParam(StringParam parameter) const;

  IloBool     getDefault(BoolParam   parameter) const;

  CPXINT      getDefault(IntParam    parameter) const;

  CPXLONG     getDefault(LongParam   parameter) const;

  IloNum      getDefault(NumParam  parameter) const;

  const char* getDefault(StringParam parameter) const;

  CPXINT      getMin(IntParam    parameter) const;

  CPXLONG     getMin(LongParam parameter) const;

  IloNum      getMin(NumParam  parameter) const;

  CPXINT      getMax(IntParam    parameter) const;

  CPXLONG     getMax(LongParam  parameter) const;

  IloNum      getMax(NumParam  parameter) const;

  class Parameter;
  class ParameterSetI;

  class ParameterSet {
     ParameterSetI* _impl;
    
  public:
    class Iterator;
    ParameterSet(IloEnv env); 
    ParameterSet(ParameterSetI* impl) : _impl(impl) {}
    ParameterSet() : _impl(0) {}
    ParameterSetI* getImpl() const {return _impl;}

    void clear() {
       IloAssert(_impl, "Using empty handle IloCplex::ParameterSet");
       _impl->clear();
    }

    void end() {
       IloAssert(_impl, "Using empty handle IloCplex::ParameterSet");
       delete _impl;
       _impl = 0;
    }

    void setParam(IntParam which, CPXINT val) {
       IloAssert(_impl, "Using empty handle IloCplex::ParameterSet");
       _impl->setParam(which, val);
    }

    void setParam(LongParam which, CPXLONG val) {
       IloAssert(_impl, "Using empty handle IloCplex::ParameterSet");
       _impl->setParam(which, val);
    }
  
    void setParam(StringParam  which, const char* val) {
       IloAssert(_impl, "Using empty handle IloCplex::ParameterSet");
       _impl->setParam(which, val);
    }
  
    void setParam(BoolParam which, IloBool val) {
       IloAssert(_impl, "Using empty handle IloCplex::ParameterSet");
       _impl->setParam(which, val);
    }
  
    void setParam(NumParam  which, IloNum val) {
       IloAssert(_impl, "Using empty handle IloCplex::ParameterSet");
       _impl->setParam(which, val);
    }

    CPXINT getParam(IntParam which) const {
       IloAssert(_impl, "Using empty handle IloCplex::ParameterSet");
       return _impl->getParam(which);
    }
    CPXLONG getParam(LongParam which) const {
       IloAssert(_impl, "Using empty handle IloCplex::ParameterSet");
       return _impl->getParam(which);
    }
    char* getParam(StringParam  which) const {
       IloAssert(_impl, "Using empty handle IloCplex::ParameterSet");
       return _impl->getParam(which);
    }
   
    IloBool getParam(BoolParam which) const {
       IloAssert(_impl, "Using empty handle IloCplex::ParameterSet");
       return _impl->getParam(which);
    }
  
    IloNum getParam(NumParam  which) const {
       IloAssert(_impl, "Using empty handle IloCplex::ParameterSet");
       return _impl->getParam(which);
    }

  };

  class ParameterSetI {
    friend class IloCplexI;
    friend class ParameterSet::Iterator;
    IloEnvI *_env;
    IloArray<IntParam>    _intParams;
    IloArray<CPXINT>      _intParamValues;
    IloArray<BoolParam>   _boolParams;
    IloBoolArray          _boolParamValues;
    IloArray<NumParam>    _numParams;
    IloNumArray           _numParamValues;
    IloArray<StringParam> _stringParams;
    IloArray<char*>       _stringParamValues;
    IloArray<LongParam>   _longParams;
    IloArray<CPXLONG>     _longParamValues;
  public:
    ParameterSetI(IloEnvI* env);
    ~ParameterSetI();
    void operator delete(void*, size_t);
    void clear();
    void setParam(IntParam which, CPXINT val);
    void setParam(LongParam which, CPXLONG val);
    void setParam(StringParam  which, const char* val);
    void setParam(BoolParam which, IloBool val);
    void setParam(NumParam  which, IloNum val);
    CPXINT  getParam(IntParam which) const;
    CPXLONG getParam(LongParam which) const;
    char*   getParam(StringParam  which) const;
    IloBool getParam(BoolParam which) const;
    IloNum  getParam(NumParam  which) const;
    void applyTo(IloCplexI* cplex);
    void extractFrom(IloCplexI* cplex);
  };

   ParameterSet getParameterSet() {
     IloAssert(getImpl(), "Using empty IloCplex handle.");
     ParameterSet set(getEnv());
     set.getImpl()->extractFrom(getImpl());
     return set;
   }

   void setParameterSet(ParameterSet set) {
      IloAssert(getImpl(), "Using empty IloCplex handle.");
      IloAssert(set.getImpl(), "Using empty IloCplex::ParameterSet handle.");
      set.getImpl()->applyTo(getImpl());
   }
   
  enum MIPEmphasisType {
    MIPEmphasisBalanced    = CPX_MIPEMPHASIS_BALANCED, 
    MIPEmphasisOptimality  = CPX_MIPEMPHASIS_OPTIMALITY, 
    MIPEmphasisFeasibility = CPX_MIPEMPHASIS_FEASIBILITY, 
    MIPEmphasisBestBound   = CPX_MIPEMPHASIS_BESTBOUND, 
    MIPEmphasisHiddenFeas  = CPX_MIPEMPHASIS_HIDDENFEAS 
  };

  enum OptimalityTargetType {
    OptimalityAuto          = CPX_OPTIMALITYTARGET_AUTO,       
    OptimalityOptimalConvex = CPX_OPTIMALITYTARGET_OPTIMALCONVEX,
    OptimalityFirstOrder    = CPX_OPTIMALITYTARGET_FIRSTORDER,  
    OptimalityOptimalGlobal = CPX_OPTIMALITYTARGET_OPTIMALGLOBAL 
  };


  enum VariableSelect {
    MinInfeas     = CPX_VARSEL_MININFEAS, 
    DefaultVarSel = CPX_VARSEL_DEFAULT, 
    MaxInfeas     = CPX_VARSEL_MAXINFEAS, 
    Pseudo        = CPX_VARSEL_PSEUDO, 
    Strong        = CPX_VARSEL_STRONG, 
    PseudoReduced = CPX_VARSEL_PSEUDOREDUCED 
  };
  enum NodeSelect {
    DFS        = CPX_NODESEL_DFS, 
    BestBound  = CPX_NODESEL_BESTBOUND, 
    BestEst    = CPX_NODESEL_BESTEST, 
    BestEstAlt = CPX_NODESEL_BESTEST_ALT 
  };

   enum DistMIPRampupDuration {
      RampupDisabled = CPX_RAMPUP_DISABLED, 
      RampupAuto     = CPX_RAMPUP_AUTO,    
      RampupDynamic  = CPX_RAMPUP_DYNAMIC,  
      RampupInfinite = CPX_RAMPUP_INFINITE  
   };

  enum PrimalPricing {
    PPriIndPartial     = CPX_PPRIIND_PARTIAL, 
    PPriIndAuto        = CPX_PPRIIND_AUTO, 
    PPriIndDevex       = CPX_PPRIIND_DEVEX, 
    PPriIndSteep       = CPX_PPRIIND_STEEP, 
    PPriIndSteepQStart = CPX_PPRIIND_STEEPQSTART, 
    PPriIndFull        = CPX_PPRIIND_FULL 
  };

  enum ConflictAlgorithm {
     ConflictAuto         = CPX_CONFLICTALG_AUTO,    
     ConflictFast         = CPX_CONFLICTALG_FAST,   
     ConflictPropagate    = CPX_CONFLICTALG_PROPAGATE, 
     ConflictPresolve     = CPX_CONFLICTALG_PRESOLVE,  
     ConflictIIS          = CPX_CONFLICTALG_IIS,   
     ConflictLimitedSolve = CPX_CONFLICTALG_LIMITSOLVE, 
     ConflictSolve        = CPX_CONFLICTALG_SOLVE  
  };

  enum Parallel_Mode {
    Opportunistic  = CPX_PARALLEL_OPPORTUNISTIC, 
    AutoParallel   = CPX_PARALLEL_AUTO,         
    Deterministic  = CPX_PARALLEL_DETERMINISTIC  
  };

  enum MIPsearch {
    AutoSearch  = CPX_MIPSEARCH_AUTO,        
    Traditional = CPX_MIPSEARCH_TRADITIONAL, 
    Dynamic     = CPX_MIPSEARCH_DYNAMIC     
  };


#define CPX_MIPSEARCH_AUTO               0
#define CPX_MIPSEARCH_TRADITIONAL        1
#define CPX_MIPSEARCH_DYNAMIC            2

  enum DataCheckType {
    Off        = CPX_DATACHECK_OFF, /**< = CPX_DATACHECK_OFF */
    Warn       = CPX_DATACHECK_WARN, /**< = CPX_DATACHECK_WARN */
    Assist     = CPX_DATACHECK_ASSIST /**< = CPX_DATACHECK_ASSIST */
  };

  enum DualPricing {
    DPriIndAuto        = CPX_DPRIIND_AUTO, 
    DPriIndFull        = CPX_DPRIIND_FULL, 
    DPriIndSteep       = CPX_DPRIIND_STEEP, 
    DPriIndFullSteep   = CPX_DPRIIND_FULLSTEEP, 
    DPriIndSteepQStart = CPX_DPRIIND_STEEPQSTART, 
    DPriIndDevex       = CPX_DPRIIND_DEVEX 
  };

  enum BranchDirection {
    BranchGlobal = CPX_BRANCH_GLOBAL, 
    BranchDown   = CPX_BRANCH_DOWN, 
    BranchUp     = CPX_BRANCH_UP 
  };

  typedef IloArray<BranchDirection> BranchDirectionArray;

  enum Algorithm {
    NoAlg      = CPX_ALG_NONE, 
    AutoAlg    = CPX_ALG_AUTOMATIC, 
    Primal     = CPX_ALG_PRIMAL, 
    Dual       = CPX_ALG_DUAL, 
    Barrier    = CPX_ALG_BARRIER, 
    Sifting    = CPX_ALG_SIFTING, 
    Concurrent = CPX_ALG_CONCURRENT, 
    Network    = CPX_ALG_NET, 
    FeasOpt    = CPX_ALG_FEASOPT, 
    MIP        = CPX_ALG_MIP  
  };


  enum Relaxation {
    MinSum  = CPX_FEASOPT_MIN_SUM,    
    OptSum  = CPX_FEASOPT_OPT_SUM,   
    MinInf  = CPX_FEASOPT_MIN_INF,  
    OptInf  = CPX_FEASOPT_OPT_INF,   
    MinQuad = CPX_FEASOPT_MIN_QUAD, 
    OptQuad = CPX_FEASOPT_OPT_QUAD 
  };

  enum CalcQCPDuals {
    QCPDualsNo         = CPX_QCPDUALS_NO,   
    QCPDualsIfPossible = CPX_QCPDUALS_IFPOSSIBLE, 
    QCPDualsForce      = CPX_QCPDUALS_FORCE  
  };

    enum BendersStrategyType {
       BendersOff         = CPX_BENDERSSTRATEGY_OFF,   
       BendersAuto        = CPX_BENDERSSTRATEGY_AUTO,  
       BendersUser        = CPX_BENDERSSTRATEGY_USER,  
       BendersWorkers     = CPX_BENDERSSTRATEGY_WORKERS,
       BendersFull        = CPX_BENDERSSTRATEGY_FULL   
    };

   static const char * BendersAnnotation;
  enum CplexStatus {
    Unknown         = 0,
    Optimal         = CPX_STAT_OPTIMAL, 
    Unbounded       = CPX_STAT_UNBOUNDED, 
    Infeasible      = CPX_STAT_INFEASIBLE, 
    InfOrUnbd       = CPX_STAT_INForUNBD, 
    OptimalInfeas   = CPX_STAT_OPTIMAL_INFEAS, 
    NumBest         = CPX_STAT_NUM_BEST, 
    FeasibleRelaxedSum = CPX_STAT_FEASIBLE_RELAXED_SUM, 
    OptimalRelaxedSum  = CPX_STAT_OPTIMAL_RELAXED_SUM, 
    FeasibleRelaxedInf = CPX_STAT_FEASIBLE_RELAXED_INF, 
    OptimalRelaxedInf     = CPX_STAT_OPTIMAL_RELAXED_INF, 
    FeasibleRelaxedQuad   = CPX_STAT_FEASIBLE_RELAXED_QUAD, 
    OptimalRelaxedQuad    = CPX_STAT_OPTIMAL_RELAXED_QUAD, 
    AbortRelaxed          = CPXMIP_ABORT_RELAXED, 
    AbortObjLim           = CPX_STAT_ABORT_OBJ_LIM, 
    AbortPrimObjLim       = CPX_STAT_ABORT_PRIM_OBJ_LIM, 
    AbortDualObjLim       = CPX_STAT_ABORT_DUAL_OBJ_LIM, 
    AbortItLim            = CPX_STAT_ABORT_IT_LIM, 
    AbortTimeLim          = CPX_STAT_ABORT_TIME_LIM, 
    AbortDetTimeLim       = CPX_STAT_ABORT_DETTIME_LIM, 
    AbortUser       = CPX_STAT_ABORT_USER, 

    OptimalFaceUnbounded  = CPX_STAT_OPTIMAL_FACE_UNBOUNDED, 

    OptimalTol            = CPXMIP_OPTIMAL_TOL, 
    SolLim                = CPXMIP_SOL_LIM, 
    PopulateSolLim        = CPXMIP_POPULATESOL_LIM, 
    NodeLimFeas           = CPXMIP_NODE_LIM_FEAS, 
    NodeLimInfeas         = CPXMIP_NODE_LIM_INFEAS, 
    FailFeas              = CPXMIP_FAIL_FEAS, 
    FailInfeas            = CPXMIP_FAIL_INFEAS, 
    MemLimFeas            = CPXMIP_MEM_LIM_FEAS, 
    MemLimInfeas          = CPXMIP_MEM_LIM_INFEAS, 
    FailFeasNoTree        = CPXMIP_FAIL_FEAS_NO_TREE, 
    FailInfeasNoTree      = CPXMIP_FAIL_INFEAS_NO_TREE, 
    ConflictFeasible      = CPX_STAT_CONFLICT_FEASIBLE, 
    ConflictMinimal       = CPX_STAT_CONFLICT_MINIMAL, 
    ConflictAbortContradiction = CPX_STAT_CONFLICT_ABORT_CONTRADICTION, 
    ConflictAbortTimeLim  = CPX_STAT_CONFLICT_ABORT_TIME_LIM, 
    ConflictAbortDetTimeLim = CPX_STAT_CONFLICT_ABORT_DETTIME_LIM, 
    ConflictAbortItLim    = CPX_STAT_CONFLICT_ABORT_IT_LIM, 
    ConflictAbortNodeLim  = CPX_STAT_CONFLICT_ABORT_NODE_LIM, 
    ConflictAbortObjLim   = CPX_STAT_CONFLICT_ABORT_OBJ_LIM, 
    ConflictAbortMemLim   = CPX_STAT_CONFLICT_ABORT_MEM_LIM, 
    ConflictAbortUser     = CPX_STAT_CONFLICT_ABORT_USER, 
    Feasible              = CPX_STAT_FEASIBLE, 
    OptimalPopulated      = CPXMIP_OPTIMAL_POPULATED, 
    OptimalPopulatedTol   = CPXMIP_OPTIMAL_POPULATED_TOL, 
    RelaxationUnbounded   = CPXMIP_ABORT_RELAXATION_UNBOUNDED, 
    FirstOrder            = CPX_STAT_FIRSTORDER 
  };
  typedef CplexStatus Status;

  IloAlgorithm::Status getStatus() const;

  CplexStatus     getCplexStatus() const;

  CplexStatus     getCplexSubStatus() const;

  IloBool         isPrimalFeasible() const;

  IloBool         isDualFeasible() const;

  Algorithm       getAlgorithm() const;

  Algorithm       getSubAlgorithm() const;

  enum DeleteMode {
    LeaveBasis, 
    FixBasis
  };

  void       setDeleteMode(DeleteMode mode);

  DeleteMode getDeleteMode() const;

  IloBool feasOpt(const IloRangeArray  rngs,
                  const IloNumArray    rnglb,
                  const IloNumArray    rngub,
                  const IloNumVarArray vars,
                  const IloNumArray    varlb,
                  const IloNumArray    varub);

  IloBool feasOpt(const IloRangeArray  rngs,
                  const IloNumArray    rnglb,
                  const IloNumArray    rngub,
                  const IloIntVarArray vars,
                  const IloNumArray    varlb,
                  const IloNumArray    varub);

  IloBool feasOpt(const IloNumVarArray vars, const IloNumArray varlb,
                                             const IloNumArray varub);
  IloBool feasOpt(const IloIntVarArray vars,
                  const IloNumArray    varlb,
                  const IloNumArray    varub);

  IloBool feasOpt(const IloRangeArray rngs,
                  const IloNumArray   rnglb,
                  const IloNumArray   rngub);

  IloBool feasOpt(const IloConstraintArray cts,
                  const IloNumArray        prefs);

#ifndef ILOG_CPLEX_NO_REMOTE_API
  FeasOptHandle feasOpt(const IloRangeArray  rngs,
                        const IloNumArray    rnglb,
                        const IloNumArray    rngub,
                        const IloNumVarArray vars,
                        const IloNumArray    varlb,
                        const IloNumArray    varub,
                        bool async);

  FeasOptHandle feasOpt(const IloRangeArray  rngs,
                        const IloNumArray    rnglb,
                        const IloNumArray    rngub,
                        const IloIntVarArray vars,
                        const IloNumArray    varlb,
                        const IloNumArray    varub,
                        bool async);

  FeasOptHandle feasOpt(const IloNumVarArray vars, const IloNumArray varlb,
                        const IloNumArray varub, bool async);

  FeasOptHandle feasOpt(const IloIntVarArray vars,
                        const IloNumArray    varlb,
                        const IloNumArray    varub,
                        bool async);

  FeasOptHandle feasOpt(const IloRangeArray rngs,
                        const IloNumArray   rnglb,
                        const IloNumArray   rngub,
                        bool async);

  FeasOptHandle feasOpt(const IloConstraintArray cts,
                        const IloNumArray        prefs,
                        bool async);
#endif // !ILOG_CPLEX_NO_REMOTE_API

  IloBool populate();
#ifndef ILOG_CPLEX_NO_REMOTE_API
  class PopulateHandleI : public AsyncHandleI {
  public:
    virtual IloBool joinPopulate() = 0;
  };
  class PopulateHandle : public AsyncHandle {
  public:
    PopulateHandle(PopulateHandleI *i = 0) : AsyncHandle(i) {}
    IloBool joinPopulate();
  };
  PopulateHandle populate(bool async);
#endif

  enum TuningStatus {
     TuningComplete   = 0,
     TuningAbort      = CPX_TUNE_ABORT,
     TuningTimeLim    = CPX_TUNE_TILIM,
     TuningDetTimeLim = CPX_TUNE_DETTILIM
  };

  IloInt  tuneParam(IloArray<const char *> filename,
                    IloCplex::ParameterSet fixedset);

  IloInt  tuneParam();
  IloInt  tuneParam(IloCplex::ParameterSet fixedset);
#ifndef ILOG_CPLEX_NO_REMOTE_API
  class TuneParamHandleI : public AsyncHandleI {
  public:
    virtual IloInt joinTuneParam() = 0;
  };
  class TuneParamHandle : public AsyncHandle {
  public:
    TuneParamHandle(TuneParamHandleI *i = 0) : AsyncHandle(i) {}
    IloInt joinTuneParam();
  };
  TuneParamHandle tuneParam(bool async);
  TuneParamHandle tuneParam(IloCplex::ParameterSet fixedset, bool async);
#endif // !ILOG_CPLEX_NO_REMOTE_API
  IloInt  tuneParam(IloArray<const char *> filename);

  enum ConflictStatus {
     ConflictExcluded       = CPX_CONFLICT_EXCLUDED,
     ConflictPossibleMember = CPX_CONFLICT_POSSIBLE_MEMBER,
     ConflictMember         = CPX_CONFLICT_MEMBER
  };

  typedef IloArray<ConflictStatus> ConflictStatusArray;

  IloBool refineConflict(IloConstraintArray cons, IloNumArray prefs);
#ifndef ILOG_CPLEX_NO_REMOTE_API
  class RefineConflictHandleI : public AsyncHandleI {
  public:
    virtual IloBool joinRefineConflict() = 0;
  };
  class RefineConflictHandle : public AsyncHandle {
  public:
    RefineConflictHandle(RefineConflictHandleI *i = 0) : AsyncHandle(i) {}
    IloBool joinRefineConflict();
  };
  RefineConflictHandle refineConflict(IloConstraintArray cons, IloNumArray prefs, bool async);
#endif // !ILOG_CPLEX_NO_REMOTE_API

  IloBool refineMIPStartConflict(IloInt mipstartindex, IloConstraintArray cons, IloNumArray prefs);
#ifndef ILOG_CPLEX_NO_REMOTE_API
  class RefineMIPStartConflictHandleI : public AsyncHandleI {
  public:
    virtual IloBool joinRefineMIPStartConflict() = 0;
  };
  class RefineMIPStartConflictHandle : public AsyncHandle {
  public:
    RefineMIPStartConflictHandle(RefineMIPStartConflictHandleI *i = 0) : AsyncHandle(i) {}
    IloBool joinRefineMIPStartConflict();
  };
  RefineMIPStartConflictHandle refineMIPStartConflict(IloInt mipstartindex, IloConstraintArray cons, IloNumArray prefs, bool async);
#endif // !ILOG_CPLEX_NO_REMOTE_API

  ConflictStatusArray getConflict(IloConstraintArray cons) const;

  ConflictStatus getConflict(IloConstraint con) const;


  void getDnorms(IloNumArray dnorms, const IloNumVarArray vars,
                                     const IloRangeArray  cons) const;
  void getPnorms(IloNumArray cnorms, const IloNumVarArray vars,
                 IloNumArray rnorms, const IloRangeArray  cons) const;
  void setDnorms(const IloNumArray norms, const IloNumVarArray vars,
                                          const IloRangeArray  cons);
  void setPnorms(const IloNumArray cnorms, const IloNumVarArray vars,
                 const IloNumArray rnorms, const IloRangeArray  cons);
  void getDnorms(IloNumArray dnorms, const IloIntVarArray vars,
                                     const IloRangeArray  cons) const;
  void getPnorms(IloNumArray cnorms, const IloIntVarArray vars,
                 IloNumArray rnorms, const IloRangeArray  cons) const;
  void setDnorms(const IloNumArray norms, const IloIntVarArray vars,
                                          const IloRangeArray  cons);
  void setPnorms(const IloNumArray cnorms, const IloIntVarArray vars,
                 const IloNumArray rnorms, const IloRangeArray  cons);

  enum Quality {
    MaxPrimalInfeas         = CPX_MAX_PRIMAL_INFEAS, 
    MaxScaledPrimalInfeas   = CPX_MAX_SCALED_PRIMAL_INFEAS, 
    SumPrimalInfeas         = CPX_SUM_PRIMAL_INFEAS, 
    SumScaledPrimalInfeas   = CPX_SUM_SCALED_PRIMAL_INFEAS, 
    MaxDualInfeas           = CPX_MAX_DUAL_INFEAS, 
    MaxScaledDualInfeas     = CPX_MAX_SCALED_DUAL_INFEAS, 
    SumDualInfeas           = CPX_SUM_DUAL_INFEAS, 
    SumScaledDualInfeas     = CPX_SUM_SCALED_DUAL_INFEAS, 
    MaxIntInfeas            = CPX_MAX_INT_INFEAS, 
    SumIntInfeas            = CPX_SUM_INT_INFEAS, 
    MaxPrimalResidual       = CPX_MAX_PRIMAL_RESIDUAL, 
    MaxScaledPrimalResidual = CPX_MAX_SCALED_PRIMAL_RESIDUAL, 
    SumPrimalResidual       = CPX_SUM_PRIMAL_RESIDUAL, 
    SumScaledPrimalResidual = CPX_SUM_SCALED_PRIMAL_RESIDUAL, 
    MaxDualResidual         = CPX_MAX_DUAL_RESIDUAL, 
    MaxScaledDualResidual   = CPX_MAX_SCALED_DUAL_RESIDUAL, 
    SumDualResidual         = CPX_SUM_DUAL_RESIDUAL, 
    SumScaledDualResidual   = CPX_SUM_SCALED_DUAL_RESIDUAL, 
    MaxCompSlack            = CPX_MAX_COMP_SLACK, 
    SumCompSlack            = CPX_SUM_COMP_SLACK, 
    MaxX                    = CPX_MAX_X, 
    MaxScaledX              = CPX_MAX_SCALED_X, 
    MaxPi                   = CPX_MAX_PI, 
    MaxScaledPi             = CPX_MAX_SCALED_PI, 
    MaxSlack                = CPX_MAX_SLACK, 
    MaxScaledSlack          = CPX_MAX_SCALED_SLACK, 
    MaxRedCost              = CPX_MAX_RED_COST, 
    MaxScaledRedCost        = CPX_MAX_SCALED_RED_COST, 
    SumX                    = CPX_SUM_X, 
    SumScaledX              = CPX_SUM_SCALED_X, 
    SumPi                   = CPX_SUM_PI, 
    SumScaledPi             = CPX_SUM_SCALED_PI, 
    SumSlack                = CPX_SUM_SLACK, 
    SumScaledSlack          = CPX_SUM_SCALED_SLACK, 
    SumRedCost              = CPX_SUM_RED_COST, 
    SumScaledRedCost        = CPX_SUM_SCALED_RED_COST, 
    Kappa                   = CPX_KAPPA, 
    ObjGap                  = CPX_OBJ_GAP, 
    DualObj                 = CPX_DUAL_OBJ, 
    PrimalObj               = CPX_PRIMAL_OBJ, 
    ExactKappa              = CPX_EXACT_KAPPA, 
    KappaStable             = CPX_KAPPA_STABLE, 
    KappaSuspicious         = CPX_KAPPA_SUSPICIOUS, 
    KappaUnstable           = CPX_KAPPA_UNSTABLE, 
    KappaIllposed           = CPX_KAPPA_ILLPOSED, 
    KappaMax                = CPX_KAPPA_MAX, 
    KappaAttention          = CPX_KAPPA_ATTENTION 
  };


  IloNum getQuality(Quality q, IloNumVar*     var=0,
                               IloConstraint* rng=0) const;
  IloNum getQuality(Quality q, IloConstraint* rng,
                               IloNumVar*     var=0) const;


  IloNum getQuality(Quality q, IloInt         soln,
                               IloConstraint* rng,
                               IloNumVar*     var=0) const;
  IloNum getQuality(Quality q, IloInt         soln,
                               IloNumVar*     var=0,
                               IloConstraint* rng=0) const;

  void setPriority  (IloNumVar var, IloNum pri);

  void setPriority  (IloIntVar var, IloNum pri);

  void setPriorities(const IloNumVarArray var, const IloNumArray pri);

  void setPriorities(const IloIntVarArray var, const IloNumArray pri);

  void setDirection (IloNumVar var, BranchDirection dir);

  void setDirection (IloIntVar var, BranchDirection dir);

  void setDirections(const IloNumVarArray var,
                            const BranchDirectionArray dir);

  void setDirections(const IloIntVarArray var,
                            const BranchDirectionArray dir);

  void delPriority  (IloNumVar var);

  void delPriority  (IloIntVar var);

  void delPriorities(const IloNumVarArray var);

  void delPriorities(const IloIntVarArray var);

  void delDirection (IloNumVar var);

  void delDirection (IloIntVar var);

  void delDirections(const IloNumVarArray var);

  void delDirections(const IloIntVarArray var);

  IloNum          getPriority  (IloNumVar var) const;

  IloNum          getPriority  (IloIntVar var) const;

  BranchDirection getDirection (IloNumVar var) const;

  BranchDirection getDirection (IloIntVar var) const;

  void            getPriorities(IloNumArray          pri,
                                       const IloNumVarArray var) const;

  void            getPriorities(IloNumArray          pri,
                                       const IloIntVarArray var) const;

  void            getDirections(BranchDirectionArray dir,
                                       const IloNumVarArray var) const;
  void            getDirections(BranchDirectionArray dir,
                                       const IloIntVarArray var) const;

  void basicPresolve(const IloNumVarArray vars,
                            IloNumArray          redlb = 0,
                            IloNumArray          redub = 0,
                            const IloRangeArray  rngs = 0,
                            IloBoolArray         redundant = 0) const;

  void basicPresolve(const IloIntVarArray vars,
                            IloNumArray          redlb = 0,
                            IloNumArray          redub = 0,
                            const IloRangeArray  rngs = 0,
                            IloBoolArray         redundant = 0) const;

  void freePresolve();

  void presolve(IloCplex::Algorithm alg);

#ifndef ILOG_CPLEX_NO_REMOTE_API
  class PresolveHandleI : public AsyncHandleI {
  public:
  };
  class PresolveHandle : public AsyncHandle {
  public:
    PresolveHandle(PresolveHandleI *i = 0) : AsyncHandle(i) {}
    void joinPresolve() { join(); }
  };
  PresolveHandle presolve(IloCplex::Algorithm alg, bool async);
#endif // !ILOG_CPLEX_NO_REMOTE_API

  // advanced API for use with user-defined extractors.

  void use(IloLPExtractor* extr);

  IloExtractable getDiverging() const;

  void getRay(IloNumArray vals, IloNumVarArray vars) const;

  void getDualNorms(IloNumArray norms, const IloExprArray expr,
                           DualPricing dpriind = DPriIndAuto) const;
  void deleteDnorms();
  void deletePnorms();

  void getDriebeekPenalties(IloNumArray          downratio,
                                   IloNumArray          upratio,
                                   const IloNumVarArray ind) const;
  void getDriebeekPenalties(IloNumArray          downratio,
                                   IloNumArray          upratio,
                                   const IloIntVarArray ind) const;
  void getDriebeekPenalties(IloNumArray          downratio,
                                   IloNumArray          upratio,
                                   const IloRangeArray  ind) const;
  void getStrongBranch(IloNumArray          downratio,
                              IloNumArray          upratio,
                              const IloRangeArray  ind,
                              IloInt64             itlim) const;
  void getStrongBranch(IloNumArray          downratio,
                              IloNumArray          upratio,
                              const IloNumVarArray ind,
                              IloInt64             itlim) const;
  void getStrongBranch(IloNumArray          downratio,
                              IloNumArray          upratio,
                              const IloIntVarArray ind,
                              IloInt64             itlim) const;

  IloNum dualFarkas (IloConstraintArray rng, IloNumArray y);

  void qpIndefCertificate (IloNumVarArray var, IloNumArray x);

  void qpIndefCertificate (IloIntVarArray var, IloNumArray x);

  void protectVariables(const IloNumVarArray var);

  void protectVariables(const IloIntVarArray var);

  class Exception : public IloAlgorithm::Exception {
    IloInt _status;
  public:
    Exception(int status, const char* str)
      : IloAlgorithm::Exception(str), _status(status)      {}
    Exception& operator=(const Exception& cpy) {
      IloException::operator=(cpy);
      _status = cpy.getStatus();
      return *this;
    }

    IloInt getStatus() const                    { return (_status); }
  };

  class MultipleObjException : public Exception {
    IloObjective _obj;
  public:
    MultipleObjException(IloObjective obj)
      : IloCplex::Exception(-1, "MultipleObjException: IloCplex can not handle multiple objectives")
      , _obj(obj)                       {}
    IloObjective getObj() const               { return (_obj); }
  };

  class MultipleConversionException : public Exception {
    IloConversion  _conv;
    IloNumVarArray _var;
  public:
    MultipleConversionException(IloConversion conv,
                                const IloNumVarArray var)
      : IloCplex::Exception(-1,
        "MultipleConversionException: IloCplex can not handle multiple variable type conversions")
      , _conv(conv)
      , _var (var )                                   {}
    void addVar(const IloNumVar var)                  { _var.add(var); }

    IloConversion        getConversion() const        { return (_conv); }

    const IloNumVarArray getVariables() const         { return (_var); }
  };

  class UnknownExtractableException : public Exception {
    IloExtractable _ex;
  public:
    UnknownExtractableException(IloExtractable ex)
    : IloCplex::Exception(-1, "UnknownExtractableException: extractable is not known to IloCplex algorithm")
    , _ex(ex)                                 {}
    IloExtractable getExtractable() const       { return (_ex); }
  };

  class ExtractedConstraintException : public Exception {
    IloConstraint _con;
  public:
    ExtractedConstraintException(IloConstraintI *con=0)
      : IloCplex::Exception(-1, "ExtractedConstraintException: constraint already extracted")
      , _con(con)
      {}
    IloConstraint getConstraint() const        { return _con; }
  };


  class InvalidCutException : public Exception {
    IloConstraint _con;
  public:
    InvalidCutException(IloConstraintI *con=0)
      : IloCplex::Exception(-1, "InvalidCutException: invalid cut")
      , _con(con)
      {}
    IloConstraint getCut() const        { return _con; }
  };

  void flush();
  
  class Aborter {
    friend class IloCplex;
    friend class IloCplexI;
    friend class IloCplexAborterI;
    IloCplexAborterI* _impl;
   public:

    Aborter() : _impl(0) {}
    Aborter(IloEnv env);
    Aborter(const Aborter& copy) : _impl(copy._impl) {}
    Aborter(IloCplexAborterI* impl) : _impl(impl) {}
    IloCplexAborterI* getImpl() const {return _impl;}

    void      abort();

    void      clear();

    IloBool   isAborted() const;
    void      end();
  };


  IloCplex::Aborter use(IloCplex::Aborter abort);
  IloCplex::Aborter getAborter();
  void  remove(IloCplex::Aborter abort);

  class CallbackI;
  class GoalI;
  class GoalBaseI;

  class Callback {
    CallbackI* _impl;
  public:

    Callback(CallbackI* impl=0) : _impl(impl)   {}

    void end();

    enum Type {
      Presolve          = 0,
      Simplex           = 1,
      Barrier           = 2,
      Crossover         = 3,
      Network           = 4,
      MIP               = 5,
      Probing           = 6,
      FractionalCut     = 7,
      DisjunctiveCut    = 8,
      Branch            = 9,
      UserCut           = 10,
      Node              = 11,
      Heuristic         = 12,
      Incumbent         = 13,
      Solve             = 14,
      FlowMIRCut        = 15,
      Continuous        = 16,
      MIPInfo           = 17,
      ProbingInfo       = 18,
      FractionalCutInfo = 19,
      DisjunctiveCutInfo= 20,
      FlowMIRCutInfo    = 21,
      Tuning            = 22,
      LazyConstraint    = 23,
      _Number           = 24    // don't document; just name for last one
    };

    Type       getType() const;

    CallbackI* getImpl() const          { return (_impl); }
  };

  class CallbackI {
    friend class Callback;
    friend class IloCplexI;
    friend class IloCallbackManager;
    friend class IloCplexCallbackManager;
    void calldelete();

    CallbackI*          _next;
  public:
    IloCallbackManager* _cbmgr;

    IloEnvI* _env;

    /* We always allocate callback objects in the IloEnv, so we need
     * to overload the delete operator to return the memory correctly.
     */
    void operator delete (void *, size_t);
#if defined (ILODELETEOPERATOR)         /* needed for some platforms */
    void operator delete(void*, const IloEnvI*) {}
    void operator delete(void*, const IloEnv&) {}
#endif
    IloNamedPropertySetI* getProperties() const;
    IloNamedPropertyI* getProperty(const char*) const;
    IloBool hasProperty(const char *) const;
  protected:
    CallbackI(IloEnv env);

    // documented API
    typedef Callback::Type Type;

    virtual void       main() = 0;   // to be implemented by user-classes

    virtual CallbackI* duplicateCallback () const = 0;

  public:
    void     abort();

    IloEnv   getEnv() const { return _env; }


    IloNum getCplexTime() const;

    IloNum getDetTime() const;

    IloNum getStartTime() const;

    IloNum getStartDetTime() const;

    IloNum getEndTime() const;

    IloNum getEndDetTime() const;

  public:
    virtual Callback::Type getType() const = 0;
    virtual ~CallbackI();
  };

  class TuningCallbackI : public CallbackI {
    Callback::Type getType() const;
  protected:
    TuningCallbackI(IloEnv env) : CallbackI(env)       {}

  public:
    IloNum  getProgress() const;
  };


  class OptimizationCallbackI : public CallbackI {
  protected:
    OptimizationCallbackI(IloEnv env) : CallbackI(env) {}
  public:
    IloModel getModel() const;

    IloInt   getNcols() const;

    IloInt   getNrows() const;

    IloInt   getNQCs() const;
  };

  class CPXDEPRECATED(12070100) PresolveCallbackI : public OptimizationCallbackI {
    Callback::Type getType() const;
  protected:

    CPXDEPRECATED(12070100) PresolveCallbackI(IloEnv env) : OptimizationCallbackI(env) {}

  public:
    CPXDEPRECATED(12070100) IloInt getNremovedRows() const;

    CPXDEPRECATED(12070100) IloInt getNremovedCols() const;

    CPXDEPRECATED(12070100) IloInt64 getNaggregations64() const;

    CPXDEPRECATED(12070100) IloInt getNaggregations() const;

    CPXDEPRECATED(12070100) IloInt64 getNmodifiedCoeffs64() const;

    CPXDEPRECATED(12070100) IloInt getNmodifiedCoeffs() const;
  };

  class ContinuousCallbackI : public OptimizationCallbackI {
    Callback::Type getType() const;
  protected:

    ContinuousCallbackI(IloEnv env) : OptimizationCallbackI(env) {}

  public:
    IloNum  getObjValue() const;

    IloNum  getInfeasibility() const;

    IloNum  getDualInfeasibility() const;

    IloBool isFeasible() const;

    IloBool isDualFeasible() const;

    IloInt64  getNiterations64() const;

    IloInt  getNiterations() const;
  };
  typedef ContinuousCallbackI LPCallbackI;

  class BarrierCallbackI : public ContinuousCallbackI {
    Callback::Type getType() const;
    BarrierCallbackI(const ContinuousCallbackI& lp) :ContinuousCallbackI(lp) {}
  protected:

    BarrierCallbackI(IloEnv env) : ContinuousCallbackI(env) {}

  public:
    IloNum  getDualObjValue() const;
  };

  class SimplexCallbackI : public ContinuousCallbackI {
    Callback::Type getType() const;
    SimplexCallbackI(const ContinuousCallbackI& lp) :ContinuousCallbackI(lp) {}
  protected:

    SimplexCallbackI(IloEnv env) : ContinuousCallbackI(env) {}
  };


  class CrossoverCallbackI : public OptimizationCallbackI {
    Callback::Type getType() const;
  protected:
    CrossoverCallbackI(IloEnv env) : OptimizationCallbackI(env) {}

  public:
    IloInt64  getNprimalPushes64() const;

    IloInt  getNprimalPushes() const;

    IloInt64  getNprimalExchanges64() const;

    IloInt  getNprimalExchanges() const;

    IloInt64  getNdualPushes64() const;

    IloInt  getNdualPushes() const;

    IloInt64  getNdualExchanges64() const;

    IloInt  getNdualExchanges() const;

    IloInt  getNsuperbasics() const;
  };

  class NetworkCallbackI : public OptimizationCallbackI {
    Callback::Type getType() const;
  protected:
    NetworkCallbackI(IloEnv env) : OptimizationCallbackI(env) {}

  public:
    IloNum  getObjValue() const;

    IloNum  getInfeasibility() const;

    IloBool isFeasible() const;

    IloInt64  getNiterations64() const;

    IloInt  getNiterations() const;
  };

  class MIPInfoCallbackI : public OptimizationCallbackI {
    Callback::Type getType() const;
    void doGetIncumbentValues (IloNumArray val,
                               const IloNumVarArray vars) const;
    void doGetIncumbentValues (IloNumArray val,
                               const IloIntVarArray vars) const;
    void doGetIncumbentSlacks (IloNumArray val,
                               const IloRangeArray cons) const;
    void doGetIncumbentSlacks (IloNumArray val,
                               const IloForAllRangeArray cons) const;

  protected:
    MIPInfoCallbackI(IloEnv env) : OptimizationCallbackI(env) {}

  public:
    IloNum  getBestObjValue() const;

    IloNum getMIPRelativeGap() const;

    IloNum  getIncumbentObjValue() const;

    IloNum  getIncumbentValue(const IloNumVar var) const;

    IloNum  getIncumbentValue(const IloIntVar var) const {
       return  getIncumbentValue(IloNumVar(var.getImpl()));
    }

    IloNum getIncumbentValue(const IloExprArg expr) const;

    void    getIncumbentValues (IloNumArray val,
                                const IloNumVarArray vars) const {
       IloAssert (val.getImpl(), "array is not initialized");
       IloAssert (vars.getImpl(), "array is not initialized");
       doGetIncumbentValues(val, vars);
    }

    void    getIncumbentValues (IloNumArray val,
                                const IloIntVarArray vars) const {
       IloAssert (val.getImpl(), "array is not initialized");
       IloAssert (vars.getImpl(), "array is not initialized");
       doGetIncumbentValues(val, vars);
    }

    IloNum getIncumbentSlack(const IloRange rng) const;

    IloNum getIncumbentSlack(const IloForAllRange rng) const;

    void   getIncumbentSlacks(IloNumArray vals,
                              const IloRangeArray cons) const { 
       IloAssert (vals.getImpl(), "array is not initialized");
       IloAssert (cons.getImpl(), "array is not initialized");
       doGetIncumbentSlacks(vals, cons);
    }

    void   getIncumbentSlacks(IloNumArray vals,
                              const IloForAllRangeArray cons) const { 
       IloAssert (vals.getImpl(), "array is not initialized");
       IloAssert (cons.getImpl(), "array is not initialized");
       doGetIncumbentSlacks(vals, cons);
    }

    IloInt getNcuts(IloCplex::CutType which) const;

    IloInt  getMyThreadNum() const;

    IloBool hasIncumbent() const;

    IloInt64  getNnodes64() const;

    IloInt  getNnodes() const;

    IloInt64  getNremainingNodes64() const;

    IloInt  getNremainingNodes() const;

    IloInt64  getNiterations64() const;

    IloInt  getNiterations() const;

    IloNum  getCutoff() const;


    BranchDirection getDirection(const IloNumVar var) const;

    BranchDirection getDirection(const IloIntVar var) const {
       return getDirection(IloNumVar(var.getImpl()));
    }

    IloNum  getPriority(const IloNumVar sos) const;

    IloNum  getPriority(const IloIntVar sos) const {
       return  getPriority(IloNumVar(sos.getImpl()));
    }

    IloNum  getQuality(IloCplex::Quality q) const;
  };

  class ProbingInfoCallbackI : public MIPInfoCallbackI {
    Callback::Type getType() const;
  protected:
    ProbingInfoCallbackI(IloEnv env) : MIPInfoCallbackI(env)  {}

  public:
    IloInt  getPhase() const;

    IloNum  getProgress() const;
  };

  class FractionalCutInfoCallbackI : public MIPInfoCallbackI {
    Callback::Type getType() const;
  protected:
    FractionalCutInfoCallbackI(IloEnv env) : MIPInfoCallbackI(env)    {}

  public:
    IloNum  getProgress() const;
  };

  class FlowMIRCutInfoCallbackI : public MIPInfoCallbackI {
    Callback::Type getType() const;
  protected:
    FlowMIRCutInfoCallbackI(IloEnv env) : MIPInfoCallbackI(env)       {}

  public:
    IloNum  getProgress() const;
  };

  class DisjunctiveCutInfoCallbackI : public MIPInfoCallbackI {
    Callback::Type getType() const;
  protected:
    DisjunctiveCutInfoCallbackI(IloEnv env) : MIPInfoCallbackI(env)   {}

  public:
    IloNum  getProgress() const;
  };

  class MIPCallbackI : public MIPInfoCallbackI {
    Callback::Type getType() const;
    void doGetObjCoefs(IloNumArray val, const IloNumVarArray vars) const;
    void doGetObjCoefs(IloNumArray val, const IloIntVarArray vars) const;

  public:
    class NodeData {
      protected:
         NodeData() {}
      public:
        virtual ~NodeData() {}

        virtual IloAny getDataType() const { return 0; }

    };

    struct NodeId {
      CPXLONG _id;
      int operator==(const NodeId& nodeid) const {
         return ( nodeid._id == _id);
      }

      int operator!=(const NodeId& nodeid) const {
         return ( nodeid._id != _id);
      }
    };

  protected:
    MIPCallbackI(IloEnv env) : MIPInfoCallbackI(env) {}

  public:
    IloInt  getUserThreads() const;

    IloNum getObjCoef (const IloNumVar var) const;

    IloNum getObjCoef (const IloIntVar var) const {
       return getObjCoef (IloNumVar(var.getImpl()));
    }

    void   getObjCoefs(IloNumArray val, const IloNumVarArray vars) const {
      IloAssert(val.getImpl(), "array not initialized");
      IloAssert(vars.getImpl(), "array not initialized");
      doGetObjCoefs(val, vars);
    }

    void   getObjCoefs(IloNumArray val, const IloIntVarArray vars) const {
      IloAssert(val.getImpl(), "array not initialized");
      IloAssert(vars.getImpl(), "array not initialized");
      doGetObjCoefs(val, vars);
    }

  };


  class ProbingCallbackI : public MIPCallbackI {
    Callback::Type getType() const;
  protected:
    ProbingCallbackI(IloEnv env) : MIPCallbackI(env)  {}

  public:
    IloInt  getPhase() const;

    IloNum  getProgress() const;
  };

  class FractionalCutCallbackI : public MIPCallbackI {
    Callback::Type getType() const;
  protected:
    FractionalCutCallbackI(IloEnv env) : MIPCallbackI(env)    {}

  public:
    IloNum  getProgress() const;
  };

  class FlowMIRCutCallbackI : public MIPCallbackI {
    Callback::Type getType() const;
  protected:
    FlowMIRCutCallbackI(IloEnv env) : MIPCallbackI(env)       {}

  public:
    IloNum  getProgress() const;
  };

  class DisjunctiveCutCallbackI : public MIPCallbackI {
    Callback::Type getType() const;
  protected:
    DisjunctiveCutCallbackI(IloEnv env) : MIPCallbackI(env)   {}

  public:
    IloNum  getProgress() const;
  };

  class IncumbentCallbackI : public MIPCallbackI {
    friend class GoalI;
    friend class CpxSolutionGoalI;
    friend class CpxNodeI;

    void doGetValues (IloNumArray val, const IloNumVarArray vars) const;
    void doGetValues (IloNumArray val, const IloIntVarArray vars) const;
    Callback::Type getType() const;
  protected:
    IncumbentCallbackI(IloEnv env) : MIPCallbackI(env)     {}

  public:
    enum SolutionSource {
      NodeSolution      = CPX_CALLBACK_MIP_INCUMBENT_NODESOLN,
      HeuristicSolution = CPX_CALLBACK_MIP_INCUMBENT_HEURSOLN,
      UserSolution      = CPX_CALLBACK_MIP_INCUMBENT_USERSOLN,
      MIPStartSolution  = CPX_CALLBACK_MIP_INCUMBENT_MIPSTART
    };

    SolutionSource getSolutionSource() const;

    IloNum getObjValue() const;

    IloNum getValue(const IloExprArg expr) const;

    IloNum getValue(const IloNumVar var) const;

    IloNum getValue(const IloIntVar var) const {
       return getValue(IloNumVar(var.getImpl()));
    }

    IloNum getSlack(const IloRange rng) const;

    void   getSlacks (IloNumArray val, const IloRangeArray con) const;

    NodeId getNodeId() const;

    NodeData  *getNodeData() const;

    NodeData *setNodeData(NodeData *data);

    void getValues (IloNumArray val, const IloNumVarArray vars) const {
      IloAssert(val.getImpl(), "array not initialized");
      IloAssert(vars.getImpl(), "array not initialized");
      doGetValues(val, vars);
    }

    void getValues (IloNumArray val, const IloIntVarArray vars) const {
      IloAssert(val.getImpl(), "array not initialized");
      IloAssert(vars.getImpl(), "array not initialized");
      doGetValues(val, vars);
    }

    void reject();
  };

  class NodeCallbackI : public MIPCallbackI {
    friend class NodeEvaluatorI;
    Callback::Type getType() const;

  protected:
    NodeCallbackI(IloEnv env) : MIPCallbackI(env)     {}

  public:

    NodeId getNodeId(IloInt64 node) const;

    IloNum getObjValue(IloInt64 node) const;

    IloNum getEstimatedObjValue(IloInt64 node) const;

    IloInt getDepth(IloInt64 node) const;

    IloNum getInfeasibilitySum(IloInt64 node) const;

    IloInt getNinfeasibilities(IloInt64 node) const;

    NodeData  *getNodeData(IloInt64 node) const;

    NodeData *setNodeData(IloInt64 node, NodeData *data);

    void selectNode(IloInt64 node);

    IloNumVar getBranchVar(IloInt64 node) const;

    IloInt64 getNodeNumber64(NodeId nodeid) const;

    IloInt getNodeNumber(NodeId nodeid) const;

    IloNum getObjValue(NodeId nodeid) const;

    IloNum getEstimatedObjValue(NodeId nodeid) const;

    IloInt getDepth(NodeId nodeid) const;

    IloNum getInfeasibilitySum(NodeId nodeid) const;

    IloInt getNinfeasibilities(NodeId nodeid) const;

    NodeData  *getNodeData(NodeId nodeid) const;

    void selectNode(NodeId nodeid);

    IloNumVar getBranchVar(NodeId nodeid) const;
  };

  class ControlCallbackI : public MIPCallbackI {
  public:
    class PresolvedVariableException : public Exception {
      IloNumVarArray _vars;
      void doGetPresolvedVariables(IloNumVarArray vars) const;
    public:
      PresolvedVariableException(IloEnv env)
        : Exception(-2,
       "Callback attempted operation on variable that has been presolved out"),
       _vars(env) {}
      void addVar(const IloNumVar var)                   { _vars.add(var); }

      void getPresolvedVariables(IloNumVarArray vars) const {
        IloAssert(vars.getImpl() != 0,
                  "IloNumVarArray accessed through 0 handle");
        doGetPresolvedVariables(vars);
      }

      void end();
    };

    enum IntegerFeasibility {
      ImpliedInfeasible = -1, 
      Feasible          =  CPX_INTEGER_FEASIBLE, 
      Infeasible        =  CPX_INTEGER_INFEASIBLE, 
      ImpliedFeasible   =  CPX_IMPLIED_INTEGER_FEASIBLE 
    };

    typedef IloArray<IntegerFeasibility> IntegerFeasibilityArray;

  private:
    void doGetFeasibilities(IntegerFeasibilityArray stat,
                            const IloNumVarArray var) const;
    void doGetFeasibilities(IntegerFeasibilityArray stat,
                            const IloIntVarArray var) const;
    void doGetLbs(IloNumArray val, const IloNumVarArray vars) const;
    void doGetLbs(IloNumArray val, const IloIntVarArray vars) const;
    void doGetUbs(IloNumArray val, const IloNumVarArray vars) const;
    void doGetUbs(IloNumArray val, const IloIntVarArray vars) const;
    void doGetValues (IloNumArray val, const IloNumVarArray vars) const;
    void doGetValues (IloNumArray val, const IloIntVarArray vars) const;
    void doGetSlacks (IloNumArray val, const IloRangeArray con) const;

  protected:
    ControlCallbackI(IloEnv env) : MIPCallbackI(env)  {}

  public:
    NodeId     getNodeId() const;

    IntegerFeasibility getFeasibility(const IloSOS1 sos) const;

    IntegerFeasibility getFeasibility(const IloSOS2 sos) const;

    IntegerFeasibility getFeasibility(const IloNumVar var) const;

    IntegerFeasibility getFeasibility(const IloIntVar var) const {
       return getFeasibility(IloNumVar(var.getImpl()));
    }

    void getFeasibilities(IntegerFeasibilityArray stat,
                          const IloNumVarArray var) const {
      IloAssert (stat.getImpl(), "array is not initialized");
      IloAssert (var.getImpl(), "array is not initialized");
      doGetFeasibilities(stat, var);
    }

    void getFeasibilities(IntegerFeasibilityArray stat,
                          const IloIntVarArray var) const {
      IloAssert (stat.getImpl(), "array is not initialized");
      IloAssert (var.getImpl(), "array is not initialized");
      doGetFeasibilities(stat, var);
    }

    IloBool isSOSFeasible(const IloSOS1 sos1) const;

    IloBool isSOSFeasible(const IloSOS2 sos2) const;

    IloNum getLB (const IloNumVar var) const;

    IloNum getLB (const IloIntVar var) const {
       return getLB(IloNumVar(var.getImpl()));
    }

    IloNum getUB (const IloNumVar var) const;

    IloNum getUB (const IloIntVar var) const {
       return getUB(IloNumVar(var.getImpl()));
    }

    void   getLBs(IloNumArray val, const IloNumVarArray vars) const {
      IloAssert(val.getImpl(), "array not initialized");
      IloAssert(vars.getImpl(), "array not initialized");
      doGetLbs(val, vars);
    }

    void   getLBs(IloNumArray val, const IloIntVarArray vars) const {
      IloAssert(val.getImpl(), "array not initialized");
      IloAssert(vars.getImpl(), "array not initialized");
      doGetLbs(val, vars);
    }

    void   getUBs(IloNumArray val, const IloNumVarArray vars) const {
      IloAssert(val.getImpl(), "array not initialized");
      IloAssert(vars.getImpl(), "array not initialized");
      doGetUbs(val, vars);
    }

    void   getUBs(IloNumArray val, const IloIntVarArray vars) const {
      IloAssert(val.getImpl(), "array not initialized");
      IloAssert(vars.getImpl(), "array not initialized");
      doGetUbs(val, vars);
    }

    IloNum getObjValue() const;


    IloNum getValue(const IloExprArg expr) const;

    IloNum getValue(const IloNumVar var) const;

    IloNum getValue(const IloIntVar var) const {
       return getValue(IloNumVar(var.getImpl()));
    }

    IloNum getSlack(const IloRange rng) const;

    void getValues (IloNumArray val, const IloNumVarArray vars) const {
      IloAssert(val.getImpl(), "array not initialized");
      IloAssert(vars.getImpl(), "array not initialized");
      doGetValues(val, vars);
    }

    void getValues (IloNumArray val, const IloIntVarArray vars) const {
      IloAssert(val.getImpl(), "array not initialized");
      IloAssert(vars.getImpl(), "array not initialized");
      doGetValues(val, vars);
    }

    void getSlacks (IloNumArray val, const IloRangeArray con) const {
      IloAssert(val.getImpl(), "array not initialized");
      IloAssert(con.getImpl(), "array not initialized");
      doGetSlacks(val, con);
    }

    IloNum getDownPseudoCost(const IloNumVar var) const;

    IloNum getDownPseudoCost(const IloIntVar var) const {
       return getDownPseudoCost(IloNumVar(var.getImpl()));
    }

    IloNum getUpPseudoCost(const IloNumVar var) const;

    IloNum getUpPseudoCost(const IloIntVar var) const {
       return getUpPseudoCost(IloNumVar(var.getImpl()));
    }

    NodeData *getNodeData() const;

    NodeData *setNodeData(NodeData *data);
  };

  class BranchCallbackI : public ControlCallbackI {
    friend class GoalI;
    friend class CpxBranchAsCplexI;
    friend class CpxSolutionGoalI;
    friend class CpxNodeI;
    Callback::Type getType() const;

    IloNum doGetBranch (IloNumVarArray       vars,
                        IloNumArray          bounds,
                        BranchDirectionArray dirs,
                        IloInt               i) const;
    NodeId doMakeBranch(const IloConstraintArray   ranges,
                        const IloNumVarArray       var,
                        const IloNumArray          bounds,
                        const BranchDirectionArray dirs,
                        IloNum                     objestimate,
                        NodeData                   *data = 0);
    NodeId doMakeBranch(const IloConstraintArray   ranges,
                        const IloIntVarArray       var,
                        const IloNumArray          bounds,
                        const BranchDirectionArray dirs,
                        IloNum                     objestimate,
                        NodeData                   *data = 0);
    NodeId doMakeBranch(const IloNumVarArray       var,
                        const IloNumArray          bounds,
                        const BranchDirectionArray dirs,
                        IloNum                     objestimate,
                        NodeData                   *data = 0);
    NodeId doMakeBranch(const IloIntVarArray       var,
                        const IloNumArray          bounds,
                        const BranchDirectionArray dirs,
                        IloNum                     objestimate,
                        NodeData                   *data = 0);
    NodeId doMakeBranch(const IloConstraintArray& rng,
                        IloNum               objestimate,
                        NodeData                *data = 0);

  public:
    enum BranchType {
      BranchOnVariable = CPX_TYPE_VAR, 
      BranchOnSOS1     = CPX_TYPE_SOS1, 
      BranchOnSOS2     = CPX_TYPE_SOS2, 
      BranchOnAny      = CPX_TYPE_ANY, 
      UserBranch       = CPX_TYPE_USER  
    };

  protected:
    BranchCallbackI(IloEnv env) : ControlCallbackI(env)       {}

  public:
    IloInt     getNbranches() const;

    BranchType getBranchType() const;

    IloNum getBranch(IloNumVarArray       vars,
                     IloNumArray          bounds,
                     BranchDirectionArray dirs,
                     IloInt               i) const {
      IloAssert(vars.getImpl(), "array not initialized");
      IloAssert(bounds.getImpl(), "array not initialized");
      IloAssert(dirs.getImpl(), "array not initialized");
      return doGetBranch(vars, bounds, dirs, i);
    }

    IloNum getBranch(IloRangeArray cuts, IloInt i) const;

    IloBool isIntegerFeasible() const;

    NodeId makeBranch(IloInt num, NodeData *data = 0);

    NodeId makeBranch(const IloNumVarArray       vars,
                      const IloNumArray          bounds,
                      const BranchDirectionArray dirs,
                      IloNum                     objestimate,
                      NodeData                   *data = 0) {
      IloAssert(vars.getImpl(), "array not initialized");
      IloAssert(bounds.getImpl(), "array not initialized");
      IloAssert(dirs.getImpl(), "array not initialized");
      return (doMakeBranch(vars, bounds, dirs, objestimate, data));
    }

    NodeId makeBranch(const IloIntVarArray       vars,
                      const IloNumArray          bounds,
                      const BranchDirectionArray dirs,
                      IloNum                     objestimate,
                      NodeData                   *data = 0) {
      IloAssert(vars.getImpl(), "array not initialized");
      IloAssert(bounds.getImpl(), "array not initialized");
      IloAssert(dirs.getImpl(), "array not initialized");
      return (doMakeBranch(vars, bounds, dirs, objestimate, data));
    }

    NodeId makeBranch(const IloNumVar var,
                      IloNum          bound,
                      BranchDirection dir,
                      IloNum          objestimate,
                      NodeData        *data = 0);

    NodeId makeBranch(const IloIntVar var,
                      IloNum          bound,
                      BranchDirection dir,
                      IloNum          objestimate,
                      NodeData        *data = 0) {
       return makeBranch(IloNumVar(var.getImpl()),
                         bound, dir, objestimate, data);
    }

    NodeId makeBranch(const IloConstraintArray cons,
                      IloNum                   objestimate,
                      NodeData                 *data = 0) {
      IloAssert(cons.getImpl(), "array not initialized");
      return (doMakeBranch(cons, objestimate, data));
    }

    NodeId makeBranch(const IloConstraint con,
                      IloNum              objestimate,
                      NodeData            *data = 0);

    NodeId makeBranch(const IloConstraintArray   cons,
                      const IloNumVarArray       vars,
                      const IloNumArray          bounds,
                      const BranchDirectionArray dirs,
                      IloNum                     objestimate,
                      NodeData                   *data = 0) {
      IloAssert(cons.getImpl(), "array not initialized");
      IloAssert(vars.getImpl(), "array not initialized");
      IloAssert(bounds.getImpl(), "array not initialized");
      IloAssert(dirs.getImpl(), "array not initialized");
      return (doMakeBranch(cons, vars, bounds, dirs, objestimate, data));
    }

    NodeId makeBranch(const IloConstraintArray   cons,
                      const IloIntVarArray       vars,
                      const IloNumArray          bounds,
                      const BranchDirectionArray dirs,
                      IloNum                     objestimate,
                      NodeData                   *data = 0) {
      IloAssert(cons.getImpl(), "array not initialized");
      IloAssert(vars.getImpl(), "array not initialized");
      IloAssert(bounds.getImpl(), "array not initialized");
      IloAssert(dirs.getImpl(), "array not initialized");
      return (doMakeBranch(cons, vars, bounds, dirs, objestimate, data));
    }

    void prune();
  };

  class HeuristicCallbackI : public ControlCallbackI {
    Callback::Type getType() const;
    void setSolution(const IloNumVarArray vars, const IloNumArray vals,
                     IloNum objval, IloBool set);
    void setSolution(const IloIntVarArray vars, const IloNumArray vals,
                     IloNum objval, IloBool set);
  protected:
    HeuristicCallbackI(IloEnv env) : ControlCallbackI(env)     {}

  public:
    void setBounds(const IloNumVar var, IloNum lb, IloNum ub);

    void setBounds(const IloIntVar var, IloNum lb, IloNum ub) {
       setBounds(IloNumVar(var.getImpl()), lb, ub);
    }

    void setBounds(const IloNumVarArray var, const IloNumArray lb,
                                             const IloNumArray ub);

    void setBounds(const IloIntVarArray var, const IloNumArray lb,
                   const IloNumArray ub);

    IloBool              solve(Algorithm alg = Dual);

    IloAlgorithm::Status getStatus() const;

    CplexStatus          getCplexStatus() const;

    IloBool              isPrimalFeasible() const;

    IloBool              isDualFeasible() const;

    void setSolution(const IloNumVarArray vars, const IloNumArray vals) {
      IloAssert(vars.getImpl(), "array not initialized");
      IloAssert(vals.getImpl(), "array not initialized");
      setSolution(vars, vals, 0.0, IloFalse);
    }

    void setSolution(const IloNumVarArray vars, const IloNumArray vals,
                     IloNum obj) {
      IloAssert(vars.getImpl(), "array not initialized");
      IloAssert(vals.getImpl(), "array not initialized");
      setSolution(vars, vals, obj, IloTrue);
    }

    void setSolution(const IloIntVarArray vars, const IloNumArray vals) {
      IloAssert(vars.getImpl(), "array not initialized");
      IloAssert(vals.getImpl(), "array not initialized");
      setSolution(vars, vals, 0.0, IloFalse);
    }

    void setSolution(const IloIntVarArray vars, const IloNumArray vals,
                     IloNum obj) {
      IloAssert(vars.getImpl(), "array not initialized");
      IloAssert(vals.getImpl(), "array not initialized");
      setSolution(vars, vals, obj, IloTrue);
    }
  };


  class SolveCallbackI : public ControlCallbackI {
    Callback::Type getType() const;
    void doSetStart(const IloNumArray    x,
                    const IloNumVarArray var,
                    const IloNumArray    pi,
                    const IloRangeArray  rng);
    void doSetStart(const IloNumArray    x,
                    const IloIntVarArray var,
                    const IloNumArray    pi,
                    const IloRangeArray  rng);
  protected:
    SolveCallbackI(IloEnv env) : ControlCallbackI(env)        {}

  public:
    IloBool solve(Algorithm alg = Dual);

    IloAlgorithm::Status getStatus() const;

    CplexStatus          getCplexStatus() const;

    IloBool              isPrimalFeasible() const;

    IloBool              isDualFeasible() const;

    void useSolution();

    void setStart(const IloNumArray    x,
                  const IloNumVarArray var,
                  const IloNumArray    pi,
                  const IloRangeArray  rng) {
      IloAssert(var.getImpl() == 0 || var.getSize() ==  x.getSize(),
                "Array lengths don't match");
      IloAssert(rng.getImpl() == 0 || rng.getSize() == pi.getSize(),
                "Array lengths don't match");
      doSetStart(x, var, pi, rng);
    }

    void setStart(const IloNumArray    x,
                  const IloIntVarArray var,
                  const IloNumArray    pi,
                  const IloRangeArray  rng) {
      IloAssert(var.getImpl() == 0 || var.getSize() ==  x.getSize(),
                "Array lengths don't match");
      IloAssert(rng.getImpl() == 0 || rng.getSize() == pi.getSize(),
                "Array lengths don't match");
      doSetStart(x, var, pi, rng);
    }
  };

  enum CutManagement {
    UseCutForce  = CPX_USECUT_FORCE , 
    UseCutPurge  = CPX_USECUT_PURGE , 
    UseCutFilter = CPX_USECUT_FILTER  
  };

  class UserCutCallbackI : public ControlCallbackI {
    Callback::Type getType() const;
  protected:
    UserCutCallbackI(IloEnv env) : ControlCallbackI(env) {}

    IloBool isAfterCutLoop() const;

    IloConstraint add(IloConstraint con,
                      CutManagement purgeable = UseCutForce);
    IloConstraint addLocal(IloConstraint con);

    void abortCutLoop();
  };

  class LazyConstraintCallbackI : public ControlCallbackI {
    Callback::Type getType() const;
    void updateSolutionSource() const;

  protected:
    LazyConstraintCallbackI(IloEnv env) : ControlCallbackI(env) {}

  public:

    IloCplex::IncumbentCallbackI::SolutionSource getSolutionSource() const;

    IloBool isUnboundedNode() const;

    IloConstraint add(IloConstraint con,
                      CutManagement purgeable = UseCutForce);
    IloConstraint addLocal(IloConstraint con);
  };

  Callback use(Callback cb);
  Callback add(Callback cb);
  bool     inUse(Callback cb);
  void     clear(Callback::Type cbtype);

  void     remove(Callback cb);

  class Goal {
  public:
    Goal(GoalBaseI *goalI);

    Goal(const Goal& goal);

    Goal() : _impl(0) {}

    Goal(IloConstraint cut);

    Goal(IloConstraintArray cut);

    Goal operator=(const Goal& goal);

    GoalBaseI *getImpl() const { return _impl; }

    ~Goal();

  protected:
    GoalBaseI *_impl;
  };

  class GoalBaseI {
  protected:
    IloInt    _refCnt;
    IloEnv    _env;
    CpxNodeI* _node;

    IloConstraint copyConstraint(IloConstraint rng);
  public:
    enum GoalType {
      Or,
      And,
      Branch,
      User
    };

    GoalBaseI(IloEnv env);

    Goal executeNode(CpxNodeI *node);

    virtual Goal execute() = 0;
    virtual Goal duplicateGoal() = 0;

    IloEnv getEnv() const { return _env; }

    virtual GoalType getType() const;

    void addRef() { _refCnt++; }
    void removeRef() { _refCnt--; }
    IloInt getNRefs() const { return _refCnt; }

    void setNode(CpxNodeI *node) { _node = node; }
    CpxNodeI *getNode() const { return _node; }

    virtual ~GoalBaseI();
  };

  class GoalI : public GoalBaseI {
  public:
    typedef struct MIPCallbackI::NodeId NodeId;

    enum IntegerFeasibility {
      ImpliedInfeasible = -1, 
      Feasible          =  CPX_INTEGER_FEASIBLE, 
      Infeasible        =  CPX_INTEGER_INFEASIBLE, 
      ImpliedFeasible   =  CPX_IMPLIED_INTEGER_FEASIBLE 
    };

    typedef IloArray<IntegerFeasibility> IntegerFeasibilityArray;

    enum BranchType {
      BranchOnVariable = CPX_TYPE_VAR, 
      BranchOnSOS1     = CPX_TYPE_SOS1, 
      BranchOnSOS2     = CPX_TYPE_SOS2, 
      BranchOnAny      = CPX_TYPE_ANY, 
      UserBranch       = CPX_TYPE_USER 
    };

    GoalI(IloEnv env) : GoalBaseI(env) {};

    IloEnv getEnv() const { return _env; }

    virtual Goal execute() = 0;

    virtual Goal duplicateGoal() = 0;

    virtual GoalType getType() const;

    void abort();

    IloModel getModel() const;

    NodeId getNodeId() const;

    IloInt getNcols() const;

    IloInt getNrows() const;

    IloNum getBestObjValue() const;

    IloNum getMIPRelativeGap() const;

    IloNum getCutoff() const;

    BranchDirection getDirection(const IloNumVar var);

    BranchDirection getDirection(const IloIntVar var) {
       return getDirection(IloNumVar(var.getImpl()));
    }

    IloNum getIncumbentObjValue() const;

    IloNum getIncumbentValue(const IloNumVar var) const;

    IloNum getIncumbentValue(const IloIntVar var) const {
       return getIncumbentValue(IloNumVar(var.getImpl()));
    }

    void getIncumbentValues (IloNumArray val,
                             const IloNumVarArray vars) const;

    void getIncumbentValues (IloNumArray val,
                             const IloIntVarArray vars) const;

    IloNum getIncumbentValue(const IloExprArg expr) const;

    IloInt getMyThreadNum() const;

    IloInt getUserThreads() const;

    IloInt getNcuts(IloCplex::CutType which) const;

    IloInt64 getNiterations64() const;

    IloInt getNiterations() const;

    IloInt64 getNnodes64() const;

    IloInt getNnodes() const;

    IloInt64 getNremainingNodes64() const;

    IloInt getNremainingNodes() const;

    IloNum getPriority(const IloNumVar var) const;

    IloNum getPriority(const IloIntVar var) const {
       return getPriority(IloNumVar(var.getImpl()));
    }

    IloBool isIntegerFeasible() const;

    IloBool hasIncumbent() const;

     IloNum getBranch(IloNumVarArray vars,
                      IloNumArray bounds,
                      BranchDirectionArray dirs,
                      IloInt i) const;

    BranchType getBranchType() const;

    IloInt getNbranches() const;

    IloNum getDownPseudoCost(const IloNumVar var) const;

    IloNum getDownPseudoCost(const IloIntVar var) const {
       return getDownPseudoCost(IloNumVar(var.getImpl()));
    }

    IntegerFeasibility getFeasibility(const IloNumVar var) const;

    IntegerFeasibility getFeasibility(const IloIntVar var) const {
       return getFeasibility(IloNumVar(var.getImpl()));
    }

    IntegerFeasibility getFeasibility(const IloSOS1 sos) const;

    IntegerFeasibility getFeasibility(const IloSOS2 sos) const;

    void getFeasibilities(IntegerFeasibilityArray stats,
                          const IloNumVarArray vars) const;

    void getFeasibilities(IntegerFeasibilityArray stats,
                          const IloIntVarArray vars) const;

    IloNum getLB (const IloNumVar var) const;

    IloNum getLB (const IloIntVar var) const {
       return getLB (IloNumVar(var.getImpl()));
    }

    void getLBs(IloNumArray vals, const IloNumVarArray vars) const;

    void getLBs(IloNumArray vals, const IloIntVarArray vars) const;

    IloNum getLb (const IloNumVar var) const    { return getLB(var); }
    void getLbs(IloNumArray vals, const IloNumVarArray vars) const {
       getLBs(vals, vars);
    }

    IloNum getObjCoef (const IloNumVar var) const;

    IloNum getObjCoef (const IloIntVar var) const {
       return getObjCoef (IloNumVar(var.getImpl()));
    }

    void getObjCoefs(IloNumArray vals,
                     const IloNumVarArray vars) const;

    void getObjCoefs(IloNumArray vals,
                     const IloIntVarArray vars) const;

    IloNum getObjValue() const;

    IloNum getSlack(const IloRange rng) const;

    void getSlacks(IloNumArray vals, const IloRangeArray rngs) const;

    IloNum getUB(const IloNumVar var) const;

    IloNum getUB(const IloIntVar var) const {
       return getUB(IloNumVar(var.getImpl()));
    }

    void getUBs(IloNumArray vals, const IloNumVarArray vars) const;

    void getUBs(IloNumArray vals, const IloIntVarArray vars) const;

    IloNum getUb (const IloNumVar var) const    { return getUB(var); }
    void getUbs(IloNumArray vals, const IloNumVarArray vars) const {
       getUBs(vals, vars);
    }

    IloNum getUpPseudoCost(const IloNumVar var) const;

    IloNum getUpPseudoCost(const IloIntVar var) const {
       return getUpPseudoCost(IloNumVar(var.getImpl()));
    }

    IloNum getValue(const IloExprArg expr) const;

    IloNum getValue(const IloNumVar var) const;

    IloNum getValue(const IloIntVar var) const {
       return getValue(IloNumVar(var.getImpl()));
    }

    void getValues(IloNumArray vals, const IloNumVarArray vars) const;

    void getValues(IloNumArray vals, const IloIntVarArray vars) const;

    IloBool isSOSFeasible(const IloSOS1 sos1) const;

    IloBool isSOSFeasible(const IloSOS2 sos2) const;

    static Goal BranchAsCplexGoal(IloEnv env);

    static Goal OrGoal(Goal goal1, Goal goal2);

    static Goal OrGoal(Goal goal1, Goal goal2, Goal goal3);
    static Goal OrGoal(Goal goal1, Goal goal2,
                       Goal goal3, Goal goal4);
    static Goal OrGoal(Goal goal1, Goal goal2, Goal goal3,
                       Goal goal4, Goal goal5);
    static Goal OrGoal(Goal goal1, Goal goal2, Goal goal3,
                       Goal goal4, Goal goal5, Goal goal6);

    static Goal AndGoal(Goal goal1, Goal goal2);
    static Goal AndGoal(Goal goal1, Goal goal2, Goal goal3);
    static Goal AndGoal(Goal goal1, Goal goal2,
                        Goal goal3, Goal goal4);
    static Goal AndGoal(Goal goal1, Goal goal2, Goal goal3,
                        Goal goal4, Goal goal5);
    static Goal AndGoal(Goal goal1, Goal goal2, Goal goal3,
                        Goal goal4, Goal goal5, Goal goal6);

    static Goal FailGoal(IloEnv env);

    static Goal GlobalCutGoal(IloConstraint con);

    static Goal GlobalCutGoal(IloConstraintArray con);

    static Goal SolutionGoal(const IloNumVarArray vars,
                             const IloNumArray vals);
    static Goal SolutionGoal(const IloNumVarArray vars,
                             const IloNumArray vals,
                             IloNum obj);

    static Goal SolutionGoal(const IloIntVarArray vars,
                             const IloNumArray vals);
    static Goal SolutionGoal(const IloIntVarArray vars,
                             const IloNumArray vals,
                             IloNum obj);

  };

  class Node {
  public:
    Node() : _impl(0) {}
    Node(CpxNodeI *impl) : _impl(impl) {}

    CpxNodeI *getImpl() const { return _impl; }

    IloInt getLeftDepth() const;
    IloInt getRightDepth() const;
    IloInt getDepth()  const;
  protected:
    CpxNodeI *_impl;
  };

  class EvaluatorI {
  public:
    EvaluatorI() : _node(0) {}

    void setNode(CpxNodeI *node) { _node = node; }
    virtual ~EvaluatorI();

  protected:
    IloInt getLeftDepth() const;
    IloInt getRightDepth() const;
    IloInt getDepth()  const;

    CpxNodeI *_node;
  };

  class NodeEvaluatorI : public EvaluatorI {
  public:
    NodeEvaluatorI () : _refCnt(0),
                        _id(-1),
                        _isInit(IloFalse) {}

    virtual IloNum evaluate() const = 0;

    virtual NodeEvaluatorI* duplicateEvaluator() = 0;

    virtual IloBool subsume(IloNum evalBest,
                            IloNum evalCurrent) const;

    virtual void    init();

    IloBool isInit() { return _isInit; }

    void addRef() { _refCnt++; }
    void removeRef() { _refCnt--; }
    IloInt getNRefs() const { return _refCnt; }

    IloNum evaluateNode(CpxNodeI *node, IloInt64 nIndex);

    NodeCallbackI *getCallback() const;

    void initNode(CpxNodeI *node);
    virtual NodeEvaluatorI* duplicateEvaluatorWithId();
    IloInt getId() const { return _id; }
    void  setId(IloInt id) { _id = id; }


    virtual ~NodeEvaluatorI();

  protected:
    IloNumVar getBranchVar() const;

    IloInt getDepth() const;

    IloNum getEstimatedObjValue() const;

    IloNum getInfeasibilitySum() const;

    IloInt getNinfeasibilities() const;

    IloNum getObjValue() const;

    IloInt    _refCnt;
    IloInt64  _nIndex;

    IloInt    _id;

    IloBool   _isInit;
  };

  class NodeEvaluator {
  protected:

    NodeEvaluatorI *_impl;

  public:
    NodeEvaluator ();

    NodeEvaluator (NodeEvaluatorI *impl);

    NodeEvaluator (const NodeEvaluator& eval);

    NodeEvaluator operator=(const NodeEvaluator& eval);

    NodeEvaluatorI *getImpl() const { return _impl; }

    ~NodeEvaluator();
  };

  class SearchLimitI : public EvaluatorI {
  public:
    SearchLimitI();

    virtual ~SearchLimitI();

    virtual SearchLimitI* duplicateLimit()=0;

    virtual IloBool check() = 0;

    virtual void init();

    // END:: Documented API

    virtual IloBool checkNode(CpxNodeI *node);
    virtual void initNode(CpxNodeI *node);

    void setViolated() { _isViolated = IloTrue; }
    IloBool isViolated() const { return _isViolated; }

    void addRef() { _refCnt++; }
    void removeRef() { _refCnt--; }
    IloInt getNRefs() const { return _refCnt; }
  protected:
    IloInt _refCnt;
    IloBool _isViolated;
  };

  class SearchLimit {
  protected:
    SearchLimitI *_impl;

  public:
    SearchLimit();

    SearchLimit(SearchLimitI* impl);

    SearchLimit(const SearchLimit& limit);

    SearchLimit operator=(const SearchLimit& limit);


    SearchLimitI *getImpl() const { return _impl; }

    ~SearchLimit();
  };

  static Goal Apply ( IloCplex cplex, Goal goal, NodeEvaluator eval );

  static Goal LimitSearch ( IloCplex cplex, Goal goal, SearchLimit limit );

/* To be implemented:
 *
 * static NodeEvaluator DFSEvaluator();
 * static NodeEvaluator IDFSEvaluator(IloCplex cplex);
 * static NodeEvaluator DDSEvaluator(IloCplex);
 *
 * static SearchLimit FailLimit(IloCplex cplex, IloInt failLimit);
 */

  /* We are not exporting this in this release: */
  static SearchLimit OrLimit(IloInt orLimit);

  IloBool solve() { return IloAlgorithm::solve(); }

#ifndef ILOG_CPLEX_NO_REMOTE_API
  class SolveHandleI : public AsyncHandleI {
  public:
    virtual IloBool joinSolve() = 0;
  };
  class SolveHandle : public AsyncHandle {
  public:
    SolveHandle(SolveHandleI *i = 0) : AsyncHandle(i) {}
    IloBool joinSolve();
  };
  SolveHandle solve(bool async);
#endif // !ILOG_CPLEX_NO_REMOTE_API

  IloBool solve(Goal goal);
  // END: For the Goal API

  void   setFormulationEpsValue(IloNum eps) {
     setParam(EpLin, eps);
  }

  IloNum getFormulationEpsValue() {
     return getParam(EpLin);
  }

 public:
  IloNum getSolnPoolMeanObjValue() const;
  IloInt getSolnPoolNsolns() const;
  IloInt getSolnPoolNreplaced() const;
  void delSolnPoolSoln(IloInt which);
  void delSolnPoolSolns(IloInt begin, IloInt end);

  enum FilterType { 
    FilterDiversity = CPX_SOLNPOOL_FILTER_DIVERSITY,
    FilterRange     = CPX_SOLNPOOL_FILTER_RANGE
  };

  typedef Index FilterIndex;
  typedef IndexArray FilterIndexArray;
  inline FilterIndex
  addDiversityFilter(IloNum lower_cutoff, IloNum upper_cutoff,
			  const IloNumVarArray vars, const IloNumArray weights,
			  const IloNumArray refval, const char *fname = 0);
  inline FilterIndex
  addDiversityFilter(IloNum lower_cutoff, IloNum upper_cutoff,
			  const IloIntVarArray vars, const IloNumArray weights,
			  const IloNumArray refval, const char *fname = 0);
  inline FilterIndex getFilterIndex(const char *lname_str) const;
  inline IloInt getNfilters() const;
  inline FilterType getFilterType(FilterIndex filter) const;
  inline IloNum getDiversityFilterLowerCutoff(FilterIndex filter) const;
  inline IloNum getDiversityFilterUpperCutoff(FilterIndex filter) const;
  inline void getFilterVars(FilterIndex filter, IloNumVarArray) const;
  inline void getFilterVars(FilterIndex filter, IloIntVarArray) const;
  inline void getDiversityFilterWeights(FilterIndex filter, IloNumArray) const;
  inline void getDiversityFilterRefVals(FilterIndex filter, IloNumArray) const;
  inline FilterIndex addRangeFilter(IloNum, IloNum, const IloNumVarArray,
		      const IloNumArray, const char* = 0);
  inline FilterIndex addRangeFilter(IloNum, IloNum, const IloIntVarArray,
		      const IloNumArray, const char* = 0);
  inline IloNum getRangeFilterLowerBound(FilterIndex filter) const;
  inline IloNum getRangeFilterUpperBound(FilterIndex filter) const;
  inline void getRangeFilterCoefs(FilterIndex filter, IloNumArray) const;
  inline void delFilter(FilterIndex filter);
  inline FilterIndexArray readFilters(const char* name);
  inline void writeFilters(const char* name);

  inline IloNum getCplexTime() const;
  inline IloNum getDetTime() const;
  inline int    getNumCores() const;
};
class IloCplex::Parameter {
 public:
   // 'Unknown' must be last element in enumeration or iterator does not work.
   enum Type {        Int, Num, Bool, String, Long, Unknown };
private:
    Type _t;
    int  _key;
    union {
        CPXINT Int;
        IloNum Num;
        IloBool Bool;
        char* String;
        CPXLONG Long;
    } _value;
public:
    inline Parameter(int key, CPXINT value, bool isBool = 0);
    inline Parameter(int key, CPXLONG value);
    inline Parameter(int key, IloNum value);
    inline Parameter(int key, char* value);
    inline Type getType() const;
    inline int getParameterId() const;
    inline CPXINT getIntValue() const;
    inline CPXLONG getLongValue() const;
    inline IloNum getNumValue() const;
    inline IloBool getBoolValue() const;
    inline char* getStringValue() const;
};

inline IloCplex::Parameter::Parameter(int key, CPXINT value, bool isBool) :
    _t(isBool ? Bool : Int), _key(key) {
  if (isBool)
    _value.Bool = value ? true : false;
  else
    _value.Int = value;
}

inline IloCplex::Parameter::Parameter(int key, CPXLONG value) :
    _t(Long), _key(key) {
    _value.Long = value;
}

inline IloCplex::Parameter::Parameter(int key, IloNum value) :
    _t(Num), _key(key) {
    _value.Num = value;
}

inline IloCplex::Parameter::Parameter(int key, char* value) :
    _t(String), _key(key) {
    _value.String = value;
}

inline IloCplex::Parameter::Type IloCplex::Parameter::getType() const {
    return _t;
}

inline int IloCplex::Parameter::getParameterId() const {
    return _key;
}

inline CPXINT IloCplex::Parameter::getIntValue() const {
    return _value.Int;
}

inline CPXLONG IloCplex::Parameter::getLongValue() const {
    return _value.Long;
}

inline IloNum IloCplex::Parameter::getNumValue() const {
    return _value.Num;
}

inline IloBool IloCplex::Parameter::getBoolValue() const {
    return _value.Bool;
}

inline char* IloCplex::Parameter::getStringValue() const {
    return _value.String;
}

class IloCplex::ParameterSet::Iterator {
    ParameterSetI* _ps;
    Parameter::Type state;
    int pos;
public:
    inline Iterator(ParameterSet);
    inline Parameter operator*() const;
    inline bool ok() const;
    inline Iterator& operator++();
    inline Iterator operator++(int);
};

inline IloCplex::ParameterSet::Iterator::Iterator(ParameterSet ps) :
    _ps(ps.getImpl()), state(Parameter::Int), pos(0) {
    if (_ps->_intParams.getSize() == 0)
        state = Parameter::Num;
    if (state == Parameter::Num && _ps->_numParams.getSize() == 0)
        state = Parameter::Bool;
    if (state == Parameter::Bool && _ps->_boolParams.getSize() == 0)
        state = Parameter::String;
    if (state == Parameter::String && _ps->_stringParams.getSize() == 0)
        state = Parameter::Long;
    if (state == Parameter::Long && _ps->_longParams.getSize() == 0)
        state = Parameter::Unknown;
}

inline IloCplex::Parameter
IloCplex::ParameterSet::Iterator::operator*() const {
    switch (state) {
        case Parameter::Int:
            return Parameter(_ps->_intParams[pos], _ps->_intParamValues[pos]);
        case Parameter::Num:
            return Parameter(_ps->_numParams[pos], _ps->_numParamValues[pos]);
        case Parameter::Bool:
            return Parameter(_ps->_boolParams[pos],
                             _ps->_boolParamValues[pos] ? true : false,
        		     true);
        case Parameter::String:
            return Parameter(_ps->_stringParams[pos],
        		     _ps->_stringParamValues[pos]);
        case Parameter::Long:
            return Parameter(_ps->_longParams[pos],
                             _ps->_longParamValues[pos]);
        case Parameter::Unknown:
            throw Exception(-1, "Iterator used beyond end");
    }
    throw Exception(-1, "Unhandled parameter type (internal error)");
}

inline bool IloCplex::ParameterSet::Iterator::ok() const {
    return state != Parameter::Unknown;
}

inline IloCplex::ParameterSet::Iterator&
IloCplex::ParameterSet::Iterator::operator++() {
    ++pos;
    if (state == Parameter::Int && _ps->_intParams.getSize() == pos) {
        state = Parameter::Num;
        pos = 0;
    }
    if (state == Parameter::Num && _ps->_numParams.getSize() == pos) {
        state = Parameter::Bool;
        pos = 0;
    }
    if (state == Parameter::Bool && _ps->_boolParams.getSize() == pos) {
        state = Parameter::String;
        pos = 0;
    }
    if (state == Parameter::String && _ps->_stringParams.getSize() == pos) {
        state = Parameter::Long;
        pos = 0;
    }
    if (state == Parameter::Long && _ps->_longParams.getSize() == pos) {
        state = Parameter::Unknown;
        pos = 0;
    }
    return *this;
}

inline IloCplex::ParameterSet::Iterator
IloCplex::ParameterSet::Iterator::operator++(int) {
    Iterator cp = *this;
    ++*this;
    return cp;
}

class IloCplexIndexManager;
extern "C" {
void CPXPUBLIC IloCplexErrorChannelFunction(void* arg, const char *message);
}

class IloCplexMutex;

class IloCplexI : public IloAlgorithmI {
  // No copying or assignment
  IloCplexI(IloCplexI const &);
  IloCplexI& operator=(IloCplexI const &);
public:
  // For the Goal API
  class GoalStack;
  // END: For the Goal API
  typedef IloCplex::Index      Index;
  typedef IloCplex::IndexArray IndexArray;

  IloBool inconsistency(int i);
  IloBool isSelfConsistent();
  IloBool isConsistent(IloCplexI* copy);
  IloBool isConsistent();

  IloExprParser* getCurrentBaseExprParser();
  IloExprParser* popExprParser();
  void           pushExprParser(IloExprParser*);

private:
  friend class IloCplex;
  friend class IloCplexColumn;
  friend class IloFastCplexColumn;
  friend class IloCplexRow;
  friend class IloFastCplexRow;
  friend class IloCplexSOS;
  friend class IloFastCplexSOS;
  friend class IloLPExtractor;
  friend class IloCallbackManager;
  friend class IloOptimizationCallbackManager;
  friend class IloCutCallbackManager;
  friend class IloIncumbentCallbackManager;
  friend class IloControlCallbackManager;
  friend class IloHeuristicCallbackManager;
  friend class IloSolveCallbackManager;
  friend class IloCplexCallbackManager;
  friend class IloDefaultLPExtractor;
  friend class IloLogicalExtractor;
#ifdef USE_SET_VARS
  friend class IloSetConstraintExtractor;
#endif
  friend void CPXPUBLIC IloCplexErrorChannelFunction(void* arg,
                                                     const char *message);

  IloDefaultLPExtractor*      _defextr;
  IloLogicalExtractor*        _logextr;
#ifdef USE_SET_VARS
  IloSetConstraintExtractor*  _setextr;
#endif
  IloColumnExtractor*         _colextr;
  IloExprParser*              _qpextr;
  IloLPExtractorManager*      _extractorManager;
  IloCplexCallbackManager*    _callbacks;
  IloCplexAborterI*           _abort;

  IloCplexIndexManager* _rowind;
  IloCplexIndexManager* _colind;
  IloCplexIndexManager* _qcpind;
  IloCplexIndexManager* _sosind;
  IloCplexIndexManager* _filterind;
  IloCplexIndexManager* _gcind[CPX_CON_LAST_CONTYPE];
  IloCarray<int>        _gctype;

  char _tmpname[256];

  cpxenv* _cpxenv;
  cpxlp*  _lp;
  IloCplex::Exception _constructorException;

  const IloObjectiveI* _obj;

  IloInt _datacheck;   // cached copy of parameter for faster access
public:
  IloBool isDataCheck() const {
     if ( _datacheck == IloCplex::Warn ||
          _datacheck == IloCplex::Assist ) {
        return IloTrue;
     }
     else {
        IloAssert (_datacheck == IloCplex::Off,
                   "Unexpected DataCheckType!");
        return IloFalse;
     }
  }
  static void alwaysCheckNAN(double val) {
     if ( val != val ) {
        throw IloCplex::Exception(CPXERR_NAN,
                "Numeric entry is not a double precison number (NAN)");
     }
  }
  void checkNAN(double val) const {
     if ( _datacheck  &&  val != val ) {
        throw IloCplex::Exception(CPXERR_NAN,
                "Numeric entry is not a double precison number (NAN)");
     }
  }

  // The deleter
  void setEmptyDeleter(IloBool remove=IloFalse);
  void unsetDeleter();

  void replaceObject (Index index, const IloExtractableI* src,
                                   const IloExtractableI* dest);

private:
  char _errorstring[CPX_STR_PARAM_MAX];
  char _strparam[CPX_STR_PARAM_MAX];

  IloCplex::DeleteMode _delmode;
  bool _isRemote;
  void const *const _asynctab;
#ifndef ILOG_CPLEX_NO_DISTRIBUTED_MIP_API
  IloCplexDistmipopt      *_distmipopt;
  IloCplexDelVMConfig *_delvmconfig;
#endif

  IloCarray<int> mutable    _tmpi;
  IloCarray<char> mutable   _tmpc;
  IloCarray<double> mutable _tmpd;
  void minTmpSize(IloInt min) const {
    ((IloCplexI*)this)->_tmpi.setMinSize(min);
    ((IloCplexI*)this)->_tmpc.setMinSize(min);
    ((IloCplexI*)this)->_tmpd.setMinSize(min);
  }

  void initSolutionManager(IloEnvI* env);
  void finitSolutionManager();
  void init(IloCplexInitFunction *initFunction, char const *transport,
            int argc, char const *const *argv);

  void copyIndices(IloCarray<int>& col, const IndexArray& ind);

  void fixProbType();
  const char *probName(char *nameBuf);

  void deleteNames();

  ::IloCplex::CplexStatus handleSolveStatus(int solstat) const;
  ::IloAlgorithm::Status CplexToAlgorithmStatus(int solstat, int pfeas,
                                                             int dfeas) const;
  void cpxthrow(int status) const;

  // input caches
  IloCplexCache* _cache;

  IloCachedArray<char> _ctype;
  IloCachedArray<char> _convtype;
  void flushCtype();
  void removeFromCtype(Index col);
  void removeFromCtype(const IndexArray cols, IloCarray<int>& mark);

  IloBool         _ordchanged;
  IloCarray<int>  _ordpri;
  IloCarray<int>  _orddir;
  void flushOrder();
  void unflushOrder();
  void removeFromOrder(Index col);
  void removeFromOrder(const IndexArray cols, IloCarray<int>& mark);

  void markColumns(const IndexArray cols, IloCarray<int>& mark);
  
  void doflush();
  void flush(IloBool force=IloTrue) const;

  // query caches
  int _nInts;
  int _nCols;
  int _nRows;
  int _nQCs;
  int _nSOS;
  IloBool _hasQ;
  IloBool hasUserCuts() const;
  IloBool hasLazyConstraints() const;
  IloBool hasGeneralConstraints() const;

  IloCachedArray<double> _lb;
  IloCachedArray<double> _ub;

  // result caches
  mutable IloCplex::CplexStatus  _solstat;
  mutable IloCachedArray<double> _qcslack;
  mutable IloCachedArray<double> _slack;
  mutable IloCachedArray<double> _x;
  mutable IloCachedArray<double> _pi;
  mutable IloCachedArray<double> _dj;
  mutable IloCachedArray<IloCplex::BasisStatus> _rstat;
  mutable IloCachedArray<IloCplex::BasisStatus> _cstat;
  mutable IloCachedMultiArray<double> _solnpoolx;
  mutable IloCachedMultiArray<double> _solnpoolslack;
  mutable IloCachedMultiArray<double> _solnpoolqcslack;
  mutable IloCachedArray<double> _objSAl;
  mutable IloCachedArray<double> _objSAu;
  mutable IloCachedArray<double> _rhsSAl;
  mutable IloCachedArray<double> _rhsSAu;
  mutable IloCachedArray<double> _rngSAll;
  mutable IloCachedArray<double> _rngSAlu;
  mutable IloCachedArray<double> _rngSAul;
  mutable IloCachedArray<double> _rngSAuu;
  mutable IloCachedArray<double> _lbSAl;
  mutable IloCachedArray<double> _lbSAu;
  mutable IloCachedArray<double> _ubSAl;
  mutable IloCachedArray<double> _ubSAu;

  void invalidate() const;
  void validateX() const;
  void validateLb() const;
  void validateUb() const;
  void validatePi() const;
  void validateDj() const;
  void validateSlack() const;
  void validateQCSlack() const;
  void validateObjSA() const;
  void validateRhsSA() const;
  void validateRngSA() const;
  void validateBoundSA() const;
  void validateSolnPoolX(IloInt soln) const;
  void validateSolnPoolSlack(IloInt soln) const;
  void validateSolnPoolQCSlack(IloInt soln) const;
  void validateRowStatus() const;
  void validateColumnStatus() const;

  // For the Goal API
  CpxNodeI*            _rootNode;
  IloCplex::Goal       _rootGoal;
  IloCplex::GoalBaseI* _lastGoal;

  IloBool           _usesEval;
  IloInt            _evalId;

  IloArray<IloConstraintArray> _globalCuts;
  IloCplexMutex**              _gCutMutex;
  IloCplexMutex*               _idMutex;

  IloCplex::BranchCallbackI           *_branchCallback;
  IloCplex::NodeCallbackI             *_nodeCallback;
  IloCplex::IncumbentCallbackI        *_incCallback;
  IloCplex::UserCutCallbackI          *_ucCallback;
  IloCplex::LazyConstraintCallbackI   *_lcCallback;
  void    setRootNode(CpxNodeI *node) { _rootNode = node; }
  void    initGoals(IloBool& prevInSubtree, IloBool& prevMIPStart);
  void    finitGoals(IloBool insubtree, int mipstart);
  // END: For the Goal API

private:
  template<typename T>
  void feasOpt_wrap (const IloRangeArray rows, 
                     const IloNumArray rnglb, const IloNumArray rngub,
                     const IloForAllRangeArray frows, 
                     const IloNumArray frnglb, const IloNumArray frngub,
                     const T cols,
                     const IloNumArray varlb, const IloNumArray varub,
                     IloBool *result_p, bool async,
                     IloCplex::FeasOptHandleI **handle_p);

  friend class IloAbstractHandle;
  friend struct IloPresolve;
  friend struct IloSolve;
  friend struct IloSolveFixed;
  friend struct IloPopulate;
  friend struct IloRefineConflict;
  friend struct IloRefineMIPStartConflict;
  friend struct IloTuneParam;
  friend struct IloEFeasOpt;
  friend struct IloFeasOptExt;

  void prepareParamList (const IloCplex::ParameterSet fixedset,
                         int& icnt, int*& inum, int*& ival,
                         int& dcnt, int*& dnum, double*& dval,
                         IloCarray<int>& snum, IloCarray<char*>& sval,
                         IloCarray<char>& sbuf);

#ifndef ILOG_CPLEX_NO_DISTRIBUTED_MIP_API
  void copyVMConfig (char const *xmlstring, IloCplexCopyVMConfig *r,
                IloCplexDelVMConfig *d, IloCplexDistmipopt *o);
  void readVMConfig (char const *xmlstring, IloCplexReadVMConfig *r,
                    IloCplexDelVMConfig *d, IloCplexDistmipopt *o);
#endif

public:
  ~IloCplexI();
  IloCplexI(IloEnvI* env,
            bool isRemote,
            IloCplexInitFunction *initFunction,
            char const *transport = 0, int argc = 0,
            char const *const *argv = 0,
            void const *asynctab = 0);

  // Every extractable extracted by to IloCplex must store a data object
  // which is a derived class of Data.  In this object index must be the
  // index of the column, row, qcprow, or SOS created to represent the
  // extracted expression.
  struct Data {
    Index index;
    Data()                      {}
    Data(Index i) : index(i)    {}

    Index getIndex()        { return index; }
    void  setIndex(Index i) { index = i; } 
  };

  void uses() {}
  void getData() {}
  void setData() {}
  Index throwNotExtracted(const IloExtractableI* obj) const;

  Index getVarIndex (IloInt id) const;
  Index getVarIndexOrException (const IloExtractableI* obj) const;

  void getVarIndices           (IndexArray ind,
                                const IloExtractableArray& obj) const;
  void getVarIndicesOrException(IndexArray ind,
                                const IloExtractableArray& obj) const;

  void getVarIndices (IndexArray& ind, const IloNumVarArray& obj) const {
     getVarIndices(ind, *(const IloExtractableArray*)&obj);
  }
  void getVarIndicesOrException (IndexArray&           ind,
                                 const IloNumVarArray& obj) const {
     getVarIndicesOrException(ind, *(const IloExtractableArray*)&obj);
  }

  Index getConIndex (IloInt id) const;
  Index getConIndexOrException (const IloExtractableI* obj) const;

  void getConIndices           (IndexArray                 ind,
                                const IloExtractableArray& obj) const;
  void getConIndicesOrException(IndexArray                 ind,
                                const IloExtractableArray& obj) const;

  void getConIndices (IndexArray& ind, const IloRangeArray& obj) const {
     getConIndices(ind, *(const IloExtractableArray*)&obj);
  }
  void getConIndicesOrException (IndexArray&          ind,
                                 const IloRangeArray& obj) const {
     getConIndicesOrException(ind, *(const IloExtractableArray*)&obj);
  }
  int getGCType(const IloExtractableI* obj) const;

  const IloCplexIndexManager* getColIndexManager() { return (_colind); }

  void                 setName(const char *name);

  const IloObjectiveI* getObjective() const                    { return _obj; }
  void                 setObjective(const IloObjectiveI* obj)  { _obj = obj; }
  void                 setObjName(const char *name);

  void                 setQCName(Index which, const char *name);
  void                 setSOSName(Index which, const char *name);

  IloConstraint            addLazyConstraint(IloConstraint rng);
  const IloConstraintArray addLazyConstraints(const IloConstraintArray rng);
  void                     clearLazyConstraints();

  IloConstraint            addUserCut(IloConstraint rng);
  const IloConstraintArray addUserCuts(const IloConstraintArray rng);
  void                     clearUserCuts();

   // general constraints

   Index addAbs  (const IloExtractableI* obj,
                  Index                  absvar,
                  Index                  x,
                  const char*            name=0);

   Index addMin  (const IloExtractableI*  obj,
                  Index                   minvar,
                  const IloCarray<Index>& terms,
                  double                  cnst=IloInfinity,
                  const char*             name=0);

   Index addMax  (const IloExtractableI*  obj,
                  Index                   maxvar,
                  const IloCarray<Index>& terms,
                  double                  cnst=IloInfinity,
                  const char*             name=0);

   // pwlvar = PWL(..., x);
   Index addPWL (const IloExtractableI* obj,
                 Index                  pwlvar,
                 const IloNumArray&     point,
                 const IloNumArray&     slope,
                 double                 a,
                 double                 fa,
                 Index                  x,
                 const char*            name=0);

private:
   // helper function for importModel
   IloNumExprArg getPWLexpr (IloEnv          env,
                             IloNumVarArray& x,
                             CPXENVptr       cpxenv,
                             CPXLPptr        lp,
                             CPXDIM          pwlind) const;

public:
   Index addIndicator (const IloExtractableI *obj,
                       const Index indvar,
                       double rhs, int sense,
                       const IloCarray<Index>&  lind,
                       const IloCarray<double>& lval);

#ifdef USE_SET_VARS
   Index addSetVar (const IloIntSetVarI *obj);

   void changeSetVar (Index setvar, const IloIntSetVarI *obj);

   void getIntSetValue (const IloIntSetVarI *obj, IloIntSet set);

   Index addSetVarCard (const IloExtractableI *obj,
                        Index cardvar, Index setvar);

   Index addSetVarMember (const IloExtractableI *obj,
                        Index indvar, Index setvar, double value);

   Index addSetVarSum(const IloExtractableI *obj,
                  Index sumvar, Index setvar, IloIntArray values);

   Index addSetVarMin(const IloExtractableI *obj,
                  Index minvar, Index setvar, IloIntArray values);

   Index addSetVarMax(const IloExtractableI *obj,
                  Index maxvar, Index setvar, IloIntArray values);

   Index addSetVarSubset(const IloExtractableI *obj,
                  Index setvar1, Index setvar2, int strict);

   Index addSetVarDomain(const IloExtractableI *obj,
                  Index setvar, IloIntArray values, 
                  int possible, int required, int forbidden,
                  int strict);

   Index addSetVarUnion(const IloExtractableI *obj,
                  Index setvar, Index setvar1, Index setvar2);

   Index addSetVarIntersection(const IloExtractableI *obj,
                  Index setvar, Index setvar1, Index setvar2);

   Index addSetVarNullIntersect(const IloExtractableI *obj,
                  Index setvar1, Index setvar2);

   Index addSetVarEq(const IloExtractableI *obj,
                  Index setvar1, Index setvar2);

   Index addSetVarNEq(const IloExtractableI *obj,
                  Index setvar1, Index setvar2);

   Index addSetVarNEqCst(const IloExtractableI *obj,
                       Index setvar, IloIntArray values);
#endif

  cpxenv* getCplexEnv() { return _cpxenv; }
  cpxlp*  getCplexLp()  { flush(IloTrue); return _lp; }

  IloLPExtractorManager* getExtractorManager() { return (_extractorManager); }

  void importModel(IloModel& m, const char* filename) const;
  void importModel(IloModel& m, const char* filename,
                   IloObjective& obj, IloNumVarArray vars, IloRangeArray rngs,
                   IloRangeArray  lazy,
                   IloRangeArray  cuts) const;
  void importModel(IloModel& m, const char* filename,
                   IloObjective& obj, IloNumVarArray vars, IloRangeArray rngs,
                   IloSOS1Array sos1, IloSOS2Array sos2,
                   IloRangeArray  lazy,
                   IloRangeArray  cuts) const;

  void use(IloLPExtractor* extr);
  void use(IloExprExtractor* extr);

  void
  addColumnExtractorAddon(IloExprExtractor* (*add)(IloEnv, IloColumnExtractor*),
			  void (*remove)(IloExprExtractor*));
  void
  addDefaultLPExtractorAddon(IloLPExtractor* (*add)(IloEnv,
						    IloDefaultLPExtractor*),
			     void (*remove)(IloLPExtractor*));
  void addExprParserAddon(IloLPExtractor* (*add)(IloEnv, IloExprParser*),
			  void (*remove)(IloLPExtractor*));
  void addLogicalExtractorAddon(IloLPExtractor* (*add)(IloEnv,
						       IloLogicalExtractor*),
				void (*remove)(IloLPExtractor*));

  void use(IloCplexAborterI* abort);
  void remove(IloCplexAborterI* abort);
  IloCplexAborterI* getAborter();

  IloCplex::CallbackI* use(IloCplex::CallbackI* cb);
  IloCplex::CallbackI* add(IloCplex::CallbackI* cb);
  bool                 inUse(IloCplex::CallbackI* cb);
  void                 remove(IloCplex::CallbackI* cb);
  void                 clear(IloCplex::Callback::Type cbtype);

  void setMaxId(IloInt id);
  virtual void extract(const IloExtractableI* obj);
  virtual void remove (const IloExtractableI* obj);
  virtual void apply  (const IloChange& chg, const IloExtractableI* obj);
  virtual void apply  (const IloChange& chg);
  void extract(const IloExtractableArray& o) { IloAlgorithmI::extract(o); }
  void remove (const IloExtractableArray& o) { IloAlgorithmI::remove(o); }
  virtual IloBool doExtract(const IloExtractableI* , void**);
  virtual IloBool doRemove (const IloExtractableI*, void*);
  virtual IloBool doApply  (const IloChange* chg, void** data,
                            const IloExtractableI* obj);

  // IloLPExtractor* getLPExtractor(IloInt id) const;

  void setDeleteMode(IloCplex::DeleteMode mode) { _delmode = mode; }
  IloCplex::DeleteMode getDeleteMode() const    { return (_delmode); }

  virtual IloNum getValue(const IloObjectiveI* obj) const;
  virtual IloNum getValue(const IloNumVarI*    var) const;
  virtual IloNum getValue(const IloConstraintI* con) const;
  virtual void getValues(const IloNumVarArray, IloNumArray) const;
  virtual void getValues(const IloIntVarArray, IloNumArray) const;

  void getValues(const IloIntVarArray var, IloNumArray val, IloInt soln) const;
  void getValues(const IloNumVarArray var, IloNumArray val, IloInt soln) const;
  IloNum getValue(const IloNumVarI* var, IloInt soln) const;
  IloNum getValue(const IloObjectiveI* var, IloInt soln) const;
  IloNum getValue(const IloConstraintI* con, IloInt soln) const;
  IloNum getValue(IloNumExprI* expr, IloInt soln) const;
  IloNum getObjValue(IloInt soln) const;

  IloNum getDual  (IloRangeI* con) const;
  IloNum getSlack (IloRangeI* con, IloInt soln) const;
  IloNum getInfeasibility (IloConstraintI* con, double* rowinfeas) const;   
  IloNum getAX    (IloRangeI* con) const;
  IloNum getReducedCost(IloNumVarI* con) const;
  IloNum getInfeasibility (IloNumVarI* var) const;
  IloCplex::BasisStatus getBasisStatus(IloNumVarI* con) const;
  IloCplex::BasisStatus getBasisStatus(IloConstraintI*  con) const;

  void getQCDSlack(IloRangeI const *con,
                   IloNumArray& vals, IloNumVarArray& vars) const;
  void getQCDSlack(IloForAllRangeI const *con,
                   IloNumArray& vals, IloNumVarArray& vars) const;

  void getDuals  (IloNumArray val, const IloRangeArray con) const;
  void getSlacks (IloNumArray val, const IloRangeArray con, IloInt soln) const;
  IloNum getInfeasibilities (IloNumArray infeas, const IloRangeArray range) const;
  IloNum getInfeasibilities (IloNumArray infeas, const IloConstraintArray con) const;
  void getAX     (IloNumArray val, const IloRangeArray con) const;
  void getReducedCosts(IloNumArray val, const IloNumVarArray con) const;
  void getReducedCosts(IloNumArray val, const IloIntVarArray con) const;
  IloNum getInfeasibilities (IloNumArray infeas, const IloNumVarArray var) const;
  IloNum getInfeasibilities (IloNumArray infeas, const IloIntVarArray var) const;
  void getBasisStatuses(IloCplex::BasisStatusArray stat,
                        const IloNumVarArray con) const;
  void getBasisStatuses(IloCplex::BasisStatusArray stat,
                        const IloIntVarArray con) const;
  void getBasisStatuses(IloCplex::BasisStatusArray stat,
                        const IloConstraintArray  con) const;
  void getBasisStatuses(IloCplex::BasisStatusArray cstat,
                        const IloNumVarArray var,
                        IloCplex::BasisStatusArray rstat,
                        const IloConstraintArray con) const;
  void getBasisStatuses(IloCplex::BasisStatusArray cstat,
                        const IloIntVarArray var,
                        IloCplex::BasisStatusArray rstat,
                        const IloConstraintArray con) const;

  void getBoundSA(IloNumArray lblower, IloNumArray lbupper,
                  IloNumArray ublower, IloNumArray ubupper,
                  const IloNumVarArray cols) const;
  void getBoundSA(IloNumArray lblower, IloNumArray lbupper,
                  IloNumArray ublower, IloNumArray ubupper,
                  const IloIntVarArray cols) const;
  void getRangeSA(IloNumArray lblower, IloNumArray lbupper,
                  IloNumArray ublower, IloNumArray ubupper,
                  const IloRangeArray rows) const;
  void getRHSSA  (IloNumArray lower, IloNumArray upper,
                  const IloRangeArray rows) const;
  void getObjSA  (IloNumArray lower, IloNumArray upper,
                  const IloNumVarArray cols) const;
  void getObjSA  (IloNumArray lower, IloNumArray upper,
                  const IloIntVarArray cols) const;

  IloNum getAX    (IloForAllRangeI* con) const;
  IloNum getDual  (IloForAllRangeI* con) const;
  IloNum getSlack (IloForAllRangeI* con, IloInt soln=IloCplex::IncumbentId) const;
  void   getBds   (IloForAllRangeI* con, IloNum &lb, IloNum &ub) const;
  IloNum getLB    (IloForAllRangeI* con) const;
  IloNum getUB    (IloForAllRangeI* con) const;
  void getAX  (IloNumArray val, const IloForAllRangeArray con) const;
  void getDuals  (IloNumArray val, const IloForAllRangeArray con) const;
  void getSlacks (IloNumArray val, const IloForAllRangeArray con,
                  IloInt soln=IloCplex::IncumbentId) const;
  void getForAllRanges(IloForAllRangeArray rows,
                       IloConstraintI*     forall) const;

  void setBasisStatuses(const IloCplex::BasisStatusArray cstat,
                        const IloNumVarArray var,
                        const IloCplex::BasisStatusArray rstat,
                        const IloConstraintArray con);
  void setBasisStatuses(const IloCplex::BasisStatusArray cstat,
                        const IloIntVarArray var,
                        const IloCplex::BasisStatusArray rstat,
                        const IloConstraintArray con);

  void setStart(const IloNumArray    x,
                const IloNumArray    dj,
                const IloNumVarArray var,
                const IloNumArray    slack,
                const IloNumArray    pi,
                const IloRangeArray  rng);
  void setStart(const IloNumArray    x,
                const IloNumArray    dj,
                const IloIntVarArray var,
                const IloNumArray    slack,
                const IloNumArray    pi,
                const IloRangeArray  rng);

  /* MIPstart API */

  IloInt addMIPStart      (IloNumVarArray vars=0, IloNumArray values=0,
                           IloCplex::MIPStartEffort effort=IloCplex::MIPStartAuto,
                           const char *name=0);
  void changeMIPStart     (IloInt mipstartindex, IloNumVarArray vars, 
                           IloNumArray values);
  void changeMIPStart     (IloInt mipstartindex, IloNumVarArray vars, 
                           IloNumArray values,
                           IloCplex::MIPStartEffort effort);

  void deleteMIPStarts    (IloInt first, IloInt num=1);


  int                      getNMIPStarts() const;
  IloCplex::MIPStartEffort getMIPStart (IloInt               mipstartindex,
                                        const IloNumVarArray vars,
                                        IloNumArray          vals,
                                        IloBoolArray         isset);
  const char*              getMIPStartName (IloInt mipstartindex);
  IloInt                   getMIPStartIndex(const char *lname_str) const;
 
 
   IloBool fillElement (IloExtractable e, IloCarray<int>& tind,
                        IloCarray<char>& ttype) const;
   void fillGroup  (IloExtractable e, IloCarray<int>& tind,
                    IloCarray<char>& ttype,
                    IloExtractableArray tmp,
                    IloBool             fillSub) const;

  IloCarray<IloInt> _conflictGroupId;
  IloBool refineConflict(IloConstraintArray cons, IloNumArray prios);
  IloBool refineMIPStartConflict(IloInt mipstartindex, IloConstraintArray cons, IloNumArray prefs);
#ifndef ILOG_CPLEX_NO_REMOTE_API
  IloCplex::RefineConflictHandle refineConflict(IloConstraintArray cons,
                                                IloNumArray prios, bool async);
  IloCplex::RefineMIPStartConflictHandle refineMIPStartConflict(IloInt mipstartindex, IloConstraintArray cons, IloNumArray prefs, bool async);
#endif // !ILOG_CPLEX_NO_REMOTE_API
  void    getConflict(IloCplex::ConflictStatusArray& cstat,
                      IloNumVarArray&                var,
                      IloCplex::ConflictStatusArray& rstat,
                      IloConstraintArray&            rng);
  IloCplex::ConflictStatus      getConflict(IloConstraint      con ) const;
  IloCplex::ConflictStatusArray getConflict(IloConstraintArray cons) const;

  void setPriority(const IloNumVarI* var, IloNum pri);
  void setDirection (const IloNumVarI* var, IloCplex::BranchDirection dir);
  void delPriority  (const IloNumVarI* var);
  void delDirection (const IloNumVarI* var);

  void setPriorities(const IloNumVarArray& var, const IloNumArray& pri);
  void setPriorities(const IloIntVarArray& var, const IloNumArray& pri);
  void setDirections(const IloNumVarArray& var, const IloCplex::BranchDirectionArray& dir);
  void setDirections(const IloIntVarArray& var, const IloCplex::BranchDirectionArray& dir);
  void delPriorities(const IloNumVarArray& var);
  void delPriorities(const IloIntVarArray& var);
  void delDirections(const IloNumVarArray& var);
  void delDirections(const IloIntVarArray& var);

  void getPriorities(const IloNumVarArray var, IloNumArray pri) const;
  void getPriorities(const IloIntVarArray var, IloNumArray pri) const;
  void getDirections(const IloNumVarArray var, IloCplex::BranchDirectionArray dir) const;
  void getDirections(const IloIntVarArray var, IloCplex::BranchDirectionArray dir) const;
  IloNum getPriority(IloNumVar var) const;
  IloCplex::BranchDirection getDirection (IloNumVar var) const;

  void basicPresolve(const IloNumVarArray vars,
                     IloNumArray          redlb,
                     IloNumArray          redub,
                     const IloRangeArray  rngs,
                     IloBoolArray         redundant) const;
  void basicPresolve(const IloIntVarArray vars,
                     IloNumArray          redlb,
                     IloNumArray          redub,
                     const IloRangeArray  rngs,
                     IloBoolArray         redundant) const;

  void getDnorms(IloNumArray& dnorms, const IloNumVarArray& vars,
                                      const IloRangeArray&  cons) const;
  void getDnorms(IloNumArray& dnorms, const IloIntVarArray& vars,
                                      const IloRangeArray&  cons) const;
  void getPnorms(IloNumArray& cnorms, const IloNumVarArray& vars,
                 IloNumArray& rnorms, const IloRangeArray&  cons) const;
  void getPnorms(IloNumArray& cnorms, const IloIntVarArray& vars,
                 IloNumArray& rnorms, const IloRangeArray&  cons) const;
  void setDnorms(const IloNumArray& norms, const IloNumVarArray& vars,
                                           const IloRangeArray&  cons);
  void setDnorms(const IloNumArray& norms, const IloIntVarArray& vars,
                                           const IloRangeArray&  cons);
  void setPnorms(const IloNumArray& cnorms, const IloNumVarArray& vars,
                 const IloNumArray& rnorms, const IloRangeArray&  cons);
  void setPnorms(const IloNumArray& cnorms, const IloIntVarArray& vars,
                 const IloNumArray& rnorms, const IloRangeArray&  cons);

  void getRay(IloNumArray& vals, IloNumVarArray& vars) const;
  void getDriebeekPenalties(const IloExtractableArray&  ind,
                            IloNumArray&                downratio,
                            IloNumArray&                upratio) const;

  void getStrongBranch(const IloExtractableArray&  ind,
                       IloNumArray&                downratio,
                       IloNumArray&                upratio,
                       IloInt64                    itlim) const;

  IloNum getQuality(IloCplex::Quality q, IloInt         soln,
                                         IloNumVar*     var=0,
                                         IloConstraint* rng=0) const;

  IloNum getQuality(IloCplex::Quality q, IloInt soln,
                                         Index& var,
                                         Index& rng,
                                         Index& qc) const;

  IloBool feasOpt(const IloRangeArray  rngs,
                  const IloNumArray    rnglb,
                  const IloNumArray    rngub,
                  const IloNumVarArray vars,
                  const IloNumArray    varlb,
                  const IloNumArray    varub);
#ifndef ILOG_CPLEX_NO_REMOTE_API
  IloCplex::FeasOptHandle feasOpt (const IloRangeArray rows,
                                   const IloNumArray rnglb,
                                   const IloNumArray rngub,
                                   const IloNumVarArray cols,
                                   const IloNumArray varlb,
                                   const IloNumArray varub,
                                   bool async);
#endif // !ILOG_CPLEX_NO_REMOTE_API
  IloBool feasOpt(const IloRangeArray  rngs,
                  const IloNumArray    rnglb,
                  const IloNumArray    rngub,
                  const IloIntVarArray vars,
                  const IloNumArray    varlb,
                  const IloNumArray    varub);
#ifndef ILOG_CPLEX_NO_REMOTE_API
  IloCplex::FeasOptHandle feasOpt(const IloRangeArray  rngs,
                                  const IloNumArray    rnglb,
                                  const IloNumArray    rngub,
                                  const IloIntVarArray vars,
                                  const IloNumArray    varlb,
                                  const IloNumArray    varub,
                                  bool async);
#endif // !ILOG_CPLEX_NO_REMOTE_API

  IloBool feasOpt(const IloRangeArray       rngs,
                  const IloNumArray         rnglb,
                  const IloNumArray         rngub,
                  const IloForAllRangeArray rngf,
                  const IloNumArray         frnglb,
                  const IloNumArray         frngub,
                  const IloNumVarArray      vars,
                  const IloNumArray         varlb,
                  const IloNumArray         varub);
#ifndef ILOG_CPLEX_NO_REMOTE_API
  IloCplex::FeasOptHandle feasOpt(const IloRangeArray       rngs,
                                  const IloNumArray         rnglb,
                                  const IloNumArray         rngub,
                                  const IloForAllRangeArray rngf,
                                  const IloNumArray         frnglb,
                                  const IloNumArray         frngub,
                                  const IloNumVarArray      vars,
                                  const IloNumArray         varlb,
                                  const IloNumArray         varub,
                                  bool async);
#endif // !ILOG_CPLEX_NO_REMOTE_API
  IloBool feasOpt(const IloRangeArray       rngs,
                  const IloNumArray         rnglb,
                  const IloNumArray         rngub,
                  const IloForAllRangeArray rngf,
                  const IloNumArray         frnglb,
                  const IloNumArray         frngub,
                  const IloIntVarArray      vars,
                  const IloNumArray         varlb,
                  const IloNumArray         varub);
#ifndef ILOG_CPLEX_NO_REMOTE_API
  IloCplex::FeasOptHandle feasOpt(const IloRangeArray       rngs,
                                  const IloNumArray         rnglb,
                                  const IloNumArray         rngub,
                                  const IloForAllRangeArray rngf,
                                  const IloNumArray         frnglb,
                                  const IloNumArray         frngub,
                                  const IloIntVarArray      vars,
                                  const IloNumArray         varlb,
                                  const IloNumArray         varub,
                                  bool async);
#endif // !ILOG_CPLEX_NO_REMOTE_API

  IloBool feasOpt(const IloConstraintArray cts,
                  const IloNumArray        relax);
#ifndef ILOG_CPLEX_NO_REMOTE_API
  IloCplex::FeasOptHandle feasOpt(const IloConstraintArray cts,
                                  const IloNumArray        relax,
                                  bool async);
#endif // !ILOG_CPLEX_NO_REMOTE_API

#ifndef ILOG_CPLEX_NO_REMOTE_API
  IloCplex::PopulateHandle populate(bool async);
#endif // !ILOG_CPLEX_NO_REMOTE_API
  IloBool populate();

  IloInt  tuneParam(IloCplex::ParameterSet fixedset);
  IloInt  tuneParam(IloArray<const char *> filename,
                    IloCplex::ParameterSet fixedset);
#ifndef ILOG_CPLEX_NO_REMOTE_API
  IloCplex::TuneParamHandle tuneParam (IloCplex::ParameterSet fixedset,
                                       bool async);
#endif // !ILOG_CPLEX_NO_REMOTE_API

  IloExtractable getDiverging() const;

  void presolve(IloCplex::Algorithm alg);
#ifndef ILOG_CPLEX_NO_REMOTE_API
  IloCplex::PresolveHandle presolve(IloCplex::Algorithm alg, bool async);
#endif // !ILOG_CPLEX_NO_REMOTE_API
  void freePresolve();

  void getDualNorms(const IloExprArray& expr, IloNumArray& norms,
                    IloCplex::DualPricing dpriind) const;
  void protectVariables(const IloNumVarArray& var);
  void protectVariables(const IloIntVarArray& var);


  IloNum dualFarkas (IloExtractableArray& rind, IloNumArray& y);
  void qpIndefCertificate (IloExtractableArray& ind, IloNumArray& x);

  // cplex function methods stubs

  const char* getVersion() const;
  int getVersionNumber() const;

  int getNcols() const { return (_nCols); }
  int getNrows() const { return (_nRows); }
  int getNQCs() const { return (_nQCs); }
  int getNSOSs() const { return (_nSOS); }
  int getNindicators() const { return getCplexNindicators(); }
  int getNLCs() const { return getCplexNLCs(); }
  int getNUCs() const { return getCplexNUCs(); }
  IloInt64 getNNZs () const;
  int getNintVars() const;
  int getNbinVars() const;
  int getNsemiContVars() const;
  int getNsemiIntVars() const;

  int getCplexNcols() const;
  int getCplexNrows() const;
  int getCplexNQCs() const;
  int getCplexNindicators() const;
  int getCplexNLCs() const;
  int getCplexNUCs() const;
  IloInt64 getNiterations() const;
  IloInt64 getNbarrierIterations() const;
  IloInt64 getNsiftingIterations() const;
  IloInt64 getNsiftingPhaseOneIterations() const;

  enum Type {
    NoType   = '\0',             // don't document "NoType"
    Cont     = CPX_CONTINUOUS,
    Bin      = CPX_BINARY,
    Int      = CPX_INTEGER,
    SemiInt  = CPX_SEMIINT,
    SemiCont = CPX_SEMICONT
  };
  typedef IloArray<Type> TypeArray;

  IloNum getLb(Index col) const         { validateLb(); return (_lb[*col]); }
  IloNum getUb(Index col) const         { validateUb(); return (_ub[*col]); }
  Type   getType(Index var) const       { return ((Type)_ctype[*var]); }
  Type   getConvType(Index var) const   { return ((Type)_convtype[*var]); }
  IloNum getCoef(Index row, Index col) const;
  void   getLbs(IloNumArray& val, const IndexArray& col) const;
  void   getUbs(IloNumArray& val, const IndexArray& col) const;
  void   getType(TypeArray& type, const IndexArray& col) const ;
  void   getConvType(TypeArray& type, const IndexArray& col) const ;
  void   getRowCoefs(Index row, IloNumArray& val, const IndexArray& col) const;
  void   getRow   (Index row, IloNumArray& val, IndexArray& col) const;

  IloBool isMIP() const;
  IloBool isQC() const     { return (_nQCs > 0); }
  IloBool isQO() const      { return (_hasQ); }

  int    getObjSense() const;
  IloNum getObjOffset() const;
  IloNum getObjCoef(Index col) const;
  void   getObjCoefs(IloNumArray& obj, const IndexArray& col) const;
  void   getObj     (IloNumArray& obj, IndexArray& col) const;
  void   getLinearObj(IloNumArray& obj, IloNumVarArray col) const;
  void   getQuadraticObj(IloNumArray& obj, IloNumVarArray col1,
                                           IloNumVarArray col2) const;

  void setObjOffset(double offset);
  void setObjSense (int sense);
  void setObjCoef  (double val, Index col);
  void setObjCoefs (const IloNumArray& obj, const IndexArray& col);
  void setObj      (int sense, const IloNumArray& obj, const IndexArray& col, IloNum offset);
  void setObj      (int sense, const IloCarray<double>& obj,
                               const IloCarray<Index>& col, IloNum offset);
  void setObjQuadCoef(double obj, Index row, Index col);

  void copyQ(const CPXNNZ* beg, const CPXDIM* cnt,
             const CPXDIM* ind, const double* val);
  void clearQ();

  void tightenLb(Index var, IloNum bd);
  void tightenUb(Index var, IloNum bd);

  void setBounds(Index var, IloNum lb, IloNum ub);
  void setBounds(const IndexArray& col,
                 const IloNumArray& lb,
                 const IloNumArray& ub);
  void setBounds(const IndexArray& col,
                 const IloCarray<double>& lb,
                 const IloCarray<double>& ub);

  void setType     (const IndexArray& col, const TypeArray& type);
  void setConvType (const IndexArray& col, const TypeArray& type);
  void setType     (Index var, Type type);
  void setConvType (Index var, Type type);
  void setType (Index var, IloNumVar::Type type) {
    setType(var, (type == ILOFLOAT) ? Cont : (type == ILOINT) ? Int : Bin);
  }

   // Added for use with IloForAllRange
  IloBool setLB(const IndexArray& row, const IloNumArray& lb);
  IloBool setUB(const IndexArray& row, const IloNumArray&  ub);
  IloBool setUB(Index row, const IloNum ub);
  IloBool setLB(Index row, const IloNum lb);
  IloBool setUB(CPXDIM num, const CPXDIM *row, const double* ub);
  IloBool setLB(CPXDIM num, const CPXDIM *row, const double* lb);

  IloBool setRange(Index row, double lb, double ub);
  IloBool setRange(const IndexArray& row,
                   const IloNumArray&     lb,
                   const IloNumArray&     ub);
  IloBool setRange(const IndexArray&  row,
                   const IloCarray<double>& lb,
                   const IloCarray<double>& ub);
  IloBool setQCRange(Index row, double lb, double ub);

  void setCoef (double val, Index row, Index col);
  void setRowCoefs(Index row, const IloNumArray& val, const IndexArray& col);
  void clearRow(Index row);

  void removeRow    (Index  row);
  void removeRows   (const IndexArray& rows);
  void removeColumn (Index  col);
  void removeColumns(const IndexArray& cols);
  void removeQC     (Index  qcp);
  void removeQCs    (const IndexArray& qcps);
  void fixQCs       ();
  void removeSOS    (Index sos);
  void removeSOSs   (const IndexArray& soss);
  void removeGC     (Index index, int type);

  IloBool solve();
  IloBool solveFixed(IloInt soln);
#ifndef ILOG_CPLEX_NO_REMOTE_API
  IloCplex::SolveHandle solve(bool async);
  IloCplex::SolveFixedHandle solveFixed(IloInt soln, bool async);
#endif

  IloAlgorithm::Status  getStatus() const;
  IloCplex::CplexStatus getCplexStatus() const;
  IloCplex::CplexStatus getCplexSubStatus() const;
  int                   isPrimalFeasible() const;
  int                   isDualFeasible() const;
  IloCplex::Algorithm   getAlgorithm() const;
  IloCplex::Algorithm   getSubAlgorithm() const;


  IloNum getObjValue() const;
  IloNum getBestObjValue() const;
  IloNum getMIPRelativeGap() const;
  IloNum getCutoff() const;
  IloInt64 getIncumbentNode() const;
  IloInt getNprimalSuperbasics() const;
  IloInt getNdualSuperbasics() const;
  IloInt64 getNphaseOneIterations() const;
  IloInt64 getNnodes() const;
  IloInt64 getNnodesLeft() const;
  IloInt getNcuts(IloCplex::CutType which) const;
  IloInt64 getNcrossPPush() const;
  IloInt64 getNcrossPExch() const;
  IloInt64 getNcrossDPush() const;
  IloInt64 getNcrossDExch() const;

  IloNum getX (Index j) const {
    flush();
    if ( !_x.isValid() ) validateX();
    return (_x[*j]);
  }
  IloNum getPi(Index i) const {
    flush();
    if ( !_pi.isValid() ) validatePi();
    return (_pi[*i]);
  }
  IloNum getDj(Index j) const {
    flush();
    if ( !_dj.isValid() ) validateDj();
    return (_dj[*j]);
  }
  IloNum getSlack(Index i) const {
    flush();
    if ( !_slack.isValid() ) validateSlack();
    return (_slack[*i]);
  }
  IloNum getQCSlack(Index i) const {
    flush();
    if ( !_qcslack.isValid() ) validateQCSlack();
    return (_qcslack[*i]);
  }
  IloNum getSolnPoolX (Index j, IloInt soln) const {
    flush();
    if ( !_solnpoolx.isValid(soln) ) validateSolnPoolX(soln);
    return (_solnpoolx[*j]);
  }
  IloNum getSolnPoolSlack(Index i, IloInt soln) const {
    flush();
    if ( !_solnpoolslack.isValid(soln) ) validateSolnPoolSlack(soln);
    return (_solnpoolslack[*i]);
  }
  IloNum getSolnPoolQCSlack(Index i, IloInt soln) const {
    flush();
    if ( !_solnpoolqcslack.isValid(soln) ) validateSolnPoolQCSlack(soln);
    return (_solnpoolqcslack[*i]);
  }

  IloNum getRowInfeasibility(Index i) const;
  IloNum getQCInfeasibility(Index i) const;
  IloNum getSOSInfeasibility(Index i) const;
  IloNum getIndInfeasibility(Index i) const;
  IloNum getColInfeasibility(Index i) const;

  IloCplex::BasisStatus getRowStatus(Index index) const {
    flush();
    if ( !_rstat.isValid() ) validateRowStatus();
    return (_rstat[*index]);
  }
  IloCplex::BasisStatus getColumnStatus(Index index) const {
    flush();
    if ( !_cstat.isValid() ) validateColumnStatus();
    return (_cstat[*index]);
  }

  IloNum getAX(Index row) const;
  IloNum getQCAX(Index row) const;

  void deleteDnorms();
  void deletePnorms();

  const IloNumVarI*      getColumnExtractable(Index col) const;
  const IloExtractableI* getRowExtractable(Index row) const;
  const IloExtractableI* getQCExtractable(Index qcp) const;
  const IloExtractableI* getSOSExtractable(Index sos) const;

  IloBool isQuadratic(const IloConstraintI* rng, Index index) const;

  void        setDefaults();
  void        setParam(IloCplex::IntParam    parameter, CPXINT value);
  void        setParam(IloCplex::LongParam    parameter, CPXLONG value);
  void        setParam(IloCplex::BoolParam   parameter, IloBool value);
  void        setParam(IloCplex::NumParam  parameter, IloNum value);
  void        setParam(IloCplex::StringParam parameter, const char* value);

  CPXINT      getParam(IloCplex::IntParam    parameter) const;
  CPXLONG     getParam(IloCplex::LongParam    parameter) const;
  IloBool     getParam(IloCplex::BoolParam   parameter) const;
  IloNum      getParam(IloCplex::NumParam  parameter) const;
  const char* getParam(IloCplex::StringParam parameter) const;

  IloBool     getDefault(IloCplex::BoolParam   parameter) const;
  CPXINT      getDefault(IloCplex::IntParam    parameter) const;
  CPXLONG     getDefault(IloCplex::LongParam    parameter) const;
  IloNum      getDefault(IloCplex::NumParam  parameter) const;
  const char* getDefault(IloCplex::StringParam parameter) const;
  CPXINT      getMin(IloCplex::IntParam    parameter) const;
  CPXLONG     getMin(IloCplex::LongParam    parameter) const;
  IloNum      getMin(IloCplex::NumParam  parameter) const;
  CPXINT      getMax(IloCplex::IntParam    parameter) const;
  CPXLONG     getMax(IloCplex::LongParam    parameter) const;
  IloNum      getMax(IloCplex::NumParam  parameter) const;

  void applyParameterSet(IloCplex::ParameterSetI* set);
  void extractParameterSet(IloCplex::ParameterSetI* set);

  void exportModel(const char* name);
  void writeOrder (const char* name);
  void writeConflict (const char* name);
  void writeParam(const char* name);
  void writeBasis(const char* name);
  void writeSolution(const char* name, IloInt soln=IloCplex::IncumbentId);
  void writeMIPStarts(const char* name, IloInt first, IloInt num);
  void writeSolutions(const char *name);
  void qreport(IloInt soln=IloCplex::IncumbentId);
  void qreport(ILOSTD(ostream)& out, IloInt soln=IloCplex::IncumbentId);

  void readOrder (const char* name);
  void readParam(const char* name);
  void readBasis(const char* name);
  void readSolution(const char* name);
  void readMIPStarts(const char* name);

  void clear();

  typedef IloCplexRow    Row;
  typedef IloCplexColumn Column;
  typedef IloCplexSOS    SOS;

  Row    getRow   (Index i);
  Column getColumn(Index j);
  Index makeRow(const IloExtractableI* obj, IloNum lb, IloNum ub,
                const char *name);
  Index makeCol(const IloExtractableI* obj, IloNum lb,
                IloNum ub, IloNumVar::Type type,
                const char *name);
  Index addSOS (const IloExtractableI*   obj,
                int                      type,
                const IloCarray<Index>&  ind,
                const IloCarray<double>& wt,
                const char*              name);

  Index addQC (const IloExtractableI*   obj,
               const IloCarray<double>& linVals,
               const IloCarray<Index>&  linVars,
               const IloCarray<double>& qVals,
               const IloCarray<Index>&  qVars1,
               const IloCarray<Index>&  qVars2,
               int sense, double rhs,
               const char *name);

  Index makeGC (const IloExtractableI* obj, int type);

  // For the Goal API
  class GoalStack {
  public:
    GoalStack(IloCplex::Goal goal,
              GoalStack *prev) : _goal(goal),
                                 _prev(prev) {}

    IloCplex::Goal          _goal;
    GoalStack    *_prev;
  };

  IloBool      solve(IloCplex::Goal goal);

  CpxNodeI    *getRootNode() const { return _rootNode; }
  IloCplex::Goal getRootGoal() const { return _rootGoal; }
  IloCplex::GoalBaseI* getLastGoal() const { return _lastGoal; }

  IloInt getGCutsSize() const { return _globalCuts.getSize(); }
  void  addGlobalCuts(IloInt thread, IloConstraintArray rng);
  void  clearGlobalCuts(IloInt thread);
  IloConstraintArray getGlobalCuts(IloInt thread) 
    { return _globalCuts[thread]; }

  IloCplexMutex *getGCutMutex(IloInt thread) { return _gCutMutex[thread]; }
  IloCplexMutex *getIdMutex() const { return _idMutex; }

  IloInt        getNewEvalId() { return _evalId++; }

  void         setDefaultSearch( IloBool uses ) { _usesEval = !uses; }
  IloBool      useDefaultSearch( ) { return !_usesEval; }

  IloCplex::BranchCallbackI    *getBCallback() const { return _branchCallback;}
  IloCplex::NodeCallbackI      *getNCallback() const { return _nodeCallback; }
  IloCplex::IncumbentCallbackI *getICallback() const { return _incCallback; }
  IloCplex::UserCutCallbackI   *getUCCallback() const {
    return _ucCallback;
  }
  IloCplex::LazyConstraintCallbackI *getLCCallback() const {
    return _lcCallback;
  }
  // END: For Goal API

  IloNum getSolnPoolMeanObjValue() const;
  IloInt getSolnPoolNsolns() const;
  IloInt getSolnPoolNreplaced() const;
  void delSolnPoolSolns(IloInt begin, IloInt end);

  class Filter {
     public:
     IloCplex::FilterType _type;
     int                  _num;
     IloNum               _lb;
     IloNum               _ub;
     double               *_weight;
     Index                *_var;
     double               *_refval;
     char                 *_name;
     ~Filter ();
     Filter (const IloCplexI*     cplex,
             IloCplex::FilterType type,
	     IloNum               lb,
	     IloNum               ub,
	     const IloNumVarArray var,
	     const IloNumArray    weight,
	     const IloNumArray    refval,
	     const char           *name = 0);
     Filter(const IloCplexI* cplex, int type, double lb,
	    double ub, int num, int* var, double* weight,
	    double* refval, char* name);
  };
  friend class Filter;
  IloArray<Filter*> _filter;

  void flushFilters();
  void delFilters();
  void delFiltersFromLP();
  void removeFromFilters(Index col);
  void removeFromFilters(const IndexArray cols, IloCarray<int>& mark);

  IloCplex::FilterIndex addDiversityFilter(IloNum lower_cutoff, IloNum upper_cutoff,
			   const IloNumVarArray vars,
			   const IloNumArray weights,
			   const IloNumArray refval, const char *fname = 0);
  IloCplex::FilterIndex addDiversityFilter(IloNum lower_cutoff, IloNum upper_cutoff,
			   const IloIntVarArray vars,
			   const IloNumArray weights,
			   const IloNumArray refval, const char *fname = 0);
  IloCplex::FilterIndex getFilterIndex(const char *lname_str) const;
  IloInt getNfilters() const;
  IloCplex::FilterType getFilterType(IloCplex::FilterIndex filter) const;
  IloNum getFilterLowerBound(IloCplex::FilterIndex filter) const;
  IloNum getFilterUpperBound(IloCplex::FilterIndex filter) const;
  void getFilterVars(IloCplex::FilterIndex filter, IloNumVarArray) const;
  //void getFilterVars(IloCplex::FilterIndex filter, IloIntVarArray) const;
  void getFilterWeights(IloCplex::FilterIndex filter, IloNumArray) const;
  void getFilterRefVals(IloCplex::FilterIndex filter, IloNumArray) const;
  IloCplex::FilterIndex addRangeFilter(IloNum, IloNum, const IloNumVarArray,
		      const IloNumArray, const char* = 0);
  IloCplex::FilterIndex addRangeFilter(IloNum, IloNum, const IloIntVarArray,
		      const IloNumArray, const char* = 0);

  void delFilter(IloCplex::FilterIndex filter);
  IloCplex::FilterIndexArray readFilters(const char* name);
  void writeFilters(const char*);

  IloArray<IloExprExtractor* (*)(IloEnv, IloColumnExtractor*)> _colextrAdd;
  IloArray<IloLPExtractor* (*)(IloEnv, IloDefaultLPExtractor*)> _defextrAdd;
  IloArray<IloLPExtractor* (*)(IloEnv, IloExprParser*)> _qpextrAdd;
  IloArray<IloLPExtractor* (*)(IloEnv, IloLogicalExtractor*)> _logextrAdd;
  IloArray<void (*)(IloExprExtractor*)> _colextrRemove;
  IloArray<void (*)(IloLPExtractor*)> _defextrRemove;
  IloArray<void (*)(IloLPExtractor*)> _qpextrRemove;
  IloArray<void (*)(IloLPExtractor*)> _logextrRemove;

#ifndef ILOG_CPLEX_NO_REMOTE_API
private:
  IloCplex::RemoteInfoHandler *_remoteinfo;
public:
#endif

  IloNum getCplexTime() const;

  IloNum getDetTime() const;

  int    getNumCores() const;

#ifndef ILOG_CPLEX_NO_REMOTE_API
  friend class IloCplexIRemoteInfoHandlerInvoke;
  IloCplex::RemoteInfoHandler *setRemoteInfoHandler(IloCplex::RemoteInfoHandler *handler);
  IloCplex::RemoteInfoHandler *getRemoteInfoHandler() const;
  IloCplex::RemoteInfoHandler *removeRemoteInfoHandler();

  int userfunction (int id, CPXLONG inlen, void const *in,
                    CPXLONG outcap, CPXLONG *outlen_p, void *out);

  void transportctrl(int ctrl, CPXINT &data) const;
  void transportctrl(int ctrl, CPXLONG &data) const;
  void transportctrl(int ctrl, double &data) const;

#endif

#ifndef ILOG_CPLEX_NO_DISTRIBUTED_MIP_API
  bool hasVMConfig () const;
  template<typename T> void copyVMConfig(T xmlstring) { copyVMConfig (xmlstring, CPXcopyvmconfig, CPXdelvmconfig, CPXdistmipopt); }
  template<typename T> void readVMConfig(T file) { readVMConfig (file, CPXreadcopyvmconfig, CPXdelvmconfig, CPXdistmipopt); }
  void delVMConfig ();
#endif // !ILOG_CPLEX_NO_DISTRIBUTED_MIP_API

  struct IloCpxAnnotations *_anno;

  void readAnnotations (const char* name);
  void writeAnnotations (const char* name) const;
  void writeBendersAnnotation (const char* name) const;

  IloInt     numLongAnnotations () const;
  void       delAnnotation (IloCplex::LongAnnotation anno);
  const char *getName(const IloCplex::LongAnnotation annotation) const;

  void freeAnnotations();

  IloCplex::LongAnnotation newLongAnnotation  (const char *name, IloInt64 defval = 0.0);
  IloCplex::LongAnnotation findLongAnnotation (const char *name) const;
  IloCplex::LongAnnotation findLongAnnotation (IloInt num) const;
  IloBool                  hasLongAnnotation  (const char *name) const;

  IloInt64 getDefaultValue (const IloCplex::LongAnnotation annotation) const;

  IloInt64 getAnnotation (const IloCplex::LongAnnotation annotation, const IloExtractableI* obj) const;
  void     getAnnotation (const IloCplex::LongAnnotation annotation, const IloExtractableArray obj, IloArray<IloInt64>& value) const;

  void     setAnnotation (const IloCplex::LongAnnotation annotation, const IloExtractableI* obj, IloInt64 value);
  void     setAnnotation (const IloCplex::LongAnnotation annotation, const IloExtractableArray obj, const IloArray<IloInt64> value);

  IloInt     numNumAnnotations () const;
  void       delAnnotation (IloCplex::NumAnnotation anno);
  const char *getName(const IloCplex::NumAnnotation annotation) const;

  IloCplex::NumAnnotation   newNumAnnotation  (const char *name, IloNum defval = 0.0);
  IloCplex::NumAnnotation   findNumAnnotation (const char *name) const;
  IloCplex::NumAnnotation   findNumAnnotation (IloInt num) const;
  IloBool                   hasNumAnnotation  (const char *name) const;

  IloNum   getDefaultValue (const IloCplex::NumAnnotation annotation) const;

  IloNum getAnnotation (const IloCplex::NumAnnotation annotation, const IloExtractableI* obj) const;
  void   getAnnotation (const IloCplex::NumAnnotation annotation, const IloExtractableArray obj, IloNumArray& value) const;
  void   setAnnotation (const IloCplex::NumAnnotation annotation, const IloExtractableI* obj, IloNum value);
  void   setAnnotation (const IloCplex::NumAnnotation annotation, const IloExtractableArray obj, const IloNumArray value);

  int getAnnotationData (const IloExtractableI* obj, CPXDIM *idx) const;
};


class IloCplexColumn {
protected:
  IloCplexI* _cplex;
  int        _col;
  friend class IloCplexI;

  IloCplexColumn(IloCplexI* cplex, int j)
    : _cplex(cplex), _col(j) {
  }

public:
  void add(IloNum val, int row);
  void add(IloNum val, IloCplex::Index row);
  void add(IloCplex::Index row, IloNum val);
  void setName(const char *name);
};


class IloCplexRow {
protected:
  IloCplexI* _cplex;
  int        _row;
  friend class IloCplexI;

  void resizeNz();
  void resize();

  IloCplexRow(IloCplexI* cplex, int j)
    : _cplex(cplex), _row(j) {
  }

public:
  void add (IloNum val, int col);
  void add (IloNum val, IloCplex::Index col);
  void add (IloCplex::Index col, IloNum val);
  void setName(const char *name);
};

class IloCplexAborterI {
  friend class IloCplexI;
  friend class Aborter;
  volatile int _abort;
  IloEnvI*     _env;
  IloArray<IloCplexI*> _cplexList;
  void registerIloCplexI(IloCplexI*);
  void unregisterIloCplexI(IloCplexI*);
 public:
  IloCplexAborterI(IloEnv env);
  ~IloCplexAborterI();
  void     abort();
  void     clear();
  IloBool  isAborted();


  void operator delete (void *, size_t);
#if defined (ILODELETEOPERATOR)
  void operator delete(void*, const IloEnvI*) {}
  void operator delete(void*, const IloEnv&) {}
#endif
};

/////////////////////////////////////////////////////////////////////////
//
// inline implementations
//

inline IloCplexI::Column
IloCplexI::getColumn(Index j) {
  return (IloCplexI::Column(this, *j));
}

inline IloCplexI::Row
IloCplexI::getRow(Index i) {
  return (IloCplexI::Row(this, *i));
}

/////////////////////////////////////////////////////////////////////////
//
// inline implementations for IloCplex
//

inline const char* IloCplex::getVersion() const {
  IloAssert (getImpl(), "accessing IloCplex through 0 handle");
  return (getImpl()->getVersion());
}
 
inline int IloCplex::getVersionNumber() const {
  IloAssert (getImpl(), "accessing IloCplex through 0 handle");
  return (getImpl()->getVersionNumber());
}

inline void
IloCplex::flush() {
  IloAssert(getImpl(), "accessing IloCplex through 0 handle");
  getImpl()->flush();
}

inline IloBool
IloCplex::solveFixed(IloInt soln) {
  IloAssert(getImpl(), "accessing IloCplex through 0 handle");
  return (getImpl()->solveFixed(soln));
}

inline IloBool
IloCplex::isMIP() const {
  IloAssert(getImpl(), "accessing IloCplex through 0 handle");
  getImpl()->flush();
  return (getImpl()->isMIP());
}

inline IloBool
IloCplex::isQC() const {
  IloAssert(getImpl(), "accessing IloCplex through 0 handle");
  getImpl()->flush();
  return (getImpl()->isQC());
}

inline IloBool
IloCplex::isQO() const {
  IloAssert(getImpl(), "accessing IloCplex through 0 handle");
  getImpl()->flush();
  return (getImpl()->isQO());
}

inline void
IloCplex::setDeleteMode(IloCplex::DeleteMode mode) {
  IloAssert(getImpl(), "accessing IloCplex through 0 handle");
  getImpl()->setDeleteMode(mode);
}

inline IloCplex::DeleteMode
IloCplex::getDeleteMode() const {
  IloAssert(getImpl(), "accessing IloCplex through 0 handle");
  return (getImpl()->getDeleteMode());
}

inline IloNum
IloCplex::getBestObjValue() const {
  IloAssert (getImpl(), "accessing IloCplex through 0 handle");
  return (getImpl()->getBestObjValue());
}

inline IloNum
IloCplex::getMIPRelativeGap() const {
  IloAssert (getImpl(), "accessing IloCplex through 0 handle");
  return (getImpl()->getMIPRelativeGap());
}
inline IloNum
IloCplex::getCutoff() const {
  IloAssert (getImpl(), "accessing IloCplex through 0 handle");
  return (getImpl()->getCutoff());
}

inline IloInt64
IloCplex::getIncumbentNode64() const {
  IloAssert (getImpl(), "accessing IloCplex through 0 handle");
  return (getImpl()->getIncumbentNode());
}

inline IloInt
IloCplex::getIncumbentNode() const {
  return (IloCplex::int64to32(getIncumbentNode64()));
}

inline IloInt
IloCplex::getNprimalSuperbasics() const {
  IloAssert (getImpl(), "accessing IloCplex through 0 handle");
  return (getImpl()->getNprimalSuperbasics());
}

inline IloInt
IloCplex::getNdualSuperbasics() const {
  IloAssert (getImpl(), "accessing IloCplex through 0 handle");
  return (getImpl()->getNdualSuperbasics());
}

inline IloInt64
IloCplex::getNphaseOneIterations64() const {
  IloAssert (getImpl(), "accessing IloCplex through 0 handle");
  return (getImpl()->getNphaseOneIterations());
}

inline IloInt
IloCplex::getNphaseOneIterations() const {
  return (IloCplex::int64to32(getNphaseOneIterations64()));
}

inline IloInt64
IloCplex::getNnodes64() const {
  IloAssert (getImpl(), "accessing IloCplex through 0 handle");
  return (getImpl()->getNnodes());
}

inline IloInt
IloCplex::getNnodes() const {
  return (IloCplex::int64to32 (getNnodes64()));
}

inline IloInt64
IloCplex::getNnodesLeft64() const {
  IloAssert (getImpl(), "accessing IloCplex through 0 handle");
  return (getImpl()->getNnodesLeft());
}

inline IloInt
IloCplex::getNnodesLeft() const {
  return (IloCplex::int64to32 (getNnodesLeft64()));
}

inline IloInt
IloCplex::getNcuts(IloCplex::CutType which) const {
  IloAssert (getImpl(), "accessing IloCplex through 0 handle");
  return (getImpl()->getNcuts(which));
}

inline IloInt64
IloCplex::getNcrossPPush64() const {
  IloAssert (getImpl(), "accessing IloCplex through 0 handle");
  return (getImpl()->getNcrossPPush());
}

inline IloInt
IloCplex::getNcrossPPush() const {
  return (IloCplex::int64to32 (getNcrossPPush64()));
}

inline IloInt64
IloCplex::getNcrossPExch64() const {
  IloAssert (getImpl(), "accessing IloCplex through 0 handle");
  return (getImpl()->getNcrossPExch());
}

inline IloInt
IloCplex::getNcrossPExch() const {
  return (IloCplex::int64to32 (getNcrossPExch64()));
}

inline IloInt64
IloCplex::getNcrossDPush64() const {
  IloAssert (getImpl(), "accessing IloCplex through 0 handle");
  return (getImpl()->getNcrossDPush());
}

inline IloInt
IloCplex::getNcrossDPush() const {
  return (IloCplex::int64to32 (getNcrossDPush64()));
}

inline IloInt64
IloCplex::getNcrossDExch64() const {
  IloAssert (getImpl(), "accessing IloCplex through 0 handle");
  return (getImpl()->getNcrossDExch());
}

inline IloInt
IloCplex::getNcrossDExch() const {
  return (IloCplex::int64to32 (getNcrossDExch64()));
}

inline IloInt64
IloCplex::getNiterations64() const {
  IloAssert (getImpl(), "accessing IloCplex through 0 handle");
  return (getImpl()->getNiterations());
}

inline IloInt
IloCplex::getNiterations() const {
  return (IloCplex::int64to32 (getNiterations64()));
}

inline IloInt64
IloCplex::getNbarrierIterations64() const {
  IloAssert (getImpl(), "accessing IloCplex through 0 handle");
  return (getImpl()->getNbarrierIterations());
}

inline IloInt
IloCplex::getNbarrierIterations() const {
  return (IloCplex::int64to32 (getNbarrierIterations64()));
}

inline IloInt64
IloCplex::getNsiftingIterations64() const {
  IloAssert (getImpl(), "accessing IloCplex through 0 handle");
  return (getImpl()->getNsiftingIterations());
}

inline IloInt
IloCplex::getNsiftingIterations() const {
  return (IloCplex::int64to32 (getNsiftingIterations64()));
}

inline IloInt64
IloCplex::getNsiftingPhaseOneIterations64() const {
  IloAssert (getImpl(), "accessing IloCplex through 0 handle");
  return (getImpl()->getNsiftingPhaseOneIterations());
}

inline IloInt
IloCplex::getNsiftingPhaseOneIterations() const {
  return (IloCplex::int64to32 (getNsiftingPhaseOneIterations64()));
}

inline IloInt   IloCplex::getNcols() const {
  IloAssert (getImpl(), "accessing IloCplex through 0 handle");
  return (getImpl()->getNcols());
}

inline IloInt   IloCplex::getNrows() const {
  IloAssert (getImpl(), "accessing IloCplex through 0 handle");
  return (getImpl()->getNrows());
}

inline IloInt   IloCplex::getNQCs() const {
  IloAssert (getImpl(), "accessing IloCplex through 0 handle");
  return (getImpl()->getNQCs());
}

inline IloInt IloCplex::getNintVars() const {
  IloAssert (getImpl(), "accessing IloCplex through 0 handle");
  return (getImpl()->getNintVars());
}

inline IloInt IloCplex::getNbinVars() const {
  IloAssert (getImpl(), "accessing IloCplex through 0 handle");
  return (getImpl()->getNbinVars());
}

inline IloInt IloCplex::getNsemiContVars() const {
  IloAssert (getImpl(), "accessing IloCplex through 0 handle");
  return (getImpl()->getNsemiContVars());
}

inline IloInt IloCplex::getNsemiIntVars() const {
  IloAssert (getImpl(), "accessing IloCplex through 0 handle");
  return (getImpl()->getNsemiIntVars());
}

inline IloInt64
IloCplex::getNNZs64() const {
  IloAssert (getImpl(), "accessing IloCplex through 0 handle");
  return (getImpl()->getNNZs());
}

inline IloInt
IloCplex::getNNZs() const {
  return (IloCplex::int64to32 (getNNZs64()));
}

inline IloInt   IloCplex::getNSOSs() const {
  IloAssert (getImpl(), "accessing IloCplex through 0 handle");
  return (getImpl()->getNSOSs());
}

inline IloInt IloCplex::getNindicators() const {
  IloAssert (getImpl(), "accessing IloCplex through 0 handle");
  return (getImpl()->getNindicators());
}

inline IloInt IloCplex::getNLCs() const {
  IloAssert (getImpl(), "accessing IloCplex through 0 handle");
  return (getImpl()->getNLCs());
}

inline IloInt IloCplex::getNUCs() const {
  IloAssert (getImpl(), "accessing IloCplex through 0 handle");
  return (getImpl()->getNUCs());
}

inline void IloCplex::setDefaults() {
  IloAssert (getImpl(), "accessing IloCplex through 0 handle");
  getImpl()->setDefaults();
}

inline void IloCplex::setParam(IntParam parameter, CPXINT value) {
  IloAssert (getImpl(), "accessing IloCplex through 0 handle");
  getImpl()->setParam(parameter, value);
}

inline void IloCplex::setParam(LongParam parameter, CPXLONG value) {
  IloAssert (getImpl(), "accessing IloCplex through 0 handle");
  getImpl()->setParam(parameter, value);
}

inline void IloCplex::setParam(BoolParam parameter, IloBool value) {
  IloAssert (getImpl(), "accessing IloCplex through 0 handle");
  getImpl()->setParam(parameter, value);
}

inline void IloCplex::setParam(NumParam parameter, IloNum value) {
  IloAssert (getImpl(), "accessing IloCplex through 0 handle");
  getImpl()->setParam(parameter, value);
}

inline void IloCplex::setParam(StringParam parameter, const char* value) {
  IloAssert (getImpl(), "accessing IloCplex through 0 handle");
  getImpl()->setParam(parameter, value);
}

inline CPXINT IloCplex::getParam(IntParam parameter) const {
  IloAssert (getImpl(), "accessing IloCplex through 0 handle");
  return (getImpl()->getParam(parameter));
}

inline CPXLONG IloCplex::getParam(LongParam parameter) const {
  IloAssert (getImpl(), "accessing IloCplex through 0 handle");
  return (getImpl()->getParam(parameter));
}

inline IloBool IloCplex::getParam(BoolParam parameter) const {
  IloAssert (getImpl(), "accessing IloCplex through 0 handle");
  return (getImpl()->getParam(parameter));
}

inline IloNum IloCplex::getParam(NumParam parameter) const {
  IloAssert (getImpl(), "accessing IloCplex through 0 handle");
  return (getImpl()->getParam(parameter));
}

inline const char* IloCplex::getParam(StringParam parameter) const {
  IloAssert (getImpl(), "accessing IloCplex through 0 handle");
  return (getImpl()->getParam(parameter));
}

inline IloBool     IloCplex::getDefault(BoolParam   parameter) const {
  IloAssert (getImpl(), "accessing IloCplex through 0 handle");
  return (getImpl()->getDefault(parameter));
}
inline CPXINT      IloCplex::getDefault(IntParam    parameter) const {
  IloAssert (getImpl(), "accessing IloCplex through 0 handle");
  return (getImpl()->getDefault(parameter));
}
inline CPXLONG     IloCplex::getDefault(LongParam   parameter) const {
  IloAssert (getImpl(), "accessing IloCplex through 0 handle");
  return (getImpl()->getDefault(parameter));
}
inline IloNum      IloCplex::getDefault(NumParam  parameter) const {
  IloAssert (getImpl(), "accessing IloCplex through 0 handle");
  return (getImpl()->getDefault(parameter));
}
inline const char* IloCplex::getDefault(StringParam parameter) const {
  IloAssert (getImpl(), "accessing IloCplex through 0 handle");
  return (getImpl()->getDefault(parameter));
}
inline CPXINT      IloCplex::getMin(IntParam    parameter) const {
  IloAssert (getImpl(), "accessing IloCplex through 0 handle");
  return (getImpl()->getMin(parameter));
}
inline CPXLONG     IloCplex::getMin(LongParam   parameter) const {
  IloAssert (getImpl(), "accessing IloCplex through 0 handle");
  return (getImpl()->getMin(parameter));
}
inline IloNum      IloCplex::getMin(NumParam  parameter) const {
  IloAssert (getImpl(), "accessing IloCplex through 0 handle");
  return (getImpl()->getMin(parameter));
}
inline CPXINT      IloCplex::getMax(IntParam    parameter) const {
  IloAssert (getImpl(), "accessing IloCplex through 0 handle");
  return (getImpl()->getMax(parameter));
}
inline CPXLONG     IloCplex::getMax(LongParam   parameter) const {
  IloAssert (getImpl(), "accessing IloCplex through 0 handle");
  return (getImpl()->getMax(parameter));
}
inline IloNum      IloCplex::getMax(NumParam  parameter) const {
  IloAssert (getImpl(), "accessing IloCplex through 0 handle");
  return (getImpl()->getMax(parameter));
}

inline void IloCplex::exportModel(const char* name) const {
  IloAssert (getImpl(), "accessing IloCplex through 0 handle");
  getImpl()->exportModel(name);
}

inline void IloCplex::writeOrder(const char* name) const {
  IloAssert (getImpl(), "accessing IloCplex through 0 handle");
  getImpl()->writeOrder(name);
}

inline void IloCplex::writeConflict(const char* name) const {
  IloAssert (getImpl(), "accessing IloCplex through 0 handle");
  getImpl()->writeConflict(name);
}

inline void IloCplex::writeParam(const char* name) const {
  IloAssert (getImpl(), "accessing IloCplex through 0 handle");
  getImpl()->writeParam(name);
}

inline void IloCplex::writeBasis(const char* name) const {
  IloAssert (getImpl(), "accessing IloCplex through 0 handle");
  getImpl()->writeBasis(name);
}

inline void IloCplex::writeSolution(const char* name, IloInt soln) const {
  IloAssert (getImpl(), "accessing IloCplex through 0 handle");
  getImpl()->writeSolution(name, soln);
}

inline void IloCplex::writeSolutions(const char* name) const {
  IloAssert (getImpl(), "accessing IloCplex through 0 handle");
  getImpl()->writeSolutions(name);
}

inline void IloCplex::writeMIPStarts(const char* name,
                                     IloInt first,
                                     IloInt num) const {
  IloAssert (getImpl(), "accessing IloCplex through 0 handle");
  getImpl()->writeMIPStarts(name, first, num);
}

inline void IloCplex::readOrder(const char* name) const {
  IloAssert (getImpl(), "accessing IloCplex through 0 handle");
  getImpl()->readOrder(name);
}

inline void IloCplex::readParam(const char* name) const {
  IloAssert (getImpl(), "accessing IloCplex through 0 handle");
  getImpl()->readParam(name);
}

inline void IloCplex::readBasis(const char* name) const {
  IloAssert (getImpl(), "accessing IloCplex through 0 handle");
  getImpl()->readBasis(name);
}

inline void IloCplex::readSolution(const char* name) const {
  IloAssert (getImpl(), "accessing IloCplex through 0 handle");
  getImpl()->readSolution(name);
}

inline void IloCplex::readMIPStarts(const char* name) const {
  IloAssert (getImpl(), "accessing IloCplex through 0 handle");
  getImpl()->readMIPStarts(name);
}

inline IloAlgorithm::Status
IloCplex::getStatus() const {
  IloAssert (getImpl(), "accessing IloCplex through 0 handle");
  return (getImpl()->getStatus());
}

inline IloCplex::CplexStatus    
IloCplex::getCplexStatus() const {
  IloAssert (getImpl(), "accessing IloCplex through 0 handle");
  return (getImpl()->getCplexStatus());
}

inline IloCplex::CplexStatus    
IloCplex::getCplexSubStatus() const {
  IloAssert (getImpl(), "accessing IloCplex through 0 handle");
  return (getImpl()->getCplexSubStatus());
}

inline IloBool
IloCplex::isPrimalFeasible() const {
  IloAssert (getImpl(), "accessing IloCplex through 0 handle");
  return (getImpl()->isPrimalFeasible());
}

inline IloBool
IloCplex::isDualFeasible() const {
  IloAssert (getImpl(), "accessing IloCplex through 0 handle");
  return (getImpl()->isPrimalFeasible());
}

inline IloCplex::Algorithm    
IloCplex::getAlgorithm() const {
  IloAssert (getImpl(), "accessing IloCplex through 0 handle");
  return (getImpl()->getAlgorithm());
}

inline IloCplex::Algorithm    
IloCplex::getSubAlgorithm() const {
  IloAssert (getImpl(), "accessing IloCplex through 0 handle");
  return (getImpl()->getSubAlgorithm());
}

inline void
IloCplex::deleteDnorms() {
  IloAssert (getImpl(), "accessing IloCplex through 0 handle");
  getImpl()->deleteDnorms();
}

inline void
IloCplex::deletePnorms() {
  IloAssert (getImpl(), "accessing IloCplex through 0 handle");
  getImpl()->deletePnorms();
}

inline IloConstraint
IloCplex::addUserCut(IloConstraint rng) {
  IloAssert (getImpl(), "accessing IloCplex through 0 handle");
  return (getImpl()->addUserCut(rng));
}

inline const IloConstraintArray
IloCplex::addUserCuts(const IloConstraintArray rng) {
  IloAssert (getImpl(), "accessing IloCplex through 0 handle");
  IloAssert (rng.getImpl(), "array not initialized");
  return (getImpl()->addUserCuts(rng));
}

inline void
IloCplex::clearUserCuts() {
  IloAssert (getImpl(), "accessing IloCplex through 0 handle");
  getImpl()->clearUserCuts();
}

inline IloConstraint
IloCplex::addCut(IloConstraint rng) {
  return (addLazyConstraint(rng));
}

inline const IloConstraintArray
IloCplex::addCuts(const IloConstraintArray rng) {
  return (addLazyConstraints(rng));
}

inline void
IloCplex::clearCuts() {
  clearLazyConstraints();
}


inline IloConstraint
IloCplex::addLazyConstraint(IloConstraint rng) {
  IloAssert (getImpl(), "accessing IloCplex through 0 handle");
  return (getImpl()->addLazyConstraint(rng));
}

inline const IloConstraintArray
IloCplex::addLazyConstraints(const IloConstraintArray rng) {
  IloAssert (getImpl(), "accessing IloCplex through 0 handle");
  IloAssert (rng.getImpl(), "array not initialized");
  return (getImpl()->addLazyConstraints(rng));
}

inline void
IloCplex::clearLazyConstraints() {
  IloAssert (getImpl(), "accessing IloCplex through 0 handle");
  getImpl()->clearLazyConstraints();
}

inline void
IloCplex::importModel(IloModel& m, const char* filename) const {
  IloAssert (getImpl(), "accessing IloCplex through 0 handle");
  getImpl()->importModel(m, filename);
}

inline void
IloCplex::importModel(IloModel& m, const char* filename,
                           IloObjective& obj,
                           IloNumVarArray vars, IloRangeArray  rngs,
                           IloRangeArray  lazy,
                           IloRangeArray  cuts) const {
  IloAssert (getImpl(), "accessing IloCplex through 0 handle");
  getImpl()->importModel(m, filename, obj, vars, rngs, lazy, cuts);
}

inline void
IloCplex::importModel(IloModel& m, const char* filename,
                           IloObjective& obj,
                           IloNumVarArray vars, IloRangeArray rngs,
                           IloSOS1Array sos1, IloSOS2Array sos2,
                           IloRangeArray  lazy,
                           IloRangeArray  cuts) const {
  IloAssert (getImpl(), "accessing IloCplex through 0 handle");
  getImpl()->importModel(m, filename, obj, vars, rngs, sos1, sos2, lazy, cuts);
}

inline IloExtractable
IloCplex::getDiverging() const {
  IloAssert (getImpl(), "accessing IloCplex through 0 handle");
  return (getImpl()->getDiverging());
}

inline void
IloCplex::getDualNorms(IloNumArray norms, const IloExprArray expr,
                            IloCplex::DualPricing dpriind) const {
  IloAssert (getImpl(), "accessing IloCplex through 0 handle");
  IloAssert (expr.getImpl(), "array not initialized");
  IloAssert (norms.getImpl(), "array not initialized");
  getImpl()->getDualNorms(expr, norms, dpriind);
}

inline IloCplex::Callback
IloCplex::use(Callback cb) {
  IloAssert (getImpl(), "accessing IloCplex through 0 handle");
  IloAssert (cb.getImpl(), "accessing callback through 0 handle");
  return (getImpl()->use(cb.getImpl()));
}

inline IloCplex::Callback
IloCplex::add(Callback cb) {
  IloAssert (getImpl(), "accessing IloCplex through 0 handle");
  IloAssert (cb.getImpl(), "accessing callback through 0 handle");
  return (getImpl()->add(cb.getImpl()));
}

inline bool 
IloCplex::inUse(Callback cb) {
  IloAssert (getImpl(), "accessing IloCplex through 0 handle");
  IloAssert (cb.getImpl(), "accessing callback through 0 handle");
  return getImpl()->inUse(cb.getImpl());
}

inline void 
IloCplex::remove(Callback cb) {
  IloAssert (getImpl(), "accessing IloCplex through 0 handle");
  IloAssert (cb.getImpl(), "accessing callback through 0 handle");
  getImpl()->remove(cb.getImpl());
}

inline void
IloCplex::clear(Callback::Type cbtype) {
  IloAssert (getImpl(), "accessing IloCplex through 0 handle");
  getImpl()->clear(cbtype);
}

inline void
IloCplex::clearModel() {
  IloAssert (getImpl(), "accessing IloCplex through 0 handle");
  getImpl()->clear();
}

inline IloBool
IloCplex::solve(Goal goal) {
  return getImpl()->solve(goal);
}

class CpxEmptyDeleterI : public IloBaseDeleterI {
  IloBool _remove;
public:
  CpxEmptyDeleterI(IloEnvI *env, IloBool remove = IloFalse);
  virtual void addToBeExtracted(const IloExtractable) {}
  virtual void inhibit(IloBool) {}
  virtual void end(IloExtractableI* object, IloBool);
  virtual void end(const IloExtractableArray objects, IloBool);
  virtual ~CpxEmptyDeleterI() {}
  virtual void setVerbosityLevel(IloInt) {}
  virtual void apply(const IloChange&, const IloExtractableI*) {}

  virtual void removeFromAll(IloInt) {}
  virtual void removeToBeExtracted(const IloExtractable)    {}
  virtual void fastEnd(IloExtractableI* object) { end(object, IloFalse); }
  virtual void addLink(IloExtractableI*, IloExtractableI*)    {}
  virtual void removeLink(IloExtractableI*, IloExtractableI*) {}
  virtual void addLink(IloExtractableI*, IloExtractableArray) {}
  virtual void removeLink(IloExtractableI*, IloExtractableArray) {}
  virtual IloBool hasLink(IloExtractableI*, IloExtractableI*) {
    return IloFalse;
  }
  virtual IloBool sendFullChange() const { return IloFalse; }
  virtual void setSendFullChange(IloBool) {}
  virtual void setSendFullChange() {}

protected:
  IloEnvI* _env;
};

/////////////////////////////////////
// class CpxNodeI
/////////////////////////////////////

class CpxNodeI : public IloCplex::MIPCallbackI::NodeData {
public:
  class GoalStack {
  public:
    GoalStack(IloCplex::Goal goal,
                 GoalStack *prev) : _goal(goal),
                                       _prev(prev) {}

    IloCplex::Goal   _goal;
    GoalStack       *_prev;
  };

  class LimitStack {
  public:
    LimitStack(IloCplex::SearchLimit limit,
                  LimitStack *prev) : _limit(limit),
                                         _prev(prev) {}

    IloCplex::SearchLimit   _limit;
    LimitStack   *_prev;
  };

  class EvaluatorList {
  public:
    EvaluatorList(IloCplex::NodeEvaluator eval,
                  EvaluatorList          *next) : _eval(eval),
                                                  _value(0),
                                                  _next(next) {
    }

    IloCplex::NodeEvaluator  _eval;
    IloNum                   _value;
    EvaluatorList           *_next;
  };


  CpxNodeI(IloCplexI *cplex, IloNum ext=IloInfinity);
  virtual ~CpxNodeI();

  IloInt     getNNewNodes() const { return _nNewNodes; }
  CpxNodeI  *addNewNode(IloNum est);
  CpxNodeI **getNewNodes()  const { return _newNodes; }

  void solve();

  IloNum              getEstimate() const { return _est; }
  IloConstraintArray  getCuts() const { return _ranges; }
  IloConstraintArray  getGlobalCuts() const { return _globalRanges; }
  void                initCuts(IloBool create);
  void                addCut(IloConstraint rng) { _ranges.add(rng); }
  void                addCuts(IloConstraintArray rng) { _ranges.add(rng); }
  void                addGlobalCut(IloConstraint rng) { _globalRanges.add(rng); }
  void                addGlobalCuts(IloConstraintArray rng) {
    _globalRanges.add(rng);
  }

  void performBranch();

  void        delBranchInfo();
  void        prepareToBranch();

  // Related with the Goal Stack:
  IloCplex::Goal popGoalStack();
  void addGoalStack(IloCplex::Goal goal);
  void copyGoalStack(CpxNodeI *node);

  // Related with the Limit Stack:
  IloCplex::SearchLimit popLimitStack();
  void addLimitStack(IloCplex::SearchLimit limit);
  void copyLimitStack(CpxNodeI *node);
  IloBool checkLimits();

  void setNodeCallback(IloCplex::NodeCallbackI *cb) { _ndCallback = cb; }
  void setBranchCallback(IloCplex::BranchCallbackI *cb) { _brCallback = cb; }
  void setIncumbentCallback(IloCplex::IncumbentCallbackI *cb) {
    _incCallback = cb;
  }

  IloCplex::NodeCallbackI      *getNodeCallback() const { return _ndCallback; }
  IloCplex::BranchCallbackI    *getBranchCallback() const {return _brCallback;}
  IloCplex::IncumbentCallbackI *getIncumbentCallback() const {
    return _incCallback;
  }

  IloCplexI *getCplex() const { return _cplex; }
  IloEnv     getEnv() const { return _cplex->getEnv(); }

  CpxNodeI *makeBranch(IloCplex::Goal goal, IloNum est=IloInfinity);

  IloBool   isFail() const { return _fail; }
  void      setFail(IloBool fail) { _fail = fail; }

  // Methods to get the information
  void      increaseLDepth() { _lDepth++; _depth++; }
  void      increaseRDepth() { _depth++; }
  IloInt    getLeftDepth() const { return _lDepth; }
  IloInt    getRightDepth() const { return _depth - _lDepth; }
  IloInt    getDepth() const { return _depth; }

  IloAny getDataType() const;
  IloBool hasGoals() const { return _goalStack != 0; }

  IloCplexMutex *getMutex() const { return _mutex; }
  void evaluate(IloInt64 nodeId);
  IloBool subsume(CpxNodeI *node);
  IloBool isFathomed() const { return _fathomed; }

  // For the evaluators.
  void cleanEvaluators();
  void copyEvaluators(CpxNodeI *node);
  void addEvaluator(IloCplex::NodeEvaluator newEval);

  // Duplication
  CpxNodeI *duplicate();

  // Feasibility checker
  IloBool checkFeasibility(IloConstraintI* con, IloNum eps) const;
  IloBool checkFeasibility(IloNum eps) const;

protected:
  IloCplexI     *_cplex;
  IloCplexMutex *_mutex;

  GoalStack                  *_goalStack;
  LimitStack                 *_limitStack;
  EvaluatorList              *_evaluators;
  EvaluatorList              *_toEvaluate;

  IloNum                     _est;
  IloInt                     _nSons;

  IloBool                    _fathomed;

  IloConstraintArray         _ranges;
  IloConstraintArray         _globalRanges;

  CpxNodeI                  **_newNodes;
  IloInt                      _nNewNodes;

  IloBool                     _fail;

  IloCplex::NodeCallbackI      *_ndCallback;
  IloCplex::BranchCallbackI    *_brCallback;
  IloCplex::IncumbentCallbackI *_incCallback;

  // For the limits
  IloInt _depth;
  IloInt _lDepth;

  // Ordering
  void sort(IloNumVarArray vars, IloIntArray index,
            IloInt start, IloInt end);
};


inline IloInt
IloCplex::Node::getLeftDepth() const {
  return _impl->getLeftDepth();
}

inline IloInt
IloCplex::Node::getRightDepth() const {
  return _impl->getRightDepth();
}

inline IloInt
IloCplex::Node::getDepth() const {
  return _impl->getDepth();
}

inline IloInt
IloCplex::EvaluatorI::getLeftDepth() const {
  return _node->getLeftDepth();
}

inline IloInt
IloCplex::EvaluatorI::getRightDepth() const {
  return _node->getRightDepth();
}

inline IloInt
IloCplex::EvaluatorI::getDepth()  const {
  return _node->getDepth();
}

inline IloCplex::NodeCallbackI
*IloCplex::NodeEvaluatorI::getCallback() const {
  return _node->getNodeCallback();
}

inline IloObjective
IloCplex::getObjective() const {
   return (IloObjective((IloObjectiveI*)(getImpl()->getObjective())));
}

#ifndef ILOG_CPLEX_NO_REMOTE_API
inline IloCplex::SolveFixedHandle
IloCplex::solveFixed(IloInt soln, bool async) {
  IloAssert(getImpl(), "accessing IloCplex through 0 handle");
  return (getImpl()->solveFixed(soln, async));
}

inline IloCplex::SolveHandle
IloCplex::solve(bool async) {
  return getImpl()->solve(async);
}

#endif // !ILOG_CPLEX_NO_REMOTE_API

#ifndef ILOG_CPLEX_NO_DISTRIBUTED_MIP_API
inline bool IloCplex::hasVMConfig () const { return this->getImpl()->hasVMConfig(); }
template<typename T> inline void IloCplex::copyVMConfig(T xmlstring) { this->getImpl()->copyVMConfig(xmlstring); }
template<typename T> inline void IloCplex::readVMConfig(T file) { this->getImpl()->readVMConfig(file); }
inline void IloCplex::delVMConfig() { this->getImpl()->delVMConfig(); }
#endif // !ILOG_CPLEX_NO_DISTRIBUTED_MIP_API

#ifdef _WIN32
#pragma pack(pop)
#endif

#endif

