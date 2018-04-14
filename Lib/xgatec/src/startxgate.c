/**********************************************************************
  FILE        : startup.c 
  PURPOSE     : standard startup code
  LANGUAGE    : ANSI-C / HLI
 **********************************************************************/

#include <hidef.h>
#include <startup.h>

/**********************************************************************/
 /* read-only: _startupData is allocated in ROM and
               initialized by the linker */
struct _tagStartup _startupData;
/*--------------------------------------------------------------------*/
static void ZeroOut(_ConstStartupPtr _startupDataPtr) {
/* purpose: zero out RAM-areas where data is allocated.
            ANSI-C requires that global variables (e.g. 'int i;')
            are intialized with zero */
  unsigned int i, j;
  unsigned char *PTR_QUAL dst;
  _RangePtr r;

  r = _startupDataPtr->pZeroOut;
  for (i=_startupDataPtr->nofZeroOuts; i>0U; i--) {
    dst = r->beg;
    j = (unsigned int)r->size;
    do {
      *dst = (unsigned char)'\0'; /* zero out */
      dst++;
      j--;
    } while(j>0U);
    r++;
  }
}
/*--------------------------------------------------------------------*/
#pragma MESSAGE DISABLE C4000 /* INFORMATION C4000: Condition always is TRUE for the alignment below */
#pragma MESSAGE DISABLE C4001 /* INFORMATION C4001: Condition always is FALSE for the alignment below */
static void CopyDown(_ConstStartupPtr _startupDataPtr) {
/* purpose: zero out RAM-areas where data is allocated.
            this intializes global variables with their values,
            e.g. 'int i = 5;' then 'i' is here initialized with '5' */
#if LARGE_SIZE
  unsigned long i;
#else
  unsigned int i;
#endif
  unsigned char *PTR_QUAL dst;
  char *PTR_QUAL ip;

  /* _startupData.toCopyDownBeg  ---> {nof(16) dstAddr(16) {bytes(8)}^nof} Zero(16) */
  /*lint -e{928} , MISRA 11.4 ADV, safe conversion */  
  ip = (char *PTR_QUAL)_startupDataPtr->toCopyDownBeg; 
  while ((*ip != 0U) || (*(ip+1) != 0U)) {
    /*lint -e{927} , MISRA 11.4 ADV, safe conversion */  
    /*lint -e{928} , MISRA 11.4 ADV, safe conversion */
    /*lint -e{826} , deliberate cast from 'char *' to 'int *' */  
    *((char *)&i) = *((char *)&(((_CopyPtr)ip)->size)); /* nof */
    /*lint -e{927} , MISRA 11.4 ADV, safe conversion */  
    /*lint -e{928} , MISRA 11.4 ADV, safe conversion */  
    /*lint -e{826} , deliberate cast from 'char *' to 'int *' */  
    *((char *)&i+1) = *((char *)&(((_CopyPtr)ip)->size)+1); /* nof */
    /*lint -e{927} , MISRA 11.4 ADV, safe conversion */  
    /*lint -e{928} , MISRA 11.4 ADV, safe conversion */  
    /*lint -e{826} , deliberate cast from 'char *' to 'int *' */  
    *((char *)&dst) = *((char *)&(((_CopyPtr)ip)->dest)); /* dstAddr */
    /*lint -e{927} , MISRA 11.4 ADV, safe conversion */  
    /*lint -e{928} , MISRA 11.4 ADV, safe conversion */  
    /*lint -e{826} , deliberate cast from 'char *' to 'int *' */  
    *((char *)&dst+1) = *((char *)&(((_CopyPtr)ip)->dest)+1); /* dstAddr */
    /*lint -e{927} , MISRA 11.4 ADV, safe conversion */  
    /*lint -e{928} , MISRA 11.4 ADV, safe conversion */  
    /*lint -e{826} , deliberate cast from 'char *' to 'int *' */  
    ip = (char *PTR_QUAL)(((_CopyPtr)ip)+1);
    do {
      /* p points now into 'bytes' */
      /*lint -e{926} , MISRA 11.4 ADV, safe conversion */
      *dst = *((unsigned char*PTR_QUAL)ip); /* copy byte-wise */
      dst++;
      /*lint -e{926} , MISRA 11.4 ADV, safe conversion */
      ((char*PTR_QUAL)ip)++;
      i--;
    } while (i>0U);
  }
}
/*--------------------------------------------------------------------*/
/* purpose: C++ requires that the global constructors have to be called
            before main() and the global destructors after main().
            This function is only called for C++ */
#ifdef __ELF_OBJECT_FILE_FORMAT__
static void CallConDestructors(const _Cpp *fctPtr, short i) {
  while (i>0) {
    fctPtr->initFunc(); /* call con/destructor */
    fctPtr++;
    i--;
  }
}
#else
static void CallConDestructors(_mInitPtr fctPtr) {
  if (fctPtr != NULL) {
    while(*fctPtr != NULL) {
      (**fctPtr)(); /* call constructor */
      fctPtr++;
    }
  }
}
#endif
/*--------------------------------------------------------------------*/
static void ProcessStartupDesc(_ConstStartupPtr _startupData, Bool constructing);
/*--------------------------------------------------------------------*/
static void HandleRomLibraries(_ConstStartupPtr _startupDataPtr, Bool constructing) {
  /* purpose: ROM libraries have their own startup functions which 
              have to be called.
              This is only necessary if ROM Libraries are used! */
  _LibInitPtr p;
#ifdef __ELF_OBJECT_FILE_FORMAT__
  unsigned short i;
  
  p = _startupDataPtr->libInits;
  for (i=_startupDataPtr->nofLibInits; i>0U; i--) {
    ProcessStartupDesc(p->startup, constructing);
    p++;
  }
#else
  #pragma MESSAGE DISABLE C1805 /* WARNING C1805: Non standard conversion used */
  p = _startupDataPtr->libInits;
  if (p != NULL) {
    _LibInitStartupPtr pStartup = p->startup;
    
    while (pStartup != (_LibInitStartupPtr)_LIBINIT_STARTUP_SENTINEL) { /* sentinel! */
      ProcessStartupDesc((_StartupPtr)pStartup, constructing);
      p++;
      pStartup = p->startup;
    }
  }
#endif
}
/*--------------------------------------------------------------------*/
static void ProcessStartupDesc(_ConstStartupPtr _startupDataPtr, Bool constructing) {
  if (constructing) {
    ZeroOut(_startupDataPtr);
    CopyDown(_startupDataPtr);
  #ifdef __cplusplus
    #ifdef __ELF_OBJECT_FILE_FORMAT__
      CallConDestructors(_startupDataPtr->initBodies,
                         _startupDataPtr->nofInitBodies);
    #else
      CallConDestructors(_startupDataPtr->mInits);
    #endif
  #endif
    /*lint -estring(960, "Operators '~' and '<<' require recasting to underlying type for sub-integers") , MISRA 10.5 REQ, '<<' applied to an operand of type 'unsigned int' - which is not a sub-integer type */  
    if (!(_startupDataPtr->flags&STARTUP_FLAGS_ROM_LIB)) {
    /*lint +estring(960, "Operators '~' and '<<' require recasting to underlying type for sub-integers") */  
      /* if the application contains ROM libraries, then the 'main' application does NOT
         have the STARTUP_FLAGS_ROM_LIB set. However, the ROM libraries itself have it set */
      HandleRomLibraries(_startupDataPtr, TRUE);
    }
#ifdef __ELF_OBJECT_FILE_FORMAT__
  } else {
    CallConDestructors(_startupDataPtr->finiBodies,
                       (short)_startupDataPtr->nofFiniBodies);  
    /*lint -estring(960, "Operators '~' and '<<' require recasting to underlying type for sub-integers") , MISRA 10.5 REQ, '<<' applied to an operand of type 'unsigned int' - which is not a sub-integer type */  
    if (_startupDataPtr->flags&STARTUP_FLAGS_ROM_LIB) {
    /*lint +estring(960, "Operators '~' and '<<' require recasting to underlying type for sub-integers") */  
      HandleRomLibraries(_startupDataPtr, FALSE);
    }
#endif
  }
}
/*--------------------------------------------------------------------*/
static void Start(void) {
  ProcessStartupDesc(&_startupData, TRUE);
  (*_startupData.main)(); /* call main function */
#if defined(__cplusplus) && defined(__ELF_OBJECT_FILE_FORMAT__)
  ProcessStartupDesc(&_startupData, FALSE); /* call global destructors */
#endif
}
/*--------------------------------------------------------------------*/
#pragma NO_EXIT  /* this function never returns */
#pragma NO_FRAME /* do not use local variables here, because SP is not set! */
#ifdef __cplusplus
  extern "C"
#endif
 /* To set in the linker parameter file: 'VECTOR 0 _Startup' */
#ifdef __HC11__
  void NEAR _Startup (void) {
#else
  void _Startup (void) {
#endif
#ifdef __ELF_OBJECT_FILE_FORMAT__
  DisableInterrupts  /* in HIWARE format, this is done in _PRESTART code */
#endif
  for (;;) { /* forever: initialize the program; call the root-procedure */
    asm {
      /* put your target specific initialisation (e.g. CHIP SELECTS) here */
    }
#ifdef INIT_SP_FROM_STARTUP_DESC
    if (!(_startupData.flags&STARTUP_FLAGS_NOT_INIT_SP)) {
      /* initialize the stack pointer */
      INIT_SP_FROM_STARTUP_DESC(); /* HLI macro definition in hidef.h */
    }
#endif
    Start();
  } /* end loop forever */
}
/*--------------------------------------------------------------------*/

/*lint -esym(754, pc) , struct Entry is used within this module */
/*lint -esym(754, dataptr) , struct Entry is used within this module */
typedef struct {
  void (*pc)(void);
  int dataptr;
} Entry;

#pragma CONST_SEG X_Vectors
const Entry vectors[0x80] = {
                  /* Channel # = Vector address / 2 */
  {_Startup, 0},  /* Channel 00 - Reserved */
  {_Startup, 0},  /* Channel 01 - Reserved */
  {_Startup, 0},  /* Channel 02 - Reserved */
  {_Startup, 0},  /* Channel 03 - Reserved */
  {_Startup, 0},  /* Channel 04 - Reserved */
  {_Startup, 0},  /* Channel 05 - Reserved */
  {_Startup, 0},  /* Channel 06 - Reserved */
  {_Startup, 0},  /* Channel 07 - Reserved */
  {_Startup, 0},  /* Channel 08 - Spurious Interrupt */
  {_Startup, 0},  /* Channel 09 - Reserved */
  {_Startup, 0},  /* Channel 0A - Reserved */
  {_Startup, 0},  /* Channel 0B - Reserved */
  {_Startup, 0},  /* Channel 0C - Reserved */
  {_Startup, 0},  /* Channel 0D - Reserved */
  {_Startup, 0},  /* Channel 0E - Reserved */
  {_Startup, 0},  /* Channel 0F - Reserved */
  {_Startup, 0},  /* Channel 10 - Reserved */
  {_Startup, 0},  /* Channel 11 - Reserved */
  {_Startup, 0},  /* Channel 12 - Reserved */
  {_Startup, 0},  /* Channel 13 - Reserved */
  {_Startup, 0},  /* Channel 14 - Reserved */
  {_Startup, 0},  /* Channel 15 - Reserved */
  {_Startup, 0},  /* Channel 16 - Reserved */
  {_Startup, 0},  /* Channel 17 - Reserved */
  {_Startup, 0},  /* Channel 18 - Reserved */
  {_Startup, 0},  /* Channel 19 - Reserved */
  {_Startup, 0},  /* Channel 1A - Reserved */
  {_Startup, 0},  /* Channel 1B - Reserved */
  {_Startup, 0},  /* Channel 1C - Reserved */
  {_Startup, 0},  /* Channel 1D - Reserved */
  {_Startup, 0},  /* Channel 1E - Reserved */
  {_Startup, 0},  /* Channel 1F - Reserved */
  {_Startup, 0},  /* Channel 20 - Reserved */
  {_Startup, 0},  /* Channel 21 - Reserved */
  {_Startup, 0},  /* Channel 22 - Reserved */
  {_Startup, 0},  /* Channel 23 - Reserved */
  {_Startup, 0},  /* Channel 24 - Reserved */
  {_Startup, 0},  /* Channel 25 - Reserved */
  {_Startup, 0},  /* Channel 26 - Reserved */
  {_Startup, 0},  /* Channel 27 - Reserved */
  {_Startup, 0},  /* Channel 28 - Reserved */
  {_Startup, 0},  /* Channel 29 - Reserved */
  {_Startup, 0},  /* Channel 2A - Reserved */
  {_Startup, 0},  /* Channel 2B - Reserved */
  {_Startup, 0},  /* Channel 2C - Reserved */
  {_Startup, 0},  /* Channel 2D - Reserved */
  {_Startup, 0},  /* Channel 2E - Reserved */
  {_Startup, 0},  /* Channel 2F - Reserved */
  {_Startup, 0},  /* Channel 30 - XSRAM20K Access Violation */
  {_Startup, 0},  /* Channel 31 - XGATE Software Error Interrupt      */
  {_Startup, 0},  /* Channel 32 - XGATE Software Trigger 7            */
  {_Startup, 0},  /* Channel 33 - XGATE Software Trigger 6            */
  {_Startup, 0},  /* Channel 34 - XGATE Software Trigger 5            */
  {_Startup, 0},  /* Channel 35 - XGATE Software Trigger 4            */
  {_Startup, 0},  /* Channel 36 - XGATE Software Trigger 3            */
  {_Startup, 0},  /* Channel 37 - XGATE Software Trigger 2            */
  {_Startup, 0},  /* Channel 38 - XGATE Software Trigger 1            */
  {_Startup, 0},  /* Channel 39 - XGATE Software Trigger 0            */
  {_Startup, 0},  /* Channel 3A - Periodic Interrupt Timer            */
  {_Startup, 0},  /* Channel 3B - Periodic Interrupt Timer            */
  {_Startup, 0},  /* Channel 3C - Periodic Interrupt Timer            */
  {_Startup, 0},  /* Channel 3D - Periodic Interrupt Timer            */
  {_Startup, 0},  /* Channel 3E - Reserved                            */
  {_Startup, 0},  /* Channel 3F - Autonomous Periodical interrupt API */
  {_Startup, 0},  /* Channel 40 - Low Voltage interrupt LVI */
  {_Startup, 0},  /* Channel 41 - IIC1 Bus                  */
  {_Startup, 0},  /* Channel 42 - SCI5                      */
  {_Startup, 0},  /* Channel 43 - SCI4                      */
  {_Startup, 0},  /* Channel 44 - SCI3                      */
  {_Startup, 0},  /* Channel 45 - SCI2                      */
  {_Startup, 0},  /* Channel 46 - PWM Emergency Shutdown    */
  {_Startup, 0},  /* Channel 47 - Port P Interrupt          */
  {_Startup, 0},  /* Channel 48 - CAN4 transmit             */
  {_Startup, 0},  /* Channel 49 - CAN4 receive              */
  {_Startup, 0},  /* Channel 4A - CAN4 errors               */
  {_Startup, 0},  /* Channel 4B - CAN4 wake-up              */
  {_Startup, 0},  /* Channel 4C - CAN3 transmit             */
  {_Startup, 0},  /* Channel 4D - CAN3 receive              */
  {_Startup, 0},  /* Channel 4E - CAN3 errors               */
  {_Startup, 0},  /* Channel 4F - CAN3 wake-up              */
  {_Startup, 0},  /* Channel 50 - CAN2 transmit */
  {_Startup, 0},  /* Channel 51 - CAN2 receive  */
  {_Startup, 0},  /* Channel 52 - CAN2 errors   */
  {_Startup, 0},  /* Channel 53 - CAN2 wake-up  */
  {_Startup, 0},  /* Channel 54 - CAN1 transmit */
  {_Startup, 0},  /* Channel 55 - CAN1 receive  */
  {_Startup, 0},  /* Channel 56 - CAN1 errors   */
  {_Startup, 0},  /* Channel 57 - CAN1 wake-up  */
  {_Startup, 0},  /* Channel 58 - CAN0 transmit */
  {_Startup, 0},  /* Channel 59 - CAN0 receive  */
  {_Startup, 0},  /* Channel 5A - CAN0 errors   */
  {_Startup, 0},  /* Channel 5B - CAN0 wake-up  */
  {_Startup, 0},  /* Channel 5C - FLASH  */
  {_Startup, 0},  /* Channel 5D - EEPROM */
  {_Startup, 0},  /* Channel 5E - SPI2   */
  {_Startup, 0},  /* Channel 5F - SPI1 */
  {_Startup, 0},  /* Channel 60 - IIC0 Bus                          */
  {_Startup, 0},  /* Channel 61 - Reserved                          */
  {_Startup, 0},  /* Channel 62 - CRG Self Clock Mode               */
  {_Startup, 0},  /* Channel 63 - CRG PLL lock                      */
  {_Startup, 0},  /* Channel 64 - Pulse Accumulator B Overflow      */
  {_Startup, 0},  /* Channel 65 - Modulus Down Counter underflow    */
  {_Startup, 0},  /* Channel 66 - Port H                            */
  {_Startup, 0},  /* Channel 67 - Port J                            */
  {_Startup, 0},  /* Channel 68 - ATD1                              */
  {_Startup, 0},  /* Channel 69 - ATD0                              */
  {_Startup, 0},  /* Channel 6A - SCI1                              */
  {_Startup, 0},  /* Channel 6B - SCI0                              */
  {_Startup, 0},  /* Channel 6C - SPI0                              */
  {_Startup, 0},  /* Channel 6D - Pulse accumulator input edge      */
  {_Startup, 0},  /* Channel 6E - Pulse accumulator A overflow      */
  {_Startup, 0},  /* Channel 6F - Enhanced Capture Timer overflow   */
  {_Startup, 0},  /* Channel 70 - Enhanced Capture Timer channel 7  */
  {_Startup, 0},  /* Channel 71 - Enhanced Capture Timer channel 6  */
  {_Startup, 0},  /* Channel 72 - Enhanced Capture Timer channel 5  */
  {_Startup, 0},  /* Channel 73 - Enhanced Capture Timer channel 4  */
  {_Startup, 0},  /* Channel 74 - Enhanced Capture Timer channel 3  */
  {_Startup, 0},  /* Channel 75 - Enhanced Capture Timer channel 2  */
  {_Startup, 0},  /* Channel 76 - Enhanced Capture Timer channel 1  */
  {_Startup, 0},  /* Channel 77 - Enhanced Capture Timer channel 0  */
  {_Startup, 0},  /* Channel 78 - Real Time Interrupt  */
  {_Startup, 0},  /* Channel 79 - Reserved */
  {_Startup, 0},  /* Channel 7A - Reserved */
  {_Startup, 0},  /* Channel 7B - Reserved */
  {_Startup, 0},  /* Channel 7C - Reserved */
  {_Startup, 0},  /* Channel 7D - Reserved */
  {_Startup, 0},  /* Channel 7E - Reserved */
  {_Startup, 0},  /* Channel 7F - Reserved   */
};

