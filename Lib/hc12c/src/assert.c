/*****************************************************
    assert.c - ANSI-C library: primitive debugging
 ----------------------------------------------------
   Copyright (c) Metrowerks, Basel, Switzerland
               All rights reserved
                  Do not modify!
 *****************************************************/

#include <hidef.h>
#include <stdlib.h>
#include <libdefs.h>
#include <assert.h>

#ifndef __S12LISA__
#pragma MESSAGE DISABLE C5703 /* name: parameter declared in function _assert but not referenced */
#endif

int _assert (unsigned long line, LIBDEF_ConstStringPtr name)
{
  abort ();
  /*lint -unreachable */
  return 1; 
} /*lint !e715 name not used */
/*****************************************************/
/* end assert.c */
/*lint --e{766} hidef.h contains conditionally compiled code */
