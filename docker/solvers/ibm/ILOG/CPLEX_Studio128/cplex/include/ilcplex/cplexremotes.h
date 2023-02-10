/* --------------------------------------------------------------------------
 * File: cplexremotes.h
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

#ifndef CPX_CPLEX_REMOTES_H
#   define CPX_CPLEX_REMOTES_H 1
#include "ilcplex/cplexs.h"

#ifdef _WIN32
#pragma pack(push, 8)
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if CPX_CPLEX_S_API_DEFINED > 0 || CPX_CPLEX_S_API_FORCE > 0

















































































CPXLIBAPI
int CPXPUBLIC
   CPXSloadLPhandle (CPXCENVptr env, CPXDESERIALIZERptr d,
                     CPXLPptr *lp_p);


CPXLIBAPI
int CPXPUBLIC
   CPXSloadNEThandle (CPXCENVptr env, CPXDESERIALIZERptr d,
                      CPXNETptr *net_p);

















































































CPXLIBAPI
int CPXPUBLIC
   CPXSstoreLPhandle (CPXCENVptr env, CPXSERIALIZERptr s, CPXCLPptr lp);


CPXLIBAPI
int CPXPUBLIC
   CPXSstoreNEThandle (CPXCENVptr env, CPXSERIALIZERptr s,
                       CPXCNETptr net);















#endif /* CPX_CPLEX_S_API_DEFINED > 0 */

#ifdef __cplusplus
}
#endif

#ifdef _WIN32
#pragma pack(pop)
#endif

#endif /* !CPX_CPLEX_REMOTES_H */
