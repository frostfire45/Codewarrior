/******************************************************************************
  FILE        : codepage.c
  PURPOSE     : paged code access runtime routines
  MACHINE     : Freescale 68HC12 (Target)
  LANGUAGE    : ANSI-C
******************************************************************************/

/*
   With the -^b option, the compiler generates calls to the runtime routines
   below instead of the CALL instruction.
*/

#include "hidef.h"
#include "non_bank.sgm"
#include "runtime.sgm"


#define DG128
/* Compile with option -DDG128 to activate this code */

#ifdef DG128
  /* HC12 DG128 derivative has page register at 0xff and only P page */
#define REGISTER_BASE 0
#define PPAGE_ADDR        (0xFF+REGISTER_BASE)
#define KPORT_ADDR        (0xFC+REGISTER_BASE)
#define KPORT_MASK  0xFF /* 0x80 */
#endif

/*--------------------------- _CALL_ABS_SPEC --------------------------------
  Runtime routine to call a function with the banked memory model
  The address of the function to be called is just where the return address points
  to in the code of the calling function.
  it uses the following format:

  JSR _CALL_ABS_SPEC
  DC.W fun_to_be_called
  DC.B page(fun_to_be_called)
ret:

  The _CALL_ABS_SPEC function should call fun_to_be_called and after this function returns,
  go back to ret.

  Result :
  The function to be called is called, with 4 additional bytes on the stack.
  The D & X register are unmodified at the call time.
  When this function returns, the control goes back 3 bytes after the address from which
  this function does usually return.
  The X and D register are passed through.

  --------------------------- _CALL_ABS_SPEC ----------------------------------*/


#ifdef __cplusplus
extern "C"
#endif
#pragma NO_ENTRY
#pragma NO_EXIT
#pragma NO_FRAME

void _CALL_ABS_SPEC(void) {
#if (KPORT_MASK & 0xff) == 0xff
  /* we do not have to mask some bytes from the page */
  /* so we do not need a 8 bit register */
  asm {
       MOVB KPORT_ADDR, 1,-SP ; PUSH the content of port K (0xFC)
       LDY  1,SP              ; load return address
       MOVB 2,Y, KPORT_ADDR   ; Set PORTK with the new page
       CALL  [0,Y]            ; call the function
       MOVB  1,SP+,KPORT_ADDR ; restore the old value of port K
       PULY                   ; load RA
     _SRET
       JMP  3,Y
  }
#else
  asm {
       PSHD
       LDAA KPORT_ADDR        ; Load A with content of port K (0xFC)
#if 0  /* necessary to mask old KPORT ? */
       ANDA #KPORT_MASK       ; Mask all bits except PK3 in PORTK
#endif
       STAA 1,SP              ; save it on the stack
       LDY  2,SP              ; load return address
       LDAA 2,Y               ; Load B with the page number of the function
       ANDA #KPORT_MASK       ; Mask all bits except PK3 in PORTK
       STAA KPORT_ADDR  ; Set bit PK3 in PORTK according to page number
       PULA                   ; (= 0 for page 0-7, = 1 for page 8-15)
       CALL  [0,Y]            ; call the function
       MOVB  1,SP+,KPORT_ADDR ; restore the old value of port K
       PULY                   ; load RA
     _SRET
       JMP  3,Y
  }
#endif
}

/*--------------------------- _CALL_PTR_SPEC --------------------------------
  Runtime routine to call a function with the banked memory model,
  The function to be called is not known at compile time (usually a function pointer call).
  The address of the function to be called is just above the return address on the stack.
  it uses the following format:

  LDAA #PAGE(fun_to_be_called)
  PSHA
  LDD fun_to_be_called
  PSHD
  LDD #param
  LDX #param
  JSR _CALL_ABS_SPEC
ret:

  The _CALL_ABS_SPEC function should call fun_to_be_called and after this function returns,
  go back to ret.

  Arguments :

  The function to be called is called, with 4 additional bytes on the stack.
  The D & X register are unmodified at the call time.
  When this function returns, the control goes back 3 bytes after the address from which
  this function does usually return.
  The X and D register are passed through.

  --------------------------- _CALL_PTR_SPEC ----------------------------------*/

#ifdef __cplusplus
extern "C"
#endif
#pragma NO_ENTRY
#pragma NO_EXIT
#pragma NO_FRAME

void _CALL_PTR_SPEC(void) {
#if (KPORT_MASK & 0xff) == 0xff
  asm {
       LDY   2,SP           ; load destination address
       PSHB                 ; save B register
       LDAB  KPORT_ADDR     ; load content of old KPORT register
       ANDB  #KPORT_MASK    ; mask unused bits
       ORAB  PPAGE_ADDR     ; add PPAGE bits
       STAB  3,SP           ; save it
       LDAB  5,SP           ; get new page
       STAB  PPAGE_ADDR     ; set PPAGE
       ANDB  #KPORT_MASK    ; mask unused bits
       STAB  KPORT_ADDR     ; set KPORT
       PULB                 ; restore B register
#if 1
       MOVW  0,SP, 3,SP     ; move return address
       LEAS  2,SP           ; free area of return address
#else
       MOVW  2,SP+,1,SP     ; move return address and free. Is it legal to access, change and access the new SP in one instruction?
#endif
       BSR   retu           ; call label to push the current PC
       MOVB  0,SP, KPORT_ADDR ; restore old KPORT
       RTC

retu:  PSHB                 ; this byte is used the the RTC of the called function as page
                            ; but because we are setting PPAGE after the return anyway, its value does not matter
       JMP  0,Y
  }
#else
  asm {
       LDY   2,SP           ; load destination address
       PSHB                 ; save B register
       LDAB  KPORT_ADDR     ; load content of old KPORT register
       ORAB  PPAGE_ADDR     ; add PPAGE bits
       STAB  3,SP           ; save it
       LDAB  5,SP           ; get new page
       STAB  PPAGE_ADDR     ; set PPAGE
       ANDB  #KPORT_MASK    ; mask unused bits
       STAB  KPORT_ADDR     ; set KPORT
       PULB                 ; restore B register
#if 1
       MOVW  0,SP, 3,SP     ; move return address
       LEAS  2,SP           ; free area of return address
#else
       MOVW  2,SP+,1,SP     ; move return address and free. Is it legal to access, change and access the new SP in one instruction?
#endif
       BSR   retu           ; call label to push the current PC
       PSHB
       LDAB  1,SP
       ANDB  #KPORT_MASK    ; mask unused bits
       STAB KPORT_ADDR
       PULB
       RTC

retu:  PSHB                 ; this byte is used the the RTC of the called function as page
                            ; but because we are setting PPAGE after the return anyway, its value does not matter
       JMP  0,Y
  }
#endif
}
