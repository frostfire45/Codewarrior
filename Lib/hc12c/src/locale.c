/*****************************************************
      locale.c - ANSI-C library: localisation
 ----------------------------------------------------
   Copyright (c) Metrowerks, Basel, Switzerland
               All rights reserved
                  Do not modify!
 *****************************************************/

#include <hidef.h>
#include <locale.h>
#include <stddef.h>

#ifndef __S12LISA__
#pragma MESSAGE DISABLE C5703 /* p: parameter declared in function setlocale but not referenced */
#endif

char *setlocale(int a, const char *p) {
  return NULL; /* NYI */
} /*lint !e715 inhibit message on 'a' and 'p' not being referenced */

struct lconv *localeconv(void) {
  return NULL; /* NYI */
}
/*****************************************************/
/* end locale.c */
