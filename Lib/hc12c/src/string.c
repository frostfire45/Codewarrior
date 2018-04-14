/*****************************************************
    string.c - ANSI-C library: string handling
 ----------------------------------------------------
   Copyright (c) Metrowerks, Basel, Switzerland
               All rights reserved
                  Do not modify!
 *****************************************************/

#include <hidef.h>
#include <string.h>
#include <libdefs.h>

/*****************************************************/
#pragma MESSAGE DISABLE  C5703 /* errnum: parameter declared in function strerror but not referenced */

LIBDEF_StringPtr strerror(int errnum) {
  /*lint -e{926} , MISRA 11.4 ADV, deliberate cast */
  return (LIBDEF_StringPtr)"";  /* no specific errors implemented */
} /*lint !e715 , implementation of a standard library function */
/*****************************************************/
LIBDEF_MemPtr memchr(LIBDEF_ConstMemPtr buffer, int chr, size_t count) {
  LIBDEF_ConstStringPtr ptr = buffer; /*lint !e625 options ConstQualiNear and -NonConstQualiNear force qualifier 'far' on library pointer types */

  while (count--) {
    if ((unsigned char)*ptr == (unsigned char)chr) {
      return (LIBDEF_MemPtr)(ptr);
    }
    ++ptr;
  }
  return NULL;
}
/*****************************************************/
int memcmp(LIBDEF_ConstMemPtr buf1, LIBDEF_ConstMemPtr buf2, size_t count) {
  LIBDEF_ConstStringPtr ptr1 = buf1; /*lint !e625 options ConstQualiNear and -NonConstQualiNear force qualifier 'far' on library pointer types */
  LIBDEF_ConstStringPtr ptr2 = buf2; /*lint !e625 options ConstQualiNear and -NonConstQualiNear force qualifier 'far' on library pointer types */

  if (!count) {
    return 0;
  }
  while (--count) {
    if (*ptr1 != *ptr2) {
      break;
    }
    ++ptr1;
    ++ptr2;
  }
  return (int)(unsigned char)*ptr1 - (int)(unsigned char)*ptr2;
}
/*****************************************************/
void memcpy2(LIBDEF_MemPtr dest, LIBDEF_ConstMemPtr source, size_t count) {
  /* this function does not return the dest and assumes count > 0 */
  do {
    *((LIBDEF_MemBytePtr)dest)++ = *((LIBDEF_ConstMemBytePtr)source)++;
  } while(--count);
}
/*****************************************************/
LIBDEF_MemPtr memcpy(LIBDEF_MemPtr dest, LIBDEF_ConstMemPtr source, size_t count) {
  LIBDEF_MemBytePtr sd = dest;        /*lint !e625 options ConstQualiNear and -NonConstQualiNear force qualifier 'far' on library pointer types */
  LIBDEF_ConstMemBytePtr ss = source; /*lint !e625 options ConstQualiNear and -NonConstQualiNear force qualifier 'far' on library pointer types */

  while (count--) {
    *sd++ = *ss++;
  }
  return (dest);
}
/*****************************************************/
void _memcpy_8bitCount(LIBDEF_MemPtr dest, LIBDEF_ConstMemPtr source, unsigned char count) {
  /* this function does not return the dest, and count is in the range 0..0xff */
  while(count != 0U) {
    count--;
    ((LIBDEF_MemBytePtr)dest)[count] = ((LIBDEF_MemBytePtr)source)[count];
  }
}
/*****************************************************/
LIBDEF_MemPtr memmove(LIBDEF_MemPtr dest, LIBDEF_ConstMemPtr source, size_t count) {
  LIBDEF_MemBytePtr sd = dest;        /*lint !e625 options ConstQualiNear and -NonConstQualiNear force qualifier 'far' on library pointer types */
  LIBDEF_ConstMemBytePtr ss = source; /*lint !e625 options ConstQualiNear and -NonConstQualiNear force qualifier 'far' on library pointer types */

  if (ss > sd) {         /*lint !e946 , MISRA 17.2 REQ & MISRA 17.3 REQ, memmove implementation : need to establish if the two memory areas overlap */
    while (count--) {
      *sd++ = *ss++;
    }
  } else if (ss < sd) {  /*lint !e946 , MISRA 17.2 REQ & MISRA 17.3 REQ, memmove implementation : need to establish if the two memory areas overlap */
    sd += count - 1U;
    ss += count - 1U;
    while (count--) {
      *sd-- = *ss--;
    }
  } else { /* do nothing */
  }
  return (dest);
}
/*****************************************************/
LIBDEF_MemPtr memset(LIBDEF_MemPtr buffer, int chr, size_t count) {
  LIBDEF_MemBytePtr ptr = buffer; /*lint !e625 options ConstQualiNear and -NonConstQualiNear force qualifier 'far' on library pointer types */

  while(count--) {
    *ptr++ = (LIBDEF_MemByte) chr;
  }
  return (buffer);
}
/*****************************************************/
void _memset_clear_8bitCount(LIBDEF_MemPtr buffer, unsigned char count) {
  /* same as memset, but
     - no return value
     - memory is initialized with zero
     - count is a 8bit value and > 0
     ===> this makes it much more efficient!
   */
  do {
    *(LIBDEF_MemBytePtr)buffer = (char)0;
    ((LIBDEF_MemBytePtr)buffer)++;
    count--;
  } while(count != 0U);
}
/*****************************************************/
size_t  strlen(LIBDEF_ConstStringPtr str) {
  /*lint -e{926} , MISRA 11.4 ADV, safe conversion to 'char *' */
  /*lint -e{625} , options ConstQualiNear and -NonConstQualiNear force qualifier 'far' on library pointer types */
  LIBDEF_ConstMemBytePtr s = (LIBDEF_ConstMemBytePtr)str;
  int tmp;

  while(*str++) {}
  /*lint -e{946} , MISRA 17.2 REQ & MISRA 17.3 REQ, the two pointers point into the same string */
  /*lint -e{947} , MISRA 17.2 REQ , the two pointers point into the same string */
  tmp = (str - s) - 1;
  return ((size_t)tmp);
}
/*****************************************************/
LIBDEF_StringPtr strset(LIBDEF_StringPtr str, int chr) {
  LIBDEF_StringPtr s = str; /*lint !e625 options ConstQualiNear and -NonConstQualiNear force qualifier 'far' on library pointer types */

  while (*str) {
    *str++ = (char) chr;
  }
  return (s);
}
/*****************************************************/
LIBDEF_StringPtr strcat(LIBDEF_StringPtr str_d, LIBDEF_ConstStringPtr str_s) {
  LIBDEF_StringPtr sd = str_d;  /*lint !e625 options ConstQualiNear and -NonConstQualiNear force qualifier 'far' on library pointer types */

  str_d += strlen(str_d);
  while(*str_d++ = *str_s++) {} /*lint !e720 , MISRA 13.1 REQ & MISRA 13.2 ADV, assignment deliberately used in a Boolean context */
  return (sd);
}
/*****************************************************/
LIBDEF_StringPtr strncat(LIBDEF_StringPtr str_d, LIBDEF_ConstStringPtr str_s, size_t count) {
  LIBDEF_StringPtr sd = str_d;   /*lint !e625 options ConstQualiNear and -NonConstQualiNear force qualifier 'far' on library pointer types */

  while (*str_d++) {}
  str_d--;
  while (count--) {
    if (!(*str_d++ = *str_s++)) { /*lint !e820 , MISRA 13.1 REQ, assignment deliberately used in a Boolean context */
      return sd;
    }
  }
  *str_d = (char)'\0';
  return sd;
}
/*****************************************************/
/* strcpy ANSI routine */

#if defined(__XGATE__) && defined(__CHAR_IS_8BIT__)
/* this XGATE assembly version of strcpy assumes that:       */
/* - sizeof(char) == 1 (can be changed with compiler option) */
/* - 16 bit pointer type (cannot be changed)                 */
/* - code is for XGATE                                       */
#pragma NO_ENTRY
#pragma NO_EXIT
#pragma NO_RETURN

/*lint -esym(715, str_d) , this function contains HLI only */
/*lint -esym(715, str_s) , this function contains HLI only */
/*lint -esym(818, str_d) , MISRA 16.7 ADV, this function contains HLI only */    
LIBDEF_StringPtr strcpy(LIBDEF_StringPtr str_d, LIBDEF_ConstStringPtr str_s) {
  asm {
       STW        R6,(R0,-R7)
       MOV        R6, R2
Loop:
       LDB        R4,(R0,R6+)
       STB        R4,(R0,R3+)
       CMP        R4,R0
       BNE        Loop
       LDW        R6,(R0, R7+)
       JAL        R6
  }
} /*lint !e533 , MISRA 16.8 REQ, this function contains HLI only */
/*lint +esym(715, str_d) */
/*lint +esym(818, str_d) */

#elif defined(__HC12__) && defined(__CHAR_IS_8BIT__)
/* this HC12 assembly version of strcmp assumes that:                           */
/* - sizeof(char) == 1 (can be changed with compiler option)                    */
/* - char is unsigned  (can be changed with compiler option)                    */
/* - 16 bit pointer type (depends on memory model, can be changed in libdefs.h) */
/* - code is for HC12, HCS12 or HCS12X                                          */
LIBDEF_StringPtr strcpy(LIBDEF_StringPtr str_d, LIBDEF_ConstStringPtr str_s) {
  /*lint -e{506} , MISRA 13.7 REQ & MISRA 14.1 REQ, the Boolean value depends on the memory model */
  /*lint -e{774} , the Boolean value depends on the memory model */
  if ((sizeof(LIBDEF_ConstStringPtr) == 2U) && (sizeof(LIBDEF_StringPtr) == 2U)) { 
    /* detect what type in libdefs.h was choosen */
    asm {
       TFR        D,Y    ; /* Y: str_s pointer */
       LDX        str_d  ; /* X: str_d pointer */
loop:
#if defined(__OPTIMIZE_FOR_SIZE__) /* optimized version: handle two bytes at once */
       LDAB       1,Y+   ; /* load one byte */
       STAB       1,X+   ; /* store one byte */
       BNE        loop   ; /* one more byte if it last one was not zero */
#else /* __OPTIMIZE_FOR_TIME__ */
NextWord:
       LDD        2,Y+   ; /* load two bytes */
       TBEQ       A,CopyLastByte; /* write terminating zero byte */
       STD        2,X+   ;
       TBNE       B,NextWord
       BRA        Done

CopyLastByte:
       STAA       1,X+   ;/* write terminating zero byte */
#endif /* __OPTIMIZE_FOR_SIZE__ */
Done:
       LDD        str_d
    }
  } else {
    LIBDEF_StringPtr sd = str_d;  /*lint !e625 options ConstQualiNear and -NonConstQualiNear force qualifier 'far' on library pointer types */

    while(*str_d++ = *str_s++) {} /*lint !e720 , MISRA 13.1 REQ & MISRA 13.2 ADV, assignment deliberately used in a Boolean context */
    return (sd);
  }
} /*lint !e533 , MISRA 16.8 REQ, on this exit path, the function contains HLI only */

#else

LIBDEF_StringPtr strcpy(LIBDEF_StringPtr str_d, LIBDEF_ConstStringPtr str_s) {
  LIBDEF_StringPtr sd = str_d;

  while(*str_d++ = *str_s++) {}
  return (sd);
}

#endif

/*****************************************************/
LIBDEF_StringPtr strncpy(LIBDEF_StringPtr str_d, LIBDEF_ConstStringPtr str_s, size_t count) {
  LIBDEF_StringPtr sd = str_d; /*lint !e625 options ConstQualiNear and -NonConstQualiNear force qualifier 'far' on library pointer types */

  while(count--) {
    if (*str_s) {
      *str_d++ = *str_s++;
    } else {
      *str_d++ = (char)'\0';
    }
  }
  return (sd);
}
/*****************************************************/
/* strcmp ANSI routine */
#if defined(__XGATE__) && defined(__CHAR_IS_UNSIGNED__) && defined(__CHAR_IS_8BIT__)
/* this XGATE assembly version of strcmp assumes that:       */
/* - sizeof(char) == 1 (can be changed with compiler option) */
/* - char is unsigned  (can be changed with compiler option) */
/* - 16 bit pointer type (cannot be changed)                 */
/* - code is for XGATE                                       */

#pragma NO_ENTRY
#pragma NO_EXIT
#pragma NO_RETURN

/* ignore some messages only caused by high level inline assembly */
#pragma MESSAGE DISABLE C1404 /* Warning : C1404: Return expected */
#pragma MESSAGE DISABLE C5661 /* Warning : C5661: Not all control paths return a value */

/*lint -esym(715, str1) , this function contains HLI only */
/*lint -esym(715, str2) , this function contains HLI only */
int strcmp(LIBDEF_ConstStringPtr str1, LIBDEF_ConstStringPtr str2) {
   asm {
        STW        R6,(R0,-R7)
        BRA        LoadValues
Loop:
        CMP        R4,R6
        BNE        Done
LoadValues:
        LDB        R4,(R0,R3+)
        LDB        R6,(R0,R2+)
#ifdef __OPTIMIZE_FOR_TIME__
        AND        R0,R6,R4
        BNE        LoadValues
#endif
        CMP        R4,R0
        BEQ        Done
        CMP        R6,R0
        BNE        Loop
Done:
        SUB        R2,R4,R6

        LDW        R6,(R0,R7+)
        JAL        R6
    }
} /*lint !e533 , MISRA 16.8 REQ, this function contains HLI only */

#elif defined(__HC12__) && defined(__CHAR_IS_8BIT__)
/* this HC12 assembly version of strcmp assumes that:                           */
/* - sizeof(char) == 1 (can be changed with compiler option)                    */
/* - 16 bit pointer type (depends on memory model, can be changed in libdefs.h) */
/* - code is for HC12, HCS12 or HCS12X                                          */

int strcmp(LIBDEF_ConstStringPtr str1, LIBDEF_ConstStringPtr str2) {
  /*lint -e{506} , MISRA 13.7 REQ & MISRA 14.1 REQ, the Boolean value depends on the memory model */
  /*lint -e{774} , the Boolean value depends on the memory model */ 
  if (sizeof(LIBDEF_ConstStringPtr) == 2U) {
    /* detect what type in libdefs.h was choosen */
    asm {
        TFR        D,X    ; /* X: str2 pointer */
        LDY        str1   ; /* Y: str1 pointer */
        BRA        LoadValues
Loop:
        TBEQ       A, Done  /* done if (*str2) is 0 */
LoadValues:
        LDAA       1,X+   ; /* load *str2 into A */
        LDAB       1,Y+   ; /* load *str1 into B */
        BEQ        Done   ; /* done if (*str1) is 0 */
        CBA
        BEQ        Loop   ; /* done if (*str2 != *str1) */
Done:
        PSHA
        CLRA
        PSHA
        SUBD       2,SP+  ; /* return ((unsigned char)*str1 - (unsigned char)*str2) */
    }
  } else {
    while (*str1 && *str2) {
      if (*str1 != *str2) {
        break;
      }
      ++str1;
      ++str2;
    }
    return ((int)(unsigned char)*str1 - (int)(unsigned char)*str2);
  }
} /*lint !e533, MISRA 16.8 REQ, the absence of a return statement on the HLI exit path is deliberate */

#else
/* ANSI-C version of strcmp */
int strcmp(LIBDEF_ConstStringPtr str1, LIBDEF_ConstStringPtr str2) {
  while (*str1 && *str2) {
    if (*str1 != *str2) {
      break;
    }
    ++str1;
    ++str2;
  }
  return ((unsigned char)*str1 - (unsigned char)*str2);
}
#endif
/*****************************************************/
int strncmp(LIBDEF_ConstStringPtr str1, LIBDEF_ConstStringPtr str2, size_t count) {
  if (!count) {
    return 0;
  }
  while (--count && *str1 && *str2) {
    if (*str1 != *str2) {
      break;
    }
    ++str1;
    ++str2;
  }
  return ((int)(unsigned char)*str1 - (int)(unsigned char)*str2);
}
/*****************************************************/
LIBDEF_StringPtr strchr(LIBDEF_ConstStringPtr str, int chr) {
  while (*str) {
    if (*str == (char)chr) {
      return (LIBDEF_StringPtr)str; /*lint !e926 , MISRA 11.4 ADV, safe conversion, from 'const char *' to 'char *' */
    }
    ++str;
  }
  if (*str == (char)chr) {
    return (LIBDEF_StringPtr)str;   /*lint !e926 , MISRA 11.4 ADV, safe conversion, from 'const char *' to 'char *' */
  }
  return (NULL);
}
/*****************************************************/
LIBDEF_StringPtr strrchr(LIBDEF_ConstStringPtr str, int chr) {
  LIBDEF_ConstStringPtr sr = NULL; /*lint !e625 options ConstQualiNear and -NonConstQualiNear force qualifier 'far' on library pointer types */

  while (*str) {
    if (*str == (char)chr) {
      sr = str;
    }
    ++str;
  }
  if (*str == (char)chr) {
    return (LIBDEF_StringPtr)str;  /*lint !e926 , MISRA 11.4 ADV, safe conversion, from 'const char *' to 'char *' */
  }
  return (LIBDEF_StringPtr)sr;     /*lint !e926 , MISRA 11.4 ADV, safe conversion, from 'const char *' to 'char *' */
}
/*****************************************************/
size_t strspn(LIBDEF_ConstStringPtr str1, LIBDEF_ConstStringPtr str2) {
  size_t len = 0U;

  while(*str1) {
    if (strchr(str2, (int)*str1) == NULL) {
      return (len);
    }
    ++str1;
    ++len;
  }
  return (len);
}
/*****************************************************/
size_t strcspn(LIBDEF_ConstStringPtr str1, LIBDEF_ConstStringPtr str2) {
  register LIBDEF_ConstStringPtr b2; /*lint !e625 options ConstQualiNear and -NonConstQualiNear force qualifier 'far' on library pointer types */
  size_t len = 0U;

  while (*str1) {
    b2 = str2;
    while (*b2) {
      if (*str1 == *b2++) {
        return (len);
      }
    }
    ++str1;
    ++len;
  }
  return (len);
}
/*****************************************************/
LIBDEF_StringPtr strpbrk(LIBDEF_ConstStringPtr str1, LIBDEF_ConstStringPtr str2) {
  register LIBDEF_ConstStringPtr b2;  /*lint !e625 options ConstQualiNear and -NonConstQualiNear force qualifier 'far' on library pointer types */

  while (*str1) {
    b2 = str2;
    while (*b2) {
      if (*str1 == *b2++) {
        return (LIBDEF_StringPtr)str1; /*lint !e926 , MISRA 11.4 ADV, safe conversion, from 'const char *' to 'char *' */
      }
    }
    ++str1;
  }
  return (NULL);
}
/*****************************************************/
LIBDEF_StringPtr strstr(LIBDEF_ConstStringPtr str1, LIBDEF_ConstStringPtr str2) {
  register int    count;
  register size_t len;

  len = strlen(str2);
  if (len == 0U) {
    return (LIBDEF_StringPtr)str1;  /*lint !e926 , MISRA 11.4 ADV, safe conversion, from 'const char *' to 'char *' */
  }
#if defined(__HC08__) || defined(__RS08__) || defined(__HC12__)  || defined(__XGATE__)
  {
    size_t tmp = (strlen(str1) + (size_t)1) - len;
    count = (int)tmp;
  }
#else
  count = (strlen(str1) + 1) - len;
#endif  
  if (count < 1) {
    return (NULL);
  }
  while (count--) {
    if (*str1 == *str2) {
      if (strncmp(str1, str2, len) == 0) {
        return (LIBDEF_StringPtr)str1; /*lint !e926 , MISRA 11.4 ADV, safe conversion, from 'const char *' to 'char *' */
      }
    }
    ++str1;
  }
  return (NULL);
}
/*****************************************************/
LIBDEF_StringPtr strtok(LIBDEF_StringPtr str1, LIBDEF_ConstStringPtr str2) {
  static LIBDEF_StringPtr next = NULL;
  register LIBDEF_ConstStringPtr s2; /*lint !e625 options ConstQualiNear and -NonConstQualiNear force qualifier 'far' on library pointer types */

  if (str1 != NULL) {
    next = str1;                /* start new sequence */
  } else {
    str1 = next;                /* set *s to start of token */
  }
  while (*str1)  {
    s2 = str2;
    while (*s2) {
      if (*str1 == *s2++) {
        /* found */
        if (str1 == next) {
          next++;         /* remove delimiters in front of token */
          break;
        }
        *str1  = (char)'\0';      /* change delimiter to null */
        s2   = next;        /* save token start         */
        next = ++str1;      /* set start of next token  */
        return (LIBDEF_StringPtr)s2; /*lint !e926 , MISRA 11.4 ADV, safe conversion, from 'const char *' to 'char *' */
      }
    }
    str1++; /* test next character        */
  }
  /* end of string found */
  if (*next) {
    s2   = next; /* save token start         */
    next = str1; /* set start of next token  */
    return (LIBDEF_StringPtr)s2;     /*lint !e926 , MISRA 11.4 ADV, safe conversion, from 'const char *' to 'char *' */
  }
  return (NULL);   /* if end_of_string, return NULL */
}
/*****************************************************/
int strcoll(LIBDEF_ConstStringPtr string1, LIBDEF_ConstStringPtr string2) {
  return strcmp(string1, string2);
}
/*****************************************************/
size_t strxfrm(LIBDEF_StringPtr strDest, LIBDEF_ConstStringPtr strSource, size_t count) {
  (void)strncpy(strDest, strSource, count);
  return(strlen(strSource));
}
/*****************************************************/
/* end string.c */
