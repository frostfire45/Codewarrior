/*****************************************************
     printf.c - ANSI-C library: sprintf, vprintf                  
 ----------------------------------------------------
   Copyright (c) Metrowerks, Basel, Switzerland
               All rights reserved
                  Do not modify!
 *****************************************************/
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h> 
#include <hidef.h>
#include <libdefs.h>

#ifndef __S12LISA__
#ifdef __HC12__
  #pragma MESSAGE DISABLE C12002 /* WARNING C12002: Use DPAGE, PPAGE, EPAGE to specify the page register. Assumed DPAGE */
  #pragma MESSAGE DISABLE C12056 /* WARNING C12056: SP debug info incorrect because of optimization or inline assembler */
#endif
#endif

#if defined(__M68K__) && defined(__CPU81__)
  #pragma OPTION ADD PMC81NC "-Pmc81nC"
#endif

#ifndef __S12LISA__
/* Is ok in these cases : */
#pragma MESSAGE DISABLE C5919 /* WARNING C5919: Conversion of floating to unsigned integral */
/* OK for cases like sizeof(...) == sizeof(...) */
#pragma MESSAGE DISABLE C4001 /* INFORMATION C4001: Condition always is FALSE */
/* OK for this case */
#pragma MESSAGE DISABLE C5703 /* INFORMATION C5703: This: parameter declared in function outc_callback but not referenced */
#endif

/* flag bits (vprintf) */

#if LIBDEF_PRINTF_LONG
  #if LIBDEF_PRINTF_LLONG
    #define _PRINTF_INTEG long long
  #else
    #define _PRINTF_INTEG long
  #endif
#else
  #define _PRINTF_INTEG int
#endif

#define _PRINTF_OCTINT  0x1U
#define _PRINTF_HEXINT  0x2U
#define _PRINTF_NOT_DEC (_PRINTF_HEXINT | _PRINTF_OCTINT)

#if LIBDEF_PRINTF_FLOATING
  #define _PRINTF_ETYPE 0x1U
  #define _PRINTF_FTYPE 0x2U
  #define _PRINTF_GTYPE (_PRINTF_ETYPE | _PRINTF_FTYPE)
#endif

#define _PRINTF_BLANK      0x4U
#define _PRINTF_SIGNED     0x8U
#define _PRINTF_NEG       (_PRINTF_SIGNED | _PRINTF_BLANK)

#define _PRINTF_UPPER     0x10U
#define _PRINTF_LEFT      0x20U
#define _PRINTF_ZEROPAD   0x40U
#define _PRINTF_ALT       0x80U
#define _PRINTF_LONGVAL  0x100U
#define _PRINTF_LLONGVAL 0x1000U
#define _PRINTF_SHORTVAL 0x200U
#define _PRINTF_PREC     0x400U
#define _PRINTF_PTR      0x800U

#if LIBDEF_PRINTF_FAR_PTR
  #define _PRINTF_FARVAL 0x1000U
#endif

#ifdef __XGATE__ /* for the XGATE all constants have to be in RAM. Variables have to be distinct from the HCS12X */
#define pbuf    _X_pbuf /* XGATE/HCS12X should use seperate buffers for XGATE */
#define pow10   _X_pow10
#define pow16   _X_pow16
#define pow8    _X_pow8
#define fpow10  _X_fpow10
#define fpow_10  _X_fpow_10
#endif /* __XGATE__ */

#if !LIBDEF_REENTRANT_PRINTF

static struct __print_buf {
  LIBDEF_StringPtr s;
#ifdef __RS08__
  unsigned char jmp_opcode;
#endif
  void (*outc)(char); /*lint !e960 MISRA 16.3 REQ, this is a function pointer declaration */
  unsigned int i;
} pbuf;
#endif /* !LIBDEF_REENTRANT_PRINTF */


#ifndef __S12LISA__
#pragma MESSAGE DISABLE C2402 /* Variable pow10  allocated in ROM */
#endif

static const LIBDEF_CONST_DPTRQ unsigned _PRINTF_INTEG pow10[] = {1U, 10U, 100U, 1000U, 10000U
#if LIBDEF_PRINTF_LONG
        , 100000UL, 1000000UL, 10000000UL, 100000000UL, 1000000000UL
	#if LIBDEF_PRINTF_LLONG
		, 10000000000ULL, 100000000000ULL, 1000000000000ULL, 10000000000000ULL, 100000000000000ULL, 1000000000000000ULL, 10000000000000000ULL, 100000000000000000ULL, 1000000000000000000ULL, 10000000000000000000ULL
	#endif		
#endif
        };
static const LIBDEF_CONST_DPTRQ unsigned _PRINTF_INTEG pow16[] = {1U, 0x10U, 0x100U, 0x1000U
#if LIBDEF_PRINTF_LONG
        , 0x10000UL, 0x100000UL, 0x1000000UL, 0x10000000UL
	#if LIBDEF_PRINTF_LLONG
		, 0x100000000ULL, 0x1000000000ULL, 0x10000000000ULL, 0x100000000000ULL,
0x1000000000000ULL, 0x10000000000000ULL, 0x100000000000000ULL, 0x1000000000000000ULL
	#endif
#endif
        };

#ifndef __S12LISA__
#pragma MESSAGE DISABLE C2706
#endif
/*lint -e{960} MISRA 7.1 REQ, safe use of octal constants */
static const LIBDEF_CONST_DPTRQ unsigned _PRINTF_INTEG pow8[] = {1U, 010U, 0100U, 01000U, 010000U, 0100000U
#if LIBDEF_PRINTF_LONG
        , 01000000UL, 010000000UL, 0100000000UL, 01000000000UL, 010000000000UL
	#if LIBDEF_PRINTF_LLONG
		, 0100000000000ULL, 01000000000000ULL, 010000000000000ULL, 0100000000000000ULL, 01000000000000000ULL, 010000000000000000ULL, 0100000000000000000ULL, 01000000000000000000ULL, 010000000000000000000ULL, 0100000000000000000000ULL, 01000000000000000000000ULL
	#endif
#endif
        };

#if LIBDEF_PRINTF_FLOATING
  static const LIBDEF_CONST_DPTRQ double fpow10[] = {1e0, 1e1, 1e2, 1e3, 1e4, 1e5, 1e6, 1e7, 1e8, 1e16, 1e24, 1e32};
  static const LIBDEF_CONST_DPTRQ double fpow_10[] = {1e0, 1e-1, 1e-2, 1e-3, 1e-4, 1e-5, 1e-6, 1e-7, 1e-8, 1e-16, 1e-24, 1e-32};

  #ifdef __DOUBLE_IS_IEEE64__
    #define EXPON int
  #else
    #define EXPON signed char
  #endif
#endif

#if LIBDEF_PRINTF_FLOATING
static double Ten(EXPON e) {
  const double *LIBDEF_CONST_DPTRQ arr= fpow10; /*lint !e625 !e619 (accept unusual type modifier; no precision loss) */ 
  int int_tmp;           /* necessary for compliance with MISRA 10.1 REQ */
  unsigned int uint_tmp; /* necessary for compliance with MISRA 10.1 REQ */

  if (e < 0) {
    arr= fpow_10; /*lint !e619 no precision loss */
    e = -e;
  }
  if (e <= 8) {
    return arr[e];
  } else {
    double res;
    unsigned int i; 
    {      
       int_tmp = (int)e >> 3;  /*lint !e702 !e960 MISRA 12.7 REQ, allow signed right shift, its positive anyway */
       i = (unsigned int)int_tmp;
    }
    if (i > 4U) {
      i= 4U;
    } 
    {
      uint_tmp = (unsigned int)(int)e - (i << 3U);
      e = (EXPON)uint_tmp;
    }
    res= arr[i+7U];
    while (e > 8) {
      {
         int_tmp = (int)e >> 3;  /*lint !e702 !e960 MISRA 12.7 REQ, allow signed right shift, its positive anyway */
         i = (unsigned int)int_tmp;                                                  
      }
      if (i > 4U) {
         i= 4U;
      }
      {
         uint_tmp = (unsigned int)(int)e - (i << 3U);
         e = (EXPON)uint_tmp;
      }
      res*= arr[i+7U];
    }
    return res*arr[e];
  }
}
#endif

/*lint --e{750} suppress the message on macros 'DIGITS' and 'BOUND' not being referenced */

#if defined(__DOUBLE_IS_IEEE32__)
  #define DIGITS  6
  #define BOUND   1.0E-6F
#elif defined (__DOUBLE_IS_DSP__)
  #define DIGITS  4
  #define BOUND   1.0E-4F
#else
  #if !defined(__DOUBLE_IS_IEEE64__)
    /* assume double is IEEE64 by default */
    #pragma warning "assume double is IEEE64"
  #endif

  #define DIGITS  14
  #define BOUND   1.0E-14F
#endif

/*****************************************************/
#define MyAbs(v)     (((v) < 0) ? -(v) : (v))
/*****************************************************/

#define LEN(array)  (sizeof(array)/sizeof(array[0]))
#define F_DIGITS  (LEN(pow10)-2U)

#if defined (__PPC__) || defined(__HC12__) || defined(__M68K__) || defined(__MCORE__) || defined(__XA__)
#define USE_UNION 0
#else
#define USE_UNION 1
#endif

#if USE_UNION
#define str _local._str
#define val _local._num._val
#define pwr _local._num._pow
#define fval  _local._num._flt
#define expon  _local._num._exp
#if LIBDEF_PRINTF_FLOATING
#define exp0 _local._int
#endif
#endif

#define dig c


#if LIBDEF_REENTRANT_PRINTF
static void _out(char c, struct __print_buf* desc);
#define out(c) _out(c,desc); pbuf_i++
#else
static void _out(char c);
#define out(c) _out((c))
#define pbuf_i pbuf.i
#endif

#if LIBDEF_REENTRANT_PRINTF
int __vprintf_desc(LIBDEF_ConstStringPtr format, va_list args, struct __print_buf* desc) {   /* reentrant version of printf */
#else
int vprintf(LIBDEF_ConstStringPtr format, va_list args) {
#endif
  int int_tmp;               /* necessary for compliance with MISRA 10.1 REQ & 10.3 REQ */
  unsigned int uint_tmp;     /* necessary for compliance with MISRA 10.1 REQ & 10.3 REQ */
  short short_tmp;           /* necessary for compliance with MISRA 10.1 REQ & 10.3 REQ */
  unsigned short ushort_tmp; /* necessary for compliance with MISRA 10.1 REQ & 10.3 REQ */
#if LIBDEF_PRINTF_LONG
  #if LIBDEF_PRINTF_LLONG
	long long llong_tmp;
  #endif
	long long_tmp;             /* necessary for compliance with MISRA 10.1 REQ & 10.3 REQ */
#endif
#if LIBDEF_PRINTF_FLOATING
  double double_tmp;         /* necessary for compliance with MISRA 10.1 REQ & 10.3 REQ */
#endif

  unsigned int flags;
  
#if LIBDEF_PRINTF_PREC
  unsigned int prec;
#endif
  unsigned int len;
  int width;

  char c;
#if 1 /* the address of c1 is taken. By using a separate var, more optimizations with c are possible */
  char c1;
#else
#define c1 c
#endif

#if USE_UNION
  union {
#if LIBDEF_PRINTF_FAR_PTR
    char *_FAR _str;
#else
    LIBDEF_StringPtr _str;
#endif
#if LIBDEF_PRINTF_FLOATING
    int _int;
#endif    
    struct {
      unsigned _PRINTF_INTEG _val;
      unsigned _PRINTF_INTEG _pow;
#if LIBDEF_PRINTF_FLOATING
      double _flt;
      EXPON _exp;
#endif
    } _num;
  } _local;
#else  /* USE_UNION */
#if LIBDEF_PRINTF_FAR_PTR
  char *_FAR str;
#else
  LIBDEF_StringPtr str; /*lint !e625 options ConstQualiNear and -NonConstQualiNear force qualifier 'far' on library pointer types */
#endif
  unsigned _PRINTF_INTEG val;
  unsigned _PRINTF_INTEG pwr;
#if LIBDEF_PRINTF_FLOATING
  int exp0;
  double fval;
  EXPON expon;
#endif
#endif /* USE_UNION */
#if LIBDEF_REENTRANT_PRINTF
  int pbuf_i=0;
#endif
  while (*format) {
    if (*format != (char)'%') {
      out(*format);
      ++format;
      continue;
    } else {
      flags = 0U;
#if LIBDEF_PRINTF_PREC
      prec = 0U;
#endif
      width = 0;
      for (;;) {
        ++format;
        switch (*format) {
          case '-':
            flags |= _PRINTF_LEFT;
            continue;
          case '+':
            flags |= _PRINTF_SIGNED;
            continue;
          case ' ':
            flags |= _PRINTF_BLANK;
            continue;
          case '0':
            flags |= _PRINTF_ZEROPAD;
            continue;
          case '#':
            flags |= _PRINTF_ALT;
            continue;
          default: break;
        }
        break;
      }
      if (flags & _PRINTF_SIGNED) {
        flags &= ~_PRINTF_BLANK;   /*lint !e960 , MISRA 10.5 REQ, '~' applied to an operand of type 'unsigned int' */
      }
      if (flags & _PRINTF_LEFT) {
        flags &= ~_PRINTF_ZEROPAD; /*lint !e960 , MISRA 10.5 REQ, '~' applied to an operand of type 'unsigned int' */
      }

      /* field width */
      if (*format == (char)'*') {
        width = va_arg(args, int); /*lint !e506 , MISRA 13.7 REQ & MISRA 14.1 REQ, default data type formats can be changed with the -T option */
        ++format;
      } else {
        c = *format;
        while ((c >= (char)'0') && (c <= (char)'9')) {
          width = ((10*width) + (int)c) - '0';
          ++format;
          c = *format;
        }
      }
#if LIBDEF_PRINTF_PREC
      /* precision */
      if (*format == (char)'.') {
        flags |= _PRINTF_PREC;
        ++format;
        if (*format == (char)'*') {
          prec = (unsigned int)va_arg(args, unsigned short); /*lint !e506 , MISRA 13.7 REQ & MISRA 14.1 REQ, default data type formats can be changed with the -T option */
          ++format;
        } else {
          c = *format;
          while ((c >= (char)'0') && (c <= (char)'9')) {
#ifdef __CHAR_IS_SIGNED__
            prec = ((10U*prec) + (unsigned int)(int)c) - (unsigned int)'0';
#else
            prec = ((10U*prec) + (unsigned int)c) - (unsigned int)'0';
#endif            
            ++format;
            c = *format;
          }
        }
      }
#endif /* LIBDEF_PRINTF_PREC */
      /* long or short argument */
#if LIBDEF_PRINTF_LONG
      if ((*format == (char)'L') || (*format == (char)'l')) {
        flags |= _PRINTF_LONGVAL;
        ++format;
#if LIBDEF_PRINTF_LLONG
		if ((*format == (char)'L') || (*format == (char)'l')) {
		  flags &= ~_PRINTF_LONGVAL;
		  flags |= _PRINTF_LLONGVAL;
          ++format;
		}
#endif
      } else 
#endif
      if (*format == (char)'h') {
        flags |= _PRINTF_SHORTVAL;
        ++format;
      }
#if LIBDEF_PRINTF_LONG
      else { /* no special actions at this point for a format character other than 'L', 'l' or 'h'  */
      }
#endif      
      /* conversions */
      
      switch (*format++) {
        case '%':
          out((char)'%');
          continue;

#if LIBDEF_PRINTF_NOF_CHAR
#if LIBDEF_PRINTF_FAR_PTR
        case 'N': /* return nof chars */
          if (flags & _PRINTF_SHORTVAL) {
            *va_arg(args, short int *FAR) = pbuf_i;
#if LIBDEF_PRINTF_LONG
	#if LIBDEF_PRINTF_LLONG
		  } else if (flags & _PRINTF_LLONGVAL) {
            *va_arg(args, long long int *FAR) = pbuf_i;
	#endif
		  } else if (flags & _PRINTF_LONGVAL) {
            *va_arg(args, long int *FAR) = pbuf_i;
#endif
          } else {
            *va_arg(args, int *FAR) = pbuf_i;
          }
          continue;
#endif
        case 'n': /* return nof chars */
          if (flags & _PRINTF_SHORTVAL) {
            /*lint -e{506} , MISRA 13.7 REQ & MISRA 14.1 REQ, default data type formats can be changed with the -T option */
            /*lint -e{826} safe conversion */
            *va_arg(args, short int*) =(short int)pbuf_i;
#if LIBDEF_PRINTF_LONG
	#if LIBDEF_PRINTF_LLONG
          } else if (flags & _PRINTF_LLONGVAL) {
            *va_arg(args, long long int*) = (int)pbuf_i;
	#endif
          } else if (flags & _PRINTF_LONGVAL) {
            /*lint -e{506} , MISRA 13.7 REQ & MISRA 14.1 REQ, default data type formats can be changed with the -T option */
            /*lint -e{826} safe conversion */
            *va_arg(args, long int*) = (int)pbuf_i;
#endif
          } else {
            /*lint -e{506} , MISRA 13.7 REQ & MISRA 14.1 REQ, default data type formats can be changed with the -T option */
            /*lint -e{826} safe conversion */            
            *va_arg(args, int*) = (int)pbuf_i;
          }
          continue;
#endif /* LIBDEF_PRINTF_NOF_CHAR */

#if LIBDEF_PRINTF_CHAR
        case 'c': /* char */
          /*lint -e{506} , MISRA 13.7 REQ & MISRA 14.1 REQ, default data type formats can be changed with the -T option */
#ifdef __CHAR_IS_SIGNED__          
          c1 = (char)va_arg(args, int);
#else
          int_tmp = va_arg(args, int);
          c1 = (char)int_tmp;
#endif          
          str = (LIBDEF_StringPtr) &c1; /*lint !e926 , MISRA 11.4 ADV, conversion is necessary and safe */
          len = 1U;
          goto string;                  /*lint !e801 Use of goto is not deprecated */
#endif

#if LIBDEF_PRINTF_FAR_PTR
        case 'S':
          flags |= _PRINTF_FARVAL;
          str = va_arg(args, char *FAR);
          len = 0;
          if (str) {
            while (str[len]) {
              ++len;
            }
          }
          goto string; /*lint !e801 Use of goto is not deprecated */
#endif
        case 's':  /* string */
#ifdef __USER_DEF_QUALIS__
          str = va_arg(args, char *);
#else
          /*lint -e{506} , MISRA 13.7 REQ & MISRA 14.1 REQ, default data type formats can be changed with the -T option */
          str = va_arg(args, LIBDEF_StringPtr);
#endif          
          len = 0U;
          if (str) {
            while (str[len]) {
              ++len;
            }
          }
string:
        
#if LIBDEF_PRINTF_PREC
          /* adjust length to precision */
          if (prec && (prec < len)) {
            len = prec;
          }
#endif
          if (width > (int)len) {
            uint_tmp = (unsigned int)width - len;
            width = (int)uint_tmp;
          } else {
            width = 0;
          }
          /* pad left */
          if (!(flags & _PRINTF_LEFT)) {
            while (width) {
              out((char)' '); --width;
            }
          }            
          /* output string */
          while (len) {
            out(*str); ++str; --len; /*lint !e613 Possible use of null pointer 'str' in argument */
          }
          /* pad right */
          while (width) {
            out((char)' '); --width;
          }
          continue;

#if LIBDEF_PRINTF_FAR_PTR
        case 'P':
          flags |= _PRINTF_FARVAL;
          /*lint -fallthrough */
#endif
#if LIBDEF_PRINTF_PTR
        case 'p':
          if (sizeof(void*) != sizeof(unsigned int)) { /*lint !e506 !e774 , MISRA 13.7 REQ & MISRA 14.1 REQ, the Boolean value is target-dependent */
            flags |= _PRINTF_PTR;
          }
          /*lint -fallthrough */
#endif
#if LIBDEF_PRINTF_ALLOW_HEXINT
         /*lint -fallthrough */
        case 'X': /* _PRINTF_INTEGer */
          flags |= _PRINTF_UPPER;
          /*lint -fallthrough */
        case 'x':
          flags |= _PRINTF_HEXINT;
          goto unsig_int; /*lint !e801 Use of goto is not deprecated */
#endif
#if LIBDEF_PRINTF_ALLOW_OCTINT
        case 'o':
          flags |= _PRINTF_OCTINT;
          /*lint -fallthrough */
#endif        
        case 'u':

unsig_int:
          /* get unsigned _PRINTF_INTEGer */
          flags &= ~_PRINTF_NEG; /*lint !e960 MISRA 10.5 REQ, '~' applied to an operand of type 'unsigned int' */
#if LIBDEF_PRINTF_FAR_PTR
          if (flags & _PRINTF_FARVAL) {
            val = (unsigned _PRINTF_INTEG) va_arg(args, char *FAR);
          } else
#endif
          if (flags & _PRINTF_SHORTVAL) {
            /*lint -e{506} , MISRA 13.7 REQ & MISRA 14.1 REQ, default data type formats can be changed with the -T option */
            ushort_tmp = va_arg(args, unsigned short); 
            val = (unsigned _PRINTF_INTEG)ushort_tmp;
#if LIBDEF_PRINTF_LONG
	#if LIBDEF_PRINTF_LLONG
          } else if (flags & _PRINTF_LLONGVAL) {
            val = va_arg(args, unsigned long long); 
	#endif
		  } else if (flags & _PRINTF_LONGVAL) {
            /*lint -e{506} , MISRA 13.7 REQ & MISRA 14.1 REQ, default data type formats can be changed with the -T option */
            val = va_arg(args, unsigned long);
#endif
          } else {
#if LIBDEF_PRINTF_PTR
            if ((sizeof(void*) != sizeof(unsigned int)) && ((flags & _PRINTF_PTR) != 0U)) { /*lint !e506 !e774 !e845 , MISRA 13.7 REQ & MISRA 14.1 REQ, target-dependent Boolean expressions */
              /* support for %p for targets with non int pointer sizes */
              /*lint -e{506} , MISRA 13.7 REQ & MISRA 14.1 REQ, default data type formats can be changed with the -T option */
              /*lint -e{923} , MISRA 11.3 ADV, the cast is necessary, see comment above */
              val = (unsigned _PRINTF_INTEG)va_arg(args, void*);
            } else {
              /*lint -e{506} , MISRA 13.7 REQ & MISRA 14.1 REQ, default data type formats can be changed with the -T option */
              uint_tmp = va_arg(args, unsigned int); 
              val = (unsigned _PRINTF_INTEG)uint_tmp;
            }
#else
            val = va_arg(args, unsigned int);
#endif /* LIBDEF_PRINTF_PTR */
          }
          goto integer; /*lint !e801 Use of goto is not deprecated */

        case 'i':
        case 'd':
          /* get signed integer */
          if (flags & _PRINTF_SHORTVAL) {
            /*lint -e{506} , MISRA 13.7 REQ & MISRA 14.1 REQ, default data type formats can be changed with the -T option */
            short_tmp = va_arg(args, short);
            val = (unsigned _PRINTF_INTEG)(_PRINTF_INTEG)short_tmp;
#if LIBDEF_PRINTF_LONG
	#if LIBDEF_PRINTF_LLONG
          } else if (flags & _PRINTF_LLONGVAL) {
            llong_tmp = va_arg(args, long long);
            val = (unsigned _PRINTF_INTEG)llong_tmp; 
	#endif
		  } else if (flags & _PRINTF_LONGVAL) {
            /*lint -e{506} , MISRA 13.7 REQ & MISRA 14.1 REQ, default data type formats can be changed with the -T option */
            long_tmp = va_arg(args, long);
            val = (unsigned _PRINTF_INTEG)long_tmp;
#endif
          } else {
            /*lint -e{506} , MISRA 13.7 REQ & MISRA 14.1 REQ, default data type formats can be changed with the -T option */
            int_tmp = va_arg(args, int);
            val = (unsigned _PRINTF_INTEG)(_PRINTF_INTEG)int_tmp;
          }

          if ((_PRINTF_INTEG) val < 0) {
            _PRINTF_INTEG tmp = -(_PRINTF_INTEG)val; /* necessary for compliance with MISRA 10.3 REQ */
            val = (unsigned _PRINTF_INTEG)(tmp);
            flags |= _PRINTF_NEG;
          }

integer:

          len = 1U;
#if LIBDEF_PRINTF_ALLOW_OCTINT && LIBDEF_PRINTF_ALLOW_HEXINT
          if (flags & _PRINTF_OCTINT) {
            while ((len < LEN(pow8)) && (val >= pow8[len])) { ++len; }   /*lint !e960 the result of sizeof() is size_t, which is defined to 'unsigned int' */
          } else if (flags & _PRINTF_HEXINT) {
            while ((len < LEN(pow16)) && (val >= pow16[len])) { ++len; } /*lint !e960 the result of sizeof() is size_t, which is defined to 'unsigned int' */
          } else {
            while ((len < LEN(pow10)) && (val >= pow10[len])) { ++len; } /*lint !e960 the result of sizeof() is size_t, which is defined to 'unsigned int' */
          }
#elif LIBDEF_PRINTF_ALLOW_OCTINT
          if (flags & _PRINTF_OCTINT) {
            while ((len < LEN(pow8)) && (val >= pow8[len])) { ++len; }   /*lint !e960 the result of sizeof() is size_t, which is defined to 'unsigned int' */
          } else {
            while ((len < LEN(pow10)) && (val >= pow10[len])) { ++len; } /*lint !e960 the result of sizeof() is size_t, which is defined to 'unsigned int' */
          }
#elif LIBDEF_PRINTF_ALLOW_HEXINT
         if (flags & _PRINTF_HEXINT) {
            while ((len < LEN(pow16)) && (val >= pow16[len])) { ++len; } /*lint !e960 the result of sizeof() is size_t, which is defined to 'unsigned int' */
          } else {
            while ((len < LEN(pow10)) && (val >= pow10[len])) { ++len; } /*lint !e960 the result of sizeof() is size_t, which is defined to 'unsigned int' */
          }
#else 
          while ((len < LEN(pow10)) && (val >= pow10[len])) { ++len; }
#endif
          
#if LIBDEF_PRINTF_PREC
          /* width of integer */
          if (prec > len)  {
            prec -= len;
          } else {
            prec = 0U;
          } 
          {
            uint_tmp = (unsigned int) width - (prec + len);
            width = (int)uint_tmp;
          }
#else
          width -= len;
#endif /* LIBDEF_PRINTF_PREC */

#if LIBDEF_PRINTF_ALLOW_OCTINT && LIBDEF_PRINTF_ALLOW_HEXINT
          if (flags & _PRINTF_ALT) {
            if (flags & _PRINTF_OCTINT) {
              --width;
            } else if (flags & _PRINTF_HEXINT) {
              width -= 2;
            } else { /* the value of 'width' does not change */
            }            
          }
#elif LIBDEF_PRINTF_ALLOW_OCTINT
          if ((flags & (_PRINTF_ALT|_PRINTF_OCTINT))==(_PRINTF_ALT|_PRINTF_OCTINT)) {
            --width;
          } 
#elif LIBDEF_PRINTF_ALLOW_HEXINT
          if ((flags & (_PRINTF_ALT|_PRINTF_HEXINT))==(_PRINTF_ALT|_PRINTF_HEXINT)) {
            width -= 2;
          } 
#endif
          if (flags & _PRINTF_NEG) {
            --width;
          }
          
          if (width < 0) {
            width = 0;
          }
          
          /* pad left */
          if (width && !(flags & _PRINTF_LEFT)) {
            if (!(flags & _PRINTF_ZEROPAD)) {/* pad with spaces */
              do {
                out((char)' '); --width;
              } while (width);
            } else {
              /* pad with zeros */
#if LIBDEF_PRINTF_PREC
              prec += (unsigned int)width; 
              width = 0;
#else
              do {
                out((char)'0'); --width;
              } while (width);
#endif
            }
          }

          /* alternate form of integers for oct and hex numbers */
#if LIBDEF_PRINTF_ALLOW_HEXINT && LIBDEF_PRINTF_ALLOW_OCTINT
          if ((flags & _PRINTF_ALT) && (flags & _PRINTF_NOT_DEC)) {
            out((char)'0');
            if (flags & _PRINTF_HEXINT) {
              if (flags & _PRINTF_UPPER) {
                out((char)'X');
              } else {
                out((char)'x');
              }
            }
          }
#elif LIBDEF_PRINTF_ALLOW_HEXINT
          if ((flags & (_PRINTF_ALT|_PRINTF_HEXINT)) == (_PRINTF_ALT|_PRINTF_HEXINT)) {
            out('0');
            if (flags & _PRINTF_UPPER) {
              out('X');
            } else {
              out('x');
            }
          }
#elif LIBDEF_PRINTF_ALLOW_OCTINT
          if ((flags & (_PRINTF_ALT|_PRINTF_OCTINT)) == (_PRINTF_ALT|_PRINTF_OCTINT)) {
            out('0');
          }
#endif

          /* sign */
          if (flags & _PRINTF_SIGNED) {
            if (flags & _PRINTF_BLANK) {
              out((char)'-');
            } else {
              out((char)'+');
            }
          } else if (flags & _PRINTF_BLANK) {
            out((char)' ');
          } else { /* nothing to output */
          }

#if LIBDEF_PRINTF_PREC
          /* pad with zeros to precision */
          while (prec) {
            out((char)'0'); --prec;
          }
#endif
          /* output conversion. par: val, len; local: dig, pwr*/
          do {
            dig = (char)0;
            --len;
#if LIBDEF_PRINTF_ALLOW_OCTINT && LIBDEF_PRINTF_ALLOW_HEXINT
            if (flags & _PRINTF_OCTINT) {
              pwr = pow8[len];
            } else if (flags & _PRINTF_HEXINT) {
              pwr = pow16[len];  /*lint !e661 !e662 (no out-of-bounds access) */
            } else {
              pwr = pow10[len];  /*lint !e661 (no out-of-bounds access) */
            }
#elif LIBDEF_PRINTF_ALLOW_OCTINT
            if (flags & _PRINTF_OCTINT) {
              pwr = pow8[len];
            } else {
              pwr = pow10[len];
            }
#elif LIBDEF_PRINTF_ALLOW_HEXINT
            if (flags & _PRINTF_HEXINT) {
              pwr = pow16[len];
            } else {
              pwr = pow10[len];
            }
#else
            pwr = pow10[len];
#endif

            while (val >= pwr) {
              val -= pwr;
              ++dig;
            }
#if LIBDEF_PRINTF_ALLOW_HEXINT
            if ((int)dig < 10) {
              int_tmp = (int)dig + '0';
              out((char)int_tmp);
            } else if (flags & _PRINTF_UPPER) {
              int_tmp = ((int)dig + 'A') - 10;
              out((char)int_tmp);
            } else {
              int_tmp = ((int)dig + 'a') - 10;
              out((char)int_tmp);
            }
#else 
            out(dig + '0');
#endif
          } while (len);

          /* append spaces to field width */
          while (width) {
            out((char)' '); --width;
          }
          continue;

#if LIBDEF_PRINTF_FLOATING
        case 'E': /* float */
          flags |= _PRINTF_UPPER;
          /* fall through */
        case 'e': /*lint !e825 fallthrough is deliberate */
          flags |= _PRINTF_ETYPE;
          goto real; /*lint !e801 Use of goto is not deprecated */

        case 'f':
          flags |= _PRINTF_FTYPE;
          goto real; /*lint !e801 Use of goto is not deprecated */

        case 'G':
          flags |= _PRINTF_UPPER;
          /* fall through */
        case 'g': /*lint !e825 fall through is deliberate */
          flags |= _PRINTF_GTYPE;
          /* fall through */
real:
          if (!(flags & _PRINTF_PREC)) {/* default precision */
            prec = 6U;
          }
          fval = va_arg(args, double); /*lint !e506 , MISRA 13.7 REQ & MISRA 14.1 REQ, default data type formats can be changed with the -T option */
#ifndef __S12LISA__
          if (fval < 0.0) {
#else
          if (isSignMinus(fval)) {
#endif
            fval = (-fval);
            flags |= _PRINTF_NEG;
          }
          
          expon = 0;
          if (fval != 0.0) {
#if defined(__DOUBLE_IS_IEEE32__) && !defined(__XGATE__) 
            (void)frexpf((float)fval, &exp0);
#else
            (void)frexp(fval, &exp0);
#endif
            expon = (EXPON)((exp0 * 3) / 10);  /*ln(2)/ln(10) = 0.30102999..*/
          }
          if ((flags & _PRINTF_ETYPE) && (!(flags & _PRINTF_FTYPE) || (expon < -4) || (expon >= (int) prec))) {
            /* base conversion */
            if (fval != 0.0) {
              fval *= Ten(-expon);
              if (fval != 0.0) {
                while (fval >= 10.0) {
                  fval *= 1e-1; ++expon;
                }
                while (fval < 1.0) {
                  fval *= 10.0; --expon;
                }
              }
            }
            /* x = fval * 10 ^ expon; 1 <= fval < 10 */
            /* e type conversion */
            if (prec && (flags & _PRINTF_FTYPE)) {/* for g type: prec = nof significant digits */
              --prec;
            }
            if (prec < F_DIGITS) { /*lint !e960 the type of the result of sizeof() is size_t, which is defined to 'unsigned int' */
              fval += 0.5*Ten(-(EXPON)prec);
            }
#if 1 /* if rounding causes overflow */
            if (fval >= 10.0) {
              fval *= 1e-1; ++expon;
            }
#endif              
            /*adjust precision for g type conversion (remove trailing zeros)*/
            if (prec && (flags & _PRINTF_FTYPE) && !(flags & _PRINTF_ALT)) {
              if (prec > F_DIGITS) { /*lint !e960 the type of the result of sizeof() is size_t, which is defined to 'unsigned int' */
                prec = F_DIGITS;     /*lint !e960 the type of the result of sizeof() is size_t, which is defined to 'unsigned int' */
              }
                
              {
                double_tmp = fval * Ten((EXPON)prec); /* necessary for compliance with MISRA 10.4 REQ */
                val = (unsigned _PRINTF_INTEG)double_tmp;
              }

              if (val) {
                while (prec && ((val % 10U) == 0U)) {
                  val /= 10U; --prec;
                }
              } else {
                prec = 0U;
              }
            }
            flags &= ~_PRINTF_FTYPE; /*lint !e960 MISRA 10.5 REQ, '~' applied to an operand of type 'unsigned int' */
            
            /* width of e type conversion */
            {
              uint_tmp = (unsigned int)width - (5U + prec); /*minimum: dE+dd*/
              width = (int)uint_tmp;
            }
            if (prec || (flags & _PRINTF_ALT)) { /*decimal point*/
              --width;
            }
            if (flags & _PRINTF_NEG) {     /*sign or blank*/
              --width;
            }
            if (MyAbs(expon) >= 100) {       /*additional digit for exponent*/
              --width;
            }

            val = (unsigned _PRINTF_INTEG)fval;
            fval -= (double) val;
            len = 1U;
          } else  {/* f type conversion */
            /*float = fval * 10 ^ expon; fval is not restricted to 1 <= fval < 10 !!!*/
            
            /*adjust precision for g type conversion (trailing zeros)*/
            if (prec && (flags & _PRINTF_ETYPE) && !(flags & _PRINTF_ALT)) { 
              {
                int_tmp = (int)expon + 1;                
                prec -= (unsigned int)int_tmp; /*prec >= expon*/
              }
              if ((expon < 0) || (fval < 1.0)) { /*leading 0 is not significant*/
                ++prec;
              }
              if (prec > F_DIGITS) { /*lint !e960 the type of the result of sizeof() is size_t, which is defined to 'unsigned int' */
                prec = F_DIGITS;     /*lint !e960 the type of the result of sizeof() is size_t, which is defined to 'unsigned int' */
              } 
              {
                double_tmp = (fval*Ten((EXPON)prec))+0.5;               
                val = (unsigned _PRINTF_INTEG)double_tmp;
              }
              while (prec && !(val % 10U)) {
                val /= 10U; --prec;
              }
            }
            flags &= ~_PRINTF_ETYPE; /*lint !e960 MISRA 10.5 REQ, '~' applied to operand of type 'unsigned int') */
            {
              uint_tmp = (unsigned int)(int)expon-F_DIGITS; /*lint !e960 the type of the result of sizeof() is size_t, which is defined to 'unsigned int' */

			  if ((EXPON) uint_tmp >= -(EXPON)prec && sizeof(double) == 4) {
                fval += 0.5*Ten((EXPON)uint_tmp);
              } else {
                fval += 0.5*Ten(-(EXPON)prec);
              }
			}

            /* width of type f conversion */
            if (expon >= 0) {/* (expon + 1) digits before dec pt */
              if ((unsigned int)(int)expon > F_DIGITS) {                  /*lint !e960 the type of the result of sizeof() is size_t, which is defined to 'unsigned int' */
                {
                  uint_tmp = (unsigned int)(int)expon - F_DIGITS; /*lint !e960 the type of the result of sizeof() is size_t, which is defined to 'unsigned int' */
                  expon = (EXPON)uint_tmp; 
                } 
                {
                  double_tmp = fval * Ten(-expon);                  
                  val = (unsigned _PRINTF_INTEG)double_tmp;
                }
                fval = 0.0;
              } else {
                val = (unsigned _PRINTF_INTEG)fval;
                fval -= (double) val;
                expon = 0;
              }
            } else {
              val = 0U;
              expon = 0;
            }

            len = 1U;
            while ((len < LEN(pow10)) && (val >= pow10[len])) {  /*lint !e960 the type of the result of sizeof() is size_t, which is defined to 'unsigned int' */
              ++len;
            }
            
            {
              uint_tmp = (unsigned int)width - (prec + len + (unsigned int)(int)expon);
              width = (int)uint_tmp;
            }
            
            if (prec || (flags & _PRINTF_ALT)) { /*decimal point*/
              --width;
            }
            if (flags & _PRINTF_NEG) {     /*sign or blank*/
              --width;
            }

          }

          if (width < 0) {            
            width = 0;
          }

          /* pad left */
          if (!(flags & _PRINTF_LEFT)) {
            if (!(flags & _PRINTF_ZEROPAD)) {/*pad with spaces before sign*/
              while (width) {
                out((char)' '); --width;
              }
            }
          }
          /*!(flags & _PRINTF_LEFT) && !(flags & _PRINTF_ZEROPAD) => (width == 0)*/

          /*sign*/
          if (flags & _PRINTF_SIGNED) {
            if (flags & _PRINTF_BLANK) {
              out((char)'-');
            } else {
              out((char)'+');
            }
          } else if (flags & _PRINTF_BLANK) {
            out((char)' ');
          } else { /* nothing to output */
          }

          if (!(flags & _PRINTF_LEFT)) { /*pad with zeros after sign (if width still > 0)*/
            while (width) {
              out((char)'0'); --width;
            }
          }
          
          /* float conversion */

          /*print all digits before decimal point*/
          do {
            --len;
            dig = (char)'0';
            pwr = pow10[len];
            while (val >= pwr) {
              val -= pwr; ++dig;
            }
            out(dig);
          } while (len);
          
          if (flags & _PRINTF_FTYPE) {/* add zeros before decimal point */
            while (expon > 0) {
              out((char)'0'); --expon;
            }
          }
          
          if (prec || (flags & _PRINTF_ALT)) {
            out((char)'.');
            if(prec > 0U) {
              if (prec > F_DIGITS) {  /*lint !e960 the type of the result of sizeof() is size_t, which is defined to 'unsigned int' */
                len = F_DIGITS;       /*lint !e960 the type of the result of sizeof() is size_t, which is defined to 'unsigned int' */
              } else {
                len = prec;
              }
              
              prec -= len;
  
              if (flags & _PRINTF_FTYPE) {
                uint_tmp = len - (unsigned int)(int)expon;
                double_tmp = fval * Ten((EXPON)uint_tmp);
                val = (unsigned _PRINTF_INTEG)double_tmp; /*10^(-expon) --> 1 <= fval < 10 */
              } else {
                double_tmp = fval * Ten((EXPON)len);
                val = (unsigned _PRINTF_INTEG)double_tmp;
              }
              
              /*out int val */
              do {
                --len;
                dig = (char)'0';
                pwr = pow10[len];
                while (val >= pwr) {
                  val -= pwr; ++dig;
                }
                out(dig);
              } while (len);
              
              while (prec) {
                out((char)'0'); --prec;
              }
            } /* if prec > 0 */
          } 
          if (flags & _PRINTF_ETYPE) { /*exponent*/
            if (flags & _PRINTF_UPPER) {
              out((char)'E');
            } else {
              out((char)'e');
            }
            if (expon < 0) {
              expon = (-expon);
              out((char)'-');
            } else {
              out((char)'+');
            }
          
            if (expon >= 100) {
              int_tmp = ((int)expon / 100) + '0'; /* required for compliance with MISRA 10.3 REQ */
              out((char)int_tmp);
              expon = (EXPON)(expon % 100);
            } 
            {
              int_tmp = ((int)expon / 10) + '0';  /* required for compliance with MISRA 10.3 REQ */
              out((char)int_tmp);
            } 
            {
              int_tmp = ((int)expon % 10) + '0';  /* required for compliance with MISRA 10.3 REQ */
              out((char)int_tmp);
            }
          }

          /* pad right */
          while (width) {
            out((char)' '); --width;
          }
#else
        case 'E':
        case 'e':
        case 'f':
        case 'G':
        case 'g':
          /*lint -e{506} , MISRA 13.7 REQ & MISRA 14.1 REQ, default data type formats can be changed with the -T option */
          /*lint -e{522} , MISRA 14.2 REQ, the argument is dropped */
          va_arg(args, double); /* drop it */
#endif
        default: /*lint !e825 fallthrough is deliberate */
          continue;

      } /* switch (*format++) */
    } /* if (*format != '%') */
  } /* while (*format) */
  return (int)(pbuf_i);
} /* vprintf */ /*lint !e818 , MISRA 16.7 ADV, this is a standard library function, cannot change its prototype */


#if LIBDEF_REENTRANT_PRINTF
 /* support of non-reentrant version of vprintf */
static void (*f_callback)(char);
static void outc_callback(char c, struct __print_buf* This) {
  f_callback(c);
}
static struct __print_buf pbuf={(__printf_callback)outc_callback};
void set_printf(void (*f)(char)) {
  f_callback = f;
}

int vprintf(LIBDEF_ConstStringPtr format, va_list args) {    
  return __vprintf_desc(format, args, &pbuf);
}

/* sprintf */
struct __sprintfBuf {
  struct __print_buf p;
  LIBDEF_StringPtr s;
  int i;
};

static void deposit_char(char c, struct __sprintfBuf* p) {
  p->s[p->i] = c;
  p->i++;
}

int sprintf(LIBDEF_StringPtr s, LIBDEF_ConstStringPtr format, ...) {
  va_list args;
  struct __sprintfBuf p;
 
  p.i = 0;
  p.s = s;
  p.p.outc = (__printf_callback)deposit_char;
  va_start(args, format);
  (void)__vprintf_desc(format, args, (struct __print_buf*)&p);
  p.s[p.i] = 0;
  va_end(args);
  return p.i;
}

int vsprintf(LIBDEF_StringPtr s, LIBDEF_ConstStringPtr format, va_list args) {
  struct __sprintfBuf p;
  p.i = 0;
  p.s = s;
  p.p.outc = (__printf_callback)deposit_char;
  (void)__vprintf_desc(format, args, (struct __print_buf*)&p);
  p.s[p.i] = 0;
  return p.i;
}

int snprintf(LIBDEF_StringPtr s, size_t n, LIBDEF_ConstStringPtr format, ...) {
  va_list args;
  struct __sprintfBuf p;
 
  p.i = 0;
  p.s = s;
  p.p.outc = (__printf_callback)deposit_char;
  va_start(args, format);
  (void)__vprintf_desc(format, args, (struct __print_buf*)&p);
  va_end(args);
  if (p.s != NULL) {
    if ((size_t) p.i < n)
      p.s[p.i] = 0;
    else if (n > 0U)
      p.s[n - 1U] = 0;
  }
  return p.i;
}

int vsnprintf(LIBDEF_StringPtr s, size_t n, LIBDEF_ConstStringPtr format, va_list args) {
  struct __sprintfBuf p;
  p.i = 0;
  p.s = s;
  p.p.outc = (__printf_callback)deposit_char;
  (void)__vprintf_desc(format, args, (struct __print_buf*)&p);
  if (p.s != NULL) {
    if ((size_t) p.i < n)
      p.s[p.i] = 0;
    else if (n > 0U)
      p.s[n - 1U] = 0;
  }
  return p.i;
}

static void _out(char c, struct __print_buf* desc) {
  desc->outc((c),(desc));
}

#else

#ifdef __RS08__
#pragma NO_ENTRY
#pragma NO_EXIT
#pragma NO_RETURN
static void _out(char c) {
  ++pbuf.i;
  pbuf.jmp_opcode= (unsigned char)0xBC;
  __asm jmp pbuf.jmp_opcode;
} /*lint !e715 the implementation of function '_out' is target-dependent */
#else
static void _out(char c) {
  pbuf.outc(c);
  ++pbuf.i;
}
#endif

void set_printf(void (*f)(char)) { /*lint !e960 MISRA 16.3 REQ, this is a function pointer parameter */
  /* installs a handler function to write to the terminal */
  pbuf.outc = f;
  pbuf.s = NULL;
  pbuf.i = 0U;
}


/* sprintf */
#if defined(__RS08__)

#pragma NO_ENTRY
#pragma NO_EXIT
 /*lint -esym(528, _save_pc) , '_save_pc' referenced in HLI */
static unsigned int _save_pc;
static void deposit_char(char c) {
  asm {
    STA   c
    MOV   #%HIGH_6_13(_save_pc), __PAGESEL
    SHA
    STA   %MAP_ADDR_6(_save_pc)
    SLA
    STA   %MAP_ADDR_6(_save_pc+1)  
  }
  pbuf.s[pbuf.i-1U] = c;
  asm {
    MOV   #%HIGH_6_13(_save_pc), __PAGESEL
    LDA   %MAP_ADDR_6(_save_pc)
    SHA
    LDA   %MAP_ADDR_6(_save_pc+1)  
    SLA
  }
}

#else /* defined(__RS08__) */

static void deposit_char(char c) {
  pbuf.s[pbuf.i] = c;
}
#endif /* defined(__RS08__) */

int sprintf(LIBDEF_StringPtr s, LIBDEF_ConstStringPtr format, ...) { /*lint !e960 MISRA 16.1 REQ, standard library function  implementation */
  va_list args;
  
  pbuf.i = 0U;
  pbuf.s = s;
  pbuf.outc = deposit_char;
  /*lint -e{643} misleading warning ('&format' does not have a far pointer type) */
  /*lint -e{928} , MISRA 11.4 ADV, safe conversion to 'char *' */
  va_start(args, format);
  (void)vprintf(format, args);
  pbuf.s[pbuf.i] = (char)0;
  va_end(args);
  return (int)(pbuf.i); /*lint !e438 'va_end' must be invoked before return in a variadic function */
}

int vsprintf(LIBDEF_StringPtr s, LIBDEF_ConstStringPtr format, va_list args) {
  pbuf.i = 0U;
  pbuf.s = s;
  pbuf.outc = deposit_char;
  (void)vprintf(format, args);
  pbuf.s[pbuf.i] = (char)0;
  return (int)(pbuf.i);
}

int snprintf(LIBDEF_StringPtr s, size_t n, LIBDEF_ConstStringPtr format, ...) { /*lint !e960 MISRA 16.1 REQ, standard library function  implementation */
  va_list args;
  
  pbuf.i = 0U;
  pbuf.s = s;
  pbuf.outc = deposit_char;
  /*lint -e{643} misleading warning ('&format' does not have a far pointer type) */
  /*lint -e{928} , MISRA 11.4 ADV, safe conversion to 'char *' */
  va_start(args, format);
  (void)vprintf(format, args);
  va_end(args);
  if (pbuf.s != NULL) {
    if ((size_t) pbuf.i < n)
      pbuf.s[pbuf.i] = (char)0;
    else if (n > 0U)
      pbuf.s[n - 1U] = (char)0;
  }
  return (int)(pbuf.i); /*lint !e438 'va_end' must be invoked before return in a variadic function */
}

int vsnprintf(LIBDEF_StringPtr s, size_t n, LIBDEF_ConstStringPtr format, va_list args) {
  pbuf.i = 0U;
  pbuf.s = s;
  pbuf.outc = deposit_char;
  (void)vprintf(format, args);
  if (pbuf.s != NULL) {
    if ((size_t) pbuf.i < n)
      pbuf.s[pbuf.i] = (char)0;
    else if (n > 0U)
      pbuf.s[n - 1U] = (char)0;
  }
  return (int)(pbuf.i);
}

#endif
/*lint --e{766} header file <math.h> contains conditionally compiled code */
