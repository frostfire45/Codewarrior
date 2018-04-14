/******************************************************************************
  FILE        : fcmp.c
  PURPOSE     : Run time ieee32 comparison.
  LANGUAGE    : Inline assembler
  ----------------------------------------------------------------------------
  HISTORY
    24 jun 93    Created.
    04/26/96     adapted for C++
 ******************************************************************************/

#include "non_bank.sgm"
#include "runtime.sgm"

/*lint --e{957} , MISRA 8.1 REQ, these are runtime support functions and, as such, are not meant to be called in user code; they are only invoked via jumps, in compiler-generated code */

/*--------------------------------------------------------------------------*/
#pragma NO_FRAME
#pragma NO_ENTRY
#pragma NO_EXIT
/**
    DESC  ieee32 comparison.
    IN    X:D   : ieee32 a;
          stack : <return address, ieee32 b>
    WRITE A, B, X, SR;
          K, L;
    OUT   stack : <invalid>
          CC    : set for (a - b)
**/

#define FCMP_a 6
#define FCMP_b 0

#ifdef __cplusplus
  extern "C"
#endif
void _FCMP (void) {
  asm {
                PSHD               ; a to stack
                PSHX
                LDAA  (FCMP_b+0),SP
                TAB
                EORA  (FCMP_a+0),SP
                BMI   FCMP_0       ; different signs
                ; {
                ;   numbers with same sign.
                ;   A: will contain #-1 for negative, #1 for positive numbers.
                ; }
                LDAA  #-1
                LDX   (FCMP_b+0),SP
                BMI   FCMP_1       ; negative numbers
                NEGA               ; LDAA  #1
    FCMP_1:     CPX   (FCMP_a+0),SP
                BNE   FCMP_2       ; it is decided
                LDX   (FCMP_b+2),SP
                CPX   (FCMP_a+2),SP
                BEQ   exit       ; it is decided!
    FCMP_2:     ; {
                ;   LO & negative ==> GT
                ;   LO & positive ==> LT
                ;   HI & negative ==> LT
                ;   HI & positive ==> GT
                ; }
                BHI   FCMP_3
                NEGA
    FCMP_3:     TSTA
                BRA   exit
                ;
    FCMP_0:     ; {
                ;   B: FCMP_b[0]
                ;   signs are different!
                ; }
                CMPB  (FCMP_a+0),SP
    exit:
                LEAS 4,SP
                RTS
  }
}
/*--------------------------------------------------------------------------*/

/*lint --e{766} non_bank.sgm is not a regular header file, it contains a conditionally compiled CODE_SEG pragma */
