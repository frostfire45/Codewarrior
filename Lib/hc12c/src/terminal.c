/*****************************************************
   terminal.c - Terminal: terminal functions
 ----------------------------------------------------
   Copyright (c) Metrowerks, Basel, Switzerland
               All rights reserved
                  Do not modify!
 *****************************************************/
#include <terminal.h>
#include <termio.h>

/*lint -estring(960, "Octal escape sequence used") , MISRA 7.1 REQ, safe use of octal escape sequences */
/*lint -estring(960, "Prohibited escape sequence used") , MISRA 4.1 REQ, safe use of octal escape sequences */
#define BS   '\010'
#define DEL  '\177'
#define CR   '\015'
#define LF   '\012'
#define ESC  '\033'

char TERM_Read(void) {
  /* reads a character from the terminal */
  return TERMIO_GetChar();
}

void TERM_ReadString(LIBDEF_StringPtr str, int maxLen) {
  /* reads a string int buffer 'str' with maxLen */
  char ch = TERM_Read();
  int len = 0;
  
  while ((ch >= (char)' ') || (ch == (char)BS) || (ch == (char)DEL)) {
    if (ch >= (char)' ') {
      if ( len < (maxLen-1)) {
        str[len++] = ch; TERM_Write(ch);
      }
    } else if (len > 0) {
      TERM_Write(ch); len--;
    } else { /* do nothing */
    }
    ch = TERM_Read();
  }
  str[len] = (char)0;
}

void TERM_Write(char ch) {
  /* writes a character to the terminal */
  TERMIO_PutChar(ch);
}

void TERM_WriteLn(void) {
  /* writes a new-line to the terminal */
  TERMIO_PutChar((char)CR); TERMIO_PutChar((char)LF);
}

void TERM_WriteString(LIBDEF_ConstStringPtr str) {
#ifndef _TERMIO_HAS_PUT_STRING_
  /* writes a zero terminated string to the terminal */
  while (*str) {
    TERMIO_PutChar(*str);
    str++;
  }
#else
  TERMIO_PutString(str);
#endif

}

void TERM_Direct(TERM_DirectKind what, LIBDEF_ConstStringPtr fileName) {
  /* sets direction of the terminal */
  if ((what < TERM_TO_WINDOW) || (what > TERM_APPEND_FILE)) { /*lint !e685 the function may take an integer as argument */
    return;
  }
  TERM_Write((char)ESC); TERM_Write((char)'h'); 
  {
    int tmp = what + '0';   /* required for compliance with MISRA 10.3 REQ */ /*lint !e641 use the integer model for enums */  
    TERM_Write((char)tmp);
  }
  if ((what != TERM_TO_WINDOW) && (what != TERM_FROM_KEYS)) {
    TERM_WriteString(fileName); TERM_Write((char)CR);
  }
}

/*lint +estring(960, "Octal escape sequence used") */
/*lint +estring(960, "Prohibited escape sequence used") */
