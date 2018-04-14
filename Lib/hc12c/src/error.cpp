/*****************************************************

     error.cpp - ANSI-C++ library: errors
 ----------------------------------------------------
   Copyright (c) Metrowerks, Basel, Switzerland
               
                  Do not modify!
 *****************************************************/

/* 
Copyright (C) 1990 Free Software Foundation
    written by Doug Lea (dl@rocky.oswego.edu)

This file is part of the GNU C++ Library.  This library is free
software; you can redistribute it and/or modify it under the terms of
the GNU Library General Public License as published by the Free
Software Foundation; either version 2 of the License, or (at your
option) any later version.  This library is distributed in the hope
that it will be useful, but WITHOUT ANY WARRANTY; without even the
implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
PURPOSE.  See the GNU Library General Public License for more details.
You should have received a copy of the GNU Library General Public
License along with this library; if not, write to the Free Software
Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
*/

#ifdef __GNUG__
#pragma implementation
#endif
#include "comp.h"
#include <builtin.h>

void default_one_arg_error_handler(const char*_LIBDEF_FAR_CPP_PTR msg)
{
#ifndef _C_LIB_LIMIT_IMPL
  fputs("Error: ", stderr);
#ifndef _LIBRARY_WORKAROUND  /* ptr to const passed to ptr to non-const */
  fputs(msg, stderr);
#else
  fputs((char *)msg, stderr);
#endif
  fputs("\n", stderr);
#else
  exit(1);
#endif
  abort();
}


void default_two_arg_error_handler(const char*_LIBDEF_FAR_CPP_PTR kind, const char*_LIBDEF_FAR_CPP_PTR msg)
{
#ifndef _C_LIB_LIMIT_IMPL
#ifndef _LIBRARY_WORKAROUND  /* ptr to const passed to ptr to non-const */  
  fputs(kind, stderr);
#else
  fputs((char *)kind, stderr);
#endif
  fputs(" Error: ", stderr);
#ifndef _LIBRARY_WORKAROUND  /* ptr to const passed to ptr to non-const */  
  fputs(msg, stderr);
#else
  fputs((char *)msg, stderr);
#endif
  fputs("\n", stderr);
#else
  exit(1);
#endif
  abort();
}

two_arg_error_handler_t lib_error_handler = default_two_arg_error_handler;

two_arg_error_handler_t set_lib_error_handler(two_arg_error_handler_t f)
{
  two_arg_error_handler_t old = lib_error_handler;
  lib_error_handler = f;
  return old;
}

