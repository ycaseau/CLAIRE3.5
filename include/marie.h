/*****C******************************************************************/
/**   microCLAIRE                                       Yves Caseau    */
/**   marie .h                                                         */
/**  Copyright (C) 1998-99 Yves Caseau. All Rights Reserved.           */
/**  Redistribution and use in source and binary forms are permitted   */
/**  provided that source distribution retains this entire copyright   */
/**  notice and comments.                                              */
/**  THIS SOFTWARE IS PROVIDED AS IS AND WITHOUT ANY WARRANTY,         */
/**  INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF          */
/**  MERCHANTABILTY AND FITNESS FOR A PARTICULAR PURPOSE               */
/***********************************************************************/

// this file contains the private header for the Kernel module

#include <signal.h>
#include <stdarg.h>
#ifdef CLMAC
#include <stdlib.h>
#include <types.h>
#include <time.h>
#define SIGQUIT SIGINT
#endif
#ifdef CLPC
#define SIGQUIT SIGINT
#include <time.h>
#endif
#ifdef CLUNIX
// #define CLFLPAR 1               // LINUX requires this flag: cf clReflect.cpp
#include <time.h>               // with LINUX, #include <time.h> works  ...
// #include <sys/types.h>       // ... but on some other UNIX OSs it does not !!!!
// #include <sys/times.h>       // this may prove useful
// #define CLOCKS_PER_SEC 100   // sometimes this is needed !!!!
#endif
#ifdef CLOSX
#include <time.h>
#endif

/***********************************************************************/
/** Contents                                                           */
/**    1. Constants                                                    */
/**    2. Structures                                                   */
/**    3. Macros                                                       */
/***********************************************************************/

/***********************************************************************/
/**    1. Constants                                                    */
/***********************************************************************/

/* in some machines (compilers) RAND is not be defined (appears to be true
   for both cc and g++ on sun. Note the actual constant may be machine
   dependent */
#ifndef RAND_MAX
#define RAND_MAX 0x7FFFFFFF
#endif

extern double CKernelRelease;

/************************************************************************/
/**    3. Macros & external functions                                   */
/************************************************************************/


#define msec( t )  {double x; \
x = ((double) clock()) * 1000.0 / ((double) CLOCKS_PER_SEC); t = floor(x); }


#define ADR(A) (A & ADR_MASK)         /* the address                   */


/* tells where the string is allocated */
#define CLMEM(s) ((CCAST(s) > CCAST(&Cmemory[0])) && (CCAST(s) < CCAST(&Cmemory[ClAlloc->maxSize])))

// these are the two macros to convert between the CLAIRE & C++ representation

#define CLAIREOID(x,s) ((s == Kernel._object) ? _oid_(x) : \
                       ((s == Kernel._any) ? x : \
                       ((s == Kernel._integer) ? _integer_((Cint) x) : \
                       ((s == Kernel._array) ? _array_(x) : \
                       ((s == Kernel._void) ? CNULL : ClAlloc->import(s,(OID *) x))))))

#define CPOINTER(x,s) ((s == Kernel._object) ? CCAST(&Cmemory[(x & ADR_MASK) + 1]) : \
                      ((s == Kernel._any || s == Kernel._integer) ? x : \
                      ((s == Kernel._array) ? CCAST(array_v(x)) : \
                      ((s == Kernel._void) ? NULL : OBJECT(ClaireImport,x)->value))))

// read the n-th slot of the object x
#define SLOTADR(x,n) ((OID *) x + (n - 1))
// no longer used #define SORT(r) ((class ClaireClass *) Lmemory[ADR(r) + 7])

#define ARRAYTYPE(a)  ((ClaireType *) a[-1])
#define ARRAYLENGTH(a)  a[0]
#define ARRAYFLOAT(a) (a[-1] == CCAST(Kernel._float))


// we now have three macros STOREOID, STOREOBJ and STOREFLOAT
// STOREOID(x,y)  does the book-keeping so that the value y (an OID) for x (a container) in remembered
// for a defeasible update
#define STOREOID(x,y) {ClRes->haiStack[++ClRes->iIndex] = x; ClRes->hviStack[ClRes->iIndex] = y;\
                       if (ClRes->iIndex >= ClAlloc->maxHist) Cerror(37,1,0); }

// same when y is an object (X*) and x a containter
#define STOREOBJ(x,y) {ClRes->haoStack[++ClRes->oIndex] = x; ClRes->hvoStack[ClRes->oIndex] = y;\
                       if (ClRes->oIndex >= ClAlloc->maxHist) Cerror(37,2,0); }

#define STOREFLOAT(x,y) {ClRes->hafStack[++ClRes->fIndex] = (OID *) x;\
                         ClRes->hvfStack[ClRes->fIndex] = y;\
                         if (ClRes->fIndex >= ClAlloc->maxHist) Cerror(37,3,0); }

// methods that are defined in the CLAIRE code (a dumb equivalent exists in the test file)
extern ClaireType *of_extract_type(ClaireType *t);
extern void push_debug_property(property *p,Cint n, Cint m);
extern void pop_debug_property(property *p,Cint n,OID v);
extern ClaireClass *class_I_type(ClaireType *t);
extern void insert_definition_property(property *p,restriction *s);
extern ClaireObject* find_which_class(ClaireClass *c,list *l,Cint i, Cint j);
extern ClaireObject* find_which_property(property *p,Cint i, ClaireClass *c);
extern OID eval_message_property(property *p,ClaireObject *r,Cint i,ClaireBoolean *b);
extern method *inlineok_ask_method(method *m, char *s);
extern ClaireObject * hashget_class(ClaireClass *c,property *p);


extern void see(OID x);
extern void see(OID x, Cint i);
extern void see(char *c,OID x,Cint i);
extern void see(char *c,OID x);

// for debug
#ifdef CL64
#define getADR(A) (((CCAST(A) - CCAST(&Cmemory[0])) >> 3) - 1)  // gets the ADR from the object - used for debug (fixed in 3.4)
#else
#define getADR(A) (((CCAST(A) - CCAST(&Cmemory[0])) >> 2) - 1)
#endif
#define _chunk_(A) (NIET_CODE + getADR(A))              // makes a chunk address into an OID

// stupid list but necessary for true C++ portability ------------------
// note that we got rid of half of this junk by being optimistic .....
typedef OID (*fptr1) (OID);
typedef OID (*fptr2) (OID,OID);
typedef OID (*fptr3) (OID,OID,OID);
typedef OID (*fptr4) (OID,OID,OID,OID);
typedef OID (*fptr5) (OID,OID,OID,OID,OID);
typedef OID (*fptr6) (OID,OID,OID,OID,OID,OID);
typedef OID (*fptr7) (OID,OID,OID,OID,OID,OID,OID);
typedef OID (*fptr8) (OID,OID,OID,OID,OID,OID,OID,OID);
typedef OID (*fptr9) (OID,OID,OID,OID,OID,OID,OID,OID,OID);
typedef OID (*fptr10) (OID,OID,OID,OID,OID,OID,OID,OID,OID,OID);
typedef OID (*fptr11) (OID,OID,OID,OID,OID,OID,OID,OID,OID,OID,OID);
typedef OID (*fptr12) (OID,OID,OID,OID,OID,OID,OID,OID,OID,OID,OID,OID);
typedef OID (*fptr13) (OID,OID,OID,OID,OID,OID,OID,OID,OID,OID,OID,OID,OID);
typedef OID (*fptr14) (OID,OID,OID,OID,OID,OID,OID,OID,OID,OID,OID,OID,OID,OID);
typedef OID (*fptr15) (OID,OID,OID,OID,OID,OID,OID,OID,OID,OID,OID,OID,OID,OID,OID);
typedef OID (*fptr16) (OID,OID,OID,OID,OID,OID,OID,OID,OID,OID,OID,OID,OID,OID,OID,OID);
typedef OID (*fptr17) (OID,OID,OID,OID,OID,OID,OID,OID,OID,OID,OID,OID,OID,OID,OID,OID,OID);
typedef OID (*fptr18) (OID,OID,OID,OID,OID,OID,OID,OID,OID,OID,OID,OID,OID,OID,OID,OID,OID,OID);
typedef OID (*fptr19) (OID,OID,OID,OID,OID,OID,OID,OID,OID,OID,OID,OID,OID,OID,OID,OID,OID,OID,OID);
typedef OID (*fptr20) (OID,OID,OID,OID,OID,OID,OID,OID,OID,OID,OID,OID,OID,OID,OID,OID,OID,OID,OID,OID);


// used to compile properly the system profiling methods defined in ClPort
// note that this definition is produced in Reader.h
class PRcount: public ClaireObject{ 
  public:
     Cint rtime;
     Cint rdepth;
     Cint rnum;
     Cint rloop;
     Cint rstart;};


