/*****************************************************

     new.cpp - ANSI-C++ library: new/delete
 ----------------------------------------------------
   Copyright (c) Metrowerks, Basel, Switzerland
               
                  Do not modify!
 *****************************************************/
/* Defines a buffered memory allocation abstraction that reduces calls to
   malloc.
   Copyright (C) 1989 Free Software Foundation, Inc.
   written by Douglas C. Schmidt (schmidt@ics.uci.edu)

This file is part of GNU GPERF.

GNU GPERF is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 1, or (at your option)
any later version.

GNU GPERF is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with GNU GPERF; see the file COPYING.  If not, write to the Free
Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111, USA.  */

#include "comp.h"
#include <stdio.h>
#include <std.h>
#include "stderr.h"
#include "trace.h"


#ifdef _LIBRARY_WORKAROUND
typedef void (*new_handler)();

extern "C" new_handler set_new_handler (new_handler nh){
  return nh;
}
#endif

struct fooalign {char x; double d;};
#ifndef  _LIBRARY_WORKAROUND
  const int ALIGNMENT = ((char *)&((struct fooalign *) 0)->d - (char *)0);
#else
  #define ALIGNMENT ((char *)&((struct fooalign *) 0)->d - (char *)0)
#endif

int Trace::nesting;

void *operator new (size_t size){
  T (Trace t ("operator new");)
  size = ((size + ALIGNMENT - 1) / ALIGNMENT) * ALIGNMENT;
  char *p = (char *)malloc(size);
  if(p==NULL){
    exit(1);
  }
  return p;
}

void operator delete (void *ptr){
  T (Trace t ("operator delete");)
  free (ptr);
}

