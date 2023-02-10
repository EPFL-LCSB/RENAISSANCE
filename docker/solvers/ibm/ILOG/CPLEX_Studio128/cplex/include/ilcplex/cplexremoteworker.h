/* --------------------------------------------------------------------------
 * File: cplexremoteworker.h
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

#ifndef CPX_CPLEX_REMOTEWORKER_H
#   define CPX_CPLEX_REMOTEWORKER_H 1
#include "ilcplex/cplexremote.h"

#ifdef _WIN32
#pragma pack(push, 8)
#endif

#ifdef __cplusplus
extern "C" {
#endif









































































CPXLIBAPI
int CPXPUBLIC
   CPXgetuserfunction (CPXCMESSAGEHANDLERptr handler,
                       CPXUSERFUNCTION  **userfunction_p,
                       void  **handle_p);










































































CPXLIBAPI
int CPXPUBLIC
   CPXsendinfobyte (CPXCENVptr env, int tag, CPXLONG length,
                    CPXBYTE const *data);


CPXLIBAPI
int CPXPUBLIC
   CPXsendinfodouble (CPXCENVptr env, int tag, CPXLONG length,
                      double const *data);


CPXLIBAPI
int CPXPUBLIC
   CPXsendinfoint (CPXCENVptr env, int tag, CPXLONG length,
                   CPXINT const *data);


CPXLIBAPI
int CPXPUBLIC
   CPXsendinfolong (CPXCENVptr env, int tag, CPXLONG length,
                    CPXLONG const *data);


CPXLIBAPI
int CPXPUBLIC
   CPXsendinfoshort (CPXCENVptr env, int tag, CPXLONG length,
                     CPXSHORT const *data);










CPXLIBAPI
int CPXPUBLIC
   CPXsetuserfunction (CPXMESSAGEHANDLERptr handler,
                       CPXUSERFUNCTION *userfunction, void *handle);




















#ifdef __cplusplus
}
#endif

#ifdef _WIN32
#pragma pack(pop)
#endif

#endif /* !CPX_CPLEX_REMOTEWORKER_H */
