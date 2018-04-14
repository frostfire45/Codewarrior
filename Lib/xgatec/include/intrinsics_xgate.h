/*****************************************************
 intrinsics_xgate.h - 
              prototypes for XGATE-C compiler 
              known built-in functions
 ----------------------------------------------------
 Copyright (c) Metrowerks, Basel, Switzerland
               All rights reserved
                  Do not modify!
 *****************************************************/

#ifndef _H_INTRINSICS_XGATE_
#define _H_INTRINSICS_XGATE_

#ifdef __cplusplus  /* C name mangling in C++ */
extern "C" {
#endif

#if defined(__XGATE__) && defined(__HIWARE__) /* intrinsics known by the Metrowerks/Hiware XGATE compiler */

/* Semaphore handling.
   use of HW semaphore to control the concurrent access to
   a resource from the HCS12X and the XGATE. XGATE side.
   short example:
   
   while (!_ssem(1)) { }
   ..use resource protected by semaphore
   _csem(1);
*/

/* set XGATE semaphore */
/* implemented with the SSEM instruction */
int _ssem(unsigned int sem);

/* clear XGATE semaphore */
/* implemented with the CSEM instruction */
void _csem(unsigned int sem);


/* Mathematical intrinsics.
   Used to perform some calculations especially
   efficient on the XGATE architecture.
   short example:
   
   int bits= ...;
   int firstOne= _bffo(bits); 
*/

/* calculate parity */
/* implemented with the PAR instruction */
unsigned int _par(unsigned int);

/* find first one */
/* implemented with the BFFO instruction */
int _bffo(unsigned int);

/* rotate left */
/* implemented with the ROL instruction */
unsigned int _rol(unsigned int val, unsigned int cnt);

/* rotate right */
/* implemented with the ROR instruction */
unsigned int _ror(unsigned int val, unsigned int cnt);

/* Flag handling.
	 Used to check hardware supported flags not otherwise accessible from C.
   short example:
   
   int bits= ...;
   int firstOne= _bffo(bits);
   if (_carry()) {... 
*/
	 

/* check carry flag */
/* usually used in conditions. Then implemented with the BCC/BCS instructions */
/* when used in a expression, implemented with a ADC RX,R0,R0 instruction */
unsigned int _carry(void);

/* check overflow flag */
/* must be used in conditions. They are implemented with the BVC/BVS instructions */
unsigned int _ovfl(void);

/* Interrupt signaling.
   The XGATE core can raise any of the HCS12X interrupts:
   This might indicate that some data for the HCS12X are ready or any other 
   topic which should be handled by the HCS12X.
   
   if (receiveError) {
     _sif(HCS12_RECEIVE_ERROR_INTERRUPT);
   }  
*/

/* signal current interrupt flag. Forwards the interrupt just being handled to the HCS12X */
/* implemented with the SIF instruction */
void _sif(void);

/* signal interrupt flag with channel number argument. Forwards a specified interrupt to the HCS12X */
/* implemented with the SIF instruction with argument */
void _sif1(int chan);

#endif /* defined(__XGATE__) && defined(__HIWARE__) */

#ifdef __cplusplus
}
#endif

#endif /* _H_INTRINSICS_XGATE_ */
