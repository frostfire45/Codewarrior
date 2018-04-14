/******************************************************************************
   FILE        : dmul.c
  PURPOSE     : Run time floating point routines.
                Multiplication and division.
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
                 General stack layout for IEEE64 multiplication/division:

                  | ********** |
               30 | _K_mant(6) |
               29 | _K_mant(5) |
               28 | _K_mant(4) |
               27 | _K_mant(3) |
               26 | _K_mant(2) |
               25 | _K_mant(1) |
               24 | _K_mant(0) |
               23 | _K_sign    |
               22 | _L_mant(6) |
               21 | _L_mant(5) |
               20 | _L_mant(4) |
               19 | _L_mant(3) |
               18 | _L_mant(2) |
               17 | _L_mant(1) |
               16 | _L_mant(0) |
               15 | _L_sign    |
               14 |*ret addr 1*|            1) to backend
               13 |*ret addr 1*|
               12 | _K_exp(1)  |
               11 | _K_exp(0)  |
               10 | _L_exp(1)  |
                9 | _L_exp(0)  |
                8 |*ret addr 2*|            2) to top RT routine
                7 |*ret addr 2*|
                6 |   _M(6)    |
                5 |   _M(5)    |
                4 |   _M(4)    |
                3 |   _M(3)    |
                2 |   _M(2)    |
                1 |   _M(1)    |
                0 |   _M(0)    | <--- SP
*/

/*
#define _L(offset)        15 + (offset), SP
#define _K(offset)        23 + (offset), SP
*/
#define _L_mant(offset)   16 + (offset), SP
#define _L_exp(offset)     9 + (offset), SP
#define _L_sign           15           , SP
#define _K_mant(offset)   24 + (offset), SP
#define _K_exp(offset)    11 + (offset), SP
#define _K_sign           23           , SP
#define _M(offset)             (offset), SP


#pragma NO_FRAME
#pragma NO_ENTRY
#pragma NO_EXIT

/**
    DESC   f64 division.
    IN     K  : <f64 a>;
           L  : <f64 b>;
    WRITE  A, B, X, SR;
           K, L;
    OUT    K  : <f64 (a / b)>;
**/
void D_DIVKL (void)
{
  asm {
              LEAS    -7,SP        /* reserve space for _M */
              LDAA    _K_sign
              EORA    _L_sign
              STAA    _K_sign
              /* { */
              /*   assert (_K:sign == sign of result) */
              /* } */
              LDD     _K_exp(0)
              SUBD    _L_exp(0)
              ADDD    #1022
              /* { */
              /*   assert (D == result exponent) */
              /* } */
              XGDX                /* save D to X */
              LDAA    _L_mant(0)
              BITA    #0x10
              BNE     DIVKL_0     /* L is normalized */

              CLRB
    DIVKL_1:  /* { */
              /*   loop to normalize L, or to recognize == 0 */
              /*   A: mant[0] */
              /* } */
              INCB
              BMI     DIVKL_2     /* overflow, divide by zero! */
#ifdef __HCS12X__
              ASLW    _L_mant(5)
              ROLW    _L_mant(3)
              ROLW    _L_mant(1)
#else
              ASL     _L_mant(6)
              ROL     _L_mant(5)
              ROL     _L_mant(4)
              ROL     _L_mant(3)
              ROL     _L_mant(2)
              ROL     _L_mant(1)
#endif
              ROLA
              BITA    #0x10
              BEQ     DIVKL_1     /* not yet normalized */
              /* { */
              /*   L is not zero, now adjust result expo. */
              /*   A: mant[0] not saved yet. */
              /* } */
              STAA    _L_mant(0)
              ABX
    DIVKL_0:  /* { */
              /*   X == result exponent, */
              /*   L != 0, normalized. */
              /* } */
              STX     _K_exp(0)
              /* { */
              /*   prepare auxiliary space. */
              /* } */
              CLRA
              CLRB
              STD     _M(0)
              STD     _M(2)
              STD     _M(4)
              STAB    _M(6)
              /* { */
              /*   prepare to enter loop: */
              /*   for (...) { */
              /*     <M.mant> <<= 1; */
              /*     <K.mant> <<= 1; */
              /*     if (K.mant < 0) { */
              /*       K.mant += L.mant; M.mant -= 1; */
              /*     } else if (K.mant msb-set) { */
              /*       K.mant -= L.mant; M.mant += 1; */
              /*     } */
              /*   } */
              /*   X: counter -> loop 53 (and a half) times. */
              /* } */
              LDX     #53
              BRA     DIVKL_3     /* hops into the (else-if) test */
              /* --------------------------------------------- */
              /* The following has nothing to do with the loop. */
    DIVKL_2:  /* { */
              /*   DIVIDE BY ZERO! */
              /* } */
              LEAS    7,SP        /* release space of _M */
              __PIC_JMP(D_MAXK)
              /* --------------------------------------------- */
    DIVKL_4:
#ifdef __HCS12X__
              LSLW    _M(5)
              ROLW    _M(3)
              ROLW    _M(1)
              ROL     _M(0)
              LSLW    _K_mant(5)
              ROLW    _K_mant(3)
              ROLW    _K_mant(1)
              ROL     _K_mant(0)
#else
              LSL     _M(6)
              ROL     _M(5)
              ROL     _M(4)
              ROL     _M(3)
              ROL     _M(2)
              ROL     _M(1)
              ROL     _M(0)
              LSL     _K_mant(6)
              ROL     _K_mant(5)
              ROL     _K_mant(4)
              ROL     _K_mant(3)
              ROL     _K_mant(2)
              ROL     _K_mant(1)
              ROL     _K_mant(0)
#endif
              BCC     DIVKL_3     /* K.mant was not negative */
              /* { */
              /*   the if-branch */
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
              DEC     _M(6)         /* propagation is excluded */
              BRA     DIVKL_8     /* continue */

    DIVKL_3:  /* { */
              /*   _K:(mant+0) is not negative, has bit7..bit6 == 0. */
              /* } */
              LDAB    _K_mant(0)
              BITB    #0x30
              BEQ     DIVKL_8     /* continue loop */
              /* { */
              /*   the else-if branch */
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
              LDAB    _K_mant(0)
              SBCB    _L_mant(0)
              STAB    _K_mant(0)
              INC     _M(6)         /* propagation is excluded */

    DIVKL_8:  /* { */
              /*   for-test: repeat loop X times. */
              /* } */
              DEX
              BEQ     DIVKL_7     /* continue */
              BRA     DIVKL_4     /* implement JMP <label> in inline later */

    DIVKL_7:  /* { */
              /*   There we are. */
              /* } */
              LDD     _M(5)
              STD     _K_mant(5)
              LDD     _M(3)
              STD     _K_mant(3)
              LDD     _M(1)
              STD     _K_mant(1)
              LDAB    _M(0)
              STAB    _K_mant(0)
              LEAS    7,SP        /* release space of _K */
              __PIC_JMP(D_NORMK)    /* normalize K and return */
  }
}

/*--------------------------------------------------------------------------*/

#pragma NO_FRAME
#pragma NO_ENTRY
#pragma NO_EXIT

/**
    DESC   f64 multiplication.
    IN     K  : <f64 a>;
           L  : <f64 b>;
    WRITE  A, B, X, SR;
           K, L;
    OUT    K  : <f64 (a * b)>;
**/
void D_MULKL (void)
{
  asm {
              LEAS    -7,SP        /* reserve space for _M */
              LDAA    _K_sign
              EORA    _L_sign
              STAA    _K_sign      /* result sign */
              LDD     _K_exp(0)
              ADDD    _L_exp(0)
              SUBD    #1022
              BPL     MULKL_0
              LEAS    7,SP         /* release space of _M */
              __PIC_JMP(D_CLRK)

    MULKL_0:  STD     _K_exp(0)
              /* { */
              /*   _K:sign sign of result */
              /*   _K:exp  exponent of result */
              /* } */
              /* { */
              /*   The algorithm is following. */
              /*   for (M = 0, bit = 0; bit < 53; bit++ ) { */
              /*     M >>= 1; */
              /*     if (bit IN K) M+=L; */
              /*   } */
              /* ----------------- (0) */
              CLRA
              CLRB
              STD     _M(0)
              STD     _M(2)
              STD     _M(4)
              STAB    _M(6)
              LEAX    _K_mant(6) /* load X with address of current byte */
              LDAA    #1          /* A is mask for bit. */
              BRA     MULKL_1

    MULKL_2:  /* { */
              /*   bit-no is incremented by shifting A. */
              /*   if bit-no > 7 => X is decremented!, A = #1. */
              /* } */
              PSHY
              LEAY    _K_mant(2)  /* _K_mant(0+sizeof(Y)) */
              PSHY
              CPX     2,SP+
              PULY
              BNE     MULKL_6     /* is not last byte */
              CMPA    #0x10
              BEQ     MULKL_3     /* we are finished! */
    MULKL_6:  LSLA
              BCC     MULKL_1
              DEX
              LDAA    #1

    MULKL_1:  /* { */
              /*   That is the shift part: M >>= 1. */
              /* } */
#ifdef __HCS12X__
              LSRW    _M(0)
              RORW    _M(2)
              RORW    _M(4)
#else
              LSR     _M(0)
              ROR     _M(1)
              ROR     _M(2)
              ROR     _M(3)
              ROR     _M(4)
              ROR     _M(5)
#endif
              ROR     _M(6)

              BITA    0,X
              BEQ     MULKL_2     /* bit is zero, continue loop */

              PSHA
              LDD     _M(5+1)
              ADDD    _L_mant(5+1)
              STD     _M(5+1)
              LDD     _M(3+1)
#ifdef __HCS12X__
              ADED    _L_mant(3+1)
#else
              ADCB    _L_mant(4+1)
              ADCA    _L_mant(3+1)
#endif
              STD     _M(3+1)
              LDD     _M(1+1)
#ifdef __HCS12X__
              ADED    _L_mant(1+1)
#else
              ADCB    _L_mant(2+1)
              ADCA    _L_mant(1+1)
#endif
              STD     _M(1+1)
              PULA

              LDAB    _M(0)
              ADCB    _L_mant(0)
              STAB    _M(0)
              BRA     MULKL_2    /* back to loop , implement JMP <label> in inline later */

    MULKL_3:  /* { */
              /*   end of for. */
              /* } */
    MULKL_5:  LDD     _M(5)
              STD     _K_mant(5)
              LDD     _M(3)
              STD     _K_mant(3)
              LDD     _M(1)
              STD     _K_mant(1)
              LDAB    _M(0)
              STAB    _K_mant(0)
              LEAS    7,SP         /* release space of _M */
              __PIC_JMP(D_NORMK)    /* normalize K and return */

  } /* msa */
}

/*--------------------------------------------------------------------------*/

#pragma NO_FRAME
#pragma NO_ENTRY
#pragma NO_EXIT

/**
    DESC  ieee64 multiplication
    IN    stack : <return address, ieee64 a, ieee64 b>;
    WRITE A, B, X, SR;
          K, L;
    OUT   stack : <ieee64 (invalid), ieee64 (a * b)>
**/
#ifdef __cplusplus
  extern "C"
#endif
void _DMUL (void)
{
  asm {
                PSHX                /* reserve space for exponents */
                PSHX
                __PIC_JSR(D_PULK)
                __PIC_JSR(D_PULL)
                __PIC_JSR(D_MULKL)
                __PIC_JSR(D_PSHK)
                PULX                /* release space of exponents */
                PULX
                RTS
  }
}

/*--------------------------------------------------------------------------*/

#pragma NO_FRAME
#pragma NO_ENTRY
#pragma NO_EXIT

/**
    DESC  ieee64 division
    IN    stack : <return address, ieee64 a, ieee64 b>;
    WRITE A, B, X, SR;
          K, L;
    OUT   stack : <ieee64 (invalid), ieee64 (b / a)>
**/
#ifdef __cplusplus
  extern "C"
#endif
void _DDIV (void)
{
  asm {
                PSHX                /* reserve space for exponents */
                PSHX
                __PIC_JSR(D_PULL)
                __PIC_JSR(D_PULK)
                __PIC_JSR(D_DIVKL)
                __PIC_JSR(D_PSHK)
                PULX                /* release space of exponents */
                PULX
                RTS
  }
}

/*--------------------------------------------------------------------------*/

/*lint --e{766} , header file 'dregs.h' is used, but in HLI code */
