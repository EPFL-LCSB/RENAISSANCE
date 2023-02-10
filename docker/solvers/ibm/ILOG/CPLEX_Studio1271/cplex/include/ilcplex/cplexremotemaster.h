/* --------------------------------------------------------------------------
 * File: cplexremotemaster.h
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

#ifndef CPX_CPLEX_REMOTEMASTER_H
#   define CPX_CPLEX_REMOTEMASTER_H 1
#include "ilcplex/cplexremote.h"

#ifdef _WIN32
#pragma pack(push, 8)
#endif

#ifdef __cplusplus
extern "C" {
#endif

CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXaddcols_async (CPXCENVptr env, CPXLPptr lp, int ccnt, int nzcnt,
                     double const *obj, int const *cmatbeg,
                     int const *cmatind, double const *cmatval,
                     double const *lb, double const *ub,
                     char **colname, CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXaddcols_join (CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXaddindconstr_async (CPXCENVptr env, CPXLPptr lp, int indvar,
                          int complemented, int nzcnt, double rhs,
                          int sense, int const *linind,
                          double const *linval,
                          char const *indname_str,
                          CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXaddindconstr_join (CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXaddlazyconstraints_async (CPXCENVptr env, CPXLPptr lp, int rcnt,
                                int nzcnt, double const *rhs,
                                char const *sense, int const *rmatbeg,
                                int const *rmatind,
                                double const *rmatval, char **rowname,
                                CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXaddlazyconstraints_join (CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXaddmipstarts_async (CPXCENVptr env, CPXLPptr lp, int mcnt,
                          int nzcnt, int const *beg,
                          int const *varindices, double const *values,
                          int const *effortlevel, char **mipstartname,
                          CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXaddmipstarts_join (CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXaddqconstr_async (CPXCENVptr env, CPXLPptr lp, int linnzcnt,
                        int quadnzcnt, double rhs, int sense,
                        int const *linind, double const *linval,
                        int const *quadrow, int const *quadcol,
                        double const *quadval, char const *lname_str,
                        CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXaddqconstr_join (CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXaddrows_async (CPXCENVptr env, CPXLPptr lp, int ccnt, int rcnt,
                     int nzcnt, double const *rhs, char const *sense,
                     int const *rmatbeg, int const *rmatind,
                     double const *rmatval, char **colname,
                     char **rowname, CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXaddrows_join (CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXaddsolnpooldivfilter_async (CPXCENVptr env, CPXLPptr lp,
                                  double lower_bound,
                                  double upper_bound, int nzcnt,
                                  int const *ind, double const *weight,
                                  double const *refval,
                                  char const *lname_str,
                                  CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXaddsolnpooldivfilter_join (CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXaddsolnpoolrngfilter_async (CPXCENVptr env, CPXLPptr lp,
                                  double lb, double ub, int nzcnt,
                                  int const *ind, double const *val,
                                  char const *lname_str,
                                  CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXaddsolnpoolrngfilter_join (CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXaddsos_async (CPXCENVptr env, CPXLPptr lp, int numsos,
                    int numsosnz, char const *sostype,
                    int const *sosbeg, int const *sosind,
                    double const *soswt, char **sosname,
                    CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXaddsos_join (CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXaddusercuts_async (CPXCENVptr env, CPXLPptr lp, int rcnt,
                         int nzcnt, double const *rhs,
                         char const *sense, int const *rmatbeg,
                         int const *rmatind, double const *rmatval,
                         char **rowname, CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXaddusercuts_join (CPXASYNCptr *handle_p);


CPXLIBAPI
void CPXPUBLIC
   CPXasynchandledel (CPXASYNCptr *asynchandle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXasynchandleload (CPXENVptr env, CPXASYNCptr *asynchandle_p,
                       void const *buffer);


CPXLIBAPI
void CPXPUBLIC
   CPXasynchandlesave (CPXCASYNCptr asynchandle, void *buffer);


CPXLIBAPI
int CPXPUBLIC
   CPXasynckill (CPXASYNCptr asynchandle);


CPXLIBAPI
int CPXPUBLIC
   CPXasynctest (CPXASYNCptr asynchandle, int *running_p);


CPXLIBAPI
int CPXPUBLIC
   CPXbaropt_async (CPXCENVptr env, CPXLPptr lp, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXbaropt_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXbaropt_multicast (CPXENVGROUPptr group);


CPXLIBAPI
int CPXPUBLIC
   CPXbasicpresolve_async (CPXCENVptr env, CPXLPptr lp,
                           CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXbasicpresolve_join (CPXASYNCptr *handle_p, double *redlb,
                          double *redub, int *rstat);


CPXLIBAPI
int CPXPUBLIC
   CPXbendersopt_async (CPXCENVptr env, CPXLPptr lp,
                        CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXbendersopt_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXbendersopt_multicast (CPXENVGROUPptr group);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXbinvacol_async (CPXCENVptr env, CPXCLPptr lp, int j,
                      CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXbinvacol_join (CPXASYNCptr *handle_p, double *x);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXbinvarow_async (CPXCENVptr env, CPXCLPptr lp, int i,
                      CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXbinvarow_join (CPXASYNCptr *handle_p, double *z);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXbinvcol_async (CPXCENVptr env, CPXCLPptr lp, int j,
                     CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXbinvcol_join (CPXASYNCptr *handle_p, double *x);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXbinvrow_async (CPXCENVptr env, CPXCLPptr lp, int i,
                     CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXbinvrow_join (CPXASYNCptr *handle_p, double *y);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXboundsa_async (CPXCENVptr env, CPXCLPptr lp, int begin, int end,
                     CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXboundsa_join (CPXASYNCptr *handle_p, double *lblower,
                    double *lbupper, double *ublower, double *ubupper);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXbtran_async (CPXCENVptr env, CPXCLPptr lp, double *y,
                   CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXbtran_join (CPXASYNCptr *handle_p, double *y);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXcheckdfeas_async (CPXCENVptr env, CPXLPptr lp,
                        CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXcheckdfeas_join (CPXASYNCptr *handle_p, int *infeas_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXcheckpfeas_async (CPXCENVptr env, CPXLPptr lp,
                        CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXcheckpfeas_join (CPXASYNCptr *handle_p, int *infeas_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXchecksoln_async (CPXCENVptr env, CPXLPptr lp,
                       CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXchecksoln_join (CPXASYNCptr *handle_p, int *lpstatus_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXchgbds_async (CPXCENVptr env, CPXLPptr lp, int cnt,
                    int const *indices, char const *lu,
                    double const *bd, CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXchgbds_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXchgbds_multicast (CPXENVGROUPptr group, int cnt,
                        int const *indices, char const *lu,
                        double const *bd);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXchgcoef_async (CPXCENVptr env, CPXLPptr lp, int i, int j,
                     double newvalue, CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXchgcoef_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXchgcoef_multicast (CPXENVGROUPptr group, int i, int j,
                         double newvalue);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXchgcoeflist_async (CPXCENVptr env, CPXLPptr lp, int numcoefs,
                         int const *rowlist, int const *collist,
                         double const *vallist, CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXchgcoeflist_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXchgcoeflist_multicast (CPXENVGROUPptr group, int numcoefs,
                             int const *rowlist, int const *collist,
                             double const *vallist);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXchgcolname_async (CPXCENVptr env, CPXLPptr lp, int cnt,
                        int const *indices, char **newname,
                        CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXchgcolname_join (CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXchgctype_async (CPXCENVptr env, CPXLPptr lp, int cnt,
                      int const *indices, char const *xctype,
                      CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXchgctype_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXchgctype_multicast (CPXENVGROUPptr group, int cnt,
                          int const *indices, char const *xctype);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXchgmipstarts_async (CPXCENVptr env, CPXLPptr lp, int mcnt,
                          int const *mipstartindices, int nzcnt,
                          int const *beg, int const *varindices,
                          double const *values, int const *effortlevel,
                          CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXchgmipstarts_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXchgmipstarts_multicast (CPXENVGROUPptr group, int mcnt,
                              int const *mipstartindices, int nzcnt,
                              int const *beg, int const *varindices,
                              double const *values,
                              int const *effortlevel);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXchgname_async (CPXCENVptr env, CPXLPptr lp, int key, int ij,
                     char const *newname_str, CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXchgname_join (CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXchgobj_async (CPXCENVptr env, CPXLPptr lp, int cnt,
                    int const *indices, double const *values,
                    CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXchgobj_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXchgobj_multicast (CPXENVGROUPptr group, int cnt,
                        int const *indices, double const *values);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXchgobjoffset_async (CPXCENVptr env, CPXLPptr lp, double offset,
                          CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXchgobjoffset_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXchgobjoffset_multicast (CPXENVGROUPptr group, double offset);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXchgobjsen_async (CPXCENVptr env, CPXLPptr lp, int maxormin,
                       CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXchgobjsen_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXchgobjsen_multicast (CPXENVGROUPptr group, int maxormin);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXchgprobname_async (CPXCENVptr env, CPXLPptr lp,
                         char const *probname, CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXchgprobname_join (CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXchgprobtype_async (CPXCENVptr env, CPXLPptr lp, int type,
                         CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXchgprobtype_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXchgprobtype_multicast (CPXENVGROUPptr group, int type);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXchgprobtypesolnpool_async (CPXCENVptr env, CPXLPptr lp, int type,
                                 int soln, CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXchgprobtypesolnpool_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXchgprobtypesolnpool_multicast (CPXENVGROUPptr group, int type,
                                     int soln);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXchgqpcoef_async (CPXCENVptr env, CPXLPptr lp, int i, int j,
                       double newvalue, CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXchgqpcoef_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXchgqpcoef_multicast (CPXENVGROUPptr group, int i, int j,
                           double newvalue);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXchgrhs_async (CPXCENVptr env, CPXLPptr lp, int cnt,
                    int const *indices, double const *values,
                    CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXchgrhs_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXchgrhs_multicast (CPXENVGROUPptr group, int cnt,
                        int const *indices, double const *values);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXchgrngval_async (CPXCENVptr env, CPXLPptr lp, int cnt,
                       int const *indices, double const *values,
                       CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXchgrngval_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXchgrngval_multicast (CPXENVGROUPptr group, int cnt,
                           int const *indices, double const *values);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXchgrowname_async (CPXCENVptr env, CPXLPptr lp, int cnt,
                        int const *indices, char **newname,
                        CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXchgrowname_join (CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXchgsense_async (CPXCENVptr env, CPXLPptr lp, int cnt,
                      int const *indices, char const *sense,
                      CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXchgsense_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXchgsense_multicast (CPXENVGROUPptr group, int cnt,
                          int const *indices, char const *sense);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXcleanup_async (CPXCENVptr env, CPXLPptr lp, double eps,
                     CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXcleanup_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXcleanup_multicast (CPXENVGROUPptr group, double eps);


CPXLIBAPI
int CPXPUBLIC
   CPXcloseCPLEXdisconnect (CPXENVptr *env_p, void *buffer);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXclpwrite_async (CPXCENVptr env, CPXCLPptr lp,
                      char const *filename_str, CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXclpwrite_join (CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXclpwrite_multicast (CPXENVGROUPptr group,
                          char const *filename_str);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXcompletelp_async (CPXCENVptr env, CPXLPptr lp,
                        CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXcompletelp_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXcompletelp_multicast (CPXENVGROUPptr group);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXcopybase_async (CPXCENVptr env, CPXLPptr lp, int const *cstat,
                      int const *rstat, CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXcopybase_join (CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXcopybasednorms_async (CPXCENVptr env, CPXLPptr lp,
                            int const *cstat, int const *rstat,
                            double const *dnorm, CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXcopybasednorms_join (CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXcopyctype_async (CPXCENVptr env, CPXLPptr lp, char const *xctype,
                       CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXcopyctype_join (CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXcopydnorms_async (CPXCENVptr env, CPXLPptr lp,
                        double const *norm, int const *head, int len,
                        CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXcopydnorms_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXcopydnorms_multicast (CPXENVGROUPptr group, double const *norm,
                            int const *head, int len);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXcopylp_async (CPXCENVptr env, CPXLPptr lp, int numcols,
                    int numrows, int objsense, double const *objective,
                    double const *rhs, char const *sense,
                    int const *matbeg, int const *matcnt,
                    int const *matind, double const *matval,
                    double const *lb, double const *ub,
                    double const *rngval, CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXcopylp_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXcopylp_multicast (CPXENVGROUPptr group, int numcols, int numrows,
                        int objsense, double const *objective,
                        double const *rhs, char const *sense,
                        int const *matbeg, int const *matcnt,
                        int const *matind, double const *matval,
                        double const *lb, double const *ub,
                        double const *rngval);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXcopylpwnames_async (CPXCENVptr env, CPXLPptr lp, int numcols,
                          int numrows, int objsense,
                          double const *objective, double const *rhs,
                          char const *sense, int const *matbeg,
                          int const *matcnt, int const *matind,
                          double const *matval, double const *lb,
                          double const *ub, double const *rngval,
                          char **colname, char **rowname,
                          CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXcopylpwnames_join (CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXcopynettolp_async (CPXCENVptr env, CPXLPptr lp, CPXCNETptr net,
                         CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXcopynettolp_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXcopynettolp_multicast (CPXENVGROUPptr group);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXcopyobjname_async (CPXCENVptr env, CPXLPptr lp,
                         char const *objname_str,
                         CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXcopyobjname_join (CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXcopyorder_async (CPXCENVptr env, CPXLPptr lp, int cnt,
                       int const *indices, int const *priority,
                       int const *direction, CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXcopyorder_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXcopyorder_multicast (CPXENVGROUPptr group, int cnt,
                           int const *indices, int const *priority,
                           int const *direction);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXcopypartialbase_async (CPXCENVptr env, CPXLPptr lp, int ccnt,
                             int const *cindices, int const *cstat,
                             int rcnt, int const *rindices,
                             int const *rstat, CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXcopypartialbase_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXcopypartialbase_multicast (CPXENVGROUPptr group, int ccnt,
                                 int const *cindices, int const *cstat,
                                 int rcnt, int const *rindices,
                                 int const *rstat);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXcopypnorms_async (CPXCENVptr env, CPXLPptr lp,
                        double const *cnorm, double const *rnorm,
                        int len, CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXcopypnorms_join (CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXcopyprotected_async (CPXCENVptr env, CPXLPptr lp, int cnt,
                           int const *indices, CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXcopyprotected_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXcopyprotected_multicast (CPXENVGROUPptr group, int cnt,
                               int const *indices);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXcopyqpsep_async (CPXCENVptr env, CPXLPptr lp,
                       double const *qsepvec, CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXcopyqpsep_join (CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXcopyquad_async (CPXCENVptr env, CPXLPptr lp, int const *qmatbeg,
                      int const *qmatcnt, int const *qmatind,
                      double const *qmatval, CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXcopyquad_join (CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXcopysos_async (CPXCENVptr env, CPXLPptr lp, int numsos,
                     int numsosnz, char const *sostype,
                     int const *sosbeg, int const *sosind,
                     double const *soswt, char **sosname,
                     CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXcopysos_join (CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXcopystart_async (CPXCENVptr env, CPXLPptr lp, int const *cstat,
                       int const *rstat, double const *cprim,
                       double const *rprim, double const *cdual,
                       double const *rdual, CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXcopystart_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXcreateenvgroup (CPXENVGROUPptr *group_p, int nenvs,
                      CPXENVptr const *envs);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXcrushform_async (CPXCENVptr env, CPXCLPptr lp, int len,
                       int const *ind, double const *val,
                       CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXcrushform_join (CPXASYNCptr *handle_p, int *plen_p,
                      double *poffset_p, int *pind, double *pval);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXcrushpi_async (CPXCENVptr env, CPXCLPptr lp, double const *pi,
                     CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXcrushpi_join (CPXASYNCptr *handle_p, double *prepi);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXcrushx_async (CPXCENVptr env, CPXCLPptr lp, double const *x,
                    CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXcrushx_join (CPXASYNCptr *handle_p, double *prex);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXdelcols_async (CPXCENVptr env, CPXLPptr lp, int begin, int end,
                     CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXdelcols_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXdelcols_multicast (CPXENVGROUPptr group, int begin, int end);


CPXLIBAPI
int CPXPUBLIC
   CPXdeldblannotation_multicast (CPXENVGROUPptr group, int idx);


CPXLIBAPI
int CPXPUBLIC
   CPXdeldblannotations_multicast (CPXENVGROUPptr group, int begin,
                                   int end);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXdelindconstrs_async (CPXCENVptr env, CPXLPptr lp, int begin,
                           int end, CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXdelindconstrs_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXdelindconstrs_multicast (CPXENVGROUPptr group, int begin,
                               int end);


CPXLIBAPI
int CPXPUBLIC
   CPXdellongannotation_multicast (CPXENVGROUPptr group, int idx);


CPXLIBAPI
int CPXPUBLIC
   CPXdellongannotations_multicast (CPXENVGROUPptr group, int begin,
                                    int end);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXdelmipstarts_async (CPXCENVptr env, CPXLPptr lp, int begin,
                          int end, CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXdelmipstarts_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXdelmipstarts_multicast (CPXENVGROUPptr group, int begin, int end);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXdelnames_async (CPXCENVptr env, CPXLPptr lp,
                      CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXdelnames_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXdelnames_multicast (CPXENVGROUPptr group);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXdelqconstrs_async (CPXCENVptr env, CPXLPptr lp, int begin,
                         int end, CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXdelqconstrs_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXdelqconstrs_multicast (CPXENVGROUPptr group, int begin, int end);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXdelrows_async (CPXCENVptr env, CPXLPptr lp, int begin, int end,
                     CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXdelrows_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXdelrows_multicast (CPXENVGROUPptr group, int begin, int end);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXdelsetcols_async (CPXCENVptr env, CPXLPptr lp, int *delstat,
                        CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXdelsetcols_join (CPXASYNCptr *handle_p, int *delstat);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXdelsetmipstarts_async (CPXCENVptr env, CPXLPptr lp, int *delstat,
                             CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXdelsetmipstarts_join (CPXASYNCptr *handle_p, int *delstat);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXdelsetrows_async (CPXCENVptr env, CPXLPptr lp, int *delstat,
                        CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXdelsetrows_join (CPXASYNCptr *handle_p, int *delstat);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXdelsetsolnpoolfilters_async (CPXCENVptr env, CPXLPptr lp,
                                   int *delstat, CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXdelsetsolnpoolfilters_join (CPXASYNCptr *handle_p, int *delstat);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXdelsetsolnpoolsolns_async (CPXCENVptr env, CPXLPptr lp,
                                 int *delstat, CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXdelsetsolnpoolsolns_join (CPXASYNCptr *handle_p, int *delstat);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXdelsetsos_async (CPXCENVptr env, CPXLPptr lp, int *delset,
                       CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXdelsetsos_join (CPXASYNCptr *handle_p, int *delset);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXdelsolnpoolfilters_async (CPXCENVptr env, CPXLPptr lp, int begin,
                                int end, CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXdelsolnpoolfilters_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXdelsolnpoolfilters_multicast (CPXENVGROUPptr group, int begin,
                                    int end);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXdelsolnpoolsolns_async (CPXCENVptr env, CPXLPptr lp, int begin,
                              int end, CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXdelsolnpoolsolns_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXdelsolnpoolsolns_multicast (CPXENVGROUPptr group, int begin,
                                  int end);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXdelsos_async (CPXCENVptr env, CPXLPptr lp, int begin, int end,
                    CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXdelsos_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXdelsos_multicast (CPXENVGROUPptr group, int begin, int end);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXdjfrompi_async (CPXCENVptr env, CPXCLPptr lp, double const *pi,
                      CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXdjfrompi_join (CPXASYNCptr *handle_p, double *dj);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXdperwrite_async (CPXCENVptr env, CPXLPptr lp,
                       char const *filename_str, double epsilon,
                       CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXdperwrite_join (CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXdperwrite_multicast (CPXENVGROUPptr group,
                           char const *filename_str, double epsilon);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXdratio_async (CPXCENVptr env, CPXLPptr lp, int *indices, int cnt,
                    CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXdratio_join (CPXASYNCptr *handle_p, int *indices,
                   double *downratio, double *upratio, int *downenter,
                   int *upenter, int *downstatus, int *upstatus);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXdualfarkas_async (CPXCENVptr env, CPXCLPptr lp,
                        CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXdualfarkas_join (CPXASYNCptr *handle_p, double *y,
                       double *proof_p);


CPXLIBAPI
int CPXPUBLIC
   CPXdualopt_async (CPXCENVptr env, CPXLPptr lp,
                     CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXdualopt_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXdualopt_multicast (CPXENVGROUPptr group);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXdualwrite_async (CPXCENVptr env, CPXCLPptr lp,
                       char const *filename_str, CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXdualwrite_join (CPXASYNCptr *handle_p, double *objshift_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXEgetsolnpoolfilter_async (CPXCENVptr env, CPXCLPptr lp,
                                int space, int which,
                                CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXEgetsolnpoolfilter_join (CPXASYNCptr *handle_p, int *ftype_p,
                               double *lowercutoff_p,
                               double *upper_cutoff_p, int *nzcnt_p,
                               int *ind, double *val, double *refval,
                               int *surplus_p);


CPXLIBAPI
int CPXPUBLIC
   CPXembwrite_async (CPXCENVptr env, CPXLPptr lp,
                      char const *filename_str, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXembwrite_join (CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXembwrite_multicast (CPXENVGROUPptr group,
                          char const *filename_str);


CPXLIBAPI
int CPXPUBLIC
   CPXenvgroupstatus (CPXCENVGROUPptr group, int idx);


CPXLIBAPI
int CPXPUBLIC
   CPXfeasopt_async (CPXCENVptr env, CPXLPptr lp, double const *rhs,
                     double const *rng, double const *lb,
                     double const *ub, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXfeasopt_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXfeasoptext_async (CPXCENVptr env, CPXLPptr lp, int grpcnt,
                        int concnt, double const *grppref,
                        int const *grpbeg, int const *grpind,
                        char const *grptype, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXfeasoptext_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXfeasoptext_multicast (CPXENVGROUPptr group, int grpcnt,
                            int concnt, double const *grppref,
                            int const *grpbeg, int const *grpind,
                            char const *grptype);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXfltwrite_async (CPXCENVptr env, CPXCLPptr lp,
                      char const *filename_str, CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXfltwrite_join (CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXfltwrite_multicast (CPXENVGROUPptr group,
                          char const *filename_str);


CPXLIBAPI
void CPXPUBLIC
   CPXfreeenvgroup (CPXENVGROUPptr *group_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXfreelazyconstraints_async (CPXCENVptr env, CPXLPptr lp,
                                 CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXfreelazyconstraints_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXfreelazyconstraints_multicast (CPXENVGROUPptr group);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXfreepresolve_async (CPXCENVptr env, CPXLPptr lp,
                          CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXfreepresolve_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXfreepresolve_multicast (CPXENVGROUPptr group);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXfreeusercuts_async (CPXCENVptr env, CPXLPptr lp,
                          CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXfreeusercuts_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXfreeusercuts_multicast (CPXENVGROUPptr group);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXftran_async (CPXCENVptr env, CPXCLPptr lp, double *x,
                   CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXftran_join (CPXASYNCptr *handle_p, double *x);


CPXLIBAPI
int CPXPUBLIC
   CPXgetasynchandlesize (CPXCASYNCptr asynchandle);


CPXLIBAPI
void const * CPXPUBLIC
   CPXgetasynctab (void);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetax_async (CPXCENVptr env, CPXCLPptr lp, int begin, int end,
                   CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetax_join (CPXASYNCptr *handle_p, double *x);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetbase_async (CPXCENVptr env, CPXCLPptr lp,
                     CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetbase_join (CPXASYNCptr *handle_p, int *cstat, int *rstat);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetbasednorms_async (CPXCENVptr env, CPXCLPptr lp,
                           CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetbasednorms_join (CPXASYNCptr *handle_p, int *cstat,
                          int *rstat, double *dnorm);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetbestobjval_async (CPXCENVptr env, CPXCLPptr lp,
                           CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetbestobjval_join (CPXASYNCptr *handle_p, double *objval_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetbhead_async (CPXCENVptr env, CPXCLPptr lp,
                      CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetbhead_join (CPXASYNCptr *handle_p, int *head, double *x);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetchgparam_async (CPXCENVptr env, int pspace,
                         CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetchgparam_join (CPXASYNCptr *handle_p, int *cnt_p,
                        int *paramnum, int *surplus_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetcoef_async (CPXCENVptr env, CPXCLPptr lp, int i, int j,
                     CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetcoef_join (CPXASYNCptr *handle_p, double *coef_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetcolindex_async (CPXCENVptr env, CPXCLPptr lp,
                         char const *lname_str, CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetcolindex_join (CPXASYNCptr *handle_p, int *index_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetcolinfeas_async (CPXCENVptr env, CPXCLPptr lp,
                          double const *x, int begin, int end,
                          CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetcolinfeas_join (CPXASYNCptr *handle_p, double *infeasout);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetcolname_async (CPXCENVptr env, CPXCLPptr lp, int storespace,
                        int begin, int end, CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetcolname_join (CPXASYNCptr *handle_p, char  **name,
                       char *namestore, int *surplus_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetcols_async (CPXCENVptr env, CPXCLPptr lp, int cmatspace,
                     int begin, int end, CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetcols_join (CPXASYNCptr *handle_p, int *nzcnt_p, int *cmatbeg,
                    int *cmatind, double *cmatval, int *surplus_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetconflictext_async (CPXCENVptr env, CPXCLPptr lp, int beg,
                            int end, CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetconflictext_join (CPXASYNCptr *handle_p, int *grpstat);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetctype_async (CPXCENVptr env, CPXCLPptr lp, int begin, int end,
                      CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetctype_join (CPXASYNCptr *handle_p, char *xctype);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetcutoff_async (CPXCENVptr env, CPXCLPptr lp,
                       CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetcutoff_join (CPXASYNCptr *handle_p, double *cutoff_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetdblparam_async (CPXCENVptr env, int whichparam,
                         CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetdblparam_join (CPXASYNCptr *handle_p, double *value_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetdblquality_async (CPXCENVptr env, CPXCLPptr lp, int what,
                           CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetdblquality_join (CPXASYNCptr *handle_p, double *quality_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetdettime_async (CPXCENVptr env, CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetdettime_join (CPXASYNCptr *handle_p, double *dettimestamp_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetdj_async (CPXCENVptr env, CPXCLPptr lp, int begin, int end,
                   CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetdj_join (CPXASYNCptr *handle_p, double *dj);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetdnorms_async (CPXCENVptr env, CPXCLPptr lp,
                       CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetdnorms_join (CPXASYNCptr *handle_p, double *norm, int *head,
                      int *len_p);


CPXLIBAPI
CPXENVptr CPXPUBLIC
   CPXgetenvgroupenv (CPXCENVGROUPptr group, int idx);


CPXLIBAPI
int CPXPUBLIC
   CPXgetenvgroupsize (CPXCENVGROUPptr group);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetgrad_async (CPXCENVptr env, CPXCLPptr lp, int j,
                     CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetgrad_join (CPXASYNCptr *handle_p, int *head, double *y);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetijdiv_async (CPXCENVptr env, CPXCLPptr lp,
                      CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetijdiv_join (CPXASYNCptr *handle_p, int *idiv_p, int *jdiv_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetijrow_async (CPXCENVptr env, CPXCLPptr lp, int i, int j,
                      CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetijrow_join (CPXASYNCptr *handle_p, int *row_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetindconstr_async (CPXCENVptr env, CPXCLPptr lp, int space,
                          int which, CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetindconstr_join (CPXASYNCptr *handle_p, int *indvar_p,
                         int *complemented_p, int *nzcnt_p,
                         double *rhs_p, char *sense_p, int *linind,
                         double *linval, int *surplus_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetindconstrindex_async (CPXCENVptr env, CPXCLPptr lp,
                               char const *lname_str,
                               CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetindconstrindex_join (CPXASYNCptr *handle_p, int *index_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetindconstrinfeas_async (CPXCENVptr env, CPXCLPptr lp,
                                double const *x, int begin, int end,
                                CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetindconstrinfeas_join (CPXASYNCptr *handle_p,
                               double *infeasout);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetindconstrname_async (CPXCENVptr env, CPXCLPptr lp,
                              int bufspace, int which,
                              CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetindconstrname_join (CPXASYNCptr *handle_p, char *buf_str,
                             int *surplus_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetindconstrslack_async (CPXCENVptr env, CPXCLPptr lp, int begin,
                               int end, CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetindconstrslack_join (CPXASYNCptr *handle_p, double *indslack);


CPXLIBAPI
int CPXPUBLIC
   CPXgetinfohandler (CPXCENVptr env, CPXINFOHANDLER  **infohandler_p,
                      void  **handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetintparam_async (CPXCENVptr env, int whichparam,
                         CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetintparam_join (CPXASYNCptr *handle_p, CPXINT *value_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetintquality_async (CPXCENVptr env, CPXCLPptr lp, int what,
                           CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetintquality_join (CPXASYNCptr *handle_p, int *quality_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetlb_async (CPXCENVptr env, CPXCLPptr lp, int begin, int end,
                   CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetlb_join (CPXASYNCptr *handle_p, double *lb);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetlongparam_async (CPXCENVptr env, int whichparam,
                          CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetlongparam_join (CPXASYNCptr *handle_p, CPXLONG *value_p);


CPXLIBAPI
int CPXPUBLIC
   CPXgetlps (CPXCENVptr env, int capacity, CPXLPptr *lps,
              int *count_p, int *total_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetmiprelgap_async (CPXCENVptr env, CPXCLPptr lp,
                          CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetmiprelgap_join (CPXASYNCptr *handle_p, double *gap_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetmipstartindex_async (CPXCENVptr env, CPXCLPptr lp,
                              char const *lname_str,
                              CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetmipstartindex_join (CPXASYNCptr *handle_p, int *index_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetmipstartname_async (CPXCENVptr env, CPXCLPptr lp, int storesz,
                             int begin, int end, CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetmipstartname_join (CPXASYNCptr *handle_p, char  **name,
                            char *store, int *surplus_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetmipstarts_async (CPXCENVptr env, CPXCLPptr lp, int startspace,
                          int begin, int end, CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetmipstarts_join (CPXASYNCptr *handle_p, int *nzcnt_p, int *beg,
                         int *varindices, double *values,
                         int *effortlevel, int *surplus_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetnumcores_async (CPXCENVptr env, CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetnumcores_join (CPXASYNCptr *handle_p, int *numcores_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetnumcuts_async (CPXCENVptr env, CPXCLPptr lp, int cuttype,
                        CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetnumcuts_join (CPXASYNCptr *handle_p, int *num_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetobj_async (CPXCENVptr env, CPXCLPptr lp, int begin, int end,
                    CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetobj_join (CPXASYNCptr *handle_p, double *obj);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetobjname_async (CPXCENVptr env, CPXCLPptr lp, int bufspace,
                        CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetobjname_join (CPXASYNCptr *handle_p, char *buf_str,
                       int *surplus_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetobjoffset_async (CPXCENVptr env, CPXCLPptr lp,
                          CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetobjoffset_join (CPXASYNCptr *handle_p, double *objoffset_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetobjval_async (CPXCENVptr env, CPXCLPptr lp,
                       CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetobjval_join (CPXASYNCptr *handle_p, double *objval_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetorder_async (CPXCENVptr env, CPXCLPptr lp, int ordspace,
                      CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetorder_join (CPXASYNCptr *handle_p, int *cnt_p, int *indices,
                     int *priority, int *direction, int *surplus_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetparamname_async (CPXCENVptr env, int whichparam,
                          CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetparamname_join (CPXASYNCptr *handle_p, char *name_str);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetparamnum_async (CPXCENVptr env, char const *name_str,
                         CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetparamnum_join (CPXASYNCptr *handle_p, int *whichparam_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetparamtype_async (CPXCENVptr env, int whichparam,
                          CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetparamtype_join (CPXASYNCptr *handle_p, int *paramtype);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetpi_async (CPXCENVptr env, CPXCLPptr lp, int begin, int end,
                   CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetpi_join (CPXASYNCptr *handle_p, double *pi);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetpnorms_async (CPXCENVptr env, CPXCLPptr lp,
                       CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetpnorms_join (CPXASYNCptr *handle_p, double *cnorm,
                      double *rnorm, int *len_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetprestat_async (CPXCENVptr env, CPXCLPptr lp,
                        CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetprestat_join (CPXASYNCptr *handle_p, int *prestat_p,
                       int *pcstat, int *prstat, int *ocstat,
                       int *orstat);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetprobname_async (CPXCENVptr env, CPXCLPptr lp, int bufspace,
                         CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetprobname_join (CPXASYNCptr *handle_p, char *buf_str,
                        int *surplus_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetprotected_async (CPXCENVptr env, CPXCLPptr lp, int pspace,
                          CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetprotected_join (CPXASYNCptr *handle_p, int *cnt_p,
                         int *indices, int *surplus_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetqconstr_async (CPXCENVptr env, CPXCLPptr lp, int linspace,
                        int quadspace, int which,
                        CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetqconstr_join (CPXASYNCptr *handle_p, int *linnzcnt_p,
                       int *quadnzcnt_p, double *rhs_p, char *sense_p,
                       int *linind, double *linval, int *linsurplus_p,
                       int *quadrow, int *quadcol, double *quadval,
                       int *quadsurplus_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetqconstrdslack_async (CPXCENVptr env, CPXCLPptr lp, int qind,
                              int space, CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetqconstrdslack_join (CPXASYNCptr *handle_p, int *nz_p,
                             int *ind, double *val, int *surplus_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetqconstrindex_async (CPXCENVptr env, CPXCLPptr lp,
                             char const *lname_str,
                             CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetqconstrindex_join (CPXASYNCptr *handle_p, int *index_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetqconstrinfeas_async (CPXCENVptr env, CPXCLPptr lp,
                              double const *x, int begin, int end,
                              CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetqconstrinfeas_join (CPXASYNCptr *handle_p, double *infeasout);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetqconstrname_async (CPXCENVptr env, CPXCLPptr lp, int bufspace,
                            int which, CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetqconstrname_join (CPXASYNCptr *handle_p, char *buf_str,
                           int *surplus_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetqconstrslack_async (CPXCENVptr env, CPXCLPptr lp, int begin,
                             int end, CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetqconstrslack_join (CPXASYNCptr *handle_p, double *qcslack);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetqpcoef_async (CPXCENVptr env, CPXCLPptr lp, int rownum,
                       int colnum, CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetqpcoef_join (CPXASYNCptr *handle_p, double *coef_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetquad_async (CPXCENVptr env, CPXCLPptr lp, int qmatspace,
                     int begin, int end, CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetquad_join (CPXASYNCptr *handle_p, int *nzcnt_p, int *qmatbeg,
                    int *qmatind, double *qmatval, int *surplus_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetray_async (CPXCENVptr env, CPXCLPptr lp,
                    CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetray_join (CPXASYNCptr *handle_p, double *z);


CPXLIBAPI
int CPXPUBLIC
   CPXgetreconnectinfolen (CPXCENVptr env);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetrhs_async (CPXCENVptr env, CPXCLPptr lp, int begin, int end,
                    CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetrhs_join (CPXASYNCptr *handle_p, double *rhs);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetrngval_async (CPXCENVptr env, CPXCLPptr lp, int begin,
                       int end, CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetrngval_join (CPXASYNCptr *handle_p, double *rngval);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetrowindex_async (CPXCENVptr env, CPXCLPptr lp,
                         char const *lname_str, CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetrowindex_join (CPXASYNCptr *handle_p, int *index_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetrowinfeas_async (CPXCENVptr env, CPXCLPptr lp,
                          double const *x, int begin, int end,
                          CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetrowinfeas_join (CPXASYNCptr *handle_p, double *infeasout);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetrowname_async (CPXCENVptr env, CPXCLPptr lp, int storespace,
                        int begin, int end, CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetrowname_join (CPXASYNCptr *handle_p, char  **name,
                       char *namestore, int *surplus_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetrows_async (CPXCENVptr env, CPXCLPptr lp, int rmatspace,
                     int begin, int end, CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetrows_join (CPXASYNCptr *handle_p, int *nzcnt_p, int *rmatbeg,
                    int *rmatind, double *rmatval, int *surplus_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetsense_async (CPXCENVptr env, CPXCLPptr lp, int begin, int end,
                      CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetsense_join (CPXASYNCptr *handle_p, char *sense);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetslack_async (CPXCENVptr env, CPXCLPptr lp, int begin, int end,
                      CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetslack_join (CPXASYNCptr *handle_p, double *slack);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetsolnpooldblquality_async (CPXCENVptr env, CPXCLPptr lp,
                                   int soln, int what,
                                   CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetsolnpooldblquality_join (CPXASYNCptr *handle_p,
                                  double *quality_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetsolnpooldivfilter_async (CPXCENVptr env, CPXCLPptr lp,
                                  int space, int which,
                                  CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetsolnpooldivfilter_join (CPXASYNCptr *handle_p,
                                 double *lower_cutoff_p,
                                 double *upper_cutoff_p, int *nzcnt_p,
                                 int *ind, double *val, double *refval,
                                 int *surplus_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetsolnpoolfilterindex_async (CPXCENVptr env, CPXCLPptr lp,
                                    char const *lname_str,
                                    CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetsolnpoolfilterindex_join (CPXASYNCptr *handle_p, int *index_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetsolnpoolfiltername_async (CPXCENVptr env, CPXCLPptr lp,
                                   int bufspace, int which,
                                   CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetsolnpoolfiltername_join (CPXASYNCptr *handle_p, char *buf_str,
                                  int *surplus_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetsolnpoolfiltertype_async (CPXCENVptr env, CPXCLPptr lp,
                                   int which, CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetsolnpoolfiltertype_join (CPXASYNCptr *handle_p, int *ftype_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetsolnpoolintquality_async (CPXCENVptr env, CPXCLPptr lp,
                                   int soln, int what,
                                   CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetsolnpoolintquality_join (CPXASYNCptr *handle_p,
                                  int *quality_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetsolnpoolmeanobjval_async (CPXCENVptr env, CPXCLPptr lp,
                                   CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetsolnpoolmeanobjval_join (CPXASYNCptr *handle_p,
                                  double *meanobjval_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetsolnpoolobjval_async (CPXCENVptr env, CPXCLPptr lp, int soln,
                               CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetsolnpoolobjval_join (CPXASYNCptr *handle_p, double *objval_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetsolnpoolqconstrslack_async (CPXCENVptr env, CPXCLPptr lp,
                                     int soln, int begin, int end,
                                     CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetsolnpoolqconstrslack_join (CPXASYNCptr *handle_p,
                                    double *qcslack);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetsolnpoolrngfilter_async (CPXCENVptr env, CPXCLPptr lp,
                                  int space, int which,
                                  CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetsolnpoolrngfilter_join (CPXASYNCptr *handle_p, double *lb_p,
                                 double *ub_p, int *nzcnt_p, int *ind,
                                 double *val, int *surplus_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetsolnpoolslack_async (CPXCENVptr env, CPXCLPptr lp, int soln,
                              int begin, int end,
                              CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetsolnpoolslack_join (CPXASYNCptr *handle_p, double *slack);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetsolnpoolsolnindex_async (CPXCENVptr env, CPXCLPptr lp,
                                  char const *lname_str,
                                  CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetsolnpoolsolnindex_join (CPXASYNCptr *handle_p, int *index_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetsolnpoolsolnname_async (CPXCENVptr env, CPXCLPptr lp,
                                 int storesz, int which,
                                 CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetsolnpoolsolnname_join (CPXASYNCptr *handle_p, char *store,
                                int *surplus_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetsolnpoolx_async (CPXCENVptr env, CPXCLPptr lp, int soln,
                          int begin, int end, CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetsolnpoolx_join (CPXASYNCptr *handle_p, double *x);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetsos_async (CPXCENVptr env, CPXCLPptr lp, int sosspace,
                    int begin, int end, CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetsos_join (CPXASYNCptr *handle_p, int *numsosnz_p,
                   char *sostype, int *sosbeg, int *sosind,
                   double *soswt, int *surplus_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetsosindex_async (CPXCENVptr env, CPXCLPptr lp,
                         char const *lname_str, CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetsosindex_join (CPXASYNCptr *handle_p, int *index_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetsosinfeas_async (CPXCENVptr env, CPXCLPptr lp,
                          double const *x, int begin, int end,
                          CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetsosinfeas_join (CPXASYNCptr *handle_p, double *infeasout);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetsosname_async (CPXCENVptr env, CPXCLPptr lp, int storespace,
                        int begin, int end, CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetsosname_join (CPXASYNCptr *handle_p, char  **name,
                       char *namestore, int *surplus_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgettime_async (CPXCENVptr env, CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgettime_join (CPXASYNCptr *handle_p, double *timestamp_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetub_async (CPXCENVptr env, CPXCLPptr lp, int begin, int end,
                   CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetub_join (CPXASYNCptr *handle_p, double *ub);



CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetx_async (CPXCENVptr env, CPXCLPptr lp, int begin, int end,
                  CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetx_join (CPXASYNCptr *handle_p, double *x);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetxqxax_async (CPXCENVptr env, CPXCLPptr lp, int begin, int end,
                      CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXgetxqxax_join (CPXASYNCptr *handle_p, double *xqxax);


CPXLIBAPI
int CPXPUBLIC
   CPXhybbaropt_async (CPXCENVptr env, CPXLPptr lp, int method,
                       CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXhybbaropt_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXhybbaropt_multicast (CPXENVGROUPptr group, int method);


CPXLIBAPI
int CPXPUBLIC
   CPXhybnetopt_async (CPXCENVptr env, CPXLPptr lp, int method,
                       CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXhybnetopt_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXhybnetopt_multicast (CPXENVGROUPptr group, int method);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXindconstrslackfromx_async (CPXCENVptr env, CPXCLPptr lp,
                                 double const *x,
                                 CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXindconstrslackfromx_join (CPXASYNCptr *handle_p,
                                double *indslack);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXinfodblparam_async (CPXCENVptr env, int whichparam,
                          CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXinfodblparam_join (CPXASYNCptr *handle_p, double *defvalue_p,
                         double *minvalue_p, double *maxvalue_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXinfointparam_async (CPXCENVptr env, int whichparam,
                          CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXinfointparam_join (CPXASYNCptr *handle_p, CPXINT *defvalue_p,
                         CPXINT *minvalue_p, CPXINT *maxvalue_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXinfolongparam_async (CPXCENVptr env, int whichparam,
                           CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXinfolongparam_join (CPXASYNCptr *handle_p, CPXLONG *defvalue_p,
                          CPXLONG *minvalue_p, CPXLONG *maxvalue_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXkilldnorms_async (CPXENVptr env, CPXLPptr lp,
                        CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXkilldnorms_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXkilldnorms_multicast (CPXENVGROUPptr group);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXkillpnorms_async (CPXENVptr env, CPXLPptr lp,
                        CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXkillpnorms_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXkillpnorms_multicast (CPXENVGROUPptr group);




CPXLIBAPI
int CPXPUBLIC
   CPXlpopt_async (CPXCENVptr env, CPXLPptr lp, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXlpopt_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXlpopt_multicast (CPXENVGROUPptr group);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXlprewrite_async (CPXCENVptr env, CPXCLPptr lp,
                       char const *filename_str, CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXlprewrite_join (CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXlprewrite_multicast (CPXENVGROUPptr group,
                           char const *filename_str);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXlpwrite_async (CPXCENVptr env, CPXCLPptr lp,
                     char const *filename_str, CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXlpwrite_join (CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXlpwrite_multicast (CPXENVGROUPptr group,
                         char const *filename_str);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXmbasewrite_async (CPXCENVptr env, CPXCLPptr lp,
                        char const *filename_str,
                        CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXmbasewrite_join (CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXmbasewrite_multicast (CPXENVGROUPptr group,
                            char const *filename_str);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXmdleave_async (CPXCENVptr env, CPXLPptr lp, int const *indices,
                     int cnt, CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXmdleave_join (CPXASYNCptr *handle_p, double *downratio,
                    double *upratio);


CPXLIBAPI
int CPXPUBLIC
   CPXmipopt_async (CPXCENVptr env, CPXLPptr lp, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXmipopt_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXmipopt_multicast (CPXENVGROUPptr group);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXmpsrewrite_async (CPXCENVptr env, CPXCLPptr lp,
                        char const *filename_str,
                        CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXmpsrewrite_join (CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXmpsrewrite_multicast (CPXENVGROUPptr group,
                            char const *filename_str);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXmpswrite_async (CPXCENVptr env, CPXCLPptr lp,
                      char const *filename_str, CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXmpswrite_join (CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXmpswrite_multicast (CPXENVGROUPptr group,
                          char const *filename_str);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXNETaddarcs_async (CPXCENVptr env, CPXNETptr net, int narcs,
                        int const *fromnode, int const *tonode,
                        double const *low, double const *up,
                        double const *obj, char **anames,
                        CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXNETaddarcs_join (CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXNETaddnodes_async (CPXCENVptr env, CPXNETptr net, int nnodes,
                         double const *supply, char **name,
                         CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXNETaddnodes_join (CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXNETbasewrite_async (CPXCENVptr env, CPXCNETptr net,
                          char const *filename_str,
                          CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXNETbasewrite_join (CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXNETbasewrite_multicast (CPXENVGROUPptr group,
                              char const *filename_str);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXNETchgarcname_async (CPXCENVptr env, CPXNETptr net, int cnt,
                           int const *indices, char **newname,
                           CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXNETchgarcname_join (CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXNETchgarcnodes_async (CPXCENVptr env, CPXNETptr net, int cnt,
                            int const *indices, int const *fromnode,
                            int const *tonode, CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXNETchgarcnodes_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXNETchgarcnodes_multicast (CPXENVGROUPptr group, int cnt,
                                int const *indices,
                                int const *fromnode, int const *tonode);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXNETchgbds_async (CPXCENVptr env, CPXNETptr net, int cnt,
                       int const *indices, char const *lu,
                       double const *bd, CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXNETchgbds_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXNETchgbds_multicast (CPXENVGROUPptr group, int cnt,
                           int const *indices, char const *lu,
                           double const *bd);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXNETchgname_async (CPXCENVptr env, CPXNETptr net, int key,
                        int vindex, char const *name_str,
                        CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXNETchgname_join (CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXNETchgnodename_async (CPXCENVptr env, CPXNETptr net, int cnt,
                            int const *indices, char **newname,
                            CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXNETchgnodename_join (CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXNETchgobj_async (CPXCENVptr env, CPXNETptr net, int cnt,
                       int const *indices, double const *obj,
                       CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXNETchgobj_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXNETchgobj_multicast (CPXENVGROUPptr group, int cnt,
                           int const *indices, double const *obj);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXNETchgobjsen_async (CPXCENVptr env, CPXNETptr net, int maxormin,
                          CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXNETchgobjsen_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXNETchgobjsen_multicast (CPXENVGROUPptr group, int maxormin);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXNETchgsupply_async (CPXCENVptr env, CPXNETptr net, int cnt,
                          int const *indices, double const *supply,
                          CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXNETchgsupply_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXNETchgsupply_multicast (CPXENVGROUPptr group, int cnt,
                              int const *indices, double const *supply);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXNETcopybase_async (CPXCENVptr env, CPXNETptr net,
                         int const *astat, int const *nstat,
                         CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXNETcopybase_join (CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXNETcopynet_async (CPXCENVptr env, CPXNETptr net, int objsen,
                        int nnodes, double const *supply,
                        char **nnames, int narcs, int const *fromnode,
                        int const *tonode, double const *low,
                        double const *up, double const *obj,
                        char **anames, CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXNETcopynet_join (CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXNETdelarcs_async (CPXCENVptr env, CPXNETptr net, int begin,
                        int end, CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXNETdelarcs_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXNETdelarcs_multicast (CPXENVGROUPptr group, int begin, int end);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXNETdelnodes_async (CPXCENVptr env, CPXNETptr net, int begin,
                         int end, CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXNETdelnodes_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXNETdelnodes_multicast (CPXENVGROUPptr group, int begin, int end);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXNETdelset_async (CPXCENVptr env, CPXNETptr net, int *whichnodes,
                       int *whicharcs, CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXNETdelset_join (CPXASYNCptr *handle_p, int *whichnodes,
                      int *whicharcs);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXNETextract_async (CPXCENVptr env, CPXNETptr net, CPXCLPptr lp,
                        CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXNETextract_join (CPXASYNCptr *handle_p, int *colmap, int *rowmap);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXNETgetarcindex_async (CPXCENVptr env, CPXCNETptr net,
                            char const *lname_str,
                            CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXNETgetarcindex_join (CPXASYNCptr *handle_p, int *index_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXNETgetarcname_async (CPXCENVptr env, CPXCNETptr net, int namespc,
                           int begin, int end, CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXNETgetarcname_join (CPXASYNCptr *handle_p, char  **nnames,
                          char *namestore, int *surplus_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXNETgetarcnodes_async (CPXCENVptr env, CPXCNETptr net, int begin,
                            int end, CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXNETgetarcnodes_join (CPXASYNCptr *handle_p, int *fromnode,
                           int *tonode);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXNETgetbase_async (CPXCENVptr env, CPXCNETptr net,
                        CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXNETgetbase_join (CPXASYNCptr *handle_p, int *astat, int *nstat);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXNETgetdj_async (CPXCENVptr env, CPXCNETptr net, int begin,
                      int end, CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXNETgetdj_join (CPXASYNCptr *handle_p, double *dj);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXNETgetlb_async (CPXCENVptr env, CPXCNETptr net, int begin,
                      int end, CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXNETgetlb_join (CPXASYNCptr *handle_p, double *low);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXNETgetnodearcs_async (CPXCENVptr env, CPXCNETptr net,
                            int arcspace, int begin, int end,
                            CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXNETgetnodearcs_join (CPXASYNCptr *handle_p, int *arccnt_p,
                           int *arcbeg, int *arc, int *surplus_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXNETgetnodeindex_async (CPXCENVptr env, CPXCNETptr net,
                             char const *lname_str,
                             CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXNETgetnodeindex_join (CPXASYNCptr *handle_p, int *index_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXNETgetnodename_async (CPXCENVptr env, CPXCNETptr net,
                            int namespc, int begin, int end,
                            CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXNETgetnodename_join (CPXASYNCptr *handle_p, char  **nnames,
                           char *namestore, int *surplus_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXNETgetobj_async (CPXCENVptr env, CPXCNETptr net, int begin,
                       int end, CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXNETgetobj_join (CPXASYNCptr *handle_p, double *obj);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXNETgetobjval_async (CPXCENVptr env, CPXCNETptr net,
                          CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXNETgetobjval_join (CPXASYNCptr *handle_p, double *objval_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXNETgetpi_async (CPXCENVptr env, CPXCNETptr net, int begin,
                      int end, CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXNETgetpi_join (CPXASYNCptr *handle_p, double *pi);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXNETgetprobname_async (CPXCENVptr env, CPXCNETptr net,
                            int bufspace, CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXNETgetprobname_join (CPXASYNCptr *handle_p, char *buf_str,
                           int *surplus_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXNETgetslack_async (CPXCENVptr env, CPXCNETptr net, int begin,
                         int end, CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXNETgetslack_join (CPXASYNCptr *handle_p, double *slack);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXNETgetsupply_async (CPXCENVptr env, CPXCNETptr net, int begin,
                          int end, CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXNETgetsupply_join (CPXASYNCptr *handle_p, double *supply);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXNETgetub_async (CPXCENVptr env, CPXCNETptr net, int begin,
                      int end, CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXNETgetub_join (CPXASYNCptr *handle_p, double *up);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXNETgetx_async (CPXCENVptr env, CPXCNETptr net, int begin,
                     int end, CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXNETgetx_join (CPXASYNCptr *handle_p, double *x);


CPXLIBAPI
int CPXPUBLIC
   CPXNETprimopt_async (CPXCENVptr env, CPXNETptr net,
                        CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXNETprimopt_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXNETprimopt_multicast (CPXENVGROUPptr group);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXNETreadcopybase_async (CPXCENVptr env, CPXNETptr net,
                             char const *filename_str,
                             CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXNETreadcopybase_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXNETreadcopybase_multicast (CPXENVGROUPptr group,
                                 char const *filename_str);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXNETreadcopyprob_async (CPXCENVptr env, CPXNETptr net,
                             char const *filename_str,
                             CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXNETreadcopyprob_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXNETreadcopyprob_multicast (CPXENVGROUPptr group,
                                 char const *filename_str);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXNETsolninfo_async (CPXCENVptr env, CPXCNETptr net,
                         CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXNETsolninfo_join (CPXASYNCptr *handle_p, int *pfeasind_p,
                        int *dfeasind_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXNETsolution_async (CPXCENVptr env, CPXCNETptr net,
                         CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXNETsolution_join (CPXASYNCptr *handle_p, int *netstat_p,
                        double *objval_p, double *x, double *pi,
                        double *slack, double *dj);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXNETwriteprob_async (CPXCENVptr env, CPXCNETptr net,
                          char const *filename_str,
                          char const *format_str,
                          CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXNETwriteprob_join (CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXNETwriteprob_multicast (CPXENVGROUPptr group,
                              char const *filename_str,
                              char const *format_str);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXnewcols_async (CPXCENVptr env, CPXLPptr lp, int ccnt,
                     double const *obj, double const *lb,
                     double const *ub, char const *xctype,
                     char **colname, CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXnewcols_join (CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXnewrows_async (CPXCENVptr env, CPXLPptr lp, int rcnt,
                     double const *rhs, char const *sense,
                     double const *rngval, char **rowname,
                     CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXnewrows_join (CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXobjsa_async (CPXCENVptr env, CPXCLPptr lp, int begin, int end,
                   CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXobjsa_join (CPXASYNCptr *handle_p, double *lower, double *upper);


CPXLIBAPI
CPXENVptr CPXPUBLIC
   CPXopenCPLEXreconnect (int *status_p, void const *buffer);


CPXLIBAPI
CPXENVptr CPXPUBLIC
   CPXopenCPLEXremote (char const *transport, int argc,
                       char const *const *argv, int *status_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXordread_async (CPXCENVptr env, char const *filename_str,
                     int numcols, char **colname,
                     CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXordread_join (CPXASYNCptr *handle_p, int *cnt_p, int *indices,
                    int *priority, int *direction);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXordwrite_async (CPXCENVptr env, CPXCLPptr lp,
                      char const *filename_str, CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXordwrite_join (CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXordwrite_multicast (CPXENVGROUPptr group,
                          char const *filename_str);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXpivot_async (CPXCENVptr env, CPXLPptr lp, int jenter, int jleave,
                   int leavestat, CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXpivot_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXpivot_multicast (CPXENVGROUPptr group, int jenter, int jleave,
                       int leavestat);


CPXLIBAPI
int CPXPUBLIC
   CPXpivotin_async (CPXCENVptr env, CPXLPptr lp, int const *rlist,
                     int rlen, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXpivotin_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXpivotin_multicast (CPXENVGROUPptr group, int const *rlist,
                         int rlen);


CPXLIBAPI
int CPXPUBLIC
   CPXpivotout_async (CPXCENVptr env, CPXLPptr lp, int const *clist,
                      int clen, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXpivotout_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXpivotout_multicast (CPXENVGROUPptr group, int const *clist,
                          int clen);


CPXLIBAPI
int CPXPUBLIC
   CPXpopulate_async (CPXCENVptr env, CPXLPptr lp,
                      CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXpopulate_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXpopulate_multicast (CPXENVGROUPptr group);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXpperwrite_async (CPXCENVptr env, CPXLPptr lp,
                       char const *filename_str, double epsilon,
                       CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXpperwrite_join (CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXpperwrite_multicast (CPXENVGROUPptr group,
                           char const *filename_str, double epsilon);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXpratio_async (CPXCENVptr env, CPXLPptr lp, int *indices, int cnt,
                    CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXpratio_join (CPXASYNCptr *handle_p, int *indices,
                   double *downratio, double *upratio, int *downleave,
                   int *upleave, int *downleavestatus,
                   int *upleavestatus, int *downstatus, int *upstatus);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXpreaddrows_async (CPXCENVptr env, CPXLPptr lp, int rcnt,
                        int nzcnt, double const *rhs,
                        char const *sense, int const *rmatbeg,
                        int const *rmatind, double const *rmatval,
                        char **rowname, CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXpreaddrows_join (CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXprechgobj_async (CPXCENVptr env, CPXLPptr lp, int cnt,
                       int const *indices, double const *values,
                       CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXprechgobj_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXprechgobj_multicast (CPXENVGROUPptr group, int cnt,
                           int const *indices, double const *values);


CPXLIBAPI
int CPXPUBLIC
   CPXpreslvwrite_async (CPXCENVptr env, CPXLPptr lp,
                         char const *filename_str,
                         CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXpreslvwrite_join (CPXASYNCptr *handle_p, double *objoff_p);


CPXLIBAPI
int CPXPUBLIC
   CPXpresolve_async (CPXCENVptr env, CPXLPptr lp, int method,
                      CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXpresolve_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXpresolve_multicast (CPXENVGROUPptr group, int method);


CPXLIBAPI
int CPXPUBLIC
   CPXprimopt_async (CPXCENVptr env, CPXLPptr lp,
                     CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXprimopt_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXprimopt_multicast (CPXENVGROUPptr group);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXqconstrslackfromx_async (CPXCENVptr env, CPXCLPptr lp,
                               double const *x, CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXqconstrslackfromx_join (CPXASYNCptr *handle_p, double *qcslack);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXqpdjfrompi_async (CPXCENVptr env, CPXCLPptr lp, double const *pi,
                        double const *x, CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXqpdjfrompi_join (CPXASYNCptr *handle_p, double *dj);


CPXLIBAPI
int CPXPUBLIC
   CPXqpindefcertificate_async (CPXCENVptr env, CPXCLPptr lp,
                                CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXqpindefcertificate_join (CPXASYNCptr *handle_p, double *x);


CPXLIBAPI
int CPXPUBLIC
   CPXqpopt_async (CPXCENVptr env, CPXLPptr lp, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXqpopt_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXqpopt_multicast (CPXENVGROUPptr group);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXqpuncrushpi_async (CPXCENVptr env, CPXCLPptr lp,
                         double const *prepi, double const *x,
                         CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXqpuncrushpi_join (CPXASYNCptr *handle_p, double *pi);


CPXLIBAPI
int CPXPUBLIC
   CPXreadcopyannotations_multicast (CPXENVGROUPptr group,
                                     char const *filename);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXreadcopybase_async (CPXCENVptr env, CPXLPptr lp,
                          char const *filename_str,
                          CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXreadcopybase_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXreadcopybase_multicast (CPXENVGROUPptr group,
                              char const *filename_str);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXreadcopymipstarts_async (CPXCENVptr env, CPXLPptr lp,
                               char const *filename_str,
                               CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXreadcopymipstarts_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXreadcopymipstarts_multicast (CPXENVGROUPptr group,
                                   char const *filename_str);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXreadcopyorder_async (CPXCENVptr env, CPXLPptr lp,
                           char const *filename_str,
                           CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXreadcopyorder_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXreadcopyorder_multicast (CPXENVGROUPptr group,
                               char const *filename_str);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXreadcopyparam_async (CPXENVptr env, char const *filename_str,
                           CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXreadcopyparam_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXreadcopyparam_multicast (CPXENVGROUPptr group,
                               char const *filename_str);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXreadcopyprob_async (CPXCENVptr env, CPXLPptr lp,
                          char const *filename_str,
                          char const *filetype_str,
                          CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXreadcopyprob_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXreadcopyprob_multicast (CPXENVGROUPptr group,
                              char const *filename_str,
                              char const *filetype_str);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXreadcopysol_async (CPXCENVptr env, CPXLPptr lp,
                         char const *filename_str,
                         CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXreadcopysol_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXreadcopysol_multicast (CPXENVGROUPptr group,
                             char const *filename_str);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXreadcopysolnpoolfilters_async (CPXCENVptr env, CPXLPptr lp,
                                     char const *filename_str,
                                     CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXreadcopysolnpoolfilters_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXreadcopysolnpoolfilters_multicast (CPXENVGROUPptr group,
                                         char const *filename_str);


CPXLIBAPI
int CPXPUBLIC
   CPXrefineconflict_async (CPXCENVptr env, CPXLPptr lp,
                            CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXrefineconflict_join (CPXASYNCptr *handle_p, int *confnumrows_p,
                           int *confnumcols_p);


CPXLIBAPI
int CPXPUBLIC
   CPXrefineconflictext_async (CPXCENVptr env, CPXLPptr lp, int grpcnt,
                               int concnt, double const *grppref,
                               int const *grpbeg, int const *grpind,
                               char const *grptype,
                               CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXrefineconflictext_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXrefineconflictext_multicast (CPXENVGROUPptr group, int grpcnt,
                                   int concnt, double const *grppref,
                                   int const *grpbeg,
                                   int const *grpind,
                                   char const *grptype);


CPXLIBAPI
int CPXPUBLIC
   CPXrefinemipstartconflict_async (CPXCENVptr env, CPXLPptr lp,
                                    int mipstartindex,
                                    CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXrefinemipstartconflict_join (CPXASYNCptr *handle_p,
                                   int *confnumrows_p,
                                   int *confnumcols_p);


CPXLIBAPI
int CPXPUBLIC
   CPXrefinemipstartconflictext_async (CPXCENVptr env, CPXLPptr lp,
                                       int mipstartindex, int grpcnt,
                                       int concnt,
                                       double const *grppref,
                                       int const *grpbeg,
                                       int const *grpind,
                                       char const *grptype,
                                       CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXrefinemipstartconflictext_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXrefinemipstartconflictext_multicast (CPXENVGROUPptr group,
                                           int mipstartindex,
                                           int grpcnt, int concnt,
                                           double const *grppref,
                                           int const *grpbeg,
                                           int const *grpind,
                                           char const *grptype);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXrhssa_async (CPXCENVptr env, CPXCLPptr lp, int begin, int end,
                   CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXrhssa_join (CPXASYNCptr *handle_p, double *lower, double *upper);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXsavwrite_async (CPXCENVptr env, CPXCLPptr lp,
                      char const *filename_str, CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXsavwrite_join (CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXsavwrite_multicast (CPXENVGROUPptr group,
                          char const *filename_str);







CPXLIBAPI
int CPXPUBLIC
   CPXsetdblannotations_multicast (CPXENVGROUPptr group, int idx,
                                   int objtype, int cnt,
                                   int const *indices,
                                   double const *values);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXsetdblparam_async (CPXENVptr env, int whichparam,
                         double newvalue, CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXsetdblparam_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXsetdblparam_multicast (CPXENVGROUPptr group, int whichparam,
                             double newvalue);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXsetdefaults_async (CPXENVptr env, CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXsetdefaults_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXsetdefaults_multicast (CPXENVGROUPptr group);


CPXLIBAPI
int CPXPUBLIC
   CPXsetinfohandler (CPXENVptr env, CPXINFOHANDLER *infohandler,
                      void *handle);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXsetintparam_async (CPXENVptr env, int whichparam,
                         CPXINT newvalue, CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXsetintparam_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXsetintparam_multicast (CPXENVGROUPptr group, int whichparam,
                             CPXINT newvalue);


CPXLIBAPI
int CPXPUBLIC
   CPXsetlongannotations_multicast (CPXENVGROUPptr group, int idx,
                                    int objtype, int cnt,
                                    int const *indices,
                                    CPXLONG const *values);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXsetlongparam_async (CPXENVptr env, int whichparam,
                          CPXLONG newvalue, CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXsetlongparam_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXsetlongparam_multicast (CPXENVGROUPptr group, int whichparam,
                              CPXLONG newvalue);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXsetphase2_async (CPXCENVptr env, CPXLPptr lp,
                       CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXsetphase2_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXsetphase2_multicast (CPXENVGROUPptr group);



CPXLIBAPI
int CPXPUBLIC
   CPXsiftopt_async (CPXCENVptr env, CPXLPptr lp,
                     CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXsiftopt_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXsiftopt_multicast (CPXENVGROUPptr group);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXslackfromx_async (CPXCENVptr env, CPXCLPptr lp, double const *x,
                        CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXslackfromx_join (CPXASYNCptr *handle_p, double *slack);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXsolninfo_async (CPXCENVptr env, CPXCLPptr lp,
                      CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXsolninfo_join (CPXASYNCptr *handle_p, int *solnmethod_p,
                     int *solntype_p, int *pfeasind_p, int *dfeasind_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXsolution_async (CPXCENVptr env, CPXCLPptr lp,
                      CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXsolution_join (CPXASYNCptr *handle_p, int *lpstat_p,
                     double *objval_p, double *x, double *pi,
                     double *slack, double *dj);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXsolwrite_async (CPXCENVptr env, CPXCLPptr lp,
                      char const *filename_str, CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXsolwrite_join (CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXsolwrite_multicast (CPXENVGROUPptr group,
                          char const *filename_str);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXsolwritesolnpool_async (CPXCENVptr env, CPXCLPptr lp, int soln,
                              char const *filename_str,
                              CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXsolwritesolnpool_join (CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXsolwritesolnpool_multicast (CPXENVGROUPptr group, int soln,
                                  char const *filename_str);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXsolwritesolnpoolall_async (CPXCENVptr env, CPXCLPptr lp,
                                 char const *filename_str,
                                 CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXsolwritesolnpoolall_join (CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXsolwritesolnpoolall_multicast (CPXENVGROUPptr group,
                                     char const *filename_str);




CPXLIBAPI
int CPXPUBLIC
   CPXstrongbranch_async (CPXCENVptr env, CPXLPptr lp,
                          int const *indices, int cnt, int itlim,
                          CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXstrongbranch_join (CPXASYNCptr *handle_p, double *downobj,
                         double *upobj);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXtightenbds_async (CPXCENVptr env, CPXLPptr lp, int cnt,
                        int const *indices, char const *lu,
                        double const *bd, CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXtightenbds_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXtightenbds_multicast (CPXENVGROUPptr group, int cnt,
                            int const *indices, char const *lu,
                            double const *bd);


CPXLIBAPI
int CPXPUBLIC
   CPXtransportctrldbl (CPXCENVptr env, int ctrl, double *data_p);


CPXLIBAPI
int CPXPUBLIC
   CPXtransportctrlint (CPXCENVptr env, int ctrl, CPXINT *data_p);


CPXLIBAPI
int CPXPUBLIC
   CPXtransportctrllong (CPXCENVptr env, int ctrl, CPXLONG *data_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXtuneparam_async (CPXENVptr env, CPXLPptr lp, int intcnt,
                       int const *intnum, int const *intval,
                       int dblcnt, int const *dblnum,
                       double const *dblval, int strcnt,
                       int const *strnum, char **strval,
                       CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXtuneparam_join (CPXASYNCptr *handle_p, int *tunestat_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXuncrushpi_async (CPXCENVptr env, CPXCLPptr lp,
                       double const *prepi, CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXuncrushpi_join (CPXASYNCptr *handle_p, double *pi);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXuncrushx_async (CPXCENVptr env, CPXCLPptr lp, double const *prex,
                      CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXuncrushx_join (CPXASYNCptr *handle_p, double *x);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXunscaleprob_async (CPXCENVptr env, CPXLPptr lp,
                         CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXunscaleprob_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXunscaleprob_multicast (CPXENVGROUPptr group);


CPXLIBAPI
int CPXPUBLIC
   CPXuserfunction (CPXENVptr env, int id, CPXLONG insize,
                    void const *indata, CPXLONG outspace,
                    CPXLONG *outsize_p, void *outdata);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXuserfunction_async (CPXENVptr env, int id, CPXLONG insize,
                          void const *indata, CPXLONG outspace,
                          CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXuserfunction_join (CPXASYNCptr *handle_p, CPXLONG *outsize_p,
                         void *outdata);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXwritemipstarts_async (CPXCENVptr env, CPXCLPptr lp,
                            char const *filename_str, int begin,
                            int end, CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXwritemipstarts_join (CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXwritemipstarts_multicast (CPXENVGROUPptr group,
                                char const *filename_str, int begin,
                                int end);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXwriteparam_async (CPXCENVptr env, char const *filename_str,
                        CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXwriteparam_join (CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXwriteparam_multicast (CPXENVGROUPptr group,
                            char const *filename_str);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXwriteprob_async (CPXCENVptr env, CPXCLPptr lp,
                       char const *filename_str,
                       char const *filetype_str, CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXwriteprob_join (CPXASYNCptr *handle_p);


CPXDEPRECATEDAPI(12700000)
int CPXPUBLIC
   CPXwriteprob_multicast (CPXENVGROUPptr group,
                           char const *filename_str,
                           char const *filetype_str);



#ifdef __cplusplus
}
#endif

#ifdef _WIN32
#pragma pack(pop)
#endif

#endif /* !CPX_CPLEX_REMOTEMASTER_H */
