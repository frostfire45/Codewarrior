/******************************************************************************
  FILE        : dadd.c
  PURPOSE     : Run time ieee64 addition.
  LANGUAGE    : Inline assembler
  ----------------------------------------------------------------------------
  HISTORY
    24 jun 93   Created.
    09/11/95    renaming M -> _M, L -> _L, K -> _K
 ******************************************************************************/

#include "hidef.h"
#include "dregs.h"
/*lint -e451 non_bank.sgm and runtime.sgm are not regular header files, they contain CODE_SEG/push/pop pragmas */
#include "non_bank.sgm"
#include "runtime.sgm"
/*lint +e451 */

/*lint --e{957} , MISRA 8.1 REQ, these are runtime support functions and, as such, are not meant to be called in user code; they are only invoked via jumps, in compiler-generated code */

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


#pragma NO_FRAME
#pragma NO_ENTRY
#pragma NO_EXIT

/**
    DESC   f64 addition.
    IN     K  : <f64 a>;
           L  : <f64 b>;
    WRITE  A, B, X, SR;
           K, L;
    OUT    K  : <f64 (a + b)>;
**/
void D_ADDKL (void)
{
  asm {
              LDD     _K_exp(0)
              SUBD    _L_exp(0)
              BEQ     ADDKL_0   /* exponents are the same */
              BPL     ADDKL_1   /* _K:exp > _L:exp , normalize L */
              CPD     #-52
              BGE     ADDKL_6
              __PIC_JMP(D_XGKL)   /* return L */

    ADDKL_6:  PULX
              __PIC_JSR( D_XGKL)
              PSHX
              NEGB
              BRA     ADDKL_2
    ADDKL_1:  /* { */
              /*   assert (_K:exp > _L:exp); */
              /*   A : (_K:exp - _L:exp)     */
              /* } */
              CPD     #52
              BLO     ADDKL_2    /* values are in range */
              RTS
    ADDKL_2:  /* { */
              /*   assert (_K:exp > _L:exp); */
              /*   B : (_K:exp - _L:exp);    */
              /*   K, _L: original values;   */
              /* } */
    ADDKL_3:
#ifdef __HCS12X__
              LSRW    _L_mant(0)
              RORW    _L_mant(2)
              RORW    _L_mant(4)
              ROR     _L_mant(6)
#else
              LSR     _L_mant(0)
              ROR     _L_mant(1)
              ROR     _L_mant(2)
              ROR     _L_mant(3)
              ROR     _L_mant(4)
              ROR     _L_mant(5)
              ROR     _L_mant(6)
#endif
              DECB
              BNE     ADDKL_3

    ADDKL_0:  /* { */
              /*   K, L mantissas with exponent == _K:exp */
              /* } */
              LDAA    _K_sign
              CMPA    _L_sign
              BEQ     ADDKL_4     /* signs are the same */
              /* { */
              /*   assert (_K:sign != _L:sign)            */
              /*   K, L mantissas with exponent == _K:exp */
              /* } */
              LDD     _K_mant(5)
              SUBD    _L_mant(5)
              STD     _K_mant(5)
              LDD     _K_mant(3)
#ifdef __HCS12X__
              SBED    _L_mant(3)
#else
              SBCB    _L_mant(4)
              SBCA    _L_mant(3)
#endif
              STD     _K_mant(3)
              LDD     _K_mant(1)
#ifdef __HCS12X__
              SBED    _L_mant(1)
#else
              SBCB    _L_mant(2)
              SBCA    _L_mant(1)
#endif
              STD     _K_mant(1)
              LDAA    _K_mant(0)
              SBCA    _L_mant(0)
              STAA    _K_mant(0)
              BCC     ADDKL_5     /* |K| was greater than |L| */
              /* { */
              /*   assert (<A, K.mant[1..2]> == K.mant - L.mant); */
              /* } */
              COM     _K_sign
#ifdef __HCS12X__
              COMW    _K_mant(0)
              COMW    _K_mant(2)
              COMW    _K_mant(4)
              COM     _K_mant(6)
              INCW    _K_mant(5)
              BNE     ADDKL_5
              INCW    _K_mant(3)
              BNE     ADDKL_5
              INCW    _K_mant(1)
              BNE     ADDKL_5
              INC     _K_mant(0)
#else
              COM     _K_mant(0)
              COM     _K_mant(1)
              COM     _K_mant(2)
              COM     _K_mant(3)
              COM     _K_mant(4)
              COM     _K_mant(5)
#if 0
              COM     _K_mant(6)
              INC     _K_mant(6)
#else
              NEG     _K_mant(6)
#endif
              BNE     ADDKL_5
              INC     _K_mant(5)
              BNE     ADDKL_5
              INC     _K_mant(4)
              BNE     ADDKL_5
              INC     _K_mant(3)
              BNE     ADDKL_5
              INC     _K_mant(2)
              BNE     ADDKL_5
              INC     _K_mant(1)
              BNE     ADDKL_5
              INC     _K_mant(0)
#endif
    ADDKL_5:
              /* { */
              /*   informal: K contains the correct result. */
              /*             But K.mant may have leading zeros. */
              /* } */
              __PIC_JMP(D_NORMK)   /* normalize and return */
    ADDKL_4:  /* { */
              /*   assert (_K:sign == _L:sign)            */
              /*   K, L mantissas with exponent == _K:exp */
              /* } */
              LDD     _K_mant(5)
              ADDD    _L_mant(5)
              STD     _K_mant(5)
              LDD     _K_mant(3)
#ifdef __HCS12X__
              ADED    _L_mant(3)
#else
              ADCB    _L_mant(4)
              ADCA    _L_mant(3)
#endif
              STD     _K_mant(3)
              LDD     _K_mant(1)
#ifdef __HCS12X__
              ADED    _L_mant(1)
#else
              ADCB    _L_mant(2)
              ADCA    _L_mant(1)
#endif
              STD     _K_mant(1)
              LDAA    _K_mant(0)
              ADCA    _L_mant(0)
              STAA    _K_mant(0)
    ADDKL_8:  /* { */
              /*   The mantissa may be too large, normalize. */
              /* } */
              __PIC_JMP(D_NORMK)
  } /* msa */
}

/*--------------------------------------------------------------------------*/

#pragma NO_FRAME
#pragma NO_ENTRY
#pragma NO_EXIT

/**
    DESC  ieee64 addition
    IN    stack : <return address, ieee64 a, ieee64 b>;
    WRITE SR, A, B, X;
          K, L;
    OUT   stack : <ieee64 (invalid), ieee64 (a + b)>
**/
#ifdef __cplusplus
  extern "C"
#endif
void _DADD (void) {
  asm {
                PSHX               /* reserve space for exponents */
                PSHX
                __PIC_JSR(D_PULK)
                __PIC_JSR(D_PULL)
                __PIC_JSR(D_ADDKL)
                __PIC_JSR(D_PSHK)
                PULX               /* release space for exponents */
                PULX
                RTS
  }
}

/*--------------------------------------------------------------------------*/

#pragma NO_FRAME
#pragma NO_ENTRY
#pragma NO_EXIT

/**
    DESC  ieee64 subtraction
    IN    stack : <return address, ieee64 a, ieee64 b>;
    WRITE A, B, X, SR;
          K, L;
    OUT   stack : <ieee64 (invalid), ieee64 (b - a)>
**/
#ifdef __cplusplus
  extern "C"
#endif
void _DSUB (void) {
  asm {
                LDD   8,SP
                BNE   SetSign   /* b is not zero */
                LDD   6,SP
                BNE   SetSign   /* b is not zero */
                LDD   4,SP
                BNE   SetSign   /* b is not zero */
                LDD   2,SP
                BEQ   DoAdd     /* b is zero, do not set sign bit! */
       SetSign: LDAA  2,SP
                EORA  #0x80     /* invert sign bit */
                STAA  2,SP
        DoAdd:  __PIC_JMP(_DADD)
  }
}

/*--------------------------------------------------------------------------*/

#pragma NO_FRAME
#pragma NO_ENTRY
#pragma NO_EXIT
/** DESC  ieee32 increment
    IN    stack   : ieee32 a
    WRITE SR;
          K, L;
    OUT   stack   : <ieee32 (invalid), ieee32 (a + 1)>  **/
#ifdef __cplusplus
  extern "C"
#endif
void _DINC (void) {
  asm {
                LDX   0,SP                /* ret addr */
                MOVW  2,SP, 0,SP          /* move a to TOS */
                MOVW  4,SP, 2,SP
                MOVW  6,SP, 4,SP
                MOVW  8,SP, 6,SP
                STX   8,SP
#ifdef __HCS12X__
                CLRX
#else
                LDX   #0x0000             /* b = #1 */
#endif
                PSHX
                PSHX
                PSHX
                LDX   #0x3FF0
                PSHX
                __PIC_JSR(_DADD)
                LEAS  8,SP
                LDX   8,SP                /* ret addr */
                MOVW  6,SP, 8,SP          /* move back result */
                MOVW  4,SP, 6,SP
                MOVW  2,SP, 4,SP
                PULD
                STD   0,SP
                JMP   0,X
  }
}

/*--------------------------------------------------------------------------*/

#pragma NO_FRAME
#pragma NO_ENTRY
#pragma NO_EXIT
/** DESC  ieee32 decrement
    IN    stack   : ieee32 a
    WRITE SR;
          K, L;
    OUT   stack   : <ieee32 (invalid), ieee32 (a + 1)>  **/
#ifdef __cplusplus
  extern "C"
#endif
void _DDEC (void) {
  asm {
                LDX   0,SP                /* ret addr */
                MOVW  2,SP, 0,SP          /* move a to TOS */
                MOVW  4,SP, 2,SP
                MOVW  6,SP, 4,SP
                MOVW  8,SP, 6,SP
                STX   8,SP
#ifdef __HCS12X__
                CLRX
#else
                LDX   #0x0000             /* b = #-1 */
#endif
                PSHX
                PSHX
                PSHX
                LDX   #0xBFF0
                PSHX
                __PIC_JSR(_DADD)
                LEAS  8,SP
                LDX   8,SP                /* ret addr */
                MOVW  6,SP, 8,SP          /* move back result */
                MOVW  4,SP, 6,SP
                MOVW  2,SP, 4,SP
                PULD
                STD   0,SP
                JMP   0,X
  }
}

/*--------------------------------------------------------------------------*/

#pragma NO_FRAME
#pragma NO_ENTRY
#pragma NO_EXIT

/**
    DESC  ieee64 negation
    IN    stack : <return address, ieee64 a>;
    WRITE A, SR;
    OUT   stack : <ieee64 (-a)>
**/
#ifdef __cplusplus
  extern "C"
#endif
void _DNEG (void) {
  asm {
#ifdef __HCS12X__
                LDX  2,SP
                ORX  4,SP
                ORX  6,SP
                ORX  8,SP
                BEQ   NEG2
#else
                LDX   2,SP
                BNE   NEG1
                LDX   4,SP
                BNE   NEG1
                LDX   6,SP
                BNE   NEG1
                LDX   8,SP
                BEQ   NEG2
#endif
   NEG1:        LDAA  2,SP
                EORA  #0x80
                STAA  2,SP
	 NEG2:
                RTS
  }
}

/*--------------------------------------------------------------------------*/

#pragma NO_FRAME
#pragma NO_ENTRY
#pragma NO_EXIT

/**
    DESC  ieee64 absolute
    IN    stack : <return address, ieee64 a>;
    WRITE SR;
    OUT   stack : <ieee64 |a|>
**/
#ifdef __cplusplus
  extern "C"
#endif
void _DABS (void) {
  asm {
                BCLR  2,SP, #0x80
                RTS
  }
}

/*--------------------------------------------------------------------------*/

/*lint --e{766} , header file 'dregs.h' is used, but in HLI code */
