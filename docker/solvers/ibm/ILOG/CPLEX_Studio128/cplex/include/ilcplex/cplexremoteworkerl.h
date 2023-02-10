/* --------------------------------------------------------------------------
 * File: cplexremoteworkerl.h
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

#ifndef CPX_CPLEX_REMOTEWORKERL_H
#   define CPX_CPLEX_REMOTEWORKERL_H 1
#include "ilcplex/cplexremotel.h"

#ifdef _WIN32
#pragma pack(push, 8)
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if CPX_CPLEX_L_API_DEFINED > 0 || CPX_CPLEX_L_API_FORCE > 0








































































CPXLIBAPI
int CPXPUBLIC
   CPXLgetuserfunction (CPXCMESSAGEHANDLERptr handler,
                        CPXUSERFUNCTION  **userfunction_p,
                        void  **handle_p);










































































CPXLIBAPI
int CPXPUBLIC
   CPXLsendinfobyte (CPXCENVptr env, int tag, CPXLONG length,
                     CPXBYTE const *data);


CPXLIBAPI
int CPXPUBLIC
   CPXLsendinfodouble (CPXCENVptr env, int tag, CPXLONG length,
                       double const *data);


CPXLIBAPI
int CPXPUBLIC
   CPXLsendinfoint (CPXCENVptr env, int tag, CPXLONG length,
                    CPXINT const *data);


CPXLIBAPI
int CPXPUBLIC
   CPXLsendinfolong (CPXCENVptr env, int tag, CPXLONG length,
                     CPXLONG const *data);


CPXLIBAPI
int CPXPUBLIC
   CPXLsendinfoshort (CPXCENVptr env, int tag, CPXLONG length,
                      CPXSHORT const *data);










CPXLIBAPI
int CPXPUBLIC
   CPXLsetuserfunction (CPXMESSAGEHANDLERptr handler,
                        CPXUSERFUNCTION *userfunction, void *handle);




















#endif /* CPX_CPLEX_L_API_DEFINED > 0 */

#ifdef __cplusplus
}
#endif

#ifdef _WIN32
#pragma pack(pop)
#endif

#endif /* !CPX_CPLEX_REMOTEWORKERL_H */
