/* --------------------------------------------------------------------------
 * File: cplexremotemasters.h
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
   CPXSchgbds_multicast (CPXENVGROUPptr group, CPXINT cnt,
                         CPXINT const *indices, char const *lu,
                         double const *bd);


CPXLIBAPI
int CPXPUBLIC
   CPXSchgcoef_multicast (CPXENVGROUPptr group, CPXINT i, CPXINT j,
                          double newvalue);


CPXLIBAPI
int CPXPUBLIC
   CPXSchgcoeflist_multicast (CPXENVGROUPptr group, CPXINT numcoefs,
                              CPXINT const *rowlist,
                              CPXINT const *collist,
                              double const *vallist);


CPXLIBAPI
int CPXPUBLIC
   CPXSchgctype_multicast (CPXENVGROUPptr group, CPXINT cnt,
                           CPXINT const *indices, char const *xctype);


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
   CPXSchgobj_multicast (CPXENVGROUPptr group, CPXINT cnt,
                         CPXINT const *indices, double const *values);


CPXLIBAPI
int CPXPUBLIC
   CPXSchgobjoffset_multicast (CPXENVGROUPptr group, double offset);


CPXLIBAPI
int CPXPUBLIC
   CPXSchgobjsen_multicast (CPXENVGROUPptr group, int maxormin);


CPXLIBAPI
int CPXPUBLIC
   CPXSchgprobtype_multicast (CPXENVGROUPptr group, int type);


CPXLIBAPI
int CPXPUBLIC
   CPXSchgprobtypesolnpool_multicast (CPXENVGROUPptr group, int type,
                                      int soln);


CPXLIBAPI
int CPXPUBLIC
   CPXSchgqpcoef_multicast (CPXENVGROUPptr group, CPXINT i, CPXINT j,
                            double newvalue);


CPXLIBAPI
int CPXPUBLIC
   CPXSchgrhs_multicast (CPXENVGROUPptr group, CPXINT cnt,
                         CPXINT const *indices, double const *values);


CPXLIBAPI
int CPXPUBLIC
   CPXSchgrngval_multicast (CPXENVGROUPptr group, CPXINT cnt,
                            CPXINT const *indices,
                            double const *values);


CPXLIBAPI
int CPXPUBLIC
   CPXSchgsense_multicast (CPXENVGROUPptr group, CPXINT cnt,
                           CPXINT const *indices, char const *sense);


CPXLIBAPI
int CPXPUBLIC
   CPXScleanup_multicast (CPXENVGROUPptr group, double eps);


CPXLIBAPI
int CPXPUBLIC
   CPXScloseCPLEXdisconnect (CPXENVptr *env_p, void *buffer);


CPXLIBAPI
int CPXPUBLIC
   CPXScompletelp_multicast (CPXENVGROUPptr group);


CPXLIBAPI
int CPXPUBLIC
   CPXScopydnorms_multicast (CPXENVGROUPptr group, double const *norm,
                             CPXINT const *head, CPXINT len);


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
   CPXScopynettolp_multicast (CPXENVGROUPptr group);


CPXLIBAPI
int CPXPUBLIC
   CPXScopyorder_multicast (CPXENVGROUPptr group, CPXINT cnt,
                            CPXINT const *indices,
                            CPXINT const *priority,
                            int const *direction);


CPXLIBAPI
int CPXPUBLIC
   CPXScopypartialbase_multicast (CPXENVGROUPptr group, CPXINT ccnt,
                                  CPXINT const *cindices,
                                  int const *cstat, CPXINT rcnt,
                                  CPXINT const *rindices,
                                  int const *rstat);


CPXLIBAPI
int CPXPUBLIC
   CPXScopyprotected_multicast (CPXENVGROUPptr group, CPXINT cnt,
                                CPXINT const *indices);


CPXLIBAPI
int CPXPUBLIC
   CPXScreateenvgroup (CPXENVGROUPptr *group_p, int nenvs,
                       CPXENVptr const *envs);


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
   CPXSdelmipstarts_multicast (CPXENVGROUPptr group, int begin,
                               int end);


CPXLIBAPI
int CPXPUBLIC
   CPXSdelnames_multicast (CPXENVGROUPptr group);


CPXLIBAPI
int CPXPUBLIC
   CPXSdelqconstrs_multicast (CPXENVGROUPptr group, CPXINT begin,
                              CPXINT end);


CPXLIBAPI
int CPXPUBLIC
   CPXSdelrows_multicast (CPXENVGROUPptr group, CPXINT begin,
                          CPXINT end);


CPXLIBAPI
int CPXPUBLIC
   CPXSdelsolnpoolfilters_multicast (CPXENVGROUPptr group, int begin,
                                     int end);


CPXLIBAPI
int CPXPUBLIC
   CPXSdelsolnpoolsolns_multicast (CPXENVGROUPptr group, int begin,
                                   int end);


CPXLIBAPI
int CPXPUBLIC
   CPXSdelsos_multicast (CPXENVGROUPptr group, CPXINT begin,
                         CPXINT end);


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
   CPXSembwrite_async (CPXCENVptr env, CPXLPptr lp,
                       char const *filename_str, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSembwrite_join (CPXASYNCptr *handle_p);


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
void CPXPUBLIC
   CPXSfreeenvgroup (CPXENVGROUPptr *group_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSfreelazyconstraints_multicast (CPXENVGROUPptr group);


CPXLIBAPI
int CPXPUBLIC
   CPXSfreepresolve_multicast (CPXENVGROUPptr group);


CPXLIBAPI
int CPXPUBLIC
   CPXSfreeusercuts_multicast (CPXENVGROUPptr group);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetasynchandlesize (CPXCASYNCptr asynchandle);


CPXLIBAPI
void const * CPXPUBLIC
   CPXSgetasynctab (void);


CPXLIBAPI
CPXENVptr CPXPUBLIC
   CPXSgetenvgroupenv (CPXCENVGROUPptr group, int idx);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetenvgroupsize (CPXCENVGROUPptr group);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetinfohandler (CPXCENVptr env, CPXINFOHANDLER  **infohandler_p,
                       void  **handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetlps (CPXCENVptr env, int capacity, CPXLPptr *lps,
               int *count_p, int *total_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetreconnectinfolen (CPXCENVptr env);



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
   CPXSkilldnorms_multicast (CPXENVGROUPptr group);


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
   CPXSNETchgarcnodes_multicast (CPXENVGROUPptr group, CPXINT cnt,
                                 CPXINT const *indices,
                                 CPXINT const *fromnode,
                                 CPXINT const *tonode);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETchgbds_multicast (CPXENVGROUPptr group, CPXINT cnt,
                            CPXINT const *indices, char const *lu,
                            double const *bd);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETchgobj_multicast (CPXENVGROUPptr group, CPXINT cnt,
                            CPXINT const *indices, double const *obj);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETchgobjsen_multicast (CPXENVGROUPptr group, int maxormin);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETchgsupply_multicast (CPXENVGROUPptr group, CPXINT cnt,
                               CPXINT const *indices,
                               double const *supply);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETdelarcs_multicast (CPXENVGROUPptr group, CPXINT begin,
                             CPXINT end);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETdelnodes_multicast (CPXENVGROUPptr group, CPXINT begin,
                              CPXINT end);


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
   CPXSNETreadcopybase_multicast (CPXENVGROUPptr group,
                                  char const *filename_str);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETreadcopyprob_multicast (CPXENVGROUPptr group,
                                  char const *filename_str);


CPXLIBAPI
CPXENVptr CPXPUBLIC
   CPXSopenCPLEXreconnect (int *status_p, void const *buffer);


CPXLIBAPI
CPXENVptr CPXPUBLIC
   CPXSopenCPLEXremote (char const *transport, int argc,
                        char const *const *argv, int *status_p);


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
   CPXSreadcopyannotations_multicast (CPXENVGROUPptr group,
                                      char const *filename);


CPXLIBAPI
int CPXPUBLIC
   CPXSreadcopybase_multicast (CPXENVGROUPptr group,
                               char const *filename_str);


CPXLIBAPI
int CPXPUBLIC
   CPXSreadcopymipstarts_multicast (CPXENVGROUPptr group,
                                    char const *filename_str);


CPXLIBAPI
int CPXPUBLIC
   CPXSreadcopyorder_multicast (CPXENVGROUPptr group,
                                char const *filename_str);


CPXLIBAPI
int CPXPUBLIC
   CPXSreadcopyparam_multicast (CPXENVGROUPptr group,
                                char const *filename_str);


CPXLIBAPI
int CPXPUBLIC
   CPXSreadcopyprob_multicast (CPXENVGROUPptr group,
                               char const *filename_str,
                               char const *filetype_str);


CPXLIBAPI
int CPXPUBLIC
   CPXSreadcopysol_multicast (CPXENVGROUPptr group,
                              char const *filename_str);


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
   CPXSsetdblannotations_multicast (CPXENVGROUPptr group, CPXINT idx,
                                    int objtype, CPXINT cnt,
                                    CPXINT const *indices,
                                    double const *values);


CPXLIBAPI
int CPXPUBLIC
   CPXSsetdblparam_multicast (CPXENVGROUPptr group, int whichparam,
                              double newvalue);


CPXLIBAPI
int CPXPUBLIC
   CPXSsetdefaults_multicast (CPXENVGROUPptr group);


CPXLIBAPI
int CPXPUBLIC
   CPXSsetinfohandler (CPXENVptr env, CPXINFOHANDLER *infohandler,
                       void *handle);


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
   CPXSsetlongparam_multicast (CPXENVGROUPptr group, int whichparam,
                               CPXLONG newvalue);


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
   CPXSstrongbranch_async (CPXCENVptr env, CPXLPptr lp,
                           CPXINT const *indices, CPXINT cnt,
                           CPXLONG itlim, CPXASYNCptr *handle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSstrongbranch_join (CPXASYNCptr *handle_p, double *downobj,
                          double *upobj);


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



#endif /* CPX_CPLEX_S_API_DEFINED > 0 */

#ifdef __cplusplus
}
#endif

#ifdef _WIN32
#pragma pack(pop)
#endif

#endif /* !CPX_CPLEX_REMOTEMASTERS_H */
