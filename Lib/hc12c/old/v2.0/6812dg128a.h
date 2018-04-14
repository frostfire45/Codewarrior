/*****************************************************
    6812dg128a.h - Target interface library
    Describes I/O registers of MC68HC12DG128A
 ----------------------------------------------------
   Copyright (c) Metrowerks, Basel, Switzerland
                  Do not modify!
 *****************************************************/



/****************************************!! WARNINGS !!*********************************************/
/*      1)PORT A, PORT B, and data direction registers DDRA and DDRB are not in map in expanded    */
/*      and peripheral modes                                                                       */
/*      2)PORT E and DDRE not in map in peripheral mode; also not in map in expanded modes with    */
/*      EME set.                                                                                   */
/*      3)Registers also not in map in peripheral mode.                                            */
/*      4)Port K and DDRK not in the map in peripheral and expanded modes with EMK set.            */
/*      5)Data read at these locations is undefined.                                               */
/*      6)Choose carefully your variable names, some letters are used as register bit name.        */
/*      7)Some registers like PWPRES (PWM PRESCALE COUNTER) have only 7 bits defined               */
/*      8)In the motorola register map, the bits of some some registers have the same name (first  */
/*      bit of PCTLCAN0 = first bit of PCTLCAN1 = RDPCAN). So for PCTLCAN0 his name is RDPCAN_0 and*/
/*      for PCTLCAN1 his name is RDPCAN_1.                                                         */
/***************************************************************************************************/



#ifndef __6812DG128A_H__
#define __6812DG128A_H__

#include <stdtypes.h>

#define _IO_BASE_ADDR 0
#define _IO_AT(x)  @(_IO_BASE_ADDR+(x))

#ifndef __DECL__6812DG128A_H__
#define __DECL__6812DG128A_H__  extern
#endif

#pragma MESSAGE DISABLE C1106 /* WARNING C1106: Non-standard bitfield type */

/**************************************************************************************************/
/*                                         DEFINE PORT A                                          */
/**************************************************************************************************/

__DECL__6812DG128A_H__ volatile unsigned char PORTA    _IO_AT(0x00);  /* port A */

__DECL__6812DG128A_H__ volatile unsigned char DDRA     _IO_AT(0x02);  /* data direction port A */



/**************************************************************************************************/
/*                                         DEFINE PORT B                                          */
/**************************************************************************************************/

__DECL__6812DG128A_H__ volatile unsigned char PORTB    _IO_AT(0x01);  /* port B */

__DECL__6812DG128A_H__ volatile unsigned char DDRB     _IO_AT(0x03);  /* data direction port B */


/**************************************************************************************************/
/*                                         DEFINE PORT E                                          */
/**************************************************************************************************/


__DECL__6812DG128A_H__ volatile unsigned char PORTE    _IO_AT(0x08);  /* port E */

/****Data Register E******/
__DECL__6812DG128A_H__ volatile  union {
  struct {
    unsigned char BIT0:1;
    unsigned char BIT1:1;
    unsigned char _DDE2:1;
    unsigned char _DDE3:1;
    unsigned char _DDE4:1;
    unsigned char _DDE5:1;
    unsigned char _DDE6:1;
    unsigned char _DDE7:1;
  } DDRE_BITS;
  unsigned char DDRE_BYTE;
}DDRE1  _IO_AT(0x09);


/* DEFINE REGISTER */
#define DDRE DDRE1.DDRE_BYTE

/*DEFINE REGISTER BITS*/
#define DDE2 DDRE1.DDRE_BITS._DDE2
#define DDE3 DDRE1.DDRE_BITS._DDE3
#define DDE4 DDRE1.DDRE_BITS._DDE4
#define DDE5 DDRE1.DDRE_BITS._DDE5
#define DDE6 DDRE1.DDRE_BITS._DDE6
#define DDE7 DDRE1.DDRE_BITS._DDE7



/**************************************************************************************************/
/*                               PORT E ASSIGNEMENT REGISTER                                      */
/**************************************************************************************************/

__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char _DBENE:1;
    unsigned char _CALE:1;
    unsigned char _RDWE:1;
    unsigned char _LSTRE:1;
    unsigned char _NECLK:1;
    unsigned char _PIPOE:1;
    unsigned char _CGMTE:1;
    unsigned char _NDBE:1;
  } PEAR_BITS;
  unsigned char PEAR_BYTE;
}PEAR1 _IO_AT(0x0a);

/*DEFINE REGISTER*/
#define PEAR PEAR1.PEAR_BYTE

/*DEFINE REGISTER BITS*/
#define DBENE PEAR1.PEAR_BITS._DBENE
#define CALE PEAR1.PEAR_BITS._CALE
#define RDWE PEAR1.PEAR_BITS._RDWE
#define LSTRE PEAR1.PEAR_BITS._LSTRE
#define NECLK PEAR1.PEAR_BITS._NECLK
#define PIPOE PEAR1.PEAR_BITS._PIPOE
#define CGMTE PEAR1.PEAR_BITS._CGMTE
#define NDBE PEAR1.PEAR_BITS._NDBE



/**************************************************************************************************/
/*                                            MODE REGISTER                                       */
/**************************************************************************************************/
__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char _EME:1;
    unsigned char _EMK:1;
    unsigned char _EBSWAI:1;
    unsigned char _IVIS:1;
    unsigned char _ESTR:1;
    unsigned char _MODA:1;
    unsigned char _MODB:1;
    unsigned char _SMODN:1;
  } MODE_BITS;
  unsigned char MODE_BYTE;
}MODE1 _IO_AT(0x0B);

/*DEFINE REGISTER*/
#define MODE MODE1.MODE_BYTE

/*DEFINE REGISTER BITS*/
#define EME MODE1.MODE_BITS._EME
#define EMK MODE1.MODE_BITS._EMK
#define EBSWAI MODE1.MODE_BITS._EBSWAI
#define IVIS MODE1.MODE_BITS._IVIS
#define ESTR MODE1.MODE_BITS._ESTR
#define MODA MODE1.MODE_BITS._MODA
#define MODB MODE1.MODE_BITS._MODB
#define SMODN MODE1.MODE_BITS._SMODN



/**************************************************************************************************/
/*                               PULL-UP CONTROL REGISTER                                         */
/**************************************************************************************************/
__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char _PUPA:1;
    unsigned char _PUPB:1;
    unsigned char BIT2:1;
    unsigned char BIT3:1;
    unsigned char _PUPE:1;
    unsigned char _PUPH:1;
    unsigned char _PUPJ:1;
    unsigned char _PUPK:1;
  } PUCR_BITS;
  unsigned char PUCR_BYTE;
}PUCR1 _IO_AT(0x0C);

/*DEFINE REGISTER*/
#define PUCR PUCR1.PUCR_BYTE

/*DEFINE REGISTER BITS*/
#define PUPA PUCR1.PUCR_BITS._PUPA
#define PUPB PUCR1.PUCR_BITS._PUPB
#define PUPE PUCR1.PUCR_BITS._PUPE
#define PUPH PUCR1.PUCR_BITS._PUPH
#define PUPJ PUCR1.PUCR_BITS._PUPJ
#define PUPK PUCR1.PUCR_BITS._PUPK



/**************************************************************************************************/
/*                               REDUCED DRIVE OF I\O LINES                                       */
/**************************************************************************************************/
__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char _RDPA:1;
    unsigned char _RDPB:1;
    unsigned char BIT2:1;
    unsigned char BIT3:1;
    unsigned char _RDPE:1;
    unsigned char _RDPH:1;
    unsigned char _RDPJ:1;
    unsigned char _RDPK:1;
  } RDRIV_BITS;
  unsigned char RDRIV_BYTE;
}RDRIV1 _IO_AT(0x0D);

/*DEFINE REGISTER*/
#define RDRIV RDRIV1.RDRIV_BYTE

/*DEFINE REGISTER BITS*/
#define RDPA RDRIV1.RDRIV_BITS._RDPA
#define RDPB RDRIV1.RDRIV_BITS._RDPB
#define RDPE RDRIV1.RDRIV_BITS._RDPE


/**************************************************************************************************/
/*                    INITIALIZATION OF INTERNAL RAM POSITION REGISTER                            */
/**************************************************************************************************/
__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char BIT0:1;
    unsigned char BIT1:1;
    unsigned char BIT2:1;
    unsigned char BIT3:1;
    unsigned char BIT4:1;
    unsigned char _RAM13:1;
    unsigned char _RAM14:1;
    unsigned char _RAM15:1;
  } INITRM_BITS;
  unsigned char INITRM_BYTE;
}INITRM1 _IO_AT(0x10);

/*DEFINE REGISTER*/
#define INITRM INITRM1.INITRM_BYTE

/*DEFINE REGISTER BITS*/
#define RAM13 INITRM1.INITRM_BITS._RAM13
#define RAM14 INITRM1.INITRM_BITS._RAM14
#define RAM15 INITRM1.INITRM_BITS._RAM15


/**************************************************************************************************/
/*                    INITIALIZATION OF INTERNAL REGISTER POSITION REGISTER                       */
/**************************************************************************************************/
__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char _MMSWAI:1;
    unsigned char BIT1:1;
    unsigned char BIT2:1;
    unsigned char _REG11:1;
    unsigned char _REG12:1;
    unsigned char _REG13:1;
    unsigned char _REG14:1;
    unsigned char _REG15:1;
  } INITRG_BITS;
  unsigned char INITRG_BYTE;
}INITRG1 _IO_AT(0x11);

/*DEFINE REGISTER*/
#define INITRG INITRG1.INITRG_BYTE

/*DEFINE REGISTER BITS*/
#define MMSWAI INITRG1.INITRG_BITS._MMSWAI
#define REG11 INITRG1.INITRG_BITS._REG11
#define REG12 INITRG1.INITRG_BITS._REG12
#define REG13 INITRG1.INITRG_BITS._REG13
#define REG14 INITRG1.INITRG_BITS._REG14
#define REG15 INITRG1.INITRG_BITS._REG15


/**************************************************************************************************/
/*                    INITIALIZATION OF INTERNAL EEPROM POSITION REGISTER                         */
/**************************************************************************************************/
__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char _EEON:1;
    unsigned char BIT1:1;
    unsigned char BIT2:1;
    unsigned char BIT3:1;
    unsigned char _EE12:1;
    unsigned char _EE13:1;
    unsigned char _EE14:1;
    unsigned char _EE15:1;
  } INITEE_BITS;
  unsigned char INITEE_BYTE;
}INITEE1 _IO_AT(0x12);

/*DEFINE REGISTER*/
#define INITEE INITEE1.INITEE_BYTE

/*DEFINE REGISTER BITS*/
#define EEON INITEE1.INITEE_BITS._EEON
#define EE12 INITEE1.INITEE_BITS._EE12
#define EE13 INITEE1.INITEE_BITS._EE13
#define EE14 INITEE1.INITEE_BITS._EE14
#define EE15 INITEE1.INITEE_BITS._EE15


/**************************************************************************************************/
/*                         MISCELLANEOUS MAPPING CONTROL REGISTER                                 */
/**************************************************************************************************/
__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char _ROMON:1;
    unsigned char _ROMHM:1;
    unsigned char _EXSTR0:1;
    unsigned char _EXSTR1:1;
    unsigned char _RFSTR0:1;
    unsigned char _RFSTR1:1;
    unsigned char _NDRF:1;
    unsigned char _ROMTST:1;
  } MISC_BITS;
  unsigned char MISC_BYTE;
}MISC1 _IO_AT(0x13);

/*DEFINE REGISTER*/
#define MISC MISC1.MISC_BYTE

/*DEFINE REGISTER BITS*/
#define ROMON MISC1.MISC_BITS._ROMON
#define ROMHM MISC1.MISC_BITS._ROMHM
#define EXSTR0 MISC1.MISC_BITS._EXSTR0
#define EXSTR1 MISC1.MISC_BITS._EXSTR1
#define RFSTR0 MISC1.MISC_BITS._RFSTR0
#define RFSTR1 MISC1.MISC_BITS._RFSTR1
#define NDRF MISC1.MISC_BITS._NDRF
#define ROMTST MISC1.MISC_BITS._ROMTST


/**************************************************************************************************/
/*                                     REAL-TIME INTERRUPT ENABLE                                 */
/**************************************************************************************************/
__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char _RTR0:1;
    unsigned char _RTR1:1;
    unsigned char _RTR2:1;
    unsigned char _RTBYP:1;
    unsigned char _BIT4:1;
    unsigned char _RSBCK:1;
    unsigned char _RSWAI:1;
    unsigned char _RTIE:1;
  } RTICTL_BITS;
  unsigned char RTICTL_BYTE;
}RTICTL1 _IO_AT(0x14);

/*DEFINE REGISTER*/
#define RTICTL RTICTL1.RTICTL_BYTE

/*DEFINE REGISTER BITS*/
#define RTR0 RTICTL1.RTICTL_BITS._RTR0
#define RTR1 RTICTL1.RTICTL_BITS._RTR1
#define RTR2 RTICTL1.RTICTL_BITS._RTR2
#define RTBYP RTICTL1.RTICTL_BITS._RTBYP
#define RSBCK RTICTL1.RTICTL_BITS._RSBCK
#define RSWAI RTICTL1.RTICTL_BITS._RSWAI
#define RTIE RTICTL1.RTICTL_BITS._RTIE


/**************************************************************************************************/
/*                                  REAL-TIME INTERRUPT FLAG REGISTER                             */
/**************************************************************************************************/
__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char BIT0:1;
    unsigned char BIT1:1;
    unsigned char BIT2:1;
    unsigned char BIT3:1;
    unsigned char BIT4:1;
    unsigned char BIT5:1;
    unsigned char BIT6:1;
    unsigned char _RTIF:1;
  } RTIFLG_BITS;
  unsigned char RTIFLG_BYTE;
}RTIFLG1 _IO_AT(0x15);

/*DEFINE REGISTER*/
#define RTIFLG RTIFLG1.RTIFLG_BYTE

/*DEFINE REGISTER BITS*/
#define RTIF RTIFLG1.RTIFLG_BITS._RTIF


/**************************************************************************************************/
/*                                       COP CONTROL REGISTER                                     */
/**************************************************************************************************/
__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char _CR0:1;
    unsigned char _CR1:1;
    unsigned char _CR2:1;
    unsigned char _DISR:1;
    unsigned char _WCOP:1;
    unsigned char _FCMCOP:1;
    unsigned char _FCME:1;
    unsigned char _CME:1;
  } COPCTL_BITS;
  unsigned char COPCTL_BYTE;
}COPCTL1 _IO_AT(0x16);

/*DEFINE REGISTER*/
#define COPCTL COPCTL1.COPCTL_BYTE

/*DEFINE REGISTER BITS*/
#define CR0 COPCTL1.COPCTL_BITS._CR0
#define CR1 COPCTL1.COPCTL_BITS._CR1
#define CR2 COPCTL1.COPCTL_BITS._CR2
#define DISR COPCTL1.COPCTL_BITS._DISR
#define WCOP COPCTL1.COPCTL_BITS._WCOP
#define FCMCOP COPCTL1.COPCTL_BITS._FCMCOP
#define FCME COPCTL1.COPCTL_BITS._FCME
#define CME COPCTL1.COPCTL_BITS._CME




/**************************************************************************************************/
/*                                 ARM/RESET COP TIMER REGISTER                                   */
/**************************************************************************************************/
__DECL__6812DG128A_H__ volatile unsigned char COPRST   _IO_AT(0x17);  /* COP arm/reset */


/**************************************************************************************************/
/*                                   INTERRUPT TEST REGISTERS                                     */
/**************************************************************************************************/

__DECL__6812DG128A_H__ volatile unsigned char ITST0    _IO_AT(0x18);  /* interrupt test 0 */
__DECL__6812DG128A_H__ volatile unsigned char ITST1    _IO_AT(0x19);  /* interrupt test 1 */
__DECL__6812DG128A_H__ volatile unsigned char ITST2    _IO_AT(0x1a);  /* interrupt test 2 */
__DECL__6812DG128A_H__ volatile unsigned char ITST3    _IO_AT(0x1b);  /* interrupt test 3 */



/**************************************************************************************************/
/*                                     INTERRUPT CONTROL REGISTER                                 */
/**************************************************************************************************/
__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char BIT0:1;
    unsigned char BIT1:1;
    unsigned char BIT2:1;
    unsigned char BIT3:1;
    unsigned char BIT4:1;
    unsigned char _DLY:1;
    unsigned char _IRQEN:1;
    unsigned char _IRQE:1;
  } INTCR_BITS;
  unsigned char INTCR_BYTE;
}INTCR1 _IO_AT(0x1E);

/*DEFINE REGISTER*/
#define INTCR INTCR1.INTCR_BYTE

/*DEFINE REGISTER BITS*/
#define DLY INTCR1.INTCR_BITS._DLY
#define IRQEN INTCR1.INTCR_BITS._IRQEN
#define IRQE INTCR1.INTCR_BITS._IRQE



/**************************************************************************************************/
/*                                   HIGHEST PRIORITY I INTERRUPT                                 */
/**************************************************************************************************/
__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char BIT0:1;
    unsigned char _PSEL1:1;
    unsigned char _PSEL2:1;
    unsigned char _PSEL3:1;
    unsigned char _PSEL4:1;
    unsigned char _PSEL5:1;
    unsigned char _PSEL6:1;
    unsigned char BIT7:1;
  } HPRIO_BITS;
  unsigned char HPRIO_BYTE;
}HPRIO1 _IO_AT(0x1F);

/*DEFINE REGISTER*/
#define HPRIO HPRIO1.HPRIO_BYTE

/*DEFINE REGISTER BITS*/
#define PSEL1 HPRIO1.HPRIO_BITS._PSEL1
#define PSEL2 HPRIO1.HPRIO_BITS._PSEL2
#define PSEL3 HPRIO1.HPRIO_BITS._PSEL3
#define PSEL4 HPRIO1.HPRIO_BITS._PSEL4
#define PSEL5 HPRIO1.HPRIO_BITS._PSEL5
#define PSEL6 HPRIO1.HPRIO_BITS._PSEL6


/**************************************************************************************************/
/*                                   BREAKPOINT CONTROL REGISTER 0                                */
/**************************************************************************************************/
__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char BIT0:1;
    unsigned char BIT1:1;
    unsigned char _BK0ALE:1;
    unsigned char _BK1ALE:1;
    unsigned char BIT4:1;
    unsigned char _BKPM:1;
    unsigned char _BKEN0:1;
    unsigned char _BKEN1:1;
  } BRKCT0_BITS;
  unsigned char BRKCT0_BYTE;
}BRKCT01 _IO_AT(0x20);

/*DEFINE REGISTER*/
#define BRKCT0 BRKCT01.BRKCT0_BYTE

/*DEFINE REGISTER BITS*/
#define BK0ALE BRKCT01.BRKCT0_BITS._BK0ALE
#define BK1ALE BRKCT01.BRKCT0_BITS._BK1ALE
#define BKPM BRKCT01.BRKCT0_BITS._BKPM
#define BKEN0 BRKCT01.BRKCT0_BITS._BKEN0
#define BKEN1 BRKCT01.BRKCT0_BITS._BKEN1




/*******************************************************************************************/
/*                                   BREAKPOINT CONTROL REGISTER 1                         */
/*******************************************************************************************/
__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char _BK0RW:1;
    unsigned char _BK0RWE:1;
    unsigned char _BK1RW:1;
    unsigned char _BK1RWE:1;
    unsigned char _BKMBL:1;
    unsigned char _BKMBH:1;
    unsigned char _BKDBE:1;
    unsigned char BIT7:1;
  } BRKCT1_BITS;
  unsigned char BRKCT1_BYTE;
}BRKCT11 _IO_AT(0x21);

/*DEFINE REGISTER*/
#define BRKCT1 BRKCT11.BRKCT1_BYTE

/*DEFINE REGISTER BITS*/
#define BK0RW BRKCT11.BRKCT1_BITS._BK0RW
#define BK0RWE BRKCT11.BRKCT1_BITS._BK0RWE
#define BK1RW BRKCT11.BRKCT1_BITS._BK1RW
#define BK1RWE BRKCT11.BRKCT1_BITS._BK1RWE
#define BKMBL BRKCT11.BRKCT1_BITS._BKMBL
#define BKMBH BRKCT11.BRKCT1_BITS._BKMBH
#define BKDBE BRKCT11.BRKCT1_BITS._BKDBE





/*******************************************************************************************/
/*                           BREAKPOINT DATA AND ADDRESS REGISTERS                         */
/*******************************************************************************************/


__DECL__6812DG128A_H__ volatile unsigned char BRKAH    _IO_AT(0x22);  /* Breakpoint Address Register, High Byte*/
__DECL__6812DG128A_H__ volatile unsigned char BRKAL    _IO_AT(0x23);  /* Breakpoint Address Register, Low Byte*/

__DECL__6812DG128A_H__ volatile unsigned char BRKDH    _IO_AT(0x24);  /* Breakpoint Data Register, High Byte*/
__DECL__6812DG128A_H__ volatile unsigned char BRKDL    _IO_AT(0x25);  /* Breakpoint Data Register, Low Byte*/


/**************************************************************************************************/
/*                                         DEFINE PORT J                                          */
/**************************************************************************************************/

__DECL__6812DG128A_H__ volatile unsigned char PORTJ    _IO_AT(0x28);  /* port J */

__DECL__6812DG128A_H__ volatile unsigned char DDRJ     _IO_AT(0x2A);  /* data direction port J */



/**************************************************************************************************/
/*                                         DEFINE PORT H                                          */
/**************************************************************************************************/

/* ----------------------------------------------------- */
/* FCOM#1307 : Modify Definitions for Best use of PORT H */
/* ----------------------------------------------------- */

__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char _PH0:1;
    unsigned char _PH1:1;
    unsigned char _PH2:1;
    unsigned char _PH3:1;
    unsigned char _PH4:1;
    unsigned char _PH5:1;
    unsigned char _PH6:1;
    unsigned char _PH7:1;
  } PORTH_BITS;
  unsigned char PORTH_BYTE;
} PORTH1 _IO_AT(0x29);

/*DEFINE REGISTER*/
#define PORTH PORTH1.PORTH_BYTE

/*DEFINE REGISTER BITS*/
#define PH0 PORTH1.PORTH_BITS._PH0
#define PH1 PORTH1.PORTH_BITS._PH1
#define PH2 PORTH1.PORTH_BITS._PH2
#define PH3 PORTH1.PORTH_BITS._PH3
#define PH4 PORTH1.PORTH_BITS._PH4
#define PH5 PORTH1.PORTH_BITS._PH5
#define PH6 PORTH1.PORTH_BITS._PH6
#define PH7 PORTH1.PORTH_BITS._PH7

__DECL__6812DG128A_H__ volatile unsigned char DDRH     _IO_AT(0x2B);  /* data direction port H */


/**************************************************************************************************/
/*                           KEY WAKE UP PORT J INTERRUPT ENABLE REGISTER                         */
/**************************************************************************************************/

__DECL__6812DG128A_H__ volatile unsigned char KWIEJ    _IO_AT(0x2C);


/**************************************************************************************************/
/*                           KEY WAKE UP PORT H INTERRUPT ENABLE REGISTER                         */
/**************************************************************************************************/

__DECL__6812DG128A_H__ volatile unsigned char KWIEH    _IO_AT(0x2D);


/**************************************************************************************************/
/*                           KEY WAKE UP PORT J FLAG REGISTER                                     */
/**************************************************************************************************/

__DECL__6812DG128A_H__ volatile unsigned char KWIFJ    _IO_AT(0x2E);


/**************************************************************************************************/
/*                           KEY WAKE UP PORT H FLAG REGISTER                                     */
/**************************************************************************************************/

__DECL__6812DG128A_H__ volatile unsigned char KWIFH    _IO_AT(0x2F);


/**************************************************************************************************/
/*                           KEY WAKE UP PORT J POLARITY REGISTER                                 */
/**************************************************************************************************/

__DECL__6812DG128A_H__ volatile unsigned char KWPJ    _IO_AT(0x30);


/**************************************************************************************************/
/*                           KEY WAKE UP PORT H POLARITY REGISTER                                 */
/**************************************************************************************************/

__DECL__6812DG128A_H__ volatile unsigned char KWPH    _IO_AT(0x31);


/*******************************************************************************************/
/*                                    SYNTHETIZER REGISTER                                 */
/*******************************************************************************************/

__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char _SYNR0:1;
    unsigned char _SYNR1:1;
    unsigned char _SYNR2:1;
    unsigned char _SYNR3:1;
    unsigned char _SYNR4:1;
    unsigned char _SYNR5:1;
    unsigned char _BIT6:1;
    unsigned char _BIT7:1;
  } SYNR_BITS;
  unsigned char SYNR_BYTE;
}SYNR11 _IO_AT(0x38);

/*DEFINE REGISTER*/
#define SYNR SYNR11.SYNR_BYTE

/*DEFINE REGISTER BITS*/
#define SYNR0 SYNR11.SYNR_BITS._SYNR0
#define SYNR1 SYNR11.SYNR_BITS._SYNR1
#define SYNR2 SYNR11.SYNR_BITS._SYNR2
#define SYNR3 SYNR11.SYNR_BITS._SYNR3
#define SYNR4 SYNR11.SYNR_BITS._SYNR4
#define SYNR5 SYNR11.SYNR_BITS._SYNR5


/*******************************************************************************************/
/*                              REFERENCE DIVIDER REGISTER                                 */
/*******************************************************************************************/

__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char _REFDV0:1;
    unsigned char _REFDV1:1;
    unsigned char _REFDV2:1;
    unsigned char _BIT3:1;
    unsigned char _BIT4:1;
    unsigned char _BIT5:1;
    unsigned char _BIT6:1;
    unsigned char _BIT7:1;
  } REFDV_BITS;
  unsigned char REFDV_BYTE;
}REFDV11 _IO_AT(0x39);

/*DEFINE REGISTER*/
#define REFDV REFDV11.REFDV_BYTE

/*DEFINE REGISTER BITS*/
#define REFDV0 REFDV11.REFDV_BITS._REFDV0
#define REFDV1 REFDV11.REFDV_BITS._REFDV1
#define REFDV2 REFDV11.REFDV_BITS._REFDV2



/**************************************************************************************************/
/*                                     CLOCK GENERATOR TEST REGISTER                              */
/**************************************************************************************************/

__DECL__6812DG128A_H__ volatile unsigned char CGTFLG    _IO_AT(0x3A);


/*******************************************************************************************/
/*                                      PLL FLAGS                                          */
/*******************************************************************************************/

__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char _LHOME:1;
    unsigned char _LHIF:1;
    unsigned char _BIT2:1;
    unsigned char _BIT3:1;
    unsigned char _BIT4:1;
    unsigned char _BIT5:1;
    unsigned char _LOCK:1;
    unsigned char _LOCKIF:1;
  } PLLFLG_BITS;
  unsigned char PLLFLG_BYTE;
}PLLFLG11 _IO_AT(0x3B);

/*DEFINE REGISTER*/
#define PLLFLG PLLFLG11.PLLFLG_BYTE

/*DEFINE REGISTER BITS*/
#define LHOME PLLFLG11.PLLFLG_BITS._LHOME
#define LHIF PLLFLG11.PLLFLG_BITS._LHIF
#define LOCK PLLFLG11.PLLFLG_BITS._LOCK
#define LOCKIF PLLFLG11.PLLFLG_BITS._LOCKIF


/*******************************************************************************************/
/*                                      PLL CONTROL REGISTER                               */
/*******************************************************************************************/

__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char _RSTE:1;
    unsigned char _LHIE:1;
    unsigned char _PSTP:1;
    unsigned char _BIT3:1;
    unsigned char _ACQ1:1;
    unsigned char _AUTO1:1;
    unsigned char _PLLON1:1;
    unsigned char _LOCKIE:1;
  } PLLPC_BITS;
  unsigned char PLLPC_BYTE;
}PLLPC1 _IO_AT(0x3C);

/*DEFINE REGISTER*/
#define PLLPC PLLPC1.PLLPC_BYTE

/*DEFINE REGISTER BITS*/
#define RSTE PLLPC1.PLLPC_BITS._RSTE
#define LHIE PLLPC1.PLLPC_BITS._LHIE
#define PSTP PLLPC1.PLLPC_BITS._PSTP
#define _ACQ PLLPC1.PLLPC_BITS._ACQ1
#define _PLLON PLLPC1.PLLPC_BITS._PLLON1
#define LOCKIE PLLPC1.PLLPC_BITS._LOCKIE


/*******************************************************************************************/
/*                     CLOCK GENERATOR CLOCK SELECT REGISTER                               */
/*******************************************************************************************/

__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char BIT0:1;
    unsigned char BIT1:1;
    unsigned char _MCS:1;
    unsigned char BIT3:1;
    unsigned char BIT4:1;
    unsigned char _BCSS:1;
    unsigned char _BCSP:1;
    unsigned char BIT7:1;
  } CLKSEL_BITS;
  unsigned char CLKSEL_BYTE;
}CLKSEL1 _IO_AT(0x3D);

/*DEFINE REGISTER*/
#define CLKSEL CLKSEL1.CLKSEL_BYTE

/*DEFINE REGISTER BITS*/
#define MCS CLKSEL1.CLKSEL_BITS._MCS
#define BCSS CLKSEL1.CLKSEL_BITS._BCSS
#define BCSP CLKSEL1.CLKSEL_BITS._BCSP


/*******************************************************************************************/
/*                               SLOW MODE DIVIDER REGISTER                                */
/*******************************************************************************************/

__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char _SLDV0:1;
    unsigned char _SLDV1:1;
    unsigned char _SLDV2:1;
    unsigned char _SLDV3:1;
    unsigned char _SLDV4:1;
    unsigned char _SLDV5:1;
    unsigned char _BIT6:1;
    unsigned char _BIT7:1;
  } SLOW_BITS;
  unsigned char SLOW_BYTE;
}SLOW1 _IO_AT(0x3E);

/*DEFINE REGISTER*/
#define SLOW SLOW1.SLOW_BYTE

/*DEFINE REGISTER BITS*/
#define SLDV0 SLOW1.SLOW_BITS._SLDV0
#define SLDV1 SLOW1.SLOW_BITS._SLDV1
#define SLDV2 SLOW1.SLOW_BITS._SLDV2
#define SLDV3 SLOW1.SLOW_BITS._SLDV3
#define SLDV4 SLOW1.SLOW_BITS._SLDV4
#define SLDV5 SLOW1.SLOW_BITS._SLDV5


/*******************************************************************************************/
/*                          CLOCK GENERATOR TEST CONTROL REGISTER                          */
/*******************************************************************************************/

__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char _TST0:1;
    unsigned char _TST1:1;
    unsigned char _TST2:1;
    unsigned char _TST3:1;
    unsigned char _TST4:1;
    unsigned char _TSTCLKE:1;
    unsigned char _TRK1:1;
    unsigned char _OPNLE:1;
  } CGTCTL_BITS;
  unsigned char CGTCTL_BYTE;
}CGTCTL1 _IO_AT(0x3F);

/*DEFINE REGISTER*/
#define CGTCTL CGTCTL1.CGTCTL_BYTE

/*DEFINE REGISTER BITS*/
#define TST0 CGTCTL1.CGTCTL_BITS._TST0
#define TST1 CGTCTL1.CGTCTL_BITS._TST1
#define TST2 CGTCTL1.CGTCTL_BITS._TST2
#define TST3 CGTCTL1.CGTCTL_BITS._TST3
#define TST4 CGTCTL1.CGTCTL_BITS._TST4
#define TSTCLKE CGTCTL1.CGTCTL_BITS._TSTCLKE
#define _TRK CGTCTL1.CGTCTL_BITS._TRK1
#define OPNLE CGTCTL1.CGTCTL_BITS._OPNLE


/*******************************************************************************************/
/*                              PWM CLOCKS AND CONCATENATE                                 */
/*******************************************************************************************/

__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char _PCKB0:1;
    unsigned char _PCKB1:1;
    unsigned char _PCKB2:1;
    unsigned char _PCKA0:1;
    unsigned char _PCKA1:1;
    unsigned char _PCKA2:1;
    unsigned char _CON01:1;
    unsigned char _CON23:1;
  } PWCLK_BITS;
  unsigned char PWCLK_BYTE;
}PWCLK1 _IO_AT(0x40);

/*DEFINE REGISTER*/
#define PWCLK PWCLK1.PWCLK_BYTE

/*DEFINE REGISTER BITS*/
#define PCKB0 PWCLK1.PWCLK_BITS._PCKB0
#define PCKB1 PWCLK1.PWCLK_BITS._PCKB1
#define PCKB2 PWCLK1.PWCLK_BITS._PCKB2
#define PCKA0 PWCLK1.PWCLK_BITS._PCKA0
#define PCKA1 PWCLK1.PWCLK_BITS._PCKA1
#define PCKA2 PWCLK1.PWCLK_BITS._PCKA2
#define CON01 PWCLK1.PWCLK_BITS._CON01
#define CON23 PWCLK1.PWCLK_BITS._CON23



/*******************************************************************************************/
/*                              PWM CLOCK SELECT AND POLARITY                              */
/*******************************************************************************************/

__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char _PPOL0:1;
    unsigned char _PPOL1:1;
    unsigned char _PPOL2:1;
    unsigned char _PPOL3:1;
    unsigned char _PCLK0:1;
    unsigned char _PCLK1:1;
    unsigned char _PCLK2:1;
    unsigned char _PCLK3:1;
  } PWPOL_BITS;
  unsigned char PWPOL_BYTE;
}PWPOL1 _IO_AT(0x41);

/*DEFINE REGISTER*/
#define PWPOL PWPOL1.PWPOL_BYTE

/*DEFINE REGISTER BITS*/
#define PPOL0 PWPOL1.PWPOL_BITS._PPOL0
#define PPOL1 PWPOL1.PWPOL_BITS._PPOL1
#define PPOL2 PWPOL1.PWPOL_BITS._PPOL2
#define PPOL3 PWPOL1.PWPOL_BITS._PPOL3
#define PCLK0 PWPOL1.PWPOL_BITS._PCLK0
#define PCLK1 PWPOL1.PWPOL_BITS._PCLK1
#define PCLK2 PWPOL1.PWPOL_BITS._PCLK2
#define PCLK3 PWPOL1.PWPOL_BITS._PCLK3



/*******************************************************************************************/
/*                                          PWM ENABLE                                     */
/*******************************************************************************************/

__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char _PWEN0:1;
    unsigned char _PWEN1:1;
    unsigned char _PWEN2:1;
    unsigned char _PWEN3:1;
    unsigned char BIT4:1;
    unsigned char BIT5:1;
    unsigned char BIT6:1;
    unsigned char BIT7:1;
  } PWEN_BITS;
  unsigned char PWEN_BYTE;
}PWEN_1 _IO_AT(0x42);

/*DEFINE REGISTER*/
#define PWEN PWEN_1.PWEN_BYTE

/*DEFINE REGISTER BITS*/
#define PWEN0 PWEN_1.PWEN_BITS._PWEN0
#define PWEN1 PWEN_1.PWEN_BITS._PWEN1
#define PWEN2 PWEN_1.PWEN_BITS._PWEN2
#define PWEN3 PWEN_1.PWEN_BITS._PWEN3


/*******************************************************************************************/
/*                                 PWM PRESCALE COUNTER                                    */
/*******************************************************************************************/

__DECL__6812DG128A_H__ volatile unsigned char PWPRES   _IO_AT(0x43);  /* PWM Prescale Counter */



/*******************************************************************************************/
/*                                 PWM SCALE REGISTER 0                                    */
/*******************************************************************************************/

__DECL__6812DG128A_H__ volatile unsigned char PWSCAL0  _IO_AT(0x44); /* PWM Scale 0 */



/*******************************************************************************************/
/*                                 PWM SCALE COUNTER VALUE 0                               */
/*******************************************************************************************/

__DECL__6812DG128A_H__ volatile unsigned char PWSCNT0  _IO_AT(0x45); /* PWM Counter 0 */



/*******************************************************************************************/
/*                                 PWM SCALE REGISTER 1                                    */
/*******************************************************************************************/

__DECL__6812DG128A_H__ volatile unsigned char PWSCAL1  _IO_AT(0x46); /* PWM Scale 1 */



/*******************************************************************************************/
/*                                 PWM SCALE COUNTER VALUE 1                               */
/*******************************************************************************************/

__DECL__6812DG128A_H__ volatile unsigned char PWSCNT1  _IO_AT(0x47); /* PWM Counter 1 */




/*******************************************************************************************/
/*                                      PWM CHANNEL COUNTERS                               */
/*******************************************************************************************/

__DECL__6812DG128A_H__ volatile unsigned char PWCNT0   _IO_AT(0x48);  /* PWM Channel Counter 0 */
__DECL__6812DG128A_H__ volatile unsigned char PWCNT1   _IO_AT(0x49);  /* PWM Channel Counter 1 */
__DECL__6812DG128A_H__ volatile unsigned char PWCNT2   _IO_AT(0x4a);  /* PWM Channel Counter 2 */
__DECL__6812DG128A_H__ volatile unsigned char PWCNT3   _IO_AT(0x4b);  /* PWM Channel Counter 3 */



/*******************************************************************************************/
/*                              PWM CHANNEL PERIOD REGISTERS                               */
/*******************************************************************************************/

__DECL__6812DG128A_H__ volatile unsigned char PWPER0   _IO_AT(0x4c);  /* PWM Channel Period 0 */
__DECL__6812DG128A_H__ volatile unsigned char PWPER1   _IO_AT(0x4d);  /* PWM Channel Period 1 */
__DECL__6812DG128A_H__ volatile unsigned char PWPER2   _IO_AT(0x4e);  /* PWM Channel Period 2 */
__DECL__6812DG128A_H__ volatile unsigned char PWPER3   _IO_AT(0x4f);  /* PWM Channel Period 3 */




/*******************************************************************************************/
/*                                PWM CHANNEL DUTY REGISTERS                               */
/*******************************************************************************************/

__DECL__6812DG128A_H__ volatile unsigned char PWDTY0   _IO_AT(0x50);  /* PWM Channel Duty 0 */
__DECL__6812DG128A_H__ volatile unsigned char PWDTY1   _IO_AT(0x51);  /* PWM Channel Duty 1 */
__DECL__6812DG128A_H__ volatile unsigned char PWDTY2   _IO_AT(0x52);  /* PWM Channel Duty 2 */
__DECL__6812DG128A_H__ volatile unsigned char PWDTY3   _IO_AT(0x53);  /* PWM Channel Duty 3 */



/*******************************************************************************************/
/*                                PWM CONTROL REGISTER                                     */
/*******************************************************************************************/

__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char _PSBCK:1;
    unsigned char _PUPP:1;
    unsigned char _RDPP:1;
    unsigned char _CENTR:1;
    unsigned char _PSWAI:1;
    unsigned char BIT5:1;
    unsigned char BIT6:1;
    unsigned char BIT7:1;
  } PWCTL_BITS;
  unsigned char PWCTL_BYTE;
}PWCTL1 _IO_AT(0x54);

/*DEFINE REGISTER*/
#define PWCTL PWCTL1.PWCTL_BYTE

/*DEFINE REGISTER BITS*/
#define PSBCK PWCTL1.PWCTL_BITS._PSBCK
#define PUPP PWCTL1.PWCTL_BITS._PUPP
#define RDPP PWCTL1.PWCTL_BITS._RDPP
#define CENTR PWCTL1.PWCTL_BITS._CENTR
#define PSWAI PWCTL1.PWCTL_BITS._PSWAI


/*******************************************************************************************/
/*                              PWM SPECIAL MODE REGISTER (TEST)                           */
/*******************************************************************************************/

__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char BIT0:1;
    unsigned char BIT1:1;
    unsigned char BIT2:1;
    unsigned char BIT3:1;
    unsigned char BIT4:1;
    unsigned char _DISCAL:1;
    unsigned char _DISCP:1;
    unsigned char _DISCR:1;
  } PWTST_BITS;
  unsigned char PWTST_BYTE;
}PWTST1 _IO_AT(0x55);

/*DEFINE REGISTER*/
#define PWTST PWTST1.PWTST_BYTE

/*DEFINE REGISTER BITS*/
#define DISCAL PWTST1.PWTST_BITS._DISCAL
#define DISCP PWTST1.PWTST_BITS._DISCP
#define DISCR PWTST1.PWTST_BITS._DISCR

/* -------------------------------------------------------------- */
/* FCOM#1307 : Modify Definitions for Best use of PORT P and DDRT */
/* -------------------------------------------------------------- */

/**************************************************************************************************/
/*                                         DEFINE PORT P                                          */
/**************************************************************************************************/
    
__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char _PWM0:1;
    unsigned char _PWM1:1;
    unsigned char _PWM2:1;
    unsigned char _PWM3:1;
    unsigned char BIT4:1;
    unsigned char BIT5:1;
    unsigned char BIT6:1;
    unsigned char BIT7:1;
  } PORTP_BITS;
  unsigned char PORTP_BYTE;
} PORTP1 _IO_AT(0x56);

/*DEFINE REGISTER*/
#define PORTP PORTP1.PORTP_BYTE

/*DEFINE REGISTER BITS*/
#define PP0 PORTP1.PORTP_BITS._PWM0
#define PP1 PORTP1.PORTP_BITS._PWM1
#define PP2 PORTP1.PORTP_BITS._PWM2
#define PP3 PORTP1.PORTP_BITS._PWM3
   
/*******************************************************************************************/
/*                               PORT P DATA DIRECTION REGISTER                            */
/*******************************************************************************************/

__DECL__6812DG128A_H__  volatile union {
  struct {
    unsigned char _DDP0:1;
    unsigned char _DDP1:1;
    unsigned char _DDP2:1;
    unsigned char _DDP3:1;
    unsigned char BIT4:1;
    unsigned char BIT5:1;
    unsigned char BIT6:1;
    unsigned char BIT7:1;
  } DDRP_BITS;
  unsigned char DDRP_BYTE;
} DDRP1 _IO_AT(0x57);

/* DEFINE REGISTER */
#define DDRP DDRP1.DDRP_BYTE

/* DEFINE REGISTER BITS */
#define DDP0 DDRP1.DDRP_BITS._DDP0
#define DDP1 DDRP1.DDRP_BITS._DDP1
#define DDP2 DDRP1.DDRP_BITS._DDP2
#define DDP3 DDRP1.DDRP_BITS._DDP3


/* END of FCOM#1307 */

/**************************************************************************************************/
/*                                   ATD RESERVED REGISTERS                                       */
/**************************************************************************************************/

__DECL__6812DG128A_H__ volatile unsigned char ATD0CTL0  _IO_AT(0x60); /* A/D control register 0 */
__DECL__6812DG128A_H__ volatile unsigned char ATD0CTL1  _IO_AT(0x61); /* A/D control register 1 */



/**************************************************************************************************/
/*                                    ATD CONTROL REGISTERS                                       */
/**************************************************************************************************/


/**********ATD CONTROL REGISTER 2********/
__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char _ASCIF_0:1;
    unsigned char _ASCIE_0:1;
    unsigned char BIT2:1;
    unsigned char BIT3:1;
    unsigned char BIT4:1;
    unsigned char _ASWAI_0:1;
    unsigned char _AFFC_0:1;
    unsigned char _ADPU_0:1;
  } ATD0CTL2_BITS;
  unsigned char ATD0CTL2_BYTE;
}ATD0CTL21 _IO_AT(0x62);

/*DEFINE REGISTER*/
#define ATD0CTL2 ATD0CTL21.ATD0CTL2_BYTE

/*DEFINE REGISTER BITS*/
#define ASCIF_0 ATD0CTL21.ATD0CTL2_BITS._ASCIF_0
#define ASCIE_0 ATD0CTL21.ATD0CTL2_BITS._ASCIE_0
#define ASWAI_0 ATD0CTL21.ATD0CTL2_BITS._ASWAI_0
#define AFFC_0 ATD0CTL21.ATD0CTL2_BITS._AFFC_0
#define ADPU_0 ATD0CTL21.ATD0CTL2_BITS._ADPU_0



/**********ATD CONTROL REGISTER 3********/
__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char _FRZ0_0:1;
    unsigned char _FRZ1_0:1;
    unsigned char BIT2:1;
    unsigned char BIT3:1;
    unsigned char BIT4:1;
    unsigned char BIT5:1;
    unsigned char BIT6:1;
    unsigned char BIT7:1;
  } ATD0CTL3_BITS;
  unsigned char ATD0CTL3_BYTE;
}ATD0CTL31 _IO_AT(0x63);

/*DEFINE REGISTER*/
#define ATD0CTL3 ATD0CTL31.ATD0CTL3_BYTE

/*DEFINE REGISTER BITS*/
#define FRZ0_0 ATD0CTL31.ATD0CTL3_BITS._FRZ0_0
#define FRZ1_0 ATD0CTL31.ATD0CTL3_BITS._FRZ1_0



/**********ATD CONTROL REGISTER 4********/
__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char _PRS0_0:1;
    unsigned char _PRS1_0:1;
    unsigned char _PRS2_0:1;
    unsigned char _PRS3_0:1;
    unsigned char _PRS4_0:1;
    unsigned char _SMP0_0:1;
    unsigned char _SMP1_0:1;
    /* FCOM#1311 : Add definitions for read of ATD Converter in 10 Bit Mode */
    unsigned char _RES10_0:1;
  } ATD0CTL4_BITS;
  unsigned char ATD0CTL4_BYTE;
}ATD0CTL41 _IO_AT(0x64);

/*DEFINE REGISTER*/
#define ATD0CTL4 ATD0CTL41.ATD0CTL4_BYTE

/*DEFINE REGISTER BITS*/
#define PRS0_0 ATD0CTL41.ATD0CTL4_BITS._PRS0_0
#define PRS1_0 ATD0CTL41.ATD0CTL4_BITS._PRS1_0
#define PRS2_0 ATD0CTL41.ATD0CTL4_BITS._PRS2_0
#define PRS3_0 ATD0CTL41.ATD0CTL4_BITS._PRS3_0
#define PRS4_0 ATD0CTL41.ATD0CTL4_BITS._PRS4_0
#define SMP0_0 ATD0CTL41.ATD0CTL4_BITS._SMP0_0
#define SMP1_0 ATD0CTL41.ATD0CTL4_BITS._SMP1_0
/* FCOM#1311 : Add definitions for read of ATD Converter in 10 Bit Mode */
#define RES10_0 ATD0CTL41.ATD0CTL4_BITS._RES10_0


/**********ATD CONTROL REGISTER 5********/
__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char _CA_0:1;
    unsigned char _CB_0:1;
    unsigned char _CC_0:1;
    unsigned char _CD_0:1;
    unsigned char _MULT_0:1;
    unsigned char _SCAN_0:1;
    unsigned char _S8CM_0:1;
    unsigned char BIT7:1;
  } ATD0CTL5_BITS;
  unsigned char ATD0CTL5_BYTE;
}ATD0CTL51 _IO_AT(0x65);

/*DEFINE REGISTER*/
#define ATD0CTL5 ATD0CTL51.ATD0CTL5_BYTE

/*DEFINE REGISTER BITS*/
#define CA_0 ATD0CTL51.ATD0CTL5_BITS._CA_0
#define CB_0 ATD0CTL51.ATD0CTL5_BITS._CB_0
#define CC_0 ATD0CTL51.ATD0CTL5_BITS._CC_0
#define CD_0 ATD0CTL51.ATD0CTL5_BITS._CD_0
#define MULT_0 ATD0CTL51.ATD0CTL5_BITS._MULT_0
#define SCAN_0 ATD0CTL51.ATD0CTL5_BITS._SCAN_0
#define S8CM_0 ATD0CTL51.ATD0CTL5_BITS._S8CM_0




/**************************************************************************************************/
/*                                    ATD STATUS REGISTER                                         */
/**************************************************************************************************/


__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned short  _CC0_0:1;
    unsigned short  _CC1_0:1;
    unsigned short  _CC2_0:1;
    unsigned short  BIT3:1;
    unsigned short  BIT4:1;
    unsigned short  BIT5:1;
    unsigned short  BIT6:1;
    unsigned short  _SCF_0:1;
    unsigned short  _CCF0_0:1;
    unsigned short  _CCF1_0:1;
    unsigned short  _CCF2_0:1;
    unsigned short  _CCF3_0:1;
    unsigned short  _CCF4_0:1;
    unsigned short  _CCF5_0:1;
    unsigned short  _CCF6_0:1;
    unsigned short  _CCF7_0:1;
  } ATD0STAT_BITS;
  unsigned short ATD0STAT_WORD;
}ATD0STAT1 _IO_AT(0x66);

/*DEFINE REGISTER*/
#define ATD0STAT ATD0STAT1.ATD0STAT_WORD

/*DEFINE REGISTER BITS*/
#define CC0_0 ATD0STAT1.ATD0STAT_BITS._CC0_0
#define CC1_0 ATD0STAT1.ATD0STAT_BITS._CC1_0
#define CC2_0 ATD0STAT1.ATD0STAT_BITS._CC2_0
#define SCF_0 ATD0STAT1.ATD0STAT_BITS._SCF_0
#define CCF0_0 ATD0STAT1.ATD0STAT_BITS._CCF0_0
#define CCF1_0 ATD0STAT1.ATD0STAT_BITS._CCF1_0
#define CCF2_0 ATD0STAT1.ATD0STAT_BITS._CCF2_0
#define CCF3_0 ATD0STAT1.ATD0STAT_BITS._CCF3_0
#define CCF4_0 ATD0STAT1.ATD0STAT_BITS._CCF4_0
#define CCF5_0 ATD0STAT1.ATD0STAT_BITS._CCF5_0
#define CCF6_0 ATD0STAT1.ATD0STAT_BITS._CCF6_0
#define CCF7_0 ATD0STAT1.ATD0STAT_BITS._CCF7_0



/*******************************************************************************************/
/*                                        ATD TEST REGISTER                                */
/*******************************************************************************************/




/********ATD TEST REGISTER HIGH*********/
__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char _SAR2_0:1;
    unsigned char _SAR3_0:1;
    unsigned char _SAR4_0:1;
    unsigned char _SAR5_0:1;
    unsigned char _SAR6_0:1;
    unsigned char _SAR7_0:1;
    unsigned char _SAR8_0:1;
    unsigned char _SAR9_0:1;
  } ATD0TSTH_BITS;
  unsigned char ATD0TSTH_BYTE;
} ATD0TSTH1 _IO_AT(0x68);

/*DEFINE REGISTER*/
#define ATD0TSTH ATD0TSTH1.ATD0TSTH_BYTE

/*DEFINE REGISTER BITS*/
#define SAR2_0 ATD0TSTH1.ATD0TSTH_BITS._SAR2_0
#define SAR3_0 ATD0TSTH1.ATD0TSTH_BITS._SAR3_0
#define SAR4_0 ATD0TSTH1.ATD0TSTH_BITS._SAR4_0
#define SAR5_0 ATD0TSTH1.ATD0TSTH_BITS._SAR5_0
#define SAR6_0 ATD0TSTH1.ATD0TSTH_BITS._SAR6_0
#define SAR7_0 ATD0TSTH1.ATD0TSTH_BITS._SAR7_0
#define SAR8_0 ATD0TSTH1.ATD0TSTH_BITS._SAR8_0
#define SAR9_0 ATD0TSTH1.ATD0TSTH_BITS._SAR9_0


/********ATD TEST REGISTER LOW**********/
__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char _TST0_0:1;
    unsigned char _TST1_0:1;
    unsigned char _TST2_0:1;
    unsigned char _TST3_0:1;
    unsigned char _TSTOUT_0:1;
    unsigned char _RST_0:1;
    unsigned char _SAR0_0:1;
    unsigned char _SAR1_0:1;
  } ATD0TSTL_BITS;
  unsigned char ATD0TSTL_BYTE;
} ATD0TSTL1 _IO_AT(0x69);

/*DEFINE REGISTER*/
#define ATD0TSTL ATD0TSTL1.ATD0TSTL_BYTE

/*DEFINE REGISTER BITS*/
#define TST0_0 ATD0TSTL1.ATD0TSTL_BITS._TST0_0
#define TST1_0 ATD0TSTL1.ATD0TSTL_BITS._TST1_0
#define TST2_0 ATD0TSTL1.ATD0TSTL_BITS._TST2_0
#define TST3_0 ATD0TSTL1.ATD0TSTL_BITS._TST3_0
#define TSTOUT_0 ATD0TSTL1.ATD0TSTL_BITS._TSTOUT_0
#define RST_0 ATD0TSTL1.ATD0TSTL_BITS._RST_0
#define SAR0_0 ATD0TSTL1.ATD0TSTL_BITS._SAR0_0
#define SAR1_0 ATD0TSTL1.ATD0TSTL_BITS._SAR1_0



/*******************************************************************************************/
/*                                 PORT AD 0 DATA INPUT REGISTER                           */
/*******************************************************************************************/

__DECL__6812DG128A_H__ volatile unsigned char PORTAD0   _IO_AT(0x6f); /* port AD data input register */



/*******************************************************************************************/
/*                              ADT CONVERTER RESULT REGISTERS                             */
/*******************************************************************************************/

__DECL__6812DG128A_H__ volatile unsigned char ADR00H    _IO_AT(0x70); /* A/D result 0 register high */


__DECL__6812DG128A_H__ volatile union {                            /* A/D result 0 register low */
  struct {
    unsigned char BIT0:1;
    unsigned char BIT1:1;
    unsigned char BIT2:1;
    unsigned char BIT3:1;
    unsigned char BIT4:1;
    unsigned char BIT5:1;
    unsigned char _ADR00LBIT6:1;
    unsigned char _ADR00LBIT7:1;
  } ADR00L_BITS;
  unsigned char ADR00L_BYTE;
}ADR00L1 _IO_AT(0x71);

/*DEFINE REGISTER*/
#define ADR00L ADR00L1.ADR00L_BYTE

/*DEFINE REGISTER BITS*/
#define ADR00L_BIT6 ADR00L1.ADR00L_BITS._ADR00LBIT6
#define ADR00L_BIT7 ADR00L1.ADR00L_BITS._ADR00LBIT7

/* FCOM#1311 : Add definitions for read of ATD Converter in 10 Bit Mode */
#define ADR00HL ((*(volatile unsigned short*)&ADR00H) >> 6)
__DECL__6812DG128A_H__ volatile unsigned char ADR01H    _IO_AT(0x72); /* A/D result 1 register high */


__DECL__6812DG128A_H__ volatile union {                            /* A/D result 1 register low */
  struct {
    unsigned char BIT0:1;
    unsigned char BIT1:1;
    unsigned char BIT2:1;
    unsigned char BIT3:1;
    unsigned char BIT4:1;
    unsigned char BIT5:1;
    unsigned char _ADR01LBIT6:1;
    unsigned char _ADR01LBIT7:1;
  } ADR01L_BITS;
  unsigned char ADR01L_BYTE;
}ADR01L1 _IO_AT(0x73);

/*DEFINE REGISTER*/
#define ADR01L ADR01L1.ADR01L_BYTE

/*DEFINE REGISTER BITS*/
#define ADR01L_BIT6 ADR01L1.ADR01L_BITS._ADR01LBIT6
#define ADR01L_BIT7 ADR01L1.ADR01L_BITS._ADR01LBIT7

/* FCOM#1311 : Add definitions for read of ATD Converter in 10 Bit Mode */
#define ADR01HL ((*(volatile unsigned short*)&ADR01H) >> 6)

__DECL__6812DG128A_H__ volatile unsigned char ADR02H    _IO_AT(0x74); /* A/D result 2 register high */

__DECL__6812DG128A_H__ volatile union {                            /* A/D result 2 register low */
  struct {
    unsigned char BIT0:1;
    unsigned char BIT1:1;
    unsigned char BIT2:1;
    unsigned char BIT3:1;
    unsigned char BIT4:1;
    unsigned char BIT5:1;
    unsigned char _ADR02LBIT6:1;
    unsigned char _ADR02LBIT7:1;
  } ADR02L_BITS;
  unsigned char ADR02L_BYTE;
}ADR02L1 _IO_AT(0x75);

/*DEFINE REGISTER*/
#define ADR02L ADR02L1.ADR02L_BYTE

/*DEFINE REGISTER BITS*/
#define ADR02L_BIT6 ADR02L1.ADR02L_BITS._ADR02LBIT6
#define ADR02L_BIT7 ADR02L1.ADR02L_BITS._ADR02LBIT7

/* FCOM#1311 : Add definitions for read of ATD Converter in 10 Bit Mode */

#define ADR02HL ((*(volatile unsigned short*)&ADR02H) >> 6)

__DECL__6812DG128A_H__ volatile unsigned char ADR03H    _IO_AT(0x76); /* A/D result 3 register high */

__DECL__6812DG128A_H__ volatile union {                            /* A/D result 3 register low */
  struct {
    unsigned char BIT0:1;
    unsigned char BIT1:1;
    unsigned char BIT2:1;
    unsigned char BIT3:1;
    unsigned char BIT4:1;
    unsigned char BIT5:1;
    unsigned char _ADR03LBIT6:1;
    unsigned char _ADR03LBIT7:1;
  } ADR03L_BITS;
  unsigned char ADR03L_BYTE;
}ADR03L1 _IO_AT(0x77);

/*DEFINE REGISTER*/
#define ADR03L ADR03L1.ADR03L_BYTE

/*DEFINE REGISTER BITS*/
#define ADR03L_BIT6 ADR03L1.ADR03L_BITS._ADR03LBIT6
#define ADR03L_BIT7 ADR03L1.ADR03L_BITS._ADR03LBIT7

/* FCOM#1311 : Add definitions for read of ATD Converter in 10 Bit Mode */
#define ADR03HL ((*(volatile unsigned short*)&ADR03H) >> 6)

__DECL__6812DG128A_H__ volatile unsigned char ADR04H    _IO_AT(0x78); /* A/D result 4 register high */

__DECL__6812DG128A_H__ volatile union {                            /* A/D result 4 register low */
  struct {
    unsigned char BIT0:1;
    unsigned char BIT1:1;
    unsigned char BIT2:1;
    unsigned char BIT3:1;
    unsigned char BIT4:1;
    unsigned char BIT5:1;
    unsigned char _ADR04LBIT6:1;
    unsigned char _ADR04LBIT7:1;
  } ADR04L_BITS;
  unsigned char ADR04L_BYTE;
}ADR04L1 _IO_AT(0x79);

/*DEFINE REGISTER*/
#define ADR04L ADR04L1.ADR04L_BYTE

/*DEFINE REGISTER BITS*/
#define ADR04L_BIT6 ADR04L1.ADR04L_BITS._ADR04LBIT6
#define ADR04L_BIT7 ADR04L1.ADR04L_BITS._ADR04LBIT7

/* FCOM#1311 : Add definitions for read of ATD Converter in 10 Bit Mode */
#define ADR04HL ((*(volatile unsigned short*)&ADR04H) >> 6)

__DECL__6812DG128A_H__ volatile unsigned char ADR05H    _IO_AT(0x7a); /* A/D result 5 register high */

__DECL__6812DG128A_H__ volatile union {                            /* A/D result 5 register low */
  struct {
    unsigned char BIT0:1;
    unsigned char BIT1:1;
    unsigned char BIT2:1;
    unsigned char BIT3:1;
    unsigned char BIT4:1;
    unsigned char BIT5:1;
    unsigned char _ADR05LBIT6:1;
    unsigned char _ADR05LBIT7:1;
  } ADR05L_BITS;
  unsigned char ADR05L_BYTE;
}ADR05L1 _IO_AT(0x7B);

/*DEFINE REGISTER*/
#define ADR05L ADR05L1.ADR05L_BYTE

/*DEFINE REGISTER BITS*/
#define ADR05L_BIT6 ADR05L1.ADR05L_BITS._ADR05LBIT6
#define ADR05L_BIT7 ADR05L1.ADR05L_BITS._ADR05LBIT7

/* FCOM#1311 : Add definitions for read of ATD Converter in 10 Bit Mode */
#define ADR05HL ((*(volatile unsigned short*)&ADR05H) >> 6)

__DECL__6812DG128A_H__ volatile unsigned char ADR06H    _IO_AT(0x7c); /* A/D result 6 register high */

__DECL__6812DG128A_H__ volatile union {                            /* A/D result 6 register low */
  struct {
    unsigned char BIT0:1;
    unsigned char BIT1:1;
    unsigned char BIT2:1;
    unsigned char BIT3:1;
    unsigned char BIT4:1;
    unsigned char BIT5:1;
    unsigned char _ADR06LBIT6:1;
    unsigned char _ADR06LBIT7:1;
  } ADR06L_BITS;
  unsigned char ADR06L_BYTE;
}ADR06L1 _IO_AT(0x7D);

/*DEFINE REGISTER*/
#define ADR06L ADR06L1.ADR06L_BYTE

/*DEFINE REGISTER BITS*/
#define ADR06L_BIT6 ADR06L1.ADR06L_BITS._ADR06LBIT6
#define ADR06L_BIT7 ADR06L1.ADR06L_BITS._ADR06LBIT7

/* FCOM#1311 : Add definitions for read of ATD Converter in 10 Bit Mode */
#define ADR06HL ((*(volatile unsigned short*)&ADR06H) >> 6)

__DECL__6812DG128A_H__ volatile unsigned char ADR07H    _IO_AT(0x7e); /* A/D result 7 register high */

__DECL__6812DG128A_H__ volatile union {                            /* A/D result 7 register low */
  struct {
    unsigned char BIT0:1;
    unsigned char BIT1:1;
    unsigned char BIT2:1;
    unsigned char BIT3:1;
    unsigned char BIT4:1;
    unsigned char BIT5:1;
    unsigned char _ADR07LBIT6:1;
    unsigned char _ADR07LBIT7:1;
  } ADR07L_BITS;
  unsigned char ADR07L_BYTE;
}ADR07L1 _IO_AT(0x7F);

/*DEFINE REGISTER*/
#define ADR07L ADR07L1.ADR07L_BYTE

/*DEFINE REGISTER BITS*/
#define ADR07L_BIT6 ADR07L1.ADR07L_BITS._ADR07LBIT6
#define ADR07L_BIT7 ADR07L1.ADR07L_BITS._ADR07LBIT7

/* FCOM#1311 : Add definitions for read of ATD Converter in 10 Bit Mode */
#define ADR07HL ((*(volatile unsigned short*)&ADR07H) >> 6)

/*******************************************************************************************/
/*                           TIMER INPUT/OUTPUT COMPARE SELECT                             */
/*******************************************************************************************/

__DECL__6812DG128A_H__ volatile unsigned char TIOS     _IO_AT(0x80);



/*******************************************************************************************/
/*                          TIMER COMPARE FORCE REGISTER                                  */
/*******************************************************************************************/

__DECL__6812DG128A_H__ volatile unsigned char CFORC    _IO_AT(0x81);



/*******************************************************************************************/
/*                         OUTPUT COMPARE 7 MASK REGISTER                                  */
/*******************************************************************************************/

__DECL__6812DG128A_H__ volatile unsigned char OC7M     _IO_AT(0x82);


/*******************************************************************************************/
/*                         OUTPUT COMPARE 7 DATA REGISTER                                  */
/*******************************************************************************************/

__DECL__6812DG128A_H__ volatile unsigned char OC7D     _IO_AT(0x83);



/*******************************************************************************************/
/*                         OUTPUT COMPARE 7 DATA REGISTER                                  */
/*******************************************************************************************/

__DECL__6812DG128A_H__ volatile unsigned short TCNT     _IO_AT(0x84);


/*******************************************************************************************/
/*                                TIMER SYSTEM CONTROL REGISTER                            */
/*******************************************************************************************/

__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char BIT0:1;
    unsigned char BIT1:1;
    unsigned char BIT2:1;
    unsigned char BIT3:1;
    unsigned char _TFFCA:1;
    unsigned char _TSBCK:1;
    unsigned char _TSWAI:1;
    unsigned char _TEN:1;
  } TSCR_BITS;
  unsigned char TSCR_BYTE;
} TSCR1 _IO_AT(0x86);

/*DEFINE REGISTER*/
#define TSCR TSCR1.TSCR_BYTE

/*DEFINE REGISTER BITS*/
#define TFFCA TSCR1.TSCR_BITS._TFFCA
#define TSBCK TSCR1.TSCR_BITS._TSBCK
#define TSWAI TSCR1.TSCR_BITS._TSWAI
#define TEN TSCR1.TSCR_BITS._TEN


/*******************************************************************************************/
/*                         TIMER QUEUE CONTROL REGISTER (RESERVED)                         */
/*******************************************************************************************/

__DECL__6812DG128A_H__ volatile unsigned char TQCR     _IO_AT(0x87);  /* timer queue control */


/*******************************************************************************************/
/*                                TIMER CONTROL REGISTER 1                                 */
/*******************************************************************************************/

__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char _OL4:1;
    unsigned char _OM4:1;
    unsigned char _OL5:1;
    unsigned char _OM5:1;
    unsigned char _OL6:1;
    unsigned char _OM6:1;
    unsigned char _OL7:1;
    unsigned char _OM7:1;
  } TCTL1_BITS;
  unsigned char TCTL1_BYTE;
} TCTL11 _IO_AT(0x88);

/*DEFINE REGISTER*/
#define TCTL1 TCTL11.TCTL1_BYTE

/*DEFINE REGISTER BITS*/
#define OL4 TCTL11.TCTL1_BITS._OL4
#define OM4 TCTL11.TCTL1_BITS._OM4
#define OL5 TCTL11.TCTL1_BITS._OL5
#define OM5 TCTL11.TCTL1_BITS._OM5
#define OL6 TCTL11.TCTL1_BITS._OL6
#define OM6 TCTL11.TCTL1_BITS._OM6
#define OL7 TCTL11.TCTL1_BITS._OL7
#define OM7 TCTL11.TCTL1_BITS._OM7



/*******************************************************************************************/
/*                                TIMER CONTROL REGISTER 2                                 */
/*******************************************************************************************/

__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char _OL0:1;
    unsigned char _OM0:1;
    unsigned char _OL1:1;
    unsigned char _OM1:1;
    unsigned char _OL2:1;
    unsigned char _OM2:1;
    unsigned char _OL3:1;
    unsigned char _OM3:1;
  } TCTL2_BITS;
  unsigned char TCTL2_BYTE;
} TCTL21 _IO_AT(0x89);

/*DEFINE REGISTER*/
#define TCTL2 TCTL21.TCTL2_BYTE

/*DEFINE REGISTER BITS*/
#define OL0 TCTL21.TCTL2_BITS._OL0
#define OM0 TCTL21.TCTL2_BITS._OM0
#define OL1 TCTL21.TCTL2_BITS._OL1
#define OM1 TCTL21.TCTL2_BITS._OM1
#define OL2 TCTL21.TCTL2_BITS._OL2
#define OM2 TCTL21.TCTL2_BITS._OM2
#define OL3 TCTL21.TCTL2_BITS._OL3
#define OM3 TCTL21.TCTL2_BITS._OM3



/*******************************************************************************************/
/*                                TIMER CONTROL REGISTER 3                                 */
/*******************************************************************************************/

__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char _EDG4A:1;
    unsigned char _EDG4B:1;
    unsigned char _EDG5A:1;
    unsigned char _EDG5B:1;
    unsigned char _EDG6A:1;
    unsigned char _EDG6B:1;
    unsigned char _EDG7A:1;
    unsigned char _EDG7B:1;
  } TCTL3_BITS;
  unsigned char TCTL3_BYTE;
} TCTL31 _IO_AT(0x8A);

/*DEFINE REGISTER*/
#define TCTL3 TCTL31.TCTL3_BYTE

/*DEFINE REGISTER BITS*/
#define EDG4A TCTL31.TCTL3_BITS._EDG4A
#define EDG4B TCTL31.TCTL3_BITS._EDG4B
#define EDG5A TCTL31.TCTL3_BITS._EDG5A
#define EDG5B TCTL31.TCTL3_BITS._EDG5B
#define EDG6A TCTL31.TCTL3_BITS._EDG6A
#define EDG6B TCTL31.TCTL3_BITS._EDG6B
#define EDG7A TCTL31.TCTL3_BITS._EDG7A
#define EDG7B TCTL31.TCTL3_BITS._EDG7B


/*******************************************************************************************/
/*                                TIMER CONTROL REGISTER 4                                 */
/*******************************************************************************************/

__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char _EDG0A:1;
    unsigned char _EDG0B:1;
    unsigned char _EDG1A:1;
    unsigned char _EDG1B:1;
    unsigned char _EDG2A:1;
    unsigned char _EDG2B:1;
    unsigned char _EDG3A:1;
    unsigned char _EDG3B:1;
  } TCTL4_BITS;
  unsigned char TCTL4_BYTE;
} TCTL41 _IO_AT(0x8B);

/*DEFINE REGISTER*/
#define TCTL4 TCTL41.TCTL4_BYTE

/*DEFINE REGISTER BITS*/
#define EDG0A TCTL41.TCTL4_BITS._EDG0A
#define EDG0B TCTL41.TCTL4_BITS._EDG0B
#define EDG1A TCTL41.TCTL4_BITS._EDG1A
#define EDG1B TCTL41.TCTL4_BITS._EDG1B
#define EDG2A TCTL41.TCTL4_BITS._EDG2A
#define EDG2B TCTL41.TCTL4_BITS._EDG2B
#define EDG3A TCTL41.TCTL4_BITS._EDG3A
#define EDG3B TCTL41.TCTL4_BITS._EDG3B



/*******************************************************************************************/
/*                                TIMER INTERRUPT MASK 1                                   */
/*******************************************************************************************/

__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char _C0I:1;
    unsigned char _C1I:1;
    unsigned char _C2I:1;
    unsigned char _C3I:1;
    unsigned char _C4I:1;
    unsigned char _C5I:1;
    unsigned char _C6I:1;
    unsigned char _C7I:1;
  } TMSK1_BITS;
  unsigned char TMSK1_BYTE;
} TMSK11 _IO_AT(0x8C);

/*DEFINE REGISTER*/
#define TMSK1 TMSK11.TMSK1_BYTE

/*DEFINE REGISTER BITS*/
#define C0I TMSK11.TMSK1_BITS._C0I
#define C1I TMSK11.TMSK1_BITS._C1I
#define C2I TMSK11.TMSK1_BITS._C2I
#define C3I TMSK11.TMSK1_BITS._C3I
#define C4I TMSK11.TMSK1_BITS._C4I
#define C5I TMSK11.TMSK1_BITS._C5I
#define C6I TMSK11.TMSK1_BITS._C6I
#define C7I TMSK11.TMSK1_BITS._C7I




/*******************************************************************************************/
/*                                TIMER INTERRUPT MASK 2                                   */
/*******************************************************************************************/

__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char _PR0:1;
    unsigned char _PR1:1;
    unsigned char _PR2:1;
    unsigned char _TCRE:1;
    unsigned char _RDPT:1;
    unsigned char _PUPT:1;
    unsigned char _BIT6:1;
    unsigned char _TOI:1;
  } TMSK2_BITS;
  unsigned char TMSK2_BYTE;
} TMSK21 _IO_AT(0x8D);

/*DEFINE REGISTER*/
#define TMSK2 TMSK21.TMSK2_BYTE

/*DEFINE REGISTER BITS*/
#define PR0 TMSK21.TMSK2_BITS._PR0
#define PR1 TMSK21.TMSK2_BITS._PR1
#define PR2 TMSK21.TMSK2_BITS._PR2
#define TCRE TMSK21.TMSK2_BITS._TCRE
#define RDPT TMSK21.TMSK2_BITS._RDPT
#define PUPT TMSK21.TMSK2_BITS._PUPT
#define TOI TMSK21.TMSK2_BITS._TOI


/*******************************************************************************************/
/*                                TIMER INTERRUPT FLAG 1                                   */
/*******************************************************************************************/

__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char _C0F:1;
    unsigned char _C1F:1;
    unsigned char _C2F:1;
    unsigned char _C3F:1;
    unsigned char _C4F:1;
    unsigned char _C5F:1;
    unsigned char _C6F:1;
    unsigned char _C7F:1;
  } TFLG1_BITS;
  unsigned char TFLG1_BYTE;
} TFLG11 _IO_AT(0x8E);

/*DEFINE REGISTER*/
#define TFLG1 TFLG11.TFLG1_BYTE

/*DEFINE REGISTER BITS*/
#define C0F TFLG11.TFLG1_BITS._C0F
#define C1F TFLG11.TFLG1_BITS._C1F
#define C2F TFLG11.TFLG1_BITS._C2F
#define C3F TFLG11.TFLG1_BITS._C3F
#define C4F TFLG11.TFLG1_BITS._C4F
#define C5F TFLG11.TFLG1_BITS._C5F
#define C6F TFLG11.TFLG1_BITS._C6F
#define C7F TFLG11.TFLG1_BITS._C7F



/*******************************************************************************************/
/*                                TIMER INTERRUPT FLAG 2                                   */
/*******************************************************************************************/

__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char BIT0:1;
    unsigned char BIT1:1;
    unsigned char BIT2:1;
    unsigned char BIT3:1;
    unsigned char BIT4:1;
    unsigned char BIT5:1;
    unsigned char BIT6:1;
    unsigned char _TOF:1;
  } TFLG2_BITS;
  unsigned char TFLG2_BYTE;
} TFLG21 _IO_AT(0x8F);

/*DEFINE REGISTER*/
#define TFLG2 TFLG21.TFLG2_BYTE

/*DEFINE REGISTER BITS*/
#define TOF TFLG21.TFLG2_BITS._TOF


/*******************************************************************************************/
/*                         TIMER INPUT CAPTURE/OUTPUT REGISTERS                            */
/*******************************************************************************************/

/*****TIMER INPUT CAPTURE/OUTPUT REGISTER 0*****/
__DECL__6812DG128A_H__ volatile unsigned short TC0      _IO_AT(0x90);


/*****TIMER INPUT CAPTURE/OUTPUT REGISTER 1*****/
__DECL__6812DG128A_H__ volatile unsigned short TC1      _IO_AT(0x92);


/*****TIMER INPUT CAPTURE/OUTPUT REGISTER 2*****/
__DECL__6812DG128A_H__ volatile unsigned short TC2      _IO_AT(0x94);


/*****TIMER INPUT CAPTURE/OUTPUT REGISTER 3*****/
__DECL__6812DG128A_H__ volatile unsigned short TC3      _IO_AT(0x96);


/*****TIMER INPUT CAPTURE/OUTPUT REGISTER 4*****/
__DECL__6812DG128A_H__ volatile unsigned short TC4      _IO_AT(0x98);


/*****TIMER INPUT CAPTURE/OUTPUT REGISTER 5*****/
__DECL__6812DG128A_H__ volatile unsigned short TC5      _IO_AT(0x9a);


/*****TIMER INPUT CAPTURE/OUTPUT REGISTER 6*****/
__DECL__6812DG128A_H__ volatile unsigned short TC6      _IO_AT(0x9c);


/*****TIMER INPUT CAPTURE/OUTPUT REGISTER 7*****/
__DECL__6812DG128A_H__ volatile unsigned short TC7      _IO_AT(0x9e);



/*******************************************************************************************/
/*                        PULSE ACCUMULATOR CONTROL REGISTER                               */
/*******************************************************************************************/

__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char _PAI:1;
    unsigned char _PAOVI:1;
    unsigned char _CLK0:1;
    unsigned char _CLK1:1;
    unsigned char _PEDGE:1;
    unsigned char _PAMOD:1;
    unsigned char _PAEN:1;
    unsigned char BIT7:1;
  } PACTL_BITS;
  unsigned char PACTL_BYTE;
} PACTL1 _IO_AT(0xA0);

/*DEFINE REGISTER*/
#define PACTL PACTL1.PACTL_BYTE

/*DEFINE REGISTER BITS*/
#define PAI PACTL1.PACTL_BITS._PAI
#define PAOVI PACTL1.PACTL_BITS._PAOVI
#define CLK0 PACTL1.PACTL_BITS._CLK0
#define CLK1 PACTL1.PACTL_BITS._CLK1
#define PEDGE PACTL1.PACTL_BITS._PEDGE
#define PAMOD PACTL1.PACTL_BITS._PAMOD
#define PAEN PACTL1.PACTL_BITS._PAEN



/*******************************************************************************************/
/*                         PULSE ACCUMULATOR FLAG REGISTER                                 */
/*******************************************************************************************/

__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char _PAIF:1;
    unsigned char _PAOVF:1;
    unsigned char BIT2:1;
    unsigned char BIT3:1;
    unsigned char BIT4:1;
    unsigned char BIT5:1;
    unsigned char BIT6:1;
    unsigned char BIT7:1;
  } PAFLG_BITS;
  unsigned char PAFLG_BYTE;
} PAFLG1 _IO_AT(0xA1);

/*DEFINE REGISTER*/
#define PAFLG PAFLG1.PAFLG_BYTE

/*DEFINE REGISTER BITS*/
#define PAIF PAFLG1.PAFLG_BITS._PAIF
#define PAOVF PAFLG1.PAFLG_BITS._PAOVF



/*******************************************************************************************/
/*                      16-BITS PULSE ACCUMULATOR COUNT REGISTERS                          */
/*******************************************************************************************/

__DECL__6812DG128A_H__ volatile unsigned char PACN3    _IO_AT(0xa2);
__DECL__6812DG128A_H__ volatile unsigned char PACN2    _IO_AT(0xa3);
__DECL__6812DG128A_H__ volatile unsigned char PACN1    _IO_AT(0xa4);
__DECL__6812DG128A_H__ volatile unsigned char PACN0    _IO_AT(0xa5);


/*******************************************************************************************/
/*                  16-BIT MODULUS DOWN-COUNTER CONTROL REGISTER                           */
/*******************************************************************************************/

__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char _MCPR0:1;
    unsigned char _MCPR1:1;
    unsigned char _MCEN:1;
    unsigned char _FLMC:1;
    unsigned char _ICLAT:1;
    unsigned char _RDMCL:1;
    unsigned char _MODMC:1;
    unsigned char _MCZI:1;
  } MCCTL_BITS;
  unsigned char MCCTL_BYTE;
} MCCTL1 _IO_AT(0xA6);

/*DEFINE REGISTER*/
#define MCCTL MCCTL1.MCCTL_BYTE

/*DEFINE REGISTER BITS*/
#define MCPR0 MCCTL1.MCCTL_BITS._MCPR0
#define MCPR1 MCCTL1.MCCTL_BITS._MCPR1
#define MCEN MCCTL1.MCCTL_BITS._MCEN
#define FLMC MCCTL1.MCCTL_BITS._FLMC
#define ICLAT MCCTL1.MCCTL_BITS._ICLAT
#define RDMCL MCCTL1.MCCTL_BITS._RDMCL
#define MODMC MCCTL1.MCCTL_BITS._MODMC
#define MCZI MCCTL1.MCCTL_BITS._MCZI



/*******************************************************************************************/
/*                     16-BIT MODULUS DOWN-COUNTER FLAG REGISTER                           */
/*******************************************************************************************/

__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char _POLF0:1;
    unsigned char _POLF1:1;
    unsigned char _POLF2:1;
    unsigned char _POLF3:1;
    unsigned char BIT4:1;
    unsigned char BIT5:1;
    unsigned char BIT6:1;
    unsigned char _MCZF:1;
  } MCFLG_BITS;
  unsigned char MCFLG_BYTE;
} MCFLG1 _IO_AT(0xA7);

/*DEFINE REGISTER*/
#define MCFLG MCFLG1.MCFLG_BYTE

/*DEFINE REGISTER BITS*/
#define POLF0 MCFLG1.MCFLG_BITS._POLF0
#define POLF1 MCFLG1.MCFLG_BITS._POLF1
#define POLF2 MCFLG1.MCFLG_BITS._POLF2
#define POLF3 MCFLG1.MCFLG_BITS._POLF3
#define MCZF MCFLG1.MCFLG_BITS._MCZF



/*******************************************************************************************/
/*                     INPUT CONTROL PULSE ACCUMULATORS REGISTER                           */
/*******************************************************************************************/

__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char _PA0EN:1;
    unsigned char _PA1EN:1;
    unsigned char _PA2EN:1;
    unsigned char _PA3EN:1;
    unsigned char BIT4:1;
    unsigned char BIT5:1;
    unsigned char BIT6:1;
    unsigned char BIT7:1;
  } ICPAR_BITS;
  unsigned char ICPAR_BYTE;
} ICPAR1 _IO_AT(0xA8);

/*DEFINE REGISTER*/
#define ICPAR ICPAR1.ICPAR_BYTE

/*DEFINE REGISTER BITS*/
#define PA0EN ICPAR1.ICPAR_BITS._PA0EN
#define PA1EN ICPAR1.ICPAR_BITS._PA1EN
#define PA2EN ICPAR1.ICPAR_BITS._PA2EN
#define PA3EN ICPAR1.ICPAR_BITS._PA3EN



/*******************************************************************************************/
/*                              DELAY COUNTER CONTROL REGISTER                             */
/*******************************************************************************************/

__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char _DLY0:1;
    unsigned char _DLY1:1;
    unsigned char BIT2EN:1;
    unsigned char BIT3EN:1;
    unsigned char BIT4:1;
    unsigned char BIT5:1;
    unsigned char BIT6:1;
    unsigned char BIT7:1;
  } DLYCT_BITS;
  unsigned char DLYCT_BYTE;
} DLYCT1 _IO_AT(0xA9);

/*DEFINE REGISTER*/
#define DLYCT DLYCT1.DLYCT_BYTE

/*DEFINE REGISTER BITS*/
#define DLY0 DLYCT1.DLYCT_BITS._DLY0
#define DLY1 DLYCT1.DLYCT_BITS._DLY1



/*******************************************************************************************/
/*                              INPUT CONTROL OVERWRITE REGISTER                           */
/*******************************************************************************************/

__DECL__6812DG128A_H__ volatile unsigned char ICOVW    _IO_AT(0xAA);


/*******************************************************************************************/
/*                            INPUT CONTROL SYSTEM CONTROL REGISTER                        */
/*******************************************************************************************/

__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char _LATQ:1;
    unsigned char _BUFEN:1;
    unsigned char _PACMX:1;
    unsigned char _TFMOD:1;
    unsigned char _SH04:1;
    unsigned char _SH15:1;
    unsigned char _SH26:1;
    unsigned char _SH37:1;
  } ICSYS_BITS;
  unsigned char ICSYS_BYTE;
} ICSYS1 _IO_AT(0xAB);

/*DEFINE REGISTER*/
#define ICSYS ICSYS1.ICSYS_BYTE

/*DEFINE REGISTER BITS*/
#define LATQ ICSYS1.ICSYS_BITS._LATQ
#define BUFEN ICSYS1.ICSYS_BITS._BUFEN
#define PACMX ICSYS1.ICSYS_BITS._PACMX
#define TFMOD ICSYS1.ICSYS_BITS._TFMOD
#define SH04 ICSYS1.ICSYS_BITS._SH04
#define SH15 ICSYS1.ICSYS_BITS._SH15
#define SH26 ICSYS1.ICSYS_BITS._SH26
#define SH37 ICSYS1.ICSYS_BITS._SH37


/*******************************************************************************************/
/*                                  TIMER TEST REGISTER                                    */
/*******************************************************************************************/

__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char BIT0:1;
    unsigned char _TCBYP:1;
    unsigned char BIT2:1;
    unsigned char BIT3:1;
    unsigned char BIT4:1;
    unsigned char BIT5:1;
    unsigned char BIT6:1;
    unsigned char BIT7:1;
  } TIMTST_BITS;
  unsigned char TIMTST_BYTE;
} TIMTST1 _IO_AT(0xAD);

/*DEFINE REGISTER*/
#define TIMTST TIMTST1.TIMTST_BYTE

/*DEFINE REGISTER BITS*/
#define TCBYP TIMTST1.TIMTST_BITS._TCBYP



/*******************************************************************************************/
/*                                  TIMER PORT DATA REGISTER                               */
/*******************************************************************************************/

/*****PORT T DEFINITION*****/

__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char _I_OC0:1;
    unsigned char _I_OC1:1;
    unsigned char _I_OC2:1;
    unsigned char _I_OC3:1;
    unsigned char _I_OC4:1;
    unsigned char _I_OC5:1;
    unsigned char _I_OC6:1;
    unsigned char _I_OC7:1;
  } PORTT_BITS;
  unsigned char PORTT_BYTE;
} PORTT1 _IO_AT(0xAE);

/*DEFINE REGISTER*/
#define PORTT PORTT1.PORTT_BYTE

/*DEFINE REGISTER BITS*/
#define I_OC0 PORTT1.PORTT_BITS._I_OC0
#define I_OC1 PORTT1.PORTT_BITS._I_OC1
#define I_OC2 PORTT1.PORTT_BITS._I_OC2
#define I_OC3 PORTT1.PORTT_BITS._I_OC3
#define I_OC4 PORTT1.PORTT_BITS._I_OC4
#define I_OC5 PORTT1.PORTT_BITS._I_OC5
#define I_OC6 PORTT1.PORTT_BITS._I_OC6
#define I_OC7 PORTT1.PORTT_BITS._I_OC7

/*****DATA DIRECTION REGISTER FOR TIMER OUT*****/
__DECL__6812DG128A_H__ volatile unsigned char DDRT     _IO_AT(0xaf);


/*******************************************************************************************/
/*                         16-BIT PULSE ACCUMULATOR B CONTROL REGISTER                     */
/*******************************************************************************************/

__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char BIT0:1;
    unsigned char _PB0VI:1;
    unsigned char BIT2:1;
    unsigned char BIT3:1;
    unsigned char BIT4:1;
    unsigned char BIT5:1;
    unsigned char _PBEN:1;
    unsigned char BIT7:1;
  } PBCTL_BITS;
  unsigned char PBCTL_BYTE;
} PBCTL1 _IO_AT(0xB0);

/*DEFINE REGISTER*/
#define PBCTL PBCTL1.PBCTL_BYTE

/*DEFINE REGISTER BITS*/
#define PB0VI PBCTL1.PBCTL_BITS._PB0VI
#define PBEN PBCTL1.PBCTL_BITS._PBEN



/*******************************************************************************************/
/*                         16-BIT PULSE ACCUMULATOR B FLAG REGISTER                        */
/*******************************************************************************************/

__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char BIT0:1;
    unsigned char _PB0VF:1;
    unsigned char BIT2:1;
    unsigned char BIT3:1;
    unsigned char BIT4:1;
    unsigned char BIT5:1;
    unsigned char BIT6:1;
    unsigned char BIT7:1;
  } PBFLG_BITS;
  unsigned char PBFLG_BYTE;
} PBFLG1 _IO_AT(0xB1);

/*DEFINE REGISTER*/
#define PBFLG PBFLG1.PBFLG_BYTE

/*DEFINE REGISTER BITS*/
#define PB0VF PBFLG1.PBFLG_BITS._PB0VF


/*******************************************************************************************/
/*                      8-BIT PULSE ACCUMULATORS HOLDING REGISTERS                         */
/*******************************************************************************************/

__DECL__6812DG128A_H__ volatile unsigned char PA3H    _IO_AT(0xB2);
__DECL__6812DG128A_H__ volatile unsigned char PA2H    _IO_AT(0xB3);
__DECL__6812DG128A_H__ volatile unsigned char PA1H    _IO_AT(0xB4);
__DECL__6812DG128A_H__ volatile unsigned char PA0H    _IO_AT(0xB5);


/*******************************************************************************************/
/*                              MODULUS DOWN-COUNTER REGISTERS                             */
/*******************************************************************************************/

__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char _MCCNTH;
    unsigned char _MCCNTL;
  } SC0BDH_BYTES;
  unsigned short MCCNTW;
} _MCCNT _IO_AT(0xB6);

#define MCCNTW _MCCNT.MCCNTW    /* Modulus down-counter word */
#define MCCNTH _MCCNT.SC0BDH_BYTES._MCCNTH   /* Modulus down-counter high */
#define MCCNTL _MCCNT.SC0BDH_BYTES._MCCNTL   /* Modulus down-counter low */

/*******************************************************************************************/
/*                         TIMER INPUT CAPTURE HOLDING REGISTERS                           */
/*******************************************************************************************/

__DECL__6812DG128A_H__ volatile unsigned short TC0H   _IO_AT(0xB8); /* Timer Input Capture Holding Register 0 */
__DECL__6812DG128A_H__ volatile unsigned short TC1H   _IO_AT(0xBA); /* Timer Input Capture Holding Register 1 */
__DECL__6812DG128A_H__ volatile unsigned short TC2H   _IO_AT(0xBC); /* Timer Input Capture Holding Register 2 */
__DECL__6812DG128A_H__ volatile unsigned short TC3H   _IO_AT(0xBE); /* Timer Input Capture Holding Register 3 */


/*******************************************************************************************/
/*                            SCI BAUD RATE CONTROL REGISTERS 0                            */
/*******************************************************************************************/


/*****SCI BAUD RATE CONTROL REGISTER 0 HIGH*****/
__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char _SBR8_0:1;
    unsigned char _SBR9_0:1;
    unsigned char _SBR10_0:1;
    unsigned char _SBR11_0:1;
    unsigned char _SBR12_0:1;
    unsigned char _BRLD_0:1;
    unsigned char _BSPL_0:1;
    unsigned char _BTST_0:1;
  } SC0BDH_BITS;
  unsigned char SC0BDH_BYTE;
} SC0BDH1 _IO_AT(0xC0);

/*DEFINE REGISTER*/
#define SC0BDH SC0BDH1.SC0BDH_BYTE

/*DEFINE REGISTER BITS*/
#define SBR8_0 SC0BDH1.SC0BDH_BITS._SBR8_0
#define SBR9_0 SC0BDH1.SC0BDH_BITS._SBR9_0
#define SBR10_0 SC0BDH1.SC0BDH_BITS._SBR10_0
#define SBR11_0 SC0BDH1.SC0BDH_BITS._SBR11_0
#define SBR12_0 SC0BDH1.SC0BDH_BITS._SBR12_0
#define BRLD_0 SC0BDH1.SC0BDH_BITS._BRLD_0
#define BSPL_0 SC0BDH1.SC0BDH_BITS._BSPL_0
#define BTST_0 SC0BDH1.SC0BDH_BITS._BTST_0


/*****SCI BAUD RATE CONTROL REGISTER 0 LOW*****/
__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char _SBR0_0:1;
    unsigned char _SBR1_0:1;
    unsigned char _SBR2_0:1;
    unsigned char _SBR3_0:1;
    unsigned char _SBR4_0:1;
    unsigned char _SBR5_0:1;
    unsigned char _SBR6_0:1;
    unsigned char _SBR7_0:1;
  } SC0BDL_BITS;
  unsigned char SC0BDL_BYTE;
} SC0BDL1 _IO_AT(0xC1);

/*DEFINE REGISTER*/
#define SC0BDL SC0BDL1.SC0BDL_BYTE

/*DEFINE REGISTER BITS*/
#define SBR0_0 SC0BDL1.SC0BDL_BITS._SBR0_0
#define SBR1_0 SC0BDL1.SC0BDL_BITS._SBR1_0
#define SBR2_0 SC0BDL1.SC0BDL_BITS._SBR2_0
#define SBR3_0 SC0BDL1.SC0BDL_BITS._SBR3_0
#define SBR4_0 SC0BDL1.SC0BDL_BITS._SBR4_0
#define SBR5_0 SC0BDL1.SC0BDL_BITS._SBR5_0
#define SBR6_0 SC0BDL1.SC0BDL_BITS._SBR6_0
#define SBR7_0 SC0BDL1.SC0BDL_BITS._SBR7_0



/*******************************************************************************************/
/*                                 SCI 0 CONTROL REGISTERS                                 */
/*******************************************************************************************/


/*****SCI 0 CONTROL REGISTER 1*****/
__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char _PT_0:1;
    unsigned char _PE_0:1;
    unsigned char _ILT_0:1;
    unsigned char _WAKE_0:1;
    unsigned char _M_0:1;
    unsigned char _RSRC_0:1;
    unsigned char _WOMS_0:1;
    unsigned char _LOOPS_0:1;
  } SC0CR1_BITS;
  unsigned char SC0CR1_BYTE;
} SC0CR11 _IO_AT(0xC2);

/*DEFINE REGISTER*/
#define SC0CR1 SC0CR11.SC0CR1_BYTE

/*DEFINE REGISTER BITS*/
#define PT_0 SC0CR11.SC0CR1_BITS._PT_0
#define PE_0 SC0CR11.SC0CR1_BITS._PE_0
#define ILT_0 SC0CR11.SC0CR1_BITS._ILT_0
#define WAKE_0 SC0CR11.SC0CR1_BITS._WAKE_0
#define M_0 SC0CR11.SC0CR1_BITS._M_0
#define RSRC_0 SC0CR11.SC0CR1_BITS._RSRC_0
#define WOMS_0 SC0CR11.SC0CR1_BITS._WOMS_0
#define LOOPS_0 SC0CR11.SC0CR1_BITS._LOOPS_0


/*****SCI 0 CONTROL REGISTER 2*****/
__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char _SBK_0:1;
    unsigned char _RWU_0:1;
    unsigned char _RE_0:1;
    unsigned char _TE_0:1;
    unsigned char _ILIE_0:1;
    unsigned char _RIE_0:1;
    unsigned char _TCIE_0:1;
    unsigned char _TIE_0:1;
  } SC0CR2_BITS;
  unsigned char SC0CR2_BYTE;
} SC0CR21 _IO_AT(0xC3);

/*DEFINE REGISTER*/
#define SC0CR2 SC0CR21.SC0CR2_BYTE

/*DEFINE REGISTER BITS*/
#define SBK_0 SC0CR21.SC0CR2_BITS._SBK_0
#define RWU_0 SC0CR21.SC0CR2_BITS._RWU_0
#define RE_0 SC0CR21.SC0CR2_BITS._RE_0
#define TE_0 SC0CR21.SC0CR2_BITS._TE_0
#define ILIE_0 SC0CR21.SC0CR2_BITS._ILIE_0
#define RIE_0 SC0CR21.SC0CR2_BITS._RIE_0
#define TCIE_0 SC0CR21.SC0CR2_BITS._TCIE_0
#define TIE_0 SC0CR21.SC0CR2_BITS._TIE_0


/*******************************************************************************************/
/*                                   SCI STATUS REGISTERS 0                                */
/*******************************************************************************************/


/*****SCI 0 STATUS REGISTER 1*****/
__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char _PF_0:1;
    unsigned char _FE_0:1;
    unsigned char _NF_0:1;
    unsigned char _OR_0:1;
    unsigned char _IDLE_0:1;
    unsigned char _RDRF_0:1;
    unsigned char _TC_0:1;
    unsigned char _TDRE_0:1;
  } SC0SR1_BITS;
  unsigned char SC0SR1_BYTE;
} SC0SR11 _IO_AT(0xC4);

/*DEFINE REGISTER*/
#define SC0SR1 SC0SR11.SC0SR1_BYTE

/*DEFINE REGISTER BITS*/
#define PF_0 SC0SR11.SC0SR1_BITS._PF_0
#define FE_0 SC0SR11.SC0SR1_BITS._FE_0
#define NF_0 SC0SR11.SC0SR1_BITS._NF_0
#define OR_0 SC0SR11.SC0SR1_BITS._OR_0
#define IDLE_0 SC0SR11.SC0SR1_BITS._IDLE_0
#define RDRF_0 SC0SR11.SC0SR1_BITS._RDRF_0
#define TC_0 SC0SR11.SC0SR1_BITS._TC_0
#define TDRE_0 SC0SR11.SC0SR1_BITS._TDRE_0



/*****SCI 0 STATUS REGISTER 2*****/
__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char _RAF_0:1;
    unsigned char BIT1:1;
    unsigned char BIT2:1;
    unsigned char BIT3:1;
    unsigned char BIT4:1;
    unsigned char BIT5:1;
    unsigned char BIT6:1;
    unsigned char BIT7:1;
  } SC0SR2_BITS;
  unsigned char SC0SR2_BYTE;
} SC0SR21 _IO_AT(0xC5);

/*DEFINE REGISTER*/
#define SC0SR2 SC0SR21.SC0SR2_BYTE

/*DEFINE REGISTER BITS*/
#define RAF_0 SC0SR21.SC0SR2_BITS._RAF_0



/*******************************************************************************************/
/*                                   SCI DATA REGISTERS 0                                  */
/*******************************************************************************************/


/*****SCI DATA REGISTER 0 HIGH*****/
__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char BIT0:1;
    unsigned char BIT1:1;
    unsigned char BIT2:1;
    unsigned char BIT3:1;
    unsigned char BIT4:1;
    unsigned char BIT5:1;
    unsigned char _T8_0:1;
    unsigned char _R8_0:1;
  } SC0DRH_BITS;
  unsigned char SC0DRH_BYTE;
} SC0DRH1 _IO_AT(0xC6);

/*DEFINE REGISTER*/
#define SC0DRH SC0DRH1.SC0DRH_BYTE

/*DEFINE REGISTER BITS*/
#define T8_0 SC0DRH1.SC0DRH_BITS._T8_0
#define R8_0 SC0DRH1.SC0DRH_BITS._R8_0




/*****SCI DATA REGISTER 0 LOW*****/
__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char _R0_T0_0:1;
    unsigned char _R1_T1_0:1;
    unsigned char _R2_T2_0:1;
    unsigned char _R3_T3_0:1;
    unsigned char _R4_T4_0:1;
    unsigned char _R5_T5_0:1;
    unsigned char _R6_T6_0:1;
    unsigned char _R7_T7_0:1;
  } SC0DRL_BITS;
  unsigned char SC0DRL_BYTE;
} SC0DRL1 _IO_AT(0xC7);

/*DEFINE REGISTER*/
#define SC0DRL SC0DRL1.SC0DRL_BYTE

/*DEFINE REGISTER BITS*/
#define R0_T0_0 SC0DRL1.SC0DRL_BITS._R0_T0_0
#define R1_T1_0 SC0DRL1.SC0DRL_BITS._R1_T1_0
#define R2_T2_0 SC0DRL1.SC0DRL_BITS._R2_T2_0
#define R3_T3_0 SC0DRL1.SC0DRL_BITS._R3_T3_0
#define R4_T4_0 SC0DRL1.SC0DRL_BITS._R4_T4_0
#define R5_T5_0 SC0DRL1.SC0DRL_BITS._R5_T5_0
#define R6_T6_0 SC0DRL1.SC0DRL_BITS._R6_T6_0
#define R7_T7_0 SC0DRL1.SC0DRL_BITS._R7_T7_0


/*******************************************************************************************/
/*                            SCI BAUD RATE CONTROL REGISTERS 1                            */
/*******************************************************************************************/


/*****SCI BAUD RATE CONTROL REGISTER 1 HIGH*****/
__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char _SBR8_1:1;
    unsigned char _SBR9_1:1;
    unsigned char _SBR10_1:1;
    unsigned char _SBR11_1:1;
    unsigned char _SBR12_1:1;
    unsigned char _BRLD_1:1;
    unsigned char _BSPL_1:1;
    unsigned char _BTST_1:1;
  } SC1BDH_BITS;
  unsigned char SC1BDH_BYTE;
} SC1BDH1 _IO_AT(0xC8);

/*DEFINE REGISTER*/
#define SC1BDH SC1BDH1.SC1BDH_BYTE

/*DEFINE REGISTER BITS*/
#define SBR8_1 SC1BDH1.SC1BDH_BITS._SBR8_1
#define SBR9_1 SC1BDH1.SC1BDH_BITS._SBR9_1
#define SBR10_1 SC1BDH1.SC1BDH_BITS._SBR10_1
#define SBR11_1 SC1BDH1.SC1BDH_BITS._SBR11_1
#define SBR12_1 SC1BDH1.SC1BDH_BITS._SBR12_1
#define BRLD_1 SC1BDH1.SC1BDH_BITS._BRLD_1
#define BSPL_1 SC1BDH1.SC1BDH_BITS._BSPL_1
#define BTST_1 SC1BDH1.SC1BDH_BITS._BTST_1


/*****SCI BAUD RATE CONTROL REGISTER 1 LOW*****/
__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char _SBR0_1:1;
    unsigned char _SBR1_1:1;
    unsigned char _SBR2_1:1;
    unsigned char _SBR3_1:1;
    unsigned char _SBR4_1:1;
    unsigned char _SBR5_1:1;
    unsigned char _SBR6_1:1;
    unsigned char _SBR7_1:1;
  } SC1BDL_BITS;
  unsigned char SC1BDL_BYTE;
} SC1BDL1 _IO_AT(0xC9);

/*DEFINE REGISTER*/
#define SC1BDL SC1BDL1.SC1BDL_BYTE

/*DEFINE REGISTER BITS*/
#define SBR0_1 SC1BDL1.SC1BDL_BITS._SBR0_1
#define SBR1_1 SC1BDL1.SC1BDL_BITS._SBR1_1
#define SBR2_1 SC1BDL1.SC1BDL_BITS._SBR2_1
#define SBR3_1 SC1BDL1.SC1BDL_BITS._SBR3_1
#define SBR4_1 SC1BDL1.SC1BDL_BITS._SBR4_1
#define SBR5_1 SC1BDL1.SC1BDL_BITS._SBR5_1
#define SBR6_1 SC1BDL1.SC1BDL_BITS._SBR6_1
#define SBR7_1 SC1BDL1.SC1BDL_BITS._SBR7_1



/*******************************************************************************************/
/*                                 SCI 1 CONTROL REGISTERS                                 */
/*******************************************************************************************/


/*****SCI 1 CONTROL REGISTER 1*****/
__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char _PT_1:1;
    unsigned char _PE_1:1;
    unsigned char _ILT_1:1;
    unsigned char _WAKE_1:1;
    unsigned char _M_1:1;
    unsigned char _RSRC_1:1;
    unsigned char _WOMS_1:1;
    unsigned char _LOOPS_1:1;
  } SC1CR1_BITS;
  unsigned char SC1CR1_BYTE;
} SC1CR11 _IO_AT(0xCA);

/*DEFINE REGISTER*/
#define SC1CR1 SC1CR11.SC1CR1_BYTE

/*DEFINE REGISTER BITS*/
#define PT_1 SC1CR11.SC1CR1_BITS._PT_1
#define PE_1 SC1CR11.SC1CR1_BITS._PE_1
#define ILT_1 SC1CR11.SC1CR1_BITS._ILT_1
#define WAKE_1 SC1CR11.SC1CR1_BITS._WAKE_1
#define M_1 SC1CR11.SC1CR1_BITS._M_1
#define RSRC_1 SC1CR11.SC1CR1_BITS._RSRC_1
#define WOMS_1 SC1CR11.SC1CR1_BITS._WOMS_1
#define LOOPS_1 SC1CR11.SC1CR1_BITS._LOOPS_1


/*****SCI 1 CONTROL REGISTER 2*****/
__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char _SBK_1:1;
    unsigned char _RWU_1:1;
    unsigned char _RE_1:1;
    unsigned char _TE_1:1;
    unsigned char _ILIE_1:1;
    unsigned char _RIE_1:1;
    unsigned char _TCIE_1:1;
    unsigned char _TIE_1:1;
  } SC1CR2_BITS;
  unsigned char SC1CR2_BYTE;
} SC1CR21 _IO_AT(0xCB);

/*DEFINE REGISTER*/
#define SC1CR2 SC1CR21.SC1CR2_BYTE

/*DEFINE REGISTER BITS*/
#define SBK_1 SC1CR21.SC1CR2_BITS._SBK_1
#define RWU_1 SC1CR21.SC1CR2_BITS._RWU_1
#define RE_1 SC1CR21.SC1CR2_BITS._RE_1
#define TE_1 SC1CR21.SC1CR2_BITS._TE_1
#define ILIE_1 SC1CR21.SC1CR2_BITS._ILIE_1
#define RIE_1 SC1CR21.SC1CR2_BITS._RIE_1
#define TCIE_1 SC1CR21.SC1CR2_BITS._TCIE_1
#define TIE_1 SC1CR21.SC1CR2_BITS._TIE_1


/*******************************************************************************************/
/*                                   SCI STATUS REGISTERS 1                                */
/*******************************************************************************************/


/*****SCI 1 STATUS REGISTER 1*****/
__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char _PF_1:1;
    unsigned char _FE_1:1;
    unsigned char _NF_1:1;
    unsigned char _OR_1:1;
    unsigned char _IDLE_1:1;
    unsigned char _RDRF_1:1;
    unsigned char _TC_1:1;
    unsigned char _TDRE_1:1;
  } SC1SR1_BITS;
  unsigned char SC1SR1_BYTE;
} SC1SR11 _IO_AT(0xCC);

/*DEFINE REGISTER*/
#define SC1SR1 SC1SR11.SC1SR1_BYTE

/*DEFINE REGISTER BITS*/
#define PF_1 SC1SR11.SC1SR1_BITS._PF_1
#define FE_1 SC1SR11.SC1SR1_BITS._FE_1
#define NF_1 SC1SR11.SC1SR1_BITS._NF_1
#define OR_1 SC1SR11.SC1SR1_BITS._OR_1
#define IDLE_1 SC1SR11.SC1SR1_BITS._IDLE_1
#define RDRF_1 SC1SR11.SC1SR1_BITS._RDRF_1
#define TC_1 SC1SR11.SC1SR1_BITS._TC_1
#define TDRE_1 SC1SR11.SC1SR1_BITS._TDRE_1



/*****SCI 1 STATUS REGISTER 2*****/
__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char _RAF_1:1;
    unsigned char BIT1:1;
    unsigned char BIT2:1;
    unsigned char BIT3:1;
    unsigned char BIT4:1;
    unsigned char BIT5:1;
    unsigned char BIT6:1;
    unsigned char BIT7:1;
  } SC1SR2_BITS;
  unsigned char SC1SR2_BYTE;
} SC1SR21 _IO_AT(0xCD);

/*DEFINE REGISTER*/
#define SC1SR2 SC1SR21.SC1SR2_BYTE

/*DEFINE REGISTER BITS*/
#define RAF_1 SC1SR21.SC1SR2_BITS._RAF_1



/*******************************************************************************************/
/*                                   SCI DATA REGISTERS 1                                  */
/*******************************************************************************************/


/*****SCI DATA REGISTER 1 HIGH*****/
__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char BIT0:1;
    unsigned char BIT1:1;
    unsigned char BIT2:1;
    unsigned char BIT3:1;
    unsigned char BIT4:1;
    unsigned char BIT5:1;
    unsigned char _T8_1:1;
    unsigned char _R8_1:1;
  } SC1DRH_BITS;
  unsigned char SC1DRH_BYTE;
} SC1DRH1 _IO_AT(0xCE);

/*DEFINE REGISTER*/
#define SC1DRH SC1DRH1.SC1DRH_BYTE

/*DEFINE REGISTER BITS*/
#define T8_1 SC1DRH1.SC1DRH_BITS._T8_1
#define R8_1 SC1DRH1.SC1DRH_BITS._R8_1




/*****SCI DATA REGISTER 1 LOW*****/
__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char _R0_T0_1:1;
    unsigned char _R1_T1_1:1;
    unsigned char _R2_T2_1:1;
    unsigned char _R3_T3_1:1;
    unsigned char _R4_T4_1:1;
    unsigned char _R5_T5_1:1;
    unsigned char _R6_T6_1:1;
    unsigned char _R7_T7_1:1;
  } SC1DRL_BITS;
  unsigned char SC1DRL_BYTE;
} SC1DRL1 _IO_AT(0xCF);

/*DEFINE REGISTER*/
#define SC1DRL SC1DRL1.SC1DRL_BYTE

/*DEFINE REGISTER BITS*/
#define R0_T0_1 SC1DRL1.SC1DRL_BITS._R0_T0_1
#define R1_T1_1 SC1DRL1.SC1DRL_BITS._R1_T1_1
#define R2_T2_1 SC1DRL1.SC1DRL_BITS._R2_T2_1
#define R3_T3_1 SC1DRL1.SC1DRL_BITS._R3_T3_1
#define R4_T4_1 SC1DRL1.SC1DRL_BITS._R4_T4_1
#define R5_T5_1 SC1DRL1.SC1DRL_BITS._R5_T5_1
#define R6_T6_1 SC1DRL1.SC1DRL_BITS._R6_T6_1
#define R7_T7_1 SC1DRL1.SC1DRL_BITS._R7_T7_1



/*******************************************************************************************/
/*                                 SPI  CONTROL REGISTERS                                  */
/*******************************************************************************************/


/*****SPI CONTROL REGISTER 1*****/
__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char _LSBF:1;
    unsigned char _SSOE:1;
    unsigned char _CPHA:1;
    unsigned char _CPOL:1;
    unsigned char _MSTR:1;
    unsigned char _SWOM:1;
    unsigned char _SPE:1;
    unsigned char _SPIE:1;
  } SP0CR1_BITS;
  unsigned char SP0CR1_BYTE;
} SP0CR11 _IO_AT(0xD0);

/*DEFINE REGISTER*/
#define SP0CR1 SP0CR11.SP0CR1_BYTE

/*DEFINE REGISTER BITS*/
#define LSBF SP0CR11.SP0CR1_BITS._LSBF
#define SSOE SP0CR11.SP0CR1_BITS._SSOE
#define CPHA SP0CR11.SP0CR1_BITS._CPHA
#define CPOL SP0CR11.SP0CR1_BITS._CPOL
#define MSTR SP0CR11.SP0CR1_BITS._MSTR
#define SWOM SP0CR11.SP0CR1_BITS._SWOM
#define SPE SP0CR11.SP0CR1_BITS._SPE
#define SPIE SP0CR11.SP0CR1_BITS._SPIE


/*****SPI CONTROL REGISTER 2*****/
__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char _SPC0:1;
    unsigned char _SSWAI:1;
    unsigned char _RDPS:1;
    unsigned char _PUPS:1;
    unsigned char BIT4:1;
    unsigned char BIT5:1;
    unsigned char BIT6:1;
    unsigned char BIT7:1;
  } SP0CR2_BITS;
  unsigned char SP0CR2_BYTE;
} SP0CR21 _IO_AT(0xD1);

/*DEFINE REGISTER*/
#define SP0CR2 SP0CR21.SP0CR2_BYTE

/*DEFINE REGISTER BITS*/
#define SPC0 SP0CR21.SP0CR2_BITS._SPC0
#define SSWAI SP0CR21.SP0CR2_BITS._SSWAI
#define RDPS SP0CR21.SP0CR2_BITS._RDPS
#define PUPS SP0CR21.SP0CR2_BITS._PUPS



/*******************************************************************************************/
/*                                 SPI BAUD RATE REGISTER                                  */
/*******************************************************************************************/


__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char _SPR0:1;
    unsigned char _SPR1:1;
    unsigned char _SPR2:1;
    unsigned char BIT3:1;
    unsigned char BIT4:1;
    unsigned char BIT5:1;
    unsigned char BIT6:1;
    unsigned char BIT7:1;
  } SP0BR_BITS;
  unsigned char SP0BR_BYTE;
} SP0BR1 _IO_AT(0xD2);

/*DEFINE REGISTER*/
#define SP0BR SP0BR1.SP0BR_BYTE

/*DEFINE REGISTER BITS*/
#define SPR0 SP0BR1.SP0BR_BITS._SPR0
#define SPR1 SP0BR1.SP0BR_BITS._SPR1
#define SPR2 SP0BR1.SP0BR_BITS._SPR2



/*******************************************************************************************/
/*                                    SPI STATUS REGISTER                                  */
/*******************************************************************************************/


__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char BIT0:1;
    unsigned char BIT1:1;
    unsigned char BIT2:1;
    unsigned char BIT3:1;
    unsigned char _MODF:1;
    unsigned char BIT5:1;
    unsigned char _WCOL:1;
    unsigned char _SPIF:1;
  } SP0SR_BITS;
  unsigned char SP0SR_BYTE;
} SP0SR1 _IO_AT(0xD3);

/*DEFINE REGISTER*/
#define SP0SR SP0SR1.SP0SR_BYTE

/*DEFINE REGISTER BITS*/
#define MODF SP0SR1.SP0SR_BITS._MODF
#define WCOL SP0SR1.SP0SR_BITS._WCOL
#define SPIF SP0SR1.SP0SR_BITS._SPIF




/*******************************************************************************************/
/*                                   SCI DATA REGISTERS                                    */
/*******************************************************************************************/

__DECL__6812DG128A_H__ volatile unsigned char SP0DR    _IO_AT(0xd5);


/*******************************************************************************************/
/*                                             PORT S                                      */
/*******************************************************************************************/



/*****PORT S DEFINITION*****/

__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char _RXD0:1;
    unsigned char _TXD0:1;
    unsigned char _I_O1:1;
    unsigned char _I_O2:1;
    unsigned char _MISO_SISO:1;
    unsigned char _MOSI_MOMI:1;
    unsigned char _SCK:1;
    unsigned char _SS__CSA:1;
  } PORTS_BITS;
  unsigned char PORTS_BYTE;
} PORTS1 _IO_AT(0xD6);

/*DEFINE REGISTER*/
#define PORTS PORTS1.PORTS_BYTE

/*DEFINE REGISTER BITS*/
#define RXD0 PORTS1.PORTS_BITS._RXD0
#define TXD0 PORTS1.PORTS_BITS._TXD0
#define I_O1 PORTS1.PORTS_BITS._I_O1
#define I_O2 PORTS1.PORTS_BITS._I_O2
#define MISO_SISO PORTS1.PORTS_BITS._MISO_SISO
#define MOSI_MOMI PORTS1.PORTS_BITS._MOSI_MOMI
#define SCK PORTS1.PORTS_BITS._SCK
#define _SS__CS PORTS1.PORTS_BITS._SS__CSA

/*****DATA DIRECTION REGISTER FOR PORT S*****/
__DECL__6812DG128A_H__ volatile unsigned char DDRS     _IO_AT(0xD7);



/*******************************************************************************************/
/*                                    IIC BUS ADDRESS REGISTER                             */
/*******************************************************************************************/


__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char BIT0:1;
    unsigned char _ADR1:1;
    unsigned char _ADR2:1;
    unsigned char _ADR3:1;
    unsigned char _ADR4:1;
    unsigned char _ADR5:1;
    unsigned char _ADR6:1;
    unsigned char _ADR7:1;
  } IBAD_BITS;
  unsigned char IBAD_BYTE;
} IBAD1 _IO_AT(0xE0);

/*DEFINE REGISTER*/
#define IBAD IBAD1.IBAD_BYTE

/*DEFINE REGISTER BITS*/
#define ADR1 IBAD1.IBAD_BITS._ADR1
#define ADR2 IBAD1.IBAD_BITS._ADR2
#define ADR3 IBAD1.IBAD_BITS._ADR3
#define ADR4 IBAD1.IBAD_BITS._ADR4
#define ADR5 IBAD1.IBAD_BITS._ADR5
#define ADR6 IBAD1.IBAD_BITS._ADR6
#define ADR7 IBAD1.IBAD_BITS._ADR7


/*******************************************************************************************/
/*                          IIC BUS FREQUENCY DIVIDER REGISTER                             */
/*******************************************************************************************/


__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char _IBC0:1;
    unsigned char _IBC1:1;
    unsigned char _IBC2:1;
    unsigned char _IBC3:1;
    unsigned char _IBC4:1;
    unsigned char _IBC5:1;
    unsigned char BIT6:1;
    unsigned char BIT7:1;
  } IBFD_BITS;
  unsigned char IBFD_BYTE;
} IBFD1 _IO_AT(0xE1);

/*DEFINE REGISTER*/
#define IBFD IBFD1.IBFD_BYTE

/*DEFINE REGISTER BITS*/
#define IBC0 IBFD1.IBFD_BITS._IBC0
#define IBC1 IBFD1.IBFD_BITS._IBC1
#define IBC2 IBFD1.IBFD_BITS._IBC2
#define IBC3 IBFD1.IBFD_BITS._IBC3
#define IBC4 IBFD1.IBFD_BITS._IBC4
#define IBC5 IBFD1.IBFD_BITS._IBC5



/*******************************************************************************************/
/*                              IIC BUS CONTROL REGISTER                                   */
/*******************************************************************************************/

__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char _IBSWAI:1;
    unsigned char BIT1:1;
    unsigned char _RSTA:1;
    unsigned char _TXAK:1;
    unsigned char TX_RX_1:1;
    unsigned char MS_SL_1:1;
    unsigned char _IBIE:1;
    unsigned char _IBEN:1;
  } IBCR_BITS;
  unsigned char IBCR_BYTE;
} IBCR1 _IO_AT(0xE2);

/*DEFINE REGISTER*/
#define IBCR IBCR1.IBCR_BYTE

/*DEFINE REGISTER BITS*/
#define IBSWAI IBCR1.IBCR_BITS._IBSWAI
#define RSTA IBCR1.IBCR_BITS._RSTA
#define TXAK IBCR1.IBCR_BITS._TXAK
#define TX_RX_ IBCR1.IBCR_BITS.TX_RX_1
#define MS_SL_ IBCR1.IBCR_BITS.MS_SL_1
#define IBIE IBCR1.IBCR_BITS._IBIE
#define IBEN IBCR1.IBCR_BITS._IBEN



/*******************************************************************************************/
/*                              IIC BUS CONTROL REGISTER                                   */
/*******************************************************************************************/


__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char _RXAK:1;
    unsigned char _IBIF:1;
    unsigned char _SRW:1;
    unsigned char _BIT3:1;
    unsigned char _IBAL:1;
    unsigned char _IBB:1;
    unsigned char _IAAS:1;
    unsigned char _TCF:1;
  } IBSR_BITS;
  unsigned char IBSR_BYTE;
} IBSR1 _IO_AT(0xE3);

/*DEFINE REGISTER*/
#define IBSR IBSR1.IBSR_BYTE

/*DEFINE REGISTER BITS*/
#define RXAK IBSR1.IBSR_BITS._RXAK
#define IBIF IBSR1.IBSR_BITS._IBIF
#define SRW IBSR1.IBSR_BITS._SRW
#define IBAL IBSR1.IBSR_BITS._IBAL
#define IBB IBSR1.IBSR_BITS._IBB
#define IAAS IBSR1.IBSR_BITS._IAAS
#define TCF IBSR1.IBSR_BITS._TCF



/**************************************************************************************************/
/*                              IIC BUS DATA I\O REGISTER                                         */
/**************************************************************************************************/

__DECL__6812DG128A_H__ volatile unsigned char IBDR    _IO_AT(0xE4);



/*******************************************************************************************/
/*                          PULL-UP AND REDUCED DRIVE FOR PORT IB                          */
/*******************************************************************************************/


__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char _PUPIB:1;
    unsigned char BIT1:1;
    unsigned char BIT2:1;
    unsigned char BIT3:1;
    unsigned char _RDPIB:1;
    unsigned char BIT5:1;
    unsigned char BIT6:1;
    unsigned char BIT7:1;
  } IBPURD_BITS;
  unsigned char IBPURD_BYTE;
} IBPURD1 _IO_AT(0xE5);

/*DEFINE REGISTER*/
#define IBPURD IBPURD1.IBPURD_BYTE

/*DEFINE REGISTER BITS*/
#define PUPIB IBPURD1.IBPURD_BITS._PUPIB
#define RDPIB IBPURD1.IBPURD_BITS._RDPIB





/**************************************************************************************************/
/*                                         DEFINE PORT IB                                         */
/**************************************************************************************************/
/* ----------------------------------------------------- */
/* FCOM#1307 : Modify Definitions for Best use of PORT IB */
/* ----------------------------------------------------- */

__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char _PIB0:1;
    unsigned char _PIB1:1;
    unsigned char _PIB2:1;
    unsigned char _PIB3:1;
    unsigned char _PIB4:1;
    unsigned char _PIB5:1;
    unsigned char _PIB6:1;
    unsigned char _PIB7:1;
  } PORTIB_BITS;
  unsigned char PORTIB_BYTE;
} PORTIB1 _IO_AT(0xE6);

/*DEFINE REGISTER*/
#define PORTIB PORTIB1.PORTIB_BYTE

/*DEFINE REGISTER BITS*/
#define PIB0 PORTIB1.PORTIB_BITS._PIB0
#define PIB1 PORTIB1.PORTIB_BITS._PIB1
#define PIB2 PORTIB1.PORTIB_BITS._PIB2
#define PIB3 PORTIB1.PORTIB_BITS._PIB3
#define PIB4 PORTIB1.PORTIB_BITS._PIB4
#define PIB5 PORTIB1.PORTIB_BITS._PIB5
#define PIB6 PORTIB1.PORTIB_BITS._PIB6
#define PIB7 PORTIB1.PORTIB_BITS._PIB7

__DECL__6812DG128A_H__ volatile unsigned char DDRIB     _IO_AT(0xE7);  /* data direction port IB */



/*******************************************************************************************/
/*                                  EEPROM Modulus Divider                                 */
/*******************************************************************************************/

__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char _EEDIV8:1;
    unsigned char _EEDIV9:1;
    unsigned char BIT2:1;
    unsigned char BIT3:1;
    unsigned char BIT4:1;
    unsigned char BIT5:1;
    unsigned char BIT6:1;
    unsigned char BIT7:1;
  } EEDIVH_BITS;
  unsigned char EEDIVH_BYTE;
} EEDIVH1     _IO_AT(0xEE);  /* EEPROM Modulus Divider High */

/*DEFINE REGISTER*/
#define EEDIVH EEDIVH1.EEDIVH_BYTE

/*DEFINE REGISTER BITS*/
#define EEDIV8 EEDIVH1.EEDIVH_BITS._EEDIV8
#define EEDIV9 EEDIVH1.EEDIVH_BITS._EEDIV9

__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char _EEDIV0:1;
    unsigned char _EEDIV1:1;
    unsigned char _EEDIV2:1;
    unsigned char _EEDIV3:1;
    unsigned char _EEDIV4:1;
    unsigned char _EEDIV5:1;
    unsigned char _EEDIV6:1;
    unsigned char _EEDIV7:1;
  } EEDIVL_BITS;
  unsigned char EEDIVL_BYTE;
} EEDIVL1     _IO_AT(0xEF);  /* EEPROM Modulus Divider Low */

/*DEFINE REGISTER*/
#define EEDIVL EEDIVL1.EEDIVL_BYTE

/*DEFINE REGISTER BITS*/
#define EEDIV0 EEDIVL1.EEDIVL_BITS._EEDIV0
#define EEDIV1 EEDIVL1.EEDIVL_BITS._EEDIV1
#define EEDIV2 EEDIVL1.EEDIVL_BITS._EEDIV2
#define EEDIV3 EEDIVL1.EEDIVL_BITS._EEDIV3
#define EEDIV4 EEDIVL1.EEDIVL_BITS._EEDIV4
#define EEDIV5 EEDIVL1.EEDIVL_BITS._EEDIV5
#define EEDIV6 EEDIVL1.EEDIVL_BITS._EEDIV6
#define EEDIV7 EEDIVL1.EEDIVL_BITS._EEDIV7


/*******************************************************************************************/
/*                            EEPROM MODULE CONFIGURATION                                  */
/*******************************************************************************************/


__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char _DMY:1;
    unsigned char _PROTLCK:1;
    unsigned char _EESWAI:1;
    unsigned char BIT3:1;
    unsigned char BIT4:1;
    unsigned char BIT5:1;
    unsigned char _NOSHW:1;
    unsigned char _NOBDML:1;
  } EEMCR_BITS;
  unsigned char EEMCR_BYTE;
} EEMCR1 _IO_AT(0xF0);

/*DEFINE REGISTER*/
#define EEMCR EEMCR1.EEMCR_BYTE

/*DEFINE REGISTER BITS*/
#define DMY EEMCR1.EEMCR_BITS._DMY
#define PROTLCK EEMCR1.EEMCR_BITS._PROTLCK
#define EESWAI EEMCR1.EEMCR_BITS._EESWAI
#define NOSHW EEMCR1.EEMCR_BITS._NOSHW
#define NOBDML EEMCR1.EEMCR_BITS._NOBDML


/*******************************************************************************************/
/*                                   EEPROM BLOCK PROTECT                                  */
/*******************************************************************************************/


__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char _BPROT0:1;
    unsigned char _BPROT1:1;
    unsigned char _BPROT2:1;
    unsigned char _BPROT3:1;
    unsigned char _BPROT4:1;
    unsigned char _BPROT5:1;
    unsigned char BIT6:1;
    unsigned char _SHPROT:1;
  } EEPROT_BITS;
  unsigned char EEPROT_BYTE;
} EEPROT1 _IO_AT(0xF1);

/*DEFINE REGISTER*/
#define EEPROT EEPROT1.EEPROT_BYTE

/*DEFINE REGISTER BITS*/
#define BPROT0 EEPROT1.EEPROT_BITS._BPROT0
#define BPROT1 EEPROT1.EEPROT_BITS._BPROT1
#define BPROT2 EEPROT1.EEPROT_BITS._BPROT2
#define BPROT3 EEPROT1.EEPROT_BITS._BPROT3
#define BPROT4 EEPROT1.EEPROT_BITS._BPROT4
#define BPROT5 EEPROT1.EEPROT_BITS._BPROT5
#define SHPROT EEPROT1.EEPROT_BITS._SHPROT


/*******************************************************************************************/
/*                                       EEPROM TEST                                       */
/*******************************************************************************************/


__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char _ETMSE:1;
    unsigned char _ETMR:1;
    unsigned char _ETMSD:1;
    unsigned char BIT3:1;
    unsigned char BIT4:1;
    unsigned char BIT5:1;
    unsigned char _EREVTN:1;
    unsigned char BIT7:1;
  } EETST_BITS;
  unsigned char EETST_BYTE;
} EETST1 _IO_AT(0xF2);

/*DEFINE REGISTER*/
#define EETST EETST1.EETST_BYTE

/*DEFINE REGISTER BITS*/
#define ETMSE EETST1.EETST_BITS._ETMSE
#define ETMR EETST1.EETST_BITS._ETMR
#define ETMSD EETST1.EETST_BITS._ETMSD
#define EREVTN EETST1.EETST_BITS._EREVTN


/*******************************************************************************************/
/*                                       EEPROM CONTROL                                    */
/*******************************************************************************************/


__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char _EEPGM:1;
    unsigned char _EELAT:1;
    unsigned char _ERASE:1;
    unsigned char _ROW:1;
    unsigned char _BYTE:1;
    unsigned char _AUTO:1;
    unsigned char BIT6:1;
    unsigned char _BULKP:1;
  } EEPROG_BITS;
  unsigned char EEPROG_BYTE;
} EEPROG1 _IO_AT(0xF3);

/*DEFINE REGISTER*/
#define EEPROG EEPROG1.EEPROG_BYTE

/*DEFINE REGISTER BITS*/
#define EEPGM EEPROG1.EEPROG_BITS._EEPGM
#define EELAT EEPROG1.EEPROG_BITS._EELAT
#define ERASE EEPROG1.EEPROG_BITS._ERASE
#define ROW EEPROG1.EEPROG_BITS._ROW
#define BYTE EEPROG1.EEPROG_BITS._BYTE
#define AUTO EEPROG1.EEPROG_BITS._AUTO
#define BULKP EEPROG1.EEPROG_BITS._BULKP



/*******************************************************************************************/
/*                          FLASH EEPROM LOCK CONTROL REGISTER                             */
/*     Use LOCK_ instead of LOCK to differentiate with the LOCK of PLLFLG register ($3b)   */
/*******************************************************************************************/


__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char _LOCK_:1;
    unsigned char BIT1:1;
    unsigned char BIT2:1;
    unsigned char BIT3:1;
    unsigned char BIT4:1;
    unsigned char BIT5:1;
    unsigned char BIT6:1;
    unsigned char BIT7:1;
  } FEELCK_BITS;
  unsigned char FEELCK_BYTE;
} FEELCK1 _IO_AT(0xF4);

/*DEFINE REGISTER*/
#define FEELCK FEELCK1.FEELCK_BYTE

/*DEFINE REGISTER BITS*/
#define LOCK_ FEELCK1.FEELCK_BITS._LOCK_



/*******************************************************************************************/
/*                          FLASH EEPROM MODULE CONFIGURATION REGISTER                     */
/*******************************************************************************************/


__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char _BOOTP:1;
    unsigned char BIT1:1;
    unsigned char BIT2:1;
    unsigned char BIT3:1;
    unsigned char BIT4:1;
    unsigned char BIT5:1;
    unsigned char BIT6:1;
    unsigned char BIT7:1;
  } FEEMCR_BITS;
  unsigned char FEEMCR_BYTE;
} FEEMCR1 _IO_AT(0xF5);

/*DEFINE REGISTER*/
#define FEEMCR FEEMCR1.FEEMCR_BYTE

/*DEFINE REGISTER BITS*/
#define BOOTP FEEMCR1.FEEMCR_BITS._BOOTP



/*******************************************************************************************/
/*                              FLASH EEPROM MODULE TEST REGISTER                          */
/*******************************************************************************************/


__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char _MWPR:1;
    unsigned char _STRE:1;
    unsigned char _VTCK:1;
    unsigned char _FDISVFP:1;
    unsigned char _FENLV:1;
    unsigned char _HVT:1;
    unsigned char _GADR:1;
    unsigned char _FSTE:1;
  } FEETST_BITS;
  unsigned char FEETST_BYTE;
} FEETST1 _IO_AT(0xF6);

/*DEFINE REGISTER*/
#define FEETST FEETST1.FEETST_BYTE

/*DEFINE REGISTER BITS*/
#define MWPR FEETST1.FEETST_BITS._MWPR
#define STRE FEETST1.FEETST_BITS._STRE
#define VTCK FEETST1.FEETST_BITS._VTCK
#define FDISVFP FEETST1.FEETST_BITS._FDISVFP
#define FENLV FEETST1.FEETST_BITS._FENLV
#define HVT FEETST1.FEETST_BITS._HVT
#define GADR FEETST1.FEETST_BITS._GADR
#define FSTE FEETST1.FEETST_BITS._FSTE



/*******************************************************************************************/
/*                              FLASH EEPROM CONTROL REGISTER                              */
/*******************************************************************************************/

__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char _PGM:1;
    unsigned char _ERAS:1;
    unsigned char BIT2:1;
    unsigned char _HEVN:1;
    unsigned char _FEESWAI:1;
    unsigned char BIT5:1;
    unsigned char BIT6:1;
    unsigned char BIT7:1;
  } FEECTL_BITS;
  unsigned char FEECTL_BYTE;
} FEECTL1 _IO_AT(0xF7);

/*DEFINE REGISTER*/
#define FEECTL FEECTL1.FEECTL_BYTE

/*DEFINE REGISTER BITS*/
#define PGM FEECTL1.FEECTL_BITS._PGM
#define ERAS FEECTL1.FEECTL_BITS._ERAS
#define HEVN FEECTL1.FEECTL_BITS._HEVN
#define FEESWAI FEECTL1.FEECTL_BITS._FEESWAI


/*******************************************************************************************/
/*                              MAPPING TEST REGISTER 0                                    */
/*******************************************************************************************/


__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char _MT00:1;
    unsigned char _MT01:1;
    unsigned char _MT02:1;
    unsigned char _MT03:1;
    unsigned char _MT04:1;
    unsigned char _MT05:1;
    unsigned char _MT06:1;
    unsigned char _MT07:1;
  } MTST0_BITS;
  unsigned char MTST0_BYTE;
} MTST01 _IO_AT(0xF8);

/*DEFINE REGISTER*/
#define MTST0 MTST01.MTST0_BYTE

/*DEFINE REGISTER BITS*/
#define MT00 MTST01.MTST0_BITS._MT00
#define MT01 MTST01.MTST0_BITS._MT01
#define MT02 MTST01.MTST0_BITS._MT02
#define MT03 MTST01.MTST0_BITS._MT03
#define MT04 MTST01.MTST0_BITS._MT04
#define MT05 MTST01.MTST0_BITS._MT05
#define MT06 MTST01.MTST0_BITS._MT06
#define MT07 MTST01.MTST0_BITS._MT07


/*******************************************************************************************/
/*                              MAPPING TEST REGISTER 1                                    */
/*******************************************************************************************/


__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char _MT08:1;
    unsigned char _MT09:1;
    unsigned char _MT0A:1;
    unsigned char _MT0B:1;
    unsigned char _MT0C:1;
    unsigned char _MT0D:1;
    unsigned char _MT0E:1;
    unsigned char _MT0F:1;
  } MTST1_BITS;
  unsigned char MTST1_BYTE;
} MTST11 _IO_AT(0xF9);

/*DEFINE REGISTER*/
#define MTST1 MTST11.MTST1_BYTE

/*DEFINE REGISTER BITS*/
#define MT08 MTST11.MTST1_BITS._MT08
#define MT09 MTST11.MTST1_BITS._MT09
#define MT0A MTST11.MTST1_BITS._MT0A
#define MT0B MTST11.MTST1_BITS._MT0B
#define MT0C MTST11.MTST1_BITS._MT0C
#define MT0D MTST11.MTST1_BITS._MT0D
#define MT0E MTST11.MTST1_BITS._MT0E
#define MT0F MTST11.MTST1_BITS._MT0F



/*******************************************************************************************/
/*                              MAPPING TEST REGISTER 2                                    */
/*******************************************************************************************/


__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char _MT10:1;
    unsigned char _MT11:1;
    unsigned char _MT12:1;
    unsigned char _MT13:1;
    unsigned char _MT14:1;
    unsigned char _MT15:1;
    unsigned char _MT16:1;
    unsigned char _MT17:1;
  } MTST2_BITS;
  unsigned char MTST2_BYTE;
} MTST21 _IO_AT(0xFA);

/*DEFINE REGISTER*/
#define MTST2 MTST21.MTST2_BYTE

/*DEFINE REGISTER BITS*/
#define MT10 MTST21.MTST2_BITS._MT10
#define MT11 MTST21.MTST2_BITS._MT11
#define MT12 MTST21.MTST2_BITS._MT12
#define MT13 MTST21.MTST2_BITS._MT13
#define MT14 MTST21.MTST2_BITS._MT14
#define MT15 MTST21.MTST2_BITS._MT15
#define MT16 MTST21.MTST2_BITS._MT16
#define MT17 MTST21.MTST2_BITS._MT17



/*******************************************************************************************/
/*                              MAPPING TEST REGISTER 3                                    */
/*******************************************************************************************/


__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char _MT18:1;
    unsigned char _MT19:1;
    unsigned char _MT1A:1;
    unsigned char _MT1B:1;
    unsigned char _MT1C:1;
    unsigned char _MT1D:1;
    unsigned char _MT1E:1;
    unsigned char _MT1F:1;
  } MTST3_BITS;
  unsigned char MTST3_BYTE;
} MTST31 _IO_AT(0xFB);

/*DEFINE REGISTER*/
#define MTST3 MTST31.MTST3_BYTE

/*DEFINE REGISTER BITS*/
#define MT18 MTST31.MTST3_BITS._MT18
#define MT19 MTST31.MTST3_BITS._MT19
#define MT1A MTST31.MTST3_BITS._MT1A
#define MT1B MTST31.MTST3_BITS._MT1B
#define MT1C MTST31.MTST3_BITS._MT1C
#define MT1D MTST31.MTST3_BITS._MT1D
#define MT1E MTST31.MTST3_BITS._MT1E
#define MT1F MTST31.MTST3_BITS._MT1F



/*******************************************************************************************/
/*                                              PORT K                                     */
/*******************************************************************************************/


__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char _PK0:1;
    unsigned char _PK1:1;
    unsigned char _PK2:1;
    unsigned char _PK3:1;
    unsigned char BIT4:1;
    unsigned char BIT5:1;
    unsigned char BIT6:1;
    unsigned char _PK7:1;
  } PORTK_BITS;
  unsigned char PORTK_BYTE;
} PORTK1 _IO_AT(0xFC);

/*DEFINE REGISTER*/
#define PORTK PORTK1.PORTK_BYTE

/*DEFINE REGISTER BITS*/
#define PK0 PORTK1.PORTK_BITS._PK0
#define PK1 PORTK1.PORTK_BITS._PK1
#define PK2 PORTK1.PORTK_BITS._PK2
#define PK3 PORTK1.PORTK_BITS._PK3
#define PK7 PORTK1.PORTK_BITS._PK7


/*******************************************************************************************/
/*                               PORT K DATA DIRECTION REGISTER                            */
/*******************************************************************************************/


__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char _DDK0:1;
    unsigned char _DDK1:1;
    unsigned char _DDK2:1;
    unsigned char _DDK3:1;
    unsigned char BIT4:1;
    unsigned char BIT5:1;
    unsigned char BIT6:1;
    unsigned char _DDK7:1;
  } DDRK_BITS;
  unsigned char DDRK_BYTE;
} DDRK1 _IO_AT(0xFD);

/*DEFINE REGISTER*/
#define DDRK DDRK1.DDRK_BYTE

/*DEFINE REGISTER BITS*/
#define DDK0 DDRK1.DDRK_BITS._DDK0
#define DDK1 DDRK1.DDRK_BITS._DDK1
#define DDK2 DDRK1.DDRK_BITS._DDK2
#define DDK3 DDRK1.DDRK_BITS._DDK3
#define DDK7 DDRK1.DDRK_BITS._DDK7


/*******************************************************************************************/
/*                             (PROGRAM) PAGE INDEX REGISTER                               */
/*******************************************************************************************/


__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char _PIX0:1;
    unsigned char _PIX1:1;
    unsigned char _PIX2:1;
    unsigned char BIT3:1;
    unsigned char BIT4:1;
    unsigned char BIT5:1;
    unsigned char BIT6:1;
    unsigned char BIT7:1;
  } PPAGE_BITS;
  unsigned char PPAGE_BYTE;
} PPAGE1 _IO_AT(0xFF);

/*DEFINE REGISTER*/
#define PPAGE PPAGE1.PPAGE_BYTE

/*DEFINE REGISTER BITS*/
#define PIX0 PPAGE1.PPAGE_BITS._PIX0
#define PIX1 PPAGE1.PPAGE_BITS._PIX1
#define PIX2 PPAGE1.PPAGE_BITS._PIX2


/*******************************************************************************************/
/*                             MSCAN12 MODULE CONTROL REGISTER 0                           */
/*******************************************************************************************/


__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char _SFTRES_0:1;
    unsigned char _SLPRQ_0:1;
    unsigned char _SLPAK_0:1;
    unsigned char _TLNKEN_0:1;
    unsigned char _SYNCH_0:1;
    unsigned char _CSWAI_0:1;
    unsigned char BIT6:1;
    unsigned char BIT7:1;
  } C0MCR0_BITS;
  unsigned char C0MCR0_BYTE;
} C0MCR01 _IO_AT(0x100);

/*DEFINE REGISTER*/
#define C0MCR0 C0MCR01.C0MCR0_BYTE

/*DEFINE REGISTER BITS*/
#define SFTRES_0 C0MCR01.C0MCR0_BITS._SFTRES_0
#define SLPRQ_0 C0MCR01.C0MCR0_BITS._SLPRQ_0
#define SLPAK_0 C0MCR01.C0MCR0_BITS._SLPAK_0
#define TLNKEN_0 C0MCR01.C0MCR0_BITS._TLNKEN_0
#define SYNCH_0 C0MCR01.C0MCR0_BITS._SYNCH_0
#define CSWAI_0 C0MCR01.C0MCR0_BITS._CSWAI_0


/*******************************************************************************************/
/*                             MSCAN12 MODULE CONTROL REGISTER 1                           */
/*******************************************************************************************/


__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char _CLKSRC_0:1;
    unsigned char _WUPM_0:1;
    unsigned char _LOOPB_0:1;
    unsigned char BIT3:1;
    unsigned char BIT4:1;
    unsigned char BIT5:1;
    unsigned char BIT6:1;
    unsigned char BIT7:1;
  } C0MCR1_BITS;
  unsigned char C0MCR1_BYTE;
} C0MCR11 _IO_AT(0x101);

/*DEFINE REGISTER*/
#define C0MCR1 C0MCR11.C0MCR1_BYTE

/*DEFINE REGISTER BITS*/
#define CLKSRC_0 C0MCR11.C0MCR1_BITS._CLKSRC_0
#define WUPM_0 C0MCR11.C0MCR1_BITS._WUPM_0
#define LOOPB_0 C0MCR11.C0MCR1_BITS._LOOPB_0



/*******************************************************************************************/
/*                               MSCAN12 BUS TIMING REGISTER 0                             */
/*******************************************************************************************/


__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char _BRP0_0:1;
    unsigned char _BRP1_0:1;
    unsigned char _BRP2_0:1;
    unsigned char _BRP3_0:1;
    unsigned char _BRP4_0:1;
    unsigned char _BRP5_0:1;
    unsigned char _SJW0_0:1;
    unsigned char _SJW1_0:1;
  } C0BTR0_BITS;
  unsigned char C0BTR0_BYTE;
} C0BTR01 _IO_AT(0x102);

/*DEFINE REGISTER*/
#define C0BTR0 C0BTR01.C0BTR0_BYTE

/*DEFINE REGISTER BITS*/
#define BRP0_0 C0BTR01.C0BTR0_BITS._BRP0_0
#define BRP1_0 C0BTR01.C0BTR0_BITS._BRP1_0
#define BRP2_0 C0BTR01.C0BTR0_BITS._BRP2_0
#define BRP3_0 C0BTR01.C0BTR0_BITS._BRP3_0
#define BRP4_0 C0BTR01.C0BTR0_BITS._BRP4_0
#define BRP5_0 C0BTR01.C0BTR0_BITS._BRP5_0
#define SJW0_0 C0BTR01.C0BTR0_BITS._SJW0_0
#define SJW1_0 C0BTR01.C0BTR0_BITS._SJW1_0



/*******************************************************************************************/
/*                               MSCAN12 BUS TIMING REGISTER 1                             */
/*******************************************************************************************/


__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char _TSEG10_0:1;
    unsigned char _TSEG11_0:1;
    unsigned char _TSEG12_0:1;
    unsigned char _TSEG13_0:1;
    unsigned char _TSEG20_0:1;
    unsigned char _TSEG21_0:1;
    unsigned char _TSEG22_0:1;
    unsigned char _SAMP_0:1;
  } C0BTR1_BITS;
  unsigned char C0BTR1_BYTE;
} C0BTR11 _IO_AT(0x103);

/*DEFINE REGISTER*/
#define C0BTR1 C0BTR11.C0BTR1_BYTE

/*DEFINE REGISTER BITS*/
#define TSEG10_0 C0BTR11.C0BTR1_BITS._TSEG10_0
#define TSEG11_0 C0BTR11.C0BTR1_BITS._TSEG11_0
#define TSEG12_0 C0BTR11.C0BTR1_BITS._TSEG12_0
#define TSEG13_0 C0BTR11.C0BTR1_BITS._TSEG13_0
#define TSEG20_0 C0BTR11.C0BTR1_BITS._TSEG20_0
#define TSEG21_0 C0BTR11.C0BTR1_BITS._TSEG21_0
#define TSEG22_0 C0BTR11.C0BTR1_BITS._TSEG22_0
#define SAMP_0 C0BTR11.C0BTR1_BITS._SAMP_0


/*******************************************************************************************/
/*                               MSCAN12 RECEIVER FLAG REGISTER                            */
/*******************************************************************************************/


__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char _RFX_0:1;
    unsigned char _OVRIF_0:1;
    unsigned char _BOFFIF_0:1;
    unsigned char _TERRIF_0:1;
    unsigned char _RERRIF_0:1;
    unsigned char _TWRNIF_0:1;
    unsigned char _RWRNIF_0:1;
    unsigned char _WUPIF_0:1;
  } C0RFLG_BITS;
  unsigned char C0RFLG_BYTE;
} C0RFLG1 _IO_AT(0x104);

/*DEFINE REGISTER*/
#define C0RFLG C0RFLG1.C0RFLG_BYTE

/*DEFINE REGISTER BITS*/
#define RFX_0 C0RFLG1.C0RFLG_BITS._RFX_0
#define OVRIF_0 C0RFLG1.C0RFLG_BITS._OVRIF_0
#define BOFFIF_0 C0RFLG1.C0RFLG_BITS._BOFFIF_0
#define TERRIF_0 C0RFLG1.C0RFLG_BITS._TERRIF_0
#define RERRIF_0 C0RFLG1.C0RFLG_BITS._RERRIF_0
#define TWRNIF_0 C0RFLG1.C0RFLG_BITS._TWRNIF_0
#define RWRNIF_0 C0RFLG1.C0RFLG_BITS._RWRNIF_0
#define WUPIF_0 C0RFLG1.C0RFLG_BITS._WUPIF_0




/*******************************************************************************************/
/*                      MSCAN12 RECEIVER INTERRUPT ENABLE REGISTER                         */
/*******************************************************************************************/


__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char _RFXIE_0:1;
    unsigned char _OVRIE_0:1;
    unsigned char _BOFFIE_0:1;
    unsigned char _TERRIE_0:1;
    unsigned char _RERRIE_0:1;
    unsigned char _TWRNIE_0:1;
    unsigned char _RWRNIE_0:1;
    unsigned char _WUPIE_0:1;
  } C0RIER_BITS;
  unsigned char C0RIER_BYTE;
} C0RIER1 _IO_AT(0x105);

/*DEFINE REGISTER*/
#define C0RIER C0RIER1.C0RIER_BYTE

/*DEFINE REGISTER BITS*/
#define RFXIE_0 C0RIER1.C0RIER_BITS._RFXIE_0
#define OVRIE_0 C0RIER1.C0RIER_BITS._OVRIE_0
#define BOFFIE_0 C0RIER1.C0RIER_BITS._BOFFIE_0
#define TERRIE_0 C0RIER1.C0RIER_BITS._TERRIE_0
#define RERRIE_0 C0RIER1.C0RIER_BITS._RERRIE_0
#define TWRNIE_0 C0RIER1.C0RIER_BITS._TWRNIE_0
#define RWRNIE_0 C0RIER1.C0RIER_BITS._RWRNIE_0
#define WUPIE_0 C0RIER1.C0RIER_BITS._WUPIE_0



/*******************************************************************************************/
/*                          MSCAN12 TRANSMITTER FLAG REGISTER                              */
/*******************************************************************************************/


__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char _TXE0_0:1;
    unsigned char _TXE1_0:1;
    unsigned char _TXE2_0:1;
    unsigned char BIT3:1;
    unsigned char _ABTAK0_0:1;
    unsigned char _ABTAK1_0:1;
    unsigned char _ABTAK2_0:1;
    unsigned char BIT7:1;
  } C0TFLG_BITS;
  unsigned char C0TFLG_BYTE;
} C0TFLG1 _IO_AT(0x106);

/*DEFINE REGISTER*/
#define C0TFLG C0TFLG1.C0TFLG_BYTE

/*DEFINE REGISTER BITS*/
#define TXE0_0 C0TFLG1.C0TFLG_BITS._TXE0_0
#define TXE1_0 C0TFLG1.C0TFLG_BITS._TXE1_0
#define TXE2_0 C0TFLG1.C0TFLG_BITS._TXE2_0
#define ABTAK0_0 C0TFLG1.C0TFLG_BITS._ABTAK0_0
#define ABTAK1_0 C0TFLG1.C0TFLG_BITS._ABTAK1_0
#define ABTAK2_0 C0TFLG1.C0TFLG_BITS._ABTAK2_0



/*******************************************************************************************/
/*                          MSCAN12 TRANSMITTER CONTROL REGISTER                           */
/*******************************************************************************************/


__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char _TXEIE0_0:1;
    unsigned char _TXEIE1_0:1;
    unsigned char _TXEIE2_0:1;
    unsigned char BIT3:1;
    unsigned char _ABTRQ0_0:1;
    unsigned char _ABTRQ1_0:1;
    unsigned char _ABTRQ2_0:1;
    unsigned char BIT7:1;
  } C0TCR_BITS;
  unsigned char C0TCR_BYTE;
} C0TCR1 _IO_AT(0x107);

/*DEFINE REGISTER*/
#define C0TCR C0TCR1.C0TCR_BYTE

/*DEFINE REGISTER BITS*/
#define TXEIE0_0 C0TCR1.C0TCR_BITS._TXEIE0_0
#define TXEIE1_0 C0TCR1.C0TCR_BITS._TXEIE1_0
#define TXEIE2_0 C0TCR1.C0TCR_BITS._TXEIE2_0
#define ABTRQ0_0 C0TCR1.C0TCR_BITS._ABTRQ0_0
#define ABTRQ1_0 C0TCR1.C0TCR_BITS._ABTRQ1_0
#define ABTRQ2_0 C0TCR1.C0TCR_BITS._ABTRQ2_0



/*******************************************************************************************/
/*                          MSCAN12 IDENTIFIER ACCEPTANCE CONTROL REGISTER                 */
/*******************************************************************************************/


__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char _IDHIT0_0:1;
    unsigned char _IDHIT1_0:1;
    unsigned char _IDHIT2_0:1;
    unsigned char BIT3:1;
    unsigned char _IDAM0_0:1;
    unsigned char _IDAM1_0:1;
    unsigned char BIT6:1;
    unsigned char BIT7:1;
  } C0IDAC_BITS;
  unsigned char C0IDAC_BYTE;
} C0IDAC1 _IO_AT(0x108);

/*DEFINE REGISTER*/
#define C0IDAC C0IDAC1.C0IDAC_BYTE

/*DEFINE REGISTER BITS*/
#define IDHIT0_0 C0IDAC1.C0IDAC_BITS._IDHIT0_0
#define IDHIT1_0 C0IDAC1.C0IDAC_BITS._IDHIT1_0
#define IDHIT2_0 C0IDAC1.C0IDAC_BITS._IDHIT2_0
#define IDAM0_0 C0IDAC1.C0IDAC_BITS._IDAM0_0
#define IDAM1_0 C0IDAC1.C0IDAC_BITS._IDAM1_0



/**************************************************************************************************/
/*                                      MSCAN12 RECEIVE ERROR COUNTER                             */
/**************************************************************************************************/

__DECL__6812DG128A_H__ volatile unsigned char C0RXERR    _IO_AT(0x10E);


/**************************************************************************************************/
/*                                     MSCAN12 TRANSMIT ERROR COUNTER                             */
/**************************************************************************************************/

__DECL__6812DG128A_H__ volatile unsigned char C0TXERR    _IO_AT(0x10F);


/**************************************************************************************************/
/*                            IDENTIFIER ACCEPTANCE REGISTERS (First bank)                        */
/**************************************************************************************************/

__DECL__6812DG128A_H__ volatile unsigned char C0IDAR0    _IO_AT(0x110);
__DECL__6812DG128A_H__ volatile unsigned char C0IDAR1    _IO_AT(0x111);
__DECL__6812DG128A_H__ volatile unsigned char C0IDAR2    _IO_AT(0x112);
__DECL__6812DG128A_H__ volatile unsigned char C0IDAR3    _IO_AT(0x113);



/**************************************************************************************************/
/*                                  IDENTIFIER MASK REGISTERS (First bank)                        */
/**************************************************************************************************/

__DECL__6812DG128A_H__ volatile unsigned char C0IDMR0    _IO_AT(0x114);
__DECL__6812DG128A_H__ volatile unsigned char C0IDMR1    _IO_AT(0x115);
__DECL__6812DG128A_H__ volatile unsigned char C0IDMR2    _IO_AT(0x116);
__DECL__6812DG128A_H__ volatile unsigned char C0IDMR3    _IO_AT(0x117);


/**************************************************************************************************/
/*                            IDENTIFIER ACCEPTANCE REGISTERS (Second bank)                       */
/**************************************************************************************************/

__DECL__6812DG128A_H__ volatile unsigned char C0IDAR4    _IO_AT(0x118);
__DECL__6812DG128A_H__ volatile unsigned char C0IDAR5    _IO_AT(0x119);
__DECL__6812DG128A_H__ volatile unsigned char C0IDAR6    _IO_AT(0x11A);
__DECL__6812DG128A_H__ volatile unsigned char C0IDAR7    _IO_AT(0x11B);


/**************************************************************************************************/
/*                                  IDENTIFIER MASK REGISTERS (Second bank)                       */
/**************************************************************************************************/

__DECL__6812DG128A_H__ volatile unsigned char C0IDMR4    _IO_AT(0x11C);
__DECL__6812DG128A_H__ volatile unsigned char C0IDMR5    _IO_AT(0x11D);
__DECL__6812DG128A_H__ volatile unsigned char C0IDMR6    _IO_AT(0x11E);
__DECL__6812DG128A_H__ volatile unsigned char C0IDMR7    _IO_AT(0x11F);


/*******************************************************************************************/
/*                           MSCAN12 PORT CAN CONTROL REGISTER 0                           */
/*******************************************************************************************/

__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char _RDPCAN_0:1;
    unsigned char _PUPCAN_0:1;
    unsigned char BIT2:1;
    unsigned char BIT3:1;
    unsigned char BIT4:1;
    unsigned char BIT5:1;
    unsigned char BIT6:1;
    unsigned char BIT7:1;
  } PCTLCAN0_BITS;
  unsigned char PCTLCAN0_BYTE;
} PCTLCAN01 _IO_AT(0x13D);

/*DEFINE REGISTER*/
#define PCTLCAN0 PCTLCAN01.PCTLCAN0_BYTE

/*DEFINE REGISTER BITS*/
#define RDPCAN_0 PCTLCAN01.PCTLCAN0_BITS._RDPCAN_0
#define PUPCAN_0 PCTLCAN01.PCTLCAN0_BITS._PUPCAN_0


/*******************************************************************************************/
/*                              MSCAN12 PORT CAN DATA REGISTER 0                           */
/*******************************************************************************************/

__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char _RxCAN_0:1;
    unsigned char _TxCAN_0:1;
    unsigned char _PCAN2_0:1;
    unsigned char _PCAN3_0:1;
    unsigned char _PCAN4_0:1;
    unsigned char _PCAN5_0:1;
    unsigned char _PCAN6_0:1;
    unsigned char _PCAN7_0:1;
  } PORTCAN0_BITS;
  unsigned char PORTCAN0_BYTE;
} PORTCAN01 _IO_AT(0x13E);

/*DEFINE REGISTER*/
#define PORTCAN0 PORTCAN01.PORTCAN0_BYTE

/*DEFINE REGISTER BITS*/
#define RxCAN_0 PORTCAN01.PORTCAN0_BITS._RxCAN_0
#define TxCAN_0 PORTCAN01.PORTCAN0_BITS._TxCAN_0
#define PCAN2_0 PORTCAN01.PORTCAN0_BITS._PCAN2_0
#define PCAN3_0 PORTCAN01.PORTCAN0_BITS._PCAN3_0
#define PCAN4_0 PORTCAN01.PORTCAN0_BITS._PCAN4_0
#define PCAN5_0 PORTCAN01.PORTCAN0_BITS._PCAN5_0
#define PCAN6_0 PORTCAN01.PORTCAN0_BITS._PCAN6_0
#define PCAN7_0 PORTCAN01.PORTCAN0_BITS._PCAN7_0


/*******************************************************************************************/
/*                         MSCAN12 PORT CAN DATA DIRECTION REGISTER 0                      */
/*******************************************************************************************/

__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char BIT0:1;
    unsigned char BIT1:1;
    unsigned char _DDAN2_0:1;
    unsigned char _DDAN3_0:1;
    unsigned char _DDAN4_0:1;
    unsigned char _DDAN5_0:1;
    unsigned char _DDAN6_0:1;
    unsigned char _DDAN7_0:1;
  } DDRCAN0_BITS;
  unsigned char DDRCAN0_BYTE;
} DDRCAN01 _IO_AT(0x13F);

/*DEFINE REGISTER*/
#define DDRCAN0 DDRCAN01.DDRCAN0_BYTE

/*DEFINE REGISTER BITS*/
#define DDAN2_0 DDRCAN01.DDRCAN0_BITS._DDAN2_0
#define DDAN3_0 DDRCAN01.DDRCAN0_BITS._DDAN3_0
#define DDAN4_0 DDRCAN01.DDRCAN0_BITS._DDAN4_0
#define DDAN5_0 DDRCAN01.DDRCAN0_BITS._DDAN5_0
#define DDAN6_0 DDRCAN01.DDRCAN0_BITS._DDAN6_0
#define DDAN7_0 DDRCAN01.DDRCAN0_BITS._DDAN7_0


/**************************************************************************************************/
/*                                  FOREGROUND RECEIVE BUFFER 0                                   */
/**************************************************************************************************/

__DECL__6812DG128A_H__ volatile unsigned char RxFG0[16]    _IO_AT(0x140);


/**************************************************************************************************/
/*                                      TRANSMIT BUFFER 00                                        */
/**************************************************************************************************/

__DECL__6812DG128A_H__ volatile unsigned char Tx00[16]    _IO_AT(0x150);


/**************************************************************************************************/
/*                                      TRANSMIT BUFFER 01                                        */
/**************************************************************************************************/

__DECL__6812DG128A_H__ volatile unsigned char Tx01[16]    _IO_AT(0x160);


/**************************************************************************************************/
/*                                      TRANSMIT BUFFER 02                                        */
/**************************************************************************************************/

__DECL__6812DG128A_H__ volatile unsigned char Tx02[16]    _IO_AT(0x170);




/**************************************************************************************************/
/*                                   ATD RESERVED REGISTERS                                       */
/**************************************************************************************************/

__DECL__6812DG128A_H__ volatile unsigned char ATD1CTL0  _IO_AT(0x1E0); /* A/D control register 0 */
__DECL__6812DG128A_H__ volatile unsigned char ATD1CTL1  _IO_AT(0x1E1); /* A/D control register 1 */



/**************************************************************************************************/
/*                                    ATD CONTROL REGISTERS                                       */
/**************************************************************************************************/


/**********ATD CONTROL REGISTER 2********/
__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char _ASCIF_1:1;
    unsigned char _ASCIE_1:1;
    unsigned char BIT2:1;
    unsigned char BIT3:1;
    unsigned char BIT4:1;
    unsigned char _ASWAI_1:1;
    unsigned char _AFFC_1:1;
    unsigned char _ADPU_1:1;
  } ATD1CTL2_BITS;
  unsigned char ATD1CTL2_BYTE;
}ATD1CTL21 _IO_AT(0x1E2);

/*DEFINE REGISTER*/
#define ATD1CTL2 ATD1CTL21.ATD1CTL2_BYTE

/*DEFINE REGISTER BITS*/
#define ASCIF_1 ATD1CTL21.ATD1CTL2_BITS._ASCIF_1
#define ASCIE_1 ATD1CTL21.ATD1CTL2_BITS._ASCIE_1
#define ASWAI_1 ATD1CTL21.ATD1CTL2_BITS._ASWAI_1
#define AFFC_1 ATD1CTL21.ATD1CTL2_BITS._AFFC_1
#define ADPU_1 ATD1CTL21.ATD1CTL2_BITS._ADPU_1



/**********ATD CONTROL REGISTER 3********/
__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char _FRZ0_1:1;
    unsigned char _FRZ1_1:1;
    unsigned char BIT2:1;
    unsigned char BIT3:1;
    unsigned char BIT4:1;
    unsigned char BIT5:1;
    unsigned char BIT6:1;
    unsigned char BIT7:1;
  } ATD1CTL3_BITS;
  unsigned char ATD1CTL3_BYTE;
}ATD1CTL31 _IO_AT(0x1E3);

/*DEFINE REGISTER*/
#define ATD1CTL3 ATD1CTL31.ATD1CTL3_BYTE

/*DEFINE REGISTER BITS*/
#define FRZ0_1 ATD1CTL31.ATD1CTL3_BITS._FRZ0_1
#define FRZ1_1 ATD1CTL31.ATD1CTL3_BITS._FRZ1_1



/**********ATD CONTROL REGISTER 4********/
__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char _PRS0_1:1;
    unsigned char _PRS1_1:1;
    unsigned char _PRS2_1:1;
    unsigned char _PRS3_1:1;
    unsigned char _PRS4_1:1;
    unsigned char _SMP0_1:1;
    unsigned char _SMP1_1:1;
    /* FCOM#1311 : Add definitions for read of ATD Converter in 10 Bit Mode */
    unsigned char _RES10_1:1;
  } ATD1CTL4_BITS;
  unsigned char ATD1CTL4_BYTE;
}ATD1CTL41 _IO_AT(0x1E4);

/*DEFINE REGISTER*/
#define ATD1CTL4 ATD1CTL41.ATD1CTL4_BYTE

/*DEFINE REGISTER BITS*/
#define PRS0_1 ATD1CTL41.ATD1CTL4_BITS._PRS0_1
#define PRS1_1 ATD1CTL41.ATD1CTL4_BITS._PRS1_1
#define PRS2_1 ATD1CTL41.ATD1CTL4_BITS._PRS2_1
#define PRS3_1 ATD1CTL41.ATD1CTL4_BITS._PRS3_1
#define PRS4_1 ATD1CTL41.ATD1CTL4_BITS._PRS4_1
#define SMP0_1 ATD1CTL41.ATD1CTL4_BITS._SMP0_1
#define SMP1_1 ATD1CTL41.ATD1CTL4_BITS._SMP1_1
/* FCOM#1311 : Add definitions for read of ATD Converter in 10 Bit Mode */
#define RES10_1 ATD1CTL41.ATD1CTL4_BITS._RES10_1


/**********ATD CONTROL REGISTER 5********/
__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char _CA_1:1;
    unsigned char _CB_1:1;
    unsigned char _CC_1:1;
    unsigned char _CD_1:1;
    unsigned char _MULT_1:1;
    unsigned char _SCAN_1:1;
    unsigned char _S8CM_1:1;
    unsigned char BIT7:1;
  } ATD1CTL5_BITS;
  unsigned char ATD1CTL5_BYTE;
}ATD1CTL51 _IO_AT(0x1E5);

/*DEFINE REGISTER*/
#define ATD1CTL5 ATD1CTL51.ATD1CTL5_BYTE

/*DEFINE REGISTER BITS*/
#define CA_1 ATD1CTL51.ATD1CTL5_BITS._CA_1
#define CB_1 ATD1CTL51.ATD1CTL5_BITS._CB_1
#define CC_1 ATD1CTL51.ATD1CTL5_BITS._CC_1
#define CD_1 ATD1CTL51.ATD1CTL5_BITS._CD_1
#define MULT_1 ATD1CTL51.ATD1CTL5_BITS._MULT_1
#define SCAN_1 ATD1CTL51.ATD1CTL5_BITS._SCAN_1
#define S8CM_1 ATD1CTL51.ATD1CTL5_BITS._S8CM_1



/**************************************************************************************************/
/*                                    ATD STATUS REGISTER                                         */
/**************************************************************************************************/


__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned short  _CC0_1:1;
    unsigned short  _CC1_1:1;
    unsigned short  _CC2_1:1;
    unsigned short  BIT3:1;
    unsigned short  BIT4:1;
    unsigned short  BIT5:1;
    unsigned short  BIT6:1;
    unsigned short  _SCF_1:1;
    unsigned short  _CCF0_1:1;
    unsigned short  _CCF1_1:1;
    unsigned short  _CCF2_1:1;
    unsigned short  _CCF3_1:1;
    unsigned short  _CCF4_1:1;
    unsigned short  _CCF5_1:1;
    unsigned short  _CCF6_1:1;
    unsigned short  _CCF7_1:1;
  } ATD1STAT_BITS;
  unsigned short ATD1STAT_WORD;
}ATD1STAT1 _IO_AT(0x1E6);

/*DEFINE REGISTER*/
#define ATD1STAT ATD1STAT1.ATD1STAT_WORD

/*DEFINE REGISTER BITS*/
#define CC0_1 ATD1STAT1.ATD1STAT_BITS._CC0_1
#define CC1_1 ATD1STAT1.ATD1STAT_BITS._CC1_1
#define CC2_1 ATD1STAT1.ATD1STAT_BITS._CC2_1
#define SCF_1 ATD1STAT1.ATD1STAT_BITS._SCF_1
#define CCF0_1 ATD1STAT1.ATD1STAT_BITS._CCF0_1
#define CCF1_1 ATD1STAT1.ATD1STAT_BITS._CCF1_1
#define CCF2_1 ATD1STAT1.ATD1STAT_BITS._CCF2_1
#define CCF3_1 ATD1STAT1.ATD1STAT_BITS._CCF3_1
#define CCF4_1 ATD1STAT1.ATD1STAT_BITS._CCF4_1
#define CCF5_1 ATD1STAT1.ATD1STAT_BITS._CCF5_1
#define CCF6_1 ATD1STAT1.ATD1STAT_BITS._CCF6_1
#define CCF7_1 ATD1STAT1.ATD1STAT_BITS._CCF7_1


/*******************************************************************************************/
/*                                        ATD TEST REGISTER                                */
/*******************************************************************************************/


/********ATD TEST REGISTER HIGH*********/
__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char _SAR2_1:1;
    unsigned char _SAR3_1:1;
    unsigned char _SAR4_1:1;
    unsigned char _SAR5_1:1;
    unsigned char _SAR6_1:1;
    unsigned char _SAR7_1:1;
    unsigned char _SAR8_1:1;
    unsigned char _SAR9_1:1;
  } ATD1TSTH_BITS;
  unsigned char ATD1TSTH_BYTE;
} ATD1TSTH1 _IO_AT(0x1E8);

/*DEFINE REGISTER*/
#define ATD1TSTH ATD1TSTH1.ATD1TSTH_BYTE

/*DEFINE REGISTER BITS*/
#define SAR2_1 ATD1TSTH1.ATD1TSTH_BITS._SAR2_1
#define SAR3_1 ATD1TSTH1.ATD1TSTH_BITS._SAR3_1
#define SAR4_1 ATD1TSTH1.ATD1TSTH_BITS._SAR4_1
#define SAR5_1 ATD1TSTH1.ATD1TSTH_BITS._SAR5_1
#define SAR6_1 ATD1TSTH1.ATD1TSTH_BITS._SAR6_1
#define SAR7_1 ATD1TSTH1.ATD1TSTH_BITS._SAR7_1
#define SAR8_1 ATD1TSTH1.ATD1TSTH_BITS._SAR8_1
#define SAR9_1 ATD1TSTH1.ATD1TSTH_BITS._SAR9_1


/********ATD TEST REGISTER LOW**********/
__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char _TST0_1:1;
    unsigned char _TST1_1:1;
    unsigned char _TST2_1:1;
    unsigned char _TST3_1:1;
    unsigned char _TSTOUT_1:1;
    unsigned char _RST_1:1;
    unsigned char _SAR0_1:1;
    unsigned char _SAR1_1:1;
  } ATD1TSTL_BITS;
  unsigned char ATD1TSTL_BYTE;
} ATD1TSTL1 _IO_AT(0x1E9);

/*DEFINE REGISTER*/
#define ATD1TSTL ATD1TSTL1.ATD1TSTL_BYTE

/*DEFINE REGISTER BITS*/
#define TST0_1 ATD1TSTL1.ATD1TSTL_BITS._TST0_1
#define TST1_1 ATD1TSTL1.ATD1TSTL_BITS._TST1_1
#define TST2_1 ATD1TSTL1.ATD1TSTL_BITS._TST2_1
#define TST3_1 ATD1TSTL1.ATD1TSTL_BITS._TST3_1
#define TSTOUT1 ATD1TSTL1.ATD1TSTL_BITS._TSTOUT_1
#define RST_1 ATD1TSTL1.ATD1TSTL_BITS._RST_1
#define SAR0_1 ATD1TSTL1.ATD1TSTL_BITS._SAR0_1
#define SAR1_1 ATD1TSTL1.ATD1TSTL_BITS._SAR1_1



/*******************************************************************************************/
/*                                 PORT AD 1 DATA INPUT REGISTER                           */
/*******************************************************************************************/

__DECL__6812DG128A_H__ volatile unsigned char PORTAD1   _IO_AT(0x1EF); /* port AD 1 data input register */



/*******************************************************************************************/
/*                              ADT CONVERTER RESULT REGISTERS                             */
/*******************************************************************************************/

__DECL__6812DG128A_H__ volatile unsigned char ADR10H    _IO_AT(0x1F0); /* A/D result 0 register high */


__DECL__6812DG128A_H__ volatile union {                            /* A/D result 0 register low */
  struct {
    unsigned char BIT0:1;
    unsigned char BIT1:1;
    unsigned char BIT2:1;
    unsigned char BIT3:1;
    unsigned char BIT4:1;
    unsigned char BIT5:1;
    unsigned char _ADR10LBIT6:1;
    unsigned char _ADR10LBIT7:1;
  } ADR10L_BITS;
  unsigned char ADR10L_BYTE;
}ADR10L1 _IO_AT(0x1F1);

/*DEFINE REGISTER*/
#define ADR10L ADR10L1.ADR10L_BYTE

/*DEFINE REGISTER BITS*/
#define ADR10L_BIT6 ADR10L1.ADR10L_BITS._ADR10LBIT6
#define ADR10L_BIT7 ADR10L1.ADR10L_BITS._ADR10LBIT7

/* FCOM#1311 : Add definitions for read of ATD Converter in 10 Bit Mode */
#define ADR10HL ((*(volatile unsigned short*)&ADR10H) >> 6)

__DECL__6812DG128A_H__ volatile unsigned char ADR11H    _IO_AT(0x1F2); /* A/D result 1 register high */


__DECL__6812DG128A_H__ volatile union {                            /* A/D result 1 register low */
  struct {
    unsigned char BIT0:1;
    unsigned char BIT1:1;
    unsigned char BIT2:1;
    unsigned char BIT3:1;
    unsigned char BIT4:1;
    unsigned char BIT5:1;
    unsigned char _ADR11LBIT6:1;
    unsigned char _ADR11LBIT7:1;
  } ADR11L_BITS;
  unsigned char ADR11L_BYTE;
}ADR11L1 _IO_AT(0x1F3);

/*DEFINE REGISTER*/
#define ADR11L ADR11L1.ADR11L_BYTE

/*DEFINE REGISTER BITS*/
#define ADR11L_BIT6 ADR11L1.ADR11L_BITS._ADR11LBIT6
#define ADR11L_BIT7 ADR11L1.ADR11L_BITS._ADR11LBIT7

/* FCOM#1311 : Add definitions for read of ATD Converter in 10 Bit Mode */
#define ADR11HL ((*(volatile unsigned short*)&ADR11H) >> 6)

__DECL__6812DG128A_H__ volatile unsigned char ADR12H    _IO_AT(0x1F4); /* A/D result 2 register high */

__DECL__6812DG128A_H__ volatile union {                            /* A/D result 2 register low */
  struct {
    unsigned char BIT0:1;
    unsigned char BIT1:1;
    unsigned char BIT2:1;
    unsigned char BIT3:1;
    unsigned char BIT4:1;
    unsigned char BIT5:1;
    unsigned char _ADR12LBIT6:1;
    unsigned char _ADR12LBIT7:1;
  } ADR12L_BITS;
  unsigned char ADR12L_BYTE;
}ADR12L1 _IO_AT(0x1F5);

/*DEFINE REGISTER*/
#define ADR12L ADR12L1.ADR12L_BYTE

/*DEFINE REGISTER BITS*/
#define ADR12L_BIT6 ADR12L1.ADR12L_BITS._ADR12LBIT6
#define ADR12L_BIT7 ADR12L1.ADR12L_BITS._ADR12LBIT7

/* FCOM#1311 : Add definitions for read of ATD Converter in 10 Bit Mode */
#define ADR12HL ((*(volatile unsigned short*)&ADR12H) >> 6)

__DECL__6812DG128A_H__ volatile unsigned char ADR13H    _IO_AT(0x1F6); /* A/D result 3 register high */

__DECL__6812DG128A_H__ volatile union {                            /* A/D result 3 register low */
  struct {
    unsigned char BIT0:1;
    unsigned char BIT1:1;
    unsigned char BIT2:1;
    unsigned char BIT3:1;
    unsigned char BIT4:1;
    unsigned char BIT5:1;
    unsigned char _ADR13LBIT6:1;
    unsigned char _ADR13LBIT7:1;
  } ADR13L_BITS;
  unsigned char ADR13L_BYTE;
}ADR13L1 _IO_AT(0x1F7);

/*DEFINE REGISTER*/
#define ADR13L ADR13L1.ADR13L_BYTE

/*DEFINE REGISTER BITS*/
#define ADR13L_BIT6 ADR13L1.ADR13L_BITS._ADR13LBIT6
#define ADR13L_BIT7 ADR13L1.ADR13L_BITS._ADR13LBIT7

/* FCOM#1311 : Add definitions for read of ATD Converter in 10 Bit Mode */
#define ADR13HL ((*(volatile unsigned short*)&ADR13H) >> 6)
__DECL__6812DG128A_H__ volatile unsigned char ADR14H    _IO_AT(0x1F8); /* A/D result 4 register high */

__DECL__6812DG128A_H__ volatile union {                            /* A/D result 4 register low */
  struct {
    unsigned char BIT0:1;
    unsigned char BIT1:1;
    unsigned char BIT2:1;
    unsigned char BIT3:1;
    unsigned char BIT4:1;
    unsigned char BIT5:1;
    unsigned char _ADR14LBIT6:1;
    unsigned char _ADR14LBIT7:1;
  } ADR14L_BITS;
  unsigned char ADR14L_BYTE;
}ADR14L1 _IO_AT(0x1F9);

/*DEFINE REGISTER*/
#define ADR14L ADR14L1.ADR14L_BYTE

/*DEFINE REGISTER BITS*/
#define ADR14L_BIT6 ADR14L1.ADR14L_BITS._ADR14LBIT6
#define ADR14L_BIT7 ADR14L1.ADR14L_BITS._ADR14LBIT7

/* FCOM#1311 : Add definitions for read of ATD Converter in 10 Bit Mode */
#define ADR14HL ((*(volatile unsigned short*)&ADR14H) >> 6)
__DECL__6812DG128A_H__ volatile unsigned char ADR15H    _IO_AT(0x1Fa); /* A/D result 5 register high */

__DECL__6812DG128A_H__ volatile union {                            /* A/D result 5 register low */
  struct {
    unsigned char BIT0:1;
    unsigned char BIT1:1;
    unsigned char BIT2:1;
    unsigned char BIT3:1;
    unsigned char BIT4:1;
    unsigned char BIT5:1;
    unsigned char _ADR15LBIT6:1;
    unsigned char _ADR15LBIT7:1;
  } ADR15L_BITS;
  unsigned char ADR15L_BYTE;
}ADR15L1 _IO_AT(0x1FB);

/*DEFINE REGISTER*/
#define ADR15L ADR15L1.ADR15L_BYTE

/*DEFINE REGISTER BITS*/
#define ADR15L_BIT6 ADR15L1.ADR15L_BITS._ADR15LBIT6
#define ADR15L_BIT7 ADR15L1.ADR15L_BITS._ADR15LBIT7

/* FCOM#1311 : Add definitions for read of ATD Converter in 10 Bit Mode */
#define ADR15HL ((*(volatile unsigned short*)&ADR15H) >> 6)

__DECL__6812DG128A_H__ volatile unsigned char ADR16H    _IO_AT(0x1Fc); /* A/D result 6 register high */

__DECL__6812DG128A_H__ volatile union {                            /* A/D result 6 register low */
  struct {
    unsigned char BIT0:1;
    unsigned char BIT1:1;
    unsigned char BIT2:1;
    unsigned char BIT3:1;
    unsigned char BIT4:1;
    unsigned char BIT5:1;
    unsigned char _ADR16LBIT6:1;
    unsigned char _ADR16LBIT7:1;
  } ADR16L_BITS;
  unsigned char ADR16L_BYTE;
}ADR16L1 _IO_AT(0x1FD);

/*DEFINE REGISTER*/
#define ADR16L ADR16L1.ADR16L_BYTE

/*DEFINE REGISTER BITS*/
#define ADR16L_BIT6 ADR16L1.ADR16L_BITS._ADR16LBIT6
#define ADR16L_BIT7 ADR16L1.ADR16L_BITS._ADR16LBIT7

/* FCOM#1311 : Add definitions for read of ATD Converter in 10 Bit Mode */
#define ADR16HL ((*(volatile unsigned short*)&ADR16H) >> 6)
__DECL__6812DG128A_H__ volatile unsigned char ADR17H    _IO_AT(0x1Fe); /* A/D result 7 register high */

__DECL__6812DG128A_H__ volatile union {                            /* A/D result 7 register low */
  struct {
    unsigned char BIT0:1;
    unsigned char BIT1:1;
    unsigned char BIT2:1;
    unsigned char BIT3:1;
    unsigned char BIT4:1;
    unsigned char BIT5:1;
    unsigned char _ADR17LBIT6:1;
    unsigned char _ADR17LBIT7:1;
  } ADR17L_BITS;
  unsigned char ADR17L_BYTE;
}ADR17L1 _IO_AT(0x1FF);

/*DEFINE REGISTER*/
#define ADR17L ADR17L1.ADR17L_BYTE

/*DEFINE REGISTER BITS*/
#define ADR17L_BIT6 ADR17L1.ADR17L_BITS._ADR17LBIT6
#define ADR17L_BIT7 ADR17L1.ADR17L_BITS._ADR17LBIT7

/* FCOM#1311 : Add definitions for read of ATD Converter in 10 Bit Mode */
#define ADR17HL ((*(volatile unsigned short*)&ADR17H) >> 6)

/*******************************************************************************************/
/*                             MSCAN12 MODULE CONTROL REGISTER 0                           */
/*******************************************************************************************/


__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char _SFTRES_1:1;
    unsigned char _SLPRQ_1:1;
    unsigned char _SLPAK_1:1;
    unsigned char _TLNKEN_1:1;
    unsigned char _SYNCH_1:1;
    unsigned char _CSWAI_1:1;
    unsigned char BIT6:1;
    unsigned char BIT7:1;
  } C1MCR0_BITS;
  unsigned char C1MCR0_BYTE;
} C1MCR01 _IO_AT(0x300);

/*DEFINE REGISTER*/
#define C1MCR0 C1MCR01.C1MCR0_BYTE

/*DEFINE REGISTER BITS*/
#define SFTRES_1 C1MCR01.C1MCR0_BITS._SFTRES_1
#define SLPRQ_1 C1MCR01.C1MCR0_BITS._SLPRQ_1
#define SLPAK_1 C1MCR01.C1MCR0_BITS._SLPAK_1
#define TLNKEN_1 C1MCR01.C1MCR0_BITS._TLNKEN_1
#define SYNCH_1 C1MCR01.C1MCR0_BITS._SYNCH_1
#define CSWAI_1 C1MCR01.C1MCR0_BITS._CSWAI_1



/*******************************************************************************************/
/*                             MSCAN12 MODULE CONTROL REGISTER 1                           */
/*******************************************************************************************/


__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char _CLKSRC_1:1;
    unsigned char _WUPM_1:1;
    unsigned char _LOOPB_1:1;
    unsigned char BIT3:1;
    unsigned char BIT4:1;
    unsigned char BIT5:1;
    unsigned char BIT6:1;
    unsigned char BIT7:1;
  } C1MCR1_BITS;
  unsigned char C1MCR1_BYTE;
} C1MCR11 _IO_AT(0x301);

/*DEFINE REGISTER*/
#define C1MCR1 C1MCR11.C1MCR1_BYTE

/*DEFINE REGISTER BITS*/
#define CLKSRC_1 C1MCR11.C1MCR1_BITS._CLKSRC_1
#define WUPM_1 C1MCR11.C1MCR1_BITS._WUPM_1
#define LOOPB_1 C1MCR11.C1MCR1_BITS._LOOPB_1


/*******************************************************************************************/
/*                               MSCAN12 BUS TIMING REGISTER 0                             */
/*******************************************************************************************/


__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char _BRP0_1:1;
    unsigned char _BRP1_1:1;
    unsigned char _BRP2_1:1;
    unsigned char _BRP3_1:1;
    unsigned char _BRP4_1:1;
    unsigned char _BRP5_1:1;
    unsigned char _SJW0_1:1;
    unsigned char _SJW1_1:1;
  } C1BTR0_BITS;
  unsigned char C1BTR0_BYTE;
} C1BTR01 _IO_AT(0x302);

/*DEFINE REGISTER*/
#define C1BTR0 C1BTR01.C1BTR0_BYTE

/*DEFINE REGISTER BITS*/
#define BRP0_1 C1BTR01.C1BTR0_BITS._BRP0_1
#define BRP1_1 C1BTR01.C1BTR0_BITS._BRP1_1
#define BRP2_1 C1BTR01.C1BTR0_BITS._BRP2_1
#define BRP3_1 C1BTR01.C1BTR0_BITS._BRP3_1
#define BRP4_1 C1BTR01.C1BTR0_BITS._BRP4_1
#define BRP5_1 C1BTR01.C1BTR0_BITS._BRP5_1
#define SJW0_1 C1BTR01.C1BTR0_BITS._SJW0_1
#define SJW1_1 C1BTR01.C1BTR0_BITS._SJW1_1



/*******************************************************************************************/
/*                               MSCAN12 BUS TIMING REGISTER 1                             */
/*******************************************************************************************/


__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char _TSEG10_1:1;
    unsigned char _TSEG11_1:1;
    unsigned char _TSEG12_1:1;
    unsigned char _TSEG13_1:1;
    unsigned char _TSEG20_1:1;
    unsigned char _TSEG21_1:1;
    unsigned char _TSEG22_1:1;
    unsigned char _SAMP_1:1;
  } C1BTR1_BITS;
  unsigned char C1BTR1_BYTE;
} C1BTR11 _IO_AT(0x303);

/*DEFINE REGISTER*/
#define C1BTR1 C1BTR11.C1BTR1_BYTE

/*DEFINE REGISTER BITS*/
#define TSEG10_1 C1BTR11.C1BTR1_BITS._TSEG10_1
#define TSEG11_1 C1BTR11.C1BTR1_BITS._TSEG11_1
#define TSEG12_1 C1BTR11.C1BTR1_BITS._TSEG12_1
#define TSEG13_1 C1BTR11.C1BTR1_BITS._TSEG13_1
#define TSEG20_1 C1BTR11.C1BTR1_BITS._TSEG20_1
#define TSEG21_1 C1BTR11.C1BTR1_BITS._TSEG21_1
#define TSEG22_1 C1BTR11.C1BTR1_BITS._TSEG22_1
#define SAMP_1 C1BTR11.C1BTR1_BITS._SAMP_1



/*******************************************************************************************/
/*                               MSCAN12 RECEIVER FLAG REGISTER                            */
/*******************************************************************************************/


__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char _RFX_1:1;
    unsigned char _OVRIF_1:1;
    unsigned char _BOFFIF_1:1;
    unsigned char _TERRIF_1:1;
    unsigned char _RERRIF_1:1;
    unsigned char _TWRNIF_1:1;
    unsigned char _RWRNIF_1:1;
    unsigned char _WUPIF_1:1;
  } C1RFLG_BITS;
  unsigned char C1RFLG_BYTE;
} C1RFLG1 _IO_AT(0x304);

/*DEFINE REGISTER*/
#define C1RFLG C1RFLG1.C1RFLG_BYTE

/*DEFINE REGISTER BITS*/
#define RFX_1 C1RFLG1.C1RFLG_BITS._RFX_1
#define OVRIF_1 C1RFLG1.C1RFLG_BITS._OVRIF_1
#define BOFFIF_1 C1RFLG1.C1RFLG_BITS._BOFFIF_1
#define TERRIF_1 C1RFLG1.C1RFLG_BITS._TERRIF_1
#define RERRIF_1 C1RFLG1.C1RFLG_BITS._RERRIF_1
#define TWRNIF_1 C1RFLG1.C1RFLG_BITS._TWRNIF_1
#define RWRNIF_1 C1RFLG1.C1RFLG_BITS._RWRNIF_1
#define WUPIF_1 C1RFLG1.C1RFLG_BITS._WUPIF_1


/*******************************************************************************************/
/*                      MSCAN12 RECEIVER INTERRUPT ENABLE REGISTER                         */
/*******************************************************************************************/


__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char _RFXIE_1:1;
    unsigned char _OVRIE_1:1;
    unsigned char _BOFFIE_1:1;
    unsigned char _TERRIE_1:1;
    unsigned char _RERRIE_1:1;
    unsigned char _TWRNIE_1:1;
    unsigned char _RWRNIE_1:1;
    unsigned char _WUPIE_1:1;
  } C1RIER_BITS;
  unsigned char C1RIER_BYTE;
} C1RIER1 _IO_AT(0x305);

/*DEFINE REGISTER*/
#define C1RIER C1RIER1.C1RIER_BYTE

/*DEFINE REGISTER BITS*/
#define RFXIE_1 C1RIER1.C1RIER_BITS._RFXIE_1
#define OVRIE_1 C1RIER1.C1RIER_BITS._OVRIE_1
#define BOFFIE_1 C1RIER1.C1RIER_BITS._BOFFIE_1
#define TERRIE_1 C1RIER1.C1RIER_BITS._TERRIE_1
#define RERRIE_1 C1RIER1.C1RIER_BITS._RERRIE_1
#define TWRNIE_1 C1RIER1.C1RIER_BITS._TWRNIE_1
#define RWRNIE_1 C1RIER1.C1RIER_BITS._RWRNIE_1
#define WUPIE_1 C1RIER1.C1RIER_BITS._WUPIE_1


/*******************************************************************************************/
/*                          MSCAN12 TRANSMITTER FLAG REGISTER                              */
/*******************************************************************************************/


__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char _TXE0_1:1;
    unsigned char _TXE1_1:1;
    unsigned char _TXE2_1:1;
    unsigned char BIT3:1;
    unsigned char _ABTAK0_1:1;
    unsigned char _ABTAK1_1:1;
    unsigned char _ABTAK2_1:1;
    unsigned char BIT7:1;
  } C1TFLG_BITS;
  unsigned char C1TFLG_BYTE;
} C1TFLG1 _IO_AT(0x306);

/*DEFINE REGISTER*/
#define C1TFLG C1TFLG1.C1TFLG_BYTE

/*DEFINE REGISTER BITS*/
#define TXE0_1 C1TFLG1.C1TFLG_BITS._TXE0_1
#define TXE1_1 C1TFLG1.C1TFLG_BITS._TXE1_1
#define TXE2_1 C1TFLG1.C1TFLG_BITS._TXE2_1
#define ABTAK0_1 C1TFLG1.C1TFLG_BITS._ABTAK0_1
#define ABTAK1_1 C1TFLG1.C1TFLG_BITS._ABTAK1_1
#define ABTAK2_1 C1TFLG1.C1TFLG_BITS._ABTAK2_1


/*******************************************************************************************/
/*                          MSCAN12 TRANSMITTER CONTROL REGISTER                           */
/*******************************************************************************************/


__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char _TXEIE0_1:1;
    unsigned char _TXEIE1_1:1;
    unsigned char _TXEIE2_1:1;
    unsigned char BIT3:1;
    unsigned char _ABTRQ0_1:1;
    unsigned char _ABTRQ1_1:1;
    unsigned char _ABTRQ2_1:1;
    unsigned char BIT7:1;
  } C1TCR_BITS;
  unsigned char C1TCR_BYTE;
} C1TCR1 _IO_AT(0x307);

/*DEFINE REGISTER*/
#define C1TCR C1TCR1.C1TCR_BYTE

/*DEFINE REGISTER BITS*/
#define TXEIE0_1 C1TCR1.C1TCR_BITS._TXEIE0_1
#define TXEIE1_1 C1TCR1.C1TCR_BITS._TXEIE1_1
#define TXEIE2_1 C1TCR1.C1TCR_BITS._TXEIE2_1
#define ABTRQ0_1 C1TCR1.C1TCR_BITS._ABTRQ0_1
#define ABTRQ1_1 C1TCR1.C1TCR_BITS._ABTRQ1_1
#define ABTRQ2_1 C1TCR1.C1TCR_BITS._ABTRQ2_1


/*******************************************************************************************/
/*                          MSCAN12 IDENTIFIER ACCEPTANCE CONTROL REGISTER                 */
/*******************************************************************************************/


__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char _IDHIT0_1:1;
    unsigned char _IDHIT1_1:1;
    unsigned char _IDHIT2_1:1;
    unsigned char BIT3:1;
    unsigned char _IDAM0_1:1;
    unsigned char _IDAM1_1:1;
    unsigned char BIT6:1;
    unsigned char BIT7:1;
  } C1IDAC_BITS;
  unsigned char C1IDAC_BYTE;
} C1IDAC1 _IO_AT(0x308);

/*DEFINE REGISTER*/
#define C1IDAC C1IDAC1.C1IDAC_BYTE

/*DEFINE REGISTER BITS*/
#define IDHIT0_1 C1IDAC1.C1IDAC_BITS._IDHIT0_1
#define IDHIT1_1 C1IDAC1.C1IDAC_BITS._IDHIT1_1
#define IDHIT2_1 C1IDAC1.C1IDAC_BITS._IDHIT2_1
#define IDAM0_1 C1IDAC1.C1IDAC_BITS._IDAM0_1
#define IDAM1_1 C1IDAC1.C1IDAC_BITS._IDAM1_1


/**************************************************************************************************/
/*                                      MSCAN12 RECEIVE ERROR COUNTER                             */
/**************************************************************************************************/

__DECL__6812DG128A_H__ volatile unsigned char C1RXERR    _IO_AT(0x30E);


/**************************************************************************************************/
/*                                     MSCAN12 TRANSMIT ERROR COUNTER                             */
/**************************************************************************************************/

__DECL__6812DG128A_H__ volatile unsigned char C1TXERR    _IO_AT(0x30F);


/**************************************************************************************************/
/*                            IDENTIFIER ACCEPTANCE REGISTERS (First bank)                        */
/**************************************************************************************************/

__DECL__6812DG128A_H__ volatile unsigned char C1IDAR0    _IO_AT(0x310);
__DECL__6812DG128A_H__ volatile unsigned char C1IDAR1    _IO_AT(0x311);
__DECL__6812DG128A_H__ volatile unsigned char C1IDAR2    _IO_AT(0x312);
__DECL__6812DG128A_H__ volatile unsigned char C1IDAR3    _IO_AT(0x313);


/**************************************************************************************************/
/*                                  IDENTIFIER MASK REGISTERS (First bank)                        */
/**************************************************************************************************/

__DECL__6812DG128A_H__ volatile unsigned char C1IDMR0    _IO_AT(0x314);
__DECL__6812DG128A_H__ volatile unsigned char C1IDMR1    _IO_AT(0x315);
__DECL__6812DG128A_H__ volatile unsigned char C1IDMR2    _IO_AT(0x316);
__DECL__6812DG128A_H__ volatile unsigned char C1IDMR3    _IO_AT(0x317);


/**************************************************************************************************/
/*                            IDENTIFIER ACCEPTANCE REGISTERS (Second bank)                       */
/**************************************************************************************************/

__DECL__6812DG128A_H__ volatile unsigned char C1IDAR4    _IO_AT(0x318);
__DECL__6812DG128A_H__ volatile unsigned char C1IDAR5    _IO_AT(0x319);
__DECL__6812DG128A_H__ volatile unsigned char C1IDAR6    _IO_AT(0x31A);
__DECL__6812DG128A_H__ volatile unsigned char C1IDAR7    _IO_AT(0x31B);


/**************************************************************************************************/
/*                                  IDENTIFIER MASK REGISTERS (Second bank)                       */
/**************************************************************************************************/

__DECL__6812DG128A_H__ volatile unsigned char C1IDMR4    _IO_AT(0x31C);
__DECL__6812DG128A_H__ volatile unsigned char C1IDMR5    _IO_AT(0x31D);
__DECL__6812DG128A_H__ volatile unsigned char C1IDMR6    _IO_AT(0x31E);
__DECL__6812DG128A_H__ volatile unsigned char C1IDMR7    _IO_AT(0x31F);


/*******************************************************************************************/
/*                           MSCAN12 PORT CAN CONTROL REGISTER 0                           */
/*******************************************************************************************/

__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char _RDPCAN_1:1;
    unsigned char _PUPCAN_1:1;
    unsigned char BIT2:1;
    unsigned char BIT3:1;
    unsigned char BIT4:1;
    unsigned char BIT5:1;
    unsigned char BIT6:1;
    unsigned char BIT7:1;
  } PCTLCAN1_BITS;
  unsigned char PCTLCAN1_BYTE;
} PCTLCAN11 _IO_AT(0x33D);

/*DEFINE REGISTER*/
#define PCTLCAN1 PCTLCAN11.PCTLCAN1_BYTE

/*DEFINE REGISTER BITS*/
#define RDPCAN_1 PCTLCAN11.PCTLCAN1_BITS._RDPCAN_1
#define PUPCAN_1 PCTLCAN11.PCTLCAN1_BITS._PUPCAN_1



/*******************************************************************************************/
/*                              MSCAN12 PORT CAN DATA REGISTER 0                           */
/*******************************************************************************************/

__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char _RxCAN_1:1;
    unsigned char _TxCAN_1:1;
    unsigned char _PCAN2_1:1;
    unsigned char _PCAN3_1:1;
    unsigned char _PCAN4_1:1;
    unsigned char _PCAN5_1:1;
    unsigned char _PCAN6_1:1;
    unsigned char _PCAN7_1:1;
  } PORTCAN1_BITS;
  unsigned char PORTCAN1_BYTE;
} PORTCAN11 _IO_AT(0x33E);

/*DEFINE REGISTER*/
#define PORTCAN1 PORTCAN11.PORTCAN1_BYTE

/*DEFINE REGISTER BITS*/
#define RxCAN_1 PORTCAN11.PORTCAN1_BITS._RxCAN_1
#define TxCAN_1 PORTCAN11.PORTCAN1_BITS._TxCAN_1
#define PCAN2_1 PORTCAN11.PORTCAN1_BITS._PCAN2_1
#define PCAN3_1 PORTCAN11.PORTCAN1_BITS._PCAN3_1
#define PCAN4_1 PORTCAN11.PORTCAN1_BITS._PCAN4_1
#define PCAN5_1 PORTCAN11.PORTCAN1_BITS._PCAN5_1
#define PCAN6_1 PORTCAN11.PORTCAN1_BITS._PCAN6_1
#define PCAN7_1 PORTCAN11.PORTCAN1_BITS._PCAN7_1


/*******************************************************************************************/
/*                         MSCAN12 PORT CAN DATA DIRECTION REGISTER 0                      */
/*******************************************************************************************/

__DECL__6812DG128A_H__ volatile union {
  struct {
    unsigned char BIT0:1;
    unsigned char BIT1:1;
    unsigned char _DDAN2_1:1;
    unsigned char _DDAN3_1:1;
    unsigned char _DDAN4_1:1;
    unsigned char _DDAN5_1:1;
    unsigned char _DDAN6_1:1;
    unsigned char _DDAN7_1:1;
  } DDRCAN1_BITS;
  unsigned char DDRCAN1_BYTE;
} DDRCAN11 _IO_AT(0x33F);

/*DEFINE REGISTER*/
#define DDRCAN1 DDRCAN11.DDRCAN1_BYTE

/*DEFINE REGISTER BITS*/
#define DDAN2_1 DDRCAN11.DDRCAN1_BITS._DDAN2_1
#define DDAN3_1 DDRCAN11.DDRCAN1_BITS._DDAN3_1
#define DDAN4_1 DDRCAN11.DDRCAN1_BITS._DDAN4_1
#define DDAN5_1 DDRCAN11.DDRCAN1_BITS._DDAN5_1
#define DDAN6_1 DDRCAN11.DDRCAN1_BITS._DDAN6_1
#define DDAN7_1 DDRCAN11.DDRCAN1_BITS._DDAN7_1


/**************************************************************************************************/
/*                                  FOREGROUND RECEIVE BUFFER 1                                   */
/**************************************************************************************************/

__DECL__6812DG128A_H__ volatile unsigned char RxFG1[16]    _IO_AT(0x340);


/**************************************************************************************************/
/*                                      TRANSMIT BUFFER 00                                        */
/**************************************************************************************************/

__DECL__6812DG128A_H__ volatile unsigned char Tx10[16]    _IO_AT(0x350);


/**************************************************************************************************/
/*                                      TRANSMIT BUFFER 01                                        */
/**************************************************************************************************/

__DECL__6812DG128A_H__ volatile unsigned char Tx11[16]    _IO_AT(0x360);


/**************************************************************************************************/
/*                                      TRANSMIT BUFFER 02                                        */
/**************************************************************************************************/

__DECL__6812DG128A_H__ volatile unsigned char Tx12[16]    _IO_AT(0x370);

#endif /* __6812DG128_H__ */
