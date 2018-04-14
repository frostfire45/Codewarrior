/*****************************************************
    signal.c - ANSI-C library: exception handling
 ----------------------------------------------------
   Copyright (c) Metrowerks, Basel, Switzerland
               All rights reserved

 *****************************************************/

#include <errno.h>
#include <signal.h>
#include <hidef.h>

#pragma NO_STRING_CONSTR

#include "non_bank.sgm"

/*lint -estring(961, "'#/##' operator used") , MISRA 19.13 ADV, '#' is used in HLI as an operator - see pragma NO_STRING_CONSTR above */
#define UNKNOWN  #4

/*****************************************************/

#pragma TRAP_PROC /* SAVE_ALL_REGS */

void _dft_sig_handler (void); /* prototype in scope MISRA 8.1 REQ */

void _dft_sig_handler (void)
{
  HALTX(UNKNOWN); /*lint !e960 , MISRA 14.3 REQ, macro HALTX expands to several HLI statements */
} /* end _dft_sig_handler */

#include "default.sgm" /*lint !e961 , MISRA 19.1 ADV, the included file contains a CODE_SEG pragma */ 
/*****************************************************/

_sig_func signal (int sig, _sig_func func)
{
   _sig_func *v;

   v = (_sig_func *) (sizeof (_sig_func) * (unsigned int)sig);       /*lint !e923, MISRA 11.3 ADV, safe cast (no truncation) because the maximum signal number is 23 (SIGALRM) */
   if ((func == (_sig_func)SIG_IGN) || (func == (_sig_func)SIG_DFL)) /*lint !e923 !e929 , MISRA 11.3 ADV, MISRA 11.4 ADV, safe casts */
   {
     func = _dft_sig_handler;
   }
   if ((sig < 0) || (sig > 255)) 
   {
     errno = ERANGE; return (_sig_func) SIG_ERR; /*lint !e923 !e929 , MISRA 11.3 ADV, MISRA 11.4 ADV, safe casts */
   } /* end if */
   return (*v = func);
} /* end signal */

/*****************************************************/
#pragma MESSAGE DISABLE C5703 /* sig: parameter declared in function raise but not referenced */
int raise (int sig)
{
  HALTX(UNKNOWN); /*lint !e960 MISRA 14.3 REQ, macro HALTX expands to several HLI statements */
  return 0;
} /* end raise */ /*lint !e715 the function contains inline assembly only */

/*****************************************************/
/* end signal.c */
/*lint +estring(961, "'#/##' operator used") */
/*lint --e{766} non_bank.sgm is not a regular header file, it contains a conditionally CODE_SEG pragma */
