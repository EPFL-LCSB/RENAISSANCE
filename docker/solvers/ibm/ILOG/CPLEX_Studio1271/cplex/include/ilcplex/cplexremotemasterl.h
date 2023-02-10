/* --------------------------------------------------------------------------
 * File: cplexremotemasterl.h
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

#ifndef CPX_CPLEX_REMOTEMASTERL_H
#   define CPX_CPLEX_REMOTEMASTERL_H 1
#include "ilcplex/cplexremotel.h"

#ifdef _WIN32
#pragma pack(push, 8)
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if CPX_CPLEX_L_API_DEFINED > 0 || CPX_CPLEX_L_API_FORCE > 0
CPXLIBAPI
int CPXPUBLIC
   CPXLaddcols_async (CPXCENVptr env, CPXLPptr lp, CPXINT ccnt,
                      CPXLONG nzcnt, double const *obj,
                      CPXLONG const *cmatbeg, CPXINT const *cmatind,
                      double const *cmatval, double const *lb,
                      double const *ub, char const *const *colname,
                      CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLaddcols_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLaddindconstr_async (CPXCENVptr env, CPXLPptr lp, CPXINT indvar,
                           int complemented, CPXINT nzcnt, double rhs,
                           int sense, CPXINT const *linind,
                           double const *linval,
                           char const *indname_str,
                           CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLaddindconstr_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLaddlazyconstraints_async (CPXCENVptr env, CPXLPptr lp,
                                 CPXINT rcnt, CPXLONG nzcnt,
                                 double const *rhs, char const *sense,
                                 CPXLONG const *rmatbeg,
                                 CPXINT const *rmatind,
                                 double const *rmatval,
                                 char const *const *rowname,
                                 CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLaddlazyconstraints_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLaddmipstarts_async (CPXCENVptr env, CPXLPptr lp, int mcnt,
                           CPXLONG nzcnt, CPXLONG const *beg,
                           CPXINT const *varindices,
                           double const *values,
                           int const *effortlevel,
                           char const *const *mipstartname,
                           CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLaddmipstarts_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLaddqconstr_async (CPXCENVptr env, CPXLPptr lp, CPXINT linnzcnt,
                         CPXLONG quadnzcnt, double rhs, int sense,
                         CPXINT const *linind, double const *linval,
                         CPXINT const *quadrow, CPXINT const *quadcol,
                         double const *quadval, char const *lname_str,
                         CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLaddqconstr_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLaddrows_async (CPXCENVptr env, CPXLPptr lp, CPXINT ccnt,
                      CPXINT rcnt, CPXLONG nzcnt, double const *rhs,
                      char const *sense, CPXLONG const *rmatbeg,
                      CPXINT const *rmatind, double const *rmatval,
                      char const *const *colname,
                      char const *const *rowname,
                      CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLaddrows_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLaddsolnpooldivfilter_async (CPXCENVptr env, CPXLPptr lp,
                                   double lower_bound,
                                   double upper_bound, CPXINT nzcnt,
                                   CPXINT const *ind,
                                   double const *weight,
                                   double const *refval,
                                   char const *lname_str,
                                   CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLaddsolnpooldivfilter_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLaddsolnpoolrngfilter_async (CPXCENVptr env, CPXLPptr lp,
                                   double lb, double ub, CPXINT nzcnt,
                                   CPXINT const *ind,
                                   double const *val,
                                   char const *lname_str,
                                   CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLaddsolnpoolrngfilter_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLaddsos_async (CPXCENVptr env, CPXLPptr lp, CPXINT numsos,
                     CPXLONG numsosnz, char const *sostype,
                     CPXLONG const *sosbeg, CPXINT const *sosind,
                     double const *soswt, char const *const *sosname,
                     CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLaddsos_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLaddusercuts_async (CPXCENVptr env, CPXLPptr lp, CPXINT rcnt,
                          CPXLONG nzcnt, double const *rhs,
                          char const *sense, CPXLONG const *rmatbeg,
                          CPXINT const *rmatind, double const *rmatval,
                          char const *const *rowname,
                          CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLaddusercuts_join (CPXASYNCptr *handle_p);


CPXLIBAPI
void CPXPUBLIC
   CPXLasynchandledel (CPXASYNCptr *asynchandle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLasynchandleload (CPXENVptr env, CPXASYNCptr *asynchandle_p,
                        void const *buffer);


CPXLIBAPI
void CPXPUBLIC
   CPXLasynchandlesave (CPXCASYNCptr asynchandle, void *buffer);


CPXLIBAPI
int CPXPUBLIC
   CPXLasynckill (CPXASYNCptr asynchandle);


CPXLIBAPI
int CPXPUBLIC
   CPXLasynctest (CPXASYNCptr asynchandle, int *running_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLbaropt_async (CPXCENVptr env, CPXLPptr lp,
                     CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLbaropt_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLbaropt_multicast (CPXENVGROUPptr group);


CPXLIBAPI
int CPXPUBLIC
   CPXLbasicpresolve_async (CPXCENVptr env, CPXLPptr lp,
                            CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLbasicpresolve_join (CPXASYNCptr *handle_p, double *redlb,
                           double *redub, int *rstat);


CPXLIBAPI
int CPXPUBLIC
   CPXLbendersopt_async (CPXCENVptr env, CPXLPptr lp,
                         CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLbendersopt_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLbendersopt_multicast (CPXENVGROUPptr group);


CPXLIBAPI
int CPXPUBLIC
   CPXLbinvacol_async (CPXCENVptr env, CPXCLPptr lp, CPXINT j,
                       CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLbinvacol_join (CPXASYNCptr *handle_p, double *x);


CPXLIBAPI
int CPXPUBLIC
   CPXLbinvarow_async (CPXCENVptr env, CPXCLPptr lp, CPXINT i,
                       CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLbinvarow_join (CPXASYNCptr *handle_p, double *z);


CPXLIBAPI
int CPXPUBLIC
   CPXLbinvcol_async (CPXCENVptr env, CPXCLPptr lp, CPXINT j,
                      CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLbinvcol_join (CPXASYNCptr *handle_p, double *x);


CPXLIBAPI
int CPXPUBLIC
   CPXLbinvrow_async (CPXCENVptr env, CPXCLPptr lp, CPXINT i,
                      CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLbinvrow_join (CPXASYNCptr *handle_p, double *y);


CPXLIBAPI
int CPXPUBLIC
   CPXLboundsa_async (CPXCENVptr env, CPXCLPptr lp, CPXINT begin,
                      CPXINT end, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLboundsa_join (CPXASYNCptr *handle_p, double *lblower,
                     double *lbupper, double *ublower, double *ubupper);


CPXLIBAPI
int CPXPUBLIC
   CPXLbtran_async (CPXCENVptr env, CPXCLPptr lp, double *y,
                    CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLbtran_join (CPXASYNCptr *handle_p, double *y);


CPXLIBAPI
int CPXPUBLIC
   CPXLcheckdfeas_async (CPXCENVptr env, CPXLPptr lp,
                         CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLcheckdfeas_join (CPXASYNCptr *handle_p, CPXINT *infeas_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLcheckpfeas_async (CPXCENVptr env, CPXLPptr lp,
                         CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLcheckpfeas_join (CPXASYNCptr *handle_p, CPXINT *infeas_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLchecksoln_async (CPXCENVptr env, CPXLPptr lp,
                        CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLchecksoln_join (CPXASYNCptr *handle_p, int *lpstatus_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLchgbds_async (CPXCENVptr env, CPXLPptr lp, CPXINT cnt,
                     CPXINT const *indices, char const *lu,
                     double const *bd, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLchgbds_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLchgbds_multicast (CPXENVGROUPptr group, CPXINT cnt,
                         CPXINT const *indices, char const *lu,
                         double const *bd);


CPXLIBAPI
int CPXPUBLIC
   CPXLchgcoef_async (CPXCENVptr env, CPXLPptr lp, CPXINT i, CPXINT j,
                      double newvalue, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLchgcoef_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLchgcoef_multicast (CPXENVGROUPptr group, CPXINT i, CPXINT j,
                          double newvalue);


CPXLIBAPI
int CPXPUBLIC
   CPXLchgcoeflist_async (CPXCENVptr env, CPXLPptr lp,
                          CPXLONG numcoefs, CPXINT const *rowlist,
                          CPXINT const *collist, double const *vallist,
                          CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLchgcoeflist_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLchgcoeflist_multicast (CPXENVGROUPptr group, CPXLONG numcoefs,
                              CPXINT const *rowlist,
                              CPXINT const *collist,
                              double const *vallist);


CPXLIBAPI
int CPXPUBLIC
   CPXLchgcolname_async (CPXCENVptr env, CPXLPptr lp, CPXINT cnt,
                         CPXINT const *indices,
                         char const *const *newname,
                         CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLchgcolname_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLchgctype_async (CPXCENVptr env, CPXLPptr lp, CPXINT cnt,
                       CPXINT const *indices, char const *xctype,
                       CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLchgctype_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLchgctype_multicast (CPXENVGROUPptr group, CPXINT cnt,
                           CPXINT const *indices, char const *xctype);


CPXLIBAPI
int CPXPUBLIC
   CPXLchgmipstarts_async (CPXCENVptr env, CPXLPptr lp, int mcnt,
                           int const *mipstartindices, CPXLONG nzcnt,
                           CPXLONG const *beg,
                           CPXINT const *varindices,
                           double const *values,
                           int const *effortlevel,
                           CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLchgmipstarts_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLchgmipstarts_multicast (CPXENVGROUPptr group, int mcnt,
                               int const *mipstartindices,
                               CPXLONG nzcnt, CPXLONG const *beg,
                               CPXINT const *varindices,
                               double const *values,
                               int const *effortlevel);


CPXLIBAPI
int CPXPUBLIC
   CPXLchgname_async (CPXCENVptr env, CPXLPptr lp, int key, CPXINT ij,
                      char const *newname_str, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLchgname_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLchgobj_async (CPXCENVptr env, CPXLPptr lp, CPXINT cnt,
                     CPXINT const *indices, double const *values,
                     CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLchgobj_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLchgobj_multicast (CPXENVGROUPptr group, CPXINT cnt,
                         CPXINT const *indices, double const *values);


CPXLIBAPI
int CPXPUBLIC
   CPXLchgobjoffset_async (CPXCENVptr env, CPXLPptr lp, double offset,
                           CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLchgobjoffset_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLchgobjoffset_multicast (CPXENVGROUPptr group, double offset);


CPXLIBAPI
int CPXPUBLIC
   CPXLchgobjsen_async (CPXCENVptr env, CPXLPptr lp, int maxormin,
                        CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLchgobjsen_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLchgobjsen_multicast (CPXENVGROUPptr group, int maxormin);


CPXLIBAPI
int CPXPUBLIC
   CPXLchgprobname_async (CPXCENVptr env, CPXLPptr lp,
                          char const *probname, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLchgprobname_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLchgprobtype_async (CPXCENVptr env, CPXLPptr lp, int type,
                          CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLchgprobtype_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLchgprobtype_multicast (CPXENVGROUPptr group, int type);


CPXLIBAPI
int CPXPUBLIC
   CPXLchgprobtypesolnpool_async (CPXCENVptr env, CPXLPptr lp,
                                  int type, int soln,
                                  CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLchgprobtypesolnpool_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLchgprobtypesolnpool_multicast (CPXENVGROUPptr group, int type,
                                      int soln);


CPXLIBAPI
int CPXPUBLIC
   CPXLchgqpcoef_async (CPXCENVptr env, CPXLPptr lp, CPXINT i,
                        CPXINT j, double newvalue,
                        CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLchgqpcoef_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLchgqpcoef_multicast (CPXENVGROUPptr group, CPXINT i, CPXINT j,
                            double newvalue);


CPXLIBAPI
int CPXPUBLIC
   CPXLchgrhs_async (CPXCENVptr env, CPXLPptr lp, CPXINT cnt,
                     CPXINT const *indices, double const *values,
                     CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLchgrhs_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLchgrhs_multicast (CPXENVGROUPptr group, CPXINT cnt,
                         CPXINT const *indices, double const *values);


CPXLIBAPI
int CPXPUBLIC
   CPXLchgrngval_async (CPXCENVptr env, CPXLPptr lp, CPXINT cnt,
                        CPXINT const *indices, double const *values,
                        CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLchgrngval_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLchgrngval_multicast (CPXENVGROUPptr group, CPXINT cnt,
                            CPXINT const *indices,
                            double const *values);


CPXLIBAPI
int CPXPUBLIC
   CPXLchgrowname_async (CPXCENVptr env, CPXLPptr lp, CPXINT cnt,
                         CPXINT const *indices,
                         char const *const *newname,
                         CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLchgrowname_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLchgsense_async (CPXCENVptr env, CPXLPptr lp, CPXINT cnt,
                       CPXINT const *indices, char const *sense,
                       CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLchgsense_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLchgsense_multicast (CPXENVGROUPptr group, CPXINT cnt,
                           CPXINT const *indices, char const *sense);


CPXLIBAPI
int CPXPUBLIC
   CPXLcleanup_async (CPXCENVptr env, CPXLPptr lp, double eps,
                      CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLcleanup_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLcleanup_multicast (CPXENVGROUPptr group, double eps);


CPXLIBAPI
int CPXPUBLIC
   CPXLcloseCPLEXdisconnect (CPXENVptr *env_p, void *buffer);


CPXLIBAPI
int CPXPUBLIC
   CPXLclpwrite_async (CPXCENVptr env, CPXCLPptr lp,
                       char const *filename_str, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLclpwrite_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLclpwrite_multicast (CPXENVGROUPptr group,
                           char const *filename_str);


CPXLIBAPI
int CPXPUBLIC
   CPXLcompletelp_async (CPXCENVptr env, CPXLPptr lp,
                         CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLcompletelp_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLcompletelp_multicast (CPXENVGROUPptr group);


CPXLIBAPI
int CPXPUBLIC
   CPXLcopybase_async (CPXCENVptr env, CPXLPptr lp, int const *cstat,
                       int const *rstat, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLcopybase_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLcopybasednorms_async (CPXCENVptr env, CPXLPptr lp,
                             int const *cstat, int const *rstat,
                             double const *dnorm,
                             CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLcopybasednorms_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLcopyctype_async (CPXCENVptr env, CPXLPptr lp,
                        char const *xctype, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLcopyctype_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLcopydnorms_async (CPXCENVptr env, CPXLPptr lp,
                         double const *norm, CPXINT const *head,
                         CPXINT len, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLcopydnorms_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLcopydnorms_multicast (CPXENVGROUPptr group, double const *norm,
                             CPXINT const *head, CPXINT len);


CPXLIBAPI
int CPXPUBLIC
   CPXLcopylp_async (CPXCENVptr env, CPXLPptr lp, CPXINT numcols,
                     CPXINT numrows, int objsense,
                     double const *objective, double const *rhs,
                     char const *sense, CPXLONG const *matbeg,
                     CPXINT const *matcnt, CPXINT const *matind,
                     double const *matval, double const *lb,
                     double const *ub, double const *rngval,
                     CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLcopylp_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLcopylp_multicast (CPXENVGROUPptr group, CPXINT numcols,
                         CPXINT numrows, int objsense,
                         double const *objective, double const *rhs,
                         char const *sense, CPXLONG const *matbeg,
                         CPXINT const *matcnt, CPXINT const *matind,
                         double const *matval, double const *lb,
                         double const *ub, double const *rngval);


CPXLIBAPI
int CPXPUBLIC
   CPXLcopylpwnames_async (CPXCENVptr env, CPXLPptr lp, CPXINT numcols,
                           CPXINT numrows, int objsense,
                           double const *objective, double const *rhs,
                           char const *sense, CPXLONG const *matbeg,
                           CPXINT const *matcnt, CPXINT const *matind,
                           double const *matval, double const *lb,
                           double const *ub, double const *rngval,
                           char const *const *colname,
                           char const *const *rowname,
                           CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLcopylpwnames_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLcopynettolp_async (CPXCENVptr env, CPXLPptr lp, CPXCNETptr net,
                          CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLcopynettolp_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLcopynettolp_multicast (CPXENVGROUPptr group);


CPXLIBAPI
int CPXPUBLIC
   CPXLcopyobjname_async (CPXCENVptr env, CPXLPptr lp,
                          char const *objname_str,
                          CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLcopyobjname_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLcopyorder_async (CPXCENVptr env, CPXLPptr lp, CPXINT cnt,
                        CPXINT const *indices, CPXINT const *priority,
                        int const *direction, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLcopyorder_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLcopyorder_multicast (CPXENVGROUPptr group, CPXINT cnt,
                            CPXINT const *indices,
                            CPXINT const *priority,
                            int const *direction);


CPXLIBAPI
int CPXPUBLIC
   CPXLcopypartialbase_async (CPXCENVptr env, CPXLPptr lp, CPXINT ccnt,
                              CPXINT const *cindices, int const *cstat,
                              CPXINT rcnt, CPXINT const *rindices,
                              int const *rstat, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLcopypartialbase_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLcopypartialbase_multicast (CPXENVGROUPptr group, CPXINT ccnt,
                                  CPXINT const *cindices,
                                  int const *cstat, CPXINT rcnt,
                                  CPXINT const *rindices,
                                  int const *rstat);


CPXLIBAPI
int CPXPUBLIC
   CPXLcopypnorms_async (CPXCENVptr env, CPXLPptr lp,
                         double const *cnorm, double const *rnorm,
                         CPXINT len, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLcopypnorms_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLcopyprotected_async (CPXCENVptr env, CPXLPptr lp, CPXINT cnt,
                            CPXINT const *indices,
                            CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLcopyprotected_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLcopyprotected_multicast (CPXENVGROUPptr group, CPXINT cnt,
                                CPXINT const *indices);


CPXLIBAPI
int CPXPUBLIC
   CPXLcopyqpsep_async (CPXCENVptr env, CPXLPptr lp,
                        double const *qsepvec, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLcopyqpsep_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLcopyquad_async (CPXCENVptr env, CPXLPptr lp,
                       CPXLONG const *qmatbeg, CPXINT const *qmatcnt,
                       CPXINT const *qmatind, double const *qmatval,
                       CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLcopyquad_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLcopysos_async (CPXCENVptr env, CPXLPptr lp, CPXINT numsos,
                      CPXLONG numsosnz, char const *sostype,
                      CPXLONG const *sosbeg, CPXINT const *sosind,
                      double const *soswt, char const *const *sosname,
                      CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLcopysos_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLcopystart_async (CPXCENVptr env, CPXLPptr lp, int const *cstat,
                        int const *rstat, double const *cprim,
                        double const *rprim, double const *cdual,
                        double const *rdual, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLcopystart_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLcreateenvgroup (CPXENVGROUPptr *group_p, int nenvs,
                       CPXENVptr const *envs);


CPXLIBAPI
int CPXPUBLIC
   CPXLcrushform_async (CPXCENVptr env, CPXCLPptr lp, CPXINT len,
                        CPXINT const *ind, double const *val,
                        CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLcrushform_join (CPXASYNCptr *handle_p, CPXINT *plen_p,
                       double *poffset_p, CPXINT *pind, double *pval);


CPXLIBAPI
int CPXPUBLIC
   CPXLcrushpi_async (CPXCENVptr env, CPXCLPptr lp, double const *pi,
                      CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLcrushpi_join (CPXASYNCptr *handle_p, double *prepi);


CPXLIBAPI
int CPXPUBLIC
   CPXLcrushx_async (CPXCENVptr env, CPXCLPptr lp, double const *x,
                     CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLcrushx_join (CPXASYNCptr *handle_p, double *prex);


CPXLIBAPI
int CPXPUBLIC
   CPXLdelcols_async (CPXCENVptr env, CPXLPptr lp, CPXINT begin,
                      CPXINT end, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLdelcols_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLdelcols_multicast (CPXENVGROUPptr group, CPXINT begin,
                          CPXINT end);


CPXLIBAPI
int CPXPUBLIC
   CPXLdeldblannotation_multicast (CPXENVGROUPptr group, CPXINT idx);


CPXLIBAPI
int CPXPUBLIC
   CPXLdeldblannotations_multicast (CPXENVGROUPptr group, CPXINT begin,
                                    CPXINT end);


CPXLIBAPI
int CPXPUBLIC
   CPXLdelindconstrs_async (CPXCENVptr env, CPXLPptr lp, CPXINT begin,
                            CPXINT end, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLdelindconstrs_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLdelindconstrs_multicast (CPXENVGROUPptr group, CPXINT begin,
                                CPXINT end);


CPXLIBAPI
int CPXPUBLIC
   CPXLdellongannotation_multicast (CPXENVGROUPptr group, CPXINT idx);


CPXLIBAPI
int CPXPUBLIC
   CPXLdellongannotations_multicast (CPXENVGROUPptr group,
                                     CPXINT begin, CPXINT end);


CPXLIBAPI
int CPXPUBLIC
   CPXLdelmipstarts_async (CPXCENVptr env, CPXLPptr lp, int begin,
                           int end, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLdelmipstarts_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLdelmipstarts_multicast (CPXENVGROUPptr group, int begin,
                               int end);


CPXLIBAPI
int CPXPUBLIC
   CPXLdelnames_async (CPXCENVptr env, CPXLPptr lp,
                       CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLdelnames_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLdelnames_multicast (CPXENVGROUPptr group);


CPXLIBAPI
int CPXPUBLIC
   CPXLdelqconstrs_async (CPXCENVptr env, CPXLPptr lp, CPXINT begin,
                          CPXINT end, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLdelqconstrs_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLdelqconstrs_multicast (CPXENVGROUPptr group, CPXINT begin,
                              CPXINT end);


CPXLIBAPI
int CPXPUBLIC
   CPXLdelrows_async (CPXCENVptr env, CPXLPptr lp, CPXINT begin,
                      CPXINT end, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLdelrows_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLdelrows_multicast (CPXENVGROUPptr group, CPXINT begin,
                          CPXINT end);


CPXLIBAPI
int CPXPUBLIC
   CPXLdelsetcols_async (CPXCENVptr env, CPXLPptr lp, CPXINT *delstat,
                         CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLdelsetcols_join (CPXASYNCptr *handle_p, CPXINT *delstat);


CPXLIBAPI
int CPXPUBLIC
   CPXLdelsetmipstarts_async (CPXCENVptr env, CPXLPptr lp,
                              int *delstat, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLdelsetmipstarts_join (CPXASYNCptr *handle_p, int *delstat);


CPXLIBAPI
int CPXPUBLIC
   CPXLdelsetrows_async (CPXCENVptr env, CPXLPptr lp, CPXINT *delstat,
                         CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLdelsetrows_join (CPXASYNCptr *handle_p, CPXINT *delstat);


CPXLIBAPI
int CPXPUBLIC
   CPXLdelsetsolnpoolfilters_async (CPXCENVptr env, CPXLPptr lp,
                                    int *delstat,
                                    CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLdelsetsolnpoolfilters_join (CPXASYNCptr *handle_p, int *delstat);


CPXLIBAPI
int CPXPUBLIC
   CPXLdelsetsolnpoolsolns_async (CPXCENVptr env, CPXLPptr lp,
                                  int *delstat, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLdelsetsolnpoolsolns_join (CPXASYNCptr *handle_p, int *delstat);


CPXLIBAPI
int CPXPUBLIC
   CPXLdelsetsos_async (CPXCENVptr env, CPXLPptr lp, CPXINT *delset,
                        CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLdelsetsos_join (CPXASYNCptr *handle_p, CPXINT *delset);


CPXLIBAPI
int CPXPUBLIC
   CPXLdelsolnpoolfilters_async (CPXCENVptr env, CPXLPptr lp,
                                 int begin, int end,
                                 CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLdelsolnpoolfilters_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLdelsolnpoolfilters_multicast (CPXENVGROUPptr group, int begin,
                                     int end);


CPXLIBAPI
int CPXPUBLIC
   CPXLdelsolnpoolsolns_async (CPXCENVptr env, CPXLPptr lp, int begin,
                               int end, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLdelsolnpoolsolns_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLdelsolnpoolsolns_multicast (CPXENVGROUPptr group, int begin,
                                   int end);


CPXLIBAPI
int CPXPUBLIC
   CPXLdelsos_async (CPXCENVptr env, CPXLPptr lp, CPXINT begin,
                     CPXINT end, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLdelsos_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLdelsos_multicast (CPXENVGROUPptr group, CPXINT begin,
                         CPXINT end);


CPXLIBAPI
int CPXPUBLIC
   CPXLdjfrompi_async (CPXCENVptr env, CPXCLPptr lp, double const *pi,
                       CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLdjfrompi_join (CPXASYNCptr *handle_p, double *dj);


CPXLIBAPI
int CPXPUBLIC
   CPXLdperwrite_async (CPXCENVptr env, CPXLPptr lp,
                        char const *filename_str, double epsilon,
                        CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLdperwrite_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLdperwrite_multicast (CPXENVGROUPptr group,
                            char const *filename_str, double epsilon);


CPXLIBAPI
int CPXPUBLIC
   CPXLdratio_async (CPXCENVptr env, CPXLPptr lp, CPXINT *indices,
                     CPXINT cnt, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLdratio_join (CPXASYNCptr *handle_p, CPXINT *indices,
                    double *downratio, double *upratio,
                    CPXINT *downenter, CPXINT *upenter,
                    int *downstatus, int *upstatus);


CPXLIBAPI
int CPXPUBLIC
   CPXLdualfarkas_async (CPXCENVptr env, CPXCLPptr lp,
                         CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLdualfarkas_join (CPXASYNCptr *handle_p, double *y,
                        double *proof_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLdualopt_async (CPXCENVptr env, CPXLPptr lp,
                      CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLdualopt_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLdualopt_multicast (CPXENVGROUPptr group);


CPXLIBAPI
int CPXPUBLIC
   CPXLdualwrite_async (CPXCENVptr env, CPXCLPptr lp,
                        char const *filename_str,
                        CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLdualwrite_join (CPXASYNCptr *handle_p, double *objshift_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLEgetsolnpoolfilter_async (CPXCENVptr env, CPXCLPptr lp,
                                 CPXINT space, int which,
                                 CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLEgetsolnpoolfilter_join (CPXASYNCptr *handle_p, int *ftype_p,
                                double *lowercutoff_p,
                                double *upper_cutoff_p,
                                CPXINT *nzcnt_p, CPXINT *ind,
                                double *val, double *refval,
                                CPXINT *surplus_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLembwrite_async (CPXCENVptr env, CPXLPptr lp,
                       char const *filename_str, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLembwrite_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLembwrite_multicast (CPXENVGROUPptr group,
                           char const *filename_str);


CPXLIBAPI
int CPXPUBLIC
   CPXLenvgroupstatus (CPXCENVGROUPptr group, int idx);


CPXLIBAPI
int CPXPUBLIC
   CPXLfeasopt_async (CPXCENVptr env, CPXLPptr lp, double const *rhs,
                      double const *rng, double const *lb,
                      double const *ub, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLfeasopt_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLfeasoptext_async (CPXCENVptr env, CPXLPptr lp, CPXINT grpcnt,
                         CPXLONG concnt, double const *grppref,
                         CPXLONG const *grpbeg, CPXINT const *grpind,
                         char const *grptype, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLfeasoptext_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLfeasoptext_multicast (CPXENVGROUPptr group, CPXINT grpcnt,
                             CPXLONG concnt, double const *grppref,
                             CPXLONG const *grpbeg,
                             CPXINT const *grpind, char const *grptype);


CPXLIBAPI
int CPXPUBLIC
   CPXLfltwrite_async (CPXCENVptr env, CPXCLPptr lp,
                       char const *filename_str, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLfltwrite_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLfltwrite_multicast (CPXENVGROUPptr group,
                           char const *filename_str);


CPXLIBAPI
void CPXPUBLIC
   CPXLfreeenvgroup (CPXENVGROUPptr *group_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLfreelazyconstraints_async (CPXCENVptr env, CPXLPptr lp,
                                  CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLfreelazyconstraints_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLfreelazyconstraints_multicast (CPXENVGROUPptr group);


CPXLIBAPI
int CPXPUBLIC
   CPXLfreepresolve_async (CPXCENVptr env, CPXLPptr lp,
                           CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLfreepresolve_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLfreepresolve_multicast (CPXENVGROUPptr group);


CPXLIBAPI
int CPXPUBLIC
   CPXLfreeusercuts_async (CPXCENVptr env, CPXLPptr lp,
                           CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLfreeusercuts_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLfreeusercuts_multicast (CPXENVGROUPptr group);


CPXLIBAPI
int CPXPUBLIC
   CPXLftran_async (CPXCENVptr env, CPXCLPptr lp, double *x,
                    CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLftran_join (CPXASYNCptr *handle_p, double *x);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetasynchandlesize (CPXCASYNCptr asynchandle);


CPXLIBAPI
void const * CPXPUBLIC
   CPXLgetasynctab (void);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetax_async (CPXCENVptr env, CPXCLPptr lp, CPXINT begin,
                    CPXINT end, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetax_join (CPXASYNCptr *handle_p, double *x);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetbase_async (CPXCENVptr env, CPXCLPptr lp,
                      CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetbase_join (CPXASYNCptr *handle_p, int *cstat, int *rstat);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetbasednorms_async (CPXCENVptr env, CPXCLPptr lp,
                            CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetbasednorms_join (CPXASYNCptr *handle_p, int *cstat,
                           int *rstat, double *dnorm);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetbestobjval_async (CPXCENVptr env, CPXCLPptr lp,
                            CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetbestobjval_join (CPXASYNCptr *handle_p, double *objval_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetbhead_async (CPXCENVptr env, CPXCLPptr lp,
                       CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetbhead_join (CPXASYNCptr *handle_p, CPXINT *head, double *x);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetchgparam_async (CPXCENVptr env, int pspace,
                          CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetchgparam_join (CPXASYNCptr *handle_p, int *cnt_p,
                         int *paramnum, int *surplus_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetcoef_async (CPXCENVptr env, CPXCLPptr lp, CPXINT i, CPXINT j,
                      CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetcoef_join (CPXASYNCptr *handle_p, double *coef_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetcolindex_async (CPXCENVptr env, CPXCLPptr lp,
                          char const *lname_str, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetcolindex_join (CPXASYNCptr *handle_p, CPXINT *index_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetcolinfeas_async (CPXCENVptr env, CPXCLPptr lp,
                           double const *x, CPXINT begin, CPXINT end,
                           CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetcolinfeas_join (CPXASYNCptr *handle_p, double *infeasout);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetcolname_async (CPXCENVptr env, CPXCLPptr lp,
                         CPXSIZE storespace, CPXINT begin, CPXINT end,
                         CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetcolname_join (CPXASYNCptr *handle_p, char  **name,
                        char *namestore, CPXSIZE *surplus_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetcols_async (CPXCENVptr env, CPXCLPptr lp, CPXLONG cmatspace,
                      CPXINT begin, CPXINT end, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetcols_join (CPXASYNCptr *handle_p, CPXLONG *nzcnt_p,
                     CPXLONG *cmatbeg, CPXINT *cmatind,
                     double *cmatval, CPXLONG *surplus_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetconflictext_async (CPXCENVptr env, CPXCLPptr lp, CPXLONG beg,
                             CPXLONG end, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetconflictext_join (CPXASYNCptr *handle_p, int *grpstat);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetctype_async (CPXCENVptr env, CPXCLPptr lp, CPXINT begin,
                       CPXINT end, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetctype_join (CPXASYNCptr *handle_p, char *xctype);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetcutoff_async (CPXCENVptr env, CPXCLPptr lp,
                        CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetcutoff_join (CPXASYNCptr *handle_p, double *cutoff_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetdblparam_async (CPXCENVptr env, int whichparam,
                          CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetdblparam_join (CPXASYNCptr *handle_p, double *value_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetdblquality_async (CPXCENVptr env, CPXCLPptr lp, int what,
                            CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetdblquality_join (CPXASYNCptr *handle_p, double *quality_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetdettime_async (CPXCENVptr env, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetdettime_join (CPXASYNCptr *handle_p, double *dettimestamp_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetdj_async (CPXCENVptr env, CPXCLPptr lp, CPXINT begin,
                    CPXINT end, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetdj_join (CPXASYNCptr *handle_p, double *dj);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetdnorms_async (CPXCENVptr env, CPXCLPptr lp,
                        CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetdnorms_join (CPXASYNCptr *handle_p, double *norm,
                       CPXINT *head, CPXINT *len_p);


CPXLIBAPI
CPXENVptr CPXPUBLIC
   CPXLgetenvgroupenv (CPXCENVGROUPptr group, int idx);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetenvgroupsize (CPXCENVGROUPptr group);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetgrad_async (CPXCENVptr env, CPXCLPptr lp, CPXINT j,
                      CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetgrad_join (CPXASYNCptr *handle_p, CPXINT *head, double *y);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetijdiv_async (CPXCENVptr env, CPXCLPptr lp,
                       CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetijdiv_join (CPXASYNCptr *handle_p, CPXINT *idiv_p,
                      CPXINT *jdiv_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetijrow_async (CPXCENVptr env, CPXCLPptr lp, CPXINT i,
                       CPXINT j, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetijrow_join (CPXASYNCptr *handle_p, CPXINT *row_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetindconstr_async (CPXCENVptr env, CPXCLPptr lp, CPXINT space,
                           CPXINT which, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetindconstr_join (CPXASYNCptr *handle_p, CPXINT *indvar_p,
                          int *complemented_p, CPXINT *nzcnt_p,
                          double *rhs_p, char *sense_p, CPXINT *linind,
                          double *linval, CPXINT *surplus_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetindconstrindex_async (CPXCENVptr env, CPXCLPptr lp,
                                char const *lname_str,
                                CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetindconstrindex_join (CPXASYNCptr *handle_p, CPXINT *index_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetindconstrinfeas_async (CPXCENVptr env, CPXCLPptr lp,
                                 double const *x, CPXINT begin,
                                 CPXINT end, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetindconstrinfeas_join (CPXASYNCptr *handle_p,
                                double *infeasout);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetindconstrname_async (CPXCENVptr env, CPXCLPptr lp,
                               CPXSIZE bufspace, CPXINT which,
                               CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetindconstrname_join (CPXASYNCptr *handle_p, char *buf_str,
                              CPXSIZE *surplus_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetindconstrslack_async (CPXCENVptr env, CPXCLPptr lp,
                                CPXINT begin, CPXINT end,
                                CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetindconstrslack_join (CPXASYNCptr *handle_p, double *indslack);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetinfohandler (CPXCENVptr env, CPXINFOHANDLER  **infohandler_p,
                       void  **handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetintparam_async (CPXCENVptr env, int whichparam,
                          CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetintparam_join (CPXASYNCptr *handle_p, CPXINT *value_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetintquality_async (CPXCENVptr env, CPXCLPptr lp, int what,
                            CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetintquality_join (CPXASYNCptr *handle_p, CPXINT *quality_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetlb_async (CPXCENVptr env, CPXCLPptr lp, CPXINT begin,
                    CPXINT end, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetlb_join (CPXASYNCptr *handle_p, double *lb);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetlongparam_async (CPXCENVptr env, int whichparam,
                           CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetlongparam_join (CPXASYNCptr *handle_p, CPXLONG *value_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetlps (CPXCENVptr env, int capacity, CPXLPptr *lps,
               int *count_p, int *total_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetmiprelgap_async (CPXCENVptr env, CPXCLPptr lp,
                           CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetmiprelgap_join (CPXASYNCptr *handle_p, double *gap_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetmipstartindex_async (CPXCENVptr env, CPXCLPptr lp,
                               char const *lname_str,
                               CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetmipstartindex_join (CPXASYNCptr *handle_p, int *index_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetmipstartname_async (CPXCENVptr env, CPXCLPptr lp,
                              CPXSIZE storesz, int begin, int end,
                              CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetmipstartname_join (CPXASYNCptr *handle_p, char  **name,
                             char *store, CPXSIZE *surplus_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetmipstarts_async (CPXCENVptr env, CPXCLPptr lp,
                           CPXLONG startspace, int begin, int end,
                           CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetmipstarts_join (CPXASYNCptr *handle_p, CPXLONG *nzcnt_p,
                          CPXLONG *beg, CPXINT *varindices,
                          double *values, int *effortlevel,
                          CPXLONG *surplus_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetnumcores_async (CPXCENVptr env, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetnumcores_join (CPXASYNCptr *handle_p, int *numcores_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetnumcuts_async (CPXCENVptr env, CPXCLPptr lp, int cuttype,
                         CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetnumcuts_join (CPXASYNCptr *handle_p, CPXINT *num_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetobj_async (CPXCENVptr env, CPXCLPptr lp, CPXINT begin,
                     CPXINT end, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetobj_join (CPXASYNCptr *handle_p, double *obj);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetobjname_async (CPXCENVptr env, CPXCLPptr lp,
                         CPXSIZE bufspace, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetobjname_join (CPXASYNCptr *handle_p, char *buf_str,
                        CPXSIZE *surplus_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetobjoffset_async (CPXCENVptr env, CPXCLPptr lp,
                           CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetobjoffset_join (CPXASYNCptr *handle_p, double *objoffset_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetobjval_async (CPXCENVptr env, CPXCLPptr lp,
                        CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetobjval_join (CPXASYNCptr *handle_p, double *objval_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetorder_async (CPXCENVptr env, CPXCLPptr lp, CPXINT ordspace,
                       CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetorder_join (CPXASYNCptr *handle_p, CPXINT *cnt_p,
                      CPXINT *indices, CPXINT *priority,
                      int *direction, CPXINT *surplus_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetparamname_async (CPXCENVptr env, int whichparam,
                           CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetparamname_join (CPXASYNCptr *handle_p, char *name_str);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetparamnum_async (CPXCENVptr env, char const *name_str,
                          CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetparamnum_join (CPXASYNCptr *handle_p, int *whichparam_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetparamtype_async (CPXCENVptr env, int whichparam,
                           CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetparamtype_join (CPXASYNCptr *handle_p, int *paramtype);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetpi_async (CPXCENVptr env, CPXCLPptr lp, CPXINT begin,
                    CPXINT end, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetpi_join (CPXASYNCptr *handle_p, double *pi);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetpnorms_async (CPXCENVptr env, CPXCLPptr lp,
                        CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetpnorms_join (CPXASYNCptr *handle_p, double *cnorm,
                       double *rnorm, CPXINT *len_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetprestat_async (CPXCENVptr env, CPXCLPptr lp,
                         CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetprestat_join (CPXASYNCptr *handle_p, int *prestat_p,
                        CPXINT *pcstat, CPXINT *prstat, CPXINT *ocstat,
                        CPXINT *orstat);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetprobname_async (CPXCENVptr env, CPXCLPptr lp,
                          CPXSIZE bufspace, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetprobname_join (CPXASYNCptr *handle_p, char *buf_str,
                         CPXSIZE *surplus_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetprotected_async (CPXCENVptr env, CPXCLPptr lp, CPXINT pspace,
                           CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetprotected_join (CPXASYNCptr *handle_p, CPXINT *cnt_p,
                          CPXINT *indices, CPXINT *surplus_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetqconstr_async (CPXCENVptr env, CPXCLPptr lp, CPXINT linspace,
                         CPXLONG quadspace, CPXINT which,
                         CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetqconstr_join (CPXASYNCptr *handle_p, CPXINT *linnzcnt_p,
                        CPXLONG *quadnzcnt_p, double *rhs_p,
                        char *sense_p, CPXINT *linind, double *linval,
                        CPXINT *linsurplus_p, CPXINT *quadrow,
                        CPXINT *quadcol, double *quadval,
                        CPXLONG *quadsurplus_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetqconstrdslack_async (CPXCENVptr env, CPXCLPptr lp,
                               CPXINT qind, int space,
                               CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetqconstrdslack_join (CPXASYNCptr *handle_p, CPXINT *nz_p,
                              CPXINT *ind, double *val, int *surplus_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetqconstrindex_async (CPXCENVptr env, CPXCLPptr lp,
                              char const *lname_str,
                              CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetqconstrindex_join (CPXASYNCptr *handle_p, CPXINT *index_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetqconstrinfeas_async (CPXCENVptr env, CPXCLPptr lp,
                               double const *x, CPXINT begin,
                               CPXINT end, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetqconstrinfeas_join (CPXASYNCptr *handle_p, double *infeasout);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetqconstrname_async (CPXCENVptr env, CPXCLPptr lp,
                             CPXSIZE bufspace, CPXINT which,
                             CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetqconstrname_join (CPXASYNCptr *handle_p, char *buf_str,
                            CPXSIZE *surplus_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetqconstrslack_async (CPXCENVptr env, CPXCLPptr lp,
                              CPXINT begin, CPXINT end,
                              CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetqconstrslack_join (CPXASYNCptr *handle_p, double *qcslack);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetqpcoef_async (CPXCENVptr env, CPXCLPptr lp, CPXINT rownum,
                        CPXINT colnum, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetqpcoef_join (CPXASYNCptr *handle_p, double *coef_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetquad_async (CPXCENVptr env, CPXCLPptr lp, CPXLONG qmatspace,
                      CPXINT begin, CPXINT end, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetquad_join (CPXASYNCptr *handle_p, CPXLONG *nzcnt_p,
                     CPXLONG *qmatbeg, CPXINT *qmatind,
                     double *qmatval, CPXLONG *surplus_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetray_async (CPXCENVptr env, CPXCLPptr lp,
                     CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetray_join (CPXASYNCptr *handle_p, double *z);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetreconnectinfolen (CPXCENVptr env);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetrhs_async (CPXCENVptr env, CPXCLPptr lp, CPXINT begin,
                     CPXINT end, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetrhs_join (CPXASYNCptr *handle_p, double *rhs);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetrngval_async (CPXCENVptr env, CPXCLPptr lp, CPXINT begin,
                        CPXINT end, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetrngval_join (CPXASYNCptr *handle_p, double *rngval);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetrowindex_async (CPXCENVptr env, CPXCLPptr lp,
                          char const *lname_str, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetrowindex_join (CPXASYNCptr *handle_p, CPXINT *index_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetrowinfeas_async (CPXCENVptr env, CPXCLPptr lp,
                           double const *x, CPXINT begin, CPXINT end,
                           CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetrowinfeas_join (CPXASYNCptr *handle_p, double *infeasout);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetrowname_async (CPXCENVptr env, CPXCLPptr lp,
                         CPXSIZE storespace, CPXINT begin, CPXINT end,
                         CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetrowname_join (CPXASYNCptr *handle_p, char  **name,
                        char *namestore, CPXSIZE *surplus_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetrows_async (CPXCENVptr env, CPXCLPptr lp, CPXLONG rmatspace,
                      CPXINT begin, CPXINT end, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetrows_join (CPXASYNCptr *handle_p, CPXLONG *nzcnt_p,
                     CPXLONG *rmatbeg, CPXINT *rmatind,
                     double *rmatval, CPXLONG *surplus_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetsense_async (CPXCENVptr env, CPXCLPptr lp, CPXINT begin,
                       CPXINT end, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetsense_join (CPXASYNCptr *handle_p, char *sense);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetslack_async (CPXCENVptr env, CPXCLPptr lp, CPXINT begin,
                       CPXINT end, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetslack_join (CPXASYNCptr *handle_p, double *slack);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetsolnpooldblquality_async (CPXCENVptr env, CPXCLPptr lp,
                                    int soln, int what,
                                    CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetsolnpooldblquality_join (CPXASYNCptr *handle_p,
                                   double *quality_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetsolnpooldivfilter_async (CPXCENVptr env, CPXCLPptr lp,
                                   CPXINT space, int which,
                                   CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetsolnpooldivfilter_join (CPXASYNCptr *handle_p,
                                  double *lower_cutoff_p,
                                  double *upper_cutoff_p,
                                  CPXINT *nzcnt_p, CPXINT *ind,
                                  double *val, double *refval,
                                  CPXINT *surplus_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetsolnpoolfilterindex_async (CPXCENVptr env, CPXCLPptr lp,
                                     char const *lname_str,
                                     CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetsolnpoolfilterindex_join (CPXASYNCptr *handle_p,
                                    int *index_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetsolnpoolfiltername_async (CPXCENVptr env, CPXCLPptr lp,
                                    CPXSIZE bufspace, int which,
                                    CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetsolnpoolfiltername_join (CPXASYNCptr *handle_p,
                                   char *buf_str, CPXSIZE *surplus_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetsolnpoolfiltertype_async (CPXCENVptr env, CPXCLPptr lp,
                                    int which, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetsolnpoolfiltertype_join (CPXASYNCptr *handle_p, int *ftype_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetsolnpoolintquality_async (CPXCENVptr env, CPXCLPptr lp,
                                    int soln, int what,
                                    CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetsolnpoolintquality_join (CPXASYNCptr *handle_p,
                                   CPXINT *quality_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetsolnpoolmeanobjval_async (CPXCENVptr env, CPXCLPptr lp,
                                    CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetsolnpoolmeanobjval_join (CPXASYNCptr *handle_p,
                                   double *meanobjval_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetsolnpoolobjval_async (CPXCENVptr env, CPXCLPptr lp, int soln,
                                CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetsolnpoolobjval_join (CPXASYNCptr *handle_p, double *objval_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetsolnpoolqconstrslack_async (CPXCENVptr env, CPXCLPptr lp,
                                      int soln, CPXINT begin,
                                      CPXINT end,
                                      CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetsolnpoolqconstrslack_join (CPXASYNCptr *handle_p,
                                     double *qcslack);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetsolnpoolrngfilter_async (CPXCENVptr env, CPXCLPptr lp,
                                   CPXINT space, int which,
                                   CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetsolnpoolrngfilter_join (CPXASYNCptr *handle_p, double *lb_p,
                                  double *ub_p, CPXINT *nzcnt_p,
                                  CPXINT *ind, double *val,
                                  CPXINT *surplus_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetsolnpoolslack_async (CPXCENVptr env, CPXCLPptr lp, int soln,
                               CPXINT begin, CPXINT end,
                               CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetsolnpoolslack_join (CPXASYNCptr *handle_p, double *slack);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetsolnpoolsolnindex_async (CPXCENVptr env, CPXCLPptr lp,
                                   char const *lname_str,
                                   CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetsolnpoolsolnindex_join (CPXASYNCptr *handle_p, int *index_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetsolnpoolsolnname_async (CPXCENVptr env, CPXCLPptr lp,
                                  CPXSIZE storesz, int which,
                                  CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetsolnpoolsolnname_join (CPXASYNCptr *handle_p, char *store,
                                 CPXSIZE *surplus_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetsolnpoolx_async (CPXCENVptr env, CPXCLPptr lp, int soln,
                           CPXINT begin, CPXINT end,
                           CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetsolnpoolx_join (CPXASYNCptr *handle_p, double *x);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetsos_async (CPXCENVptr env, CPXCLPptr lp, CPXLONG sosspace,
                     CPXINT begin, CPXINT end, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetsos_join (CPXASYNCptr *handle_p, CPXLONG *numsosnz_p,
                    char *sostype, CPXLONG *sosbeg, CPXINT *sosind,
                    double *soswt, CPXLONG *surplus_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetsosindex_async (CPXCENVptr env, CPXCLPptr lp,
                          char const *lname_str, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetsosindex_join (CPXASYNCptr *handle_p, CPXINT *index_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetsosinfeas_async (CPXCENVptr env, CPXCLPptr lp,
                           double const *x, CPXINT begin, CPXINT end,
                           CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetsosinfeas_join (CPXASYNCptr *handle_p, double *infeasout);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetsosname_async (CPXCENVptr env, CPXCLPptr lp,
                         CPXSIZE storespace, CPXINT begin, CPXINT end,
                         CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetsosname_join (CPXASYNCptr *handle_p, char  **name,
                        char *namestore, CPXSIZE *surplus_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgettime_async (CPXCENVptr env, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgettime_join (CPXASYNCptr *handle_p, double *timestamp_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetub_async (CPXCENVptr env, CPXCLPptr lp, CPXINT begin,
                    CPXINT end, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetub_join (CPXASYNCptr *handle_p, double *ub);



CPXLIBAPI
int CPXPUBLIC
   CPXLgetx_async (CPXCENVptr env, CPXCLPptr lp, CPXINT begin,
                   CPXINT end, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetx_join (CPXASYNCptr *handle_p, double *x);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetxqxax_async (CPXCENVptr env, CPXCLPptr lp, CPXINT begin,
                       CPXINT end, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetxqxax_join (CPXASYNCptr *handle_p, double *xqxax);


CPXLIBAPI
int CPXPUBLIC
   CPXLhybbaropt_async (CPXCENVptr env, CPXLPptr lp, int method,
                        CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLhybbaropt_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLhybbaropt_multicast (CPXENVGROUPptr group, int method);


CPXLIBAPI
int CPXPUBLIC
   CPXLhybnetopt_async (CPXCENVptr env, CPXLPptr lp, int method,
                        CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLhybnetopt_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLhybnetopt_multicast (CPXENVGROUPptr group, int method);


CPXLIBAPI
int CPXPUBLIC
   CPXLindconstrslackfromx_async (CPXCENVptr env, CPXCLPptr lp,
                                  double const *x,
                                  CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLindconstrslackfromx_join (CPXASYNCptr *handle_p,
                                 double *indslack);


CPXLIBAPI
int CPXPUBLIC
   CPXLinfodblparam_async (CPXCENVptr env, int whichparam,
                           CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLinfodblparam_join (CPXASYNCptr *handle_p, double *defvalue_p,
                          double *minvalue_p, double *maxvalue_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLinfointparam_async (CPXCENVptr env, int whichparam,
                           CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLinfointparam_join (CPXASYNCptr *handle_p, CPXINT *defvalue_p,
                          CPXINT *minvalue_p, CPXINT *maxvalue_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLinfolongparam_async (CPXCENVptr env, int whichparam,
                            CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLinfolongparam_join (CPXASYNCptr *handle_p, CPXLONG *defvalue_p,
                           CPXLONG *minvalue_p, CPXLONG *maxvalue_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLkilldnorms_async (CPXENVptr env, CPXLPptr lp,
                         CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLkilldnorms_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLkilldnorms_multicast (CPXENVGROUPptr group);


CPXLIBAPI
int CPXPUBLIC
   CPXLkillpnorms_async (CPXENVptr env, CPXLPptr lp,
                         CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLkillpnorms_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLkillpnorms_multicast (CPXENVGROUPptr group);




CPXLIBAPI
int CPXPUBLIC
   CPXLlpopt_async (CPXCENVptr env, CPXLPptr lp, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLlpopt_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLlpopt_multicast (CPXENVGROUPptr group);


CPXLIBAPI
int CPXPUBLIC
   CPXLlprewrite_async (CPXCENVptr env, CPXCLPptr lp,
                        char const *filename_str,
                        CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLlprewrite_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLlprewrite_multicast (CPXENVGROUPptr group,
                            char const *filename_str);


CPXLIBAPI
int CPXPUBLIC
   CPXLlpwrite_async (CPXCENVptr env, CPXCLPptr lp,
                      char const *filename_str, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLlpwrite_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLlpwrite_multicast (CPXENVGROUPptr group,
                          char const *filename_str);


CPXLIBAPI
int CPXPUBLIC
   CPXLmbasewrite_async (CPXCENVptr env, CPXCLPptr lp,
                         char const *filename_str,
                         CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLmbasewrite_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLmbasewrite_multicast (CPXENVGROUPptr group,
                             char const *filename_str);


CPXLIBAPI
int CPXPUBLIC
   CPXLmdleave_async (CPXCENVptr env, CPXLPptr lp,
                      CPXINT const *indices, CPXINT cnt,
                      CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLmdleave_join (CPXASYNCptr *handle_p, double *downratio,
                     double *upratio);


CPXLIBAPI
int CPXPUBLIC
   CPXLmipopt_async (CPXCENVptr env, CPXLPptr lp,
                     CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLmipopt_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLmipopt_multicast (CPXENVGROUPptr group);


CPXLIBAPI
int CPXPUBLIC
   CPXLmpsrewrite_async (CPXCENVptr env, CPXCLPptr lp,
                         char const *filename_str,
                         CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLmpsrewrite_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLmpsrewrite_multicast (CPXENVGROUPptr group,
                             char const *filename_str);


CPXLIBAPI
int CPXPUBLIC
   CPXLmpswrite_async (CPXCENVptr env, CPXCLPptr lp,
                       char const *filename_str, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLmpswrite_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLmpswrite_multicast (CPXENVGROUPptr group,
                           char const *filename_str);


CPXLIBAPI
int CPXPUBLIC
   CPXLNETaddarcs_async (CPXCENVptr env, CPXNETptr net, CPXINT narcs,
                         CPXINT const *fromnode, CPXINT const *tonode,
                         double const *low, double const *up,
                         double const *obj, char const *const *anames,
                         CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLNETaddarcs_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLNETaddnodes_async (CPXCENVptr env, CPXNETptr net, CPXINT nnodes,
                          double const *supply,
                          char const *const *name,
                          CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLNETaddnodes_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLNETbasewrite_async (CPXCENVptr env, CPXCNETptr net,
                           char const *filename_str,
                           CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLNETbasewrite_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLNETbasewrite_multicast (CPXENVGROUPptr group,
                               char const *filename_str);


CPXLIBAPI
int CPXPUBLIC
   CPXLNETchgarcname_async (CPXCENVptr env, CPXNETptr net, CPXINT cnt,
                            CPXINT const *indices,
                            char const *const *newname,
                            CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLNETchgarcname_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLNETchgarcnodes_async (CPXCENVptr env, CPXNETptr net, CPXINT cnt,
                             CPXINT const *indices,
                             CPXINT const *fromnode,
                             CPXINT const *tonode,
                             CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLNETchgarcnodes_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLNETchgarcnodes_multicast (CPXENVGROUPptr group, CPXINT cnt,
                                 CPXINT const *indices,
                                 CPXINT const *fromnode,
                                 CPXINT const *tonode);


CPXLIBAPI
int CPXPUBLIC
   CPXLNETchgbds_async (CPXCENVptr env, CPXNETptr net, CPXINT cnt,
                        CPXINT const *indices, char const *lu,
                        double const *bd, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLNETchgbds_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLNETchgbds_multicast (CPXENVGROUPptr group, CPXINT cnt,
                            CPXINT const *indices, char const *lu,
                            double const *bd);


CPXLIBAPI
int CPXPUBLIC
   CPXLNETchgname_async (CPXCENVptr env, CPXNETptr net, int key,
                         CPXINT vindex, char const *name_str,
                         CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLNETchgname_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLNETchgnodename_async (CPXCENVptr env, CPXNETptr net, CPXINT cnt,
                             CPXINT const *indices,
                             char const *const *newname,
                             CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLNETchgnodename_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLNETchgobj_async (CPXCENVptr env, CPXNETptr net, CPXINT cnt,
                        CPXINT const *indices, double const *obj,
                        CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLNETchgobj_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLNETchgobj_multicast (CPXENVGROUPptr group, CPXINT cnt,
                            CPXINT const *indices, double const *obj);


CPXLIBAPI
int CPXPUBLIC
   CPXLNETchgobjsen_async (CPXCENVptr env, CPXNETptr net, int maxormin,
                           CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLNETchgobjsen_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLNETchgobjsen_multicast (CPXENVGROUPptr group, int maxormin);


CPXLIBAPI
int CPXPUBLIC
   CPXLNETchgsupply_async (CPXCENVptr env, CPXNETptr net, CPXINT cnt,
                           CPXINT const *indices, double const *supply,
                           CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLNETchgsupply_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLNETchgsupply_multicast (CPXENVGROUPptr group, CPXINT cnt,
                               CPXINT const *indices,
                               double const *supply);


CPXLIBAPI
int CPXPUBLIC
   CPXLNETcopybase_async (CPXCENVptr env, CPXNETptr net,
                          int const *astat, int const *nstat,
                          CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLNETcopybase_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLNETcopynet_async (CPXCENVptr env, CPXNETptr net, int objsen,
                         CPXINT nnodes, double const *supply,
                         char const *const *nnames, CPXINT narcs,
                         CPXINT const *fromnode, CPXINT const *tonode,
                         double const *low, double const *up,
                         double const *obj, char const *const *anames,
                         CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLNETcopynet_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLNETdelarcs_async (CPXCENVptr env, CPXNETptr net, CPXINT begin,
                         CPXINT end, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLNETdelarcs_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLNETdelarcs_multicast (CPXENVGROUPptr group, CPXINT begin,
                             CPXINT end);


CPXLIBAPI
int CPXPUBLIC
   CPXLNETdelnodes_async (CPXCENVptr env, CPXNETptr net, CPXINT begin,
                          CPXINT end, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLNETdelnodes_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLNETdelnodes_multicast (CPXENVGROUPptr group, CPXINT begin,
                              CPXINT end);


CPXLIBAPI
int CPXPUBLIC
   CPXLNETdelset_async (CPXCENVptr env, CPXNETptr net,
                        CPXINT *whichnodes, CPXINT *whicharcs,
                        CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLNETdelset_join (CPXASYNCptr *handle_p, CPXINT *whichnodes,
                       CPXINT *whicharcs);


CPXLIBAPI
int CPXPUBLIC
   CPXLNETextract_async (CPXCENVptr env, CPXNETptr net, CPXCLPptr lp,
                         CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLNETextract_join (CPXASYNCptr *handle_p, CPXINT *colmap,
                        CPXINT *rowmap);


CPXLIBAPI
int CPXPUBLIC
   CPXLNETgetarcindex_async (CPXCENVptr env, CPXCNETptr net,
                             char const *lname_str,
                             CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLNETgetarcindex_join (CPXASYNCptr *handle_p, CPXINT *index_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLNETgetarcname_async (CPXCENVptr env, CPXCNETptr net,
                            CPXSIZE namespc, CPXINT begin, CPXINT end,
                            CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLNETgetarcname_join (CPXASYNCptr *handle_p, char  **nnames,
                           char *namestore, CPXSIZE *surplus_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLNETgetarcnodes_async (CPXCENVptr env, CPXCNETptr net,
                             CPXINT begin, CPXINT end,
                             CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLNETgetarcnodes_join (CPXASYNCptr *handle_p, CPXINT *fromnode,
                            CPXINT *tonode);


CPXLIBAPI
int CPXPUBLIC
   CPXLNETgetbase_async (CPXCENVptr env, CPXCNETptr net,
                         CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLNETgetbase_join (CPXASYNCptr *handle_p, int *astat, int *nstat);


CPXLIBAPI
int CPXPUBLIC
   CPXLNETgetdj_async (CPXCENVptr env, CPXCNETptr net, CPXINT begin,
                       CPXINT end, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLNETgetdj_join (CPXASYNCptr *handle_p, double *dj);


CPXLIBAPI
int CPXPUBLIC
   CPXLNETgetlb_async (CPXCENVptr env, CPXCNETptr net, CPXINT begin,
                       CPXINT end, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLNETgetlb_join (CPXASYNCptr *handle_p, double *low);


CPXLIBAPI
int CPXPUBLIC
   CPXLNETgetnodearcs_async (CPXCENVptr env, CPXCNETptr net,
                             CPXINT arcspace, CPXINT begin, CPXINT end,
                             CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLNETgetnodearcs_join (CPXASYNCptr *handle_p, CPXINT *arccnt_p,
                            CPXINT *arcbeg, CPXINT *arc,
                            CPXINT *surplus_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLNETgetnodeindex_async (CPXCENVptr env, CPXCNETptr net,
                              char const *lname_str,
                              CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLNETgetnodeindex_join (CPXASYNCptr *handle_p, CPXINT *index_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLNETgetnodename_async (CPXCENVptr env, CPXCNETptr net,
                             CPXSIZE namespc, CPXINT begin, CPXINT end,
                             CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLNETgetnodename_join (CPXASYNCptr *handle_p, char  **nnames,
                            char *namestore, CPXSIZE *surplus_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLNETgetobj_async (CPXCENVptr env, CPXCNETptr net, CPXINT begin,
                        CPXINT end, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLNETgetobj_join (CPXASYNCptr *handle_p, double *obj);


CPXLIBAPI
int CPXPUBLIC
   CPXLNETgetobjval_async (CPXCENVptr env, CPXCNETptr net,
                           CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLNETgetobjval_join (CPXASYNCptr *handle_p, double *objval_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLNETgetpi_async (CPXCENVptr env, CPXCNETptr net, CPXINT begin,
                       CPXINT end, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLNETgetpi_join (CPXASYNCptr *handle_p, double *pi);


CPXLIBAPI
int CPXPUBLIC
   CPXLNETgetprobname_async (CPXCENVptr env, CPXCNETptr net,
                             CPXSIZE bufspace, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLNETgetprobname_join (CPXASYNCptr *handle_p, char *buf_str,
                            CPXSIZE *surplus_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLNETgetslack_async (CPXCENVptr env, CPXCNETptr net, CPXINT begin,
                          CPXINT end, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLNETgetslack_join (CPXASYNCptr *handle_p, double *slack);


CPXLIBAPI
int CPXPUBLIC
   CPXLNETgetsupply_async (CPXCENVptr env, CPXCNETptr net,
                           CPXINT begin, CPXINT end,
                           CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLNETgetsupply_join (CPXASYNCptr *handle_p, double *supply);


CPXLIBAPI
int CPXPUBLIC
   CPXLNETgetub_async (CPXCENVptr env, CPXCNETptr net, CPXINT begin,
                       CPXINT end, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLNETgetub_join (CPXASYNCptr *handle_p, double *up);


CPXLIBAPI
int CPXPUBLIC
   CPXLNETgetx_async (CPXCENVptr env, CPXCNETptr net, CPXINT begin,
                      CPXINT end, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLNETgetx_join (CPXASYNCptr *handle_p, double *x);


CPXLIBAPI
int CPXPUBLIC
   CPXLNETprimopt_async (CPXCENVptr env, CPXNETptr net,
                         CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLNETprimopt_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLNETprimopt_multicast (CPXENVGROUPptr group);


CPXLIBAPI
int CPXPUBLIC
   CPXLNETreadcopybase_async (CPXCENVptr env, CPXNETptr net,
                              char const *filename_str,
                              CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLNETreadcopybase_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLNETreadcopybase_multicast (CPXENVGROUPptr group,
                                  char const *filename_str);


CPXLIBAPI
int CPXPUBLIC
   CPXLNETreadcopyprob_async (CPXCENVptr env, CPXNETptr net,
                              char const *filename_str,
                              CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLNETreadcopyprob_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLNETreadcopyprob_multicast (CPXENVGROUPptr group,
                                  char const *filename_str);


CPXLIBAPI
int CPXPUBLIC
   CPXLNETsolninfo_async (CPXCENVptr env, CPXCNETptr net,
                          CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLNETsolninfo_join (CPXASYNCptr *handle_p, int *pfeasind_p,
                         int *dfeasind_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLNETsolution_async (CPXCENVptr env, CPXCNETptr net,
                          CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLNETsolution_join (CPXASYNCptr *handle_p, int *netstat_p,
                         double *objval_p, double *x, double *pi,
                         double *slack, double *dj);


CPXLIBAPI
int CPXPUBLIC
   CPXLNETwriteprob_async (CPXCENVptr env, CPXCNETptr net,
                           char const *filename_str,
                           char const *format_str,
                           CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLNETwriteprob_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLNETwriteprob_multicast (CPXENVGROUPptr group,
                               char const *filename_str,
                               char const *format_str);


CPXLIBAPI
int CPXPUBLIC
   CPXLnewcols_async (CPXCENVptr env, CPXLPptr lp, CPXINT ccnt,
                      double const *obj, double const *lb,
                      double const *ub, char const *xctype,
                      char const *const *colname,
                      CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLnewcols_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLnewrows_async (CPXCENVptr env, CPXLPptr lp, CPXINT rcnt,
                      double const *rhs, char const *sense,
                      double const *rngval, char const *const *rowname,
                      CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLnewrows_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLobjsa_async (CPXCENVptr env, CPXCLPptr lp, CPXINT begin,
                    CPXINT end, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLobjsa_join (CPXASYNCptr *handle_p, double *lower, double *upper);


CPXLIBAPI
CPXENVptr CPXPUBLIC
   CPXLopenCPLEXreconnect (int *status_p, void const *buffer);


CPXLIBAPI
CPXENVptr CPXPUBLIC
   CPXLopenCPLEXremote (char const *transport, int argc,
                        char const *const *argv, int *status_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLordread_async (CPXCENVptr env, char const *filename_str,
                      CPXINT numcols, char const *const *colname,
                      CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLordread_join (CPXASYNCptr *handle_p, CPXINT *cnt_p,
                     CPXINT *indices, CPXINT *priority, int *direction);


CPXLIBAPI
int CPXPUBLIC
   CPXLordwrite_async (CPXCENVptr env, CPXCLPptr lp,
                       char const *filename_str, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLordwrite_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLordwrite_multicast (CPXENVGROUPptr group,
                           char const *filename_str);


CPXLIBAPI
int CPXPUBLIC
   CPXLpivot_async (CPXCENVptr env, CPXLPptr lp, CPXINT jenter,
                    CPXINT jleave, int leavestat,
                    CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLpivot_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLpivot_multicast (CPXENVGROUPptr group, CPXINT jenter,
                        CPXINT jleave, int leavestat);


CPXLIBAPI
int CPXPUBLIC
   CPXLpivotin_async (CPXCENVptr env, CPXLPptr lp, CPXINT const *rlist,
                      CPXINT rlen, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLpivotin_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLpivotin_multicast (CPXENVGROUPptr group, CPXINT const *rlist,
                          CPXINT rlen);


CPXLIBAPI
int CPXPUBLIC
   CPXLpivotout_async (CPXCENVptr env, CPXLPptr lp,
                       CPXINT const *clist, CPXINT clen,
                       CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLpivotout_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLpivotout_multicast (CPXENVGROUPptr group, CPXINT const *clist,
                           CPXINT clen);


CPXLIBAPI
int CPXPUBLIC
   CPXLpopulate_async (CPXCENVptr env, CPXLPptr lp,
                       CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLpopulate_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLpopulate_multicast (CPXENVGROUPptr group);


CPXLIBAPI
int CPXPUBLIC
   CPXLpperwrite_async (CPXCENVptr env, CPXLPptr lp,
                        char const *filename_str, double epsilon,
                        CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLpperwrite_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLpperwrite_multicast (CPXENVGROUPptr group,
                            char const *filename_str, double epsilon);


CPXLIBAPI
int CPXPUBLIC
   CPXLpratio_async (CPXCENVptr env, CPXLPptr lp, CPXINT *indices,
                     CPXINT cnt, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLpratio_join (CPXASYNCptr *handle_p, CPXINT *indices,
                    double *downratio, double *upratio,
                    CPXINT *downleave, CPXINT *upleave,
                    int *downleavestatus, int *upleavestatus,
                    int *downstatus, int *upstatus);


CPXLIBAPI
int CPXPUBLIC
   CPXLpreaddrows_async (CPXCENVptr env, CPXLPptr lp, CPXINT rcnt,
                         CPXLONG nzcnt, double const *rhs,
                         char const *sense, CPXLONG const *rmatbeg,
                         CPXINT const *rmatind, double const *rmatval,
                         char const *const *rowname,
                         CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLpreaddrows_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLprechgobj_async (CPXCENVptr env, CPXLPptr lp, CPXINT cnt,
                        CPXINT const *indices, double const *values,
                        CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLprechgobj_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLprechgobj_multicast (CPXENVGROUPptr group, CPXINT cnt,
                            CPXINT const *indices,
                            double const *values);


CPXLIBAPI
int CPXPUBLIC
   CPXLpreslvwrite_async (CPXCENVptr env, CPXLPptr lp,
                          char const *filename_str,
                          CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLpreslvwrite_join (CPXASYNCptr *handle_p, double *objoff_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLpresolve_async (CPXCENVptr env, CPXLPptr lp, int method,
                       CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLpresolve_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLpresolve_multicast (CPXENVGROUPptr group, int method);


CPXLIBAPI
int CPXPUBLIC
   CPXLprimopt_async (CPXCENVptr env, CPXLPptr lp,
                      CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLprimopt_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLprimopt_multicast (CPXENVGROUPptr group);


CPXLIBAPI
int CPXPUBLIC
   CPXLqconstrslackfromx_async (CPXCENVptr env, CPXCLPptr lp,
                                double const *x, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLqconstrslackfromx_join (CPXASYNCptr *handle_p, double *qcslack);


CPXLIBAPI
int CPXPUBLIC
   CPXLqpdjfrompi_async (CPXCENVptr env, CPXCLPptr lp,
                         double const *pi, double const *x,
                         CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLqpdjfrompi_join (CPXASYNCptr *handle_p, double *dj);


CPXLIBAPI
int CPXPUBLIC
   CPXLqpindefcertificate_async (CPXCENVptr env, CPXCLPptr lp,
                                 CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLqpindefcertificate_join (CPXASYNCptr *handle_p, double *x);


CPXLIBAPI
int CPXPUBLIC
   CPXLqpopt_async (CPXCENVptr env, CPXLPptr lp, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLqpopt_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLqpopt_multicast (CPXENVGROUPptr group);


CPXLIBAPI
int CPXPUBLIC
   CPXLqpuncrushpi_async (CPXCENVptr env, CPXCLPptr lp,
                          double const *prepi, double const *x,
                          CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLqpuncrushpi_join (CPXASYNCptr *handle_p, double *pi);


CPXLIBAPI
int CPXPUBLIC
   CPXLreadcopyannotations_multicast (CPXENVGROUPptr group,
                                      char const *filename);


CPXLIBAPI
int CPXPUBLIC
   CPXLreadcopybase_async (CPXCENVptr env, CPXLPptr lp,
                           char const *filename_str,
                           CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLreadcopybase_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLreadcopybase_multicast (CPXENVGROUPptr group,
                               char const *filename_str);


CPXLIBAPI
int CPXPUBLIC
   CPXLreadcopymipstarts_async (CPXCENVptr env, CPXLPptr lp,
                                char const *filename_str,
                                CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLreadcopymipstarts_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLreadcopymipstarts_multicast (CPXENVGROUPptr group,
                                    char const *filename_str);


CPXLIBAPI
int CPXPUBLIC
   CPXLreadcopyorder_async (CPXCENVptr env, CPXLPptr lp,
                            char const *filename_str,
                            CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLreadcopyorder_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLreadcopyorder_multicast (CPXENVGROUPptr group,
                                char const *filename_str);


CPXLIBAPI
int CPXPUBLIC
   CPXLreadcopyparam_async (CPXENVptr env, char const *filename_str,
                            CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLreadcopyparam_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLreadcopyparam_multicast (CPXENVGROUPptr group,
                                char const *filename_str);


CPXLIBAPI
int CPXPUBLIC
   CPXLreadcopyprob_async (CPXCENVptr env, CPXLPptr lp,
                           char const *filename_str,
                           char const *filetype_str,
                           CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLreadcopyprob_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLreadcopyprob_multicast (CPXENVGROUPptr group,
                               char const *filename_str,
                               char const *filetype_str);


CPXLIBAPI
int CPXPUBLIC
   CPXLreadcopysol_async (CPXCENVptr env, CPXLPptr lp,
                          char const *filename_str,
                          CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLreadcopysol_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLreadcopysol_multicast (CPXENVGROUPptr group,
                              char const *filename_str);


CPXLIBAPI
int CPXPUBLIC
   CPXLreadcopysolnpoolfilters_async (CPXCENVptr env, CPXLPptr lp,
                                      char const *filename_str,
                                      CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLreadcopysolnpoolfilters_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLreadcopysolnpoolfilters_multicast (CPXENVGROUPptr group,
                                          char const *filename_str);


CPXLIBAPI
int CPXPUBLIC
   CPXLrefineconflict_async (CPXCENVptr env, CPXLPptr lp,
                             CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLrefineconflict_join (CPXASYNCptr *handle_p,
                            CPXINT *confnumrows_p,
                            CPXINT *confnumcols_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLrefineconflictext_async (CPXCENVptr env, CPXLPptr lp,
                                CPXLONG grpcnt, CPXLONG concnt,
                                double const *grppref,
                                CPXLONG const *grpbeg,
                                CPXINT const *grpind,
                                char const *grptype,
                                CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLrefineconflictext_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLrefineconflictext_multicast (CPXENVGROUPptr group,
                                    CPXLONG grpcnt, CPXLONG concnt,
                                    double const *grppref,
                                    CPXLONG const *grpbeg,
                                    CPXINT const *grpind,
                                    char const *grptype);


CPXLIBAPI
int CPXPUBLIC
   CPXLrefinemipstartconflict_async (CPXCENVptr env, CPXLPptr lp,
                                     int mipstartindex,
                                     CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLrefinemipstartconflict_join (CPXASYNCptr *handle_p,
                                    CPXINT *confnumrows_p,
                                    CPXINT *confnumcols_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLrefinemipstartconflictext_async (CPXCENVptr env, CPXLPptr lp,
                                        int mipstartindex,
                                        CPXLONG grpcnt, CPXLONG concnt,
                                        double const *grppref,
                                        CPXLONG const *grpbeg,
                                        CPXINT const *grpind,
                                        char const *grptype,
                                        CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLrefinemipstartconflictext_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLrefinemipstartconflictext_multicast (CPXENVGROUPptr group,
                                            int mipstartindex,
                                            CPXLONG grpcnt,
                                            CPXLONG concnt,
                                            double const *grppref,
                                            CPXLONG const *grpbeg,
                                            CPXINT const *grpind,
                                            char const *grptype);


CPXLIBAPI
int CPXPUBLIC
   CPXLrhssa_async (CPXCENVptr env, CPXCLPptr lp, CPXINT begin,
                    CPXINT end, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLrhssa_join (CPXASYNCptr *handle_p, double *lower, double *upper);


CPXLIBAPI
int CPXPUBLIC
   CPXLsavwrite_async (CPXCENVptr env, CPXCLPptr lp,
                       char const *filename_str, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLsavwrite_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLsavwrite_multicast (CPXENVGROUPptr group,
                           char const *filename_str);







CPXLIBAPI
int CPXPUBLIC
   CPXLsetdblannotations_multicast (CPXENVGROUPptr group, CPXINT idx,
                                    int objtype, CPXINT cnt,
                                    CPXINT const *indices,
                                    double const *values);


CPXLIBAPI
int CPXPUBLIC
   CPXLsetdblparam_async (CPXENVptr env, int whichparam,
                          double newvalue, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLsetdblparam_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLsetdblparam_multicast (CPXENVGROUPptr group, int whichparam,
                              double newvalue);


CPXLIBAPI
int CPXPUBLIC
   CPXLsetdefaults_async (CPXENVptr env, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLsetdefaults_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLsetdefaults_multicast (CPXENVGROUPptr group);


CPXLIBAPI
int CPXPUBLIC
   CPXLsetinfohandler (CPXENVptr env, CPXINFOHANDLER *infohandler,
                       void *handle);


CPXLIBAPI
int CPXPUBLIC
   CPXLsetintparam_async (CPXENVptr env, int whichparam,
                          CPXINT newvalue, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLsetintparam_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLsetintparam_multicast (CPXENVGROUPptr group, int whichparam,
                              CPXINT newvalue);


CPXLIBAPI
int CPXPUBLIC
   CPXLsetlongannotations_multicast (CPXENVGROUPptr group, CPXINT idx,
                                     int objtype, CPXINT cnt,
                                     CPXINT const *indices,
                                     CPXLONG const *values);


CPXLIBAPI
int CPXPUBLIC
   CPXLsetlongparam_async (CPXENVptr env, int whichparam,
                           CPXLONG newvalue, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLsetlongparam_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLsetlongparam_multicast (CPXENVGROUPptr group, int whichparam,
                               CPXLONG newvalue);


CPXLIBAPI
int CPXPUBLIC
   CPXLsetphase2_async (CPXCENVptr env, CPXLPptr lp,
                        CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLsetphase2_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLsetphase2_multicast (CPXENVGROUPptr group);



CPXLIBAPI
int CPXPUBLIC
   CPXLsiftopt_async (CPXCENVptr env, CPXLPptr lp,
                      CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLsiftopt_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLsiftopt_multicast (CPXENVGROUPptr group);


CPXLIBAPI
int CPXPUBLIC
   CPXLslackfromx_async (CPXCENVptr env, CPXCLPptr lp, double const *x,
                         CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLslackfromx_join (CPXASYNCptr *handle_p, double *slack);


CPXLIBAPI
int CPXPUBLIC
   CPXLsolninfo_async (CPXCENVptr env, CPXCLPptr lp,
                       CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLsolninfo_join (CPXASYNCptr *handle_p, int *solnmethod_p,
                      int *solntype_p, int *pfeasind_p,
                      int *dfeasind_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLsolution_async (CPXCENVptr env, CPXCLPptr lp,
                       CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLsolution_join (CPXASYNCptr *handle_p, int *lpstat_p,
                      double *objval_p, double *x, double *pi,
                      double *slack, double *dj);


CPXLIBAPI
int CPXPUBLIC
   CPXLsolwrite_async (CPXCENVptr env, CPXCLPptr lp,
                       char const *filename_str, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLsolwrite_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLsolwrite_multicast (CPXENVGROUPptr group,
                           char const *filename_str);


CPXLIBAPI
int CPXPUBLIC
   CPXLsolwritesolnpool_async (CPXCENVptr env, CPXCLPptr lp, int soln,
                               char const *filename_str,
                               CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLsolwritesolnpool_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLsolwritesolnpool_multicast (CPXENVGROUPptr group, int soln,
                                   char const *filename_str);


CPXLIBAPI
int CPXPUBLIC
   CPXLsolwritesolnpoolall_async (CPXCENVptr env, CPXCLPptr lp,
                                  char const *filename_str,
                                  CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLsolwritesolnpoolall_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLsolwritesolnpoolall_multicast (CPXENVGROUPptr group,
                                      char const *filename_str);




CPXLIBAPI
int CPXPUBLIC
   CPXLstrongbranch_async (CPXCENVptr env, CPXLPptr lp,
                           CPXINT const *indices, CPXINT cnt,
                           CPXLONG itlim, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLstrongbranch_join (CPXASYNCptr *handle_p, double *downobj,
                          double *upobj);


CPXLIBAPI
int CPXPUBLIC
   CPXLtightenbds_async (CPXCENVptr env, CPXLPptr lp, CPXINT cnt,
                         CPXINT const *indices, char const *lu,
                         double const *bd, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLtightenbds_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLtightenbds_multicast (CPXENVGROUPptr group, CPXINT cnt,
                             CPXINT const *indices, char const *lu,
                             double const *bd);


CPXLIBAPI
int CPXPUBLIC
   CPXLtransportctrldbl (CPXCENVptr env, int ctrl, double *data_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLtransportctrlint (CPXCENVptr env, int ctrl, CPXINT *data_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLtransportctrllong (CPXCENVptr env, int ctrl, CPXLONG *data_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLtuneparam_async (CPXENVptr env, CPXLPptr lp, int intcnt,
                        int const *intnum, int const *intval,
                        int dblcnt, int const *dblnum,
                        double const *dblval, int strcnt,
                        int const *strnum, char const *const *strval,
                        CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLtuneparam_join (CPXASYNCptr *handle_p, int *tunestat_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLuncrushpi_async (CPXCENVptr env, CPXCLPptr lp,
                        double const *prepi, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLuncrushpi_join (CPXASYNCptr *handle_p, double *pi);


CPXLIBAPI
int CPXPUBLIC
   CPXLuncrushx_async (CPXCENVptr env, CPXCLPptr lp,
                       double const *prex, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLuncrushx_join (CPXASYNCptr *handle_p, double *x);


CPXLIBAPI
int CPXPUBLIC
   CPXLunscaleprob_async (CPXCENVptr env, CPXLPptr lp,
                          CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLunscaleprob_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLunscaleprob_multicast (CPXENVGROUPptr group);


CPXLIBAPI
int CPXPUBLIC
   CPXLuserfunction (CPXENVptr env, int id, CPXLONG insize,
                     void const *indata, CPXLONG outspace,
                     CPXLONG *outsize_p, void *outdata);


CPXLIBAPI
int CPXPUBLIC
   CPXLuserfunction_async (CPXENVptr env, int id, CPXLONG insize,
                           void const *indata, CPXLONG outspace,
                           CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLuserfunction_join (CPXASYNCptr *handle_p, CPXLONG *outsize_p,
                          void *outdata);


CPXLIBAPI
int CPXPUBLIC
   CPXLwritemipstarts_async (CPXCENVptr env, CPXCLPptr lp,
                             char const *filename_str, int begin,
                             int end, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLwritemipstarts_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLwritemipstarts_multicast (CPXENVGROUPptr group,
                                 char const *filename_str, int begin,
                                 int end);


CPXLIBAPI
int CPXPUBLIC
   CPXLwriteparam_async (CPXCENVptr env, char const *filename_str,
                         CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLwriteparam_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLwriteparam_multicast (CPXENVGROUPptr group,
                             char const *filename_str);


CPXLIBAPI
int CPXPUBLIC
   CPXLwriteprob_async (CPXCENVptr env, CPXCLPptr lp,
                        char const *filename_str,
                        char const *filetype_str,
                        CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLwriteprob_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLwriteprob_multicast (CPXENVGROUPptr group,
                            char const *filename_str,
                            char const *filetype_str);



#endif /* CPX_CPLEX_L_API_DEFINED > 0 */

#ifdef __cplusplus
}
#endif

#ifdef _WIN32
#pragma pack(pop)
#endif

#endif /* !CPX_CPLEX_REMOTEMASTERL_H */
