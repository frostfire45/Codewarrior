/******************************************************************************
  FILE        : dcmp.c
  PURPOSE     : Run time ieee64 comparison.
  LANGUAGE    : Inline assembler
  ----------------------------------------------------------------------------
  HISTORY
    24 jun 93   Created.
 ******************************************************************************/

/*--------------------------------------------------------------------------*/

#include "non_bank.sgm"
#include "runtime.sgm"

/*lint --e{957} , MISRA 8.1 REQ, these are runtime support functions and, as such, are not meant to be called in user code; they are only invoked via jumps, in compiler-generated code */

#pragma NO_FRAME
#pragma NO_ENTRY
#pragma NO_EXIT

/**
    DESC  ieee64 comparison.
    IN    stack : <return address, ieee64 b, ieee64 a>;
    WRITE A, B, X, SR;
          K, L;
    OUT   stack : <invalid>
          CC    : set for (b - a)
**/

#define DCMP_a 10
#define DCMP_b 2

#ifdef __cplusplus
  extern "C"
#endif
void _DCMP (void) {
  asm {
                LDAA  (DCMP_b+0),SP
                TAB
                EORA  (DCMP_a+0),SP
                BMI   FCMP_0       ; different signs
                ; {
                ;   numbers with same sign.
                ;   A: will contain #-1 for negative, #1 for positive numbers.
                ; }
                LDAA  #-1
                LDX   (DCMP_b+0),SP
                BMI   FCMP_1       ; negative numbers
                LDAA  #1
    FCMP_1:     CPX   (DCMP_a+0),SP
                BNE   FCMP_2       ; it is decided
                LDX   (DCMP_b+2),SP
                CPX   (DCMP_a+2),SP
                BNE   FCMP_2       ; it is decided!
                LDX   (DCMP_b+4),SP
                CPX   (DCMP_a+4),SP
                BNE   FCMP_2       ; it is decided!
                LDX   (DCMP_b+6),SP
                CPX   (DCMP_a+6),SP
                BNE   FCMP_2       ; it is decided!
                RTS
    FCMP_2:     ; {
                ;   LO & negative ==> GT
                ;   LO & positive ==> LT
                ;   HI & negative ==> LT
                ;   HI & positive ==> GT
                ; }
                BHI   FCMP_3
                NEGA
    FCMP_3:     TSTA
                RTS
                ;
    FCMP_0:     ; {
                ;   B: DCMP_b[0]
                ;   signs are different!
                ; }
                CMPB  (DCMP_a+0),SP
                RTS
  }
}

/*--------------------------------------------------------------------------*/

/*lint --e{766} non_bank.sgm is not a regular header file, it contains a conditionally compiled CODE_SEG pragma */
