/* --------------------------------------------------------------------------
 * File: cplexremotemasterl.h
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
   CPXLchgbds_multicast (CPXENVGROUPptr group, CPXINT cnt,
                         CPXINT const *indices, char const *lu,
                         double const *bd);


CPXLIBAPI
int CPXPUBLIC
   CPXLchgcoef_multicast (CPXENVGROUPptr group, CPXINT i, CPXINT j,
                          double newvalue);


CPXLIBAPI
int CPXPUBLIC
   CPXLchgcoeflist_multicast (CPXENVGROUPptr group, CPXLONG numcoefs,
                              CPXINT const *rowlist,
                              CPXINT const *collist,
                              double const *vallist);


CPXLIBAPI
int CPXPUBLIC
   CPXLchgctype_multicast (CPXENVGROUPptr group, CPXINT cnt,
                           CPXINT const *indices, char const *xctype);


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
   CPXLchgobj_multicast (CPXENVGROUPptr group, CPXINT cnt,
                         CPXINT const *indices, double const *values);


CPXLIBAPI
int CPXPUBLIC
   CPXLchgobjoffset_multicast (CPXENVGROUPptr group, double offset);


CPXLIBAPI
int CPXPUBLIC
   CPXLchgobjsen_multicast (CPXENVGROUPptr group, int maxormin);


CPXLIBAPI
int CPXPUBLIC
   CPXLchgprobtype_multicast (CPXENVGROUPptr group, int type);


CPXLIBAPI
int CPXPUBLIC
   CPXLchgprobtypesolnpool_multicast (CPXENVGROUPptr group, int type,
                                      int soln);


CPXLIBAPI
int CPXPUBLIC
   CPXLchgqpcoef_multicast (CPXENVGROUPptr group, CPXINT i, CPXINT j,
                            double newvalue);


CPXLIBAPI
int CPXPUBLIC
   CPXLchgrhs_multicast (CPXENVGROUPptr group, CPXINT cnt,
                         CPXINT const *indices, double const *values);


CPXLIBAPI
int CPXPUBLIC
   CPXLchgrngval_multicast (CPXENVGROUPptr group, CPXINT cnt,
                            CPXINT const *indices,
                            double const *values);


CPXLIBAPI
int CPXPUBLIC
   CPXLchgsense_multicast (CPXENVGROUPptr group, CPXINT cnt,
                           CPXINT const *indices, char const *sense);


CPXLIBAPI
int CPXPUBLIC
   CPXLcleanup_multicast (CPXENVGROUPptr group, double eps);


CPXLIBAPI
int CPXPUBLIC
   CPXLcloseCPLEXdisconnect (CPXENVptr *env_p, void *buffer);


CPXLIBAPI
int CPXPUBLIC
   CPXLcompletelp_multicast (CPXENVGROUPptr group);


CPXLIBAPI
int CPXPUBLIC
   CPXLcopydnorms_multicast (CPXENVGROUPptr group, double const *norm,
                             CPXINT const *head, CPXINT len);


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
   CPXLcopynettolp_multicast (CPXENVGROUPptr group);


CPXLIBAPI
int CPXPUBLIC
   CPXLcopyorder_multicast (CPXENVGROUPptr group, CPXINT cnt,
                            CPXINT const *indices,
                            CPXINT const *priority,
                            int const *direction);


CPXLIBAPI
int CPXPUBLIC
   CPXLcopypartialbase_multicast (CPXENVGROUPptr group, CPXINT ccnt,
                                  CPXINT const *cindices,
                                  int const *cstat, CPXINT rcnt,
                                  CPXINT const *rindices,
                                  int const *rstat);


CPXLIBAPI
int CPXPUBLIC
   CPXLcopyprotected_multicast (CPXENVGROUPptr group, CPXINT cnt,
                                CPXINT const *indices);


CPXLIBAPI
int CPXPUBLIC
   CPXLcreateenvgroup (CPXENVGROUPptr *group_p, int nenvs,
                       CPXENVptr const *envs);


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
   CPXLdelmipstarts_multicast (CPXENVGROUPptr group, int begin,
                               int end);


CPXLIBAPI
int CPXPUBLIC
   CPXLdelnames_multicast (CPXENVGROUPptr group);


CPXLIBAPI
int CPXPUBLIC
   CPXLdelqconstrs_multicast (CPXENVGROUPptr group, CPXINT begin,
                              CPXINT end);


CPXLIBAPI
int CPXPUBLIC
   CPXLdelrows_multicast (CPXENVGROUPptr group, CPXINT begin,
                          CPXINT end);


CPXLIBAPI
int CPXPUBLIC
   CPXLdelsolnpoolfilters_multicast (CPXENVGROUPptr group, int begin,
                                     int end);


CPXLIBAPI
int CPXPUBLIC
   CPXLdelsolnpoolsolns_multicast (CPXENVGROUPptr group, int begin,
                                   int end);


CPXLIBAPI
int CPXPUBLIC
   CPXLdelsos_multicast (CPXENVGROUPptr group, CPXINT begin,
                         CPXINT end);


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
   CPXLembwrite_async (CPXCENVptr env, CPXLPptr lp,
                       char const *filename_str, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLembwrite_join (CPXASYNCptr *handle_p);


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
void CPXPUBLIC
   CPXLfreeenvgroup (CPXENVGROUPptr *group_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLfreelazyconstraints_multicast (CPXENVGROUPptr group);


CPXLIBAPI
int CPXPUBLIC
   CPXLfreepresolve_multicast (CPXENVGROUPptr group);


CPXLIBAPI
int CPXPUBLIC
   CPXLfreeusercuts_multicast (CPXENVGROUPptr group);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetasynchandlesize (CPXCASYNCptr asynchandle);


CPXLIBAPI
void const * CPXPUBLIC
   CPXLgetasynctab (void);


CPXLIBAPI
CPXENVptr CPXPUBLIC
   CPXLgetenvgroupenv (CPXCENVGROUPptr group, int idx);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetenvgroupsize (CPXCENVGROUPptr group);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetinfohandler (CPXCENVptr env, CPXINFOHANDLER  **infohandler_p,
                       void  **handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetlps (CPXCENVptr env, int capacity, CPXLPptr *lps,
               int *count_p, int *total_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLgetreconnectinfolen (CPXCENVptr env);



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
   CPXLkilldnorms_multicast (CPXENVGROUPptr group);


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
   CPXLNETchgarcnodes_multicast (CPXENVGROUPptr group, CPXINT cnt,
                                 CPXINT const *indices,
                                 CPXINT const *fromnode,
                                 CPXINT const *tonode);


CPXLIBAPI
int CPXPUBLIC
   CPXLNETchgbds_multicast (CPXENVGROUPptr group, CPXINT cnt,
                            CPXINT const *indices, char const *lu,
                            double const *bd);


CPXLIBAPI
int CPXPUBLIC
   CPXLNETchgobj_multicast (CPXENVGROUPptr group, CPXINT cnt,
                            CPXINT const *indices, double const *obj);


CPXLIBAPI
int CPXPUBLIC
   CPXLNETchgobjsen_multicast (CPXENVGROUPptr group, int maxormin);


CPXLIBAPI
int CPXPUBLIC
   CPXLNETchgsupply_multicast (CPXENVGROUPptr group, CPXINT cnt,
                               CPXINT const *indices,
                               double const *supply);


CPXLIBAPI
int CPXPUBLIC
   CPXLNETdelarcs_multicast (CPXENVGROUPptr group, CPXINT begin,
                             CPXINT end);


CPXLIBAPI
int CPXPUBLIC
   CPXLNETdelnodes_multicast (CPXENVGROUPptr group, CPXINT begin,
                              CPXINT end);


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
   CPXLNETreadcopybase_multicast (CPXENVGROUPptr group,
                                  char const *filename_str);


CPXLIBAPI
int CPXPUBLIC
   CPXLNETreadcopyprob_multicast (CPXENVGROUPptr group,
                                  char const *filename_str);


CPXLIBAPI
CPXENVptr CPXPUBLIC
   CPXLopenCPLEXreconnect (int *status_p, void const *buffer);


CPXLIBAPI
CPXENVptr CPXPUBLIC
   CPXLopenCPLEXremote (char const *transport, int argc,
                        char const *const *argv, int *status_p);


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
   CPXLreadcopyannotations_multicast (CPXENVGROUPptr group,
                                      char const *filename);


CPXLIBAPI
int CPXPUBLIC
   CPXLreadcopybase_multicast (CPXENVGROUPptr group,
                               char const *filename_str);


CPXLIBAPI
int CPXPUBLIC
   CPXLreadcopymipstarts_multicast (CPXENVGROUPptr group,
                                    char const *filename_str);


CPXLIBAPI
int CPXPUBLIC
   CPXLreadcopyorder_multicast (CPXENVGROUPptr group,
                                char const *filename_str);


CPXLIBAPI
int CPXPUBLIC
   CPXLreadcopyparam_multicast (CPXENVGROUPptr group,
                                char const *filename_str);


CPXLIBAPI
int CPXPUBLIC
   CPXLreadcopyprob_multicast (CPXENVGROUPptr group,
                               char const *filename_str,
                               char const *filetype_str);


CPXLIBAPI
int CPXPUBLIC
   CPXLreadcopysol_multicast (CPXENVGROUPptr group,
                              char const *filename_str);


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
   CPXLsetdblannotations_multicast (CPXENVGROUPptr group, CPXINT idx,
                                    int objtype, CPXINT cnt,
                                    CPXINT const *indices,
                                    double const *values);


CPXLIBAPI
int CPXPUBLIC
   CPXLsetdblparam_multicast (CPXENVGROUPptr group, int whichparam,
                              double newvalue);


CPXLIBAPI
int CPXPUBLIC
   CPXLsetdefaults_multicast (CPXENVGROUPptr group);


CPXLIBAPI
int CPXPUBLIC
   CPXLsetinfohandler (CPXENVptr env, CPXINFOHANDLER *infohandler,
                       void *handle);


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
   CPXLsetlongparam_multicast (CPXENVGROUPptr group, int whichparam,
                               CPXLONG newvalue);


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
   CPXLstrongbranch_async (CPXCENVptr env, CPXLPptr lp,
                           CPXINT const *indices, CPXINT cnt,
                           CPXLONG itlim, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXLstrongbranch_join (CPXASYNCptr *handle_p, double *downobj,
                          double *upobj);


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



#endif /* CPX_CPLEX_L_API_DEFINED > 0 */

#ifdef __cplusplus
}
#endif

#ifdef _WIN32
#pragma pack(pop)
#endif

#endif /* !CPX_CPLEX_REMOTEMASTERL_H */
