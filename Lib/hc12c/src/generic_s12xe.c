
#include <generic_s12xe.h>

volatile IVBRSTR _IVBR;                                    /* Interrupt Vector Base Register; 0x00000121 */
volatile INT_XGPRIOSTR _INT_XGPRIO;                        /* XGATE Interrupt Priority Configuration Register; 0x00000126 */
volatile INT_CFADDRSTR _INT_CFADDR;                        /* Interrupt Configuration Address Register; 0x00000127 */
volatile INT_CFDATA0STR _INT_CFDATA0;                      /* Interrupt Configuration Data Register 0; 0x00000128 */
volatile INT_CFDATA1STR _INT_CFDATA1;                      /* Interrupt Configuration Data Register 1; 0x00000129 */
volatile INT_CFDATA2STR _INT_CFDATA2;                      /* Interrupt Configuration Data Register 2; 0x0000012A */
volatile INT_CFDATA3STR _INT_CFDATA3;                      /* Interrupt Configuration Data Register 3; 0x0000012B */
volatile INT_CFDATA4STR _INT_CFDATA4;                      /* Interrupt Configuration Data Register 4; 0x0000012C */
volatile INT_CFDATA5STR _INT_CFDATA5;                      /* Interrupt Configuration Data Register 5; 0x0000012D */
volatile INT_CFDATA6STR _INT_CFDATA6;                      /* Interrupt Configuration Data Register 6; 0x0000012E */
volatile INT_CFDATA7STR _INT_CFDATA7;                      /* Interrupt Configuration Data Register 7; 0x0000012F */

volatile XGCHIDSTR _XGCHID;                                /* XGATE Channel ID Register; 0x00000382 */
volatile XGMCTLSTR _XGMCTL;                                /* XGATE Module Control Register; 0x00000380 */
volatile byte _XGCHPL;                                     /* XGATE Channel XGATE Channel Priority Level (XGCHPL); 0x00000383 */
volatile byte XGISPSEL;                                    /* XGATE Initial Stack Pointer Select Register (XGISPSEL); 0x00000385 */
volatile XGVBRSTR _XGVBR;                                  /* XGATE Vector Base Address Register; 0x00000386 */
volatile XGIF0STR _XGIF0;                                  /* XGATE Channel Interrupt Flag Vector 0; 0x00000388 */
volatile XGIF1STR _XGIF1;                                  /* XGATE Channel Interrupt Flag Vector 1; 0x0000038A */
volatile XGIF2STR _XGIF2;                                  /* XGATE Channel Interrupt Flag Vector 2; 0x0000038C */
volatile XGIF3STR _XGIF3;                                  /* XGATE Channel Interrupt Flag Vector 3; 0x0000038E */
volatile XGIF4STR _XGIF4;                                  /* XGATE Channel Interrupt Flag Vector 4; 0x00000390 */
volatile XGIF5STR _XGIF5;                                  /* XGATE Channel Interrupt Flag Vector 5; 0x00000392 */
volatile XGIF6STR _XGIF6;                                  /* XGATE Channel Interrupt Flag Vector 6; 0x00000394 */
volatile XGIF7STR _XGIF7;                                  /* XGATE Channel Interrupt Flag Vector 7; 0x00000396 */
volatile XGSWTSTR _XGSWT;                                  /* XGATE Software Trigger Register; 0x00000398 */
volatile XGSEMSTR _XGSEM;                                  /* XGATE Semaphore Register; 0x0000039A */
volatile XGPCSTR _XGPC;                                    /* XGATE Program Counter Register; 0x0000039E */
volatile XGR1STR _XGR1;                                    /* XGATE Register 1; 0x000003A2 */
volatile XGR2STR _XGR2;                                    /* XGATE Register 2; 0x000003A4 */
volatile XGR3STR _XGR3;                                    /* XGATE Register 3; 0x000003A6 */
volatile XGR4STR _XGR4;                                    /* XGATE Register 4; 0x000003A8 */
volatile XGR5STR _XGR5;                                    /* XGATE Register 5; 0x000003AA */
volatile XGR6STR _XGR6;                                    /* XGATE Register 6; 0x000003AC */
volatile XGR7STR _XGR7;                                    /* XGATE Register 7; 0x000003AE */
