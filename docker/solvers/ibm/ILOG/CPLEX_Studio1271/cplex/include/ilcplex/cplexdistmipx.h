/* --------------------------------------------------------------------------
 * File: cplexdistmipx.h
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

#ifndef CPX_CPLEXDISTMIPX_H
#   define CPX_CPLEXDISTMIPX_H 1
#include "cpxconst.h"

#ifdef _WIN32
#pragma pack(push, 8)
#endif

#ifdef __cplusplus
extern "C" {
#endif

#include <ilcplex/cplexx.h>
#if CPX_APIMODEL == CPX_APIMODEL_SMALL
#   include "cplexdistmips.h"
#elif CPX_APIMODEL == CPX_APIMODEL_LARGE
#   include "cplexdistmipl.h"
#else
#   error "Unknown CPX_APIMODEL"
#endif
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXcopyvmconfig (CPXENVptr env, char const *xmlstr)
{
   return CPX_CALL (copyvmconfig) (env, xmlstr);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXdelvmconfig (CPXENVptr env)
{
   return CPX_CALL (delvmconfig) (env);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXdistmipopt (CPXCENVptr env, CPXLPptr lp)
{
   return CPX_CALL (distmipopt) (env, lp);
}


#if !defined(CPX_NO_REMOTE)
#ifdef CPX_DISTMIP_ENABLE_ASYNC
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXdistmipopt_async (CPXCENVptr env, CPXLPptr lp,
                         CPXASYNCptr *handle_p)
{
   return CPX_CALL (distmipopt_async) (env, lp, handle_p);
}

#endif /* CPX_DISTMIP_ENABLE_ASYNC */
#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
#ifdef CPX_DISTMIP_ENABLE_ASYNC
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXdistmipopt_join (CPXASYNCptr *handle_p)
{
   return CPX_CALL (distmipopt_join) (handle_p);
}

#endif /* CPX_DISTMIP_ENABLE_ASYNC */
#endif /* !CPX_NO_REMOTE */

CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXfinalizeMPIworkers (int nranks, int const *ranks, int argc,
                           char const *const *argv, int abortonerror)
{
   return CPX_CALL (finalizeMPIworkers) (nranks, ranks, argc, argv, abortonerror);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXreadcopyvmconfig (CPXENVptr env, char const *filename)
{
   return CPX_CALL (readcopyvmconfig) (env, filename);
}




#ifdef __cplusplus
}
#endif

#ifdef _WIN32
#pragma pack(pop)
#endif

#endif /* !CPX_CPLEXDISTMIPX_H */
