/******************************************************************************
  FILE        : fconv.c
  PURPOSE     : Run time ieee32 conversions.
  LANGUAGE    : Inline assembler
  ----------------------------------------------------------------------------
  HISTORY
    29 jun 93    Created.
    09/11/95     renaming M -> _M, L -> _L, K -> _K
 ******************************************************************************/

#include "hidef.h"
#include "fregs.h"
/*lint -e451 non_bank.sgm and runtime.sgm are not regular header files, they contain CODE_SEG/push/pop pragmas */
#include "non_bank.sgm"
#include "runtime.sgm"
/*lint +e451 */

/*lint --e{957} , MISRA 8.1 REQ, these are runtime support functions and, as such, are not meant to be called in user code; they are only invoked via jumps, in compiler-generated code */

/*--------------------------------------------------------------------------
                 General stack layout for IEEE32 unary operations:

                  | ********** |
               10 |*ret addr 1*|            1) to backend
                9 |*ret addr 1*|
                8 | _K_mant(3) |  -> for longs
                7 | _K_mant(2) |
                6 | _K_mant(1) |
                5 | _K_mant(0) |
                4 | _K_sign    |
                3 | _K_exp(1)  |
                2 | _K_exp(0)  |
                1 |*ret addr 2*|            2) to top RT routine
                0 |*ret addr 2*| <--- SP
*/

/* #define _K(offset)        4+offset,SP */
/* #define _K_sign           4,SP        */
#define _K_mant(offset)   5+offset,SP
#define _K_exp(offset)    2+offset,SP

#pragma NO_FRAME
#pragma NO_ENTRY
#pragma NO_EXIT

/**
    DESC   f32 to long conversion.
    IN     K  : <f32 a>;
    WRITE  A, B, X, SR;
           K;
    OUT    K  : <sign, mant[0..3] is absolute val>
**/
void F_TOLONGK (void)
{
  asm {
              LDD     _K_exp(0)
              SUBD    #(125+32)
              XGDX
              BMI     TOLONGK_0  /* expo too small -> shift right. */
              BEQ     TOLONGK_1  /* already done! */
              /* { */
              /*   X: number of left shifts. */
              /* } */
              LDD     _K_mant(1)
   TOLONGK_2: LSLD
              ROL     _K_mant(1)
              DEX
              BNE     TOLONGK_2
              STD     _K_mant(1)

   TOLONGK_1: CLR     _K_mant(3)
              RTS

   TOLONGK_0: /* { */
              /*   X == -(number of right shifts). */
              /* } */
              CPX     #-32
              BLT     TOLONGK_3 ; clear K
              CLR     _K_mant(3)
              LDD     _K_mant(0)
   TOLONGK_4: LSRD
#ifdef __HCS12X__
              RORW    _K_mant(2)
#else
              ROR     _K_mant(2)
              ROR     _K_mant(3)
#endif
              INX
              BNE     TOLONGK_4
              STD     _K_mant(0)
              RTS

   TOLONGK_3: CLRA
              CLRB
              STD     _K_mant(0)
              STD     _K_mant(2)
              RTS
  } /* msa */
}

/*--------------------------------------------------------------------------*/

#pragma NO_FRAME
#pragma NO_ENTRY
#pragma NO_EXIT

/**
    DESC   f32 from long conversion.
    IN     K  : <sign, mant[0..3] is absolute val>
    WRITE  A, B, X, SR;
           K;
    OUT    K  : <f32 a>
**/
void F_FRLONGK (void)
{
  asm {
              LDD     _K_mant(2)
              BNE     FRLONGK_0    /* not zero */
              LDX     _K_mant(0)
              BNE     FRLONGK_0    /* not zero */
              /* { */
              /*   val == 0. */
              /* } */
              STD     _K_exp(0)
              RTS

  FRLONGK_0:  /* { */
              /*   D = mant[2..3] */
              /* } */
              LDX     #(125+32)
              TST     _K_mant(0)
              BMI     FRLONGK_1     /* already normalized */

  FRLONGK_2:  DEX
              LSLD
#ifdef __HCS12X__
              ROLW    _K_mant(0)
#else
              ROL     _K_mant(1)
              ROL     _K_mant(0)
#endif
              BPL     FRLONGK_2     /* not normalized yet */

  FRLONGK_1:  STAA    _K_mant(2)
              STX     _K_exp(0)
              RTS
  } /* msa */
}

/*--------------------------------------------------------------------------*/

#pragma NO_FRAME
#pragma NO_ENTRY
#pragma NO_EXIT

/**
    DESC  signed long -> ieee32 conversion
    IN    X:D   : signed long a
    WRITE A, B, X, SR;
          K, L;
    OUT   X:D   : <ieee32 a>
**/
#ifdef __cplusplus
  extern "C"
#endif
void _FSFLOAT (void)
{
  asm {
                PSHD               /* a to stack */
                PSHX
                PSHA               /* space for _K_sign */
                PSHX               /* space for _K_exp */
                __PIC_JSR(SL_PULK)
                __PIC_JSR(F_FRLONGK)
                __PIC_JSR(F_PSHK)
                PULX
                PULX               /* result to X:D */
                PULD
                LEAS  1,SP
                RTS
  } /* msa */
}

/*--------------------------------------------------------------------------*/

#pragma NO_FRAME
#pragma NO_ENTRY
#pragma NO_EXIT

/**
    DESC  unsigned long -> ieee32 conversion
    IN    X:D  : unsigned long a
    WRITE A, B, X, SR;
          K, L;
    OUT   X:D  : <ieee32 a>
**/
#ifdef __cplusplus
  extern "C"
#endif
void _FUFLOAT (void)
{
  asm {
                PSHD               /* a to stack */
                PSHX
                PSHA               /* space for _K_sign */
                PSHX               /* space for _K_exp */
                __PIC_JSR(UL_PULK)
                __PIC_JSR(F_FRLONGK)
                __PIC_JSR(F_PSHK)
                PULX
                PULX               /* result to X:D */
                PULD
                LEAS  1,SP
                RTS
  } /* msa */
}

/*--------------------------------------------------------------------------*/

#pragma NO_FRAME
#pragma NO_ENTRY
#pragma NO_EXIT

/**
    DESC  ieee32 -> signed long conversion
    IN    X:D   : ieee32 a
    WRITE A, B, X, SR;
          K, L;
    OUT   X:D   : <signed long a>
**/
#ifdef __cplusplus
  extern "C"
#endif
void _FSTRUNC (void)
{
  asm {
                PSHA                  /* space for _K_mant(3) */
                PSHD                  /* a to stack */
                PSHX
                PSHX                  /* space for _K_exp */
                __PIC_JSR(F_PULK)
                __PIC_JSR(F_TOLONGK)
                __PIC_JSR(L_PSHK)
                PULX
                PULA
                PULX                  /* result to X:D */
                PULD
                RTS
  } /* msa */
}

/*--------------------------------------------------------------------------*/

#pragma NO_FRAME
#pragma NO_ENTRY
#pragma NO_EXIT

/**
    DESC  ieee32 -> unsigned long conversion
    IN    X:D   : ieee32 a;
    WRITE A, B, X, SR;
          K, L;
    OUT   X:D   : <unsigned long a>
**/
#ifdef __cplusplus
  extern "C"
#endif
void _FUTRUNC (void)
{
  asm {
                __PIC_JMP(_FSTRUNC)    /* just ignore the sign! */
  }
}

/*--------------------------------------------------------------------------*/

/*lint --e{766} , header file 'fregs.h' is used, but in HLI code */
