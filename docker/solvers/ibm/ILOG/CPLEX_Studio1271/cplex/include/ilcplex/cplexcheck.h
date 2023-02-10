/* --------------------------------------------------------------------------
 * File: cplexcheck.h
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

#ifndef CPX_CPLEXCHECK_H
#define CPX_CPLEXCHECK_H
#endif

/* Include file for diagnostic routines in check.c example program. 
   Assumes static linking on all platforms except Windows.   On
   Windows, the default is static linking, but you can choose to 
   build check.c into a DLL instead by using -DCPX_CHECK_DLL and 
   -DBUILD_CPXLIB when compiling check.c. Subsequently, when your 
   program calls the check function as a DLL, compile your code with 
   -DCPX_CHECK_DLL (but not with -DBUILD_CPXLIB.*/

#ifdef CPX_CHECK_DLL
#define CPXCHECKLIBAPI CPXLIBAPI
#else
#define CPXCHECKLIBAPI
#endif

/* check.c should work regardless of whether original 32 bit
or new 64 bit API is supported.  Use -DCPLEXX_NAMES when compiling
or #define CPLEXX_NAMES to use the 64-bit API, which will work in
conjunction with CPX_APIMODEL specification. */

#if CPLEXX_NAMES
#include <ilcplex/cplexx.h>
#define CPXcheckcopylpwnames CPXXcheckcopylpwnames
#define CPXcheckcopylp       CPXXcheckcopylp
#define CPXcheckcopyctype    CPXXcheckcopyctype
#define CPXcheckcopysos      CPXXcheckcopysos
#define CPXcheckaddcols      CPXXcheckaddcols
#define CPXcheckaddrows      CPXXcheckaddrows
#define CPXcheckchgcoeflist  CPXXcheckchgcoeflist
#define CPXcheckvals         CPXXcheckvals
#define CPXcheckcopyqpsep    CPXXcheckcopyqpsep
#define CPXcheckcopyquad     CPXXcheckcopyquad
#define CPXcheckaddqconstr   CPXXcheckaddqconstr
#define CPXNETcheckcopynet   CPXXNETcheckcopynet
#else
#include <ilcplex/cplex.h>
#ifndef CPXDIM_DEFINED
typedef int CPXDIM;
#endif
#ifndef CPXNNZ_DEFINED
typedef int CPXNNZ;
#endif
#ifndef CPXCNT_DEFINED
typedef int CPXCNT;
#endif
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* LP Data Debugging Routines */

CPXCHECKLIBAPI
int CPXPUBLIC
   CPXcheckcopylp       (CPXCENVptr env, CPXCLPptr lp, CPXDIM numcols,
                         CPXDIM numrows, int objsen, const double *obj,
                         const double *rhs, const char *sense,
                         const CPXNNZ *matbeg, const CPXDIM *matcnt,
                         const CPXDIM *matind, const double *matval,
                         const double *lb, const double *ub,
                         const double *rngval);
CPXCHECKLIBAPI
int CPXPUBLIC
   CPXcheckcopylpwnames (CPXCENVptr env, CPXCLPptr lp, CPXDIM numcols,
                         CPXDIM numrows, int objsen, const double *obj,
                         const double *rhs, const char *sense,
                         const CPXNNZ *matbeg, const CPXDIM *matcnt,
                         const CPXDIM *matind, const double *matval,
                         const double *lb, const double *ub,
                         const double *rngval,
                         char **colname, char **rowname);

CPXCHECKLIBAPI
int CPXPUBLIC
   CPXcheckaddcols      (CPXCENVptr env, CPXCLPptr lp, CPXDIM ccnt,
                         CPXNNZ nzcnt, const double *obj,
                         const CPXNNZ *cmatbeg, const CPXDIM *cmatind,
                         const double *cmatval, const double *lb,
                         const double *ub, char **colname);
CPXCHECKLIBAPI
int CPXPUBLIC
   CPXcheckaddrows      (CPXCENVptr env, CPXCLPptr lp, CPXDIM ccnt,
                         CPXDIM rcnt, CPXNNZ nzcnt, const double *rhs,
                         const char *sense, const CPXNNZ *rmatbeg,
                         const CPXDIM *rmatind, const double *rmatval,
                         char **colname, char **rowname);
CPXCHECKLIBAPI
int CPXPUBLIC
   CPXcheckchgcoeflist  (CPXCENVptr env, CPXCLPptr lp, CPXNNZ numcoefs,
                         const CPXDIM *rowlist, const CPXDIM *collist,
                         const double *vallist);
CPXCHECKLIBAPI
int CPXPUBLIC
   CPXcheckvals         (CPXCENVptr env, CPXCLPptr lp, CPXNNZ cnt,
                         const CPXDIM *rowind, const CPXDIM *colind,
                         const double *values);


/* MIP Data Debugging Routines */

CPXCHECKLIBAPI
int CPXPUBLIC
   CPXcheckcopyctype    (CPXCENVptr env, CPXCLPptr lp, const char *xctype);

CPXCHECKLIBAPI
int CPXPUBLIC
   CPXcheckcopysos      (CPXCENVptr env, CPXCLPptr lp, CPXDIM numsos,
                         CPXNNZ numsosnz, const char *sostype,
                         const CPXNNZ *sosbeg, const CPXDIM *sosind,
                         const double *soswt, char **sosname);


/* QP Data Debugging Routines */
CPXCHECKLIBAPI
int CPXPUBLIC
   CPXcheckcopyqpsep    (CPXCENVptr env, CPXCLPptr lp,
                         const double *qsepvec);
CPXCHECKLIBAPI
int CPXPUBLIC
   CPXcheckcopyquad     (CPXCENVptr env, CPXCLPptr lp, const CPXNNZ *qmatbeg,
                         const CPXDIM *qmatcnt, const CPXDIM *qmatind,
                         const double *qmatval);






CPXCHECKLIBAPI
int CPXPUBLIC 
CPXcheckaddqconstr (CPXCENVptr   env,
                    CPXLPptr     lp,
                    CPXDIM       linnzcnt,
                    CPXNNZ       quadnzcnt,
                    double       rhs,
                    int          sense,
                    const CPXDIM *linind,
                    const double *linval,
                    const CPXDIM *quadrow,
                    const CPXDIM *quadcol,
                    const double *quadval,
                    const char   *constrname);



CPXCHECKLIBAPI
int CPXPUBLIC
   CPXNETcheckcopynet (CPXCENVptr env, CPXNETptr net, int objsen,
                       CPXDIM nnodes, const double *supply, char **nnames,
                       CPXDIM narcs, const CPXDIM *fromnode, 
                       const CPXDIM *tonode, const double *low, 
                       const double *up, const double *obj, char **aname);


#ifdef __cplusplus
}
#endif
