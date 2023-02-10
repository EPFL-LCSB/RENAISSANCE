// -------------------------------------------------------------- -*- C++ -*-
// File: ilocplex.h
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

#ifndef _ILOCPLEX_H
#define _ILOCPLEX_H

#ifdef _WIN32
#pragma pack(push, 8)
#endif

//
// To be included by applications using IloCplex.  It imports all include files
// needed for an IloCplex concert technology application.  Also inline
// implementation for various IloCplex member functions are provided here
//

#include <ilconcert/ilomodel.h>
#include <ilconcert/ilosys.h>
#include <ilcplex/ilocplexi.h>
#include <ilconcert/iloalg.h>
// #include <ilcplex/ilolpextr.h>
#include <ilcplex/ilm.h>
#include <ilcplex/ilogoals.h>


#ifdef _WIN32
#define ILOCPLEX_VERSIONSTRING "@(#)Licensed Materials - Property of IBM - 5725-A06 5725-A29 5724-Y48 5724-Y49 5724-Y54 5724-Y55 5655-Y21: \
product CPLEX , library ilocplex.lib, version 12.7.1.0, date 05/01/2017, \
Copyright IBM Corporation 2000, 2017. All Rights Reserved. \
US Government Users Restricted Rights - Use, duplication or \
disclosure restricted by GSA ADP Schedule Contract with IBM Corp."
#else
#define ILOCPLEX_VERSIONSTRING "@(#)Licensed Materials - Property of IBM - 5725-A06 5725-A29 5724-Y48 5724-Y49 5724-Y54 5724-Y55 5655-Y21: \
product CPLEX , library libilocplex.a, version 12.7.1.0, date 05/01/2017, \
Copyright IBM Corporation 2000, 2017. All Rights Reserved. \
US Government Users Restricted Rights - Use, duplication or \
disclosure restricted by GSA ADP Schedule Contract with IBM Corp."
#endif


inline void
IloCplex::deleteNames() {
  IloAssert(getImpl() != 0, "accessing IloCplex through 0 handle");
  getImpl()->deleteNames();
}

inline void
IloCplex::use(IloLPExtractor* trans) {
  IloAssert(getImpl() != 0, "accessing IloCplex through 0 handle");
  IloAssert(trans, "accessing IloLPExtractor through 0 handle");
  getImpl()->use(trans);
}

#ifdef USE_SET_VARS
inline void
IloCplex::getIntSetValue (const IloIntSetVar var, IloIntSet set) const {
  IloAssert(getImpl() != 0, "accessing IloCplex through 0 handle");
  IloAssert (var.getImpl() != 0, "accessing IloIntSetVar through 0 handle");
  IloAssert (set.getImpl() != 0, "accessing IloIntSet through 0 handle");
  getImpl()->getIntSetValue(var.getImpl(), set);
}
#endif

inline IloNum
IloCplex::getDual  (const IloRange con) const {
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  IloAssert (con.getImpl() != 0, "accessing IloRange through 0 handle");
 return (getImpl()->getDual(con.getImpl()));
}

inline void
IloCplex::getQCDSlack (const IloRange con, IloNumArray& vals, IloNumVarArray& vars) const {
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  IloAssert (con.getImpl() != 0, "accessing IloRange through 0 handle");
  IloAssert (vals.getImpl() != 0, "accessing IloNumArray through 0 handle");
  IloAssert (vars.getImpl() != 0, "accessing IloNumVarArray through 0 handle");
  getImpl()->getQCDSlack(con.getImpl(), vals, vars);
}
inline void
IloCplex::getQCDSlack (const IloForAllRange con, IloNumArray& vals, IloNumVarArray& vars) const {
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  IloAssert (con.getImpl() != 0, "accessing IloForAllRange through 0 handle");
  IloAssert (vals.getImpl() != 0, "accessing IloNumArray through 0 handle");
  IloAssert (vars.getImpl() != 0, "accessing IloNumVarArray through 0 handle");
  getImpl()->getQCDSlack(con.getImpl(), vals, vars);
}

inline IloNum
IloCplex::getAX  (const IloForAllRange con) const {
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  IloAssert (con.getImpl() != 0, "accessing IloForAllRange through 0 handle");
 return (getImpl()->getAX(con.getImpl()));
}
inline IloNum
IloCplex::getDual  (const IloForAllRange con) const {
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  IloAssert (con.getImpl() != 0, "accessing IloForAllRange through 0 handle");
 return (getImpl()->getDual(con.getImpl()));
}
inline IloNum
IloCplex::getSlack (const IloForAllRange con, IloInt soln) const {
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  IloAssert (con.getImpl() != 0, "accessing IloForAllRange through 0 handle");
 return (getImpl()->getSlack(con.getImpl(), soln));
}
inline void
IloCplex::getForAllRanges (IloForAllRangeArray rows,
                                IloConstraint       forall) const {
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  IloAssert (forall.getImpl() != 0, "accessing IloForAll through 0 handle");
  IloAssert (rows.getImpl() != 0, "array not initialized");
  getImpl()->getForAllRanges(rows, forall.getImpl());
}
inline IloNum
IloCplex::getLB(const IloForAllRange con) const {
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  IloAssert (con.getImpl() != 0, "accessing IloForAllRange through 0 handle");
  return (getImpl()->getLB(con.getImpl()));
}
inline IloNum
IloCplex::getUB(const IloForAllRange con) const {
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  IloAssert (con.getImpl() != 0, "accessing IloForAllRange through 0 handle");
  return (getImpl()->getUB(con.getImpl()));
}
inline IloBool
IloCplex::feasOpt(const IloRangeArray rngs,       const IloNumArray rnglb,
                                                  const IloNumArray rngub,
                  const IloForAllRangeArray frng, const IloNumArray frnglb,
                                                  const IloNumArray frngub,
                  const IloNumVarArray vars,      const IloNumArray varlb,
                                                  const IloNumArray varub) {
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  return getImpl()->feasOpt(rngs, rnglb, rngub,
                            frng, frnglb, frngub,
                            vars, varlb, varub);
                  }
inline IloNum
IloCplex::getObjValue(IloInt soln) const {
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  return (getImpl()->getObjValue(soln));
}

inline IloNum
IloCplex::getValue(const IloNumVar var, IloInt soln) const {
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  IloAssert (var.getImpl() != 0, "accessing IloNumVar through 0 handle");
  return (getImpl()->getValue(var.getImpl(), soln));
}

inline IloNum
IloCplex::getValue(const IloIntVar var, IloInt soln) const {
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  IloAssert (var.getImpl() != 0, "accessing IloIntVar through 0 handle");
  return (getImpl()->getValue(var.getImpl(), soln));
}

inline IloNum
IloCplex::getValue(const IloNumExprArg expr, IloInt soln) const {
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  IloAssert (expr.getImpl() != 0, "accessing IloNumExprArg through 0 handle");
  return (getImpl()->getValue(expr.getImpl(), soln));
}

inline IloNum
IloCplex::getValue(const IloObjective ob, IloInt soln) const {
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  IloAssert (ob.getImpl() != 0, "accessing IloObjective through 0 handle");
  return (getImpl()->getValue(ob.getImpl(), soln));
}

inline IloNum
IloCplex::getSlack (const IloRange con, IloInt soln) const {
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  IloAssert (con.getImpl() != 0, "accessing IloRange through 0 handle");
  return (getImpl()->getSlack(con.getImpl(), soln));
}

inline IloNum
IloCplex::getInfeasibility (const IloConstraint con) const {
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  IloAssert (con.getImpl() != 0, "accessing IloConstraint through 0 handle");
  return (getImpl()->getInfeasibility(con.getImpl(), NULL));
}

inline IloNum
IloCplex::getReducedCost(const IloNumVar con) const {
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  IloAssert (con.getImpl() != 0, "accessing IloNumVar through 0 handle");
  return (getImpl()->getReducedCost(con.getImpl()));
}

inline IloNum
IloCplex::getReducedCost(const IloIntVar con) const {
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  IloAssert (con.getImpl() != 0, "accessing IloIntVar through 0 handle");
  return (getImpl()->getReducedCost(con.getImpl()));
}

inline IloNum
IloCplex::getInfeasibility (const IloNumVar var) const {
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  IloAssert (var.getImpl() != 0, "accessing IloNumVar through 0 handle");
  return (getImpl()->getInfeasibility(var.getImpl()));
}

inline IloNum
IloCplex::getInfeasibility (const IloIntVar var) const {
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  IloAssert (var.getImpl() != 0, "accessing IloIntVar through 0 handle");
  return (getImpl()->getInfeasibility(var.getImpl()));
}

inline IloCplex::BasisStatus
IloCplex::getBasisStatus(const IloNumVar con) const {
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  IloAssert (con.getImpl() != 0, "accessing IloNumVar through 0 handle");
  return (getImpl()->getBasisStatus(con.getImpl()));
}

inline
IloCplex::BasisStatus IloCplex::getBasisStatus(const IloIntVar con) const {
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  IloAssert (con.getImpl() != 0, "accessing IloIntVar through 0 handle");
  return (getImpl()->getBasisStatus(con.getImpl()));
}

inline IloCplex::BasisStatus
IloCplex::getBasisStatus(const IloConstraint con) const {
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  IloAssert (con.getImpl() != 0, "accessing IloConstraint through 0 handle");
  return (getImpl()->getBasisStatus(con.getImpl()));
}

inline void
IloCplex::getDuals  (IloNumArray val, const IloRangeArray con) const {
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  IloAssert (val.getImpl() != 0, "array not initialized");
  IloAssert (con.getImpl() != 0, "array not initialized");
  getImpl()->getDuals(val, con);
}

inline void
IloCplex::getAX  (IloNumArray val, const IloForAllRangeArray con) const {
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  IloAssert (val.getImpl() != 0, "array not initialized");
  IloAssert (con.getImpl() != 0, "array not initialized");
  getImpl()->getAX(val, con);
}
inline void
IloCplex::getDuals  (IloNumArray val, const IloForAllRangeArray con) const {
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  IloAssert (val.getImpl() != 0, "array not initialized");
  IloAssert (con.getImpl() != 0, "array not initialized");
  getImpl()->getDuals(val, con);
}
inline void
IloCplex::getSlacks (IloNumArray val, const IloForAllRangeArray con, IloInt soln) const {
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  IloAssert (val.getImpl() != 0, "array not initialized");
  IloAssert (con.getImpl() != 0, "array not initialized");
  getImpl()->getSlacks(val, con, soln);
}

inline void
IloCplex::getValues(IloNumArray val, const IloNumVarArray var,
                    IloInt soln) const {
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  IloAssert (val.getImpl() != 0, "array not initialized");
  IloAssert (var.getImpl() != 0, "array not initialized");
  getImpl()->getValues(var, val, soln);
}

inline void
IloCplex::getValues(const IloNumVarArray var, IloNumArray val,
                    IloInt soln) const {
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  IloAssert (val.getImpl() != 0, "array not initialized");
  IloAssert (var.getImpl() != 0, "array not initialized");
  getImpl()->getValues(var, val, soln);
}

inline void
IloCplex::getValues(IloNumArray val, const IloIntVarArray var,
                    IloInt soln) const {
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  IloAssert (val.getImpl() != 0, "array not initialized");
  IloAssert (var.getImpl() != 0, "array not initialized");
  getImpl()->getValues(var, val, soln);
}

inline void
IloCplex::getValues(const IloIntVarArray var, IloNumArray val,
                    IloInt soln) const {
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  IloAssert (val.getImpl() != 0, "array not initialized");
  IloAssert (var.getImpl() != 0, "array not initialized");
  getImpl()->getValues(var, val, soln);
}

inline void
IloCplex::getSlacks (IloNumArray val, const IloRangeArray con,
                     IloInt soln) const {
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  IloAssert (val.getImpl() != 0, "array not initialized");
  IloAssert (con.getImpl() != 0, "array not initialized");
  getImpl()->getSlacks(val, con, soln);
}

inline IloNum
IloCplex::getInfeasibilities (IloNumArray infeas,
                              const IloConstraintArray con) const {
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  IloAssert (con.getImpl() != 0, "array not initialized");
  IloAssert (infeas.getImpl() != 0, "array not initialized");
  return (getImpl()->getInfeasibilities(infeas, con));
}

inline void
IloCplex::getReducedCosts(IloNumArray val, const IloNumVarArray var) const {
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  IloAssert (val.getImpl() != 0, "array not initialized");
  IloAssert (var.getImpl() != 0, "array not initialized");
  getImpl()->getReducedCosts(val, var);
}

inline void
IloCplex::getReducedCosts(IloNumArray val, const IloIntVarArray var) const {
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  IloAssert (val.getImpl() != 0, "array not initialized");
  IloAssert (var.getImpl() != 0, "array not initialized");
  getImpl()->getReducedCosts(val, var);
}

inline IloNum
IloCplex::getInfeasibilities (IloNumArray infeas,
                              const IloNumVarArray var) const {
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  IloAssert (infeas.getImpl() != 0, "array not initialized");
  IloAssert (var.getImpl() != 0, "array not initialized");
  return (getImpl()->getInfeasibilities(infeas, var));
}

inline IloNum
IloCplex::getInfeasibilities (IloNumArray infeas,
                              const IloIntVarArray var) const {
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  IloAssert (infeas.getImpl() != 0, "array not initialized");
  IloAssert (var.getImpl() != 0, "array not initialized");
  return (getImpl()->getInfeasibilities(infeas, var));
}

inline void
IloCplex::getBasisStatuses(IloCplex::BasisStatusArray stat,
                           const IloNumVarArray       con) const {
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  IloAssert (stat.getImpl() != 0, "array not initialized");
  IloAssert (con.getImpl() != 0, "array not initialized");
  getImpl()->getBasisStatuses(stat, con);
}

inline void
IloCplex::getBasisStatuses(IloCplex::BasisStatusArray stat,
                           const IloIntVarArray       con) const {
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  IloAssert (stat.getImpl() != 0, "array not initialized");
  IloAssert (con.getImpl() != 0, "array not initialized");
  getImpl()->getBasisStatuses(stat, con);
}

inline void
IloCplex::getBasisStatuses(IloCplex::BasisStatusArray stat,
                           const IloConstraintArray   con) const {
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  IloAssert (stat.getImpl() != 0, "array not initialized");
  IloAssert (con.getImpl() != 0, "array not initialized");
  getImpl()->getBasisStatuses(stat, con);
}

inline void
IloCplex::getBasisStatuses(IloCplex::BasisStatusArray cstat,
                           const IloNumVarArray       var,
                           IloCplex::BasisStatusArray rstat,
                           const IloConstraintArray   con) const {
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  IloAssert (cstat.getImpl() != 0, "array not initialized");
  IloAssert (var.getImpl() != 0, "array not initialized");
  IloAssert (rstat.getImpl() != 0, "array not initialized");
  IloAssert (con.getImpl() != 0, "array not initialized");
  getImpl()->getBasisStatuses(cstat, var, rstat, con);
}

inline void
IloCplex::getBasisStatuses(IloCplex::BasisStatusArray cstat,
                           const IloIntVarArray       var,
                           IloCplex::BasisStatusArray rstat,
                           const IloConstraintArray   con) const {
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  IloAssert (cstat.getImpl() != 0, "array not initialized");
  IloAssert (var.getImpl() != 0, "array not initialized");
  IloAssert (rstat.getImpl() != 0, "array not initialized");
  IloAssert (con.getImpl() != 0, "array not initialized");
  getImpl()->getBasisStatuses(cstat, var, rstat, con);
}

inline void
IloCplex::setBasisStatuses(const IloCplex::BasisStatusArray cstat,
                           const IloNumVarArray             var,
                           const IloCplex::BasisStatusArray rstat,
                           const IloConstraintArray         con) {
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  IloAssert (var.getImpl()   == 0            ||
             cstat.getImpl() != 0            ||
             cstat.getSize() == var.getSize()  ,
             "arrays sizes don't match");
  IloAssert (rstat.getImpl() == 0            ||
             con.getImpl()   != 0            ||
             rstat.getSize() == con.getSize()  ,
             "arrays sizes don't match");
  getImpl()->setBasisStatuses(cstat, var, rstat, con);
}

inline void
IloCplex::setBasisStatuses(const IloCplex::BasisStatusArray cstat,
                           const IloIntVarArray             var,
                           const IloCplex::BasisStatusArray rstat,
                           const IloConstraintArray         con) {
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  IloAssert (var.getImpl()   == 0            ||
             cstat.getImpl() != 0            ||
             cstat.getSize() == var.getSize()  ,
             "arrays sizes don't match");
  IloAssert (rstat.getImpl() == 0            ||
             con.getImpl()   != 0            ||
             rstat.getSize() == con.getSize()  ,
             "arrays sizes don't match");
  getImpl()->setBasisStatuses(cstat, var, rstat, con);
}

inline void
IloCplex::setStart(const IloNumArray    x,
                     const IloNumArray    dj,
                     const IloNumVarArray var,
                     const IloNumArray    slack,
                     const IloNumArray    pi,
                     const IloRangeArray  rng) {
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  IloAssert (var.getImpl() == 0              ||
             (x.getImpl() != 0            &&
              x.getSize() == var.getSize()  )  ,
             "arrays sizes don't match");
  IloAssert (var.getImpl() == 0            ||
             dj.getImpl()  == 0            ||
             dj.getSize()  == var.getSize()  ,
             "arrays sizes don't match");
  IloAssert (rng.getImpl() == 0               ||
             (pi.getImpl() != 0            &&
              pi.getSize() == rng.getSize()  )  ,
             "arrays sizes don't match");
  IloAssert (rng.getImpl()   == 0            ||
             slack.getImpl() == 0            ||
             slack.getSize() == rng.getSize()  ,
             "arrays sizes don't match");
  getImpl()->setStart(x, dj, var, slack, pi, rng);
}

inline void
IloCplex::setStart(const IloNumArray    x,
                          const IloNumArray    dj,
                          const IloIntVarArray var,
                          const IloNumArray    slack,
                          const IloNumArray    pi,
                          const IloRangeArray  rng) {
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  IloAssert (var.getImpl() == 0              ||
             (x.getImpl() != 0            &&
              x.getSize() == var.getSize()  )  ,
             "arrays sizes don't match");
  IloAssert (var.getImpl() == 0            ||
             dj.getImpl()  == 0            ||
             dj.getSize()  == var.getSize()  ,
             "arrays sizes don't match");
  IloAssert (rng.getImpl() == 0               ||
             (pi.getImpl() != 0            &&
              pi.getSize() == rng.getSize()  )  ,
             "arrays sizes don't match");
  IloAssert (rng.getImpl()   == 0            ||
             slack.getImpl() == 0            ||
             slack.getSize() == rng.getSize()  ,
             "arrays sizes don't match");
  getImpl()->setStart(x, dj, var, slack, pi, rng);
}


inline IloInt
IloCplex::addMIPStart (IloNumVarArray vars, IloNumArray values,
                        IloCplex::MIPStartEffort effort,
                        const char *name)
{
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  return (getImpl()->addMIPStart (vars, values, effort, name));
}

inline void
IloCplex::changeMIPStart (IloInt mipstartindex, IloNumVarArray vars,
                          IloNumArray values)
{
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  getImpl()->changeMIPStart (mipstartindex, vars, values);
}
inline void
IloCplex::changeMIPStart (IloInt mipstartindex, IloNumVarArray vars,
                        IloNumArray values,
                        IloCplex::MIPStartEffort effort)
{
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  getImpl()->changeMIPStart (mipstartindex, vars, values, effort);
}


inline void
IloCplex::deleteMIPStarts (IloInt first, IloInt num)
{
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  getImpl()->deleteMIPStarts (first, num);
}

inline int
IloCplex::getNMIPStarts() const
{
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  return (getImpl()->getNMIPStarts());
}

inline IloCplex::MIPStartEffort
IloCplex::getMIPStart (IloInt               mipstartindex,
                       const IloNumVarArray vars,
                       IloNumArray          vals,
                       IloBoolArray         isset)
{
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  return (getImpl()->getMIPStart (mipstartindex, vars, vals, isset));
}

inline const char *
IloCplex::getMIPStartName (IloInt mipstartindex)
{
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  return (getImpl()->getMIPStartName (mipstartindex));
}

inline IloInt
IloCplex::getMIPStartIndex(const char *lname_str) const
{
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  return (getImpl()->getMIPStartIndex(lname_str));
}


inline IloNum
IloCplex::getAX(const IloRange con) const {
  IloAssert (getImpl() != 0,     "accessing IloCplex through 0 handle");
  IloAssert (con.getImpl() != 0, "accessing IloRange through 0 handle");
  return (getImpl()->getAX(con.getImpl()));
}

inline void
IloCplex::getAX(IloNumArray val, const IloRangeArray con) const {
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  IloAssert (val.getImpl() != 0, "array not initialized");
  IloAssert (con.getImpl() != 0, "array not initialized");
  getImpl()->getAX(val, con);
}

inline void
IloCplex::getBoundSA(IloNumArray lblower, IloNumArray lbupper,
                          IloNumArray ublower, IloNumArray ubupper,
                          const IloNumVarArray cols) const {
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  IloAssert (cols.getImpl() != 0, "array not initialized");
  getImpl()->getBoundSA(lblower, lbupper, ublower, ubupper, cols);
}

inline void
IloCplex::getBoundSA(IloNumArray lblower, IloNumArray lbupper,
                          IloNumArray ublower, IloNumArray ubupper,
                          const IloIntVarArray cols) const {
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  IloAssert (cols.getImpl() != 0, "array not initialized");
  getImpl()->getBoundSA(lblower, lbupper, ublower, ubupper, cols);
}

inline void
IloCplex::getRangeSA(IloNumArray lblower, IloNumArray lbupper,
                          IloNumArray ublower, IloNumArray ubupper,
                          const IloRangeArray rows) const {
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  IloAssert (rows.getImpl() != 0, "array not initialized");
  getImpl()->getRangeSA(lblower, lbupper, ublower, ubupper, rows);
}

inline void
IloCplex::getRHSSA(IloNumArray lower, IloNumArray upper,
                        const IloRangeArray rows) const {
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  IloAssert (rows.getImpl() != 0, "array not initialized");
  getImpl()->getRHSSA(lower, upper, rows);
}

inline void
IloCplex::getObjSA(IloNumArray lower, IloNumArray upper,
                        const IloNumVarArray cols) const {
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  IloAssert (cols.getImpl() != 0, "array not initialized");
  getImpl()->getObjSA(lower, upper, cols);
}

inline void
IloCplex::getObjSA(IloNumArray lower, IloNumArray upper,
                        const IloIntVarArray cols) const {
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  IloAssert (cols.getImpl() != 0, "array not initialized");
  getImpl()->getObjSA(lower, upper, cols);
}

inline IloBool
IloCplex::refineConflict(IloConstraintArray cons, IloNumArray prios) {
  IloAssert (getImpl() != 0,     "accessing IloCplex through 0 handle");
  IloAssert (cons.getImpl() != 0, "array not initialized");
  IloAssert (prios.getImpl() != 0, "array not initialized");
  IloAssert (cons.getSize() == prios.getSize(), "array sizes don't match");
  return getImpl()->refineConflict(cons, prios);
}


inline IloBool
IloCplex::refineMIPStartConflict(IloInt mst, IloConstraintArray cons, IloNumArray prios) {
  IloAssert (getImpl() != 0,     "accessing IloCplex through 0 handle");
  IloAssert (cons.getImpl() != 0, "array not initialized");
  IloAssert (prios.getImpl() != 0, "array not initialized");
  IloAssert (cons.getSize() == prios.getSize(), "array sizes don't match");
  return getImpl()->refineMIPStartConflict(mst, cons, prios);
}


inline IloCplex::ConflictStatus
IloCplex::getConflict (IloConstraint rng) const
{
  IloAssert (getImpl() != 0,     "accessing IloCplex through 0 handle");
  IloAssert (rng.getImpl() != 0, "array not initialized");
  return getImpl()->getConflict(rng);
}

inline IloCplex::ConflictStatusArray
IloCplex::getConflict (IloConstraintArray rng) const
{
  IloAssert (getImpl() != 0,     "accessing IloCplex through 0 handle");
  IloAssert (rng.getImpl() != 0, "array not initialized");
  return getImpl()->getConflict(rng);
}


inline void
IloCplex::getDnorms(IloNumArray dnorms, const IloNumVarArray vars,
                                             const IloRangeArray  cons) const {
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  IloAssert (dnorms.getImpl() != 0, "array not initialized");
  IloAssert (vars.getImpl() ||  cons.getImpl() != 0, "array not initialized");
  getImpl()->getDnorms(dnorms, vars, cons);
}

inline void
IloCplex::getDnorms(IloNumArray dnorms, const IloIntVarArray vars,
                                             const IloRangeArray  cons) const {
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  IloAssert (dnorms.getImpl() != 0, "array not initialized");
  IloAssert (vars.getImpl() ||  cons.getImpl() != 0, "array not initialized");
  getImpl()->getDnorms(dnorms, vars, cons);
}

inline void
IloCplex::getPnorms(IloNumArray cnorms, const IloNumVarArray vars,
                         IloNumArray rnorms, const IloRangeArray  cons) const {
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  IloAssert (vars.getImpl() == 0  ||  cnorms.getImpl() != 0, "array not initialized");
  IloAssert (cons.getImpl() == 0  ||  rnorms.getImpl() != 0, "array not initialized");
  getImpl()->getPnorms(cnorms, vars, rnorms, cons);
}

inline void
IloCplex::getPnorms(IloNumArray cnorms, const IloIntVarArray vars,
                         IloNumArray rnorms, const IloRangeArray  cons) const {
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  IloAssert (vars.getImpl() == 0  ||  cnorms.getImpl() != 0, "array not initialized");
  IloAssert (cons.getImpl() == 0  ||  rnorms.getImpl() != 0, "array not initialized");
  getImpl()->getPnorms(cnorms, vars, rnorms, cons);
}

inline void
IloCplex::setDnorms(const IloNumArray norms, const IloNumVarArray vars,
                                                  const IloRangeArray  cons) {
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  IloAssert (norms.getImpl() != 0, "array not initialized");
  IloAssert (vars.getImpl() != 0, "array not initialized");
  IloAssert (cons.getImpl() != 0, "array not initialized");
  getImpl()->setDnorms(norms, vars, cons);
}

inline void
IloCplex::setDnorms(const IloNumArray norms, const IloIntVarArray vars,
                                                  const IloRangeArray  cons) {
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  IloAssert (norms.getImpl() != 0, "array not initialized");
  IloAssert (vars.getImpl() != 0, "array not initialized");
  IloAssert (cons.getImpl() != 0, "array not initialized");
  getImpl()->setDnorms(norms, vars, cons);
}

inline void
IloCplex::setPnorms(const IloNumArray cnorms, const IloNumVarArray vars,
                         const IloNumArray rnorms, const IloRangeArray  cons) {
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  IloAssert (cnorms.getImpl() != 0, "array not initialized");
  IloAssert (rnorms.getImpl() != 0, "array not initialized");
  IloAssert (vars.getImpl() != 0, "array not initialized");
  IloAssert (cons.getImpl() != 0, "array not initialized");
  getImpl()->setPnorms(cnorms, vars, rnorms, cons);
}

inline void
IloCplex::setPnorms(const IloNumArray cnorms, const IloIntVarArray vars,
                         const IloNumArray rnorms, const IloRangeArray  cons) {
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  IloAssert (cnorms.getImpl() != 0, "array not initialized");
  IloAssert (rnorms.getImpl() != 0, "array not initialized");
  IloAssert (vars.getImpl() != 0, "array not initialized");
  IloAssert (cons.getImpl() != 0, "array not initialized");
  getImpl()->setPnorms(cnorms, vars, rnorms, cons);
}

inline IloNum
IloCplex::getQuality(Quality q, IloNumVar*     var,
                                IloConstraint* rng) const {
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  return (getImpl()->getQuality(q, IloCplex::IncumbentId, var, rng));
}

inline IloNum
IloCplex::getQuality(Quality q, IloInt         soln,
                                IloNumVar*     var,
                                IloConstraint* rng) const {
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  return (getImpl()->getQuality(q, soln, var, rng));
}

inline IloNum
IloCplex::getQuality(Quality q, IloConstraint* rng,
                                IloNumVar*     var) const {
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  return (getImpl()->getQuality(q, IloCplex::IncumbentId, var, rng));
}

inline IloNum
IloCplex::getQuality(Quality q, IloInt         soln,
                                IloConstraint* rng,
                                IloNumVar*     var) const {
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  return (getImpl()->getQuality(q, soln, var, rng));
}

inline void
IloCplex::setPriority  (IloNumVar var, IloNum pri) {
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  getImpl()->setPriority(var.getImpl(), pri);
}

inline void
IloCplex::setPriority  (IloIntVar var, IloNum pri) {
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  getImpl()->setPriority(var.getImpl(), pri);
}

inline void
IloCplex::setPriorities(const IloNumVarArray var, const IloNumArray pri) {
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  IloAssert (var.getImpl() != 0, "array not initialized");
  IloAssert (pri.getImpl() != 0, "array not initialized");
  getImpl()->setPriorities(var, pri);
}

inline void
IloCplex::setPriorities(const IloIntVarArray var, const IloNumArray pri) {
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  IloAssert (var.getImpl() != 0, "array not initialized");
  IloAssert (pri.getImpl() != 0, "array not initialized");
  getImpl()->setPriorities(var, pri);
}

inline void
IloCplex::setDirection (IloNumVar var, BranchDirection dir) {
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  getImpl()->setDirection(var.getImpl(), dir);
}

inline void
IloCplex::setDirection (IloIntVar var, BranchDirection dir) {
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  getImpl()->setDirection(var.getImpl(), dir);
}

inline void
IloCplex::setDirections(const IloNumVarArray var, const BranchDirectionArray dir) {
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  IloAssert (var.getImpl() != 0, "array not initialized");
  IloAssert (dir.getImpl() != 0, "array not initialized");
  getImpl()->setDirections(var, dir);
}

inline void
IloCplex::setDirections(const IloIntVarArray var, const BranchDirectionArray dir) {
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  IloAssert (var.getImpl() != 0, "array not initialized");
  IloAssert (dir.getImpl() != 0, "array not initialized");
  getImpl()->setDirections(var, dir);
}

inline void
IloCplex::delPriority  (IloNumVar var) {
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  getImpl()->delPriority(var.getImpl());
}

inline void
IloCplex::delPriority  (IloIntVar var) {
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  getImpl()->delPriority(var.getImpl());
}

inline void
IloCplex::delPriorities(const IloNumVarArray var) {
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  IloAssert (var.getImpl() != 0, "array not initialized");
  getImpl()->delPriorities(var);
}

inline void
IloCplex::delPriorities(const IloIntVarArray var) {
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  IloAssert (var.getImpl() != 0, "array not initialized");
  getImpl()->delPriorities(var);
}

inline void
IloCplex::delDirection (IloNumVar var) {
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  getImpl()->delDirection(var.getImpl());
}

inline void
IloCplex::delDirection (IloIntVar var) {
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  getImpl()->delDirection(var.getImpl());
}

inline void
IloCplex::delDirections(const IloNumVarArray var) {
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  IloAssert (var.getImpl() != 0, "array not initialized");
  getImpl()->delDirections(var);
}

inline void
IloCplex::delDirections(const IloIntVarArray var) {
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  IloAssert (var.getImpl() != 0, "array not initialized");
  getImpl()->delDirections(var);
}


inline IloNum IloCplex::getPriority(IloNumVar var) const {
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  IloAssert (var.getImpl() != 0, "accessing IloNumVar through 0 handle");
  return (getImpl()->getPriority(var));
}

inline IloNum IloCplex::getPriority(IloIntVar var) const {
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  IloAssert (var.getImpl() != 0, "accessing IloIntVar through 0 handle");
  return (getImpl()->getPriority(var));
}

inline IloCplex::BranchDirection IloCplex::getDirection(IloNumVar var) const {
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  IloAssert (var.getImpl() != 0, "accessing IloNumVar through 0 handle");
  return (getImpl()->getDirection(var));
}

inline IloCplex::BranchDirection IloCplex::getDirection(IloIntVar var) const {
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  IloAssert (var.getImpl() != 0, "accessing IloIntVar through 0 handle");
  return (getImpl()->getDirection(var));
}

inline void IloCplex::getPriorities(IloNumArray          pri,
                                    const IloNumVarArray var) const {
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  IloAssert (var.getImpl() != 0, "accessing IloNumVarArray through 0 handle");
  IloAssert (pri.getImpl() != 0, "accessing IloVarArray through 0 handle");
  getImpl()->getPriorities(var, pri);
}

inline void IloCplex::getPriorities(IloNumArray          pri,
                                    const IloIntVarArray var) const {
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  IloAssert (var.getImpl() != 0, "accessing IloIntVarArray through 0 handle");
  IloAssert (pri.getImpl() != 0, "accessing IloVarArray through 0 handle");
  getImpl()->getPriorities(var, pri);
}

inline void IloCplex::getDirections(BranchDirectionArray dir,
                                    const IloNumVarArray var) const {
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  IloAssert (var.getImpl() != 0, "accessing IloNumVarArray through 0 handle");
  IloAssert (dir.getImpl() != 0, "accessing IloVarArray through 0 handle");
  getImpl()->getDirections(var, dir);
}

inline void IloCplex::getDirections(BranchDirectionArray dir,
                                    const IloIntVarArray var) const {
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  IloAssert (var.getImpl() != 0, "accessing IloIntVarArray through 0 handle");
  IloAssert (dir.getImpl() != 0, "accessing IloVarArray through 0 handle");
  getImpl()->getDirections(var, dir);
}


inline void IloCplex::basicPresolve(const IloNumVarArray vars,
                                    IloNumArray          redlb,
                                    IloNumArray          redub,
                                    const IloRangeArray  rngs,
                                    IloBoolArray         redundant) const {
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  getImpl()->basicPresolve(vars, redlb, redub, rngs, redundant);
}

inline void IloCplex::basicPresolve(const IloIntVarArray vars,
                                    IloNumArray          redlb,
                                    IloNumArray          redub,
                                    const IloRangeArray  rngs,
                                    IloBoolArray         redundant) const {
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  getImpl()->basicPresolve(vars, redlb, redub, rngs, redundant);
}

inline void IloCplex::presolve(IloCplex::Algorithm alg) {
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  getImpl()->presolve(alg);
}

inline void IloCplex::freePresolve() {
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  getImpl()->freePresolve();
}

inline void IloCplex::getRay(IloNumArray vals, IloNumVarArray vars) const {
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  IloAssert (vals.getImpl() != 0, "array not initialized");
  IloAssert (vars.getImpl() != 0, "array not initialized");
  getImpl()->getRay(vals, vars);
}

inline void
IloCplex::getDriebeekPenalties(IloNumArray          downratio,
                                    IloNumArray          upratio,
                                    const IloNumVarArray ind) const {
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  IloAssert (ind.getImpl() != 0, "array not initialized");
  getImpl()->getDriebeekPenalties(ind, downratio, upratio);
}

inline void
IloCplex::getDriebeekPenalties(IloNumArray          downratio,
                                    IloNumArray          upratio,
                                    const IloIntVarArray ind) const {
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  IloAssert (ind.getImpl() != 0, "array not initialized");
  getImpl()->getDriebeekPenalties(ind, downratio, upratio);
}

inline void
IloCplex::getDriebeekPenalties(IloNumArray         downratio,
                                    IloNumArray         upratio,
                                    const IloRangeArray ind) const {
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  IloAssert (ind.getImpl() != 0, "array not initialized");
  getImpl()->getDriebeekPenalties(ind, downratio, upratio);
}

inline void
IloCplex::getStrongBranch(IloNumArray          downratio,
                               IloNumArray          upratio,
                               const IloNumVarArray ind,
                               IloInt64             itmax) const {
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  IloAssert (ind.getImpl() != 0, "array not initialized");
  getImpl()->getStrongBranch(ind, downratio, upratio, itmax);
}

inline void
IloCplex::getStrongBranch(IloNumArray          downratio,
                               IloNumArray          upratio,
                               const IloIntVarArray ind,
                               IloInt64             itmax) const {
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  IloAssert (ind.getImpl() != 0, "array not initialized");
  getImpl()->getStrongBranch(ind, downratio, upratio, itmax);
}

inline void
IloCplex::getStrongBranch(IloNumArray         downratio,
                               IloNumArray         upratio,
                               const IloRangeArray ind,
                               IloInt64            itmax) const {
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  IloAssert (ind.getImpl() != 0, "array not initialized");
  getImpl()->getStrongBranch(ind, downratio, upratio, itmax);
}

inline void
IloCplex::protectVariables(const IloNumVarArray var) {
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  getImpl()->protectVariables(var);
}

inline void
IloCplex::protectVariables(const IloIntVarArray var) {
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  getImpl()->protectVariables(var);
}

inline IloNum
IloCplex::dualFarkas(IloConstraintArray  rng, IloNumArray y) {
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  return (getImpl()->dualFarkas(rng, y));
}

inline void
IloCplex::qpIndefCertificate(IloNumVarArray var, IloNumArray x) {
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  IloAssert (var.getImpl() != 0, "array not initialized");
  IloAssert (x.getImpl()   != 0, "array not initialized");
  getImpl()->qpIndefCertificate(var, x);
}

inline void
IloCplex::qpIndefCertificate(IloIntVarArray var, IloNumArray x) {
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  IloAssert (var.getImpl() != 0, "array not initialized");
  IloAssert (x.getImpl()   != 0, "array not initialized");
  getImpl()->qpIndefCertificate(var, x);
}

inline IloBool IloCplex::feasOpt(const IloRangeArray  rngs,
                                 const IloNumArray    rnglb,
                                 const IloNumArray    rngub,
                                 const IloNumVarArray vars,
                                 const IloNumArray    varlb,
                                 const IloNumArray    varub) {
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  return getImpl()->feasOpt(rngs, rnglb, rngub,
                            vars, varlb, varub);
}

inline IloBool IloCplex::feasOpt(const IloRangeArray  rngs,
                                 const IloNumArray    rnglb,
                                 const IloNumArray    rngub,
                                 const IloIntVarArray vars,
                                 const IloNumArray    varlb,
                                 const IloNumArray    varub) {
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  return getImpl()->feasOpt(rngs, rnglb, rngub, vars, varlb, varub);
}

inline IloBool IloCplex::feasOpt(const IloNumVarArray vars,
                                 const IloNumArray    varlb,
                                 const IloNumArray    varub)
{
  return feasOpt(0, 0, 0, vars, varlb, varub);
}

inline IloBool IloCplex::feasOpt(const IloIntVarArray vars,
                                 const IloNumArray    varlb,
                                 const IloNumArray    varub)
{
  return feasOpt(0, 0, 0, vars, varlb, varub);
}

inline IloBool IloCplex::feasOpt(const IloRangeArray rngs,
                                 const IloNumArray   rnglb,
                                 const IloNumArray   rngub)
{
   IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
   IloAssert (rngs.getImpl()  != 0, "accessing constraint array through 0 handle");
   IloAssert (rnglb.getImpl() != 0, "accessing value array through 0 handle");
   IloAssert (rngub.getImpl() != 0, "accessing value array through 0 handle");
   IloAssert (rnglb.getSize() == rngs.getSize(),
              "incompatible array sizes");
   IloAssert (rngub.getSize() == rngs.getSize(),
              "incompatible array sizes");
   return getImpl()->feasOpt(rngs, rnglb, rngub, IloNumVarArray(0), 0, 0);
}


inline IloBool IloCplex::feasOpt(const IloConstraintArray rngs,
                                 const IloNumArray        relax)
{
   IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
   IloAssert (rngs.getImpl()  != 0, "accessing constraint array through 0 handle");
   IloAssert (relax.getImpl() != 0, "accessing value array through 0 handle");
   IloAssert (relax.getSize() == rngs.getSize(),
              "incompatible array sizes");
   return getImpl()->feasOpt(rngs, relax);
}



inline void
IloCplex::readAnnotations(const char* name)
{
   getImpl()->readAnnotations(name);
}

inline void
IloCplex::writeAnnotations(const char* name) const
{
   getImpl()->writeAnnotations(name);
}

inline void
IloCplex::writeBendersAnnotation(const char* name) const
{
   getImpl()->writeBendersAnnotation(name);
}

inline IloInt
IloCplex::numLongAnnotations () const
{
   return getImpl()->numLongAnnotations ();
}

inline void
IloCplex::delAnnotation (IloCplex::LongAnnotation anno)
{
   getImpl()->delAnnotation (anno);
}

inline const char *
IloCplex::getName(const IloCplex::LongAnnotation annotation) const
{
   return getImpl()->getName(annotation);
}

inline IloCplex::LongAnnotation
IloCplex::newLongAnnotation  (const char *name, IloInt64 defval)
{
   return getImpl()->newLongAnnotation  (name, defval);
}

inline IloCplex::LongAnnotation
IloCplex::findLongAnnotation (const char *name) const
{
   return getImpl()->findLongAnnotation (name);
}

inline IloCplex::LongAnnotation
IloCplex::findLongAnnotation (IloInt num) const
{
   return getImpl()->findLongAnnotation (num);
}

inline IloBool
IloCplex::hasLongAnnotation  (const char *name) const
{
   return getImpl()->hasLongAnnotation  (name);
}

inline IloInt64
IloCplex::getDefaultValue (const LongAnnotation annotation) const
{
   return getImpl()->getDefaultValue (annotation);
}

inline IloInt64
IloCplex::getAnnotation (const IloCplex::LongAnnotation annotation, const IloNumVar var) const
{
   return getImpl()->getAnnotation (annotation, var.getImpl());
}

inline IloInt64
IloCplex::getAnnotation (const IloCplex::LongAnnotation annotation, const IloIntVar var) const
{
   return getImpl()->getAnnotation (annotation, var.getImpl());
}

inline IloInt64
IloCplex::getAnnotation (const IloCplex::LongAnnotation annotation, const IloObjective obj) const
{
   return getImpl()->getAnnotation (annotation, obj.getImpl());
}

inline IloInt64
IloCplex::getAnnotation (const IloCplex::LongAnnotation annotation, const IloConstraint obj) const
{
   return getImpl()->getAnnotation (annotation, obj.getImpl());
}

inline void
IloCplex::getAnnotation (const IloCplex::LongAnnotation annotation, const IloNumVarArray var,     IloArray<IloInt64>& value) const
{
   getImpl()->getAnnotation (annotation, var, value);
}

inline void
IloCplex::getAnnotation (const IloCplex::LongAnnotation annotation, const IloIntVarArray var,     IloArray<IloInt64>& value) const
{
   getImpl()->getAnnotation (annotation, var, value);
}

inline void
IloCplex::getAnnotation (const IloCplex::LongAnnotation annotation, const IloConstraintArray obj, IloArray<IloInt64>& value) const
{
   getImpl()->getAnnotation (annotation, obj, value);
}

inline void
IloCplex::setAnnotation (const IloCplex::LongAnnotation annotation, const IloNumVar var,     IloInt64 value)
{
   getImpl()->setAnnotation (annotation, var.getImpl(), value);
}

inline void
IloCplex::setAnnotation (const IloCplex::LongAnnotation annotation, const IloIntVar var,     IloInt64 value)
{
   getImpl()->setAnnotation (annotation, var.getImpl(), value);
}

inline void
IloCplex::setAnnotation (const IloCplex::LongAnnotation annotation, const IloObjective obj,  IloInt64 value)
{
   getImpl()->setAnnotation (annotation, obj.getImpl(), value);
}

inline void
IloCplex::setAnnotation (const IloCplex::LongAnnotation annotation, const IloConstraint obj, IloInt64 value)
{
   getImpl()->setAnnotation (annotation, obj.getImpl(), value);
}

inline void
IloCplex::setAnnotation (const IloCplex::LongAnnotation annotation, const IloNumVarArray var,     const IloArray<IloInt64> value)
{
   getImpl()->setAnnotation (annotation, var, value);
}

inline void
IloCplex::setAnnotation (const IloCplex::LongAnnotation annotation, const IloIntVarArray var,     const IloArray<IloInt64> value)
{
   getImpl()->setAnnotation (annotation, var, value);
}

inline void
IloCplex::setAnnotation (const IloCplex::LongAnnotation annotation, const IloConstraintArray obj, const IloArray<IloInt64> value)
{
   getImpl()->setAnnotation (annotation, obj, value);
}

inline
IloInt
IloCplex::numNumAnnotations () const
{
   return getImpl()->numNumAnnotations ();
}

inline void
IloCplex::delAnnotation (IloCplex::NumAnnotation anno)
{
   getImpl()->delAnnotation (anno);
}

inline const char *
IloCplex::getName(const IloCplex::NumAnnotation annotation) const
{
   return getImpl()->getName(annotation);
}

inline IloCplex::NumAnnotation
IloCplex::newNumAnnotation  (const char *name, IloNum defval)
{
   return getImpl()->newNumAnnotation  (name, defval);
}

inline IloCplex::NumAnnotation
IloCplex::findNumAnnotation (const char *name) const
{
   return getImpl()->findNumAnnotation (name);
}

inline IloCplex::NumAnnotation
IloCplex::findNumAnnotation (IloInt num) const
{
   return getImpl()->findNumAnnotation (num);
}

inline IloBool
IloCplex::hasNumAnnotation  (const char *name) const
{
   return getImpl()->hasNumAnnotation  (name);
}

inline IloNum
IloCplex::getDefaultValue (const NumAnnotation annotation) const
{
   return getImpl()->getDefaultValue (annotation);
}

inline IloNum
IloCplex::getAnnotation (const IloCplex::NumAnnotation annotation, const IloNumVar var) const
{
   return getImpl()->getAnnotation (annotation, var.getImpl());
}

inline IloNum
IloCplex::getAnnotation (const IloCplex::NumAnnotation annotation, const IloIntVar var) const
{
   return getImpl()->getAnnotation (annotation, var.getImpl());
}

inline IloNum
IloCplex::getAnnotation (const IloCplex::NumAnnotation annotation, const IloObjective obj) const
{
   return getImpl()->getAnnotation (annotation, obj.getImpl());
}

inline IloNum
IloCplex::getAnnotation (const IloCplex::NumAnnotation annotation, const IloConstraint obj) const
{
   return getImpl()->getAnnotation (annotation, obj.getImpl());
}

inline void
IloCplex::getAnnotation (const IloCplex::NumAnnotation annotation, const IloNumVarArray var,     IloNumArray& value) const
{
   getImpl()->getAnnotation (annotation, var, value);
}

inline void
IloCplex::getAnnotation (const IloCplex::NumAnnotation annotation, const IloIntVarArray var,     IloNumArray& value) const
{
   getImpl()->getAnnotation (annotation, var, value);
}

inline void
IloCplex::getAnnotation (const IloCplex::NumAnnotation annotation, const IloConstraintArray obj, IloNumArray& value) const
{
   getImpl()->getAnnotation (annotation, obj, value);
}

inline void
IloCplex::setAnnotation (const IloCplex::NumAnnotation annotation, const IloNumVar var,     IloNum value)
{
   getImpl()->setAnnotation (annotation, var.getImpl(), value);
}

inline void
IloCplex::setAnnotation (const IloCplex::NumAnnotation annotation, const IloIntVar var,     IloNum value)
{
   getImpl()->setAnnotation (annotation, var.getImpl(), value);
}

inline void
IloCplex::setAnnotation (const IloCplex::NumAnnotation annotation, const IloObjective obj,  IloNum value)
{
   getImpl()->setAnnotation (annotation, obj.getImpl(), value);
}

inline void
IloCplex::setAnnotation (const IloCplex::NumAnnotation annotation, const IloConstraint obj, IloNum value)
{
   getImpl()->setAnnotation (annotation, obj.getImpl(), value);
}

inline void
IloCplex::setAnnotation (const IloCplex::NumAnnotation annotation, const IloNumVarArray var, const IloNumArray value)
{
   getImpl()->setAnnotation (annotation, var.getImpl(), value);
}

inline void
IloCplex::setAnnotation (const IloCplex::NumAnnotation annotation, const IloIntVarArray var, const IloNumArray value)
{
   getImpl()->setAnnotation (annotation, var, value);
}

inline void
IloCplex::setAnnotation (const IloCplex::NumAnnotation annotation, const IloConstraintArray obj, const IloNumArray value)
{
   getImpl()->setAnnotation (annotation, obj, value);
}


inline IloNum IloCplex::getSolnPoolMeanObjValue() const {
   IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
   return getImpl()->getSolnPoolMeanObjValue();
}
inline IloInt IloCplex::getSolnPoolNsolns() const {
   IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
   return getImpl()->getSolnPoolNsolns();
}
inline IloInt IloCplex::getSolnPoolNreplaced() const {
   IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
   return getImpl()->getSolnPoolNreplaced();
}

inline void IloCplex::delSolnPoolSoln(IloInt soln) {
   IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
   getImpl()->delSolnPoolSolns(soln, soln);
}

inline void IloCplex::delSolnPoolSolns(IloInt begin, IloInt end) {
   IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
   getImpl()->delSolnPoolSolns(begin, end);
}
inline void IloCplex::writeFilters(const char* filename) {
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  getImpl()->writeFilters(filename);
}

inline IloCplex::IndexArray IloCplex::readFilters(const char* filename) {
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  return getImpl()->readFilters(filename);
}
inline IloCplex::FilterIndex
IloCplex::addDiversityFilter(IloNum lower_bound, IloNum upper_bound,
				   const IloNumVarArray vars,
				   const IloNumArray weights,
				   const IloNumArray refval,
				   const char *fname) {
  IloAssert(_impl, "Using empty handle IloCplex");
  IloAssert(vars.getImpl() != 0, "accessing IloNumVarArray through 0 handle");
  IloAssert(weights.getImpl() != 0, "accessing IloNumArray through 0 handle");
  IloAssert(refval.getImpl() != 0, "accessing IloNumArray through 0 handle");
  return getImpl()->addDiversityFilter(lower_bound, upper_bound,
				       vars, weights, refval, fname);
}

inline IloCplex::FilterIndex
IloCplex::addDiversityFilter(IloNum lower_bound, IloNum upper_bound,
				   const IloIntVarArray vars,
				   const IloNumArray weights,
				   const IloNumArray refval,
				   const char *fname) {
  IloAssert(_impl, "Using empty handle IloCplex");
  IloAssert(vars.getImpl() != 0, "accessing IloIntVarArray through 0 handle");
  IloAssert(weights.getImpl() != 0, "accessing IloNumArray through 0 handle");
  IloAssert(refval.getImpl() != 0, "accessing IloNumArray through 0 handle");
  return getImpl()->addDiversityFilter(lower_bound, upper_bound,
				       vars, weights, refval, fname);
}

inline IloCplex::FilterIndex
IloCplex::getFilterIndex(const char *lname_str) const {
  IloAssert(_impl, "Using empty handle IloCplex");
  return getImpl()->getFilterIndex(lname_str);
}

inline IloInt IloCplex::getNfilters() const {
  IloAssert(_impl, "Using empty handle IloCplex");
  return getImpl()->getNfilters();
}

inline IloCplex::FilterType IloCplex::getFilterType(FilterIndex i) const {
  IloAssert(_impl, "Using empty handle IloCplex");
  return getImpl()->getFilterType(i);
}

inline IloNum IloCplex::getDiversityFilterLowerCutoff(FilterIndex i) const {
  IloAssert(_impl, "Using empty handle IloCplex");
  return getImpl()->getFilterLowerBound(i);
}

inline IloNum IloCplex::getDiversityFilterUpperCutoff(FilterIndex i) const {
  IloAssert(_impl, "Using empty handle IloCplex");
  return getImpl()->getFilterUpperBound(i);
}

inline void IloCplex::getFilterVars(FilterIndex f, IloNumVarArray vars) const {
  IloAssert(_impl, "Using empty handle IloCplex");
  IloAssert(vars.getImpl() != 0, "accessing IloNumVarArray through 0 handle");
  getImpl()->getFilterVars(f, vars);
}

/*
inline void IloCplex::getFilterVars(FilterIndex f, IloIntVarArray vars) const {
  IloAssert(_impl, "Using empty handle IloCplex");
  IloAssert(vars.getImpl() != 0, "accessing IloIntVarArray through 0 handle");
  getImpl()->getFilterVars(f, vars);
}
*/

inline void IloCplex::getDiversityFilterWeights(FilterIndex f, IloNumArray weights) const {
  IloAssert(_impl, "Using empty handle IloCplex");
  IloAssert(weights.getImpl() != 0, "accessing IloNumArray through 0 handle");
  getImpl()->getFilterWeights(f, weights);
}

inline void
IloCplex::getDiversityFilterRefVals(FilterIndex f, IloNumArray refvals) const {
  IloAssert(_impl, "Using empty handle IloCplex");
  IloAssert(refvals.getImpl() != 0, "accessing IloNumArray through 0 handle");
  getImpl()->getFilterRefVals(f, refvals);
}

inline IloCplex::FilterIndex
IloCplex::addRangeFilter(IloNum lower_bound, IloNum upper_bound,
			      const IloNumVarArray vars,
			      const IloNumArray weights,
			      const char *fname) {
  IloAssert(_impl, "Using empty handle IloCplex");
  IloAssert(vars.getImpl() != 0, "accessing IloNumVarArray through 0 handle");
  IloAssert(weights.getImpl() != 0, "accessing IloNumArray through 0 handle");
  return getImpl()->addRangeFilter(lower_bound, upper_bound,
				   vars, weights, fname);
}

inline IloCplex::FilterIndex
IloCplex::addRangeFilter(IloNum lower_bound, IloNum upper_bound,
			      const IloIntVarArray vars,
			      const IloNumArray weights,
			      const char *fname) {
  IloAssert(_impl, "Using empty handle IloCplex");
  IloAssert(vars.getImpl() != 0, "accessing IloIntVarArray through 0 handle");
  IloAssert(weights.getImpl() != 0, "accessing IloNumArray through 0 handle");
  return getImpl()->addRangeFilter(lower_bound, upper_bound,
				   vars, weights, fname);
}

inline IloNum IloCplex::getRangeFilterLowerBound(FilterIndex i) const {
  IloAssert(_impl, "Using empty handle IloCplex");
  return getImpl()->getFilterLowerBound(i);
}

inline IloNum IloCplex::getRangeFilterUpperBound(FilterIndex i) const {
  IloAssert(_impl, "Using empty handle IloCplex");
  return getImpl()->getFilterUpperBound(i);
}

inline void
IloCplex::getRangeFilterCoefs(FilterIndex f, IloNumArray weights) const {
  IloAssert(_impl, "Using empty handle IloCplex");
  IloAssert(weights.getImpl() != 0, "accessing IloNumArray through 0 handle");
  getImpl()->getFilterWeights(f, weights);
}

inline void IloCplex::delFilter(FilterIndex f) {
  IloAssert(_impl, "Using empty handle IloCplex");
  getImpl()->delFilter(f);
}

inline IloNum IloCplex::getCplexTime() const {
  IloAssert(_impl, "Using empty handle IloCplex");
  return getImpl()->getCplexTime();
}

inline IloNum IloCplex::getDetTime() const {
  IloAssert(_impl, "Using empty handle IloCplex");
  return getImpl()->getDetTime();
}

inline int IloCplex::getNumCores() const {
  IloAssert(_impl, "Using empty handle IloCplex");
  return getImpl()->getNumCores();
}

inline IloBool IloCplex::populate()
{
   IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
   return getImpl()->populate();
}

inline IloInt IloCplex::tuneParam()
{
   IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
   IloCplex::ParameterSet set(0);
   return getImpl()->tuneParam(set);
}

inline IloInt IloCplex::tuneParam(IloCplex::ParameterSet fixedset)
{
   IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
   IloAssert(fixedset.getImpl() != 0, "accessing ParameterSet through 0 handle");
   return getImpl()->tuneParam(fixedset);
}

inline IloInt IloCplex::tuneParam(IloArray<const char *>filename)
{
   IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
   return getImpl()->tuneParam(filename, 0);
}

inline IloInt IloCplex::tuneParam(IloArray<const char *> filename,
                                  IloCplex::ParameterSet fixedset)
{
   IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
   IloAssert(fixedset.getImpl() != 0, "accessing ParameterSet through 0 handle");
   return getImpl()->tuneParam(filename, fixedset);
}


inline IloCplex::Aborter IloCplex::use(Aborter abort)
{
   IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
   IloAssert(abort.getImpl() != 0, "accessing Aborter through 0 handle");
   getImpl()->use(abort._impl);
   return (abort);
}

inline void IloCplex::remove(Aborter abort)
{
   IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
   getImpl()->remove(abort._impl);
}

inline IloCplex::Aborter IloCplex::getAborter()
{
   IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
   return (getImpl()->getAborter());
}

#ifndef ILOG_CPLEX_NO_REMOTE_API

inline IloCplex::PopulateHandle IloCplex::populate(bool async)
{
   IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
   return getImpl()->populate(async);
}

inline IloCplex::PresolveHandle IloCplex::presolve(IloCplex::Algorithm alg,
                                                   bool async)
{
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  return getImpl()->presolve(alg, async);
}

inline IloCplex::FeasOptHandle
IloCplex::feasOpt(const IloRangeArray rngs,       const IloNumArray rnglb,
                                                  const IloNumArray rngub,
                  const IloForAllRangeArray frng, const IloNumArray frnglb,
                                                  const IloNumArray frngub,
                  const IloNumVarArray vars,      const IloNumArray varlb,
                                                  const IloNumArray varub,
                  bool async) {
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  return getImpl()->feasOpt(rngs, rnglb, rngub,
                            frng, frnglb, frngub,
                            vars, varlb, varub, async);
}

inline IloCplex::FeasOptHandle IloCplex::feasOpt(const IloRangeArray  rngs,
                                                 const IloNumArray    rnglb,
                                                 const IloNumArray    rngub,
                                                 const IloNumVarArray vars,
                                                 const IloNumArray    varlb,
                                                 const IloNumArray    varub,
                                                 bool async) {
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  return getImpl()->feasOpt(rngs, rnglb, rngub,
                            vars, varlb, varub, async);
}

inline IloCplex::FeasOptHandle IloCplex::feasOpt(const IloRangeArray  rngs,
                                                 const IloNumArray    rnglb,
                                                 const IloNumArray    rngub,
                                                 const IloIntVarArray vars,
                                                 const IloNumArray    varlb,
                                                 const IloNumArray    varub,
                                                 bool async) {
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  return getImpl()->feasOpt(rngs, rnglb, rngub, vars, varlb, varub, async);
}

inline IloCplex::FeasOptHandle IloCplex::feasOpt(const IloNumVarArray vars,
                                                 const IloNumArray    varlb,
                                                 const IloNumArray    varub,
                                                 bool async)
{
  return feasOpt(0, 0, 0, vars, varlb, varub, async);
}

inline IloCplex::FeasOptHandle IloCplex::feasOpt(const IloIntVarArray vars,
                                                 const IloNumArray    varlb,
                                                 const IloNumArray    varub,
                                                 bool async)
{
  return feasOpt(0, 0, 0, vars, varlb, varub, async);
}

inline IloCplex::FeasOptHandle IloCplex::feasOpt(const IloRangeArray rngs,
                                                 const IloNumArray   rnglb,
                                                 const IloNumArray   rngub,
                                                 bool async)
{
   IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
   IloAssert (rngs.getImpl()  != 0, "accessing constraint array through 0 handle");
   IloAssert (rnglb.getImpl() != 0, "accessing value array through 0 handle");
   IloAssert (rngub.getImpl() != 0, "accessing value array through 0 handle");
   IloAssert (rnglb.getSize() == rngs.getSize(),
              "incompatible array sizes");
   IloAssert (rngub.getSize() == rngs.getSize(),
              "incompatible array sizes");
   return getImpl()->feasOpt(rngs, rnglb, rngub, IloNumVarArray(0), 0, 0, async);
}

inline IloCplex::FeasOptHandle IloCplex::feasOpt(const IloConstraintArray rngs,
                                                 const IloNumArray        relax,
                                                 bool async)
{
   IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
   IloAssert (rngs.getImpl()  != 0, "accessing constraint array through 0 handle");
   IloAssert (relax.getImpl() != 0, "accessing value array through 0 handle");
   IloAssert (relax.getSize() == rngs.getSize(),
              "incompatible array sizes");
   return getImpl()->feasOpt(rngs, relax, async);
}

inline IloCplex::RefineConflictHandle
IloCplex::refineConflict(IloConstraintArray cons, IloNumArray prios, bool async) {
  IloAssert (getImpl() != 0,     "accessing IloCplex through 0 handle");
  IloAssert (cons.getImpl() != 0, "array not initialized");
  IloAssert (prios.getImpl() != 0, "array not initialized");
  IloAssert (cons.getSize() == prios.getSize(), "array sizes don't match");
  return getImpl()->refineConflict(cons, prios, async);
}

inline IloCplex::RefineMIPStartConflictHandle
IloCplex::refineMIPStartConflict(IloInt mst, IloConstraintArray cons, IloNumArray prios, bool async) {
  IloAssert (getImpl() != 0,     "accessing IloCplex through 0 handle");
  IloAssert (cons.getImpl() != 0, "array not initialized");
  IloAssert (prios.getImpl() != 0, "array not initialized");
  IloAssert (cons.getSize() == prios.getSize(), "array sizes don't match");
  return getImpl()->refineMIPStartConflict(mst, cons, prios, async);
}

inline IloCplex::TuneParamHandle IloCplex::tuneParam(bool async)
{
   IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
   IloCplex::ParameterSet set(0);
   return getImpl()->tuneParam(set, async);
}

inline IloCplex::TuneParamHandle
IloCplex::tuneParam(IloCplex::ParameterSet fixedset, bool async)
{
   IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
   IloAssert(fixedset.getImpl() != 0, "accessing ParameterSet through 0 handle");
   return getImpl()->tuneParam(fixedset, async);
}

inline IloCplex::RemoteInfoHandler *IloCplex::setRemoteInfoHandler(IloCplex::RemoteInfoHandler *handler)
{
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  return getImpl()->setRemoteInfoHandler(handler);
}
inline IloCplex::RemoteInfoHandler *IloCplex::getRemoteInfoHandler() const
{
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  return getImpl()->getRemoteInfoHandler();
}
inline IloCplex::RemoteInfoHandler *IloCplex::removeRemoteInfoHandler()
{
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  return getImpl()->removeRemoteInfoHandler();
}

inline int IloCplex::userfunction (int id, CPXLONG inlen, void const *in,
                                   CPXLONG outcap, CPXLONG *outlen_p, void *out)
{
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  return getImpl()->userfunction (id, inlen, in, outcap, outlen_p, out);
}

inline void IloCplex::transportctrl (int ctrl, CPXINT &data) const
{
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  return getImpl()->transportctrl (ctrl, data);
}

inline void IloCplex::transportctrl (int ctrl, CPXLONG &data) const
{
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  return getImpl()->transportctrl (ctrl, data);
}

inline void IloCplex::transportctrl (int ctrl, double &data) const
{
  IloAssert (getImpl() != 0, "accessing IloCplex through 0 handle");
  return getImpl()->transportctrl (ctrl, data);
}

#endif // !ILOG_CPLEX_NO_REMOTE_API


ILOSTD(ostream)& operator<<(ILOSTD(ostream)& out, IloCplex::Algorithm alg);
ILOSTD(ostream)& operator<<(ILOSTD(ostream)& out, IloCplex::BasisStatus st);
ILOSTD(ostream)& operator<<(ILOSTD(ostream)& out, IloCplex::BranchDirection dir);
ILOSTD(ostream)& operator<<(ILOSTD(ostream)& out, IloCplex::CplexStatus st);
ILOSTD(ostream)& operator<<(ILOSTD(ostream)& out, IloCplex::MIPCallbackI::NodeId nid);

// --------------------------------------------------------------------------
//
// callback macros
//

#define ILOCOMMONCALLBACKSTUFF(name) \
IloCplex::CallbackI* duplicateCallback() const {\
   return (new (getEnv()) name##I(*this));\
}

#define ILOPRESOLVECALLBACK0(name) \
class name##I : public IloCplex::PresolveCallbackI {\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env) : IloCplex::PresolveCallbackI(env) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env) {\
  return (IloCplex::Callback(new (env) name##I(env)));\
}\
void name##I::main()

#define ILOPRESOLVECALLBACK1(name, type1, x1) \
class name##I : public IloCplex::PresolveCallbackI {\
  type1 x1;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1) : IloCplex::PresolveCallbackI(env), x1(xx1) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1) {\
  return (IloCplex::Callback(new (env) name##I(env, x1)));\
}\
void name##I::main()

#define ILOPRESOLVECALLBACK2(name, type1, x1, type2, x2) \
class name##I : public IloCplex::PresolveCallbackI {\
  type1 x1;\
  type2 x2;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2) : IloCplex::PresolveCallbackI(env), x1(xx1), x2(xx2) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2)));\
}\
void name##I::main()

#define ILOPRESOLVECALLBACK3(name, type1, x1, type2, x2, type3, x3) \
class name##I : public IloCplex::PresolveCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3) : \
  IloCplex::PresolveCallbackI(env), x1(xx1), x2(xx2), x3(xx3) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3)));\
}\
void name##I::main()

#define ILOPRESOLVECALLBACK4(name, type1, x1, type2, x2, type3, x3, type4, x4) \
class name##I : public IloCplex::PresolveCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
  type4 x4;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3, type4 xx4) \
    : IloCplex::PresolveCallbackI(env), x1(xx1), x2(xx2), x3(xx3), x4(xx4) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3, type4 x4) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3, x4)));\
}\
void name##I::main()

#define ILOPRESOLVECALLBACK5(name, type1, x1, type2, x2, type3, x3, type4, x4, type5, x5) \
class name##I : public IloCplex::PresolveCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
  type4 x4;\
  type5 x5;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3, type4 xx4, type5 xx5) \
    : IloCplex::PresolveCallbackI(env), x1(xx1), x2(xx2), x3(xx3), x4(xx4), x5(xx5) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3, type4 x4, type5 x5) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3, x4, x5)));\
}\
void name##I::main()

#define ILOPRESOLVECALLBACK6(name, type1, x1, type2, x2, type3, x3, type4, x4, \
                        type5, x5, type6, x6) \
class name##I : public IloCplex::PresolveCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
  type4 x4;\
  type5 x5;\
  type6 x6;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3, type4 xx4, type5 xx5, type6 xx6) \
    : IloCplex::PresolveCallbackI(env), x1(xx1), x2(xx2), x3(xx3), x4(xx4), x5(xx5), x6(xx6) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3, type4 x4, \
                        type5 x5, type6 x6) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3, x4, x5, x6)));\
}\
void name##I::main()

#define ILOPRESOLVECALLBACK7(name, type1, x1, type2, x2, type3, x3, type4, x4, \
                        type5, x5, type6, x6, type7, x7) \
class name##I : public IloCplex::PresolveCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
  type4 x4;\
  type5 x5;\
  type6 x6;\
  type7 x7;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3, type4 xx4, type5 xx5, type6 xx6, type7 xx7) \
    : IloCplex::PresolveCallbackI(env), x1(xx1), x2(xx2), x3(xx3), x4(xx4), x5(xx5), x6(xx6), x7(xx7) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3, type4 x4, \
                        type5 x5, type6 x6, type7 x7) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3, x4, x5, x6, x7)));\
}\
void name##I::main()


#define ILOCONTINUOUSCALLBACK0(name) \
class name##I : public IloCplex::ContinuousCallbackI {\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env) : IloCplex::ContinuousCallbackI(env) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env) {\
  return (IloCplex::Callback(new (env) name##I(env)));\
}\
void name##I::main()

#define ILOCONTINUOUSCALLBACK1(name, type1, x1) \
class name##I : public IloCplex::ContinuousCallbackI {\
  type1 x1;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1) : IloCplex::ContinuousCallbackI(env), x1(xx1) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1) {\
  return (IloCplex::Callback(new (env) name##I(env, x1)));\
}\
void name##I::main()

#define ILOCONTINUOUSCALLBACK2(name, type1, x1, type2, x2) \
class name##I : public IloCplex::ContinuousCallbackI {\
  type1 x1;\
  type2 x2;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2) : \
  IloCplex::ContinuousCallbackI(env), x1(xx1), x2(xx2) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2)));\
}\
void name##I::main()

#define ILOCONTINUOUSCALLBACK3(name, type1, x1, type2, x2, type3, x3) \
class name##I : public IloCplex::ContinuousCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3) : \
  IloCplex::ContinuousCallbackI(env), x1(xx1), x2(xx2), x3(xx3) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3)));\
}\
void name##I::main()

#define ILOCONTINUOUSCALLBACK4(name, type1, x1, type2, x2, type3, x3, type4, x4) \
class name##I : public IloCplex::ContinuousCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
  type4 x4;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3, type4 xx4) \
    : IloCplex::ContinuousCallbackI(env), x1(xx1), x2(xx2), x3(xx3), x4(xx4) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3, type4 x4) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3, x4)));\
}\
void name##I::main()

#define ILOCONTINUOUSCALLBACK5(name, type1, x1, type2, x2, type3, x3, type4, x4, type5, x5) \
class name##I : public IloCplex::ContinuousCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
  type4 x4;\
  type5 x5;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3, type4 xx4, type5 xx5) \
    : IloCplex::ContinuousCallbackI(env), x1(xx1), x2(xx2), x3(xx3), x4(xx4), x5(xx5) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3, type4 x4, type5 x5) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3, x4, x5)));\
}\
void name##I::main()

#define ILOCONTINUOUSCALLBACK6(name, type1, x1, type2, x2, type3, x3, type4, x4, \
                        type5, x5, type6, x6) \
class name##I : public IloCplex::ContinuousCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
  type4 x4;\
  type5 x5;\
  type6 x6;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3, type4 xx4, type5 xx5, type6 xx6) \
    : IloCplex::ContinuousCallbackI(env), x1(xx1), x2(xx2), x3(xx3), x4(xx4), x5(xx5), x6(xx6) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3, type4 x4, \
                        type5 x5, type6 x6) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3, x4, x5, x6)));\
}\
void name##I::main()

#define ILOCONTINUOUSCALLBACK7(name, type1, x1, type2, x2, type3, x3, type4, x4, \
                        type5, x5, type6, x6, type7, x7) \
class name##I : public IloCplex::ContinuousCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
  type4 x4;\
  type5 x5;\
  type6 x6;\
  type7 x7;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3, type4 xx4, type5 xx5, type6 xx6, type7 xx7) \
    : IloCplex::ContinuousCallbackI(env), x1(xx1), x2(xx2), x3(xx3), x4(xx4), x5(xx5), x6(xx6), x7(xx7) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3, type4 x4, \
                        type5 x5, type6 x6, type7 x7) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3, x4, x5, x6, x7)));\
}\
void name##I::main()


#define ILOSIMPLEXCALLBACK0(name) \
class name##I : public IloCplex::SimplexCallbackI {\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env) : IloCplex::SimplexCallbackI(env) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env) {\
  return (IloCplex::Callback(new (env) name##I(env)));\
}\
void name##I::main()

#define ILOSIMPLEXCALLBACK1(name, type1, x1) \
class name##I : public IloCplex::SimplexCallbackI {\
  type1 x1;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1) : IloCplex::SimplexCallbackI(env), x1(xx1) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1) {\
  return (IloCplex::Callback(new (env) name##I(env, x1)));\
}\
void name##I::main()

#define ILOSIMPLEXCALLBACK2(name, type1, x1, type2, x2) \
class name##I : public IloCplex::SimplexCallbackI {\
  type1 x1;\
  type2 x2;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2) : \
  IloCplex::SimplexCallbackI(env), x1(xx1), x2(xx2) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2)));\
}\
void name##I::main()

#define ILOSIMPLEXCALLBACK3(name, type1, x1, type2, x2, type3, x3) \
class name##I : public IloCplex::SimplexCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3) : \
  IloCplex::SimplexCallbackI(env), x1(xx1), x2(xx2), x3(xx3) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3)));\
}\
void name##I::main()

#define ILOSIMPLEXCALLBACK4(name, type1, x1, type2, x2, type3, x3, type4, x4) \
class name##I : public IloCplex::SimplexCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
  type4 x4;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3, type4 xx4) \
    : IloCplex::SimplexCallbackI(env), x1(xx1), x2(xx2), x3(xx3), x4(xx4) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3, type4 x4) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3, x4)));\
}\
void name##I::main()

#define ILOSIMPLEXCALLBACK5(name, type1, x1, type2, x2, type3, x3, type4, x4, type5, x5) \
class name##I : public IloCplex::SimplexCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
  type4 x4;\
  type5 x5;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3, type4 xx4, type5 xx5) \
    : IloCplex::SimplexCallbackI(env), x1(xx1), x2(xx2), x3(xx3), x4(xx4), x5(xx5) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3, type4 x4, type5 x5) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3, x4, x5)));\
}\
void name##I::main()

#define ILOSIMPLEXCALLBACK6(name, type1, x1, type2, x2, type3, x3, type4, x4, \
                        type5, x5, type6, x6) \
class name##I : public IloCplex::SimplexCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
  type4 x4;\
  type5 x5;\
  type6 x6;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3, type4 xx4, type5 xx5, type6 xx6) \
    : IloCplex::SimplexCallbackI(env), x1(xx1), x2(xx2), x3(xx3), x4(xx4), x5(xx5), x6(xx6) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3, type4 x4, \
                        type5 x5, type6 x6) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3, x4, x5, x6)));\
}\
void name##I::main()

#define ILOSIMPLEXCALLBACK7(name, type1, x1, type2, x2, type3, x3, type4, x4, \
                        type5, x5, type6, x6, type7, x7) \
class name##I : public IloCplex::SimplexCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
  type4 x4;\
  type5 x5;\
  type6 x6;\
  type7 x7;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3, type4 xx4, type5 xx5, type6 xx6, type7 xx7) \
    : IloCplex::SimplexCallbackI(env), x1(xx1), x2(xx2), x3(xx3), x4(xx4), x5(xx5), x6(xx6), x7(xx7) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3, type4 x4, \
                        type5 x5, type6 x6, type7 x7) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3, x4, x5, x6, x7)));\
}\
void name##I::main()



#define ILOLPCALLBACK0(name) \
        ILOCONTINUOUSCALLBACK0(name)
#define ILOLPCALLBACK1(name, type1, x1) \
        ILOCONTINUOUSCALLBACK1(name, type1, x1)
#define ILOLPCALLBACK2(name, type1, x1, type2, x2) \
        ILOCONTINUOUSCALLBACK2(name, type1, x1, type2, x2)
#define ILOLPCALLBACK3(name, type1, x1, type2, x2, type3, x3) \
        ILOCONTINUOUSCALLBACK3(name, type1, x1, type2, x2, type3, x3)
#define ILOLPCALLBACK4(name, type1, x1, type2, x2, type3, x3, type4, x4) \
        ILOCONTINUOUSCALLBACK4(name, type1, x1, type2, x2, type3, x3, type4, x4)
#define ILOLPCALLBACK5(name, type1, x1, type2, x2, type3, x3, type4, x4, \
                       type5, x5) \
        ILOCONTINUOUSCALLBACK5(name, type1, x1, type2, x2, type3, x3, type4, \
                               x4, type5, x5)
#define ILOLPCALLBACK6(name, type1, x1, type2, x2, type3, x3, type4, x4, \
                       type5, x5) \
        ILOCONTINUOUSCALLBACK6(name, type1, x1, type2, x2, type3, x3, type4, \
                               x4, type5, x5, type6, x6)
#define ILOLPCALLBACK7(name, type1, x1, type2, x2, type3, x3, type4, x4, \
                       type5, x5) \
        ILOCONTINUOUSCALLBACK7(name, type1, x1, type2, x2, type3, x3, type4, \
                               x4, type5, x5, type6, x6, type7, x7)

#define ILOPRIMALSIMPLEXCALLBACK0(name) \
        ILOSIMPLEXCALLBACK0(name)
#define ILOPRIMALSIMPLEXCALLBACK1(name, type1, x1) \
        ILOSIMPLEXCALLBACK1(name, type1, x1)
#define ILOPRIMALSIMPLEXCALLBACK2(name, type1, x1, type2, x2) \
        ILOSIMPLEXCALLBACK2(name, type1, x1, type2, x2)
#define ILOPRIMALSIMPLEXCALLBACK3(name, type1, x1, type2, x2, type3, x3) \
        ILOSIMPLEXCALLBACK3(name, type1, x1, type2, x2, type3, x3)
#define ILOPRIMALSIMPLEXCALLBACK4(name, type1, x1, type2, x2, type3, x3, \
                                  type4, x4) \
        ILOSIMPLEXCALLBACK4(name, type1, x1, type2, x2, type3, x3, type4, x4)
#define ILOPRIMALSIMPLEXCALLBACK5(name, type1, x1, type2, x2, type3, x3, \
                                  type4, x4, type5, x5) \
        ILOSIMPLEXCALLBACK5(name, type1, x1, type2, x2, type3, x3, type4, \
                               x4, type5, x5)
#define ILOPRIMALSIMPLEXCALLBACK6(name, type1, x1, type2, x2, type3, x3, \
                                  type4, x4, type5, x5) \
        ILOSIMPLEXCALLBACK6(name, type1, x1, type2, x2, type3, x3, type4, \
                               x4, type5, x5, type6, x6)
#define ILOPRIMALSIMPLEXCALLBACK7(name, type1, x1, type2, x2, type3, x3, \
                                  type4, x4, type5, x5) \
        ILOSIMPLEXCALLBACK7(name, type1, x1, type2, x2, type3, x3, type4, \
                               x4, type5, x5, type6, x6, type7, x7)

#define ILODUALSIMPLEXCALLBACK0(name) \
        ILOSIMPLEXCALLBACK0(name)
#define ILODUALSIMPLEXCALLBACK1(name, type1, x1) \
        ILOSIMPLEXCALLBACK1(name, type1, x1)
#define ILODUALSIMPLEXCALLBACK2(name, type1, x1, type2, x2) \
        ILOSIMPLEXCALLBACK2(name, type1, x1, type2, x2)
#define ILODUALSIMPLEXCALLBACK3(name, type1, x1, type2, x2, type3, x3) \
        ILOSIMPLEXCALLBACK3(name, type1, x1, type2, x2, type3, x3)
#define ILODUALSIMPLEXCALLBACK4(name, type1, x1, type2, x2, type3, x3, \
                                  type4, x4) \
        ILOSIMPLEXCALLBACK4(name, type1, x1, type2, x2, type3, x3, type4, x4)
#define ILODUALSIMPLEXCALLBACK5(name, type1, x1, type2, x2, type3, x3, \
                                  type4, x4, type5, x5) \
        ILOSIMPLEXCALLBACK5(name, type1, x1, type2, x2, type3, x3, type4, \
                               x4, type5, x5)
#define ILODUALSIMPLEXCALLBACK6(name, type1, x1, type2, x2, type3, x3, \
                                  type4, x4, type5, x5) \
        ILOSIMPLEXCALLBACK6(name, type1, x1, type2, x2, type3, x3, type4, \
                               x4, type5, x5, type6, x6)
#define ILODUALSIMPLEXCALLBACK7(name, type1, x1, type2, x2, type3, x3, \
                                  type4, x4, type5, x5) \
        ILOSIMPLEXCALLBACK7(name, type1, x1, type2, x2, type3, x3, type4, \
                               x4, type5, x5, type6, x6, type7, x7)


#define ILOBARRIERCALLBACK0(name) \
class name##I : public IloCplex::BarrierCallbackI {\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env) : IloCplex::BarrierCallbackI(env) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env) {\
  return (IloCplex::Callback(new (env) name##I(env)));\
}\
void name##I::main()

#define ILOBARRIERCALLBACK1(name, type1, x1) \
class name##I : public IloCplex::BarrierCallbackI {\
  type1 x1;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1) : IloCplex::BarrierCallbackI(env), x1(xx1) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1) {\
  return (IloCplex::Callback(new (env) name##I(env, x1)));\
}\
void name##I::main()

#define ILOBARRIERCALLBACK2(name, type1, x1, type2, x2) \
class name##I : public IloCplex::BarrierCallbackI {\
  type1 x1;\
  type2 x2;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2) : IloCplex::BarrierCallbackI(env), x1(xx1), x2(xx2) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2)));\
}\
void name##I::main()

#define ILOBARRIERCALLBACK3(name, type1, x1, type2, x2, type3, x3) \
class name##I : public IloCplex::BarrierCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3) : \
  IloCplex::BarrierCallbackI(env), x1(xx1), x2(xx2), x3(xx3) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3)));\
}\
void name##I::main()

#define ILOBARRIERCALLBACK4(name, type1, x1, type2, x2, type3, x3, type4, x4) \
class name##I : public IloCplex::BarrierCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
  type4 x4;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3, type4 xx4) \
    : IloCplex::BarrierCallbackI(env), x1(xx1), x2(xx2), x3(xx3), x4(xx4) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3, type4 x4) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3, x4)));\
}\
void name##I::main()

#define ILOBARRIERCALLBACK5(name, type1, x1, type2, x2, type3, x3, type4, x4, type5, x5) \
class name##I : public IloCplex::BarrierCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
  type4 x4;\
  type5 x5;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3, type4 xx4, type5 xx5) \
    : IloCplex::BarrierCallbackI(env), x1(xx1), x2(xx2), x3(xx3), x4(xx4), x5(xx5) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3, type4 x4, type5 x5) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3, x4, x5)));\
}\
void name##I::main()

#define ILOBARRIERCALLBACK6(name, type1, x1, type2, x2, type3, x3, type4, x4, \
                        type5, x5, type6, x6) \
class name##I : public IloCplex::BarrierCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
  type4 x4;\
  type5 x5;\
  type6 x6;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3, type4 xx4, type5 xx5, type6 xx6) \
    : IloCplex::BarrierCallbackI(env), x1(xx1), x2(xx2), x3(xx3), x4(xx4), x5(xx5), x6(xx6) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3, type4 x4, \
                        type5 x5, type6 x6) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3, x4, x5, x6)));\
}\
void name##I::main()

#define ILOBARRIERCALLBACK7(name, type1, x1, type2, x2, type3, x3, type4, x4, \
                        type5, x5, type6, x6, type7, x7) \
class name##I : public IloCplex::BarrierCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
  type4 x4;\
  type5 x5;\
  type6 x6;\
  type7 x7;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3, type4 xx4, type5 xx5, type6 xx6, type7 xx7) \
    : IloCplex::BarrierCallbackI(env), x1(xx1), x2(xx2), x3(xx3), x4(xx4), x5(xx5), x6(xx6), x7(xx7) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3, type4 x4, \
                        type5 x5, type6 x6, type7 x7) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3, x4, x5, x6, x7)));\
}\
void name##I::main()


#define ILONETWORKCALLBACK0(name) \
class name##I : public IloCplex::NetworkCallbackI {\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env) : IloCplex::NetworkCallbackI(env) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env) {\
  return (IloCplex::Callback(new (env) name##I(env)));\
}\
void name##I::main()

#define ILONETWORKCALLBACK1(name, type1, x1) \
class name##I : public IloCplex::NetworkCallbackI {\
  type1 x1;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1) : IloCplex::NetworkCallbackI(env), x1(xx1) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1) {\
  return (IloCplex::Callback(new (env) name##I(env, x1)));\
}\
void name##I::main()

#define ILONETWORKCALLBACK2(name, type1, x1, type2, x2) \
class name##I : public IloCplex::NetworkCallbackI {\
  type1 x1;\
  type2 x2;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2) : IloCplex::NetworkCallbackI(env), x1(xx1), x2(xx2) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2)));\
}\
void name##I::main()

#define ILONETWORKCALLBACK3(name, type1, x1, type2, x2, type3, x3) \
class name##I : public IloCplex::NetworkCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3) : \
  IloCplex::NetworkCallbackI(env), x1(xx1), x2(xx2), x3(xx3) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3)));\
}\
void name##I::main()

#define ILONETWORKCALLBACK4(name, type1, x1, type2, x2, type3, x3, type4, x4) \
class name##I : public IloCplex::NetworkCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
  type4 x4;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3, type4 xx4) \
    : IloCplex::NetworkCallbackI(env), x1(xx1), x2(xx2), x3(xx3), x4(xx4) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3, type4 x4) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3, x4)));\
}\
void name##I::main()

#define ILONETWORKCALLBACK5(name, type1, x1, type2, x2, type3, x3, type4, x4, type5, x5) \
class name##I : public IloCplex::NetworkCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
  type4 x4;\
  type5 x5;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3, type4 xx4, type5 xx5) \
    : IloCplex::NetworkCallbackI(env), x1(xx1), x2(xx2), x3(xx3), x4(xx4), x5(xx5) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3, type4 x4, type5 x5) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3, x4, x5)));\
}\
void name##I::main()

#define ILONETWORKCALLBACK6(name, type1, x1, type2, x2, type3, x3, type4, x4, \
                        type5, x5, type6, x6) \
class name##I : public IloCplex::NetworkCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
  type4 x4;\
  type5 x5;\
  type6 x6;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3, type4 xx4, type5 xx5, type6 xx6) \
    : IloCplex::NetworkCallbackI(env), x1(xx1), x2(xx2), x3(xx3), x4(xx4), x5(xx5), x6(xx6) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3, type4 x4, \
                        type5 x5, type6 x6) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3, x4, x5, x6)));\
}\
void name##I::main()

#define ILONETWORKCALLBACK7(name, type1, x1, type2, x2, type3, x3, type4, x4, \
                        type5, x5, type6, x6, type7, x7) \
class name##I : public IloCplex::NetworkCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
  type4 x4;\
  type5 x5;\
  type6 x6;\
  type7 x7;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3, type4 xx4, type5 xx5, type6 xx6, type7 xx7) \
    : IloCplex::NetworkCallbackI(env), x1(xx1), x2(xx2), x3(xx3), x4(xx4), x5(xx5), x6(xx6), x7(xx7) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3, type4 x4, \
                        type5 x5, type6 x6, type7 x7) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3, x4, x5, x6, x7)));\
}\
void name##I::main()


#define ILOMIPCALLBACK0(name) \
class name##I : public IloCplex::MIPCallbackI {\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env) : IloCplex::MIPCallbackI(env) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env) {\
  return (IloCplex::Callback(new (env) name##I(env)));\
}\
void name##I::main()

#define ILOMIPCALLBACK1(name, type1, x1) \
class name##I : public IloCplex::MIPCallbackI {\
  type1 x1;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1) : IloCplex::MIPCallbackI(env), x1(xx1) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1) {\
  return (IloCplex::Callback(new (env) name##I(env, x1)));\
}\
void name##I::main()

#define ILOMIPCALLBACK2(name, type1, x1, type2, x2) \
class name##I : public IloCplex::MIPCallbackI {\
  type1 x1;\
  type2 x2;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2) : IloCplex::MIPCallbackI(env), x1(xx1), x2(xx2) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2)));\
}\
void name##I::main()

#define ILOMIPCALLBACK3(name, type1, x1, type2, x2, type3, x3) \
class name##I : public IloCplex::MIPCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3) : \
  IloCplex::MIPCallbackI(env), x1(xx1), x2(xx2), x3(xx3) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3)));\
}\
void name##I::main()

#define ILOMIPCALLBACK4(name, type1, x1, type2, x2, type3, x3, type4, x4) \
class name##I : public IloCplex::MIPCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
  type4 x4;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3, type4 xx4) \
    : IloCplex::MIPCallbackI(env), x1(xx1), x2(xx2), x3(xx3), x4(xx4) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3, type4 x4) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3, x4)));\
}\
void name##I::main()

#define ILOMIPCALLBACK5(name, type1, x1, type2, x2, type3, x3, type4, x4, type5, x5) \
class name##I : public IloCplex::MIPCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
  type4 x4;\
  type5 x5;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3, type4 xx4, type5 xx5) \
    : IloCplex::MIPCallbackI(env), x1(xx1), x2(xx2), x3(xx3), x4(xx4), x5(xx5) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3, type4 x4, type5 x5) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3, x4, x5)));\
}\
void name##I::main()

#define ILOMIPCALLBACK6(name, type1, x1, type2, x2, type3, x3, type4, x4, \
                        type5, x5, type6, x6) \
class name##I : public IloCplex::MIPCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
  type4 x4;\
  type5 x5;\
  type6 x6;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3, type4 xx4, type5 xx5, type6 xx6) \
    : IloCplex::MIPCallbackI(env), x1(xx1), x2(xx2), x3(xx3), x4(xx4), x5(xx5), x6(xx6) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3, type4 x4, \
                        type5 x5, type6 x6) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3, x4, x5, x6)));\
}\
void name##I::main()

#define ILOMIPCALLBACK7(name, type1, x1, type2, x2, type3, x3, type4, x4, \
                        type5, x5, type6, x6, type7, x7) \
class name##I : public IloCplex::MIPCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
  type4 x4;\
  type5 x5;\
  type6 x6;\
  type7 x7;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3, type4 xx4, type5 xx5, type6 xx6, type7 xx7) \
    : IloCplex::MIPCallbackI(env), x1(xx1), x2(xx2), x3(xx3), x4(xx4), x5(xx5), x6(xx6), x7(xx7) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3, type4 x4, \
                        type5 x5, type6 x6, type7 x7) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3, x4, x5, x6, x7)));\
}\
void name##I::main()


#define ILOMIPINFOCALLBACK0(name) \
class name##I : public IloCplex::MIPInfoCallbackI {\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env) : IloCplex::MIPInfoCallbackI(env) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env) {\
  return (IloCplex::Callback(new (env) name##I(env)));\
}\
void name##I::main()

#define ILOMIPINFOCALLBACK1(name, type1, x1) \
class name##I : public IloCplex::MIPInfoCallbackI {\
  type1 x1;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1) : IloCplex::MIPInfoCallbackI(env), x1(xx1) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1) {\
  return (IloCplex::Callback(new (env) name##I(env, x1)));\
}\
void name##I::main()

#define ILOMIPINFOCALLBACK2(name, type1, x1, type2, x2) \
class name##I : public IloCplex::MIPInfoCallbackI {\
  type1 x1;\
  type2 x2;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2) : IloCplex::MIPInfoCallbackI(env), x1(xx1), x2(xx2) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2)));\
}\
void name##I::main()

#define ILOMIPINFOCALLBACK3(name, type1, x1, type2, x2, type3, x3) \
class name##I : public IloCplex::MIPInfoCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3) : \
  IloCplex::MIPInfoCallbackI(env), x1(xx1), x2(xx2), x3(xx3) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3)));\
}\
void name##I::main()

#define ILOMIPINFOCALLBACK4(name, type1, x1, type2, x2, type3, x3, type4, x4) \
class name##I : public IloCplex::MIPInfoCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
  type4 x4;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3, type4 xx4) \
    : IloCplex::MIPInfoCallbackI(env), x1(xx1), x2(xx2), x3(xx3), x4(xx4) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3, type4 x4) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3, x4)));\
}\
void name##I::main()

#define ILOMIPINFOCALLBACK5(name, type1, x1, type2, x2, type3, x3, type4, x4, type5, x5) \
class name##I : public IloCplex::MIPInfoCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
  type4 x4;\
  type5 x5;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3, type4 xx4, type5 xx5) \
    : IloCplex::MIPInfoCallbackI(env), x1(xx1), x2(xx2), x3(xx3), x4(xx4), x5(xx5) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3, type4 x4, type5 x5) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3, x4, x5)));\
}\
void name##I::main()

#define ILOMIPINFOCALLBACK6(name, type1, x1, type2, x2, type3, x3, type4, x4, \
                        type5, x5, type6, x6) \
class name##I : public IloCplex::MIPInfoCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
  type4 x4;\
  type5 x5;\
  type6 x6;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3, type4 xx4, type5 xx5, type6 xx6) \
    : IloCplex::MIPInfoCallbackI(env), x1(xx1), x2(xx2), x3(xx3), x4(xx4), x5(xx5), x6(xx6) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3, type4 x4, \
                        type5 x5, type6 x6) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3, x4, x5, x6)));\
}\
void name##I::main()

#define ILOMIPINFOCALLBACK7(name, type1, x1, type2, x2, type3, x3, type4, x4, \
                        type5, x5, type6, x6, type7, x7) \
class name##I : public IloCplex::MIPInfoCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
  type4 x4;\
  type5 x5;\
  type6 x6;\
  type7 x7;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3, type4 xx4, type5 xx5, type6 xx6, type7 xx7) \
    : IloCplex::MIPInfoCallbackI(env), x1(xx1), x2(xx2), x3(xx3), x4(xx4), x5(xx5), x6(xx6), x7(xx7) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3, type4 x4, \
                        type5 x5, type6 x6, type7 x7) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3, x4, x5, x6, x7)));\
}\
void name##I::main()


#define ILOPROBINGINFOCALLBACK0(name) \
class name##I : public IloCplex::ProbingInfoCallbackI {\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env) : IloCplex::ProbingInfoCallbackI(env) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env) {\
  return (IloCplex::Callback(new (env) name##I(env)));\
}\
void name##I::main()

#define ILOPROBINGINFOCALLBACK1(name, type1, x1) \
class name##I : public IloCplex::ProbingInfoCallbackI {\
  type1 x1;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1) : IloCplex::ProbingInfoCallbackI(env), x1(xx1) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1) {\
  return (IloCplex::Callback(new (env) name##I(env, x1)));\
}\
void name##I::main()

#define ILOPROBINGINFOCALLBACK2(name, type1, x1, type2, x2) \
class name##I : public IloCplex::ProbingInfoCallbackI {\
  type1 x1;\
  type2 x2;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2) : IloCplex::ProbingInfoCallbackI(env), x1(xx1), x2(xx2) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2)));\
}\
void name##I::main()

#define ILOPROBINGINFOCALLBACK3(name, type1, x1, type2, x2, type3, x3) \
class name##I : public IloCplex::ProbingInfoCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3) : \
  IloCplex::ProbingInfoCallbackI(env), x1(xx1), x2(xx2), x3(xx3) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3)));\
}\
void name##I::main()

#define ILOPROBINGINFOCALLBACK4(name, type1, x1, type2, x2, type3, x3, type4, x4) \
class name##I : public IloCplex::ProbingInfoCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
  type4 x4;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3, type4 xx4) \
    : IloCplex::ProbingInfoCallbackI(env), x1(xx1), x2(xx2), x3(xx3), x4(xx4) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3, type4 x4) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3, x4)));\
}\
void name##I::main()

#define ILOPROBINGINFOCALLBACK5(name, type1, x1, type2, x2, type3, x3, type4, x4, type5, x5) \
class name##I : public IloCplex::ProbingInfoCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
  type4 x4;\
  type5 x5;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3, type4 xx4, type5 xx5) \
    : IloCplex::ProbingInfoCallbackI(env), x1(xx1), x2(xx2), x3(xx3), x4(xx4), x5(xx5) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3, type4 x4, type5 x5) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3, x4, x5)));\
}\
void name##I::main()

#define ILOPROBINGINFOCALLBACK6(name, type1, x1, type2, x2, type3, x3, type4, x4, \
                        type5, x5, type6, x6) \
class name##I : public IloCplex::ProbingInfoCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
  type4 x4;\
  type5 x5;\
  type6 x6;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3, type4 xx4, type5 xx5, type6 xx6) \
    : IloCplex::ProbingInfoCallbackI(env), x1(xx1), x2(xx2), x3(xx3), x4(xx4), x5(xx5), x6(xx6) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3, type4 x4, \
                        type5 x5, type6 x6) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3, x4, x5, x6)));\
}\
void name##I::main()

#define ILOPROBINGINFOCALLBACK7(name, type1, x1, type2, x2, type3, x3, type4, x4, \
                        type5, x5, type6, x6, type7, x7) \
class name##I : public IloCplex::ProbingInfoCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
  type4 x4;\
  type5 x5;\
  type6 x6;\
  type7 x7;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3, type4 xx4, type5 xx5, type6 xx6, type7 xx7) \
    : IloCplex::ProbingInfoCallbackI(env), x1(xx1), x2(xx2), x3(xx3), x4(xx4), x5(xx5), x6(xx6), x7(xx7) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3, type4 x4, \
                        type5 x5, type6 x6, type7 x7) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3, x4, x5, x6, x7)));\
}\
void name##I::main()


#define ILOPROBINGCALLBACK0(name) \
class name##I : public IloCplex::ProbingCallbackI {\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env) : IloCplex::ProbingCallbackI(env) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env) {\
  return (IloCplex::Callback(new (env) name##I(env)));\
}\
void name##I::main()

#define ILOPROBINGCALLBACK1(name, type1, x1) \
class name##I : public IloCplex::ProbingCallbackI {\
  type1 x1;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1) : IloCplex::ProbingCallbackI(env), x1(xx1) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1) {\
  return (IloCplex::Callback(new (env) name##I(env, x1)));\
}\
void name##I::main()

#define ILOPROBINGCALLBACK2(name, type1, x1, type2, x2) \
class name##I : public IloCplex::ProbingCallbackI {\
  type1 x1;\
  type2 x2;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2) : IloCplex::ProbingCallbackI(env), x1(xx1), x2(xx2) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2)));\
}\
void name##I::main()

#define ILOPROBINGCALLBACK3(name, type1, x1, type2, x2, type3, x3) \
class name##I : public IloCplex::ProbingCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3) : \
  IloCplex::ProbingCallbackI(env), x1(xx1), x2(xx2), x3(xx3) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3)));\
}\
void name##I::main()

#define ILOPROBINGCALLBACK4(name, type1, x1, type2, x2, type3, x3, type4, x4) \
class name##I : public IloCplex::ProbingCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
  type4 x4;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3, type4 xx4) \
    : IloCplex::ProbingCallbackI(env), x1(xx1), x2(xx2), x3(xx3), x4(xx4) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3, type4 x4) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3, x4)));\
}\
void name##I::main()

#define ILOPROBINGCALLBACK5(name, type1, x1, type2, x2, type3, x3, type4, x4, type5, x5) \
class name##I : public IloCplex::ProbingCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
  type4 x4;\
  type5 x5;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3, type4 xx4, type5 xx5) \
    : IloCplex::ProbingCallbackI(env), x1(xx1), x2(xx2), x3(xx3), x4(xx4), x5(xx5) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3, type4 x4, type5 x5) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3, x4, x5)));\
}\
void name##I::main()

#define ILOPROBINGCALLBACK6(name, type1, x1, type2, x2, type3, x3, type4, x4, \
                        type5, x5, type6, x6) \
class name##I : public IloCplex::ProbingCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
  type4 x4;\
  type5 x5;\
  type6 x6;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3, type4 xx4, type5 xx5, type6 xx6) \
    : IloCplex::ProbingCallbackI(env), x1(xx1), x2(xx2), x3(xx3), x4(xx4), x5(xx5), x6(xx6) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3, type4 x4, \
                        type5 x5, type6 x6) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3, x4, x5, x6)));\
}\
void name##I::main()

#define ILOPROBINGCALLBACK7(name, type1, x1, type2, x2, type3, x3, type4, x4, \
                        type5, x5, type6, x6, type7, x7) \
class name##I : public IloCplex::ProbingCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
  type4 x4;\
  type5 x5;\
  type6 x6;\
  type7 x7;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3, type4 xx4, type5 xx5, type6 xx6, type7 xx7) \
    : IloCplex::ProbingCallbackI(env), x1(xx1), x2(xx2), x3(xx3), x4(xx4), x5(xx5), x6(xx6), x7(xx7) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3, type4 x4, \
                        type5 x5, type6 x6, type7 x7) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3, x4, x5, x6, x7)));\
}\
void name##I::main()


#define ILOFRACTIONALCUTINFOCALLBACK0(name) \
class name##I : public IloCplex::FractionalCutInfoCallbackI {\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env) : IloCplex::FractionalCutInfoCallbackI(env) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env) {\
  return (IloCplex::Callback(new (env) name##I(env)));\
}\
void name##I::main()

#define ILOFRACTIONALCUTINFOCALLBACK1(name, type1, x1) \
class name##I : public IloCplex::FractionalCutInfoCallbackI {\
  type1 x1;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1) : IloCplex::FractionalCutInfoCallbackI(env), x1(xx1) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1) {\
  return (IloCplex::Callback(new (env) name##I(env, x1)));\
}\
void name##I::main()

#define ILOFRACTIONALCUTINFOCALLBACK2(name, type1, x1, type2, x2) \
class name##I : public IloCplex::FractionalCutInfoCallbackI {\
  type1 x1;\
  type2 x2;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2) : \
  IloCplex::FractionalCutInfoCallbackI(env), x1(xx1), x2(xx2) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2)));\
}\
void name##I::main()

#define ILOFRACTIONALCUTINFOCALLBACK3(name, type1, x1, type2, x2, type3, x3) \
class name##I : public IloCplex::FractionalCutInfoCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3) : \
  IloCplex::FractionalCutInfoCallbackI(env), x1(xx1), x2(xx2), x3(xx3) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3)));\
}\
void name##I::main()

#define ILOFRACTIONALCUTINFOCALLBACK4(name, type1, x1, type2, x2, type3, x3, type4, x4) \
class name##I : public IloCplex::FractionalCutInfoCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
  type4 x4;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3, type4 xx4) \
    : IloCplex::FractionalCutInfoCallbackI(env), x1(xx1), x2(xx2), x3(xx3), x4(xx4) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3, type4 x4) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3, x4)));\
}\
void name##I::main()

#define ILOFRACTIONALCUTINFOCALLBACK5(name, type1, x1, type2, x2, type3, x3, type4, x4, type5, x5) \
class name##I : public IloCplex::FractionalCutInfoCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
  type4 x4;\
  type5 x5;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3, type4 xx4, type5 xx5) \
    : IloCplex::FractionalCutInfoCallbackI(env), x1(xx1), x2(xx2), x3(xx3), x4(xx4), x5(xx5) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3, type4 x4, type5 x5) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3, x4, x5)));\
}\
void name##I::main()

#define ILOFRACTIONALCUTINFOCALLBACK6(name, type1, x1, type2, x2, type3, x3, type4, x4, \
                        type5, x5, type6, x6) \
class name##I : public IloCplex::FractionalCutInfoCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
  type4 x4;\
  type5 x5;\
  type6 x6;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3, type4 xx4, type5 xx5, type6 xx6) \
    : IloCplex::FractionalCutInfoCallbackI(env), x1(xx1), x2(xx2), x3(xx3), x4(xx4), x5(xx5), x6(xx6) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3, type4 x4, \
                        type5 x5, type6 x6) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3, x4, x5, x6)));\
}\
void name##I::main()

#define ILOFRACTIONALCUTINFOCALLBACK7(name, type1, x1, type2, x2, type3, x3, type4, x4, \
                        type5, x5, type6, x6, type7, x7) \
class name##I : public IloCplex::FractionalCutInfoCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
  type4 x4;\
  type5 x5;\
  type6 x6;\
  type7 x7;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3, type4 xx4, type5 xx5, type6 xx6, type7 xx7) \
    : IloCplex::FractionalCutInfoCallbackI(env), x1(xx1), x2(xx2), x3(xx3), x4(xx4), x5(xx5), x6(xx6), x7(xx7) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3, type4 x4, \
                        type5 x5, type6 x6, type7 x7) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3, x4, x5, x6, x7)));\
}\
void name##I::main()


#define ILOFRACTIONALCUTCALLBACK0(name) \
class name##I : public IloCplex::FractionalCutCallbackI {\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env) : IloCplex::FractionalCutCallbackI(env) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env) {\
  return (IloCplex::Callback(new (env) name##I(env)));\
}\
void name##I::main()

#define ILOFRACTIONALCUTCALLBACK1(name, type1, x1) \
class name##I : public IloCplex::FractionalCutCallbackI {\
  type1 x1;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1) : IloCplex::FractionalCutCallbackI(env), x1(xx1) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1) {\
  return (IloCplex::Callback(new (env) name##I(env, x1)));\
}\
void name##I::main()

#define ILOFRACTIONALCUTCALLBACK2(name, type1, x1, type2, x2) \
class name##I : public IloCplex::FractionalCutCallbackI {\
  type1 x1;\
  type2 x2;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2) : \
  IloCplex::FractionalCutCallbackI(env), x1(xx1), x2(xx2) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2)));\
}\
void name##I::main()

#define ILOFRACTIONALCUTCALLBACK3(name, type1, x1, type2, x2, type3, x3) \
class name##I : public IloCplex::FractionalCutCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3) : \
  IloCplex::FractionalCutCallbackI(env), x1(xx1), x2(xx2), x3(xx3) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3)));\
}\
void name##I::main()

#define ILOFRACTIONALCUTCALLBACK4(name, type1, x1, type2, x2, type3, x3, type4, x4) \
class name##I : public IloCplex::FractionalCutCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
  type4 x4;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3, type4 xx4) \
    : IloCplex::FractionalCutCallbackI(env), x1(xx1), x2(xx2), x3(xx3), x4(xx4) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3, type4 x4) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3, x4)));\
}\
void name##I::main()

#define ILOFRACTIONALCUTCALLBACK5(name, type1, x1, type2, x2, type3, x3, type4, x4, type5, x5) \
class name##I : public IloCplex::FractionalCutCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
  type4 x4;\
  type5 x5;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3, type4 xx4, type5 xx5) \
    : IloCplex::FractionalCutCallbackI(env), x1(xx1), x2(xx2), x3(xx3), x4(xx4), x5(xx5) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3, type4 x4, type5 x5) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3, x4, x5)));\
}\
void name##I::main()

#define ILOFRACTIONALCUTCALLBACK6(name, type1, x1, type2, x2, type3, x3, type4, x4, \
                        type5, x5, type6, x6) \
class name##I : public IloCplex::FractionalCutCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
  type4 x4;\
  type5 x5;\
  type6 x6;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3, type4 xx4, type5 xx5, type6 xx6) \
    : IloCplex::FractionalCutCallbackI(env), x1(xx1), x2(xx2), x3(xx3), x4(xx4), x5(xx5), x6(xx6) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3, type4 x4, \
                        type5 x5, type6 x6) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3, x4, x5, x6)));\
}\
void name##I::main()

#define ILOFRACTIONALCUTCALLBACK7(name, type1, x1, type2, x2, type3, x3, type4, x4, \
                        type5, x5, type6, x6, type7, x7) \
class name##I : public IloCplex::FractionalCutCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
  type4 x4;\
  type5 x5;\
  type6 x6;\
  type7 x7;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3, type4 xx4, type5 xx5, type6 xx6, type7 xx7) \
    : IloCplex::FractionalCutCallbackI(env), x1(xx1), x2(xx2), x3(xx3), x4(xx4), x5(xx5), x6(xx6), x7(xx7) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3, type4 x4, \
                        type5 x5, type6 x6, type7 x7) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3, x4, x5, x6, x7)));\
}\
void name##I::main()


#define ILOFLOWMIRCUTINFOCALLBACK0(name) \
class name##I : public IloCplex::FlowMIRCutInfoCallbackI {\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env) : IloCplex::FlowMIRCutInfoCallbackI(env) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env) {\
  return (IloCplex::Callback(new (env) name##I(env)));\
}\
void name##I::main()

#define ILOFLOWMIRCUTINFOCALLBACK1(name, type1, x1) \
class name##I : public IloCplex::FlowMIRCutInfoCallbackI {\
  type1 x1;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1) : IloCplex::FlowMIRCutInfoCallbackI(env), x1(xx1) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1) {\
  return (IloCplex::Callback(new (env) name##I(env, x1)));\
}\
void name##I::main()

#define ILOFLOWMIRCUTINFOCALLBACK2(name, type1, x1, type2, x2) \
class name##I : public IloCplex::FlowMIRCutInfoCallbackI {\
  type1 x1;\
  type2 x2;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2) : \
  IloCplex::FlowMIRCutInfoCallbackI(env), x1(xx1), x2(xx2) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2)));\
}\
void name##I::main()

#define ILOFLOWMIRCUTINFOCALLBACK3(name, type1, x1, type2, x2, type3, x3) \
class name##I : public IloCplex::FlowMIRCutInfoCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3) : \
  IloCplex::FlowMIRCutInfoCallbackI(env), x1(xx1), x2(xx2), x3(xx3) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3)));\
}\
void name##I::main()

#define ILOFLOWMIRCUTINFOCALLBACK4(name, type1, x1, type2, x2, type3, x3, type4, x4) \
class name##I : public IloCplex::FlowMIRCutInfoCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
  type4 x4;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3, type4 xx4) \
    : IloCplex::FlowMIRCutInfoCallbackI(env), x1(xx1), x2(xx2), x3(xx3), x4(xx4) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3, type4 x4) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3, x4)));\
}\
void name##I::main()

#define ILOFLOWMIRCUTINFOCALLBACK5(name, type1, x1, type2, x2, type3, x3, type4, x4, type5, x5) \
class name##I : public IloCplex::FlowMIRCutInfoCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
  type4 x4;\
  type5 x5;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3, type4 xx4, type5 xx5) \
    : IloCplex::FlowMIRCutInfoCallbackI(env), x1(xx1), x2(xx2), x3(xx3), x4(xx4), x5(xx5) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3, type4 x4, type5 x5) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3, x4, x5)));\
}\
void name##I::main()

#define ILOFLOWMIRCUTINFOCALLBACK6(name, type1, x1, type2, x2, type3, x3, type4, x4, \
                        type5, x5, type6, x6) \
class name##I : public IloCplex::FlowMIRCutInfoCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
  type4 x4;\
  type5 x5;\
  type6 x6;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3, type4 xx4, type5 xx5, type6 xx6) \
    : IloCplex::FlowMIRCutInfoCallbackI(env), x1(xx1), x2(xx2), x3(xx3), x4(xx4), x5(xx5), x6(xx6) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3, type4 x4, \
                        type5 x5, type6 x6) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3, x4, x5, x6)));\
}\
void name##I::main()

#define ILOFLOWMIRCUTINFOCALLBACK7(name, type1, x1, type2, x2, type3, x3, type4, x4, \
                        type5, x5, type6, x6, type7, x7) \
class name##I : public IloCplex::FlowMIRCutInfoCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
  type4 x4;\
  type5 x5;\
  type6 x6;\
  type7 x7;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3, type4 xx4, type5 xx5, type6 xx6, type7 xx7) \
    : IloCplex::FlowMIRCutInfoCallbackI(env), x1(xx1), x2(xx2), x3(xx3), x4(xx4), x5(xx5), x6(xx6), x7(xx7) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3, type4 x4, \
                        type5 x5, type6 x6, type7 x7) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3, x4, x5, x6, x7)));\
}\
void name##I::main()



#define ILOFLOWMIRCUTCALLBACK0(name) \
class name##I : public IloCplex::FlowMIRCutCallbackI {\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env) : IloCplex::FlowMIRCutCallbackI(env) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env) {\
  return (IloCplex::Callback(new (env) name##I(env)));\
}\
void name##I::main()

#define ILOFLOWMIRCUTCALLBACK1(name, type1, x1) \
class name##I : public IloCplex::FlowMIRCutCallbackI {\
  type1 x1;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1) : IloCplex::FlowMIRCutCallbackI(env), x1(xx1) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1) {\
  return (IloCplex::Callback(new (env) name##I(env, x1)));\
}\
void name##I::main()

#define ILOFLOWMIRCUTCALLBACK2(name, type1, x1, type2, x2) \
class name##I : public IloCplex::FlowMIRCutCallbackI {\
  type1 x1;\
  type2 x2;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2) : \
  IloCplex::FlowMIRCutCallbackI(env), x1(xx1), x2(xx2) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2)));\
}\
void name##I::main()

#define ILOFLOWMIRCUTCALLBACK3(name, type1, x1, type2, x2, type3, x3) \
class name##I : public IloCplex::FlowMIRCutCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3) : \
  IloCplex::FlowMIRCutCallbackI(env), x1(xx1), x2(xx2), x3(xx3) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3)));\
}\
void name##I::main()

#define ILOFLOWMIRCUTCALLBACK4(name, type1, x1, type2, x2, type3, x3, type4, x4) \
class name##I : public IloCplex::FlowMIRCutCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
  type4 x4;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3, type4 xx4) \
    : IloCplex::FlowMIRCutCallbackI(env), x1(xx1), x2(xx2), x3(xx3), x4(xx4) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3, type4 x4) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3, x4)));\
}\
void name##I::main()

#define ILOFLOWMIRCUTCALLBACK5(name, type1, x1, type2, x2, type3, x3, type4, x4, type5, x5) \
class name##I : public IloCplex::FlowMIRCutCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
  type4 x4;\
  type5 x5;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3, type4 xx4, type5 xx5) \
    : IloCplex::FlowMIRCutCallbackI(env), x1(xx1), x2(xx2), x3(xx3), x4(xx4), x5(xx5) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3, type4 x4, type5 x5) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3, x4, x5)));\
}\
void name##I::main()

#define ILOFLOWMIRCUTCALLBACK6(name, type1, x1, type2, x2, type3, x3, type4, x4, \
                        type5, x5, type6, x6) \
class name##I : public IloCplex::FlowMIRCutCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
  type4 x4;\
  type5 x5;\
  type6 x6;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3, type4 xx4, type5 xx5, type6 xx6) \
    : IloCplex::FlowMIRCutCallbackI(env), x1(xx1), x2(xx2), x3(xx3), x4(xx4), x5(xx5), x6(xx6) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3, type4 x4, \
                        type5 x5, type6 x6) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3, x4, x5, x6)));\
}\
void name##I::main()

#define ILOFLOWMIRCUTCALLBACK7(name, type1, x1, type2, x2, type3, x3, type4, x4, \
                        type5, x5, type6, x6, type7, x7) \
class name##I : public IloCplex::FlowMIRCutCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
  type4 x4;\
  type5 x5;\
  type6 x6;\
  type7 x7;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3, type4 xx4, type5 xx5, type6 xx6, type7 xx7) \
    : IloCplex::FlowMIRCutCallbackI(env), x1(xx1), x2(xx2), x3(xx3), x4(xx4), x5(xx5), x6(xx6), x7(xx7) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3, type4 x4, \
                        type5 x5, type6 x6, type7 x7) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3, x4, x5, x6, x7)));\
}\
void name##I::main()



#define ILODISJUNCTIVECUTINFOCALLBACK0(name) \
class name##I : public IloCplex::DisjunctiveCutInfoCallbackI {\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env) : IloCplex::DisjunctiveCutInfoCallbackI(env) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env) {\
  return (IloCplex::Callback(new (env) name##I(env)));\
}\
void name##I::main()

#define ILODISJUNCTIVECUTINFOCALLBACK1(name, type1, x1) \
class name##I : public IloCplex::DisjunctiveCutInfoCallbackI {\
  type1 x1;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1) : IloCplex::DisjunctiveCutInfoCallbackI(env), x1(xx1) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1) {\
  return (IloCplex::Callback(new (env) name##I(env, x1)));\
}\
void name##I::main()

#define ILODISJUNCTIVECUTINFOCALLBACK2(name, type1, x1, type2, x2) \
class name##I : public IloCplex::DisjunctiveCutInfoCallbackI {\
  type1 x1;\
  type2 x2;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2) : \
  IloCplex::DisjunctiveCutInfoCallbackI(env), x1(xx1), x2(xx2) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2)));\
}\
void name##I::main()

#define ILODISJUNCTIVECUTINFOCALLBACK3(name, type1, x1, type2, x2, type3, x3) \
class name##I : public IloCplex::DisjunctiveCutInfoCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3) : \
  IloCplex::DisjunctiveCutInfoCallbackI(env), x1(xx1), x2(xx2), x3(xx3) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3)));\
}\
void name##I::main()

#define ILODISJUNCTIVECUTINFOCALLBACK4(name, type1, x1, type2, x2, type3, x3, type4, x4) \
class name##I : public IloCplex::DisjunctiveCutInfoCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
  type4 x4;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3, type4 xx4) \
    : IloCplex::DisjunctiveCutInfoCallbackI(env), x1(xx1), x2(xx2), x3(xx3), x4(xx4) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3, type4 x4) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3, x4)));\
}\
void name##I::main()

#define ILODISJUNCTIVECUTINFOCALLBACK5(name, type1, x1, type2, x2, type3, x3, type4, x4, type5, x5) \
class name##I : public IloCplex::DisjunctiveCutInfoCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
  type4 x4;\
  type5 x5;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3, type4 xx4, type5 xx5) \
    : IloCplex::DisjunctiveCutInfoCallbackI(env), x1(xx1), x2(xx2), x3(xx3), x4(xx4), x5(xx5) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3, type4 x4, type5 x5) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3, x4, x5)));\
}\
void name##I::main()

#define ILODISJUNCTIVECUTINFOCALLBACK6(name, type1, x1, type2, x2, type3, x3, type4, x4, \
                        type5, x5, type6, x6) \
class name##I : public IloCplex::DisjunctiveCutInfoCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
  type4 x4;\
  type5 x5;\
  type6 x6;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3, type4 xx4, type5 xx5, type6 xx6) \
    : IloCplex::DisjunctiveCutInfoCallbackI(env), x1(xx1), x2(xx2), x3(xx3), x4(xx4), x5(xx5), x6(xx6) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3, type4 x4, \
                        type5 x5, type6 x6) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3, x4, x5, x6)));\
}\
void name##I::main()

#define ILODISJUNCTIVECUTINFOCALLBACK7(name, type1, x1, type2, x2, type3, x3, type4, x4, \
                        type5, x5, type6, x6, type7, x7) \
class name##I : public IloCplex::DisjunctiveCutInfoCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
  type4 x4;\
  type5 x5;\
  type6 x6;\
  type7 x7;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3, type4 xx4, type5 xx5, type6 xx6, type7 xx7) \
    : IloCplex::DisjunctiveCutInfoCallbackI(env), x1(xx1), x2(xx2), x3(xx3), x4(xx4), x5(xx5), x6(xx6), x7(xx7) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3, type4 x4, \
                        type5 x5, type6 x6, type7 x7) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3, x4, x5, x6, x7)));\
}\
void name##I::main()


#define ILODISJUNCTIVECUTCALLBACK0(name) \
class name##I : public IloCplex::DisjunctiveCutCallbackI {\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env) : IloCplex::DisjunctiveCutCallbackI(env) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env) {\
  return (IloCplex::Callback(new (env) name##I(env)));\
}\
void name##I::main()

#define ILODISJUNCTIVECUTCALLBACK1(name, type1, x1) \
class name##I : public IloCplex::DisjunctiveCutCallbackI {\
  type1 x1;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1) : IloCplex::DisjunctiveCutCallbackI(env), x1(xx1) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1) {\
  return (IloCplex::Callback(new (env) name##I(env, x1)));\
}\
void name##I::main()

#define ILODISJUNCTIVECUTCALLBACK2(name, type1, x1, type2, x2) \
class name##I : public IloCplex::DisjunctiveCutCallbackI {\
  type1 x1;\
  type2 x2;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2) : \
  IloCplex::DisjunctiveCutCallbackI(env), x1(xx1), x2(xx2) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2)));\
}\
void name##I::main()

#define ILODISJUNCTIVECUTCALLBACK3(name, type1, x1, type2, x2, type3, x3) \
class name##I : public IloCplex::DisjunctiveCutCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3) : \
  IloCplex::DisjunctiveCutCallbackI(env), x1(xx1), x2(xx2), x3(xx3) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3)));\
}\
void name##I::main()

#define ILODISJUNCTIVECUTCALLBACK4(name, type1, x1, type2, x2, type3, x3, type4, x4) \
class name##I : public IloCplex::DisjunctiveCutCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
  type4 x4;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3, type4 xx4) \
    : IloCplex::DisjunctiveCutCallbackI(env), x1(xx1), x2(xx2), x3(xx3), x4(xx4) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3, type4 x4) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3, x4)));\
}\
void name##I::main()

#define ILODISJUNCTIVECUTCALLBACK5(name, type1, x1, type2, x2, type3, x3, type4, x4, type5, x5) \
class name##I : public IloCplex::DisjunctiveCutCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
  type4 x4;\
  type5 x5;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3, type4 xx4, type5 xx5) \
    : IloCplex::DisjunctiveCutCallbackI(env), x1(xx1), x2(xx2), x3(xx3), x4(xx4), x5(xx5) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3, type4 x4, type5 x5) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3, x4, x5)));\
}\
void name##I::main()

#define ILODISJUNCTIVECUTCALLBACK6(name, type1, x1, type2, x2, type3, x3, type4, x4, \
                        type5, x5, type6, x6) \
class name##I : public IloCplex::DisjunctiveCutCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
  type4 x4;\
  type5 x5;\
  type6 x6;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3, type4 xx4, type5 xx5, type6 xx6) \
    : IloCplex::DisjunctiveCutCallbackI(env), x1(xx1), x2(xx2), x3(xx3), x4(xx4), x5(xx5), x6(xx6) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3, type4 x4, \
                        type5 x5, type6 x6) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3, x4, x5, x6)));\
}\
void name##I::main()

#define ILODISJUNCTIVECUTCALLBACK7(name, type1, x1, type2, x2, type3, x3, type4, x4, \
                        type5, x5, type6, x6, type7, x7) \
class name##I : public IloCplex::DisjunctiveCutCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
  type4 x4;\
  type5 x5;\
  type6 x6;\
  type7 x7;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3, type4 xx4, type5 xx5, type6 xx6, type7 xx7) \
    : IloCplex::DisjunctiveCutCallbackI(env), x1(xx1), x2(xx2), x3(xx3), x4(xx4), x5(xx5), x6(xx6), x7(xx7) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3, type4 x4, \
                        type5 x5, type6 x6, type7 x7) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3, x4, x5, x6, x7)));\
}\
void name##I::main()


#define ILOCROSSOVERCALLBACK0(name) \
class name##I : public IloCplex::CrossoverCallbackI {\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env) : IloCplex::CrossoverCallbackI(env) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env) {\
  return (IloCplex::Callback(new (env) name##I(env)));\
}\
void name##I::main()

#define ILOCROSSOVERCALLBACK1(name, type1, x1) \
class name##I : public IloCplex::CrossoverCallbackI {\
  type1 x1;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1) : IloCplex::CrossoverCallbackI(env), x1(xx1) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1) {\
  return (IloCplex::Callback(new (env) name##I(env, x1)));\
}\
void name##I::main()

#define ILOCROSSOVERCALLBACK2(name, type1, x1, type2, x2) \
class name##I : public IloCplex::CrossoverCallbackI {\
  type1 x1;\
  type2 x2;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2) : \
  IloCplex::CrossoverCallbackI(env), x1(xx1), x2(xx2) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2)));\
}\
void name##I::main()

#define ILOCROSSOVERCALLBACK3(name, type1, x1, type2, x2, type3, x3) \
class name##I : public IloCplex::CrossoverCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3) : \
  IloCplex::CrossoverCallbackI(env), x1(xx1), x2(xx2), x3(xx3) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3)));\
}\
void name##I::main()

#define ILOCROSSOVERCALLBACK4(name, type1, x1, type2, x2, type3, x3, type4, x4) \
class name##I : public IloCplex::CrossoverCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
  type4 x4;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3, type4 xx4) \
    : IloCplex::CrossoverCallbackI(env), x1(xx1), x2(xx2), x3(xx3), x4(xx4) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3, type4 x4) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3, x4)));\
}\
void name##I::main()

#define ILOCROSSOVERCALLBACK5(name, type1, x1, type2, x2, type3, x3, type4, x4, type5, x5) \
class name##I : public IloCplex::CrossoverCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
  type4 x4;\
  type5 x5;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3, type4 xx4, type5 xx5) \
    : IloCplex::CrossoverCallbackI(env), x1(xx1), x2(xx2), x3(xx3), x4(xx4), x5(xx5) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3, type4 x4, type5 x5) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3, x4, x5)));\
}\
void name##I::main()

#define ILOCROSSOVERCALLBACK6(name, type1, x1, type2, x2, type3, x3, type4, x4, \
                        type5, x5, type6, x6) \
class name##I : public IloCplex::CrossoverCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
  type4 x4;\
  type5 x5;\
  type6 x6;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3, type4 xx4, type5 xx5, type6 xx6) \
    : IloCplex::CrossoverCallbackI(env), x1(xx1), x2(xx2), x3(xx3), x4(xx4), x5(xx5), x6(xx6) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3, type4 x4, \
                        type5 x5, type6 x6) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3, x4, x5, x6)));\
}\
void name##I::main()

#define ILOCROSSOVERCALLBACK7(name, type1, x1, type2, x2, type3, x3, type4, x4, \
                        type5, x5, type6, x6, type7, x7) \
class name##I : public IloCplex::CrossoverCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
  type4 x4;\
  type5 x5;\
  type6 x6;\
  type7 x7;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3, type4 xx4, type5 xx5, type6 xx6, type7 xx7) \
    : IloCplex::CrossoverCallbackI(env), x1(xx1), x2(xx2), x3(xx3), x4(xx4), x5(xx5), x6(xx6), x7(xx7) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3, type4 x4, \
                        type5 x5, type6 x6, type7 x7) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3, x4, x5, x6, x7)));\
}\
void name##I::main()


#define ILOUSERCUTCALLBACK0(name) \
class name##I : public IloCplex::UserCutCallbackI {\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env) : IloCplex::UserCutCallbackI(env) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env) {\
  return (IloCplex::Callback(new (env) name##I(env)));\
}\
void name##I::main()

#define ILOUSERCUTCALLBACK1(name, type1, x1) \
class name##I : public IloCplex::UserCutCallbackI {\
  type1 x1;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1) : IloCplex::UserCutCallbackI(env), x1(xx1) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1) {\
  return (IloCplex::Callback(new (env) name##I(env, x1)));\
}\
void name##I::main()

#define ILOUSERCUTCALLBACK2(name, type1, x1, type2, x2) \
class name##I : public IloCplex::UserCutCallbackI {\
  type1 x1;\
  type2 x2;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2) : IloCplex::UserCutCallbackI(env), x1(xx1), x2(xx2) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2)));\
}\
void name##I::main()

#define ILOUSERCUTCALLBACK3(name, type1, x1, type2, x2, type3, x3) \
class name##I : public IloCplex::UserCutCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3) : \
  IloCplex::UserCutCallbackI(env), x1(xx1), x2(xx2), x3(xx3) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3)));\
}\
void name##I::main()

#define ILOUSERCUTCALLBACK4(name, type1, x1, type2, x2, type3, x3, type4, x4) \
class name##I : public IloCplex::UserCutCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
  type4 x4;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3, type4 xx4) \
    : IloCplex::UserCutCallbackI(env), x1(xx1), x2(xx2), x3(xx3), x4(xx4) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3, type4 x4) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3, x4)));\
}\
void name##I::main()

#define ILOUSERCUTCALLBACK5(name, type1, x1, type2, x2, type3, x3, type4, x4, type5, x5) \
class name##I : public IloCplex::UserCutCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
  type4 x4;\
  type5 x5;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3, type4 xx4, type5 xx5) \
    : IloCplex::UserCutCallbackI(env), x1(xx1), x2(xx2), x3(xx3), x4(xx4), x5(xx5) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3, type4 x4, type5 x5) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3, x4, x5)));\
}\
void name##I::main()

#define ILOUSERCUTCALLBACK6(name, type1, x1, type2, x2, type3, x3, type4, x4, \
                        type5, x5, type6, x6) \
class name##I : public IloCplex::UserCutCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
  type4 x4;\
  type5 x5;\
  type6 x6;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3, type4 xx4, type5 xx5, type6 xx6) \
    : IloCplex::UserCutCallbackI(env), x1(xx1), x2(xx2), x3(xx3), x4(xx4), x5(xx5), x6(xx6) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3, type4 x4, \
                        type5 x5, type6 x6) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3, x4, x5, x6)));\
}\
void name##I::main()

#define ILOUSERCUTCALLBACK7(name, type1, x1, type2, x2, type3, x3, type4, x4, \
                        type5, x5, type6, x6, type7, x7) \
class name##I : public IloCplex::UserCutCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
  type4 x4;\
  type5 x5;\
  type6 x6;\
  type7 x7;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3, type4 xx4, type5 xx5, type6 xx6, type7 xx7) \
    : IloCplex::UserCutCallbackI(env), x1(xx1), x2(xx2), x3(xx3), x4(xx4), x5(xx5), x6(xx6), x7(xx7) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3, type4 x4, \
                        type5 x5, type6 x6, type7 x7) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3, x4, x5, x6, x7)));\
}\
void name##I::main()


#define ILOLAZYCONSTRAINTCALLBACK0(name) \
class name##I : public IloCplex::LazyConstraintCallbackI {\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env) : IloCplex::LazyConstraintCallbackI(env) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env) {\
  return (IloCplex::Callback(new (env) name##I(env)));\
}\
void name##I::main()

#define ILOLAZYCONSTRAINTCALLBACK1(name, type1, x1) \
class name##I : public IloCplex::LazyConstraintCallbackI {\
  type1 x1;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1) : IloCplex::LazyConstraintCallbackI(env), x1(xx1) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1) {\
  return (IloCplex::Callback(new (env) name##I(env, x1)));\
}\
void name##I::main()

#define ILOLAZYCONSTRAINTCALLBACK2(name, type1, x1, type2, x2) \
class name##I : public IloCplex::LazyConstraintCallbackI {\
  type1 x1;\
  type2 x2;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2) : \
  IloCplex::LazyConstraintCallbackI(env), x1(xx1), x2(xx2) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2)));\
}\
void name##I::main()

#define ILOLAZYCONSTRAINTCALLBACK3(name, type1, x1, type2, x2, type3, x3) \
class name##I : public IloCplex::LazyConstraintCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3) : \
  IloCplex::LazyConstraintCallbackI(env), x1(xx1), x2(xx2), x3(xx3) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3)));\
}\
void name##I::main()

#define ILOLAZYCONSTRAINTCALLBACK4(name, type1, x1, type2, x2, type3, x3, type4, x4) \
class name##I : public IloCplex::LazyConstraintCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
  type4 x4;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3, type4 xx4) \
    : IloCplex::LazyConstraintCallbackI(env), x1(xx1), x2(xx2), x3(xx3), x4(xx4) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3, type4 x4) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3, x4)));\
}\
void name##I::main()

#define ILOLAZYCONSTRAINTCALLBACK5(name, type1, x1, type2, x2, type3, x3, type4, x4, type5, x5) \
class name##I : public IloCplex::LazyConstraintCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
  type4 x4;\
  type5 x5;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3, type4 xx4, type5 xx5) \
    : IloCplex::LazyConstraintCallbackI(env), x1(xx1), x2(xx2), x3(xx3), x4(xx4), x5(xx5) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3, type4 x4, type5 x5) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3, x4, x5)));\
}\
void name##I::main()

#define ILOLAZYCONSTRAINTCALLBACK6(name, type1, x1, type2, x2, type3, x3, type4, x4, \
                        type5, x5, type6, x6) \
class name##I : public IloCplex::LazyConstraintCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
  type4 x4;\
  type5 x5;\
  type6 x6;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3, type4 xx4, type5 xx5, type6 xx6) \
    : IloCplex::LazyConstraintCallbackI(env), x1(xx1), x2(xx2), x3(xx3), x4(xx4), x5(xx5), x6(xx6) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3, type4 x4, \
                        type5 x5, type6 x6) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3, x4, x5, x6)));\
}\
void name##I::main()

#define ILOLAZYCONSTRAINTCALLBACK7(name, type1, x1, type2, x2, type3, x3, type4, x4, \
                        type5, x5, type6, x6, type7, x7) \
class name##I : public IloCplex::LazyConstraintCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
  type4 x4;\
  type5 x5;\
  type6 x6;\
  type7 x7;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3, type4 xx4, type5 xx5, type6 xx6, type7 xx7) \
    : IloCplex::LazyConstraintCallbackI(env), x1(xx1), x2(xx2), x3(xx3), x4(xx4), x5(xx5), x6(xx6), x7(xx7) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3, type4 x4, \
                        type5 x5, type6 x6, type7 x7) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3, x4, x5, x6, x7)));\
}\
void name##I::main()

#define ILONODECALLBACK0(name) \
class name##I : public IloCplex::NodeCallbackI {\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env) : IloCplex::NodeCallbackI(env) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env) {\
  return (IloCplex::Callback(new (env) name##I(env)));\
}\
void name##I::main()

#define ILONODECALLBACK1(name, type1, x1) \
class name##I : public IloCplex::NodeCallbackI {\
  type1 x1;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1) : IloCplex::NodeCallbackI(env), x1(xx1) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1) {\
  return (IloCplex::Callback(new (env) name##I(env, x1)));\
}\
void name##I::main()

#define ILONODECALLBACK2(name, type1, x1, type2, x2) \
class name##I : public IloCplex::NodeCallbackI {\
  type1 x1;\
  type2 x2;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2) : IloCplex::NodeCallbackI(env), x1(xx1), x2(xx2) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2)));\
}\
void name##I::main()

#define ILONODECALLBACK3(name, type1, x1, type2, x2, type3, x3) \
class name##I : public IloCplex::NodeCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3) : \
  IloCplex::NodeCallbackI(env), x1(xx1), x2(xx2), x3(xx3) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3)));\
}\
void name##I::main()

#define ILONODECALLBACK4(name, type1, x1, type2, x2, type3, x3, type4, x4) \
class name##I : public IloCplex::NodeCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
  type4 x4;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3, type4 xx4) \
    : IloCplex::NodeCallbackI(env), x1(xx1), x2(xx2), x3(xx3), x4(xx4) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3, type4 x4) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3, x4)));\
}\
void name##I::main()

#define ILONODECALLBACK5(name, type1, x1, type2, x2, type3, x3, type4, x4, type5, x5) \
class name##I : public IloCplex::NodeCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
  type4 x4;\
  type5 x5;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3, type4 xx4, type5 xx5) \
    : IloCplex::NodeCallbackI(env), x1(xx1), x2(xx2), x3(xx3), x4(xx4), x5(xx5) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3, type4 x4, type5 x5) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3, x4, x5)));\
}\
void name##I::main()

#define ILONODECALLBACK6(name, type1, x1, type2, x2, type3, x3, type4, x4, \
                        type5, x5, type6, x6) \
class name##I : public IloCplex::NodeCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
  type4 x4;\
  type5 x5;\
  type6 x6;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3, type4 xx4, type5 xx5, type6 xx6) \
    : IloCplex::NodeCallbackI(env), x1(xx1), x2(xx2), x3(xx3), x4(xx4), x5(xx5), x6(xx6) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3, type4 x4, \
                        type5 x5, type6 x6) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3, x4, x5, x6)));\
}\
void name##I::main()

#define ILONODECALLBACK7(name, type1, x1, type2, x2, type3, x3, type4, x4, \
                        type5, x5, type6, x6, type7, x7) \
class name##I : public IloCplex::NodeCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
  type4 x4;\
  type5 x5;\
  type6 x6;\
  type7 x7;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3, type4 xx4, type5 xx5, type6 xx6, type7 xx7) \
    : IloCplex::NodeCallbackI(env), x1(xx1), x2(xx2), x3(xx3), x4(xx4), x5(xx5), x6(xx6), x7(xx7) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3, type4 x4, \
                        type5 x5, type6 x6, type7 x7) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3, x4, x5, x6, x7)));\
}\
void name##I::main()


#define ILOINCUMBENTCALLBACK0(name) \
class name##I : public IloCplex::IncumbentCallbackI {\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env) : IloCplex::IncumbentCallbackI(env) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env) {\
  return (IloCplex::Callback(new (env) name##I(env)));\
}\
void name##I::main()

#define ILOINCUMBENTCALLBACK1(name, type1, x1) \
class name##I : public IloCplex::IncumbentCallbackI {\
  type1 x1;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1) : IloCplex::IncumbentCallbackI(env), x1(xx1) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1) {\
  return (IloCplex::Callback(new (env) name##I(env, x1)));\
}\
void name##I::main()

#define ILOINCUMBENTCALLBACK2(name, type1, x1, type2, x2) \
class name##I : public IloCplex::IncumbentCallbackI {\
  type1 x1;\
  type2 x2;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2) : \
  IloCplex::IncumbentCallbackI(env), x1(xx1), x2(xx2) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2)));\
}\
void name##I::main()

#define ILOINCUMBENTCALLBACK3(name, type1, x1, type2, x2, type3, x3) \
class name##I : public IloCplex::IncumbentCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3) : \
  IloCplex::IncumbentCallbackI(env), x1(xx1), x2(xx2), x3(xx3) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3)));\
}\
void name##I::main()

#define ILOINCUMBENTCALLBACK4(name, type1, x1, type2, x2, type3, x3, type4, x4) \
class name##I : public IloCplex::IncumbentCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
  type4 x4;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3, type4 xx4) \
    : IloCplex::IncumbentCallbackI(env), x1(xx1), x2(xx2), x3(xx3), x4(xx4) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3, type4 x4) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3, x4)));\
}\
void name##I::main()

#define ILOINCUMBENTCALLBACK5(name, type1, x1, type2, x2, type3, x3, type4, x4, type5, x5) \
class name##I : public IloCplex::IncumbentCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
  type4 x4;\
  type5 x5;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3, type4 xx4, type5 xx5) \
    : IloCplex::IncumbentCallbackI(env), x1(xx1), x2(xx2), x3(xx3), x4(xx4), x5(xx5) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3, type4 x4, type5 x5) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3, x4, x5)));\
}\
void name##I::main()

#define ILOINCUMBENTCALLBACK6(name, type1, x1, type2, x2, type3, x3, type4, x4, \
                        type5, x5, type6, x6) \
class name##I : public IloCplex::IncumbentCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
  type4 x4;\
  type5 x5;\
  type6 x6;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3, type4 xx4, type5 xx5, type6 xx6) \
    : IloCplex::IncumbentCallbackI(env), x1(xx1), x2(xx2), x3(xx3), x4(xx4), x5(xx5), x6(xx6) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3, type4 x4, \
                        type5 x5, type6 x6) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3, x4, x5, x6)));\
}\
void name##I::main()

#define ILOINCUMBENTCALLBACK7(name, type1, x1, type2, x2, type3, x3, type4, x4, \
                        type5, x5, type6, x6, type7, x7) \
class name##I : public IloCplex::IncumbentCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
  type4 x4;\
  type5 x5;\
  type6 x6;\
  type7 x7;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3, type4 xx4, type5 xx5, type6 xx6, type7 xx7) \
    : IloCplex::IncumbentCallbackI(env), x1(xx1), x2(xx2), x3(xx3), x4(xx4), x5(xx5), x6(xx6), x7(xx7) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3, type4 x4, \
                        type5 x5, type6 x6, type7 x7) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3, x4, x5, x6, x7)));\
}\
void name##I::main()


#define ILOBRANCHCALLBACK0(name) \
class name##I : public IloCplex::BranchCallbackI {\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env) : IloCplex::BranchCallbackI(env) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env) {\
  return (IloCplex::Callback(new (env) name##I(env)));\
}\
void name##I::main()

#define ILOBRANCHCALLBACK1(name, type1, x1) \
class name##I : public IloCplex::BranchCallbackI {\
  type1 x1;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1) : IloCplex::BranchCallbackI(env), x1(xx1) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1) {\
  return (IloCplex::Callback(new (env) name##I(env, x1)));\
}\
void name##I::main()

#define ILOBRANCHCALLBACK2(name, type1, x1, type2, x2) \
class name##I : public IloCplex::BranchCallbackI {\
  type1 x1;\
  type2 x2;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2) : IloCplex::BranchCallbackI(env), x1(xx1), x2(xx2) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2)));\
}\
void name##I::main()

#define ILOBRANCHCALLBACK3(name, type1, x1, type2, x2, type3, x3) \
class name##I : public IloCplex::BranchCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3) : \
  IloCplex::BranchCallbackI(env), x1(xx1), x2(xx2), x3(xx3) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3)));\
}\
void name##I::main()

#define ILOBRANCHCALLBACK4(name, type1, x1, type2, x2, type3, x3, type4, x4) \
class name##I : public IloCplex::BranchCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
  type4 x4;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3, type4 xx4) \
    : IloCplex::BranchCallbackI(env), x1(xx1), x2(xx2), x3(xx3), x4(xx4) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3, type4 x4) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3, x4)));\
}\
void name##I::main()

#define ILOBRANCHCALLBACK5(name, type1, x1, type2, x2, type3, x3, type4, x4, type5, x5) \
class name##I : public IloCplex::BranchCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
  type4 x4;\
  type5 x5;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3, type4 xx4, type5 xx5) \
    : IloCplex::BranchCallbackI(env), x1(xx1), x2(xx2), x3(xx3), x4(xx4), x5(xx5) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3, type4 x4, type5 x5) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3, x4, x5)));\
}\
void name##I::main()

#define ILOBRANCHCALLBACK6(name, type1, x1, type2, x2, type3, x3, type4, x4, \
                        type5, x5, type6, x6) \
class name##I : public IloCplex::BranchCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
  type4 x4;\
  type5 x5;\
  type6 x6;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3, type4 xx4, type5 xx5, type6 xx6) \
    : IloCplex::BranchCallbackI(env), x1(xx1), x2(xx2), x3(xx3), x4(xx4), x5(xx5), x6(xx6) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3, type4 x4, \
                        type5 x5, type6 x6) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3, x4, x5, x6)));\
}\
void name##I::main()

#define ILOBRANCHCALLBACK7(name, type1, x1, type2, x2, type3, x3, type4, x4, \
                        type5, x5, type6, x6, type7, x7) \
class name##I : public IloCplex::BranchCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
  type4 x4;\
  type5 x5;\
  type6 x6;\
  type7 x7;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3, type4 xx4, type5 xx5, type6 xx6, type7 xx7) \
    : IloCplex::BranchCallbackI(env), x1(xx1), x2(xx2), x3(xx3), x4(xx4), x5(xx5), x6(xx6), x7(xx7) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3, type4 x4, \
                        type5 x5, type6 x6, type7 x7) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3, x4, x5, x6, x7)));\
}\
void name##I::main()


#define ILOHEURISTICCALLBACK0(name) \
class name##I : public IloCplex::HeuristicCallbackI {\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env) : IloCplex::HeuristicCallbackI(env) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env) {\
  return (IloCplex::Callback(new (env) name##I(env)));\
}\
void name##I::main()

#define ILOHEURISTICCALLBACK1(name, type1, x1) \
class name##I : public IloCplex::HeuristicCallbackI {\
  type1 x1;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1) : IloCplex::HeuristicCallbackI(env), x1(xx1) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1) {\
  return (IloCplex::Callback(new (env) name##I(env, x1)));\
}\
void name##I::main()

#define ILOHEURISTICCALLBACK2(name, type1, x1, type2, x2) \
class name##I : public IloCplex::HeuristicCallbackI {\
  type1 x1;\
  type2 x2;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2) : \
  IloCplex::HeuristicCallbackI(env), x1(xx1), x2(xx2) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2)));\
}\
void name##I::main()

#define ILOHEURISTICCALLBACK3(name, type1, x1, type2, x2, type3, x3) \
class name##I : public IloCplex::HeuristicCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3) : \
  IloCplex::HeuristicCallbackI(env), x1(xx1), x2(xx2), x3(xx3) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3)));\
}\
void name##I::main()

#define ILOHEURISTICCALLBACK4(name, type1, x1, type2, x2, type3, x3, type4, x4) \
class name##I : public IloCplex::HeuristicCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
  type4 x4;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3, type4 xx4) \
    : IloCplex::HeuristicCallbackI(env), x1(xx1), x2(xx2), x3(xx3), x4(xx4) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3, type4 x4) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3, x4)));\
}\
void name##I::main()

#define ILOHEURISTICCALLBACK5(name, type1, x1, type2, x2, type3, x3, type4, x4, type5, x5) \
class name##I : public IloCplex::HeuristicCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
  type4 x4;\
  type5 x5;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3, type4 xx4, type5 xx5) \
    : IloCplex::HeuristicCallbackI(env), x1(xx1), x2(xx2), x3(xx3), x4(xx4), x5(xx5) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3, type4 x4, type5 x5) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3, x4, x5)));\
}\
void name##I::main()

#define ILOHEURISTICCALLBACK6(name, type1, x1, type2, x2, type3, x3, type4, x4, \
                        type5, x5, type6, x6) \
class name##I : public IloCplex::HeuristicCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
  type4 x4;\
  type5 x5;\
  type6 x6;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3, type4 xx4, type5 xx5, type6 xx6) \
    : IloCplex::HeuristicCallbackI(env), x1(xx1), x2(xx2), x3(xx3), x4(xx4), x5(xx5), x6(xx6) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3, type4 x4, \
                        type5 x5, type6 x6) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3, x4, x5, x6)));\
}\
void name##I::main()

#define ILOHEURISTICCALLBACK7(name, type1, x1, type2, x2, type3, x3, type4, x4, \
                        type5, x5, type6, x6, type7, x7) \
class name##I : public IloCplex::HeuristicCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
  type4 x4;\
  type5 x5;\
  type6 x6;\
  type7 x7;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3, type4 xx4, type5 xx5, type6 xx6, type7 xx7) \
    : IloCplex::HeuristicCallbackI(env), x1(xx1), x2(xx2), x3(xx3), x4(xx4), x5(xx5), x6(xx6), x7(xx7) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3, type4 x4, \
                        type5 x5, type6 x6, type7 x7) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3, x4, x5, x6, x7)));\
}\
void name##I::main()

#define ILOSOLVECALLBACK0(name) \
class name##I : public IloCplex::SolveCallbackI {\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env) : IloCplex::SolveCallbackI(env) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env) {\
  return (IloCplex::Callback(new (env) name##I(env)));\
}\
void name##I::main()

#define ILOSOLVECALLBACK1(name, type1, x1) \
class name##I : public IloCplex::SolveCallbackI {\
  type1 x1;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1) : IloCplex::SolveCallbackI(env), x1(xx1) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1) {\
  return (IloCplex::Callback(new (env) name##I(env, x1)));\
}\
void name##I::main()

#define ILOSOLVECALLBACK2(name, type1, x1, type2, x2) \
class name##I : public IloCplex::SolveCallbackI {\
  type1 x1;\
  type2 x2;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2) : IloCplex::SolveCallbackI(env), x1(xx1), x2(xx2) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2)));\
}\
void name##I::main()

#define ILOSOLVECALLBACK3(name, type1, x1, type2, x2, type3, x3) \
class name##I : public IloCplex::SolveCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3) : \
  IloCplex::SolveCallbackI(env), x1(xx1), x2(xx2), x3(xx3) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3)));\
}\
void name##I::main()

#define ILOSOLVECALLBACK4(name, type1, x1, type2, x2, type3, x3, type4, x4) \
class name##I : public IloCplex::SolveCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
  type4 x4;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3, type4 xx4) \
    : IloCplex::SolveCallbackI(env), x1(xx1), x2(xx2), x3(xx3), x4(xx4) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3, type4 x4) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3, x4)));\
}\
void name##I::main()

#define ILOSOLVECALLBACK5(name, type1, x1, type2, x2, type3, x3, type4, x4, type5, x5) \
class name##I : public IloCplex::SolveCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
  type4 x4;\
  type5 x5;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3, type4 xx4, type5 xx5) \
    : IloCplex::SolveCallbackI(env), x1(xx1), x2(xx2), x3(xx3), x4(xx4), x5(xx5) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3, type4 x4, type5 x5) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3, x4, x5)));\
}\
void name##I::main()

#define ILOSOLVECALLBACK6(name, type1, x1, type2, x2, type3, x3, type4, x4, \
                        type5, x5, type6, x6) \
class name##I : public IloCplex::SolveCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
  type4 x4;\
  type5 x5;\
  type6 x6;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3, type4 xx4, type5 xx5, type6 xx6) \
    : IloCplex::SolveCallbackI(env), x1(xx1), x2(xx2), x3(xx3), x4(xx4), x5(xx5), x6(xx6) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3, type4 x4, \
                        type5 x5, type6 x6) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3, x4, x5, x6)));\
}\
void name##I::main()

#define ILOSOLVECALLBACK7(name, type1, x1, type2, x2, type3, x3, type4, x4, \
                        type5, x5, type6, x6, type7, x7) \
class name##I : public IloCplex::SolveCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
  type4 x4;\
  type5 x5;\
  type6 x6;\
  type7 x7;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3, type4 xx4, type5 xx5, type6 xx6, type7 xx7) \
    : IloCplex::SolveCallbackI(env), x1(xx1), x2(xx2), x3(xx3), x4(xx4), x5(xx5), x6(xx6), x7(xx7) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3, type4 x4, \
                        type5 x5, type6 x6, type7 x7) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3, x4, x5, x6, x7)));\
}\
void name##I::main()


#define ILOTUNINGCALLBACK0(name) \
class name##I : public IloCplex::TuningCallbackI {\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env) : IloCplex::TuningCallbackI(env) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env) {\
  return (IloCplex::Callback(new (env) name##I(env)));\
}\
void name##I::main()

#define ILOTUNINGCALLBACK1(name, type1, x1) \
class name##I : public IloCplex::TuningCallbackI {\
  type1 x1;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1) : IloCplex::TuningCallbackI(env), x1(xx1) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1) {\
  return (IloCplex::Callback(new (env) name##I(env, x1)));\
}\
void name##I::main()

#define ILOTUNINGCALLBACK2(name, type1, x1, type2, x2) \
class name##I : public IloCplex::TuningCallbackI {\
  type1 x1;\
  type2 x2;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2) : \
  IloCplex::TuningCallbackI(env), x1(xx1), x2(xx2) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2)));\
}\
void name##I::main()

#define ILOTUNINGCALLBACK3(name, type1, x1, type2, x2, type3, x3) \
class name##I : public IloCplex::TuningCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3) : \
  IloCplex::TuningCallbackI(env), x1(xx1), x2(xx2), x3(xx3) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3)));\
}\
void name##I::main()

#define ILOTUNINGCALLBACK4(name, type1, x1, type2, x2, type3, x3, type4, x4) \
class name##I : public IloCplex::TuningCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
  type4 x4;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3, type4 xx4) \
    : IloCplex::TuningCallbackI(env), x1(xx1), x2(xx2), x3(xx3), x4(xx4) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3, type4 x4) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3, x4)));\
}\
void name##I::main()

#define ILOTUNINGCALLBACK5(name, type1, x1, type2, x2, type3, x3, type4, x4, type5, x5) \
class name##I : public IloCplex::TuningCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
  type4 x4;\
  type5 x5;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3, type4 xx4, type5 xx5) \
    : IloCplex::TuningCallbackI(env), x1(xx1), x2(xx2), x3(xx3), x4(xx4), x5(xx5) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3, type4 x4, type5 x5) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3, x4, x5)));\
}\
void name##I::main()

#define ILOTUNINGCALLBACK6(name, type1, x1, type2, x2, type3, x3, type4, x4, \
                        type5, x5, type6, x6) \
class name##I : public IloCplex::TuningCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
  type4 x4;\
  type5 x5;\
  type6 x6;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3, type4 xx4, type5 xx5, type6 xx6) \
    : IloCplex::TuningCallbackI(env), x1(xx1), x2(xx2), x3(xx3), x4(xx4), x5(xx5), x6(xx6) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3, type4 x4, \
                        type5 x5, type6 x6) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3, x4, x5, x6)));\
}\
void name##I::main()

#define ILOTUNINGCALLBACK7(name, type1, x1, type2, x2, type3, x3, type4, x4, \
                        type5, x5, type6, x6, type7, x7) \
class name##I : public IloCplex::TuningCallbackI {\
  type1 x1;\
  type2 x2;\
  type3 x3;\
  type4 x4;\
  type5 x5;\
  type6 x6;\
  type7 x7;\
public:\
  ILOCOMMONCALLBACKSTUFF(name) \
  name##I(IloEnv env, type1 xx1, type2 xx2, type3 xx3, type4 xx4, type5 xx5, type6 xx6, type7 xx7) \
    : IloCplex::TuningCallbackI(env), x1(xx1), x2(xx2), x3(xx3), x4(xx4), x5(xx5), x6(xx6), x7(xx7) {}\
  void main();\
};\
IloCplex::Callback name(IloEnv env, type1 x1, type2 x2, type3 x3, type4 x4, \
                        type5 x5, type6 x6, type7 x7) {\
  return (IloCplex::Callback(new (env) name##I(env, x1, x2, x3, x4, x5, x6, x7)));\
}\
void name##I::main()

#ifdef _WIN32
#pragma pack(pop)
#endif

#endif

