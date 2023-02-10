/* --------------------------------------------------------------------------
 * File: cplexremotemaster.h
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

#ifndef CPX_CPLEX_REMOTEMASTER_H
#   define CPX_CPLEX_REMOTEMASTER_H 1
#include "ilcplex/cplexremote.h"

#ifdef _WIN32
#pragma pack(push, 8)
#endif

#ifdef __cplusplus
extern "C" {
#endif

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


CPXLIBAPI
int CPXPUBLIC
   CPXchgbds_multicast (CPXENVGROUPptr group, int cnt,
                        int const *indices, char const *lu,
                        double const *bd);


CPXLIBAPI
int CPXPUBLIC
   CPXchgcoef_multicast (CPXENVGROUPptr group, int i, int j,
                         double newvalue);


CPXLIBAPI
int CPXPUBLIC
   CPXchgcoeflist_multicast (CPXENVGROUPptr group, int numcoefs,
                             int const *rowlist, int const *collist,
                             double const *vallist);


CPXLIBAPI
int CPXPUBLIC
   CPXchgctype_multicast (CPXENVGROUPptr group, int cnt,
                          int const *indices, char const *xctype);


CPXLIBAPI
int CPXPUBLIC
   CPXchgmipstarts_multicast (CPXENVGROUPptr group, int mcnt,
                              int const *mipstartindices, int nzcnt,
                              int const *beg, int const *varindices,
                              double const *values,
                              int const *effortlevel);


CPXLIBAPI
int CPXPUBLIC
   CPXchgobj_multicast (CPXENVGROUPptr group, int cnt,
                        int const *indices, double const *values);


CPXLIBAPI
int CPXPUBLIC
   CPXchgobjoffset_multicast (CPXENVGROUPptr group, double offset);


CPXLIBAPI
int CPXPUBLIC
   CPXchgobjsen_multicast (CPXENVGROUPptr group, int maxormin);


CPXLIBAPI
int CPXPUBLIC
   CPXchgprobtype_multicast (CPXENVGROUPptr group, int type);


CPXLIBAPI
int CPXPUBLIC
   CPXchgprobtypesolnpool_multicast (CPXENVGROUPptr group, int type,
                                     int soln);


CPXLIBAPI
int CPXPUBLIC
   CPXchgqpcoef_multicast (CPXENVGROUPptr group, int i, int j,
                           double newvalue);


CPXLIBAPI
int CPXPUBLIC
   CPXchgrhs_multicast (CPXENVGROUPptr group, int cnt,
                        int const *indices, double const *values);


CPXLIBAPI
int CPXPUBLIC
   CPXchgrngval_multicast (CPXENVGROUPptr group, int cnt,
                           int const *indices, double const *values);


CPXLIBAPI
int CPXPUBLIC
   CPXchgsense_multicast (CPXENVGROUPptr group, int cnt,
                          int const *indices, char const *sense);


CPXLIBAPI
int CPXPUBLIC
   CPXcleanup_multicast (CPXENVGROUPptr group, double eps);


CPXLIBAPI
int CPXPUBLIC
   CPXcloseCPLEXdisconnect (CPXENVptr *env_p, void *buffer);


CPXLIBAPI
int CPXPUBLIC
   CPXcompletelp_multicast (CPXENVGROUPptr group);


CPXLIBAPI
int CPXPUBLIC
   CPXcopydnorms_multicast (CPXENVGROUPptr group, double const *norm,
                            int const *head, int len);


CPXLIBAPI
int CPXPUBLIC
   CPXcopylp_multicast (CPXENVGROUPptr group, int numcols, int numrows,
                        int objsense, double const *objective,
                        double const *rhs, char const *sense,
                        int const *matbeg, int const *matcnt,
                        int const *matind, double const *matval,
                        double const *lb, double const *ub,
                        double const *rngval);


CPXLIBAPI
int CPXPUBLIC
   CPXcopynettolp_multicast (CPXENVGROUPptr group);


CPXLIBAPI
int CPXPUBLIC
   CPXcopyorder_multicast (CPXENVGROUPptr group, int cnt,
                           int const *indices, int const *priority,
                           int const *direction);


CPXLIBAPI
int CPXPUBLIC
   CPXcopypartialbase_multicast (CPXENVGROUPptr group, int ccnt,
                                 int const *cindices, int const *cstat,
                                 int rcnt, int const *rindices,
                                 int const *rstat);


CPXLIBAPI
int CPXPUBLIC
   CPXcopyprotected_multicast (CPXENVGROUPptr group, int cnt,
                               int const *indices);


CPXLIBAPI
int CPXPUBLIC
   CPXcreateenvgroup (CPXENVGROUPptr *group_p, int nenvs,
                      CPXENVptr const *envs);


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


CPXLIBAPI
int CPXPUBLIC
   CPXdelmipstarts_multicast (CPXENVGROUPptr group, int begin, int end);


CPXLIBAPI
int CPXPUBLIC
   CPXdelnames_multicast (CPXENVGROUPptr group);


CPXLIBAPI
int CPXPUBLIC
   CPXdelqconstrs_multicast (CPXENVGROUPptr group, int begin, int end);


CPXLIBAPI
int CPXPUBLIC
   CPXdelrows_multicast (CPXENVGROUPptr group, int begin, int end);


CPXLIBAPI
int CPXPUBLIC
   CPXdelsolnpoolfilters_multicast (CPXENVGROUPptr group, int begin,
                                    int end);


CPXLIBAPI
int CPXPUBLIC
   CPXdelsolnpoolsolns_multicast (CPXENVGROUPptr group, int begin,
                                  int end);


CPXLIBAPI
int CPXPUBLIC
   CPXdelsos_multicast (CPXENVGROUPptr group, int begin, int end);


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


CPXLIBAPI
int CPXPUBLIC
   CPXembwrite_async (CPXCENVptr env, CPXLPptr lp,
                      char const *filename_str, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXembwrite_join (CPXASYNCptr *handle_p);


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


CPXLIBAPI
void CPXPUBLIC
   CPXfreeenvgroup (CPXENVGROUPptr *group_p);


CPXLIBAPI
int CPXPUBLIC
   CPXfreelazyconstraints_multicast (CPXENVGROUPptr group);


CPXLIBAPI
int CPXPUBLIC
   CPXfreepresolve_multicast (CPXENVGROUPptr group);


CPXLIBAPI
int CPXPUBLIC
   CPXfreeusercuts_multicast (CPXENVGROUPptr group);


CPXLIBAPI
int CPXPUBLIC
   CPXgetasynchandlesize (CPXCASYNCptr asynchandle);


CPXLIBAPI
void const * CPXPUBLIC
   CPXgetasynctab (void);


CPXLIBAPI
CPXENVptr CPXPUBLIC
   CPXgetenvgroupenv (CPXCENVGROUPptr group, int idx);


CPXLIBAPI
int CPXPUBLIC
   CPXgetenvgroupsize (CPXCENVGROUPptr group);


CPXLIBAPI
int CPXPUBLIC
   CPXgetinfohandler (CPXCENVptr env, CPXINFOHANDLER  **infohandler_p,
                      void  **handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXgetlps (CPXCENVptr env, int capacity, CPXLPptr *lps,
              int *count_p, int *total_p);


CPXLIBAPI
int CPXPUBLIC
   CPXgetreconnectinfolen (CPXCENVptr env);



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


CPXLIBAPI
int CPXPUBLIC
   CPXkilldnorms_multicast (CPXENVGROUPptr group);


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


CPXLIBAPI
int CPXPUBLIC
   CPXmipopt_async (CPXCENVptr env, CPXLPptr lp, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXmipopt_join (CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXmipopt_multicast (CPXENVGROUPptr group);


CPXLIBAPI
int CPXPUBLIC
   CPXNETchgarcnodes_multicast (CPXENVGROUPptr group, int cnt,
                                int const *indices,
                                int const *fromnode, int const *tonode);


CPXLIBAPI
int CPXPUBLIC
   CPXNETchgbds_multicast (CPXENVGROUPptr group, int cnt,
                           int const *indices, char const *lu,
                           double const *bd);


CPXLIBAPI
int CPXPUBLIC
   CPXNETchgobj_multicast (CPXENVGROUPptr group, int cnt,
                           int const *indices, double const *obj);


CPXLIBAPI
int CPXPUBLIC
   CPXNETchgobjsen_multicast (CPXENVGROUPptr group, int maxormin);


CPXLIBAPI
int CPXPUBLIC
   CPXNETchgsupply_multicast (CPXENVGROUPptr group, int cnt,
                              int const *indices, double const *supply);


CPXLIBAPI
int CPXPUBLIC
   CPXNETdelarcs_multicast (CPXENVGROUPptr group, int begin, int end);


CPXLIBAPI
int CPXPUBLIC
   CPXNETdelnodes_multicast (CPXENVGROUPptr group, int begin, int end);


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


CPXLIBAPI
int CPXPUBLIC
   CPXNETreadcopybase_multicast (CPXENVGROUPptr group,
                                 char const *filename_str);


CPXLIBAPI
int CPXPUBLIC
   CPXNETreadcopyprob_multicast (CPXENVGROUPptr group,
                                 char const *filename_str);


CPXLIBAPI
CPXENVptr CPXPUBLIC
   CPXopenCPLEXreconnect (int *status_p, void const *buffer);


CPXLIBAPI
CPXENVptr CPXPUBLIC
   CPXopenCPLEXremote (char const *transport, int argc,
                       char const *const *argv, int *status_p);


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


CPXLIBAPI
int CPXPUBLIC
   CPXreadcopyannotations_multicast (CPXENVGROUPptr group,
                                     char const *filename);


CPXLIBAPI
int CPXPUBLIC
   CPXreadcopybase_multicast (CPXENVGROUPptr group,
                              char const *filename_str);


CPXLIBAPI
int CPXPUBLIC
   CPXreadcopymipstarts_multicast (CPXENVGROUPptr group,
                                   char const *filename_str);


CPXLIBAPI
int CPXPUBLIC
   CPXreadcopyorder_multicast (CPXENVGROUPptr group,
                               char const *filename_str);


CPXLIBAPI
int CPXPUBLIC
   CPXreadcopyparam_multicast (CPXENVGROUPptr group,
                               char const *filename_str);


CPXLIBAPI
int CPXPUBLIC
   CPXreadcopyprob_multicast (CPXENVGROUPptr group,
                              char const *filename_str,
                              char const *filetype_str);


CPXLIBAPI
int CPXPUBLIC
   CPXreadcopysol_multicast (CPXENVGROUPptr group,
                             char const *filename_str);


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







CPXLIBAPI
int CPXPUBLIC
   CPXsetdblannotations_multicast (CPXENVGROUPptr group, int idx,
                                   int objtype, int cnt,
                                   int const *indices,
                                   double const *values);


CPXLIBAPI
int CPXPUBLIC
   CPXsetdblparam_multicast (CPXENVGROUPptr group, int whichparam,
                             double newvalue);


CPXLIBAPI
int CPXPUBLIC
   CPXsetdefaults_multicast (CPXENVGROUPptr group);


CPXLIBAPI
int CPXPUBLIC
   CPXsetinfohandler (CPXENVptr env, CPXINFOHANDLER *infohandler,
                      void *handle);


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


CPXLIBAPI
int CPXPUBLIC
   CPXsetlongparam_multicast (CPXENVGROUPptr group, int whichparam,
                              CPXLONG newvalue);


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




CPXLIBAPI
int CPXPUBLIC
   CPXstrongbranch_async (CPXCENVptr env, CPXLPptr lp,
                          int const *indices, int cnt, int itlim,
                          CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXstrongbranch_join (CPXASYNCptr *handle_p, double *downobj,
                         double *upobj);


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


CPXLIBAPI
int CPXPUBLIC
   CPXtuneparam_async (CPXENVptr env, CPXLPptr lp, int intcnt,
                       int const *intnum, int const *intval,
                       int dblcnt, int const *dblnum,
                       double const *dblval, int strcnt,
                       int const *strnum, char **strval,
                       CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXtuneparam_join (CPXASYNCptr *handle_p, int *tunestat_p);


CPXLIBAPI
int CPXPUBLIC
   CPXunscaleprob_multicast (CPXENVGROUPptr group);


CPXLIBAPI
int CPXPUBLIC
   CPXuserfunction (CPXENVptr env, int id, CPXLONG insize,
                    void const *indata, CPXLONG outspace,
                    CPXLONG *outsize_p, void *outdata);


CPXLIBAPI
int CPXPUBLIC
   CPXuserfunction_async (CPXENVptr env, int id, CPXLONG insize,
                          void const *indata, CPXLONG outspace,
                          CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXuserfunction_join (CPXASYNCptr *handle_p, CPXLONG *outsize_p,
                         void *outdata);



#ifdef __cplusplus
}
#endif

#ifdef _WIN32
#pragma pack(pop)
#endif

#endif /* !CPX_CPLEX_REMOTEMASTER_H */
