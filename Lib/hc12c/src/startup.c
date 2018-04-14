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
      *dst = (unsigned char *PTR_QUAL)'\0'; /* zero out */
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
  int *PTR_QUAL ip;

  /* _startupData.toCopyDownBeg  ---> {nof(16) dstAddr(16) {bytes(8)}^nof} Zero(16) */
  /*lint -e{929} , MISRA 11.4 ADV, safe conversion (same pointer representation) */
  /*lint -e{740} , MISRA 1.2 REQ, safe conversion (same pointer representation) */
  ip = (int *PTR_QUAL)_startupDataPtr->toCopyDownBeg;
  while (*ip != 0) {
#if LARGE_SIZE
    i = (unsigned long)((_CopyPtr)ip)->size; /* nof */
#else
    /*lint -e{929} , MISRA 11.4 ADV, safe conversion (same pointer representation) */
    /*lint -e{740} , MISRA 1.2 REQ, safe conversion (same pointer representation) */
    /*lint -e{826} , MISRA 1.2 REQ, safe conversion (same pointer representation) */
    i = (unsigned int)((_CopyPtr)ip)->size; /* nof */
#endif
    /*lint -e{929} , MISRA 11.4 ADV, safe conversion (same pointer representation) */
    /*lint -e{740} , MISRA 1.2 REQ, safe conversion (same pointer representation) */
    /*lint -e{826} , MISRA 1.2 REQ, safe conversion (same pointer representation) */
    dst = ((_CopyPtr)ip)->dest; /* dstAddr */
    /*lint -e{929} , MISRA 11.4 ADV, safe conversion (same pointer representation) */
    /*lint -e{740} , MISRA 1.2 REQ, safe conversion (same pointer representation) */
    /*lint -e{826} , MISRA 1.2 REQ, safe conversion (same pointer representation) */
    ip = (int *PTR_QUAL)(((_CopyPtr)ip)+1);
    do {
      /* p points now into 'bytes' */
      /*lint -e{928} , MISRA 11.4 ADV, safe conversion */
      *dst = *((unsigned char*PTR_QUAL)ip); /* copy byte-wise */
      dst++;
      /*lint -e{928} , MISRA 11.4 ADV, safe conversion */
      ((char*PTR_QUAL)ip)++;
      i--;
    } while (i>0U);
#if !defined(__HIWARE__)
    /* we assume that int are 4byte aligned */
      ip = (int*PTR_QUAL)(((long)ip + 4-1) & ~(4-1));
#else
    /*lint -e{506} , MISRA 13.7 REQ & 14.1 REQ , alignment is architecture-dependent */
    /*lint -e{774} , alignment is architecture-dependent */
    if (__alignof__(int) >= 2U) { /* we need aligned integers */
      /*lint -e{511} , deliberate truncation */
      /*lint -e{923} , MISRA 11.3 ADV, deliberate cast from pointer to long */
      ip = (int*PTR_QUAL)((((unsigned long)ip + __alignof__(int))-1UL) & ~(__alignof__(int)-1UL));
    }
#endif
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
    /*lint -estring(960, "Operators '~' and '<<' require recasting to underlying type for sub-integers") , MISRA 10.5 REQ, '<<' applied to an operand of type 'unsigned int' - which is not a sub-integer type */  
    if (!(_startupData.flags&STARTUP_FLAGS_NOT_INIT_SP)) {
    /*lint +estring(960, "Operators '~' and '<<' require recasting to underlying type for sub-integers") */ 
      /* initialize the stack pointer */
      INIT_SP_FROM_STARTUP_DESC() /* HLI macro definition in hidef.h */
    }
    Start();
  } /* end loop forever */
}
/*--------------------------------------------------------------------*/

