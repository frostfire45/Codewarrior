/*****************************************************
   embedded.c - Embedded functions
 ----------------------------------------------------
   Copyright (c) Metrowerks, Basel, Switzerland
               All rights reserved
                  Do not modify!
 *****************************************************/

/* this module implements functions not available on
   an embedded target. It replaces those functionality
   with some functionality of the simulator.
   
   printf => redirection to simulation terminal
   scanf  => redirection to simulation terminal
 */
   
#include <hidef.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <embedded.h>

/* interface to terminal simulation: */
#include <termio.h>
#include <terminal.h>

#ifndef __S12LISA__
#pragma MESSAGE DISABLE C5703  /* INFORMATION C5703: parameter declared in function but not referenced */
#endif
/*-----------------------------------------------------------------*/
/* terminal functins */
int printf(LIBDEF_ConstStringPtr format, ...) { /*lint !e960 MISRA 16.1 REQ, standard library function implementation */
  int i;
  va_list args;
  
  set_printf(TERMIO_PutChar); /* set up TERMIO_PutChar for writing */
  /*lint -e{643} misleading warning ('&format' does not have a far type) */  
  /*lint -e{928} , MISRA 11.4 ADV, safe conversion to 'char *' */  
  va_start(args, format);
  i = vprintf(format, args);
  va_end(args);
  return i; /*lint !e438 'va_end' must be invoked before return in a variadic function */
}

int scanf(LIBDEF_ConstStringPtr format, ...) { /*lint !e960 MISRA 16.1 REQ, standard library function implementation */
  char outbuf[LIBDEF_SCANF_BUF_SIZE];
  int i;
  va_list args;

  /*lint -e{643} misleading warning ('&format' does not have a far type) */
  /*lint -e{928} , MISRA 11.4 ADV, safe conversion to 'char *' */  
  va_start(args, format);
  TERM_ReadString(outbuf, (int)sizeof(outbuf));
  i = vsscanf(outbuf, format, args);
  va_end(args);
  return i; /*lint !e438 'va_end' must be invoked before return in a variadic function */
}

LIBDEF_StringPtr gets(LIBDEF_StringPtr s) {
/* The gets() function reads a line from the standard input stream stdin and stores it in buffer s.
   The line consists of all characters up to and including the first newline character ('\n').
   gets() then replaces the newline character with a null character ('\0') before returning
   the line. In contrast, the fgets function retains the newline character. */
  char ch;
  LIBDEF_StringPtr p = s; /*lint !e625 accept unusual type modifier */
  
  do {
    ch = TERMIO_GetChar();
    *p++ = ch; 
  } while((ch != (char)'\n') && (ch != (char)'\r'));
  *(p-1) = (char)'\0'; /* replace '\n' with '\0' */
  return s;
}

int puts(LIBDEF_ConstStringPtr s) {
  /* The puts() function writes string to the standard output stream stdout,
     replacing the string’s terminating null character ('\0') with a newline character ('\n')
     in the output stream.
     returns a nonnegative value if successful. If puts fails it returns EOF */
  TERM_WriteString(s);
  TERMIO_PutChar((char)'\n');
  return 1; /* success */
}
/*-----------------------------------------------------------------*/
/* file I/O */
/* for file I/O we are using the terminal functionality and writing
   to a file. Note that this is limited to one active file only! */
   
FILE *fopen(LIBDEF_ConstStringPtr name, LIBDEF_ConstStringPtr mode) {
  TERMIO_Init();
  TERM_Direct(TERM_APPEND_BOTH, name); /* write to terminal and file */
  return (FILE *)-1; /*lint !e923 , MISRA 11.3 ADV, no support for multiple file descriptors */
} /*lint !e715 this is the implementation of a standard library function, so its prototype is left unchanged */ 

int fflush(FILE *stream) {
  TERM_Direct(TERM_TO_WINDOW, (LIBDEF_ConstStringPtr)""); /*lint !e926 , MISRA 11.4 ADV, the conversion is safe */
  return 0;
} /*lint !e715 !e818 , MISRA 16.7 ADV, standard library function implementation */

int fclose(FILE *stream) {
  return fflush(stream);
}

int fprintf(FILE *f, LIBDEF_ConstStringPtr format, ...) { /*lint !e960 MISRA 16.1 REQ, standard library function implementation */
  int i;
  va_list args;
  
  set_printf(TERMIO_PutChar); /* set up TERMIO_PutChar for writing */
  /*lint -e{643} misleading warning ('&format' does not have a far pointer) */
  /*lint -e{928} , MISRA 11.4 ADV, safe conversion to 'char *' */
  va_start(args, format);
  i = vprintf(format, args);
  va_end(args);
  return i; /*lint !e438 'va_end' must be invoked before return in a variadic function */
} /*lint !e715 !e818 , MISRA 16.7 ADV, standard library function implementation */

int fputs(LIBDEF_ConstStringPtr s, FILE *f) {
  TERM_WriteString(s);
  return 0; /* ok */
} /*lint !e715 !e818 , MISRA 16.7 ADV, standard library function implementation */

int fputc(int c, FILE *f) {
  TERM_Write((char)c);
  return 0; /* ok */
} /*lint !e715 !e818 , MISRA 16.7 ADV, standard library function implementation */

int fgetc(FILE *f) {
  return (int)TERM_Read();
} /*lint !e715 !e818 , MISRA 16.7 ADV, standard library function implementation */

int remove(LIBDEF_ConstStringPtr name) {
  return 0; /* ok */
} /*lint !e715 this is the implementation of a standard library function, so its prototype is left unchanged */

/*-----------------------------------------------------------------*/
/* time functions */
/* here we use the HI-WAVE timer.wnd to get the actual cycle count
   from address 0x210.
   To use this feature you have to load the timer.wnd as component
   in HI-WAVE */
#define CYCLE_COUNTER_ADDRESS 0x210

#if defined(__HC05__) || defined(__HC08__) || defined(__ST7__) || defined(__ST19X__)
/*#define cycle_counter *((volatile clock_t*_FAR)CYCLE_COUNTER_ADDRESS)*/
#define cycle_counter *((volatile clock_t*__far)CYCLE_COUNTER_ADDRESS)
#elif defined(__RS08__)
#define cycle_counter *((volatile clock_t*__paged)CONVERT_TO_PAGED(CYCLE_COUNTER_ADDRESS))
#else
#define cycle_counter *((volatile clock_t*)CYCLE_COUNTER_ADDRESS)
#endif

clock_t clock(void) {
  /*lint -e511 pointer size depends on both the target and the memory model */
  /*lint -e923 , MISRA 11.3 ADV, safe conversion */
  /*lint -e506 , MISRA 13.7 REQ & MISRA 14.1 REQ, the boolean operation results from the expansion of macro 'CONVERT_TO_PAGED' */
  /*lint -estring(960, "Bitwise operator applied to signed underlying type*") , MISRA 12.7 REQ, the signed quantity is always positive */
  cycle_counter = (unsigned long)0; /* every write to the cycle counter sets it to the actual number of cycles! */
  return cycle_counter;
  /*lint +e511 +e923 +e506 */
  /*lint +estring(960, "Bitwise operator applied to signed underlying type") */
  
}
/*-----------------------------------------------------------------*/
/* program termination function */
void abort(void) {
  HALT_AND_QUIT; /*lint !e960 , MISRA 14.3 REQ, the macro expands to HLI several statements */
}

void exit(int status) {
  HALT_AND_QUIT; /*lint !e960 , MISRA 14.3 REQ, the macro expands to HLI several statements */
} /*lint !e715 this is the implementation of a standard library function, so its prototype is left unchanged */
/*-----------------------------------------------------------------*/
/*lint --e{766} hidef.h contains conditionally compiled code */
