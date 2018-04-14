/******************************************************************************
  FILE        : dansi.c
  PURPOSE     : C library floating point ieee64 routines
                modf, frexp, ldexp
  LANGUAGE    : Inline assembler
  ----------------------------------------------------------------------------
  HISTORY
    05 jul 93    Created.
    09/11/95     renaming M -> _M, L -> _L, K -> _K
    04/26/96     Adaption for C++
 ******************************************************************************/

#include "hidef.h"
#include "dregs.h"
/*lint -e451 non_bank.sgm and runtime.sgm are not regular header files, they contain CODE_SEG/push/pop pragmas */
#include "non_bank.sgm"
#include "runtime.sgm"
/*lint +e451 */
#include "errno.h"
#define __NO_MATH_PROTOTYPES__
#include "math.h"

/*lint --e{957} , MISRA 8.1 REQ, these are runtime support functions and, as such, are not meant to be called in user code; they are only invoked via jumps, in compiler-generated code */
/*lint --e{750} , local macros referenced, but in HLI */

/*--------------------------------------------------------------------------
                 General stack layout for IEEE64 operations:

                  | ********** |
               23 | _K_mant(6) |
               22 | _K_mant(5) |
               21 | _K_mant(4) |
               20 | _K_mant(3) |
               19 | _K_mant(2) |
               18 | _K_mant(1) |
               17 | _K_mant(0) |
               16 | _K_sign    |
               15 | _L_mant(6) |
               14 | _L_mant(5) |
               13 | _L_mant(4) |
               12 | _L_mant(3) |
               11 | _L_mant(2) |
               10 | _L_mant(1) |
                9 | _L_mant(0) |
                8 | _L_sign    |
                7 |*ret addr 1*|            1) to backend
                6 |*ret addr 1*|
                5 | _K_exp(1)  |
                4 | _K_exp(0)  |
                3 | _L_exp(1)  |
                2 | _L_exp(0)  |
                1 |*ret addr 2*|            2) to top RT routine
                0 |*ret addr 2*| <--- SP
*/

/*
#define _L(offset)        8+offset,SP
#define _K(offset)        16+offset,SP
*/
#define _L_mant(offset)   9+offset,SP
#define _L_exp(offset)    2+offset,SP
#define _L_sign           8,SP
#define _K_mant(offset)   17+offset,SP
#define _K_exp(offset)    4+offset,SP
#define _K_sign           16,SP

#ifndef __DOUBLE_IS_IEEE32__

#pragma NO_FRAME
#pragma NO_ENTRY
#pragma NO_EXIT

/**
    DESC   Calculate integral and fractional part.
    IN     f64 K;
    WRITE  A, B, X, SR;
           K, L;
    OUT    f64 _K: fractional part.
           f64 _L: integral part.
**/
void D_MODF (void)
{
  asm {
               LDD       _K_exp(0)
               SUBD      #(1018+3)
               BLE       MODF_0      /* there is only a fractional part */
               SUBD      #(56-3)
               BGE       MODF_1      /* there is only an integer part */
               PULX
               __PIC_JSR(D_TKL)
               PSHX
               LEAX      _L_mant(6)
               BRA       MODF_5
    MODF_4:    CLR       0,X
               DEX
    MODF_5:    ADDB      #8
               BLT       MODF_4
    MODF_2:    SUBB      #8
               BEQ       MODF_6
               /* { */
               /*   Some nasty bits get cleared now. */
               /*   To be exact bits[0..n[ in 0,X (n == -B). */
               /* } */
               LDAA      #1
    MODF_3:    LSLA
               INCB
               BNE       MODF_3
               /* { */
               /*   A: contains the bit[n]-number. */
               /*      To mask out bits[0..n[ -> mask == NOT(A-1) */
               /*          == 255-(A-1) == 256-A ! */
               /* } */
               NEGA
               ANDA      0,X
               STAA      0,X

               /* { */
               /*   L contains the integer part. */
               /*   To keep it simple, subtract L from K. */
               /*   (this will not cost this lot, since the exponents */
               /*   are the same) */
               /* } */
    MODF_6:    LDD       _K_mant(5)
               SUBD      _L_mant(5)
               STD       _K_mant(5)
#ifdef __HCS12X__
               LDD       _K_mant(3)
               SBED      _L_mant(3)
               STD       _K_mant(3)
               LDD       _K_mant(1)
               SBED      _L_mant(1)
               STD       _K_mant(1)
#else
               LDD       _K_mant(3)
               SBCB      _L_mant(4)
               SBCA      _L_mant(3)
               STD       _K_mant(3)
               LDD       _K_mant(1)
               SBCB      _L_mant(2)
               SBCA      _L_mant(1)
               STD       _K_mant(1)
#endif
               LDAA      _K_mant(0)
               SBCA      _L_mant(0)
               STAA      _K_mant(0)
               __PIC_JMP(D_NORMK)
    MODF_0:    __PIC_JMP(D_CLRL)
    MODF_1:    PULX
               __PIC_JSR(D_TKL)
               PSHX
               __PIC_JMP(D_CLRK)
  }
}

/*--------------------------------------------------------------------------*/

#pragma NO_FRAME
#pragma NO_ENTRY
#pragma NO_EXIT

/**
    DESC   Separate mantissa and exponent.
    IN     f64 K;
    WRITE  A, B, X, SR;
           K, L;
    OUT    f64 _K: mantissa part.
           _L:exp  exponent.
           val == K * 2^(_K:exp), (where 0.5 < abs(K) <= 1.0)
**/
void D_FREXP (void)
{
  asm {
               LDD       _K_exp(0)
               BEQ       FREXP_0    /* number zero or very small! */

    FREXP_1:   SUBD      #(1018+3)
               STD       _L_exp(0)
               LDD       #(1018+3)
               STD       _K_exp(0)
               RTS

    FREXP_0:   LDD       #53
               STD       _K_exp(0)
               PULD
               __PIC_JSR(D_NORMK)   /* D not destroyed by D_NORMK */
               PSHD
               LDD       _K_exp(0)
               BNE       FREXP_1    /* number not zero */

               STD       _L_exp(0)
               RTS
  }
}

/*--------------------------------------------------------------------------*/

#pragma NO_FRAME
#pragma NO_ENTRY
#pragma NO_EXIT

/**
    DESC   Combines number and exponent.
    IN     f64 K;
           _L:exp (exponent).
    WRITE  A, B, X, SR;
           K, L;
    OUT    f64 K == K * 2^(_L:exp), (where 0.5 < abs(K) <= 1.0)
**/
/*lint -esym(528, D_LDEXP) , symbol 'D_LDEXP' is referenced in HLI */
static void D_LDEXP (void)
{
  asm {
               LDD       _K_exp(0)
               ADDD      _L_exp(0)
               BVS       ErrDomainRet     /* overflow */
               BPL       InRange        /* MTWX25778 need to return 0 in case of underflow */
               CLRA
               CLRB
InRange:       CPD       #2048
               BGE       ErrDomain     /* overflow */
               STD       _K_exp(0)
               RTS
Underflow:     CLR       _K_exp(0)
               RTS                  
ErrDomain:     SEV                      /* set overflow bit */
ErrDomainRet:  RTS
  }
}

#endif
/*--------------------------------------------------------------------------*/

#ifdef __DOUBLE_IS_IEEE32__

#ifdef __cplusplus
extern "C"
#endif
#ifdef __LARGE__
/*lint -esym(752, _modff) , symbol '_modff' is used in HLI */
extern void _modff(void); /* _modff takes the second parameter as near pointer, and not as unqualified pointer */
#else
/*lint -esym(752, modff) , symbol 'modff' is used in HLI */
extern void modff(void);  /*lint !e752 , symbol 'modff' is referenced in HLI code */
#endif

#ifdef __cplusplus
extern "C"
#endif
/*lint -esym(752, frexpf) , symbol 'frexpf' is used in HLI */
extern void frexpf (void);

#ifdef __cplusplus
extern "C"
#endif
/*lint -esym(752, ldexpf) , symbol 'ldexpf' is used in HLI */
extern void ldexpf (void);

#ifdef __cplusplus
extern "C"
#endif

#pragma NO_EXIT
#pragma NO_FRAME
#pragma NO_ENTRY
#ifdef __LARGE__
void _modf(void) {	 /* _modf takes the second parameter as near pointer, and not as unqualified pointer */
  asm {
    __PIC_JMP(_modff)
  }
}
#else
void modf(void) {
  asm {
    __PIC_JMP(modff)
  }
}
#endif

#ifdef __cplusplus
extern "C"
#endif

#pragma NO_EXIT
#pragma NO_FRAME
#pragma NO_ENTRY
void frexp(void) { /* double frexp (double x, int *i) */
  asm {
    __PIC_JMP(frexpf)
  }
}

#ifdef __cplusplus
extern "C"
#endif

#pragma NO_EXIT
#pragma NO_FRAME
#pragma NO_ENTRY
void ldexp(void)  {
  asm {
    __PIC_JMP(ldexpf)
  }
}

#else /* __DOUBLE_IS_IEEE32__ */

/*--------------------------------------------------------------------------*/

/**
    DESC   Calculate integral and fractional part of an ieee64 number.
    IN     stack : <ieee64 x; address of result>
           D ieee64 *i,
    WRITE  A, B, X, Y, SR;
           K, L;
    OUT    *address of result : <ieee64 (fraction part)>
           *i:     <ieee64 (integral part)>
**/
/* double modf (double x, double *i) */
#ifdef __cplusplus
extern "C"
#endif

#pragma NO_EXIT
#pragma NO_FRAME
#pragma NO_ENTRY

#ifdef __LARGE__
void _modf(void)
#else
void modf(void)
#endif
 {
  asm {
               LDY       8,SP-                /* move return address like dregs.c stack layout */
               STY       4,SP-
               TFR       D,Y                  /* i to Y */
               __PIC_JSR(D_PULK)
               __PIC_JSR(D_MODF)
               __PIC_JSR(D_STAL)              /* store _L to *i */
               LDY       4,SP                 /* move back return address */
               STY       12,SP
               LDY       2,SP                 /* move _K_exp to _L_exp for D_STA */
               STY       8,+SP
               LDY       14,SP                /* address of result to Y */
               __PIC_JSR(D_STAL)              /* store _K to *address of result */
               LEAS      4,SP                 /* remove space for exponents */
               RTS
  }
}

/*--------------------------------------------------------------------------*/

/**
    DESC   Split a ieee64 into exponent and mantissa.
    IN     stack : <ieee64 x; address of result>
           D:    <int *i>
    WRITE  A, B, X, Y, SR;
           K, L;
    OUT    *address of result <ieee64 (mant part)>
           *i contains exponent.
           assert (val == 2^(*i) * mant  &&  0.5 < abs(mant) <= 1.0)
**/

#ifdef __cplusplus
extern "C"
#endif

#pragma NO_EXIT
#pragma NO_FRAME
#pragma NO_ENTRY

#ifdef __LARGE__
void _frexp(void)
#else
void frexp(void)
#endif
{ /* double frexp (double x, int *i) */
  asm {
               LDY       8,SP-                /* move return address like dregs.c stack layout */
               STY       4,SP-
               TFR       D,Y                  /* i to Y */
               __PIC_JSR(D_PULK)
               __PIC_JSR(D_FREXP)
               LDD       _L_exp((0-2))        /* MISRA: compliance requires 2 pairs of parenthesis (unparenthesized macro parameter is passed an expression) */
               STD       0,Y                  /* _L_exp to *i */
               LDY       4,SP                 /* move back return address */
               STY       12,SP
               LDY       2,SP                 /* move _K_exp to _L_exp for D_STA */
               STY       8,+SP
               LDY       14,SP                /* address of result to Y */
               __PIC_JSR(D_STAL)              /* store _K to *address of result */
               LEAS      4,SP                 /* remove space for exponents */
               RTS
  }
}

/*--------------------------------------------------------------------------*/
/* auxiliary function for error domain error case of ldexp */
 /*lint -esym(528, RetErrDom) , symbol 'RetErrDom' is referenced in HLI */
static void near RetErrDom(double* __near ret) {
  errno= EDOM;
  *ret= HUGE_VAL;
}
/*--------------------------------------------------------------------------*/

/**
    DESC   Returns x * 2^i.
    IN     stack : <ieee64 x; address of result>
           D: <int:2 i>
    WRITE  A, B, X, Y, SR;
           K, L;
    OUT    *address of result: (val == x * 2^i)
**/
#ifdef __cplusplus
extern "C"
#endif

#pragma NO_EXIT
#pragma NO_FRAME
#pragma NO_ENTRY
#if defined(__LARGE__) && defined(__DOUBLE_IS_IEEE64__)
void _ldexp(void)/* (double x, int exp) */
#else
void ldexp(void)/* (double x, int exp) */
#endif
{
  asm {
               LDY       8,SP-                /* move return address like dregs.c stack layout */
               STY       4,SP-
               TFR       D,Y                  /* i to Y */
               __PIC_JSR(D_PULK)
               STY       _L_exp((0-2))        /* MISRA: compliance requires 2 pairs of parenthesis (unparenthesized macro parameter is passed an expression) */
               __PIC_JSR(D_LDEXP)
               BVS       OverFlow
               LDY       4,SP                 /* move back return address */
               STY       12,SP
               LDY       2,SP                 /* move _K_exp to _L_exp for D_STA */
               STY       8,+SP
               LDY       14,SP                /* address of result to Y */
               __PIC_JSR(D_STAL)              /* store _K to *address of result */
               LEAS      4,SP                 /* remove space for exponents */
               RTS
OverFlow:
               LEAS      12,SP
               LDD       10,SP
               __PIC_JMP(RetErrDom)
  }
}

/*--------------------------------------------------------------------------*/

#endif /* __DOUBLE_IS_IEEE32__ */

/*lint --e{766} , header file 'dregs.h' is used, but in HLI code */
