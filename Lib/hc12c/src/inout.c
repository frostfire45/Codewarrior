/*****************************************************
   inout.c - Terminal: basic I/O functions with terminalwe
 ----------------------------------------------------
   Copyright (c) Metrowerks, Basel, Switzerland
               All rights reserved
                  Do not modify!
 *****************************************************/
#include <hidef.h>
#include <inout.h>
#include <terminal.h>
#include <stdtypes.h>

#if defined(__HIWARE__) && !defined(__NO_RECURSION__) && !defined(__S12LISA__)
#pragma MESSAGE DISABLE C1855 /* WARNING : C1855: Recursive function call */
#endif

#ifdef __XGATE__  /* give XGATE a separate termCh from the one of the HCS12X */
#define termCh    _X_termCh
#endif /* __XGATE__ */

static int termCh;

int INOUT_ReadInt(void) {
  /* reads an integer value from the terminal */
  Bool neg = FALSE;
  int val = 0;
 
  termCh = (int)TERM_Read();
  if (termCh == '-') {
    neg = TRUE; TERM_Write((char)termCh); termCh = (int)TERM_Read();
  }
  while ((termCh >= '0') && (termCh <= '9')) {
    TERM_Write((char)termCh);
    val = ((10*val) + termCh) - (int)'0';
    termCh = (int)TERM_Read();
  }
  if (neg) 
  {
    val = -val;
  }
  return val;
}

int INOUT_TermChar(void) {
  /* returns the last character read from the terminal */
  return termCh;
}

#if defined(__NO_RECURSION__)

static void NextDigit(int val) {
  char buf[5];
  unsigned char i;

  i = (unsigned char)sizeof(buf);
  while (val > 0) {
    int tmp;
    i--;
    tmp = val % 10;
    buf[i] = (char)tmp;
    val = val / 10;
    if (i == 0U) {
      break;
    }
  }  
  while(i < sizeof(buf)) {          /*lint !e960 MISRA 10.1 REQ, size_t is an unsigned integer type */
    TERM_Write(buf[i] + (char)'0'); /*lint !e771, all the elements of array 'buf' being accessed in this loop were initialized in the previous loop */
    i++;
  }
}

#else

static void NextDigit(int val) {
  if (val > 0) {
    int tmp;
    NextDigit(val / 10);
    tmp = (val % 10) + 48;
    TERM_Write((char)tmp);
  }
}
#endif

void INOUT_WriteInt(int val) {
  /* writes an integer value to the terminal */
  if (val == 0) {
    TERM_Write((char)'0');
  } 
  else {
    if (val < 0) {
      TERM_Write((char)'-'); val = - val;
    }
    NextDigit(val);
  }
}

#if defined(__NO_RECURSION__)

static void NextDigitLong(long val) {
  char buf[10];
  unsigned char i;

  i = (unsigned char)sizeof(buf);
  while (val > 0) {
    long tmp;
    i--;
    tmp = val % 10L;
    buf[i] = (char)tmp;
    val = val / 10L;
    if (i == 0U) {
      break;
    }
  }  
  while(i < sizeof(buf)) {          /*lint !e960 MISRA 10.1 REQ, size_t is an unsigned integer type */
    TERM_Write(buf[i] + (char)'0'); /*lint !e771, all the elements of array 'buf' being accessed in this loop were initialized in the previous loop */
    i++;
  }
}

#else

static void NextDigitLong(long val) {
  if (val > 0) {
    long tmp;
    NextDigitLong(val / 10);
    tmp = (val % 10) + 48;
    TERM_Write((char)tmp);
  }
}
#endif

void INOUT_WriteLong(long val) {
  /* writes a long value to the terminal */
  if (val == 0) {
    TERM_Write((char)'0');
  } 
  else {
    if (val < 0)  {
      TERM_Write((char)'-'); val = - val;
    }
    NextDigitLong(val);
  }
}
