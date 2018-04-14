/*****************************************************
      setjmp.c - ANSI-C library: non-local jumps
 ----------------------------------------------------
   Copyright (c) Metrowerks, Basel, Switzerland
               All rights reserved
                  Do not modify!
 *****************************************************/


#include "setjmp.h"
#include "hidef.h"

#ifdef __LARGE__
/*lint -e451 non_bank.sgm is not a regular header files, it contains a CODE_SEG pragma */
#include "non_bank.sgm"
/*lint +e451 */

/*lint -esym(752, _SET_PAGE) , symbol '_SET_PAGE' is used in HLI */
void NEAR _SET_PAGE(void);

#endif

#pragma MESSAGE DISABLE C5703 /* env: parameter declared in function _setjmp but not referenced */
#pragma NO_ENTRY
#pragma NO_FRAME

int __LONGJMP_FAR _setjmp (jmp_buf env) {
  /* IN:  D points to env */
  /* STACK:  0,SP  return address */
   asm {
#if defined( __LARGE__) && defined(__HCS12X__)
       STAB   __GPAGE_ADR__
       GSTS   0,X      ; store stack pointer into env.sp
       LDD    0,SP     ; load PC from stack (return address)
       GSTD   2,X      ; store PC
       LDAA   2,SP     ; load page from stack (return address)
       GSTAA  4,X      ; store page
#else

#if defined( __LARGE__) && defined(__HC12__)
       TFR   X,Y
       __PIC_JSR(_SET_PAGE)
#else
       TFR   D,X
#endif
       STS   0,X       ; store stack pointer into env.sp
       LDD   0,SP      ; load PC from stack (return address)
       STD   2,X       ; store PC
#if defined( __BANKED__) || defined(__LARGE__)
       LDAA   2,SP     ; load page from stack (return address)
       STAA   4,X      ; store page
#endif
#endif /* defined( __LARGE__) && defined(__HCS12X__) */
   }

   return 0;
} /*lint !e715 !e818 , MISRA 16.7 ADV, this function contains HLI only */

#pragma MESSAGE DISABLE C12053 /* Stack-pointer change not in debugging-information */

#pragma NO_ENTRY
#pragma NO_FRAME
void __LONGJMP_FAR  longjmp (jmp_buf env, int val) {
  /* IN: D contains val
     STACK:  0,SP  return address
             2,SP  pointer to env  */
   asm {
#if defined( __LARGE__) && defined(__HCS12X__)
       PSHB
       LDAB  env:0+1
       LDY   env:1+1    ; pointer to env
       STAB  __GPAGE_ADR__
       PULB
       GLDX  2,Y        ; load PC
       GLDS  0,Y        ; load SP
       PSHA
       GLDAA 4,Y
       STAA  3,SP
       PULA
       STX   0,SP       ; save PC on stack
       TBNE  D,L1       ; make sure the return
       ADDD  #1         ; value is not zero
     L1:

#else

#ifdef __LARGE__
       PSHB
       LDAB  env:0+1
       LDY   env:1+1    ; pointer to env
       __PIC_JSR(_SET_PAGE)
       PULB
#else
       LDY   env        ; pointer to env
#endif
       LDX   2,Y        ; load PC
       LDS   0,Y        ; load SP
#if defined( __BANKED__) || defined(__LARGE__)
       MOVB  4,Y, 2,SP
#endif
       STX   0,SP       ; save PC on stack
       TBNE  D,L1       ; make sure the return
       ADDD  #1         ; value is not zero
     L1:
#endif /* defined( __LARGE__) && defined(__HCS12X__) */
   }
} /*lint !e715 !e818 , MISRA 16.7 ADV, this function contains HLI only */
/*lint --e{766} hidef.h is used in HLI */
