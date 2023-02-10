/* --------------------------------------------------------------------------
 * File: cplexdistmip.h
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

#ifndef CPX_CPLEXDISTMIP_H
#   define CPX_CPLEXDISTMIP_H 1

#ifdef _WIN32
#pragma pack(push, 8)
#endif

#ifdef __cplusplus
extern "C" {
#endif

CPXLIBAPI
int CPXPUBLIC
   CPXcopyvmconfig (CPXENVptr env, char const *xmlstr);


CPXLIBAPI
int CPXPUBLIC
   CPXdelvmconfig (CPXENVptr env);


CPXLIBAPI
int CPXPUBLIC
   CPXdistmipopt (CPXCENVptr env, CPXLPptr lp);


#ifdef CPX_DISTMIP_ENABLE_ASYNC
CPXLIBAPI
int CPXPUBLIC
   CPXdistmipopt_async (CPXCENVptr env, CPXLPptr lp,
                        CPXASYNCptr *handle_p);
#endif /* CPX_DISTMIP_ENABLE_ASYNC*/


#ifdef CPX_DISTMIP_ENABLE_ASYNC
CPXLIBAPI
int CPXPUBLIC
   CPXdistmipopt_join (CPXASYNCptr *handle_p);
#endif /* CPX_DISTMIP_ENABLE_ASYNC*/


CPXLIBAPI
int CPXPUBLIC
   CPXfinalizeMPIworkers (int nranks, int const *ranks, int argc,
                          char **argv, int abortonerror);


CPXLIBAPI
int CPXPUBLIC
   CPXreadcopyvmconfig (CPXENVptr env, char const *filename);



#ifdef __cplusplus
}
#endif

#ifdef _WIN32
#pragma pack(pop)
#endif

#endif /* !CPX_CPLEXDISTMIP_H */
