/*****************************************************
    stdlib.c - ANSI-C library: various functions
 ----------------------------------------------------
   Copyright (c) Metrowerks, Basel, Switzerland
               All rights reserved
                  Do not modify!
 *****************************************************/

#include <errno.h>
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>
#include <hidef.h>    /* is not a ANSI library file (HALT, HALTX) */
#include <ctype.h>
#include <libdefs.h>
#include <stdio.h>
#include <stdtypes.h>

#undef toupper  /*lint !e960 MISRA 19.6 REQ, '#undef' necessary (use the 'toupper' function instead of the 'toupper' macro) */
#undef isspace  /*lint !e960 MISRA 19.6 REQ, '#undef' necessary (use the 'isspace' function instead of the 'isspace' macro) */
#undef isdigit  /*lint !e960 MISRA 19.6 REQ, '#undef' necessary (use the 'isdigit' function instead of the 'isdigit' macro) */

/*lint -estring(961, "'#/##' operator used") , MISRA 19.13 ADV, '#' used not as the stringification preprocessing operator, but as an inline assembly operator */

#pragma NO_STRING_CONSTR

#if defined(__MCORE__) || defined(__ST7__) || defined(__ST19X__) || defined(__HC05__) || defined(__PPC__)
    #define UNKNOWN  4
#else
    #define UNKNOWN  #4
#endif

#ifndef __NO_FLOAT__
#define _100TEN     1.0e100
#define _10TEN      1.0e010
#define _1TEN       1.0e001
#define _TEN1       1.0e-001
#define _TEN10      1.0e-010
#define _TEN100     1.0e-100
#endif

#if defined(__HC12__) && !defined(__S12LISA__)
#pragma MESSAGE DISABLE  C12056 /* WARNING C12056: SP debug info incorrect because of optimization or inline assembler */
#endif

#if LIBDEF_ENABLE_OVERFLOW_CHECK
  #define CHECK_OVERFLOW(val, rel, lim, error) if ((val) rel (lim)) {_errno = (error); }
#else
  #define CHECK_OVERFLOW(val, rel, lim, error)
#endif

/* the following prototypes are required for compliance with MISRA 8.1 REQ */
unsigned long int _strtoul(LIBDEF_ConstStringPtr nptr, LIBDEF_StringPtr *endptr, int base, unsigned int len);
long int _strtol(LIBDEF_ConstStringPtr nptr, LIBDEF_StringPtr *endptr, int base, unsigned int len);
#ifndef __NO_FLOAT__
double _strtod (LIBDEF_ConstStringPtr nptr, LIBDEF_StringPtr *endptr, unsigned int len);
#endif

/*****************************************************/
#ifdef __XGATE__ /* for the XGATE all constants have to be in RAM. Variables have to be distinct from the HCS12X */
#define seed    _X_seed /* XGATE should use seperate seed (and not share it with the HCS12X) */
#endif /* __XGATE__ */

FILE channels[1];
/*****************************************************/

#ifndef __S12LISA__
#pragma MESSAGE DISABLE C5703 /* func: parameter declared in function atexit but not referenced */
#endif

int atexit(void (*func) (void))
{
  HALTX (UNKNOWN); /*lint !e960 MISRA 14.3 REQ, the macro expands to several HLI statements */
  return -1;
} /*lint !e715 standard library function implementation */

LIBDEF_StringPtr getenv(LIBDEF_ConstStringPtr name)
{
  HALTX (UNKNOWN); /*lint !e960 MISRA 14.3 REQ, the macro expands to several HLI statements */
  return NULL;
} /*lint !e715 standard library function implementation */

int  system(LIBDEF_ConstStringPtr cmd)
{
  HALTX (UNKNOWN); /*lint !e960 MISRA 14.3 REQ, the macro expands to several HLI statements */
  return -1;
} /*lint !e715 standard library function implementation */

int  mblen(LIBDEF_ConstStringPtr s, size_t n)
{
  HALTX (UNKNOWN); /*lint !e960 MISRA 14.3 REQ, the macro expands to several HLI statements */
  return -1;
} /*lint !e715 standard library function implementation */

int  mbtowc(wchar_t *pwc, LIBDEF_ConstStringPtr s, size_t n)
{
  HALTX (UNKNOWN); /*lint !e960 MISRA 14.3 REQ, the macro expands to several HLI statements */
  return -1;
} /*lint !e715 !e818 , MISRA 16.7 ADV, standard library function implementation */

int  wctomb(LIBDEF_StringPtr s, wchar_t wchar)
{
  HALTX (UNKNOWN); /*lint !e960 MISRA 14.3 REQ, the macro expands to several HLI statements */
  return -1;
} /*lint !e715 !e818 , MISRA 16.7 ADV, standard library function implementation */

size_t  mbstowcs(wchar_t *pwcs, LIBDEF_ConstStringPtr s, size_t n)
{
  HALTX (UNKNOWN); /*lint !e960 MISRA 14.3 REQ, the macro expands to several HLI statements */
  return (size_t)0;
} /*lint !e715 !e818 , MISRA 16.7 ADV, standard library function implementation */

size_t  wcstombs(LIBDEF_StringPtr s, const wchar_t *pwcs, size_t n)
{
  HALTX (UNKNOWN); /*lint !e960 MISRA 14.3 REQ, the macro expands to several HLI statements */
  return (size_t)0;
} /*lint !e715 !e818 , MISRA 16.7 ADV, standard library function implementation */

/*****************************************************/

static char CheckCharWithBase(char ch, int base, int *val) {
/* returns true, if character is compatible to base and sets val, returns false otherwise */
  if ((ch >= (char)'0') && (ch <= (char)'9')) {
    *val = (int)ch - '0';
  } else {
    ch = (char)toupper((int)(unsigned char)ch);
    if ((ch >= (char)'A') && (ch <= (char)'Z')) {
      *val = ((int)ch - 'A') + 10;
    } else {
      return (char)0U; /* fail */
    }
  }
  if (*val < base) {
    return (char)1U; /* ok */
  } else {
    return (char)0U; /* fail */
  }
} /* CheckCharWithBase */
/*****************************************************/
unsigned long int _strtoul(LIBDEF_ConstStringPtr nptr, LIBDEF_StringPtr *endptr, int base, unsigned int len){
  /* len == 0 -> no length specified */
  /* len > 0 -> length of digits == len */
  /* spaces, sign are not counted !! */
  unsigned long int lsum;
  LIBDEF_ConstStringPtr nptr0 = nptr; /*lint !e625 accept unusual type modifier */
  int val;
  int xCase = FALSE;

#if LIBDEF_ENABLE_OVERFLOW_CHECK
  int _errno= ERESET;
#endif
  lsum = 0UL;
  while (isspace((int)(*nptr))) {
    ++nptr;   /* Eat any white spaces    */
    if (--len == 0U) {
      goto done; /*lint !e801 Use of goto is not deprecated */
    }
  }
  if (*nptr == (char)'+') {
    ++nptr;
    if (--len == 0U) {
      goto done;  /*lint !e801 Use of goto is not deprecated */
    }
  }
  if (base == 16) {                  /* Remove 0x or 0X, if any */
    if (*nptr == (char)'0') {
      char nextCh= nptr[1];
      if (toupper((int)(unsigned char)nextCh) == 'X') {
        nptr++;
        if (--len == 0U) {
          goto done; /*lint !e801 Use of goto is not deprecated */
        }
        ++nptr;
        if (--len == 0U) {
          goto done; /*lint !e801 Use of goto is not deprecated */
        }
        xCase = TRUE;
      }
    } /* end if */
  } else if (!base) {               /* Need to find base prefix */
    if (*nptr == (char)'0') {              /* Hex or octal */
      char nextCh= nptr[1];
       if (toupper((int)(unsigned char)nextCh) == 'X') {
         nptr++;
         if (--len == 0U) {
           goto done; /*lint !e801 Use of goto is not deprecated */
         }
         base = 16; ++nptr;         /* Hex */
         if (--len == 0U) {
           goto done; /*lint !e801 Use of goto is not deprecated */
         }
         xCase= TRUE;
       } else {
         base = 8;                  /* Octal */
       }
    } else {
      base = 10;                    /* Decimal */
    }
  } else { /* do nothing */
  } /* end if */
  /* check if first digit is legal */
  if (!CheckCharWithBase(*nptr, base, &val)) {
    if (xCase) {
      /* case _strtoul("0x?", NULL, 0, 100) */
      /* we already skipped the x, but now the 0 alone is the legal number */
      nptr--;
      goto done; /*lint !e801 Use of goto is not deprecated */
    }
    /* we did not scan a legal number */
    nptr = nptr0;
    goto done; /*lint !e801 Use of goto is not deprecated */
  }
  if (base < 37) {
    while (CheckCharWithBase(*nptr, base, &val)) {
      CHECK_OVERFLOW(lsum, >, (ULONG_MAX - (unsigned long)(long)val) / (unsigned int)base, ERANGE); /*lint !e960 MISRA 14.3 REQ, the macro does not always expand to a null statement */
      lsum = (lsum * (unsigned long)(long)base) + (unsigned long)(long)val;
      ++nptr;
      if (--len == 0U) {
        goto done; /*lint !e801 Use of goto is not deprecated */
      }
    } /* end while */
  } /* end if */
  done:
  if (endptr) {
    *endptr = (LIBDEF_StringPtr)nptr; /*lint !e926 , MISRA 11.4 ADV, safe cast */
  }
#if LIBDEF_ENABLE_OVERFLOW_CHECK
  errno=_errno;
  if (_errno == ERANGE) {
    return ULONG_MAX;
  }
#endif
  return lsum;
} /* end strtoul */
/*****************************************************/
unsigned long int strtoul(LIBDEF_ConstStringPtr nptr, LIBDEF_StringPtr *endptr, int base) {
  return _strtoul(nptr, endptr, base, 0U);
}
/*****************************************************/
long int _strtol(LIBDEF_ConstStringPtr nptr, LIBDEF_StringPtr *endptr, int base, unsigned int len) {
  /* len == 0 -> now length specified */
  /* len > 0 -> length of digits == len */
  /* spaces, sign are not counted !! */
   long int lsum;
   char nsgn;
   LIBDEF_ConstStringPtr nptr0 = nptr; /*lint !e625 accept unusual type modifier */

   nsgn = (char)0U;
   while (isspace((int)(*nptr))) {
     ++nptr;   /* Eat any white spaces */
     if (--len == 0U) {
       if (endptr != NULL) {              /*lint !e610 pointer tested against NULL */
         *endptr= (LIBDEF_StringPtr)nptr; /*lint !e926 , MISRA 11.4 ADV, safe cast */
       }
       return 0;
     }
   }
   switch (*nptr) {
      case '-': nsgn = (char)1U;            /* Set negative sign flag */
                /*lint -fallthrough */
      case '+': ++nptr;
                if (--len == 0U) {
                  if (endptr != NULL) {               /*lint !e610 pointer tested against NULL */
                     *endptr= (LIBDEF_StringPtr)nptr; /*lint !e926 , MISRA 11.4 ADV, safe cast */
                  }
                  return 0;
                }
                /*lint -fallthrough */
      default:
        if (!(isdigit((int)(*nptr)))) {
          /* << R2414: in case of moving back the pointer, adapt len */
          int tmp = nptr-nptr0;  /*lint !e946 !e947 , MISRA 17.2 REQ & MISRA 17.3 REQ, the two pointers point into the same array object */
          len += (unsigned int)tmp; 
          nptr = nptr0;
        }
   } /* end switch */
   lsum = (long int)_strtoul(nptr, endptr, base, len);
   if ((endptr != NULL) && (*endptr == nptr)) { /*lint !e610 pointer tested against NULL */
     /*lint -e{926} , MISRA 11.4 ADV, safe cast */
     *endptr= (LIBDEF_StringPtr)nptr0; /* undo skipping of spaces/sign for illegal numbers */
   }
#if LIBDEF_ENABLE_OVERFLOW_CHECK
   if (errno == ERANGE) {
     return nsgn ? LONG_MIN : LONG_MAX;
   }
#endif
   if (nsgn) {
     return -lsum;
   }
   return lsum;
} /* end strtol */
/*****************************************************/
long int strtol(LIBDEF_ConstStringPtr nptr, LIBDEF_StringPtr *endptr, int base) {
   return _strtol(nptr, endptr, base, 0U);
}
/*****************************************************/
#ifndef __NO_FLOAT__
double _strtod (LIBDEF_ConstStringPtr nptr, LIBDEF_StringPtr *endptr, unsigned int len) {
  /* len == 0 -> now length specified */
  double dsum, fplc;
  char nsgn, ensgn;
  LIBDEF_ConstStringPtr nptr0 = nptr; /*lint !e625 accept unusual type modifier */
  int _errno=ERESET;
  int int_tmp; /* necessary for compliance with MISRA 10.1 REQ */

  dsum = 0.0; fplc = 10.0;
  nsgn = (char)0U; ensgn = (char)0U;

  while (isspace((int)(*nptr))) {
    ++nptr;   /* Eat any white spaces */
  }
  if (!(isdigit((int)(*nptr)))) {         /* Check for sign */
    switch (*nptr) {
       case '-': nsgn=(char)1U;           /* Set negative sign flag */
                 /*lint -fallthrough */
       case '+': ++nptr;
                 if (--len == 0U) {
                   _errno= EOVERFLOW;
                   goto rt; /*lint !e801 Use of goto is not deprecated */
                 }
                 /*lint -fallthrough */
       case '.': break;
       default :
         nptr = nptr0;
         _errno = EOVERFLOW;
         goto rt;          /* Neither digit, '.' or sign */ /*lint !e801 Use of goto is not deprecated */
    } /* end switch */
  } /* end if */
  while (isdigit((int)(*nptr))) {         /* Set integer portion */
    CHECK_OVERFLOW(dsum, >, DBL_MAX/10.0, EOVERFLOW);                            /*lint !e960 MISRA 14.3 REQ, the macro does not always expand to a null statement */
    dsum *= 10.0;
    CHECK_OVERFLOW(dsum, >, (DBL_MAX - (double)*nptr) + (double)'0', EOVERFLOW); /*lint !e960 MISRA 14.3 REQ, the macro does not always expand to a null statement */
    {
      int_tmp = (int)*nptr++ - '0';
      dsum += (double)int_tmp;
    }    
    if (--len == 0U) {
      goto rt; /*lint !e801 Use of goto is not deprecated */
    }
    if (--len == 0U) {
      goto rt; /*lint !e801 Use of goto is not deprecated */
    }
  } /* end while */
  switch (*nptr) {                  /* Check char */
    default: goto rt;              /* End of 'double' | string */ /*lint !e801 Use of goto is not deprecated */
    case 'e' :
    case 'E' : goto xp;            /* Goto set exponent */ /*lint !e801 Use of goto is not deprecated */
    case '.' : ++nptr;             /* Check locale for decimal . */
               if (--len == 0U) {
                 goto rt; /*lint !e801 Use of goto is not deprecated */
               }
  } /* end switch */
  while (isdigit((int)(*nptr))) {         /* Set fractional portion */
    int_tmp = (int)*nptr++ - '0';
#if LIBDEF_STRTOD_EXTENDED_PREC
    dsum*=(double)10;
    dsum += (double)int_tmp;
#else
    dsum += (double)int_tmp / fplc;
#endif

#if LIBDEF_STRTOD_EXTENDED_PREC
    if (--len == 0U) {
      dsum/=fplc;
      goto rt; /*lint !e801 Use of goto is not deprecated */
    }
    fplc *= (double)10;
#else
    fplc *= 10;
    if (--len == 0) {
      goto rt; /*lint !e801 Use of goto is not deprecated */
    }
#endif
  } /* end while */
#if LIBDEF_STRTOD_EXTENDED_PREC
  dsum/=(fplc/(double)10);
#endif

xp:
  if (toupper((int)(unsigned char)(*nptr)) == 'E') {    /* Is there an exponent */
    int xp;

    xp = 0;
    switch (*++nptr) {
      case '-' : ensgn = (char)1U;
        /*lint -fallthrough */
      case '+' : ++nptr;
        if (--len == 0U) {
          goto rt; /*lint !e801 Use of goto is not deprecated */
        }
        break;
      default: break;
    } /* end switch */
    while (isdigit((int)(*nptr))) {      /* Get exponent value */
      CHECK_OVERFLOW(xp, >, INT_MAX/10, ensgn ? EUNDERFLOW : EOVERFLOW);             /*lint !e960 MISRA 14.3 REQ, the macro does not always expand to a null statement */
#if LIBDEF_ENABLE_OVERFLOW_CHECK
      if (_errno == 0) {
#endif
        xp *= 10;
#if LIBDEF_ENABLE_OVERFLOW_CHECK
      }
#endif
      CHECK_OVERFLOW(xp, >, (INT_MAX - *nptr) + '0', ensgn ? EUNDERFLOW : EOVERFLOW); /*lint !e960 MISRA 14.3 REQ, the macro does not always expand to a null statement */
#if LIBDEF_ENABLE_OVERFLOW_CHECK
      if (_errno == 0) {
#endif
        xp += ((int)*nptr++ - '0');
#if LIBDEF_ENABLE_OVERFLOW_CHECK
      } else {
        nptr++;
      }
#endif
      if (--len == 0U) {
        break;
      }
    } /* end while */
/*
    if (ensgn) fplc = 0.001; else fplc = 1000.0;
    while (xp >= 100) {
      dsum *= fplc; xp -= 100;
    };
    if (ensgn) fplc = 0.01; else fplc = 100.0;
    while ( xp >= 10) {
      dsum *= fplc; xp -= 10;
    };
    if (ensgn) fplc = 0.1; else fplc = 10.0;
    while (xp) {
      dsum *= fplc; --xp;
    };
*/
#if LIBDEF_ENABLE_OVERFLOW_CHECK
    if (_errno != ERESET) { /* over or under flow */
      goto rt; /*lint !e801 Use of goto is not deprecated */
    }
#endif
    if (ensgn) { fplc = _TEN100; } else { fplc = _100TEN; }
    /* Set to exponent */
    while (xp >= 100) {
      if (ensgn) {
        CHECK_OVERFLOW(dsum, ==, 0.0, EUNDERFLOW);          /*lint !e960 MISRA 14.3 REQ, the macro does not always expand to a null statement */
      } else {
        CHECK_OVERFLOW(dsum, >, DBL_MAX / fplc, EOVERFLOW); /*lint !e960 MISRA 14.3 REQ, the macro does not always expand to a null statement */
      }
      dsum *= fplc; xp -= 100;
    } /* end while */
    if (ensgn) { fplc = _TEN10; } else { fplc = _10TEN; }
    while ( xp >= 10) {
      if (ensgn) {
        CHECK_OVERFLOW(dsum, ==, 0.0, EUNDERFLOW);           /*lint !e960 MISRA 14.3 REQ, the macro does not always expand to a null statement */
      } else {
        CHECK_OVERFLOW(dsum, >, DBL_MAX / fplc, EOVERFLOW);  /*lint !e960 MISRA 14.3 REQ, the macro does not always expand to a null statement */
      }
      dsum *= fplc; xp -= 10;
    } /* end while */
    if (ensgn) { fplc = _TEN1; } else { fplc = _1TEN; }
    while (xp) {
      if (ensgn) {
        CHECK_OVERFLOW(dsum, ==, 0.0, EUNDERFLOW);            /*lint !e960 MISRA 14.3 REQ, the macro does not always expand to a null statement */
      } else {
        CHECK_OVERFLOW(dsum, >, DBL_MAX / fplc, EOVERFLOW);   /*lint !e960 MISRA 14.3 REQ, the macro does not always expand to a null statement */
      }
      dsum *= fplc; --xp;
    } /* end while */
  } /* end if */

rt:
#if LIBDEF_ENABLE_OVERFLOW_CHECK
  if (nptr0 != nptr) { /* something read */
    if (_errno == EOVERFLOW)  {
      _errno=ERANGE; dsum = HUGE_VAL;
    } else if (_errno == EUNDERFLOW) {
      _errno=ERANGE; dsum = 0.0;
    } else { /* do nothing */
    }
  }
#endif
  if (endptr) { *endptr = (LIBDEF_StringPtr)nptr; }  /*lint !e926 , MISRA 11.4 ADV, safe cast */
  if (_errno != 0) {
    errno= _errno;
  }
  if (nsgn) { return -dsum; } else { return dsum; }
} /* end strtod */
/*****************************************************/
double strtod (LIBDEF_ConstStringPtr nptr, LIBDEF_StringPtr *endptr) {
  return _strtod (nptr, endptr, 0U);
}
#endif /* __NO_FLOAT__ */
/*****************************************************/
#if 0
static void xtoa(unsigned long val, LIBDEF_StringPtr buf, unsigned int radix, int is_neg) {
  LIBDEF_StringPtr p;                /* pointer to traverse string */
  LIBDEF_StringPtr firstdig;         /* pointer to first digit */
  char temp;              /* temp char */
  unsigned int digval;        /* value of digit */

  p = buf;
  if (is_neg) { /* negative, so output '-' and negate */
    *p++ = '-';
    val = (unsigned long)(-(long)val);
  }
  firstdig = p;           /* save pointer to first digit */
  do {
    digval = (unsigned int) (val % radix);
    val /= radix;       /* get next digit */
    /* convert to ascii and store */
    if (digval > 9) {
      *p++ = (char) (digval - 10 + 'a');  /* a letter */
    } else {
      *p++ = (char) (digval + '0');       /* a digit */
    }
  } while (val > 0);
  /* We now have the digit of the number in the buffer, but in reverse
   order.  Thus we reverse them now. */
  *p-- = '\0';          /* terminate string; p points to last digit */
  do {
    temp = *p;
    *p = *firstdig;
    *firstdig = temp;   /* swap *p and *firstdig */
    --p;
    ++firstdig;         /* advance to next two digits */
  } while (firstdig < p); /* repeat until halfway */
}

LIBDEF_StringPtr _itoa(int val, LIBDEF_StringPtr buf, int radix) {
  /* writes an integral value as string into the buffer. Radix is the
     number base to be used, e.g. 10 (decimal). Returns always buf. */
  /* Actual functions just call conversion helper with neg flag set correctly,
     and return pointer to buffer. */
  if (radix == 10 && val < 0) {
    xtoa((unsigned long)val, buf, radix, 1);
  } else {
    xtoa((unsigned long)(unsigned int)val, buf, radix, 0);
  }
  return buf;
}
#else
LIBDEF_StringPtr _itoa(int val, LIBDEF_StringPtr buf, int radix) {
  unsigned int ten=1U;
  LIBDEF_StringPtr p= buf; /*lint !e625 accept unusual type modifier */
  int int_tmp;             /* necessary for compliance with MISRA 10.1 REQ */
  unsigned int uint_tmp;   /* necessary for compliance with MISRA 10.1 REQ */

  if ((radix == 10) && (val < 0)) { /* negative, so output '-' and negate */
    *p = (char)'-';
    p++;
    val = -val;
  }

  for (;;) {
    unsigned int nextten= ten*(unsigned int)radix;
    if ((nextten > (unsigned int)val) || ((nextten / (unsigned int)radix) != ten)) {   /* larger or overflow */
      break;
    }
    ten= nextten;
  }
  do {
    char digit;
    uint_tmp = (unsigned int)val / ten;
    digit= (char)uint_tmp;
    if (digit > (char)9) {
      int_tmp = (int)digit+(('a'-'0')-10);  /* required for compliance with MISRA 10.3 REQ */
      digit = (char)int_tmp;
    } 
    {
      int_tmp = (int)digit+'0';             /* required for compliance with MISRA 10.3 REQ */
      *p= (char)int_tmp;
    }
    p++;
    uint_tmp = (unsigned int)val % ten;     /* required for compliance with MISRA 10.3 REQ */
    val = (int)uint_tmp;
    ten /= (unsigned int)radix;
  } while (ten != 0U);
  *p=(char)0U;
  return buf;
}
#endif
/*****************************************************/
#if (defined(__HC05__) || defined(__RS08__) || defined(__ST7__) || defined(__ST19X__)) && !defined(__STACK__)
LIBDEF_MemPtr bsearch(LIBDEF_ConstMemPtr key, LIBDEF_ConstMemPtr base,
              size_t n, size_t size,
              int (*cmp) (LIBDEF_ConstMemPtr, LIBDEF_ConstMemPtr)) /*lint !e960 MISRA 16.3 REQ function pointer parameter */
{
  /*lint -e{960} MISRA 14.3 REQ the macro expands to several HLI statements */
  HALTX (UNKNOWN);         /* only 2 bytes are allowed for function pointer call */
  return NULL;
} /*lint !e715 the implementation of 'bsearch' is target-dependendent */
/*****************************************************/
void qsort (LIBDEF_ConstMemPtr base,
            size_t n, size_t size,
            int (*cmp) (LIBDEF_ConstMemPtr, LIBDEF_ConstMemPtr)) /*lint !e960 MISRA 16.3 REQ function pointer parameter */
{
  /*lint -e{960} MISRA 14.3 REQ the macro expands to several HLI statements */
  HALTX (UNKNOWN);         /* only 2 bytes are allowed for function pointer call in overlap calling convention */
} /*lint !e715 the implementation of 'qsort' is target-dependendent */
/*****************************************************/
#else /* (defined(__HC05__) || defined(__RS08__) || defined(__ST7__) || defined(__ST19X__)) && !defined(__STACK__) */

/* the following macros are required for compliance with MISRA 10.1 REQ - because size_t is target-dependent */
#if defined (__HC08__) || defined(__HC12__) || defined(__XGATE__)
#define SIZE_T__1 (size_t)1
#define SIZE_T__2 (size_t)2
#else
#define SIZE_T__1 1
#define SIZE_T__2 2
#endif


LIBDEF_MemPtr bsearch(LIBDEF_ConstMemPtr key, LIBDEF_ConstMemPtr base,
              size_t n, size_t size,
              int (*cmp) (LIBDEF_ConstMemPtr, LIBDEF_ConstMemPtr)) /*lint !e960 MISRA 16.3 REQ, function pointer parameter */
{
  size_t l = (size_t)0, x;
  int    res;
  LIBDEF_StringPtr thiS; /*lint !e625 accept unusual type modifier */

  while (l < n) {
    thiS = (LIBDEF_StringPtr) base + ((x = (((l + n) - SIZE_T__1) / SIZE_T__2)) * size);
    res = cmp (key, thiS);
    if (!res) {
      return thiS;
    }
    if (res < 0) {
      n = x;
    } else {
      l = x + SIZE_T__1;
    }
  } /* end while */
  return NULL;
}
/*****************************************************/
static void swap (LIBDEF_MemBytePtr left, LIBDEF_MemBytePtr right, size_t size)
  /**** Attention: assumption is sizeof (sWord) == 2!!! */
{
#if !defined(__HC05__) && !defined(__RS08__) && !defined(__HC08__) && !defined(__ST7__) && !defined(__ST19X__)  /* for 8 bit processors, this optimization does not help */
  if ((size & 1U) != 0U) {
#endif
    char a;

    /**** Odd size: do byte moves */
    do {
      a = *left; *left++ = *right; *right++ = a;
    } while (--size);
#if !defined(__HC05__) && !defined(__RS08__) && !defined(__HC08__) && !defined(__ST7__) && !defined(__ST19X__)
  } else {
    sWord    b, *LIBDEF_VOID_DPTRQ p, *LIBDEF_VOID_DPTRQ q; /*lint !e625 options ConstQualiNear and -NonConstQualiNear force qualifier 'far' on library pointer types */

    /**** Even size: do word moves */
    /*lint -e927 , MISRA 11.4 ADV, deliberate cast from 'char*' to a word pointer type */
    /*lint -e826 , deliberate cast from 'char *' to a word pointer type */ 
    p = (sWord *LIBDEF_VOID_DPTRQ) left; q = (sWord *LIBDEF_VOID_DPTRQ) right;
    /*lint +e927 +e826 */
    size >>= 1;
    do {
      b = *p; *p++ = *q; *q++ = b;
    } while (--size);
  } /* end if-else */
#endif
} /* end swap */
/*****************************************************/

#ifndef __S12LISA__
#pragma MESSAGE DISABLE C1855 /* WARNING C1855: Recursive function call */
#endif

/* Generic quicksort routine, optimized for minimum stack
   usage and speed. */
void qsort (LIBDEF_ConstMemPtr base,
            size_t n, size_t size,
            int (*cmp) (LIBDEF_ConstMemPtr, LIBDEF_ConstMemPtr)) /*lint !e960 MISRA 16.3 REQ, function pointer parameter */
{
  size_t  i, j;
  LIBDEF_MemBytePtr left, right; /*lint !e625 accept unusual type modifier */
                                 /* always point to base[i] and base[j], except
                                    when i == n or j == 0, in this case, they point
                                    to base[i-1] and base[j+1]. */
  if (size) {
    /**** It's no use doing anything if size == 0... */
    while (n) {
      /**** We use the very first element of the array for the comparison. */
      i = (size_t)0; right = (left = (LIBDEF_MemBytePtr) base) + ((j = n) * size); /*lint !e931 safe expression */
      for (;;) {
        /*lint -estring(960,"side effects on right hand of logical operator*") , MISRA 12.4 REQ, safe expression */
        while ((++i < n) && (cmp (left += size, base) <= 0)) {}
        while (--j     && (cmp (right -= size, base) >= 0)) {}
        /*lint +estring(960, "side effects on right hand of logical operator*") */          
        if (i > j) {
          break;
        }
        swap (left, right, size); /* i < j is asserted */
      } /* end for */
      if (j) {
        swap ((LIBDEF_MemBytePtr)base, right, size);
        /**** Smaller part sorted recursively, bigger part using the while loop. This
              guarantees an upper limit for the stack depth of log (n). */
        if ((SIZE_T__2 * j) < (n - SIZE_T__1)) {
          /* Left part is smaller */
          qsort (base, j, size, cmp);
          base = right + size;
          n -= (j + SIZE_T__1);
        } else {
          /* Right part is smaller */
          qsort (right + size, (n - j) - SIZE_T__1, size, cmp);
          n = j;
        } /* end if-else */
      } else {
        /**** Bad luck, leftmost element was the smallest... Note: since j == 0,
              right points to base[1], not to base[0]! */
        base = right; n--;
      } /* end if-else */
    } /* end while */
  } /* end if */
} /* end qsort */
#endif /* (defined(__HC05__) || defined(__RS08__) || defined(__ST7__) || defined(__ST19X__)) && !defined(__STACK__) */
/*****************************************************/

div_t  div(int numer, int denom)
{
  div_t res;

  res.quot = numer / denom;
  res.rem  = numer % denom;
  return res;
}

ldiv_t  ldiv(long int numer, long int denom)
{
  ldiv_t res;

  res.quot = numer / denom;
  res.rem  = numer % denom;
  return res;
}

/*****************************************************/
int abs (int j) {
  return M_ABS(j);
}

long int labs (long int j) {
  return M_ABS(j);
}
/*****************************************************/
/* Minimum standard Lehmer random number generator,
   scaled down to integer range... is not re-entrant
   for light-weight processes (uses a global variable)
*/

#define   STDLIB_A        16807  /* Multiplier */
#define   STDLIB_M   2147483647
#define   STDLIB_Q       (STDLIB_M / STDLIB_A)
#define   STDLIB_R       (STDLIB_M % STDLIB_A)

static long seed = 1;

int rand (void)
{
  long  hi, lo;
  unsigned int tmp;

  hi = seed / STDLIB_Q;
  lo = seed % STDLIB_Q;
  seed = (STDLIB_A * lo) - (STDLIB_R * hi);
  if (seed <= 0) {
    seed += STDLIB_M;
  }
  tmp = (unsigned int) seed & 0x7FFFU;
  return (int) tmp;
} /* end rand */

void srand (unsigned int init)
{
  seed = (long)init;
} /* end srand */

/*****************************************************/

/*lint +estring(961, "'#/##' operator used") */

/* end stdlib.c */
/*lint --e{766} header files 'math.h' and 'float.h' contain conditionally compiled code */
