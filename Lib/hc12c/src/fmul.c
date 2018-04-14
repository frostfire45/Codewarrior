/******************************************************************************
  FILE        : fmul.c
  PURPOSE     : Run time floating point routines.
                Multiplication and division.
  LANGUAGE    : Inline assembler
  ----------------------------------------------------------------------------
  HISTORY
    24 jun 93   Created.
    09/11/95    renaming M -> _M, L -> _L, K -> _K
    05/06/96    ported to HC12
 ******************************************************************************/

#include "hidef.h"
#include "fregs.h"
/*lint -e451 non_bank.sgm and runtime.sgm are not regular header files, they contain CODE_SEG/push/pop pragmas */
#include "non_bank.sgm"
#include "runtime.sgm"
/*lint +e451 */

/*lint --e{957} , MISRA 8.1 REQ, these are runtime support functions and, as such, are not meant to be called in user code; they are only invoked via jumps, in compiler-generated code */

/*--------------------------------------------------------------------------
                 General stack layout for IEEE32 mul and div operations:

                  | ********** |
               19 | _L_mant(2) |
               18 | _L_mant(1) |
               17 | _L_mant(0) |
               16 | _L_sign    |
               15 |*ret addr 1*|            1) to backend
               14 |*ret addr 1*|
               13 | _L_exp(1)  |
               12 | _L_exp(0)  |
               11 | _K_mant(2) |
               10 | _K_mant(1) |
                9 | _K_mant(0) |
                8 | _K_sign    |
                7 | _K_exp(1)  |
                6 | _K_exp(0)  |
                5 |*ret addr 2*|            2) to top runtime routine
                4 |*ret addr 2*|
                3 | Y1 or _M(3)|
                2 | Y2 or _M(2)|
                1 |   _M(1)    |
                0 |   _M(0)    | <--- SP
*/

/* #define _K(offset)         8 + (offset), SP */
/* #define _L(offset)        16 + (offset), SP */
#define _K_mant(offset)    9 + (offset), SP
#define _K_exp(offset)     6 + (offset), SP
#define _K_sign            8           , SP
#define _L_mant(offset)   17 + (offset), SP
#define _L_exp(offset)    12 + (offset), SP
#define _L_sign           16           , SP
#define _M(offset)             (offset), SP


#pragma NO_FRAME
#pragma NO_ENTRY
#pragma NO_EXIT

/**
    DESC   f32 division.
    IN     K  : <f32 a>;
           L  : <f32 b>;
    WRITE  A, B, X, SR;
           K, L;
    OUT    K  : <f32 (a / b)>;
**/
void F_DIVKL (void)
{
  asm {
              LEAS    -4,SP        /* reserve space for _M */
              LDAA    _K_sign
              EORA    _L_sign
              STAA    _K_sign
              /* { */
              /*   assert (_K_sign == sign of result) */
              /* } */
              LDD     _K_exp(0)
              SUBD    _L_exp(0)
              ADDD    #(125 + 1)  /* value gets shifted once less than no of bits */
              /* { */
              /*   assert (D == result exponent) */
              /* } */
              TST     _L_mant(0)
              BMI     DIVKL_0     /* L is normalized */

              XGDX                /* save D to X */
              CLRB
    DIVKL_1:  /* { */
              /*   loop to normalize L, or to recognize == 0 */
              /* } */
              INCB
              BMI     DIVKL_2     /* overflow, divide by zero! */
#ifdef __HCS12X__
              ASLW    _L_mant(1)
#else
              ASL     _L_mant(2)
              ROL     _L_mant(1)
#endif
              ROL     _L_mant(0)
              BPL     DIVKL_1     /* not yet normalized */
              /* { */
              /*   L is not zero, now adjust result expo. */
              /* } */
              ABX
              XGDX                /* adjust and into D */
    DIVKL_0:  /* { */
              /*   D == result exponent, */
              /*   L != 0, normalized. */
              /* } */
              STD     _K_exp(0)
              /* { */
              /*   prepare to enter loop: */
              /*   for (...) { */
              /*     <M.mant> <<= 1; */
              /*     <K.mant> <<= 1; */
              /*     if (K.mant < 0 && K.mant msb-clear) { */
              /*       K.mant += L.mant; M.mant -= 1; */
              /*     } else if (K.mant >= 0 && K.mant msb-set) { */
              /*       K.mant -= L.mant; M.mant += 1; */
              /*     } */
              /*   } */
              /*   This way, it may be always recognized if K.mant < 0 */
              /*   or K.mant >= 0. */
              /*   X: counter -> loop 24 (and a half) times. */
              /* } */
#ifdef __HCS12X__
              CLRW    _M(0)
#else
              CLR     _M(0)
              CLR     _M(1)
#endif
              CLR     _M(2)
              LDX     #24
              TST     _K_mant(0)
              BRA     DIVKL_3     /* hops into the (else-if) test */
              /* --------------------------------------------- */
              /* The following has nothing to do with the loop. */
    DIVKL_2:  /* { */
              /*   DIVIDE BY ZERO! */
              /* } */
              LEAS    4,SP        /* release space of _M */
              __PIC_JMP(F_MAXK)
              /* --------------------------------------------- */
    DIVKL_4:
#ifdef __HCS12X__
              LSLW    _M(1)
#else
              LSL     _M(2)
              ROL     _M(1)
#endif
              ROL     _M(0)
#ifdef __HCS12X__
              LSLW    _K_mant(1)
#else
              LSL     _K_mant(2)
              ROL     _K_mant(1)
#endif
              ROL     _K_mant(0)
              BCC     DIVKL_3     /* K.mant was not negative */
              /* { */
              /*   the if-branch */
              /* } */
              BMI     DIVKL_8     /* abs(K.mant) is small enough! */
              LDD     _K_mant(1)
              ADDD    _L_mant(1)
              STD     _K_mant(1)
              LDAA    _K_mant(0)
              ADCA    _L_mant(0)
              STAA    _K_mant(0)

              /* { */
              /*  since we do not add L always to a         */
              /*  negative K, it may happen that _M:2 == 0. */
              /*  so the decrement has to be propagated     */
              /* } */
              TST     _M(2)
              BNE     DIVKL_9
#ifdef __HCS12X__
              DECW    _M(0)
#else
              TST     _M(1)
              BNE     DIVKL_10
              DEC     _M(0)
    DIVKL_10: DEC     _M(1)
#endif
    DIVKL_9:  DEC     _M(2)
              BRA     DIVKL_8     /* continue */

    DIVKL_3:  /* { */
              /*   _K_mant(0) is not negative. */
              /* } */
              BPL     DIVKL_8     /* K.mant is small enough! */
              /* { */
              /*   the else-if branch */
              /* } */
              LDD     _K_mant(1)
              SUBD    _L_mant(1)
              STD     _K_mant(1)
              LDAB    _K_mant(0)
              SBCB    _L_mant(0)
              STAB    _K_mant(0)
              INC     _M(2)         /* propagation is excluded! */

    DIVKL_8:  /* { */
              /*   for-test: repeat loop X times. */
              /* } */
              DEX
              BNE     DIVKL_4     /* one more step. */

    DIVKL_7:  /* { */
              /*   There we are. */
              /* } */
              LDD     _M(1)
              STD     _K_mant(1)
              LDAB    _M(0)
              STAB    _K_mant(0)
              LEAS    4,SP        /* release space of _M    */
              __PIC_JMP(F_NORMK)  /* normalize K and return */
  }
}

/*--------------------------------------------------------------------------*/


#pragma NO_FRAME
#pragma NO_ENTRY
#pragma NO_EXIT

/**
    DESC   f32 multiplication.
    IN     K  : <f32 a>;
           L  : <f32 b>;
    WRITE  A, B, X, SR;
           K, L;
    OUT    K  : <f32 (a * b)>;
    --------------------------
    [ K.0 * L.0 ]                          (0)
                 [ K.0 * L.1 ]             (1)
                 [ K.1 * L.0 ]             (2)
                              [K.1 * L.1]  (3)
**/


void F_MULKL (void)
{
  asm {
              PSHY                 /* save Y */
              PSHX                 /* reserve space for _M */
              LDAA    _K_sign
              EORA    _L_sign
              STAA    _K_sign      /* result sign */
              LDD     _K_exp(0)
              ADDD    _L_exp(0)
              SUBD    #125
              BPL     MULKL_0
              PULX                 /* release space of _M */
              PULY
              __PIC_JMP(F_CLRK)
    MULKL_0:  STD     _K_exp(0)
              /* { */
              /*   _K:sign sign of result     */
              /*   _K:exp  exponent of result */
              /* } */
              /* ----------------- (3) */
              LDD     _K_mant(1)
              LDY     _L_mant(1)
              EMUL
              STY     _M(0)
              /* ----------------- (1) */
              LDAB    _K_mant(0)
              CLRA
              LDY     _L_mant(1)
              EMUL
              ADDD    _M(0)
              STD     _M(0)
              LDD     #0
              PSHD
              BCC     MULKL_1
              INC     1,SP             /* save carry of 'ADDD  _M(0)' */
    MULKL_1:  PSHY
              /* TFR     Y,X */
              /* ----------------- (2) */
              LDY     _K_mant(1+2+2)
              LDAB    _L_mant(0+2+2)
              CLRA
              EMUL

              ADDD    _M(0+2+2)
              STAA    _K_mant(2+2+2)     /* LSB result to _K_mant(2) */
              PULD
#ifdef __HCS12X__
              ADED    2,SP+
#else
              ADCB    1,SP               /* carry from 'ADDD  _M(0)' */
              ADCA    2,SP+
#endif
              LEAY    D,Y
              STY     _M(0)

              /* ----------------- (0) */
              LDAB    _K_mant(0)
              LDAA    _L_mant(0)
              MUL
              ADDD    _M(0)
              STD     _K_mant(0)       /* MSW result to _K_mant(0) */
              PULX                     /* release space of _M      */
              PULY
              __PIC_JMP(F_NORMK)
  } /* msa */
}

/*--------------------------------------------------------------------------*/

#pragma NO_FRAME
#pragma NO_ENTRY
#pragma NO_EXIT

/**
    DESC  ieee32 multiplication
    IN    X:D   : ieee32 a
          stack : <return address, ieee32 b>;
    WRITE A, B, X, SR;
          K, L;
    OUT   X:D   : <ieee32 (invalid), ieee32 (a * b)>
**/
#ifdef __cplusplus
  extern "C"
#endif
void _FMUL (void)
{
  asm {
                STD   4,-SP        /* would be faster */
                PSHX
                PSHX               /* space for _K_exp */
                __PIC_JSR(F_PULK)
                __PIC_JSR(F_PULL)
                __PIC_JSR(F_MULKL)
                __PIC_JSR(F_PSHK)
                PULX
                PULX               /* result to X:D */
                LDD   4,SP+        /* would be faster and shorter */
                RTS
  }
}

/*--------------------------------------------------------------------------*/

#pragma NO_FRAME
#pragma NO_ENTRY
#pragma NO_EXIT

/**
    DESC  ieee32 division
    IN    X:D   : ieee32 a
          stack : <return address, ieee32 b>;
    WRITE A, B, X, SR;
          K, L;
    OUT   X:D   : <ieee32 (invalid), ieee32 (a / b)>
**/
#ifdef __cplusplus
  extern "C"
#endif
void _FDIV (void)
{
  asm {
                PSHX               /* space for _L_exp */
                PSHD               /* a to stack       */
                PSHX
                PSHX               /* space for _K_exp */
                __PIC_JSR(F_PULL)
                __PIC_JSR(F_PULK)
                __PIC_JSR(F_DIVKL)
                __PIC_JSR(F_PSHK)
                PULX
                PULX               /* result to X:D */
                LDD   4,SP+
                BNE   Ret
                CPX   #0x8000      /* is it 0x8000 0000 ??? */
                BNE   Ret          /* no? then return */
                TFR   D,X          /* clear X too */
  Ret:
                RTS
  }
}

/*--------------------------------------------------------------------------*/

/*lint --e{766} , header file 'fregs.h' are used, but in HLI code */
