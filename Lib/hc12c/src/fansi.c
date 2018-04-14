/******************************************************************************
  FILE        : fansi.c
  PURPOSE     : C library floating point routines
                modff, frexpf, ldexpf
  LANGUAGE    : Inline assembler
  ----------------------------------------------------------------------------
  HISTORY
    05 jul 93    Created.
    09/11/95     renaming M -> _M, L -> _L, K -> _K
    04/26/96     Adaption for C++
 ******************************************************************************/

#include "hidef.h"
#include "fregs.h"

/*lint -e451 non_bank.sgm and runtime.sgm are not regular header files, they contain CODE_SEG/push/pop pragmas */
#include "non_bank.sgm"
#include "runtime.sgm"
/*lint +e451 */
#include "errno.h"
#define __NO_MATH_PROTOTYPES__
#include "math.h"

/*lint --e{957} , MISRA 8.1 REQ, these are runtime support functions and, as such, are not meant to be called in user code; they are only invoked via jumps, in compiler-generated code */

/*--------------------------------------------------------------------------
                 General stack layout for IEEE32 operations:

                  | ********** |
               15 | _L_mant(2) |
               14 | _L_mant(1) |
               13 | _L_mant(0) |
               12 | _L_sign    |
               11 |*ret addr 1*|            1) to backend
               10 |*ret addr 1*|
                9 | _L_exp(1)  |
                8 | _L_exp(0)  |
                7 | _K_mant(2) |
                6 | _K_mant(1) |
                5 | _K_mant(0) |
                4 | _K_sign    |
                3 | _K_exp(1)  |
                2 | _K_exp(0)  |
                1 |*ret addr 2*|            2) to top RT routine
                0 |*ret addr 2*| <--- SP
*/

/*
#define _K(offset)        4 + (offset), SP
#define _L(offset)       12 + (offset), SP
*/
#define _K_mant(offset)   5 + (offset), SP
#define _K_exp(offset)    2 + (offset), SP
/*
#define _K_sign          4, SP
*/
#define _L_mant(offset)  13 + (offset), SP
#define _L_exp(offset)    8 + (offset), SP
/*
#define _L_sign          12, SP
*/
#pragma NO_FRAME
#pragma NO_ENTRY
#pragma NO_EXIT

/**
    DESC   Calculate integral and fractional part.
    IN     f32 K;
    WRITE  A, B, X, SR;
           K, L;
    OUT    f32 _K: fractional part.
           f32 _L: integral part.
**/
void F_MODF (void)
{
  asm {
               LDD       _K_exp(0)
               SUBD      #125
               BLE       MODF_0      /* there is only a fractional part */
               SUBD      #24
               BGT       MODF_1      /* there is only an integer part */
               /*;__PIC_JSR(F_TKL)*/
               LEAX      _L_mant(2)
               BRA       MODF_5
    MODF_4:    CLR       1,X-				 /* CLR 0,X ; DEC X */
    MODF_5:    ADDB      #8
               BMI       MODF_4

    MODF_2:    SUBB      #8
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
               LDD       _K_mant(1)
               SUBD      _L_mant(1)
               STD       _K_mant(1)
               LDAA      _K_mant(0)
               SBCA      _L_mant(0)
               STAA      _K_mant(0)
               __PIC_JMP(F_NORMK)

    MODF_0:    __PIC_JMP(F_CLRL)

    MODF_1:    /*;__PIC_JSR(F_TKL) */
               __PIC_JMP(F_CLRK)
  }
}

/*--------------------------------------------------------------------------*/

#pragma NO_FRAME
#pragma NO_ENTRY
#pragma NO_EXIT

/**
    DESC   Separate mantissa and exponent.
    IN     f32 K;
    WRITE  A, B, X, SR;
           K, L;
    OUT    f32 _K: mantissa part.
           _L:exp  exponent.
           val == K * 2^(_K:exp), (where 0.5 < abs(K) <= 1.0)
**/
void F_FREXP (void)
{
  asm {
               LDD       _K_exp(0)
               BEQ       FREXP_0      /* number zero or very small! */

    FREXP_1:   SUBD      #125
               STD       _L_exp(0)
               LDD       #125
               STD       _K_exp(0)
               RTS

    FREXP_0:   LDAB      #24          /* A is already 0. Same as "LDD #24" */
               STD       _K_exp(0)
               PULD
               __PIC_JSR(F_NORMK)     /* D not touched */
               PSHD
               LDD       _K_exp(0)
               BNE       FREXP_1      /* number not zero */

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
    IN     f32 K;
           _L_exp  : (exponent).
    WRITE  A, B, SR;
           K;
    OUT    f32 K == K * 2^(_L:exp), (where 0.5 < abs(K) <= 1.0)
**/
void F_LDEXP (void)
{
  asm {
               LDD       _K_exp(0)
               ADDD      _L_exp(0)
               BVS       ErrDomainRet     /* overflow */
               BPL       InRange        /* MTWX25778 need to return 0 in case of underflow */
               CLRA
               CLRB
InRange:       CPD       #256
               BGE       ErrDomain     /* overflow */
               STD       _K_exp(0)
               RTS
               
ErrDomain:     SEV                      /* set overflow bit */
ErrDomainRet:  RTS
  }
}



/*--------------------------------------------------------------------------*/

/**
    DESC   Calculate integral and fractional part of an ieee32 number.
    IN     stack <ieee32 x>
           D ieee32 *i,
    WRITE  A, B, X, Y, SR;
           K, L;
    OUT    X:D  : <ieee32 (fraction part)>
           *i   : <ieee32 (integral part)>
**/
#ifdef __cplusplus
extern "C"
#endif

#pragma NO_FRAME
#pragma NO_ENTRY
#pragma NO_EXIT

#ifdef __LARGE__
void _modff(void)
#else
void modff(void)
#endif
{
  asm {
               TFR       D,Y                  /* *i to Y */
               LEAS      -8,SP                /* space for _L_exp and _K */
               __PIC_JSR(F_PULL)
               __PIC_JSR(F_TLK)               /* copy _L to _K */
               __PIC_JSR(F_MODF)
               __PIC_JSR(F_STAL)              /* store _L to *i */
               __PIC_JSR(F_PSHK)
               PULX
               PULX                           /* _K to X:D */
               PULD
               LEAS      2,SP
               RTS
  }
}

/*--------------------------------------------------------------------------*/

/**
    DESC   Split a ieee32 into exponent and mantissa.
    IN     stack <ieee32 x>
           D:    <int *i>
    WRITE  A, B, X, Y, SR;
           K, L;
    OUT    X:D  : <ieee32 (mant part)>
           *i contains exponent.
           assert (val == 2^(*i) * mant  &&  0.5 < abs(mant) <= 1.0)
**/
/* float frexpf (float x, int *i) */
#ifdef __cplusplus
extern "C"
#endif

#pragma NO_FRAME
#pragma NO_ENTRY
#pragma NO_EXIT
#ifdef __LARGE__
void _frexpf(void)
#else
void frexpf(void)
#endif
{
  asm {
               TFR       D,Y                  /* *i to Y */
               LEAS      -8,SP                /* space for _L_exp and _K */
               __PIC_JSR(F_PULL)
               __PIC_JSR(F_TLK)                /* copy _L to _K */
               __PIC_JSR(F_FREXP)
               LDD       _L_exp(0-2)
               STD       0,Y                  /* _L_exp to *i */
               __PIC_JSR(F_PSHK)
               PULX
               PULX                           /* _K to X:D */
               PULD
               LEAS      2,SP
               RTS
  }
}
/*--------------------------------------------------------------------------*/
/* auxiliary function for error domain error case of ldexp */
/*lint -esym(528, RetErrDom) function RetErrDom is referenced in HLI */
static float near RetErrDom(void) {
  errno= EDOM;
  return (float)HUGE_VAL;
}
/*--------------------------------------------------------------------------*/


/**
    DESC   Returns x * 2^i.
    IN     stack <ieee32 x>
           D: <int:2 i>
    WRITE  A, B, X, Y, SR;
           K, L;
    OUT    X:D  : (val == x * 2^i)
**/
/* float ldexpf (float x, int i) */
#ifdef __cplusplus
extern "C"
#endif

#pragma NO_FRAME
#pragma NO_ENTRY
#pragma NO_EXIT

void ldexpf(void) {
  asm {
               TFR       D,Y
               LEAS      -8,SP                /* space for _L_exp and _K */
               __PIC_JSR(F_PULL)
               __PIC_JSR(F_TLK)                /* copy _L to _K */
               STY       _L_exp(0-2)
               __PIC_JSR(F_LDEXP)
               BVS       OverFlow
               __PIC_JSR(F_PSHK)
               PULX
               PULX                           /* _K to X:D */
               PULD
               LEAS      2,SP
               RTS
OverFlow:      LEAS      8,SP ; release stack
               __PIC_JMP(RetErrDom)
  }
}

/*--------------------------------------------------------------------------*/

/*lint --e{766} , header file 'fregs.h' are used, but in HLI code */
