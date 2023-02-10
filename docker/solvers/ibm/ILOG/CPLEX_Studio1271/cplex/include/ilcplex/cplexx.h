/* --------------------------------------------------------------------------
 * File: cplexx.h
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

#ifndef CPX_CPLEXX_H
#   define CPX_CPLEXX_H 1
#include "cpxconst.h"

#ifdef _WIN32
#pragma pack(push, 8)
#endif

#ifdef __cplusplus
extern "C" {
#endif


#define CPX_APIMODEL_SMALL 1
#define CPX_APIMODEL_LARGE 2

#ifndef CPX_APIMODEL
#   if defined(__x86_64__) || defined(__ia64) || defined(_WIN64) || defined(__powerpc64__) || defined(__64BIT__) || defined(__sparcv9) || defined(__LP64__)
#      define CPX_APIMODEL CPX_APIMODEL_LARGE
#   else
#      define CPX_APIMODEL CPX_APIMODEL_SMALL
#   endif
#endif

#if CPX_APIMODEL == CPX_APIMODEL_SMALL
#   include "cplexs.h"
#   define CPX_CALL(function) CPXS ## function
#elif CPX_APIMODEL == CPX_APIMODEL_LARGE
#   include "cplexl.h"
#   define CPX_CALL(function) CPXL ## function
#else
#   error "Unknown CPX_APIMODEL"
#endif

#if CPX_APIMODEL == CPX_APIMODEL_SMALL
    typedef CPXINT CPXDIM;
#elif CPX_APIMODEL == CPX_APIMODEL_LARGE
    typedef CPXINT CPXDIM;
#endif

#if CPX_APIMODEL == CPX_APIMODEL_SMALL
    typedef CPXINT CPXNNZ;
#elif CPX_APIMODEL == CPX_APIMODEL_LARGE
    typedef CPXLONG CPXNNZ;
#endif

#if CPX_APIMODEL == CPX_APIMODEL_SMALL
    typedef CPXLONG CPXCNT;
#elif CPX_APIMODEL == CPX_APIMODEL_LARGE
    typedef CPXLONG CPXCNT;
#endif

/* Argument lists for callbacks */
#define CPXX_CALLBACK_ARGS CPXCENVptr env, void *cbdata, int wherefrom, \
      void *cbhandle
#define CPXX_CALLBACK_PROF_ARGS CPXCENVptr env, int wherefrom, void *cbhandle
#define CPXX_CALLBACK_BRANCH_ARGS  CPXCENVptr xenv, void *cbdata,       \
      int wherefrom, void *cbhandle, int brtype, CPXDIM brset,          \
      int nodecnt, CPXDIM bdcnt,                                        \
      const CPXDIM *nodebeg, const CPXDIM *xindex, const char *lu,      \
      const double *bd, const double *nodeest, int *useraction_p
#define CPXX_CALLBACK_NODE_ARGS  CPXCENVptr xenv, void *cbdata,         \
      int wherefrom, void *cbhandle, CPXCNT *nodeindex, int *useraction
#define CPXX_CALLBACK_HEURISTIC_ARGS  CPXCENVptr xenv, void *cbdata,    \
      int wherefrom, void *cbhandle, double *objval_p, double *x,       \
      int *checkfeas_p, int *useraction_p
#define CPXX_CALLBACK_SOLVE_ARGS  CPXCENVptr xenv, void *cbdata,        \
      int wherefrom, void *cbhandle, int *useraction
#define CPXX_CALLBACK_CUT_ARGS  CPXCENVptr xenv, void *cbdata,  \
      int wherefrom, void *cbhandle, int *useraction_p
#define CPXX_CALLBACK_INCUMBENT_ARGS  CPXCENVptr xenv, void *cbdata,    \
      int wherefrom, void *cbhandle, double objval, double *x,          \
      int *isfeas_p, int *useraction_p
#define CPXX_CALLBACK_DELETENODE_ARGS  CPXCENVptr xenv,                 \
      int wherefrom, void *cbhandle, CPXCNT seqnum, void *handle

typedef int (CPXPUBLIC CPXX_CALLBACK) (CPXX_CALLBACK_ARGS);
typedef int (CPXPUBLIC CPXX_CALLBACK_PROF)(CPXX_CALLBACK_PROF_ARGS);
typedef int (CPXPUBLIC CPXX_CALLBACK_BRANCH) (CPXX_CALLBACK_BRANCH_ARGS);
typedef int (CPXPUBLIC CPXX_CALLBACK_NODE) (CPXX_CALLBACK_NODE_ARGS);
typedef int (CPXPUBLIC CPXX_CALLBACK_HEURISTIC) (CPXX_CALLBACK_HEURISTIC_ARGS);
typedef int (CPXPUBLIC CPXX_CALLBACK_SOLVE) (CPXX_CALLBACK_SOLVE_ARGS);
typedef int (CPXPUBLIC CPXX_CALLBACK_CUT) (CPXX_CALLBACK_CUT_ARGS);
typedef int (CPXPUBLIC CPXX_CALLBACK_INCUMBENT) (CPXX_CALLBACK_INCUMBENT_ARGS);
typedef void (CPXPUBLIC CPXX_CALLBACK_DELETENODE) (CPXX_CALLBACK_DELETENODE_ARGS);






CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXaddcols (CPXCENVptr env, CPXLPptr lp, CPXDIM ccnt, CPXNNZ nzcnt,
                double const *obj, CPXNNZ const *cmatbeg,
                CPXDIM const *cmatind, double const *cmatval,
                double const *lb, double const *ub,
                char const *const *colname)
{
   return CPX_CALL (addcols) (env, lp, ccnt, nzcnt, obj, cmatbeg, cmatind, cmatval, lb, ub, colname);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXaddfpdest (CPXCENVptr env, CPXCHANNELptr channel,
                  CPXFILEptr fileptr)
{
   return CPX_CALL (addfpdest) (env, channel, fileptr);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXaddfuncdest (CPXCENVptr env, CPXCHANNELptr channel,
                    void *handle,
                    void (CPXPUBLIC *msgfunction)(void *, char const *))
{
   return CPX_CALL (addfuncdest) (env, channel, handle, msgfunction);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXaddpwl (CPXCENVptr env, CPXLPptr lp, CPXDIM vary, CPXDIM varx,
               double preslope, double postslope, CPXDIM nbreaks,
               double const *breakx, double const *breaky,
               char const *pwlname)
{
   return CPX_CALL (addpwl) (env, lp, vary, varx, preslope, postslope, nbreaks, breakx, breaky, pwlname);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXaddrows (CPXCENVptr env, CPXLPptr lp, CPXDIM ccnt, CPXDIM rcnt,
                CPXNNZ nzcnt, double const *rhs, char const *sense,
                CPXNNZ const *rmatbeg, CPXDIM const *rmatind,
                double const *rmatval, char const *const *colname,
                char const *const *rowname)
{
   return CPX_CALL (addrows) (env, lp, ccnt, rcnt, nzcnt, rhs, sense, rmatbeg, rmatind, rmatval, colname, rowname);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXbasicpresolve (CPXCENVptr env, CPXLPptr lp, double *redlb,
                      double *redub, int *rstat)
{
   return CPX_CALL (basicpresolve) (env, lp, redlb, redub, rstat);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXbinvacol (CPXCENVptr env, CPXCLPptr lp, CPXDIM j, double *x)
{
   return CPX_CALL (binvacol) (env, lp, j, x);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXbinvarow (CPXCENVptr env, CPXCLPptr lp, CPXDIM i, double *z)
{
   return CPX_CALL (binvarow) (env, lp, i, z);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXbinvcol (CPXCENVptr env, CPXCLPptr lp, CPXDIM j, double *x)
{
   return CPX_CALL (binvcol) (env, lp, j, x);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXbinvrow (CPXCENVptr env, CPXCLPptr lp, CPXDIM i, double *y)
{
   return CPX_CALL (binvrow) (env, lp, i, y);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXboundsa (CPXCENVptr env, CPXCLPptr lp, CPXDIM begin, CPXDIM end,
                double *lblower, double *lbupper, double *ublower,
                double *ubupper)
{
   return CPX_CALL (boundsa) (env, lp, begin, end, lblower, lbupper, ublower, ubupper);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXbtran (CPXCENVptr env, CPXCLPptr lp, double *y)
{
   return CPX_CALL (btran) (env, lp, y);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXcheckdfeas (CPXCENVptr env, CPXLPptr lp, CPXDIM *infeas_p)
{
   return CPX_CALL (checkdfeas) (env, lp, infeas_p);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXcheckpfeas (CPXCENVptr env, CPXLPptr lp, CPXDIM *infeas_p)
{
   return CPX_CALL (checkpfeas) (env, lp, infeas_p);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXchecksoln (CPXCENVptr env, CPXLPptr lp, int *lpstatus_p)
{
   return CPX_CALL (checksoln) (env, lp, lpstatus_p);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXchgbds (CPXCENVptr env, CPXLPptr lp, CPXDIM cnt,
               CPXDIM const *indices, char const *lu, double const *bd)
{
   return CPX_CALL (chgbds) (env, lp, cnt, indices, lu, bd);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXchgcoef (CPXCENVptr env, CPXLPptr lp, CPXDIM i, CPXDIM j,
                double newvalue)
{
   return CPX_CALL (chgcoef) (env, lp, i, j, newvalue);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXchgcoeflist (CPXCENVptr env, CPXLPptr lp, CPXNNZ numcoefs,
                    CPXDIM const *rowlist, CPXDIM const *collist,
                    double const *vallist)
{
   return CPX_CALL (chgcoeflist) (env, lp, numcoefs, rowlist, collist, vallist);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXchgcolname (CPXCENVptr env, CPXLPptr lp, CPXDIM cnt,
                   CPXDIM const *indices, char const *const *newname)
{
   return CPX_CALL (chgcolname) (env, lp, cnt, indices, newname);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXchgname (CPXCENVptr env, CPXLPptr lp, int key, CPXDIM ij,
                char const *newname_str)
{
   return CPX_CALL (chgname) (env, lp, key, ij, newname_str);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXchgobj (CPXCENVptr env, CPXLPptr lp, CPXDIM cnt,
               CPXDIM const *indices, double const *values)
{
   return CPX_CALL (chgobj) (env, lp, cnt, indices, values);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXchgobjoffset (CPXCENVptr env, CPXLPptr lp, double offset)
{
   return CPX_CALL (chgobjoffset) (env, lp, offset);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXchgobjsen (CPXCENVptr env, CPXLPptr lp, int maxormin)
{
   return CPX_CALL (chgobjsen) (env, lp, maxormin);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXchgprobname (CPXCENVptr env, CPXLPptr lp, char const *probname)
{
   return CPX_CALL (chgprobname) (env, lp, probname);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXchgprobtype (CPXCENVptr env, CPXLPptr lp, int type)
{
   return CPX_CALL (chgprobtype) (env, lp, type);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXchgprobtypesolnpool (CPXCENVptr env, CPXLPptr lp, int type,
                            int soln)
{
   return CPX_CALL (chgprobtypesolnpool) (env, lp, type, soln);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXchgrhs (CPXCENVptr env, CPXLPptr lp, CPXDIM cnt,
               CPXDIM const *indices, double const *values)
{
   return CPX_CALL (chgrhs) (env, lp, cnt, indices, values);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXchgrngval (CPXCENVptr env, CPXLPptr lp, CPXDIM cnt,
                  CPXDIM const *indices, double const *values)
{
   return CPX_CALL (chgrngval) (env, lp, cnt, indices, values);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXchgrowname (CPXCENVptr env, CPXLPptr lp, CPXDIM cnt,
                   CPXDIM const *indices, char const *const *newname)
{
   return CPX_CALL (chgrowname) (env, lp, cnt, indices, newname);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXchgsense (CPXCENVptr env, CPXLPptr lp, CPXDIM cnt,
                 CPXDIM const *indices, char const *sense)
{
   return CPX_CALL (chgsense) (env, lp, cnt, indices, sense);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXcleanup (CPXCENVptr env, CPXLPptr lp, double eps)
{
   return CPX_CALL (cleanup) (env, lp, eps);
}


CPX_STATIC_INLINE
CPXLPptr CPXPUBLIC
   CPXXcloneprob (CPXCENVptr env, CPXCLPptr lp, int *status_p)
{
   return CPX_CALL (cloneprob) (env, lp, status_p);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXcloseCPLEX (CPXENVptr *env_p)
{
   return CPX_CALL (closeCPLEX) (env_p);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXclpwrite (CPXCENVptr env, CPXCLPptr lp,
                 char const *filename_str)
{
   return CPX_CALL (clpwrite) (env, lp, filename_str);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXcompletelp (CPXCENVptr env, CPXLPptr lp)
{
   return CPX_CALL (completelp) (env, lp);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXcopybase (CPXCENVptr env, CPXLPptr lp, int const *cstat,
                 int const *rstat)
{
   return CPX_CALL (copybase) (env, lp, cstat, rstat);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXcopybasednorms (CPXCENVptr env, CPXLPptr lp, int const *cstat,
                       int const *rstat, double const *dnorm)
{
   return CPX_CALL (copybasednorms) (env, lp, cstat, rstat, dnorm);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXcopydnorms (CPXCENVptr env, CPXLPptr lp, double const *norm,
                   CPXDIM const *head, CPXDIM len)
{
   return CPX_CALL (copydnorms) (env, lp, norm, head, len);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXcopylp (CPXCENVptr env, CPXLPptr lp, CPXDIM numcols,
               CPXDIM numrows, int objsense, double const *objective,
               double const *rhs, char const *sense,
               CPXNNZ const *matbeg, CPXDIM const *matcnt,
               CPXDIM const *matind, double const *matval,
               double const *lb, double const *ub,
               double const *rngval)
{
   return CPX_CALL (copylp) (env, lp, numcols, numrows, objsense, objective, rhs, sense, matbeg, matcnt, matind, matval, lb, ub, rngval);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXcopylpwnames (CPXCENVptr env, CPXLPptr lp, CPXDIM numcols,
                     CPXDIM numrows, int objsense,
                     double const *objective, double const *rhs,
                     char const *sense, CPXNNZ const *matbeg,
                     CPXDIM const *matcnt, CPXDIM const *matind,
                     double const *matval, double const *lb,
                     double const *ub, double const *rngval,
                     char const *const *colname,
                     char const *const *rowname)
{
   return CPX_CALL (copylpwnames) (env, lp, numcols, numrows, objsense, objective, rhs, sense, matbeg, matcnt, matind, matval, lb, ub, rngval, colname, rowname);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXcopynettolp (CPXCENVptr env, CPXLPptr lp, CPXCNETptr net)
{
   return CPX_CALL (copynettolp) (env, lp, net);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXcopyobjname (CPXCENVptr env, CPXLPptr lp,
                    char const *objname_str)
{
   return CPX_CALL (copyobjname) (env, lp, objname_str);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXcopypartialbase (CPXCENVptr env, CPXLPptr lp, CPXDIM ccnt,
                        CPXDIM const *cindices, int const *cstat,
                        CPXDIM rcnt, CPXDIM const *rindices,
                        int const *rstat)
{
   return CPX_CALL (copypartialbase) (env, lp, ccnt, cindices, cstat, rcnt, rindices, rstat);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXcopypnorms (CPXCENVptr env, CPXLPptr lp, double const *cnorm,
                   double const *rnorm, CPXDIM len)
{
   return CPX_CALL (copypnorms) (env, lp, cnorm, rnorm, len);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXcopyprotected (CPXCENVptr env, CPXLPptr lp, CPXDIM cnt,
                      CPXDIM const *indices)
{
   return CPX_CALL (copyprotected) (env, lp, cnt, indices);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXcopystart (CPXCENVptr env, CPXLPptr lp, int const *cstat,
                  int const *rstat, double const *cprim,
                  double const *rprim, double const *cdual,
                  double const *rdual)
{
   return CPX_CALL (copystart) (env, lp, cstat, rstat, cprim, rprim, cdual, rdual);
}


CPX_STATIC_INLINE
CPXLPptr CPXPUBLIC
   CPXXcreateprob (CPXCENVptr env, int *status_p,
                   char const *probname_str)
{
   return CPX_CALL (createprob) (env, status_p, probname_str);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXcrushform (CPXCENVptr env, CPXCLPptr lp, CPXDIM len,
                  CPXDIM const *ind, double const *val, CPXDIM *plen_p,
                  double *poffset_p, CPXDIM *pind, double *pval)
{
   return CPX_CALL (crushform) (env, lp, len, ind, val, plen_p, poffset_p, pind, pval);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXcrushpi (CPXCENVptr env, CPXCLPptr lp, double const *pi,
                double *prepi)
{
   return CPX_CALL (crushpi) (env, lp, pi, prepi);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXcrushx (CPXCENVptr env, CPXCLPptr lp, double const *x,
               double *prex)
{
   return CPX_CALL (crushx) (env, lp, x, prex);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXdelcols (CPXCENVptr env, CPXLPptr lp, CPXDIM begin, CPXDIM end)
{
   return CPX_CALL (delcols) (env, lp, begin, end);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXdeldblannotation (CPXCENVptr env, CPXLPptr lp, CPXDIM idx)
{
   return CPX_CALL (deldblannotation) (env, lp, idx);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXdeldblannotations (CPXCENVptr env, CPXLPptr lp, CPXDIM begin,
                          CPXDIM end)
{
   return CPX_CALL (deldblannotations) (env, lp, begin, end);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXdelfpdest (CPXCENVptr env, CPXCHANNELptr channel,
                  CPXFILEptr fileptr)
{
   return CPX_CALL (delfpdest) (env, channel, fileptr);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXdelfuncdest (CPXCENVptr env, CPXCHANNELptr channel,
                    void *handle,
                    void (CPXPUBLIC *msgfunction)(void *, char const *))
{
   return CPX_CALL (delfuncdest) (env, channel, handle, msgfunction);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXdellongannotation (CPXCENVptr env, CPXLPptr lp, CPXDIM idx)
{
   return CPX_CALL (dellongannotation) (env, lp, idx);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXdellongannotations (CPXCENVptr env, CPXLPptr lp, CPXDIM begin,
                           CPXDIM end)
{
   return CPX_CALL (dellongannotations) (env, lp, begin, end);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXdelnames (CPXCENVptr env, CPXLPptr lp)
{
   return CPX_CALL (delnames) (env, lp);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXdelpwl (CPXCENVptr env, CPXLPptr lp, CPXDIM begin, CPXDIM end)
{
   return CPX_CALL (delpwl) (env, lp, begin, end);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXdelrows (CPXCENVptr env, CPXLPptr lp, CPXDIM begin, CPXDIM end)
{
   return CPX_CALL (delrows) (env, lp, begin, end);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXdelsetcols (CPXCENVptr env, CPXLPptr lp, CPXDIM *delstat)
{
   return CPX_CALL (delsetcols) (env, lp, delstat);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXdelsetpwl (CPXCENVptr env, CPXLPptr lp, CPXDIM *delstat)
{
   return CPX_CALL (delsetpwl) (env, lp, delstat);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXdelsetrows (CPXCENVptr env, CPXLPptr lp, CPXDIM *delstat)
{
   return CPX_CALL (delsetrows) (env, lp, delstat);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXdeserializercreate (CPXDESERIALIZERptr *deser_p, CPXLONG size,
                           void const *buffer)
{
   return CPX_CALL (deserializercreate) (deser_p, size, buffer);
}


CPX_STATIC_INLINE
void CPXPUBLIC
   CPXXdeserializerdestroy (CPXDESERIALIZERptr deser)
{
CPX_CALL (deserializerdestroy) (deser);
}


CPX_STATIC_INLINE
CPXLONG CPXPUBLIC
   CPXXdeserializerleft (CPXCDESERIALIZERptr deser)
{
   return CPX_CALL (deserializerleft) (deser);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXdisconnectchannel (CPXCENVptr env, CPXCHANNELptr channel)
{
   return CPX_CALL (disconnectchannel) (env, channel);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXdjfrompi (CPXCENVptr env, CPXCLPptr lp, double const *pi,
                 double *dj)
{
   return CPX_CALL (djfrompi) (env, lp, pi, dj);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXdperwrite (CPXCENVptr env, CPXLPptr lp,
                  char const *filename_str, double epsilon)
{
   return CPX_CALL (dperwrite) (env, lp, filename_str, epsilon);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXdratio (CPXCENVptr env, CPXLPptr lp, CPXDIM *indices,
               CPXDIM cnt, double *downratio, double *upratio,
               CPXDIM *downenter, CPXDIM *upenter, int *downstatus,
               int *upstatus)
{
   return CPX_CALL (dratio) (env, lp, indices, cnt, downratio, upratio, downenter, upenter, downstatus, upstatus);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXdualfarkas (CPXCENVptr env, CPXCLPptr lp, double *y,
                   double *proof_p)
{
   return CPX_CALL (dualfarkas) (env, lp, y, proof_p);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXdualopt (CPXCENVptr env, CPXLPptr lp)
{
   return CPX_CALL (dualopt) (env, lp);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXdualwrite (CPXCENVptr env, CPXCLPptr lp,
                  char const *filename_str, double *objshift_p)
{
   return CPX_CALL (dualwrite) (env, lp, filename_str, objshift_p);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXembwrite (CPXCENVptr env, CPXLPptr lp, char const *filename_str)
{
   return CPX_CALL (embwrite) (env, lp, filename_str);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXfclose (CPXFILEptr stream)
{
   return CPX_CALL (fclose) (stream);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXfeasopt (CPXCENVptr env, CPXLPptr lp, double const *rhs,
                double const *rng, double const *lb, double const *ub)
{
   return CPX_CALL (feasopt) (env, lp, rhs, rng, lb, ub);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXfeasoptext (CPXCENVptr env, CPXLPptr lp, CPXDIM grpcnt,
                   CPXNNZ concnt, double const *grppref,
                   CPXNNZ const *grpbeg, CPXDIM const *grpind,
                   char const *grptype)
{
   return CPX_CALL (feasoptext) (env, lp, grpcnt, concnt, grppref, grpbeg, grpind, grptype);
}


CPX_STATIC_INLINE
void CPXPUBLIC
   CPXXfinalize (void)
{
CPX_CALL (finalize) ();
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXflushchannel (CPXCENVptr env, CPXCHANNELptr channel)
{
   return CPX_CALL (flushchannel) (env, channel);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXflushstdchannels (CPXCENVptr env)
{
   return CPX_CALL (flushstdchannels) (env);
}


CPX_STATIC_INLINE
CPXFILEptr CPXPUBLIC
   CPXXfopen (char const *filename_str, char const *type_str)
{
   return CPX_CALL (fopen) (filename_str, type_str);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXfputs (char const *s_str, CPXFILEptr stream)
{
   return CPX_CALL (fputs) (s_str, stream);
}


CPX_STATIC_INLINE CPXDEPRECATED(12700100)
int CPXPUBLIC
   CPXXfreeparenv (CPXENVptr env, CPXENVptr *child_p)
{
   return CPX_CALL (freeparenv) (env, child_p);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXfreepresolve (CPXCENVptr env, CPXLPptr lp)
{
   return CPX_CALL (freepresolve) (env, lp);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXfreeprob (CPXCENVptr env, CPXLPptr *lp_p)
{
   return CPX_CALL (freeprob) (env, lp_p);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXftran (CPXCENVptr env, CPXCLPptr lp, double *x)
{
   return CPX_CALL (ftran) (env, lp, x);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetax (CPXCENVptr env, CPXCLPptr lp, double *x, CPXDIM begin,
              CPXDIM end)
{
   return CPX_CALL (getax) (env, lp, x, begin, end);
}


CPX_STATIC_INLINE
CPXCNT CPXPUBLIC
   CPXXgetbaritcnt (CPXCENVptr env, CPXCLPptr lp)
{
   return CPX_CALL (getbaritcnt) (env, lp);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetbase (CPXCENVptr env, CPXCLPptr lp, int *cstat, int *rstat)
{
   return CPX_CALL (getbase) (env, lp, cstat, rstat);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetbasednorms (CPXCENVptr env, CPXCLPptr lp, int *cstat,
                      int *rstat, double *dnorm)
{
   return CPX_CALL (getbasednorms) (env, lp, cstat, rstat, dnorm);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetbhead (CPXCENVptr env, CPXCLPptr lp, CPXDIM *head, double *x)
{
   return CPX_CALL (getbhead) (env, lp, head, x);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetcallbackinfo (CPXCENVptr env, void *cbdata, int wherefrom,
                        int whichinfo, void *result_p)
{
   return CPX_CALL (getcallbackinfo) (env, cbdata, wherefrom, whichinfo, result_p);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetchannels (CPXCENVptr env, CPXCHANNELptr *cpxresults_p,
                    CPXCHANNELptr *cpxwarning_p,
                    CPXCHANNELptr *cpxerror_p, CPXCHANNELptr *cpxlog_p)
{
   return CPX_CALL (getchannels) (env, cpxresults_p, cpxwarning_p, cpxerror_p, cpxlog_p);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetchgparam (CPXCENVptr env, int *cnt_p, int *paramnum,
                    int pspace, int *surplus_p)
{
   return CPX_CALL (getchgparam) (env, cnt_p, paramnum, pspace, surplus_p);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetcoef (CPXCENVptr env, CPXCLPptr lp, CPXDIM i, CPXDIM j,
                double *coef_p)
{
   return CPX_CALL (getcoef) (env, lp, i, j, coef_p);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetcolindex (CPXCENVptr env, CPXCLPptr lp,
                    char const *lname_str, CPXDIM *index_p)
{
   return CPX_CALL (getcolindex) (env, lp, lname_str, index_p);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetcolinfeas (CPXCENVptr env, CPXCLPptr lp, double const *x,
                     double *infeasout, CPXDIM begin, CPXDIM end)
{
   return CPX_CALL (getcolinfeas) (env, lp, x, infeasout, begin, end);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetcolname (CPXCENVptr env, CPXCLPptr lp, char  **name,
                   char *namestore, CPXSIZE storespace,
                   CPXSIZE *surplus_p, CPXDIM begin, CPXDIM end)
{
   return CPX_CALL (getcolname) (env, lp, name, namestore, storespace, surplus_p, begin, end);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetcols (CPXCENVptr env, CPXCLPptr lp, CPXNNZ *nzcnt_p,
                CPXNNZ *cmatbeg, CPXDIM *cmatind, double *cmatval,
                CPXNNZ cmatspace, CPXNNZ *surplus_p, CPXDIM begin,
                CPXDIM end)
{
   return CPX_CALL (getcols) (env, lp, nzcnt_p, cmatbeg, cmatind, cmatval, cmatspace, surplus_p, begin, end);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetconflict (CPXCENVptr env, CPXCLPptr lp, int *confstat_p,
                    CPXDIM *rowind, int *rowbdstat,
                    CPXDIM *confnumrows_p, CPXDIM *colind,
                    int *colbdstat, CPXDIM *confnumcols_p)
{
   return CPX_CALL (getconflict) (env, lp, confstat_p, rowind, rowbdstat, confnumrows_p, colind, colbdstat, confnumcols_p);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetconflictext (CPXCENVptr env, CPXCLPptr lp, int *grpstat,
                       CPXNNZ beg, CPXNNZ end)
{
   return CPX_CALL (getconflictext) (env, lp, grpstat, beg, end);
}


CPX_STATIC_INLINE
CPXCNT CPXPUBLIC
   CPXXgetcrossdexchcnt (CPXCENVptr env, CPXCLPptr lp)
{
   return CPX_CALL (getcrossdexchcnt) (env, lp);
}


CPX_STATIC_INLINE
CPXCNT CPXPUBLIC
   CPXXgetcrossdpushcnt (CPXCENVptr env, CPXCLPptr lp)
{
   return CPX_CALL (getcrossdpushcnt) (env, lp);
}


CPX_STATIC_INLINE
CPXCNT CPXPUBLIC
   CPXXgetcrosspexchcnt (CPXCENVptr env, CPXCLPptr lp)
{
   return CPX_CALL (getcrosspexchcnt) (env, lp);
}


CPX_STATIC_INLINE
CPXCNT CPXPUBLIC
   CPXXgetcrossppushcnt (CPXCENVptr env, CPXCLPptr lp)
{
   return CPX_CALL (getcrossppushcnt) (env, lp);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetdblannotationdefval (CPXCENVptr env, CPXCLPptr lp,
                               CPXDIM idx, double *defval_p)
{
   return CPX_CALL (getdblannotationdefval) (env, lp, idx, defval_p);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetdblannotationindex (CPXCENVptr env, CPXCLPptr lp,
                              char const *annotationname_str,
                              CPXDIM *index_p)
{
   return CPX_CALL (getdblannotationindex) (env, lp, annotationname_str, index_p);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetdblannotationname (CPXCENVptr env, CPXCLPptr lp, CPXDIM idx,
                             char *buf_str, CPXSIZE bufspace,
                             CPXSIZE *surplus_p)
{
   return CPX_CALL (getdblannotationname) (env, lp, idx, buf_str, bufspace, surplus_p);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetdblannotations (CPXCENVptr env, CPXCLPptr lp, CPXDIM idx,
                          int objtype, double *annotation,
                          CPXDIM begin, CPXDIM end)
{
   return CPX_CALL (getdblannotations) (env, lp, idx, objtype, annotation, begin, end);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetdblparam (CPXCENVptr env, int whichparam, double *value_p)
{
   return CPX_CALL (getdblparam) (env, whichparam, value_p);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetdblquality (CPXCENVptr env, CPXCLPptr lp, double *quality_p,
                      int what)
{
   return CPX_CALL (getdblquality) (env, lp, quality_p, what);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetdettime (CPXCENVptr env, double *dettimestamp_p)
{
   return CPX_CALL (getdettime) (env, dettimestamp_p);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetdj (CPXCENVptr env, CPXCLPptr lp, double *dj, CPXDIM begin,
              CPXDIM end)
{
   return CPX_CALL (getdj) (env, lp, dj, begin, end);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetdnorms (CPXCENVptr env, CPXCLPptr lp, double *norm,
                  CPXDIM *head, CPXDIM *len_p)
{
   return CPX_CALL (getdnorms) (env, lp, norm, head, len_p);
}


CPX_STATIC_INLINE
CPXDIM CPXPUBLIC
   CPXXgetdsbcnt (CPXCENVptr env, CPXCLPptr lp)
{
   return CPX_CALL (getdsbcnt) (env, lp);
}


CPX_STATIC_INLINE
CPXCCHARptr CPXPUBLIC
   CPXXgeterrorstring (CPXCENVptr env, int errcode, char *buffer_str)
{
   return CPX_CALL (geterrorstring) (env, errcode, buffer_str);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetgrad (CPXCENVptr env, CPXCLPptr lp, CPXDIM j, CPXDIM *head,
                double *y)
{
   return CPX_CALL (getgrad) (env, lp, j, head, y);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetijdiv (CPXCENVptr env, CPXCLPptr lp, CPXDIM *idiv_p,
                 CPXDIM *jdiv_p)
{
   return CPX_CALL (getijdiv) (env, lp, idiv_p, jdiv_p);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetijrow (CPXCENVptr env, CPXCLPptr lp, CPXDIM i, CPXDIM j,
                 CPXDIM *row_p)
{
   return CPX_CALL (getijrow) (env, lp, i, j, row_p);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetintparam (CPXCENVptr env, int whichparam, CPXINT *value_p)
{
   return CPX_CALL (getintparam) (env, whichparam, value_p);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetintquality (CPXCENVptr env, CPXCLPptr lp, CPXDIM *quality_p,
                      int what)
{
   return CPX_CALL (getintquality) (env, lp, quality_p, what);
}


CPX_STATIC_INLINE
CPXCNT CPXPUBLIC
   CPXXgetitcnt (CPXCENVptr env, CPXCLPptr lp)
{
   return CPX_CALL (getitcnt) (env, lp);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetlb (CPXCENVptr env, CPXCLPptr lp, double *lb, CPXDIM begin,
              CPXDIM end)
{
   return CPX_CALL (getlb) (env, lp, lb, begin, end);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetlogfile (CPXCENVptr env, CPXFILEptr *logfile_p)
{
   return CPX_CALL (getlogfile) (env, logfile_p);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetlongannotationdefval (CPXCENVptr env, CPXCLPptr lp,
                                CPXDIM idx, CPXLONG *defval_p)
{
   return CPX_CALL (getlongannotationdefval) (env, lp, idx, defval_p);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetlongannotationindex (CPXCENVptr env, CPXCLPptr lp,
                               char const *annotationname_str,
                               CPXDIM *index_p)
{
   return CPX_CALL (getlongannotationindex) (env, lp, annotationname_str, index_p);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetlongannotationname (CPXCENVptr env, CPXCLPptr lp, CPXDIM idx,
                              char *buf_str, CPXSIZE bufspace,
                              CPXSIZE *surplus_p)
{
   return CPX_CALL (getlongannotationname) (env, lp, idx, buf_str, bufspace, surplus_p);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetlongannotations (CPXCENVptr env, CPXCLPptr lp, CPXDIM idx,
                           int objtype, CPXLONG *annotation,
                           CPXDIM begin, CPXDIM end)
{
   return CPX_CALL (getlongannotations) (env, lp, idx, objtype, annotation, begin, end);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetlongparam (CPXCENVptr env, int whichparam, CPXLONG *value_p)
{
   return CPX_CALL (getlongparam) (env, whichparam, value_p);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetlpcallbackfunc (CPXCENVptr env, CPXX_CALLBACK **callback_p,
                          void  **cbhandle_p)
{
   return CPX_CALL (getlpcallbackfunc) (env, callback_p, cbhandle_p);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetmethod (CPXCENVptr env, CPXCLPptr lp)
{
   return CPX_CALL (getmethod) (env, lp);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetnetcallbackfunc (CPXCENVptr env, CPXX_CALLBACK **callback_p,
                           void  **cbhandle_p)
{
   return CPX_CALL (getnetcallbackfunc) (env, callback_p, cbhandle_p);
}


CPX_STATIC_INLINE
CPXDIM CPXPUBLIC
   CPXXgetnumcols (CPXCENVptr env, CPXCLPptr lp)
{
   return CPX_CALL (getnumcols) (env, lp);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetnumcores (CPXCENVptr env, int *numcores_p)
{
   return CPX_CALL (getnumcores) (env, numcores_p);
}


CPX_STATIC_INLINE
CPXDIM CPXPUBLIC
   CPXXgetnumdblannotations (CPXCENVptr env, CPXCLPptr lp)
{
   return CPX_CALL (getnumdblannotations) (env, lp);
}


CPX_STATIC_INLINE
CPXDIM CPXPUBLIC
   CPXXgetnumlongannotations (CPXCENVptr env, CPXCLPptr lp)
{
   return CPX_CALL (getnumlongannotations) (env, lp);
}


CPX_STATIC_INLINE
CPXNNZ CPXPUBLIC
   CPXXgetnumnz (CPXCENVptr env, CPXCLPptr lp)
{
   return CPX_CALL (getnumnz) (env, lp);
}


CPX_STATIC_INLINE
CPXDIM CPXPUBLIC
   CPXXgetnumpwl (CPXCENVptr env, CPXCLPptr lp)
{
   return CPX_CALL (getnumpwl) (env, lp);
}


CPX_STATIC_INLINE
CPXDIM CPXPUBLIC
   CPXXgetnumrows (CPXCENVptr env, CPXCLPptr lp)
{
   return CPX_CALL (getnumrows) (env, lp);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetobj (CPXCENVptr env, CPXCLPptr lp, double *obj, CPXDIM begin,
               CPXDIM end)
{
   return CPX_CALL (getobj) (env, lp, obj, begin, end);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetobjname (CPXCENVptr env, CPXCLPptr lp, char *buf_str,
                   CPXSIZE bufspace, CPXSIZE *surplus_p)
{
   return CPX_CALL (getobjname) (env, lp, buf_str, bufspace, surplus_p);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetobjoffset (CPXCENVptr env, CPXCLPptr lp, double *objoffset_p)
{
   return CPX_CALL (getobjoffset) (env, lp, objoffset_p);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetobjsen (CPXCENVptr env, CPXCLPptr lp)
{
   return CPX_CALL (getobjsen) (env, lp);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetobjval (CPXCENVptr env, CPXCLPptr lp, double *objval_p)
{
   return CPX_CALL (getobjval) (env, lp, objval_p);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetparamname (CPXCENVptr env, int whichparam, char *name_str)
{
   return CPX_CALL (getparamname) (env, whichparam, name_str);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetparamnum (CPXCENVptr env, char const *name_str,
                    int *whichparam_p)
{
   return CPX_CALL (getparamnum) (env, name_str, whichparam_p);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetparamtype (CPXCENVptr env, int whichparam, int *paramtype)
{
   return CPX_CALL (getparamtype) (env, whichparam, paramtype);
}


CPX_STATIC_INLINE
CPXCNT CPXPUBLIC
   CPXXgetphase1cnt (CPXCENVptr env, CPXCLPptr lp)
{
   return CPX_CALL (getphase1cnt) (env, lp);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetpi (CPXCENVptr env, CPXCLPptr lp, double *pi, CPXDIM begin,
              CPXDIM end)
{
   return CPX_CALL (getpi) (env, lp, pi, begin, end);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetpnorms (CPXCENVptr env, CPXCLPptr lp, double *cnorm,
                  double *rnorm, CPXDIM *len_p)
{
   return CPX_CALL (getpnorms) (env, lp, cnorm, rnorm, len_p);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetprestat (CPXCENVptr env, CPXCLPptr lp, int *prestat_p,
                   CPXDIM *pcstat, CPXDIM *prstat, CPXDIM *ocstat,
                   CPXDIM *orstat)
{
   return CPX_CALL (getprestat) (env, lp, prestat_p, pcstat, prstat, ocstat, orstat);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetprobname (CPXCENVptr env, CPXCLPptr lp, char *buf_str,
                    CPXSIZE bufspace, CPXSIZE *surplus_p)
{
   return CPX_CALL (getprobname) (env, lp, buf_str, bufspace, surplus_p);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetprobtype (CPXCENVptr env, CPXCLPptr lp)
{
   return CPX_CALL (getprobtype) (env, lp);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetprotected (CPXCENVptr env, CPXCLPptr lp, CPXDIM *cnt_p,
                     CPXDIM *indices, CPXDIM pspace, CPXDIM *surplus_p)
{
   return CPX_CALL (getprotected) (env, lp, cnt_p, indices, pspace, surplus_p);
}


CPX_STATIC_INLINE
CPXDIM CPXPUBLIC
   CPXXgetpsbcnt (CPXCENVptr env, CPXCLPptr lp)
{
   return CPX_CALL (getpsbcnt) (env, lp);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetpwl (CPXCENVptr env, CPXCLPptr lp, CPXDIM pwlindex,
               CPXDIM *vary_p, CPXDIM *varx_p, double *preslope_p,
               double *postslope_p, CPXDIM *nbreaks_p, double *breakx,
               double *breaky, CPXDIM breakspace, CPXDIM *surplus_p)
{
   return CPX_CALL (getpwl) (env, lp, pwlindex, vary_p, varx_p, preslope_p, postslope_p, nbreaks_p, breakx, breaky, breakspace, surplus_p);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetpwlindex (CPXCENVptr env, CPXCLPptr lp,
                    char const *lname_str, CPXDIM *index_p)
{
   return CPX_CALL (getpwlindex) (env, lp, lname_str, index_p);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetpwlname (CPXCENVptr env, CPXCLPptr lp, char *buf_str,
                   CPXSIZE bufspace, CPXSIZE *surplus_p, CPXDIM which)
{
   return CPX_CALL (getpwlname) (env, lp, buf_str, bufspace, surplus_p, which);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetray (CPXCENVptr env, CPXCLPptr lp, double *z)
{
   return CPX_CALL (getray) (env, lp, z);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetredlp (CPXCENVptr env, CPXCLPptr lp, CPXCLPptr *redlp_p)
{
   return CPX_CALL (getredlp) (env, lp, redlp_p);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetrhs (CPXCENVptr env, CPXCLPptr lp, double *rhs, CPXDIM begin,
               CPXDIM end)
{
   return CPX_CALL (getrhs) (env, lp, rhs, begin, end);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetrngval (CPXCENVptr env, CPXCLPptr lp, double *rngval,
                  CPXDIM begin, CPXDIM end)
{
   return CPX_CALL (getrngval) (env, lp, rngval, begin, end);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetrowindex (CPXCENVptr env, CPXCLPptr lp,
                    char const *lname_str, CPXDIM *index_p)
{
   return CPX_CALL (getrowindex) (env, lp, lname_str, index_p);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetrowinfeas (CPXCENVptr env, CPXCLPptr lp, double const *x,
                     double *infeasout, CPXDIM begin, CPXDIM end)
{
   return CPX_CALL (getrowinfeas) (env, lp, x, infeasout, begin, end);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetrowname (CPXCENVptr env, CPXCLPptr lp, char  **name,
                   char *namestore, CPXSIZE storespace,
                   CPXSIZE *surplus_p, CPXDIM begin, CPXDIM end)
{
   return CPX_CALL (getrowname) (env, lp, name, namestore, storespace, surplus_p, begin, end);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetrows (CPXCENVptr env, CPXCLPptr lp, CPXNNZ *nzcnt_p,
                CPXNNZ *rmatbeg, CPXDIM *rmatind, double *rmatval,
                CPXNNZ rmatspace, CPXNNZ *surplus_p, CPXDIM begin,
                CPXDIM end)
{
   return CPX_CALL (getrows) (env, lp, nzcnt_p, rmatbeg, rmatind, rmatval, rmatspace, surplus_p, begin, end);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetsense (CPXCENVptr env, CPXCLPptr lp, char *sense,
                 CPXDIM begin, CPXDIM end)
{
   return CPX_CALL (getsense) (env, lp, sense, begin, end);
}


CPX_STATIC_INLINE
CPXCNT CPXPUBLIC
   CPXXgetsiftitcnt (CPXCENVptr env, CPXCLPptr lp)
{
   return CPX_CALL (getsiftitcnt) (env, lp);
}


CPX_STATIC_INLINE
CPXCNT CPXPUBLIC
   CPXXgetsiftphase1cnt (CPXCENVptr env, CPXCLPptr lp)
{
   return CPX_CALL (getsiftphase1cnt) (env, lp);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetslack (CPXCENVptr env, CPXCLPptr lp, double *slack,
                 CPXDIM begin, CPXDIM end)
{
   return CPX_CALL (getslack) (env, lp, slack, begin, end);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetsolnpooldblquality (CPXCENVptr env, CPXCLPptr lp, int soln,
                              double *quality_p, int what)
{
   return CPX_CALL (getsolnpooldblquality) (env, lp, soln, quality_p, what);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetsolnpoolintquality (CPXCENVptr env, CPXCLPptr lp, int soln,
                              CPXDIM *quality_p, int what)
{
   return CPX_CALL (getsolnpoolintquality) (env, lp, soln, quality_p, what);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetstat (CPXCENVptr env, CPXCLPptr lp)
{
   return CPX_CALL (getstat) (env, lp);
}


CPX_STATIC_INLINE
CPXCHARptr CPXPUBLIC
   CPXXgetstatstring (CPXCENVptr env, int statind, char *buffer_str)
{
   return CPX_CALL (getstatstring) (env, statind, buffer_str);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetstrparam (CPXCENVptr env, int whichparam, char *value_str)
{
   return CPX_CALL (getstrparam) (env, whichparam, value_str);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgettime (CPXCENVptr env, double *timestamp_p)
{
   return CPX_CALL (gettime) (env, timestamp_p);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgettuningcallbackfunc (CPXCENVptr env,
                              CPXX_CALLBACK **callback_p,
                              void  **cbhandle_p)
{
   return CPX_CALL (gettuningcallbackfunc) (env, callback_p, cbhandle_p);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetub (CPXCENVptr env, CPXCLPptr lp, double *ub, CPXDIM begin,
              CPXDIM end)
{
   return CPX_CALL (getub) (env, lp, ub, begin, end);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetweight (CPXCENVptr env, CPXCLPptr lp, CPXDIM rcnt,
                  CPXNNZ const *rmatbeg, CPXDIM const *rmatind,
                  double const *rmatval, double *weight, int dpriind)
{
   return CPX_CALL (getweight) (env, lp, rcnt, rmatbeg, rmatind, rmatval, weight, dpriind);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetx (CPXCENVptr env, CPXCLPptr lp, double *x, CPXDIM begin,
             CPXDIM end)
{
   return CPX_CALL (getx) (env, lp, x, begin, end);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXhybnetopt (CPXCENVptr env, CPXLPptr lp, int method)
{
   return CPX_CALL (hybnetopt) (env, lp, method);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXinfodblparam (CPXCENVptr env, int whichparam,
                     double *defvalue_p, double *minvalue_p,
                     double *maxvalue_p)
{
   return CPX_CALL (infodblparam) (env, whichparam, defvalue_p, minvalue_p, maxvalue_p);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXinfointparam (CPXCENVptr env, int whichparam,
                     CPXINT *defvalue_p, CPXINT *minvalue_p,
                     CPXINT *maxvalue_p)
{
   return CPX_CALL (infointparam) (env, whichparam, defvalue_p, minvalue_p, maxvalue_p);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXinfolongparam (CPXCENVptr env, int whichparam,
                      CPXLONG *defvalue_p, CPXLONG *minvalue_p,
                      CPXLONG *maxvalue_p)
{
   return CPX_CALL (infolongparam) (env, whichparam, defvalue_p, minvalue_p, maxvalue_p);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXinfostrparam (CPXCENVptr env, int whichparam,
                     char *defvalue_str)
{
   return CPX_CALL (infostrparam) (env, whichparam, defvalue_str);
}


CPX_STATIC_INLINE
void CPXPUBLIC
   CPXXinitialize (void)
{
CPX_CALL (initialize) ();
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXkilldnorms (CPXLPptr lp)
{
   return CPX_CALL (killdnorms) (lp);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXkillpnorms (CPXLPptr lp)
{
   return CPX_CALL (killpnorms) (lp);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXlpopt (CPXCENVptr env, CPXLPptr lp)
{
   return CPX_CALL (lpopt) (env, lp);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXlprewrite (CPXCENVptr env, CPXCLPptr lp,
                  char const *filename_str)
{
   return CPX_CALL (lprewrite) (env, lp, filename_str);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXlpwrite (CPXCENVptr env, CPXCLPptr lp, char const *filename_str)
{
   return CPX_CALL (lpwrite) (env, lp, filename_str);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXmbasewrite (CPXCENVptr env, CPXCLPptr lp,
                   char const *filename_str)
{
   return CPX_CALL (mbasewrite) (env, lp, filename_str);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXmdleave (CPXCENVptr env, CPXLPptr lp, CPXDIM const *indices,
                CPXDIM cnt, double *downratio, double *upratio)
{
   return CPX_CALL (mdleave) (env, lp, indices, cnt, downratio, upratio);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXmpsrewrite (CPXCENVptr env, CPXCLPptr lp,
                   char const *filename_str)
{
   return CPX_CALL (mpsrewrite) (env, lp, filename_str);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXmpswrite (CPXCENVptr env, CPXCLPptr lp,
                 char const *filename_str)
{
   return CPX_CALL (mpswrite) (env, lp, filename_str);
}


#if CPX_APIMODEL == CPX_APIMODEL_SMALL
#      define CPXXmsg CPXSmsg
#elif CPX_APIMODEL == CPX_APIMODEL_LARGE
#      define CPXXmsg CPXLmsg
#endif

CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXmsgstr (CPXCHANNELptr channel, char const *msg_str)
{
   return CPX_CALL (msgstr) (channel, msg_str);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXNETextract (CPXCENVptr env, CPXNETptr net, CPXCLPptr lp,
                   CPXDIM *colmap, CPXDIM *rowmap)
{
   return CPX_CALL (NETextract) (env, net, lp, colmap, rowmap);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXnewcols (CPXCENVptr env, CPXLPptr lp, CPXDIM ccnt,
                double const *obj, double const *lb, double const *ub,
                char const *xctype, char const *const *colname)
{
   return CPX_CALL (newcols) (env, lp, ccnt, obj, lb, ub, xctype, colname);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXnewdblannotation (CPXCENVptr env, CPXLPptr lp,
                         char const *annotationname_str, double defval)
{
   return CPX_CALL (newdblannotation) (env, lp, annotationname_str, defval);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXnewlongannotation (CPXCENVptr env, CPXLPptr lp,
                          char const *annotationname_str,
                          CPXLONG defval)
{
   return CPX_CALL (newlongannotation) (env, lp, annotationname_str, defval);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXnewrows (CPXCENVptr env, CPXLPptr lp, CPXDIM rcnt,
                double const *rhs, char const *sense,
                double const *rngval, char const *const *rowname)
{
   return CPX_CALL (newrows) (env, lp, rcnt, rhs, sense, rngval, rowname);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXobjsa (CPXCENVptr env, CPXCLPptr lp, CPXDIM begin, CPXDIM end,
              double *lower, double *upper)
{
   return CPX_CALL (objsa) (env, lp, begin, end, lower, upper);
}


CPX_STATIC_INLINE
CPXENVptr CPXPUBLIC
   CPXXopenCPLEX (int *status_p)
{
   return CPX_CALL (openCPLEX) (status_p);
}


CPX_STATIC_INLINE
CPXENVptr CPXPUBLIC
   CPXXopenCPLEXruntime (int *status_p, int serialnum,
                         char const *licenvstring_str)
{
   return CPX_CALL (openCPLEXruntime) (status_p, serialnum, licenvstring_str);
}


CPX_STATIC_INLINE CPXDEPRECATED(12700100)
CPXENVptr CPXPUBLIC
   CPXXparenv (CPXENVptr env, int *status_p)
{
   return CPX_CALL (parenv) (env, status_p);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXpivot (CPXCENVptr env, CPXLPptr lp, CPXDIM jenter,
              CPXDIM jleave, int leavestat)
{
   return CPX_CALL (pivot) (env, lp, jenter, jleave, leavestat);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXpivotin (CPXCENVptr env, CPXLPptr lp, CPXDIM const *rlist,
                CPXDIM rlen)
{
   return CPX_CALL (pivotin) (env, lp, rlist, rlen);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXpivotout (CPXCENVptr env, CPXLPptr lp, CPXDIM const *clist,
                 CPXDIM clen)
{
   return CPX_CALL (pivotout) (env, lp, clist, clen);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXpperwrite (CPXCENVptr env, CPXLPptr lp,
                  char const *filename_str, double epsilon)
{
   return CPX_CALL (pperwrite) (env, lp, filename_str, epsilon);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXpratio (CPXCENVptr env, CPXLPptr lp, CPXDIM *indices,
               CPXDIM cnt, double *downratio, double *upratio,
               CPXDIM *downleave, CPXDIM *upleave,
               int *downleavestatus, int *upleavestatus,
               int *downstatus, int *upstatus)
{
   return CPX_CALL (pratio) (env, lp, indices, cnt, downratio, upratio, downleave, upleave, downleavestatus, upleavestatus, downstatus, upstatus);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXpreaddrows (CPXCENVptr env, CPXLPptr lp, CPXDIM rcnt,
                   CPXNNZ nzcnt, double const *rhs, char const *sense,
                   CPXNNZ const *rmatbeg, CPXDIM const *rmatind,
                   double const *rmatval, char const *const *rowname)
{
   return CPX_CALL (preaddrows) (env, lp, rcnt, nzcnt, rhs, sense, rmatbeg, rmatind, rmatval, rowname);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXprechgobj (CPXCENVptr env, CPXLPptr lp, CPXDIM cnt,
                  CPXDIM const *indices, double const *values)
{
   return CPX_CALL (prechgobj) (env, lp, cnt, indices, values);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXpreslvwrite (CPXCENVptr env, CPXLPptr lp,
                    char const *filename_str, double *objoff_p)
{
   return CPX_CALL (preslvwrite) (env, lp, filename_str, objoff_p);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXpresolve (CPXCENVptr env, CPXLPptr lp, int method)
{
   return CPX_CALL (presolve) (env, lp, method);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXprimopt (CPXCENVptr env, CPXLPptr lp)
{
   return CPX_CALL (primopt) (env, lp);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXqpdjfrompi (CPXCENVptr env, CPXCLPptr lp, double const *pi,
                   double const *x, double *dj)
{
   return CPX_CALL (qpdjfrompi) (env, lp, pi, x, dj);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXqpuncrushpi (CPXCENVptr env, CPXCLPptr lp, double *pi,
                    double const *prepi, double const *x)
{
   return CPX_CALL (qpuncrushpi) (env, lp, pi, prepi, x);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXreadcopyannotations (CPXCENVptr env, CPXLPptr lp,
                            char const *filename)
{
   return CPX_CALL (readcopyannotations) (env, lp, filename);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXreadcopybase (CPXCENVptr env, CPXLPptr lp,
                     char const *filename_str)
{
   return CPX_CALL (readcopybase) (env, lp, filename_str);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXreadcopyparam (CPXENVptr env, char const *filename_str)
{
   return CPX_CALL (readcopyparam) (env, filename_str);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXreadcopyprob (CPXCENVptr env, CPXLPptr lp,
                     char const *filename_str,
                     char const *filetype_str)
{
   return CPX_CALL (readcopyprob) (env, lp, filename_str, filetype_str);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXreadcopysol (CPXCENVptr env, CPXLPptr lp,
                    char const *filename_str)
{
   return CPX_CALL (readcopysol) (env, lp, filename_str);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXrefineconflict (CPXCENVptr env, CPXLPptr lp,
                       CPXDIM *confnumrows_p, CPXDIM *confnumcols_p)
{
   return CPX_CALL (refineconflict) (env, lp, confnumrows_p, confnumcols_p);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXrefineconflictext (CPXCENVptr env, CPXLPptr lp, CPXNNZ grpcnt,
                          CPXNNZ concnt, double const *grppref,
                          CPXNNZ const *grpbeg, CPXDIM const *grpind,
                          char const *grptype)
{
   return CPX_CALL (refineconflictext) (env, lp, grpcnt, concnt, grppref, grpbeg, grpind, grptype);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXrhssa (CPXCENVptr env, CPXCLPptr lp, CPXDIM begin, CPXDIM end,
              double *lower, double *upper)
{
   return CPX_CALL (rhssa) (env, lp, begin, end, lower, upper);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXrobustopt (CPXCENVptr env, CPXLPptr lp, CPXLPptr lblp,
                  CPXLPptr ublp, double objchg, double const *maxchg)
{
   return CPX_CALL (robustopt) (env, lp, lblp, ublp, objchg, maxchg);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXsavwrite (CPXCENVptr env, CPXCLPptr lp,
                 char const *filename_str)
{
   return CPX_CALL (savwrite) (env, lp, filename_str);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXserializercreate (CPXSERIALIZERptr *ser_p)
{
   return CPX_CALL (serializercreate) (ser_p);
}


CPX_STATIC_INLINE
void CPXPUBLIC
   CPXXserializerdestroy (CPXSERIALIZERptr ser)
{
CPX_CALL (serializerdestroy) (ser);
}


CPX_STATIC_INLINE
CPXLONG CPXPUBLIC
   CPXXserializerlength (CPXCSERIALIZERptr ser)
{
   return CPX_CALL (serializerlength) (ser);
}


CPX_STATIC_INLINE
void const * CPXPUBLIC
   CPXXserializerpayload (CPXCSERIALIZERptr ser)
{
   return CPX_CALL (serializerpayload) (ser);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXsetdblannotations (CPXCENVptr env, CPXLPptr lp, CPXDIM idx,
                          int objtype, CPXDIM cnt,
                          CPXDIM const *indices, double const *values)
{
   return CPX_CALL (setdblannotations) (env, lp, idx, objtype, cnt, indices, values);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXsetdblparam (CPXENVptr env, int whichparam, double newvalue)
{
   return CPX_CALL (setdblparam) (env, whichparam, newvalue);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXsetdefaults (CPXENVptr env)
{
   return CPX_CALL (setdefaults) (env);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXsetintparam (CPXENVptr env, int whichparam, CPXINT newvalue)
{
   return CPX_CALL (setintparam) (env, whichparam, newvalue);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXsetlogfile (CPXENVptr env, CPXFILEptr lfile)
{
   return CPX_CALL (setlogfile) (env, lfile);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXsetlongannotations (CPXCENVptr env, CPXLPptr lp, CPXDIM idx,
                           int objtype, CPXDIM cnt,
                           CPXDIM const *indices,
                           CPXLONG const *values)
{
   return CPX_CALL (setlongannotations) (env, lp, idx, objtype, cnt, indices, values);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXsetlongparam (CPXENVptr env, int whichparam, CPXLONG newvalue)
{
   return CPX_CALL (setlongparam) (env, whichparam, newvalue);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXsetlpcallbackfunc (CPXENVptr env, CPXX_CALLBACK *callback,
                          void *cbhandle)
{
   return CPX_CALL (setlpcallbackfunc) (env, callback, cbhandle);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXsetnetcallbackfunc (CPXENVptr env, CPXX_CALLBACK *callback,
                           void *cbhandle)
{
   return CPX_CALL (setnetcallbackfunc) (env, callback, cbhandle);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXsetphase2 (CPXCENVptr env, CPXLPptr lp)
{
   return CPX_CALL (setphase2) (env, lp);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXsetprofcallbackfunc (CPXENVptr env,
                            CPXX_CALLBACK_PROF *callback,
                            void *cbhandle)
{
   return CPX_CALL (setprofcallbackfunc) (env, callback, cbhandle);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXsetstrparam (CPXENVptr env, int whichparam,
                    char const *newvalue_str)
{
   return CPX_CALL (setstrparam) (env, whichparam, newvalue_str);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXsetterminate (CPXENVptr env, volatile int *terminate_p)
{
   return CPX_CALL (setterminate) (env, terminate_p);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXsettuningcallbackfunc (CPXENVptr env, CPXX_CALLBACK *callback,
                              void *cbhandle)
{
   return CPX_CALL (settuningcallbackfunc) (env, callback, cbhandle);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXsiftopt (CPXCENVptr env, CPXLPptr lp)
{
   return CPX_CALL (siftopt) (env, lp);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXslackfromx (CPXCENVptr env, CPXCLPptr lp, double const *x,
                   double *slack)
{
   return CPX_CALL (slackfromx) (env, lp, x, slack);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXsolninfo (CPXCENVptr env, CPXCLPptr lp, int *solnmethod_p,
                 int *solntype_p, int *pfeasind_p, int *dfeasind_p)
{
   return CPX_CALL (solninfo) (env, lp, solnmethod_p, solntype_p, pfeasind_p, dfeasind_p);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXsolution (CPXCENVptr env, CPXCLPptr lp, int *lpstat_p,
                 double *objval_p, double *x, double *pi,
                 double *slack, double *dj)
{
   return CPX_CALL (solution) (env, lp, lpstat_p, objval_p, x, pi, slack, dj);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXsolwrite (CPXCENVptr env, CPXCLPptr lp,
                 char const *filename_str)
{
   return CPX_CALL (solwrite) (env, lp, filename_str);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXsolwritesolnpool (CPXCENVptr env, CPXCLPptr lp, int soln,
                         char const *filename_str)
{
   return CPX_CALL (solwritesolnpool) (env, lp, soln, filename_str);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXsolwritesolnpoolall (CPXCENVptr env, CPXCLPptr lp,
                            char const *filename_str)
{
   return CPX_CALL (solwritesolnpoolall) (env, lp, filename_str);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXstrongbranch (CPXCENVptr env, CPXLPptr lp,
                     CPXDIM const *indices, CPXDIM cnt,
                     double *downobj, double *upobj, CPXCNT itlim)
{
   return CPX_CALL (strongbranch) (env, lp, indices, cnt, downobj, upobj, itlim);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXtightenbds (CPXCENVptr env, CPXLPptr lp, CPXDIM cnt,
                   CPXDIM const *indices, char const *lu,
                   double const *bd)
{
   return CPX_CALL (tightenbds) (env, lp, cnt, indices, lu, bd);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXtuneparam (CPXENVptr env, CPXLPptr lp, int intcnt,
                  int const *intnum, int const *intval, int dblcnt,
                  int const *dblnum, double const *dblval, int strcnt,
                  int const *strnum, char const *const *strval,
                  int *tunestat_p)
{
   return CPX_CALL (tuneparam) (env, lp, intcnt, intnum, intval, dblcnt, dblnum, dblval, strcnt, strnum, strval, tunestat_p);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXtuneparamprobset (CPXENVptr env, int filecnt,
                         char const *const *filename,
                         char const *const *filetype, int intcnt,
                         int const *intnum, int const *intval,
                         int dblcnt, int const *dblnum,
                         double const *dblval, int strcnt,
                         int const *strnum, char const *const *strval,
                         int *tunestat_p)
{
   return CPX_CALL (tuneparamprobset) (env, filecnt, filename, filetype, intcnt, intnum, intval, dblcnt, dblnum, dblval, strcnt, strnum, strval, tunestat_p);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXuncrushform (CPXCENVptr env, CPXCLPptr lp, CPXDIM plen,
                    CPXDIM const *pind, double const *pval,
                    CPXDIM *len_p, double *offset_p, CPXDIM *ind,
                    double *val)
{
   return CPX_CALL (uncrushform) (env, lp, plen, pind, pval, len_p, offset_p, ind, val);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXuncrushpi (CPXCENVptr env, CPXCLPptr lp, double *pi,
                  double const *prepi)
{
   return CPX_CALL (uncrushpi) (env, lp, pi, prepi);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXuncrushx (CPXCENVptr env, CPXCLPptr lp, double *x,
                 double const *prex)
{
   return CPX_CALL (uncrushx) (env, lp, x, prex);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXunscaleprob (CPXCENVptr env, CPXLPptr lp)
{
   return CPX_CALL (unscaleprob) (env, lp);
}


CPX_STATIC_INLINE
CPXCCHARptr CPXPUBLIC
   CPXXversion (CPXCENVptr env)
{
   return CPX_CALL (version) (env);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXversionnumber (CPXCENVptr env, int *version_p)
{
   return CPX_CALL (versionnumber) (env, version_p);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXwriteannotations (CPXCENVptr env, CPXCLPptr lp,
                         char const *filename)
{
   return CPX_CALL (writeannotations) (env, lp, filename);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXwritebendersannotation (CPXCENVptr env, CPXCLPptr lp,
                               char const *filename)
{
   return CPX_CALL (writebendersannotation) (env, lp, filename);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXwriteparam (CPXCENVptr env, char const *filename_str)
{
   return CPX_CALL (writeparam) (env, filename_str);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXwriteprob (CPXCENVptr env, CPXCLPptr lp,
                  char const *filename_str, char const *filetype_str)
{
   return CPX_CALL (writeprob) (env, lp, filename_str, filetype_str);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXbaropt (CPXCENVptr env, CPXLPptr lp)
{
   return CPX_CALL (baropt) (env, lp);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXhybbaropt (CPXCENVptr env, CPXLPptr lp, int method)
{
   return CPX_CALL (hybbaropt) (env, lp, method);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXaddindconstr (CPXCENVptr env, CPXLPptr lp, CPXDIM indvar,
                     int complemented, CPXDIM nzcnt, double rhs,
                     int sense, CPXDIM const *linind,
                     double const *linval, char const *indname_str)
{
   return CPX_CALL (addindconstr) (env, lp, indvar, complemented, nzcnt, rhs, sense, linind, linval, indname_str);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXchgqpcoef (CPXCENVptr env, CPXLPptr lp, CPXDIM i, CPXDIM j,
                  double newvalue)
{
   return CPX_CALL (chgqpcoef) (env, lp, i, j, newvalue);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXcopyqpsep (CPXCENVptr env, CPXLPptr lp, double const *qsepvec)
{
   return CPX_CALL (copyqpsep) (env, lp, qsepvec);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXcopyquad (CPXCENVptr env, CPXLPptr lp, CPXNNZ const *qmatbeg,
                 CPXDIM const *qmatcnt, CPXDIM const *qmatind,
                 double const *qmatval)
{
   return CPX_CALL (copyquad) (env, lp, qmatbeg, qmatcnt, qmatind, qmatval);
}


CPX_STATIC_INLINE
CPXNNZ CPXPUBLIC
   CPXXgetnumqpnz (CPXCENVptr env, CPXCLPptr lp)
{
   return CPX_CALL (getnumqpnz) (env, lp);
}


CPX_STATIC_INLINE
CPXDIM CPXPUBLIC
   CPXXgetnumquad (CPXCENVptr env, CPXCLPptr lp)
{
   return CPX_CALL (getnumquad) (env, lp);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetqpcoef (CPXCENVptr env, CPXCLPptr lp, CPXDIM rownum,
                  CPXDIM colnum, double *coef_p)
{
   return CPX_CALL (getqpcoef) (env, lp, rownum, colnum, coef_p);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetquad (CPXCENVptr env, CPXCLPptr lp, CPXNNZ *nzcnt_p,
                CPXNNZ *qmatbeg, CPXDIM *qmatind, double *qmatval,
                CPXNNZ qmatspace, CPXNNZ *surplus_p, CPXDIM begin,
                CPXDIM end)
{
   return CPX_CALL (getquad) (env, lp, nzcnt_p, qmatbeg, qmatind, qmatval, qmatspace, surplus_p, begin, end);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXqpindefcertificate (CPXCENVptr env, CPXCLPptr lp, double *x)
{
   return CPX_CALL (qpindefcertificate) (env, lp, x);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXqpopt (CPXCENVptr env, CPXLPptr lp)
{
   return CPX_CALL (qpopt) (env, lp);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXaddqconstr (CPXCENVptr env, CPXLPptr lp, CPXDIM linnzcnt,
                   CPXNNZ quadnzcnt, double rhs, int sense,
                   CPXDIM const *linind, double const *linval,
                   CPXDIM const *quadrow, CPXDIM const *quadcol,
                   double const *quadval, char const *lname_str)
{
   return CPX_CALL (addqconstr) (env, lp, linnzcnt, quadnzcnt, rhs, sense, linind, linval, quadrow, quadcol, quadval, lname_str);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXdelqconstrs (CPXCENVptr env, CPXLPptr lp, CPXDIM begin,
                    CPXDIM end)
{
   return CPX_CALL (delqconstrs) (env, lp, begin, end);
}


CPX_STATIC_INLINE
CPXDIM CPXPUBLIC
   CPXXgetnumqconstrs (CPXCENVptr env, CPXCLPptr lp)
{
   return CPX_CALL (getnumqconstrs) (env, lp);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetqconstr (CPXCENVptr env, CPXCLPptr lp, CPXDIM *linnzcnt_p,
                   CPXNNZ *quadnzcnt_p, double *rhs_p, char *sense_p,
                   CPXDIM *linind, double *linval, CPXDIM linspace,
                   CPXDIM *linsurplus_p, CPXDIM *quadrow,
                   CPXDIM *quadcol, double *quadval, CPXNNZ quadspace,
                   CPXNNZ *quadsurplus_p, CPXDIM which)
{
   return CPX_CALL (getqconstr) (env, lp, linnzcnt_p, quadnzcnt_p, rhs_p, sense_p, linind, linval, linspace, linsurplus_p, quadrow, quadcol, quadval, quadspace, quadsurplus_p, which);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetqconstrdslack (CPXCENVptr env, CPXCLPptr lp, CPXDIM qind,
                         CPXDIM *nz_p, CPXDIM *ind, double *val,
                         CPXDIM space, CPXDIM *surplus_p)
{
   return CPX_CALL (getqconstrdslack) (env, lp, qind, nz_p, ind, val, space, surplus_p);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetqconstrindex (CPXCENVptr env, CPXCLPptr lp,
                        char const *lname_str, CPXDIM *index_p)
{
   return CPX_CALL (getqconstrindex) (env, lp, lname_str, index_p);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetqconstrinfeas (CPXCENVptr env, CPXCLPptr lp, double const *x,
                         double *infeasout, CPXDIM begin, CPXDIM end)
{
   return CPX_CALL (getqconstrinfeas) (env, lp, x, infeasout, begin, end);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetqconstrname (CPXCENVptr env, CPXCLPptr lp, char *buf_str,
                       CPXSIZE bufspace, CPXSIZE *surplus_p,
                       CPXDIM which)
{
   return CPX_CALL (getqconstrname) (env, lp, buf_str, bufspace, surplus_p, which);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetqconstrslack (CPXCENVptr env, CPXCLPptr lp, double *qcslack,
                        CPXDIM begin, CPXDIM end)
{
   return CPX_CALL (getqconstrslack) (env, lp, qcslack, begin, end);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetxqxax (CPXCENVptr env, CPXCLPptr lp, double *xqxax,
                 CPXDIM begin, CPXDIM end)
{
   return CPX_CALL (getxqxax) (env, lp, xqxax, begin, end);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXqconstrslackfromx (CPXCENVptr env, CPXCLPptr lp,
                          double const *x, double *qcslack)
{
   return CPX_CALL (qconstrslackfromx) (env, lp, x, qcslack);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXNETaddarcs (CPXCENVptr env, CPXNETptr net, CPXDIM narcs,
                   CPXDIM const *fromnode, CPXDIM const *tonode,
                   double const *low, double const *up,
                   double const *obj, char const *const *anames)
{
   return CPX_CALL (NETaddarcs) (env, net, narcs, fromnode, tonode, low, up, obj, anames);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXNETaddnodes (CPXCENVptr env, CPXNETptr net, CPXDIM nnodes,
                    double const *supply, char const *const *name)
{
   return CPX_CALL (NETaddnodes) (env, net, nnodes, supply, name);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXNETbasewrite (CPXCENVptr env, CPXCNETptr net,
                     char const *filename_str)
{
   return CPX_CALL (NETbasewrite) (env, net, filename_str);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXNETchgarcname (CPXCENVptr env, CPXNETptr net, CPXDIM cnt,
                      CPXDIM const *indices,
                      char const *const *newname)
{
   return CPX_CALL (NETchgarcname) (env, net, cnt, indices, newname);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXNETchgarcnodes (CPXCENVptr env, CPXNETptr net, CPXDIM cnt,
                       CPXDIM const *indices, CPXDIM const *fromnode,
                       CPXDIM const *tonode)
{
   return CPX_CALL (NETchgarcnodes) (env, net, cnt, indices, fromnode, tonode);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXNETchgbds (CPXCENVptr env, CPXNETptr net, CPXDIM cnt,
                  CPXDIM const *indices, char const *lu,
                  double const *bd)
{
   return CPX_CALL (NETchgbds) (env, net, cnt, indices, lu, bd);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXNETchgname (CPXCENVptr env, CPXNETptr net, int key,
                   CPXDIM vindex, char const *name_str)
{
   return CPX_CALL (NETchgname) (env, net, key, vindex, name_str);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXNETchgnodename (CPXCENVptr env, CPXNETptr net, CPXDIM cnt,
                       CPXDIM const *indices,
                       char const *const *newname)
{
   return CPX_CALL (NETchgnodename) (env, net, cnt, indices, newname);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXNETchgobj (CPXCENVptr env, CPXNETptr net, CPXDIM cnt,
                  CPXDIM const *indices, double const *obj)
{
   return CPX_CALL (NETchgobj) (env, net, cnt, indices, obj);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXNETchgobjsen (CPXCENVptr env, CPXNETptr net, int maxormin)
{
   return CPX_CALL (NETchgobjsen) (env, net, maxormin);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXNETchgsupply (CPXCENVptr env, CPXNETptr net, CPXDIM cnt,
                     CPXDIM const *indices, double const *supply)
{
   return CPX_CALL (NETchgsupply) (env, net, cnt, indices, supply);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXNETcopybase (CPXCENVptr env, CPXNETptr net, int const *astat,
                    int const *nstat)
{
   return CPX_CALL (NETcopybase) (env, net, astat, nstat);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXNETcopynet (CPXCENVptr env, CPXNETptr net, int objsen,
                   CPXDIM nnodes, double const *supply,
                   char const *const *nnames, CPXDIM narcs,
                   CPXDIM const *fromnode, CPXDIM const *tonode,
                   double const *low, double const *up,
                   double const *obj, char const *const *anames)
{
   return CPX_CALL (NETcopynet) (env, net, objsen, nnodes, supply, nnames, narcs, fromnode, tonode, low, up, obj, anames);
}


CPX_STATIC_INLINE
CPXNETptr CPXPUBLIC
   CPXXNETcreateprob (CPXENVptr env, int *status_p,
                      char const *name_str)
{
   return CPX_CALL (NETcreateprob) (env, status_p, name_str);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXNETdelarcs (CPXCENVptr env, CPXNETptr net, CPXDIM begin,
                   CPXDIM end)
{
   return CPX_CALL (NETdelarcs) (env, net, begin, end);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXNETdelnodes (CPXCENVptr env, CPXNETptr net, CPXDIM begin,
                    CPXDIM end)
{
   return CPX_CALL (NETdelnodes) (env, net, begin, end);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXNETdelset (CPXCENVptr env, CPXNETptr net, CPXDIM *whichnodes,
                  CPXDIM *whicharcs)
{
   return CPX_CALL (NETdelset) (env, net, whichnodes, whicharcs);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXNETfreeprob (CPXENVptr env, CPXNETptr *net_p)
{
   return CPX_CALL (NETfreeprob) (env, net_p);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXNETgetarcindex (CPXCENVptr env, CPXCNETptr net,
                       char const *lname_str, CPXDIM *index_p)
{
   return CPX_CALL (NETgetarcindex) (env, net, lname_str, index_p);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXNETgetarcname (CPXCENVptr env, CPXCNETptr net, char  **nnames,
                      char *namestore, CPXSIZE namespc,
                      CPXSIZE *surplus_p, CPXDIM begin, CPXDIM end)
{
   return CPX_CALL (NETgetarcname) (env, net, nnames, namestore, namespc, surplus_p, begin, end);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXNETgetarcnodes (CPXCENVptr env, CPXCNETptr net,
                       CPXDIM *fromnode, CPXDIM *tonode, CPXDIM begin,
                       CPXDIM end)
{
   return CPX_CALL (NETgetarcnodes) (env, net, fromnode, tonode, begin, end);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXNETgetbase (CPXCENVptr env, CPXCNETptr net, int *astat,
                   int *nstat)
{
   return CPX_CALL (NETgetbase) (env, net, astat, nstat);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXNETgetdj (CPXCENVptr env, CPXCNETptr net, double *dj,
                 CPXDIM begin, CPXDIM end)
{
   return CPX_CALL (NETgetdj) (env, net, dj, begin, end);
}


CPX_STATIC_INLINE
CPXCNT CPXPUBLIC
   CPXXNETgetitcnt (CPXCENVptr env, CPXCNETptr net)
{
   return CPX_CALL (NETgetitcnt) (env, net);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXNETgetlb (CPXCENVptr env, CPXCNETptr net, double *low,
                 CPXDIM begin, CPXDIM end)
{
   return CPX_CALL (NETgetlb) (env, net, low, begin, end);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXNETgetnodearcs (CPXCENVptr env, CPXCNETptr net,
                       CPXDIM *arccnt_p, CPXDIM *arcbeg, CPXDIM *arc,
                       CPXDIM arcspace, CPXDIM *surplus_p,
                       CPXDIM begin, CPXDIM end)
{
   return CPX_CALL (NETgetnodearcs) (env, net, arccnt_p, arcbeg, arc, arcspace, surplus_p, begin, end);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXNETgetnodeindex (CPXCENVptr env, CPXCNETptr net,
                        char const *lname_str, CPXDIM *index_p)
{
   return CPX_CALL (NETgetnodeindex) (env, net, lname_str, index_p);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXNETgetnodename (CPXCENVptr env, CPXCNETptr net, char  **nnames,
                       char *namestore, CPXSIZE namespc,
                       CPXSIZE *surplus_p, CPXDIM begin, CPXDIM end)
{
   return CPX_CALL (NETgetnodename) (env, net, nnames, namestore, namespc, surplus_p, begin, end);
}


CPX_STATIC_INLINE
CPXDIM CPXPUBLIC
   CPXXNETgetnumarcs (CPXCENVptr env, CPXCNETptr net)
{
   return CPX_CALL (NETgetnumarcs) (env, net);
}


CPX_STATIC_INLINE
CPXDIM CPXPUBLIC
   CPXXNETgetnumnodes (CPXCENVptr env, CPXCNETptr net)
{
   return CPX_CALL (NETgetnumnodes) (env, net);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXNETgetobj (CPXCENVptr env, CPXCNETptr net, double *obj,
                  CPXDIM begin, CPXDIM end)
{
   return CPX_CALL (NETgetobj) (env, net, obj, begin, end);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXNETgetobjsen (CPXCENVptr env, CPXCNETptr net)
{
   return CPX_CALL (NETgetobjsen) (env, net);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXNETgetobjval (CPXCENVptr env, CPXCNETptr net, double *objval_p)
{
   return CPX_CALL (NETgetobjval) (env, net, objval_p);
}


CPX_STATIC_INLINE
CPXCNT CPXPUBLIC
   CPXXNETgetphase1cnt (CPXCENVptr env, CPXCNETptr net)
{
   return CPX_CALL (NETgetphase1cnt) (env, net);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXNETgetpi (CPXCENVptr env, CPXCNETptr net, double *pi,
                 CPXDIM begin, CPXDIM end)
{
   return CPX_CALL (NETgetpi) (env, net, pi, begin, end);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXNETgetprobname (CPXCENVptr env, CPXCNETptr net, char *buf_str,
                       CPXSIZE bufspace, CPXSIZE *surplus_p)
{
   return CPX_CALL (NETgetprobname) (env, net, buf_str, bufspace, surplus_p);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXNETgetslack (CPXCENVptr env, CPXCNETptr net, double *slack,
                    CPXDIM begin, CPXDIM end)
{
   return CPX_CALL (NETgetslack) (env, net, slack, begin, end);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXNETgetstat (CPXCENVptr env, CPXCNETptr net)
{
   return CPX_CALL (NETgetstat) (env, net);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXNETgetsupply (CPXCENVptr env, CPXCNETptr net, double *supply,
                     CPXDIM begin, CPXDIM end)
{
   return CPX_CALL (NETgetsupply) (env, net, supply, begin, end);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXNETgetub (CPXCENVptr env, CPXCNETptr net, double *up,
                 CPXDIM begin, CPXDIM end)
{
   return CPX_CALL (NETgetub) (env, net, up, begin, end);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXNETgetx (CPXCENVptr env, CPXCNETptr net, double *x,
                CPXDIM begin, CPXDIM end)
{
   return CPX_CALL (NETgetx) (env, net, x, begin, end);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXNETprimopt (CPXCENVptr env, CPXNETptr net)
{
   return CPX_CALL (NETprimopt) (env, net);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXNETreadcopybase (CPXCENVptr env, CPXNETptr net,
                        char const *filename_str)
{
   return CPX_CALL (NETreadcopybase) (env, net, filename_str);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXNETreadcopyprob (CPXCENVptr env, CPXNETptr net,
                        char const *filename_str)
{
   return CPX_CALL (NETreadcopyprob) (env, net, filename_str);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXNETsolninfo (CPXCENVptr env, CPXCNETptr net, int *pfeasind_p,
                    int *dfeasind_p)
{
   return CPX_CALL (NETsolninfo) (env, net, pfeasind_p, dfeasind_p);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXNETsolution (CPXCENVptr env, CPXCNETptr net, int *netstat_p,
                    double *objval_p, double *x, double *pi,
                    double *slack, double *dj)
{
   return CPX_CALL (NETsolution) (env, net, netstat_p, objval_p, x, pi, slack, dj);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXNETwriteprob (CPXCENVptr env, CPXCNETptr net,
                     char const *filename_str, char const *format_str)
{
   return CPX_CALL (NETwriteprob) (env, net, filename_str, format_str);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXaddlazyconstraints (CPXCENVptr env, CPXLPptr lp, CPXDIM rcnt,
                           CPXNNZ nzcnt, double const *rhs,
                           char const *sense, CPXNNZ const *rmatbeg,
                           CPXDIM const *rmatind,
                           double const *rmatval,
                           char const *const *rowname)
{
   return CPX_CALL (addlazyconstraints) (env, lp, rcnt, nzcnt, rhs, sense, rmatbeg, rmatind, rmatval, rowname);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXaddmipstarts (CPXCENVptr env, CPXLPptr lp, int mcnt,
                     CPXNNZ nzcnt, CPXNNZ const *beg,
                     CPXDIM const *varindices, double const *values,
                     int const *effortlevel,
                     char const *const *mipstartname)
{
   return CPX_CALL (addmipstarts) (env, lp, mcnt, nzcnt, beg, varindices, values, effortlevel, mipstartname);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXaddsolnpooldivfilter (CPXCENVptr env, CPXLPptr lp,
                             double lower_bound, double upper_bound,
                             CPXDIM nzcnt, CPXDIM const *ind,
                             double const *weight,
                             double const *refval,
                             char const *lname_str)
{
   return CPX_CALL (addsolnpooldivfilter) (env, lp, lower_bound, upper_bound, nzcnt, ind, weight, refval, lname_str);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXaddsolnpoolrngfilter (CPXCENVptr env, CPXLPptr lp, double lb,
                             double ub, CPXDIM nzcnt,
                             CPXDIM const *ind, double const *val,
                             char const *lname_str)
{
   return CPX_CALL (addsolnpoolrngfilter) (env, lp, lb, ub, nzcnt, ind, val, lname_str);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXaddsos (CPXCENVptr env, CPXLPptr lp, CPXDIM numsos,
               CPXNNZ numsosnz, char const *sostype,
               CPXNNZ const *sosbeg, CPXDIM const *sosind,
               double const *soswt, char const *const *sosname)
{
   return CPX_CALL (addsos) (env, lp, numsos, numsosnz, sostype, sosbeg, sosind, soswt, sosname);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXaddusercuts (CPXCENVptr env, CPXLPptr lp, CPXDIM rcnt,
                    CPXNNZ nzcnt, double const *rhs, char const *sense,
                    CPXNNZ const *rmatbeg, CPXDIM const *rmatind,
                    double const *rmatval, char const *const *rowname)
{
   return CPX_CALL (addusercuts) (env, lp, rcnt, nzcnt, rhs, sense, rmatbeg, rmatind, rmatval, rowname);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXbendersopt (CPXCENVptr env, CPXLPptr lp)
{
   return CPX_CALL (bendersopt) (env, lp);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXbranchcallbackbranchasCPLEX (CPXCENVptr env, void *cbdata,
                                    int wherefrom, int num,
                                    void *userhandle, CPXCNT *seqnum_p)
{
   return CPX_CALL (branchcallbackbranchasCPLEX) (env, cbdata, wherefrom, num, userhandle, seqnum_p);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXbranchcallbackbranchbds (CPXCENVptr env, void *cbdata,
                                int wherefrom, CPXDIM cnt,
                                CPXDIM const *indices, char const *lu,
                                double const *bd, double nodeest,
                                void *userhandle, CPXCNT *seqnum_p)
{
   return CPX_CALL (branchcallbackbranchbds) (env, cbdata, wherefrom, cnt, indices, lu, bd, nodeest, userhandle, seqnum_p);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXbranchcallbackbranchconstraints (CPXCENVptr env, void *cbdata,
                                        int wherefrom, CPXDIM rcnt,
                                        CPXNNZ nzcnt,
                                        double const *rhs,
                                        char const *sense,
                                        CPXNNZ const *rmatbeg,
                                        CPXDIM const *rmatind,
                                        double const *rmatval,
                                        double nodeest,
                                        void *userhandle,
                                        CPXCNT *seqnum_p)
{
   return CPX_CALL (branchcallbackbranchconstraints) (env, cbdata, wherefrom, rcnt, nzcnt, rhs, sense, rmatbeg, rmatind, rmatval, nodeest, userhandle, seqnum_p);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXbranchcallbackbranchgeneral (CPXCENVptr env, void *cbdata,
                                    int wherefrom, CPXDIM varcnt,
                                    CPXDIM const *varind,
                                    char const *varlu,
                                    double const *varbd, CPXDIM rcnt,
                                    CPXNNZ nzcnt, double const *rhs,
                                    char const *sense,
                                    CPXNNZ const *rmatbeg,
                                    CPXDIM const *rmatind,
                                    double const *rmatval,
                                    double nodeest, void *userhandle,
                                    CPXCNT *seqnum_p)
{
   return CPX_CALL (branchcallbackbranchgeneral) (env, cbdata, wherefrom, varcnt, varind, varlu, varbd, rcnt, nzcnt, rhs, sense, rmatbeg, rmatind, rmatval, nodeest, userhandle, seqnum_p);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXcallbacksetnodeuserhandle (CPXCENVptr env, void *cbdata,
                                  int wherefrom, CPXCNT nodeindex,
                                  void *userhandle,
                                  void  **olduserhandle_p)
{
   return CPX_CALL (callbacksetnodeuserhandle) (env, cbdata, wherefrom, nodeindex, userhandle, olduserhandle_p);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXcallbacksetuserhandle (CPXCENVptr env, void *cbdata,
                              int wherefrom, void *userhandle,
                              void  **olduserhandle_p)
{
   return CPX_CALL (callbacksetuserhandle) (env, cbdata, wherefrom, userhandle, olduserhandle_p);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXchgctype (CPXCENVptr env, CPXLPptr lp, CPXDIM cnt,
                 CPXDIM const *indices, char const *xctype)
{
   return CPX_CALL (chgctype) (env, lp, cnt, indices, xctype);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXchgmipstarts (CPXCENVptr env, CPXLPptr lp, int mcnt,
                     int const *mipstartindices, CPXNNZ nzcnt,
                     CPXNNZ const *beg, CPXDIM const *varindices,
                     double const *values, int const *effortlevel)
{
   return CPX_CALL (chgmipstarts) (env, lp, mcnt, mipstartindices, nzcnt, beg, varindices, values, effortlevel);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXcopyctype (CPXCENVptr env, CPXLPptr lp, char const *xctype)
{
   return CPX_CALL (copyctype) (env, lp, xctype);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXcopyorder (CPXCENVptr env, CPXLPptr lp, CPXDIM cnt,
                  CPXDIM const *indices, CPXDIM const *priority,
                  int const *direction)
{
   return CPX_CALL (copyorder) (env, lp, cnt, indices, priority, direction);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXcopysos (CPXCENVptr env, CPXLPptr lp, CPXDIM numsos,
                CPXNNZ numsosnz, char const *sostype,
                CPXNNZ const *sosbeg, CPXDIM const *sosind,
                double const *soswt, char const *const *sosname)
{
   return CPX_CALL (copysos) (env, lp, numsos, numsosnz, sostype, sosbeg, sosind, soswt, sosname);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXcutcallbackadd (CPXCENVptr env, void *cbdata, int wherefrom,
                       CPXDIM nzcnt, double rhs, int sense,
                       CPXDIM const *cutind, double const *cutval,
                       int purgeable)
{
   return CPX_CALL (cutcallbackadd) (env, cbdata, wherefrom, nzcnt, rhs, sense, cutind, cutval, purgeable);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXcutcallbackaddlocal (CPXCENVptr env, void *cbdata,
                            int wherefrom, CPXDIM nzcnt, double rhs,
                            int sense, CPXDIM const *cutind,
                            double const *cutval)
{
   return CPX_CALL (cutcallbackaddlocal) (env, cbdata, wherefrom, nzcnt, rhs, sense, cutind, cutval);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXdelindconstrs (CPXCENVptr env, CPXLPptr lp, CPXDIM begin,
                      CPXDIM end)
{
   return CPX_CALL (delindconstrs) (env, lp, begin, end);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXdelmipstarts (CPXCENVptr env, CPXLPptr lp, int begin, int end)
{
   return CPX_CALL (delmipstarts) (env, lp, begin, end);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXdelsetmipstarts (CPXCENVptr env, CPXLPptr lp, int *delstat)
{
   return CPX_CALL (delsetmipstarts) (env, lp, delstat);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXdelsetsolnpoolfilters (CPXCENVptr env, CPXLPptr lp,
                              int *delstat)
{
   return CPX_CALL (delsetsolnpoolfilters) (env, lp, delstat);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXdelsetsolnpoolsolns (CPXCENVptr env, CPXLPptr lp, int *delstat)
{
   return CPX_CALL (delsetsolnpoolsolns) (env, lp, delstat);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXdelsetsos (CPXCENVptr env, CPXLPptr lp, CPXDIM *delset)
{
   return CPX_CALL (delsetsos) (env, lp, delset);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXdelsolnpoolfilters (CPXCENVptr env, CPXLPptr lp, int begin,
                           int end)
{
   return CPX_CALL (delsolnpoolfilters) (env, lp, begin, end);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXdelsolnpoolsolns (CPXCENVptr env, CPXLPptr lp, int begin,
                         int end)
{
   return CPX_CALL (delsolnpoolsolns) (env, lp, begin, end);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXdelsos (CPXCENVptr env, CPXLPptr lp, CPXDIM begin, CPXDIM end)
{
   return CPX_CALL (delsos) (env, lp, begin, end);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXfltwrite (CPXCENVptr env, CPXCLPptr lp,
                 char const *filename_str)
{
   return CPX_CALL (fltwrite) (env, lp, filename_str);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXfreelazyconstraints (CPXCENVptr env, CPXLPptr lp)
{
   return CPX_CALL (freelazyconstraints) (env, lp);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXfreeusercuts (CPXCENVptr env, CPXLPptr lp)
{
   return CPX_CALL (freeusercuts) (env, lp);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetbestobjval (CPXCENVptr env, CPXCLPptr lp, double *objval_p)
{
   return CPX_CALL (getbestobjval) (env, lp, objval_p);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetbranchcallbackfunc (CPXCENVptr env,
                              CPXX_CALLBACK_BRANCH **branchcallback_p,
                              void  **cbhandle_p)
{
   return CPX_CALL (getbranchcallbackfunc) (env, branchcallback_p, cbhandle_p);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetbranchnosolncallbackfunc (CPXCENVptr env,
                                    CPXX_CALLBACK_BRANCH **branchnosolncallback_p,
                                    void  **cbhandle_p)
{
   return CPX_CALL (getbranchnosolncallbackfunc) (env, branchnosolncallback_p, cbhandle_p);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetcallbackbranchconstraints (CPXCENVptr env, void *cbdata,
                                     int wherefrom, int which,
                                     CPXDIM *cuts_p, CPXNNZ *nzcnt_p,
                                     double *rhs, char *sense,
                                     CPXNNZ *rmatbeg, CPXDIM *rmatind,
                                     double *rmatval, CPXNNZ rmatsz,
                                     CPXNNZ *surplus_p)
{
   return CPX_CALL (getcallbackbranchconstraints) (env, cbdata, wherefrom, which, cuts_p, nzcnt_p, rhs, sense, rmatbeg, rmatind, rmatval, rmatsz, surplus_p);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetcallbackctype (CPXCENVptr env, void *cbdata, int wherefrom,
                         char *xctype, CPXDIM begin, CPXDIM end)
{
   return CPX_CALL (getcallbackctype) (env, cbdata, wherefrom, xctype, begin, end);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetcallbackgloballb (CPXCENVptr env, void *cbdata,
                            int wherefrom, double *lb, CPXDIM begin,
                            CPXDIM end)
{
   return CPX_CALL (getcallbackgloballb) (env, cbdata, wherefrom, lb, begin, end);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetcallbackglobalub (CPXCENVptr env, void *cbdata,
                            int wherefrom, double *ub, CPXDIM begin,
                            CPXDIM end)
{
   return CPX_CALL (getcallbackglobalub) (env, cbdata, wherefrom, ub, begin, end);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetcallbackincumbent (CPXCENVptr env, void *cbdata,
                             int wherefrom, double *x, CPXDIM begin,
                             CPXDIM end)
{
   return CPX_CALL (getcallbackincumbent) (env, cbdata, wherefrom, x, begin, end);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetcallbackindicatorinfo (CPXCENVptr env, void *cbdata,
                                 int wherefrom, CPXDIM iindex,
                                 int whichinfo, void *result_p)
{
   return CPX_CALL (getcallbackindicatorinfo) (env, cbdata, wherefrom, iindex, whichinfo, result_p);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetcallbacklp (CPXCENVptr env, void *cbdata, int wherefrom,
                      CPXCLPptr *lp_p)
{
   return CPX_CALL (getcallbacklp) (env, cbdata, wherefrom, lp_p);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetcallbacknodeinfo (CPXCENVptr env, void *cbdata,
                            int wherefrom, CPXCNT nodeindex,
                            int whichinfo, void *result_p)
{
   return CPX_CALL (getcallbacknodeinfo) (env, cbdata, wherefrom, nodeindex, whichinfo, result_p);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetcallbacknodeintfeas (CPXCENVptr env, void *cbdata,
                               int wherefrom, int *feas, CPXDIM begin,
                               CPXDIM end)
{
   return CPX_CALL (getcallbacknodeintfeas) (env, cbdata, wherefrom, feas, begin, end);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetcallbacknodelb (CPXCENVptr env, void *cbdata, int wherefrom,
                          double *lb, CPXDIM begin, CPXDIM end)
{
   return CPX_CALL (getcallbacknodelb) (env, cbdata, wherefrom, lb, begin, end);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetcallbacknodelp (CPXCENVptr env, void *cbdata, int wherefrom,
                          CPXLPptr *nodelp_p)
{
   return CPX_CALL (getcallbacknodelp) (env, cbdata, wherefrom, nodelp_p);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetcallbacknodeobjval (CPXCENVptr env, void *cbdata,
                              int wherefrom, double *objval_p)
{
   return CPX_CALL (getcallbacknodeobjval) (env, cbdata, wherefrom, objval_p);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetcallbacknodestat (CPXCENVptr env, void *cbdata,
                            int wherefrom, int *nodestat_p)
{
   return CPX_CALL (getcallbacknodestat) (env, cbdata, wherefrom, nodestat_p);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetcallbacknodeub (CPXCENVptr env, void *cbdata, int wherefrom,
                          double *ub, CPXDIM begin, CPXDIM end)
{
   return CPX_CALL (getcallbacknodeub) (env, cbdata, wherefrom, ub, begin, end);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetcallbacknodex (CPXCENVptr env, void *cbdata, int wherefrom,
                         double *x, CPXDIM begin, CPXDIM end)
{
   return CPX_CALL (getcallbacknodex) (env, cbdata, wherefrom, x, begin, end);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetcallbackorder (CPXCENVptr env, void *cbdata, int wherefrom,
                         CPXDIM *priority, int *direction,
                         CPXDIM begin, CPXDIM end)
{
   return CPX_CALL (getcallbackorder) (env, cbdata, wherefrom, priority, direction, begin, end);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetcallbackpseudocosts (CPXCENVptr env, void *cbdata,
                               int wherefrom, double *uppc,
                               double *downpc, CPXDIM begin,
                               CPXDIM end)
{
   return CPX_CALL (getcallbackpseudocosts) (env, cbdata, wherefrom, uppc, downpc, begin, end);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetcallbackseqinfo (CPXCENVptr env, void *cbdata, int wherefrom,
                           CPXCNT seqid, int whichinfo, void *result_p)
{
   return CPX_CALL (getcallbackseqinfo) (env, cbdata, wherefrom, seqid, whichinfo, result_p);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetcallbacksosinfo (CPXCENVptr env, void *cbdata, int wherefrom,
                           CPXDIM sosindex, CPXDIM member,
                           int whichinfo, void *result_p)
{
   return CPX_CALL (getcallbacksosinfo) (env, cbdata, wherefrom, sosindex, member, whichinfo, result_p);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetctype (CPXCENVptr env, CPXCLPptr lp, char *xctype,
                 CPXDIM begin, CPXDIM end)
{
   return CPX_CALL (getctype) (env, lp, xctype, begin, end);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetcutoff (CPXCENVptr env, CPXCLPptr lp, double *cutoff_p)
{
   return CPX_CALL (getcutoff) (env, lp, cutoff_p);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetdeletenodecallbackfunc (CPXCENVptr env,
                                  CPXX_CALLBACK_DELETENODE **deletecallback_p,
                                  void  **cbhandle_p)
{
   return CPX_CALL (getdeletenodecallbackfunc) (env, deletecallback_p, cbhandle_p);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetheuristiccallbackfunc (CPXCENVptr env,
                                 CPXX_CALLBACK_HEURISTIC **heuristiccallback_p,
                                 void  **cbhandle_p)
{
   return CPX_CALL (getheuristiccallbackfunc) (env, heuristiccallback_p, cbhandle_p);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetincumbentcallbackfunc (CPXCENVptr env,
                                 CPXX_CALLBACK_INCUMBENT **incumbentcallback_p,
                                 void  **cbhandle_p)
{
   return CPX_CALL (getincumbentcallbackfunc) (env, incumbentcallback_p, cbhandle_p);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetindconstr (CPXCENVptr env, CPXCLPptr lp, CPXDIM *indvar_p,
                     int *complemented_p, CPXDIM *nzcnt_p,
                     double *rhs_p, char *sense_p, CPXDIM *linind,
                     double *linval, CPXDIM space, CPXDIM *surplus_p,
                     CPXDIM which)
{
   return CPX_CALL (getindconstr) (env, lp, indvar_p, complemented_p, nzcnt_p, rhs_p, sense_p, linind, linval, space, surplus_p, which);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetindconstrindex (CPXCENVptr env, CPXCLPptr lp,
                          char const *lname_str, CPXDIM *index_p)
{
   return CPX_CALL (getindconstrindex) (env, lp, lname_str, index_p);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetindconstrinfeas (CPXCENVptr env, CPXCLPptr lp,
                           double const *x, double *infeasout,
                           CPXDIM begin, CPXDIM end)
{
   return CPX_CALL (getindconstrinfeas) (env, lp, x, infeasout, begin, end);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetindconstrname (CPXCENVptr env, CPXCLPptr lp, char *buf_str,
                         CPXSIZE bufspace, CPXSIZE *surplus_p,
                         CPXDIM which)
{
   return CPX_CALL (getindconstrname) (env, lp, buf_str, bufspace, surplus_p, which);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetindconstrslack (CPXCENVptr env, CPXCLPptr lp,
                          double *indslack, CPXDIM begin, CPXDIM end)
{
   return CPX_CALL (getindconstrslack) (env, lp, indslack, begin, end);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetinfocallbackfunc (CPXCENVptr env, CPXX_CALLBACK **callback_p,
                            void  **cbhandle_p)
{
   return CPX_CALL (getinfocallbackfunc) (env, callback_p, cbhandle_p);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetlazyconstraintcallbackfunc (CPXCENVptr env,
                                      CPXX_CALLBACK_CUT **cutcallback_p,
                                      void  **cbhandle_p)
{
   return CPX_CALL (getlazyconstraintcallbackfunc) (env, cutcallback_p, cbhandle_p);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetmipcallbackfunc (CPXCENVptr env, CPXX_CALLBACK **callback_p,
                           void  **cbhandle_p)
{
   return CPX_CALL (getmipcallbackfunc) (env, callback_p, cbhandle_p);
}


CPX_STATIC_INLINE
CPXCNT CPXPUBLIC
   CPXXgetmipitcnt (CPXCENVptr env, CPXCLPptr lp)
{
   return CPX_CALL (getmipitcnt) (env, lp);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetmiprelgap (CPXCENVptr env, CPXCLPptr lp, double *gap_p)
{
   return CPX_CALL (getmiprelgap) (env, lp, gap_p);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetmipstartindex (CPXCENVptr env, CPXCLPptr lp,
                         char const *lname_str, int *index_p)
{
   return CPX_CALL (getmipstartindex) (env, lp, lname_str, index_p);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetmipstartname (CPXCENVptr env, CPXCLPptr lp, char  **name,
                        char *store, CPXSIZE storesz,
                        CPXSIZE *surplus_p, int begin, int end)
{
   return CPX_CALL (getmipstartname) (env, lp, name, store, storesz, surplus_p, begin, end);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetmipstarts (CPXCENVptr env, CPXCLPptr lp, CPXNNZ *nzcnt_p,
                     CPXNNZ *beg, CPXDIM *varindices, double *values,
                     int *effortlevel, CPXNNZ startspace,
                     CPXNNZ *surplus_p, int begin, int end)
{
   return CPX_CALL (getmipstarts) (env, lp, nzcnt_p, beg, varindices, values, effortlevel, startspace, surplus_p, begin, end);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetnodecallbackfunc (CPXCENVptr env,
                            CPXX_CALLBACK_NODE **nodecallback_p,
                            void  **cbhandle_p)
{
   return CPX_CALL (getnodecallbackfunc) (env, nodecallback_p, cbhandle_p);
}


CPX_STATIC_INLINE
CPXCNT CPXPUBLIC
   CPXXgetnodecnt (CPXCENVptr env, CPXCLPptr lp)
{
   return CPX_CALL (getnodecnt) (env, lp);
}


CPX_STATIC_INLINE
CPXCNT CPXPUBLIC
   CPXXgetnodeint (CPXCENVptr env, CPXCLPptr lp)
{
   return CPX_CALL (getnodeint) (env, lp);
}


CPX_STATIC_INLINE
CPXCNT CPXPUBLIC
   CPXXgetnodeleftcnt (CPXCENVptr env, CPXCLPptr lp)
{
   return CPX_CALL (getnodeleftcnt) (env, lp);
}


CPX_STATIC_INLINE
CPXDIM CPXPUBLIC
   CPXXgetnumbin (CPXCENVptr env, CPXCLPptr lp)
{
   return CPX_CALL (getnumbin) (env, lp);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetnumcuts (CPXCENVptr env, CPXCLPptr lp, int cuttype,
                   CPXDIM *num_p)
{
   return CPX_CALL (getnumcuts) (env, lp, cuttype, num_p);
}


CPX_STATIC_INLINE
CPXDIM CPXPUBLIC
   CPXXgetnumindconstrs (CPXCENVptr env, CPXCLPptr lp)
{
   return CPX_CALL (getnumindconstrs) (env, lp);
}


CPX_STATIC_INLINE
CPXDIM CPXPUBLIC
   CPXXgetnumint (CPXCENVptr env, CPXCLPptr lp)
{
   return CPX_CALL (getnumint) (env, lp);
}


CPX_STATIC_INLINE
CPXDIM CPXPUBLIC
   CPXXgetnumlazyconstraints (CPXCENVptr env, CPXCLPptr lp)
{
   return CPX_CALL (getnumlazyconstraints) (env, lp);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetnummipstarts (CPXCENVptr env, CPXCLPptr lp)
{
   return CPX_CALL (getnummipstarts) (env, lp);
}


CPX_STATIC_INLINE
CPXDIM CPXPUBLIC
   CPXXgetnumsemicont (CPXCENVptr env, CPXCLPptr lp)
{
   return CPX_CALL (getnumsemicont) (env, lp);
}


CPX_STATIC_INLINE
CPXDIM CPXPUBLIC
   CPXXgetnumsemiint (CPXCENVptr env, CPXCLPptr lp)
{
   return CPX_CALL (getnumsemiint) (env, lp);
}


CPX_STATIC_INLINE
CPXDIM CPXPUBLIC
   CPXXgetnumsos (CPXCENVptr env, CPXCLPptr lp)
{
   return CPX_CALL (getnumsos) (env, lp);
}


CPX_STATIC_INLINE
CPXDIM CPXPUBLIC
   CPXXgetnumusercuts (CPXCENVptr env, CPXCLPptr lp)
{
   return CPX_CALL (getnumusercuts) (env, lp);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetorder (CPXCENVptr env, CPXCLPptr lp, CPXDIM *cnt_p,
                 CPXDIM *indices, CPXDIM *priority, int *direction,
                 CPXDIM ordspace, CPXDIM *surplus_p)
{
   return CPX_CALL (getorder) (env, lp, cnt_p, indices, priority, direction, ordspace, surplus_p);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetsolnpooldivfilter (CPXCENVptr env, CPXCLPptr lp,
                             double *lower_cutoff_p,
                             double *upper_cutoff_p, CPXDIM *nzcnt_p,
                             CPXDIM *ind, double *val, double *refval,
                             CPXDIM space, CPXDIM *surplus_p,
                             int which)
{
   return CPX_CALL (getsolnpooldivfilter) (env, lp, lower_cutoff_p, upper_cutoff_p, nzcnt_p, ind, val, refval, space, surplus_p, which);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetsolnpoolfilterindex (CPXCENVptr env, CPXCLPptr lp,
                               char const *lname_str, int *index_p)
{
   return CPX_CALL (getsolnpoolfilterindex) (env, lp, lname_str, index_p);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetsolnpoolfiltername (CPXCENVptr env, CPXCLPptr lp,
                              char *buf_str, CPXSIZE bufspace,
                              CPXSIZE *surplus_p, int which)
{
   return CPX_CALL (getsolnpoolfiltername) (env, lp, buf_str, bufspace, surplus_p, which);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetsolnpoolfiltertype (CPXCENVptr env, CPXCLPptr lp,
                              int *ftype_p, int which)
{
   return CPX_CALL (getsolnpoolfiltertype) (env, lp, ftype_p, which);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetsolnpoolmeanobjval (CPXCENVptr env, CPXCLPptr lp,
                              double *meanobjval_p)
{
   return CPX_CALL (getsolnpoolmeanobjval) (env, lp, meanobjval_p);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetsolnpoolnumfilters (CPXCENVptr env, CPXCLPptr lp)
{
   return CPX_CALL (getsolnpoolnumfilters) (env, lp);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetsolnpoolnumreplaced (CPXCENVptr env, CPXCLPptr lp)
{
   return CPX_CALL (getsolnpoolnumreplaced) (env, lp);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetsolnpoolnumsolns (CPXCENVptr env, CPXCLPptr lp)
{
   return CPX_CALL (getsolnpoolnumsolns) (env, lp);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetsolnpoolobjval (CPXCENVptr env, CPXCLPptr lp, int soln,
                          double *objval_p)
{
   return CPX_CALL (getsolnpoolobjval) (env, lp, soln, objval_p);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetsolnpoolqconstrslack (CPXCENVptr env, CPXCLPptr lp, int soln,
                                double *qcslack, CPXDIM begin,
                                CPXDIM end)
{
   return CPX_CALL (getsolnpoolqconstrslack) (env, lp, soln, qcslack, begin, end);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetsolnpoolrngfilter (CPXCENVptr env, CPXCLPptr lp,
                             double *lb_p, double *ub_p,
                             CPXDIM *nzcnt_p, CPXDIM *ind, double *val,
                             CPXDIM space, CPXDIM *surplus_p,
                             int which)
{
   return CPX_CALL (getsolnpoolrngfilter) (env, lp, lb_p, ub_p, nzcnt_p, ind, val, space, surplus_p, which);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetsolnpoolslack (CPXCENVptr env, CPXCLPptr lp, int soln,
                         double *slack, CPXDIM begin, CPXDIM end)
{
   return CPX_CALL (getsolnpoolslack) (env, lp, soln, slack, begin, end);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetsolnpoolsolnindex (CPXCENVptr env, CPXCLPptr lp,
                             char const *lname_str, int *index_p)
{
   return CPX_CALL (getsolnpoolsolnindex) (env, lp, lname_str, index_p);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetsolnpoolsolnname (CPXCENVptr env, CPXCLPptr lp, char *store,
                            CPXSIZE storesz, CPXSIZE *surplus_p,
                            int which)
{
   return CPX_CALL (getsolnpoolsolnname) (env, lp, store, storesz, surplus_p, which);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetsolnpoolx (CPXCENVptr env, CPXCLPptr lp, int soln, double *x,
                     CPXDIM begin, CPXDIM end)
{
   return CPX_CALL (getsolnpoolx) (env, lp, soln, x, begin, end);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetsolvecallbackfunc (CPXCENVptr env,
                             CPXX_CALLBACK_SOLVE **solvecallback_p,
                             void  **cbhandle_p)
{
   return CPX_CALL (getsolvecallbackfunc) (env, solvecallback_p, cbhandle_p);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetsos (CPXCENVptr env, CPXCLPptr lp, CPXNNZ *numsosnz_p,
               char *sostype, CPXNNZ *sosbeg, CPXDIM *sosind,
               double *soswt, CPXNNZ sosspace, CPXNNZ *surplus_p,
               CPXDIM begin, CPXDIM end)
{
   return CPX_CALL (getsos) (env, lp, numsosnz_p, sostype, sosbeg, sosind, soswt, sosspace, surplus_p, begin, end);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetsosindex (CPXCENVptr env, CPXCLPptr lp,
                    char const *lname_str, CPXDIM *index_p)
{
   return CPX_CALL (getsosindex) (env, lp, lname_str, index_p);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetsosinfeas (CPXCENVptr env, CPXCLPptr lp, double const *x,
                     double *infeasout, CPXDIM begin, CPXDIM end)
{
   return CPX_CALL (getsosinfeas) (env, lp, x, infeasout, begin, end);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetsosname (CPXCENVptr env, CPXCLPptr lp, char  **name,
                   char *namestore, CPXSIZE storespace,
                   CPXSIZE *surplus_p, CPXDIM begin, CPXDIM end)
{
   return CPX_CALL (getsosname) (env, lp, name, namestore, storespace, surplus_p, begin, end);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetsubmethod (CPXCENVptr env, CPXCLPptr lp)
{
   return CPX_CALL (getsubmethod) (env, lp);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetsubstat (CPXCENVptr env, CPXCLPptr lp)
{
   return CPX_CALL (getsubstat) (env, lp);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetusercutcallbackfunc (CPXCENVptr env,
                               CPXX_CALLBACK_CUT **cutcallback_p,
                               void  **cbhandle_p)
{
   return CPX_CALL (getusercutcallbackfunc) (env, cutcallback_p, cbhandle_p);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXindconstrslackfromx (CPXCENVptr env, CPXCLPptr lp,
                            double const *x, double *indslack)
{
   return CPX_CALL (indconstrslackfromx) (env, lp, x, indslack);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXmipopt (CPXCENVptr env, CPXLPptr lp)
{
   return CPX_CALL (mipopt) (env, lp);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXordread (CPXCENVptr env, char const *filename_str,
                CPXDIM numcols, char const *const *colname,
                CPXDIM *cnt_p, CPXDIM *indices, CPXDIM *priority,
                int *direction)
{
   return CPX_CALL (ordread) (env, filename_str, numcols, colname, cnt_p, indices, priority, direction);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXordwrite (CPXCENVptr env, CPXCLPptr lp,
                 char const *filename_str)
{
   return CPX_CALL (ordwrite) (env, lp, filename_str);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXpopulate (CPXCENVptr env, CPXLPptr lp)
{
   return CPX_CALL (populate) (env, lp);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXreadcopymipstarts (CPXCENVptr env, CPXLPptr lp,
                          char const *filename_str)
{
   return CPX_CALL (readcopymipstarts) (env, lp, filename_str);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXreadcopyorder (CPXCENVptr env, CPXLPptr lp,
                      char const *filename_str)
{
   return CPX_CALL (readcopyorder) (env, lp, filename_str);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXreadcopysolnpoolfilters (CPXCENVptr env, CPXLPptr lp,
                                char const *filename_str)
{
   return CPX_CALL (readcopysolnpoolfilters) (env, lp, filename_str);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXrefinemipstartconflict (CPXCENVptr env, CPXLPptr lp,
                               int mipstartindex,
                               CPXDIM *confnumrows_p,
                               CPXDIM *confnumcols_p)
{
   return CPX_CALL (refinemipstartconflict) (env, lp, mipstartindex, confnumrows_p, confnumcols_p);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXrefinemipstartconflictext (CPXCENVptr env, CPXLPptr lp,
                                  int mipstartindex, CPXNNZ grpcnt,
                                  CPXNNZ concnt, double const *grppref,
                                  CPXNNZ const *grpbeg,
                                  CPXDIM const *grpind,
                                  char const *grptype)
{
   return CPX_CALL (refinemipstartconflictext) (env, lp, mipstartindex, grpcnt, concnt, grppref, grpbeg, grpind, grptype);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXsetbranchcallbackfunc (CPXENVptr env,
                              CPXX_CALLBACK_BRANCH *branchcallback,
                              void *cbhandle)
{
   return CPX_CALL (setbranchcallbackfunc) (env, branchcallback, cbhandle);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXsetbranchnosolncallbackfunc (CPXENVptr env,
                                    CPXX_CALLBACK_BRANCH *branchnosolncallback,
                                    void *cbhandle)
{
   return CPX_CALL (setbranchnosolncallbackfunc) (env, branchnosolncallback, cbhandle);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXsetdeletenodecallbackfunc (CPXENVptr env,
                                  CPXX_CALLBACK_DELETENODE *deletecallback,
                                  void *cbhandle)
{
   return CPX_CALL (setdeletenodecallbackfunc) (env, deletecallback, cbhandle);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXsetheuristiccallbackfunc (CPXENVptr env,
                                 CPXX_CALLBACK_HEURISTIC *heuristiccallback,
                                 void *cbhandle)
{
   return CPX_CALL (setheuristiccallbackfunc) (env, heuristiccallback, cbhandle);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXsetincumbentcallbackfunc (CPXENVptr env,
                                 CPXX_CALLBACK_INCUMBENT *incumbentcallback,
                                 void *cbhandle)
{
   return CPX_CALL (setincumbentcallbackfunc) (env, incumbentcallback, cbhandle);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXsetinfocallbackfunc (CPXENVptr env, CPXX_CALLBACK *callback,
                            void *cbhandle)
{
   return CPX_CALL (setinfocallbackfunc) (env, callback, cbhandle);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXsetlazyconstraintcallbackfunc (CPXENVptr env,
                                      CPXX_CALLBACK_CUT *lazyconcallback,
                                      void *cbhandle)
{
   return CPX_CALL (setlazyconstraintcallbackfunc) (env, lazyconcallback, cbhandle);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXsetmipcallbackfunc (CPXENVptr env, CPXX_CALLBACK *callback,
                           void *cbhandle)
{
   return CPX_CALL (setmipcallbackfunc) (env, callback, cbhandle);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXsetnodecallbackfunc (CPXENVptr env,
                            CPXX_CALLBACK_NODE *nodecallback,
                            void *cbhandle)
{
   return CPX_CALL (setnodecallbackfunc) (env, nodecallback, cbhandle);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXsetsolvecallbackfunc (CPXENVptr env,
                             CPXX_CALLBACK_SOLVE *solvecallback,
                             void *cbhandle)
{
   return CPX_CALL (setsolvecallbackfunc) (env, solvecallback, cbhandle);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXsetusercutcallbackfunc (CPXENVptr env,
                               CPXX_CALLBACK_CUT *cutcallback,
                               void *cbhandle)
{
   return CPX_CALL (setusercutcallbackfunc) (env, cutcallback, cbhandle);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXwritemipstarts (CPXCENVptr env, CPXCLPptr lp,
                       char const *filename_str, int begin, int end)
{
   return CPX_CALL (writemipstarts) (env, lp, filename_str, begin, end);
}



/* Convenience functions to set parameters of type
 * CPXDIM, CPXNNZ and CPXCNT.
 */
#if CPX_APIMODEL == CPX_APIMODEL_SMALL
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetdimparam (CPXCENVptr env, int whichparam, CPXDIM *value_p) {
      return CPXSgetintparam (env, whichparam, value_p);
   }
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXsetdimparam  (CPXENVptr env, int whichparam, CPXDIM newvalue) {
      return CPXSsetintparam (env, whichparam, newvalue);
   }
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXinfodimparam (CPXCENVptr env, int whichparam, CPXDIM *defvalue_p,
                     CPXDIM *minvalue_p, CPXDIM *maxvalue_p) {
      return CPXSinfointparam (env, whichparam, defvalue_p,
                               minvalue_p, maxvalue_p);
   }

CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetnnzparam (CPXCENVptr env, int whichparam, CPXNNZ *value_p) {
      return CPXSgetintparam (env, whichparam, value_p);
   }
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXsetnnzparam  (CPXENVptr env, int whichparam, CPXNNZ newvalue) {
      return CPXSsetintparam (env, whichparam, newvalue);
   }
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXinfonnzparam (CPXCENVptr env, int whichparam, CPXNNZ *defvalue_p,
                     CPXNNZ *minvalue_p, CPXNNZ *maxvalue_p) {
      return CPXSinfointparam (env, whichparam, defvalue_p,
                               minvalue_p, maxvalue_p);
   }

CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetcntparam (CPXCENVptr env, int whichparam, CPXCNT *value_p) {
      return CPXSgetlongparam (env, whichparam, value_p);
   }
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXsetcntparam  (CPXENVptr env, int whichparam, CPXCNT newvalue) {
      return CPXSsetlongparam (env, whichparam, newvalue);
   }
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXinfocntparam (CPXCENVptr env, int whichparam, CPXCNT *defvalue_p,
                     CPXCNT *minvalue_p, CPXCNT *maxvalue_p) {
      return CPXSinfolongparam (env, whichparam, defvalue_p,
                                minvalue_p, maxvalue_p);
   }
#elif CPX_APIMODEL == CPX_APIMODEL_LARGE /* CPX_APIMODEL_SMALL */
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetdimparam (CPXCENVptr env, int whichparam, CPXDIM *value_p) {
      return CPXLgetintparam (env, whichparam, value_p);
   }
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXsetdimparam  (CPXENVptr env, int whichparam, CPXDIM newvalue) {
      return CPXLsetintparam (env, whichparam, newvalue);
   }
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXinfodimparam (CPXCENVptr env, int whichparam, CPXDIM *defvalue_p,
                     CPXDIM *minvalue_p, CPXDIM *maxvalue_p) {
      return CPXLinfointparam (env, whichparam, defvalue_p,
                               minvalue_p, maxvalue_p);
   }

CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetnnzparam (CPXCENVptr env, int whichparam, CPXNNZ *value_p) {
      return CPXLgetlongparam (env, whichparam, value_p);
   }
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXsetnnzparam  (CPXENVptr env, int whichparam, CPXNNZ newvalue) {
      return CPXLsetlongparam (env, whichparam, newvalue);
   }
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXinfonnzparam (CPXCENVptr env, int whichparam, CPXNNZ *defvalue_p,
                     CPXNNZ *minvalue_p, CPXNNZ *maxvalue_p) {
      return CPXLinfolongparam (env, whichparam, defvalue_p,
                                minvalue_p, maxvalue_p);
   }

CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetcntparam (CPXCENVptr env, int whichparam, CPXCNT *value_p) {
      return CPXLgetlongparam (env, whichparam, value_p);
   }
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXsetcntparam  (CPXENVptr env, int whichparam, CPXCNT newvalue) {
      return CPXLsetlongparam (env, whichparam, newvalue);
   }
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXinfocntparam (CPXCENVptr env, int whichparam, CPXCNT *defvalue_p,
                     CPXCNT *minvalue_p, CPXCNT *maxvalue_p) {
      return CPXLinfolongparam (env, whichparam, defvalue_p,
                                minvalue_p, maxvalue_p);
   }
#else /* CPX_APIMODEL_LARGE */
#   error "Unknown CPX_APIMODEL"
#endif

#ifdef __cplusplus
}
#endif

#ifdef _WIN32
#pragma pack(pop)
#endif

#endif /* !CPX_CPLEXX_H */
