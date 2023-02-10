/* --------------------------------------------------------------------------
 * File: cplexdistmipl.h
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

#ifndef CPX_CPLEXDISTMIPL_H
#   define CPX_CPLEXDISTMIPL_H 1
#include "cpxconst.h"

#ifdef _WIN32
#pragma pack(push, 8)
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if CPX_CPLEX_L_API_DEFINED > 0 || CPX_CPLEX_L_API_FORCE > 0
CPXLIBAPI
int CPXPUBLIC
   CPXLcopyvmconfig (CPXENVptr env, char const *xmlstr);


CPXLIBAPI
int CPXPUBLIC
   CPXLdelvmconfig (CPXENVptr env);


CPXLIBAPI
int CPXPUBLIC
   CPXLdistmipopt (CPXCENVptr env, CPXLPptr lp);


#ifdef CPX_DISTMIP_ENABLE_ASYNC
CPXLIBAPI
int CPXPUBLIC
   CPXLdistmipopt_async (CPXCENVptr env, CPXLPptr lp,
                         CPXASYNCptr *handle_p);
#endif /* CPX_DISTMIP_ENABLE_ASYNC*/


#ifdef CPX_DISTMIP_ENABLE_ASYNC
CPXLIBAPI
int CPXPUBLIC
   CPXLdistmipopt_join (CPXASYNCptr *handle_p);
#endif /* CPX_DISTMIP_ENABLE_ASYNC*/


CPXLIBAPI
int CPXPUBLIC
   CPXLfinalizeMPIworkers (int nranks, int const *ranks, int argc,
                           char const *const *argv, int abortonerror);


CPXLIBAPI
int CPXPUBLIC
   CPXLreadcopyvmconfig (CPXENVptr env, char const *filename);



#endif /* CPX_CPLEX_L_API_DEFINED > 0 */

#ifdef __cplusplus
}
#endif

#ifdef _WIN32
#pragma pack(pop)
#endif

#endif /* !CPX_CPLEXDISTMIPL_H */
