/******************************************************************************
  FILE        : dconv.c
  PURPOSE     : Run time ieee64 conversions.
  LANGUAGE    : Inline assembler
  ----------------------------------------------------------------------------
  HISTORY
    29 jun 93   Created.
    09/11/95    renaming M -> _M, L -> _L, K -> _K
 ******************************************************************************/

#include "hidef.h"
#include "dregs.h"
#include "dconv.h"
/*lint -e451 non_bank.sgm and runtime.sgm are not regular header files, they contain CODE_SEG/push/pop pragmas */
#include "non_bank.sgm"
#include "runtime.sgm"
/*lint +e451 */

/*lint --e{957} , MISRA 8.1 REQ, these are runtime support functions and, as such, are not meant to be called in user code; they are only invoked via jumps, in compiler-generated code */

/*--------------------------------------------------------------------------
                 General stack layout for IEEE64 unary operations:

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

#define _K(offset)        6+offset,SP
#define _K_mant(offset)   7+offset,SP
#define _K_exp(offset)    2+offset,SP
#define _K_sign           6,SP


#pragma NO_FRAME
#pragma NO_ENTRY
#pragma NO_EXIT

/**
    DESC   f64 to long conversion.
    IN     K  : <f64 a>;
    WRITE  A, B, X, SR;
           K;
    OUT    K  : <sign, mant[0..3] is absolute val>
**/
void D_TOLONGK (void)
{
  asm {
              LDD     _K_exp(0)
              SUBD    #(1018+32)
              XGDX
              BMI     TOLONGK_0  /* expo too small -> shift right. */
              BEQ     TOLONGK_1  /* already done! */
              /* { */
              /*   X: number of left shifts. */
              /* } */
              LDD     _K_mant(3)
   TOLONGK_2: LSLD
#ifdef __HCS12X__
              ROLW    _K_mant(1)
#else
              ROL     _K_mant(2)
              ROL     _K_mant(1)
#endif
              ROL     _K_mant(0)
              DEX
              BNE     TOLONGK_2
              STD     _K_mant(3)

   TOLONGK_1: RTS

   TOLONGK_0: /* { */
              /*   X == -(number of right shifts). */
              /* } */
              CPX     #-32
              BLT     TOLONGK_3 /* clear K */
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
    DESC   f64 from long conversion.
    IN     K  : <sign, mant[0..3] is absolute val>
    WRITE  A, B, X, SR;
           K;
    OUT    K  : <f64 a>
**/
void D_FRLONGK (void)
{
  asm {
#ifdef __HCS12X__
              CLRW    _K_mant(4)
#else
              CLR     _K_mant(4)
              CLR     _K_mant(5)
#endif
              CLR     _K_mant(6)
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
              LDX     #(1018+32)
              STX     _K_exp(0)
              __PIC_JMP(D_NORMK_UNARY)
  } /* msa */
}

/*--------------------------------------------------------------------------*/

#pragma NO_FRAME
#pragma NO_ENTRY
#pragma NO_EXIT

/**
    DESC  signed long -> ieee64 conversion
    IN    X:D   : signed long a;
    WRITE A, B, X, Y, SR;
          K, L;
    OUT   stack : <ieee64 a>
**/
#ifdef __cplusplus
  extern "C"
#endif
void _DSFLOAT (void)
{
  asm {
                PULY               /* fetch ret address         */
                PSHD               /* 3 bytes for _K_mant[4..6] */
                PSHB
                PSHD               /* a to _K_mant[0..3]        */
                PSHX
                PSHB               /* 1 byte for _K_sign        */
                PSHD               /* space for _K_exp          */
                __PIC_JSR(SL_PULK)
                PULX               /* _K_exp                    */
                PSHY               /* return address            */
                PSHX
                __PIC_JSR(D_FRLONGK)
                __PIC_JSR(D_PSHK_UNARY)
                PULD               /* release space for _K_exp */
                RTS
  } /* msa */
}

/*--------------------------------------------------------------------------*/

#pragma NO_FRAME
#pragma NO_ENTRY
#pragma NO_EXIT

/**
    DESC  unsigned long -> ieee64 conversion
    IN    X:D   : unsigned long a;
    WRITE A, B, X, Y, SR;
          K, L;
    OUT   stack : <ieee64 a>
**/
#ifdef __cplusplus
  extern "C"
#endif
void _DUFLOAT (void)
{
  asm {
                PULY               /* fetch ret address */
                PSHD               /* 3 bytes for _K_mant[4..6] */
                PSHB
                PSHD               /* a to _K_mant[0..3] */
                PSHX
                PSHB               /* 1 byte for _K_sign */
                PSHD               /* space for _K_exp */
                __PIC_JSR(UL_PULK)
                PULX               /* _K_exp */
                PSHY               /* return address */
                PSHX
                __PIC_JSR(D_FRLONGK)
                __PIC_JSR(D_PSHK_UNARY)
                PULD               /* release space for _K_exp */
                RTS
  } /* msa */
}

/*--------------------------------------------------------------------------*/

#pragma NO_FRAME
#pragma NO_ENTRY
#pragma NO_EXIT

/**
    DESC  ieee64 -> signed long conversion
    IN    stack : <return address, ieee64 a>;
    WRITE A, B, X, SR;
          K, L;
    OUT   X:D   : signed long a
**/
#ifdef __cplusplus
  extern "C"
#endif
void _DSTRUNC (void)
{
  asm {
                PSHD               /* space for exponents (see dregs.c) */
                PSHD
                __PIC_JSR(D_PULL)       /* in dregs.c the TOS register is _L */
                PULD
                PULX               /* release space for dummy exponent */
                PSHD
                __PIC_JSR(D_TOLONGK)
                PULX               /* _K_exp */
                PULD
                STD   6,SP         /* return address to correct location */
                PSHX               /* now stack layout of vregs.c */
                __PIC_JSR(L_PSHK)
                LEAS  3,SP
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
    DESC  ieee64 -> unsigned long conversion
    IN    stack : <return address, ieee64 a>;
    WRITE A, B, X, SR;
          K, L;
    OUT   X:D   : <unsigned long a>
**/
#ifdef __cplusplus
  extern "C"
#endif
void _DUTRUNC (void)
{
  asm {
                __PIC_JMP(_DSTRUNC)    /* just ignore the sign! */
  } /* msa */
}

/*--------------------------------------------------------------------------*/

#pragma NO_FRAME
#pragma NO_ENTRY
#pragma NO_EXIT

/**
  DESC   Pushes K onto stack in ieee64 format.
  IN     stack: <return address>;
         K    : <f64 flt>;
  WRITE  A, B, X, SR;
  OUT    stack: <ieee64 flt>;
**/
void D_PSHK_UNARY (void)
{
  asm {
               LDX     _K_exp(0)
               LDAB    _K_mant(0)
               BITB    #0x10
               BEQ     PSHK_0       /* not normalized */
               INX
    PSHK_0:    /* { */
               /*   X: correct ieee32 exponent */
               /*   B: mant[0] + dirty bit7..bit4 */
               /* } */
               ANDB    #0x0F
               STAB    _K_mant(0)
               XGDX
               LSLD
               LSLD
               LSLD
               LSLD
               ORAB    _K_mant(0)
               /* { */
               /*   D now contains <0bit, exp, mant[0..3]> for ieee64. */
               /*   Now add the sign bit. */
               /* } */
               TST     _K_sign
               BEQ     PSHK_1  /* sign is positive. */
               ORAA    #0x80
    PSHK_1:    STD     _K(0)
               RTS
  } /* msa */
}

/*--------------------------------------------------------------------------*/

#pragma NO_FRAME
#pragma NO_ENTRY
#pragma NO_EXIT

void D_CLRK_UNARY (void)
{
  asm {
              CLRA
              CLRB
              STD      _K(0)
              STD      _K(2)
              STD      _K(4)
              STD      _K(6)
              STD      _K_exp(0)
              RTS
  } /* msa */
}

/*--------------------------------------------------------------------------*/
#pragma NO_FRAME
#pragma NO_ENTRY
#pragma NO_EXIT

void D_MAXK_UNARY (void)
{
  asm {
              PULX
              __PIC_JSR(D_CLRK_UNARY)
              PSHX
              LDD      #0x07FE
              STD      _K_exp(0)
              RTS
  } /* msa */
}

/*--------------------------------------------------------------------------*/
#pragma NO_FRAME
#pragma NO_ENTRY
#pragma NO_EXIT

/**
    DESC   normalize K
    IN     K;
    WRITE  X, K;
    OUT    K normalized if possible;
**/
void D_NORMK_UNARY (void)
{
  asm {
              LDX     _K_exp(0)
              BMI     NORMK_0    /* underflow ->denormalize */
              BEQ     NORMK_1    /* leave as it is */
              /* { */
              /*   X: exponent; */
              /* } */
              LDAB    _K_mant(0)
              BITB    #0xE0      /* for too large mantissas != 0 */
              BEQ     NORMK_6
              /* { */
              /*   mantissa not within range, shift right. */
              /* } */
    NORMK_7:  LSRB
#ifdef __HCS12X__
              RORW    _K_mant(1)
              RORW    _K_mant(3)
              RORW    _K_mant(5)
#else
              ROR     _K_mant(1)
              ROR     _K_mant(2)
              ROR     _K_mant(3)
              ROR     _K_mant(4)
              ROR     _K_mant(5)
              ROR     _K_mant(6)
#endif
              INX
              BITB    #0xE0
              BNE     NORMK_7    /* continue until bits[0..2] == 0. */
              BRA     NORMK_3
    NORMK_6:  /* { */
              /*   K has possibly to be shifted left. */
              /*   B: mant[0] */
              /*   A: counter for zero-test */
              /* } */
              LDAA    #53
    NORMK_2:  BITB    #0x10      /* == 1 for normalized numbers */
              BNE     NORMK_3    /* is normalized */
              DECA
              BNE     NORMK_8
              /* { */
              /*   number is in fact zero! */
              /* } */
              __PIC_JMP(D_CLRK_UNARY)

    NORMK_8:
#ifdef __HCS12X__
              ASLW    _K_mant(5)
              ROLW    _K_mant(3)
              ROLW    _K_mant(1)
#else
              ASL     _K_mant(6)
              ROL     _K_mant(5)
              ROL     _K_mant(4)
              ROL     _K_mant(3)
              ROL     _K_mant(2)
              ROL     _K_mant(1)
#endif
              ROLB
              DEX
              BNE     NORMK_2    /* not normalized yet */
    NORMK_3:  /* { */
              /*   mantissa <B, mant[1..6]> normalized. */
              /*   X: exponent. */
              /* } */
              STAB    _K_mant(0)
              STX     _K_exp(0)
    NORMK_1:  CPX     #0x07FF
              BLO     NORMK_5    /* that is within range */
              __PIC_JMP(D_MAXK_UNARY)    /* Sorry, that is an overflow. */

    NORMK_0:  /* { */
              /*   X: exp < 0. denormalize. */
              /* } */
    NORMK_4:
#ifdef __HCS12X__
              LSRW    _K_mant(0)
              RORW    _K_mant(2)
              RORW    _K_mant(4)
#else
              LSR     _K_mant(0)
              ROR     _K_mant(1)
              ROR     _K_mant(2)
              ROR     _K_mant(3)
              ROR     _K_mant(4)
              ROR     _K_mant(5)
#endif
              ROR     _K_mant(6)
              INX
              BNE     NORMK_4
              STX     _K_exp(0)
              /* { */
              /*   informal : un-normalized result in K. */
              /* } */
    NORMK_5:  RTS
  } /* msa */
}


/*lint --e{766} , header file 'dregs.h' is used, but in HLI code */
