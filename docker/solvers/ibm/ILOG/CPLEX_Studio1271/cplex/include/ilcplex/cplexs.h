/* --------------------------------------------------------------------------
 * File: cplexs.h
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

#ifndef CPX_CPLEXS_H
#   define CPX_CPLEXS_H 1
#include "cpxconst.h"

#ifdef _WIN32
#pragma pack(push, 8)
#endif

#ifdef __cplusplus
extern "C" {
#endif


#define CPX_CPLEX_S_API_DEFINED 1

/* Argument lists for callbacks */
#define CPXS_CALLBACK_ARGS CPXCENVptr env, void *cbdata, int wherefrom, \
      void *cbhandle
#define CPXS_CALLBACK_PROF_ARGS CPXCENVptr env, int wherefrom, void *cbhandle
#define CPXS_CALLBACK_BRANCH_ARGS  CPXCENVptr xenv, void *cbdata,       \
      int wherefrom, void *cbhandle, int brtype, CPXINT brset,          \
      int nodecnt, CPXINT bdcnt,                                        \
      const CPXINT *nodebeg, const CPXINT *xindex, const char *lu,      \
      const double *bd,  const double *nodeest, int *useraction_p
#define CPXS_CALLBACK_NODE_ARGS  CPXCENVptr xenv, void *cbdata,         \
      int wherefrom, void *cbhandle, CPXLONG *nodeindex, int *useraction
#define CPXS_CALLBACK_HEURISTIC_ARGS  CPXCENVptr xenv, void *cbdata,    \
      int wherefrom, void *cbhandle, double *objval_p, double *x,       \
      int *checkfeas_p, int *useraction_p
#define CPXS_CALLBACK_SOLVE_ARGS  CPXCENVptr xenv, void *cbdata,        \
      int wherefrom, void *cbhandle, int *useraction
#define CPXS_CALLBACK_CUT_ARGS  CPXCENVptr xenv, void *cbdata,  \
      int wherefrom, void *cbhandle, int *useraction_p
#define CPXS_CALLBACK_INCUMBENT_ARGS  CPXCENVptr xenv, void *cbdata,    \
      int wherefrom, void *cbhandle, double objval, double *x,          \
      int *isfeas_p, int *useraction_p
#define CPXS_CALLBACK_DELETENODE_ARGS  CPXCENVptr xenv,         \
   int wherefrom, void *cbhandle, CPXLONG seqnum, void *handle

typedef int (CPXPUBLIC CPXS_CALLBACK) (CPXS_CALLBACK_ARGS);
typedef int (CPXPUBLIC CPXS_CALLBACK_PROF)(CPXS_CALLBACK_PROF_ARGS);
typedef int (CPXPUBLIC CPXS_CALLBACK_BRANCH) (CPXS_CALLBACK_BRANCH_ARGS);
typedef int (CPXPUBLIC CPXS_CALLBACK_NODE) (CPXS_CALLBACK_NODE_ARGS);
typedef int (CPXPUBLIC CPXS_CALLBACK_HEURISTIC) (CPXS_CALLBACK_HEURISTIC_ARGS);
typedef int (CPXPUBLIC CPXS_CALLBACK_SOLVE) (CPXS_CALLBACK_SOLVE_ARGS);
typedef int (CPXPUBLIC CPXS_CALLBACK_CUT) (CPXS_CALLBACK_CUT_ARGS);
typedef int (CPXPUBLIC CPXS_CALLBACK_INCUMBENT) (CPXS_CALLBACK_INCUMBENT_ARGS);
typedef void (CPXPUBLIC CPXS_CALLBACK_DELETENODE) (CPXS_CALLBACK_DELETENODE_ARGS);






CPXLIBAPI
int CPXPUBLIC
   CPXSaddcols (CPXCENVptr env, CPXLPptr lp, CPXINT ccnt, CPXINT nzcnt,
                double const *obj, CPXINT const *cmatbeg,
                CPXINT const *cmatind, double const *cmatval,
                double const *lb, double const *ub,
                char const *const *colname);


CPXLIBAPI
int CPXPUBLIC
   CPXSaddfpdest (CPXCENVptr env, CPXCHANNELptr channel,
                  CPXFILEptr fileptr);


CPXLIBAPI
int CPXPUBLIC
   CPXSaddfuncdest (CPXCENVptr env, CPXCHANNELptr channel,
                    void *handle,
                    void (CPXPUBLIC *msgfunction)(void *, char const *));


CPXLIBAPI
int CPXPUBLIC
   CPXSaddpwl (CPXCENVptr env, CPXLPptr lp, CPXINT vary, CPXINT varx,
               double preslope, double postslope, CPXINT nbreaks,
               double const *breakx, double const *breaky,
               char const *pwlname);


CPXLIBAPI
int CPXPUBLIC
   CPXSaddrows (CPXCENVptr env, CPXLPptr lp, CPXINT ccnt, CPXINT rcnt,
                CPXINT nzcnt, double const *rhs, char const *sense,
                CPXINT const *rmatbeg, CPXINT const *rmatind,
                double const *rmatval, char const *const *colname,
                char const *const *rowname);


CPXLIBAPI
int CPXPUBLIC
   CPXSbasicpresolve (CPXCENVptr env, CPXLPptr lp, double *redlb,
                      double *redub, int *rstat);


CPXLIBAPI
int CPXPUBLIC
   CPXSbinvacol (CPXCENVptr env, CPXCLPptr lp, CPXINT j, double *x);


CPXLIBAPI
int CPXPUBLIC
   CPXSbinvarow (CPXCENVptr env, CPXCLPptr lp, CPXINT i, double *z);


CPXLIBAPI
int CPXPUBLIC
   CPXSbinvcol (CPXCENVptr env, CPXCLPptr lp, CPXINT j, double *x);


CPXLIBAPI
int CPXPUBLIC
   CPXSbinvrow (CPXCENVptr env, CPXCLPptr lp, CPXINT i, double *y);


CPXLIBAPI
int CPXPUBLIC
   CPXSboundsa (CPXCENVptr env, CPXCLPptr lp, CPXINT begin, CPXINT end,
                double *lblower, double *lbupper, double *ublower,
                double *ubupper);


CPXLIBAPI
int CPXPUBLIC
   CPXSbtran (CPXCENVptr env, CPXCLPptr lp, double *y);


CPXLIBAPI
int CPXPUBLIC
   CPXScheckdfeas (CPXCENVptr env, CPXLPptr lp, CPXINT *infeas_p);


CPXLIBAPI
int CPXPUBLIC
   CPXScheckpfeas (CPXCENVptr env, CPXLPptr lp, CPXINT *infeas_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSchecksoln (CPXCENVptr env, CPXLPptr lp, int *lpstatus_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSchgbds (CPXCENVptr env, CPXLPptr lp, CPXINT cnt,
               CPXINT const *indices, char const *lu, double const *bd);


CPXLIBAPI
int CPXPUBLIC
   CPXSchgcoef (CPXCENVptr env, CPXLPptr lp, CPXINT i, CPXINT j,
                double newvalue);


CPXLIBAPI
int CPXPUBLIC
   CPXSchgcoeflist (CPXCENVptr env, CPXLPptr lp, CPXINT numcoefs,
                    CPXINT const *rowlist, CPXINT const *collist,
                    double const *vallist);


CPXLIBAPI
int CPXPUBLIC
   CPXSchgcolname (CPXCENVptr env, CPXLPptr lp, CPXINT cnt,
                   CPXINT const *indices, char const *const *newname);


CPXLIBAPI
int CPXPUBLIC
   CPXSchgname (CPXCENVptr env, CPXLPptr lp, int key, CPXINT ij,
                char const *newname_str);


CPXLIBAPI
int CPXPUBLIC
   CPXSchgobj (CPXCENVptr env, CPXLPptr lp, CPXINT cnt,
               CPXINT const *indices, double const *values);


CPXLIBAPI
int CPXPUBLIC
   CPXSchgobjoffset (CPXCENVptr env, CPXLPptr lp, double offset);


CPXLIBAPI
int CPXPUBLIC
   CPXSchgobjsen (CPXCENVptr env, CPXLPptr lp, int maxormin);


CPXLIBAPI
int CPXPUBLIC
   CPXSchgprobname (CPXCENVptr env, CPXLPptr lp, char const *probname);


CPXLIBAPI
int CPXPUBLIC
   CPXSchgprobtype (CPXCENVptr env, CPXLPptr lp, int type);


CPXLIBAPI
int CPXPUBLIC
   CPXSchgprobtypesolnpool (CPXCENVptr env, CPXLPptr lp, int type,
                            int soln);


CPXLIBAPI
int CPXPUBLIC
   CPXSchgrhs (CPXCENVptr env, CPXLPptr lp, CPXINT cnt,
               CPXINT const *indices, double const *values);


CPXLIBAPI
int CPXPUBLIC
   CPXSchgrngval (CPXCENVptr env, CPXLPptr lp, CPXINT cnt,
                  CPXINT const *indices, double const *values);


CPXLIBAPI
int CPXPUBLIC
   CPXSchgrowname (CPXCENVptr env, CPXLPptr lp, CPXINT cnt,
                   CPXINT const *indices, char const *const *newname);


CPXLIBAPI
int CPXPUBLIC
   CPXSchgsense (CPXCENVptr env, CPXLPptr lp, CPXINT cnt,
                 CPXINT const *indices, char const *sense);


CPXLIBAPI
int CPXPUBLIC
   CPXScleanup (CPXCENVptr env, CPXLPptr lp, double eps);


CPXLIBAPI
CPXLPptr CPXPUBLIC
   CPXScloneprob (CPXCENVptr env, CPXCLPptr lp, int *status_p);


CPXLIBAPI
int CPXPUBLIC
   CPXScloseCPLEX (CPXENVptr *env_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSclpwrite (CPXCENVptr env, CPXCLPptr lp,
                 char const *filename_str);


CPXLIBAPI
int CPXPUBLIC
   CPXScompletelp (CPXCENVptr env, CPXLPptr lp);


CPXLIBAPI
int CPXPUBLIC
   CPXScopybase (CPXCENVptr env, CPXLPptr lp, int const *cstat,
                 int const *rstat);


CPXLIBAPI
int CPXPUBLIC
   CPXScopybasednorms (CPXCENVptr env, CPXLPptr lp, int const *cstat,
                       int const *rstat, double const *dnorm);


CPXLIBAPI
int CPXPUBLIC
   CPXScopydnorms (CPXCENVptr env, CPXLPptr lp, double const *norm,
                   CPXINT const *head, CPXINT len);


CPXLIBAPI
int CPXPUBLIC
   CPXScopylp (CPXCENVptr env, CPXLPptr lp, CPXINT numcols,
               CPXINT numrows, int objsense, double const *objective,
               double const *rhs, char const *sense,
               CPXINT const *matbeg, CPXINT const *matcnt,
               CPXINT const *matind, double const *matval,
               double const *lb, double const *ub,
               double const *rngval);


CPXLIBAPI
int CPXPUBLIC
   CPXScopylpwnames (CPXCENVptr env, CPXLPptr lp, CPXINT numcols,
                     CPXINT numrows, int objsense,
                     double const *objective, double const *rhs,
                     char const *sense, CPXINT const *matbeg,
                     CPXINT const *matcnt, CPXINT const *matind,
                     double const *matval, double const *lb,
                     double const *ub, double const *rngval,
                     char const *const *colname,
                     char const *const *rowname);


CPXLIBAPI
int CPXPUBLIC
   CPXScopynettolp (CPXCENVptr env, CPXLPptr lp, CPXCNETptr net);


CPXLIBAPI
int CPXPUBLIC
   CPXScopyobjname (CPXCENVptr env, CPXLPptr lp,
                    char const *objname_str);


CPXLIBAPI
int CPXPUBLIC
   CPXScopypartialbase (CPXCENVptr env, CPXLPptr lp, CPXINT ccnt,
                        CPXINT const *cindices, int const *cstat,
                        CPXINT rcnt, CPXINT const *rindices,
                        int const *rstat);


CPXLIBAPI
int CPXPUBLIC
   CPXScopypnorms (CPXCENVptr env, CPXLPptr lp, double const *cnorm,
                   double const *rnorm, CPXINT len);


CPXLIBAPI
int CPXPUBLIC
   CPXScopyprotected (CPXCENVptr env, CPXLPptr lp, CPXINT cnt,
                      CPXINT const *indices);


CPXLIBAPI
int CPXPUBLIC
   CPXScopystart (CPXCENVptr env, CPXLPptr lp, int const *cstat,
                  int const *rstat, double const *cprim,
                  double const *rprim, double const *cdual,
                  double const *rdual);


CPXLIBAPI
CPXLPptr CPXPUBLIC
   CPXScreateprob (CPXCENVptr env, int *status_p,
                   char const *probname_str);


CPXLIBAPI
int CPXPUBLIC
   CPXScrushform (CPXCENVptr env, CPXCLPptr lp, CPXINT len,
                  CPXINT const *ind, double const *val, CPXINT *plen_p,
                  double *poffset_p, CPXINT *pind, double *pval);


CPXLIBAPI
int CPXPUBLIC
   CPXScrushpi (CPXCENVptr env, CPXCLPptr lp, double const *pi,
                double *prepi);


CPXLIBAPI
int CPXPUBLIC
   CPXScrushx (CPXCENVptr env, CPXCLPptr lp, double const *x,
               double *prex);


CPXLIBAPI
int CPXPUBLIC
   CPXSdelcols (CPXCENVptr env, CPXLPptr lp, CPXINT begin, CPXINT end);


CPXLIBAPI
int CPXPUBLIC
   CPXSdeldblannotation (CPXCENVptr env, CPXLPptr lp, CPXINT idx);


CPXLIBAPI
int CPXPUBLIC
   CPXSdeldblannotations (CPXCENVptr env, CPXLPptr lp, CPXINT begin,
                          CPXINT end);


CPXLIBAPI
int CPXPUBLIC
   CPXSdelfpdest (CPXCENVptr env, CPXCHANNELptr channel,
                  CPXFILEptr fileptr);


CPXLIBAPI
int CPXPUBLIC
   CPXSdelfuncdest (CPXCENVptr env, CPXCHANNELptr channel,
                    void *handle,
                    void (CPXPUBLIC *msgfunction)(void *, char const *));


CPXLIBAPI
int CPXPUBLIC
   CPXSdellongannotation (CPXCENVptr env, CPXLPptr lp, CPXINT idx);


CPXLIBAPI
int CPXPUBLIC
   CPXSdellongannotations (CPXCENVptr env, CPXLPptr lp, CPXINT begin,
                           CPXINT end);


CPXLIBAPI
int CPXPUBLIC
   CPXSdelnames (CPXCENVptr env, CPXLPptr lp);


CPXLIBAPI
int CPXPUBLIC
   CPXSdelpwl (CPXCENVptr env, CPXLPptr lp, CPXINT begin, CPXINT end);


CPXLIBAPI
int CPXPUBLIC
   CPXSdelrows (CPXCENVptr env, CPXLPptr lp, CPXINT begin, CPXINT end);


CPXLIBAPI
int CPXPUBLIC
   CPXSdelsetcols (CPXCENVptr env, CPXLPptr lp, CPXINT *delstat);


CPXLIBAPI
int CPXPUBLIC
   CPXSdelsetpwl (CPXCENVptr env, CPXLPptr lp, CPXINT *delstat);


CPXLIBAPI
int CPXPUBLIC
   CPXSdelsetrows (CPXCENVptr env, CPXLPptr lp, CPXINT *delstat);


CPXLIBAPI
int CPXPUBLIC
   CPXSdeserializercreate (CPXDESERIALIZERptr *deser_p, CPXLONG size,
                           void const *buffer);


CPXLIBAPI
void CPXPUBLIC
   CPXSdeserializerdestroy (CPXDESERIALIZERptr deser);


CPXLIBAPI
CPXLONG CPXPUBLIC
   CPXSdeserializerleft (CPXCDESERIALIZERptr deser);


CPXLIBAPI
int CPXPUBLIC
   CPXSdisconnectchannel (CPXCENVptr env, CPXCHANNELptr channel);


CPXLIBAPI
int CPXPUBLIC
   CPXSdjfrompi (CPXCENVptr env, CPXCLPptr lp, double const *pi,
                 double *dj);


CPXLIBAPI
int CPXPUBLIC
   CPXSdperwrite (CPXCENVptr env, CPXLPptr lp,
                  char const *filename_str, double epsilon);


CPXLIBAPI
int CPXPUBLIC
   CPXSdratio (CPXCENVptr env, CPXLPptr lp, CPXINT *indices,
               CPXINT cnt, double *downratio, double *upratio,
               CPXINT *downenter, CPXINT *upenter, int *downstatus,
               int *upstatus);


CPXLIBAPI
int CPXPUBLIC
   CPXSdualfarkas (CPXCENVptr env, CPXCLPptr lp, double *y,
                   double *proof_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSdualopt (CPXCENVptr env, CPXLPptr lp);


CPXLIBAPI
int CPXPUBLIC
   CPXSdualwrite (CPXCENVptr env, CPXCLPptr lp,
                  char const *filename_str, double *objshift_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSembwrite (CPXCENVptr env, CPXLPptr lp, char const *filename_str);


CPXLIBAPI
int CPXPUBLIC
   CPXSfclose (CPXFILEptr stream);


CPXLIBAPI
int CPXPUBLIC
   CPXSfeasopt (CPXCENVptr env, CPXLPptr lp, double const *rhs,
                double const *rng, double const *lb, double const *ub);


CPXLIBAPI
int CPXPUBLIC
   CPXSfeasoptext (CPXCENVptr env, CPXLPptr lp, CPXINT grpcnt,
                   CPXINT concnt, double const *grppref,
                   CPXINT const *grpbeg, CPXINT const *grpind,
                   char const *grptype);


CPXLIBAPI
void CPXPUBLIC
   CPXSfinalize (void);


CPXLIBAPI
int CPXPUBLIC
   CPXSflushchannel (CPXCENVptr env, CPXCHANNELptr channel);


CPXLIBAPI
int CPXPUBLIC
   CPXSflushstdchannels (CPXCENVptr env);


CPXLIBAPI
CPXFILEptr CPXPUBLIC
   CPXSfopen (char const *filename_str, char const *type_str);


CPXLIBAPI
int CPXPUBLIC
   CPXSfputs (char const *s_str, CPXFILEptr stream);


CPXLIBAPI
int CPXPUBLIC
   CPXSfreeparenv (CPXENVptr env, CPXENVptr *child_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSfreepresolve (CPXCENVptr env, CPXLPptr lp);


CPXLIBAPI
int CPXPUBLIC
   CPXSfreeprob (CPXCENVptr env, CPXLPptr *lp_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSftran (CPXCENVptr env, CPXCLPptr lp, double *x);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetax (CPXCENVptr env, CPXCLPptr lp, double *x, CPXINT begin,
              CPXINT end);


CPXLIBAPI
CPXLONG CPXPUBLIC
   CPXSgetbaritcnt (CPXCENVptr env, CPXCLPptr lp);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetbase (CPXCENVptr env, CPXCLPptr lp, int *cstat, int *rstat);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetbasednorms (CPXCENVptr env, CPXCLPptr lp, int *cstat,
                      int *rstat, double *dnorm);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetbhead (CPXCENVptr env, CPXCLPptr lp, CPXINT *head, double *x);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetcallbackinfo (CPXCENVptr env, void *cbdata, int wherefrom,
                        int whichinfo, void *result_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetchannels (CPXCENVptr env, CPXCHANNELptr *cpxresults_p,
                    CPXCHANNELptr *cpxwarning_p,
                    CPXCHANNELptr *cpxerror_p, CPXCHANNELptr *cpxlog_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetchgparam (CPXCENVptr env, int *cnt_p, int *paramnum,
                    int pspace, int *surplus_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetcoef (CPXCENVptr env, CPXCLPptr lp, CPXINT i, CPXINT j,
                double *coef_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetcolindex (CPXCENVptr env, CPXCLPptr lp,
                    char const *lname_str, CPXINT *index_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetcolinfeas (CPXCENVptr env, CPXCLPptr lp, double const *x,
                     double *infeasout, CPXINT begin, CPXINT end);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetcolname (CPXCENVptr env, CPXCLPptr lp, char  **name,
                   char *namestore, CPXSIZE storespace,
                   CPXSIZE *surplus_p, CPXINT begin, CPXINT end);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetcols (CPXCENVptr env, CPXCLPptr lp, CPXINT *nzcnt_p,
                CPXINT *cmatbeg, CPXINT *cmatind, double *cmatval,
                CPXINT cmatspace, CPXINT *surplus_p, CPXINT begin,
                CPXINT end);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetconflict (CPXCENVptr env, CPXCLPptr lp, int *confstat_p,
                    CPXINT *rowind, int *rowbdstat,
                    CPXINT *confnumrows_p, CPXINT *colind,
                    int *colbdstat, CPXINT *confnumcols_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetconflictext (CPXCENVptr env, CPXCLPptr lp, int *grpstat,
                       CPXINT beg, CPXINT end);


CPXLIBAPI
CPXLONG CPXPUBLIC
   CPXSgetcrossdexchcnt (CPXCENVptr env, CPXCLPptr lp);


CPXLIBAPI
CPXLONG CPXPUBLIC
   CPXSgetcrossdpushcnt (CPXCENVptr env, CPXCLPptr lp);


CPXLIBAPI
CPXLONG CPXPUBLIC
   CPXSgetcrosspexchcnt (CPXCENVptr env, CPXCLPptr lp);


CPXLIBAPI
CPXLONG CPXPUBLIC
   CPXSgetcrossppushcnt (CPXCENVptr env, CPXCLPptr lp);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetdblannotationdefval (CPXCENVptr env, CPXCLPptr lp,
                               CPXINT idx, double *defval_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetdblannotationindex (CPXCENVptr env, CPXCLPptr lp,
                              char const *annotationname_str,
                              CPXINT *index_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetdblannotationname (CPXCENVptr env, CPXCLPptr lp, CPXINT idx,
                             char *buf_str, CPXSIZE bufspace,
                             CPXSIZE *surplus_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetdblannotations (CPXCENVptr env, CPXCLPptr lp, CPXINT idx,
                          int objtype, double *annotation,
                          CPXINT begin, CPXINT end);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetdblparam (CPXCENVptr env, int whichparam, double *value_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetdblquality (CPXCENVptr env, CPXCLPptr lp, double *quality_p,
                      int what);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetdettime (CPXCENVptr env, double *dettimestamp_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetdj (CPXCENVptr env, CPXCLPptr lp, double *dj, CPXINT begin,
              CPXINT end);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetdnorms (CPXCENVptr env, CPXCLPptr lp, double *norm,
                  CPXINT *head, CPXINT *len_p);


CPXLIBAPI
CPXINT CPXPUBLIC
   CPXSgetdsbcnt (CPXCENVptr env, CPXCLPptr lp);


CPXLIBAPI
CPXCCHARptr CPXPUBLIC
   CPXSgeterrorstring (CPXCENVptr env, int errcode, char *buffer_str);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetgrad (CPXCENVptr env, CPXCLPptr lp, CPXINT j, CPXINT *head,
                double *y);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetijdiv (CPXCENVptr env, CPXCLPptr lp, CPXINT *idiv_p,
                 CPXINT *jdiv_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetijrow (CPXCENVptr env, CPXCLPptr lp, CPXINT i, CPXINT j,
                 CPXINT *row_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetintparam (CPXCENVptr env, int whichparam, CPXINT *value_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetintquality (CPXCENVptr env, CPXCLPptr lp, CPXINT *quality_p,
                      int what);


CPXLIBAPI
CPXLONG CPXPUBLIC
   CPXSgetitcnt (CPXCENVptr env, CPXCLPptr lp);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetlb (CPXCENVptr env, CPXCLPptr lp, double *lb, CPXINT begin,
              CPXINT end);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetlogfile (CPXCENVptr env, CPXFILEptr *logfile_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetlongannotationdefval (CPXCENVptr env, CPXCLPptr lp,
                                CPXINT idx, CPXLONG *defval_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetlongannotationindex (CPXCENVptr env, CPXCLPptr lp,
                               char const *annotationname_str,
                               CPXINT *index_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetlongannotationname (CPXCENVptr env, CPXCLPptr lp, CPXINT idx,
                              char *buf_str, CPXSIZE bufspace,
                              CPXSIZE *surplus_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetlongannotations (CPXCENVptr env, CPXCLPptr lp, CPXINT idx,
                           int objtype, CPXLONG *annotation,
                           CPXINT begin, CPXINT end);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetlongparam (CPXCENVptr env, int whichparam, CPXLONG *value_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetlpcallbackfunc (CPXCENVptr env, CPXS_CALLBACK **callback_p,
                          void  **cbhandle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetmethod (CPXCENVptr env, CPXCLPptr lp);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetnetcallbackfunc (CPXCENVptr env, CPXS_CALLBACK **callback_p,
                           void  **cbhandle_p);


CPXLIBAPI
CPXINT CPXPUBLIC
   CPXSgetnumcols (CPXCENVptr env, CPXCLPptr lp);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetnumcores (CPXCENVptr env, int *numcores_p);


CPXLIBAPI
CPXINT CPXPUBLIC
   CPXSgetnumdblannotations (CPXCENVptr env, CPXCLPptr lp);


CPXLIBAPI
CPXINT CPXPUBLIC
   CPXSgetnumlongannotations (CPXCENVptr env, CPXCLPptr lp);


CPXLIBAPI
CPXINT CPXPUBLIC
   CPXSgetnumnz (CPXCENVptr env, CPXCLPptr lp);


CPXLIBAPI
CPXINT CPXPUBLIC
   CPXSgetnumpwl (CPXCENVptr env, CPXCLPptr lp);


CPXLIBAPI
CPXINT CPXPUBLIC
   CPXSgetnumrows (CPXCENVptr env, CPXCLPptr lp);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetobj (CPXCENVptr env, CPXCLPptr lp, double *obj, CPXINT begin,
               CPXINT end);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetobjname (CPXCENVptr env, CPXCLPptr lp, char *buf_str,
                   CPXSIZE bufspace, CPXSIZE *surplus_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetobjoffset (CPXCENVptr env, CPXCLPptr lp, double *objoffset_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetobjsen (CPXCENVptr env, CPXCLPptr lp);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetobjval (CPXCENVptr env, CPXCLPptr lp, double *objval_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetparamname (CPXCENVptr env, int whichparam, char *name_str);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetparamnum (CPXCENVptr env, char const *name_str,
                    int *whichparam_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetparamtype (CPXCENVptr env, int whichparam, int *paramtype);


CPXLIBAPI
CPXLONG CPXPUBLIC
   CPXSgetphase1cnt (CPXCENVptr env, CPXCLPptr lp);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetpi (CPXCENVptr env, CPXCLPptr lp, double *pi, CPXINT begin,
              CPXINT end);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetpnorms (CPXCENVptr env, CPXCLPptr lp, double *cnorm,
                  double *rnorm, CPXINT *len_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetprestat (CPXCENVptr env, CPXCLPptr lp, int *prestat_p,
                   CPXINT *pcstat, CPXINT *prstat, CPXINT *ocstat,
                   CPXINT *orstat);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetprobname (CPXCENVptr env, CPXCLPptr lp, char *buf_str,
                    CPXSIZE bufspace, CPXSIZE *surplus_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetprobtype (CPXCENVptr env, CPXCLPptr lp);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetprotected (CPXCENVptr env, CPXCLPptr lp, CPXINT *cnt_p,
                     CPXINT *indices, CPXINT pspace, CPXINT *surplus_p);


CPXLIBAPI
CPXINT CPXPUBLIC
   CPXSgetpsbcnt (CPXCENVptr env, CPXCLPptr lp);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetpwl (CPXCENVptr env, CPXCLPptr lp, CPXINT pwlindex,
               CPXINT *vary_p, CPXINT *varx_p, double *preslope_p,
               double *postslope_p, CPXINT *nbreaks_p, double *breakx,
               double *breaky, CPXINT breakspace, CPXINT *surplus_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetpwlindex (CPXCENVptr env, CPXCLPptr lp,
                    char const *lname_str, CPXINT *index_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetpwlname (CPXCENVptr env, CPXCLPptr lp, char *buf_str,
                   CPXSIZE bufspace, CPXSIZE *surplus_p, CPXINT which);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetray (CPXCENVptr env, CPXCLPptr lp, double *z);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetredlp (CPXCENVptr env, CPXCLPptr lp, CPXCLPptr *redlp_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetrhs (CPXCENVptr env, CPXCLPptr lp, double *rhs, CPXINT begin,
               CPXINT end);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetrngval (CPXCENVptr env, CPXCLPptr lp, double *rngval,
                  CPXINT begin, CPXINT end);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetrowindex (CPXCENVptr env, CPXCLPptr lp,
                    char const *lname_str, CPXINT *index_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetrowinfeas (CPXCENVptr env, CPXCLPptr lp, double const *x,
                     double *infeasout, CPXINT begin, CPXINT end);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetrowname (CPXCENVptr env, CPXCLPptr lp, char  **name,
                   char *namestore, CPXSIZE storespace,
                   CPXSIZE *surplus_p, CPXINT begin, CPXINT end);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetrows (CPXCENVptr env, CPXCLPptr lp, CPXINT *nzcnt_p,
                CPXINT *rmatbeg, CPXINT *rmatind, double *rmatval,
                CPXINT rmatspace, CPXINT *surplus_p, CPXINT begin,
                CPXINT end);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetsense (CPXCENVptr env, CPXCLPptr lp, char *sense,
                 CPXINT begin, CPXINT end);


CPXLIBAPI
CPXLONG CPXPUBLIC
   CPXSgetsiftitcnt (CPXCENVptr env, CPXCLPptr lp);


CPXLIBAPI
CPXLONG CPXPUBLIC
   CPXSgetsiftphase1cnt (CPXCENVptr env, CPXCLPptr lp);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetslack (CPXCENVptr env, CPXCLPptr lp, double *slack,
                 CPXINT begin, CPXINT end);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetsolnpooldblquality (CPXCENVptr env, CPXCLPptr lp, int soln,
                              double *quality_p, int what);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetsolnpoolintquality (CPXCENVptr env, CPXCLPptr lp, int soln,
                              CPXINT *quality_p, int what);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetstat (CPXCENVptr env, CPXCLPptr lp);


CPXLIBAPI
CPXCHARptr CPXPUBLIC
   CPXSgetstatstring (CPXCENVptr env, int statind, char *buffer_str);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetstrparam (CPXCENVptr env, int whichparam, char *value_str);


CPXLIBAPI
int CPXPUBLIC
   CPXSgettime (CPXCENVptr env, double *timestamp_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgettuningcallbackfunc (CPXCENVptr env,
                              CPXS_CALLBACK **callback_p,
                              void  **cbhandle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetub (CPXCENVptr env, CPXCLPptr lp, double *ub, CPXINT begin,
              CPXINT end);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetweight (CPXCENVptr env, CPXCLPptr lp, CPXINT rcnt,
                  CPXINT const *rmatbeg, CPXINT const *rmatind,
                  double const *rmatval, double *weight, int dpriind);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetx (CPXCENVptr env, CPXCLPptr lp, double *x, CPXINT begin,
             CPXINT end);


CPXLIBAPI
int CPXPUBLIC
   CPXShybnetopt (CPXCENVptr env, CPXLPptr lp, int method);


CPXLIBAPI
int CPXPUBLIC
   CPXSinfodblparam (CPXCENVptr env, int whichparam,
                     double *defvalue_p, double *minvalue_p,
                     double *maxvalue_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSinfointparam (CPXCENVptr env, int whichparam,
                     CPXINT *defvalue_p, CPXINT *minvalue_p,
                     CPXINT *maxvalue_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSinfolongparam (CPXCENVptr env, int whichparam,
                      CPXLONG *defvalue_p, CPXLONG *minvalue_p,
                      CPXLONG *maxvalue_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSinfostrparam (CPXCENVptr env, int whichparam,
                     char *defvalue_str);


CPXLIBAPI
void CPXPUBLIC
   CPXSinitialize (void);


CPXLIBAPI
int CPXPUBLIC
   CPXSkilldnorms (CPXLPptr lp);


CPXLIBAPI
int CPXPUBLIC
   CPXSkillpnorms (CPXLPptr lp);


CPXLIBAPI
int CPXPUBLIC
   CPXSlpopt (CPXCENVptr env, CPXLPptr lp);


CPXLIBAPI
int CPXPUBLIC
   CPXSlprewrite (CPXCENVptr env, CPXCLPptr lp,
                  char const *filename_str);


CPXLIBAPI
int CPXPUBLIC
   CPXSlpwrite (CPXCENVptr env, CPXCLPptr lp, char const *filename_str);


CPXLIBAPI
int CPXPUBLIC
   CPXSmbasewrite (CPXCENVptr env, CPXCLPptr lp,
                   char const *filename_str);


CPXLIBAPI
int CPXPUBLIC
   CPXSmdleave (CPXCENVptr env, CPXLPptr lp, CPXINT const *indices,
                CPXINT cnt, double *downratio, double *upratio);


CPXLIBAPI
int CPXPUBLIC
   CPXSmpsrewrite (CPXCENVptr env, CPXCLPptr lp,
                   char const *filename_str);


CPXLIBAPI
int CPXPUBLIC
   CPXSmpswrite (CPXCENVptr env, CPXCLPptr lp,
                 char const *filename_str);


CPXLIBAPI
int CPXPUBVARARGS
   CPXSmsg (CPXCHANNELptr channel, char const *format, ...);


CPXLIBAPI
int CPXPUBLIC
   CPXSmsgstr (CPXCHANNELptr channel, char const *msg_str);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETextract (CPXCENVptr env, CPXNETptr net, CPXCLPptr lp,
                   CPXINT *colmap, CPXINT *rowmap);


CPXLIBAPI
int CPXPUBLIC
   CPXSnewcols (CPXCENVptr env, CPXLPptr lp, CPXINT ccnt,
                double const *obj, double const *lb, double const *ub,
                char const *xctype, char const *const *colname);


CPXLIBAPI
int CPXPUBLIC
   CPXSnewdblannotation (CPXCENVptr env, CPXLPptr lp,
                         char const *annotationname_str, double defval);


CPXLIBAPI
int CPXPUBLIC
   CPXSnewlongannotation (CPXCENVptr env, CPXLPptr lp,
                          char const *annotationname_str,
                          CPXLONG defval);


CPXLIBAPI
int CPXPUBLIC
   CPXSnewrows (CPXCENVptr env, CPXLPptr lp, CPXINT rcnt,
                double const *rhs, char const *sense,
                double const *rngval, char const *const *rowname);


CPXLIBAPI
int CPXPUBLIC
   CPXSobjsa (CPXCENVptr env, CPXCLPptr lp, CPXINT begin, CPXINT end,
              double *lower, double *upper);


CPXLIBAPI
CPXENVptr CPXPUBLIC
   CPXSopenCPLEX (int *status_p);


CPXLIBAPI
CPXENVptr CPXPUBLIC
   CPXSopenCPLEXruntime (int *status_p, int serialnum,
                         char const *licenvstring_str);


CPXLIBAPI
CPXENVptr CPXPUBLIC
   CPXSparenv (CPXENVptr env, int *status_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSpivot (CPXCENVptr env, CPXLPptr lp, CPXINT jenter,
              CPXINT jleave, int leavestat);


CPXLIBAPI
int CPXPUBLIC
   CPXSpivotin (CPXCENVptr env, CPXLPptr lp, CPXINT const *rlist,
                CPXINT rlen);


CPXLIBAPI
int CPXPUBLIC
   CPXSpivotout (CPXCENVptr env, CPXLPptr lp, CPXINT const *clist,
                 CPXINT clen);


CPXLIBAPI
int CPXPUBLIC
   CPXSpperwrite (CPXCENVptr env, CPXLPptr lp,
                  char const *filename_str, double epsilon);


CPXLIBAPI
int CPXPUBLIC
   CPXSpratio (CPXCENVptr env, CPXLPptr lp, CPXINT *indices,
               CPXINT cnt, double *downratio, double *upratio,
               CPXINT *downleave, CPXINT *upleave,
               int *downleavestatus, int *upleavestatus,
               int *downstatus, int *upstatus);


CPXLIBAPI
int CPXPUBLIC
   CPXSpreaddrows (CPXCENVptr env, CPXLPptr lp, CPXINT rcnt,
                   CPXINT nzcnt, double const *rhs, char const *sense,
                   CPXINT const *rmatbeg, CPXINT const *rmatind,
                   double const *rmatval, char const *const *rowname);


CPXLIBAPI
int CPXPUBLIC
   CPXSprechgobj (CPXCENVptr env, CPXLPptr lp, CPXINT cnt,
                  CPXINT const *indices, double const *values);


CPXLIBAPI
int CPXPUBLIC
   CPXSpreslvwrite (CPXCENVptr env, CPXLPptr lp,
                    char const *filename_str, double *objoff_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSpresolve (CPXCENVptr env, CPXLPptr lp, int method);


CPXLIBAPI
int CPXPUBLIC
   CPXSprimopt (CPXCENVptr env, CPXLPptr lp);


CPXLIBAPI
int CPXPUBLIC
   CPXSqpdjfrompi (CPXCENVptr env, CPXCLPptr lp, double const *pi,
                   double const *x, double *dj);


CPXLIBAPI
int CPXPUBLIC
   CPXSqpuncrushpi (CPXCENVptr env, CPXCLPptr lp, double *pi,
                    double const *prepi, double const *x);


CPXLIBAPI
int CPXPUBLIC
   CPXSreadcopyannotations (CPXCENVptr env, CPXLPptr lp,
                            char const *filename);


CPXLIBAPI
int CPXPUBLIC
   CPXSreadcopybase (CPXCENVptr env, CPXLPptr lp,
                     char const *filename_str);


CPXLIBAPI
int CPXPUBLIC
   CPXSreadcopyparam (CPXENVptr env, char const *filename_str);


CPXLIBAPI
int CPXPUBLIC
   CPXSreadcopyprob (CPXCENVptr env, CPXLPptr lp,
                     char const *filename_str,
                     char const *filetype_str);


CPXLIBAPI
int CPXPUBLIC
   CPXSreadcopysol (CPXCENVptr env, CPXLPptr lp,
                    char const *filename_str);


CPXLIBAPI
int CPXPUBLIC
   CPXSrefineconflict (CPXCENVptr env, CPXLPptr lp,
                       CPXINT *confnumrows_p, CPXINT *confnumcols_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSrefineconflictext (CPXCENVptr env, CPXLPptr lp, CPXINT grpcnt,
                          CPXINT concnt, double const *grppref,
                          CPXINT const *grpbeg, CPXINT const *grpind,
                          char const *grptype);


CPXLIBAPI
int CPXPUBLIC
   CPXSrhssa (CPXCENVptr env, CPXCLPptr lp, CPXINT begin, CPXINT end,
              double *lower, double *upper);


CPXLIBAPI
int CPXPUBLIC
   CPXSrobustopt (CPXCENVptr env, CPXLPptr lp, CPXLPptr lblp,
                  CPXLPptr ublp, double objchg, double const *maxchg);


CPXLIBAPI
int CPXPUBLIC
   CPXSsavwrite (CPXCENVptr env, CPXCLPptr lp,
                 char const *filename_str);


CPXLIBAPI
int CPXPUBLIC
   CPXSserializercreate (CPXSERIALIZERptr *ser_p);


CPXLIBAPI
void CPXPUBLIC
   CPXSserializerdestroy (CPXSERIALIZERptr ser);


CPXLIBAPI
CPXLONG CPXPUBLIC
   CPXSserializerlength (CPXCSERIALIZERptr ser);


CPXLIBAPI
void const * CPXPUBLIC
   CPXSserializerpayload (CPXCSERIALIZERptr ser);


CPXLIBAPI
int CPXPUBLIC
   CPXSsetdblannotations (CPXCENVptr env, CPXLPptr lp, CPXINT idx,
                          int objtype, CPXINT cnt,
                          CPXINT const *indices, double const *values);


CPXLIBAPI
int CPXPUBLIC
   CPXSsetdblparam (CPXENVptr env, int whichparam, double newvalue);


CPXLIBAPI
int CPXPUBLIC
   CPXSsetdefaults (CPXENVptr env);


CPXLIBAPI
int CPXPUBLIC
   CPXSsetintparam (CPXENVptr env, int whichparam, CPXINT newvalue);


CPXLIBAPI
int CPXPUBLIC
   CPXSsetlogfile (CPXENVptr env, CPXFILEptr lfile);


CPXLIBAPI
int CPXPUBLIC
   CPXSsetlongannotations (CPXCENVptr env, CPXLPptr lp, CPXINT idx,
                           int objtype, CPXINT cnt,
                           CPXINT const *indices,
                           CPXLONG const *values);


CPXLIBAPI
int CPXPUBLIC
   CPXSsetlongparam (CPXENVptr env, int whichparam, CPXLONG newvalue);


CPXLIBAPI
int CPXPUBLIC
   CPXSsetlpcallbackfunc (CPXENVptr env, CPXS_CALLBACK *callback,
                          void *cbhandle);


CPXLIBAPI
int CPXPUBLIC
   CPXSsetnetcallbackfunc (CPXENVptr env, CPXS_CALLBACK *callback,
                           void *cbhandle);


CPXLIBAPI
int CPXPUBLIC
   CPXSsetphase2 (CPXCENVptr env, CPXLPptr lp);


CPXLIBAPI
int CPXPUBLIC
   CPXSsetprofcallbackfunc (CPXENVptr env,
                            CPXS_CALLBACK_PROF *callback,
                            void *cbhandle);


CPXLIBAPI
int CPXPUBLIC
   CPXSsetstrparam (CPXENVptr env, int whichparam,
                    char const *newvalue_str);


CPXLIBAPI
int CPXPUBLIC
   CPXSsetterminate (CPXENVptr env, volatile int *terminate_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSsettuningcallbackfunc (CPXENVptr env, CPXS_CALLBACK *callback,
                              void *cbhandle);


CPXLIBAPI
int CPXPUBLIC
   CPXSsiftopt (CPXCENVptr env, CPXLPptr lp);


CPXLIBAPI
int CPXPUBLIC
   CPXSslackfromx (CPXCENVptr env, CPXCLPptr lp, double const *x,
                   double *slack);


CPXLIBAPI
int CPXPUBLIC
   CPXSsolninfo (CPXCENVptr env, CPXCLPptr lp, int *solnmethod_p,
                 int *solntype_p, int *pfeasind_p, int *dfeasind_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSsolution (CPXCENVptr env, CPXCLPptr lp, int *lpstat_p,
                 double *objval_p, double *x, double *pi,
                 double *slack, double *dj);


CPXLIBAPI
int CPXPUBLIC
   CPXSsolwrite (CPXCENVptr env, CPXCLPptr lp,
                 char const *filename_str);


CPXLIBAPI
int CPXPUBLIC
   CPXSsolwritesolnpool (CPXCENVptr env, CPXCLPptr lp, int soln,
                         char const *filename_str);


CPXLIBAPI
int CPXPUBLIC
   CPXSsolwritesolnpoolall (CPXCENVptr env, CPXCLPptr lp,
                            char const *filename_str);


CPXLIBAPI
int CPXPUBLIC
   CPXSstrongbranch (CPXCENVptr env, CPXLPptr lp,
                     CPXINT const *indices, CPXINT cnt,
                     double *downobj, double *upobj, CPXLONG itlim);


CPXLIBAPI
int CPXPUBLIC
   CPXStightenbds (CPXCENVptr env, CPXLPptr lp, CPXINT cnt,
                   CPXINT const *indices, char const *lu,
                   double const *bd);


CPXLIBAPI
int CPXPUBLIC
   CPXStuneparam (CPXENVptr env, CPXLPptr lp, int intcnt,
                  int const *intnum, int const *intval, int dblcnt,
                  int const *dblnum, double const *dblval, int strcnt,
                  int const *strnum, char const *const *strval,
                  int *tunestat_p);


CPXLIBAPI
int CPXPUBLIC
   CPXStuneparamprobset (CPXENVptr env, int filecnt,
                         char const *const *filename,
                         char const *const *filetype, int intcnt,
                         int const *intnum, int const *intval,
                         int dblcnt, int const *dblnum,
                         double const *dblval, int strcnt,
                         int const *strnum, char const *const *strval,
                         int *tunestat_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSuncrushform (CPXCENVptr env, CPXCLPptr lp, CPXINT plen,
                    CPXINT const *pind, double const *pval,
                    CPXINT *len_p, double *offset_p, CPXINT *ind,
                    double *val);


CPXLIBAPI
int CPXPUBLIC
   CPXSuncrushpi (CPXCENVptr env, CPXCLPptr lp, double *pi,
                  double const *prepi);


CPXLIBAPI
int CPXPUBLIC
   CPXSuncrushx (CPXCENVptr env, CPXCLPptr lp, double *x,
                 double const *prex);


CPXLIBAPI
int CPXPUBLIC
   CPXSunscaleprob (CPXCENVptr env, CPXLPptr lp);


CPXLIBAPI
CPXCCHARptr CPXPUBLIC
   CPXSversion (CPXCENVptr env);


CPXLIBAPI
int CPXPUBLIC
   CPXSversionnumber (CPXCENVptr env, int *version_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSwriteannotations (CPXCENVptr env, CPXCLPptr lp,
                         char const *filename);


CPXLIBAPI
int CPXPUBLIC
   CPXSwritebendersannotation (CPXCENVptr env, CPXCLPptr lp,
                               char const *filename);


CPXLIBAPI
int CPXPUBLIC
   CPXSwriteparam (CPXCENVptr env, char const *filename_str);


CPXLIBAPI
int CPXPUBLIC
   CPXSwriteprob (CPXCENVptr env, CPXCLPptr lp,
                  char const *filename_str, char const *filetype_str);


CPXLIBAPI
int CPXPUBLIC
   CPXSbaropt (CPXCENVptr env, CPXLPptr lp);


CPXLIBAPI
int CPXPUBLIC
   CPXShybbaropt (CPXCENVptr env, CPXLPptr lp, int method);


CPXLIBAPI
int CPXPUBLIC
   CPXSaddindconstr (CPXCENVptr env, CPXLPptr lp, CPXINT indvar,
                     int complemented, CPXINT nzcnt, double rhs,
                     int sense, CPXINT const *linind,
                     double const *linval, char const *indname_str);


CPXLIBAPI
int CPXPUBLIC
   CPXSchgqpcoef (CPXCENVptr env, CPXLPptr lp, CPXINT i, CPXINT j,
                  double newvalue);


CPXLIBAPI
int CPXPUBLIC
   CPXScopyqpsep (CPXCENVptr env, CPXLPptr lp, double const *qsepvec);


CPXLIBAPI
int CPXPUBLIC
   CPXScopyquad (CPXCENVptr env, CPXLPptr lp, CPXINT const *qmatbeg,
                 CPXINT const *qmatcnt, CPXINT const *qmatind,
                 double const *qmatval);


CPXLIBAPI
CPXINT CPXPUBLIC
   CPXSgetnumqpnz (CPXCENVptr env, CPXCLPptr lp);


CPXLIBAPI
CPXINT CPXPUBLIC
   CPXSgetnumquad (CPXCENVptr env, CPXCLPptr lp);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetqpcoef (CPXCENVptr env, CPXCLPptr lp, CPXINT rownum,
                  CPXINT colnum, double *coef_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetquad (CPXCENVptr env, CPXCLPptr lp, CPXINT *nzcnt_p,
                CPXINT *qmatbeg, CPXINT *qmatind, double *qmatval,
                CPXINT qmatspace, CPXINT *surplus_p, CPXINT begin,
                CPXINT end);


CPXLIBAPI
int CPXPUBLIC
   CPXSqpindefcertificate (CPXCENVptr env, CPXCLPptr lp, double *x);


CPXLIBAPI
int CPXPUBLIC
   CPXSqpopt (CPXCENVptr env, CPXLPptr lp);


CPXLIBAPI
int CPXPUBLIC
   CPXSaddqconstr (CPXCENVptr env, CPXLPptr lp, CPXINT linnzcnt,
                   CPXINT quadnzcnt, double rhs, int sense,
                   CPXINT const *linind, double const *linval,
                   CPXINT const *quadrow, CPXINT const *quadcol,
                   double const *quadval, char const *lname_str);


CPXLIBAPI
int CPXPUBLIC
   CPXSdelqconstrs (CPXCENVptr env, CPXLPptr lp, CPXINT begin,
                    CPXINT end);


CPXLIBAPI
CPXINT CPXPUBLIC
   CPXSgetnumqconstrs (CPXCENVptr env, CPXCLPptr lp);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetqconstr (CPXCENVptr env, CPXCLPptr lp, CPXINT *linnzcnt_p,
                   CPXINT *quadnzcnt_p, double *rhs_p, char *sense_p,
                   CPXINT *linind, double *linval, CPXINT linspace,
                   CPXINT *linsurplus_p, CPXINT *quadrow,
                   CPXINT *quadcol, double *quadval, CPXINT quadspace,
                   CPXINT *quadsurplus_p, CPXINT which);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetqconstrdslack (CPXCENVptr env, CPXCLPptr lp, CPXINT qind,
                         CPXINT *nz_p, CPXINT *ind, double *val,
                         CPXINT space, CPXINT *surplus_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetqconstrindex (CPXCENVptr env, CPXCLPptr lp,
                        char const *lname_str, CPXINT *index_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetqconstrinfeas (CPXCENVptr env, CPXCLPptr lp, double const *x,
                         double *infeasout, CPXINT begin, CPXINT end);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetqconstrname (CPXCENVptr env, CPXCLPptr lp, char *buf_str,
                       CPXSIZE bufspace, CPXSIZE *surplus_p,
                       CPXINT which);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetqconstrslack (CPXCENVptr env, CPXCLPptr lp, double *qcslack,
                        CPXINT begin, CPXINT end);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetxqxax (CPXCENVptr env, CPXCLPptr lp, double *xqxax,
                 CPXINT begin, CPXINT end);


CPXLIBAPI
int CPXPUBLIC
   CPXSqconstrslackfromx (CPXCENVptr env, CPXCLPptr lp,
                          double const *x, double *qcslack);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETaddarcs (CPXCENVptr env, CPXNETptr net, CPXINT narcs,
                   CPXINT const *fromnode, CPXINT const *tonode,
                   double const *low, double const *up,
                   double const *obj, char const *const *anames);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETaddnodes (CPXCENVptr env, CPXNETptr net, CPXINT nnodes,
                    double const *supply, char const *const *name);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETbasewrite (CPXCENVptr env, CPXCNETptr net,
                     char const *filename_str);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETchgarcname (CPXCENVptr env, CPXNETptr net, CPXINT cnt,
                      CPXINT const *indices,
                      char const *const *newname);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETchgarcnodes (CPXCENVptr env, CPXNETptr net, CPXINT cnt,
                       CPXINT const *indices, CPXINT const *fromnode,
                       CPXINT const *tonode);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETchgbds (CPXCENVptr env, CPXNETptr net, CPXINT cnt,
                  CPXINT const *indices, char const *lu,
                  double const *bd);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETchgname (CPXCENVptr env, CPXNETptr net, int key,
                   CPXINT vindex, char const *name_str);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETchgnodename (CPXCENVptr env, CPXNETptr net, CPXINT cnt,
                       CPXINT const *indices,
                       char const *const *newname);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETchgobj (CPXCENVptr env, CPXNETptr net, CPXINT cnt,
                  CPXINT const *indices, double const *obj);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETchgobjsen (CPXCENVptr env, CPXNETptr net, int maxormin);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETchgsupply (CPXCENVptr env, CPXNETptr net, CPXINT cnt,
                     CPXINT const *indices, double const *supply);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETcopybase (CPXCENVptr env, CPXNETptr net, int const *astat,
                    int const *nstat);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETcopynet (CPXCENVptr env, CPXNETptr net, int objsen,
                   CPXINT nnodes, double const *supply,
                   char const *const *nnames, CPXINT narcs,
                   CPXINT const *fromnode, CPXINT const *tonode,
                   double const *low, double const *up,
                   double const *obj, char const *const *anames);


CPXLIBAPI
CPXNETptr CPXPUBLIC
   CPXSNETcreateprob (CPXENVptr env, int *status_p,
                      char const *name_str);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETdelarcs (CPXCENVptr env, CPXNETptr net, CPXINT begin,
                   CPXINT end);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETdelnodes (CPXCENVptr env, CPXNETptr net, CPXINT begin,
                    CPXINT end);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETdelset (CPXCENVptr env, CPXNETptr net, CPXINT *whichnodes,
                  CPXINT *whicharcs);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETfreeprob (CPXENVptr env, CPXNETptr *net_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETgetarcindex (CPXCENVptr env, CPXCNETptr net,
                       char const *lname_str, CPXINT *index_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETgetarcname (CPXCENVptr env, CPXCNETptr net, char  **nnames,
                      char *namestore, CPXSIZE namespc,
                      CPXSIZE *surplus_p, CPXINT begin, CPXINT end);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETgetarcnodes (CPXCENVptr env, CPXCNETptr net,
                       CPXINT *fromnode, CPXINT *tonode, CPXINT begin,
                       CPXINT end);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETgetbase (CPXCENVptr env, CPXCNETptr net, int *astat,
                   int *nstat);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETgetdj (CPXCENVptr env, CPXCNETptr net, double *dj,
                 CPXINT begin, CPXINT end);


CPXLIBAPI
CPXLONG CPXPUBLIC
   CPXSNETgetitcnt (CPXCENVptr env, CPXCNETptr net);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETgetlb (CPXCENVptr env, CPXCNETptr net, double *low,
                 CPXINT begin, CPXINT end);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETgetnodearcs (CPXCENVptr env, CPXCNETptr net,
                       CPXINT *arccnt_p, CPXINT *arcbeg, CPXINT *arc,
                       CPXINT arcspace, CPXINT *surplus_p,
                       CPXINT begin, CPXINT end);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETgetnodeindex (CPXCENVptr env, CPXCNETptr net,
                        char const *lname_str, CPXINT *index_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETgetnodename (CPXCENVptr env, CPXCNETptr net, char  **nnames,
                       char *namestore, CPXSIZE namespc,
                       CPXSIZE *surplus_p, CPXINT begin, CPXINT end);


CPXLIBAPI
CPXINT CPXPUBLIC
   CPXSNETgetnumarcs (CPXCENVptr env, CPXCNETptr net);


CPXLIBAPI
CPXINT CPXPUBLIC
   CPXSNETgetnumnodes (CPXCENVptr env, CPXCNETptr net);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETgetobj (CPXCENVptr env, CPXCNETptr net, double *obj,
                  CPXINT begin, CPXINT end);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETgetobjsen (CPXCENVptr env, CPXCNETptr net);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETgetobjval (CPXCENVptr env, CPXCNETptr net, double *objval_p);


CPXLIBAPI
CPXLONG CPXPUBLIC
   CPXSNETgetphase1cnt (CPXCENVptr env, CPXCNETptr net);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETgetpi (CPXCENVptr env, CPXCNETptr net, double *pi,
                 CPXINT begin, CPXINT end);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETgetprobname (CPXCENVptr env, CPXCNETptr net, char *buf_str,
                       CPXSIZE bufspace, CPXSIZE *surplus_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETgetslack (CPXCENVptr env, CPXCNETptr net, double *slack,
                    CPXINT begin, CPXINT end);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETgetstat (CPXCENVptr env, CPXCNETptr net);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETgetsupply (CPXCENVptr env, CPXCNETptr net, double *supply,
                     CPXINT begin, CPXINT end);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETgetub (CPXCENVptr env, CPXCNETptr net, double *up,
                 CPXINT begin, CPXINT end);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETgetx (CPXCENVptr env, CPXCNETptr net, double *x,
                CPXINT begin, CPXINT end);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETprimopt (CPXCENVptr env, CPXNETptr net);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETreadcopybase (CPXCENVptr env, CPXNETptr net,
                        char const *filename_str);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETreadcopyprob (CPXCENVptr env, CPXNETptr net,
                        char const *filename_str);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETsolninfo (CPXCENVptr env, CPXCNETptr net, int *pfeasind_p,
                    int *dfeasind_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETsolution (CPXCENVptr env, CPXCNETptr net, int *netstat_p,
                    double *objval_p, double *x, double *pi,
                    double *slack, double *dj);


CPXLIBAPI
int CPXPUBLIC
   CPXSNETwriteprob (CPXCENVptr env, CPXCNETptr net,
                     char const *filename_str, char const *format_str);


CPXLIBAPI
int CPXPUBLIC
   CPXSaddlazyconstraints (CPXCENVptr env, CPXLPptr lp, CPXINT rcnt,
                           CPXINT nzcnt, double const *rhs,
                           char const *sense, CPXINT const *rmatbeg,
                           CPXINT const *rmatind,
                           double const *rmatval,
                           char const *const *rowname);


CPXLIBAPI
int CPXPUBLIC
   CPXSaddmipstarts (CPXCENVptr env, CPXLPptr lp, int mcnt,
                     CPXINT nzcnt, CPXINT const *beg,
                     CPXINT const *varindices, double const *values,
                     int const *effortlevel,
                     char const *const *mipstartname);


CPXLIBAPI
int CPXPUBLIC
   CPXSaddsolnpooldivfilter (CPXCENVptr env, CPXLPptr lp,
                             double lower_bound, double upper_bound,
                             CPXINT nzcnt, CPXINT const *ind,
                             double const *weight,
                             double const *refval,
                             char const *lname_str);


CPXLIBAPI
int CPXPUBLIC
   CPXSaddsolnpoolrngfilter (CPXCENVptr env, CPXLPptr lp, double lb,
                             double ub, CPXINT nzcnt,
                             CPXINT const *ind, double const *val,
                             char const *lname_str);


CPXLIBAPI
int CPXPUBLIC
   CPXSaddsos (CPXCENVptr env, CPXLPptr lp, CPXINT numsos,
               CPXINT numsosnz, char const *sostype,
               CPXINT const *sosbeg, CPXINT const *sosind,
               double const *soswt, char const *const *sosname);


CPXLIBAPI
int CPXPUBLIC
   CPXSaddusercuts (CPXCENVptr env, CPXLPptr lp, CPXINT rcnt,
                    CPXINT nzcnt, double const *rhs, char const *sense,
                    CPXINT const *rmatbeg, CPXINT const *rmatind,
                    double const *rmatval, char const *const *rowname);


CPXLIBAPI
int CPXPUBLIC
   CPXSbendersopt (CPXCENVptr env, CPXLPptr lp);


CPXLIBAPI
int CPXPUBLIC
   CPXSbranchcallbackbranchasCPLEX (CPXCENVptr env, void *cbdata,
                                    int wherefrom, int num,
                                    void *userhandle,
                                    CPXLONG *seqnum_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSbranchcallbackbranchbds (CPXCENVptr env, void *cbdata,
                                int wherefrom, CPXINT cnt,
                                CPXINT const *indices, char const *lu,
                                double const *bd, double nodeest,
                                void *userhandle, CPXLONG *seqnum_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSbranchcallbackbranchconstraints (CPXCENVptr env, void *cbdata,
                                        int wherefrom, CPXINT rcnt,
                                        CPXINT nzcnt,
                                        double const *rhs,
                                        char const *sense,
                                        CPXINT const *rmatbeg,
                                        CPXINT const *rmatind,
                                        double const *rmatval,
                                        double nodeest,
                                        void *userhandle,
                                        CPXLONG *seqnum_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSbranchcallbackbranchgeneral (CPXCENVptr env, void *cbdata,
                                    int wherefrom, CPXINT varcnt,
                                    CPXINT const *varind,
                                    char const *varlu,
                                    double const *varbd, CPXINT rcnt,
                                    CPXINT nzcnt, double const *rhs,
                                    char const *sense,
                                    CPXINT const *rmatbeg,
                                    CPXINT const *rmatind,
                                    double const *rmatval,
                                    double nodeest, void *userhandle,
                                    CPXLONG *seqnum_p);


CPXLIBAPI
int CPXPUBLIC
   CPXScallbacksetnodeuserhandle (CPXCENVptr env, void *cbdata,
                                  int wherefrom, CPXLONG nodeindex,
                                  void *userhandle,
                                  void  **olduserhandle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXScallbacksetuserhandle (CPXCENVptr env, void *cbdata,
                              int wherefrom, void *userhandle,
                              void  **olduserhandle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSchgctype (CPXCENVptr env, CPXLPptr lp, CPXINT cnt,
                 CPXINT const *indices, char const *xctype);


CPXLIBAPI
int CPXPUBLIC
   CPXSchgmipstarts (CPXCENVptr env, CPXLPptr lp, int mcnt,
                     int const *mipstartindices, CPXINT nzcnt,
                     CPXINT const *beg, CPXINT const *varindices,
                     double const *values, int const *effortlevel);


CPXLIBAPI
int CPXPUBLIC
   CPXScopyctype (CPXCENVptr env, CPXLPptr lp, char const *xctype);


CPXLIBAPI
int CPXPUBLIC
   CPXScopyorder (CPXCENVptr env, CPXLPptr lp, CPXINT cnt,
                  CPXINT const *indices, CPXINT const *priority,
                  int const *direction);


CPXLIBAPI
int CPXPUBLIC
   CPXScopysos (CPXCENVptr env, CPXLPptr lp, CPXINT numsos,
                CPXINT numsosnz, char const *sostype,
                CPXINT const *sosbeg, CPXINT const *sosind,
                double const *soswt, char const *const *sosname);


CPXLIBAPI
int CPXPUBLIC
   CPXScutcallbackadd (CPXCENVptr env, void *cbdata, int wherefrom,
                       CPXINT nzcnt, double rhs, int sense,
                       CPXINT const *cutind, double const *cutval,
                       int purgeable);


CPXLIBAPI
int CPXPUBLIC
   CPXScutcallbackaddlocal (CPXCENVptr env, void *cbdata,
                            int wherefrom, CPXINT nzcnt, double rhs,
                            int sense, CPXINT const *cutind,
                            double const *cutval);


CPXLIBAPI
int CPXPUBLIC
   CPXSdelindconstrs (CPXCENVptr env, CPXLPptr lp, CPXINT begin,
                      CPXINT end);


CPXLIBAPI
int CPXPUBLIC
   CPXSdelmipstarts (CPXCENVptr env, CPXLPptr lp, int begin, int end);


CPXLIBAPI
int CPXPUBLIC
   CPXSdelsetmipstarts (CPXCENVptr env, CPXLPptr lp, int *delstat);


CPXLIBAPI
int CPXPUBLIC
   CPXSdelsetsolnpoolfilters (CPXCENVptr env, CPXLPptr lp,
                              int *delstat);


CPXLIBAPI
int CPXPUBLIC
   CPXSdelsetsolnpoolsolns (CPXCENVptr env, CPXLPptr lp, int *delstat);


CPXLIBAPI
int CPXPUBLIC
   CPXSdelsetsos (CPXCENVptr env, CPXLPptr lp, CPXINT *delset);


CPXLIBAPI
int CPXPUBLIC
   CPXSdelsolnpoolfilters (CPXCENVptr env, CPXLPptr lp, int begin,
                           int end);


CPXLIBAPI
int CPXPUBLIC
   CPXSdelsolnpoolsolns (CPXCENVptr env, CPXLPptr lp, int begin,
                         int end);


CPXLIBAPI
int CPXPUBLIC
   CPXSdelsos (CPXCENVptr env, CPXLPptr lp, CPXINT begin, CPXINT end);


CPXLIBAPI
int CPXPUBLIC
   CPXSfltwrite (CPXCENVptr env, CPXCLPptr lp,
                 char const *filename_str);


CPXLIBAPI
int CPXPUBLIC
   CPXSfreelazyconstraints (CPXCENVptr env, CPXLPptr lp);


CPXLIBAPI
int CPXPUBLIC
   CPXSfreeusercuts (CPXCENVptr env, CPXLPptr lp);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetbestobjval (CPXCENVptr env, CPXCLPptr lp, double *objval_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetbranchcallbackfunc (CPXCENVptr env,
                              CPXS_CALLBACK_BRANCH **branchcallback_p,
                              void  **cbhandle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetbranchnosolncallbackfunc (CPXCENVptr env,
                                    CPXS_CALLBACK_BRANCH **branchnosolncallback_p,
                                    void  **cbhandle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetcallbackbranchconstraints (CPXCENVptr env, void *cbdata,
                                     int wherefrom, int which,
                                     CPXINT *cuts_p, CPXINT *nzcnt_p,
                                     double *rhs, char *sense,
                                     CPXINT *rmatbeg, CPXINT *rmatind,
                                     double *rmatval, CPXINT rmatsz,
                                     CPXINT *surplus_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetcallbackctype (CPXCENVptr env, void *cbdata, int wherefrom,
                         char *xctype, CPXINT begin, CPXINT end);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetcallbackgloballb (CPXCENVptr env, void *cbdata,
                            int wherefrom, double *lb, CPXINT begin,
                            CPXINT end);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetcallbackglobalub (CPXCENVptr env, void *cbdata,
                            int wherefrom, double *ub, CPXINT begin,
                            CPXINT end);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetcallbackincumbent (CPXCENVptr env, void *cbdata,
                             int wherefrom, double *x, CPXINT begin,
                             CPXINT end);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetcallbackindicatorinfo (CPXCENVptr env, void *cbdata,
                                 int wherefrom, CPXINT iindex,
                                 int whichinfo, void *result_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetcallbacklp (CPXCENVptr env, void *cbdata, int wherefrom,
                      CPXCLPptr *lp_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetcallbacknodeinfo (CPXCENVptr env, void *cbdata,
                            int wherefrom, CPXLONG nodeindex,
                            int whichinfo, void *result_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetcallbacknodeintfeas (CPXCENVptr env, void *cbdata,
                               int wherefrom, int *feas, CPXINT begin,
                               CPXINT end);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetcallbacknodelb (CPXCENVptr env, void *cbdata, int wherefrom,
                          double *lb, CPXINT begin, CPXINT end);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetcallbacknodelp (CPXCENVptr env, void *cbdata, int wherefrom,
                          CPXLPptr *nodelp_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetcallbacknodeobjval (CPXCENVptr env, void *cbdata,
                              int wherefrom, double *objval_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetcallbacknodestat (CPXCENVptr env, void *cbdata,
                            int wherefrom, int *nodestat_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetcallbacknodeub (CPXCENVptr env, void *cbdata, int wherefrom,
                          double *ub, CPXINT begin, CPXINT end);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetcallbacknodex (CPXCENVptr env, void *cbdata, int wherefrom,
                         double *x, CPXINT begin, CPXINT end);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetcallbackorder (CPXCENVptr env, void *cbdata, int wherefrom,
                         CPXINT *priority, int *direction,
                         CPXINT begin, CPXINT end);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetcallbackpseudocosts (CPXCENVptr env, void *cbdata,
                               int wherefrom, double *uppc,
                               double *downpc, CPXINT begin,
                               CPXINT end);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetcallbackseqinfo (CPXCENVptr env, void *cbdata, int wherefrom,
                           CPXLONG seqid, int whichinfo,
                           void *result_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetcallbacksosinfo (CPXCENVptr env, void *cbdata, int wherefrom,
                           CPXINT sosindex, CPXINT member,
                           int whichinfo, void *result_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetctype (CPXCENVptr env, CPXCLPptr lp, char *xctype,
                 CPXINT begin, CPXINT end);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetcutoff (CPXCENVptr env, CPXCLPptr lp, double *cutoff_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetdeletenodecallbackfunc (CPXCENVptr env,
                                  CPXS_CALLBACK_DELETENODE **deletecallback_p,
                                  void  **cbhandle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetheuristiccallbackfunc (CPXCENVptr env,
                                 CPXS_CALLBACK_HEURISTIC **heuristiccallback_p,
                                 void  **cbhandle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetincumbentcallbackfunc (CPXCENVptr env,
                                 CPXS_CALLBACK_INCUMBENT **incumbentcallback_p,
                                 void  **cbhandle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetindconstr (CPXCENVptr env, CPXCLPptr lp, CPXINT *indvar_p,
                     int *complemented_p, CPXINT *nzcnt_p,
                     double *rhs_p, char *sense_p, CPXINT *linind,
                     double *linval, CPXINT space, CPXINT *surplus_p,
                     CPXINT which);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetindconstrindex (CPXCENVptr env, CPXCLPptr lp,
                          char const *lname_str, CPXINT *index_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetindconstrinfeas (CPXCENVptr env, CPXCLPptr lp,
                           double const *x, double *infeasout,
                           CPXINT begin, CPXINT end);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetindconstrname (CPXCENVptr env, CPXCLPptr lp, char *buf_str,
                         CPXSIZE bufspace, CPXSIZE *surplus_p,
                         CPXINT which);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetindconstrslack (CPXCENVptr env, CPXCLPptr lp,
                          double *indslack, CPXINT begin, CPXINT end);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetinfocallbackfunc (CPXCENVptr env, CPXS_CALLBACK **callback_p,
                            void  **cbhandle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetlazyconstraintcallbackfunc (CPXCENVptr env,
                                      CPXS_CALLBACK_CUT **cutcallback_p,
                                      void  **cbhandle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetmipcallbackfunc (CPXCENVptr env, CPXS_CALLBACK **callback_p,
                           void  **cbhandle_p);


CPXLIBAPI
CPXLONG CPXPUBLIC
   CPXSgetmipitcnt (CPXCENVptr env, CPXCLPptr lp);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetmiprelgap (CPXCENVptr env, CPXCLPptr lp, double *gap_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetmipstartindex (CPXCENVptr env, CPXCLPptr lp,
                         char const *lname_str, int *index_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetmipstartname (CPXCENVptr env, CPXCLPptr lp, char  **name,
                        char *store, CPXSIZE storesz,
                        CPXSIZE *surplus_p, int begin, int end);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetmipstarts (CPXCENVptr env, CPXCLPptr lp, CPXINT *nzcnt_p,
                     CPXINT *beg, CPXINT *varindices, double *values,
                     int *effortlevel, CPXINT startspace,
                     CPXINT *surplus_p, int begin, int end);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetnodecallbackfunc (CPXCENVptr env,
                            CPXS_CALLBACK_NODE **nodecallback_p,
                            void  **cbhandle_p);


CPXLIBAPI
CPXLONG CPXPUBLIC
   CPXSgetnodecnt (CPXCENVptr env, CPXCLPptr lp);


CPXLIBAPI
CPXLONG CPXPUBLIC
   CPXSgetnodeint (CPXCENVptr env, CPXCLPptr lp);


CPXLIBAPI
CPXLONG CPXPUBLIC
   CPXSgetnodeleftcnt (CPXCENVptr env, CPXCLPptr lp);


CPXLIBAPI
CPXINT CPXPUBLIC
   CPXSgetnumbin (CPXCENVptr env, CPXCLPptr lp);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetnumcuts (CPXCENVptr env, CPXCLPptr lp, int cuttype,
                   CPXINT *num_p);


CPXLIBAPI
CPXINT CPXPUBLIC
   CPXSgetnumindconstrs (CPXCENVptr env, CPXCLPptr lp);


CPXLIBAPI
CPXINT CPXPUBLIC
   CPXSgetnumint (CPXCENVptr env, CPXCLPptr lp);


CPXLIBAPI
CPXINT CPXPUBLIC
   CPXSgetnumlazyconstraints (CPXCENVptr env, CPXCLPptr lp);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetnummipstarts (CPXCENVptr env, CPXCLPptr lp);


CPXLIBAPI
CPXINT CPXPUBLIC
   CPXSgetnumsemicont (CPXCENVptr env, CPXCLPptr lp);


CPXLIBAPI
CPXINT CPXPUBLIC
   CPXSgetnumsemiint (CPXCENVptr env, CPXCLPptr lp);


CPXLIBAPI
CPXINT CPXPUBLIC
   CPXSgetnumsos (CPXCENVptr env, CPXCLPptr lp);


CPXLIBAPI
CPXINT CPXPUBLIC
   CPXSgetnumusercuts (CPXCENVptr env, CPXCLPptr lp);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetorder (CPXCENVptr env, CPXCLPptr lp, CPXINT *cnt_p,
                 CPXINT *indices, CPXINT *priority, int *direction,
                 CPXINT ordspace, CPXINT *surplus_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetsolnpooldivfilter (CPXCENVptr env, CPXCLPptr lp,
                             double *lower_cutoff_p,
                             double *upper_cutoff_p, CPXINT *nzcnt_p,
                             CPXINT *ind, double *val, double *refval,
                             CPXINT space, CPXINT *surplus_p,
                             int which);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetsolnpoolfilterindex (CPXCENVptr env, CPXCLPptr lp,
                               char const *lname_str, int *index_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetsolnpoolfiltername (CPXCENVptr env, CPXCLPptr lp,
                              char *buf_str, CPXSIZE bufspace,
                              CPXSIZE *surplus_p, int which);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetsolnpoolfiltertype (CPXCENVptr env, CPXCLPptr lp,
                              int *ftype_p, int which);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetsolnpoolmeanobjval (CPXCENVptr env, CPXCLPptr lp,
                              double *meanobjval_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetsolnpoolnumfilters (CPXCENVptr env, CPXCLPptr lp);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetsolnpoolnumreplaced (CPXCENVptr env, CPXCLPptr lp);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetsolnpoolnumsolns (CPXCENVptr env, CPXCLPptr lp);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetsolnpoolobjval (CPXCENVptr env, CPXCLPptr lp, int soln,
                          double *objval_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetsolnpoolqconstrslack (CPXCENVptr env, CPXCLPptr lp, int soln,
                                double *qcslack, CPXINT begin,
                                CPXINT end);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetsolnpoolrngfilter (CPXCENVptr env, CPXCLPptr lp,
                             double *lb_p, double *ub_p,
                             CPXINT *nzcnt_p, CPXINT *ind, double *val,
                             CPXINT space, CPXINT *surplus_p,
                             int which);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetsolnpoolslack (CPXCENVptr env, CPXCLPptr lp, int soln,
                         double *slack, CPXINT begin, CPXINT end);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetsolnpoolsolnindex (CPXCENVptr env, CPXCLPptr lp,
                             char const *lname_str, int *index_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetsolnpoolsolnname (CPXCENVptr env, CPXCLPptr lp, char *store,
                            CPXSIZE storesz, CPXSIZE *surplus_p,
                            int which);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetsolnpoolx (CPXCENVptr env, CPXCLPptr lp, int soln, double *x,
                     CPXINT begin, CPXINT end);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetsolvecallbackfunc (CPXCENVptr env,
                             CPXS_CALLBACK_SOLVE **solvecallback_p,
                             void  **cbhandle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetsos (CPXCENVptr env, CPXCLPptr lp, CPXINT *numsosnz_p,
               char *sostype, CPXINT *sosbeg, CPXINT *sosind,
               double *soswt, CPXINT sosspace, CPXINT *surplus_p,
               CPXINT begin, CPXINT end);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetsosindex (CPXCENVptr env, CPXCLPptr lp,
                    char const *lname_str, CPXINT *index_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetsosinfeas (CPXCENVptr env, CPXCLPptr lp, double const *x,
                     double *infeasout, CPXINT begin, CPXINT end);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetsosname (CPXCENVptr env, CPXCLPptr lp, char  **name,
                   char *namestore, CPXSIZE storespace,
                   CPXSIZE *surplus_p, CPXINT begin, CPXINT end);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetsubmethod (CPXCENVptr env, CPXCLPptr lp);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetsubstat (CPXCENVptr env, CPXCLPptr lp);


CPXLIBAPI
int CPXPUBLIC
   CPXSgetusercutcallbackfunc (CPXCENVptr env,
                               CPXS_CALLBACK_CUT **cutcallback_p,
                               void  **cbhandle_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSindconstrslackfromx (CPXCENVptr env, CPXCLPptr lp,
                            double const *x, double *indslack);


CPXLIBAPI
int CPXPUBLIC
   CPXSmipopt (CPXCENVptr env, CPXLPptr lp);


CPXLIBAPI
int CPXPUBLIC
   CPXSordread (CPXCENVptr env, char const *filename_str,
                CPXINT numcols, char const *const *colname,
                CPXINT *cnt_p, CPXINT *indices, CPXINT *priority,
                int *direction);


CPXLIBAPI
int CPXPUBLIC
   CPXSordwrite (CPXCENVptr env, CPXCLPptr lp,
                 char const *filename_str);


CPXLIBAPI
int CPXPUBLIC
   CPXSpopulate (CPXCENVptr env, CPXLPptr lp);


CPXLIBAPI
int CPXPUBLIC
   CPXSreadcopymipstarts (CPXCENVptr env, CPXLPptr lp,
                          char const *filename_str);


CPXLIBAPI
int CPXPUBLIC
   CPXSreadcopyorder (CPXCENVptr env, CPXLPptr lp,
                      char const *filename_str);


CPXLIBAPI
int CPXPUBLIC
   CPXSreadcopysolnpoolfilters (CPXCENVptr env, CPXLPptr lp,
                                char const *filename_str);


CPXLIBAPI
int CPXPUBLIC
   CPXSrefinemipstartconflict (CPXCENVptr env, CPXLPptr lp,
                               int mipstartindex,
                               CPXINT *confnumrows_p,
                               CPXINT *confnumcols_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSrefinemipstartconflictext (CPXCENVptr env, CPXLPptr lp,
                                  int mipstartindex, CPXINT grpcnt,
                                  CPXINT concnt, double const *grppref,
                                  CPXINT const *grpbeg,
                                  CPXINT const *grpind,
                                  char const *grptype);


CPXLIBAPI
int CPXPUBLIC
   CPXSsetbranchcallbackfunc (CPXENVptr env,
                              CPXS_CALLBACK_BRANCH *branchcallback,
                              void *cbhandle);


CPXLIBAPI
int CPXPUBLIC
   CPXSsetbranchnosolncallbackfunc (CPXENVptr env,
                                    CPXS_CALLBACK_BRANCH *branchnosolncallback,
                                    void *cbhandle);


CPXLIBAPI
int CPXPUBLIC
   CPXSsetdeletenodecallbackfunc (CPXENVptr env,
                                  CPXS_CALLBACK_DELETENODE *deletecallback,
                                  void *cbhandle);


CPXLIBAPI
int CPXPUBLIC
   CPXSsetheuristiccallbackfunc (CPXENVptr env,
                                 CPXS_CALLBACK_HEURISTIC *heuristiccallback,
                                 void *cbhandle);


CPXLIBAPI
int CPXPUBLIC
   CPXSsetincumbentcallbackfunc (CPXENVptr env,
                                 CPXS_CALLBACK_INCUMBENT *incumbentcallback,
                                 void *cbhandle);


CPXLIBAPI
int CPXPUBLIC
   CPXSsetinfocallbackfunc (CPXENVptr env, CPXS_CALLBACK *callback,
                            void *cbhandle);


CPXLIBAPI
int CPXPUBLIC
   CPXSsetlazyconstraintcallbackfunc (CPXENVptr env,
                                      CPXS_CALLBACK_CUT *lazyconcallback,
                                      void *cbhandle);


CPXLIBAPI
int CPXPUBLIC
   CPXSsetmipcallbackfunc (CPXENVptr env, CPXS_CALLBACK *callback,
                           void *cbhandle);


CPXLIBAPI
int CPXPUBLIC
   CPXSsetnodecallbackfunc (CPXENVptr env,
                            CPXS_CALLBACK_NODE *nodecallback,
                            void *cbhandle);


CPXLIBAPI
int CPXPUBLIC
   CPXSsetsolvecallbackfunc (CPXENVptr env,
                             CPXS_CALLBACK_SOLVE *solvecallback,
                             void *cbhandle);


CPXLIBAPI
int CPXPUBLIC
   CPXSsetusercutcallbackfunc (CPXENVptr env,
                               CPXS_CALLBACK_CUT *cutcallback,
                               void *cbhandle);


CPXLIBAPI
int CPXPUBLIC
   CPXSwritemipstarts (CPXCENVptr env, CPXCLPptr lp,
                       char const *filename_str, int begin, int end);



#ifdef __cplusplus
}
#endif

#ifdef _WIN32
#pragma pack(pop)
#endif

#endif /* !CPX_CPLEXS_H */
