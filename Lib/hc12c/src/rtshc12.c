/******************************************************************************
  FILE        : RTSHC12.c
  PURPOSE     : 8, 16, 32 bit and float arithmetic
                block move and case handling
                for Freescale 68HC12.
  MACHINE     : Freescale 68HC12 (Target)
  LANGUAGE    : ANSI-C
  HISTORY     : 25.4.96 first version derived from HC11
******************************************************************************/

#include "hidef.h"
#include "non_bank.sgm"
#include "runtime.sgm"

/*lint --e{957} , MISRA 8.1 REQ, these are runtime support functions and, as such, are not meant to be called in user code; they are only invoked via jumps, in compiler-generated code */

/*-------------------- tabled functions used with options -ot -oilib=g ----------------*/

/*lint -estring(960, "Operators '~' and '<<' require recasting to underlying type for sub-integers") , MISRA 10.5 REQ, '<<' applied to an operand of type 'unsigned int' - which is not a sub-integer type */
/* 1 << char */
const unsigned char _PowOfTwo_8[] = {1u<<0,1u<<1,1u<<2,1u<<3,1u<<4,1u<<5,1u<<6,1u<<7};
/* 1 << int */
const unsigned short _PowOfTwo_16[] =
{1u<<0,1u<<1,1u<<2,1u<<3,1u<<4,1u<<5,1u<<6,1u<<7,1u<<8,1u<<9,1u<<10,1u<<11,1u<<12,1u<<13,1u<<14,1u<<15};
/*lint +estring(960, "Operators '~' and '<<' require recasting to underlying type for sub-integers") */
/* 1L << long */
const unsigned long _PowOfTwo_32[] =
{1UL<<0,1UL<<1,1UL<<2,1UL<<3,1UL<<4,1UL<<5,1UL<<6,1UL<<7,1UL<<8,1UL<<9,1UL<<10,1UL<<11,1UL<<12,1UL<<13,1UL<<14,1UL<<15,
 1UL<<16,1UL<<17,1UL<<18,1UL<<19,1UL<<20,1UL<<21,1UL<<22,1UL<<23,1UL<<24,1UL<<25,1UL<<26,1UL<<27,1UL<<28,1UL<<29,1UL<<30,1UL<<31};

/**************************    <errno.h>   ************************************/

int errno;

/*--------------------------- char operations --------------------------------
  logical and arithmetic Byte shift

  Arguments :
  - A : value to shift
  - B : shift count

  Postcondition :
  - A == shifted old A value
  - B == 0
  - all other registers remain unchanged
*/
/*--------------------------- Byte Shift Left ----------------------------------*/

/* A = A << A */

#ifdef __cplusplus
extern "C"
#endif
#pragma NO_FRAME
#pragma NO_ENTRY
#pragma NO_EXIT

void NEAR _BSHL ( void ) {
  asm {
        TSTA
        BEQ done
  loop: LSLB
        DBNE A, loop   /* this version is faster than DECA/BNE */
  done: RTS
  }
}
/*-------------------- Byte Shift Right Signed ---------------------------------*/

/* A = A >> B , A signed */

#ifdef __cplusplus
extern "C"
#endif
#pragma NO_FRAME
#pragma NO_ENTRY
#pragma NO_EXIT

void NEAR _BSHRS( void ) {
  asm {
        TSTA
        BEQ done
  loop: ASRB
        DBNE A, loop   /* this version is faster than DECA/BNE */
  done: RTS
  }
}

/*---------------------- Byte Shift Right Unsigned -----------------------------*/

/* A = A >> B , A unsigned */

#ifdef __cplusplus
extern "C"
#endif
#pragma NO_FRAME
#pragma NO_ENTRY
#pragma NO_EXIT

void NEAR _BSHRU( void ) {
  asm {
        TSTA
        BEQ done
  loop: LSRB
        DBNE A, loop   /* this version is faster than DECA/BNE */
  done: RTS
  }
}
/*---------------------- Byte Divisions -----------------------------
  Arguments :
  - A : divisor
  - B : dividend

  Postcondition :
  - A == quotient of (B / A)
  - B == remainder of (B / A)
  - all other registers remain unchanged
*/

/*--------  Byte DIVide MODulo Unsigned -----------------------------------------------*/

/* A = B / A, B = B % A */

#ifdef __cplusplus
extern "C"
#endif
#pragma NO_FRAME
#pragma NO_ENTRY
#pragma NO_EXIT

void NEAR _BDIVMODU ( void ) {
  asm {
        PSHX
        EXG   A, X            /* Zero extend from A to X, A is destroyed */
        CLRA                  /* Zero extend for D */
        IDIV
        TFR   X, A
        PULX
        RTS
  }
}

/*--------  Byte DIVide MODulo Signed -----------------------------------------------*/

/* A = B / A, B = B % A */


#ifdef __cplusplus
extern "C"
#endif
#pragma NO_FRAME
#pragma NO_ENTRY
#pragma NO_EXIT

void NEAR _BDIVMODS ( void ) {
  asm {
        PSHX
        SEX   A, X            /* Sign extend from A to X */
        SEX   B, D            /* Sign extend from B to D */
        IDIVS
        TFR   X, A
        PULX
        RTS
  }
}

/*--------------------- int operations -----------------------------------------*/


/*--------------------- logical and arithmetic int shifts ----------------------
  Arguments :
  Y : value to shift
  B : shift count

  Postcondition :
  Y == 0
  D == shifted old Y value
  all other registers remain unchanged
*/

/*---------------------- Int Shift Left ----------------------------------------*/

/* D = Y << B */

#ifdef __cplusplus
extern "C"
#endif
#pragma NO_FRAME
#pragma NO_ENTRY
#pragma NO_EXIT

void NEAR _ISHL ( void ) {
  asm {
        CLRA
        TSTB            /* test if counter == 0 */
        EXG   D, Y
        BEQ   done
  loop: LSLD
        DBNE  Y, loop   /* this version is faster than DEY/BNE */
  done: RTS
  }
}

/*----------------- Int Shift Right Unsigned -----------------------------------*/

/* D = Y >> B , D signed */

#ifdef __cplusplus
extern "C"
#endif
#pragma NO_FRAME
#pragma NO_ENTRY
#pragma NO_EXIT

void NEAR _ISHRU ( void ) {
  asm {
        CLRA
        TSTB            /* test if counter == 0 */
        EXG   D, Y
        BEQ   done
  loop: LSRD
        DBNE Y, loop   /* this version is faster than DEY/BNE */
  done: RTS
  }
}
/*------------------- Int Shift Right Signed -----------------------------------*/

/* D = Y >> B , D signed */

#ifdef __cplusplus
extern "C"
#endif
#pragma NO_FRAME
#pragma NO_ENTRY
#pragma NO_EXIT

void NEAR _ISHRS ( void ) {
  asm {
        CLRA
        TSTB            /* test if counter == 0 */
        EXG   D, Y
        BEQ   done
  loop: ASRA
        RORB
        DBNE  Y, loop   /* this version is faster than DEY/BNE */
  done: RTS
  }
}
/*---------------------- logical and arithmetic long shifts --------------------
  Parameters :
  - loop counter in the B-Register to avoid a zero-extension for the caller
  - high order word of argument in the X-Register
  - low order word of argument in the Y-Register

  Result :
  - high order word of result in the X-Register
  - low order word of result in the D-Register
  - the Y-register contains 0
*/

/*----------------------- Long Shift Left --------------------------------------*/

/* X:D = X:Y << B , Y=0*/

#ifdef __cplusplus
extern "C"
#endif
#pragma NO_FRAME
#pragma NO_ENTRY
#pragma NO_EXIT

void NEAR _LSHL ( void ) {
  asm {
        CLRA                   /* zero extend D */
        TSTB                   /* test if counter == 0 */
        EXG   D, Y
        BEQ   done
  loop: ASLD                   /* low order word first */
#ifdef __HCS12X__
        ROLX
#else
        EXG   D, X
        ROLB                   /* low order byte of high order word second */
        ROLA                   /* and then the high order byte of the high order word */
        EXG   D, X
#endif
        DBNE  Y, loop   /* this version is faster than DEY/BNE */
  done: RTS
  }
}

/*--------------------- Long Shift Right Unsigned ------------------------------*/

/* X:D = X:Y >> B, Y=0, A unsigned */

#ifdef __cplusplus
extern "C"
#endif
#pragma NO_FRAME
#pragma NO_ENTRY
#pragma NO_EXIT

void NEAR _LSHRU ( void ) {
  asm {
        CLRA
        TSTB            /* test if counter == 0 */
        EXG   D, Y
        BEQ   done
  loop:
#ifdef __HCS12X__
        LSRX
#else
        EXG   D, X
        LSRD
        EXG   D, X
#endif
        RORA
        RORB
        DBNE  Y, loop   /* this version is faster than DEY/BNE */
  done: RTS
  }
}
/*-------------------- Long Shift Right Signed ---------------------------------*/

/* X:D = X:Y >> B, Y=0, A signed */

#ifdef __cplusplus
extern "C"
#endif
#pragma NO_FRAME
#pragma NO_ENTRY
#pragma NO_EXIT

void NEAR _LSHRS ( void ) {
  asm {
        CLRA
        TSTB            /* test if counter == 0 */
        EXG   D, Y
        BEQ   done
  loop:
#ifdef __HCS12X__
        ASRX
#else
        EXG    D, X
        ASRA
        RORB
        EXG    D, X
#endif
        RORA
        RORB
        DBNE   Y, loop   /* this version is faster than DEY/BNE */
  done: RTS
  }
}
/*----------------ADD, SUB and logical long operations -------------------------
  Parameters:
  - high order word of first argument in the X-Register
  - low order word of first argument in the D-Register
  - high order word of second argument on top of the Stack
  - low order word of second argument on the second stack position

  Result :
  - high order word of result in the X-Register
  - low order word of result in the D-Register
  - the Y Register is destroyed
  - the stack arguments are released
*/

/*---------------- Long ADD ----------------------------------------------------*/

/* X:D = X:D + SP[0:1]:SP[2:3] */


#ifdef __cplusplus
extern "C"
#endif
#pragma NO_FRAME
#pragma NO_ENTRY
#pragma NO_EXIT

void NEAR _LADD ( void ) {
  asm {
        ADDD   4, SP
#ifdef __HCS12X__
        ADEX   2, SP
#else
        EXG    D, X
        ADCB   3, SP
        ADCA   2, SP
        EXG    D, X
#endif
        LDY    6, SP+      /* load return address and release stack arguments */
        JMP    0, Y
  }
}


/* Long SUB */
/* X:D = X:D - SP[0:1]:SP[2:3] */


#ifdef __cplusplus
extern "C"
#endif
#pragma NO_FRAME
#pragma NO_ENTRY
#pragma NO_EXIT

void NEAR _LSUB ( void ) {
  asm {
        SUBD   4, SP
#ifdef __HCS12X__
        SBEX   2, SP
#else
        EXG    D, X
        SBCB   3, SP
        SBCA   2, SP
        EXG    D, X
#endif
        LDY    6, SP+      /* load return address and release stack arguments */
        JMP    0, Y
  }
}

/*----------- Long AND ---------------------------------------------------------*/

/* X:D = X:D & SP[0:1]:SP[2:3] */

#ifdef __cplusplus
extern "C"
#endif
#pragma NO_FRAME
#pragma NO_ENTRY
#pragma NO_EXIT

void NEAR _LAND ( void ) {
  asm {
        PULY               /* load return address */
        ANDA   2, SP
        ANDB   3, SP
#ifdef __HCS12X__
        ANDX   4, SP+      /* same as ANDX 0,SP, LEAS 4,SP; releases stack arguments */
#else
        EXG    D, X
        ANDA   1, SP
        ANDB   4, SP+      /* same as ANDB 0,SP, LEAS 4,SP; releases stack arguments */
        EXG    D, X
#endif
        JMP    0, Y
  }
}

/*------------ Long OR ---------------------------------------------------------*/

/* X:D = X:D | SP[0:1]:SP[2:3] */

#ifdef __cplusplus
extern "C"
#endif
#pragma NO_FRAME
#pragma NO_ENTRY
#pragma NO_EXIT

void NEAR _LOR ( void ) {
  asm {
        PULY               /* load return address */
        ORAA   2, SP
        ORAB   3, SP
#ifdef __HCS12X__
        ORX    4, SP+      /* same as ORX 0,SP, LEAS 4,SP; releases stack arguments */
#else
        EXG    D, X
        ORAA   1, SP
        ORAB   4, SP+      /* same as ORAB 0,SP, LEAS 4,SP; releases stack arguments */
        EXG    D, X
#endif
        JMP    0, Y
  }
}
/*---------- Long XOR ----------------------------------------------------------*/

/* X:D = X:D ^ SP[0:1]:SP[2:3] */

#ifdef __cplusplus
extern "C"
#endif
#pragma NO_FRAME
#pragma NO_ENTRY
#pragma NO_EXIT

void NEAR _LXOR ( void ) {
  asm {
        PULY               /* load return address */
        ORAA  2, SP
        ORAB  3, SP
#ifdef __HCS12X__
        ORX  4, SP+        /* same as ORX 0,SP, LEAS 4,SP; releases stack arguments */
#else
        EXG   D, X
        ORAA  1, SP
        ORAB  4, SP+       /* same as ORAB 0,SP, LEAS 4,SP; releases stack arguments */
        EXG   D, X
#endif
        JMP   0, Y
  }
}
/*---------- long compare ------------------------------------------------------
  Parameters:
  - high order word of first argument in the X-Register
  - low  order word of first argument in the D-Register
  - high order word of second argument on top of the Stack
  - low  order word of second argument on the second stack position


  Result :
  - N, Z, V & C are set according as in an int-compare
  - the D & X  register are still valid
  - the Y register is destroyed
  - the stack arguments are released
*/

#ifdef __cplusplus
extern "C"
#endif
#pragma NO_FRAME
#pragma NO_ENTRY
#pragma NO_EXIT

void _LCMP (void) {
   asm {
#ifdef __HCS12X__
           CPD    4,SP
           CPEX   2,SP
#else
           CPD    4,SP
           BEQ    L1
           PSHX
           XGDX
           SBCB   5,SP
           SBCA   4,SP
           XGDX
           ANDCC #0xFB               /* clr z */
           PULX
           BRA done
   L1:     CPX   2,SP
  done:
#endif
           PULY             /* load return address */
           LEAS  4, SP      /* release stack arguments */
           JMP   0, Y
   }
}

/*---------- long compare with 1 pointer ------------------------------------------------------
  Parameters:
  - high order word of first argument in the X-Register
  - low  order word of first argument in the D-Register
  - pointer to second argument is passed in Y-Register

  Result :
  - N, Z, V & C are set according as in an int-compare
  - the D, X & the Y register are still valid */

#ifdef __cplusplus
extern "C"
#endif
#pragma NO_FRAME
#pragma NO_ENTRY
#pragma NO_EXIT

void NEAR _LCMP_P (void) {
  asm {
        CPD    2,Y
#ifdef __HCS12X__
        CPEX   0,Y
#else
        BEQ    L1
        PSHX
        XGDX
        SBCB   1,Y
        SBCA   0,Y
        XGDX
        ANDCC #0xFB               /* clr z */
        PULX
        BRA done
L1:     CPX   0,Y
#endif
  done: RTS
  }
}
/*---------- long compare with 2 pointers ------------------------------------------------------
  Parameters:
  - pointer to first  argument is passed in X-Register
  - pointer to second argument is passed in Y-Register

  Result :
  - N, Z, V & C are set according as in an int-compare for a CMP X,Y X in a register
  - the D, X & Y registers are still valid */

#ifdef __cplusplus
extern "C"
#endif
#pragma NO_FRAME
#pragma NO_ENTRY
#pragma NO_EXIT

void NEAR _LCMP_PP (void) {
  asm {
        PSHD
        PSHX
        LDD    2, X
        LDX    0, X
        __PIC_JSR(_LCMP_P)
        PULX
        PULD
        RTS
  }
}
/*------------ unary long operations -------------------------------------------
  Parameters:
  - high order word of argument in the X-Register
  - low  order word of argument in the D-Register

  Result :
  - high order word of result in the X-Register
  - low  order word of result in the D-Register
  - the Y Register is still valid
*/

/*-------- Long NEG ------------------------------------------------------------*/

/* D:X = -D:X  */

#ifdef __cplusplus
extern "C"
#endif
#pragma NO_FRAME
#pragma NO_ENTRY
#pragma NO_EXIT

void NEAR _LNEG ( void ) {
  asm {
#ifdef __HCS12X__
        COMA
        COMB
        COMX
        IBNE  D,noinc
        INX
noinc:  RTS
#else
        COMA
        COMB
        EXG   D, X
        COMA
        COMB
        EXG   D, X
        IBNE  D,noinc
        INX
noinc:  RTS
#endif
   }
}

/*---------- Long COMplement ---------------------------------------------------*/

/* D:X = ~(D:X)  */

#ifdef __cplusplus
extern "C"
#endif
#pragma NO_FRAME
#pragma NO_ENTRY
#pragma NO_EXIT

void NEAR _LCOM ( void ) {
  asm {
        COMA
        COMB
#ifdef __HCS12X__
        COMX
#else
        EXG   D, X
        COMA
        COMB
        EXG   D, X
#endif
        RTS
  }
}
/*---------- Long INCrement ---------------------------------------------------*/

/* D:X = (D:X)+1  */

#ifdef __cplusplus
extern "C"
#endif
#pragma NO_FRAME
#pragma NO_ENTRY
#pragma NO_EXIT

void NEAR _LINC ( void ) {
  asm {
        IBNE  D,done
        INX
  done: RTS
  }
}
/*---------- Long DECrement ---------------------------------------------------*/

/* D:X = (D:X)-1  */

#ifdef __cplusplus
extern "C"
#endif
#pragma NO_FRAME
#pragma NO_ENTRY
#pragma NO_EXIT

void NEAR _LDEC ( void ) {
  asm {
#ifdef __HCS12X__
         SUBD  #1
         SBEX  #0
#else
         TBNE  D, decry
         DEX
  decry: SUBD  #1
#endif
         RTS
  }
}

/*----------- long multiplication ----------------------------------------------
  Parameters:
  - high order word of first argument in the X register
  - low order word of first argument in the D register
  - high order word of second argument on top of the stack
  - low order word of second argument on the second stack position

  Result :
  - high order word of result in the X-Register
  - low order word of result in the D-Register
  - the Y Register is still valid
  - the stack arguments are released

  Remark :
  - the signed and the unsigned long multiplication don't differ because
    only the first 32 bit of the result are considered.

*/

#ifdef __cplusplus
extern "C"
#endif
#pragma NO_FRAME
#pragma NO_ENTRY
#pragma NO_EXIT


/*
  calculation :
  A:B*C:D ==
  (A*2^16+B)*(C*2^16+D) ==
  A*B*2^32+B*C*2^16+A*D*2^16+B*D

  this result mod 2^32
  == B*D+B*C*2^16+A*D*2^16
  // all values larger then 2^32 are not calculated
*/

#define  V_A  4, SP
#define  V_B  6, SP
/* at 8,SP is the return-address */
#define  V_C 10, SP
#define  V_D 12, SP
#define  V_RH 0, SP
#define  V_RL 2, SP

/*---------------- Long MULtiplication -----------------------------------------*/

/* D:X = SP[0:1]:SP[2:3]*SP[4:5]*SP[6:7]  */

void NEAR _LMUL ( void ) {
  asm {
        PSHD
        PSHX
        LEAS   -4, SP /* Allocate space for the result */
                      /* Actual stack-frame: look to the defines */
        LDD    V_D    /* RH:RL = B*D */
        LDY    V_B
        EMUL
        STD    V_RL
        STY    V_RH

        LDD    V_B    /* RH += B*C */
        LDY    V_C
        EMUL
        ADDD   V_RH
        STD    V_RH

        LDD    V_A   /* RH += A*D */
        LDY    V_D
        EMUL
        ADDD   V_RH
        TFR    D, X
        LDD    V_RL
        LEAS   8, SP
        LDY    6, SP+      /* load return address and release stack arguments */
        JMP    0, Y
  }
}

/*----------- Long 16x32 bit MULtiplications ----------------------------------------------
  Parameters:
  - high order word of first argument in the X register
  - low order word of first argument in the D register
  - 16 bit second argument in the Y register

  Result :
  - high order word of result in the X-Register
  - low order word of result in the D-Register
  - the Y Register is undefined

  Remark :
  - the signed and the unsigned long multiplication do differ as the 16 bit value has to be either be multiplied signed or unsigned.

*/

#ifdef __cplusplus
extern "C"
#endif
#pragma NO_FRAME
#pragma NO_ENTRY
#pragma NO_EXIT


/*
  calculation :
  A:B*C ==
  (A*2^16+B)*C ==
  A*C*2^16+B*C
  // all values larger then 2^32 are not calculated
*/

/*---------------- Unsigned Long 16x32 bit MULtiplications -----------------------------------------*/


void NEAR _LMULU16x32 ( void ) {
  asm {
                       /* D == LOW(arg0) */
                       /* X == HIGH(arg0) */
                       /* Y == arg1 */
        PSHY           /* store arg1 for second multiplication */
        EXG     D,X    /* move high into D */
        EMUL           /* D:Y == HIGH(arg0) * arg1 */
        EXG     X,D    /* store the low word of the multiplication and restore LOW(arg0) */
        PULY           /* reload arg1 (we don't need the high word of the multiplication result) */
        EMUL           /* D:Y == LOW(arg0) * arg1 */
                       /* now we need to compute X= X + Y */
#if 0 && defined(__HCS12X__) /* saves two bytes, but costs 2 cycles. For now use shared implementation */
        PSHY
        ADDX    2,SP+
#else
        EXG     Y,D
        LEAX    D,X
        EXG     Y,D
#endif
        RTS
  }
}
/*---------------- Signed Long 16x32 bit MULtiplications -----------------------------------------*/
/*
  a_ = (sum(i=0..30, 2^i*a[i])-2^31*a[31])
  a_ = (sum(i=0..15, 2^i*a[i])              + (sum(i=16..30, 2^i*a[i])-2^31*a[31])
     = a_0                                  + a_16
  a_0= (sum(i=0..15, 2^i*a[i])
  a_16=                                       (sum(i=16..30, 2^i*a[i])-2^31*a[31])

  b_ = (sum(i=0..14, 2^i*b[i])-2^15*b[15])

  b_*a_ = b_* (a_0 + a_16)
        = b_* a_0 + b_* a_16
        = b_a_0   + b_a_16
  b_a_0=  b_* a_0

  b_a_16= b_* a_16 : easy to compute. Just 2 signed 16 bit numbers, result shifted by 16 -> use EMULS

  b_a_0=  b_* a_0: harder to compute: signed * unsigned number!
  -> change signed number to unsigned and handle sign separately:

  1. check if b_ < 0. Is so set flag, negate
  2. unsigned multiplication (EMUL)
  3. negate resulting 32 bit number if b_ < 0.

*/
#ifdef __cplusplus
extern "C"
#endif
#pragma NO_FRAME
#pragma NO_ENTRY
#pragma NO_EXIT

void NEAR _LMULS16x32 ( void ) {
  asm {
                       /* D == LOW(arg0) */
                       /* X == HIGH(arg0) */
                       /* Y == arg1 */
        PSHY           /* store arg1 for second multiplication */
        EXG     D,X    /* move high into D */
        EMULS          /* D:Y == HIGH(arg0) * arg1 */
        EXG     X,D    /* store the low word of the multiplication and restore LOW(arg0) */
        LDY     2,SP+  /* reload arg1 (we don't need the high word of the multiplication result) */
        BPL     Positive
#ifdef __HCS12X__
        NEGY           /* negate negative value. Consider result as unsigned. */
#else
        DEY            /* negate: decrement and complement (or complement and increment) */
        EXG D,Y
        COMA
        COMB
#endif
        EMUL           /* D:Y == LOW(arg0) * arg1 */
        EXG Y,X        /* LNEG negates D,X and we have D,Y -> swap X,Y */
        __PIC_JSR(_LNEG) /* negate D,X */
        BRA     AddXY

Positive:
        EMUL           /* D:Y == LOW(arg0) * arg1 */
AddXY:
        EXG     Y,D
        LEAX    D,X
        EXG     Y,D
        RTS
  }
}


/*----------- long division  ---------------------------------------------------

  Parameters:
  - high order word of the dividend in the X register
  - low order word of the dividend in the D register
  - high order word of the divisor on top of the stack
  - low order word of the divisor on the second stack position

  Result :
  - high order word of result in the X-Register
  - low order word of result in the D-Register
  - the Y Register is destroyed
  - the stack arguments are released

q3:q0 := a3:a0 DIV b3:b0;
a3:a0 := a3:a0 MOD b3:b0

<==>

q3:q1 := 0;
IF b3 > 0 THEN
  q0 := a3:a2 DIV b3:b2;
  a3:a2 := a3:a2 MOD b3:b2;
  a3:a0 := a3:a0 - q0 * b1:b0;
  IF a3:a0 < 0 THEN DEC(q0); a3:a0 := a3:a0 + b3:b0 END
ELSIF b2 > 0 THEN
  IF a3:a2 >= b2:b1 THEN
    q1 := a3:a2 DIV b2:b1;
    a3:a2 := a3:a2 MOD b2:b1;
    a3:a1 := a3:a1 - q1 * b0;
    IF a3:a1 < 0 THEN DEC(q1); a3:a1 := a3:a1 + b2:b0 END;
  END;
  q0 := a3:a1 DIV b2:b1;
  a2:a1 := a3:a1 MOD b2:b1; a3 := 0;
  a2:a0 := a2:a0 - q0 * b0;
  IF a2:a0 < 0 THEN DEC(q0); a2:a0 := a2:a0 + b2:b0 END
ELSE
  q3:q2 := a3:a2 DIV b1:b0;
  a3:a2 := a3:a2 MOD b1:b0
  q1:q0 := a3:a0 DIV b1:b0;
  a1:a0 := a3:a0 MOD b1:b0; a3:a2 := 0
END

*/  /*---------------- long division code ------------------------------------------*/
#define stackused 8
/********************************************/

/* #define lDivMod_b0 15, SP */
#define lDivMod_b1 14, SP
#define lDivMod_b2 13, SP
#define lDivMod_b3 12, SP
/* return-address of calling function */
/* #define lDivMod_a0  9, SP */
#define lDivMod_a1  8, SP
#define lDivMod_a2  7, SP
#define lDivMod_a3  6, SP
/* #define lDivMod_q0  5, SP */
#define lDivMod_q1  4, SP
/*lint -esym(750, lDivMod_q2) , the macro is referenced in HLI */
#define lDivMod_q2  3, SP
#define lDivMod_q3  2, SP

/* #define lDivMod_b0_o(off) 15+off, SP */
#define lDivMod_b1_o(off) 14+off, SP
#define lDivMod_b2_o(off) 13+off, SP
#define lDivMod_b3_o(off) 12+off, SP
/* return-address of calling function */
/* #define lDivMod_a0_o(off)  9+off, SP */
#define lDivMod_a1_o(off)  8+off, SP
/*lint -esym(750, lDivMod_a2_o) , the macro is referenced in HLI */
#define lDivMod_a2_o(off)  7+off, SP
#define lDivMod_a3_o(off)  6+off, SP
/* #define lDivMod_q0_o(off)  5+off, SP */
/* #define lDivMod_q1_o(off)  4+off, SP */
/* #define lDivMod_q2_o(off)  3+off, SP */
/* #define lDivMod_q3_o(off)  2+off, SP */


#ifdef __cplusplus
extern "C"
#endif
#pragma NO_FRAME
#pragma NO_ENTRY
#pragma NO_EXIT



void NEAR _lDivMod (void)              /* q = a / b; a = a % b */
{
   asm {
#ifdef __HCS12X__
          CLRW   lDivMod_q3
#else
          CLRA
          CLRB
          STD    lDivMod_q3
#endif
          LDD    lDivMod_b3
          BNE    large_divisor
          LDX    lDivMod_b1          /* divisor is < 2^16 */
          LDY    lDivMod_a3
          LDD    lDivMod_a1
          EDIV
          BVC    res_small_div_ok
          LDD    lDivMod_a3
#ifdef __HCS12X__
          CLRY
#else
          LDY    #0
#endif
          EDIV                       /* q3 = a3 / b1 */
          STY    lDivMod_q3
          TFR    D,Y
          LDD    lDivMod_a1
          EDIV                       /* q1 = (a3%b1):a1 / b1 */
   res_small_div_ok:
          STY    lDivMod_q1
          STD    lDivMod_a1
#ifdef __HCS12X__
          CLRW   lDivMod_a3
#else
          CLRA
          CLRB
          STD    lDivMod_a3
#endif
          RTS
   large_divisor:               /* divisor is >= 2^16 */
          TSTA  
          BEQ    not_very_large_divisor
   very_large_divisor:          /* divisor is >= 2^24 */
          LDX    lDivMod_a3
          EXG    D,X
          LDY    #0
          BRA    lDivMod1
   not_very_large_divisor:      /* divisor is < 2^24 */
          LDX    lDivMod_b2
          LDAB   lDivMod_a3
          LDY    lDivMod_a2
          EXG    D,Y
   lDivMod1: 
          EDIV             
   lDivMod2:   
          PSHY                  
          LDD    lDivMod_b1_o(2)  
          EMUL  
          PSHD  
          PSHY  
          LDD    lDivMod_b3_o(6)  
          LDY    4,SP
          EMUL  
          ADDD   2,SP+
          PULX  
          EXG    D,X
          LDY    #0
          PSHY
          ROL    1,SP
          SUBD   lDivMod_a1_o(4)
          EXG    D,X
#ifdef __HCS12X__
          SBED   lDivMod_a3_o(4)
#else
          SBCB   lDivMod_a2_o(4)
          SBCA   lDivMod_a3_o(4)
#endif
          PULY
          TBEQ   Y,noOverflow
          PSHA
          CLR    1,-SP
          PULY
          PSHB
          PULA          
          PSHX
          PULB                         
          LDX    lDivMod_b2_o(3)
          EDIV
          TFR    Y,X
          PULA
          BRA    lDivMod6
   noOverflow:          
          BCS    lDivMod8
          TBNE   D,lDivMod3       
          TBEQ   X,lDivMod_finish        
   lDivMod3:   
          TST    lDivMod_b3_o(2)  
          BEQ    lDivMod4
          LDX    lDivMod_b3_o(2) 
          CLRA
          CLRB
          BRA    lDivMod5
   lDivMod4:   
          EXG    D,X            
          PSHA  
          PSHX  
          CLR    1,-SP
          LDX    lDivMod_b2_o(6)  
          PULY  
          PULD                                       
   lDivMod5:   
          IDIV                           
   lDivMod6:          
          INX              
          PULD                  
          PSHX  
          SUBD   2,SP+
          TFR    D,Y
          BRA    lDivMod2
   lDivMod7:   
          PULY  
          INY
          BRA    lDivMod2
   lDivMod8:             
          COMA                 
          COMB  
          EXG    D,X
          COMA  
          COMB  
          IBNE   D,lDivMod9
          INX   
   lDivMod9:   
          CPX    lDivMod_b3_o(2)  
          BHI    lDivMod7
          BCS    lDivMod_finish
          CPD    lDivMod_b1_o(2)  
          BCC    lDivMod7
   lDivMod_finish:   
          PULY                   
          STY    lDivMod_q1      /* quotient is < 2^16 */
#ifdef __HCS12X__
          CLRW   lDivMod_q3
#else
          CLR    lDivMod_q2
          CLR    lDivMod_q3
#endif
          STD    lDivMod_a1			 /* remainder goes to a */
          STX    lDivMod_a3
          RTS   
   }
}


/*--------  Long DIVide Unsigned -----------------------------------------------*/

/* D:X = D:X / S[0:1]:S[2:3] */

#ifdef __cplusplus
extern "C"
#endif
#pragma NO_FRAME
#pragma NO_ENTRY
#pragma NO_EXIT

void NEAR _LDIVU ( void ) {
  asm {
        PSHD
        PSHX
        LEAS  -4, SP /* for the result */
        __PIC_JSR(_lDivMod)
        PULX
        LDD   6, SP+
        LDY   6, SP+      /* load return address and release stack arguments */
        JMP   0, Y
  }
}


/*----------------- Long DIVide Signed -----------------------------------------*/

/* Long Negate for division */

#ifdef __cplusplus
extern "C"
#endif
#pragma NO_FRAME
#pragma NO_ENTRY
#pragma NO_EXIT

void NEAR _NEG_P ( void ) {         /* [X:0..X:3]=-[X:0..X:3] */
   asm {
#ifdef __HCS12X__
         COMW   0,X    /* complement high word */
         NEGW   2,X    /* negate low */
         BNE     _SPLIT_0
         INCW   0,X    /* propagate overflow */
_SPLIT_0:
#else
         CLRA
         CLRB          /* load 0 for subtraction */
         PSHD          /* save 0 for reuse       */
         SUBD   2, X
         STD    2, X
         PULD          /* reload 0               */
         SBCB   1, X
         SBCA   0, X
         STD    0, X
#endif
         RTS
   }
}

/* D:X = D:X / S[0:1]:S[2:3] */

#define DS 10  /* divisor */
#define DD  4  /* dividend */
#define QU  0  /* quotient */

/* 10..13 divisor */
/* 08.. 9 return address*/
/*  4.. 7 dividend */
/*  0.. 3 quotient */

#ifdef __cplusplus
extern "C"
#pragma NO_FRAME
#pragma NO_ENTRY
#pragma NO_EXIT

#endif
void NEAR _LDIVS (void) {        /* a = a / b signed */
   asm {
         PSHD
         PSHX
         LEAS  -4, SP /* for the result */

         TST    DS, SP
         BGE    XdP
   XdN:  LEAX   DS, SP
         __PIC_JSR(_NEG_P)   /* X / neg   */
         TST    DD, SP
         BGE    PdN
   NdN:  LEAX   DD, SP
         __PIC_JSR(_NEG_P)   /* neg / neg */
         BRA    PdP

   NdP:  LEAX   DD, SP
         __PIC_JSR(_NEG_P)   /* neg / neg */
   PdN:  __PIC_JSR(_lDivMod)
         LEAX   QU, SP
         __PIC_JSR(_NEG_P)
         BRA    Ret

   XdP:  TST    DD, SP
         BLT    NdP
   PdP:  __PIC_JSR(_lDivMod)
   Ret:  LDD    QU+2, SP
         LDX    QU, SP
   Done: LEAS   8, SP
         LDY    6, SP+      /* load return address and release stack arguments */
         JMP    0, Y
    }
}




/*--------------- Long MODulo Unsigned -----------------------------------------*/

/* D:X = D:X % S[0:1]:S[2:3] */

#ifdef __cplusplus
extern "C"
#endif
#pragma NO_FRAME
#pragma NO_ENTRY
#pragma NO_EXIT

void NEAR _LMODU ( void ) {
  asm {
        PSHD
        PSHX
        LEAS  -4, SP
        __PIC_JSR(_lDivMod)
        LDX   4, SP
        LDD   6, SP
        LEAS  stackused, SP
        LDY    6, SP+      /* load return address and release stack arguments */
        JMP   0, Y
  }
}

/*------------ Long MODulo Signed ----------------------------------------------*/

/* D:X = D:X % S[0:1]:S[2:3] */

#ifdef __cplusplus
extern "C"
#endif
#pragma NO_FRAME
#pragma NO_ENTRY
#pragma NO_EXIT

void NEAR _LMODS ( void )         /* a = a % b signed */
{
   asm {
         PSHD
         PSHX
         LEAS  -4, SP /* for the result  */
         TST    DS, SP
         BGE    XdP       /* X / X       */
   XdN:  LEAX   DS, SP
         __PIC_JSR(_NEG_P)    /* X / neg */
   XdP:  TST    DD, SP
         BGE    PdX
   NdX:  LEAX   DD, SP
         __PIC_JSR(_NEG_P)    /* neg / X */
         __PIC_JSR(_lDivMod)
         LEAX   DD, SP
         __PIC_JSR(_NEG_P)    /* neg / X */
         BRA    Done

   PdX:  __PIC_JSR(_lDivMod)
   Done: LDX   DD, SP
         LDD   DD+2, SP
         LEAS  stackused, SP
         LDY    6, SP+      /* load return address and release stack arguments */
         JMP   0, Y
   }
}

/*------------ sign extend 16->32 bit ------------------------------------------
  Parameters:
  - signed 16-bit value int the D register

  Result :
  - high order word of result in the X-Register
  - low  order word of result in the D-Register
  - the Y Register is still valid
*/

/* D:X = D , Signed */

#ifdef __cplusplus
extern "C"
#endif
#pragma NO_FRAME
#pragma NO_ENTRY
#pragma NO_EXIT

void NEAR _ILSEXT( void ) {
  asm {
        PSHD
        SEX A, D
        SEX A, X
        PULD
        RTS
  }
}

#if 0 /* not used */
/*-------------Test for 0 for long values --------------------------------------
  Parameters:
  - address of long in the X register

  Result :
  - all register remain unchanged
  - all flags set
*/

/* D:Y = D , Signed */

#ifdef __cplusplus
extern "C"
#endif
#pragma NO_FRAME
#pragma NO_ENTRY
#pragma NO_EXIT

void NEAR _LTEST( void ) {
  asm {
        PSHD
        LDD 0, X
        BNE done
        LDD 2, X
  done: PULD
        RTS
  }
}

#endif

/*--------------------------- float operations ---------------------------------*/

/*--------------------------- block copy ---------------------------------------*/
/*

  Parameters:
  - source-address in the X Register
  - destination-address in the Y Register
  - size in D-register, > 0

  Result :
  - X is equal to the old X + size
  - Y is equal to the old Y + size
  - D is 0

  version with word-moves, size > 1
  accesses are aligned when starting-addresses are aligned
*/

/* Y[0..D-1] = X[0..D-1], D > 1 */

#ifdef __cplusplus
extern "C"
#endif
#pragma NO_FRAME
#pragma NO_ENTRY
#pragma NO_EXIT

void NEAR _COPY (void) {
   asm {
#if defined(__OPTIMIZE_FOR_SIZE__)
   loop: MOVB 1, X+, 1, Y+
         DBNE D, loop
#else   /* optimize for time, use two byte accesses */
         LSRD               /* /2 and save bit 0 in the carry */
   loop: MOVW 2, X+ ,2, Y+  /* Word-Move                      */
         DBNE D, loop
         BCC done           /* handle last byte               */
         MOVB 1, X+, 1, Y+
#endif
   done: RTS
   }
}

/*---------------------------  case handling -----------------------------------*/

/*----------------- CASE_DIRECT ------------------------------------------------
branches in a table direct following the call to this library routine

  Parameters:
  - the normalized offset into the jump table is in register D
  - on the stack: address of the jump table

  Result :
  - control is given at the correct code
  - D and X are destroyed.
  - Y remain unchanged

  the return address is set correctly by a simple bsr/jsr

  call example:

  LDD switch_value
  SUBD #first_label
  __PIC_JSR(_CASE_DIRECT)
  WORD &L0
  WORD &L1
  WORD &L2
  L0:  ...
  L1:  ...
  L2:  ...
*/

#ifdef __cplusplus
extern "C"
#endif
#pragma NO_FRAME
#pragma NO_ENTRY
#pragma NO_EXIT

void NEAR _CASE_DIRECT (void) {
  asm {
        ASLD              /* word address scale     */
        PULX              /* load address           */
        LDX  D, X         /* load branch offset     */
        _SRET             /* debug info only: This is the last instr of a function with a special return */
        JMP  0, X         /* jump to selected entry */
  }
}



#ifdef __cplusplus
extern "C"
#endif
#pragma NO_FRAME
#pragma NO_ENTRY
#pragma NO_EXIT

void NEAR _CASE_DIRECT_BYTE (void) {
  asm {
        PULX              /* load address           */
        LDAB D, X         /* load branch offset     */
        _SRET             /* debug info only: This is the last instr of a function with a special return */
        JMP  B, X         /* jump to selected entry */
  }
}

/*----------------- CASE_CHECKED -----------------------------------------------
  Parameters:
  - unsigned jump-index in the D Register
  - table starting at the return address

  Result :
  - Y remains unchanged

    table starts at the return address
       2 bytes: N                    ; number of entries
       2 bytes: AddrD                ; default label
       2 bytes: Addr0                ; jump address for entry 0
       2 bytes: Addr1                ; jump address for entry 1
         ....
       2 bytes: AddrN                ; jump address for entry N
   */

#ifdef __cplusplus
extern "C"
#endif
#pragma NO_FRAME
#pragma NO_ENTRY
#pragma NO_EXIT

void NEAR _CASE_CHECKED (void) {
  asm {
        PULX               /* load address of search table */
        CPD  4, X+         /* compare maximal entry */
        BLO  def           /* branch to a defined label */
        LDD  #-1           /* load offset of default label */
def:    LSLD               /* offset*=2 */
        _SRET              /* debug info only: This is the last instr of a function with a special return */
        JMP  [D, X]        /* jump to selected label */

  }
}


#ifdef __cplusplus
extern "C"
#endif
#pragma NO_FRAME
#pragma NO_ENTRY
#pragma NO_EXIT

void NEAR _CASE_CHECKED_BYTE (void) {
  asm {
        PULX               /* load address */
        PSHB
        CMPB 2, X+         /* compare low byte */
        TBNE A, defa       /* branch if value > 0xff */
        BLO  jump          /* branch if value < #entries */
defa:   LDAB -1, X         /* select default entry, address = X-1 */
        BRA  sum
jump:   LDAB B, X          /* load branch offset */
sum:    LEAX B, X
        PULB
        _SRET              /* debug info only: This is the last instr of a function with a special return */
        JMP  0, X          /* jump to selected entry */
  }
}


/*----------------- CASE_SEARCH ------------------------------------------------
  Parameters:
  - unsigned value in the D Register
  - table starting at the return address

  Result :
  - the Y & D  Register remains unchanged


     table starts at the return address
       valsize:  ValueN               ; upper bound
       addrsize: AddrD                ; default label

       valsize:  Value0               ; case value for entry 0
       addrsize: Addr0                ; jump address for entry 0
       valsize:  Value1               ; case value for entry 1
       addrsize: Addr1                ; jump address for entry 1
         ....
       valsize:  ValueN-1             ; case value for entry N
       addrsize: AddrN-1              ; jump address for entry N

  To keep the search table as small as possible, there are four
  runtime routines for search tables. There is one for each combination
  of byte or word values and byte or word addresses. The byte addresses
  are relative to the start of this entry; the word addresses are absolute.
  The byte value routines are handling also 16-bit selector in
  switches which only have 8-bit case entries.


  name               :   addresses    :  size of values
                     :   (addrsize)   :    (valsize)
_CASE_SEARCH_8       :   2 bytes, abs :    1 byte
_CASE_SEARCH_8_BYTE  :   1 byte, rel  :    1 byte
_CASE_SEARCH         :   2 bytes, abs :    2 bytes
_CASE_SEARCH_BYTE    :   1 byte, rel  :    2 bytes

   */

#ifdef __cplusplus
extern "C"
#endif
#pragma NO_FRAME
#pragma NO_ENTRY
#pragma NO_EXIT

void NEAR _CASE_SEARCH (void) {
  asm {
        LDX  0, SP        /* load address of search table */
        CPD  0, X         /* test to upper bound */
        BHI  found        /* overflow */
search:
        CPD  4, +X        /* test of actual label */
        BHI  search       /* label was too small */
        BEQ  found        /* the right label was found */
        LDX  0, SP        /* the right label was missed, reload table address */
found:  LEAS 2, SP        /* release stack */
        LDX  2, X         /* load destination address */
        _SRET             /* debug info only: This is the last instr of a function with a special return */
        JMP  0, X         /* jump to the selected label */
  }
}

#ifdef __cplusplus
extern "C"
#endif
#pragma NO_FRAME
#pragma NO_ENTRY
#pragma NO_EXIT

void NEAR _CASE_SEARCH_BYTE (void) {
  asm {
        LDX  0, SP        /* load address of search table */
        CPD  0, X         /* test to upper bound */
        BHI  found        /* overflow */
search:
        CPD  3, +X        /* test of actual label */
        BHI  search       /* label was too small */
        BEQ  found        /* the right label was found */
        LDX  0, SP        /* the right label was missed, reload table address */
found:  PSHB              /* save B register */
        LDAB 2, X         /* load offset */
        LEAX B, X         /* calculate dest address */
        LDAB 3, SP+       /* reload B, release stack */
        _SRET             /* debug info only: This is the last instr of a function with a special return */
        JMP  0, X         /* jump to the selected label */
  }
}

#ifdef __cplusplus
extern "C"
#endif
#pragma NO_FRAME
#pragma NO_ENTRY
#pragma NO_EXIT

void NEAR _CASE_SEARCH_8 (void) {
  asm {
        LDX  0, SP         /* load address of table */
        TSTA
        BNE  found         /* jump to default label if D > 256 */
        CMPB 0, X          /* test lowbyte of selector */
        BHI  found         /* branch to default */
search:
        CMPB 3, +X         /* test actual label */
        BHI  search        /* branch to the next entry */
        BEQ  found         /* we found the right entry */
        LDX  0, SP         /* we missed the right entry, so reload the address of the default label */
found:  LEAS 2, SP         /* release stack */
        _SRET              /* debug info only: This is the last instr of a function with a special return */
        JMP  [1, X]        /* jump to the selected label */
  }
}

#ifdef __cplusplus
extern "C"
#endif
#pragma NO_FRAME
#pragma NO_ENTRY
#pragma NO_EXIT

void NEAR _CASE_SEARCH_8_BYTE (void) {
  asm {
        LDX   0, SP     /* load address of table */
        TSTA
        BNE   found     /* jump to default label if D > 256 */
        CMPB  0, X      /* test lowbyte of selector */
        BHI   found
search:
        CMPB  2, +X     /* test actual label */
        BHI   search    /* branch to the next entry */
        BEQ   found     /* we found the right entry */
        LDX   0, SP     /* we missed the right entry, so reload the address of the default label */
found:  PSHB            /* save B register */
        LDAB  1, X      /* load offset */
        LEAX  B, X      /* calculate dest address */
        LDAB  3, SP+    /* reload A, release stack */
        _SRET           /* debug info only: This is the last instr of a function with a special return */
        JMP   0, X      /* jump to the selected label */
  }
}

/*----------------- FAR FUNCTION PTR Call ------------------------------------------------
  Parameters:
  - the normal function parameters according
  - on the stack: address of function to be called

  Result :
  - Function is called with unchanged D & X register
  - Y is changed
  - the function address is removed from the stack before the function call


  Stack layout (in):
    5, SP  : page of function to be called
  3-4, SP  : offset of function to be called
  1-2, SP  : offset of return address
    0, SP  : page of return address
       function ptr to be called (3 bytes)
       return address caller     (3 bytes)
  Idea:
       exchanging function ptr and return address
       because function ptr and return address have the page at different offset a
       complicated transformation must be done
              before        after
      0,SP    page ret  A    page fkt  F
      1,SP    high ret  B    high fkt  D
      2,SP    low  ret  C    low fkt   E
      3,SP    high fkt  D    page ret  A
      4,SP    low fkt   E    high ret  B
      5,SP    page fkt  F    low  ret  C

*/

#pragma NO_FRAME
#pragma NO_ENTRY
#pragma NO_EXIT
#ifdef __cplusplus
extern "C"
#endif

void __far _FCALL(void) {
  asm {
    LDY   1, SP                    /* A B C D E F    Y = B C   ; 2 bytes */
    MOVW  3, SP,  1, SP            /* A D E D E F    Y = B C   ; 4 bytes */
    MOVB  0, SP,  3, SP            /* A D E A E F    Y = B C   ; 4 bytes */
    MOVB  5, SP,  0, SP            /* F D E A E F    Y = B C   ; 4 bytes */
    STY   4, SP                    /* F D E D B C    Y = B C   ; 2 bytes */
                                   /* F D E A B C              ;16 bytes */
    RTC                            /* call function pointer */
  }
}


/*----------------- FAR FUNCTION PTR Compare ------------------------------------------------
  Parameters:
  - page of first address in A, offset of first address in Y
  - page of second argument in B, offset of second argument in X

  Result :
  - the flags are set according to first-second
  - D, X, Y are still unchanged
*/

#pragma NO_FRAME
#pragma NO_ENTRY
#pragma NO_EXIT
#ifdef __cplusplus
extern "C"
#endif

void NEAR _FPCMP(void) {
  asm {
    CBA
    BNE   done
    PSHX
    CPY   2, SP+
  done:
    RTS
  }
}

#ifdef __HCS12X__

/*---------------- Paged pointer arithmetic -----------------------------------
  Parameters:
  - high order byte of the first argument in A
  - low order word of the first argument in X
  - high order byte of the second argument on top of the stack
  - low order word of the second argument on the second stack position

  Result :
  - high order byte of the result in A
  - low order word of the result in X
  - Y is destroyed by the return address
  - the stack arguments are released
*/

/*---------------- Pointer ADD ----------------------------------------------------*/

/* A:X = A:X + SP[0:0]:SP[1:2] */

#ifdef __cplusplus
extern "C"
#endif
#pragma NO_FRAME
#pragma NO_ENTRY
#pragma NO_EXIT

void NEAR _PADD (void) {
  asm {
        ADDX  3, SP
        ADCA  2, SP
        LDY   5, SP+      /* load return address and release stack arguments */
        JMP   0, Y
  }
}


/*---------------- Pointer SUB ----------------------------------------------------*/

/* A:X = A:X - SP[0:0]:SP[1:2] */

#ifdef __cplusplus
extern "C"
#endif
#pragma NO_FRAME
#pragma NO_ENTRY
#pragma NO_EXIT

void NEAR _PSUB (void) {
  asm {
        SUBX  3, SP
        SBCA  2, SP
        LDY   5, SP+      /* load return address and release stack arguments */
        JMP   0, Y
  }
}

/*---------------- Pointer INC ----------------------------------------------------*/

/* A:X = A:X + 1 */

#ifdef __cplusplus
extern "C"
#endif
#pragma NO_FRAME
#pragma NO_ENTRY
#pragma NO_EXIT

void NEAR _PINC ( void ) {
  asm {
        IBNE  X,done
        INCA
  done: RTS
  }
}


/*---------------- Pointer DEC ----------------------------------------------------*/

/* A:X = A:X - 1 */

#ifdef __cplusplus
extern "C"
#endif
#pragma NO_FRAME
#pragma NO_ENTRY
#pragma NO_EXIT

void NEAR _PDEC ( void ) {
  asm {
         SUBX  #1
         SBCA  #0
         RTS
  }
}

#endif

/*----------------- end of code ------------------------------------------------*/
/*lint --e{766} , runtime.sgm is not a regular header file, it contains a CODE_SEG pragma */
