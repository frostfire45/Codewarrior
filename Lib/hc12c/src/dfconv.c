/******************************************************************************
  FILE        : dfconv.c
  PURPOSE     : Run time ieee64 <-> ieee32 conversions.
  LANGUAGE    : Inline assembler
  ----------------------------------------------------------------------------
  HISTORY
    29 jun 93    Created.
    09/11/95     renaming M -> _M, L -> _L, K -> _K
 ******************************************************************************/

#include "hidef.h"
#include "dregs.h"
#include "fregs.h"
#include "dconv.h"
/*lint -e451 non_bank.sgm and runtime.sgm are not regular header files, they contain CODE_SEG/push/pop pragmas */
#include "non_bank.sgm"
#include "runtime.sgm"
/*lint +e451 */

/*lint --e{957} , MISRA 8.1 REQ, these are runtime support functions and, as such, are not meant to be called in user code; they are only invoked via jumps, in compiler-generated code */
/*lint -estring(960, "use of '#undef' is discouraged") , MISRA 19.6 REQ, macro names need to be reused across the runtime support implementation */

/*--------------------------------------------------------------------------
                 Stack layout for IEEE64 to IEEE32 operations:

                  | ********** |
               11 | _K_mant(6) |
               10 | _K_mant(5) |
                9 | _K_mant(4) |
                8 | _K_mant(3) |
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
    DESC   f64 to f32 conversion.
    IN     K  : <f64 a>;
    WRITE  A, B, X, SR;
           K;
    OUT    K  : <f32 a>
**/
void D_TOFK (void)
{
  asm {
              LDD     _K_exp(0)
              SUBD    #(1018-125)
              XGDX
              BMI     TOFK_0       /* small number */
              BEQ     TOFK_1       /* leave it */

              LDD     _K_mant(2)
              BRA     TOFK_3
    TOFK_2:   /* { */
              /*   shift until normalized. */
              /*   X: exponent */
              /*   D: mant[2..3] */
              /* } */
              DEX
              BEQ     TOFK_4

    TOFK_3:   ASLD
#ifdef __HCS12X__
              ROLW    _K_mant(0)
#else
              ROL     _K_mant(1)
              ROL     _K_mant(0)
#endif
              BPL     TOFK_2
              DEX

    TOFK_4:   /* { */
              /*   X: exponent, */
              /*   <mant[0..1], A> mantissa */
              /* } */
              CPX     #0xFE
              BLS     TOFK_5
              __PIC_JMP(F_MAXK)
    TOFK_5:
              STAA    _K_mant(2)

    TOFK_1:   STX     _K_exp(0)
              RTS

    TOFK_0:   /* { */
              /*   X: exponent is negative */
              /* } */
              CPX     #-21
              BGE     TOFK_6       /* within range */
              __PIC_JMP(F_CLRK)
    TOFK_6:   LDD     _K_mant(0)

    TOFK_7:   LSRD
              ROR     _K_mant(2)
              INX
              BNE     TOFK_7
              STD     _K_mant(0)
              STX     _K_exp(0)
              RTS
  } /* msa */
}

/* #undef _K      */
/* #undef _K_sign */
#undef _K_mant
#undef _K_exp
/*--------------------------------------------------------------------------
                 Stack layout for IEEE32 to IEEE64 operations:

                  | ********** |
               13 | _K_mant(6) |
               12 | _K_mant(5) |
               11 | _K_mant(4) |
               10 | _K_mant(3) |
                9 | _K_mant(2) |
                8 | _K_mant(1) |
                7 | _K_mant(0) |
                6 | _K_sign    |
                5 |*ret addr 1*|            1) to backend
                4 |*ret addr 1*|
                3 | _K_exp(1)  |
                2 | _K_exp(0)  |
                1 |*ret addr 2*|            2) to top RT routine
                0 |*ret addr 2*| <--- SP
*/

/* #define _K(offset)        6+offset,SP */
/* #define _K_sign           6,SP        */
#define _K_mant(offset)   7+offset,SP
#define _K_exp(offset)    2+offset,SP

#pragma NO_FRAME
#pragma NO_ENTRY
#pragma NO_EXIT

/**
    DESC   f32 to f64 conversion.
    IN     K  : <f32 a>;
    WRITE  A, B, X, SR;
           K;
    OUT    K  : <f64 a>
**/
void D_FRFK (void)
{
  asm {
              LDD     _K_exp(0)
              ADDD    #(1018-125)
              STD     _K_exp(0)
              CLRA
              CLRB
              STD     _K_mant(3)
              STD     _K_mant(5)
              __PIC_JMP(D_NORMK_UNARY)
  } /* msa */
}

/*--------------------------------------------------------------------------*/

#pragma NO_FRAME
#pragma NO_ENTRY
#pragma NO_EXIT

/**
    DESC  ieee32 -> ieee64 conversion
    IN    X:D   : ieee32 a;
    WRITE A, B, X, Y, SR;
          K, L;
    OUT   stack : <ieee64 a>
**/
#ifdef __cplusplus
  extern "C"
#endif
void _DLONG (void) {
  asm {
                PULY               /* fetch ret address */
                PSHD               /* a to stack */
                PSHX
                PSHX               /* space for _K_exp */
                __PIC_JSR(F_PULK)
                PULX               /* save _K_exp */
                LDD   2,SP         /* copy _K */
                PSHD
                LDD   2,SP
                PSHD
                PSHY               /* ret address between _K and _K_exp */
                PSHX               /* _K_exp at right place */
                __PIC_JSR(D_FRFK)
                __PIC_JSR(D_PSHK_UNARY)
                PULX               /* remove _K_exp */
                RTS
  } /* msa */
}

/*--------------------------------------------------------------------------*/

#pragma NO_FRAME
#pragma NO_ENTRY
#pragma NO_EXIT

/**
    DESC  ieee64 -> ieee32 conversion
    IN    stack : <return address, ieee64 a>;
    WRITE A, B, X, Y, SR;
          K, L;
    OUT   X:D   : ieee32 a
**/
#ifdef __cplusplus
  extern "C"
#endif
void _DSHORT (void) {
  asm {
                PSHD               /* space for exponents (see dregs.c) */
                PSHD
                __PIC_JSR(D_PULL)       /* in dregs.c TOS register is _L */
                PULD
                PULX               /* remove dummy exponent */
                PULY               /* fetch ret address */
                PSHD               /* _K_exp to right place (see fregs.c) */
                __PIC_JSR(D_TOFK)
                __PIC_JSR(F_PSHK)
                PULX               /* remove _K_exp */
                PULX               /* a to X:D */
                PULD
                LEAS  4,SP
                JMP   0,Y          /* return */
  } /* msa */
}

/*--------------------------------------------------------------------------*/

/*lint --e{766} , header files 'dregs.h' and 'fregs.h' are used, but in HLI code */
