/*****************************************************
     scanf.c - ANSI-C library: sscanf, vsscanf
 ----------------------------------------------------
   Copyright (c) Metrowerks, Basel, Switzerland
               All rights reserved
                  Do not modify!
 *****************************************************/

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <hidef.h>
#include <libdefs.h>
#include <limits.h>
#include <stdtypes.h>

#if defined(__HC12__) && !defined(__S12LISA__)
  #pragma MESSAGE DISABLE C12002 /* WARNING C12002: Use DPAGE, PPAGE, EPAGE to specify the page register. Assumed DPAGE */
#endif
#if defined(__HIWARE__) && !defined(__S12LISA__)
#pragma MESSAGE DISABLE C4001 /* INFORMATION C4001: Condition always FALSE */
#pragma MESSAGE DISABLE C2705 /* Possible loss of data */
#endif

#undef isspace /*lint !e960 MISRA 19.6 REQ, '#undef' necessary (use the 'isspace' function instead of the 'isspace' macro) */
#undef toupper /*lint !e960 MISRA 19.6 REQ, '#undef' necessary (use the 'toupper' function instead of the 'toupper' macro) */

#if (defined(__SHORT_IS_8BIT__) && defined(__INT_IS_8BIT__)) || (defined(__SHORT_IS_16BIT__) && defined(__INT_IS_16BIT__)) || (defined(__SHORT_IS_32BIT__) && defined(__INT_IS_32BIT__)) || (defined(__SHORT_IS_64BIT__) && defined(__INT_IS_64BIT__))
#define SAME_SIZE_INT_SHORT 1
#else
#define SAME_SIZE_INT_SHORT 0
#endif

#if LIBDEF_PRINTF_FLOATING
#if (defined(__FLOAT_IS_IEEE32__) && defined(__DOUBLE_IS_IEEE32__)) || (defined(__FLOAT_IS_IEEE64__) && defined(__DOUBLE_IS_IEEE64__)) || (defined(__FLOAT_IS_DSP__) && defined(__DOUBLE_IS_DSP__))
#define SAME_ENCODING_DOUBLE_FLOAT 1
#else
#define SAME_ENCODING_DOUBLE_FLOAT 0
#endif
#endif

/*****************************************************/
static int _getNum(LIBDEF_ConstStringPtr *format)
{
   int n = 0;
   char ch = **format;
   while ((ch >= (char)'0') && (ch <= (char)'9')) {
      n = ((10*n) + (int)ch) - '0';
      ch = *(++(*format));
   }
   return n;
} /* end _getNum */

/*****************************************************/

#if LIBDEF_MULTI_CHAR_SELECTION
#if LIBDEF_PRINTF_FAR_PTR
static const char *_copyFarList(char *FAR fss, const char *s, const char **nsp, const char *format, int *tasg, int fwi, int ma)
{
   const char *FAR m;
   const char *FAR start;
   char found, sz = 0;
   int count = 0;

   *tasg = 1;
   if(*(++format) == '^') {  /* Set not eql. flag */
      sz = 1; format++;
   }
   start= format;
   if (*format == ']') {
      format++;                   /* Special case */
   }
   while (*format && (*format != ']')) {       /* Set mtchbuf */
      format++;
   }

   while (*s && fwi) {
      fwi--;
      m = start;                            /* Reset m to top */
      while (m != format && *s != *m) { m++; }

      found = (m != format);
      if (sz == found) { 
        if(count == 0) {
          *tasg = 0;
        }
        break;
      }  /* failed */
      if (ma) { *fss++ = *s; }                /* Passed test, next s */
      s++;
      count++;
   }
   if (ma) { *fss = '\0'; }               /* Terminate array */

   *nsp = s;
   return format;
} /* end _copyFarList */
#endif

static LIBDEF_ConstStringPtr _copyList(char *ss, LIBDEF_ConstStringPtr s, LIBDEF_ConstStringPtr*nsp, LIBDEF_ConstStringPtr format, int *tasg, int fwi, int ma)
{
   LIBDEF_ConstStringPtr m, start; /*lint !e625 accept unusual type modifier */
   int found, sz = 0;
   int count = 0;

   *tasg = 1;
   if(*(++format) == (char)'^') {  /* Set not eql. flag */
      sz = 1; format++;
   }
   start= format;
   if (*format == (char)']') {
      format++;                   /* Special case */
   }
   while (*format && (*format != (char)']')) {       /* Set mtchbuf */
      format++;
   }

   while (*s && fwi) {
      fwi--;
      m = start;                            /* Reset m to top */
      while ((m != format) && (*s != *m)) { m++; }

      found = (m != format);
      if (sz == found) { 
        if(count == 0) {
          *tasg = 0; 
        }
        break; 
      }  /* failed */
      if (ma) { *ss++ = *s; }                 /* Passed test, next s */
      s++;
      count++;
   }
   if (ma) { *ss = (char)'\0'; }                       /* Terminate array */

   *nsp = s;
   return format;
} /* end _copyList */
#endif /* LIBDEF_MULTI_CHAR_SELECTION */

/*****************************************************/
/* only internaly used functions defined in stdlib.c */
#if LIBDEF_PRINTF_FLOATING
double _strtod (LIBDEF_ConstStringPtr nptr, LIBDEF_StringPtr *endptr, unsigned int len);
#endif
long int _strtol(LIBDEF_ConstStringPtr nptr, LIBDEF_StringPtr *endptr, int base, unsigned int len);

/*****************************************************/

int vsscanf(LIBDEF_ConstStringPtr ps, LIBDEF_ConstStringPtr format, va_list args)
{
   LIBDEF_ConstStringPtr s=ps;    /*lint !e625 accept unusual type modifier */
   unsigned char sz, ma;          /* Size and no-assign flags  */
   int base;                      /* Base                      */
   LIBDEF_StringPtr nsp;          /* New s position            */ /*lint !e625 accept unusual type modifier */
   char *ss= NULL;
   int ok;
   int fwi;                       /* Field width size          */
   LIBDEF_ConstStringPtr sbase;   /* base addr of string s     */ /*lint !e625 accept unusual type modifier */
   int tasg = 0;                  /* Total assignments made    */
   unsigned char nConversion= 0U; /* TRUE iff %n conversion was done. Does not count as assignment, but affects the return value */

#if LIBDEF_PRINTF_FAR_PTR
   unsigned char is_far_ptr;    /* Is it a FAR pointer */
   char *FAR far_ptr = NULL;    /* FAR pointer */
#endif

   sbase = s;

   while (*format) {
      sz = (unsigned char)(fwi = (base = 0));
      ma = 1U;
      if (isspace((int)*format)) {  /* White space flag */
         while (isspace((int)*format)) { ++format; }    /* Eat white space */
         if (isspace((int)*s)) {
            while(isspace((int)*s)) {
               ++s;
            }   /* Is white space and was eaten */
         }
#if !LIBDEF_SCANF_DONTCARE_SPACES
         else if (*s) { /* Is no white space, is input failure */ 
            goto inputFailure; /*lint !e801 Use of goto is not deprecated */
         } else { /* Do nothing */
         }         
#endif
      }
      if (*format != (char)'%') {/* Read input string */
         if (*s) {
            if (*s++ == *format++) { /*lint !e931 the expression is safe */
               ; /* Character match */
            } else {
               /* non matching character -> match failure-> return number of assignments */
               goto endScan; /*lint !e801 Use of goto is not deprecated */
            }
         } else {
            /* nothing more to match against -> input failure -> return EOF if no assignments done */
            goto inputFailure; /*lint !e801 Use of goto is not deprecated */
         }
      } else {
         /* Conversion specification */
         format++; /* Drop %  */
#if LIBDEF_PRINTF_FAR_PTR
         is_far_ptr = FALSE;
#endif
         if (*format == (char)'*') {
            /* Assignment suppressed */
            format++;
            ma = 0U;
#if LIBDEF_PRINTF_FAR_PTR
         } else if (*format == '+') {
            format++;
            is_far_ptr = TRUE;
#endif
         }

         fwi = _getNum(&format);  /* Get max field width if any */

         switch (*format++) {
            case 'h': sz = 1U; break;
            case 'l': sz = 2U; break;
            case 'L': sz = 3U; break;
            default: format--;
         }

         if (((unsigned char)*s == 0U) && (*format != (char)'n') && (*format != (char)'N') && (*format != (char)'%')) {
           goto inputFailure;  /* input failure */ /*lint !e801 Use of goto is not deprecated */
         }
         switch(*format) {
            case 'd': base = 10;
                      /*lint -fallthrough */ 
            case 'i':
                    {
                      long l = _strtol(s, &nsp, base, (unsigned int)fwi);
                      if (nsp == s) {
                        goto endScan; /* conversion failure */ /*lint !e801 Use of goto is not deprecated */
                      }
                      if (ma)
                      {
#if LIBDEF_PRINTF_FAR_PTR
                         if (is_far_ptr)
                         {
                            switch(sz)
                            {
                               case 1:
                                  *va_arg(args, short int *FAR) = l;
                                  break;
                               case 2:
                               case 3:
                                  *va_arg(args, long int *FAR) = l;
                                  break;
                               default:
                                  *va_arg(args, int *FAR) = l;
                                  break;
                            }
                         } else {
#endif
                            switch(sz)
                            {
                               case 1:
                                  /*lint -e{506} , MISRA 13.7 REQ & MISRA 14.1 REQ, default data type formats can be changed with the -T option */
                                  /*lint -e{826} safe conversion */
                                  *va_arg(args, short int*) = (short int)l;
                                  break;
                               case 2:
                               case 3:
                                  /*lint -e{506} , MISRA 13.7 REQ & MISRA 14.1 REQ, default data type formats can be changed with the -T option */
                                  /*lint -e{826} safe conversion */
                                  *va_arg(args, long int*) = l;
                                  break;
                               default:
                                  /*lint -e{506} , MISRA 13.7 REQ & MISRA 14.1 REQ, default data type formats can be changed with the -T option */
                                  /*lint -e{826} safe conversion */                                  
                                  *va_arg(args, int*) = (int)l;
                                  break;
                            }
#if LIBDEF_PRINTF_FAR_PTR
                         }
#endif
                         tasg++; /* count number of assigned items */
                      }
                      s = nsp;
                      break;
                    }
            case 'o': base = 8;  goto xx; /*lint !e801 Use of goto is not deprecated */
#if LIBDEF_PRINTF_FAR_PTR
            case 'P': sz = 5;
                      base = 16; goto xx; /*lint !e801 Use of goto is not deprecated */
#endif
            case 'p': sz = 4U;
                      /*lint -fallthrough */
            case 'X': 
            case 'x': base = 16; goto xx; /*lint !e801 Use of goto is not deprecated */
            case 'u': {
                      unsigned long l;
                      base = 10;
xx:
                      if (*s == (char)'-') {
                        ++s;  /* Strip sign if any */
                        fwi--;
                      }
                      l = (unsigned long)_strtol(s, &nsp, base, (unsigned int)fwi);
                      if (nsp == s) {
                        goto endScan; /* conversion failure */ /*lint !e801 Use of goto is not deprecated */
                      }
                      if (ma)
                      {
#if LIBDEF_PRINTF_FAR_PTR
                         if (is_far_ptr)
                         {
                            switch(sz)
                            {
                               case 2:
                               case 3:
                                  *va_arg(args, unsigned long int *FAR) = l;
                                  break;
                               case 4:
                                  *va_arg(args, char * *FAR) = (char *) l;
                                  break;
                               case 5:
                                  *va_arg(args, char *FAR *FAR) = (char *FAR) l;
                                  break;
                               case 1:
#if !SAME_SIZE_INT_SHORT
                                  *va_arg(args, unsigned short int *FAR) = l;
                                  break;
#endif
                               default:
                                  *va_arg(args, unsigned int *FAR) = l;
                            }
                         } else {
#endif
                            switch(sz)
                            {
                               case 2:
                               case 3:
                                  /*lint -e{506} , MISRA 13.7 REQ & MISRA 14.1 REQ, default data type formats can be changed with the -T option */
                                  /*lint -e{826} safe conversion */                                  
                                  *va_arg(args, unsigned long int*) = l; 
                                  break;
                               case 4:
                                  /*lint -e{961} , MISRA 17.5 ADV, multiple indirection levels necessary in order to implement support for '%p' */
                                  /*lint -e{511, 923} pointer size depends on both the target and the memory model (if truncation occurs, it is expected) */
                                  /*lint -e{506} , MISRA 13.7 REQ & MISRA 14.1 REQ, default data type formats can be changed with the -T option */
                                  /*lint -e{826} safe conversion */                                
                                  *va_arg(args, char**) = (char*)l;
                                  break;
#if LIBDEF_PRINTF_FAR_PTR
                               case 5:
                                  *va_arg(args, char *FAR *) = (char *FAR) l;
                                  break;
#endif
#if !SAME_SIZE_INT_SHORT
                               case 1:
                                  *va_arg(args, unsigned short int*) = (unsigned short int)l;
                                  break;
#endif
                               default:
                                  /*lint -e{506} , MISRA 13.7 REQ & MISRA 14.1 REQ, default data type formats can be changed with the -T option */
                                  /*lint -e{826} safe conversion */
                                  *va_arg(args, unsigned int*) = (unsigned int)l;
                            }
#if LIBDEF_PRINTF_FAR_PTR
                         }
#endif
                        tasg++;
                      }
                      s = nsp;
                      }
                      break;
#if LIBDEF_PRINTF_FLOATING
            case 'e':
            case 'f':
            case 'g':
                    {
                      double d = _strtod(s, &nsp, (unsigned int)fwi);
                      if (nsp == s) {
                        goto endScan; /* conversion failure */ /*lint !e801 Use of goto is not deprecated */
                      }
                      if (ma)
                      {
#if LIBDEF_PRINTF_FAR_PTR
                         if (is_far_ptr)
                         {
#if SAME_ENCODING_DOUBLE_FLOAT
                            *va_arg(args, double *FAR) = d;
#else
                            if (sz >= 2) {
                               *va_arg(args, double *FAR) = d;
                            } else {
                               *va_arg(args, float *FAR) = d;
                            }
#endif
                         } else {
#endif
#if SAME_ENCODING_DOUBLE_FLOAT
                            /*lint -e{506} , MISRA 13.7 REQ & MISRA 14.1 REQ, default data type formats can be changed with the -T option */
                            /*lint -e{826} , safe conversion */                            
                            *va_arg(args, double*) = d;
#else
                            if (sz >= 2U) {
                               *va_arg(args, double*) = d;         /*lint !e826 safe conversion */
                            } else {
                               *va_arg(args, float*) = (float)d;   /*lint !e826 safe conversion */
                            }
#endif
#if LIBDEF_PRINTF_FAR_PTR
                         }
#endif
                         tasg++;
                       } /* if (ma) */
                       s = nsp;  /*lint !e539 conditionally compiled 'if' clause */
                     }
                     break;
#endif
#if LIBDEF_PRINTF_FAR_PTR
             case 'S':
#endif
             case 's': while (isspace((int)*s)) { ++s; }               /* Eat spaces */
                       if (!fwi) { fwi = INT_MAX; } /* Set field width */
                       if (ma)
                       {
#if LIBDEF_PRINTF_FAR_PTR
                          if ((*format == 'S') || is_far_ptr)
                          {
                             far_ptr = va_arg(args, char *FAR);   /* Set char pointer */
                             while (!(isspace(*s)) && (fwi-- != 0) &&
                                    (*s != '\0'))                 /* Transfer array */
                             {
                                *far_ptr++ = *s++;
                             }
                             *far_ptr = '\0';                     /* Terminate array */
                          } else {
#endif
                             /*lint -e{506} , MISRA 13.7 REQ & MISRA 14.1 REQ, default data type formats can be changed with the -T option */
                             ss = va_arg(args, char*);   /* Set char pointer */
                             while (!(isspace((int)*s)) && (fwi != 0) &&
                                    (*s != (char)'\0'))        /* Transfer array */
                             {
                                *ss = *s;
                                ss++;
                                s++;
                                fwi--;
                             }
                             fwi--;
                             *ss = (char)'\0';                 /* Terminate array */
#if LIBDEF_PRINTF_FAR_PTR
                          }
#endif
                          while (!isspace((int)*s) && (*s != (char)'\0')) {
                             s++;
                          }
                          tasg++;
                       } else {
                          while (!(isspace((int)*s)) && (*s != (char)'\0')) {
                            s++;  /* Skip array */
                          }
                       }
                       break;

             case '%':
                       if (*s == (char)'%') {
                         s++; /* tasg++; */ /* eat '%', do not assign */
                       }
                       break;

             case 'c': if (!fwi) { fwi = 1; } /* Set field width */
                       if (ma)
                       {
#if LIBDEF_PRINTF_FAR_PTR
                          if (is_far_ptr)
                          {
                             far_ptr = va_arg(args, char *FAR);   /* Set char pointer */
                             while (*s && fwi--)              /* Transfer array */
                             {
                                *far_ptr++ = *s++;
                             }
                          } else {
#endif
                             /*lint -e{506} , MISRA 13.7 REQ & MISRA 14.1 REQ, default data type formats can be changed with the -T option */
                             ss = va_arg(args, char*);   /* Set char pointer */
                             while (*s && fwi)           /* Transfer array */
                             {
                                 *ss = *s;
                                 ss++;
                                 s++;
                                 fwi--;
                             }
                             fwi--;
#if LIBDEF_PRINTF_FAR_PTR
                          }
#endif
                         tasg++;
                       } else {
                          while (*s && fwi) { s++; fwi--;} /* Skip array */
                          fwi--;
                       }
                       break;

#if LIBDEF_PRINTF_FAR_PTR
             case 'N':
#endif
             case 'n': if (ma)
                       {
                          nConversion= (unsigned char)TRUE;
#if LIBDEF_PRINTF_FAR_PTR
                          if ((*format == 'N') || is_far_ptr)
                          {
                             switch(sz)
                             {
                                case 1:  *va_arg(args, long int *FAR) = s - sbase;
                                         break;
                                case 2:  *va_arg(args, short int *FAR) = s - sbase;
                                         break;
                                default: *va_arg(args, int *FAR) = s - sbase;
                             }
                          } else {
#endif 
                             {   
                                int tmp = s - sbase; /*lint !e946 !e947 , MISRA 17.2 REQ & MISRA 17.3 REQ, the two pointers point into the same array object */
                                switch(sz)
                                {
                                   case 1:  
                                    /*lint -e{506} , MISRA 13.7 REQ & MISRA 14.1 REQ, default data type formats can be changed with the -T option */
                                    /*lint -e{826} safe conversion */                                    
                                    *va_arg(args, long int*) = tmp;
                                    break;
                                   case 2:  
                                    /*lint -e{506} , MISRA 13.7 REQ & MISRA 14.1 REQ, default data type formats can be changed with the -T option */
                                    /*lint -e{826} safe conversion */                                    
                                    *va_arg(args, short int*) = (short int)tmp;
                                    break;
                                   default: 
                                    /*lint -e{506} , MISRA 13.7 REQ & MISRA 14.1 REQ, default data type formats can be changed with the -T option */
                                    /*lint -e{826} safe conversion */                                    
                                    *va_arg(args, int*) = tmp;
                                }
                             }
#if LIBDEF_PRINTF_FAR_PTR
                          }
#endif
                       }

                       break;
#if LIBDEF_MULTI_CHAR_SELECTION
                 case '[':
                       if (ma)
                       {
#if LIBDEF_PRINTF_FAR_PTR
                          if (is_far_ptr) {
                             far_ptr = va_arg(args, char *FAR);   /* Set char pointer */
                          } else {
#endif
                             /*lint -e{506} , MISRA 13.7 REQ & MISRA 14.1 REQ, default data type formats can be changed with the -T option */
                             ss = va_arg(args, char*);            /* Set char pointer */
#if LIBDEF_PRINTF_FAR_PTR
                          }
#endif
                       }
                       if (!fwi) {
                          fwi = INT_MAX;     /* Set field width */
                       }
#if LIBDEF_PRINTF_FAR_PTR
                       if (is_far_ptr) {
                          format = _copyFarList(far_ptr, s, &nsp, format, &ok, fwi, ma);
                       } else {
#endif                    
                          /*lint -e{929} , MISRA 11.4 ADV, conversion is safe */
                          format = _copyList(ss, s, (LIBDEF_ConstStringPtr *)&nsp, format, &ok, fwi, (int)ma); /*lint !e539 conditionally compiled 'if' clause */
#if LIBDEF_PRINTF_FAR_PTR
                       }
#endif
                       s = nsp;
                       if (ma) {
                          tasg += ok;
                       }
                       break;
#endif /* LIBDEF_MULTI_CHAR_SELECTION */
             default: break;
         }
         format++;
      }  /* end if */
   }  /* end while */

endScan:
   return tasg;

inputFailure:
   if (!tasg && !nConversion) { return EOF; }
   return tasg;
} /* end vsscanf */ /*lint !e818 , MISRA 16.7 ADV, standard library function, cannot change its prototype */


/*****************************************************/

int sscanf(LIBDEF_ConstStringPtr s, LIBDEF_ConstStringPtr format, ...) /*lint !e960 MISRA 16.1 REQ, standard library function implementation */
{
   int i;
   va_list args;
   /*lint -e{643} misleading warning ('&format' does not have a far pointer type) */  
   /*lint -e{928} , MISRA 11.4 ADV, safe conversion to 'char *' */
   va_start(args, format);
   i = vsscanf(s, format, args);
   va_end(args);
   return i;   /*lint !e438 'va_end' must be invoked before return in a variadic function */
} /* end sscanf */

/*****************************************************/
