/******************************************************************************
  FILE        : dregs.c
  PURPOSE     : Run time floating point routines.
                Basic virtual ieee64/f64 register handling.
  LANGUAGE    : Inline assembler
  ----------------------------------------------------------------------------
  HISTORY
    24 jun 93    Created.
    09/11/95     renaming M -> _M, L -> _L, K -> _K
 ******************************************************************************/

#include "hidef.h"
#include "dregs.h"
/*lint -e451 non_bank.sgm and runtime.sgm are not regular header files, they contain CODE_SEG/push/pop pragmas */
#include "non_bank.sgm"
#include "runtime.sgm"
/*lint +e451 */

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

#define _L(offset)         8 + (offset), SP
#define _K(offset)        16 + (offset), SP
#define _L_mant(offset)    9 + (offset), SP
#define _L_exp(offset)     2 + (offset), SP
#define _L_sign            8           , SP
#define _K_mant(offset)   17 + (offset), SP
#define _K_exp(offset)     4 + (offset), SP
#define _K_sign(offset)   16 + (offset), SP

#pragma NO_FRAME
#pragma NO_ENTRY
#pragma NO_EXIT

/**
  DESC   Pops K from stack
  IN     stack: <return address, ieee64 flt>;
  WRITE  A, B, X, SR;
         K;
  OUT    stack: <>;
         K    : <f64 flt>
**/
void D_PULK (void)
{
  asm {
               LDD     _K(0)
               CLR     _K_sign(0)
               ASLD
               BCC     PULK_1
               COM     _K_sign(0)      /* negative number */
    PULK_1:    LSRD
               PSHB
               LSRD
               LSRD
               LSRD
               LSRD
               BEQ     PULK_2        /* unnormalized number */
               SUBD    #1
               STD     _K_exp(1)     /* _K_exp(0+sizeof(B)) */
               PULB
               ANDB    #0x0F
               ORAB    #0x10
               BRA     PULK_3
    PULK_2:    STD     _K_exp(1)     /* _K_exp(0+sizeof(B)) */
               PULB
               ANDB    #0x0F
    PULK_3:    /* { */
               /*   assert (_K:sign and _K:exp are set) */
               /*   B: _K:mant[0] */
               /* } */
               STAB    _K_mant(0)
               RTS
  } /* msa */
}

/*--------------------------------------------------------------------------*/

#pragma NO_FRAME
#pragma NO_ENTRY
#pragma NO_EXIT

/**
  DESC   Pops L from stack
  IN     stack: <return address, ieee64 flt>;
  WRITE  A, B, X, SR;
         L;
  OUT    stack: <>;
         L    : <f64 flt>
**/
void D_PULL (void)
{
  asm {
               LDD     _L(0)
               CLR     _L_sign
               ASLD
               BCC     PULL_1
               COM     _L_sign      /* negative number */
    PULL_1:    LSRD
               PSHB
               LSRD
               LSRD
               LSRD
               LSRD
               BEQ     PULL_2        /* unnormalized number */
               SUBD    #1
               STD     _L_exp(1)     /* _L_exp(0+sizeof(B)) */
               PULB
               ANDB    #0x0F
               ORAB    #0x10
               BRA     PULL_3
    PULL_2:    STD     _L_exp(1)     /* _L_exp(0+sizeof(B)) */
               PULB
               ANDB    #0x0F
    PULL_3:    /* { */
               /*   assert (_L:sign and _L:exp are set) */
               /*   B: _L:mant[0] */
               /* } */
               STAB    _L_mant(0)
               RTS
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
void D_PSHK (void)
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
               TST     _K_sign(0)
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

/**
  DESC   Stores L in ieee64 format to (Y).
  IN     stack: <return address>;
         L    : <f64 flt>;
         Y    : dest address;
  WRITE  A, B, X, SR;
  OUT    *Y   : <ieee64 flt>
**/
void D_STAL (void)
{
  asm {
               LDD     _L_mant(5)
               STD     6,Y
               LDD     _L_mant(3)
               STD     4,Y
               LDD     _L_mant(1)
               STD     2,Y
               LDX     _L_exp(0)
               LDAB    _L_mant(0)
               BITB    #0x10
               BEQ     STAL_0       /* not normalized */
               INX
    STAL_0:    /* { */
               /*   X: correct ieee32 exponent */
               /*   B: mant[0] + dirty bit7..bit4 */
               /* } */
               ANDB    #0x0F
               STAB    _L_mant(0)
               XGDX
               LSLD
               LSLD
               LSLD
               LSLD
               ORAB    _L_mant(0)
               /* { */
               /*   D now contains <0bit, exp, mant[0..3]> for ieee64. */
               /*   Now add the sign bit. */
               /* } */
               TST     _L_sign
               BEQ     STAL_1  /* sign is positive. */
               ORAA    #0x80
    STAL_1:    STD     0,Y
               RTS
  } /* msa */
}

/*--------------------------------------------------------------------------*/

#pragma NO_FRAME
#pragma NO_ENTRY
#pragma NO_EXIT

/**
    DESC   transfers L to K.
    IN     L  : <f64 a>;
    WRITE  A, B, SR;
    OUT    K  : <f64 a>;
**/
void D_TLK (void)
{
  asm {
              PSHD
              LDD     _L(0+2)
              STD     _K(0+2)
              LDD     _L(2+2)
              STD     _K(2+2)
              LDD     _L(4+2)
              STD     _K(4+2)
              LDD     _L(6+2)
              STD     _K(6+2)
              LDD     _L_exp(0+2)
              STD     _K_exp(0+2)
              PULD
              RTS
  }
}

/*--------------------------------------------------------------------------*/

#pragma NO_FRAME
#pragma NO_ENTRY
#pragma NO_EXIT

/**
    DESC   transfers K to L.
    IN     K  : <f64 a>;
    WRITE  A, B, SR;
    OUT    L  : <f64 a>;
**/
void D_TKL (void)
{
  asm {
              PSHD
              LDD     _K(0+2)
              STD     _L(0+2)
              LDD     _K(2+2)
              STD     _L(2+2)
              LDD     _K(4+2)
              STD     _L(4+2)
              LDD     _K(6+2)
              STD     _L(6+2)
              LDD     _K_exp(0+2)
              STD     _L_exp(0+2)
              PULD
              RTS
  }
}

/*--------------------------------------------------------------------------*/

#pragma NO_FRAME
#pragma NO_ENTRY
#pragma NO_EXIT

/**
    DESC   swaps K and L.
    IN     K  : <f64 a>;
           L  : <f64 b>;
    WRITE  SR;
           K, L;
    OUT    K  : <f64 b>;
           L  : <f64 a>;
**/
void D_XGKL (void)
{
  asm {
              PSHX
              PSHD
              LDD     _L(4)
              LDX     _K(4)
              STD     _K(4)
              STX     _L(4)
              LDD     _L(6)
              LDX     _K(6)
              STD     _K(6)
              STX     _L(6)
              LDD     _L(8)
              LDX     _K(8)
              STD     _K(8)
              STX     _L(8)
              LDD     _L(10)
              LDX     _K(10)
              STD     _K(10)
              STX     _L(10)
              LDD     _L_exp(4)
              LDX     _K_exp(4)
              STD     _K_exp(4)
              STX     _L_exp(4)
              PULD
              PULX
              RTS
  }
}

/*--------------------------------------------------------------------------*/

#pragma NO_FRAME
#pragma NO_ENTRY
#pragma NO_EXIT

/**
    DESC   sets K to zero
    IN     -
    WRITE  K;
    OUT    K == 0;
**/
void D_CLRK (void)
{
  asm {
              PSHD
              CLRA
              CLRB
              STD      _K(0+2)
              STD      _K(2+2)
              STD      _K(4+2)
              STD      _K(6+2)
              STD      _K_exp(0+2)
              PULD
              RTS
  } /* msa */
}


/*--------------------------------------------------------------------------*/

#pragma NO_FRAME
#pragma NO_ENTRY
#pragma NO_EXIT

/**
    DESC   sets L to zero
    IN     -
    WRITE  L;
    OUT    L == 0;
**/
void D_CLRL (void)
{
  asm {
              PSHD
              CLRA
              CLRB
              STD      _L(0+2)
              STD      _L(2+2)
              STD      _L(4+2)
              STD      _L(6+2)
              STD      _L_exp(0+2)
              PULD
              RTS
  } /* msa */
}


/*--------------------------------------------------------------------------*/

#pragma NO_FRAME
#pragma NO_ENTRY
#pragma NO_EXIT

/**
    DESC   sets absolute of K to maximum
    IN     -
    WRITE  A, B, X;
           K;
    OUT    K's <exp, mant> is maximal;
**/
void D_MAXK (void)
{
  asm {
              PULX
              __PIC_JSR(D_CLRK)
              PSHX
              LDX      #0x07FE
              STX      _K_exp(0)
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
void D_NORMK (void)
{
  asm {
              PSHD
#ifdef __HCS12X__
              LDX     _K_mant(0+2)
              ORX     _K_mant(2+2)
              ORX     _K_mant(4+2)
              ORX     _K_mant(6+2-1) /* note: oring same byte twice. */
#else
              LDAB    _K_mant(0+2)
              ORAB    _K_mant(1+2)
              ORAB    _K_mant(2+2)
              ORAB    _K_mant(3+2)
              ORAB    _K_mant(4+2)
              ORAB    _K_mant(5+2)
              ORAB    _K_mant(6+2)
#endif
              BNE     NORMK_9
              CLR     _K_sign(0+2)    /* r2766 avoid -0.000 */
    NORMK_9:
              LDX     _K_exp(0+2)
              BMI     NORMK_0    /* underflow ->denormalize */
              BEQ     NORMK_1    /* leave as it is */
              /* { */
              /*   X: exponent; */
              /* } */
              LDAB    _K_mant(0+2)
              BITB    #0xE0      /* for too large mantissas != 0 */
              BEQ     NORMK_6
              /* { */
              /*   mantissa not within range, shift right. */
              /* } */
    NORMK_7:  LSRB
#ifdef __HCS12X__
              RORW    _K_mant(1+2)
              RORW    _K_mant(3+2)
              RORW    _K_mant(5+2)
#else
              ROR     _K_mant(1+2)
              ROR     _K_mant(2+2)
              ROR     _K_mant(3+2)
              ROR     _K_mant(4+2)
              ROR     _K_mant(5+2)
              ROR     _K_mant(6+2)
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
              PULD
              __PIC_JMP(D_CLRK)

    NORMK_8:
#ifdef __HCS12X__
              ASLW    _K_mant(5+2)
              ROLW    _K_mant(3+2)
              ROLW    _K_mant(1+2)
#else
              ASL     _K_mant(6+2)
              ROL     _K_mant(5+2)
              ROL     _K_mant(4+2)
              ROL     _K_mant(3+2)
              ROL     _K_mant(2+2)
              ROL     _K_mant(1+2)
#endif
              ROLB
              DEX
              BNE     NORMK_2    /* not normalized yet */
    NORMK_3:  /* { */
              /*   mantissa <B, mant[1..6]> normalized. */
              /*   X: exponent. */
              /* } */
              STAB    _K_mant(0+2)
              STX     _K_exp(0+2)
    NORMK_1:  CPX     #0x07FF
              BLO     NORMK_5    /* that is within range */
              PULD
              __PIC_JMP(D_MAXK)    /* Sorry, that is an overflow. */

    NORMK_0:  /* { */
              /*   X: exp < 0. denormalize. */
              /* } */
    NORMK_4:
#ifdef __HCS12X__
              LSRW    _K_mant(0+2)
              RORW    _K_mant(2+2)
              RORW    _K_mant(4+2)
#else
              LSR     _K_mant(0+2)
              ROR     _K_mant(1+2)
              ROR     _K_mant(2+2)
              ROR     _K_mant(3+2)
              ROR     _K_mant(4+2)
              ROR     _K_mant(5+2)
#endif
              ROR     _K_mant(6+2)
              INX
              BNE     NORMK_4
              STX     _K_exp(0+2)
              /* { */
              /*   informal : un-normalized result in K. */
              /* } */
    NORMK_5:  PULD
              RTS
  } /* msa */
}

/*--------------------------------------------------------------------------*/


/*lint --e{766} non_bank.sgm is not a regular header file, it contains a conditionally compiled CODE_SEG pragma */
