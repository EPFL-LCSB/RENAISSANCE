/* --------------------------------------------------------------------------
 * File: cplexremotemasters.h
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

#ifndef CPX_CPLEX_REMOTEMASTERS_H
#   define CPX_CPLEX_REMOTEMASTERS_H 1
#include "ilcplex/cplexremotemaster.h"

#ifdef _WIN32
#pragma pack(push, 8)
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if CPX_CPLEX_S_API_DEFINED > 0 || CPX_CPLEX_S_API_FORCE > 0
CPXLIBAPI
int CPXPUBLIC
   CPXSaddcols_async (CPXCENVptr env, CPXLPptr lp, CPXINT ccnt,
                      CPXINT nzcnt, double const *obj,
                      CPXINT const *cmatbeg, CPXINT const *cmatind,
                      double const *cmatval, double const *lb,
                      double const *ub, char const *const *colname,
                      CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSaddcols_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSaddindconstr_async (CPXCENVptr env, CPXLPptr lp, CPXINT indvar,
                           int complemented, CPXINT nzcnt, double rhs,
                           int sense, CPXINT const *linind,
                           double const *linval,
                           char const *indname_str,
                           CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSaddindconstr_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSaddlazyconstraints_async (CPXCENVptr env, CPXLPptr lp,
                                 CPXINT rcnt, CPXINT nzcnt,
                                 double const *rhs, char const *sense,
                                 CPXINT const *rmatbeg,
                                 CPXINT const *rmatind,
                                 double const *rmatval,
                                 char const *const *rowname,
                                 CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSaddlazyconstraints_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSaddmipstarts_async (CPXCENVptr env, CPXLPptr lp, int mcnt,
                           CPXINT nzcnt, CPXINT const *beg,
                           CPXINT const *varindices,
                           double const *values,
                           int const *effortlevel,
                           char const *const *mipstartname,
                           CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSaddmipstarts_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSaddqconstr_async (CPXCENVptr env, CPXLPptr lp, CPXINT linnzcnt,
                         CPXINT quadnzcnt, double rhs, int sense,
                         CPXINT const *linind, double const *linval,
                         CPXINT const *quadrow, CPXINT const *quadcol,
                         double const *quadval, char const *lname_str,
                         CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSaddqconstr_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSaddrows_async (CPXCENVptr env, CPXLPptr lp, CPXINT ccnt,
                      CPXINT rcnt, CPXINT nzcnt, double const *rhs,
                      char const *sense, CPXINT const *rmatbeg,
                      CPXINT const *rmatind, double const *rmatval,
                      char const *const *colname,
                      char const *const *rowname,
                      CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSaddrows_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSaddsolnpooldivfilter_async (CPXCENVptr env, CPXLPptr lp,
                                   double lower_bound,
                                   double upper_bound, CPXINT nzcnt,
                                   CPXINT const *ind,
                                   double const *weight,
                                   double const *refval,
                                   char const *lname_str,
                                   CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSaddsolnpooldivfilter_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSaddsolnpoolrngfilter_async (CPXCENVptr env, CPXLPptr lp,
                                   double lb, double ub, CPXINT nzcnt,
                                   CPXINT const *ind,
                                   double const *val,
                                   char const *lname_str,
                                   CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSaddsolnpoolrngfilter_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSaddsos_async (CPXCENVptr env, CPXLPptr lp, CPXINT numsos,
                     CPXINT numsosnz, char const *sostype,
                     CPXINT const *sosbeg, CPXINT const *sosind,
                     double const *soswt, char const *const *sosname,
                     CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSaddsos_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSaddusercuts_async (CPXCENVptr env, CPXLPptr lp, CPXINT rcnt,
                          CPXINT nzcnt, double const *rhs,
                          char const *sense, CPXINT const *rmatbeg,
                          CPXINT const *rmatind, double const *rmatval,
                          char const *const *rowname,
                          CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSaddusercuts_join (CPXASYNCptr *handle_p);


CPXLIBAPI
void CPXPUBLIC
   CPXSasynchandledel (CPXASYNCptr *asynchandle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSasynchandleload (CPXENVptr env, CPXASYNCptr *asynchandle_p,
                        void const *buffer);


CPXLIBAPI
void CPXPUBLIC
   CPXSasynchandlesave (CPXCASYNCptr asynchandle, void *buffer);


CPXLIBAPI
int CPXPUBLIC
   CPXSasynckill (CPXASYNCptr asynchandle);


CPXLIBAPI
int CPXPUBLIC
   CPXSasynctest (CPXASYNCptr asynchandle, int *running_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSbaropt_async (CPXCENVptr env, CPXLPptr lp,
                     CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSbaropt_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSbaropt_multicast (CPXENVGROUPptr group);


CPXLIBAPI
int CPXPUBLIC
   CPXSbasicpresolve_async (CPXCENVptr env, CPXLPptr lp,
                            CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSbasicpresolve_join (CPXASYNCptr *handle_p, double *redlb,
                           double *redub, int *rstat);


CPXLIBAPI
int CPXPUBLIC
   CPXSbendersopt_async (CPXCENVptr env, CPXLPptr lp,
                         CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSbendersopt_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSbendersopt_multicast (CPXENVGROUPptr group);


CPXLIBAPI
int CPXPUBLIC
   CPXSbinvacol_async (CPXCENVptr env, CPXCLPptr lp, CPXINT j,
                       CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSbinvacol_join (CPXASYNCptr *handle_p, double *x);


CPXLIBAPI
int CPXPUBLIC
   CPXSbinvarow_async (CPXCENVptr env, CPXCLPptr lp, CPXINT i,
                       CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSbinvarow_join (CPXASYNCptr *handle_p, double *z);


CPXLIBAPI
int CPXPUBLIC
   CPXSbinvcol_async (CPXCENVptr env, CPXCLPptr lp, CPXINT j,
                      CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSbinvcol_join (CPXASYNCptr *handle_p, double *x);


CPXLIBAPI
int CPXPUBLIC
   CPXSbinvrow_async (CPXCENVptr env, CPXCLPptr lp, CPXINT i,
                      CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSbinvrow_join (CPXASYNCptr *handle_p, double *y);


CPXLIBAPI
int CPXPUBLIC
   CPXSboundsa_async (CPXCENVptr env, CPXCLPptr lp, CPXINT begin,
                      CPXINT end, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSboundsa_join (CPXASYNCptr *handle_p, double *lblower,
                     double *lbupper, double *ublower, double *ubupper);


CPXLIBAPI
int CPXPUBLIC
   CPXSbtran_async (CPXCENVptr env, CPXCLPptr lp, double *y,
                    CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSbtran_join (CPXASYNCptr *handle_p, double *y);


CPXLIBAPI
int CPXPUBLIC
   CPXScheckdfeas_async (CPXCENVptr env, CPXLPptr lp,
                         CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXScheckdfeas_join (CPXASYNCptr *handle_p, CPXINT *infeas_p);


CPXLIBAPI
int CPXPUBLIC
   CPXScheckpfeas_async (CPXCENVptr env, CPXLPptr lp,
                         CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXScheckpfeas_join (CPXASYNCptr *handle_p, CPXINT *infeas_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSchecksoln_async (CPXCENVptr env, CPXLPptr lp,
                        CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSchecksoln_join (CPXASYNCptr *handle_p, int *lpstatus_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSchgbds_async (CPXCENVptr env, CPXLPptr lp, CPXINT cnt,
                     CPXINT const *indices, char const *lu,
                     double const *bd, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSchgbds_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSchgbds_multicast (CPXENVGROUPptr group, CPXINT cnt,
                         CPXINT const *indices, char const *lu,
                         double const *bd);


CPXLIBAPI
int CPXPUBLIC
   CPXSchgcoef_async (CPXCENVptr env, CPXLPptr lp, CPXINT i, CPXINT j,
                      double newvalue, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSchgcoef_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSchgcoef_multicast (CPXENVGROUPptr group, CPXINT i, CPXINT j,
                          double newvalue);


CPXLIBAPI
int CPXPUBLIC
   CPXSchgcoeflist_async (CPXCENVptr env, CPXLPptr lp, CPXINT numcoefs,
                          CPXINT const *rowlist, CPXINT const *collist,
                          double const *vallist, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSchgcoeflist_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSchgcoeflist_multicast (CPXENVGROUPptr group, CPXINT numcoefs,
                              CPXINT const *rowlist,
                              CPXINT const *collist,
                              double const *vallist);


CPXLIBAPI
int CPXPUBLIC
   CPXSchgcolname_async (CPXCENVptr env, CPXLPptr lp, CPXINT cnt,
                         CPXINT const *indices,
                         char const *const *newname,
                         CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSchgcolname_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSchgctype_async (CPXCENVptr env, CPXLPptr lp, CPXINT cnt,
                       CPXINT const *indices, char const *xctype,
                       CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSchgctype_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSchgctype_multicast (CPXENVGROUPptr group, CPXINT cnt,
                           CPXINT const *indices, char const *xctype);


CPXLIBAPI
int CPXPUBLIC
   CPXSchgmipstarts_async (CPXCENVptr env, CPXLPptr lp, int mcnt,
                           int const *mipstartindices, CPXINT nzcnt,
                           CPXINT const *beg, CPXINT const *varindices,
                           double const *values,
                           int const *effortlevel,
                           CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSchgmipstarts_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSchgmipstarts_multicast (CPXENVGROUPptr group, int mcnt,
                               int const *mipstartindices,
                               CPXINT nzcnt, CPXINT const *beg,
                               CPXINT const *varindices,
                               double const *values,
                               int const *effortlevel);


CPXLIBAPI
int CPXPUBLIC
   CPXSchgname_async (CPXCENVptr env, CPXLPptr lp, int key, CPXINT ij,
                      char const *newname_str, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSchgname_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSchgobj_async (CPXCENVptr env, CPXLPptr lp, CPXINT cnt,
                     CPXINT const *indices, double const *values,
                     CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSchgobj_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSchgobj_multicast (CPXENVGROUPptr group, CPXINT cnt,
                         CPXINT const *indices, double const *values);


CPXLIBAPI
int CPXPUBLIC
   CPXSchgobjoffset_async (CPXCENVptr env, CPXLPptr lp, double offset,
                           CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSchgobjoffset_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSchgobjoffset_multicast (CPXENVGROUPptr group, double offset);


CPXLIBAPI
int CPXPUBLIC
   CPXSchgobjsen_async (CPXCENVptr env, CPXLPptr lp, int maxormin,
                        CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSchgobjsen_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSchgobjsen_multicast (CPXENVGROUPptr group, int maxormin);


CPXLIBAPI
int CPXPUBLIC
   CPXSchgprobname_async (CPXCENVptr env, CPXLPptr lp,
                          char const *probname, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSchgprobname_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSchgprobtype_async (CPXCENVptr env, CPXLPptr lp, int type,
                          CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSchgprobtype_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSchgprobtype_multicast (CPXENVGROUPptr group, int type);


CPXLIBAPI
int CPXPUBLIC
   CPXSchgprobtypesolnpool_async (CPXCENVptr env, CPXLPptr lp,
                                  int type, int soln,
                                  CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSchgprobtypesolnpool_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSchgprobtypesolnpool_multicast (CPXENVGROUPptr group, int type,
                                      int soln);


CPXLIBAPI
int CPXPUBLIC
   CPXSchgqpcoef_async (CPXCENVptr env, CPXLPptr lp, CPXINT i,
                        CPXINT j, double newvalue,
                        CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSchgqpcoef_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSchgqpcoef_multicast (CPXENVGROUPptr group, CPXINT i, CPXINT j,
                            double newvalue);


CPXLIBAPI
int CPXPUBLIC
   CPXSchgrhs_async (CPXCENVptr env, CPXLPptr lp, CPXINT cnt,
                     CPXINT const *indices, double const *values,
                     CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSchgrhs_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSchgrhs_multicast (CPXENVGROUPptr group, CPXINT cnt,
                         CPXINT const *indices, double const *values);


CPXLIBAPI
int CPXPUBLIC
   CPXSchgrngval_async (CPXCENVptr env, CPXLPptr lp, CPXINT cnt,
                        CPXINT const *indices, double const *values,
                        CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSchgrngval_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSchgrngval_multicast (CPXENVGROUPptr group, CPXINT cnt,
                            CPXINT const *indices,
                            double const *values);


CPXLIBAPI
int CPXPUBLIC
   CPXSchgrowname_async (CPXCENVptr env, CPXLPptr lp, CPXINT cnt,
                         CPXINT const *indices,
                         char const *const *newname,
                         CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSchgrowname_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSchgsense_async (CPXCENVptr env, CPXLPptr lp, CPXINT cnt,
                       CPXINT const *indices, char const *sense,
                       CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSchgsense_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSchgsense_multicast (CPXENVGROUPptr group, CPXINT cnt,
                           CPXINT const *indices, char const *sense);


CPXLIBAPI
int CPXPUBLIC
   CPXScleanup_async (CPXCENVptr env, CPXLPptr lp, double eps,
                      CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXScleanup_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXScleanup_multicast (CPXENVGROUPptr group, double eps);


CPXLIBAPI
int CPXPUBLIC
   CPXScloseCPLEXdisconnect (CPXENVptr *env_p, void *buffer);


CPXLIBAPI
int CPXPUBLIC
   CPXSclpwrite_async (CPXCENVptr env, CPXCLPptr lp,
                       char const *filename_str, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSclpwrite_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSclpwrite_multicast (CPXENVGROUPptr group,
                           char const *filename_str);


CPXLIBAPI
int CPXPUBLIC
   CPXScompletelp_async (CPXCENVptr env, CPXLPptr lp,
                         CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXScompletelp_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXScompletelp_multicast (CPXENVGROUPptr group);


CPXLIBAPI
int CPXPUBLIC
   CPXScopybase_async (CPXCENVptr env, CPXLPptr lp, int const *cstat,
                       int const *rstat, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXScopybase_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXScopybasednorms_async (CPXCENVptr env, CPXLPptr lp,
                             int const *cstat, int const *rstat,
                             double const *dnorm,
                             CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXScopybasednorms_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXScopyctype_async (CPXCENVptr env, CPXLPptr lp,
                        char const *xctype, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXScopyctype_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXScopydnorms_async (CPXCENVptr env, CPXLPptr lp,
                         double const *norm, CPXINT const *head,
                         CPXINT len, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXScopydnorms_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXScopydnorms_multicast (CPXENVGROUPptr group, double const *norm,
                             CPXINT const *head, CPXINT len);


CPXLIBAPI
int CPXPUBLIC
   CPXScopylp_async (CPXCENVptr env, CPXLPptr lp, CPXINT numcols,
                     CPXINT numrows, int objsense,
                     double const *objective, double const *rhs,
                     char const *sense, CPXINT const *matbeg,
                     CPXINT const *matcnt, CPXINT const *matind,
                     double const *matval, double const *lb,
                     double const *ub, double const *rngval,
                     CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXScopylp_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXScopylp_multicast (CPXENVGROUPptr group, CPXINT numcols,
                         CPXINT numrows, int objsense,
                         double const *objective, double const *rhs,
                         char const *sense, CPXINT const *matbeg,
                         CPXINT const *matcnt, CPXINT const *matind,
                         double const *matval, double const *lb,
                         double const *ub, double const *rngval);


CPXLIBAPI
int CPXPUBLIC
   CPXScopylpwnames_async (CPXCENVptr env, CPXLPptr lp, CPXINT numcols,
                           CPXINT numrows, int objsense,
                           double const *objective, double const *rhs,
                           char const *sense, CPXINT const *matbeg,
                           CPXINT const *matcnt, CPXINT const *matind,
                           double const *matval, double const *lb,
                           double const *ub, double const *rngval,
                           char const *const *colname,
                           char const *const *rowname,
                           CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXScopylpwnames_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXScopynettolp_async (CPXCENVptr env, CPXLPptr lp, CPXCNETptr net,
                          CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXScopynettolp_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXScopynettolp_multicast (CPXENVGROUPptr group);


CPXLIBAPI
int CPXPUBLIC
   CPXScopyobjname_async (CPXCENVptr env, CPXLPptr lp,
                          char const *objname_str,
                          CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXScopyobjname_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXScopyorder_async (CPXCENVptr env, CPXLPptr lp, CPXINT cnt,
                        CPXINT const *indices, CPXINT const *priority,
                        int const *direction, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXScopyorder_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXScopyorder_multicast (CPXENVGROUPptr group, CPXINT cnt,
                            CPXINT const *indices,
                            CPXINT const *priority,
                            int const *direction);


CPXLIBAPI
int CPXPUBLIC
   CPXScopypartialbase_async (CPXCENVptr env, CPXLPptr lp, CPXINT ccnt,
                              CPXINT const *cindices, int const *cstat,
                              CPXINT rcnt, CPXINT const *rindices,
                              int const *rstat, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXScopypartialbase_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXScopypartialbase_multicast (CPXENVGROUPptr group, CPXINT ccnt,
                                  CPXINT const *cindices,
                                  int const *cstat, CPXINT rcnt,
                                  CPXINT const *rindices,
                                  int const *rstat);


CPXLIBAPI
int CPXPUBLIC
   CPXScopypnorms_async (CPXCENVptr env, CPXLPptr lp,
                         double const *cnorm, double const *rnorm,
                         CPXINT len, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXScopypnorms_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXScopyprotected_async (CPXCENVptr env, CPXLPptr lp, CPXINT cnt,
                            CPXINT const *indices,
                            CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXScopyprotected_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXScopyprotected_multicast (CPXENVGROUPptr group, CPXINT cnt,
                                CPXINT const *indices);


CPXLIBAPI
int CPXPUBLIC
   CPXScopyqpsep_async (CPXCENVptr env, CPXLPptr lp,
                        double const *qsepvec, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXScopyqpsep_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXScopyquad_async (CPXCENVptr env, CPXLPptr lp,
                       CPXINT const *qmatbeg, CPXINT const *qmatcnt,
                       CPXINT const *qmatind, double const *qmatval,
                       CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXScopyquad_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXScopysos_async (CPXCENVptr env, CPXLPptr lp, CPXINT numsos,
                      CPXINT numsosnz, char const *sostype,
                      CPXINT const *sosbeg, CPXINT const *sosind,
                      double const *soswt, char const *const *sosname,
                      CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXScopysos_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXScopystart_async (CPXCENVptr env, CPXLPptr lp, int const *cstat,
                        int const *rstat, double const *cprim,
                        double const *rprim, double const *cdual,
                        double const *rdual, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXScopystart_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXScreateenvgroup (CPXENVGROUPptr *group_p, int nenvs,
                       CPXENVptr const *envs);


CPXLIBAPI
int CPXPUBLIC
   CPXScrushform_async (CPXCENVptr env, CPXCLPptr lp, CPXINT len,
                        CPXINT const *ind, double const *val,
                        CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXScrushform_join (CPXASYNCptr *handle_p, CPXINT *plen_p,
                       double *poffset_p, CPXINT *pind, double *pval);


CPXLIBAPI
int CPXPUBLIC
   CPXScrushpi_async (CPXCENVptr env, CPXCLPptr lp, double const *pi,
                      CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXScrushpi_join (CPXASYNCptr *handle_p, double *prepi);


CPXLIBAPI
int CPXPUBLIC
   CPXScrushx_async (CPXCENVptr env, CPXCLPptr lp, double const *x,
                     CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXScrushx_join (CPXASYNCptr *handle_p, double *prex);


CPXLIBAPI
int CPXPUBLIC
   CPXSdelcols_async (CPXCENVptr env, CPXLPptr lp, CPXINT begin,
                      CPXINT end, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSdelcols_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSdelcols_multicast (CPXENVGROUPptr group, CPXINT begin,
                          CPXINT end);


CPXLIBAPI
int CPXPUBLIC
   CPXSdeldblannotation_multicast (CPXENVGROUPptr group, CPXINT idx);


CPXLIBAPI
int CPXPUBLIC
   CPXSdeldblannotations_multicast (CPXENVGROUPptr group, CPXINT begin,
                                    CPXINT end);


CPXLIBAPI
int CPXPUBLIC
   CPXSdelindconstrs_async (CPXCENVptr env, CPXLPptr lp, CPXINT begin,
                            CPXINT end, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSdelindconstrs_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSdelindconstrs_multicast (CPXENVGROUPptr group, CPXINT begin,
                                CPXINT end);


CPXLIBAPI
int CPXPUBLIC
   CPXSdellongannotation_multicast (CPXENVGROUPptr group, CPXINT idx);


CPXLIBAPI
int CPXPUBLIC
   CPXSdellongannotations_multicast (CPXENVGROUPptr group,
                                     CPXINT begin, CPXINT end);


CPXLIBAPI
int CPXPUBLIC
   CPXSdelmipstarts_async (CPXCENVptr env, CPXLPptr lp, int begin,
                           int end, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSdelmipstarts_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSdelmipstarts_multicast (CPXENVGROUPptr group, int begin,
                               int end);


CPXLIBAPI
int CPXPUBLIC
   CPXSdelnames_async (CPXCENVptr env, CPXLPptr lp,
                       CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSdelnames_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSdelnames_multicast (CPXENVGROUPptr group);


CPXLIBAPI
int CPXPUBLIC
   CPXSdelqconstrs_async (CPXCENVptr env, CPXLPptr lp, CPXINT begin,
                          CPXINT end, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSdelqconstrs_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSdelqconstrs_multicast (CPXENVGROUPptr group, CPXINT begin,
                              CPXINT end);


CPXLIBAPI
int CPXPUBLIC
   CPXSdelrows_async (CPXCENVptr env, CPXLPptr lp, CPXINT begin,
                      CPXINT end, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSdelrows_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSdelrows_multicast (CPXENVGROUPptr group, CPXINT begin,
                          CPXINT end);


CPXLIBAPI
int CPXPUBLIC
   CPXSdelsetcols_async (CPXCENVptr env, CPXLPptr lp, CPXINT *delstat,
                         CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSdelsetcols_join (CPXASYNCptr *handle_p, CPXINT *delstat);


CPXLIBAPI
int CPXPUBLIC
   CPXSdelsetmipstarts_async (CPXCENVptr env, CPXLPptr lp,
                              int *delstat, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSdelsetmipstarts_join (CPXASYNCptr *handle_p, int *delstat);


CPXLIBAPI
int CPXPUBLIC
   CPXSdelsetrows_async (CPXCENVptr env, CPXLPptr lp, CPXINT *delstat,
                         CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSdelsetrows_join (CPXASYNCptr *handle_p, CPXINT *delstat);


CPXLIBAPI
int CPXPUBLIC
   CPXSdelsetsolnpoolfilters_async (CPXCENVptr env, CPXLPptr lp,
                                    int *delstat,
                                    CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSdelsetsolnpoolfilters_join (CPXASYNCptr *handle_p, int *delstat);


CPXLIBAPI
int CPXPUBLIC
   CPXSdelsetsolnpoolsolns_async (CPXCENVptr env, CPXLPptr lp,
                                  int *delstat, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSdelsetsolnpoolsolns_join (CPXASYNCptr *handle_p, int *delstat);


CPXLIBAPI
int CPXPUBLIC
   CPXSdelsetsos_async (CPXCENVptr env, CPXLPptr lp, CPXINT *delset,
                        CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSdelsetsos_join (CPXASYNCptr *handle_p, CPXINT *delset);


CPXLIBAPI
int CPXPUBLIC
   CPXSdelsolnpoolfilters_async (CPXCENVptr env, CPXLPptr lp,
                                 int begin, int end,
                                 CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSdelsolnpoolfilters_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSdelsolnpoolfilters_multicast (CPXENVGROUPptr group, int begin,
                                     int end);


CPXLIBAPI
int CPXPUBLIC
   CPXSdelsolnpoolsolns_async (CPXCENVptr env, CPXLPptr lp, int begin,
                               int end, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSdelsolnpoolsolns_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSdelsolnpoolsolns_multicast (CPXENVGROUPptr group, int begin,
                                   int end);


CPXLIBAPI
int CPXPUBLIC
   CPXSdelsos_async (CPXCENVptr env, CPXLPptr lp, CPXINT begin,
                     CPXINT end, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSdelsos_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSdelsos_multicast (CPXENVGROUPptr group, CPXINT begin,
                         CPXINT end);


CPXLIBAPI
int CPXPUBLIC
   CPXSdjfrompi_async (CPXCENVptr env, CPXCLPptr lp, double const *pi,
                       CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSdjfrompi_join (CPXASYNCptr *handle_p, double *dj);


CPXLIBAPI
int CPXPUBLIC
   CPXSdperwrite_async (CPXCENVptr env, CPXLPptr lp,
                        char const *filename_str, double epsilon,
                        CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSdperwrite_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSdperwrite_multicast (CPXENVGROUPptr group,
                            char const *filename_str, double epsilon);


CPXLIBAPI
int CPXPUBLIC
   CPXSdratio_async (CPXCENVptr env, CPXLPptr lp, CPXINT *indices,
                     CPXINT cnt, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSdratio_join (CPXASYNCptr *handle_p, CPXINT *indices,
                    double *downratio, double *upratio,
                    CPXINT *downenter, CPXINT *upenter,
                    int *downstatus, int *upstatus);


CPXLIBAPI
int CPXPUBLIC
   CPXSdualfarkas_async (CPXCENVptr env, CPXCLPptr lp,
                         CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSdualfarkas_join (CPXASYNCptr *handle_p, double *y,
                        double *proof_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSdualopt_async (CPXCENVptr env, CPXLPptr lp,
                      CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSdualopt_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSdualopt_multicast (CPXENVGROUPptr group);


CPXLIBAPI
int CPXPUBLIC
   CPXSdualwrite_async (CPXCENVptr env, CPXCLPptr lp,
                        char const *filename_str,
                        CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSdualwrite_join (CPXASYNCptr *handle_p, double *objshift_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSEgetsolnpoolfilter_async (CPXCENVptr env, CPXCLPptr lp,
                                 CPXINT space, int which,
                                 CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSEgetsolnpoolfilter_join (CPXASYNCptr *handle_p, int *ftype_p,
                                double *lowercutoff_p,
                                double *upper_cutoff_p,
                                CPXINT *nzcnt_p, CPXINT *ind,
                                double *val, double *refval,
                                CPXINT *surplus_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSembwrite_async (CPXCENVptr env, CPXLPptr lp,
                       char const *filename_str, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSembwrite_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSembwrite_multicast (CPXENVGROUPptr group,
                           char const *filename_str);


CPXLIBAPI
int CPXPUBLIC
   CPXSenvgroupstatus (CPXCENVGROUPptr group, int idx);


CPXLIBAPI
int CPXPUBLIC
   CPXSfeasopt_async (CPXCENVptr env, CPXLPptr lp, double const *rhs,
                      double const *rng, double const *lb,
                      double const *ub, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSfeasopt_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSfeasoptext_async (CPXCENVptr env, CPXLPptr lp, CPXINT grpcnt,
                         CPXINT concnt, double const *grppref,
                         CPXINT const *grpbeg, CPXINT const *grpind,
                         char const *grptype, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSfeasoptext_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSfeasoptext_multicast (CPXENVGROUPptr group, CPXINT grpcnt,
                             CPXINT concnt, double const *grppref,
                             CPXINT const *grpbeg,
                             CPXINT const *grpind, char const *grptype);


CPXLIBAPI
int CPXPUBLIC
   CPXSfltwrite_async (CPXCENVptr env, CPXCLPptr lp,
                       char const *filename_str, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSfltwrite_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSfltwrite_multicast (CPXENVGROUPptr group,
                           char const *filename_str);


CPXLIBAPI
void CPXPUBLIC
   CPXSfreeenvgroup (CPXENVGROUPptr *group_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSfreelazyconstraints_async (CPXCENVptr env, CPXLPptr lp,
                                  CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSfreelazyconstraints_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSfreelazyconstraints_multicast (CPXENVGROUPptr group);


CPXLIBAPI
int CPXPUBLIC
   CPXSfreepresolve_async (CPXCENVptr env, CPXLPptr lp,
                           CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSfreepresolve_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSfreepresolve_multicast (CPXENVGROUPptr group);


CPXLIBAPI
int CPXPUBLIC
   CPXSfreeusercuts_async (CPXCENVptr env, CPXLPptr lp,
                           CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSfreeusercuts_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSfreeusercuts_multicast (CPXENVGROUPptr group);


CPXLIBAPI
int CPXPUBLIC
   CPXSftran_async (CPXCENVptr env, CPXCLPptr lp, double *x,
                    CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSftran_join (CPXASYNCptr *handle_p, double *x);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetasynchandlesize (CPXCASYNCptr asynchandle);


CPXLIBAPI
void const * CPXPUBLIC
   CPXSgetasynctab (void);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetax_async (CPXCENVptr env, CPXCLPptr lp, CPXINT begin,
                    CPXINT end, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetax_join (CPXASYNCptr *handle_p, double *x);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetbase_async (CPXCENVptr env, CPXCLPptr lp,
                      CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetbase_join (CPXASYNCptr *handle_p, int *cstat, int *rstat);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetbasednorms_async (CPXCENVptr env, CPXCLPptr lp,
                            CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetbasednorms_join (CPXASYNCptr *handle_p, int *cstat,
                           int *rstat, double *dnorm);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetbestobjval_async (CPXCENVptr env, CPXCLPptr lp,
                            CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetbestobjval_join (CPXASYNCptr *handle_p, double *objval_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetbhead_async (CPXCENVptr env, CPXCLPptr lp,
                       CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetbhead_join (CPXASYNCptr *handle_p, CPXINT *head, double *x);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetchgparam_async (CPXCENVptr env, int pspace,
                          CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetchgparam_join (CPXASYNCptr *handle_p, int *cnt_p,
                         int *paramnum, int *surplus_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetcoef_async (CPXCENVptr env, CPXCLPptr lp, CPXINT i, CPXINT j,
                      CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetcoef_join (CPXASYNCptr *handle_p, double *coef_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetcolindex_async (CPXCENVptr env, CPXCLPptr lp,
                          char const *lname_str, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetcolindex_join (CPXASYNCptr *handle_p, CPXINT *index_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetcolinfeas_async (CPXCENVptr env, CPXCLPptr lp,
                           double const *x, CPXINT begin, CPXINT end,
                           CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetcolinfeas_join (CPXASYNCptr *handle_p, double *infeasout);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetcolname_async (CPXCENVptr env, CPXCLPptr lp,
                         CPXSIZE storespace, CPXINT begin, CPXINT end,
                         CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetcolname_join (CPXASYNCptr *handle_p, char  **name,
                        char *namestore, CPXSIZE *surplus_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetcols_async (CPXCENVptr env, CPXCLPptr lp, CPXINT cmatspace,
                      CPXINT begin, CPXINT end, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetcols_join (CPXASYNCptr *handle_p, CPXINT *nzcnt_p,
                     CPXINT *cmatbeg, CPXINT *cmatind, double *cmatval,
                     CPXINT *surplus_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetconflictext_async (CPXCENVptr env, CPXCLPptr lp, CPXINT beg,
                             CPXINT end, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetconflictext_join (CPXASYNCptr *handle_p, int *grpstat);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetctype_async (CPXCENVptr env, CPXCLPptr lp, CPXINT begin,
                       CPXINT end, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetctype_join (CPXASYNCptr *handle_p, char *xctype);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetcutoff_async (CPXCENVptr env, CPXCLPptr lp,
                        CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetcutoff_join (CPXASYNCptr *handle_p, double *cutoff_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetdblparam_async (CPXCENVptr env, int whichparam,
                          CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetdblparam_join (CPXASYNCptr *handle_p, double *value_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetdblquality_async (CPXCENVptr env, CPXCLPptr lp, int what,
                            CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetdblquality_join (CPXASYNCptr *handle_p, double *quality_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetdettime_async (CPXCENVptr env, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetdettime_join (CPXASYNCptr *handle_p, double *dettimestamp_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetdj_async (CPXCENVptr env, CPXCLPptr lp, CPXINT begin,
                    CPXINT end, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetdj_join (CPXASYNCptr *handle_p, double *dj);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetdnorms_async (CPXCENVptr env, CPXCLPptr lp,
                        CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetdnorms_join (CPXASYNCptr *handle_p, double *norm,
                       CPXINT *head, CPXINT *len_p);


CPXLIBAPI
CPXENVptr CPXPUBLIC
   CPXSgetenvgroupenv (CPXCENVGROUPptr group, int idx);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetenvgroupsize (CPXCENVGROUPptr group);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetgrad_async (CPXCENVptr env, CPXCLPptr lp, CPXINT j,
                      CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetgrad_join (CPXASYNCptr *handle_p, CPXINT *head, double *y);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetijdiv_async (CPXCENVptr env, CPXCLPptr lp,
                       CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetijdiv_join (CPXASYNCptr *handle_p, CPXINT *idiv_p,
                      CPXINT *jdiv_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetijrow_async (CPXCENVptr env, CPXCLPptr lp, CPXINT i,
                       CPXINT j, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetijrow_join (CPXASYNCptr *handle_p, CPXINT *row_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetindconstr_async (CPXCENVptr env, CPXCLPptr lp, CPXINT space,
                           CPXINT which, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetindconstr_join (CPXASYNCptr *handle_p, CPXINT *indvar_p,
                          int *complemented_p, CPXINT *nzcnt_p,
                          double *rhs_p, char *sense_p, CPXINT *linind,
                          double *linval, CPXINT *surplus_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetindconstrindex_async (CPXCENVptr env, CPXCLPptr lp,
                                char const *lname_str,
                                CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetindconstrindex_join (CPXASYNCptr *handle_p, CPXINT *index_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetindconstrinfeas_async (CPXCENVptr env, CPXCLPptr lp,
                                 double const *x, CPXINT begin,
                                 CPXINT end, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetindconstrinfeas_join (CPXASYNCptr *handle_p,
                                double *infeasout);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetindconstrname_async (CPXCENVptr env, CPXCLPptr lp,
                               CPXSIZE bufspace, CPXINT which,
                               CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetindconstrname_join (CPXASYNCptr *handle_p, char *buf_str,
                              CPXSIZE *surplus_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetindconstrslack_async (CPXCENVptr env, CPXCLPptr lp,
                                CPXINT begin, CPXINT end,
                                CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetindconstrslack_join (CPXASYNCptr *handle_p, double *indslack);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetinfohandler (CPXCENVptr env, CPXINFOHANDLER  **infohandler_p,
                       void  **handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetintparam_async (CPXCENVptr env, int whichparam,
                          CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetintparam_join (CPXASYNCptr *handle_p, CPXINT *value_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetintquality_async (CPXCENVptr env, CPXCLPptr lp, int what,
                            CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetintquality_join (CPXASYNCptr *handle_p, CPXINT *quality_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetlb_async (CPXCENVptr env, CPXCLPptr lp, CPXINT begin,
                    CPXINT end, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetlb_join (CPXASYNCptr *handle_p, double *lb);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetlongparam_async (CPXCENVptr env, int whichparam,
                           CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetlongparam_join (CPXASYNCptr *handle_p, CPXLONG *value_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetlps (CPXCENVptr env, int capacity, CPXLPptr *lps,
               int *count_p, int *total_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetmiprelgap_async (CPXCENVptr env, CPXCLPptr lp,
                           CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetmiprelgap_join (CPXASYNCptr *handle_p, double *gap_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetmipstartindex_async (CPXCENVptr env, CPXCLPptr lp,
                               char const *lname_str,
                               CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetmipstartindex_join (CPXASYNCptr *handle_p, int *index_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetmipstartname_async (CPXCENVptr env, CPXCLPptr lp,
                              CPXSIZE storesz, int begin, int end,
                              CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetmipstartname_join (CPXASYNCptr *handle_p, char  **name,
                             char *store, CPXSIZE *surplus_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetmipstarts_async (CPXCENVptr env, CPXCLPptr lp,
                           CPXINT startspace, int begin, int end,
                           CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetmipstarts_join (CPXASYNCptr *handle_p, CPXINT *nzcnt_p,
                          CPXINT *beg, CPXINT *varindices,
                          double *values, int *effortlevel,
                          CPXINT *surplus_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetnumcores_async (CPXCENVptr env, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetnumcores_join (CPXASYNCptr *handle_p, int *numcores_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetnumcuts_async (CPXCENVptr env, CPXCLPptr lp, int cuttype,
                         CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetnumcuts_join (CPXASYNCptr *handle_p, CPXINT *num_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetobj_async (CPXCENVptr env, CPXCLPptr lp, CPXINT begin,
                     CPXINT end, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetobj_join (CPXASYNCptr *handle_p, double *obj);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetobjname_async (CPXCENVptr env, CPXCLPptr lp,
                         CPXSIZE bufspace, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetobjname_join (CPXASYNCptr *handle_p, char *buf_str,
                        CPXSIZE *surplus_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetobjoffset_async (CPXCENVptr env, CPXCLPptr lp,
                           CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetobjoffset_join (CPXASYNCptr *handle_p, double *objoffset_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetobjval_async (CPXCENVptr env, CPXCLPptr lp,
                        CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetobjval_join (CPXASYNCptr *handle_p, double *objval_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetorder_async (CPXCENVptr env, CPXCLPptr lp, CPXINT ordspace,
                       CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetorder_join (CPXASYNCptr *handle_p, CPXINT *cnt_p,
                      CPXINT *indices, CPXINT *priority,
                      int *direction, CPXINT *surplus_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetparamname_async (CPXCENVptr env, int whichparam,
                           CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetparamname_join (CPXASYNCptr *handle_p, char *name_str);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetparamnum_async (CPXCENVptr env, char const *name_str,
                          CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetparamnum_join (CPXASYNCptr *handle_p, int *whichparam_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetparamtype_async (CPXCENVptr env, int whichparam,
                           CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetparamtype_join (CPXASYNCptr *handle_p, int *paramtype);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetpi_async (CPXCENVptr env, CPXCLPptr lp, CPXINT begin,
                    CPXINT end, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetpi_join (CPXASYNCptr *handle_p, double *pi);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetpnorms_async (CPXCENVptr env, CPXCLPptr lp,
                        CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetpnorms_join (CPXASYNCptr *handle_p, double *cnorm,
                       double *rnorm, CPXINT *len_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetprestat_async (CPXCENVptr env, CPXCLPptr lp,
                         CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetprestat_join (CPXASYNCptr *handle_p, int *prestat_p,
                        CPXINT *pcstat, CPXINT *prstat, CPXINT *ocstat,
                        CPXINT *orstat);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetprobname_async (CPXCENVptr env, CPXCLPptr lp,
                          CPXSIZE bufspace, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetprobname_join (CPXASYNCptr *handle_p, char *buf_str,
                         CPXSIZE *surplus_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetprotected_async (CPXCENVptr env, CPXCLPptr lp, CPXINT pspace,
                           CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetprotected_join (CPXASYNCptr *handle_p, CPXINT *cnt_p,
                          CPXINT *indices, CPXINT *surplus_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetqconstr_async (CPXCENVptr env, CPXCLPptr lp, CPXINT linspace,
                         CPXINT quadspace, CPXINT which,
                         CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetqconstr_join (CPXASYNCptr *handle_p, CPXINT *linnzcnt_p,
                        CPXINT *quadnzcnt_p, double *rhs_p,
                        char *sense_p, CPXINT *linind, double *linval,
                        CPXINT *linsurplus_p, CPXINT *quadrow,
                        CPXINT *quadcol, double *quadval,
                        CPXINT *quadsurplus_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetqconstrdslack_async (CPXCENVptr env, CPXCLPptr lp,
                               CPXINT qind, int space,
                               CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetqconstrdslack_join (CPXASYNCptr *handle_p, CPXINT *nz_p,
                              CPXINT *ind, double *val, int *surplus_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetqconstrindex_async (CPXCENVptr env, CPXCLPptr lp,
                              char const *lname_str,
                              CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetqconstrindex_join (CPXASYNCptr *handle_p, CPXINT *index_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetqconstrinfeas_async (CPXCENVptr env, CPXCLPptr lp,
                               double const *x, CPXINT begin,
                               CPXINT end, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetqconstrinfeas_join (CPXASYNCptr *handle_p, double *infeasout);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetqconstrname_async (CPXCENVptr env, CPXCLPptr lp,
                             CPXSIZE bufspace, CPXINT which,
                             CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetqconstrname_join (CPXASYNCptr *handle_p, char *buf_str,
                            CPXSIZE *surplus_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetqconstrslack_async (CPXCENVptr env, CPXCLPptr lp,
                              CPXINT begin, CPXINT end,
                              CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetqconstrslack_join (CPXASYNCptr *handle_p, double *qcslack);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetqpcoef_async (CPXCENVptr env, CPXCLPptr lp, CPXINT rownum,
                        CPXINT colnum, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetqpcoef_join (CPXASYNCptr *handle_p, double *coef_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetquad_async (CPXCENVptr env, CPXCLPptr lp, CPXINT qmatspace,
                      CPXINT begin, CPXINT end, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetquad_join (CPXASYNCptr *handle_p, CPXINT *nzcnt_p,
                     CPXINT *qmatbeg, CPXINT *qmatind, double *qmatval,
                     CPXINT *surplus_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetray_async (CPXCENVptr env, CPXCLPptr lp,
                     CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetray_join (CPXASYNCptr *handle_p, double *z);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetreconnectinfolen (CPXCENVptr env);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetrhs_async (CPXCENVptr env, CPXCLPptr lp, CPXINT begin,
                     CPXINT end, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetrhs_join (CPXASYNCptr *handle_p, double *rhs);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetrngval_async (CPXCENVptr env, CPXCLPptr lp, CPXINT begin,
                        CPXINT end, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetrngval_join (CPXASYNCptr *handle_p, double *rngval);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetrowindex_async (CPXCENVptr env, CPXCLPptr lp,
                          char const *lname_str, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetrowindex_join (CPXASYNCptr *handle_p, CPXINT *index_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetrowinfeas_async (CPXCENVptr env, CPXCLPptr lp,
                           double const *x, CPXINT begin, CPXINT end,
                           CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetrowinfeas_join (CPXASYNCptr *handle_p, double *infeasout);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetrowname_async (CPXCENVptr env, CPXCLPptr lp,
                         CPXSIZE storespace, CPXINT begin, CPXINT end,
                         CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetrowname_join (CPXASYNCptr *handle_p, char  **name,
                        char *namestore, CPXSIZE *surplus_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetrows_async (CPXCENVptr env, CPXCLPptr lp, CPXINT rmatspace,
                      CPXINT begin, CPXINT end, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetrows_join (CPXASYNCptr *handle_p, CPXINT *nzcnt_p,
                     CPXINT *rmatbeg, CPXINT *rmatind, double *rmatval,
                     CPXINT *surplus_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetsense_async (CPXCENVptr env, CPXCLPptr lp, CPXINT begin,
                       CPXINT end, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetsense_join (CPXASYNCptr *handle_p, char *sense);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetslack_async (CPXCENVptr env, CPXCLPptr lp, CPXINT begin,
                       CPXINT end, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetslack_join (CPXASYNCptr *handle_p, double *slack);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetsolnpooldblquality_async (CPXCENVptr env, CPXCLPptr lp,
                                    int soln, int what,
                                    CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetsolnpooldblquality_join (CPXASYNCptr *handle_p,
                                   double *quality_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetsolnpooldivfilter_async (CPXCENVptr env, CPXCLPptr lp,
                                   CPXINT space, int which,
                                   CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetsolnpooldivfilter_join (CPXASYNCptr *handle_p,
                                  double *lower_cutoff_p,
                                  double *upper_cutoff_p,
                                  CPXINT *nzcnt_p, CPXINT *ind,
                                  double *val, double *refval,
                                  CPXINT *surplus_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetsolnpoolfilterindex_async (CPXCENVptr env, CPXCLPptr lp,
                                     char const *lname_str,
                                     CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetsolnpoolfilterindex_join (CPXASYNCptr *handle_p,
                                    int *index_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetsolnpoolfiltername_async (CPXCENVptr env, CPXCLPptr lp,
                                    CPXSIZE bufspace, int which,
                                    CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetsolnpoolfiltername_join (CPXASYNCptr *handle_p,
                                   char *buf_str, CPXSIZE *surplus_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetsolnpoolfiltertype_async (CPXCENVptr env, CPXCLPptr lp,
                                    int which, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetsolnpoolfiltertype_join (CPXASYNCptr *handle_p, int *ftype_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetsolnpoolintquality_async (CPXCENVptr env, CPXCLPptr lp,
                                    int soln, int what,
                                    CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetsolnpoolintquality_join (CPXASYNCptr *handle_p,
                                   CPXINT *quality_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetsolnpoolmeanobjval_async (CPXCENVptr env, CPXCLPptr lp,
                                    CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetsolnpoolmeanobjval_join (CPXASYNCptr *handle_p,
                                   double *meanobjval_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetsolnpoolobjval_async (CPXCENVptr env, CPXCLPptr lp, int soln,
                                CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetsolnpoolobjval_join (CPXASYNCptr *handle_p, double *objval_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetsolnpoolqconstrslack_async (CPXCENVptr env, CPXCLPptr lp,
                                      int soln, CPXINT begin,
                                      CPXINT end,
                                      CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetsolnpoolqconstrslack_join (CPXASYNCptr *handle_p,
                                     double *qcslack);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetsolnpoolrngfilter_async (CPXCENVptr env, CPXCLPptr lp,
                                   CPXINT space, int which,
                                   CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetsolnpoolrngfilter_join (CPXASYNCptr *handle_p, double *lb_p,
                                  double *ub_p, CPXINT *nzcnt_p,
                                  CPXINT *ind, double *val,
                                  CPXINT *surplus_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetsolnpoolslack_async (CPXCENVptr env, CPXCLPptr lp, int soln,
                               CPXINT begin, CPXINT end,
                               CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetsolnpoolslack_join (CPXASYNCptr *handle_p, double *slack);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetsolnpoolsolnindex_async (CPXCENVptr env, CPXCLPptr lp,
                                   char const *lname_str,
                                   CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetsolnpoolsolnindex_join (CPXASYNCptr *handle_p, int *index_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetsolnpoolsolnname_async (CPXCENVptr env, CPXCLPptr lp,
                                  CPXSIZE storesz, int which,
                                  CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetsolnpoolsolnname_join (CPXASYNCptr *handle_p, char *store,
                                 CPXSIZE *surplus_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetsolnpoolx_async (CPXCENVptr env, CPXCLPptr lp, int soln,
                           CPXINT begin, CPXINT end,
                           CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetsolnpoolx_join (CPXASYNCptr *handle_p, double *x);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetsos_async (CPXCENVptr env, CPXCLPptr lp, CPXINT sosspace,
                     CPXINT begin, CPXINT end, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetsos_join (CPXASYNCptr *handle_p, CPXINT *numsosnz_p,
                    char *sostype, CPXINT *sosbeg, CPXINT *sosind,
                    double *soswt, CPXINT *surplus_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetsosindex_async (CPXCENVptr env, CPXCLPptr lp,
                          char const *lname_str, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetsosindex_join (CPXASYNCptr *handle_p, CPXINT *index_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetsosinfeas_async (CPXCENVptr env, CPXCLPptr lp,
                           double const *x, CPXINT begin, CPXINT end,
                           CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetsosinfeas_join (CPXASYNCptr *handle_p, double *infeasout);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetsosname_async (CPXCENVptr env, CPXCLPptr lp,
                         CPXSIZE storespace, CPXINT begin, CPXINT end,
                         CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetsosname_join (CPXASYNCptr *handle_p, char  **name,
                        char *namestore, CPXSIZE *surplus_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgettime_async (CPXCENVptr env, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgettime_join (CPXASYNCptr *handle_p, double *timestamp_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetub_async (CPXCENVptr env, CPXCLPptr lp, CPXINT begin,
                    CPXINT end, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetub_join (CPXASYNCptr *handle_p, double *ub);



CPXLIBAPI
int CPXPUBLIC
   CPXSgetx_async (CPXCENVptr env, CPXCLPptr lp, CPXINT begin,
                   CPXINT end, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetx_join (CPXASYNCptr *handle_p, double *x);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetxqxax_async (CPXCENVptr env, CPXCLPptr lp, CPXINT begin,
                       CPXINT end, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetxqxax_join (CPXASYNCptr *handle_p, double *xqxax);


CPXLIBAPI
int CPXPUBLIC
   CPXShybbaropt_async (CPXCENVptr env, CPXLPptr lp, int method,
                        CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXShybbaropt_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXShybbaropt_multicast (CPXENVGROUPptr group, int method);


CPXLIBAPI
int CPXPUBLIC
   CPXShybnetopt_async (CPXCENVptr env, CPXLPptr lp, int method,
                        CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXShybnetopt_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXShybnetopt_multicast (CPXENVGROUPptr group, int method);


CPXLIBAPI
int CPXPUBLIC
   CPXSindconstrslackfromx_async (CPXCENVptr env, CPXCLPptr lp,
                                  double const *x,
                                  CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSindconstrslackfromx_join (CPXASYNCptr *handle_p,
                                 double *indslack);


CPXLIBAPI
int CPXPUBLIC
   CPXSinfodblparam_async (CPXCENVptr env, int whichparam,
                           CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSinfodblparam_join (CPXASYNCptr *handle_p, double *defvalue_p,
                          double *minvalue_p, double *maxvalue_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSinfointparam_async (CPXCENVptr env, int whichparam,
                           CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSinfointparam_join (CPXASYNCptr *handle_p, CPXINT *defvalue_p,
                          CPXINT *minvalue_p, CPXINT *maxvalue_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSinfolongparam_async (CPXCENVptr env, int whichparam,
                            CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSinfolongparam_join (CPXASYNCptr *handle_p, CPXLONG *defvalue_p,
                           CPXLONG *minvalue_p, CPXLONG *maxvalue_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSkilldnorms_async (CPXENVptr env, CPXLPptr lp,
                         CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSkilldnorms_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSkilldnorms_multicast (CPXENVGROUPptr group);


CPXLIBAPI
int CPXPUBLIC
   CPXSkillpnorms_async (CPXENVptr env, CPXLPptr lp,
                         CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSkillpnorms_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSkillpnorms_multicast (CPXENVGROUPptr group);




CPXLIBAPI
int CPXPUBLIC
   CPXSlpopt_async (CPXCENVptr env, CPXLPptr lp, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSlpopt_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSlpopt_multicast (CPXENVGROUPptr group);


CPXLIBAPI
int CPXPUBLIC
   CPXSlprewrite_async (CPXCENVptr env, CPXCLPptr lp,
                        char const *filename_str,
                        CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSlprewrite_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSlprewrite_multicast (CPXENVGROUPptr group,
                            char const *filename_str);


CPXLIBAPI
int CPXPUBLIC
   CPXSlpwrite_async (CPXCENVptr env, CPXCLPptr lp,
                      char const *filename_str, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSlpwrite_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSlpwrite_multicast (CPXENVGROUPptr group,
                          char const *filename_str);


CPXLIBAPI
int CPXPUBLIC
   CPXSmbasewrite_async (CPXCENVptr env, CPXCLPptr lp,
                         char const *filename_str,
                         CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSmbasewrite_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSmbasewrite_multicast (CPXENVGROUPptr group,
                             char const *filename_str);


CPXLIBAPI
int CPXPUBLIC
   CPXSmdleave_async (CPXCENVptr env, CPXLPptr lp,
                      CPXINT const *indices, CPXINT cnt,
                      CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSmdleave_join (CPXASYNCptr *handle_p, double *downratio,
                     double *upratio);


CPXLIBAPI
int CPXPUBLIC
   CPXSmipopt_async (CPXCENVptr env, CPXLPptr lp,
                     CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSmipopt_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSmipopt_multicast (CPXENVGROUPptr group);


CPXLIBAPI
int CPXPUBLIC
   CPXSmpsrewrite_async (CPXCENVptr env, CPXCLPptr lp,
                         char const *filename_str,
                         CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSmpsrewrite_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSmpsrewrite_multicast (CPXENVGROUPptr group,
                             char const *filename_str);


CPXLIBAPI
int CPXPUBLIC
   CPXSmpswrite_async (CPXCENVptr env, CPXCLPptr lp,
                       char const *filename_str, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSmpswrite_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSmpswrite_multicast (CPXENVGROUPptr group,
                           char const *filename_str);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETaddarcs_async (CPXCENVptr env, CPXNETptr net, CPXINT narcs,
                         CPXINT const *fromnode, CPXINT const *tonode,
                         double const *low, double const *up,
                         double const *obj, char const *const *anames,
                         CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETaddarcs_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETaddnodes_async (CPXCENVptr env, CPXNETptr net, CPXINT nnodes,
                          double const *supply,
                          char const *const *name,
                          CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETaddnodes_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETbasewrite_async (CPXCENVptr env, CPXCNETptr net,
                           char const *filename_str,
                           CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETbasewrite_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETbasewrite_multicast (CPXENVGROUPptr group,
                               char const *filename_str);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETchgarcname_async (CPXCENVptr env, CPXNETptr net, CPXINT cnt,
                            CPXINT const *indices,
                            char const *const *newname,
                            CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETchgarcname_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETchgarcnodes_async (CPXCENVptr env, CPXNETptr net, CPXINT cnt,
                             CPXINT const *indices,
                             CPXINT const *fromnode,
                             CPXINT const *tonode,
                             CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETchgarcnodes_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETchgarcnodes_multicast (CPXENVGROUPptr group, CPXINT cnt,
                                 CPXINT const *indices,
                                 CPXINT const *fromnode,
                                 CPXINT const *tonode);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETchgbds_async (CPXCENVptr env, CPXNETptr net, CPXINT cnt,
                        CPXINT const *indices, char const *lu,
                        double const *bd, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETchgbds_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETchgbds_multicast (CPXENVGROUPptr group, CPXINT cnt,
                            CPXINT const *indices, char const *lu,
                            double const *bd);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETchgname_async (CPXCENVptr env, CPXNETptr net, int key,
                         CPXINT vindex, char const *name_str,
                         CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETchgname_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETchgnodename_async (CPXCENVptr env, CPXNETptr net, CPXINT cnt,
                             CPXINT const *indices,
                             char const *const *newname,
                             CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETchgnodename_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETchgobj_async (CPXCENVptr env, CPXNETptr net, CPXINT cnt,
                        CPXINT const *indices, double const *obj,
                        CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETchgobj_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETchgobj_multicast (CPXENVGROUPptr group, CPXINT cnt,
                            CPXINT const *indices, double const *obj);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETchgobjsen_async (CPXCENVptr env, CPXNETptr net, int maxormin,
                           CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETchgobjsen_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETchgobjsen_multicast (CPXENVGROUPptr group, int maxormin);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETchgsupply_async (CPXCENVptr env, CPXNETptr net, CPXINT cnt,
                           CPXINT const *indices, double const *supply,
                           CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETchgsupply_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETchgsupply_multicast (CPXENVGROUPptr group, CPXINT cnt,
                               CPXINT const *indices,
                               double const *supply);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETcopybase_async (CPXCENVptr env, CPXNETptr net,
                          int const *astat, int const *nstat,
                          CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETcopybase_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETcopynet_async (CPXCENVptr env, CPXNETptr net, int objsen,
                         CPXINT nnodes, double const *supply,
                         char const *const *nnames, CPXINT narcs,
                         CPXINT const *fromnode, CPXINT const *tonode,
                         double const *low, double const *up,
                         double const *obj, char const *const *anames,
                         CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETcopynet_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETdelarcs_async (CPXCENVptr env, CPXNETptr net, CPXINT begin,
                         CPXINT end, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETdelarcs_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETdelarcs_multicast (CPXENVGROUPptr group, CPXINT begin,
                             CPXINT end);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETdelnodes_async (CPXCENVptr env, CPXNETptr net, CPXINT begin,
                          CPXINT end, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETdelnodes_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETdelnodes_multicast (CPXENVGROUPptr group, CPXINT begin,
                              CPXINT end);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETdelset_async (CPXCENVptr env, CPXNETptr net,
                        CPXINT *whichnodes, CPXINT *whicharcs,
                        CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETdelset_join (CPXASYNCptr *handle_p, CPXINT *whichnodes,
                       CPXINT *whicharcs);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETextract_async (CPXCENVptr env, CPXNETptr net, CPXCLPptr lp,
                         CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETextract_join (CPXASYNCptr *handle_p, CPXINT *colmap,
                        CPXINT *rowmap);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETgetarcindex_async (CPXCENVptr env, CPXCNETptr net,
                             char const *lname_str,
                             CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETgetarcindex_join (CPXASYNCptr *handle_p, CPXINT *index_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETgetarcname_async (CPXCENVptr env, CPXCNETptr net,
                            CPXSIZE namespc, CPXINT begin, CPXINT end,
                            CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETgetarcname_join (CPXASYNCptr *handle_p, char  **nnames,
                           char *namestore, CPXSIZE *surplus_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETgetarcnodes_async (CPXCENVptr env, CPXCNETptr net,
                             CPXINT begin, CPXINT end,
                             CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETgetarcnodes_join (CPXASYNCptr *handle_p, CPXINT *fromnode,
                            CPXINT *tonode);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETgetbase_async (CPXCENVptr env, CPXCNETptr net,
                         CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETgetbase_join (CPXASYNCptr *handle_p, int *astat, int *nstat);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETgetdj_async (CPXCENVptr env, CPXCNETptr net, CPXINT begin,
                       CPXINT end, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETgetdj_join (CPXASYNCptr *handle_p, double *dj);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETgetlb_async (CPXCENVptr env, CPXCNETptr net, CPXINT begin,
                       CPXINT end, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETgetlb_join (CPXASYNCptr *handle_p, double *low);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETgetnodearcs_async (CPXCENVptr env, CPXCNETptr net,
                             CPXINT arcspace, CPXINT begin, CPXINT end,
                             CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETgetnodearcs_join (CPXASYNCptr *handle_p, CPXINT *arccnt_p,
                            CPXINT *arcbeg, CPXINT *arc,
                            CPXINT *surplus_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETgetnodeindex_async (CPXCENVptr env, CPXCNETptr net,
                              char const *lname_str,
                              CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETgetnodeindex_join (CPXASYNCptr *handle_p, CPXINT *index_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETgetnodename_async (CPXCENVptr env, CPXCNETptr net,
                             CPXSIZE namespc, CPXINT begin, CPXINT end,
                             CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETgetnodename_join (CPXASYNCptr *handle_p, char  **nnames,
                            char *namestore, CPXSIZE *surplus_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETgetobj_async (CPXCENVptr env, CPXCNETptr net, CPXINT begin,
                        CPXINT end, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETgetobj_join (CPXASYNCptr *handle_p, double *obj);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETgetobjval_async (CPXCENVptr env, CPXCNETptr net,
                           CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETgetobjval_join (CPXASYNCptr *handle_p, double *objval_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETgetpi_async (CPXCENVptr env, CPXCNETptr net, CPXINT begin,
                       CPXINT end, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETgetpi_join (CPXASYNCptr *handle_p, double *pi);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETgetprobname_async (CPXCENVptr env, CPXCNETptr net,
                             CPXSIZE bufspace, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETgetprobname_join (CPXASYNCptr *handle_p, char *buf_str,
                            CPXSIZE *surplus_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETgetslack_async (CPXCENVptr env, CPXCNETptr net, CPXINT begin,
                          CPXINT end, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETgetslack_join (CPXASYNCptr *handle_p, double *slack);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETgetsupply_async (CPXCENVptr env, CPXCNETptr net,
                           CPXINT begin, CPXINT end,
                           CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETgetsupply_join (CPXASYNCptr *handle_p, double *supply);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETgetub_async (CPXCENVptr env, CPXCNETptr net, CPXINT begin,
                       CPXINT end, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETgetub_join (CPXASYNCptr *handle_p, double *up);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETgetx_async (CPXCENVptr env, CPXCNETptr net, CPXINT begin,
                      CPXINT end, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETgetx_join (CPXASYNCptr *handle_p, double *x);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETprimopt_async (CPXCENVptr env, CPXNETptr net,
                         CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETprimopt_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETprimopt_multicast (CPXENVGROUPptr group);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETreadcopybase_async (CPXCENVptr env, CPXNETptr net,
                              char const *filename_str,
                              CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETreadcopybase_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETreadcopybase_multicast (CPXENVGROUPptr group,
                                  char const *filename_str);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETreadcopyprob_async (CPXCENVptr env, CPXNETptr net,
                              char const *filename_str,
                              CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETreadcopyprob_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETreadcopyprob_multicast (CPXENVGROUPptr group,
                                  char const *filename_str);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETsolninfo_async (CPXCENVptr env, CPXCNETptr net,
                          CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETsolninfo_join (CPXASYNCptr *handle_p, int *pfeasind_p,
                         int *dfeasind_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETsolution_async (CPXCENVptr env, CPXCNETptr net,
                          CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETsolution_join (CPXASYNCptr *handle_p, int *netstat_p,
                         double *objval_p, double *x, double *pi,
                         double *slack, double *dj);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETwriteprob_async (CPXCENVptr env, CPXCNETptr net,
                           char const *filename_str,
                           char const *format_str,
                           CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETwriteprob_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETwriteprob_multicast (CPXENVGROUPptr group,
                               char const *filename_str,
                               char const *format_str);


CPXLIBAPI
int CPXPUBLIC
   CPXSnewcols_async (CPXCENVptr env, CPXLPptr lp, CPXINT ccnt,
                      double const *obj, double const *lb,
                      double const *ub, char const *xctype,
                      char const *const *colname,
                      CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSnewcols_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSnewrows_async (CPXCENVptr env, CPXLPptr lp, CPXINT rcnt,
                      double const *rhs, char const *sense,
                      double const *rngval, char const *const *rowname,
                      CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSnewrows_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSobjsa_async (CPXCENVptr env, CPXCLPptr lp, CPXINT begin,
                    CPXINT end, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSobjsa_join (CPXASYNCptr *handle_p, double *lower, double *upper);


CPXLIBAPI
CPXENVptr CPXPUBLIC
   CPXSopenCPLEXreconnect (int *status_p, void const *buffer);


CPXLIBAPI
CPXENVptr CPXPUBLIC
   CPXSopenCPLEXremote (char const *transport, int argc,
                        char const *const *argv, int *status_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSordread_async (CPXCENVptr env, char const *filename_str,
                      CPXINT numcols, char const *const *colname,
                      CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSordread_join (CPXASYNCptr *handle_p, CPXINT *cnt_p,
                     CPXINT *indices, CPXINT *priority, int *direction);


CPXLIBAPI
int CPXPUBLIC
   CPXSordwrite_async (CPXCENVptr env, CPXCLPptr lp,
                       char const *filename_str, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSordwrite_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSordwrite_multicast (CPXENVGROUPptr group,
                           char const *filename_str);


CPXLIBAPI
int CPXPUBLIC
   CPXSpivot_async (CPXCENVptr env, CPXLPptr lp, CPXINT jenter,
                    CPXINT jleave, int leavestat,
                    CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSpivot_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSpivot_multicast (CPXENVGROUPptr group, CPXINT jenter,
                        CPXINT jleave, int leavestat);


CPXLIBAPI
int CPXPUBLIC
   CPXSpivotin_async (CPXCENVptr env, CPXLPptr lp, CPXINT const *rlist,
                      CPXINT rlen, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSpivotin_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSpivotin_multicast (CPXENVGROUPptr group, CPXINT const *rlist,
                          CPXINT rlen);


CPXLIBAPI
int CPXPUBLIC
   CPXSpivotout_async (CPXCENVptr env, CPXLPptr lp,
                       CPXINT const *clist, CPXINT clen,
                       CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSpivotout_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSpivotout_multicast (CPXENVGROUPptr group, CPXINT const *clist,
                           CPXINT clen);


CPXLIBAPI
int CPXPUBLIC
   CPXSpopulate_async (CPXCENVptr env, CPXLPptr lp,
                       CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSpopulate_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSpopulate_multicast (CPXENVGROUPptr group);


CPXLIBAPI
int CPXPUBLIC
   CPXSpperwrite_async (CPXCENVptr env, CPXLPptr lp,
                        char const *filename_str, double epsilon,
                        CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSpperwrite_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSpperwrite_multicast (CPXENVGROUPptr group,
                            char const *filename_str, double epsilon);


CPXLIBAPI
int CPXPUBLIC
   CPXSpratio_async (CPXCENVptr env, CPXLPptr lp, CPXINT *indices,
                     CPXINT cnt, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSpratio_join (CPXASYNCptr *handle_p, CPXINT *indices,
                    double *downratio, double *upratio,
                    CPXINT *downleave, CPXINT *upleave,
                    int *downleavestatus, int *upleavestatus,
                    int *downstatus, int *upstatus);


CPXLIBAPI
int CPXPUBLIC
   CPXSpreaddrows_async (CPXCENVptr env, CPXLPptr lp, CPXINT rcnt,
                         CPXINT nzcnt, double const *rhs,
                         char const *sense, CPXINT const *rmatbeg,
                         CPXINT const *rmatind, double const *rmatval,
                         char const *const *rowname,
                         CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSpreaddrows_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSprechgobj_async (CPXCENVptr env, CPXLPptr lp, CPXINT cnt,
                        CPXINT const *indices, double const *values,
                        CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSprechgobj_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSprechgobj_multicast (CPXENVGROUPptr group, CPXINT cnt,
                            CPXINT const *indices,
                            double const *values);


CPXLIBAPI
int CPXPUBLIC
   CPXSpreslvwrite_async (CPXCENVptr env, CPXLPptr lp,
                          char const *filename_str,
                          CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSpreslvwrite_join (CPXASYNCptr *handle_p, double *objoff_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSpresolve_async (CPXCENVptr env, CPXLPptr lp, int method,
                       CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSpresolve_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSpresolve_multicast (CPXENVGROUPptr group, int method);


CPXLIBAPI
int CPXPUBLIC
   CPXSprimopt_async (CPXCENVptr env, CPXLPptr lp,
                      CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSprimopt_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSprimopt_multicast (CPXENVGROUPptr group);


CPXLIBAPI
int CPXPUBLIC
   CPXSqconstrslackfromx_async (CPXCENVptr env, CPXCLPptr lp,
                                double const *x, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSqconstrslackfromx_join (CPXASYNCptr *handle_p, double *qcslack);


CPXLIBAPI
int CPXPUBLIC
   CPXSqpdjfrompi_async (CPXCENVptr env, CPXCLPptr lp,
                         double const *pi, double const *x,
                         CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSqpdjfrompi_join (CPXASYNCptr *handle_p, double *dj);


CPXLIBAPI
int CPXPUBLIC
   CPXSqpindefcertificate_async (CPXCENVptr env, CPXCLPptr lp,
                                 CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSqpindefcertificate_join (CPXASYNCptr *handle_p, double *x);


CPXLIBAPI
int CPXPUBLIC
   CPXSqpopt_async (CPXCENVptr env, CPXLPptr lp, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSqpopt_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSqpopt_multicast (CPXENVGROUPptr group);


CPXLIBAPI
int CPXPUBLIC
   CPXSqpuncrushpi_async (CPXCENVptr env, CPXCLPptr lp,
                          double const *prepi, double const *x,
                          CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSqpuncrushpi_join (CPXASYNCptr *handle_p, double *pi);


CPXLIBAPI
int CPXPUBLIC
   CPXSreadcopyannotations_multicast (CPXENVGROUPptr group,
                                      char const *filename);


CPXLIBAPI
int CPXPUBLIC
   CPXSreadcopybase_async (CPXCENVptr env, CPXLPptr lp,
                           char const *filename_str,
                           CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSreadcopybase_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSreadcopybase_multicast (CPXENVGROUPptr group,
                               char const *filename_str);


CPXLIBAPI
int CPXPUBLIC
   CPXSreadcopymipstarts_async (CPXCENVptr env, CPXLPptr lp,
                                char const *filename_str,
                                CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSreadcopymipstarts_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSreadcopymipstarts_multicast (CPXENVGROUPptr group,
                                    char const *filename_str);


CPXLIBAPI
int CPXPUBLIC
   CPXSreadcopyorder_async (CPXCENVptr env, CPXLPptr lp,
                            char const *filename_str,
                            CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSreadcopyorder_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSreadcopyorder_multicast (CPXENVGROUPptr group,
                                char const *filename_str);


CPXLIBAPI
int CPXPUBLIC
   CPXSreadcopyparam_async (CPXENVptr env, char const *filename_str,
                            CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSreadcopyparam_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSreadcopyparam_multicast (CPXENVGROUPptr group,
                                char const *filename_str);


CPXLIBAPI
int CPXPUBLIC
   CPXSreadcopyprob_async (CPXCENVptr env, CPXLPptr lp,
                           char const *filename_str,
                           char const *filetype_str,
                           CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSreadcopyprob_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSreadcopyprob_multicast (CPXENVGROUPptr group,
                               char const *filename_str,
                               char const *filetype_str);


CPXLIBAPI
int CPXPUBLIC
   CPXSreadcopysol_async (CPXCENVptr env, CPXLPptr lp,
                          char const *filename_str,
                          CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSreadcopysol_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSreadcopysol_multicast (CPXENVGROUPptr group,
                              char const *filename_str);


CPXLIBAPI
int CPXPUBLIC
   CPXSreadcopysolnpoolfilters_async (CPXCENVptr env, CPXLPptr lp,
                                      char const *filename_str,
                                      CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSreadcopysolnpoolfilters_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSreadcopysolnpoolfilters_multicast (CPXENVGROUPptr group,
                                          char const *filename_str);


CPXLIBAPI
int CPXPUBLIC
   CPXSrefineconflict_async (CPXCENVptr env, CPXLPptr lp,
                             CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSrefineconflict_join (CPXASYNCptr *handle_p,
                            CPXINT *confnumrows_p,
                            CPXINT *confnumcols_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSrefineconflictext_async (CPXCENVptr env, CPXLPptr lp,
                                CPXINT grpcnt, CPXINT concnt,
                                double const *grppref,
                                CPXINT const *grpbeg,
                                CPXINT const *grpind,
                                char const *grptype,
                                CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSrefineconflictext_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSrefineconflictext_multicast (CPXENVGROUPptr group,
                                    CPXINT grpcnt, CPXINT concnt,
                                    double const *grppref,
                                    CPXINT const *grpbeg,
                                    CPXINT const *grpind,
                                    char const *grptype);


CPXLIBAPI
int CPXPUBLIC
   CPXSrefinemipstartconflict_async (CPXCENVptr env, CPXLPptr lp,
                                     int mipstartindex,
                                     CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSrefinemipstartconflict_join (CPXASYNCptr *handle_p,
                                    CPXINT *confnumrows_p,
                                    CPXINT *confnumcols_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSrefinemipstartconflictext_async (CPXCENVptr env, CPXLPptr lp,
                                        int mipstartindex,
                                        CPXINT grpcnt, CPXINT concnt,
                                        double const *grppref,
                                        CPXINT const *grpbeg,
                                        CPXINT const *grpind,
                                        char const *grptype,
                                        CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSrefinemipstartconflictext_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSrefinemipstartconflictext_multicast (CPXENVGROUPptr group,
                                            int mipstartindex,
                                            CPXINT grpcnt,
                                            CPXINT concnt,
                                            double const *grppref,
                                            CPXINT const *grpbeg,
                                            CPXINT const *grpind,
                                            char const *grptype);


CPXLIBAPI
int CPXPUBLIC
   CPXSrhssa_async (CPXCENVptr env, CPXCLPptr lp, CPXINT begin,
                    CPXINT end, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSrhssa_join (CPXASYNCptr *handle_p, double *lower, double *upper);


CPXLIBAPI
int CPXPUBLIC
   CPXSsavwrite_async (CPXCENVptr env, CPXCLPptr lp,
                       char const *filename_str, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSsavwrite_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSsavwrite_multicast (CPXENVGROUPptr group,
                           char const *filename_str);







CPXLIBAPI
int CPXPUBLIC
   CPXSsetdblannotations_multicast (CPXENVGROUPptr group, CPXINT idx,
                                    int objtype, CPXINT cnt,
                                    CPXINT const *indices,
                                    double const *values);


CPXLIBAPI
int CPXPUBLIC
   CPXSsetdblparam_async (CPXENVptr env, int whichparam,
                          double newvalue, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSsetdblparam_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSsetdblparam_multicast (CPXENVGROUPptr group, int whichparam,
                              double newvalue);


CPXLIBAPI
int CPXPUBLIC
   CPXSsetdefaults_async (CPXENVptr env, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSsetdefaults_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSsetdefaults_multicast (CPXENVGROUPptr group);


CPXLIBAPI
int CPXPUBLIC
   CPXSsetinfohandler (CPXENVptr env, CPXINFOHANDLER *infohandler,
                       void *handle);


CPXLIBAPI
int CPXPUBLIC
   CPXSsetintparam_async (CPXENVptr env, int whichparam,
                          CPXINT newvalue, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSsetintparam_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSsetintparam_multicast (CPXENVGROUPptr group, int whichparam,
                              CPXINT newvalue);


CPXLIBAPI
int CPXPUBLIC
   CPXSsetlongannotations_multicast (CPXENVGROUPptr group, CPXINT idx,
                                     int objtype, CPXINT cnt,
                                     CPXINT const *indices,
                                     CPXLONG const *values);


CPXLIBAPI
int CPXPUBLIC
   CPXSsetlongparam_async (CPXENVptr env, int whichparam,
                           CPXLONG newvalue, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSsetlongparam_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSsetlongparam_multicast (CPXENVGROUPptr group, int whichparam,
                               CPXLONG newvalue);


CPXLIBAPI
int CPXPUBLIC
   CPXSsetphase2_async (CPXCENVptr env, CPXLPptr lp,
                        CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSsetphase2_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSsetphase2_multicast (CPXENVGROUPptr group);



CPXLIBAPI
int CPXPUBLIC
   CPXSsiftopt_async (CPXCENVptr env, CPXLPptr lp,
                      CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSsiftopt_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSsiftopt_multicast (CPXENVGROUPptr group);


CPXLIBAPI
int CPXPUBLIC
   CPXSslackfromx_async (CPXCENVptr env, CPXCLPptr lp, double const *x,
                         CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSslackfromx_join (CPXASYNCptr *handle_p, double *slack);


CPXLIBAPI
int CPXPUBLIC
   CPXSsolninfo_async (CPXCENVptr env, CPXCLPptr lp,
                       CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSsolninfo_join (CPXASYNCptr *handle_p, int *solnmethod_p,
                      int *solntype_p, int *pfeasind_p,
                      int *dfeasind_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSsolution_async (CPXCENVptr env, CPXCLPptr lp,
                       CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSsolution_join (CPXASYNCptr *handle_p, int *lpstat_p,
                      double *objval_p, double *x, double *pi,
                      double *slack, double *dj);


CPXLIBAPI
int CPXPUBLIC
   CPXSsolwrite_async (CPXCENVptr env, CPXCLPptr lp,
                       char const *filename_str, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSsolwrite_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSsolwrite_multicast (CPXENVGROUPptr group,
                           char const *filename_str);


CPXLIBAPI
int CPXPUBLIC
   CPXSsolwritesolnpool_async (CPXCENVptr env, CPXCLPptr lp, int soln,
                               char const *filename_str,
                               CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSsolwritesolnpool_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSsolwritesolnpool_multicast (CPXENVGROUPptr group, int soln,
                                   char const *filename_str);


CPXLIBAPI
int CPXPUBLIC
   CPXSsolwritesolnpoolall_async (CPXCENVptr env, CPXCLPptr lp,
                                  char const *filename_str,
                                  CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSsolwritesolnpoolall_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSsolwritesolnpoolall_multicast (CPXENVGROUPptr group,
                                      char const *filename_str);




CPXLIBAPI
int CPXPUBLIC
   CPXSstrongbranch_async (CPXCENVptr env, CPXLPptr lp,
                           CPXINT const *indices, CPXINT cnt,
                           CPXLONG itlim, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSstrongbranch_join (CPXASYNCptr *handle_p, double *downobj,
                          double *upobj);


CPXLIBAPI
int CPXPUBLIC
   CPXStightenbds_async (CPXCENVptr env, CPXLPptr lp, CPXINT cnt,
                         CPXINT const *indices, char const *lu,
                         double const *bd, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXStightenbds_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXStightenbds_multicast (CPXENVGROUPptr group, CPXINT cnt,
                             CPXINT const *indices, char const *lu,
                             double const *bd);


CPXLIBAPI
int CPXPUBLIC
   CPXStransportctrldbl (CPXCENVptr env, int ctrl, double *data_p);


CPXLIBAPI
int CPXPUBLIC
   CPXStransportctrlint (CPXCENVptr env, int ctrl, CPXINT *data_p);


CPXLIBAPI
int CPXPUBLIC
   CPXStransportctrllong (CPXCENVptr env, int ctrl, CPXLONG *data_p);


CPXLIBAPI
int CPXPUBLIC
   CPXStuneparam_async (CPXENVptr env, CPXLPptr lp, int intcnt,
                        int const *intnum, int const *intval,
                        int dblcnt, int const *dblnum,
                        double const *dblval, int strcnt,
                        int const *strnum, char const *const *strval,
                        CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXStuneparam_join (CPXASYNCptr *handle_p, int *tunestat_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSuncrushpi_async (CPXCENVptr env, CPXCLPptr lp,
                        double const *prepi, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSuncrushpi_join (CPXASYNCptr *handle_p, double *pi);


CPXLIBAPI
int CPXPUBLIC
   CPXSuncrushx_async (CPXCENVptr env, CPXCLPptr lp,
                       double const *prex, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSuncrushx_join (CPXASYNCptr *handle_p, double *x);


CPXLIBAPI
int CPXPUBLIC
   CPXSunscaleprob_async (CPXCENVptr env, CPXLPptr lp,
                          CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSunscaleprob_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSunscaleprob_multicast (CPXENVGROUPptr group);


CPXLIBAPI
int CPXPUBLIC
   CPXSuserfunction (CPXENVptr env, int id, CPXLONG insize,
                     void const *indata, CPXLONG outspace,
                     CPXLONG *outsize_p, void *outdata);


CPXLIBAPI
int CPXPUBLIC
   CPXSuserfunction_async (CPXENVptr env, int id, CPXLONG insize,
                           void const *indata, CPXLONG outspace,
                           CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSuserfunction_join (CPXASYNCptr *handle_p, CPXLONG *outsize_p,
                          void *outdata);


CPXLIBAPI
int CPXPUBLIC
   CPXSwritemipstarts_async (CPXCENVptr env, CPXCLPptr lp,
                             char const *filename_str, int begin,
                             int end, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSwritemipstarts_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSwritemipstarts_multicast (CPXENVGROUPptr group,
                                 char const *filename_str, int begin,
                                 int end);


CPXLIBAPI
int CPXPUBLIC
   CPXSwriteparam_async (CPXCENVptr env, char const *filename_str,
                         CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSwriteparam_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSwriteparam_multicast (CPXENVGROUPptr group,
                             char const *filename_str);


CPXLIBAPI
int CPXPUBLIC
   CPXSwriteprob_async (CPXCENVptr env, CPXCLPptr lp,
                        char const *filename_str,
                        char const *filetype_str,
                        CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSwriteprob_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSwriteprob_multicast (CPXENVGROUPptr group,
                            char const *filename_str,
                            char const *filetype_str);



#endif /* CPX_CPLEX_S_API_DEFINED > 0 */

#ifdef __cplusplus
}
#endif

#ifdef _WIN32
#pragma pack(pop)
#endif

#endif /* !CPX_CPLEX_REMOTEMASTERS_H */
