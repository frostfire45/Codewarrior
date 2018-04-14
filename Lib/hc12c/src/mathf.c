/*****************************************************
   mathf.c - Float library: mathematical functions
 ----------------------------------------------------
   Copyright (c) Metrowerks, Basel, Switzerland
               All rights reserved
                  Do not modify!
 *****************************************************/
/*
 * Copyright (c) 1985 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted provided
 * that: (1) source distributions retain this entire copyright notice and
 * comment, and (2) distributions including binaries display the following
 * acknowledgement:  ``This product includes software developed by the
 * University of California, Berkeley and its contributors'' in the
 * documentation or other materials provided with the distribution and in
 * all advertising materials mentioning features or use of this software.
 * Neither the name of the University nor the names of its contributors may
 * be used to endorse or promote products derived from this software without
 * specific prior written permission.
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 */
/*************************************************************************
 Copyright (c) Metrowerks, Basel, Switzerland
               All rights reserved
                           
Version: Single Precsion 1.1;
Date:    7.8.1992
Updates: 12.7.1995   Handling domain error in atan2f.
************************************************************************/

#include <hidef.h>
#include <math.h>

#if (defined(__FLOAT_IS_IEEE32__) && defined(__DOUBLE_IS_IEEE32__)) || (defined(__FLOAT_IS_IEEE64__) && defined(__DOUBLE_IS_IEEE64__)) || (defined(__FLOAT_IS_DSP__) && defined(__DOUBLE_IS_DSP__))
  #define SAME_ENCODING_DOUBLE_FLOAT 1
#else
  #define SAME_ENCODING_DOUBLE_FLOAT 0
#endif

#if SAME_ENCODING_DOUBLE_FLOAT

float fabsf(float x) {
  return (float)fabs((double)x);
}

float powf_i(float x, long int y) {
  return (float)pow_i((double)x,(int)y);
}

float expf_r(float x) {
  return (float)exp_r((double)x);
}

float expf(float x) {
  return (float)exp((double)x);
}

float logf_r(float x) {
  return (float)log_r((double)x);
}

float logf(float x) {
  return (float)log((double)x);
}

float log10f(float x) {
  return (float)log10((double)x);
}

float powf(float x, float y) {
  return (float)pow((double)x,(double)y);
}

float sincosf(float x, int sgn, int flg) {
  return (float)sincos((double)x, sgn, flg);
}

float tanf(float x) {
  return (float)tan((double)x);
}

float sinf(float x) {
  return (float)sin((double)x);
}

float cosf(float x) {
  return (float)cos((double)x);
}

float sqrtf_r(float x) {
  return (float)sqrt_r((double)x);
}

float sqrtf(float x) {
  return (float)sqrt((double)x);
}

float atan2f(float y,float x) {
  return (float)atan2((double)y,(double)x);
}

float asinf(float x) {
  return (float)asin((double)x);
}

float acosf(float x) {
  return (float)acos((double)x);
}

float atanf(float x) {
  return (float)atan((double)x);
}

float sncshf(float y, int flg) {
  return (float)sncsh((double)y, flg);
}

float sinhf(float x) {
  return (float)sinh((double)x);
}

float coshf(float x) {
  return (float)cosh((double)x);
}

float tanhf(float x) {
  return (float)tanh((double)x);
}

float ceilf (float x) {
  return (float)ceil((double)x);
}

float floorf (float x) {
  return (float)floor((double)x);
}

float fmodf(float x, float y) {
  return (float)fmod((double)x,(double)y);
}

#else /* SAME_ENCODING_DOUBLE_FLOAT */

#include <errno.h>

/* values returned by is_special() */
#if 0 /* the 'symbolic way */
  typedef enum {
    is_special_none = 0,
    is_special_nan = 1,
    is_special_inf = 2,
    is_special_minf = 3
  } is_special_return;
#else /* the (code/speed) efficient way */
  typedef unsigned char is_special_return;
  #define is_special_none (unsigned char)0
  #define is_special_nan  (unsigned char)1
  #define is_special_inf  (unsigned char)2
  #define is_special_minf (unsigned char)3
#endif

#ifdef __HIWARE__
#ifdef __HC12__
#pragma MESSAGE DISABLE  C12056 /* WARNING C12056: SP debug info incorrect because of optimization or inline assembler */
#endif
#pragma MESSAGE DISABLE C2705 /*  Possible loss of data */
#endif

#ifdef __FLOAT_IS_DSP__
  #define SINGLE_NAN   0.0F
  #define SINGLE_INF   0.9999695E+9863F;
#else
  const intfloat infinityf={0x7f800000UL};      /*lint !e708 initialization applied to the first named member of the union */
  const intfloat nan_unionf = {0x7fc00000UL};   /*lint !e708 initialization applied to the first named member of the union */

  #define SINGLE_NAN   nan_unionf.f
  #define SINGLE_INF   infinityf.f
#endif

static float copysignf(float x, float y) {
#ifdef __FLOAT_IS_IEEE32__
  intfloat ix,iy;

  ix.f = x;
  iy.f = y;
  ix.i = (iy.i & 0x80000000UL) | (ix.i & 0x7fffffffUL);
  return ix.f; 
#else
  if (y < 0.0F) {
    if (x >= 0) {
      x = -x;
    }
  } else {
    if (x < 0) {
      x = -x;
    }
  }
  return x;
#endif
}

static int logbf(float x) {
  int Exp;
       
  (void)frexpf(x,&Exp);
  return Exp;
}

/************************************************************/
#ifdef fabsf
  #undef fabsf /* inline version is used in math.h */
#endif
float fabsf(float x) {
#ifdef __FLOAT_IS_IEEE32__
  intfloat ix;

  ix.f=x;
  ix.i &= 0x7fffffffUL;
  return ix.f;
#else
  if( x < 0.0f) {
    return -x;
  }
  return x;
#endif
}
/**************************************************************/
static int isint(float x,long int *iy) {
  float y;
  
  (void)modff(x, &y);
  if(x==y) {          /*lint !e777 the purpose of the test is to compare the bit patterns for an exact match */
    *iy=(long int)y;
    return(1);
  }
  return 0;
}

static is_special_return is_special(float x) {
#ifdef __FLOAT_IS_IEEE32__
  intfloat ugly;
  
  ugly.f=x;
  if(ugly.i == 0xff800000) {
    return is_special_minf;
  } else if(ugly.i == 0x7f800000UL) {
    return is_special_inf;
  } else if((ugly.i & 0x7f800000UL)==0x7f800000UL){
    return is_special_nan;
  } else { /* do nothing */
  }
  return (is_special_return)0;
#else
  return (is_special_return)0;
#endif
}


/***************************************************************/
/* Method:
 *        Right to left binary method 
 *        
 * Complexity: Approx: log2(y) multiplications   
 */

float powf_i(float x, long y) {
  
   float z,r;
  
   if(y < 0) {
    x=1.0F/x;
    y=-y;
   }
   z=x;r=1.0F;
   switch(y) {
     case 0:return 1.0F;
     case 1:return x;
     case 2:return x*x;
     case 3:return x*x*x;
     default: break;
   }
   while( y > 0)
   {
      if( (unsigned long)y & 1UL) {
         r*=z;
      }
      y>>=1; /*lint !e704 !e960 y is positive */
      if(y != 0) {
         z*=z;
      }
   }
   return r;
}
   

/*******************************************************/
#define    ln2hi   6.9314718036912381649E-1F
#define    ln2lo    1.9082149292705877000E-10F
#define   invln2    1.4426950408889633870E0F
#define       p1    1.6666666666666601904E-1F
#define       p2    -2.7777777777015593384E-3F
#define       p3    6.6137563214379343612E-5F
#define       p4    -1.6533902205465251539E-6F
#define       p5    4.1381367970572384604E-8F
/* Method:
 *      1. Argument Reduction: given the input x, find r and integer k such 
 *         that
 *                         x = k*ln2 + r,  |r| <= 0.5*ln2 .  
 *         r will be represented as r := z+c for better accuracy.
 *
 *      2. Compute exp(r)
 *
 *              exp(r) = 1 + r + r*R1/(2-R1),
 *         where
 *              R1 = x - x^2*(p1+x^2*(p2+x^2*(p3+x^2*(p4+p5*x^2)))).
 *
 *      3. exp(x) = 2^k * exp(r) .
 */

float expf_r(float x)
{
  float  z,hi,lo,c;
  int k;
  
  if (x >= _M_EXP_MAX) {
    errno = ERANGE; return SINGLE_INF;
  }
  if (fabsf(x) < 2.220446049e-16F) {
    return 1.0F;
  }
  if( x >=  -7.5137154372698068983E2F ) {
    /* argument reduction : x --> x - k*ln2 */
        float tmp = (invln2*x)+copysignf(0.5F,x);      /* k=NINT(x/ln2) */
        k=(int)tmp;
    /* express x-k*ln2 as hi-lo and let x=hi-lo rounded */
        hi=(float)(x-((double)k*ln2hi));
        x=hi-(lo=(float)((double)k*ln2lo));
    /* return 2^k*[1+x+x*c/(2+c)]  */
        z=x*x;
        c= x - (z*(p1+(z*(p2+(z*(p3+(z*(p4+(z*p5)))))))));
        return  ldexpf(1.0F+(hi-(lo-((x*c)/(2.0F-c)))),k);
  } else {
    return(ldexpf(1.0F,-5000));
  }
}
                

float expf (float x)
/* Special cases:
 *      exp(INF) is INF, exp(NaN) is NaN;
 *      exp(-INF)=  0;
 *      for finite argument, only exp(0)=1 is exact.
 */

{
  is_special_return rR;
  
  rR=is_special(x);
  if(rR != is_special_none) {
    switch(rR) {
      case is_special_nan:return x;
      case is_special_inf:
          errno = ERANGE;
          return SINGLE_INF;
      case is_special_minf:return 0.0F;
      default: break;
    }
  }
  return expf_r(x);   
}

/******************************************************/
        
float logf_r (float x)
{

  int n;
  float f, znum, zden, z, w, aw, bw, rz2, rz, xn;

  
  f = frexpf(x, &n);
  if (f > _M_S1_2) {
    znum = (f - 1.0F );
    zden = ldexpf(f, -1) + .5F ;
  } 
  else {
    --n;
    znum = f - .5F ;
    zden = ldexpf(znum,-1) + .5F ;
  }
  z = znum/zden;
  w = z * z;
  aw = (((-.789561128874912572767F * w) + 16.383943563021534222F) * w) -
       64.124943423745581147F ;
  bw = ((((w + -35.667977739034646171F) * w) + 312.03222091924532844F) * w) -
       769.49932108494879777F ;
  rz2 = (aw/bw) * w;
  rz = z + (z * rz2);
  xn = (float)n;
  return (((xn * -2.121944400546905827679E-4F) + rz) + (xn * 0.693359375F));
}


float logf (float x)
{
  is_special_return rR;
  
  rR=is_special(x);
  if(rR != is_special_none) {
    switch(rR) {
    case is_special_nan:return x;
    case is_special_inf:
        errno = ERANGE;
        return SINGLE_INF;
    case is_special_minf:
        errno = EDOM;
        return SINGLE_NAN;
    default: break;
    }
  }
  if (x <= 0.0F) {
    if (x < 0.0F) {
      errno = EDOM;
    } else {
      errno = ERANGE;
    }
    return SINGLE_NAN;
  }
  return logf_r(x);      
}


float log10f(float x)
{
  return(4.3429448190325181667E-1F*logf(x)); 
}

/*************************************************************************/
/* Method
 *       exp(y*log(x)); for all legal cases with x > 0.0 
 *       x**y using powf_i for integer y
 */
float powf(float x, float y) {
  long int iy;
  is_special_return rR;
  
  if((y == 0.0F) && (x != 0.0F)) {
    return 1.0F;
  } else if(y == 1.0F) {
    return x;
  } else { /* do nothing */
  }
  rR=is_special(y);
  if(rR!=is_special_none) {
    switch(rR) {
      case is_special_nan: return y;
      case is_special_inf:
        if(fabsf(x) < 1.0F) {
          return 0.0F;
        } else  {
          errno=ERANGE;
          return SINGLE_INF;
        }
      case is_special_minf:
        if(fabsf(x) < 1.0F) {
          errno=ERANGE;
          return SINGLE_INF; 
        } else {
          return 0.0F;
        }
      default: break;
    } /* switch */
  }
  rR=is_special(x);
  if(rR != is_special_none) {
    switch(rR) {
      case is_special_nan: return x;
      case is_special_inf:
        if(y > 0.0F) {
          return x;
        } else {
          return 0.0F;
        }
      case is_special_minf:
          if( isint(y,&iy) ) {
            if((unsigned int)iy & 1U )  /* odd y */ {
              return x;
            } else {
              return -x;
            }
          }
          return SINGLE_NAN;
      default: break;
    } /* switch */
  } else if (x == 0.0F) {
    if (y <= 0.0F) {
      errno = EDOM;
      return SINGLE_INF;
    }
    return x;
  } else if(x < 0.0F) {
    if( !isint(y,&iy)) {
      errno = EDOM;
      return SINGLE_NAN;
    } else {
      if(fabsf(y)<32767.0F) {
        return powf_i(x,iy);
      } else {
        x=expf_r(y*logf_r(-x));
        if((unsigned long)iy & 1UL) { /* if odd */
          return -x;
        }
        return x;
      }
    }   
  } else { /* do nothing */
  }
  if(isint(y,&iy) && (fabsf(y)<32767.0F)) {
    return powf_i(x,iy);
  } 
  return expf_r(y*logf_r(x));
}

/******************************************************************************************/
#define _SIN_HUGE  1 /* sin of more than MAXINT * Pi is not currect,  if set to 0 (old version) */

float sincosf(float x, int sgn, int flg) {
/* Method:
     1. reduce argument on -Pi/2..Pi/2
     2. taylor expansion of sin at x0=0;
 */


#if !_SIN_HUGE
  int n;
#else
  long n;
#endif
  float y, frac, xn, f, t1, rv;

  y = x;
  if (flg) {
    y = (float)(y + _M_PI2);
  }

  frac = modff((float)(y *  _M_1PI), &xn);
#if !_SIN_HUGE
  n = (int)xn;
#else
  n = (long)xn;
#endif  
  if (frac > 0.5F) {
    ++n;
    xn = (float)n;  
  }
#if !_SIN_HUGE
  if ((unsigned int)n & 1U) {
#else
  if ((unsigned long)n & 1UL) {
#endif  
    sgn = !sgn;  
  }
  if (flg)  {
    xn -= 0.5F;
  }
  f = (x - (xn * 3.1416016F))+ (xn * 8.90891020676E-6F); /* correction term for Pi rounding */
  if (fabsf(f) <  _M_EPS) {
    rv = f;
  } else {
    t1 = f*f; 
    /* degree of the polynomial lowered to 10 for single precsion math */
    rv = (((((((((/*((0.27204790957888846175e-14F * t1 - 0.76429178068910467734e-12F) * t1  +
           0.16058936490371589114e-9F) * t1 */ - 0.25052106798274584544e-7F)  * t1) +
           0.27557319210152756119e-5F) * t1) - 0.19841269841201840457e-3F)  * t1) +
           0.83333333333331650314e-2F) * t1) - 0.16666666666666665052F)     * t1;
    rv=(rv*f)+f; 
  }
  if(sgn) {
    return (-rv);
  }
  return (rv);
}

/*****************************************************/
float tanf(float x) {

#if !_SIN_HUGE
  int n;
#else
  long n;
#endif
  is_special_return rR;
  float y, frac, xn, f, xnum, xden, g;
  
  rR=is_special(x);
  if(rR!=is_special_none) {
    switch(rR) {
      case is_special_nan:return x;
      case is_special_inf:return 0.0F;
      case is_special_minf:return 0.0F;
      default: break;
    }     
  }
  y = fabsf(x);
  if (y > 149078413.0F) {
    errno = ERANGE; return SINGLE_INF;
  }
  frac = modff( x * 0.63661977236758134308F, &xn);
#if !_SIN_HUGE
  n = (int)xn;
#else
  n = (long)xn;
#endif  
  if (frac > 0.5F) {
    ++n;   
    xn = (float)n;
  }
  f = (x - (xn * 1.57080078125F)) - (xn * -4.454455103380768678308e-6F);
  if (fabsf(f) < _M_EPS) {
    xnum = f;
    xden = 1.0F;
  } else {
      g = f * f;
      xnum = (((((-0.17861707342254426711e-4F * g) + 0.34248878235890589960e-2F) * g) -
                0.13338350006421960681F)* g * f) + f;
      xden = (((((((0.49819433993786512270e-6F * g) - 0.31181531907010027307e-3F) * g) +
                0.25663832289440112864e-1F)* g) - 0.46671683339755294240F) * g) + 1.0F;
  }
#if !_SIN_HUGE  
  if((unsigned int)n & 1U) {
#else
  if((unsigned long)n & 1UL) {
#endif
      xnum = -xnum;
      return (xden/xnum);
  } else {
    return (xnum/xden);
  }
}

float sinf(float x) {
  int sgn;
  is_special_return rR;
  
  rR=is_special(x);
  if(rR!=is_special_none) {
    switch(rR) {
      case is_special_nan: return x;
      case is_special_inf: return 0.0F;
      case is_special_minf:return 0.0F;
      default: break;
    } /* switch */
  } else if (x == 0.0F) {
    return 0.0F;
  } else { /* do nothing */
  }
  if (x < 0.0F) {
   sgn = 1;
   x = -x;
  } else {
    sgn = 0;
  }
  return (sincosf(x,sgn,0));
}

/*****************************************************/

float cosf(float x) {
  is_special_return rR;

  rR=is_special(x);
  if(rR!=is_special_none) {
    switch(rR) {
      case is_special_nan:return x;
      case is_special_inf:return 0.0F;
      case is_special_minf:return 0.0F;
      default: break;
    }
  }
  else if(x == 0.0F) {
      return 1.0F;
  } else { /* do nothing */
  }
  x = fabsf(x);

  return (sincosf(x,0,1));
}

/*****************************************************/
/* Method:
 *       repetitiv approx. using Heron's method
 */ 
float sqrtf_r(float x)
{
  int n;
  float f, z, y0, y2, y3;

 
  if (x == 0.0F) {   
    return (x);
  }
  f = frexpf(x,&n);
  y0 = .41731F + (.59016F * f);
      
  z = y0 + (f/y0);
  y2 = ldexpf(z,-2) + (f/z);
  y3 = ldexpf(y2 + (f/y2),-1);
  if ((unsigned int)n & 1U) /* exponent is odd */
  {
    y3 = (float)(y3 * _M_S1_2);
    ++n;
  }
  {
    unsigned long tmp = (unsigned long)(long)n >> 1U; /* required for compliance with MISRA 10.3 REQ */   
    n = (int)tmp;
  }
  return (ldexpf(y3,n));
}

float sqrtf(float x) {
  is_special_return rR;

  rR=is_special(x);
  if(rR!=is_special_none) {
    switch(rR) {
      case is_special_nan:return x;
      case is_special_inf:return SINGLE_INF;
      case is_special_minf:
         errno = EDOM;
         return SINGLE_NAN;
      default: break;
    } /* switch */
  } else if (x < 0.0F) {
      errno = EDOM;
      return SINGLE_NAN;
  } else { /* do nothing */
  }
  return sqrtf_r(x);
}
/*************************************************************/
#define athfhi  4.6364760900080611433E-1F
#define athflo  1.9338828231967579916E-19F
#define PIo4    7.8539816339744830676E-1F
#define at1fhi  9.8279372324732906796E-1F
#define at1flo  -3.5540295636764633916E-18F
#define PIo2    1.5707963267948966135E0F
#define PI      3.1415926535897932270E0F
#define a1      0.3333333333333F
#define a2     -0.200000000000F
#define a3      1.4285714286694640301E-1F
#define a4     -1.1111111135032672795E-1F
#define a5      9.0909091380563043783E-2F
#define a6     -7.6922954286089459397E-2F
#define a7      6.6663180891693915586E-2F 
#define a8     -5.8772703698290408927E-2F
#define a9      5.2170707402812969804E-2F
/* not used 
#define a10    -4.4895863157820361210E-2F
#define a11     3.3006147437343875094E-2F
#define a12    -1.4614844866464185439E-2F
*/
/* Method :
 *      1. Reduce y to positive by atan2(y,x)=-atan2(-y,x).
 *      2. Reduce x to positive by (if x and y are unexceptional): 
 *              ARG (x+iy) = arctan(y/x)           ... if x > 0,
 *              ARG (x+iy) = pi - arctan[y/(-x)]   ... if x < 0,
 *      3. According to the integer k=4t+0.25 truncated , t=y/x, the argument 
 *         is further reduced to one of the following intervals and the 
 *         arctangent of y/x is evaluated by the corresponding formula:
 *
 *         [0,7/16]        atan(y/x) = t - t^3*(a1+t^2*(a2+...(a10+t^2*a11)...)
 *         [7/16,11/16]    atan(y/x) = atan(1/2) + atan( (y-x/2)/(x+y/2) )
 *         [11/16.19/16]   atan(y/x) = atan( 1 ) + atan( (y-x)/(x+y) )
 *         [19/16,39/16]   atan(y/x) = atan(3/2) + atan( (y-1.5x)/(x+1.5y) )
 *         [39/16,INF]     atan(y/x) = atan(INF) + atan( -x/y )
 *
 * Special cases:
 * Notations: atan2(y,x) == ARG (x+iy) == ARG(x,y).
*/
float atan2f(float y,float x) {  
  static const float zero=0.0F, one=1.0F, small=1.0E-9F, big=1.0E18F;
  float t,z,signy,signx,hi,lo;
  int k,m;
  is_special_return mR;

  /* copy down the sign of y and x */
  if ((x == zero) && (y == zero)) { /*lint !e777 the purpose of the test is to compare the bit patterns for an exact match */
    errno = EDOM;
    return 0.0F;
  }
  signy = copysignf(one,y) ;  
  signx = copysignf(one,x) ;  
  mR=is_special(x);
  if(mR!=is_special_none) {
    switch(mR) {
      case is_special_nan:return y;
      case is_special_inf:
      case is_special_minf:
        if(is_special(y)!=is_special_none) {
          return(copysignf((signx==one)?PIo4:(3.0F*PIo4),signy)); /*lint !e777 the purpose of the test is to compare the bit patterns for an exact match */
        } else {
          return(copysignf((signx==one)?zero:PI,signy));          /*lint !e777 the purpose of the test is to compare the bit patterns for an exact match */
        }
      default: break;
    }
  }
  mR=is_special(y);
  if (mR!=is_special_none) {
    switch(mR) {
      case is_special_nan:return y;
      case is_special_inf:
      case is_special_minf:return(copysignf(PIo2,signy));
      default: break;
    }
  }  
  /* if x is 1.0 */
  if(x==1.0F) { 
     y=copysignf(y,one); t=y;
  } else {
    /* when y = 0 */
    if(y==zero) {                    /*lint !e777 the purpose of the test is to compare the bit patterns for an exact match */
      if(signx==one) {               /*lint !e777 the purpose of the test is to compare the bit patterns for an exact match */
        return(y);
      } else {
        return(copysignf(PI,signy));
      }
    }
    if(x==zero) {                    /*lint !e777 the purpose of the test is to compare the bit patterns for an exact match */
      return(copysignf(PIo2,signy));
    }
    x=copysignf(x,one);
    y=copysignf(y,one);
    k=logbf(y);
    m=(k)-logbf(x);
    if(m > 60) {
      t=big+big; 
    } else if(m < -80 ) {
      t=y/x;
    } else { 
      t = y/x ; y = ldexpf(y,-k); x=ldexpf(x,-k);
    }
  }
  /* begin argument reduction */
  if (t < 2.4375F) {                
    /* truncate 4(t+1/16) to integer for branching */
    float tmp = 4.0F * (t+0.0625F); /* required for compliance with MISRA 10.4 REQ */
    k = (int)tmp;
    switch (k) {

      /* t is in [0,7/16] */
      case 0:                    
      case 1:
          if (t < small) {
            if(signx>zero) {
              return (copysignf(t,signy)); 
            } else {
              return(copysignf(PI-t,signy));
            }
            /*return (copysignf((signx>zero)?t:PI-t,signy));*/
          }  
          hi = zero;  lo = zero;  break;
          /* t is in [7/16,11/16] */
      case 2:                    
          hi = athfhi; lo = athflo;
          z = x+x;
          t = ( (y+y) - x ) / ( z +  y ); break;

      /* t is in [11/16,19/16] */
      case 3:                    
      case 4:
          hi = PIo4; lo = zero;
          t = ( y - x ) / ( x + y ); break;

      /* t is in [19/16,39/16] */
      default:                   
          hi = at1fhi; lo = at1flo;
          z = y-x; y=y+y+y; t = x+x;
          t = ( (z+z)-x ) / ( t + y ); break;
    } /* switch */
    /* end of if (t < 2.4375) */
  } else {
    hi = PIo2; lo = zero;
    /* t is in [2.4375, big] */
    if (t <= big) {
      t = - x / y;
      /* t is in [big, INF] */
    } else { /* big+small;      raise inexact flag */
      t = zero;
    }
  }
  /* end of argument reduction */

  /* compute atan(t) for t in [-.4375, .4375] */
  z = t*t;
  z = t*(z*(a1+(z*(a2+(z*(a3+(z*(a4+(z*(a5+(z*(a6+(z*(a7+(z*(a8+
                  (z*(a9/*+z*(a10+z*a11)*/))))))))))))))))));
  z = lo - z; z += t; z += hi;
  if(signx > 0.0F) {
     return copysignf(z,signy);
  } else {
     return copysignf(PI-z,signy);
  } 
  /* return(copysignf((signx>zero)?z:PI-z,signy)); */  
  /* return x; */
}

float asinf(float x) {
  is_special_return rR;

  rR=is_special(x);
  if(rR!=is_special_none) {
    switch(rR) {
      case is_special_nan:return x;
      case is_special_inf:{
         errno = EDOM;
         return SINGLE_NAN;
      }
      case is_special_minf:{
         errno = EDOM;
         return SINGLE_NAN;
      }
      default: break;
    }
  }
  if(fabsf(x) > 1.0F) {
    errno = EDOM;
    return SINGLE_NAN;
  }
  return(atan2f(x,sqrtf(1.0F-(x*x))));
}


float acosf(float x) {
  float t;
  is_special_return rR;
  
  rR=is_special(x);
  if(rR!=is_special_none) {
    switch(rR) {
      case is_special_nan:   return x;
      case is_special_inf:
      case is_special_minf:  errno = EDOM; return SINGLE_NAN;
      default: break;
    }
  }
  if(fabsf(x) > 1.0F) {
    errno = EDOM;
    return SINGLE_NAN;
  }
  if( x != -1.0F) {
      t=atan2f(sqrtf((1.0F-x)/(1.0F+x)),1.0F);
  } else {
     /* t=atan2f(1.0F,0.0F);*/ /*  t = PI/2 */ t=PIo2;
  }
  return(t+t);
}

float atanf(float x)
{
 return(atan2f(x,1.0F));
}

/*************************************************************/
float sncshf(float y, int flg)
{

  float w, z;

  if (y > _M_EXP_MAX)
    {
      w = y - 0.69316101074218750000F;
      if (w > _M_EXP_MAX) {         
        errno = ERANGE;
      }
      z = expf(w);
      return (z + (0.13830277879601902638e-4F * z));
    }
  z = expf(y);
  if(flg) {   
    return ((z - (1.0F/z))/2.0F);
  }
  return ((z + (1.0F/z))/2.0F);
}

/*****************************************************/

float sinhf(float x)
{
  is_special_return rR;
  float y, f, pf, qf, rf, sign;

  rR=is_special(x);
  if(rR!=is_special_none) {
     switch(rR) {
       case is_special_nan:return x;
       case is_special_inf:{
         errno = ERANGE;
         return SINGLE_INF;
       }
       case is_special_minf:{
         errno = ERANGE;
         return -SINGLE_INF;
       }
       default: break;
     }
  }
  sign=copysignf(1.0F,x);
  y=copysignf(x,1.0F);
  if (y > 1.0F) {   
    return copysignf(sncshf(y,1),sign);
  }
  if (y < _M_EPS) {   
    return (x);
  }
  f = y * y;
  pf = (((((-0.78966127417357099479F * f) - 0.16375798202630751372e+3F) * f)
        - 0.11563521196851768270e+5F) * f) - 0.35181283430177117881e+6F;

  qf = ((((f - 0.27773523119650701667e+3F) * f)
           + 0.36162723109421836460e+5F) * f)
           - 0.21108770058106271242e+7F;

  rf = f * (pf/qf);

  return (x + (x * rf));
}
/*****************************************************/

float coshf(float x)
{
  is_special_return rR;
  
  rR=is_special(x);
  if(rR!=is_special_none) {
     switch(rR) {
       case is_special_nan:return x;
       case is_special_inf:{
         errno = ERANGE;
         return SINGLE_INF;
       }
       case is_special_minf:{
         errno = ERANGE;
         return SINGLE_INF;
       }
       default: break;
     }
  }
  x=fabsf(x);
  return (sncshf(x,0));
}

/*****************************************************/

float tanhf(float x)
{
  is_special_return rR;
  float f, g, gpg, qg, rg, rv, sign;
  
  rR=is_special(x);
  if(rR!=is_special_none) {
     switch(rR) {
       case is_special_nan:return x;
       case is_special_inf:{
         return 1.0F;
       }
       case is_special_minf:{
         return -1.0F;
       }
       default: break;
     }
  }
  sign=copysignf(1.0F,x);
  f=copysignf(x,1.0F);
  if (f < _M_EPS) {   
    return (x);
  }
  if (f > 19.06154747F) {   
    return copysignf(1.0F,sign);
  }
  if (f > 0.54930614433405484570F)
  {
    rv = 0.5F - (1.0F/(expf(f + f) + 1.0F));
    rv = ldexpf(rv,1);
    return copysignf(rv,sign);
  }

  g = f * f;

  gpg = ((((-0.96437492777225469787F * g)
         - 0.99225929672236083313e+2F) * g)
         - 0.16134119023996228053e+4F) * g;

  qg = ((((g + 0.11274474380534949335e+3F) * g)
           + 0.22337720718962312926e+4F) * g)
           + 0.48402357071988688686e+4F;

  rg = gpg / qg;
  rv = f + (f * rg);
  return copysignf(rv,sign);
}

/***********************************************************************/
float ceilf (float x)
{

  float y;
  
  (void)modff(x, &y);
  if ((x != y) && (x > 0.0F)) { /*lint !e777 the purpose of the test is to compare the bit patterns for an exact match */
    return (y + 1.0F);
  }
  return(y);
}

float floorf(float x)
{

  float y;
  
  (void)modff(x, &y);
  if ((x != y) && (x < 0.0F)) { /*lint !e777 the purpose of the test is to compare the bit patterns for an exact match */  
    return (y - 1.0F);
  }
  return(y);
}


float fmodf(float x, float y)
{ 

  float z;
  
  if (y == 0.0F) {   
    return (0.0F);
  }
  (void) modff (x / y, &z);
  return (x - (z * y));
}
/****************************************************************/
#endif /* SAME_ENCODING_DOUBLE_FLOAT */
/*lint --e{766} hidef.h contains conditionally compiled code */
