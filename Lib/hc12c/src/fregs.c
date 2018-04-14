/******************************************************************************
   FILE        : fregs.c
  PURPOSE     : Run time floating point routines.
                Basic virtual ieee32/f32 register handling.
  LANGUAGE    : Inline assembler
  ----------------------------------------------------------------------------
  HISTORY
    24 jun 93    Created.
    09/11/95     renaming M -> _M, L -> _L, K -> _K
    05/09/96     ported to HC12 (workspace on stack, full reentrant)
    05/25/96     Must include RA into offset in F_XGKL.
 ******************************************************************************/

#include "hidef.h"
#include "fregs.h"
/*lint -e451 non_bank.sgm and runtime.sgm are not regular header files, they contain CODE_SEG/push/pop pragmas */
#include "non_bank.sgm"
#include "runtime.sgm"
/*lint +e451 */

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

#define _K(offset)         4 + (offset), SP
#define _L(offset)        12 + (offset), SP
#define _K_mant(offset)    5 + (offset), SP
#define _K_exp(offset)     2 + (offset), SP
#define _K_sign            4           , SP
#define _L_mant(offset)   13 + (offset), SP
#define _L_exp(offset)     8 + (offset), SP
#define _L_sign           12           , SP

#pragma NO_FRAME
#pragma NO_ENTRY
#pragma NO_EXIT

/**
  DESC   Pops K from stack
  IN     stack: <return address, ieee32 flt>;
  WRITE  A, B, X, SR;
         K;
  OUT    stack: <>;
         K    : <f32 flt>
**/
void F_PULK (void) {
  asm {
               LDD     _K(0)
               CLR     _K_sign      ; clear sign by default
               ASLD                 ; sign bit in carry
               BCC     PULK_1
               COM     _K_sign      ; negative number
    PULK_1:
               TAB
               BEQ     PULK_3       ; branch if unnormalized number, _K_mant(0),#0x80 bit is already cleared
               DECB                 ; normalized number
               BSET    _K_mant(0),#0x80
    PULK_3:
               CLRA
               STD     _K_exp(0)
               RTS
  } /* msa */
}

/*--------------------------------------------------------------------------*/

#pragma NO_FRAME
#pragma NO_ENTRY
#pragma NO_EXIT

/**
  DESC   Pops L from stack
  IN     stack: <return address, ieee32 flt>;
  WRITE  A, B, X, SR;
         L;
  OUT    stack: <>;
         L    : <f32 flt>
**/
void F_PULL (void)
{
    asm {
               LDD     _L(0)
               CLR     _L_sign
               ASLD                 ; sign bit in carry
               BCC     PULL_1
               COM     _L_sign      ; negative number
    PULL_1:
               TAB
               BEQ     PULL_3       ; unnormalized number, _L_mant(0),#0x80 bit is already cleared
               DECB                 ; normalized number
               BSET    _L_mant(0),#0x80
    PULL_3:
               CLRA
               STD     _L_exp(0)
               RTS
  } /* msa */
}

/*--------------------------------------------------------------------------*/

#pragma NO_FRAME
#pragma NO_ENTRY
#pragma NO_EXIT

/**
  DESC   Pushes K onto stack in ieee32 format.
  IN     stack: <return address>;
         K    : <f32 flt>;
  WRITE  A, B, X, SR;
  OUT    stack: <ieee32 flt>;
**/
void F_PSHK (void)
{
  asm {
               LDAA    _K_exp(1)
               LDAB    _K_mant(0)   ;
               BPL     PSHK_0       ; not normalized
               INCA
    PSHK_0:    ASLB
               TST     _K_sign
               BEQ     PSHK_1  ; sign is positive. clears C
               SEC
    PSHK_1:    RORA
               RORB
               STD     _K(0)         ; store packed sign, exponent and upper mant
               RTS
  } /* msa */
}

/*--------------------------------------------------------------------------*/

#pragma NO_FRAME
#pragma NO_ENTRY
#pragma NO_EXIT

/**
  DESC   Stores L to (Y) in ieee32 format.
  IN     stack: <return address>;
         L    : <f32 flt>;
         Y    : dest address;
  WRITE  A, B, SR;
  OUT    *Y = <ieee32 flt>;
**/
void F_STAL (void)
{
  asm {
               LDD     _L_mant(1)
               STD     2,Y
               LDAA    _L_exp(1)
               LDAB    _L_mant(0)   ;
               BPL     STAL_0       ; not normalized
               INCA
    STAL_0:    ; {
               ;   A: correct ieee32 exponent
               ;   B: mant[0]
               ; }
               ASLB
               TST     _L_sign
               BEQ     STAL_1  ; sign is positive. clears C
               SEC
    STAL_1:    RORA
               RORB
               STD     0,Y
               RTS
  } /* msa */
}

/*--------------------------------------------------------------------------*/

#pragma NO_FRAME
#pragma NO_ENTRY
#pragma NO_EXIT

/**
    DESC   transfers L to K.
    IN     L  : <f32 a>;
    WRITE  A, B, SR;
    OUT    K  : <f32 a>;
**/
void F_TLK (void)
{
  asm {
              LDD     _L(0)
              STD     _K(0)
              LDD     _L(2)
              STD     _K(2)
              LDD     _L_exp(0)
              STD     _K_exp(0)
              RTS
  }
}

/*--------------------------------------------------------------------------*/

#pragma NO_FRAME
#pragma NO_ENTRY
#pragma NO_EXIT

/**
    DESC   transfers K to L.
    IN     K  : <f32 a>;
    WRITE  A, B, SR;
    OUT    L  : <f32 a>;
**/
void F_TKL (void)
{
  asm {
              LDD     _K(0)
              STD     _L(0)
              LDD     _K(2)
              STD     _L(2)
              LDD     _K_exp(0)
              STD     _L_exp(0)
              RTS
  }
}

/*--------------------------------------------------------------------------*/

#pragma NO_FRAME
#pragma NO_ENTRY
#pragma NO_EXIT

/**
    DESC   swaps K and L.
    IN     K  : <f32 a>;
           L  : <f32 b>;
    WRITE  SR;
           K, L;
    OUT    K  : <f32 b>;
           L  : <f32 a>;
**/
void F_XGKL (void) {
  asm {
              PSHX
              PSHD
              LDD     _L(0+4)
              LDX     _K(0+4)
              STD     _K(0+4)
              STX     _L(0+4)
              LDD     _L(2+4)
              LDX     _K(2+4)
              STD     _K(2+4)
              STX     _L(2+4)
              LDD     _L_exp(0+4)
              LDX     _K_exp(0+4)
              STD     _K_exp(0+4)
              STX     _L_exp(0+4)
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
void F_CLRK (void)
{
  asm {
              PSHD
              CLRA
              CLRB
              STD      _K(0+2)
              STD      _K(2+2)
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
void F_CLRL (void)
{
  asm {
              PSHD
              CLRA
              CLRB
              STD      _L(0+2)
              STD      _L(2+2)
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
    WRITE  X;
           K;
    OUT    K's <exp, mant> is maximal;
**/
void F_MAXK (void)
{
  asm {
              PULX
              __PIC_JSR(F_CLRK)
              PSHX
              MOVB     #0xFE, _K_exp(1+1)
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
void F_NORMK (void)
{
  asm {
              LDX     _K_exp(0)
              BMI     NORMK_0    ; underflow ->denormalize
              BEQ     NORMK_1    ; leave as it is
              ; {
              ;   X: exponent;
              ; }
#ifdef __HCS12X__
              TSTW    _K_mant(0)
              BNE     NORMK_2
              TST     _K_mant(2)
              BNE     NORMK_2
              CLRX
#else
              TST     _K_mant(0)
              BNE     NORMK_2
              TST     _K_mant(1)
              BNE     NORMK_2
              TST     _K_mant(2)
              BNE     NORMK_2
              LDX     #0
#endif
              CLR     _K_sign    ; r2766 avoid -0.000
              BRA     NORMK_3
    NORMK_2:  TST     _K_mant(0)
              BMI     NORMK_3    ; already normalized
#ifdef __HCS12X__
              ASLW    _K_mant(1)
#else
              ASL     _K_mant(2)
              ROL     _K_mant(1)
#endif
              ROL     _K_mant(0)
              DEX
              BNE     NORMK_2    ; not normalized yet
    NORMK_3:  STX     _K_exp(0)
    NORMK_1:  CPX     #0xFF
              BLO     NORMK_5    ; that is within range
              __PIC_JMP(F_MAXK)    ; Sorry, that is an overflow.
              ;
    NORMK_0:  ; {
              ;   X: exp < 0. denormalize.
              ; }
    NORMK_4:
#ifdef __HCS12X__
              LSRW    _K_mant(0)
#else
              LSR     _K_mant(0)
              ROR     _K_mant(1)
#endif
              ROR     _K_mant(2)
              INX
              BNE     NORMK_4
#ifdef __HCS12X__
              CLRW    _K_exp(0)
#else
              CLR     _K_exp(0)
              CLR     _K_exp(1)
#endif
              ; {
              ;   informal : un-normalized result in K.
              ; }
    NORMK_5:  RTS
  } /* msa */
}

/*--------------------------------------------------------------------------*/


/*lint --e{766} non_bank.sgm is not a regular header file, it contains a conditionally compiled CODE_SEG pragma */
