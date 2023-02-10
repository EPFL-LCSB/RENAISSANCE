/* --------------------------------------------------------------------------
 * File: cplexremotex.h
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

#ifndef CPX_CPLEX_REMOTEX_H
#   define CPX_CPLEX_REMOTEX_H 1
#include "ilcplex/cplexx.h"

#ifdef _WIN32
#pragma pack(push, 8)
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if CPX_APIMODEL == CPX_APIMODEL_SMALL
#   include "cplexremotes.h"
#elif CPX_APIMODEL == CPX_APIMODEL_LARGE
#   include "cplexremotel.h"
#else
#   error "Unknown CPX_APIMODEL"
#endif

















































































CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXloadLPhandle (CPXCENVptr env, CPXDESERIALIZERptr d,
                     CPXLPptr *lp_p)
{
   return CPX_CALL (loadLPhandle) (env, d, lp_p);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXloadNEThandle (CPXCENVptr env, CPXDESERIALIZERptr d,
                      CPXNETptr *net_p)
{
   return CPX_CALL (loadNEThandle) (env, d, net_p);
}

















































































CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXstoreLPhandle (CPXCENVptr env, CPXSERIALIZERptr s, CPXCLPptr lp)
{
   return CPX_CALL (storeLPhandle) (env, s, lp);
}


CPX_STATIC_INLINE
int CPXPUBLIC
   CPXXstoreNEThandle (CPXCENVptr env, CPXSERIALIZERptr s,
                       CPXCNETptr net)
{
   return CPX_CALL (storeNEThandle) (env, s, net);
}
















#ifdef __cplusplus
}
#endif

#ifdef _WIN32
#pragma pack(pop)
#endif

#endif /* !CPX_CPLEX_REMOTEX_H */
