/* --------------------------------------------------------------------------
 * File: cplexremotemasterx.h
 * Version 12.7.1
 * --------------------------------------------------------------------------
 * Licensed Materials - Property of IBM
 * 5725-A06 5725-A29 5724-Y48 5724-Y49 5724-Y54 5724-Y55 5655-Y21
 * Copyright IBM Corporation 1988, 2017. All Rights Reserved.
 *
 * US Government Users Restricted Rights - Use, duplication or
 * disclosure restricted by GSA ADP Schedule Contract with
 * IBM Corp.
 *---------------------------------------------------------------------------
 */

#ifndef CPX_CPLEX_REMOTEMASTERX_H
#   define CPX_CPLEX_REMOTEMASTERX_H 1
#include "ilcplex/cplexremotex.h"

#ifdef _WIN32
#pragma pack(push, 8)
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if CPX_APIMODEL == CPX_APIMODEL_SMALL
#   include "cplexremotemasters.h"
#elif CPX_APIMODEL == CPX_APIMODEL_LARGE
#   include "cplexremotemasterl.h"
#else
#   error "Unknown CPX_APIMODEL"
#endif
#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXaddcols_async (CPXCENVptr env, CPXLPptr lp, CPXDIM ccnt,
                      CPXNNZ nzcnt, double const *obj,
                      CPXNNZ const *cmatbeg, CPXDIM const *cmatind,
                      double const *cmatval, double const *lb,
                      double const *ub, char const *const *colname,
                      CPXASYNCptr *handle_p)
{
   return CPX_CALL (addcols_async) (env, lp, ccnt, nzcnt, obj, cmatbeg, cmatind, cmatval, lb, ub, colname, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXaddcols_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (addcols_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXaddindconstr_async (CPXCENVptr env, CPXLPptr lp, CPXDIM indvar,
                           int complemented, CPXDIM nzcnt, double rhs,
                           int sense, CPXDIM const *linind,
                           double const *linval,
                           char const *indname_str,
                           CPXASYNCptr *handle_p)
{
   return CPX_CALL (addindconstr_async) (env, lp, indvar, complemented, nzcnt, rhs, sense, linind, linval, indname_str, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXaddindconstr_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (addindconstr_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXaddlazyconstraints_async (CPXCENVptr env, CPXLPptr lp,
                                 CPXDIM rcnt, CPXNNZ nzcnt,
                                 double const *rhs, char const *sense,
                                 CPXNNZ const *rmatbeg,
                                 CPXDIM const *rmatind,
                                 double const *rmatval,
                                 char const *const *rowname,
                                 CPXASYNCptr *handle_p)
{
   return CPX_CALL (addlazyconstraints_async) (env, lp, rcnt, nzcnt, rhs, sense, rmatbeg, rmatind, rmatval, rowname, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXaddlazyconstraints_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (addlazyconstraints_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXaddmipstarts_async (CPXCENVptr env, CPXLPptr lp, int mcnt,
                           CPXNNZ nzcnt, CPXNNZ const *beg,
                           CPXDIM const *varindices,
                           double const *values,
                           int const *effortlevel,
                           char const *const *mipstartname,
                           CPXASYNCptr *handle_p)
{
   return CPX_CALL (addmipstarts_async) (env, lp, mcnt, nzcnt, beg, varindices, values, effortlevel, mipstartname, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXaddmipstarts_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (addmipstarts_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXaddqconstr_async (CPXCENVptr env, CPXLPptr lp, CPXDIM linnzcnt,
                         CPXNNZ quadnzcnt, double rhs, int sense,
                         CPXDIM const *linind, double const *linval,
                         CPXDIM const *quadrow, CPXDIM const *quadcol,
                         double const *quadval, char const *lname_str,
                         CPXASYNCptr *handle_p)
{
   return CPX_CALL (addqconstr_async) (env, lp, linnzcnt, quadnzcnt, rhs, sense, linind, linval, quadrow, quadcol, quadval, lname_str, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXaddqconstr_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (addqconstr_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXaddrows_async (CPXCENVptr env, CPXLPptr lp, CPXDIM ccnt,
                      CPXDIM rcnt, CPXNNZ nzcnt, double const *rhs,
                      char const *sense, CPXNNZ const *rmatbeg,
                      CPXDIM const *rmatind, double const *rmatval,
                      char const *const *colname,
                      char const *const *rowname,
                      CPXASYNCptr *handle_p)
{
   return CPX_CALL (addrows_async) (env, lp, ccnt, rcnt, nzcnt, rhs, sense, rmatbeg, rmatind, rmatval, colname, rowname, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXaddrows_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (addrows_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXaddsolnpooldivfilter_async (CPXCENVptr env, CPXLPptr lp,
                                   double lower_bound,
                                   double upper_bound, CPXDIM nzcnt,
                                   CPXDIM const *ind,
                                   double const *weight,
                                   double const *refval,
                                   char const *lname_str,
                                   CPXASYNCptr *handle_p)
{
   return CPX_CALL (addsolnpooldivfilter_async) (env, lp, lower_bound, upper_bound, nzcnt, ind, weight, refval, lname_str, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXaddsolnpooldivfilter_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (addsolnpooldivfilter_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXaddsolnpoolrngfilter_async (CPXCENVptr env, CPXLPptr lp,
                                   double lb, double ub, CPXDIM nzcnt,
                                   CPXDIM const *ind,
                                   double const *val,
                                   char const *lname_str,
                                   CPXASYNCptr *handle_p)
{
   return CPX_CALL (addsolnpoolrngfilter_async) (env, lp, lb, ub, nzcnt, ind, val, lname_str, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXaddsolnpoolrngfilter_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (addsolnpoolrngfilter_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXaddsos_async (CPXCENVptr env, CPXLPptr lp, CPXDIM numsos,
                     CPXNNZ numsosnz, char const *sostype,
                     CPXNNZ const *sosbeg, CPXDIM const *sosind,
                     double const *soswt, char const *const *sosname,
                     CPXASYNCptr *handle_p)
{
   return CPX_CALL (addsos_async) (env, lp, numsos, numsosnz, sostype, sosbeg, sosind, soswt, sosname, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXaddsos_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (addsos_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXaddusercuts_async (CPXCENVptr env, CPXLPptr lp, CPXDIM rcnt,
                          CPXNNZ nzcnt, double const *rhs,
                          char const *sense, CPXNNZ const *rmatbeg,
                          CPXDIM const *rmatind, double const *rmatval,
                          char const *const *rowname,
                          CPXASYNCptr *handle_p)
{
   return CPX_CALL (addusercuts_async) (env, lp, rcnt, nzcnt, rhs, sense, rmatbeg, rmatind, rmatval, rowname, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXaddusercuts_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (addusercuts_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
void CPXPUBLIC
   CPXXasynchandledel (CPXASYNCptr *asynchandle_p)
{
CPX_CALL (asynchandledel) (asynchandle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXasynchandleload (CPXENVptr env, CPXASYNCptr *asynchandle_p,
                        void const *buffer)
{
   return CPX_CALL (asynchandleload) (env, asynchandle_p, buffer);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
void CPXPUBLIC
   CPXXasynchandlesave (CPXCASYNCptr asynchandle, void *buffer)
{
CPX_CALL (asynchandlesave) (asynchandle, buffer);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXasynckill (CPXASYNCptr asynchandle)
{
   return CPX_CALL (asynckill) (asynchandle);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXasynctest (CPXASYNCptr asynchandle, int *running_p)
{
   return CPX_CALL (asynctest) (asynchandle, running_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXbaropt_async (CPXCENVptr env, CPXLPptr lp,
                     CPXASYNCptr *handle_p)
{
   return CPX_CALL (baropt_async) (env, lp, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXbaropt_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (baropt_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXbaropt_multicast (CPXENVGROUPptr group)
{
   return CPX_CALL (baropt_multicast) (group);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXbasicpresolve_async (CPXCENVptr env, CPXLPptr lp,
                            CPXASYNCptr *handle_p)
{
   return CPX_CALL (basicpresolve_async) (env, lp, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXbasicpresolve_join (CPXASYNCptr *handle_p, double *redlb,
                           double *redub, int *rstat)
{
   return CPX_CALL (basicpresolve_join) (handle_p, redlb, redub, rstat);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXbendersopt_async (CPXCENVptr env, CPXLPptr lp,
                         CPXASYNCptr *handle_p)
{
   return CPX_CALL (bendersopt_async) (env, lp, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXbendersopt_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (bendersopt_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXbendersopt_multicast (CPXENVGROUPptr group)
{
   return CPX_CALL (bendersopt_multicast) (group);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXbinvacol_async (CPXCENVptr env, CPXCLPptr lp, CPXDIM j,
                       CPXASYNCptr *handle_p)
{
   return CPX_CALL (binvacol_async) (env, lp, j, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXbinvacol_join (CPXASYNCptr *handle_p, double *x)
{
   return CPX_CALL (binvacol_join) (handle_p, x);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXbinvarow_async (CPXCENVptr env, CPXCLPptr lp, CPXDIM i,
                       CPXASYNCptr *handle_p)
{
   return CPX_CALL (binvarow_async) (env, lp, i, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXbinvarow_join (CPXASYNCptr *handle_p, double *z)
{
   return CPX_CALL (binvarow_join) (handle_p, z);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXbinvcol_async (CPXCENVptr env, CPXCLPptr lp, CPXDIM j,
                      CPXASYNCptr *handle_p)
{
   return CPX_CALL (binvcol_async) (env, lp, j, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXbinvcol_join (CPXASYNCptr *handle_p, double *x)
{
   return CPX_CALL (binvcol_join) (handle_p, x);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXbinvrow_async (CPXCENVptr env, CPXCLPptr lp, CPXDIM i,
                      CPXASYNCptr *handle_p)
{
   return CPX_CALL (binvrow_async) (env, lp, i, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXbinvrow_join (CPXASYNCptr *handle_p, double *y)
{
   return CPX_CALL (binvrow_join) (handle_p, y);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXboundsa_async (CPXCENVptr env, CPXCLPptr lp, CPXDIM begin,
                      CPXDIM end, CPXASYNCptr *handle_p)
{
   return CPX_CALL (boundsa_async) (env, lp, begin, end, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXboundsa_join (CPXASYNCptr *handle_p, double *lblower,
                     double *lbupper, double *ublower, double *ubupper)
{
   return CPX_CALL (boundsa_join) (handle_p, lblower, lbupper, ublower, ubupper);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXbtran_async (CPXCENVptr env, CPXCLPptr lp, double *y,
                    CPXASYNCptr *handle_p)
{
   return CPX_CALL (btran_async) (env, lp, y, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXbtran_join (CPXASYNCptr *handle_p, double *y)
{
   return CPX_CALL (btran_join) (handle_p, y);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXcheckdfeas_async (CPXCENVptr env, CPXLPptr lp,
                         CPXASYNCptr *handle_p)
{
   return CPX_CALL (checkdfeas_async) (env, lp, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXcheckdfeas_join (CPXASYNCptr *handle_p, CPXDIM *infeas_p)
{
   return CPX_CALL (checkdfeas_join) (handle_p, infeas_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXcheckpfeas_async (CPXCENVptr env, CPXLPptr lp,
                         CPXASYNCptr *handle_p)
{
   return CPX_CALL (checkpfeas_async) (env, lp, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXcheckpfeas_join (CPXASYNCptr *handle_p, CPXDIM *infeas_p)
{
   return CPX_CALL (checkpfeas_join) (handle_p, infeas_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXchecksoln_async (CPXCENVptr env, CPXLPptr lp,
                        CPXASYNCptr *handle_p)
{
   return CPX_CALL (checksoln_async) (env, lp, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXchecksoln_join (CPXASYNCptr *handle_p, int *lpstatus_p)
{
   return CPX_CALL (checksoln_join) (handle_p, lpstatus_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXchgbds_async (CPXCENVptr env, CPXLPptr lp, CPXDIM cnt,
                     CPXDIM const *indices, char const *lu,
                     double const *bd, CPXASYNCptr *handle_p)
{
   return CPX_CALL (chgbds_async) (env, lp, cnt, indices, lu, bd, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXchgbds_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (chgbds_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXchgbds_multicast (CPXENVGROUPptr group, CPXDIM cnt,
                         CPXDIM const *indices, char const *lu,
                         double const *bd)
{
   return CPX_CALL (chgbds_multicast) (group, cnt, indices, lu, bd);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXchgcoef_async (CPXCENVptr env, CPXLPptr lp, CPXDIM i, CPXDIM j,
                      double newvalue, CPXASYNCptr *handle_p)
{
   return CPX_CALL (chgcoef_async) (env, lp, i, j, newvalue, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXchgcoef_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (chgcoef_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXchgcoef_multicast (CPXENVGROUPptr group, CPXDIM i, CPXDIM j,
                          double newvalue)
{
   return CPX_CALL (chgcoef_multicast) (group, i, j, newvalue);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXchgcoeflist_async (CPXCENVptr env, CPXLPptr lp, CPXNNZ numcoefs,
                          CPXDIM const *rowlist, CPXDIM const *collist,
                          double const *vallist, CPXASYNCptr *handle_p)
{
   return CPX_CALL (chgcoeflist_async) (env, lp, numcoefs, rowlist, collist, vallist, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXchgcoeflist_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (chgcoeflist_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXchgcoeflist_multicast (CPXENVGROUPptr group, CPXNNZ numcoefs,
                              CPXDIM const *rowlist,
                              CPXDIM const *collist,
                              double const *vallist)
{
   return CPX_CALL (chgcoeflist_multicast) (group, numcoefs, rowlist, collist, vallist);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXchgcolname_async (CPXCENVptr env, CPXLPptr lp, CPXDIM cnt,
                         CPXDIM const *indices,
                         char const *const *newname,
                         CPXASYNCptr *handle_p)
{
   return CPX_CALL (chgcolname_async) (env, lp, cnt, indices, newname, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXchgcolname_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (chgcolname_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXchgctype_async (CPXCENVptr env, CPXLPptr lp, CPXDIM cnt,
                       CPXDIM const *indices, char const *xctype,
                       CPXASYNCptr *handle_p)
{
   return CPX_CALL (chgctype_async) (env, lp, cnt, indices, xctype, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXchgctype_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (chgctype_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXchgctype_multicast (CPXENVGROUPptr group, CPXDIM cnt,
                           CPXDIM const *indices, char const *xctype)
{
   return CPX_CALL (chgctype_multicast) (group, cnt, indices, xctype);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXchgmipstarts_async (CPXCENVptr env, CPXLPptr lp, int mcnt,
                           int const *mipstartindices, CPXNNZ nzcnt,
                           CPXNNZ const *beg, CPXDIM const *varindices,
                           double const *values,
                           int const *effortlevel,
                           CPXASYNCptr *handle_p)
{
   return CPX_CALL (chgmipstarts_async) (env, lp, mcnt, mipstartindices, nzcnt, beg, varindices, values, effortlevel, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXchgmipstarts_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (chgmipstarts_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXchgmipstarts_multicast (CPXENVGROUPptr group, int mcnt,
                               int const *mipstartindices,
                               CPXNNZ nzcnt, CPXNNZ const *beg,
                               CPXDIM const *varindices,
                               double const *values,
                               int const *effortlevel)
{
   return CPX_CALL (chgmipstarts_multicast) (group, mcnt, mipstartindices, nzcnt, beg, varindices, values, effortlevel);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXchgname_async (CPXCENVptr env, CPXLPptr lp, int key, CPXDIM ij,
                      char const *newname_str, CPXASYNCptr *handle_p)
{
   return CPX_CALL (chgname_async) (env, lp, key, ij, newname_str, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXchgname_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (chgname_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXchgobj_async (CPXCENVptr env, CPXLPptr lp, CPXDIM cnt,
                     CPXDIM const *indices, double const *values,
                     CPXASYNCptr *handle_p)
{
   return CPX_CALL (chgobj_async) (env, lp, cnt, indices, values, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXchgobj_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (chgobj_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXchgobj_multicast (CPXENVGROUPptr group, CPXDIM cnt,
                         CPXDIM const *indices, double const *values)
{
   return CPX_CALL (chgobj_multicast) (group, cnt, indices, values);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXchgobjoffset_async (CPXCENVptr env, CPXLPptr lp, double offset,
                           CPXASYNCptr *handle_p)
{
   return CPX_CALL (chgobjoffset_async) (env, lp, offset, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXchgobjoffset_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (chgobjoffset_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXchgobjoffset_multicast (CPXENVGROUPptr group, double offset)
{
   return CPX_CALL (chgobjoffset_multicast) (group, offset);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXchgobjsen_async (CPXCENVptr env, CPXLPptr lp, int maxormin,
                        CPXASYNCptr *handle_p)
{
   return CPX_CALL (chgobjsen_async) (env, lp, maxormin, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXchgobjsen_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (chgobjsen_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXchgobjsen_multicast (CPXENVGROUPptr group, int maxormin)
{
   return CPX_CALL (chgobjsen_multicast) (group, maxormin);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXchgprobname_async (CPXCENVptr env, CPXLPptr lp,
                          char const *probname, CPXASYNCptr *handle_p)
{
   return CPX_CALL (chgprobname_async) (env, lp, probname, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXchgprobname_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (chgprobname_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXchgprobtype_async (CPXCENVptr env, CPXLPptr lp, int type,
                          CPXASYNCptr *handle_p)
{
   return CPX_CALL (chgprobtype_async) (env, lp, type, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXchgprobtype_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (chgprobtype_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXchgprobtype_multicast (CPXENVGROUPptr group, int type)
{
   return CPX_CALL (chgprobtype_multicast) (group, type);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXchgprobtypesolnpool_async (CPXCENVptr env, CPXLPptr lp,
                                  int type, int soln,
                                  CPXASYNCptr *handle_p)
{
   return CPX_CALL (chgprobtypesolnpool_async) (env, lp, type, soln, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXchgprobtypesolnpool_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (chgprobtypesolnpool_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXchgprobtypesolnpool_multicast (CPXENVGROUPptr group, int type,
                                      int soln)
{
   return CPX_CALL (chgprobtypesolnpool_multicast) (group, type, soln);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXchgqpcoef_async (CPXCENVptr env, CPXLPptr lp, CPXDIM i,
                        CPXDIM j, double newvalue,
                        CPXASYNCptr *handle_p)
{
   return CPX_CALL (chgqpcoef_async) (env, lp, i, j, newvalue, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXchgqpcoef_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (chgqpcoef_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXchgqpcoef_multicast (CPXENVGROUPptr group, CPXDIM i, CPXDIM j,
                            double newvalue)
{
   return CPX_CALL (chgqpcoef_multicast) (group, i, j, newvalue);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXchgrhs_async (CPXCENVptr env, CPXLPptr lp, CPXDIM cnt,
                     CPXDIM const *indices, double const *values,
                     CPXASYNCptr *handle_p)
{
   return CPX_CALL (chgrhs_async) (env, lp, cnt, indices, values, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXchgrhs_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (chgrhs_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXchgrhs_multicast (CPXENVGROUPptr group, CPXDIM cnt,
                         CPXDIM const *indices, double const *values)
{
   return CPX_CALL (chgrhs_multicast) (group, cnt, indices, values);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXchgrngval_async (CPXCENVptr env, CPXLPptr lp, CPXDIM cnt,
                        CPXDIM const *indices, double const *values,
                        CPXASYNCptr *handle_p)
{
   return CPX_CALL (chgrngval_async) (env, lp, cnt, indices, values, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXchgrngval_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (chgrngval_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXchgrngval_multicast (CPXENVGROUPptr group, CPXDIM cnt,
                            CPXDIM const *indices,
                            double const *values)
{
   return CPX_CALL (chgrngval_multicast) (group, cnt, indices, values);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXchgrowname_async (CPXCENVptr env, CPXLPptr lp, CPXDIM cnt,
                         CPXDIM const *indices,
                         char const *const *newname,
                         CPXASYNCptr *handle_p)
{
   return CPX_CALL (chgrowname_async) (env, lp, cnt, indices, newname, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXchgrowname_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (chgrowname_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXchgsense_async (CPXCENVptr env, CPXLPptr lp, CPXDIM cnt,
                       CPXDIM const *indices, char const *sense,
                       CPXASYNCptr *handle_p)
{
   return CPX_CALL (chgsense_async) (env, lp, cnt, indices, sense, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXchgsense_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (chgsense_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXchgsense_multicast (CPXENVGROUPptr group, CPXDIM cnt,
                           CPXDIM const *indices, char const *sense)
{
   return CPX_CALL (chgsense_multicast) (group, cnt, indices, sense);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXcleanup_async (CPXCENVptr env, CPXLPptr lp, double eps,
                      CPXASYNCptr *handle_p)
{
   return CPX_CALL (cleanup_async) (env, lp, eps, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXcleanup_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (cleanup_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXcleanup_multicast (CPXENVGROUPptr group, double eps)
{
   return CPX_CALL (cleanup_multicast) (group, eps);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXcloseCPLEXdisconnect (CPXENVptr *env_p, void *buffer)
{
   return CPX_CALL (closeCPLEXdisconnect) (env_p, buffer);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXclpwrite_async (CPXCENVptr env, CPXCLPptr lp,
                       char const *filename_str, CPXASYNCptr *handle_p)
{
   return CPX_CALL (clpwrite_async) (env, lp, filename_str, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXclpwrite_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (clpwrite_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXclpwrite_multicast (CPXENVGROUPptr group,
                           char const *filename_str)
{
   return CPX_CALL (clpwrite_multicast) (group, filename_str);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXcompletelp_async (CPXCENVptr env, CPXLPptr lp,
                         CPXASYNCptr *handle_p)
{
   return CPX_CALL (completelp_async) (env, lp, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXcompletelp_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (completelp_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXcompletelp_multicast (CPXENVGROUPptr group)
{
   return CPX_CALL (completelp_multicast) (group);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXcopybase_async (CPXCENVptr env, CPXLPptr lp, int const *cstat,
                       int const *rstat, CPXASYNCptr *handle_p)
{
   return CPX_CALL (copybase_async) (env, lp, cstat, rstat, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXcopybase_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (copybase_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXcopybasednorms_async (CPXCENVptr env, CPXLPptr lp,
                             int const *cstat, int const *rstat,
                             double const *dnorm,
                             CPXASYNCptr *handle_p)
{
   return CPX_CALL (copybasednorms_async) (env, lp, cstat, rstat, dnorm, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXcopybasednorms_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (copybasednorms_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXcopyctype_async (CPXCENVptr env, CPXLPptr lp,
                        char const *xctype, CPXASYNCptr *handle_p)
{
   return CPX_CALL (copyctype_async) (env, lp, xctype, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXcopyctype_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (copyctype_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXcopydnorms_async (CPXCENVptr env, CPXLPptr lp,
                         double const *norm, CPXDIM const *head,
                         CPXDIM len, CPXASYNCptr *handle_p)
{
   return CPX_CALL (copydnorms_async) (env, lp, norm, head, len, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXcopydnorms_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (copydnorms_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXcopydnorms_multicast (CPXENVGROUPptr group, double const *norm,
                             CPXDIM const *head, CPXDIM len)
{
   return CPX_CALL (copydnorms_multicast) (group, norm, head, len);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXcopylp_async (CPXCENVptr env, CPXLPptr lp, CPXDIM numcols,
                     CPXDIM numrows, int objsense,
                     double const *objective, double const *rhs,
                     char const *sense, CPXNNZ const *matbeg,
                     CPXDIM const *matcnt, CPXDIM const *matind,
                     double const *matval, double const *lb,
                     double const *ub, double const *rngval,
                     CPXASYNCptr *handle_p)
{
   return CPX_CALL (copylp_async) (env, lp, numcols, numrows, objsense, objective, rhs, sense, matbeg, matcnt, matind, matval, lb, ub, rngval, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXcopylp_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (copylp_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXcopylp_multicast (CPXENVGROUPptr group, CPXDIM numcols,
                         CPXDIM numrows, int objsense,
                         double const *objective, double const *rhs,
                         char const *sense, CPXNNZ const *matbeg,
                         CPXDIM const *matcnt, CPXDIM const *matind,
                         double const *matval, double const *lb,
                         double const *ub, double const *rngval)
{
   return CPX_CALL (copylp_multicast) (group, numcols, numrows, objsense, objective, rhs, sense, matbeg, matcnt, matind, matval, lb, ub, rngval);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXcopylpwnames_async (CPXCENVptr env, CPXLPptr lp, CPXDIM numcols,
                           CPXDIM numrows, int objsense,
                           double const *objective, double const *rhs,
                           char const *sense, CPXNNZ const *matbeg,
                           CPXDIM const *matcnt, CPXDIM const *matind,
                           double const *matval, double const *lb,
                           double const *ub, double const *rngval,
                           char const *const *colname,
                           char const *const *rowname,
                           CPXASYNCptr *handle_p)
{
   return CPX_CALL (copylpwnames_async) (env, lp, numcols, numrows, objsense, objective, rhs, sense, matbeg, matcnt, matind, matval, lb, ub, rngval, colname, rowname, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXcopylpwnames_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (copylpwnames_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXcopynettolp_async (CPXCENVptr env, CPXLPptr lp, CPXCNETptr net,
                          CPXASYNCptr *handle_p)
{
   return CPX_CALL (copynettolp_async) (env, lp, net, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXcopynettolp_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (copynettolp_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXcopynettolp_multicast (CPXENVGROUPptr group)
{
   return CPX_CALL (copynettolp_multicast) (group);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXcopyobjname_async (CPXCENVptr env, CPXLPptr lp,
                          char const *objname_str,
                          CPXASYNCptr *handle_p)
{
   return CPX_CALL (copyobjname_async) (env, lp, objname_str, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXcopyobjname_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (copyobjname_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXcopyorder_async (CPXCENVptr env, CPXLPptr lp, CPXDIM cnt,
                        CPXDIM const *indices, CPXDIM const *priority,
                        int const *direction, CPXASYNCptr *handle_p)
{
   return CPX_CALL (copyorder_async) (env, lp, cnt, indices, priority, direction, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXcopyorder_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (copyorder_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXcopyorder_multicast (CPXENVGROUPptr group, CPXDIM cnt,
                            CPXDIM const *indices,
                            CPXDIM const *priority,
                            int const *direction)
{
   return CPX_CALL (copyorder_multicast) (group, cnt, indices, priority, direction);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXcopypartialbase_async (CPXCENVptr env, CPXLPptr lp, CPXDIM ccnt,
                              CPXDIM const *cindices, int const *cstat,
                              CPXDIM rcnt, CPXDIM const *rindices,
                              int const *rstat, CPXASYNCptr *handle_p)
{
   return CPX_CALL (copypartialbase_async) (env, lp, ccnt, cindices, cstat, rcnt, rindices, rstat, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXcopypartialbase_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (copypartialbase_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXcopypartialbase_multicast (CPXENVGROUPptr group, CPXDIM ccnt,
                                  CPXDIM const *cindices,
                                  int const *cstat, CPXDIM rcnt,
                                  CPXDIM const *rindices,
                                  int const *rstat)
{
   return CPX_CALL (copypartialbase_multicast) (group, ccnt, cindices, cstat, rcnt, rindices, rstat);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXcopypnorms_async (CPXCENVptr env, CPXLPptr lp,
                         double const *cnorm, double const *rnorm,
                         CPXDIM len, CPXASYNCptr *handle_p)
{
   return CPX_CALL (copypnorms_async) (env, lp, cnorm, rnorm, len, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXcopypnorms_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (copypnorms_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXcopyprotected_async (CPXCENVptr env, CPXLPptr lp, CPXDIM cnt,
                            CPXDIM const *indices,
                            CPXASYNCptr *handle_p)
{
   return CPX_CALL (copyprotected_async) (env, lp, cnt, indices, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXcopyprotected_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (copyprotected_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXcopyprotected_multicast (CPXENVGROUPptr group, CPXDIM cnt,
                                CPXDIM const *indices)
{
   return CPX_CALL (copyprotected_multicast) (group, cnt, indices);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXcopyqpsep_async (CPXCENVptr env, CPXLPptr lp,
                        double const *qsepvec, CPXASYNCptr *handle_p)
{
   return CPX_CALL (copyqpsep_async) (env, lp, qsepvec, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXcopyqpsep_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (copyqpsep_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXcopyquad_async (CPXCENVptr env, CPXLPptr lp,
                       CPXNNZ const *qmatbeg, CPXDIM const *qmatcnt,
                       CPXDIM const *qmatind, double const *qmatval,
                       CPXASYNCptr *handle_p)
{
   return CPX_CALL (copyquad_async) (env, lp, qmatbeg, qmatcnt, qmatind, qmatval, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXcopyquad_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (copyquad_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXcopysos_async (CPXCENVptr env, CPXLPptr lp, CPXDIM numsos,
                      CPXNNZ numsosnz, char const *sostype,
                      CPXNNZ const *sosbeg, CPXDIM const *sosind,
                      double const *soswt, char const *const *sosname,
                      CPXASYNCptr *handle_p)
{
   return CPX_CALL (copysos_async) (env, lp, numsos, numsosnz, sostype, sosbeg, sosind, soswt, sosname, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXcopysos_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (copysos_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXcopystart_async (CPXCENVptr env, CPXLPptr lp, int const *cstat,
                        int const *rstat, double const *cprim,
                        double const *rprim, double const *cdual,
                        double const *rdual, CPXASYNCptr *handle_p)
{
   return CPX_CALL (copystart_async) (env, lp, cstat, rstat, cprim, rprim, cdual, rdual, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXcopystart_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (copystart_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXcreateenvgroup (CPXENVGROUPptr *group_p, int nenvs,
                       CPXENVptr const *envs)
{
   return CPX_CALL (createenvgroup) (group_p, nenvs, envs);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXcrushform_async (CPXCENVptr env, CPXCLPptr lp, CPXDIM len,
                        CPXDIM const *ind, double const *val,
                        CPXASYNCptr *handle_p)
{
   return CPX_CALL (crushform_async) (env, lp, len, ind, val, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXcrushform_join (CPXASYNCptr *handle_p, CPXDIM *plen_p,
                       double *poffset_p, CPXDIM *pind, double *pval)
{
   return CPX_CALL (crushform_join) (handle_p, plen_p, poffset_p, pind, pval);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXcrushpi_async (CPXCENVptr env, CPXCLPptr lp, double const *pi,
                      CPXASYNCptr *handle_p)
{
   return CPX_CALL (crushpi_async) (env, lp, pi, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXcrushpi_join (CPXASYNCptr *handle_p, double *prepi)
{
   return CPX_CALL (crushpi_join) (handle_p, prepi);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXcrushx_async (CPXCENVptr env, CPXCLPptr lp, double const *x,
                     CPXASYNCptr *handle_p)
{
   return CPX_CALL (crushx_async) (env, lp, x, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXcrushx_join (CPXASYNCptr *handle_p, double *prex)
{
   return CPX_CALL (crushx_join) (handle_p, prex);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXdelcols_async (CPXCENVptr env, CPXLPptr lp, CPXDIM begin,
                      CPXDIM end, CPXASYNCptr *handle_p)
{
   return CPX_CALL (delcols_async) (env, lp, begin, end, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXdelcols_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (delcols_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXdelcols_multicast (CPXENVGROUPptr group, CPXDIM begin,
                          CPXDIM end)
{
   return CPX_CALL (delcols_multicast) (group, begin, end);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXdeldblannotation_multicast (CPXENVGROUPptr group, CPXDIM idx)
{
   return CPX_CALL (deldblannotation_multicast) (group, idx);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXdeldblannotations_multicast (CPXENVGROUPptr group, CPXDIM begin,
                                    CPXDIM end)
{
   return CPX_CALL (deldblannotations_multicast) (group, begin, end);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXdelindconstrs_async (CPXCENVptr env, CPXLPptr lp, CPXDIM begin,
                            CPXDIM end, CPXASYNCptr *handle_p)
{
   return CPX_CALL (delindconstrs_async) (env, lp, begin, end, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXdelindconstrs_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (delindconstrs_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXdelindconstrs_multicast (CPXENVGROUPptr group, CPXDIM begin,
                                CPXDIM end)
{
   return CPX_CALL (delindconstrs_multicast) (group, begin, end);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXdellongannotation_multicast (CPXENVGROUPptr group, CPXDIM idx)
{
   return CPX_CALL (dellongannotation_multicast) (group, idx);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXdellongannotations_multicast (CPXENVGROUPptr group,
                                     CPXDIM begin, CPXDIM end)
{
   return CPX_CALL (dellongannotations_multicast) (group, begin, end);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXdelmipstarts_async (CPXCENVptr env, CPXLPptr lp, int begin,
                           int end, CPXASYNCptr *handle_p)
{
   return CPX_CALL (delmipstarts_async) (env, lp, begin, end, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXdelmipstarts_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (delmipstarts_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXdelmipstarts_multicast (CPXENVGROUPptr group, int begin,
                               int end)
{
   return CPX_CALL (delmipstarts_multicast) (group, begin, end);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXdelnames_async (CPXCENVptr env, CPXLPptr lp,
                       CPXASYNCptr *handle_p)
{
   return CPX_CALL (delnames_async) (env, lp, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXdelnames_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (delnames_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXdelnames_multicast (CPXENVGROUPptr group)
{
   return CPX_CALL (delnames_multicast) (group);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXdelqconstrs_async (CPXCENVptr env, CPXLPptr lp, CPXDIM begin,
                          CPXDIM end, CPXASYNCptr *handle_p)
{
   return CPX_CALL (delqconstrs_async) (env, lp, begin, end, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXdelqconstrs_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (delqconstrs_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXdelqconstrs_multicast (CPXENVGROUPptr group, CPXDIM begin,
                              CPXDIM end)
{
   return CPX_CALL (delqconstrs_multicast) (group, begin, end);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXdelrows_async (CPXCENVptr env, CPXLPptr lp, CPXDIM begin,
                      CPXDIM end, CPXASYNCptr *handle_p)
{
   return CPX_CALL (delrows_async) (env, lp, begin, end, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXdelrows_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (delrows_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXdelrows_multicast (CPXENVGROUPptr group, CPXDIM begin,
                          CPXDIM end)
{
   return CPX_CALL (delrows_multicast) (group, begin, end);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXdelsetcols_async (CPXCENVptr env, CPXLPptr lp, CPXDIM *delstat,
                         CPXASYNCptr *handle_p)
{
   return CPX_CALL (delsetcols_async) (env, lp, delstat, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXdelsetcols_join (CPXASYNCptr *handle_p, CPXDIM *delstat)
{
   return CPX_CALL (delsetcols_join) (handle_p, delstat);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXdelsetmipstarts_async (CPXCENVptr env, CPXLPptr lp,
                              int *delstat, CPXASYNCptr *handle_p)
{
   return CPX_CALL (delsetmipstarts_async) (env, lp, delstat, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXdelsetmipstarts_join (CPXASYNCptr *handle_p, int *delstat)
{
   return CPX_CALL (delsetmipstarts_join) (handle_p, delstat);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXdelsetrows_async (CPXCENVptr env, CPXLPptr lp, CPXDIM *delstat,
                         CPXASYNCptr *handle_p)
{
   return CPX_CALL (delsetrows_async) (env, lp, delstat, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXdelsetrows_join (CPXASYNCptr *handle_p, CPXDIM *delstat)
{
   return CPX_CALL (delsetrows_join) (handle_p, delstat);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXdelsetsolnpoolfilters_async (CPXCENVptr env, CPXLPptr lp,
                                    int *delstat,
                                    CPXASYNCptr *handle_p)
{
   return CPX_CALL (delsetsolnpoolfilters_async) (env, lp, delstat, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXdelsetsolnpoolfilters_join (CPXASYNCptr *handle_p, int *delstat)
{
   return CPX_CALL (delsetsolnpoolfilters_join) (handle_p, delstat);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXdelsetsolnpoolsolns_async (CPXCENVptr env, CPXLPptr lp,
                                  int *delstat, CPXASYNCptr *handle_p)
{
   return CPX_CALL (delsetsolnpoolsolns_async) (env, lp, delstat, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXdelsetsolnpoolsolns_join (CPXASYNCptr *handle_p, int *delstat)
{
   return CPX_CALL (delsetsolnpoolsolns_join) (handle_p, delstat);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXdelsetsos_async (CPXCENVptr env, CPXLPptr lp, CPXDIM *delset,
                        CPXASYNCptr *handle_p)
{
   return CPX_CALL (delsetsos_async) (env, lp, delset, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXdelsetsos_join (CPXASYNCptr *handle_p, CPXDIM *delset)
{
   return CPX_CALL (delsetsos_join) (handle_p, delset);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXdelsolnpoolfilters_async (CPXCENVptr env, CPXLPptr lp,
                                 int begin, int end,
                                 CPXASYNCptr *handle_p)
{
   return CPX_CALL (delsolnpoolfilters_async) (env, lp, begin, end, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXdelsolnpoolfilters_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (delsolnpoolfilters_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXdelsolnpoolfilters_multicast (CPXENVGROUPptr group, int begin,
                                     int end)
{
   return CPX_CALL (delsolnpoolfilters_multicast) (group, begin, end);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXdelsolnpoolsolns_async (CPXCENVptr env, CPXLPptr lp, int begin,
                               int end, CPXASYNCptr *handle_p)
{
   return CPX_CALL (delsolnpoolsolns_async) (env, lp, begin, end, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXdelsolnpoolsolns_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (delsolnpoolsolns_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXdelsolnpoolsolns_multicast (CPXENVGROUPptr group, int begin,
                                   int end)
{
   return CPX_CALL (delsolnpoolsolns_multicast) (group, begin, end);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXdelsos_async (CPXCENVptr env, CPXLPptr lp, CPXDIM begin,
                     CPXDIM end, CPXASYNCptr *handle_p)
{
   return CPX_CALL (delsos_async) (env, lp, begin, end, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXdelsos_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (delsos_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXdelsos_multicast (CPXENVGROUPptr group, CPXDIM begin,
                         CPXDIM end)
{
   return CPX_CALL (delsos_multicast) (group, begin, end);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXdjfrompi_async (CPXCENVptr env, CPXCLPptr lp, double const *pi,
                       CPXASYNCptr *handle_p)
{
   return CPX_CALL (djfrompi_async) (env, lp, pi, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXdjfrompi_join (CPXASYNCptr *handle_p, double *dj)
{
   return CPX_CALL (djfrompi_join) (handle_p, dj);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXdperwrite_async (CPXCENVptr env, CPXLPptr lp,
                        char const *filename_str, double epsilon,
                        CPXASYNCptr *handle_p)
{
   return CPX_CALL (dperwrite_async) (env, lp, filename_str, epsilon, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXdperwrite_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (dperwrite_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXdperwrite_multicast (CPXENVGROUPptr group,
                            char const *filename_str, double epsilon)
{
   return CPX_CALL (dperwrite_multicast) (group, filename_str, epsilon);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXdratio_async (CPXCENVptr env, CPXLPptr lp, CPXDIM *indices,
                     CPXDIM cnt, CPXASYNCptr *handle_p)
{
   return CPX_CALL (dratio_async) (env, lp, indices, cnt, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXdratio_join (CPXASYNCptr *handle_p, CPXDIM *indices,
                    double *downratio, double *upratio,
                    CPXDIM *downenter, CPXDIM *upenter,
                    int *downstatus, int *upstatus)
{
   return CPX_CALL (dratio_join) (handle_p, indices, downratio, upratio, downenter, upenter, downstatus, upstatus);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXdualfarkas_async (CPXCENVptr env, CPXCLPptr lp,
                         CPXASYNCptr *handle_p)
{
   return CPX_CALL (dualfarkas_async) (env, lp, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXdualfarkas_join (CPXASYNCptr *handle_p, double *y,
                        double *proof_p)
{
   return CPX_CALL (dualfarkas_join) (handle_p, y, proof_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXdualopt_async (CPXCENVptr env, CPXLPptr lp,
                      CPXASYNCptr *handle_p)
{
   return CPX_CALL (dualopt_async) (env, lp, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXdualopt_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (dualopt_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXdualopt_multicast (CPXENVGROUPptr group)
{
   return CPX_CALL (dualopt_multicast) (group);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXdualwrite_async (CPXCENVptr env, CPXCLPptr lp,
                        char const *filename_str,
                        CPXASYNCptr *handle_p)
{
   return CPX_CALL (dualwrite_async) (env, lp, filename_str, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXdualwrite_join (CPXASYNCptr *handle_p, double *objshift_p)
{
   return CPX_CALL (dualwrite_join) (handle_p, objshift_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXEgetsolnpoolfilter_async (CPXCENVptr env, CPXCLPptr lp,
                                 CPXDIM space, int which,
                                 CPXASYNCptr *handle_p)
{
   return CPX_CALL (Egetsolnpoolfilter_async) (env, lp, space, which, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXEgetsolnpoolfilter_join (CPXASYNCptr *handle_p, int *ftype_p,
                                double *lowercutoff_p,
                                double *upper_cutoff_p,
                                CPXDIM *nzcnt_p, CPXDIM *ind,
                                double *val, double *refval,
                                CPXDIM *surplus_p)
{
   return CPX_CALL (Egetsolnpoolfilter_join) (handle_p, ftype_p, lowercutoff_p, upper_cutoff_p, nzcnt_p, ind, val, refval, surplus_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXembwrite_async (CPXCENVptr env, CPXLPptr lp,
                       char const *filename_str, CPXASYNCptr *handle_p)
{
   return CPX_CALL (embwrite_async) (env, lp, filename_str, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXembwrite_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (embwrite_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXembwrite_multicast (CPXENVGROUPptr group,
                           char const *filename_str)
{
   return CPX_CALL (embwrite_multicast) (group, filename_str);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXenvgroupstatus (CPXCENVGROUPptr group, int idx)
{
   return CPX_CALL (envgroupstatus) (group, idx);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXfeasopt_async (CPXCENVptr env, CPXLPptr lp, double const *rhs,
                      double const *rng, double const *lb,
                      double const *ub, CPXASYNCptr *handle_p)
{
   return CPX_CALL (feasopt_async) (env, lp, rhs, rng, lb, ub, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXfeasopt_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (feasopt_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXfeasoptext_async (CPXCENVptr env, CPXLPptr lp, CPXDIM grpcnt,
                         CPXNNZ concnt, double const *grppref,
                         CPXNNZ const *grpbeg, CPXDIM const *grpind,
                         char const *grptype, CPXASYNCptr *handle_p)
{
   return CPX_CALL (feasoptext_async) (env, lp, grpcnt, concnt, grppref, grpbeg, grpind, grptype, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXfeasoptext_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (feasoptext_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXfeasoptext_multicast (CPXENVGROUPptr group, CPXDIM grpcnt,
                             CPXNNZ concnt, double const *grppref,
                             CPXNNZ const *grpbeg,
                             CPXDIM const *grpind, char const *grptype)
{
   return CPX_CALL (feasoptext_multicast) (group, grpcnt, concnt, grppref, grpbeg, grpind, grptype);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXfltwrite_async (CPXCENVptr env, CPXCLPptr lp,
                       char const *filename_str, CPXASYNCptr *handle_p)
{
   return CPX_CALL (fltwrite_async) (env, lp, filename_str, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXfltwrite_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (fltwrite_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXfltwrite_multicast (CPXENVGROUPptr group,
                           char const *filename_str)
{
   return CPX_CALL (fltwrite_multicast) (group, filename_str);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
void CPXPUBLIC
   CPXXfreeenvgroup (CPXENVGROUPptr *group_p)
{
CPX_CALL (freeenvgroup) (group_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXfreelazyconstraints_async (CPXCENVptr env, CPXLPptr lp,
                                  CPXASYNCptr *handle_p)
{
   return CPX_CALL (freelazyconstraints_async) (env, lp, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXfreelazyconstraints_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (freelazyconstraints_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXfreelazyconstraints_multicast (CPXENVGROUPptr group)
{
   return CPX_CALL (freelazyconstraints_multicast) (group);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXfreepresolve_async (CPXCENVptr env, CPXLPptr lp,
                           CPXASYNCptr *handle_p)
{
   return CPX_CALL (freepresolve_async) (env, lp, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXfreepresolve_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (freepresolve_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXfreepresolve_multicast (CPXENVGROUPptr group)
{
   return CPX_CALL (freepresolve_multicast) (group);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXfreeusercuts_async (CPXCENVptr env, CPXLPptr lp,
                           CPXASYNCptr *handle_p)
{
   return CPX_CALL (freeusercuts_async) (env, lp, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXfreeusercuts_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (freeusercuts_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXfreeusercuts_multicast (CPXENVGROUPptr group)
{
   return CPX_CALL (freeusercuts_multicast) (group);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXftran_async (CPXCENVptr env, CPXCLPptr lp, double *x,
                    CPXASYNCptr *handle_p)
{
   return CPX_CALL (ftran_async) (env, lp, x, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXftran_join (CPXASYNCptr *handle_p, double *x)
{
   return CPX_CALL (ftran_join) (handle_p, x);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetasynchandlesize (CPXCASYNCptr asynchandle)
{
   return CPX_CALL (getasynchandlesize) (asynchandle);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
void const * CPXPUBLIC
   CPXXgetasynctab (void)
{
   return CPX_CALL (getasynctab) ();
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetax_async (CPXCENVptr env, CPXCLPptr lp, CPXDIM begin,
                    CPXDIM end, CPXASYNCptr *handle_p)
{
   return CPX_CALL (getax_async) (env, lp, begin, end, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetax_join (CPXASYNCptr *handle_p, double *x)
{
   return CPX_CALL (getax_join) (handle_p, x);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetbase_async (CPXCENVptr env, CPXCLPptr lp,
                      CPXASYNCptr *handle_p)
{
   return CPX_CALL (getbase_async) (env, lp, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetbase_join (CPXASYNCptr *handle_p, int *cstat, int *rstat)
{
   return CPX_CALL (getbase_join) (handle_p, cstat, rstat);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetbasednorms_async (CPXCENVptr env, CPXCLPptr lp,
                            CPXASYNCptr *handle_p)
{
   return CPX_CALL (getbasednorms_async) (env, lp, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetbasednorms_join (CPXASYNCptr *handle_p, int *cstat,
                           int *rstat, double *dnorm)
{
   return CPX_CALL (getbasednorms_join) (handle_p, cstat, rstat, dnorm);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetbestobjval_async (CPXCENVptr env, CPXCLPptr lp,
                            CPXASYNCptr *handle_p)
{
   return CPX_CALL (getbestobjval_async) (env, lp, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetbestobjval_join (CPXASYNCptr *handle_p, double *objval_p)
{
   return CPX_CALL (getbestobjval_join) (handle_p, objval_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetbhead_async (CPXCENVptr env, CPXCLPptr lp,
                       CPXASYNCptr *handle_p)
{
   return CPX_CALL (getbhead_async) (env, lp, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetbhead_join (CPXASYNCptr *handle_p, CPXDIM *head, double *x)
{
   return CPX_CALL (getbhead_join) (handle_p, head, x);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetchgparam_async (CPXCENVptr env, int pspace,
                          CPXASYNCptr *handle_p)
{
   return CPX_CALL (getchgparam_async) (env, pspace, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetchgparam_join (CPXASYNCptr *handle_p, int *cnt_p,
                         int *paramnum, int *surplus_p)
{
   return CPX_CALL (getchgparam_join) (handle_p, cnt_p, paramnum, surplus_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetcoef_async (CPXCENVptr env, CPXCLPptr lp, CPXDIM i, CPXDIM j,
                      CPXASYNCptr *handle_p)
{
   return CPX_CALL (getcoef_async) (env, lp, i, j, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetcoef_join (CPXASYNCptr *handle_p, double *coef_p)
{
   return CPX_CALL (getcoef_join) (handle_p, coef_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetcolindex_async (CPXCENVptr env, CPXCLPptr lp,
                          char const *lname_str, CPXASYNCptr *handle_p)
{
   return CPX_CALL (getcolindex_async) (env, lp, lname_str, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetcolindex_join (CPXASYNCptr *handle_p, CPXDIM *index_p)
{
   return CPX_CALL (getcolindex_join) (handle_p, index_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetcolinfeas_async (CPXCENVptr env, CPXCLPptr lp,
                           double const *x, CPXDIM begin, CPXDIM end,
                           CPXASYNCptr *handle_p)
{
   return CPX_CALL (getcolinfeas_async) (env, lp, x, begin, end, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetcolinfeas_join (CPXASYNCptr *handle_p, double *infeasout)
{
   return CPX_CALL (getcolinfeas_join) (handle_p, infeasout);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetcolname_async (CPXCENVptr env, CPXCLPptr lp,
                         CPXSIZE storespace, CPXDIM begin, CPXDIM end,
                         CPXASYNCptr *handle_p)
{
   return CPX_CALL (getcolname_async) (env, lp, storespace, begin, end, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetcolname_join (CPXASYNCptr *handle_p, char  **name,
                        char *namestore, CPXSIZE *surplus_p)
{
   return CPX_CALL (getcolname_join) (handle_p, name, namestore, surplus_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetcols_async (CPXCENVptr env, CPXCLPptr lp, CPXNNZ cmatspace,
                      CPXDIM begin, CPXDIM end, CPXASYNCptr *handle_p)
{
   return CPX_CALL (getcols_async) (env, lp, cmatspace, begin, end, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetcols_join (CPXASYNCptr *handle_p, CPXNNZ *nzcnt_p,
                     CPXNNZ *cmatbeg, CPXDIM *cmatind, double *cmatval,
                     CPXNNZ *surplus_p)
{
   return CPX_CALL (getcols_join) (handle_p, nzcnt_p, cmatbeg, cmatind, cmatval, surplus_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetconflictext_async (CPXCENVptr env, CPXCLPptr lp, CPXNNZ beg,
                             CPXNNZ end, CPXASYNCptr *handle_p)
{
   return CPX_CALL (getconflictext_async) (env, lp, beg, end, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetconflictext_join (CPXASYNCptr *handle_p, int *grpstat)
{
   return CPX_CALL (getconflictext_join) (handle_p, grpstat);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetctype_async (CPXCENVptr env, CPXCLPptr lp, CPXDIM begin,
                       CPXDIM end, CPXASYNCptr *handle_p)
{
   return CPX_CALL (getctype_async) (env, lp, begin, end, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetctype_join (CPXASYNCptr *handle_p, char *xctype)
{
   return CPX_CALL (getctype_join) (handle_p, xctype);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetcutoff_async (CPXCENVptr env, CPXCLPptr lp,
                        CPXASYNCptr *handle_p)
{
   return CPX_CALL (getcutoff_async) (env, lp, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetcutoff_join (CPXASYNCptr *handle_p, double *cutoff_p)
{
   return CPX_CALL (getcutoff_join) (handle_p, cutoff_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetdblparam_async (CPXCENVptr env, int whichparam,
                          CPXASYNCptr *handle_p)
{
   return CPX_CALL (getdblparam_async) (env, whichparam, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetdblparam_join (CPXASYNCptr *handle_p, double *value_p)
{
   return CPX_CALL (getdblparam_join) (handle_p, value_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetdblquality_async (CPXCENVptr env, CPXCLPptr lp, int what,
                            CPXASYNCptr *handle_p)
{
   return CPX_CALL (getdblquality_async) (env, lp, what, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetdblquality_join (CPXASYNCptr *handle_p, double *quality_p)
{
   return CPX_CALL (getdblquality_join) (handle_p, quality_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetdettime_async (CPXCENVptr env, CPXASYNCptr *handle_p)
{
   return CPX_CALL (getdettime_async) (env, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetdettime_join (CPXASYNCptr *handle_p, double *dettimestamp_p)
{
   return CPX_CALL (getdettime_join) (handle_p, dettimestamp_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetdj_async (CPXCENVptr env, CPXCLPptr lp, CPXDIM begin,
                    CPXDIM end, CPXASYNCptr *handle_p)
{
   return CPX_CALL (getdj_async) (env, lp, begin, end, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetdj_join (CPXASYNCptr *handle_p, double *dj)
{
   return CPX_CALL (getdj_join) (handle_p, dj);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetdnorms_async (CPXCENVptr env, CPXCLPptr lp,
                        CPXASYNCptr *handle_p)
{
   return CPX_CALL (getdnorms_async) (env, lp, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetdnorms_join (CPXASYNCptr *handle_p, double *norm,
                       CPXDIM *head, CPXDIM *len_p)
{
   return CPX_CALL (getdnorms_join) (handle_p, norm, head, len_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
CPXENVptr CPXPUBLIC
   CPXXgetenvgroupenv (CPXCENVGROUPptr group, int idx)
{
   return CPX_CALL (getenvgroupenv) (group, idx);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetenvgroupsize (CPXCENVGROUPptr group)
{
   return CPX_CALL (getenvgroupsize) (group);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetgrad_async (CPXCENVptr env, CPXCLPptr lp, CPXDIM j,
                      CPXASYNCptr *handle_p)
{
   return CPX_CALL (getgrad_async) (env, lp, j, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetgrad_join (CPXASYNCptr *handle_p, CPXDIM *head, double *y)
{
   return CPX_CALL (getgrad_join) (handle_p, head, y);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetijdiv_async (CPXCENVptr env, CPXCLPptr lp,
                       CPXASYNCptr *handle_p)
{
   return CPX_CALL (getijdiv_async) (env, lp, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetijdiv_join (CPXASYNCptr *handle_p, CPXDIM *idiv_p,
                      CPXDIM *jdiv_p)
{
   return CPX_CALL (getijdiv_join) (handle_p, idiv_p, jdiv_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetijrow_async (CPXCENVptr env, CPXCLPptr lp, CPXDIM i,
                       CPXDIM j, CPXASYNCptr *handle_p)
{
   return CPX_CALL (getijrow_async) (env, lp, i, j, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetijrow_join (CPXASYNCptr *handle_p, CPXDIM *row_p)
{
   return CPX_CALL (getijrow_join) (handle_p, row_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetindconstr_async (CPXCENVptr env, CPXCLPptr lp, CPXDIM space,
                           CPXDIM which, CPXASYNCptr *handle_p)
{
   return CPX_CALL (getindconstr_async) (env, lp, space, which, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetindconstr_join (CPXASYNCptr *handle_p, CPXDIM *indvar_p,
                          int *complemented_p, CPXDIM *nzcnt_p,
                          double *rhs_p, char *sense_p, CPXDIM *linind,
                          double *linval, CPXDIM *surplus_p)
{
   return CPX_CALL (getindconstr_join) (handle_p, indvar_p, complemented_p, nzcnt_p, rhs_p, sense_p, linind, linval, surplus_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetindconstrindex_async (CPXCENVptr env, CPXCLPptr lp,
                                char const *lname_str,
                                CPXASYNCptr *handle_p)
{
   return CPX_CALL (getindconstrindex_async) (env, lp, lname_str, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetindconstrindex_join (CPXASYNCptr *handle_p, CPXDIM *index_p)
{
   return CPX_CALL (getindconstrindex_join) (handle_p, index_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetindconstrinfeas_async (CPXCENVptr env, CPXCLPptr lp,
                                 double const *x, CPXDIM begin,
                                 CPXDIM end, CPXASYNCptr *handle_p)
{
   return CPX_CALL (getindconstrinfeas_async) (env, lp, x, begin, end, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetindconstrinfeas_join (CPXASYNCptr *handle_p,
                                double *infeasout)
{
   return CPX_CALL (getindconstrinfeas_join) (handle_p, infeasout);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetindconstrname_async (CPXCENVptr env, CPXCLPptr lp,
                               CPXSIZE bufspace, CPXDIM which,
                               CPXASYNCptr *handle_p)
{
   return CPX_CALL (getindconstrname_async) (env, lp, bufspace, which, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetindconstrname_join (CPXASYNCptr *handle_p, char *buf_str,
                              CPXSIZE *surplus_p)
{
   return CPX_CALL (getindconstrname_join) (handle_p, buf_str, surplus_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetindconstrslack_async (CPXCENVptr env, CPXCLPptr lp,
                                CPXDIM begin, CPXDIM end,
                                CPXASYNCptr *handle_p)
{
   return CPX_CALL (getindconstrslack_async) (env, lp, begin, end, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetindconstrslack_join (CPXASYNCptr *handle_p, double *indslack)
{
   return CPX_CALL (getindconstrslack_join) (handle_p, indslack);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetinfohandler (CPXCENVptr env, CPXINFOHANDLER  **infohandler_p,
                       void  **handle_p)
{
   return CPX_CALL (getinfohandler) (env, infohandler_p, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetintparam_async (CPXCENVptr env, int whichparam,
                          CPXASYNCptr *handle_p)
{
   return CPX_CALL (getintparam_async) (env, whichparam, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetintparam_join (CPXASYNCptr *handle_p, CPXINT *value_p)
{
   return CPX_CALL (getintparam_join) (handle_p, value_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetintquality_async (CPXCENVptr env, CPXCLPptr lp, int what,
                            CPXASYNCptr *handle_p)
{
   return CPX_CALL (getintquality_async) (env, lp, what, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetintquality_join (CPXASYNCptr *handle_p, CPXDIM *quality_p)
{
   return CPX_CALL (getintquality_join) (handle_p, quality_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetlb_async (CPXCENVptr env, CPXCLPptr lp, CPXDIM begin,
                    CPXDIM end, CPXASYNCptr *handle_p)
{
   return CPX_CALL (getlb_async) (env, lp, begin, end, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetlb_join (CPXASYNCptr *handle_p, double *lb)
{
   return CPX_CALL (getlb_join) (handle_p, lb);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetlongparam_async (CPXCENVptr env, int whichparam,
                           CPXASYNCptr *handle_p)
{
   return CPX_CALL (getlongparam_async) (env, whichparam, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetlongparam_join (CPXASYNCptr *handle_p, CPXLONG *value_p)
{
   return CPX_CALL (getlongparam_join) (handle_p, value_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetlps (CPXCENVptr env, int capacity, CPXLPptr *lps,
               int *count_p, int *total_p)
{
   return CPX_CALL (getlps) (env, capacity, lps, count_p, total_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetmiprelgap_async (CPXCENVptr env, CPXCLPptr lp,
                           CPXASYNCptr *handle_p)
{
   return CPX_CALL (getmiprelgap_async) (env, lp, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetmiprelgap_join (CPXASYNCptr *handle_p, double *gap_p)
{
   return CPX_CALL (getmiprelgap_join) (handle_p, gap_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetmipstartindex_async (CPXCENVptr env, CPXCLPptr lp,
                               char const *lname_str,
                               CPXASYNCptr *handle_p)
{
   return CPX_CALL (getmipstartindex_async) (env, lp, lname_str, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetmipstartindex_join (CPXASYNCptr *handle_p, int *index_p)
{
   return CPX_CALL (getmipstartindex_join) (handle_p, index_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetmipstartname_async (CPXCENVptr env, CPXCLPptr lp,
                              CPXSIZE storesz, int begin, int end,
                              CPXASYNCptr *handle_p)
{
   return CPX_CALL (getmipstartname_async) (env, lp, storesz, begin, end, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetmipstartname_join (CPXASYNCptr *handle_p, char  **name,
                             char *store, CPXSIZE *surplus_p)
{
   return CPX_CALL (getmipstartname_join) (handle_p, name, store, surplus_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetmipstarts_async (CPXCENVptr env, CPXCLPptr lp,
                           CPXNNZ startspace, int begin, int end,
                           CPXASYNCptr *handle_p)
{
   return CPX_CALL (getmipstarts_async) (env, lp, startspace, begin, end, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetmipstarts_join (CPXASYNCptr *handle_p, CPXNNZ *nzcnt_p,
                          CPXNNZ *beg, CPXDIM *varindices,
                          double *values, int *effortlevel,
                          CPXNNZ *surplus_p)
{
   return CPX_CALL (getmipstarts_join) (handle_p, nzcnt_p, beg, varindices, values, effortlevel, surplus_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetnumcores_async (CPXCENVptr env, CPXASYNCptr *handle_p)
{
   return CPX_CALL (getnumcores_async) (env, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetnumcores_join (CPXASYNCptr *handle_p, int *numcores_p)
{
   return CPX_CALL (getnumcores_join) (handle_p, numcores_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetnumcuts_async (CPXCENVptr env, CPXCLPptr lp, int cuttype,
                         CPXASYNCptr *handle_p)
{
   return CPX_CALL (getnumcuts_async) (env, lp, cuttype, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetnumcuts_join (CPXASYNCptr *handle_p, CPXDIM *num_p)
{
   return CPX_CALL (getnumcuts_join) (handle_p, num_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetobj_async (CPXCENVptr env, CPXCLPptr lp, CPXDIM begin,
                     CPXDIM end, CPXASYNCptr *handle_p)
{
   return CPX_CALL (getobj_async) (env, lp, begin, end, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetobj_join (CPXASYNCptr *handle_p, double *obj)
{
   return CPX_CALL (getobj_join) (handle_p, obj);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetobjname_async (CPXCENVptr env, CPXCLPptr lp,
                         CPXSIZE bufspace, CPXASYNCptr *handle_p)
{
   return CPX_CALL (getobjname_async) (env, lp, bufspace, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetobjname_join (CPXASYNCptr *handle_p, char *buf_str,
                        CPXSIZE *surplus_p)
{
   return CPX_CALL (getobjname_join) (handle_p, buf_str, surplus_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetobjoffset_async (CPXCENVptr env, CPXCLPptr lp,
                           CPXASYNCptr *handle_p)
{
   return CPX_CALL (getobjoffset_async) (env, lp, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetobjoffset_join (CPXASYNCptr *handle_p, double *objoffset_p)
{
   return CPX_CALL (getobjoffset_join) (handle_p, objoffset_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetobjval_async (CPXCENVptr env, CPXCLPptr lp,
                        CPXASYNCptr *handle_p)
{
   return CPX_CALL (getobjval_async) (env, lp, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetobjval_join (CPXASYNCptr *handle_p, double *objval_p)
{
   return CPX_CALL (getobjval_join) (handle_p, objval_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetorder_async (CPXCENVptr env, CPXCLPptr lp, CPXDIM ordspace,
                       CPXASYNCptr *handle_p)
{
   return CPX_CALL (getorder_async) (env, lp, ordspace, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetorder_join (CPXASYNCptr *handle_p, CPXDIM *cnt_p,
                      CPXDIM *indices, CPXDIM *priority,
                      int *direction, CPXDIM *surplus_p)
{
   return CPX_CALL (getorder_join) (handle_p, cnt_p, indices, priority, direction, surplus_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetparamname_async (CPXCENVptr env, int whichparam,
                           CPXASYNCptr *handle_p)
{
   return CPX_CALL (getparamname_async) (env, whichparam, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetparamname_join (CPXASYNCptr *handle_p, char *name_str)
{
   return CPX_CALL (getparamname_join) (handle_p, name_str);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetparamnum_async (CPXCENVptr env, char const *name_str,
                          CPXASYNCptr *handle_p)
{
   return CPX_CALL (getparamnum_async) (env, name_str, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetparamnum_join (CPXASYNCptr *handle_p, int *whichparam_p)
{
   return CPX_CALL (getparamnum_join) (handle_p, whichparam_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetparamtype_async (CPXCENVptr env, int whichparam,
                           CPXASYNCptr *handle_p)
{
   return CPX_CALL (getparamtype_async) (env, whichparam, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetparamtype_join (CPXASYNCptr *handle_p, int *paramtype)
{
   return CPX_CALL (getparamtype_join) (handle_p, paramtype);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetpi_async (CPXCENVptr env, CPXCLPptr lp, CPXDIM begin,
                    CPXDIM end, CPXASYNCptr *handle_p)
{
   return CPX_CALL (getpi_async) (env, lp, begin, end, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetpi_join (CPXASYNCptr *handle_p, double *pi)
{
   return CPX_CALL (getpi_join) (handle_p, pi);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetpnorms_async (CPXCENVptr env, CPXCLPptr lp,
                        CPXASYNCptr *handle_p)
{
   return CPX_CALL (getpnorms_async) (env, lp, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetpnorms_join (CPXASYNCptr *handle_p, double *cnorm,
                       double *rnorm, CPXDIM *len_p)
{
   return CPX_CALL (getpnorms_join) (handle_p, cnorm, rnorm, len_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetprestat_async (CPXCENVptr env, CPXCLPptr lp,
                         CPXASYNCptr *handle_p)
{
   return CPX_CALL (getprestat_async) (env, lp, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetprestat_join (CPXASYNCptr *handle_p, int *prestat_p,
                        CPXDIM *pcstat, CPXDIM *prstat, CPXDIM *ocstat,
                        CPXDIM *orstat)
{
   return CPX_CALL (getprestat_join) (handle_p, prestat_p, pcstat, prstat, ocstat, orstat);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetprobname_async (CPXCENVptr env, CPXCLPptr lp,
                          CPXSIZE bufspace, CPXASYNCptr *handle_p)
{
   return CPX_CALL (getprobname_async) (env, lp, bufspace, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetprobname_join (CPXASYNCptr *handle_p, char *buf_str,
                         CPXSIZE *surplus_p)
{
   return CPX_CALL (getprobname_join) (handle_p, buf_str, surplus_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetprotected_async (CPXCENVptr env, CPXCLPptr lp, CPXDIM pspace,
                           CPXASYNCptr *handle_p)
{
   return CPX_CALL (getprotected_async) (env, lp, pspace, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetprotected_join (CPXASYNCptr *handle_p, CPXDIM *cnt_p,
                          CPXDIM *indices, CPXDIM *surplus_p)
{
   return CPX_CALL (getprotected_join) (handle_p, cnt_p, indices, surplus_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetqconstr_async (CPXCENVptr env, CPXCLPptr lp, CPXDIM linspace,
                         CPXNNZ quadspace, CPXDIM which,
                         CPXASYNCptr *handle_p)
{
   return CPX_CALL (getqconstr_async) (env, lp, linspace, quadspace, which, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetqconstr_join (CPXASYNCptr *handle_p, CPXDIM *linnzcnt_p,
                        CPXNNZ *quadnzcnt_p, double *rhs_p,
                        char *sense_p, CPXDIM *linind, double *linval,
                        CPXDIM *linsurplus_p, CPXDIM *quadrow,
                        CPXDIM *quadcol, double *quadval,
                        CPXNNZ *quadsurplus_p)
{
   return CPX_CALL (getqconstr_join) (handle_p, linnzcnt_p, quadnzcnt_p, rhs_p, sense_p, linind, linval, linsurplus_p, quadrow, quadcol, quadval, quadsurplus_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetqconstrdslack_async (CPXCENVptr env, CPXCLPptr lp,
                               CPXDIM qind, int space,
                               CPXASYNCptr *handle_p)
{
   return CPX_CALL (getqconstrdslack_async) (env, lp, qind, space, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetqconstrdslack_join (CPXASYNCptr *handle_p, CPXDIM *nz_p,
                              CPXDIM *ind, double *val, int *surplus_p)
{
   return CPX_CALL (getqconstrdslack_join) (handle_p, nz_p, ind, val, surplus_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetqconstrindex_async (CPXCENVptr env, CPXCLPptr lp,
                              char const *lname_str,
                              CPXASYNCptr *handle_p)
{
   return CPX_CALL (getqconstrindex_async) (env, lp, lname_str, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetqconstrindex_join (CPXASYNCptr *handle_p, CPXDIM *index_p)
{
   return CPX_CALL (getqconstrindex_join) (handle_p, index_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetqconstrinfeas_async (CPXCENVptr env, CPXCLPptr lp,
                               double const *x, CPXDIM begin,
                               CPXDIM end, CPXASYNCptr *handle_p)
{
   return CPX_CALL (getqconstrinfeas_async) (env, lp, x, begin, end, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetqconstrinfeas_join (CPXASYNCptr *handle_p, double *infeasout)
{
   return CPX_CALL (getqconstrinfeas_join) (handle_p, infeasout);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetqconstrname_async (CPXCENVptr env, CPXCLPptr lp,
                             CPXSIZE bufspace, CPXDIM which,
                             CPXASYNCptr *handle_p)
{
   return CPX_CALL (getqconstrname_async) (env, lp, bufspace, which, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetqconstrname_join (CPXASYNCptr *handle_p, char *buf_str,
                            CPXSIZE *surplus_p)
{
   return CPX_CALL (getqconstrname_join) (handle_p, buf_str, surplus_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetqconstrslack_async (CPXCENVptr env, CPXCLPptr lp,
                              CPXDIM begin, CPXDIM end,
                              CPXASYNCptr *handle_p)
{
   return CPX_CALL (getqconstrslack_async) (env, lp, begin, end, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetqconstrslack_join (CPXASYNCptr *handle_p, double *qcslack)
{
   return CPX_CALL (getqconstrslack_join) (handle_p, qcslack);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetqpcoef_async (CPXCENVptr env, CPXCLPptr lp, CPXDIM rownum,
                        CPXDIM colnum, CPXASYNCptr *handle_p)
{
   return CPX_CALL (getqpcoef_async) (env, lp, rownum, colnum, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetqpcoef_join (CPXASYNCptr *handle_p, double *coef_p)
{
   return CPX_CALL (getqpcoef_join) (handle_p, coef_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetquad_async (CPXCENVptr env, CPXCLPptr lp, CPXNNZ qmatspace,
                      CPXDIM begin, CPXDIM end, CPXASYNCptr *handle_p)
{
   return CPX_CALL (getquad_async) (env, lp, qmatspace, begin, end, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetquad_join (CPXASYNCptr *handle_p, CPXNNZ *nzcnt_p,
                     CPXNNZ *qmatbeg, CPXDIM *qmatind, double *qmatval,
                     CPXNNZ *surplus_p)
{
   return CPX_CALL (getquad_join) (handle_p, nzcnt_p, qmatbeg, qmatind, qmatval, surplus_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetray_async (CPXCENVptr env, CPXCLPptr lp,
                     CPXASYNCptr *handle_p)
{
   return CPX_CALL (getray_async) (env, lp, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetray_join (CPXASYNCptr *handle_p, double *z)
{
   return CPX_CALL (getray_join) (handle_p, z);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetreconnectinfolen (CPXCENVptr env)
{
   return CPX_CALL (getreconnectinfolen) (env);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetrhs_async (CPXCENVptr env, CPXCLPptr lp, CPXDIM begin,
                     CPXDIM end, CPXASYNCptr *handle_p)
{
   return CPX_CALL (getrhs_async) (env, lp, begin, end, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetrhs_join (CPXASYNCptr *handle_p, double *rhs)
{
   return CPX_CALL (getrhs_join) (handle_p, rhs);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetrngval_async (CPXCENVptr env, CPXCLPptr lp, CPXDIM begin,
                        CPXDIM end, CPXASYNCptr *handle_p)
{
   return CPX_CALL (getrngval_async) (env, lp, begin, end, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetrngval_join (CPXASYNCptr *handle_p, double *rngval)
{
   return CPX_CALL (getrngval_join) (handle_p, rngval);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetrowindex_async (CPXCENVptr env, CPXCLPptr lp,
                          char const *lname_str, CPXASYNCptr *handle_p)
{
   return CPX_CALL (getrowindex_async) (env, lp, lname_str, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetrowindex_join (CPXASYNCptr *handle_p, CPXDIM *index_p)
{
   return CPX_CALL (getrowindex_join) (handle_p, index_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetrowinfeas_async (CPXCENVptr env, CPXCLPptr lp,
                           double const *x, CPXDIM begin, CPXDIM end,
                           CPXASYNCptr *handle_p)
{
   return CPX_CALL (getrowinfeas_async) (env, lp, x, begin, end, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetrowinfeas_join (CPXASYNCptr *handle_p, double *infeasout)
{
   return CPX_CALL (getrowinfeas_join) (handle_p, infeasout);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetrowname_async (CPXCENVptr env, CPXCLPptr lp,
                         CPXSIZE storespace, CPXDIM begin, CPXDIM end,
                         CPXASYNCptr *handle_p)
{
   return CPX_CALL (getrowname_async) (env, lp, storespace, begin, end, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetrowname_join (CPXASYNCptr *handle_p, char  **name,
                        char *namestore, CPXSIZE *surplus_p)
{
   return CPX_CALL (getrowname_join) (handle_p, name, namestore, surplus_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetrows_async (CPXCENVptr env, CPXCLPptr lp, CPXNNZ rmatspace,
                      CPXDIM begin, CPXDIM end, CPXASYNCptr *handle_p)
{
   return CPX_CALL (getrows_async) (env, lp, rmatspace, begin, end, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetrows_join (CPXASYNCptr *handle_p, CPXNNZ *nzcnt_p,
                     CPXNNZ *rmatbeg, CPXDIM *rmatind, double *rmatval,
                     CPXNNZ *surplus_p)
{
   return CPX_CALL (getrows_join) (handle_p, nzcnt_p, rmatbeg, rmatind, rmatval, surplus_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetsense_async (CPXCENVptr env, CPXCLPptr lp, CPXDIM begin,
                       CPXDIM end, CPXASYNCptr *handle_p)
{
   return CPX_CALL (getsense_async) (env, lp, begin, end, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetsense_join (CPXASYNCptr *handle_p, char *sense)
{
   return CPX_CALL (getsense_join) (handle_p, sense);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetslack_async (CPXCENVptr env, CPXCLPptr lp, CPXDIM begin,
                       CPXDIM end, CPXASYNCptr *handle_p)
{
   return CPX_CALL (getslack_async) (env, lp, begin, end, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetslack_join (CPXASYNCptr *handle_p, double *slack)
{
   return CPX_CALL (getslack_join) (handle_p, slack);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetsolnpooldblquality_async (CPXCENVptr env, CPXCLPptr lp,
                                    int soln, int what,
                                    CPXASYNCptr *handle_p)
{
   return CPX_CALL (getsolnpooldblquality_async) (env, lp, soln, what, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetsolnpooldblquality_join (CPXASYNCptr *handle_p,
                                   double *quality_p)
{
   return CPX_CALL (getsolnpooldblquality_join) (handle_p, quality_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetsolnpooldivfilter_async (CPXCENVptr env, CPXCLPptr lp,
                                   CPXDIM space, int which,
                                   CPXASYNCptr *handle_p)
{
   return CPX_CALL (getsolnpooldivfilter_async) (env, lp, space, which, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetsolnpooldivfilter_join (CPXASYNCptr *handle_p,
                                  double *lower_cutoff_p,
                                  double *upper_cutoff_p,
                                  CPXDIM *nzcnt_p, CPXDIM *ind,
                                  double *val, double *refval,
                                  CPXDIM *surplus_p)
{
   return CPX_CALL (getsolnpooldivfilter_join) (handle_p, lower_cutoff_p, upper_cutoff_p, nzcnt_p, ind, val, refval, surplus_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetsolnpoolfilterindex_async (CPXCENVptr env, CPXCLPptr lp,
                                     char const *lname_str,
                                     CPXASYNCptr *handle_p)
{
   return CPX_CALL (getsolnpoolfilterindex_async) (env, lp, lname_str, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetsolnpoolfilterindex_join (CPXASYNCptr *handle_p,
                                    int *index_p)
{
   return CPX_CALL (getsolnpoolfilterindex_join) (handle_p, index_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetsolnpoolfiltername_async (CPXCENVptr env, CPXCLPptr lp,
                                    CPXSIZE bufspace, int which,
                                    CPXASYNCptr *handle_p)
{
   return CPX_CALL (getsolnpoolfiltername_async) (env, lp, bufspace, which, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetsolnpoolfiltername_join (CPXASYNCptr *handle_p,
                                   char *buf_str, CPXSIZE *surplus_p)
{
   return CPX_CALL (getsolnpoolfiltername_join) (handle_p, buf_str, surplus_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetsolnpoolfiltertype_async (CPXCENVptr env, CPXCLPptr lp,
                                    int which, CPXASYNCptr *handle_p)
{
   return CPX_CALL (getsolnpoolfiltertype_async) (env, lp, which, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetsolnpoolfiltertype_join (CPXASYNCptr *handle_p, int *ftype_p)
{
   return CPX_CALL (getsolnpoolfiltertype_join) (handle_p, ftype_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetsolnpoolintquality_async (CPXCENVptr env, CPXCLPptr lp,
                                    int soln, int what,
                                    CPXASYNCptr *handle_p)
{
   return CPX_CALL (getsolnpoolintquality_async) (env, lp, soln, what, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetsolnpoolintquality_join (CPXASYNCptr *handle_p,
                                   CPXDIM *quality_p)
{
   return CPX_CALL (getsolnpoolintquality_join) (handle_p, quality_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetsolnpoolmeanobjval_async (CPXCENVptr env, CPXCLPptr lp,
                                    CPXASYNCptr *handle_p)
{
   return CPX_CALL (getsolnpoolmeanobjval_async) (env, lp, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetsolnpoolmeanobjval_join (CPXASYNCptr *handle_p,
                                   double *meanobjval_p)
{
   return CPX_CALL (getsolnpoolmeanobjval_join) (handle_p, meanobjval_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetsolnpoolobjval_async (CPXCENVptr env, CPXCLPptr lp, int soln,
                                CPXASYNCptr *handle_p)
{
   return CPX_CALL (getsolnpoolobjval_async) (env, lp, soln, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetsolnpoolobjval_join (CPXASYNCptr *handle_p, double *objval_p)
{
   return CPX_CALL (getsolnpoolobjval_join) (handle_p, objval_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetsolnpoolqconstrslack_async (CPXCENVptr env, CPXCLPptr lp,
                                      int soln, CPXDIM begin,
                                      CPXDIM end,
                                      CPXASYNCptr *handle_p)
{
   return CPX_CALL (getsolnpoolqconstrslack_async) (env, lp, soln, begin, end, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetsolnpoolqconstrslack_join (CPXASYNCptr *handle_p,
                                     double *qcslack)
{
   return CPX_CALL (getsolnpoolqconstrslack_join) (handle_p, qcslack);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetsolnpoolrngfilter_async (CPXCENVptr env, CPXCLPptr lp,
                                   CPXDIM space, int which,
                                   CPXASYNCptr *handle_p)
{
   return CPX_CALL (getsolnpoolrngfilter_async) (env, lp, space, which, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetsolnpoolrngfilter_join (CPXASYNCptr *handle_p, double *lb_p,
                                  double *ub_p, CPXDIM *nzcnt_p,
                                  CPXDIM *ind, double *val,
                                  CPXDIM *surplus_p)
{
   return CPX_CALL (getsolnpoolrngfilter_join) (handle_p, lb_p, ub_p, nzcnt_p, ind, val, surplus_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetsolnpoolslack_async (CPXCENVptr env, CPXCLPptr lp, int soln,
                               CPXDIM begin, CPXDIM end,
                               CPXASYNCptr *handle_p)
{
   return CPX_CALL (getsolnpoolslack_async) (env, lp, soln, begin, end, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetsolnpoolslack_join (CPXASYNCptr *handle_p, double *slack)
{
   return CPX_CALL (getsolnpoolslack_join) (handle_p, slack);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetsolnpoolsolnindex_async (CPXCENVptr env, CPXCLPptr lp,
                                   char const *lname_str,
                                   CPXASYNCptr *handle_p)
{
   return CPX_CALL (getsolnpoolsolnindex_async) (env, lp, lname_str, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetsolnpoolsolnindex_join (CPXASYNCptr *handle_p, int *index_p)
{
   return CPX_CALL (getsolnpoolsolnindex_join) (handle_p, index_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetsolnpoolsolnname_async (CPXCENVptr env, CPXCLPptr lp,
                                  CPXSIZE storesz, int which,
                                  CPXASYNCptr *handle_p)
{
   return CPX_CALL (getsolnpoolsolnname_async) (env, lp, storesz, which, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetsolnpoolsolnname_join (CPXASYNCptr *handle_p, char *store,
                                 CPXSIZE *surplus_p)
{
   return CPX_CALL (getsolnpoolsolnname_join) (handle_p, store, surplus_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetsolnpoolx_async (CPXCENVptr env, CPXCLPptr lp, int soln,
                           CPXDIM begin, CPXDIM end,
                           CPXASYNCptr *handle_p)
{
   return CPX_CALL (getsolnpoolx_async) (env, lp, soln, begin, end, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetsolnpoolx_join (CPXASYNCptr *handle_p, double *x)
{
   return CPX_CALL (getsolnpoolx_join) (handle_p, x);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetsos_async (CPXCENVptr env, CPXCLPptr lp, CPXNNZ sosspace,
                     CPXDIM begin, CPXDIM end, CPXASYNCptr *handle_p)
{
   return CPX_CALL (getsos_async) (env, lp, sosspace, begin, end, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetsos_join (CPXASYNCptr *handle_p, CPXNNZ *numsosnz_p,
                    char *sostype, CPXNNZ *sosbeg, CPXDIM *sosind,
                    double *soswt, CPXNNZ *surplus_p)
{
   return CPX_CALL (getsos_join) (handle_p, numsosnz_p, sostype, sosbeg, sosind, soswt, surplus_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetsosindex_async (CPXCENVptr env, CPXCLPptr lp,
                          char const *lname_str, CPXASYNCptr *handle_p)
{
   return CPX_CALL (getsosindex_async) (env, lp, lname_str, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetsosindex_join (CPXASYNCptr *handle_p, CPXDIM *index_p)
{
   return CPX_CALL (getsosindex_join) (handle_p, index_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetsosinfeas_async (CPXCENVptr env, CPXCLPptr lp,
                           double const *x, CPXDIM begin, CPXDIM end,
                           CPXASYNCptr *handle_p)
{
   return CPX_CALL (getsosinfeas_async) (env, lp, x, begin, end, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetsosinfeas_join (CPXASYNCptr *handle_p, double *infeasout)
{
   return CPX_CALL (getsosinfeas_join) (handle_p, infeasout);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetsosname_async (CPXCENVptr env, CPXCLPptr lp,
                         CPXSIZE storespace, CPXDIM begin, CPXDIM end,
                         CPXASYNCptr *handle_p)
{
   return CPX_CALL (getsosname_async) (env, lp, storespace, begin, end, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetsosname_join (CPXASYNCptr *handle_p, char  **name,
                        char *namestore, CPXSIZE *surplus_p)
{
   return CPX_CALL (getsosname_join) (handle_p, name, namestore, surplus_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgettime_async (CPXCENVptr env, CPXASYNCptr *handle_p)
{
   return CPX_CALL (gettime_async) (env, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgettime_join (CPXASYNCptr *handle_p, double *timestamp_p)
{
   return CPX_CALL (gettime_join) (handle_p, timestamp_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetub_async (CPXCENVptr env, CPXCLPptr lp, CPXDIM begin,
                    CPXDIM end, CPXASYNCptr *handle_p)
{
   return CPX_CALL (getub_async) (env, lp, begin, end, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetub_join (CPXASYNCptr *handle_p, double *ub)
{
   return CPX_CALL (getub_join) (handle_p, ub);
}

#endif /* !CPX_NO_REMOTE */


#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetx_async (CPXCENVptr env, CPXCLPptr lp, CPXDIM begin,
                   CPXDIM end, CPXASYNCptr *handle_p)
{
   return CPX_CALL (getx_async) (env, lp, begin, end, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetx_join (CPXASYNCptr *handle_p, double *x)
{
   return CPX_CALL (getx_join) (handle_p, x);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetxqxax_async (CPXCENVptr env, CPXCLPptr lp, CPXDIM begin,
                       CPXDIM end, CPXASYNCptr *handle_p)
{
   return CPX_CALL (getxqxax_async) (env, lp, begin, end, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXgetxqxax_join (CPXASYNCptr *handle_p, double *xqxax)
{
   return CPX_CALL (getxqxax_join) (handle_p, xqxax);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXhybbaropt_async (CPXCENVptr env, CPXLPptr lp, int method,
                        CPXASYNCptr *handle_p)
{
   return CPX_CALL (hybbaropt_async) (env, lp, method, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXhybbaropt_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (hybbaropt_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXhybbaropt_multicast (CPXENVGROUPptr group, int method)
{
   return CPX_CALL (hybbaropt_multicast) (group, method);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXhybnetopt_async (CPXCENVptr env, CPXLPptr lp, int method,
                        CPXASYNCptr *handle_p)
{
   return CPX_CALL (hybnetopt_async) (env, lp, method, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXhybnetopt_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (hybnetopt_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXhybnetopt_multicast (CPXENVGROUPptr group, int method)
{
   return CPX_CALL (hybnetopt_multicast) (group, method);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXindconstrslackfromx_async (CPXCENVptr env, CPXCLPptr lp,
                                  double const *x,
                                  CPXASYNCptr *handle_p)
{
   return CPX_CALL (indconstrslackfromx_async) (env, lp, x, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXindconstrslackfromx_join (CPXASYNCptr *handle_p,
                                 double *indslack)
{
   return CPX_CALL (indconstrslackfromx_join) (handle_p, indslack);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXinfodblparam_async (CPXCENVptr env, int whichparam,
                           CPXASYNCptr *handle_p)
{
   return CPX_CALL (infodblparam_async) (env, whichparam, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXinfodblparam_join (CPXASYNCptr *handle_p, double *defvalue_p,
                          double *minvalue_p, double *maxvalue_p)
{
   return CPX_CALL (infodblparam_join) (handle_p, defvalue_p, minvalue_p, maxvalue_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXinfointparam_async (CPXCENVptr env, int whichparam,
                           CPXASYNCptr *handle_p)
{
   return CPX_CALL (infointparam_async) (env, whichparam, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXinfointparam_join (CPXASYNCptr *handle_p, CPXINT *defvalue_p,
                          CPXINT *minvalue_p, CPXINT *maxvalue_p)
{
   return CPX_CALL (infointparam_join) (handle_p, defvalue_p, minvalue_p, maxvalue_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXinfolongparam_async (CPXCENVptr env, int whichparam,
                            CPXASYNCptr *handle_p)
{
   return CPX_CALL (infolongparam_async) (env, whichparam, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXinfolongparam_join (CPXASYNCptr *handle_p, CPXLONG *defvalue_p,
                           CPXLONG *minvalue_p, CPXLONG *maxvalue_p)
{
   return CPX_CALL (infolongparam_join) (handle_p, defvalue_p, minvalue_p, maxvalue_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXkilldnorms_async (CPXENVptr env, CPXLPptr lp,
                         CPXASYNCptr *handle_p)
{
   return CPX_CALL (killdnorms_async) (env, lp, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXkilldnorms_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (killdnorms_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXkilldnorms_multicast (CPXENVGROUPptr group)
{
   return CPX_CALL (killdnorms_multicast) (group);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXkillpnorms_async (CPXENVptr env, CPXLPptr lp,
                         CPXASYNCptr *handle_p)
{
   return CPX_CALL (killpnorms_async) (env, lp, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXkillpnorms_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (killpnorms_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXkillpnorms_multicast (CPXENVGROUPptr group)
{
   return CPX_CALL (killpnorms_multicast) (group);
}

#endif /* !CPX_NO_REMOTE */



#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXlpopt_async (CPXCENVptr env, CPXLPptr lp, CPXASYNCptr *handle_p)
{
   return CPX_CALL (lpopt_async) (env, lp, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXlpopt_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (lpopt_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXlpopt_multicast (CPXENVGROUPptr group)
{
   return CPX_CALL (lpopt_multicast) (group);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXlprewrite_async (CPXCENVptr env, CPXCLPptr lp,
                        char const *filename_str,
                        CPXASYNCptr *handle_p)
{
   return CPX_CALL (lprewrite_async) (env, lp, filename_str, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXlprewrite_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (lprewrite_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXlprewrite_multicast (CPXENVGROUPptr group,
                            char const *filename_str)
{
   return CPX_CALL (lprewrite_multicast) (group, filename_str);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXlpwrite_async (CPXCENVptr env, CPXCLPptr lp,
                      char const *filename_str, CPXASYNCptr *handle_p)
{
   return CPX_CALL (lpwrite_async) (env, lp, filename_str, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXlpwrite_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (lpwrite_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXlpwrite_multicast (CPXENVGROUPptr group,
                          char const *filename_str)
{
   return CPX_CALL (lpwrite_multicast) (group, filename_str);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXmbasewrite_async (CPXCENVptr env, CPXCLPptr lp,
                         char const *filename_str,
                         CPXASYNCptr *handle_p)
{
   return CPX_CALL (mbasewrite_async) (env, lp, filename_str, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXmbasewrite_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (mbasewrite_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXmbasewrite_multicast (CPXENVGROUPptr group,
                             char const *filename_str)
{
   return CPX_CALL (mbasewrite_multicast) (group, filename_str);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXmdleave_async (CPXCENVptr env, CPXLPptr lp,
                      CPXDIM const *indices, CPXDIM cnt,
                      CPXASYNCptr *handle_p)
{
   return CPX_CALL (mdleave_async) (env, lp, indices, cnt, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXmdleave_join (CPXASYNCptr *handle_p, double *downratio,
                     double *upratio)
{
   return CPX_CALL (mdleave_join) (handle_p, downratio, upratio);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXmipopt_async (CPXCENVptr env, CPXLPptr lp,
                     CPXASYNCptr *handle_p)
{
   return CPX_CALL (mipopt_async) (env, lp, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXmipopt_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (mipopt_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXmipopt_multicast (CPXENVGROUPptr group)
{
   return CPX_CALL (mipopt_multicast) (group);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXmpsrewrite_async (CPXCENVptr env, CPXCLPptr lp,
                         char const *filename_str,
                         CPXASYNCptr *handle_p)
{
   return CPX_CALL (mpsrewrite_async) (env, lp, filename_str, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXmpsrewrite_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (mpsrewrite_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXmpsrewrite_multicast (CPXENVGROUPptr group,
                             char const *filename_str)
{
   return CPX_CALL (mpsrewrite_multicast) (group, filename_str);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXmpswrite_async (CPXCENVptr env, CPXCLPptr lp,
                       char const *filename_str, CPXASYNCptr *handle_p)
{
   return CPX_CALL (mpswrite_async) (env, lp, filename_str, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXmpswrite_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (mpswrite_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXmpswrite_multicast (CPXENVGROUPptr group,
                           char const *filename_str)
{
   return CPX_CALL (mpswrite_multicast) (group, filename_str);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXNETaddarcs_async (CPXCENVptr env, CPXNETptr net, CPXDIM narcs,
                         CPXDIM const *fromnode, CPXDIM const *tonode,
                         double const *low, double const *up,
                         double const *obj, char const *const *anames,
                         CPXASYNCptr *handle_p)
{
   return CPX_CALL (NETaddarcs_async) (env, net, narcs, fromnode, tonode, low, up, obj, anames, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXNETaddarcs_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (NETaddarcs_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXNETaddnodes_async (CPXCENVptr env, CPXNETptr net, CPXDIM nnodes,
                          double const *supply,
                          char const *const *name,
                          CPXASYNCptr *handle_p)
{
   return CPX_CALL (NETaddnodes_async) (env, net, nnodes, supply, name, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXNETaddnodes_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (NETaddnodes_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXNETbasewrite_async (CPXCENVptr env, CPXCNETptr net,
                           char const *filename_str,
                           CPXASYNCptr *handle_p)
{
   return CPX_CALL (NETbasewrite_async) (env, net, filename_str, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXNETbasewrite_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (NETbasewrite_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXNETbasewrite_multicast (CPXENVGROUPptr group,
                               char const *filename_str)
{
   return CPX_CALL (NETbasewrite_multicast) (group, filename_str);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXNETchgarcname_async (CPXCENVptr env, CPXNETptr net, CPXDIM cnt,
                            CPXDIM const *indices,
                            char const *const *newname,
                            CPXASYNCptr *handle_p)
{
   return CPX_CALL (NETchgarcname_async) (env, net, cnt, indices, newname, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXNETchgarcname_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (NETchgarcname_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXNETchgarcnodes_async (CPXCENVptr env, CPXNETptr net, CPXDIM cnt,
                             CPXDIM const *indices,
                             CPXDIM const *fromnode,
                             CPXDIM const *tonode,
                             CPXASYNCptr *handle_p)
{
   return CPX_CALL (NETchgarcnodes_async) (env, net, cnt, indices, fromnode, tonode, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXNETchgarcnodes_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (NETchgarcnodes_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXNETchgarcnodes_multicast (CPXENVGROUPptr group, CPXDIM cnt,
                                 CPXDIM const *indices,
                                 CPXDIM const *fromnode,
                                 CPXDIM const *tonode)
{
   return CPX_CALL (NETchgarcnodes_multicast) (group, cnt, indices, fromnode, tonode);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXNETchgbds_async (CPXCENVptr env, CPXNETptr net, CPXDIM cnt,
                        CPXDIM const *indices, char const *lu,
                        double const *bd, CPXASYNCptr *handle_p)
{
   return CPX_CALL (NETchgbds_async) (env, net, cnt, indices, lu, bd, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXNETchgbds_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (NETchgbds_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXNETchgbds_multicast (CPXENVGROUPptr group, CPXDIM cnt,
                            CPXDIM const *indices, char const *lu,
                            double const *bd)
{
   return CPX_CALL (NETchgbds_multicast) (group, cnt, indices, lu, bd);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXNETchgname_async (CPXCENVptr env, CPXNETptr net, int key,
                         CPXDIM vindex, char const *name_str,
                         CPXASYNCptr *handle_p)
{
   return CPX_CALL (NETchgname_async) (env, net, key, vindex, name_str, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXNETchgname_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (NETchgname_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXNETchgnodename_async (CPXCENVptr env, CPXNETptr net, CPXDIM cnt,
                             CPXDIM const *indices,
                             char const *const *newname,
                             CPXASYNCptr *handle_p)
{
   return CPX_CALL (NETchgnodename_async) (env, net, cnt, indices, newname, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXNETchgnodename_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (NETchgnodename_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXNETchgobj_async (CPXCENVptr env, CPXNETptr net, CPXDIM cnt,
                        CPXDIM const *indices, double const *obj,
                        CPXASYNCptr *handle_p)
{
   return CPX_CALL (NETchgobj_async) (env, net, cnt, indices, obj, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXNETchgobj_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (NETchgobj_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXNETchgobj_multicast (CPXENVGROUPptr group, CPXDIM cnt,
                            CPXDIM const *indices, double const *obj)
{
   return CPX_CALL (NETchgobj_multicast) (group, cnt, indices, obj);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXNETchgobjsen_async (CPXCENVptr env, CPXNETptr net, int maxormin,
                           CPXASYNCptr *handle_p)
{
   return CPX_CALL (NETchgobjsen_async) (env, net, maxormin, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXNETchgobjsen_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (NETchgobjsen_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXNETchgobjsen_multicast (CPXENVGROUPptr group, int maxormin)
{
   return CPX_CALL (NETchgobjsen_multicast) (group, maxormin);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXNETchgsupply_async (CPXCENVptr env, CPXNETptr net, CPXDIM cnt,
                           CPXDIM const *indices, double const *supply,
                           CPXASYNCptr *handle_p)
{
   return CPX_CALL (NETchgsupply_async) (env, net, cnt, indices, supply, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXNETchgsupply_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (NETchgsupply_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXNETchgsupply_multicast (CPXENVGROUPptr group, CPXDIM cnt,
                               CPXDIM const *indices,
                               double const *supply)
{
   return CPX_CALL (NETchgsupply_multicast) (group, cnt, indices, supply);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXNETcopybase_async (CPXCENVptr env, CPXNETptr net,
                          int const *astat, int const *nstat,
                          CPXASYNCptr *handle_p)
{
   return CPX_CALL (NETcopybase_async) (env, net, astat, nstat, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXNETcopybase_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (NETcopybase_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXNETcopynet_async (CPXCENVptr env, CPXNETptr net, int objsen,
                         CPXDIM nnodes, double const *supply,
                         char const *const *nnames, CPXDIM narcs,
                         CPXDIM const *fromnode, CPXDIM const *tonode,
                         double const *low, double const *up,
                         double const *obj, char const *const *anames,
                         CPXASYNCptr *handle_p)
{
   return CPX_CALL (NETcopynet_async) (env, net, objsen, nnodes, supply, nnames, narcs, fromnode, tonode, low, up, obj, anames, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXNETcopynet_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (NETcopynet_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXNETdelarcs_async (CPXCENVptr env, CPXNETptr net, CPXDIM begin,
                         CPXDIM end, CPXASYNCptr *handle_p)
{
   return CPX_CALL (NETdelarcs_async) (env, net, begin, end, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXNETdelarcs_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (NETdelarcs_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXNETdelarcs_multicast (CPXENVGROUPptr group, CPXDIM begin,
                             CPXDIM end)
{
   return CPX_CALL (NETdelarcs_multicast) (group, begin, end);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXNETdelnodes_async (CPXCENVptr env, CPXNETptr net, CPXDIM begin,
                          CPXDIM end, CPXASYNCptr *handle_p)
{
   return CPX_CALL (NETdelnodes_async) (env, net, begin, end, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXNETdelnodes_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (NETdelnodes_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXNETdelnodes_multicast (CPXENVGROUPptr group, CPXDIM begin,
                              CPXDIM end)
{
   return CPX_CALL (NETdelnodes_multicast) (group, begin, end);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXNETdelset_async (CPXCENVptr env, CPXNETptr net,
                        CPXDIM *whichnodes, CPXDIM *whicharcs,
                        CPXASYNCptr *handle_p)
{
   return CPX_CALL (NETdelset_async) (env, net, whichnodes, whicharcs, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXNETdelset_join (CPXASYNCptr *handle_p, CPXDIM *whichnodes,
                       CPXDIM *whicharcs)
{
   return CPX_CALL (NETdelset_join) (handle_p, whichnodes, whicharcs);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXNETextract_async (CPXCENVptr env, CPXNETptr net, CPXCLPptr lp,
                         CPXASYNCptr *handle_p)
{
   return CPX_CALL (NETextract_async) (env, net, lp, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXNETextract_join (CPXASYNCptr *handle_p, CPXDIM *colmap,
                        CPXDIM *rowmap)
{
   return CPX_CALL (NETextract_join) (handle_p, colmap, rowmap);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXNETgetarcindex_async (CPXCENVptr env, CPXCNETptr net,
                             char const *lname_str,
                             CPXASYNCptr *handle_p)
{
   return CPX_CALL (NETgetarcindex_async) (env, net, lname_str, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXNETgetarcindex_join (CPXASYNCptr *handle_p, CPXDIM *index_p)
{
   return CPX_CALL (NETgetarcindex_join) (handle_p, index_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXNETgetarcname_async (CPXCENVptr env, CPXCNETptr net,
                            CPXSIZE namespc, CPXDIM begin, CPXDIM end,
                            CPXASYNCptr *handle_p)
{
   return CPX_CALL (NETgetarcname_async) (env, net, namespc, begin, end, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXNETgetarcname_join (CPXASYNCptr *handle_p, char  **nnames,
                           char *namestore, CPXSIZE *surplus_p)
{
   return CPX_CALL (NETgetarcname_join) (handle_p, nnames, namestore, surplus_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXNETgetarcnodes_async (CPXCENVptr env, CPXCNETptr net,
                             CPXDIM begin, CPXDIM end,
                             CPXASYNCptr *handle_p)
{
   return CPX_CALL (NETgetarcnodes_async) (env, net, begin, end, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXNETgetarcnodes_join (CPXASYNCptr *handle_p, CPXDIM *fromnode,
                            CPXDIM *tonode)
{
   return CPX_CALL (NETgetarcnodes_join) (handle_p, fromnode, tonode);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXNETgetbase_async (CPXCENVptr env, CPXCNETptr net,
                         CPXASYNCptr *handle_p)
{
   return CPX_CALL (NETgetbase_async) (env, net, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXNETgetbase_join (CPXASYNCptr *handle_p, int *astat, int *nstat)
{
   return CPX_CALL (NETgetbase_join) (handle_p, astat, nstat);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXNETgetdj_async (CPXCENVptr env, CPXCNETptr net, CPXDIM begin,
                       CPXDIM end, CPXASYNCptr *handle_p)
{
   return CPX_CALL (NETgetdj_async) (env, net, begin, end, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXNETgetdj_join (CPXASYNCptr *handle_p, double *dj)
{
   return CPX_CALL (NETgetdj_join) (handle_p, dj);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXNETgetlb_async (CPXCENVptr env, CPXCNETptr net, CPXDIM begin,
                       CPXDIM end, CPXASYNCptr *handle_p)
{
   return CPX_CALL (NETgetlb_async) (env, net, begin, end, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXNETgetlb_join (CPXASYNCptr *handle_p, double *low)
{
   return CPX_CALL (NETgetlb_join) (handle_p, low);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXNETgetnodearcs_async (CPXCENVptr env, CPXCNETptr net,
                             CPXDIM arcspace, CPXDIM begin, CPXDIM end,
                             CPXASYNCptr *handle_p)
{
   return CPX_CALL (NETgetnodearcs_async) (env, net, arcspace, begin, end, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXNETgetnodearcs_join (CPXASYNCptr *handle_p, CPXDIM *arccnt_p,
                            CPXDIM *arcbeg, CPXDIM *arc,
                            CPXDIM *surplus_p)
{
   return CPX_CALL (NETgetnodearcs_join) (handle_p, arccnt_p, arcbeg, arc, surplus_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXNETgetnodeindex_async (CPXCENVptr env, CPXCNETptr net,
                              char const *lname_str,
                              CPXASYNCptr *handle_p)
{
   return CPX_CALL (NETgetnodeindex_async) (env, net, lname_str, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXNETgetnodeindex_join (CPXASYNCptr *handle_p, CPXDIM *index_p)
{
   return CPX_CALL (NETgetnodeindex_join) (handle_p, index_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXNETgetnodename_async (CPXCENVptr env, CPXCNETptr net,
                             CPXSIZE namespc, CPXDIM begin, CPXDIM end,
                             CPXASYNCptr *handle_p)
{
   return CPX_CALL (NETgetnodename_async) (env, net, namespc, begin, end, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXNETgetnodename_join (CPXASYNCptr *handle_p, char  **nnames,
                            char *namestore, CPXSIZE *surplus_p)
{
   return CPX_CALL (NETgetnodename_join) (handle_p, nnames, namestore, surplus_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXNETgetobj_async (CPXCENVptr env, CPXCNETptr net, CPXDIM begin,
                        CPXDIM end, CPXASYNCptr *handle_p)
{
   return CPX_CALL (NETgetobj_async) (env, net, begin, end, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXNETgetobj_join (CPXASYNCptr *handle_p, double *obj)
{
   return CPX_CALL (NETgetobj_join) (handle_p, obj);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXNETgetobjval_async (CPXCENVptr env, CPXCNETptr net,
                           CPXASYNCptr *handle_p)
{
   return CPX_CALL (NETgetobjval_async) (env, net, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXNETgetobjval_join (CPXASYNCptr *handle_p, double *objval_p)
{
   return CPX_CALL (NETgetobjval_join) (handle_p, objval_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXNETgetpi_async (CPXCENVptr env, CPXCNETptr net, CPXDIM begin,
                       CPXDIM end, CPXASYNCptr *handle_p)
{
   return CPX_CALL (NETgetpi_async) (env, net, begin, end, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXNETgetpi_join (CPXASYNCptr *handle_p, double *pi)
{
   return CPX_CALL (NETgetpi_join) (handle_p, pi);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXNETgetprobname_async (CPXCENVptr env, CPXCNETptr net,
                             CPXSIZE bufspace, CPXASYNCptr *handle_p)
{
   return CPX_CALL (NETgetprobname_async) (env, net, bufspace, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXNETgetprobname_join (CPXASYNCptr *handle_p, char *buf_str,
                            CPXSIZE *surplus_p)
{
   return CPX_CALL (NETgetprobname_join) (handle_p, buf_str, surplus_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXNETgetslack_async (CPXCENVptr env, CPXCNETptr net, CPXDIM begin,
                          CPXDIM end, CPXASYNCptr *handle_p)
{
   return CPX_CALL (NETgetslack_async) (env, net, begin, end, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXNETgetslack_join (CPXASYNCptr *handle_p, double *slack)
{
   return CPX_CALL (NETgetslack_join) (handle_p, slack);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXNETgetsupply_async (CPXCENVptr env, CPXCNETptr net,
                           CPXDIM begin, CPXDIM end,
                           CPXASYNCptr *handle_p)
{
   return CPX_CALL (NETgetsupply_async) (env, net, begin, end, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXNETgetsupply_join (CPXASYNCptr *handle_p, double *supply)
{
   return CPX_CALL (NETgetsupply_join) (handle_p, supply);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXNETgetub_async (CPXCENVptr env, CPXCNETptr net, CPXDIM begin,
                       CPXDIM end, CPXASYNCptr *handle_p)
{
   return CPX_CALL (NETgetub_async) (env, net, begin, end, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXNETgetub_join (CPXASYNCptr *handle_p, double *up)
{
   return CPX_CALL (NETgetub_join) (handle_p, up);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXNETgetx_async (CPXCENVptr env, CPXCNETptr net, CPXDIM begin,
                      CPXDIM end, CPXASYNCptr *handle_p)
{
   return CPX_CALL (NETgetx_async) (env, net, begin, end, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXNETgetx_join (CPXASYNCptr *handle_p, double *x)
{
   return CPX_CALL (NETgetx_join) (handle_p, x);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXNETprimopt_async (CPXCENVptr env, CPXNETptr net,
                         CPXASYNCptr *handle_p)
{
   return CPX_CALL (NETprimopt_async) (env, net, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXNETprimopt_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (NETprimopt_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXNETprimopt_multicast (CPXENVGROUPptr group)
{
   return CPX_CALL (NETprimopt_multicast) (group);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXNETreadcopybase_async (CPXCENVptr env, CPXNETptr net,
                              char const *filename_str,
                              CPXASYNCptr *handle_p)
{
   return CPX_CALL (NETreadcopybase_async) (env, net, filename_str, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXNETreadcopybase_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (NETreadcopybase_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXNETreadcopybase_multicast (CPXENVGROUPptr group,
                                  char const *filename_str)
{
   return CPX_CALL (NETreadcopybase_multicast) (group, filename_str);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXNETreadcopyprob_async (CPXCENVptr env, CPXNETptr net,
                              char const *filename_str,
                              CPXASYNCptr *handle_p)
{
   return CPX_CALL (NETreadcopyprob_async) (env, net, filename_str, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXNETreadcopyprob_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (NETreadcopyprob_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXNETreadcopyprob_multicast (CPXENVGROUPptr group,
                                  char const *filename_str)
{
   return CPX_CALL (NETreadcopyprob_multicast) (group, filename_str);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXNETsolninfo_async (CPXCENVptr env, CPXCNETptr net,
                          CPXASYNCptr *handle_p)
{
   return CPX_CALL (NETsolninfo_async) (env, net, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXNETsolninfo_join (CPXASYNCptr *handle_p, int *pfeasind_p,
                         int *dfeasind_p)
{
   return CPX_CALL (NETsolninfo_join) (handle_p, pfeasind_p, dfeasind_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXNETsolution_async (CPXCENVptr env, CPXCNETptr net,
                          CPXASYNCptr *handle_p)
{
   return CPX_CALL (NETsolution_async) (env, net, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXNETsolution_join (CPXASYNCptr *handle_p, int *netstat_p,
                         double *objval_p, double *x, double *pi,
                         double *slack, double *dj)
{
   return CPX_CALL (NETsolution_join) (handle_p, netstat_p, objval_p, x, pi, slack, dj);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXNETwriteprob_async (CPXCENVptr env, CPXCNETptr net,
                           char const *filename_str,
                           char const *format_str,
                           CPXASYNCptr *handle_p)
{
   return CPX_CALL (NETwriteprob_async) (env, net, filename_str, format_str, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXNETwriteprob_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (NETwriteprob_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXNETwriteprob_multicast (CPXENVGROUPptr group,
                               char const *filename_str,
                               char const *format_str)
{
   return CPX_CALL (NETwriteprob_multicast) (group, filename_str, format_str);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXnewcols_async (CPXCENVptr env, CPXLPptr lp, CPXDIM ccnt,
                      double const *obj, double const *lb,
                      double const *ub, char const *xctype,
                      char const *const *colname,
                      CPXASYNCptr *handle_p)
{
   return CPX_CALL (newcols_async) (env, lp, ccnt, obj, lb, ub, xctype, colname, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXnewcols_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (newcols_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXnewrows_async (CPXCENVptr env, CPXLPptr lp, CPXDIM rcnt,
                      double const *rhs, char const *sense,
                      double const *rngval, char const *const *rowname,
                      CPXASYNCptr *handle_p)
{
   return CPX_CALL (newrows_async) (env, lp, rcnt, rhs, sense, rngval, rowname, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXnewrows_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (newrows_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXobjsa_async (CPXCENVptr env, CPXCLPptr lp, CPXDIM begin,
                    CPXDIM end, CPXASYNCptr *handle_p)
{
   return CPX_CALL (objsa_async) (env, lp, begin, end, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXobjsa_join (CPXASYNCptr *handle_p, double *lower, double *upper)
{
   return CPX_CALL (objsa_join) (handle_p, lower, upper);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
CPXENVptr CPXPUBLIC
   CPXXopenCPLEXreconnect (int *status_p, void const *buffer)
{
   return CPX_CALL (openCPLEXreconnect) (status_p, buffer);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
CPXENVptr CPXPUBLIC
   CPXXopenCPLEXremote (char const *transport, int argc,
                        char const *const *argv, int *status_p)
{
   return CPX_CALL (openCPLEXremote) (transport, argc, argv, status_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXordread_async (CPXCENVptr env, char const *filename_str,
                      CPXDIM numcols, char const *const *colname,
                      CPXASYNCptr *handle_p)
{
   return CPX_CALL (ordread_async) (env, filename_str, numcols, colname, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXordread_join (CPXASYNCptr *handle_p, CPXDIM *cnt_p,
                     CPXDIM *indices, CPXDIM *priority, int *direction)
{
   return CPX_CALL (ordread_join) (handle_p, cnt_p, indices, priority, direction);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXordwrite_async (CPXCENVptr env, CPXCLPptr lp,
                       char const *filename_str, CPXASYNCptr *handle_p)
{
   return CPX_CALL (ordwrite_async) (env, lp, filename_str, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXordwrite_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (ordwrite_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXordwrite_multicast (CPXENVGROUPptr group,
                           char const *filename_str)
{
   return CPX_CALL (ordwrite_multicast) (group, filename_str);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXpivot_async (CPXCENVptr env, CPXLPptr lp, CPXDIM jenter,
                    CPXDIM jleave, int leavestat,
                    CPXASYNCptr *handle_p)
{
   return CPX_CALL (pivot_async) (env, lp, jenter, jleave, leavestat, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXpivot_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (pivot_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXpivot_multicast (CPXENVGROUPptr group, CPXDIM jenter,
                        CPXDIM jleave, int leavestat)
{
   return CPX_CALL (pivot_multicast) (group, jenter, jleave, leavestat);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXpivotin_async (CPXCENVptr env, CPXLPptr lp, CPXDIM const *rlist,
                      CPXDIM rlen, CPXASYNCptr *handle_p)
{
   return CPX_CALL (pivotin_async) (env, lp, rlist, rlen, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXpivotin_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (pivotin_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXpivotin_multicast (CPXENVGROUPptr group, CPXDIM const *rlist,
                          CPXDIM rlen)
{
   return CPX_CALL (pivotin_multicast) (group, rlist, rlen);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXpivotout_async (CPXCENVptr env, CPXLPptr lp,
                       CPXDIM const *clist, CPXDIM clen,
                       CPXASYNCptr *handle_p)
{
   return CPX_CALL (pivotout_async) (env, lp, clist, clen, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXpivotout_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (pivotout_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXpivotout_multicast (CPXENVGROUPptr group, CPXDIM const *clist,
                           CPXDIM clen)
{
   return CPX_CALL (pivotout_multicast) (group, clist, clen);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXpopulate_async (CPXCENVptr env, CPXLPptr lp,
                       CPXASYNCptr *handle_p)
{
   return CPX_CALL (populate_async) (env, lp, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXpopulate_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (populate_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXpopulate_multicast (CPXENVGROUPptr group)
{
   return CPX_CALL (populate_multicast) (group);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXpperwrite_async (CPXCENVptr env, CPXLPptr lp,
                        char const *filename_str, double epsilon,
                        CPXASYNCptr *handle_p)
{
   return CPX_CALL (pperwrite_async) (env, lp, filename_str, epsilon, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXpperwrite_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (pperwrite_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXpperwrite_multicast (CPXENVGROUPptr group,
                            char const *filename_str, double epsilon)
{
   return CPX_CALL (pperwrite_multicast) (group, filename_str, epsilon);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXpratio_async (CPXCENVptr env, CPXLPptr lp, CPXDIM *indices,
                     CPXDIM cnt, CPXASYNCptr *handle_p)
{
   return CPX_CALL (pratio_async) (env, lp, indices, cnt, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXpratio_join (CPXASYNCptr *handle_p, CPXDIM *indices,
                    double *downratio, double *upratio,
                    CPXDIM *downleave, CPXDIM *upleave,
                    int *downleavestatus, int *upleavestatus,
                    int *downstatus, int *upstatus)
{
   return CPX_CALL (pratio_join) (handle_p, indices, downratio, upratio, downleave, upleave, downleavestatus, upleavestatus, downstatus, upstatus);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXpreaddrows_async (CPXCENVptr env, CPXLPptr lp, CPXDIM rcnt,
                         CPXNNZ nzcnt, double const *rhs,
                         char const *sense, CPXNNZ const *rmatbeg,
                         CPXDIM const *rmatind, double const *rmatval,
                         char const *const *rowname,
                         CPXASYNCptr *handle_p)
{
   return CPX_CALL (preaddrows_async) (env, lp, rcnt, nzcnt, rhs, sense, rmatbeg, rmatind, rmatval, rowname, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXpreaddrows_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (preaddrows_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXprechgobj_async (CPXCENVptr env, CPXLPptr lp, CPXDIM cnt,
                        CPXDIM const *indices, double const *values,
                        CPXASYNCptr *handle_p)
{
   return CPX_CALL (prechgobj_async) (env, lp, cnt, indices, values, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXprechgobj_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (prechgobj_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXprechgobj_multicast (CPXENVGROUPptr group, CPXDIM cnt,
                            CPXDIM const *indices,
                            double const *values)
{
   return CPX_CALL (prechgobj_multicast) (group, cnt, indices, values);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXpreslvwrite_async (CPXCENVptr env, CPXLPptr lp,
                          char const *filename_str,
                          CPXASYNCptr *handle_p)
{
   return CPX_CALL (preslvwrite_async) (env, lp, filename_str, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXpreslvwrite_join (CPXASYNCptr *handle_p, double *objoff_p)
{
   return CPX_CALL (preslvwrite_join) (handle_p, objoff_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXpresolve_async (CPXCENVptr env, CPXLPptr lp, int method,
                       CPXASYNCptr *handle_p)
{
   return CPX_CALL (presolve_async) (env, lp, method, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXpresolve_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (presolve_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXpresolve_multicast (CPXENVGROUPptr group, int method)
{
   return CPX_CALL (presolve_multicast) (group, method);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXprimopt_async (CPXCENVptr env, CPXLPptr lp,
                      CPXASYNCptr *handle_p)
{
   return CPX_CALL (primopt_async) (env, lp, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXprimopt_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (primopt_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXprimopt_multicast (CPXENVGROUPptr group)
{
   return CPX_CALL (primopt_multicast) (group);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXqconstrslackfromx_async (CPXCENVptr env, CPXCLPptr lp,
                                double const *x, CPXASYNCptr *handle_p)
{
   return CPX_CALL (qconstrslackfromx_async) (env, lp, x, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXqconstrslackfromx_join (CPXASYNCptr *handle_p, double *qcslack)
{
   return CPX_CALL (qconstrslackfromx_join) (handle_p, qcslack);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXqpdjfrompi_async (CPXCENVptr env, CPXCLPptr lp,
                         double const *pi, double const *x,
                         CPXASYNCptr *handle_p)
{
   return CPX_CALL (qpdjfrompi_async) (env, lp, pi, x, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXqpdjfrompi_join (CPXASYNCptr *handle_p, double *dj)
{
   return CPX_CALL (qpdjfrompi_join) (handle_p, dj);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXqpindefcertificate_async (CPXCENVptr env, CPXCLPptr lp,
                                 CPXASYNCptr *handle_p)
{
   return CPX_CALL (qpindefcertificate_async) (env, lp, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXqpindefcertificate_join (CPXASYNCptr *handle_p, double *x)
{
   return CPX_CALL (qpindefcertificate_join) (handle_p, x);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXqpopt_async (CPXCENVptr env, CPXLPptr lp, CPXASYNCptr *handle_p)
{
   return CPX_CALL (qpopt_async) (env, lp, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXqpopt_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (qpopt_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXqpopt_multicast (CPXENVGROUPptr group)
{
   return CPX_CALL (qpopt_multicast) (group);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXqpuncrushpi_async (CPXCENVptr env, CPXCLPptr lp,
                          double const *prepi, double const *x,
                          CPXASYNCptr *handle_p)
{
   return CPX_CALL (qpuncrushpi_async) (env, lp, prepi, x, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXqpuncrushpi_join (CPXASYNCptr *handle_p, double *pi)
{
   return CPX_CALL (qpuncrushpi_join) (handle_p, pi);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXreadcopyannotations_multicast (CPXENVGROUPptr group,
                                      char const *filename)
{
   return CPX_CALL (readcopyannotations_multicast) (group, filename);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXreadcopybase_async (CPXCENVptr env, CPXLPptr lp,
                           char const *filename_str,
                           CPXASYNCptr *handle_p)
{
   return CPX_CALL (readcopybase_async) (env, lp, filename_str, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXreadcopybase_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (readcopybase_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXreadcopybase_multicast (CPXENVGROUPptr group,
                               char const *filename_str)
{
   return CPX_CALL (readcopybase_multicast) (group, filename_str);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXreadcopymipstarts_async (CPXCENVptr env, CPXLPptr lp,
                                char const *filename_str,
                                CPXASYNCptr *handle_p)
{
   return CPX_CALL (readcopymipstarts_async) (env, lp, filename_str, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXreadcopymipstarts_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (readcopymipstarts_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXreadcopymipstarts_multicast (CPXENVGROUPptr group,
                                    char const *filename_str)
{
   return CPX_CALL (readcopymipstarts_multicast) (group, filename_str);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXreadcopyorder_async (CPXCENVptr env, CPXLPptr lp,
                            char const *filename_str,
                            CPXASYNCptr *handle_p)
{
   return CPX_CALL (readcopyorder_async) (env, lp, filename_str, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXreadcopyorder_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (readcopyorder_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXreadcopyorder_multicast (CPXENVGROUPptr group,
                                char const *filename_str)
{
   return CPX_CALL (readcopyorder_multicast) (group, filename_str);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXreadcopyparam_async (CPXENVptr env, char const *filename_str,
                            CPXASYNCptr *handle_p)
{
   return CPX_CALL (readcopyparam_async) (env, filename_str, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXreadcopyparam_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (readcopyparam_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXreadcopyparam_multicast (CPXENVGROUPptr group,
                                char const *filename_str)
{
   return CPX_CALL (readcopyparam_multicast) (group, filename_str);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXreadcopyprob_async (CPXCENVptr env, CPXLPptr lp,
                           char const *filename_str,
                           char const *filetype_str,
                           CPXASYNCptr *handle_p)
{
   return CPX_CALL (readcopyprob_async) (env, lp, filename_str, filetype_str, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXreadcopyprob_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (readcopyprob_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXreadcopyprob_multicast (CPXENVGROUPptr group,
                               char const *filename_str,
                               char const *filetype_str)
{
   return CPX_CALL (readcopyprob_multicast) (group, filename_str, filetype_str);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXreadcopysol_async (CPXCENVptr env, CPXLPptr lp,
                          char const *filename_str,
                          CPXASYNCptr *handle_p)
{
   return CPX_CALL (readcopysol_async) (env, lp, filename_str, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXreadcopysol_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (readcopysol_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXreadcopysol_multicast (CPXENVGROUPptr group,
                              char const *filename_str)
{
   return CPX_CALL (readcopysol_multicast) (group, filename_str);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXreadcopysolnpoolfilters_async (CPXCENVptr env, CPXLPptr lp,
                                      char const *filename_str,
                                      CPXASYNCptr *handle_p)
{
   return CPX_CALL (readcopysolnpoolfilters_async) (env, lp, filename_str, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXreadcopysolnpoolfilters_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (readcopysolnpoolfilters_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXreadcopysolnpoolfilters_multicast (CPXENVGROUPptr group,
                                          char const *filename_str)
{
   return CPX_CALL (readcopysolnpoolfilters_multicast) (group, filename_str);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXrefineconflict_async (CPXCENVptr env, CPXLPptr lp,
                             CPXASYNCptr *handle_p)
{
   return CPX_CALL (refineconflict_async) (env, lp, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXrefineconflict_join (CPXASYNCptr *handle_p,
                            CPXDIM *confnumrows_p,
                            CPXDIM *confnumcols_p)
{
   return CPX_CALL (refineconflict_join) (handle_p, confnumrows_p, confnumcols_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXrefineconflictext_async (CPXCENVptr env, CPXLPptr lp,
                                CPXNNZ grpcnt, CPXNNZ concnt,
                                double const *grppref,
                                CPXNNZ const *grpbeg,
                                CPXDIM const *grpind,
                                char const *grptype,
                                CPXASYNCptr *handle_p)
{
   return CPX_CALL (refineconflictext_async) (env, lp, grpcnt, concnt, grppref, grpbeg, grpind, grptype, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXrefineconflictext_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (refineconflictext_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXrefineconflictext_multicast (CPXENVGROUPptr group,
                                    CPXNNZ grpcnt, CPXNNZ concnt,
                                    double const *grppref,
                                    CPXNNZ const *grpbeg,
                                    CPXDIM const *grpind,
                                    char const *grptype)
{
   return CPX_CALL (refineconflictext_multicast) (group, grpcnt, concnt, grppref, grpbeg, grpind, grptype);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXrefinemipstartconflict_async (CPXCENVptr env, CPXLPptr lp,
                                     int mipstartindex,
                                     CPXASYNCptr *handle_p)
{
   return CPX_CALL (refinemipstartconflict_async) (env, lp, mipstartindex, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXrefinemipstartconflict_join (CPXASYNCptr *handle_p,
                                    CPXDIM *confnumrows_p,
                                    CPXDIM *confnumcols_p)
{
   return CPX_CALL (refinemipstartconflict_join) (handle_p, confnumrows_p, confnumcols_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXrefinemipstartconflictext_async (CPXCENVptr env, CPXLPptr lp,
                                        int mipstartindex,
                                        CPXNNZ grpcnt, CPXNNZ concnt,
                                        double const *grppref,
                                        CPXNNZ const *grpbeg,
                                        CPXDIM const *grpind,
                                        char const *grptype,
                                        CPXASYNCptr *handle_p)
{
   return CPX_CALL (refinemipstartconflictext_async) (env, lp, mipstartindex, grpcnt, concnt, grppref, grpbeg, grpind, grptype, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXrefinemipstartconflictext_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (refinemipstartconflictext_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXrefinemipstartconflictext_multicast (CPXENVGROUPptr group,
                                            int mipstartindex,
                                            CPXNNZ grpcnt,
                                            CPXNNZ concnt,
                                            double const *grppref,
                                            CPXNNZ const *grpbeg,
                                            CPXDIM const *grpind,
                                            char const *grptype)
{
   return CPX_CALL (refinemipstartconflictext_multicast) (group, mipstartindex, grpcnt, concnt, grppref, grpbeg, grpind, grptype);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXrhssa_async (CPXCENVptr env, CPXCLPptr lp, CPXDIM begin,
                    CPXDIM end, CPXASYNCptr *handle_p)
{
   return CPX_CALL (rhssa_async) (env, lp, begin, end, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXrhssa_join (CPXASYNCptr *handle_p, double *lower, double *upper)
{
   return CPX_CALL (rhssa_join) (handle_p, lower, upper);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXsavwrite_async (CPXCENVptr env, CPXCLPptr lp,
                       char const *filename_str, CPXASYNCptr *handle_p)
{
   return CPX_CALL (savwrite_async) (env, lp, filename_str, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXsavwrite_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (savwrite_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXsavwrite_multicast (CPXENVGROUPptr group,
                           char const *filename_str)
{
   return CPX_CALL (savwrite_multicast) (group, filename_str);
}

#endif /* !CPX_NO_REMOTE */






#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXsetdblannotations_multicast (CPXENVGROUPptr group, CPXDIM idx,
                                    int objtype, CPXDIM cnt,
                                    CPXDIM const *indices,
                                    double const *values)
{
   return CPX_CALL (setdblannotations_multicast) (group, idx, objtype, cnt, indices, values);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXsetdblparam_async (CPXENVptr env, int whichparam,
                          double newvalue, CPXASYNCptr *handle_p)
{
   return CPX_CALL (setdblparam_async) (env, whichparam, newvalue, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXsetdblparam_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (setdblparam_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXsetdblparam_multicast (CPXENVGROUPptr group, int whichparam,
                              double newvalue)
{
   return CPX_CALL (setdblparam_multicast) (group, whichparam, newvalue);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXsetdefaults_async (CPXENVptr env, CPXASYNCptr *handle_p)
{
   return CPX_CALL (setdefaults_async) (env, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXsetdefaults_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (setdefaults_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXsetdefaults_multicast (CPXENVGROUPptr group)
{
   return CPX_CALL (setdefaults_multicast) (group);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXsetinfohandler (CPXENVptr env, CPXINFOHANDLER *infohandler,
                       void *handle)
{
   return CPX_CALL (setinfohandler) (env, infohandler, handle);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXsetintparam_async (CPXENVptr env, int whichparam,
                          CPXINT newvalue, CPXASYNCptr *handle_p)
{
   return CPX_CALL (setintparam_async) (env, whichparam, newvalue, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXsetintparam_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (setintparam_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXsetintparam_multicast (CPXENVGROUPptr group, int whichparam,
                              CPXINT newvalue)
{
   return CPX_CALL (setintparam_multicast) (group, whichparam, newvalue);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXsetlongannotations_multicast (CPXENVGROUPptr group, CPXDIM idx,
                                     int objtype, CPXDIM cnt,
                                     CPXDIM const *indices,
                                     CPXLONG const *values)
{
   return CPX_CALL (setlongannotations_multicast) (group, idx, objtype, cnt, indices, values);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXsetlongparam_async (CPXENVptr env, int whichparam,
                           CPXLONG newvalue, CPXASYNCptr *handle_p)
{
   return CPX_CALL (setlongparam_async) (env, whichparam, newvalue, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXsetlongparam_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (setlongparam_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXsetlongparam_multicast (CPXENVGROUPptr group, int whichparam,
                               CPXLONG newvalue)
{
   return CPX_CALL (setlongparam_multicast) (group, whichparam, newvalue);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXsetphase2_async (CPXCENVptr env, CPXLPptr lp,
                        CPXASYNCptr *handle_p)
{
   return CPX_CALL (setphase2_async) (env, lp, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXsetphase2_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (setphase2_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXsetphase2_multicast (CPXENVGROUPptr group)
{
   return CPX_CALL (setphase2_multicast) (group);
}

#endif /* !CPX_NO_REMOTE */


#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXsiftopt_async (CPXCENVptr env, CPXLPptr lp,
                      CPXASYNCptr *handle_p)
{
   return CPX_CALL (siftopt_async) (env, lp, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXsiftopt_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (siftopt_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXsiftopt_multicast (CPXENVGROUPptr group)
{
   return CPX_CALL (siftopt_multicast) (group);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXslackfromx_async (CPXCENVptr env, CPXCLPptr lp, double const *x,
                         CPXASYNCptr *handle_p)
{
   return CPX_CALL (slackfromx_async) (env, lp, x, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXslackfromx_join (CPXASYNCptr *handle_p, double *slack)
{
   return CPX_CALL (slackfromx_join) (handle_p, slack);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXsolninfo_async (CPXCENVptr env, CPXCLPptr lp,
                       CPXASYNCptr *handle_p)
{
   return CPX_CALL (solninfo_async) (env, lp, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXsolninfo_join (CPXASYNCptr *handle_p, int *solnmethod_p,
                      int *solntype_p, int *pfeasind_p,
                      int *dfeasind_p)
{
   return CPX_CALL (solninfo_join) (handle_p, solnmethod_p, solntype_p, pfeasind_p, dfeasind_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXsolution_async (CPXCENVptr env, CPXCLPptr lp,
                       CPXASYNCptr *handle_p)
{
   return CPX_CALL (solution_async) (env, lp, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXsolution_join (CPXASYNCptr *handle_p, int *lpstat_p,
                      double *objval_p, double *x, double *pi,
                      double *slack, double *dj)
{
   return CPX_CALL (solution_join) (handle_p, lpstat_p, objval_p, x, pi, slack, dj);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXsolwrite_async (CPXCENVptr env, CPXCLPptr lp,
                       char const *filename_str, CPXASYNCptr *handle_p)
{
   return CPX_CALL (solwrite_async) (env, lp, filename_str, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXsolwrite_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (solwrite_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXsolwrite_multicast (CPXENVGROUPptr group,
                           char const *filename_str)
{
   return CPX_CALL (solwrite_multicast) (group, filename_str);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXsolwritesolnpool_async (CPXCENVptr env, CPXCLPptr lp, int soln,
                               char const *filename_str,
                               CPXASYNCptr *handle_p)
{
   return CPX_CALL (solwritesolnpool_async) (env, lp, soln, filename_str, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXsolwritesolnpool_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (solwritesolnpool_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXsolwritesolnpool_multicast (CPXENVGROUPptr group, int soln,
                                   char const *filename_str)
{
   return CPX_CALL (solwritesolnpool_multicast) (group, soln, filename_str);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXsolwritesolnpoolall_async (CPXCENVptr env, CPXCLPptr lp,
                                  char const *filename_str,
                                  CPXASYNCptr *handle_p)
{
   return CPX_CALL (solwritesolnpoolall_async) (env, lp, filename_str, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXsolwritesolnpoolall_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (solwritesolnpoolall_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXsolwritesolnpoolall_multicast (CPXENVGROUPptr group,
                                      char const *filename_str)
{
   return CPX_CALL (solwritesolnpoolall_multicast) (group, filename_str);
}

#endif /* !CPX_NO_REMOTE */



#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXstrongbranch_async (CPXCENVptr env, CPXLPptr lp,
                           CPXDIM const *indices, CPXDIM cnt,
                           CPXCNT itlim, CPXASYNCptr *handle_p)
{
   return CPX_CALL (strongbranch_async) (env, lp, indices, cnt, itlim, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXstrongbranch_join (CPXASYNCptr *handle_p, double *downobj,
                          double *upobj)
{
   return CPX_CALL (strongbranch_join) (handle_p, downobj, upobj);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXtightenbds_async (CPXCENVptr env, CPXLPptr lp, CPXDIM cnt,
                         CPXDIM const *indices, char const *lu,
                         double const *bd, CPXASYNCptr *handle_p)
{
   return CPX_CALL (tightenbds_async) (env, lp, cnt, indices, lu, bd, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXtightenbds_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (tightenbds_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXtightenbds_multicast (CPXENVGROUPptr group, CPXDIM cnt,
                             CPXDIM const *indices, char const *lu,
                             double const *bd)
{
   return CPX_CALL (tightenbds_multicast) (group, cnt, indices, lu, bd);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXtransportctrldbl (CPXCENVptr env, int ctrl, double *data_p)
{
   return CPX_CALL (transportctrldbl) (env, ctrl, data_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXtransportctrlint (CPXCENVptr env, int ctrl, CPXINT *data_p)
{
   return CPX_CALL (transportctrlint) (env, ctrl, data_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXtransportctrllong (CPXCENVptr env, int ctrl, CPXLONG *data_p)
{
   return CPX_CALL (transportctrllong) (env, ctrl, data_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXtuneparam_async (CPXENVptr env, CPXLPptr lp, int intcnt,
                        int const *intnum, int const *intval,
                        int dblcnt, int const *dblnum,
                        double const *dblval, int strcnt,
                        int const *strnum, char const *const *strval,
                        CPXASYNCptr *handle_p)
{
   return CPX_CALL (tuneparam_async) (env, lp, intcnt, intnum, intval, dblcnt, dblnum, dblval, strcnt, strnum, strval, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXtuneparam_join (CPXASYNCptr *handle_p, int *tunestat_p)
{
   return CPX_CALL (tuneparam_join) (handle_p, tunestat_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXuncrushpi_async (CPXCENVptr env, CPXCLPptr lp,
                        double const *prepi, CPXASYNCptr *handle_p)
{
   return CPX_CALL (uncrushpi_async) (env, lp, prepi, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXuncrushpi_join (CPXASYNCptr *handle_p, double *pi)
{
   return CPX_CALL (uncrushpi_join) (handle_p, pi);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXuncrushx_async (CPXCENVptr env, CPXCLPptr lp,
                       double const *prex, CPXASYNCptr *handle_p)
{
   return CPX_CALL (uncrushx_async) (env, lp, prex, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXuncrushx_join (CPXASYNCptr *handle_p, double *x)
{
   return CPX_CALL (uncrushx_join) (handle_p, x);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXunscaleprob_async (CPXCENVptr env, CPXLPptr lp,
                          CPXASYNCptr *handle_p)
{
   return CPX_CALL (unscaleprob_async) (env, lp, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXunscaleprob_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (unscaleprob_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXunscaleprob_multicast (CPXENVGROUPptr group)
{
   return CPX_CALL (unscaleprob_multicast) (group);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXuserfunction (CPXENVptr env, int id, CPXLONG insize,
                     void const *indata, CPXLONG outspace,
                     CPXLONG *outsize_p, void *outdata)
{
   return CPX_CALL (userfunction) (env, id, insize, indata, outspace, outsize_p, outdata);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXuserfunction_async (CPXENVptr env, int id, CPXLONG insize,
                           void const *indata, CPXLONG outspace,
                           CPXASYNCptr *handle_p)
{
   return CPX_CALL (userfunction_async) (env, id, insize, indata, outspace, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXuserfunction_join (CPXASYNCptr *handle_p, CPXLONG *outsize_p,
                          void *outdata)
{
   return CPX_CALL (userfunction_join) (handle_p, outsize_p, outdata);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXwritemipstarts_async (CPXCENVptr env, CPXCLPptr lp,
                             char const *filename_str, int begin,
                             int end, CPXASYNCptr *handle_p)
{
   return CPX_CALL (writemipstarts_async) (env, lp, filename_str, begin, end, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXwritemipstarts_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (writemipstarts_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXwritemipstarts_multicast (CPXENVGROUPptr group,
                                 char const *filename_str, int begin,
                                 int end)
{
   return CPX_CALL (writemipstarts_multicast) (group, filename_str, begin, end);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXwriteparam_async (CPXCENVptr env, char const *filename_str,
                         CPXASYNCptr *handle_p)
{
   return CPX_CALL (writeparam_async) (env, filename_str, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXwriteparam_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (writeparam_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXwriteparam_multicast (CPXENVGROUPptr group,
                             char const *filename_str)
{
   return CPX_CALL (writeparam_multicast) (group, filename_str);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXwriteprob_async (CPXCENVptr env, CPXCLPptr lp,
                        char const *filename_str,
                        char const *filetype_str,
                        CPXASYNCptr *handle_p)
{
   return CPX_CALL (writeprob_async) (env, lp, filename_str, filetype_str, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXwriteprob_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (writeprob_join) (handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE CPXDEPRECATED(12700000)
int CPXPUBLIC
   CPXXwriteprob_multicast (CPXENVGROUPptr group,
                            char const *filename_str,
                            char const *filetype_str)
{
   return CPX_CALL (writeprob_multicast) (group, filename_str, filetype_str);
}

#endif /* !CPX_NO_REMOTE */



#ifdef __cplusplus
}
#endif

#ifdef _WIN32
#pragma pack(pop)
#endif

#endif /* !CPX_CPLEX_REMOTEMASTERX_H */
