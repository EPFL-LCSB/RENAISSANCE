/* --------------------------------------------------------------------------
 * File: cplexremotemasterx.h
 * Version 12.8.0
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
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXchgcoef_multicast (CPXENVGROUPptr group, CPXDIM i, CPXDIM j,
                          double newvalue)
{
   return CPX_CALL (chgcoef_multicast) (group, i, j, newvalue);
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
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXchgctype_multicast (CPXENVGROUPptr group, CPXDIM cnt,
                           CPXDIM const *indices, char const *xctype)
{
   return CPX_CALL (chgctype_multicast) (group, cnt, indices, xctype);
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
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXchgobj_multicast (CPXENVGROUPptr group, CPXDIM cnt,
                         CPXDIM const *indices, double const *values)
{
   return CPX_CALL (chgobj_multicast) (group, cnt, indices, values);
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
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXchgobjsen_multicast (CPXENVGROUPptr group, int maxormin)
{
   return CPX_CALL (chgobjsen_multicast) (group, maxormin);
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
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXchgprobtypesolnpool_multicast (CPXENVGROUPptr group, int type,
                                      int soln)
{
   return CPX_CALL (chgprobtypesolnpool_multicast) (group, type, soln);
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
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXchgrhs_multicast (CPXENVGROUPptr group, CPXDIM cnt,
                         CPXDIM const *indices, double const *values)
{
   return CPX_CALL (chgrhs_multicast) (group, cnt, indices, values);
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
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXchgsense_multicast (CPXENVGROUPptr group, CPXDIM cnt,
                           CPXDIM const *indices, char const *sense)
{
   return CPX_CALL (chgsense_multicast) (group, cnt, indices, sense);
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
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXcompletelp_multicast (CPXENVGROUPptr group)
{
   return CPX_CALL (completelp_multicast) (group);
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
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXcopynettolp_multicast (CPXENVGROUPptr group)
{
   return CPX_CALL (copynettolp_multicast) (group);
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
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXcopyprotected_multicast (CPXENVGROUPptr group, CPXDIM cnt,
                                CPXDIM const *indices)
{
   return CPX_CALL (copyprotected_multicast) (group, cnt, indices);
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
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXdelmipstarts_multicast (CPXENVGROUPptr group, int begin,
                               int end)
{
   return CPX_CALL (delmipstarts_multicast) (group, begin, end);
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
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXdelqconstrs_multicast (CPXENVGROUPptr group, CPXDIM begin,
                              CPXDIM end)
{
   return CPX_CALL (delqconstrs_multicast) (group, begin, end);
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
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXdelsolnpoolfilters_multicast (CPXENVGROUPptr group, int begin,
                                     int end)
{
   return CPX_CALL (delsolnpoolfilters_multicast) (group, begin, end);
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
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXdelsos_multicast (CPXENVGROUPptr group, CPXDIM begin,
                         CPXDIM end)
{
   return CPX_CALL (delsos_multicast) (group, begin, end);
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
CPX_STATIC_INLINE
void CPXPUBLIC
   CPXXfreeenvgroup (CPXENVGROUPptr *group_p)
{
CPX_CALL (freeenvgroup) (group_p);
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
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXfreepresolve_multicast (CPXENVGROUPptr group)
{
   return CPX_CALL (freepresolve_multicast) (group);
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
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetinfohandler (CPXCENVptr env, CPXINFOHANDLER  **infohandler_p,
                       void  **handle_p)
{
   return CPX_CALL (getinfohandler) (env, infohandler_p, handle_p);
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
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetreconnectinfolen (CPXCENVptr env)
{
   return CPX_CALL (getreconnectinfolen) (env);
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
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXkilldnorms_multicast (CPXENVGROUPptr group)
{
   return CPX_CALL (killdnorms_multicast) (group);
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
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXNETchgobj_multicast (CPXENVGROUPptr group, CPXDIM cnt,
                            CPXDIM const *indices, double const *obj)
{
   return CPX_CALL (NETchgobj_multicast) (group, cnt, indices, obj);
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
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXNETdelarcs_multicast (CPXENVGROUPptr group, CPXDIM begin,
                             CPXDIM end)
{
   return CPX_CALL (NETdelarcs_multicast) (group, begin, end);
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
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXNETreadcopybase_multicast (CPXENVGROUPptr group,
                                  char const *filename_str)
{
   return CPX_CALL (NETreadcopybase_multicast) (group, filename_str);
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
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXreadcopyannotations_multicast (CPXENVGROUPptr group,
                                      char const *filename)
{
   return CPX_CALL (readcopyannotations_multicast) (group, filename);
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
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXreadcopymipstarts_multicast (CPXENVGROUPptr group,
                                    char const *filename_str)
{
   return CPX_CALL (readcopymipstarts_multicast) (group, filename_str);
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
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXreadcopyparam_multicast (CPXENVGROUPptr group,
                                char const *filename_str)
{
   return CPX_CALL (readcopyparam_multicast) (group, filename_str);
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
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXreadcopysol_multicast (CPXENVGROUPptr group,
                              char const *filename_str)
{
   return CPX_CALL (readcopysol_multicast) (group, filename_str);
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
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXsetdblparam_multicast (CPXENVGROUPptr group, int whichparam,
                              double newvalue)
{
   return CPX_CALL (setdblparam_multicast) (group, whichparam, newvalue);
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
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXsetlongparam_multicast (CPXENVGROUPptr group, int whichparam,
                               CPXLONG newvalue)
{
   return CPX_CALL (setlongparam_multicast) (group, whichparam, newvalue);
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
CPX_STATIC_INLINE
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
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXtuneparam_join (CPXASYNCptr *handle_p, int *tunestat_p)
{
   return CPX_CALL (tuneparam_join) (handle_p, tunestat_p);
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
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXuserfunction_async (CPXENVptr env, int id, CPXLONG insize,
                           void const *indata, CPXLONG outspace,
                           CPXASYNCptr *handle_p)
{
   return CPX_CALL (userfunction_async) (env, id, insize, indata, outspace, handle_p);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXuserfunction_join (CPXASYNCptr *handle_p, CPXLONG *outsize_p,
                          void *outdata)
{
   return CPX_CALL (userfunction_join) (handle_p, outsize_p, outdata);
}

#endif /* !CPX_NO_REMOTE */



#ifdef __cplusplus
}
#endif

#ifdef _WIN32
#pragma pack(pop)
#endif

#endif /* !CPX_CPLEX_REMOTEMASTERX_H */
