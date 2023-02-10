// -------------------------------------------------------------- -*- C++ -*-
// File: ilogoals.h
// Version 12.7.1
// --------------------------------------------------------------------------
// Licensed Materials - Property of IBM
// 5725-A06 5725-A29 5724-Y48 5724-Y49 5724-Y54 5724-Y55 5655-Y21
// Copyright IBM Corporation 2002, 2017. All Rights Reserved.
//
// US Government Users Restricted Rights - Use, duplication or
// disclosure restricted by GSA ADP Schedule Contract with
// IBM Corp.
// --------------------------------------------------------------------------

#ifndef __ILOGOALS__H_
#define __ILOGOALS__H_

#ifdef _WIN32
#pragma pack(push, 8)
#endif

#include <ilcplex/ilocplexi.h>

///////////////////////
// ILOCPLEXGOAL0
///////////////////////

#define ILOCPXAUXGOAL0(goalName, implName)\
class implName : public IloCplex::GoalI {\
public:\
  implName(IloEnv env): IloCplex::GoalI(env) {}\
  IloCplex::Goal execute();\
  IloCplex::Goal duplicateGoal();\
};\
IloCplex::Goal implName::duplicateGoal() {\
  IloCplex::GoalBaseI* retgoal;\
  CPXNEW (retgoal , new implName(getEnv()));\
  return retgoal;\
}\
IloCplex::Goal goalName(IloEnv env) {\
  IloCplex::GoalBaseI* retgoal;\
  CPXNEW (retgoal , new implName(env));\
  return retgoal;\
}\
IloCplex::Goal implName::execute()

#define ILOCPLEXGOAL0(name)\
ILOCPXAUXGOAL0(name, name2(name, I))

///////////////////////
// ILOCPLEXGOAL1
///////////////////////

#define ILOCPXAUXGOAL1(goalName, implName, type0, var0)\
class implName : public IloCplex::GoalI {\
public:\
  implName(IloEnv env, type0 CpxArg0): IloCplex::GoalI(env),\
                                       var0(CpxArg0) {}\
  IloCplex::Goal execute();\
  IloCplex::Goal duplicateGoal();\
private:\
  type0 var0;\
};\
IloCplex::Goal implName::duplicateGoal() {\
  IloCplex::GoalBaseI* retgoal;\
  CPXNEW (retgoal , new implName(getEnv(), var0));\
  return retgoal;\
}\
IloCplex::Goal goalName(IloEnv env, type0 var0) {\
  IloCplex::GoalBaseI* retgoal;\
  CPXNEW (retgoal , new implName(env, var0));\
  return retgoal;\
}\
IloCplex::Goal implName::execute()

#define ILOCPLEXGOAL1(name, type0, var0)\
ILOCPXAUXGOAL1(name, name2(name, I), type0, var0)

///////////////////////
// ILOCPLEXGOAL2
///////////////////////

#define ILOCPXAUXGOAL2(goalName, implName, type0, var0, type1, var1)\
class implName : public IloCplex::GoalI {\
public:\
  implName(IloEnv env, type0 CpxArg0, type1 CpxArg1): IloCplex::GoalI(env),\
                                                      var0(CpxArg0),\
                                                      var1(CpxArg1) {}\
  IloCplex::Goal execute();\
  IloCplex::Goal duplicateGoal();\
private:\
  type0 var0;\
  type1 var1;\
};\
IloCplex::Goal implName::duplicateGoal() {\
  IloCplex::GoalBaseI* retgoal;\
  CPXNEW (retgoal , new implName(getEnv(), var0, var1));\
  return retgoal;\
}\
IloCplex::Goal goalName(IloEnv env, type0 var0, type1 var1) {\
  IloCplex::GoalBaseI* retgoal;\
  CPXNEW (retgoal , new implName(env, var0, var1));\
  return retgoal;\
}\
IloCplex::Goal implName::execute()

#define ILOCPLEXGOAL2(name, type0, var0, type1, var1)\
ILOCPXAUXGOAL2(name, name2(name, I), type0, var0, type1, var1)

///////////////////////
// ILOCPLEXGOAL3
///////////////////////

#define ILOCPXAUXGOAL3(goalName, implName, type0, var0, type1, \
                     var1, type2, var2)\
class implName : public IloCplex::GoalI {\
public:\
  implName(IloEnv env,\
           type0 CpxArg0,\
           type1 CpxArg1,\
           type2 CpxArg2): IloCplex::GoalI(env),\
                           var0(CpxArg0),\
                           var1(CpxArg1),\
                           var2(CpxArg2) {}\
  IloCplex::Goal execute();\
  IloCplex::Goal duplicateGoal();\
private:\
  type0 var0;\
  type1 var1;\
  type2 var2;\
};\
IloCplex::Goal implName::duplicateGoal() {\
  IloCplex::GoalBaseI* retgoal;\
  CPXNEW (retgoal , new implName(getEnv(), var0, var1, var2));\
  return retgoal;\
}\
IloCplex::Goal goalName(IloEnv env,\
                        type0 var0,\
                        type1 var1,\
                        type2 var2) {\
  IloCplex::GoalBaseI* retgoal;\
  CPXNEW (retgoal , new implName(env, var0, var1, var2));\
  return retgoal;\
}\
IloCplex::Goal implName::execute()

#define ILOCPLEXGOAL3(name, type0, var0, type1, var1, type2, var2)\
ILOCPXAUXGOAL3(name, name2(name, I), type0, var0, type1, var1, type2, var2)

///////////////////////
// ILOCPLEXGOAL4
///////////////////////

#define ILOCPXAUXGOAL4(goalName, implName, t0, v0, t1, v1, t2, v2, t3, v3)\
class implName : public IloCplex::GoalI {\
public:\
  implName(IloEnv env,\
           t0 CpxArg0,\
           t1 CpxArg1,\
           t2 CpxArg2,\
           t3 CpxArg3): IloCplex::GoalI(env),\
                        v0(CpxArg0),\
                        v1(CpxArg1),\
                        v2(CpxArg2),\
                        v3(CpxArg3){}\
  IloCplex::Goal execute();\
  IloCplex::Goal duplicateGoal();\
private:\
  t0 v0;\
  t1 v1;\
  t2 v2;\
  t3 v3;\
};\
IloCplex::Goal implName::duplicateGoal() {\
  IloCplex::GoalBaseI* retgoal;\
  CPXNEW (retgoal , new implName(getEnv(), v0, v1, v2, v3));\
  return retgoal;\
}\
IloCplex::Goal goalName(IloEnv env,\
                        t0 v0,\
                        t1 v1,\
                        t2 v2,\
                        t3 v3) {\
  IloCplex::GoalBaseI* retgoal;\
  CPXNEW (retgoal , new implName(env, v0, v1, v2, v3));\
  return retgoal;\
}\
IloCplex::Goal implName::execute()

#define ILOCPLEXGOAL4(name, t0, v0, t1, v1, t2, v2, t3, v3)\
ILOCPXAUXGOAL4(name, name2(name, I), t0, v0, t1, v1, t2, v2, t3, v3)

///////////////////////
// ILOCPLEXGOAL5
///////////////////////

#define ILOCPXAUXGOAL5(goalName, implName, t0, v0, t1, v1, \
                                         t2, v2, t3, v3, t4, v4)\
class implName : public IloCplex::GoalI {\
public:\
  implName(IloEnv env,\
           t0 CpxArg0,\
           t1 CpxArg1,\
           t2 CpxArg2,\
           t3 CpxArg3,\
           t4 CpxArg4): IloCplex::GoalI(env),\
                        v0(CpxArg0),\
                        v1(CpxArg1),\
                        v2(CpxArg2),\
                        v3(CpxArg3),\
                        v4(CpxArg4) {}\
  IloCplex::Goal execute();\
  IloCplex::Goal duplicateGoal();\
private:\
  t0 v0;\
  t1 v1;\
  t2 v2;\
  t3 v3;\
  t4 v4;\
};\
IloCplex::Goal implName::duplicateGoal() {\
  IloCplex::GoalBaseI* retgoal;\
  CPXNEW (retgoal , new implName(getEnv(), v0, v1, v2, v3, v4));\
  return retgoal;\
}\
IloCplex::Goal goalName(IloEnv env,\
                        t0 v0,\
                        t1 v1,\
                        t2 v2,\
                        t3 v3,\
                        t4 v4) {\
  IloCplex::GoalBaseI* retgoal;\
  CPXNEW (retgoal , new implName(env, v0, v1, v2, v3, v4));\
  return retgoal;\
}\
IloCplex::Goal implName::execute()

#define ILOCPLEXGOAL5(name, t0, v0, t1, v1, t2, v2, t3, v3, t4, v4)\
ILOCPXAUXGOAL5(name, name2(name, I), t0, v0, t1, v1, t2, v2, t3, v3, t4, v4)

///////////////////////
// ILOCPLEXGOAL6
///////////////////////

#define ILOCPXAUXGOAL6(goalName, implName, t0, v0, t1, v1, t2, v2, \
                                           t3, v3, t4, v4, t5, v5)\
class implName : public IloCplex::GoalI {\
public:\
  implName(IloEnv env,\
           t0 CpxArg0,\
           t1 CpxArg1,\
           t2 CpxArg2,\
           t3 CpxArg3,\
           t4 CpxArg4,\
           t5 CpxArg5): IloCplex::GoalI(env),\
                        v0(CpxArg0),\
                        v1(CpxArg1),\
                        v2(CpxArg2),\
                        v3(CpxArg3),\
                        v4(CpxArg4),\
                        v5(CpxArg5) {}\
  IloCplex::Goal execute();\
  IloCplex::Goal duplicateGoal();\
private:\
  t0 v0;\
  t1 v1;\
  t2 v2;\
  t3 v3;\
  t4 v4;\
  t5 v5;\
};\
IloCplex::Goal implName::duplicateGoal() {\
  IloCplex::GoalBaseI* retgoal;\
  CPXNEW (retgoal , new implName(getEnv(), v0, v1, v2, v3, v4, v5));\
  return retgoal;\
}\
IloCplex::Goal goalName(IloEnv env,\
                        t0 v0,\
                        t1 v1,\
                        t2 v2,\
                        t3 v3,\
                        t4 v4,\
                        t5 v5) {\
  IloCplex::GoalBaseI* retgoal;\
  CPXNEW (retgoal , new implName(env, v0, v1, v2, v3, v4, v5));\
  return retgoal;\
}\
IloCplex::Goal implName::execute()

#define ILOCPLEXGOAL6(name, t0, v0, t1, v1, t2, v2, t3, v3, t4, v4, t5, v5)\
ILOCPXAUXGOAL6(name, name2(name, I), t0, v0, t1, v1, t2, v2, \
                                     t3, v3, t4, v4, t5, v5)

////////////////////////////
// class CpxCutGoalI
////////////////////////////

class CpxCutGoalI : public IloCplex::GoalBaseI {
public:
  CpxCutGoalI(IloConstraint rng);

  virtual IloCplex::Goal execute();

  virtual IloCplex::Goal duplicateGoal();

  virtual ~CpxCutGoalI();

protected:
  IloConstraint _rng;
};

////////////////////////////
// class CpxCutArrayGoalI
////////////////////////////

class CpxCutArrayGoalI : public IloCplex::GoalBaseI {
public:
  CpxCutArrayGoalI(IloConstraintArray rng);

  virtual IloCplex::Goal execute();

  virtual IloCplex::Goal duplicateGoal();

  virtual ~CpxCutArrayGoalI();

protected:
  IloConstraintArray _rng;
};

////////////////////////////
// class CpxGlobalCutGoalI
////////////////////////////

class CpxGlobalCutGoalI : public IloCplex::GoalBaseI {
public:
  CpxGlobalCutGoalI(IloConstraint rng);

  virtual IloCplex::Goal execute();

  virtual IloCplex::Goal duplicateGoal();

  virtual ~CpxGlobalCutGoalI();

protected:
  IloConstraint _rng;
};

////////////////////////////
// class CpxSolutionGoalI
////////////////////////////

class CpxSolutionGoalI : public IloCplex::GoalBaseI {
public:
  CpxSolutionGoalI(const IloNumVarArray vars, 
                   const IloNumArray    vals);

  CpxSolutionGoalI(const IloNumVarArray vars, 
                   const IloNumArray    vals,
                   IloNum               obj);

  virtual IloCplex::Goal execute();

  virtual IloCplex::Goal duplicateGoal();

  virtual ~CpxSolutionGoalI();

protected:
  IloNumVarArray _vars;
  IloNumArray    _vals;
  IloNum         _obj;
  IloBool        _tryObj;
};

////////////////////////////
// class CpxGCutArrayGoalI
////////////////////////////

class CpxGCutArrayGoalI : public IloCplex::GoalBaseI {
public:
  CpxGCutArrayGoalI(IloConstraintArray rng);

  virtual IloCplex::Goal execute();

  virtual IloCplex::Goal duplicateGoal();

  virtual ~CpxGCutArrayGoalI();

protected:
  IloConstraintArray _rng;
};

/////////////////////////////
// class CpxBranchAsCplexI 
/////////////////////////////

class CpxBranchAsCplexI : public IloCplex::GoalI {
public:
  CpxBranchAsCplexI(IloEnv env);

  virtual IloCplex::Goal execute();
  virtual IloCplex::Goal duplicateGoal();
};

////////////////////////////
// class CpxFailGoalI
////////////////////////////

class CpxFailGoalI : public IloCplex::GoalBaseI {
public:
  CpxFailGoalI(IloEnv env);

  virtual IloCplex::Goal execute();

  virtual IloCplex::Goal duplicateGoal();
};

/////////////////////////////
// Class  CpxOrI
/////////////////////////////

class CpxOrI : public IloCplex::GoalBaseI {
public:
  CpxOrI(IloCplex::Goal goal1, IloCplex::Goal goal2,
         double est1=IloInfinity, double est2=IloInfinity);

  IloCplex::Goal execute();
  IloCplex::Goal duplicateGoal();
  virtual GoalType getType() const;
protected:
  IloCplex::Goal _goal1;
  IloCplex::Goal _goal2;
  double         _est1;
  double         _est2;
};


/////////////////////////////
// Class  CpxAndI
/////////////////////////////

class CpxAndI : public IloCplex::GoalBaseI {
public:
  CpxAndI(IloCplex::Goal goal1, IloCplex::Goal goal2);

  IloCplex::Goal execute();
  IloCplex::Goal duplicateGoal();
  virtual GoalType getType() const;
protected:
  IloCplex::Goal _goal1;
  IloCplex::Goal _goal2;
};

///////////////////////////////
// class CpxApplyGoalI
///////////////////////////////

class CpxApplyGoalI : public IloCplex::GoalBaseI {
public:
  CpxApplyGoalI(IloCplex  cplex,
                IloCplex::NodeEvaluator eval);

  virtual IloCplex::Goal execute();

  virtual IloCplex::Goal duplicateGoal();

protected:
  IloCplex::NodeEvaluator _eval;
  IloCplexI* _cplex;
};


///////////////////////////////
// class CpxLimitGoalI
///////////////////////////////

class CpxLimitGoalI : public IloCplex::GoalBaseI {
public:
  CpxLimitGoalI(IloCplex cplex,
                IloCplex::SearchLimit limit);

  virtual IloCplex::Goal execute();

  virtual IloCplex::Goal duplicateGoal();

protected:
  IloCplex::SearchLimit _limit;
  IloCplexI* _cplex;
};

//////////////////////////////
//       CpxOrLimitI
//////////////////////////////

class CpxOrLimitI : public IloCplex::SearchLimitI {
public:
  CpxOrLimitI(IloInt orLimit);

  virtual IloBool check();
  virtual void init();
  virtual IloCplex::SearchLimitI* duplicateLimit();

protected:
  IloInt _orLimit;
  IloInt _nbOr;
};

#ifdef _WIN32
#pragma pack(pop)
#endif

#endif
