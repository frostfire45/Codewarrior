/******************************************************************************
  FILE        : vregs.c
  PURPOSE     : Run time floating point routines.
                Virtual register definition and
                basic long routines (for conversions).
  LANGUAGE    : Inline assembler
  ----------------------------------------------------------------------------
  HISTORY
    24 jun 93    Created.
    09/11/95     renaming M -> _M, L -> _L, K -> _K
 ******************************************************************************/

#include "hidef.h"
#include "vregs.h"
/*lint -e451 non_bank.sgm and runtime.sgm are not regular header files, they contain CODE_SEG/push/pop pragmas */
#include "non_bank.sgm"
#include "runtime.sgm"
/*lint +e451 */

/******************************************************************************/


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
#define _K_mant(offset)   5+offset,SP
#define _K_sign           4,SP

#pragma NO_FRAME
#pragma NO_ENTRY
#pragma NO_EXIT

#ifdef __cplusplus
extern "C"
#endif
#pragma NO_FRAME
#pragma NO_ENTRY
#pragma NO_EXIT

/*lint -esym(752, _NEG_P) , symbol '_NEG_P' is used in HLI */
extern void NEAR _NEG_P (void);

/**
    DESC   negate long K
    IN     K  : <mant[0..3] == a (negative)>
    WRITE  A, B, X, SR;
           K;
    OUT    K  : <mant[0..3] == abs(a)>
**/
void L_NEGK (void)
{
  asm {
              COM     _K_sign
#if 1 /* reuse runtime code */
              LEAX    _K_mant(0)
              __PIC_JMP(_NEG_P)
#else
#ifdef __HCS12X__

              NEGW    _K_mant(2)
              BNE     NEGK_1
              NEGW    _K_mant(0)
              RTS
    NEGK_1:   COMW    _K_mant(0)
#else

              NEG     _K_mant(3)
              BNE     NEGK_0
              NEG     _K_mant(2)
              BNE     NEGK_1
              NEG     _K_mant(1)
              BNE     NEGK_2
              NEG     _K_mant(0)
              RTS
    NEGK_0:   COM     _K_mant(2)
    NEGK_1:   COM     _K_mant(1)
    NEGK_2:   COM     _K_mant(0)
#endif
              RTS
#endif
  } /* msa */
}

/*--------------------------------------------------------------------------*/

#pragma NO_FRAME
#pragma NO_ENTRY
#pragma NO_EXIT

/**
    DESC   push (unsigned or signed) long from K.
    IN     stack <return address>
           K : <sign, mant[0..3] == a>
    WRITE  A, B, X, SR;
           K;
    OUT    stack : (unsigned or signed long) a.
**/
void L_PSHK (void)
{
  asm {
              TST     _K_sign
              BEQ     PSHK_0     ; it is positive
              __PIC_JMP(L_NEGK)
    PSHK_0:   RTS
  } /* msa */
}

/*--------------------------------------------------------------------------*/

#pragma NO_FRAME
#pragma NO_ENTRY
#pragma NO_EXIT

/**
    DESC   pop unsigned long to K.
    IN     stack <return address, unsigned long a>
    WRITE  A, B, X, SR;
           K;
    OUT    K  : <sign == 0, mant[0..3] == a>
**/
void UL_PULK (void)
{
  asm {
              CLR     _K_sign
              RTS
  } /* msa */
}

/*--------------------------------------------------------------------------*/

#pragma NO_FRAME
#pragma NO_ENTRY
#pragma NO_EXIT

/**
    DESC   pop signed long to K.
    IN     stack <return address, signed long a>
    WRITE  A, B, X, SR;
           K;
    OUT    K  : <sign, mant[0..3] == abs(a)>
**/
void SL_PULK (void)
{
  asm {
              CLR     _K_sign
              TST     _K_mant(0)
              BPL     PULK_0
              __PIC_JMP(L_NEGK)
    PULK_0:   RTS
  } /* msa */
}

/******************************************************************************/


/*lint --e{766} , runtime.sgm is not a regular header file, it contains a conditionally compiled CODE_SEG pragma */
