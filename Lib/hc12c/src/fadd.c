/******************************************************************************
  FILE        : fadd.c
  PURPOSE     : Run time floating point addition/subtraction/negation/absolute.
  LANGUAGE    : Inline assembler
  ----------------------------------------------------------------------------
  HISTORY
    24 jun 93   Created.
    09/11/95    renaming M -> _M, L -> _L, K -> _K
    05/06/96    ported to HC12
    05/25/96    F_XGKL destroys X!
 ******************************************************************************/

#include "hidef.h"
#include "fregs.h"
/*lint -e451 non_bank.sgm and runtime.sgm are not regular header files, they contain CODE_SEG/push/pop pragmas */
#include "non_bank.sgm"
#include "runtime.sgm"
/*lint +e451 */

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

/* #define _K(offset)        4+offset,SP  */
/* #define _L(offset)        12+offset,SP */
#define _K_mant(offset)   5+offset,SP
#define _K_exp(offset)    2+offset,SP
#define _K_sign           4,SP
#define _L_mant(offset)   13+offset,SP
#define _L_exp(offset)    8+offset,SP
#define _L_sign           12,SP

#pragma NO_FRAME
#pragma NO_ENTRY
#pragma NO_EXIT
/** DESC   f32 addition.
    IN     K  : <f32 a>;
           L  : <f32 b>;
    WRITE  A, B, X, SR;
           K, L;
    OUT    K  : <f32 (a + b)>; **/
void F_ADDKL (void) {
  asm {
              LDD     _K_exp(0)
              SUBD    _L_exp(0)
              BEQ     ADDKL_0   /* exponents are the same */
              BPL     ADDKL_1   /* _K:exp > _L:exp , normalize L */
              CPD     #-24
              BGE     ADDKL_6
              __PIC_JMP(F_XGKL)   /* return L */
    ADDKL_6:  PULX
              __PIC_JSR(F_XGKL)
              PSHX
              NEGB
              BRA     ADDKL_2
    ADDKL_1:  /* { */
              /*   assert (_K_exp(0) > _L_exp(0)); */
              /*   A : (_K_exp(0) - _L_exp(0)) */
              /* } */
              CPD     #24
              BLO     ADDKL_2    /* values are in range */
              RTS
    ADDKL_2:  /* { */
              /*   assert (_K_exp(0) > _L_exp(0)); */
              /*   B : (_K_exp(0) - _L_exp(0)); */
              /*   K, _L: original values; */
              /* } */
    ADDKL_3:
#ifdef __HCS12X__
              LSRW    _L_mant(0)
#else
              LSR     _L_mant(0)
              ROR     _L_mant(1)
#endif
              ROR     _L_mant(2)
              DECB
              BNE     ADDKL_3
    ADDKL_0:  /* { */
              /*   K, L mantissas with exponent == _K_exp */
              /* } */
              LDAA    _K_sign
              CMPA    _L_sign
              BEQ     ADDKL_4     /* signs are the same */
              /* { */
              /*   assert (_K_sign != _L_sign) */
              /*   K, L mantissas with exponent == _K_exp */
              /* } */
              LDD     _K_mant(1)
              SUBD    _L_mant(1)
              STD     _K_mant(1)
              LDAA    _K_mant(0)
              SBCA    _L_mant(0)
              STAA    _K_mant(0)
              BCC     ADDKL_5     /* |K| was greater than |L| */
              /* { */
              /*   assert (<A, K.mant[1..2]> == K.mant - L.mant); */
              /* } */
              COM     _K_sign
              COM     _K_mant(0)
#ifdef __HCS12X__
              NEGW    _K_mant(1)
#else
              COM     _K_mant(1)
              NEG     _K_mant(2)
              BNE     ADDKL_5
              INC     _K_mant(1)
#endif
              BNE     ADDKL_5
              INC     _K_mant(0)
    ADDKL_5:  /* { */
              /*   informal: K contains the correct result. */
              /*             But K.mant may have leading zeros. */
              /* } */
              __PIC_JMP(F_NORMK)   /* normalize and return */
    ADDKL_4:  /* { */
              /*   assert (_K_sign == _L_sign) */
              /*   K, L mantissas with exponent == _K_exp */
              /* } */
              LDD     _K_mant(1)
              ADDD    _L_mant(1)
              STD     _K_mant(1)
              LDAA    _K_mant(0)
              ADCA    _L_mant(0)
              BCC     ADDKL_8      /* no overflow */
              RORA
#ifdef __HCS12X__
              RORW    _K_mant(1)
              INCW    _K_exp(0)
#else
              ROR     _K_mant(1)
              ROR     _K_mant(2)
              LDX     _K_exp(0)
              INX
              STX     _K_exp(0)
#endif
    ADDKL_8:  /* { */
              /*   <A, _K_mant[1..2]> == mant. */
              /* } */
              STAA    _K_mant(0)
              RTS
  } /* msa */
}
/*--------------------------------------------------------------------------*/
#pragma NO_FRAME
#pragma NO_ENTRY
#pragma NO_EXIT
/** DESC  ieee32 addition
    IN    X:D   : ieee32 a
          stack : <return address, ieee32 b>;
    WRITE A, B, X, SR;
          K, L;
    OUT   X:D   : <ieee32 (invalid), ieee32 (a + b)>  **/
#ifdef __cplusplus
  extern "C"
#endif
void _FADD (void) {
  asm {
                PSHX               /* space for _L_exp */
                PSHD               /* a to stack */
                PSHX
                PSHX               /* space for _K_exp */
                __PIC_JSR(F_PULK)
                __PIC_JSR(F_PULL)
                __PIC_JSR(F_ADDKL)
                __PIC_JSR(F_PSHK)
                PULX
                PULX               /* result to X:D */
                PULD
                LEAS  2,SP
                RTS
  }
}
/*--------------------------------------------------------------------------*/
#pragma NO_FRAME
#pragma NO_ENTRY
#pragma NO_EXIT
/** DESC  ieee32 subtraction
    IN    X:D   : ieee32 a
          stack : <return address, ieee32 b>;
    WRITE A, B, X, SR;
          K, L;
    OUT   X:D   : <ieee32 (invalid), ieee32 (a + -b)>  **/
#ifdef __cplusplus
  extern "C"
#endif
void _FSUB (void) {
  asm {
                PSHD
                LDD   4+2,SP
                BNE   SetSign
                LDD   2+2,SP
                BEQ   DoAdd     /* b is zero, do not set sign bit! */
       SetSign: LDAA  2+2,SP
                EORA  #0x80     /* invert sign bit */
                STAA  2+2,SP
        DoAdd:  PULD
                __PIC_JMP(_FADD)
  }
}
/*--------------------------------------------------------------------------*/
#pragma NO_FRAME
#pragma NO_ENTRY
#pragma NO_EXIT
/** DESC  ieee32 increment
    IN    X:D   : ieee32 a
    WRITE A, B, X, SR;
          K, L;
    OUT   X:D   : <ieee32 (invalid), ieee32 (a + 1)>  **/
#ifdef __cplusplus
  extern "C"
#endif
void _FINC (void) {
  asm {
#ifdef __HCS12X__
                CLRW  2,-SP               /* b = #1 */
#else
                MOVW  #0x0000, 2,-SP      /* b = #1 */
#endif
                MOVW  #0x3F80, 2,-SP
                __PIC_JSR(_FADD)
                LEAS  4,SP
                RTS
  }
}
/*--------------------------------------------------------------------------*/
#pragma NO_FRAME
#pragma NO_ENTRY
#pragma NO_EXIT
/** DESC  ieee32 decrement
    IN    X:D   : ieee32 a
    WRITE A, B, X, SR;
          K, L;
    OUT   X:D   : <ieee32 (invalid), ieee32 (a + 1)>  **/
#ifdef __cplusplus
  extern "C"
#endif
void _FDEC (void) {
  asm {
#ifdef __HCS12X__
                CLRW  2,-SP               /* b = #1 */
#else
                MOVW  #0x0000, 2,-SP      /* b = #1 */
#endif
                MOVW  #0xBF80, 2,-SP
                __PIC_JSR(_FADD)
                LEAS  4,SP
                RTS
  }
}
/*--------------------------------------------------------------------------*/
#pragma NO_FRAME
#pragma NO_ENTRY
#pragma NO_EXIT
/** DESC  ieee32 negation
    IN    X:D : ieee32 a;
    WRITE A, X, SR;
    OUT   X:D : ieee32 (-a) **/
#ifdef __cplusplus
  extern "C"
#endif
void _FNEG (void) {
  asm {
                TBNE D, _DO_NEG
                TBEQ X, _DONT_NEG
_DO_NEG:        LEAX 0x8000, X
  _DONT_NEG: RTS
  }
}
/*--------------------------------------------------------------------------*/
#pragma NO_FRAME
#pragma NO_ENTRY
#pragma NO_EXIT
/** DESC  ieee32 absolute
    IN    X:D   : ieee32 a;
    WRITE A, X, SR;
    OUT   X:D   : <ieee32 |a|>   **/
#ifdef __cplusplus
  extern "C"
#endif
void _FABS (void) {
  asm {

#ifdef __HCS12X__
                ANDX  #0x7FFF
#else
                XGDX
                ANDA  #0x7F
                XGDX
#endif
                RTS
  }
}
/*--------------------------------------------------------------------------*/

/*lint --e{766} , header files 'dregs.h' and 'fregs.h' are used, but in HLI code */
