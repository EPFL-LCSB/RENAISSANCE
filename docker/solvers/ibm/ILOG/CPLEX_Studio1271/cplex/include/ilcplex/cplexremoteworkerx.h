/* --------------------------------------------------------------------------
 * File: cplexremoteworkerx.h
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

#ifndef CPX_CPLEX_REMOTEWORKERX_H
#   define CPX_CPLEX_REMOTEWORKERX_H 1
#include "ilcplex/cplexremotex.h"

#ifdef _WIN32
#pragma pack(push, 8)
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if CPX_APIMODEL == CPX_APIMODEL_SMALL
#   include "cplexremoteworkers.h"
#elif CPX_APIMODEL == CPX_APIMODEL_LARGE
#   include "cplexremoteworkerl.h"
#else
#   error "Unknown CPX_APIMODEL"
#endif




































































































































































































































































































































































































































#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXgetuserfunction (CPXCMESSAGEHANDLERptr handler,
                        CPXUSERFUNCTION  **userfunction_p,
                        void  **handle_p)
{
   return CPX_CALL (getuserfunction) (handler, userfunction_p, handle_p);
}

#endif /* !CPX_NO_REMOTE */









































































































































































































































#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXsendinfobyte (CPXCENVptr env, int tag, CPXLONG length,
                     CPXBYTE const *data)
{
   return CPX_CALL (sendinfobyte) (env, tag, length, data);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXsendinfodouble (CPXCENVptr env, int tag, CPXLONG length,
                       double const *data)
{
   return CPX_CALL (sendinfodouble) (env, tag, length, data);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXsendinfoint (CPXCENVptr env, int tag, CPXLONG length,
                    CPXINT const *data)
{
   return CPX_CALL (sendinfoint) (env, tag, length, data);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXsendinfolong (CPXCENVptr env, int tag, CPXLONG length,
                     CPXLONG const *data)
{
   return CPX_CALL (sendinfolong) (env, tag, length, data);
}

#endif /* !CPX_NO_REMOTE */

#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXsendinfoshort (CPXCENVptr env, int tag, CPXLONG length,
                      CPXSHORT const *data)
{
   return CPX_CALL (sendinfoshort) (env, tag, length, data);
}

#endif /* !CPX_NO_REMOTE */



















#if !defined(CPX_NO_REMOTE)
CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXsetuserfunction (CPXMESSAGEHANDLERptr handler,
                        CPXUSERFUNCTION *userfunction, void *handle)
{
   return CPX_CALL (setuserfunction) (handler, userfunction, handle);
}

#endif /* !CPX_NO_REMOTE */




















































#ifdef __cplusplus
}
#endif

#ifdef _WIN32
#pragma pack(pop)
#endif

#endif /* !CPX_CPLEX_REMOTEWORKERX_H */
