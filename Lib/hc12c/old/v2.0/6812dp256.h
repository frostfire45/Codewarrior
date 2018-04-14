/*****************************************************
    6812dp256.h - Target interface library
    Describes I/O registers of MC68HC12DP256
 ----------------------------------------------------
   Copyright (c) Metrowerks, Basel, Switzerland
                  Do not modify!
 *****************************************************/

/****************************************************************************/
/*      The M68HC12DP256 MCU is equipped with several devices, which share  */
/*      the same architecture. There are 2 Analog to Digital converter      */
/*      (ATD0 and ATD1), 2 Serial Communication Interface (SCI0 and SCI1),  */
/*      3 Serial Peripheral Interface (SPI0, SPI1 and SPI2), 5 CAN module   */
/*      (CAN0, CAN1, CAN2, CAN3 and CAN4). The bits inside of the registers */
/*      for for two similar devices  share the same name. In order to be    */
/*      able to access the single bits in the diferent devices, a suffix    */
/*      has beenadded to the different bit mnemeonics.                      */
/*      _0 has been added to the bit mnemonics inside of ATD0, SCI0, SPI0   */
/*         and CAN0                                                         */
/*      _1 has been added to the bit mnemonics inside of ATD1, SCI1, SPI1   */
/*         and CAN1                                                         */
/*      _2 has been added to the bit mnemonics inside of SPI2 and CAN2      */
/*      _3 has been added to the bit mnemonics inside of CAN3               */
/*      _4 has been added to the bit mnemonics inside of CAN4               */
/*       Example TIE_0 refers to bit 7 in SCI0CR2 register                  */
/*               TIE_1 refers to bit 7 in SCI1CR2 register                  */
/****************************************************************************/


#ifndef __6812DP256_H__
#define __6812DP256_H__

#include <stdtypes.h>

#define _IO_BASE_ADDR 0
#define _IO_AT(x)  @(_IO_BASE_ADDR+(x))

#ifndef __DECL__6812DP256_H__
#define __DECL__6812DP256_H__  extern
#endif

#pragma MESSAGE DISABLE C1106 /* WARNING C1106: Non-standard bitfield type */

/**************************************************************************************************/
/*                                         DEFINE PORT A                                          */
/**************************************************************************************************/
__DECL__6812DP256_H__ volatile   union {                  
  struct {          
    unsigned char BIT0:1;
    unsigned char BIT1:1;
    unsigned char BIT2:1;
    unsigned char BIT3:1;
    unsigned char BIT4:1;
    unsigned char BIT5:1;
    unsigned char BIT6:1;
    unsigned char BIT7:1;
  } PORTA_BITS;        
  unsigned char PORTA_BYTE;  
}PORTA_  _IO_AT(0x00);  /* port A */

/* DEFINE REGISTER */        
#define PORTA PORTA_.PORTA_BYTE

/*DEFINE REGISTER BITS*/
#define PORTA0 PORTA_.PORTA_BITS.BIT0
#define PORTA1 PORTA_.PORTA_BITS.BIT1
#define PORTA2 PORTA_.PORTA_BITS.BIT2
#define PORTA3 PORTA_.PORTA_BITS.BIT3
#define PORTA4 PORTA_.PORTA_BITS.BIT4
#define PORTA5 PORTA_.PORTA_BITS.BIT5
#define PORTA6 PORTA_.PORTA_BITS.BIT6
#define PORTA7 PORTA_.PORTA_BITS.BIT7

__DECL__6812DP256_H__ volatile   union {                  
  struct {          
    unsigned char _DDRA0:1;
    unsigned char _DDRA1:1;
    unsigned char _DDRA2:1;
    unsigned char _DDRA3:1;
    unsigned char _DDRA4:1;
    unsigned char _DDRA5:1;
    unsigned char _DDRA6:1;
    unsigned char _DDRA7:1;
  } DDRA_BITS;        
  unsigned char DDRA_BYTE;  
}DDRA_  _IO_AT(0x02);              


/* DEFINE REGISTER */        
#define DDRA DDRA_.DDRA_BYTE

/*DEFINE REGISTER BITS*/
#define DDRA0 DDRA_.DDRA_BITS._DDRA0
#define DDRA1 DDRA_.DDRA_BITS._DDRA1
#define DDRA2 DDRA_.DDRA_BITS._DDRA2
#define DDRA3 DDRA_.DDRA_BITS._DDRA3
#define DDRA4 DDRA_.DDRA_BITS._DDRA4
#define DDRA5 DDRA_.DDRA_BITS._DDRA5
#define DDRA6 DDRA_.DDRA_BITS._DDRA6
#define DDRA7 DDRA_.DDRA_BITS._DDRA7

/**************************************************************************************************/
/*                                         DEFINE PORT B                                          */
/**************************************************************************************************/
__DECL__6812DP256_H__ volatile   union {                  
  struct {          
    unsigned char BIT0:1;
    unsigned char BIT1:1;
    unsigned char BIT2:1;
    unsigned char BIT3:1;
    unsigned char BIT4:1;
    unsigned char BIT5:1;
    unsigned char BIT6:1;
    unsigned char BIT7:1;
  } PORTB_BITS;        
  unsigned char PORTB_BYTE;  
}PORTB_  _IO_AT(0x01);  /* port B */

/* DEFINE REGISTER */        
#define PORTB PORTB_.PORTB_BYTE

/*DEFINE REGISTER BITS*/
#define PORTB0 PORTB_.PORTB_BITS.BIT0
#define PORTB1 PORTB_.PORTB_BITS.BIT1
#define PORTB2 PORTB_.PORTB_BITS.BIT2
#define PORTB3 PORTB_.PORTB_BITS.BIT3
#define PORTB4 PORTB_.PORTB_BITS.BIT4
#define PORTB5 PORTB_.PORTB_BITS.BIT5
#define PORTB6 PORTB_.PORTB_BITS.BIT6
#define PORTB7 PORTB_.PORTB_BITS.BIT7


__DECL__6812DP256_H__ volatile   union {                  
  struct {          
    unsigned char _DDRB0:1;
    unsigned char _DDRB1:1;
    unsigned char _DDRB2:1;
    unsigned char _DDRB3:1;
    unsigned char _DDRB4:1;
    unsigned char _DDRB5:1;
    unsigned char _DDRB6:1;
    unsigned char _DDRB7:1;
  } DDRB_BITS;        
  unsigned char DDRB_BYTE;  
}DDRB_  _IO_AT(0x03);              


/* DEFINE REGISTER */        
#define DDRB DDRB_.DDRB_BYTE

/*DEFINE REGISTER BITS*/
#define DDRB0 DDRB_.DDRB_BITS._DDRB0
#define DDRB1 DDRB_.DDRB_BITS._DDRB1
#define DDRB2 DDRB_.DDRB_BITS._DDRB2
#define DDRB3 DDRB_.DDRB_BITS._DDRB3
#define DDRB4 DDRB_.DDRB_BITS._DDRB4
#define DDRB5 DDRB_.DDRB_BITS._DDRB5
#define DDRB6 DDRB_.DDRB_BITS._DDRB6
#define DDRB7 DDRB_.DDRB_BITS._DDRB7

/**************************************************************************************************/
/*                                         DEFINE PORT E                                          */
/**************************************************************************************************/

__DECL__6812DP256_H__ volatile  unsigned char PORTE    _IO_AT(0x08);  /* port E */

/****Data Register E******/           
__DECL__6812DP256_H__ volatile   union {                  
  struct {          
    unsigned char BIT0:1;
    unsigned char BIT1:1;
    unsigned char _DDRE2:1;
    unsigned char _DDRE3:1;
    unsigned char _DDRE4:1;
    unsigned char _DDRE5:1;
    unsigned char _DDRE6:1;
    unsigned char _DDRE7:1;
  } DDRE_BITS;        
  unsigned char DDRE_BYTE;  
}DDRE1  _IO_AT(0x09);              


/* DEFINE REGISTER */        
#define DDRE DDRE1.DDRE_BYTE

/*DEFINE REGISTER BITS*/
#define DDRE2 DDRE1.DDRE_BITS._DDRE2
#define DDRE3 DDRE1.DDRE_BITS._DDRE3
#define DDRE4 DDRE1.DDRE_BITS._DDRE4
#define DDRE5 DDRE1.DDRE_BITS._DDRE5
#define DDRE6 DDRE1.DDRE_BITS._DDRE6
#define DDRE7 DDRE1.DDRE_BITS._DDRE7

/**************************************************************************************************/
/*                               PORT E ASSIGNEMENT REGISTER                                      */
/**************************************************************************************************/
__DECL__6812DP256_H__ volatile  union {                  
  struct {          
    unsigned char BIT0:1;
    unsigned char BIT1:1;
    unsigned char _RDWE:1;
    unsigned char _LSTRE:1;
    unsigned char _NECLK:1;
    unsigned char _PIPOE:1;
    unsigned char BIT6:1;
    unsigned char _NOACCE:1;
  } PEAR_BITS;        
  unsigned char PEAR_BYTE;  
}PEAR1 _IO_AT(0x0a);       

/*DEFINE REGISTER*/
#define PEAR PEAR1.PEAR_BYTE

/*DEFINE REGISTER BITS*/
#define RDWE PEAR1.PEAR_BITS._RDWE
#define LSTRE PEAR1.PEAR_BITS._LSTRE
#define NECKL PEAR1.PEAR_BITS._NECLK
#define PIPOE PEAR1.PEAR_BITS._PIPOE
#define NOACCE PEAR1.PEAR_BITS._NOACCE

/**************************************************************************************************/
/*                                            MODE REGISTER                                       */
/**************************************************************************************************/
__DECL__6812DP256_H__ volatile  union {                  
  struct {          
    unsigned char _EME:1     ;
    unsigned char _EMK:1    ;
    unsigned char BIT2:1  ;
    unsigned char _IVIS:1    ;
    unsigned char BIT4:1    ;
    unsigned char _MODA:1    ;
    unsigned char _MODB:1    ;
    unsigned char _MODC:1   ;
  } MODE_BITS;        
  unsigned char MODE_BYTE;  
}MODE1 _IO_AT(0x0B);       

/*DEFINE REGISTER*/
#define MODE MODE1.MODE_BYTE

/*DEFINE REGISTER BITS*/
#define EME MODE1.MODE_BITS._EME
#define EMK MODE1.MODE_BITS._EMK
#define IVIS MODE1.MODE_BITS._IVIS
#define MODA MODE1.MODE_BITS._MODA
#define MODB MODE1.MODE_BITS._MODB
#define MODC MODE1.MODE_BITS._MODC

/**************************************************************************************************/
/*                               PULL-UP CONTROL REGISTER                                         */
/**************************************************************************************************/
__DECL__6812DP256_H__ volatile  union {                  
  struct {          
    unsigned char _PUPAE:1;
    unsigned char _PUPBE:1;
    unsigned char BIT2:1;
    unsigned char BIT3:1;
    unsigned char _PUPEE:1;
    unsigned char BIT5:1;
    unsigned char BIT6:1;
    unsigned char _PUPKE:1;
  } PUCR_BITS;        
  unsigned char PUCR_BYTE;  
}PUCR1 _IO_AT(0x0C);       

/*DEFINE REGISTER*/
#define PUCR PUCR1.PUCR_BYTE

/*DEFINE REGISTER BITS*/
#define PUPAE PUCR1.PUCR_BITS._PUPAE
#define PUPBE PUCR1.PUCR_BITS._PUPBE
#define PUPEE PUCR1.PUCR_BITS._PUPEE
#define PUPKE PUCR1.PUCR_BITS._PUPKE

/**************************************************************************************************/
/*                               REDUCED DRIVE OF I\O LINES                                       */
/**************************************************************************************************/
__DECL__6812DP256_H__ volatile  union {                  
  struct {          
    unsigned char _RDPA:1;
    unsigned char _RDPB:1;
    unsigned char BIT2:1;
    unsigned char BIT3:1;
    unsigned char _RDPE:1;
    unsigned char BIT5:1;
    unsigned char BIT6:1;
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
#define RDPK RDRIV1.RDRIV_BITS._RDPK

/**************************************************************************************************/
/*                              EXTERNAL BUS INTERFACE CONTROL                                    */
/**************************************************************************************************/
__DECL__6812DP256_H__ volatile  union {                  
  struct {          
    unsigned char _ESTR:1;
    unsigned char BIT1:1;
    unsigned char BIT2:1;
    unsigned char BIT3:1;
    unsigned char BIT4:1;
    unsigned char BIT5:1;
    unsigned char BIT6:1;
    unsigned char BIT7:1;
  } EBICTL_BITS;        
  unsigned char EBICTL_BYTE;  
}EBICTL1 _IO_AT(0x0E);       

/*DEFINE REGISTER*/
#define EBICTL EBICTL1.EBICTL_BYTE

/*DEFINE REGISTER BITS*/
#define ESTR EBICTL1.EBICTL_BITS._ESTR

/**************************************************************************************************/
/*                    INITIALIZATION OF INTERNAL RAM POSITION REGISTER                            */
/**************************************************************************************************/
__DECL__6812DP256_H__ volatile  union {                  
  struct {          
    unsigned char _RAMHAL:1;
    unsigned char BIT1:1;
    unsigned char BIT2:1;
    unsigned char _RAM11:1;
    unsigned char _RAM12:1;
    unsigned char _RAM13:1;
    unsigned char _RAM14:1;
    unsigned char _RAM15:1;
  } INITRM_BITS;        
  unsigned char INITRM_BYTE;  
}INITRM1 _IO_AT(0x10);       

/*DEFINE REGISTER*/
#define INITRM INITRM1.INITRM_BYTE

/*DEFINE REGISTER BITS*/
#define RAMHAL INITRM1.INITRM_BITS._RAMHAL
#define RAM11  INITRM1.INITRM_BITS._RAM11
#define RAM12  INITRM1.INITRM_BITS._RAM12
#define RAM13  INITRM1.INITRM_BITS._RAM13
#define RAM14  INITRM1.INITRM_BITS._RAM14
#define RAM15  INITRM1.INITRM_BITS._RAM15

/**************************************************************************************************/
/*                    INITIALIZATION OF INTERNAL REGISTER POSITION REGISTER                       */
/**************************************************************************************************/
__DECL__6812DP256_H__ volatile  union {                  
  struct {          
    unsigned char BIT0:1;
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
#define REG11 INITRG1.INITRG_BITS._REG11
#define REG12 INITRG1.INITRG_BITS._REG12
#define REG13 INITRG1.INITRG_BITS._REG13
#define REG14 INITRG1.INITRG_BITS._REG14
#define REG15 INITRG1.INITRG_BITS._REG15

/**************************************************************************************************/
/*                    INITIALIZATION OF INTERNAL EEPROM POSITION REGISTER                         */
/**************************************************************************************************/
__DECL__6812DP256_H__ volatile  union {                  
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
__DECL__6812DP256_H__ volatile  union {                  
  struct {          
    unsigned char _ROMON:1;
    unsigned char _ROMHM:1;
    unsigned char _EXSTR0:1;
    unsigned char _EXSTR1:1;
    unsigned char BIT4:1;
    unsigned char BIT5:1;
    unsigned char BIT6:1;
    unsigned char BIT7:1;
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

/**************************************************************************************************/
/*                                     MAPPING TEST REGISTERS                                     */
/**************************************************************************************************/
__DECL__6812DP256_H__ volatile  unsigned char  MTST0   _IO_AT(0x14); 
__DECL__6812DP256_H__ volatile  unsigned char  MTST1   _IO_AT(0x17); 


/**************************************************************************************************/
/*                             INTERRUPT TEST CONTROL REGISTER                                    */
/**************************************************************************************************/
__DECL__6812DP256_H__ volatile  union {                  
  struct {          
    unsigned char _ADR0:1;
    unsigned char _ADR1:1;
    unsigned char _ADR2:1;
    unsigned char _ADR3:1;
    unsigned char _WRINT:1;
    unsigned char BIT5:1;
    unsigned char BIT6:1;
    unsigned char BIT7:1;
  } ITCR_BITS;        
  unsigned char ITCR_BYTE;  
}ITCR1 _IO_AT(0x15);       

/*DEFINE REGISTER*/
#define ITCR ITCR1.ITCR_BYTE

/*DEFINE REGISTER BITS*/
#define ADR0 ITCR1.ITCR_BITS._ADR0
#define ADR1 ITCR1.ITCR_BITS._ADR1
#define ADR2 ITCR1.ITCR_BITS._ADR2
#define ADR3 ITCR1.ITCR_BITS._ADR3
#define WRINT ITCR1.ITCR_BITS._WRINT

/**************************************************************************************************/
/*                                INTERRUPT TEST  REGISTER                                        */
/**************************************************************************************************/
__DECL__6812DP256_H__ volatile  union {                  
  struct {          
    unsigned char _INT0:1;
    unsigned char _INT2:1;
    unsigned char _INT4:1;
    unsigned char _INT6:1;
    unsigned char _INT8:1;
    unsigned char _INTA:1;
    unsigned char _INTC:1;
    unsigned char _INTE:1;
  } ITEST_BITS;        
  unsigned char ITEST_BYTE;  
}ITEST1 _IO_AT(0x16);       

/*DEFINE REGISTER*/
#define ITEST ITEST1.ITEST_BYTE

/*DEFINE REGISTER BITS*/
#define INT0 ITEST1.ITEST_BITS._INT0
#define INT2 ITEST1.ITEST_BITS._INT2
#define INT4 ITEST1.ITEST_BITS._INT4
#define INT6 ITEST1.ITEST_BITS._INT6
#define INT8 ITEST1.ITEST_BITS._INT8
#define INTA ITEST1.ITEST_BITS._INTA
#define INTC ITEST1.ITEST_BITS._INTC
#define INTE ITEST1.ITEST_BITS._INTE

/**************************************************************************************************/
/*                              PART ID  REGISTER ASSIGNMENTS                                     */
/**************************************************************************************************/
__DECL__6812DP256_H__ volatile  union {                  
  struct {
    unsigned char _PARTIDH;          
    unsigned char _PARTIDL;          
  } PARTID_BYTES;        
  unsigned int PARTID_WORD;  
}PARTID1 _IO_AT(0x1A);       

/*DEFINE REGISTER*/
#define PARTID PARTID1.PARTID_WORD

/*DEFINE REGISTER BYTES*/
#define PARTIDH PARTID1.PARTID_BYTES._PARTIDH
#define PARTIDL PARTID1.PARTID_BYTES._PARTIDL

/**************************************************************************************************/
/*                                                                        */
/**************************************************************************************************/
__DECL__6812DP256_H__ volatile  union {                  
  struct {          
    unsigned char _ram_sw0:1;
    unsigned char _ram_sw1:1;
    unsigned char _ram_sw2:1;
    unsigned char BIT3:1;
    unsigned char _eep_sw0:1;
    unsigned char _eep_sw1:1;
    unsigned char BIT6:1;
    unsigned char _reg_sw0:1;
  } MEMSIZ0_BITS;        
  unsigned char MEMSIZ0_BYTE;  
}MEMSIZ01 _IO_AT(0x1C);       

/*DEFINE REGISTER*/
#define MEMSIZ0 MEMSIZ01.MEMSIZ0_BYTE

/*DEFINE REGISTER BITS*/
#define ram_sw0 MEMSIZ01.MEMSIZ0_BITS._ram_sw0
#define ram_sw1 MEMSIZ01.MEMSIZ0_BITS._ram_sw1
#define ram_sw2 MEMSIZ01.MEMSIZ0_BITS._ram_sw2
#define eep_sw0 MEMSIZ01.MEMSIZ0_BITS._eep_sw0
#define eep_sw1 MEMSIZ01.MEMSIZ0_BITS._eep_sw1
#define reg_sw0 MEMSIZ01.MEMSIZ0_BITS._reg_sw0

/**************************************************************************************************/
/*                                                                        */
/**************************************************************************************************/
__DECL__6812DP256_H__ volatile  union {                  
  struct {          
    unsigned char _pag_sw0:1;
    unsigned char _pag_sw1:1;
    unsigned char BIT2:1;
    unsigned char BIT3:1;
    unsigned char BIT4:1;
    unsigned char BIT5:1;
    unsigned char _rom_sw0:1;
    unsigned char _rom_sw1:1;
  } MEMSIZ1_BITS;        
  unsigned char MEMSIZ1_BYTE;  
}MEMSIZ11 _IO_AT(0x1D);       

/*DEFINE REGISTER*/
#define MEMSIZ1 MEMSIZ11.MEMSIZ1_BYTE

/*DEFINE REGISTER BITS*/
#define pag_sw0 MEMSIZ11.MEMSIZ1_BITS._pag_sw0
#define pag_sw1 MEMSIZ11.MEMSIZ1_BITS._pag_sw1
#define rom_sw0 MEMSIZ11.MEMSIZ1_BITS._rom_sw0
#define rom_sw1 MEMSIZ11.MEMSIZ1_BITS._rom_sw1

/**************************************************************************************************/
/*                                     INTERRUPT CONTROL REGISTER                                 */
/**************************************************************************************************/
__DECL__6812DP256_H__ volatile  union {                  
  struct {          
    unsigned char BIT0:1;
    unsigned char BIT1:1;
    unsigned char BIT2:1;
    unsigned char BIT3:1;
    unsigned char BIT4:1;
    unsigned char BIT5:1;
    unsigned char _IRQEN:1;
    unsigned char _IRQE:1;
  } INTCR_BITS;        
  unsigned char INTCR_BYTE;  
}INTCR1 _IO_AT(0x1E);       

/*DEFINE REGISTER*/
#define INTCR INTCR1.INTCR_BYTE

/*DEFINE REGISTER BITS*/
#define IRQEN INTCR1.INTCR_BITS._IRQEN
#define IRQE INTCR1.INTCR_BITS._IRQE

/**************************************************************************************************/
/*                                   HIGHEST PRIORITY I INTERRUPT                                 */
/**************************************************************************************************/
__DECL__6812DP256_H__ volatile  union {                  
  struct {          
    unsigned char BIT0:1;
    unsigned char _PSEL1:1;
    unsigned char _PSEL2:1;
    unsigned char _PSEL3:1;
    unsigned char _PSEL4:1;
    unsigned char _PSEL5:1;
    unsigned char _PSEL6:1;
    unsigned char _PSEL7:1;
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
#define PSEL7 HPRIO1.HPRIO_BITS._PSEL7

/**************************************************************************************************/
/*                                   BREAKPOINT CONTROL REGISTER 0                                */
/**************************************************************************************************/
__DECL__6812DP256_H__ volatile  union {                  
  struct {          
    unsigned char BIT0:1;
    unsigned char BIT1:1;
    unsigned char BIT2:1;
    unsigned char BIT3:1;
    unsigned char _BKTAG:1;
    unsigned char _BKBDM:1;
    unsigned char _BKFULL:1;
    unsigned char _BKEN:1;
  } BKPCT0_BITS;        
  unsigned char BKPCT0_BYTE;  
}BKPCT01 _IO_AT(0x28);       

/*DEFINE REGISTER*/
#define BKPCT0 BKPCT01.BKPCT0_BYTE

/*DEFINE REGISTER BITS*/
#define BKTAG  BKPCT01.BKPCT0_BITS._BKTAG
#define BKBDM  BKPCT01.BKPCT0_BITS._BKBDM
#define BKFULL BKPCT01.BKPCT0_BITS._BKFULL
#define BKEN   BKPCT01.BKPCT0_BITS._BKEN

/*******************************************************************************************/
/*                                   BREAKPOINT CONTROL REGISTER 1                         */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  union {                                                                           
  struct {                                                                            
    unsigned char _BK1RW:1;                                                               
    unsigned char _BK1RWE:1;                                                               
    unsigned char _BK0RW:1;                                                             
    unsigned char _BK0RWE:1;                                                             
    unsigned char _BK1MBL:1;                                                               
    unsigned char _BK1MBH:1;                                                               
    unsigned char _BK0MBL:1;                                                              
    unsigned char _BK0MBH:1;                                                              
  } BKPCT1_BITS;                                                                      
  unsigned char BKPCT1_BYTE;                                                                
}BKPCT11 _IO_AT(0x29);                                                               

/*DEFINE REGISTER*/                                                                         
#define BKPCT1 BKPCT11.BKPCT1_BYTE                                                           

/*DEFINE REGISTER BITS*/                                                                    
#define BK1RW BKPCT11.BKPCT1_BITS._BK1RW                                                    
#define BK1RWE BKPCT11.BKPCT1_BITS._BK1RWE                                                    
#define BK0RW BKPCT11.BKPCT1_BITS._BK0RW                                                        
#define BK0RWE BKPCT11.BKPCT1_BITS._BK0RWE
#define BK1MBL BKPCT11.BKPCT1_BITS._BK1MBL                                                       
#define BK1MBH BKPCT11.BKPCT1_BITS._BK1MBH
#define BK0MBL BKPCT11.BKPCT1_BITS._BK0MBL                                                       
#define BK0MBH BKPCT11.BKPCT1_BITS._BK0MBH                                                       

/*******************************************************************************************/
/*                           BREAKPOINT DATA AND ADDRESS REGISTERS                         */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  unsigned char BKP0X    _IO_AT(0x2A);  /* Breakpoint Address Register,Bank Number*/
__DECL__6812DP256_H__ volatile  unsigned int  BKP0     _IO_AT(0x2B);  /* Breakpoint Address Register*/

__DECL__6812DP256_H__ volatile  unsigned char BKP1X    _IO_AT(0x2D);  /* Breakpoint Address Register,Bank Number*/
__DECL__6812DP256_H__ volatile  unsigned int  BKP1     _IO_AT(0x2E);  /* Breakpoint Data Register*/

/*******************************************************************************************/
/*                             (PROGRAM) PAGE INDEX REGISTER                               */                                
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  unsigned char PPAGE    _IO_AT(0x30);  

/*******************************************************************************************/
/*                                              PORT K                                     */                                
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  unsigned char PORTK    _IO_AT(0x32);  /* port K */

__DECL__6812DP256_H__ volatile  unsigned char DDRK     _IO_AT(0x33);  /* data direction port K */

/*******************************************************************************************/
/*                                    SYNTHETIZER REGISTER                                 */
/*******************************************************************************************/
/* Bits 6-7 is this registers are unimplemented. They cannot be used. */
__DECL__6812DP256_H__ volatile  unsigned char SYNR _IO_AT(0x34);

/*******************************************************************************************/
/*                              REFERENCE DIVIDER REGISTER                                 */
/*******************************************************************************************/
/* Bits 4-7 is this registers are unimplemented. They cannot be used. */
__DECL__6812DP256_H__ volatile  unsigned char REFDV _IO_AT(0x35);

/**************************************************************************************************/
/*                                     CLOCK GENERATOR TEST REGISTER                              */
/**************************************************************************************************/
__DECL__6812DP256_H__ volatile  unsigned char  CTFLG    _IO_AT(0x36);  

/**************************************************************************************************/
/*                                   CLOCK GENERATOR FLAG REGISTER                                */
/**************************************************************************************************/
__DECL__6812DP256_H__ volatile  union {                  
  struct {          
    unsigned char _SCM:1;
    unsigned char _SCMIF:1;
    unsigned char _TRACK:1;
    unsigned char _LOCK:1;
    unsigned char _LOCKIF:1;
    unsigned char BIT5:1;
    unsigned char _PROF:1;
    unsigned char _RTIF:1;
  } CRGFLG_BITS;        
  unsigned char CRGFLG_BYTE;  
}CRGFLG1 _IO_AT(0x37);       

/*DEFINE REGISTER*/
#define CRGFLG CRGFLG1.CRGFLG_BYTE

/*DEFINE REGISTER BITS*/
#define SCM   CRGFLG1.CRGFLG_BITS._SCM
#define SCMIF CRGFLG1.CRGFLG_BITS._SCMIF
#define TRACK CRGFLG1.CRGFLG_BITS._TRACK
#define LOCK  CRGFLG1.CRGFLG_BITS._LOCK
#define LOCKIF CRGFLG1.CRGFLG_BITS._LOCKIF
#define PROF  CRGFLG1.CRGFLG_BITS._PROF
#define RTIF  CRGFLG1.CRGFLG_BITS._RTIF

/**************************************************************************************************/
/*                             CLOCK GENERATOR INTERRUPT MASK REGISTER                            */
/**************************************************************************************************/
__DECL__6812DP256_H__ volatile  union {                  
  struct {          
    unsigned char BIT0:1;
    unsigned char _SCMIE:1;
    unsigned char BIT2:1;
    unsigned char BIT3:1;
    unsigned char _LOCKIE:1;
    unsigned char BIT5:1;
    unsigned char BIT6:1;
    unsigned char _RTIE:1;
  } CRGINT_BITS;        
  unsigned char CRGINT_BYTE;  
}CRGINT1 _IO_AT(0x38);       

/*DEFINE REGISTER*/
#define CRGINT CRGINT1.CRGINT_BYTE

/*DEFINE REGISTER BITS*/
#define SCMIE CRGINT1.CRGINT_BITS._SCMIE
#define LOCKIE CRGINT1.CRGINT_BITS._LOCKIE
#define RTIE CRGINT1.CRGINT_BITS._RTIE

/*******************************************************************************************/
/*                     CLOCK GENERATOR CLOCK SELECT REGISTER                               */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  union {                            
  struct {                             
    unsigned char _COPWAI:1;               
    unsigned char _RTIWAI:1;              
    unsigned char _CWAI:1;               
    unsigned char _PLLWAI:1;              
    unsigned char _ROAWAI:1;               
    unsigned char _SYSWAI:1;               
    unsigned char _PSTP:1;               
    unsigned char _PLLSEL:1;                
  } CLKSEL_BITS;                       
  unsigned char CLKSEL_BYTE;                 
}CLKSEL1 _IO_AT(0x39);                

/*DEFINE REGISTER*/                          
#define CLKSEL CLKSEL1.CLKSEL_BYTE            

/*DEFINE REGISTER BITS*/                     
#define COPWAI CLKSEL1.CLKSEL_BITS._COPWAI
#define RTIWAI CLKSEL1.CLKSEL_BITS._RTIWAI
#define CWAI   CLKSEL1.CLKSEL_BITS._CWAI
#define PLLWAI CLKSEL1.CLKSEL_BITS._PLLWAI
#define ROAWAI CLKSEL1.CLKSEL_BITS._ROAWAI
#define SYSWAI CLKSEL1.CLKSEL_BITS._SYSWAI
#define PSTP   CLKSEL1.CLKSEL_BITS._PSTP
#define PLLSEL CLKSEL1.CLKSEL_BITS._PLLSEL

/*******************************************************************************************/
/*                                              PLL CONTROL REGISTER                       */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  union {                            
  struct {                             
    unsigned char _SCME:1;               
    unsigned char _PCE:1;              
    unsigned char _PRE:1;               
    unsigned char BIT3:1;              
    unsigned char _ACQ:1;               
    unsigned char _AUTO:1;               
    unsigned char _PLLON:1;               
    unsigned char _CME:1;                
  } PLLCTL_BITS;                       
  unsigned char PLLCTL_BYTE;                 
}PLLCTL1 _IO_AT(0x3A);                

/*DEFINE REGISTER*/                          
#define PLLCTL PLLCTL1.PLLCTL_BYTE            

/*DEFINE REGISTER BITS*/                     
#define SCME  PLLCTL1.PLLCTL_BITS._SCME
#define PCE   PLLCTL1.PLLCTL_BITS._PCE
#define PRE   PLLCTL1.PLLCTL_BITS._PRE
#define ACQ   PLLCTL1.PLLCTL_BITS._ACQ
#define AUTO  PLLCTL1.PLLCTL_BITS._AUTO
#define PLLON PLLCTL1.PLLCTL_BITS._PLLON
#define CME   PLLCTL1.PLLCTL_BITS._CME

/**************************************************************************************************/
/*                                     REAL-TIME INTERRUPT ENABLE                                 */
/**************************************************************************************************/
__DECL__6812DP256_H__ volatile  union {                  
  struct {          
    unsigned char _RTR0:1;
    unsigned char _RTR1:1;
    unsigned char _RTR2:1;
    unsigned char _RTR3:1;
    unsigned char _RTR4:1;
    unsigned char _RTR5:1;
    unsigned char _RTR6:1;
    unsigned char BIT7:1;
  } RTICTL_BITS;        
  unsigned char RTICTL_BYTE;  
}RTICTL1 _IO_AT(0x3B);       

/*DEFINE REGISTER*/
#define RTICTL RTICTL1.RTICTL_BYTE

/*DEFINE REGISTER BITS*/
#define RTR0 RTICTL1.RTICTL_BITS._RTR0
#define RTR1 RTICTL1.RTICTL_BITS._RTR1
#define RTR2 RTICTL1.RTICTL_BITS._RTR2
#define RTR3 RTICTL1.RTICTL_BITS._RTR3
#define RTR4 RTICTL1.RTICTL_BITS._RTR4
#define RTR5 RTICTL1.RTICTL_BITS._RTR5
#define RTR6 RTICTL1.RTICTL_BITS._RTR6

/**************************************************************************************************/
/*                                       COP CONTROL REGISTER                                     */
/**************************************************************************************************/
__DECL__6812DP256_H__ volatile  union {                  
  struct {          
    unsigned char _CR0:1;
    unsigned char _CR1:1;
    unsigned char _CR2:1;
    unsigned char BIT3:1;
    unsigned char BIT4:1;
    unsigned char BIT5:1;
    unsigned char BIT6:1;
    unsigned char _WCOP:1;
  } COPCTL_BITS;        
  unsigned char COPCTL_BYTE;  
}COPCTL1 _IO_AT(0x3C);       

/*DEFINE REGISTER*/
#define COPCTL COPCTL1.COPCTL_BYTE

/*DEFINE REGISTER BITS*/
#define CR0  COPCTL1.COPCTL_BITS._CR0
#define CR1  COPCTL1.COPCTL_BITS._CR1
#define CR2  COPCTL1.COPCTL_BITS._CR2
#define WCOP COPCTL1.COPCTL_BITS._WCOP

/**************************************************************************************************/
/*                                                                            */
/**************************************************************************************************/
__DECL__6812DP256_H__ volatile  union {                  
  struct {          
    unsigned char BIT0:1;
    unsigned char _FCM:1;
    unsigned char BIT2:1;
    unsigned char BIT3:1;
    unsigned char _PLLBYP:1;
    unsigned char BIT5:1;
    unsigned char _COPBYP:1;
    unsigned char _RTIBYP:1;
  } FORBYP_BITS;        
  unsigned char FORBYP_BYTE;  
}FORBYP1 _IO_AT(0x3D);       

/*DEFINE REGISTER*/
#define FORBYP FORBYP1.FORBYP_BYTE

/*DEFINE REGISTER BITS*/
#define FCM    FORBYP1.FORBYP_BITS._FCM
#define PLLBYP FORBYP1.FORBYP_BITS._PLLBYP
#define COPBYP FORBYP1.FORBYP_BITS._COPBYP
#define RTIBYP FORBYP1.FORBYP_BITS._RTIBYP

/**************************************************************************************************/
/*                                                                            */
/**************************************************************************************************/
__DECL__6812DP256_H__ volatile  unsigned char CTCTL     _IO_AT(0x3E);  
__DECL__6812DP256_H__ volatile  unsigned char ARMCOP    _IO_AT(0x3F);  

/*******************************************************************************************/
/*                           TIMER INPUT/OUTPUT COMPARE SELECT                             */
/*******************************************************************************************/   
__DECL__6812DP256_H__ volatile  unsigned char TIOS     _IO_AT(0x40);

/*******************************************************************************************/
/*                          TIMER COMPARE FORCE REGISTER                                  */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  unsigned char CFORC     _IO_AT(0x41); 
#define TCFORC CFORC  /* Motorola documentation is inconsistent (CFORC and TCFORC used) */
/*******************************************************************************************/
/*                         OUTPUT COMPARE 7 MASK REGISTER                                  */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  unsigned char OC7M     _IO_AT(0x42); 
#define TOC7M OC7M  /* Motorola documentation is inconsistent (TOC7M and OC7M used) */
/*******************************************************************************************/
/*                         OUTPUT COMPARE 7 DATA REGISTER                                  */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  unsigned char OC7D     _IO_AT(0x43);
#define TOC7D OC7D  /* Motorola documentation is inconsistent (TOC7D and OC7D used) */
/*******************************************************************************************/
/*                         OUTPUT COMPARE 7 DATA REGISTER                                  */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  unsigned int TCNT     _IO_AT(0x44); 

/*******************************************************************************************/
/*                                TIMER SYSTEM CONTROL REGISTER 1                          */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  union {                            
  struct {                             
    unsigned char BIT0:1;               
    unsigned char BIT1:1;              
    unsigned char BIT2:1;               
    unsigned char BIT3:1;              
    unsigned char _TFFCA:1;               
    unsigned char _TSFRZ:1;               
    unsigned char _TSWAI:1;               
    unsigned char _TEN:1;                
  } TSCR1_BITS;                       
  unsigned char TSCR1_BYTE;                 
} TSCR11 _IO_AT(0x46);                

/*DEFINE REGISTER*/                          
#define TSCR1 TSCR11.TSCR1_BYTE            

/*DEFINE REGISTER BITS*/                     
#define TFFCA TSCR11.TSCR1_BITS._TFFCA       
#define TSFRZ TSCR11.TSCR1_BITS._TSFRZ       
#define TSWAI TSCR11.TSCR1_BITS._TSWAI       
#define TEN   TSCR11.TSCR1_BITS._TEN       

/*******************************************************************************************/
/*                                                  */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  unsigned char TTOV     _IO_AT(0x47);  

/*******************************************************************************************/
/*                                TIMER CONTROL REGISTER 1                                 */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  union {                            
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
} TCTL11 _IO_AT(0x48);                

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
__DECL__6812DP256_H__ volatile  union {                            
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
} TCTL21 _IO_AT(0x49);                

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
__DECL__6812DP256_H__ volatile  union {                            
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
} TCTL31 _IO_AT(0x4A);                

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
__DECL__6812DP256_H__ volatile  union {                            
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
} TCTL41 _IO_AT(0x4B);                

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
/*                            TIMER INTERRUPT ENABLE REGISTER                              */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  union {                            
  struct {                             
    unsigned char _C0I:1;               
    unsigned char _C1I:1;              
    unsigned char _C2I:1;               
    unsigned char _C3I:1;              
    unsigned char _C4I:1;               
    unsigned char _C5I:1;               
    unsigned char _C6I:1;               
    unsigned char _C7I:1;                
  } TIE_BITS;                       
  unsigned char TIE_BYTE;                 
} _TIE _IO_AT(0x4C);                

/*DEFINE REGISTER*/                          
#define TIE _TIE.TIE_BYTE            

/*DEFINE REGISTER BITS*/                     
#define C0I _TIE.TIE_BITS._C0I       
#define C1I _TIE.TIE_BITS._C1I     
#define C2I _TIE.TIE_BITS._C2I       
#define C3I _TIE.TIE_BITS._C3I       
#define C4I _TIE.TIE_BITS._C4I       
#define C5I _TIE.TIE_BITS._C5I    
#define C6I _TIE.TIE_BITS._C6I       
#define C7I _TIE.TIE_BITS._C7I           

/*******************************************************************************************/
/*                                TIMER SYSTEM CONTROL REGISTER 2                          */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  union {                            
  struct {                             
    unsigned char _PR0:1;               
    unsigned char _PR1:1;              
    unsigned char _PR2:1;               
    unsigned char _TCRE:1;              
    unsigned char BIT4:1;               
    unsigned char BIT5:1;               
    unsigned char BIT6:1;               
    unsigned char _TOI:1;                
  } TSCR2_BITS;                       
  unsigned char TSCR2_BYTE;                 
} TSCR21 _IO_AT(0x4D);                

/*DEFINE REGISTER*/                          
#define TSCR2 TSCR21.TSCR2_BYTE            

/*DEFINE REGISTER BITS*/                     
#define PR0  TSCR21.TSCR2_BITS._PR0       
#define PR1  TSCR21.TSCR2_BITS._PR1       
#define PR2  TSCR21.TSCR2_BITS._PR2       
#define TCRE TSCR21.TSCR2_BITS._TCRE       
#define TOI  TSCR21.TSCR2_BITS._TOI       

/*******************************************************************************************/
/*                                TIMER INTERRUPT FLAG 1                                   */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  union {                            
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
} TFLG11 _IO_AT(0x4E);                

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
__DECL__6812DP256_H__ volatile  union {                            
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
} TFLG21 _IO_AT(0x4F);                

/*DEFINE REGISTER*/                          
#define TFLG2 TFLG21.TFLG2_BYTE            

/*DEFINE REGISTER BITS*/               
#define TOF TFLG21.TFLG2_BITS._TOF

/*******************************************************************************************/
/*                         TIMER INPUT CAPTURE/OUTPUT REGISTERS                            */
/*******************************************************************************************/

/*****TIMER INPUT CAPTURE/OUTPUT REGISTER 0*****/
__DECL__6812DP256_H__ volatile  unsigned int TC0      _IO_AT(0x50);  

/*****TIMER INPUT CAPTURE/OUTPUT REGISTER 1*****/
__DECL__6812DP256_H__ volatile  unsigned int TC1      _IO_AT(0x52);  

/*****TIMER INPUT CAPTURE/OUTPUT REGISTER 2*****/
__DECL__6812DP256_H__ volatile  unsigned int TC2      _IO_AT(0x54);  

/*****TIMER INPUT CAPTURE/OUTPUT REGISTER 3*****/
__DECL__6812DP256_H__ volatile  unsigned int TC3      _IO_AT(0x56);  

/*****TIMER INPUT CAPTURE/OUTPUT REGISTER 4*****/
__DECL__6812DP256_H__ volatile  unsigned int TC4      _IO_AT(0x58);  

/*****TIMER INPUT CAPTURE/OUTPUT REGISTER 5*****/
__DECL__6812DP256_H__ volatile  unsigned int TC5      _IO_AT(0x5a);  

/*****TIMER INPUT CAPTURE/OUTPUT REGISTER 6*****/
__DECL__6812DP256_H__ volatile  unsigned int TC6      _IO_AT(0x5c);  

/*****TIMER INPUT CAPTURE/OUTPUT REGISTER 7*****/
__DECL__6812DP256_H__ volatile  unsigned int TC7      _IO_AT(0x5e);  

/*******************************************************************************************/
/*                        PULSE ACCUMULATOR CONTROL REGISTER                               */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  union {                            
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
} PACTL1 _IO_AT(0x60);                

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
__DECL__6812DP256_H__ volatile  union {                            
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
} PAFLG1 _IO_AT(0x61);                

/*DEFINE REGISTER*/                          
#define PAFLG PAFLG1.PAFLG_BYTE            

/*DEFINE REGISTER BITS*/                     
#define PAIF PAFLG1.PAFLG_BITS._PAIF       
#define PAOVF PAFLG1.PAFLG_BITS._PAOVF     

/*******************************************************************************************/
/*                      16-BITS PULSE ACCUMULATOR COUNT REGISTERS                          */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  unsigned char PACN3    _IO_AT(0x62);  
__DECL__6812DP256_H__ volatile  unsigned char PACN2    _IO_AT(0x63);  
__DECL__6812DP256_H__ volatile  unsigned char PACN1    _IO_AT(0x64);  
__DECL__6812DP256_H__ volatile  unsigned char PACN0    _IO_AT(0x65);  

/*******************************************************************************************/
/*                  16-BIT MODULUS DOWN-COUNTER CONTROL REGISTER                           */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  union {                            
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
} MCCTL1 _IO_AT(0x66);                

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
__DECL__6812DP256_H__ volatile  union {                            
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
} MCFLG1 _IO_AT(0x67);                

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
__DECL__6812DP256_H__ volatile  union {                            
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
} ICPAR1 _IO_AT(0x68);                

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
__DECL__6812DP256_H__ volatile  union {                            
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
} DLYCT1 _IO_AT(0x69);                

/*DEFINE REGISTER*/                          
#define DLYCT DLYCT1.DLYCT_BYTE            

/*DEFINE REGISTER BITS*/                     
#define DLY0 DLYCT1.DLYCT_BITS._DLY0     
#define DLY1 DLYCT1.DLYCT_BITS._DLY1

/*******************************************************************************************/
/*                              INPUT CONTROL OVERWRITE REGISTER                           */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  unsigned char ICOVW    _IO_AT(0x6A);  

/*******************************************************************************************/
/*                            INPUT CONTROL SYSTEM CONTROL REGISTER                        */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  union {                            
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
} ICSYS1 _IO_AT(0x6B);                

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
__DECL__6812DP256_H__ volatile  union {                            
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
} TIMTST1 _IO_AT(0x6D);                

/*DEFINE REGISTER*/                          
#define TIMTST TIMTST1.TIMTST_BYTE            

/*DEFINE REGISTER BITS*/                     
#define TCBBYP TIMTST1.TIMTST_BITS._TCBYP       

/*******************************************************************************************/
/*                         16-BIT PULSE ACCUMULATOR B CONTROL REGISTER                     */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  union {                            
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
} PBCTL1 _IO_AT(0x70);                

/*DEFINE REGISTER*/                          
#define PBCTL PBCTL1.PBCTL_BYTE            

/*DEFINE REGISTER BITS*/                     
#define PB0VI PBCTL1.PBCTL_BITS._PB0VI /* do not use PB0VI any more (shall be PBOVI) */
#define PBOVI PBCTL1.PBCTL_BITS._PB0VI
  
#define PBEN PBCTL1.PBCTL_BITS._PBEN  

/*******************************************************************************************/
/*                         16-BIT PULSE ACCUMULATOR B FLAG REGISTER                        */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  union {                            
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
} PBFLG1 _IO_AT(0x71);                

/*DEFINE REGISTER*/                          
#define PBFLG PBFLG1.PBFLG_BYTE            

/*DEFINE REGISTER BITS*/                     
#define PB0VF PBFLG1.PBFLG_BITS._PB0VF   

/*******************************************************************************************/
/*                      8-BIT PULSE ACCUMULATORS HOLDING REGISTERS                         */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  unsigned char PA3H    _IO_AT(0x72);  
__DECL__6812DP256_H__ volatile  unsigned char PA2H    _IO_AT(0x73); 
__DECL__6812DP256_H__ volatile  unsigned char PA1H    _IO_AT(0x74); 
__DECL__6812DP256_H__ volatile  unsigned char PA0H    _IO_AT(0x75); 

/*******************************************************************************************/  
/*                              MODULUS DOWN-COUNTER REGISTERS                             */  
/*******************************************************************************************/  


__DECL__6812DP256_H__ volatile  union {                  
  struct {
    unsigned char _MCCNTH;       /* Modulus down-counter high */    
    unsigned char _MCCNTL;       /* Modulus down-counter low */ 
  } MCCNT_BYTES;                 
  unsigned int MCCNTW_WORD;      /* Modulus down-counter word */   
} MCCNT_ _IO_AT(0x76);       

#define MCCNTW   MCCNT_.MCCNTW_WORD            /* Modulus down-counter word */
#define MCCNTH   MCCNT_.MCCNT_BYTES._MCCNTH    /* Modulus down-counter high */                                     
#define MCCNTL   MCCNT_.MCCNT_BYTES._MCCNTL    /* Modulus down-counter high */ 

/*******************************************************************************************/  
/*                         TIMER INPUT CAPTURE HOLDING REGISTERS                           */  
/*******************************************************************************************/  
__DECL__6812DP256_H__ volatile  unsigned int TC0H   _IO_AT(0x78); /* Timer Input Capture Holding Register 0 */ 
__DECL__6812DP256_H__ volatile  unsigned int TC1H   _IO_AT(0x7A); /* Timer Input Capture Holding Register 1 */ 
__DECL__6812DP256_H__ volatile  unsigned int TC2H   _IO_AT(0x7C); /* Timer Input Capture Holding Register 2 */ 
__DECL__6812DP256_H__ volatile  unsigned int TC3H   _IO_AT(0x7E); /* Timer Input Capture Holding Register 3 */

/**************************************************************************************************/
/*                                    ATD PORTS STRUCTURE                                         */
/**************************************************************************************************/
/**********ATD CONTROL REGISTER 2********/
typedef  union {                            
  struct {                             
    unsigned char _ASCIF:1;               
    unsigned char _ASCIE:1;              
    unsigned char _ETRIG:1;               
    unsigned char _ETRIGP:1;              
    unsigned char _ETRIGLE:1;               
    unsigned char _AWAI:1;               
    unsigned char _AFFC:1;               
    unsigned char _ADPU:1;                
  } ATDCTL2_BITS;                       
  unsigned char ATDCTL2_BYTE;                 
}ATDCTL2_TYPE;                

/**********ATD CONTROL REGISTER 3********/
typedef  union {                         
  struct {                          
    unsigned char _FRZ0:1;            
    unsigned char _FRZ1:1;            
    unsigned char _FIFO:1;             
    unsigned char _S1C:1;             
    unsigned char _S2C:1;             
    unsigned char _S4C:1;            
    unsigned char _S8C:1;             
    unsigned char BIT7:1;             
  } ATDCTL3_BITS;                   
  unsigned char ATDCTL3_BYTE;               
}ATDCTL3_TYPE;            

/**********ATD CONTROL REGISTER 4********/
typedef  union {                         
  struct {                          
    unsigned char _PRS0:1;            
    unsigned char _PRS1:1;            
    unsigned char _PRS2:1;             
    unsigned char _PRS3:1;             
    unsigned char _PRS4:1;             
    unsigned char _SMP0:1;            
    unsigned char _SMP1:1;             
    unsigned char _SRES8:1;             
  } ATDCTL4_BITS;                   
  unsigned char ATDCTL4_BYTE;               
}ATDCTL4_TYPE;            

/**********ATD CONTROL REGISTER 5********/
typedef  union {                         
  struct {                          
    unsigned char _CA:1;            
    unsigned char _CB:1;            
    unsigned char _CC:1;             
    unsigned char BIT3:1;             
    unsigned char _MULT:1;             
    unsigned char _SCAN:1;            
    unsigned char _DSGN:1;             
    unsigned char _DJM:1;             
  } ATDCTL5_BITS;                   
  unsigned char ATDCTL5_BYTE;               
}ATDCTL5_TYPE;            

/**********ATD STATUS REGISTER 0********/
typedef  union {                         
  struct {                          
    unsigned char  _CC0:1;          
    unsigned char  _CC1:1;
    unsigned char  _CC2:1;           
    unsigned char  BIT3:1;           
    unsigned char  _FIFOR:1;
    unsigned char  _ETORF:1;
    unsigned char  BIT6:1;
    unsigned char  _SCF:1;          
  } ATDSTAT0_BITS;                 
  unsigned char ATDSTAT0_BYTE;               
}ATDSTAT0_TYPE;            

/**********ATD STATUS REGISTER 1********/
typedef  union {                         
  struct {
    unsigned char  _CCF0:1;
    unsigned char  _CCF1:1;
    unsigned char  _CCF2:1;
    unsigned char  _CCF3:1;
    unsigned char  _CCF4:1;
    unsigned char  _CCF5:1;
    unsigned char  _CCF6:1;
    unsigned char  _CCF7:1; 
  } ATDSTAT1_BITS;                 
  unsigned char ATDSTAT1_BYTE;               
}ATDSTAT1_TYPE;            

/********ATD TEST REGISTER HIGH*********/
typedef  union {                            
  struct {                             
    unsigned char _SAR2:1;               
    unsigned char _SAR3:1;              
    unsigned char _SAR4:1;               
    unsigned char _SAR5:1;              
    unsigned char _SAR6:1;               
    unsigned char _SAR7:1;               
    unsigned char _SAR8:1;               
    unsigned char _SAR9:1;                
  } ATDTEST0_BITS;                      
  unsigned char ATDTEST0_BYTE;                 
} ATDTEST0_TYPE;     

/********ATD TEST REGISTER LOW**********/
typedef  union {                            
  struct {                             
    unsigned char _SC:1;               
    unsigned char BIT1:1;              
    unsigned char _RST:1;               
    unsigned char BIT3:1;              
    unsigned char BIT4:1;               
    unsigned char BIT5:1;               
    unsigned char _SAR0:1;               
    unsigned char _SAR1:1;                
  } ATDTEST1_BITS;                       
  unsigned char ATDTEST1_BYTE;                 
} ATDTEST1_TYPE;
                           
/**************************************************************************************************/
/*                                  ATD 0 RESERVED REGISTERS                                      */
/**************************************************************************************************/
__DECL__6812DP256_H__ volatile  unsigned char ATD0CTL0  _IO_AT(0x80); /* A/D control register 0 */
__DECL__6812DP256_H__ volatile  unsigned char ATD0CTL1  _IO_AT(0x81); /* A/D control register 1 */

/**************************************************************************************************/
/*                                   ATD 0 CONTROL REGISTERS                                      */
/**************************************************************************************************/

/**********ATD CONTROL REGISTER 2********/
__DECL__6812DP256_H__ volatile  ATDCTL2_TYPE ATD0CTL21 _IO_AT(0x82);                

/*DEFINE REGISTER*/                          
#define ATD0CTL2 ATD0CTL21.ATDCTL2_BYTE            

/*DEFINE REGISTER BITS*/                      
#define ASCIF_0   ATD0CTL21.ATDCTL2_BITS._ASCIF       
#define ASCIE_0   ATD0CTL21.ATDCTL2_BITS._ASCIE
#define ETRIG_0   ATD0CTL21.ATDCTL2_BITS._ETRIG
#define ETRIGP_0  ATD0CTL21.ATDCTL2_BITS._ETRIGP
#define ETRIGLE_0 ATD0CTL21.ATDCTL2_BITS._ETRIGLE
#define ASWAI_0   ATD0CTL21.ATDCTL2_BITS._AWAI
#define AFFC_0    ATD0CTL21.ATDCTL2_BITS._AFFC
#define ADPU_0    ATD0CTL21.ATDCTL2_BITS._ADPU

/**********ATD CONTROL REGISTER 3********/
__DECL__6812DP256_H__ volatile  ATDCTL3_TYPE ATD0CTL31 _IO_AT(0x83);            

/*DEFINE REGISTER*/                       
#define ATD0CTL3 ATD0CTL31.ATDCTL3_BYTE      

/*DEFINE REGISTER BITS*/                  
#define FRZ0_0 ATD0CTL31.ATDCTL3_BITS._FRZ0  
#define FRZ1_0 ATD0CTL31.ATDCTL3_BITS._FRZ1 
#define FIFO_0 ATD0CTL31.ATDCTL3_BITS._FIFO  
#define S1C_0  ATD0CTL31.ATDCTL3_BITS._S1C 
#define S2C_0  ATD0CTL31.ATDCTL3_BITS._S2C  
#define S4C_0  ATD0CTL31.ATDCTL3_BITS._S4C 
#define S8C_0  ATD0CTL31.ATDCTL3_BITS._S8C  

/**********ATD CONTROL REGISTER 4********/
__DECL__6812DP256_H__ volatile  ATDCTL4_TYPE ATD0CTL41 _IO_AT(0x84);            

/*DEFINE REGISTER*/                       
#define ATD0CTL4 ATD0CTL41.ATDCTL4_BYTE      

/*DEFINE REGISTER BITS*/                  
#define PRS0_0  ATD0CTL41.ATDCTL4_BITS._PRS0  
#define PRS1_0  ATD0CTL41.ATDCTL4_BITS._PRS1  
#define PRS2_0  ATD0CTL41.ATDCTL4_BITS._PRS2  
#define PRS3_0  ATD0CTL41.ATDCTL4_BITS._PRS3  
#define PRS4_0  ATD0CTL41.ATDCTL4_BITS._PRS4  
#define SMP0_0  ATD0CTL41.ATDCTL4_BITS._SMP0
#define SMP1_0  ATD0CTL41.ATDCTL4_BITS._SMP1
#define SRES8_0 ATD0CTL41.ATDCTL4_BITS._SRES8

/**********ATD CONTROL REGISTER 5********/
__DECL__6812DP256_H__ volatile  ATDCTL5_TYPE ATD0CTL51 _IO_AT(0x85);            

/*DEFINE REGISTER*/                       
#define ATD0CTL5 ATD0CTL51.ATDCTL5_BYTE      

/*DEFINE REGISTER BITS*/                  
#define CA_0   ATD0CTL51.ATDCTL5_BITS._CA  
#define CB_0   ATD0CTL51.ATDCTL5_BITS._CB  
#define CC_0   ATD0CTL51.ATDCTL5_BITS._CC  
#define MULT_0 ATD0CTL51.ATDCTL5_BITS._MULT  
#define SCAN_0 ATD0CTL51.ATDCTL5_BITS._SCAN
#define DSGN_0 ATD0CTL51.ATDCTL5_BITS._DSGN   
#define DJM_0  ATD0CTL51.ATDCTL5_BITS._DJM   

/**************************************************************************************************/
/*                                   ATD 0 STATUS REGISTER 0                                        */
/**************************************************************************************************/
__DECL__6812DP256_H__ volatile  ATDSTAT0_TYPE ATD0STAT01 _IO_AT(0x86);            

/*DEFINE REGISTER*/                       
#define ATD0STAT0 ATD0STAT01.ATDSTAT0_BYTE      

/*DEFINE REGISTER BITS*/                  
#define CC0_0   ATD0STAT01.ATDSTAT0_BITS._CC0  
#define CC1_0   ATD0STAT01.ATDSTAT0_BITS._CC1
#define CC2_0   ATD0STAT01.ATDSTAT0_BITS._CC2
#define FIFOR_0 ATD0STAT01.ATDSTAT0_BITS._FIFOR
#define ETORF_0 ATD0STAT01.ATDSTAT0_BITS._ETORF
#define SCF_0   ATD0STAT01.ATDSTAT0_BITS._SCF

/*******************************************************************************************/
/*                                       ATD 0 TEST REGISTER                               */
/*******************************************************************************************/

/********ATD TEST REGISTER HIGH*********/
__DECL__6812DP256_H__ volatile  ATDTEST0_TYPE ATD0TEST01 _IO_AT(0x88);                

/*DEFINE REGISTER*/                          
#define ATD0TEST0 ATD0TEST01.ATDTEST0_BYTE            

/*DEFINE REGISTER BITS*/                     
#define SAR2_0 ATD0TEST01.ATDTEST0_BITS._SAR2       
#define SAR3_0 ATD0TEST01.ATDTEST0_BITS._SAR3       
#define SAR4_0 ATD0TEST01.ATDTEST0_BITS._SAR4       
#define SAR5_0 ATD0TEST01.ATDTEST0_BITS._SAR5       
#define SAR6_0 ATD0TEST01.ATDTEST0_BITS._SAR6       
#define SAR7_0 ATD0TEST01.ATDTEST0_BITS._SAR7       
#define SAR8_0 ATD0TEST01.ATDTEST0_BITS._SAR8       
#define SAR9_0 ATD0TEST01.ATDTEST0_BITS._SAR9       

/********ATD TEST REGISTER LOW**********/
__DECL__6812DP256_H__ volatile  ATDTEST1_TYPE ATD0TEST11 _IO_AT(0x89);                

/*DEFINE REGISTER*/                          
#define ATD0TEST1 ATD0TEST11.ATDTEST1_BYTE            

/*DEFINE REGISTER BITS*/                     
#define SC_0   ATD0TEST11.ATDTEST1_BITS._SC       
#define RST_0  ATD0TEST11.ATDTEST1_BITS._RST       
#define SAR0_0 ATD0TEST11.ATDTEST1_BITS._SAR0       
#define SAR1_0 ATD0TEST11.ATDTEST1_BITS._SAR1       

/**************************************************************************************************/
/*                                   ATD 0 STATUS REGISTER 1                                        */
/**************************************************************************************************/
__DECL__6812DP256_H__ volatile  ATDSTAT1_TYPE ATD0STAT11 _IO_AT(0x8B);            

/*DEFINE REGISTER*/                       
#define ATD0STAT1 ATD0STAT11.ATDSTAT1_BYTE

#define CCF0_0  ATD0STAT11.ATDSTAT1_BITS._CCF0
#define CCF1_0  ATD0STAT11.ATDSTAT1_BITS._CCF1 
#define CCF2_0  ATD0STAT11.ATDSTAT1_BITS._CCF2 
#define CCF3_0  ATD0STAT11.ATDSTAT1_BITS._CCF3 
#define CCF4_0  ATD0STAT11.ATDSTAT1_BITS._CCF4 
#define CCF5_0  ATD0STAT11.ATDSTAT1_BITS._CCF5 
#define CCF6_0  ATD0STAT11.ATDSTAT1_BITS._CCF6 
#define CCF7_0  ATD0STAT11.ATDSTAT1_BITS._CCF7 

__DECL__6812DP256_H__ volatile  unsigned char ATD0DIEN  _IO_AT(0x8D); 
__DECL__6812DP256_H__ volatile  unsigned char PORTAD0   _IO_AT(0x8F); 
__DECL__6812DP256_H__ volatile  unsigned int  ATD0DR0   _IO_AT(0x90); 
__DECL__6812DP256_H__ volatile  unsigned int  ATD0DR1   _IO_AT(0x92); 
__DECL__6812DP256_H__ volatile  unsigned int  ATD0DR2   _IO_AT(0x94); 
__DECL__6812DP256_H__ volatile  unsigned int  ATD0DR3   _IO_AT(0x96); 
__DECL__6812DP256_H__ volatile  unsigned int  ATD0DR4   _IO_AT(0x98); 
__DECL__6812DP256_H__ volatile  unsigned int  ATD0DR5   _IO_AT(0x9A); 
__DECL__6812DP256_H__ volatile  unsigned int  ATD0DR6   _IO_AT(0x9C); 
__DECL__6812DP256_H__ volatile  unsigned int  ATD0DR7   _IO_AT(0x9E); 

/**************************************************************************************************/
/*                                  ATD 1 RESERVED REGISTERS                                      */
/**************************************************************************************************/
__DECL__6812DP256_H__ volatile  unsigned char ATD1CTL0  _IO_AT(0x120); /* A/D control register 0 */
__DECL__6812DP256_H__ volatile  unsigned char ATD1CTL1  _IO_AT(0x121); /* A/D control register 1 */

/**************************************************************************************************/
/*                                   ATD 1 CONTROL REGISTERS                                      */
/**************************************************************************************************/

/**********ATD CONTROL REGISTER 2********/
__DECL__6812DP256_H__ volatile  ATDCTL2_TYPE ATD1CTL21 _IO_AT(0x122);                

/*DEFINE REGISTER*/                          
#define ATD1CTL2 ATD1CTL21.ATDCTL2_BYTE            

/*DEFINE REGISTER BITS*/                      
#define ASCIF_1   ATD1CTL21.ATDCTL2_BITS._ASCIF       
#define ASCIE_1   ATD1CTL21.ATDCTL2_BITS._ASCIE
#define ETRIG_1   ATD1CTL21.ATDCTL2_BITS._ETRIG
#define ETRIGP_1  ATD1CTL21.ATDCTL2_BITS._ETRIGP
#define ETRIGLE_1 ATD1CTL21.ATDCTL2_BITS._ETRIGLE
#define ASWAI_1   ATD1CTL21.ATDCTL2_BITS._AWAI
#define AFFC_1    ATD1CTL21.ATDCTL2_BITS._AFFC
#define ADPU_1    ATD1CTL21.ATDCTL2_BITS._ADPU

/**********ATD CONTROL REGISTER 3********/
__DECL__6812DP256_H__ volatile  ATDCTL3_TYPE ATD1CTL31 _IO_AT(0x123);            

/*DEFINE REGISTER*/                       
#define ATD1CTL3 ATD1CTL31.ATDCTL3_BYTE      

/*DEFINE REGISTER BITS*/                  
#define FRZ0_1 ATD1CTL31.ATDCTL3_BITS._FRZ0  
#define FRZ1_1 ATD1CTL31.ATDCTL3_BITS._FRZ1 
#define FIFO_1 ATD1CTL31.ATDCTL3_BITS._FIFO  
#define S1C_1  ATD1CTL31.ATDCTL3_BITS._S1C 
#define S2C_1  ATD1CTL31.ATDCTL3_BITS._S2C  
#define S4C_1  ATD1CTL31.ATDCTL3_BITS._S4C 
#define S8C_1  ATD1CTL31.ATDCTL3_BITS._S8C  

/**********ATD CONTROL REGISTER 4********/
__DECL__6812DP256_H__ volatile  ATDCTL4_TYPE ATD1CTL41 _IO_AT(0x124);            

/*DEFINE REGISTER*/                       
#define ATD1CTL4 ATD1CTL41.ATDCTL4_BYTE      

/*DEFINE REGISTER BITS*/                  
#define PRS0_1  ATD1CTL41.ATDCTL4_BITS._PRS0  
#define PRS1_1  ATD1CTL41.ATDCTL4_BITS._PRS1  
#define PRS2_1  ATD1CTL41.ATDCTL4_BITS._PRS2  
#define PRS3_1  ATD1CTL41.ATDCTL4_BITS._PRS3  
#define PRS4_1  ATD1CTL41.ATDCTL4_BITS._PRS4  
#define SMP0_1  ATD1CTL41.ATDCTL4_BITS._SMP0
#define SMP1_1  ATD1CTL41.ATDCTL4_BITS._SMP1
#define SRES8_1 ATD1CTL41.ATDCTL4_BITS._SRES8

/**********ATD CONTROL REGISTER 5********/
__DECL__6812DP256_H__ volatile  ATDCTL5_TYPE ATD1CTL51 _IO_AT(0x125);            
                                                                 
/*DEFINE REGISTER*/                       
#define ATD1CTL5 ATD1CTL51.ATDCTL5_BYTE      

/*DEFINE REGISTER BITS*/                  
#define CA_1   ATD1CTL51.ATDCTL5_BITS._CA  
#define CB_1   ATD1CTL51.ATDCTL5_BITS._CB  
#define CC_1   ATD1CTL51.ATDCTL5_BITS._CC  
#define MULT_1 ATD1CTL51.ATDCTL5_BITS._MULT  
#define SCAN_1 ATD1CTL51.ATDCTL5_BITS._SCAN
#define DSGN_1 ATD1CTL51.ATDCTL5_BITS._DSGN   
#define DJM_1  ATD1CTL51.ATDCTL5_BITS._DJM   

/**************************************************************************************************/
/*                                   ATD 1 STATUS REGISTER 0                                       */
/**************************************************************************************************/
__DECL__6812DP256_H__ volatile  ATDSTAT0_TYPE ATD1STAT01 _IO_AT(0x126);            

/*DEFINE REGISTER*/                       
#define ATD1STAT0 ATD1STAT01.ATDSTAT0_BYTE      

/*DEFINE REGISTER BITS*/                  
#define CC0_1   ATD1STAT01.ATDSTAT0_BITS._CC0  
#define CC1_1   ATD1STAT01.ATDSTAT0_BITS._CC1
#define CC2_1   ATD1STAT01.ATDSTAT0_BITS._CC2
#define FIFOR_1 ATD1STAT01.ATDSTAT0_BITS._FIFOR
#define ETORF_1 ATD1STAT01.ATDSTAT0_BITS._ETORF
#define SCF_1   ATD1STAT01.ATDSTAT0_BITS._SCF


/*******************************************************************************************/
/*                                       ATD 1 TEST REGISTER                               */
/*******************************************************************************************/

/********ATD TEST REGISTER HIGH*********/
__DECL__6812DP256_H__ volatile  ATDTEST0_TYPE ATD1TEST01 _IO_AT(0x128);                

/*DEFINE REGISTER*/                          
#define ATD1TEST0 ATD1TEST01.ATDTEST0_BYTE            

/*DEFINE REGISTER BITS*/                     
#define SAR2_1 ATD1TEST01.ATDTEST0_BITS._SAR2       
#define SAR3_1 ATD1TEST01.ATDTEST0_BITS._SAR3       
#define SAR4_1 ATD1TEST01.ATDTEST0_BITS._SAR4       
#define SAR5_1 ATD1TEST01.ATDTEST0_BITS._SAR5       
#define SAR6_1 ATD1TEST01.ATDTEST0_BITS._SAR6       
#define SAR7_1 ATD1TEST01.ATDTEST0_BITS._SAR7       
#define SAR8_1 ATD1TEST01.ATDTEST0_BITS._SAR8       
#define SAR9_1 ATD1TEST01.ATDTEST0_BITS._SAR9       

/********ATD TEST REGISTER LOW**********/
__DECL__6812DP256_H__ volatile  ATDTEST1_TYPE ATD1TEST11 _IO_AT(0x129);                

/*DEFINE REGISTER*/                          
#define ATD1TEST1 ATD1TEST11.ATDTEST1_BYTE            

/*DEFINE REGISTER BITS*/                     
#define SC_1   ATD1TEST11.ATDTEST1_BITS._SC       
#define RST_1  ATD1TEST11.ATDTEST1_BITS._RST       
#define SAR0_1 ATD1TEST11.ATDTEST1_BITS._SAR0       
#define SAR1_1 ATD1TEST11.ATDTEST1_BITS._SAR1       

/**************************************************************************************************/
/*                                   ATD 1 STATUS REGISTER 1                                       */
/**************************************************************************************************/
__DECL__6812DP256_H__ volatile  ATDSTAT1_TYPE ATD1STAT11 _IO_AT(0x12B);            

/*DEFINE REGISTER*/                       
#define ATD1STAT1 ATD1STAT11.ATDSTAT1_BYTE      

/*DEFINE REGISTER BITS*/                  
#define CCF0_1  ATD1STAT11.ATDSTAT1_BITS._CCF0
#define CCF1_1  ATD1STAT11.ATDSTAT1_BITS._CCF1 
#define CCF2_1  ATD1STAT11.ATDSTAT1_BITS._CCF2 
#define CCF3_1  ATD1STAT11.ATDSTAT1_BITS._CCF3 
#define CCF4_1  ATD1STAT11.ATDSTAT1_BITS._CCF4 
#define CCF5_1  ATD1STAT11.ATDSTAT1_BITS._CCF5 
#define CCF6_1  ATD1STAT11.ATDSTAT1_BITS._CCF6 
#define CCF7_1  ATD1STAT11.ATDSTAT1_BITS._CCF7 

__DECL__6812DP256_H__ volatile  unsigned char ATD1DIEN  _IO_AT(0x12D); 
__DECL__6812DP256_H__ volatile  unsigned char PORTAD1   _IO_AT(0x12F); 
__DECL__6812DP256_H__ volatile  unsigned int  ATD1DR0   _IO_AT(0x130); 
__DECL__6812DP256_H__ volatile  unsigned int  ATD1DR1   _IO_AT(0x132); 
__DECL__6812DP256_H__ volatile  unsigned int  ATD1DR2   _IO_AT(0x134); 
__DECL__6812DP256_H__ volatile  unsigned int  ATD1DR3   _IO_AT(0x136); 
__DECL__6812DP256_H__ volatile  unsigned int  ATD1DR4   _IO_AT(0x138); 
__DECL__6812DP256_H__ volatile  unsigned int  ATD1DR5   _IO_AT(0x13A); 
__DECL__6812DP256_H__ volatile  unsigned int  ATD1DR6   _IO_AT(0x13C); 
__DECL__6812DP256_H__ volatile  unsigned int  ATD1DR7   _IO_AT(0x13E); 

/*******************************************************************************************/
/*                                          PWM ENABLE                                     */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  union {                            
  struct {                             
    unsigned char _PWME0:1;               
    unsigned char _PWME1:1;              
    unsigned char _PWME2:1;               
    unsigned char _PWME3:1;              
    unsigned char _PWME4:1;               
    unsigned char _PWME5:1;               
    unsigned char _PWME6:1;               
    unsigned char _PWME7:1;                
  } PWME_BITS;                       
  unsigned char PWME_BYTE;                 
}PWME_ _IO_AT(0xA0);                

/*DEFINE REGISTER*/                          
#define PWME PWME_.PWME_BYTE            

/*DEFINE REGISTER BITS*/                     
#define PWME0 PWME_.PWME_BITS._PWME0       
#define PWME1 PWME_.PWME_BITS._PWME1     
#define PWME2 PWME_.PWME_BITS._PWME2       
#define PWME3 PWME_.PWME_BITS._PWME3     
#define PWME4 PWME_.PWME_BITS._PWME4       
#define PWME5 PWME_.PWME_BITS._PWME5       
#define PWME6 PWME_.PWME_BITS._PWME6       
#define PWME7 PWME_.PWME_BITS._PWME7       

/*******************************************************************************************/
/*                              PWM CLOCK SELECT AND POLARITY                              */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  union {                            
  struct {                             
    unsigned char _PPOL0:1;               
    unsigned char _PPOL1:1;              
    unsigned char _PPOL2:1;               
    unsigned char _PPOL3:1;              
    unsigned char _PPOL4:1;               
    unsigned char _PPOL5:1;               
    unsigned char _PPOL6:1;               
    unsigned char _PPOL7:1;                
  } PWMPOL_BITS;                       
  unsigned char PWMPOL_BYTE;                 
}PWMPOL1 _IO_AT(0xA1);                

/*DEFINE REGISTER*/                          
#define PWMPOL PWMPOL1.PWMPOL_BYTE            

/*DEFINE REGISTER BITS*/                     
#define PPOL0 PWMPOL1.PWMPOL_BITS._PPOL0       
#define PPOL1 PWMPOL1.PWMPOL_BITS._PPOL1
#define PPOL2 PWMPOL1.PWMPOL_BITS._PPOL2
#define PPOL3 PWMPOL1.PWMPOL_BITS._PPOL3       
#define PPOL4 PWMPOL1.PWMPOL_BITS._PPOL4    
#define PPOL5 PWMPOL1.PWMPOL_BITS._PPOL5       
#define PPOL6 PWMPOL1.PWMPOL_BITS._PPOL6       
#define PPOL7 PWMPOL1.PWMPOL_BITS._PPOL7       

/*******************************************************************************************/
/*                               PWM CLOCK AND CONCATENATE                                 */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  union {                            
  struct {                             
    unsigned char _PCLK0:1;               
    unsigned char _PCLK1:1;              
    unsigned char _PCLK2:1;               
    unsigned char _PCLK3:1;              
    unsigned char _PCLK4:1;               
    unsigned char _PCLK5:1;               
    unsigned char _PCLK6:1;               
    unsigned char _PCLK7:1;                
  } PWMCLK_BITS;                       
  unsigned char PWMCLK_BYTE;                 
}PWMCLK1 _IO_AT(0xA2);                

/*DEFINE REGISTER*/                          
#define PWMCKL PWMCLK1.PWMCLK_BYTE            
#define PWMCLK PWMCKL /* the manual is using PWMCLK */

/*DEFINE REGISTER BITS*/                     
#define PCLK0 PWMCLK1.PWMCLK_BITS._PCLK0       
#define PCLK1 PWMCLK1.PWMCLK_BITS._PCLK1     
#define PCLK2 PWMCLK1.PWMCLK_BITS._PCLK2       
#define PCLK3 PWMCLK1.PWMCLK_BITS._PCLK3     
#define PCLK4 PWMCLK1.PWMCLK_BITS._PCLK4       
#define PCLK5 PWMCLK1.PWMCLK_BITS._PCLK5       
#define PCLK6 PWMCLK1.PWMCLK_BITS._PCLK6       
#define PCLK7 PWMCLK1.PWMCLK_BITS._PCLK7       

/*******************************************************************************************/
/*                                                               */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  union {                            
  struct {                             
    unsigned char _PCKA0:1;               
    unsigned char _PCKA1:1;              
    unsigned char _PCKA2:1;               
    unsigned char BIT3:1;              
    unsigned char _PCKB0:1;               
    unsigned char _PCKB1:1;               
    unsigned char _PCKB2:1;               
    unsigned char BIT7:1;                
  } PWMPRCLK_BITS;                       
  unsigned char PWMPRCLK_BYTE;                 
}PWMPRCLK1 _IO_AT(0xA3);                

/*DEFINE REGISTER*/                          
#define PWMPRCLK PWMPRCLK1.PWMPRCLK_BYTE            

/*DEFINE REGISTER BITS*/                     
#define PCKA0 PWMPRCLK1.PWMPRCLK_BITS._PCKA0       
#define PCKA1 PWMPRCLK1.PWMPRCLK_BITS._PCKA1     
#define PCKA2 PWMPRCLK1.PWMPRCLK_BITS._PCKA2       
#define PCKB0 PWMPRCLK1.PWMPRCLK_BITS._PCKB0     
#define PCKB1 PWMPRCLK1.PWMPRCLK_BITS._PCKB1       
#define PCKB2 PWMPRCLK1.PWMPRCLK_BITS._PCKB2       

/*******************************************************************************************/
/*                                                              */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  union {                            
  struct {                             
    unsigned char _CAE0:1;               
    unsigned char _CAE1:1;              
    unsigned char _CAE2:1;               
    unsigned char _CAE3:1;              
    unsigned char _CAE4:1;               
    unsigned char _CAE5:1;               
    unsigned char _CAE6:1;               
    unsigned char _CAE7:1;                
  } PWMCAE_BITS;                       
  unsigned char PWMCAE_BYTE;                 
}PWMCAE1 _IO_AT(0xA4);                

/*DEFINE REGISTER*/                          
#define PWMCAE PWMCAE1.PWMCAE_BYTE            

/*DEFINE REGISTER BITS*/                     
#define CAE0 PWMCAE1.PWMCAE_BITS._CAE0       
#define CAE1 PWMCAE1.PWMCAE_BITS._CAE1     
#define CAE2 PWMCAE1.PWMCAE_BITS._CAE2       
#define CAE3 PWMCAE1.PWMCAE_BITS._CAE3     
#define CAE4 PWMCAE1.PWMCAE_BITS._CAE4       
#define CAE5 PWMCAE1.PWMCAE_BITS._CAE5       
#define CAE6 PWMCAE1.PWMCAE_BITS._CAE6       
#define CAE7 PWMCAE1.PWMCAE_BITS._CAE7       

/*******************************************************************************************/
/*                                PWM CONTROL REGISTER                                     */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  union {                            
  struct {                             
    unsigned char BIT0:1;               
    unsigned char BIT1:1;              
    unsigned char _PFRZ:1;               
    unsigned char _PSWAI:1;              
    unsigned char _CON01:1;               
    unsigned char _CON23:1;               
    unsigned char _CON45:1;               
    unsigned char _CON67:1;                
  } PWMCTL_BITS;                       
  unsigned char PWMCTL_BYTE;                 
}PWMCTL1 _IO_AT(0xA5);                

/*DEFINE REGISTER*/                          
#define PWMCTL PWMCTL1.PWMCTL_BYTE            

/*DEFINE REGISTER BITS*/                     
#define PFRZ  PWMCTL1.PWMCTL_BITS._PFRZ       
#define PSWAI PWMCTL1.PWMCTL_BITS._PSWAI     
#define CON01 PWMCTL1.PWMCTL_BITS._CON01       
#define CON23 PWMCTL1.PWMCTL_BITS._CON23     
#define CON45 PWMCTL1.PWMCTL_BITS._CON45       
#define CON67 PWMCTL1.PWMCTL_BITS._CON67       

/*******************************************************************************************/
/*                              PWM SPECIAL MODE REGISTER (TEST)                           */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  unsigned char PWMTST   _IO_AT(0xA6);  /* PWM Test Register */

/*******************************************************************************************/
/*                                 PWM PRESCALE COUNTER                                    */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  unsigned char PWMPRSC   _IO_AT(0xA7);  /* PWM Prescale Counter */

/*******************************************************************************************/
/*                                 PWM SCALE REGISTER A                                    */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  unsigned char PWMSCLA  _IO_AT(0xA8); /* PWM Scale A */
#define PWMSCALA PWMSCLA  /* for legacy reason only, do not use any more! */
/*******************************************************************************************/
/*                                 PWM SCALE REGISTER B                                    */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  unsigned char PWMSCLB  _IO_AT(0xA9); /* PWM Scale B */
#define PWMSCALB PWMSCLB  /* for legacy reason only, do not use any more! */
/*******************************************************************************************/
/*                                 PWM SCALE COUNTER VALUE A                               */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  unsigned char PWMSCNTA  _IO_AT(0xAA); /* PWM Counter A */

/*******************************************************************************************/
/*                                 PWM SCALE COUNTER VALUE B                               */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  unsigned char PWMSCNTB  _IO_AT(0xAB); /* PWM Counter B */

/*******************************************************************************************/
/*                                      PWM CHANNEL COUNTERS                               */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  unsigned char PWMCNT0   _IO_AT(0xAC);  /* PWM Channel Counter 0 */
__DECL__6812DP256_H__ volatile  unsigned char PWMCNT1   _IO_AT(0xAD);  /* PWM Channel Counter 1 */
__DECL__6812DP256_H__ volatile  unsigned char PWMCNT2   _IO_AT(0xAE);  /* PWM Channel Counter 2 */
__DECL__6812DP256_H__ volatile  unsigned char PWMCNT3   _IO_AT(0xAF);  /* PWM Channel Counter 3 */
__DECL__6812DP256_H__ volatile  unsigned char PWMCNT4   _IO_AT(0xB0);  /* PWM Channel Counter 4 */
__DECL__6812DP256_H__ volatile  unsigned char PWMCNT5   _IO_AT(0xB1);  /* PWM Channel Counter 5 */
__DECL__6812DP256_H__ volatile  unsigned char PWMCNT6   _IO_AT(0xB2);  /* PWM Channel Counter 6 */
__DECL__6812DP256_H__ volatile  unsigned char PWMCNT7   _IO_AT(0xB3);  /* PWM Channel Counter 7 */

/*******************************************************************************************/
/*                              PWM CHANNEL PERIOD REGISTERS                               */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  unsigned char PWMPER0   _IO_AT(0xB4);  /* PWM Channel Period 0 */
__DECL__6812DP256_H__ volatile  unsigned char PWMPER1   _IO_AT(0xB5);  /* PWM Channel Period 1 */
__DECL__6812DP256_H__ volatile  unsigned char PWMPER2   _IO_AT(0xB6);  /* PWM Channel Period 2 */
__DECL__6812DP256_H__ volatile  unsigned char PWMPER3   _IO_AT(0xB7);  /* PWM Channel Period 3 */
__DECL__6812DP256_H__ volatile  unsigned char PWMPER4   _IO_AT(0xB8);  /* PWM Channel Period 4 */
__DECL__6812DP256_H__ volatile  unsigned char PWMPER5   _IO_AT(0xB9);  /* PWM Channel Period 5 */
__DECL__6812DP256_H__ volatile  unsigned char PWMPER6   _IO_AT(0xBA);  /* PWM Channel Period 6 */
__DECL__6812DP256_H__ volatile  unsigned char PWMPER7   _IO_AT(0xBB);  /* PWM Channel Period 7 */

/*******************************************************************************************/
/*                                PWM CHANNEL DUTY REGISTERS                               */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  unsigned char PWMDTY0   _IO_AT(0xBC);  /* PWM Channel Duty 0 */
__DECL__6812DP256_H__ volatile  unsigned char PWMDTY1   _IO_AT(0xBD);  /* PWM Channel Duty 1 */
__DECL__6812DP256_H__ volatile  unsigned char PWMDTY2   _IO_AT(0xBE);  /* PWM Channel Duty 2 */
__DECL__6812DP256_H__ volatile  unsigned char PWMDTY3   _IO_AT(0xBF);  /* PWM Channel Duty 3 */
__DECL__6812DP256_H__ volatile  unsigned char PWMDTY4   _IO_AT(0xC0);  /* PWM Channel Duty 4 */
__DECL__6812DP256_H__ volatile  unsigned char PWMDTY5   _IO_AT(0xC1);  /* PWM Channel Duty 5 */
__DECL__6812DP256_H__ volatile  unsigned char PWMDTY6   _IO_AT(0xC2);  /* PWM Channel Duty 6 */
__DECL__6812DP256_H__ volatile  unsigned char PWMDTY7   _IO_AT(0xC3);  /* PWM Channel Duty 7 */

/*******************************************************************************************/
/*                                                                     */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  union {                            
  struct {                             
    unsigned char _PWM7ENA:1;               
    unsigned char _PWM7INL:1;              
    unsigned char _PWN7IN:1;               
    unsigned char BIT3:1;              
    unsigned char _PWMLVL:1;               
    unsigned char _PWMRSTRT:1;               
    unsigned char _PWMIE:1;               
    unsigned char _PWMIF:1;                
  } PWMSDN_BITS;                       
  unsigned char PWMSD_BYTE;                 
}PWMSDN1 _IO_AT(0xC4);                

/*DEFINE REGISTER*/                          
#define PWMSDN PWMSDN1.PWMSD_BYTE            

/*DEFINE REGISTER BITS*/                     
#define PWM7ENA  PWMSDN1.PWMSDN_BITS._PWM7ENA       
#define PWM7INL  PWMSDN1.PWMSDN_BITS._PWM7INL     

#define PWN7IN   PWMSDN1.PWMSDN_BITS._PWN7IN /* do not use this one any more */       
#define PWM7IN   PWMSDN1.PWMSDN_BITS._PWN7IN

#define PWMLVL   PWMSDN1.PWMSDN_BITS._PWMLVL     
#define PWMRSTRT PWMSDN1.PWMSDN_BITS._PWMRSTRT       
#define PWMIE    PWMSDN1.PWMSDN_BITS._PWMIE       
#define PWMIF    PWMSDN1.PWMSDN_BITS._PWMIF       

/*******************************************************************************************/
/*                                SCI PORTS STRUCTURE                                      */
/*******************************************************************************************/
/*****SCI BAUD RATE CONTROL REGISTER HIGH*****/
typedef  union {                            
  struct {                             
    unsigned char _SBR8:1;               
    unsigned char _SBR9:1;              
    unsigned char _SBR10:1;               
    unsigned char _SBR11:1;              
    unsigned char _SBR12:1;               
    unsigned char BIT5:1;               
    unsigned char BIT6:1;               
    unsigned char BIT7:1;                
  } SCIBDH_BITS;                       
  unsigned char SCIBDH_BYTE;                 
} SCIBDH_TYPE;                

/*****SCI BAUD RATE CONTROL REGISTER LOW*****/
typedef  union {                            
  struct {                             
    unsigned char _SBR0:1;               
    unsigned char _SBR1:1;              
    unsigned char _SBR2:1;               
    unsigned char _SBR3:1;              
    unsigned char _SBR4:1;               
    unsigned char _SBR5:1;               
    unsigned char _SBR6:1;               
    unsigned char _SBR7:1;                
  } SCIBDL_BITS;                       
  unsigned char SCIBDL_BYTE;                 
} SCIBDL_TYPE;                

/*****SCI CONTROL REGISTER 1*****/
typedef  union {                            
  struct {                             
    unsigned char _PT:1;               
    unsigned char _PE:1;              
    unsigned char _ILT:1;               
    unsigned char _WAKE:1;              
    unsigned char _M:1;               
    unsigned char _RSRC:1;               
    unsigned char _SCISWAI:1;               
    unsigned char _LOOPS:1;                
  } SCICR1_BITS;                       
  unsigned char SCICR1_BYTE;                 
} SCICR1_TYPE;                

/*****SCI CONTROL REGISTER 2*****/
typedef  union {                            
  struct {                             
    unsigned char _SBK:1;               
    unsigned char _RWU:1;              
    unsigned char _RE:1;               
    unsigned char _TE:1;              
    unsigned char _ILIE:1;               
    unsigned char _RIE:1;               
    unsigned char _TCIE:1;               
    unsigned char _TIE:1;                
  } SCICR2_BITS;                       
  unsigned char SCICR2_BYTE;                 
} SCICR2_TYPE;                

/*****SCI STATUS REGISTER 1*****/
typedef  union {                            
  struct {                             
    unsigned char _PF:1;               
    unsigned char _FE:1;              
    unsigned char _NF:1;               
    unsigned char _OR:1;              
    unsigned char _IDLE:1;               
    unsigned char _RDRF:1;               
    unsigned char _TC:1;               
    unsigned char _TDRE:1;                    
  } SCISR1_BITS;                       
  unsigned char SCISR1_BYTE;                 
} SCISR1_TYPE;                

/*****SCI STATUS REGISTER 2*****/
typedef  union {                            
  struct {                             
    unsigned char _RAF:1;               
    unsigned char BIT1:1;              
    unsigned char BIT2:1;               
    unsigned char BIT3:1;              
    unsigned char BIT4:1;               
    unsigned char BIT5:1;               
    unsigned char BIT6:1;               
    unsigned char BIT7:1;                
  } SCISR2_BITS;                       
  unsigned char SCISR2_BYTE;                 
} SCISR2_TYPE;                


/*****SCI DATA REGISTER  HIGH     *****/
typedef  union {
  struct {                             
    unsigned char BIT0:1;               
    unsigned char BIT1:1;              
    unsigned char BIT2:1;               
    unsigned char BIT3:1;              
    unsigned char BIT4:1;               
    unsigned char BIT5:1;               
    unsigned char _T8:1;               
    unsigned char _R8:1;                    
  } SCIDRH_BITS;                       
  unsigned char SCIDRH_BYTE;                 
} SCIDRH_TYPE;                

/*******************************************************************************************/
/*                            SCI BAUD RATE CONTROL REGISTERS 0                            */
/*******************************************************************************************/

/*****SCI BAUD RATE CONTROL REGISTER 0 HIGH*****/
__DECL__6812DP256_H__ volatile  SCIBDH_TYPE SCI0BDH1 _IO_AT(0xC8);                

/*DEFINE REGISTER*/                          
#define SCI0BDH SCI0BDH1.SCIBDH_BYTE            

/*DEFINE REGISTER BITS*/                     
#define SBR8_0  SCI0BDH1.SCIBDH_BITS._SBR8
#define SBR9_0  SCI0BDH1.SCIBDH_BITS._SBR9     
#define SBR10_0 SCI0BDH1.SCIBDH_BITS._SBR10       
#define SBR11_0 SCI0BDH1.SCIBDH_BITS._SBR11      
#define SBR12_0 SCI0BDH1.SCIBDH_BITS._SBR12      

/*****SCI BAUD RATE CONTROL REGISTER 0 LOW*****/
__DECL__6812DP256_H__ volatile  SCIBDL_TYPE SCI0BDL1 _IO_AT(0xC9);                

/*DEFINE REGISTER*/                          
#define SCI0BDL SCI0BDL1.SCIBDL_BYTE            

/*DEFINE REGISTER BITS*/                     
#define SBR0_0 SCI0BDL1.SCIBDL_BITS._SBR0       
#define SBR1_0 SCI0BDL1.SCIBDL_BITS._SBR1    
#define SBR2_0 SCI0BDL1.SCIBDL_BITS._SBR2       
#define SBR3_0 SCI0BDL1.SCIBDL_BITS._SBR3      
#define SBR4_0 SCI0BDL1.SCIBDL_BITS._SBR4      
#define SBR5_0 SCI0BDL1.SCIBDL_BITS._SBR5    
#define SBR6_0 SCI0BDL1.SCIBDL_BITS._SBR6
#define SBR7_0 SCI0BDL1.SCIBDL_BITS._SBR7

/*******************************************************************************************/
/*                                 SCI 0 CONTROL REGISTERS                                 */
/*******************************************************************************************/

/*****SCI 0 CONTROL REGISTER 1*****/
__DECL__6812DP256_H__ volatile  SCICR1_TYPE SCI0CR11 _IO_AT(0xCA);                

/*DEFINE REGISTER*/                          
#define SCI0CR1 SCI0CR11.SCICR1_BYTE            

/*DEFINE REGISTER BITS*/                     
#define PT_0      SCI0CR11.SCICR1_BITS._PT      
#define PE_0      SCI0CR11.SCICR1_BITS._PE     
#define ILT_0     SCI0CR11.SCICR1_BITS._ILT       
#define WAKE_0    SCI0CR11.SCICR1_BITS._WAKE      
#define M_0       SCI0CR11.SCICR1_BITS._M      
#define RSRC_0    SCI0CR11.SCICR1_BITS._RSRC     
#define SCISWAI_0 SCI0CR11.SCICR1_BITS._SCISWAI
#define LOOPS_0   SCI0CR11.SCICR1_BITS._LOOPS

/*****SCI 0 CONTROL REGISTER 2*****/
__DECL__6812DP256_H__ volatile  SCICR2_TYPE SCI0CR21 _IO_AT(0xCB);                

/*DEFINE REGISTER*/                          
#define SCI0CR2 SCI0CR21.SCICR2_BYTE            

/*DEFINE REGISTER BITS*/                     
#define SBK_0  SCI0CR21.SCICR2_BITS._SBK      
#define RWU_0  SCI0CR21.SCICR2_BITS._RWU     
#define RE_0   SCI0CR21.SCICR2_BITS._RE       
#define TE_0   SCI0CR21.SCICR2_BITS._TE      
#define ILIE_0 SCI0CR21.SCICR2_BITS._ILIE      
#define RIE_0  SCI0CR21.SCICR2_BITS._RIE     
#define TCIE_0 SCI0CR21.SCICR2_BITS._TCIE
#define TIE_0  SCI0CR21.SCICR2_BITS._TIE

/*******************************************************************************************/
/*                                   SCI STATUS REGISTERS 0                                */
/*******************************************************************************************/

/*****SCI 0 STATUS REGISTER 1*****/
__DECL__6812DP256_H__ volatile  SCISR1_TYPE SCI0SR11 _IO_AT(0xCC);                

/*DEFINE REGISTER*/                          
#define SCI0SR1 SCI0SR11.SCISR1_BYTE            

/*DEFINE REGISTER BITS*/                     
#define PF_0   SCI0SR11.SCISR1_BITS._PF      
#define FE_0   SCI0SR11.SCISR1_BITS._FE     
#define NF_0   SCI0SR11.SCISR1_BITS._NF       
#define OR_0   SCI0SR11.SCISR1_BITS._OR      
#define IDLE_0 SCI0SR11.SCISR1_BITS._IDLE      
#define RDRF_0 SCI0SR11.SCISR1_BITS._RDRF     
#define TC_0   SCI0SR11.SCISR1_BITS._TC
#define TDRE_0 SCI0SR11.SCISR1_BITS._TDRE

/*****SCI 0 STATUS REGISTER 2*****/
__DECL__6812DP256_H__ volatile  SCISR2_TYPE SCI0SR21 _IO_AT(0xCD);                

/*DEFINE REGISTER*/                          
#define SCI0SR2 SCI0SR21.SCISR2_BYTE            

/*DEFINE REGISTER BITS*/                     
#define RAF_0 SCI0SR21.SCISR2_BITS._RAF      

/*******************************************************************************************/
/*                                   SCI DATA REGISTERS 0                                  */
/*******************************************************************************************/

/*****SCI DATA REGISTER 0 HIGH*****/
__DECL__6812DP256_H__ volatile  SCIDRH_TYPE SCI0DRH1 _IO_AT(0xCE);                

/*DEFINE REGISTER*/                          
#define SCI0DRH SCI0DRH1.SCIDRH_BYTE            

/*DEFINE REGISTER BITS*/                     
#define T8_0 SCI0DRH1.SCIDRH_BITS._T8
#define R8_0 SCI0DRH1.SCIDRH_BITS._R8


/*****SCI DATA REGISTER 0 LOW*****/
__DECL__6812DP256_H__ volatile  unsigned char SCI0DRL    _IO_AT(0xCF);  

/*******************************************************************************************/
/*                            SCI BAUD RATE CONTROL REGISTERS 1                            */
/*******************************************************************************************/

/*****SCI BAUD RATE CONTROL REGISTER 1 HIGH*****/
__DECL__6812DP256_H__ volatile  SCIBDH_TYPE SCI1BDH1 _IO_AT(0xD0);                

/*DEFINE REGISTER*/                          
#define SCI1BDH SCI1BDH1.SCIBDH_BYTE            

/*DEFINE REGISTER BITS*/                     
#define SBR8_1  SCI1BDH1.SCIBDH_BITS._SBR8
#define SBR9_1  SCI1BDH1.SCIBDH_BITS._SBR9     
#define SBR10_1 SCI1BDH1.SCIBDH_BITS._SBR10       
#define SBR11_1 SCI1BDH1.SCIBDH_BITS._SBR11      
#define SBR12_1 SCI1BDH1.SCIBDH_BITS._SBR12      

/*****SCI BAUD RATE CONTROL REGISTER 1 LOW*****/
__DECL__6812DP256_H__ volatile  SCIBDL_TYPE SCI1BDL1 _IO_AT(0xD1);                

/*DEFINE REGISTER*/                          
#define SCI1BDL SCI1BDL1.SCIBDL_BYTE            

/*DEFINE REGISTER BITS*/                     
#define SBR0_1 SCI1BDL1.SCIBDL_BITS._SBR0       
#define SBR1_1 SCI1BDL1.SCIBDL_BITS._SBR1    
#define SBR2_1 SCI1BDL1.SCIBDL_BITS._SBR2       
#define SBR3_1 SCI1BDL1.SCIBDL_BITS._SBR3      
#define SBR4_1 SCI1BDL1.SCIBDL_BITS._SBR4      
#define SBR5_1 SCI1BDL1.SCIBDL_BITS._SBR5    
#define SBR6_1 SCI1BDL1.SCIBDL_BITS._SBR6
#define SBR7_1 SCI1BDL1.SCIBDL_BITS._SBR7

/*******************************************************************************************/
/*                                 SCI 1 CONTROL REGISTERS                                 */
/*******************************************************************************************/

/*****SCI 1 CONTROL REGISTER 1*****/
__DECL__6812DP256_H__ volatile  SCICR1_TYPE SCI1CR11 _IO_AT(0xD2);                

/*DEFINE REGISTER*/                          
#define SCI1CR1 SCI1CR11.SCICR1_BYTE            

/*DEFINE REGISTER BITS*/                     
#define PT_1      SCI1CR11.SCICR1_BITS._PT      
#define PE_1      SCI1CR11.SCICR1_BITS._PE     
#define ILT_1     SCI1CR11.SCICR1_BITS._ILT       
#define WAKE_1    SCI1CR11.SCICR1_BITS._WAKE      
#define M_1       SCI1CR11.SCICR1_BITS._M      
#define RSRC_1    SCI1CR11.SCICR1_BITS._RSRC     
#define SCISWAI_1 SCI1CR11.SCICR1_BITS._SCISWAI
#define LOOPS_1   SCI1CR11.SCICR1_BITS._LOOPS

/*****SCI 1 CONTROL REGISTER 2*****/
__DECL__6812DP256_H__ volatile  SCICR2_TYPE SCI1CR21 _IO_AT(0xD3);                

/*DEFINE REGISTER*/                          
#define SCI1CR2 SCI1CR21.SCICR2_BYTE            

/*DEFINE REGISTER BITS*/                     
#define SBK_1  SCI1CR21.SCICR2_BITS._SBK      
#define RWU_1  SCI1CR21.SCICR2_BITS._RWU     
#define RE_1   SCI1CR21.SCICR2_BITS._RE       
#define TE_1   SCI1CR21.SCICR2_BITS._TE      
#define ILIE_1 SCI1CR21.SCICR2_BITS._ILIE      
#define RIE_1  SCI1CR21.SCICR2_BITS._RIE     
#define TCIE_1 SCI1CR21.SCICR2_BITS._TCIE
#define TIE_1  SCI1CR21.SCICR2_BITS._TIE

/*******************************************************************************************/
/*                                   SCI STATUS REGISTERS 1                                */
/*******************************************************************************************/

/*****SCI 1 STATUS REGISTER 1*****/
__DECL__6812DP256_H__ volatile  SCISR1_TYPE SCI1SR11 _IO_AT(0xD4);                

/*DEFINE REGISTER*/                          
#define SCI1SR1 SCI1SR11.SCISR1_BYTE            

/*DEFINE REGISTER BITS*/                     
#define PF_1   SCI1SR11.SCISR1_BITS._PF      
#define FE_1   SCI1SR11.SCISR1_BITS._FE     
#define NF_1   SCI1SR11.SCISR1_BITS._NF       
#define OR_1   SCI1SR11.SCISR1_BITS._OR      
#define IDLE_1 SCI1SR11.SCISR1_BITS._IDLE      
#define RDRF_1 SCI1SR11.SCISR1_BITS._RDRF     
#define TC_1   SCI1SR11.SCISR1_BITS._TC
#define TDRE_1 SCI1SR11.SCISR1_BITS._TDRE

/*****SCI 1 STATUS REGISTER 2*****/
__DECL__6812DP256_H__ volatile  SCISR2_TYPE SCI1SR21 _IO_AT(0xD5);                

/*DEFINE REGISTER*/                          
#define SCI1SR2 SCI1SR21.SCISR2_BYTE            

/*DEFINE REGISTER BITS*/                     
#define RAF_1 SCI1SR21.SCISR2_BITS._RAF      

/*******************************************************************************************/
/*                                   SCI DATA REGISTERS 1                                  */
/*******************************************************************************************/

/*****SCI DATA REGISTER 1 HIGH*****/
__DECL__6812DP256_H__ volatile  SCIDRH_TYPE SCI1DRH1 _IO_AT(0xD6);                

/*DEFINE REGISTER*/                          
#define SCI1DRH SCI1DRH1.SCIDRH_BYTE            

/*DEFINE REGISTER BITS*/                     
#define T8_1 SCI1DRH1.SCIDRH_BITS._T8
#define R8_1 SCI1DRH1.SCIDRH_BITS._R8


/*****SCI DATA REGISTER 1 LOW*****/
__DECL__6812DP256_H__ volatile  unsigned char SCI1DRL    _IO_AT(0xD7);  

/*******************************************************************************************/
/*                                 SPI REGISTERS STRUCTURE                                 */
/*******************************************************************************************/

/*****SPI CONTROL REGISTER 1*****/
typedef  union {                            
  struct {                             
    unsigned char _LSBF:1;               
    unsigned char _SSOE:1;              
    unsigned char _CPHA:1;               
    unsigned char _CPOL:1;              
    unsigned char _MSTR:1;               
    unsigned char _SPTIE:1;               
    unsigned char _SPE:1;               
    unsigned char _SPIE:1;                
  } SPICR1_BITS;                       
  unsigned char SPICR1_BYTE;                 
} SPICR1_TYPE;                

/*****SPI 0 CONTROL REGISTER 2*****/
typedef  union {                            
  struct {                             
    unsigned char _SPC0:1;               
    unsigned char _SPISWAI:1;              
    unsigned char BIT2:1;               
    unsigned char _BIDIROE:1;              
    unsigned char _MODFEN:1;               
    unsigned char BIT5:1;               
    unsigned char BIT6:1;               
    unsigned char BIT7:1;                
  } SPICR2_BITS;                       
  unsigned char SPICR2_BYTE;                 
} SPICR2_TYPE;                

/*****SPI BAUD RATE REGISTER *****/
typedef  union {                            
  struct {                             
    unsigned char _SPR0:1;               
    unsigned char _SPR1:1;              
    unsigned char _SPR2:1;               
    unsigned char BIT3:1;              
    unsigned char _SPPR0:1;               
    unsigned char _SPPR1:1;               
    unsigned char _SPPR2:1;               
    unsigned char BIT7:1;                
  } SPIBR_BITS;                       
  unsigned char SPIBR_BYTE;                 
} SPIBR_TYPE;                

/*****SPI STATUS REGISTER *****/
typedef  union {                            
  struct {                             
    unsigned char BIT0:1;               
    unsigned char BIT1:1;              
    unsigned char BIT2:1;               
    unsigned char BIT3:1;              
    unsigned char _MODF:1;               
    unsigned char _SPTEF:1;               
    unsigned char BIT6:1;               
    unsigned char _SPIF:1;                    
  } SPISR_BITS;                       
  unsigned char SPISR_BYTE;                 
} SPISR_TYPE;

/*******************************************************************************************/
/*                                 SPI 0 CONTROL REGISTERS                                 */
/*******************************************************************************************/

/*****SPI CONTROL REGISTER 1*****/
__DECL__6812DP256_H__ volatile  SPICR1_TYPE SPI0CR11 _IO_AT(0xD8);                

/*DEFINE REGISTER*/                          
#define SPI0CR1 SPI0CR11.SPICR1_BYTE            

/*DEFINE REGISTER BITS*/                     
#define LSBF_0  SPI0CR11.SPICR1_BITS._LSBF      
#define SSOE_0  SPI0CR11.SPICR1_BITS._SSOE     
#define CPHA_0  SPI0CR11.SPICR1_BITS._CPHA       
#define CPOL_0  SPI0CR11.SPICR1_BITS._CPOL      
#define MSTR_0  SPI0CR11.SPICR1_BITS._MSTR      
#define SPTIE_0 SPI0CR11.SPICR1_BITS._SPTIE     
#define SPE_0   SPI0CR11.SPICR1_BITS._SPE
#define SPIE_0  SPI0CR11.SPICR1_BITS._SPIE

/*****SPI 0 CONTROL REGISTER 2*****/
__DECL__6812DP256_H__ volatile  SPICR2_TYPE SPI0CR21 _IO_AT(0xD9);                

/*DEFINE REGISTER*/                          
#define SPI0CR2 SPI0CR21.SPICR2_BYTE            

/*DEFINE REGISTER BITS*/                     
#define SPC0_0    SPI0CR21.SPICR2_BITS._SPC0      
#define SPISWAI_0 SPI0CR21.SPICR2_BITS._SPISWAI     
#define BIDIROE_0 SPI0CR21.SPICR2_BITS._BIDIROE     
#define MODFEN_0  SPI0CR21.SPICR2_BITS._MODFEN     

/*******************************************************************************************/
/*                                SPI 0 BAUD RATE REGISTER                                 */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  SPIBR_TYPE SPI0BR1 _IO_AT(0xDA);                

/*DEFINE REGISTER*/                          
#define SPI0BR SPI0BR1.SPIBR_BYTE            

/*DEFINE REGISTER BITS*/                     
#define SPR0_0  SPI0BR1.SPIBR_BITS._SPR0      
#define SPR1_0  SPI0BR1.SPIBR_BITS._SPR1     
#define SPR2_0  SPI0BR1.SPIBR_BITS._SPR2      
#define SPPR0_0 SPI0BR1.SPIBR_BITS._SPPR0      
#define SPPR1_0 SPI0BR1.SPIBR_BITS._SPPR1     
#define SPPR2_0 SPI0BR1.SPIBR_BITS._SPPR2      

/*******************************************************************************************/
/*                                   SPI 0 STATUS REGISTER                                 */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  SPISR_TYPE SPI0SR1 _IO_AT(0xDB);                

/*DEFINE REGISTER*/                          
#define SPI0SR SPI0SR1.SPISR_BYTE            

/*DEFINE REGISTER BITS*/                     
#define MODF_0  SPI0SR1.SPISR_BITS._MODF     
#define SPTEF_0 SPI0SR1.SPISR_BITS._SPTEF
#define SPIF_0  SPI0SR1.SPISR_BITS._SPIF

/*******************************************************************************************/
/*                                  SPI 0 DATA REGISTERS                                   */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  unsigned char SPI0DR    _IO_AT(0xDD);  

/*******************************************************************************************/
/*                                 SPI 1 CONTROL REGISTERS                                 */
/*******************************************************************************************/

/*****SPI CONTROL REGISTER 1*****/
__DECL__6812DP256_H__ volatile  SPICR1_TYPE SPI1CR11 _IO_AT(0xF0);                

/*DEFINE REGISTER*/                          
#define SPI1CR1 SPI1CR11.SPICR1_BYTE            

/*DEFINE REGISTER BITS*/                     
#define LSBF_1  SPI1CR11.SPICR1_BITS._LSBF      
#define SSOE_1  SPI1CR11.SPICR1_BITS._SSOE     
#define CPHA_1  SPI1CR11.SPICR1_BITS._CPHA       
#define CPOL_1  SPI1CR11.SPICR1_BITS._CPOL      
#define MSTR_1  SPI1CR11.SPICR1_BITS._MSTR      
#define SPTIE_1 SPI1CR11.SPICR1_BITS._SPTIE     
#define SPE_1   SPI1CR11.SPICR1_BITS._SPE
#define SPIE_1  SPI1CR11.SPICR1_BITS._SPIE

/*****SPI 1 CONTROL REGISTER 2*****/
__DECL__6812DP256_H__ volatile  SPICR2_TYPE SPI1CR21 _IO_AT(0xF1);                

/*DEFINE REGISTER*/                          
#define SPI1CR2 SPI1CR21.SPICR2_BYTE            

/*DEFINE REGISTER BITS*/                     
#define SPC0_1    SPI1CR21.SPICR2_BITS._SPC0      
#define SPISWAI_1 SPI1CR21.SPICR2_BITS._SPISWAI     
#define BIDIROE_1 SPI1CR21.SPICR2_BITS._BIDIROE     
#define MODFEN_1  SPI1CR21.SPICR2_BITS._MODFEN     

/*******************************************************************************************/
/*                                SPI 1 BAUD RATE REGISTER                                 */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  SPIBR_TYPE SPI1BR1 _IO_AT(0xF2);                

/*DEFINE REGISTER*/                          
#define SPI1BR SPI1BR1.SPIBR_BYTE            

/*DEFINE REGISTER BITS*/                     
#define SPR0_1  SPI1BR1.SPIBR_BITS._SPR0      
#define SPR1_1  SPI1BR1.SPIBR_BITS._SPR1     
#define SPR2_1  SPI1BR1.SPIBR_BITS._SPR2      
#define SPPR0_1 SPI1BR1.SPIBR_BITS._SPPR0      
#define SPPR1_1 SPI1BR1.SPIBR_BITS._SPPR1     
#define SPPR2_1 SPI1BR1.SPIBR_BITS._SPPR2      

/*******************************************************************************************/
/*                                   SPI 1 STATUS REGISTER                                 */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  SPISR_TYPE SPI1SR1 _IO_AT(0xF3);                

/*DEFINE REGISTER*/                          
#define SPI1SR SPI1SR1.SPISR_BYTE            

/*DEFINE REGISTER BITS*/                     
#define MODF_1  SPI1SR1.SPISR_BITS._MODF     
#define SPTEF_1 SPI1SR1.SPISR_BITS._SPTEF
#define SPIF_1  SPI1SR1.SPISR_BITS._SPIF

/*******************************************************************************************/
/*                                  SPI 1 DATA REGISTERS                                   */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  unsigned char SPI1DR    _IO_AT(0xF5);  

/*******************************************************************************************/
/*                                 SPI 2 CONTROL REGISTERS                                 */
/*******************************************************************************************/

/*****SPI CONTROL REGISTER 1*****/
__DECL__6812DP256_H__ volatile  SPICR1_TYPE SPI2CR11 _IO_AT(0xF8);                

/*DEFINE REGISTER*/                          
#define SPI2CR1 SPI2CR11.SPICR1_BYTE            

/*DEFINE REGISTER BITS*/                     
#define LSBF_2  SPI2CR11.SPICR1_BITS._LSBF      
#define SSOE_2  SPI2CR11.SPICR1_BITS._SSOE     
#define CPHA_2  SPI2CR11.SPICR1_BITS._CPHA       
#define CPOL_2  SPI2CR11.SPICR1_BITS._CPOL      
#define MSTR_2  SPI2CR11.SPICR1_BITS._MSTR      
#define SPTIE_2 SPI2CR11.SPICR1_BITS._SPTIE     
#define SPE_2   SPI2CR11.SPICR1_BITS._SPE
#define SPIE_2  SPI2CR11.SPICR1_BITS._SPIE

/*****SPI 2 CONTROL REGISTER 2*****/
__DECL__6812DP256_H__ volatile  SPICR2_TYPE SPI2CR21 _IO_AT(0xF9);                

/*DEFINE REGISTER*/                          
#define SPI2CR2 SPI2CR21.SPICR2_BYTE            

/*DEFINE REGISTER BITS*/                     
#define SPC0_2    SPI2CR21.SPICR2_BITS._SPC0      
#define SPISWAI_2 SPI2CR21.SPICR2_BITS._SPISWAI     
#define BIDIROE_2 SPI2CR21.SPICR2_BITS._BIDIROE     
#define MODFEN_2  SPI2CR21.SPICR2_BITS._MODFEN     

/*******************************************************************************************/
/*                                SPI 2 BAUD RATE REGISTER                                 */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  SPIBR_TYPE SPI2BR1 _IO_AT(0xFA);                

/*DEFINE REGISTER*/                          
#define SPI2BR SPI2BR1.SPIBR_BYTE            

/*DEFINE REGISTER BITS*/                     
#define SPR0_2  SPI2BR1.SPIBR_BITS._SPR0      
#define SPR1_2  SPI2BR1.SPIBR_BITS._SPR1     
#define SPR2_2  SPI2BR1.SPIBR_BITS._SPR2      
#define SPPR0_2 SPI2BR1.SPIBR_BITS._SPPR0      
#define SPPR1_2 SPI2BR1.SPIBR_BITS._SPPR1     
#define SPPR2_2 SPI2BR1.SPIBR_BITS._SPPR2      

/*******************************************************************************************/
/*                                   SPI 2 STATUS REGISTER                                 */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  SPISR_TYPE SPI2SR1 _IO_AT(0xFB);                

/*DEFINE REGISTER*/                          
#define SPI2SR SPI2SR1.SPISR_BYTE            

/*DEFINE REGISTER BITS*/                     
#define MODF_2  SPI2SR1.SPISR_BITS._MODF     
#define SPTEF_2 SPI2SR1.SPISR_BITS._SPTEF
#define SPIF_2  SPI2SR1.SPISR_BITS._SPIF

/*******************************************************************************************/
/*                                  SPI 2 DATA REGISTERS                                   */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  unsigned char SPI2DR    _IO_AT(0xFD);  

/*******************************************************************************************/
/*                                    IIC BUS ADDRESS REGISTER                             */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  unsigned char IBAD    _IO_AT(0xE0);  

/*******************************************************************************************/
/*                          IIC BUS FREQUENCY DIVIDER REGISTER                             */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  union {                            
  struct {                             
    unsigned char _IBC0:1;               
    unsigned char _IBC1:1;              
    unsigned char _IBC2:1;              
    unsigned char _IBC3:1;             
    unsigned char _IBC4:1;               
    unsigned char _IBC5:1;              
    unsigned char _IBC6:1;               
    unsigned char _IBC7:1;                    
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
#define IBC6 IBFD1.IBFD_BITS._IBC6  
#define IBC7 IBFD1.IBFD_BITS._IBC7  

/*******************************************************************************************/
/*                              IIC BUS CONTROL REGISTER                                   */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  union {                            
  struct {                             
    unsigned char _IBSWAI:1;               
    unsigned char BIT1:1;              
    unsigned char _RSTA:1;              
    unsigned char _TXAK:1 ;            
    unsigned char TX_RX_1:1;               
    unsigned char MS_SL_1:1;             
    unsigned char _IBIE:1  ;            
    unsigned char _IBEN:1  ;                
  } IBCR_BITS;                       
  unsigned char IBCR_BYTE;                 
} IBCR1 _IO_AT(0xE2);                

/*DEFINE REGISTER*/                          
#define IBCR IBCR1.IBCR_BYTE            

/*DEFINE REGISTER BITS*/                     
#define IBSWAI IBCR1.IBCR_BITS._IBSWAI     
#define RSTA   IBCR1.IBCR_BITS._RSTA     
#define TXAK   IBCR1.IBCR_BITS._TXAK  
#define TX_RX_ IBCR1.IBCR_BITS.TX_RX_1  
#define MS_SL_ IBCR1.IBCR_BITS.MS_SL_1  
#define IBIE   IBCR1.IBCR_BITS._IBIE  
#define IBEN   IBCR1.IBCR_BITS._IBEN 

/*******************************************************************************************/
/*                              IIC BUS CONTROL REGISTER                                   */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  union {                            
  struct {                             
    unsigned char _RXAK:1;               
    unsigned char _IBIF:1;              
    unsigned char _SRW:1   ;               
    unsigned char _BIT3:1  ;             
    unsigned char _IBAL:1  ;              
    unsigned char _IBB:1   ;           
    unsigned char _IAAS:1  ;             
    unsigned char _TCF:1   ;                 
  } IBSR_BITS;                       
  unsigned char IBSR_BYTE;                 
} IBSR1 _IO_AT(0xE3);                

/*DEFINE REGISTER*/                          
#define IBSR IBSR1.IBSR_BYTE            

/*DEFINE REGISTER BITS*/                     
#define RXAK IBSR1.IBSR_BITS._RXAK     
#define IBIF IBSR1.IBSR_BITS._IBIF   
#define SRW  IBSR1.IBSR_BITS._SRW   
#define IBAL IBSR1.IBSR_BITS._IBAL     
#define IBB  IBSR1.IBSR_BITS._IBB   
#define IAAS IBSR1.IBSR_BITS._IAAS   
#define TCF  IBSR1.IBSR_BITS._TCF   

/**************************************************************************************************/
/*                              IIC BUS DATA I\O REGISTER                                         */
/**************************************************************************************************/    
__DECL__6812DP256_H__ volatile  unsigned char  IICDR    _IO_AT(0xE4);                                             

/*******************************************************************************************/
/*                                                                 */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  union {                            
  struct {                             
    unsigned char _WCM:1;               
    unsigned char _IE:1;              
    unsigned char BIT2:1   ;               
    unsigned char BIT3:1  ;             
    unsigned char BIT4:1  ;              
    unsigned char BIT5:1   ;           
    unsigned char _CLKS:1  ;             
    unsigned char _IMSG:1   ;                 
  } DLCBCR1_BITS;                       
  unsigned char DLCBCR1_BYTE;                 
} DLCBCR11 _IO_AT(0xE8);                

/*DEFINE REGISTER*/                          
#define DLCBCR1 DLCBCR11.DLCBCR1_BYTE            

/*DEFINE REGISTER BITS*/                     
#define WCM  DLCBCR11.DLCBCR1_BITS._WCM     
#define IE   DLCBCR11.DLCBCR1_BITS._IE   
#define CLKS DLCBCR11.DLCBCR1_BITS._CLKS   
#define IMSG DLCBCR11.DLCBCR1_BITS._IMSG     
 
/*******************************************************************************************/
/*                                                                 */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  union {                            
  struct {                             
    unsigned char BIT0:1;               
    unsigned char BIT1:1;              
    unsigned char _I0:1   ;               
    unsigned char _I1:1  ;             
    unsigned char _I2:1  ;              
    unsigned char _I3:1   ;           
    unsigned char BIT6:1  ;             
    unsigned char BIT7:1   ;                 
  } DLCBSVR_BITS;                       
  unsigned char DLCBSVR_BYTE;                 
} DLCBSVR1 _IO_AT(0xE9);                

/*DEFINE REGISTER*/                          
#define DLCBSVR DLCBSVR1.DLCBSVR_BYTE            

/*DEFINE REGISTER BITS*/                     
#define I0 DLCBSVR1.DLCBSVR_BITS._I0     
#define I1 DLCBSVR1.DLCBSVR_BITS._I1   
#define I2 DLCBSVR1.DLCBSVR_BITS._I2   
#define I3 DLCBSVR1.DLCBSVR_BITS._I3     
 
/*******************************************************************************************/
/*                                                                 */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  union {                            
  struct {                             
    unsigned char _TMIFR0:1;               
    unsigned char _TMIFR1:1;              
    unsigned char _TSIFR:1   ;               
    unsigned char _TEOD:1  ;             
    unsigned char _NBFS:1  ;              
    unsigned char _RX4XE:1   ;           
    unsigned char _DLOOP:1  ;             
    unsigned char _SMRST:1   ;                 
  } DLCBCR2_BITS;                       
  unsigned char DLCBCR2_BYTE;                 
} DLCBCR21 _IO_AT(0xEA);                

/*DEFINE REGISTER*/                          
#define DLCBCR2 DLCBCR21.DLCBCR2_BYTE            

/*DEFINE REGISTER BITS*/                     
#define TMIFR0 DLCBCR21.DLCBCR2_BITS._TMIFR0     
#define TMIFR1 DLCBCR21.DLCBCR2_BITS._TMIFR1   
#define TSIFR  DLCBCR21.DLCBCR2_BITS._TSIFR   
#define TEOD   DLCBCR21.DLCBCR2_BITS._TEOD     
#define NBFS   DLCBCR21.DLCBCR2_BITS._NBFS     
#define RX4XE  DLCBCR21.DLCBCR2_BITS._RX4XE   
#define DLOOP  DLCBCR21.DLCBCR2_BITS._DLOOP   
#define SMRST  DLCBCR21.DLCBCR2_BITS._SMRST     
 
/*******************************************************************************************/
/*                                                                     */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  unsigned char DLCBDR    _IO_AT(0xEB);  

/*******************************************************************************************/
/*                                                                 */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  union {                            
  struct {                             
    unsigned char _BO0:1;               
    unsigned char _BO1:1;              
    unsigned char _BO2:1   ;               
    unsigned char _BO3:1  ;             
    unsigned char BIT4:1  ;              
    unsigned char BIT5:1   ;           
    unsigned char _RXPOL:1  ;             
    unsigned char BIT7:1   ;                 
  } DLCBARD_BITS;                       
  unsigned char DLCBARD_BYTE;                 
} DLCBARD1 _IO_AT(0xEC);                

/*DEFINE REGISTER*/                          
#define DLCBARD DLCBARD1.DLCBARD_BYTE            

/*DEFINE REGISTER BITS*/                     
#define BO0   DLCBARD1.DLCBARD_BITS._BO0     
#define BO1   DLCBARD1.DLCBARD_BITS._BO1   
#define BO2   DLCBARD1.DLCBARD_BITS._BO2   
#define BO3   DLCBARD1.DLCBARD_BITS._BO3     
#define RXPOL DLCBARD1.DLCBARD_BITS._RXPOL     
 
/*******************************************************************************************/
/*                                                                 */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  union {                            
  struct {                             
    unsigned char _R0:1;               
    unsigned char _R1:1;              
    unsigned char _R2:1   ;               
    unsigned char _R3:1  ;             
    unsigned char _R4:1  ;              
    unsigned char _R5:1   ;           
    unsigned char BIT6:1  ;             
    unsigned char BIT7:1   ;                 
  } DLCBRSR_BITS;                       
  unsigned char DLCBRSR_BYTE;                 
} DLCBRSR1 _IO_AT(0xED);                

/*DEFINE REGISTER*/                          
#define DLCBRSR DLCBRSR1.DLCBRSR_BYTE            

/*DEFINE REGISTER BITS*/                     
#define R0 DLCBRSR1.DLCBRSR_BITS._R0     
#define R1 DLCBRSR1.DLCBRSR_BITS._R1   
#define R2 DLCBRSR1.DLCBRSR_BITS._R2   
#define R3 DLCBRSR1.DLCBRSR_BITS._R3     
#define R4 DLCBRSR1.DLCBRSR_BITS._R4     
#define R5 DLCBRSR1.DLCBRSR_BITS._R5     

/*******************************************************************************************/
/*                                                                 */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  union {                            
  struct {                             
    unsigned char BIT0:1;               
    unsigned char BIT1:1;              
    unsigned char BIT2:1   ;               
    unsigned char BIT3:1  ;             
    unsigned char _BDLCE:1  ;              
    unsigned char BIT5:1   ;           
    unsigned char BIT6:1  ;             
    unsigned char BIT7:1   ;                 
  } DLCSRC_BITS;                       
  unsigned char DLCSRC_BYTE;                 
} DLCSRC1 _IO_AT(0xEE);                

/*DEFINE REGISTER*/                          
#define DLCSRC DLCSRC1.DLCSRC_BYTE            

/*DEFINE REGISTER BITS*/                     
#define BDLCE DLCSRC1.DLCSRC_BITS._BDLCE     

/*******************************************************************************************/
/*                                                                 */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  union {                            
  struct {                             
    unsigned char _IDLE:1;               
    unsigned char BIT1:1;              
    unsigned char BIT2:1   ;               
    unsigned char BIT3:1  ;             
    unsigned char BIT4:1  ;              
    unsigned char BIT5:1   ;           
    unsigned char BIT6:1  ;             
    unsigned char BIT7:1   ;                 
  } DLCBSTAT_BITS;                       
  unsigned char DLCBSTAT_BYTE;                 
} DLCBSTAT1 _IO_AT(0xEF);                

/*DEFINE REGISTER*/                          
#define DLCBSTAT DLCBSTAT1.DLCBSTAT_BYTE            

/*DEFINE REGISTER BITS*/                     
#define IDLE DLCBSTAT1.DLCBSTAT_BITS._IDLE     

/*******************************************************************************************/
/*                             FLASH CLOCK DIVIDER REGISTER.                               */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  union {                            
  struct {                             
    unsigned char _FDIV0:1;               
    unsigned char _FDIV1:1;              
    unsigned char _FDIV2:1;               
    unsigned char _FDIV3:1;              
    unsigned char _FDIV4:1;               
    unsigned char _FDIV5:1;               
    unsigned char _FDIV8:1;               
    unsigned char _FDIVLD:1;                
  } FCLKDIV_BITS;                       
  unsigned char FCLKDIV_BYTE;                 
} FCLKDIV1 _IO_AT(0x100);                

/*DEFINE REGISTER*/                          
#define FCLKDIV FCLKDIV1.FCLKDIV_BYTE            

/*DEFINE REGISTER BITS*/                     
#define FDIV0  FCLKDIV1.FCLKDIV_BITS._FDIV0      
#define FDIV1  FCLKDIV1.FCLKDIV_BITS._FDIV1      
#define FDIV2  FCLKDIV1.FCLKDIV_BITS._FDIV2      
#define FDIV3  FCLKDIV1.FCLKDIV_BITS._FDIV3      
#define FDIV4  FCLKDIV1.FCLKDIV_BITS._FDIV4      
#define FDIV5  FCLKDIV1.FCLKDIV_BITS._FDIV5      
#define FDIV8  FCLKDIV1.FCLKDIV_BITS._FDIV8      
#define FDIVLD FCLKDIV1.FCLKDIV_BITS._FDIVLD      

/*******************************************************************************************/
/*                               FLASH SECURITY REGISTER.                                  */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  union {                            
  struct {                             
    unsigned char _SEC00:1;               
    unsigned char _SEC01:1;              
    unsigned char _NV2:1;               
    unsigned char _NV3:1;              
    unsigned char _NV4:1;               
    unsigned char _NV5:1;               
    unsigned char _NV6:1;               
    unsigned char _KEYEN:1;                
  } FSEC_BITS;                       
  unsigned char FSEC_BYTE;                 
} FSEC1 _IO_AT(0x101);                

/*DEFINE REGISTER*/                          
#define FSEC FSEC1.FSEC_BYTE            

/*DEFINE REGISTER BITS*/                     
#define SEC00 FSEC1.FSEC_BITS._SEC00      
#define SEC01 FSEC1.FSEC_BITS._SEC01      
#define NV2   FSEC1.FSEC_BITS._NV2      
#define NV3   FSEC1.FSEC_BITS._NV3      
#define NV4   FSEC1.FSEC_BITS._NV4      
#define NV5   FSEC1.FSEC_BITS._NV5      
#define NV6   FSEC1.FSEC_BITS._NV6      
#define KEYEN FSEC1.FSEC_BITS._KEYEN      

/*******************************************************************************************/
/*                             FLASH EEPROM CONFIGURATION REGISTER                         */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  union {                            
  struct {                             
    unsigned char BIT0:1;               
    unsigned char BIT1:1;              
    unsigned char BIT2:1;               
    unsigned char BIT3:1;              
    unsigned char BIT4:1;               
    unsigned char _KEYACC:1;               
    unsigned char _CCIE:1;               
    unsigned char _CBEIE:1;                
  } FCNFG_BITS;                       
  unsigned char FCNFG_BYTE;                 
} FCNFG1 _IO_AT(0x103);                

/*DEFINE REGISTER*/                          
#define FCNFG FCNFG1.FCNFG_BYTE            

/*DEFINE REGISTER BITS*/                     
#define KEYACC FCNFG1.FCNFG_BITS._KEYACC        
#define CCIE   FCNFG1.FCNFG_BITS._CCIE        
#define CBEIE  FCNFG1.FCNFG_BITS._CBEIE        

/*******************************************************************************************/
/*                              FLASH EEPROM PROTECTION REGISTER                           */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  union {                            
  struct {                             
    unsigned char _FPLS0:1;               
    unsigned char _FPLS1:1;              
    unsigned char _FPLDIS:1;               
    unsigned char _FPHS0:1;              
    unsigned char _FPHS1:1;               
    unsigned char _FPHDIS:1;               
    unsigned char BIT6:1;               
    unsigned char _FPOPEN:1;                
  } FPROT_BITS;                       
  unsigned char FPROT_BYTE;                 
} FPROT1 _IO_AT(0x104);                

/*DEFINE REGISTER*/                          
#define FPROT FPROT1.FPROT_BYTE            

/*DEFINE REGISTER BITS*/                     
#define FPLS0  FPROT1.FPROT_BITS._FPLS0     
#define FPLS1  FPROT1.FPROT_BITS._FPLS1     
#define FPLDIS FPROT1.FPROT_BITS._FPLDIS      
#define FPHS0  FPROT1.FPROT_BITS._FPHS0      
#define FPHS1  FPROT1.FPROT_BITS._FPHS1      
#define FPHDIS FPROT1.FPROT_BITS._FPHDIS     
#define FPOPEN FPROT1.FPROT_BITS._FPOPEN

/*******************************************************************************************/
/*                                FLASH EEPROM STATUS REGISTER                             */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  union {                            
  struct {                             
    unsigned char BIT0:1;               
    unsigned char BIT1:1;              
    unsigned char _BLANK:1;               
    unsigned char BIT3:1;              
    unsigned char _ACCERR:1;               
    unsigned char _PVIOL:1;               
    unsigned char _CCIF:1;               
    unsigned char _CBEIF:1;                
  } FSTAT_BITS;                       
  unsigned char FSTAT_BYTE;                 
} FSTAT1 _IO_AT(0x105);                

/*DEFINE REGISTER*/                          
#define FSTAT FSTAT1.FSTAT_BYTE            

/*DEFINE REGISTER BITS*/                     
#define BLANK  FSTAT1.FSTAT_BITS._BLANK     
#define ACCERR FSTAT1.FSTAT_BITS._ACCERR     
#define PVIOL  FSTAT1.FSTAT_BITS._PVIOL      
#define CCIF   FSTAT1.FSTAT_BITS._CCIF      
#define CBEIF  FSTAT1.FSTAT_BITS._CBEIF      

/*******************************************************************************************/
/*                            FLASH EEPROM COMMAND BUFFER REGISTER                         */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  union {                            
  struct {                             
    unsigned char _MASS:1;               
    unsigned char BIT1:1;              
    unsigned char _ERVR:1;               
    unsigned char BIT3:1;              
    unsigned char BIT4:1;               
    unsigned char _PROG:1;               
    unsigned char _ERASE:1;               
    unsigned char BIT7:1;                
  } FCMD_BITS;                       
  unsigned char FCMD_BYTE;                 
} FCMD1 _IO_AT(0x106);                

/*DEFINE REGISTER*/                          
#define FCMD FCMD1.FCMD_BYTE            

/*DEFINE REGISTER BITS*/                     
#define MASS  FCMD1.FCMD_BITS._MASS     
#define ERVR  FCMD1.FCMD_BITS._ERVR     
#define PROG  FCMD1.FCMD_BITS._PROG      
#define ERASE FCMD1.FCMD_BITS._ERASE      

/*******************************************************************************************/
/*                               EEPROM CLOCK DIVIDER                                       */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  union {                            
  struct {                             
    unsigned char _EDIV0:1;               
    unsigned char _EDIV1:1;              
    unsigned char _EDIV2:1;               
    unsigned char _EDIV3:1;              
    unsigned char _EDIV4:1;               
    unsigned char _EDIV5:1;               
    unsigned char _EDIV6:1;               
    unsigned char _EDIVLD:1;                
  } ECLKDIV_BITS;                       
  unsigned char ECLKDIV_BYTE;                 
} ECLKDIV1 _IO_AT(0x110);                

/*DEFINE REGISTER*/                          
#define ECLKDIV ECLKDIV1.ECLKDIV_BYTE            

/*DEFINE REGISTER BITS*/                     
#define EDIV0  ECLKDIV1.ECLKDIV_BITS._EDIV0      
#define EDIV1  ECLKDIV1.ECLKDIV_BITS._EDIV1      
#define EDIV2  ECLKDIV1.ECLKDIV_BITS._EDIV2      
#define EDIV3  ECLKDIV1.ECLKDIV_BITS._EDIV3      
#define EDIV4  ECLKDIV1.ECLKDIV_BITS._EDIV4      
#define EDIV5  ECLKDIV1.ECLKDIV_BITS._EDIV5      
#define EDIV6  ECLKDIV1.ECLKDIV_BITS._EDIV6      
#define EDIVLD ECLKDIV1.ECLKDIV_BITS._EDIVLD     

/*******************************************************************************************/
/*                                      EEPROM CONFIG                                      */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  union {                            
  struct {                             
    unsigned char BIT0:1;               
    unsigned char BIT1:1;              
    unsigned char BIT2:1;               
    unsigned char BIT3:1;              
    unsigned char BIT4:1;               
    unsigned char BIT5:1;               
    unsigned char _CCIE:1;               
    unsigned char _CBEIE:1;                
  } ECNFG_BITS;                       
  unsigned char ECNFG_BYTE;                 
} ECNFG1 _IO_AT(0x113);                

/*DEFINE REGISTER*/                          
#define ECNFG ECNFG1.ECNFG_BYTE            

/*DEFINE REGISTER BITS*/                     
#define E_CCIE  ECNFG1.ECNFG_BITS._CCIE      
#define E_CBEIE ECNFG1.ECNFG_BITS._CBEIE     

/*******************************************************************************************/
/*                                   EEPROM BLOCK PROTECT                                  */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  union {                            
  struct {                             
    unsigned char _EP0:1;               
    unsigned char _EP1:1;              
    unsigned char _EP2:1;               
    unsigned char _EPDIS:1;              
    unsigned char BIT4:1;               
    unsigned char BIT5:1;               
    unsigned char BIT6:1;               
    unsigned char _EPOPEN:1;                
  } EPROT_BITS;                       
  unsigned char EPROT_BYTE;                 
} EPROT1 _IO_AT(0x114);                

/*DEFINE REGISTER*/                          
#define EPROT EPROT1.EPROT_BYTE            

/*DEFINE REGISTER BITS*/                     
#define EP0    EPROT1.EPROT_BITS._EP0      
#define EP1    EPROT1.EPROT_BITS._EP1     
#define EP2    EPROT1.EPROT_BITS._EP2      
#define EPDIS  EPROT1.EPROT_BITS._EPDIS      
#define EPOPEN EPROT1.EPROT_BITS._EPOPEN      

/*******************************************************************************************/
/*                                      EEPROM STATUS                                      */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  union {                            
  struct {                             
    unsigned char BIT0:1;               
    unsigned char BIT1:1;              
    unsigned char _BLANK:1;               
    unsigned char BIT3:1;              
    unsigned char _ACCERR:1;               
    unsigned char _PVIOL:1;               
    unsigned char _CCIF:1;               
    unsigned char _CBEIF:1;                
  } ESTAT_BITS;                       
  unsigned char ESTAT_BYTE;                 
} ESTAT1 _IO_AT(0x115);                

/*DEFINE REGISTER*/                          
#define ESTAT ESTAT1.ESTAT_BYTE            

/*DEFINE REGISTER BITS*/                     
#define E_BLANK  ESTAT1.ESTAT_BITS._BLANK     
#define E_ACCERR ESTAT1.ESTAT_BITS._ACCERR      
#define E_PVIOL  ESTAT1.ESTAT_BITS._PVIOL      
#define E_CCIF   ESTAT1.ESTAT_BITS._CCIF     
#define E_CBEIF  ESTAT1.ESTAT_BITS._CBEIF

/*******************************************************************************************/
/*                                       EEPROM COMMAND                                    */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  union {                            
  struct {                             
    unsigned char _MASS:1;               
    unsigned char BIT1:1;              
    unsigned char _ERVR:1;               
    unsigned char BIT3:1;              
    unsigned char BIT4:1;               
    unsigned char _PROG:1;               
    unsigned char _ERASE:1;               
    unsigned char BIT7:1;                
  } ECMD_BITS;                       
  unsigned char ECMD_BYTE;                 
} ECMD1 _IO_AT(0x116);                

/*DEFINE REGISTER*/                          
#define ECMD ECMD1.ECMD_BYTE            

/*DEFINE REGISTER BITS*/                     
#define E_MASS  ECMD1.ECMD_BITS._MASS       
#define E_ERVR  ECMD1.ECMD_BITS._ERVR     
#define E_PROG  ECMD1.ECMD_BITS._PROG      
#define E_ERASE ECMD1.ECMD_BITS._ERASE      

/*******************************************************************************************/
/*                                MSCAN12 REGISTER STRUCTURE                               */
/*******************************************************************************************/

/**********MSCAN12 MODULE CONTROL REGISTER 0********/
typedef  union {                            
  struct {                             
    unsigned char _INITRQ:1;               
    unsigned char _SLPRQ:1;              
    unsigned char _WUPE:1;               
    unsigned char _TIME:1;              
    unsigned char _SYNCH:1;               
    unsigned char _CSWAI:1;               
    unsigned char _RXACT:1;               
    unsigned char _RXFRM:1;                
  } CANCTL0_BITS;                       
  unsigned char CANCTL0_BYTE;                 
} CANCTL0_TYPE;               

/**********MSCAN12 MODULE CONTROL REGISTER 1********/
typedef  union {                            
  struct {                             
    unsigned char _INITAK:1;               
    unsigned char _SPLACK:1;              
    unsigned char _WUPM:1;               
    unsigned char BIT3:1;              
    unsigned char _LISTEN:1;               
    unsigned char _LOOPB:1;               
    unsigned char _CLKSRC:1;               
    unsigned char _CANE:1;                
  } CANCTL1_BITS;                       
  unsigned char CANCTL1_BYTE;                 
} CANCTL1_TYPE;               

/**********MSCAN12 BUS TIMING REGISTER 0********/
typedef  union {                            
  struct {                             
    unsigned char _BRP0:1;               
    unsigned char _BRP1:1;              
    unsigned char _BRP2:1;               
    unsigned char _BRP3:1;              
    unsigned char _BRP4:1;               
    unsigned char _BRP5:1;               
    unsigned char _SJW0:1;               
    unsigned char _SJW1:1;                
  } CANBTR0_BITS;                       
  unsigned char CANCBTR0_BYTE;                 
} CANBTR0_TYPE;               

/**********MSCAN12 BUS TIMING REGISTER 1 ********/
typedef  union {                            
  struct {                             
    unsigned char _TSEG10:1;               
    unsigned char _TSEG11:1;              
    unsigned char _TSEG12:1;               
    unsigned char _TSEG13:1;              
    unsigned char _TSEG20:1;               
    unsigned char _TSEG21:1;               
    unsigned char _TSEG22:1;               
    unsigned char _SAMP:1;                
  } CANBTR1_BITS;                       
  unsigned char CANBTR1_BYTE;                 
} CANBTR1_TYPE;               

/**********MSCAN12 RECEIVER FLAG REGISTER ********/
typedef  union {                            
  struct {                             
    unsigned char _RFX:1;               
    unsigned char _OVRIF:1;              
    unsigned char _TSTAT0:1;               
    unsigned char _TSTAT1:1;              
    unsigned char _RSTAT0:1;               
    unsigned char _RSTAT1:1;               
    unsigned char _CSCIF:1;               
    unsigned char _WUPIF:1;                
  } CANRFLG_BITS;                       
  unsigned char CANRFLG_BYTE;                 
} CANRFLG_TYPE;               

/**********MSCAN12 RECEIVER INTERRUPT ENABLE REGISTER ********/
typedef  union {                            
  struct {                             
    unsigned char _RFXIE:1;               
    unsigned char _OVRIE:1;              
    unsigned char _TSTATE0:1;               
    unsigned char _TSTATE1:1;              
    unsigned char _RSTATE0:1;               
    unsigned char _RSTATE1:1;               
    unsigned char _CSCIE:1;               
    unsigned char _WUPIE:1;                
  } CANRIER_BITS;                       
  unsigned char CANRIER_BYTE;                 
} CANRIER_TYPE;               

/**********MSCAN12 TRANSMITTER FLAG REGISTER ********/
typedef  union {                            
  struct {                             
    unsigned char _TXE0:1;               
    unsigned char _TXE1:1;              
    unsigned char _TXE2:1;               
    unsigned char BIT3:1;              
    unsigned char BIT4:1;               
    unsigned char BIT5:1;               
    unsigned char BIT6:1;               
    unsigned char BIT7:1;                
  } CANTFLG_BITS;                       
  unsigned char CANTFLG_BYTE;                 
} CANTFLG_TYPE;               

/**********MSCAN12 TRANSMITTER CONTROL REGISTER ********/
typedef  union {                            
  struct {                             
    unsigned char _TXEIE0:1;               
    unsigned char _TXEIE1:1;              
    unsigned char _TXEIE2:1;               
    unsigned char BIT3:1;              
    unsigned char BIT4:1;               
    unsigned char BIT5:1;               
    unsigned char BIT6:1;               
    unsigned char BIT7:1;                
  } CANTIER_BITS;                       
  unsigned char CANTIER_BYTE;                 
} CANTIER_TYPE;               

/**********MSCAN12 IDENTIFIER ACCEPTANCE CONTROL REGISTER ********/
typedef  union {                            
  struct {                             
    unsigned char _ABTRQ0:1;               
    unsigned char _ABTRQ1:1;              
    unsigned char _ABTRQ2:1;               
    unsigned char BIT3:1;              
    unsigned char BIT4:1;               
    unsigned char BIT5:1;               
    unsigned char BIT6:1;               
    unsigned char BIT7:1;                
  } CANTARQ_BITS;                       
  unsigned char CANTARQ_BYTE;                 
} CANTARQ_TYPE;               

/**********    ********/
typedef  union {                            
  struct {                             
    unsigned char _ABTAK0:1;               
    unsigned char _ABTAK1:1;              
    unsigned char _ABTAK2:1;               
    unsigned char BIT3:1;              
    unsigned char BIT4:1;               
    unsigned char BIT5:1;               
    unsigned char BIT6:1;               
    unsigned char BIT7:1;                
  } CANTAAK_BITS;                       
  unsigned char CANTAAK_BYTE;                 
} CANTAAK_TYPE;               

/**********    ********/
typedef  union {                            
  struct {                             
    unsigned char _TX0:1;               
    unsigned char _TX1:1;              
    unsigned char _TX2:1;               
    unsigned char BIT3:1;              
    unsigned char BIT4:1;               
    unsigned char BIT5:1;               
    unsigned char BIT6:1;               
    unsigned char BIT7:1;                
  } CANTBSEL_BITS;                       
  unsigned char CANTBSEL_BYTE;                 
} CANTBSEL_TYPE;               

/**********    ********/
typedef union {
  struct {                             
    unsigned char _IDHI0:1;               
    unsigned char _IDHI1:1;              
    unsigned char _IDJIT2:1;               
    unsigned char BIT3:1;              
    unsigned char _IDAM0:1;               
    unsigned char _IDAM1:1;               
    unsigned char BIT6:1;               
    unsigned char BIT7:1;                
  } CANIDAC_BITS;                       
  unsigned char CANIDAC_BYTE;                 
} CANIDAC_TYPE;  
             
/*******************************************************************************************/
/*                             MSCAN12 MODULE CONTROL REGISTER 0                           */                                
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  CANCTL0_TYPE CAN0CTL01 _IO_AT(0x140);               

/*DEFINE REGISTER*/                          
#define CAN0CTL0 CAN0CTL01.CANCTL0_BYTE            

/*DEFINE REGISTER BITS*/                     
#define INITRQ_0 CAN0CTL01.CANCTL0_BITS._INITRQ       
#define SLPRQ_0  CAN0CTL01.CANCTL0_BITS._SLPRQ
#define WUPE_0   CAN0CTL01.CANCTL0_BITS._WUPE 
#define TIME_0   CAN0CTL01.CANCTL0_BITS._TIME       
#define SYNCH_0  CAN0CTL01.CANCTL0_BITS._SYNCH 
#define CSWAI_0  CAN0CTL01.CANCTL0_BITS._CSWAI 
#define RXACT_0  CAN0CTL01.CANCTL0_BITS._RXACT 
#define RXFRM_0  CAN0CTL01.CANCTL0_BITS._RXFRM 

/*******************************************************************************************/
/*                             MSCAN12 MODULE CONTROL REGISTER 1                           */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  CANCTL1_TYPE CAN0CTL11 _IO_AT(0x141);               

/*DEFINE REGISTER*/                          
#define CAN0CTL1 CAN0CTL11.CANCTL1_BYTE            

/*DEFINE REGISTER BITS*/                     
#define INITAK_0 CAN0CTL11.CANCTL1_BITS._INITAK      
#define SPLACK_0 CAN0CTL11.CANCTL1_BITS._SPLACK      
#define WUPM_0   CAN0CTL11.CANCTL1_BITS._WUPM
#define LISTEN_0 CAN0CTL11.CANCTL1_BITS._LISTEN      
#define LOOPB_0  CAN0CTL11.CANCTL1_BITS._LOOPB
#define CLKSRC_0 CAN0CTL11.CANCTL1_BITS._CLKSRC      
#define CANE_0   CAN0CTL11.CANCTL1_BITS._CANE      

/*******************************************************************************************/
/*                               MSCAN12 BUS TIMING REGISTER 0                             */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  CANBTR0_TYPE CAN0BTR01 _IO_AT(0x142);               

/*DEFINE REGISTER*/                          
#define CAN0BTR0 CAN0BTR01.CANCBTR0_BYTE            

/*DEFINE REGISTER BITS*/                     
#define BRP0_0 CAN0BTR01.CANBTR0_BITS._BRP0      
#define BRP1_0 CAN0BTR01.CANBTR0_BITS._BRP1      
#define BRP2_0 CAN0BTR01.CANBTR0_BITS._BRP2      
#define BRP3_0 CAN0BTR01.CANBTR0_BITS._BRP3      
#define BRP4_0 CAN0BTR01.CANBTR0_BITS._BRP4      
#define BRP5_0 CAN0BTR01.CANBTR0_BITS._BRP5      
#define SJW0_0 CAN0BTR01.CANBTR0_BITS._SJW0      
#define SJW1_0 CAN0BTR01.CANBTR0_BITS._SJW1

/*******************************************************************************************/
/*                               MSCAN12 BUS TIMING REGISTER 1                             */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  CANBTR1_TYPE CAN0BTR11 _IO_AT(0x143);               

/*DEFINE REGISTER*/                          
#define CAN0BTR1 CAN0BTR11.CANBTR1_BYTE            

/*DEFINE REGISTER BITS*/                     
#define TSEG10_0 CAN0BTR11.CANBTR1_BITS._TSEG10    
#define TSEG11_0 CAN0BTR11.CANBTR1_BITS._TSEG11    
#define TSEG12_0 CAN0BTR11.CANBTR1_BITS._TSEG12    
#define TSEG13_0 CAN0BTR11.CANBTR1_BITS._TSEG13    
#define TSEG20_0 CAN0BTR11.CANBTR1_BITS._TSEG20    
#define TSEG21_0 CAN0BTR11.CANBTR1_BITS._TSEG21    
#define TSEG22_0 CAN0BTR11.CANBTR1_BITS._TSEG22    
#define SAMP_0   CAN0BTR11.CANBTR1_BITS._SAMP

/*******************************************************************************************/
/*                               MSCAN12 RECEIVER FLAG REGISTER                            */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  CANRFLG_TYPE CAN0RFLG1 _IO_AT(0x144);               

/*DEFINE REGISTER*/                          
#define CAN0RFLG CAN0RFLG1.CANRFLG_BYTE            

/*DEFINE REGISTER BITS*/                     
#define RFX_0    CAN0RFLG1.CANRFLG_BITS._RFX
#define OVRIF_0  CAN0RFLG1.CANRFLG_BITS._OVRIF  
#define TSTAT0_0 CAN0RFLG1.CANRFLG_BITS._TSTAT0   
#define TSTAT1_0 CAN0RFLG1.CANRFLG_BITS._TSTAT1     
#define RSTAT0_0 CAN0RFLG1.CANRFLG_BITS._RSTAT0     
#define RSTAT1_0 CAN0RFLG1.CANRFLG_BITS._RSTAT1 
#define CSCIF_0  CAN0RFLG1.CANRFLG_BITS._CSCIF 
#define WUPIF_0  CAN0RFLG1.CANRFLG_BITS._WUPIF

/*******************************************************************************************/
/*                      MSCAN12 RECEIVER INTERRUPT ENABLE REGISTER                         */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  CANRIER_TYPE CAN0RIER1 _IO_AT(0x145);               

/*DEFINE REGISTER*/                          
#define CAN0RIER CAN0RIER1.CANRIER_BYTE            

/*DEFINE REGISTER BITS*/                     
#define RFXIE_0   CAN0RIER1.CANRIER_BITS._RFXIE
#define OVRIE_0   CAN0RIER1.CANRIER_BITS._OVRIE  
#define TSTATE0_0 CAN0RIER1.CANRIER_BITS._TSTATE0   
#define TSTATE1_0 CAN0RIER1.CANRIER_BITS._TSTATE1     
#define RSTATE0_0 CAN0RIER1.CANRIER_BITS._RSTATE0     
#define RSTATE1_0 CAN0RIER1.CANRIER_BITS._RSTATE1 
#define CSCIE_0   CAN0RIER1.CANRIER_BITS._CSCIE 
#define WUPIE_0   CAN0RIER1.CANRIER_BITS._WUPIE

/*******************************************************************************************/
/*                          MSCAN12 TRANSMITTER FLAG REGISTER                              */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  CANTFLG_TYPE CAN0TFLG1 _IO_AT(0x146);               

/*DEFINE REGISTER*/                          
#define CAN0TFLG CAN0TFLG1.CANTFLG_BYTE            

/*DEFINE REGISTER BITS*/                     
#define TXE0_0 CAN0TFLG1.CANTFLG_BITS._TXE0
#define TXE1_0 CAN0TFLG1.CANTFLG_BITS._TXE1
#define TXE2_0 CAN0TFLG1.CANTFLG_BITS._TXE2

/*******************************************************************************************/
/*                          MSCAN12 TRANSMITTER CONTROL REGISTER                           */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  CANTIER_TYPE CAN0TIER1 _IO_AT(0x147);               

/*DEFINE REGISTER*/                          
#define CAN0TIER CAN0TIER1.CANTIER_BYTE            

/*DEFINE REGISTER BITS*/                     
#define TXEIE0_0 CAN0TIER1.CANTIER_BITS._TXEIE0
#define TXEIE1_0 CAN0TIER1.CANTIER_BITS._TXEIE1
#define TXEIE2_0 CAN0TIER1.CANTIER_BITS._TXEIE2

/*******************************************************************************************/
/*                          MSCAN12 IDENTIFIER ACCEPTANCE CONTROL REGISTER                 */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  CANTARQ_TYPE CAN0TARQ1 _IO_AT(0x148);               

/*DEFINE REGISTER*/                          
#define CAN0TARQ CAN0TARQ1.CANTARQ_BYTE            

/*DEFINE REGISTER BITS*/                     
#define ABTRQ0_0 CAN0TARQ1.CANTARQ_BITS._ABTRQ0
#define ABTRQ1_0 CAN0TARQ1.CANTARQ_BITS._ABTRQ1
#define ABTRQ2_0 CAN0TARQ1.CANTARQ_BITS._ABTRQ2

/*******************************************************************************************/
/*                                           */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  CANTAAK_TYPE CAN0TAAK1 _IO_AT(0x149);               

/*DEFINE REGISTER*/                          
#define CAN0TAAK CAN0TAAK1.CANTAAK_BYTE            

/*DEFINE REGISTER BITS*/                     
#define ABTAK0_0 CAN0TAAK1.CANTAAK_BITS._ABTAK0
#define ABTAK1_0 CAN0TAAK1.CANTAAK_BITS._ABTAK1
#define ABTAK2_0 CAN0TAAK1.CANTAAK_BITS._ABTAK2

/*******************************************************************************************/
/*                                           */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  CANTBSEL_TYPE CAN0TBSEL1 _IO_AT(0x14A);               

/*DEFINE REGISTER*/                          
#define CAN0TBSEL CAN0TBSEL1.CANTBSEL_BYTE            

/*DEFINE REGISTER BITS*/                     
#define TX0_0 CAN0TBSEL1.CANTBSEL_BITS._TX0
#define TX1_0 CAN0TBSEL1.CANTBSEL_BITS._TX1
#define TX2_0 CAN0TBSEL1.CANTBSEL_BITS._TX2

/*******************************************************************************************/
/*                                           */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  CANIDAC_TYPE CAN0IDAC1 _IO_AT(0x14B);               

/*DEFINE REGISTER*/                          
#define CAN0IDAC CAN0IDAC1.CANIDAC_BYTE            

/*DEFINE REGISTER BITS*/                     
#define IDHI0_0  CAN0IDAC1.CANIDAC_BITS._IDHI0
#define IDHI1_0  CAN0IDAC1.CANIDAC_BITS._IDHI1
#define IDJIT2_0 CAN0IDAC1.CANIDAC_BITS._IDJIT2
#define IDAM0_0  CAN0IDAC1.CANIDAC_BITS._IDAM0
#define IDAM1_0  CAN0IDAC1.CANIDAC_BITS._IDAM1

/**************************************************************************************************/
/*                                      MSCAN12 RECEIVE ERROR COUNTER                             */
/**************************************************************************************************/
__DECL__6812DP256_H__ volatile  unsigned char  CAN0RXERR    _IO_AT(0x14E); 

/**************************************************************************************************/
/*                                     MSCAN12 TRANSMIT ERROR COUNTER                             */
/**************************************************************************************************/
__DECL__6812DP256_H__ volatile  unsigned char  CAN0TXERR    _IO_AT(0x14F); 

/**************************************************************************************************/
/*                            IDENTIFIER ACCEPTANCE REGISTERS (First bank)                        */
/**************************************************************************************************/
__DECL__6812DP256_H__ volatile  unsigned char  CAN0IDAR0    _IO_AT(0x150); 
__DECL__6812DP256_H__ volatile  unsigned char  CAN0IDAR1    _IO_AT(0x151); 
__DECL__6812DP256_H__ volatile  unsigned char  CAN0IDAR2    _IO_AT(0x152); 
__DECL__6812DP256_H__ volatile  unsigned char  CAN0IDAR3    _IO_AT(0x153); 

/**************************************************************************************************/
/*                                  IDENTIFIER MASK REGISTERS (First bank)                        */
/**************************************************************************************************/
__DECL__6812DP256_H__ volatile  unsigned char  CAN0IDMR0    _IO_AT(0x154); 
__DECL__6812DP256_H__ volatile  unsigned char  CAN0IDMR1    _IO_AT(0x155); 
__DECL__6812DP256_H__ volatile  unsigned char  CAN0IDMR2    _IO_AT(0x156); 
__DECL__6812DP256_H__ volatile  unsigned char  CAN0IDMR3    _IO_AT(0x157); 

/**************************************************************************************************/
/*                            IDENTIFIER ACCEPTANCE REGISTERS (Second bank)                       */
/**************************************************************************************************/
__DECL__6812DP256_H__ volatile  unsigned char  CAN0IDAR4    _IO_AT(0x158); 
__DECL__6812DP256_H__ volatile  unsigned char  CAN0IDAR5    _IO_AT(0x159); 
__DECL__6812DP256_H__ volatile  unsigned char  CAN0IDAR6    _IO_AT(0x15A); 
__DECL__6812DP256_H__ volatile  unsigned char  CAN0IDAR7    _IO_AT(0x15B); 

/**************************************************************************************************/
/*                                  IDENTIFIER MASK REGISTERS (Second bank)                       */
/**************************************************************************************************/
__DECL__6812DP256_H__ volatile  unsigned char  CAN0IDMR4    _IO_AT(0x15C); 
__DECL__6812DP256_H__ volatile  unsigned char  CAN0IDMR5    _IO_AT(0x15D); 
__DECL__6812DP256_H__ volatile  unsigned char  CAN0IDMR6    _IO_AT(0x15E); 
__DECL__6812DP256_H__ volatile  unsigned char  CAN0IDMR7    _IO_AT(0x15F); 

/**************************************************************************************************/
/*                                  FOREGROUND RECEIVE BUFFER                                     */
/**************************************************************************************************/
__DECL__6812DP256_H__ volatile  unsigned char  CAN0RXFG[16]    _IO_AT(0x160); 

/**************************************************************************************************/
/*                                  FOREGROUND TRANSMIT BUFFER                                    */
/**************************************************************************************************/
__DECL__6812DP256_H__ volatile  unsigned char  CAN0TXFG[16]    _IO_AT(0x170); 

/*******************************************************************************************/
/*                             MSCAN12 MODULE CONTROL REGISTER 0                           */                                
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  CANCTL0_TYPE CAN1CTL01 _IO_AT(0x180);               

/*DEFINE REGISTER*/                          
#define CAN1CTL0 CAN1CTL01.CANCTL0_BYTE            

/*DEFINE REGISTER BITS*/                     
#define INITRQ_1 CAN1CTL01.CANCTL0_BITS._INITRQ       
#define SLPRQ_1  CAN1CTL01.CANCTL0_BITS._SLPRQ
#define WUPE_1   CAN1CTL01.CANCTL0_BITS._WUPE 
#define TIME_1   CAN1CTL01.CANCTL0_BITS._TIME       
#define SYNCH_1  CAN1CTL01.CANCTL0_BITS._SYNCH 
#define CSWAI_1  CAN1CTL01.CANCTL0_BITS._CSWAI 
#define RXACT_1  CAN1CTL01.CANCTL0_BITS._RXACT 
#define RXFRM_1  CAN1CTL01.CANCTL0_BITS._RXFRM 

/*******************************************************************************************/
/*                             MSCAN12 MODULE CONTROL REGISTER 1                           */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  CANCTL1_TYPE CAN1CTL11 _IO_AT(0x181);               

/*DEFINE REGISTER*/                          
#define CAN1CTL1 CAN1CTL11.CANCTL1_BYTE            

/*DEFINE REGISTER BITS*/                     
#define INITAK_1 CAN1CTL11.CANCTL1_BITS._INITAK      
#define SPLACK_1 CAN1CTL11.CANCTL1_BITS._SPLACK      
#define WUPM_1   CAN1CTL11.CANCTL1_BITS._WUPM
#define LISTEN_1 CAN1CTL11.CANCTL1_BITS._LISTEN      
#define LOOPB_1  CAN1CTL11.CANCTL1_BITS._LOOPB
#define CLKSRC_1 CAN1CTL11.CANCTL1_BITS._CLKSRC      
#define CANE_1   CAN1CTL11.CANCTL1_BITS._CANE      

/*******************************************************************************************/
/*                               MSCAN12 BUS TIMING REGISTER 0                             */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  CANBTR0_TYPE CAN1BTR01 _IO_AT(0x182);               

/*DEFINE REGISTER*/                          
#define CAN1BTR0 CAN1BTR01.CANCBTR0_BYTE            

/*DEFINE REGISTER BITS*/                     
#define BRP0_1 CAN1BTR01.CANBTR0_BITS._BRP0      
#define BRP1_1 CAN1BTR01.CANBTR0_BITS._BRP1      
#define BRP2_1 CAN1BTR01.CANBTR0_BITS._BRP2      
#define BRP3_1 CAN1BTR01.CANBTR0_BITS._BRP3      
#define BRP4_1 CAN1BTR01.CANBTR0_BITS._BRP4      
#define BRP5_1 CAN1BTR01.CANBTR0_BITS._BRP5      
#define SJW0_1 CAN1BTR01.CANBTR0_BITS._SJW0      
#define SJW1_1 CAN1BTR01.CANBTR0_BITS._SJW1

/*******************************************************************************************/
/*                               MSCAN12 BUS TIMING REGISTER 1                             */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  CANBTR1_TYPE CAN1BTR11 _IO_AT(0x183);               

/*DEFINE REGISTER*/                          
#define CAN1BTR1 CAN1BTR11.CANBTR1_BYTE            

/*DEFINE REGISTER BITS*/                     
#define TSEG10_1 CAN1BTR11.CANBTR1_BITS._TSEG10    
#define TSEG11_1 CAN1BTR11.CANBTR1_BITS._TSEG11    
#define TSEG12_1 CAN1BTR11.CANBTR1_BITS._TSEG12    
#define TSEG13_1 CAN1BTR11.CANBTR1_BITS._TSEG13    
#define TSEG20_1 CAN1BTR11.CANBTR1_BITS._TSEG20    
#define TSEG21_1 CAN1BTR11.CANBTR1_BITS._TSEG21    
#define TSEG22_1 CAN1BTR11.CANBTR1_BITS._TSEG22    
#define SAMP_1   CAN1BTR11.CANBTR1_BITS._SAMP

/*******************************************************************************************/
/*                               MSCAN12 RECEIVER FLAG REGISTER                            */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  CANRFLG_TYPE CAN1RFLG1 _IO_AT(0x184);               

/*DEFINE REGISTER*/                          
#define CAN1RFLG CAN1RFLG1.CANRFLG_BYTE            

/*DEFINE REGISTER BITS*/                     
#define RFX_1    CAN1RFLG1.CANRFLG_BITS._RFX
#define OVRIF_1  CAN1RFLG1.CANRFLG_BITS._OVRIF  
#define TSTAT0_1 CAN1RFLG1.CANRFLG_BITS._TSTAT0   
#define TSTAT1_1 CAN1RFLG1.CANRFLG_BITS._TSTAT1     
#define RSTAT0_1 CAN1RFLG1.CANRFLG_BITS._RSTAT0     
#define RSTAT1_1 CAN1RFLG1.CANRFLG_BITS._RSTAT1 
#define CSCIF_1  CAN1RFLG1.CANRFLG_BITS._CSCIF 
#define WUPIF_1  CAN1RFLG1.CANRFLG_BITS._WUPIF

/*******************************************************************************************/
/*                      MSCAN12 RECEIVER INTERRUPT ENABLE REGISTER                         */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  CANRIER_TYPE CAN1RIER1 _IO_AT(0x185);               

/*DEFINE REGISTER*/                          
#define CAN1RIER CAN1RIER1.CANRIER_BYTE            

/*DEFINE REGISTER BITS*/                     
#define RFXIE_1   CAN1RIER1.CANRIER_BITS._RFXIE
#define OVRIE_1   CAN1RIER1.CANRIER_BITS._OVRIE  
#define TSTATE0_1 CAN1RIER1.CANRIER_BITS._TSTATE0   
#define TSTATE1_1 CAN1RIER1.CANRIER_BITS._TSTATE1     
#define RSTATE0_1 CAN1RIER1.CANRIER_BITS._RSTATE0     
#define RSTATE1_1 CAN1RIER1.CANRIER_BITS._RSTATE1 
#define CSCIE_1   CAN1RIER1.CANRIER_BITS._CSCIE 
#define WUPIE_1   CAN1RIER1.CANRIER_BITS._WUPIE

/*******************************************************************************************/
/*                          MSCAN12 TRANSMITTER FLAG REGISTER                              */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  CANTFLG_TYPE CAN1TFLG1 _IO_AT(0x186);               

/*DEFINE REGISTER*/                          
#define CAN1TFLG CAN1TFLG1.CANTFLG_BYTE            

/*DEFINE REGISTER BITS*/                     
#define TXE0_1 CAN1TFLG1.CANTFLG_BITS._TXE0
#define TXE1_1 CAN1TFLG1.CANTFLG_BITS._TXE1
#define TXE2_1 CAN1TFLG1.CANTFLG_BITS._TXE2

/*******************************************************************************************/
/*                          MSCAN12 TRANSMITTER CONTROL REGISTER                           */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  CANTIER_TYPE CAN1TIER1 _IO_AT(0x187);               

/*DEFINE REGISTER*/                          
#define CAN1TIER CAN1TIER1.CANTIER_BYTE            

/*DEFINE REGISTER BITS*/                     
#define TXEIE0_1 CAN1TIER1.CANTIER_BITS._TXEIE0
#define TXEIE1_1 CAN1TIER1.CANTIER_BITS._TXEIE1
#define TXEIE2_1 CAN1TIER1.CANTIER_BITS._TXEIE2

/*******************************************************************************************/
/*                          MSCAN12 IDENTIFIER ACCEPTANCE CONTROL REGISTER                 */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  CANTARQ_TYPE CAN1TARQ1 _IO_AT(0x188);               

/*DEFINE REGISTER*/                          
#define CAN1TARQ CAN1TARQ1.CANTARQ_BYTE            

/*DEFINE REGISTER BITS*/                     
#define ABTRQ0_1 CAN1TARQ1.CANTARQ_BITS._ABTRQ0
#define ABTRQ1_1 CAN1TARQ1.CANTARQ_BITS._ABTRQ1
#define ABTRQ2_1 CAN1TARQ1.CANTARQ_BITS._ABTRQ2

/*******************************************************************************************/
/*                                           */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  CANTAAK_TYPE CAN1TAAK1 _IO_AT(0x189);               

/*DEFINE REGISTER*/                          
#define CAN1TAAK CAN1TAAK1.CANTAAK_BYTE            

/*DEFINE REGISTER BITS*/                     
#define ABTAK0_1 CAN1TAAK1.CANTAAK_BITS._ABTAK0
#define ABTAK1_1 CAN1TAAK1.CANTAAK_BITS._ABTAK1
#define ABTAK2_1 CAN1TAAK1.CANTAAK_BITS._ABTAK2

/*******************************************************************************************/
/*                                           */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  CANTBSEL_TYPE CAN1TBSEL1 _IO_AT(0x18A);               

/*DEFINE REGISTER*/                          
#define CAN1TBSEL CAN1TBSEL1.CANTBSEL_BYTE            

/*DEFINE REGISTER BITS*/                     
#define TX0_1 CAN1TBSEL1.CANTBSEL_BITS._TX0
#define TX1_1 CAN1TBSEL1.CANTBSEL_BITS._TX1
#define TX2_1 CAN1TBSEL1.CANTBSEL_BITS._TX2

/*******************************************************************************************/
/*                                           */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  CANIDAC_TYPE CAN1IDAC1 _IO_AT(0x18B);               

/*DEFINE REGISTER*/                          
#define CAN1IDAC CAN1IDAC1.CANIDAC_BYTE            

/*DEFINE REGISTER BITS*/                     
#define IDHI0_1  CAN1IDAC1.CANIDAC_BITS._IDHI0
#define IDHI1_1  CAN1IDAC1.CANIDAC_BITS._IDHI1
#define IDJIT2_1 CAN1IDAC1.CANIDAC_BITS._IDJIT2
#define IDAM0_1  CAN1IDAC1.CANIDAC_BITS._IDAM0
#define IDAM1_1  CAN1IDAC1.CANIDAC_BITS._IDAM1

/**************************************************************************************************/
/*                                      MSCAN12 RECEIVE ERROR COUNTER                             */
/**************************************************************************************************/
__DECL__6812DP256_H__ volatile  unsigned char  CAN1RXERR    _IO_AT(0x18E); 

/**************************************************************************************************/
/*                                     MSCAN12 TRANSMIT ERROR COUNTER                             */
/**************************************************************************************************/
__DECL__6812DP256_H__ volatile  unsigned char  CAN1TXERR    _IO_AT(0x18F); 

/**************************************************************************************************/
/*                            IDENTIFIER ACCEPTANCE REGISTERS (First bank)                        */
/**************************************************************************************************/
__DECL__6812DP256_H__ volatile  unsigned char  CAN1IDAR0    _IO_AT(0x190); 
__DECL__6812DP256_H__ volatile  unsigned char  CAN1IDAR1    _IO_AT(0x191); 
__DECL__6812DP256_H__ volatile  unsigned char  CAN1IDAR2    _IO_AT(0x192); 
__DECL__6812DP256_H__ volatile  unsigned char  CAN1IDAR3    _IO_AT(0x193); 

/**************************************************************************************************/
/*                                  IDENTIFIER MASK REGISTERS (First bank)                        */
/**************************************************************************************************/
__DECL__6812DP256_H__ volatile  unsigned char  CAN1IDMR0    _IO_AT(0x194); 
__DECL__6812DP256_H__ volatile  unsigned char  CAN1IDMR1    _IO_AT(0x195); 
__DECL__6812DP256_H__ volatile  unsigned char  CAN1IDMR2    _IO_AT(0x196); 
__DECL__6812DP256_H__ volatile  unsigned char  CAN1IDMR3    _IO_AT(0x197); 

/**************************************************************************************************/
/*                            IDENTIFIER ACCEPTANCE REGISTERS (Second bank)                       */
/**************************************************************************************************/
__DECL__6812DP256_H__ volatile  unsigned char  CAN1IDAR4    _IO_AT(0x198); 
__DECL__6812DP256_H__ volatile  unsigned char  CAN1IDAR5    _IO_AT(0x199); 
__DECL__6812DP256_H__ volatile  unsigned char  CAN1IDAR6    _IO_AT(0x19A); 
__DECL__6812DP256_H__ volatile  unsigned char  CAN1IDAR7    _IO_AT(0x19B); 

/**************************************************************************************************/
/*                                  IDENTIFIER MASK REGISTERS (Second bank)                       */
/**************************************************************************************************/
__DECL__6812DP256_H__ volatile  unsigned char  CAN1IDMR4    _IO_AT(0x19C); 
__DECL__6812DP256_H__ volatile  unsigned char  CAN1IDMR5    _IO_AT(0x19D); 
__DECL__6812DP256_H__ volatile  unsigned char  CAN1IDMR6    _IO_AT(0x19E); 
__DECL__6812DP256_H__ volatile  unsigned char  CAN1IDMR7    _IO_AT(0x19F); 

/**************************************************************************************************/
/*                                  FOREGROUND RECEIVE BUFFER                                     */
/**************************************************************************************************/
__DECL__6812DP256_H__ volatile  unsigned char  CAN1RXFG[16]    _IO_AT(0x1A0); 

/**************************************************************************************************/
/*                                  FOREGROUND TRANSMIT BUFFER                                    */
/**************************************************************************************************/
__DECL__6812DP256_H__ volatile  unsigned char  CAN1TXFG[16]    _IO_AT(0x1B0); 

/*******************************************************************************************/
/*                             MSCAN12 MODULE CONTROL REGISTER 0                           */                                
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  CANCTL0_TYPE CAN2CTL01 _IO_AT(0x1C0);               

/*DEFINE REGISTER*/                          
#define CAN2CTL0 CAN2CTL01.CANCTL0_BYTE            

/*DEFINE REGISTER BITS*/                     
#define INITRQ_2 CAN2CTL01.CANCTL0_BITS._INITRQ       
#define SLPRQ_2  CAN2CTL01.CANCTL0_BITS._SLPRQ
#define WUPE_2   CAN2CTL01.CANCTL0_BITS._WUPE 
#define TIME_2   CAN2CTL01.CANCTL0_BITS._TIME       
#define SYNCH_2  CAN2CTL01.CANCTL0_BITS._SYNCH 
#define CSWAI_2  CAN2CTL01.CANCTL0_BITS._CSWAI 
#define RXACT_2  CAN2CTL01.CANCTL0_BITS._RXACT 
#define RXFRM_2  CAN2CTL01.CANCTL0_BITS._RXFRM 

/*******************************************************************************************/
/*                             MSCAN12 MODULE CONTROL REGISTER 1                           */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  CANCTL1_TYPE CAN2CTL11 _IO_AT(0x1C1);               

/*DEFINE REGISTER*/                          
#define CAN2CTL1 CAN2CTL11.CANCTL1_BYTE            

/*DEFINE REGISTER BITS*/                     
#define INITAK_2 CAN2CTL11.CANCTL1_BITS._INITAK      
#define SPLACK_2 CAN2CTL11.CANCTL1_BITS._SPLACK      
#define WUPM_2   CAN2CTL11.CANCTL1_BITS._WUPM
#define LISTEN_2 CAN2CTL11.CANCTL1_BITS._LISTEN      
#define LOOPB_2  CAN2CTL11.CANCTL1_BITS._LOOPB
#define CLKSRC_2 CAN2CTL11.CANCTL1_BITS._CLKSRC      
#define CANE_2   CAN2CTL11.CANCTL1_BITS._CANE      

/*******************************************************************************************/
/*                               MSCAN12 BUS TIMING REGISTER 0                             */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  CANBTR0_TYPE CAN2BTR01 _IO_AT(0x1C2);               

/*DEFINE REGISTER*/                          
#define CAN2BTR0 CAN2BTR01.CANCBTR0_BYTE            

/*DEFINE REGISTER BITS*/                     
#define BRP0_2 CAN2BTR01.CANBTR0_BITS._BRP0      
#define BRP1_2 CAN2BTR01.CANBTR0_BITS._BRP1      
#define BRP2_2 CAN2BTR01.CANBTR0_BITS._BRP2      
#define BRP3_2 CAN2BTR01.CANBTR0_BITS._BRP3      
#define BRP4_2 CAN2BTR01.CANBTR0_BITS._BRP4      
#define BRP5_2 CAN2BTR01.CANBTR0_BITS._BRP5      
#define SJW0_2 CAN2BTR01.CANBTR0_BITS._SJW0      
#define SJW1_2 CAN2BTR01.CANBTR0_BITS._SJW1

/*******************************************************************************************/
/*                               MSCAN12 BUS TIMING REGISTER 1                             */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  CANBTR1_TYPE CAN2BTR11 _IO_AT(0x1C3);               

/*DEFINE REGISTER*/                          
#define CAN2BTR1 CAN2BTR11.CANBTR1_BYTE            

/*DEFINE REGISTER BITS*/                     
#define TSEG10_2 CAN2BTR11.CANBTR1_BITS._TSEG10    
#define TSEG11_2 CAN2BTR11.CANBTR1_BITS._TSEG11    
#define TSEG12_2 CAN2BTR11.CANBTR1_BITS._TSEG12    
#define TSEG13_2 CAN2BTR11.CANBTR1_BITS._TSEG13    
#define TSEG20_2 CAN2BTR11.CANBTR1_BITS._TSEG20    
#define TSEG21_2 CAN2BTR11.CANBTR1_BITS._TSEG21    
#define TSEG22_2 CAN2BTR11.CANBTR1_BITS._TSEG22    
#define SAMP_2   CAN2BTR11.CANBTR1_BITS._SAMP

/*******************************************************************************************/
/*                               MSCAN12 RECEIVER FLAG REGISTER                            */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  CANRFLG_TYPE CAN2RFLG1 _IO_AT(0x1C4);               

/*DEFINE REGISTER*/                          
#define CAN2RFLG CAN2RFLG1.CANRFLG_BYTE            

/*DEFINE REGISTER BITS*/                     
#define RFX_2    CAN2RFLG1.CANRFLG_BITS._RFX
#define OVRIF_2  CAN2RFLG1.CANRFLG_BITS._OVRIF  
#define TSTAT0_2 CAN2RFLG1.CANRFLG_BITS._TSTAT0   
#define TSTAT1_2 CAN2RFLG1.CANRFLG_BITS._TSTAT1     
#define RSTAT0_2 CAN2RFLG1.CANRFLG_BITS._RSTAT0     
#define RSTAT1_2 CAN2RFLG1.CANRFLG_BITS._RSTAT1 
#define CSCIF_2  CAN2RFLG1.CANRFLG_BITS._CSCIF 
#define WUPIF_2  CAN2RFLG1.CANRFLG_BITS._WUPIF

/*******************************************************************************************/
/*                      MSCAN12 RECEIVER INTERRUPT ENABLE REGISTER                         */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  CANRIER_TYPE CAN2RIER1 _IO_AT(0x1C5);               

/*DEFINE REGISTER*/                          
#define CAN2RIER CAN2RIER1.CANRIER_BYTE            

/*DEFINE REGISTER BITS*/                     
#define RFXIE_2   CAN2RIER1.CANRIER_BITS._RFXIE
#define OVRIE_2   CAN2RIER1.CANRIER_BITS._OVRIE  
#define TSTATE0_2 CAN2RIER1.CANRIER_BITS._TSTATE0   
#define TSTATE1_2 CAN2RIER1.CANRIER_BITS._TSTATE1     
#define RSTATE0_2 CAN2RIER1.CANRIER_BITS._RSTATE0     
#define RSTATE1_2 CAN2RIER1.CANRIER_BITS._RSTATE1 
#define CSCIE_2   CAN2RIER1.CANRIER_BITS._CSCIE 
#define WUPIE_2   CAN2RIER1.CANRIER_BITS._WUPIE

/*******************************************************************************************/
/*                          MSCAN12 TRANSMITTER FLAG REGISTER                              */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  CANTFLG_TYPE CAN2TFLG1 _IO_AT(0x1C6);               

/*DEFINE REGISTER*/                          
#define CAN2TFLG CAN2TFLG1.CANTFLG_BYTE            

/*DEFINE REGISTER BITS*/                     
#define TXE0_2 CAN2TFLG1.CANTFLG_BITS._TXE0
#define TXE1_2 CAN2TFLG1.CANTFLG_BITS._TXE1
#define TXE2_2 CAN2TFLG1.CANTFLG_BITS._TXE2

/*******************************************************************************************/
/*                          MSCAN12 TRANSMITTER CONTROL REGISTER                           */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  CANTIER_TYPE CAN2TIER1 _IO_AT(0x1C7);               

/*DEFINE REGISTER*/                          
#define CAN2TIER CAN2TIER1.CANTIER_BYTE            

/*DEFINE REGISTER BITS*/                     
#define TXEIE0_2 CAN2TIER1.CANTIER_BITS._TXEIE0
#define TXEIE1_2 CAN2TIER1.CANTIER_BITS._TXEIE1
#define TXEIE2_2 CAN2TIER1.CANTIER_BITS._TXEIE2

/*******************************************************************************************/
/*                          MSCAN12 IDENTIFIER ACCEPTANCE CONTROL REGISTER                 */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  CANTARQ_TYPE CAN2TARQ1 _IO_AT(0x1C8);               

/*DEFINE REGISTER*/                          
#define CAN2TARQ CAN2TARQ1.CANTARQ_BYTE            

/*DEFINE REGISTER BITS*/                     
#define ABTRQ0_2 CAN2TARQ1.CANTARQ_BITS._ABTRQ0
#define ABTRQ1_2 CAN2TARQ1.CANTARQ_BITS._ABTRQ1
#define ABTRQ2_2 CAN2TARQ1.CANTARQ_BITS._ABTRQ2

/*******************************************************************************************/
/*                                           */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  CANTAAK_TYPE CAN2TAAK1 _IO_AT(0x1C9);               

/*DEFINE REGISTER*/                          
#define CAN2TAAK CAN2TAAK1.CANTAAK_BYTE            

/*DEFINE REGISTER BITS*/                     
#define ABTAK0_2 CAN2TAAK1.CANTAAK_BITS._ABTAK0
#define ABTAK1_2 CAN2TAAK1.CANTAAK_BITS._ABTAK1
#define ABTAK2_2 CAN2TAAK1.CANTAAK_BITS._ABTAK2

/*******************************************************************************************/
/*                                           */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  CANTBSEL_TYPE CAN2TBSEL1 _IO_AT(0x1CA);               

/*DEFINE REGISTER*/                          
#define CAN2TBSEL CAN2TBSEL1.CANTBSEL_BYTE            

/*DEFINE REGISTER BITS*/                     
#define TX0_2 CAN2TBSEL1.CANTBSEL_BITS._TX0
#define TX1_2 CAN2TBSEL1.CANTBSEL_BITS._TX1
#define TX2_2 CAN2TBSEL1.CANTBSEL_BITS._TX2

/*******************************************************************************************/
/*                                           */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  CANIDAC_TYPE CAN2IDAC1 _IO_AT(0x1CB);               

/*DEFINE REGISTER*/                          
#define CAN2IDAC CAN2IDAC1.CANIDAC_BYTE            

/*DEFINE REGISTER BITS*/                     
#define IDHI0_2  CAN2IDAC1.CANIDAC_BITS._IDHI0
#define IDHI1_2  CAN2IDAC1.CANIDAC_BITS._IDHI1
#define IDJIT2_2 CAN2IDAC1.CANIDAC_BITS._IDJIT2
#define IDAM0_2  CAN2IDAC1.CANIDAC_BITS._IDAM0
#define IDAM1_2  CAN2IDAC1.CANIDAC_BITS._IDAM1

/**************************************************************************************************/
/*                                      MSCAN12 RECEIVE ERROR COUNTER                             */
/**************************************************************************************************/
__DECL__6812DP256_H__ volatile  unsigned char  CAN2RXERR    _IO_AT(0x1CE); 

/**************************************************************************************************/
/*                                     MSCAN12 TRANSMIT ERROR COUNTER                             */
/**************************************************************************************************/
__DECL__6812DP256_H__ volatile  unsigned char  CAN2TXERR    _IO_AT(0x1CF); 

/**************************************************************************************************/
/*                            IDENTIFIER ACCEPTANCE REGISTERS (First bank)                        */
/**************************************************************************************************/
__DECL__6812DP256_H__ volatile  unsigned char  CAN2IDAR0    _IO_AT(0x1D0); 
__DECL__6812DP256_H__ volatile  unsigned char  CAN2IDAR1    _IO_AT(0x1D1); 
__DECL__6812DP256_H__ volatile  unsigned char  CAN2IDAR2    _IO_AT(0x1D2); 
__DECL__6812DP256_H__ volatile  unsigned char  CAN2IDAR3    _IO_AT(0x1D3); 

/**************************************************************************************************/
/*                                  IDENTIFIER MASK REGISTERS (First bank)                        */
/**************************************************************************************************/
__DECL__6812DP256_H__ volatile  unsigned char  CAN2IDMR0    _IO_AT(0x1D4); 
__DECL__6812DP256_H__ volatile  unsigned char  CAN2IDMR1    _IO_AT(0x1D5); 
__DECL__6812DP256_H__ volatile  unsigned char  CAN2IDMR2    _IO_AT(0x1D6); 
__DECL__6812DP256_H__ volatile  unsigned char  CAN2IDMR3    _IO_AT(0x1D7); 

/**************************************************************************************************/
/*                            IDENTIFIER ACCEPTANCE REGISTERS (Second bank)                       */
/**************************************************************************************************/
__DECL__6812DP256_H__ volatile  unsigned char  CAN2IDAR4    _IO_AT(0x1D8); 
__DECL__6812DP256_H__ volatile  unsigned char  CAN2IDAR5    _IO_AT(0x1D9); 
__DECL__6812DP256_H__ volatile  unsigned char  CAN2IDAR6    _IO_AT(0x1DA); 
__DECL__6812DP256_H__ volatile  unsigned char  CAN2IDAR7    _IO_AT(0x1DB); 

/**************************************************************************************************/
/*                                  IDENTIFIER MASK REGISTERS (Second bank)                       */
/**************************************************************************************************/
__DECL__6812DP256_H__ volatile  unsigned char  CAN2IDMR4    _IO_AT(0x1DC); 
__DECL__6812DP256_H__ volatile  unsigned char  CAN2IDMR5    _IO_AT(0x1DD); 
__DECL__6812DP256_H__ volatile  unsigned char  CAN2IDMR6    _IO_AT(0x1DE); 
__DECL__6812DP256_H__ volatile  unsigned char  CAN2IDMR7    _IO_AT(0x1DF); 

/**************************************************************************************************/
/*                                  FOREGROUND RECEIVE BUFFER                                     */
/**************************************************************************************************/
__DECL__6812DP256_H__ volatile  unsigned char  CAN2RXFG[16]    _IO_AT(0x1E0); 

/**************************************************************************************************/
/*                                  FOREGROUND TRANSMIT BUFFER                                    */
/**************************************************************************************************/
__DECL__6812DP256_H__ volatile  unsigned char  CAN2TXFG[16]    _IO_AT(0x1F0); 

/*******************************************************************************************/
/*                             MSCAN12 MODULE CONTROL REGISTER 0                           */                                
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  CANCTL0_TYPE CAN3CTL01 _IO_AT(0x200);               

/*DEFINE REGISTER*/                          
#define CAN3CTL0 CAN3CTL01.CANCTL0_BYTE            

/*DEFINE REGISTER BITS*/                     
#define INITRQ_3 CAN3CTL01.CANCTL0_BITS._INITRQ       
#define SLPRQ_3  CAN3CTL01.CANCTL0_BITS._SLPRQ
#define WUPE_3   CAN3CTL01.CANCTL0_BITS._WUPE 
#define TIME_3   CAN3CTL01.CANCTL0_BITS._TIME       
#define SYNCH_3  CAN3CTL01.CANCTL0_BITS._SYNCH 
#define CSWAI_3  CAN3CTL01.CANCTL0_BITS._CSWAI 
#define RXACT_3  CAN3CTL01.CANCTL0_BITS._RXACT 
#define RXFRM_3  CAN3CTL01.CANCTL0_BITS._RXFRM 

/*******************************************************************************************/
/*                             MSCAN12 MODULE CONTROL REGISTER 1                           */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  CANCTL1_TYPE CAN3CTL11 _IO_AT(0x201);               

/*DEFINE REGISTER*/                          
#define CAN3CTL1 CAN3CTL11.CANCTL1_BYTE            

/*DEFINE REGISTER BITS*/                     
#define INITAK_3 CAN3CTL11.CANCTL1_BITS._INITAK      
#define SPLACK_3 CAN3CTL11.CANCTL1_BITS._SPLACK      
#define WUPM_3   CAN3CTL11.CANCTL1_BITS._WUPM
#define LISTEN_3 CAN3CTL11.CANCTL1_BITS._LISTEN      
#define LOOPB_3  CAN3CTL11.CANCTL1_BITS._LOOPB
#define CLKSRC_3 CAN3CTL11.CANCTL1_BITS._CLKSRC      
#define CANE_3   CAN3CTL11.CANCTL1_BITS._CANE      

/*******************************************************************************************/
/*                               MSCAN12 BUS TIMING REGISTER 0                             */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  CANBTR0_TYPE CAN3BTR01 _IO_AT(0x202);               

/*DEFINE REGISTER*/                          
#define CAN3BTR0 CAN3BTR01.CANCBTR0_BYTE            

/*DEFINE REGISTER BITS*/                     
#define BRP0_3 CAN3BTR01.CANBTR0_BITS._BRP0      
#define BRP1_3 CAN3BTR01.CANBTR0_BITS._BRP1      
#define BRP2_3 CAN3BTR01.CANBTR0_BITS._BRP2      
#define BRP3_3 CAN3BTR01.CANBTR0_BITS._BRP3      
#define BRP4_3 CAN3BTR01.CANBTR0_BITS._BRP4      
#define BRP5_3 CAN3BTR01.CANBTR0_BITS._BRP5      
#define SJW0_3 CAN3BTR01.CANBTR0_BITS._SJW0      
#define SJW1_3 CAN3BTR01.CANBTR0_BITS._SJW1

/*******************************************************************************************/
/*                               MSCAN12 BUS TIMING REGISTER 1                             */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  CANBTR1_TYPE CAN3BTR11 _IO_AT(0x203);               

/*DEFINE REGISTER*/                          
#define CAN3BTR1 CAN3BTR11.CANBTR1_BYTE            

/*DEFINE REGISTER BITS*/                     
#define TSEG10_3 CAN3BTR11.CANBTR1_BITS._TSEG10    
#define TSEG11_3 CAN3BTR11.CANBTR1_BITS._TSEG11    
#define TSEG12_3 CAN3BTR11.CANBTR1_BITS._TSEG12    
#define TSEG13_3 CAN3BTR11.CANBTR1_BITS._TSEG13    
#define TSEG20_3 CAN3BTR11.CANBTR1_BITS._TSEG20    
#define TSEG21_3 CAN3BTR11.CANBTR1_BITS._TSEG21    
#define TSEG22_3 CAN3BTR11.CANBTR1_BITS._TSEG22    
#define SAMP_3   CAN3BTR11.CANBTR1_BITS._SAMP

/*******************************************************************************************/
/*                               MSCAN12 RECEIVER FLAG REGISTER                            */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  CANRFLG_TYPE CAN3RFLG1 _IO_AT(0x204);               

/*DEFINE REGISTER*/                          
#define CAN3RFLG CAN3RFLG1.CANRFLG_BYTE            

/*DEFINE REGISTER BITS*/                     
#define RFX_3    CAN3RFLG1.CANRFLG_BITS._RFX
#define OVRIF_3  CAN3RFLG1.CANRFLG_BITS._OVRIF  
#define TSTAT0_3 CAN3RFLG1.CANRFLG_BITS._TSTAT0   
#define TSTAT1_3 CAN3RFLG1.CANRFLG_BITS._TSTAT1     
#define RSTAT0_3 CAN3RFLG1.CANRFLG_BITS._RSTAT0     
#define RSTAT1_3 CAN3RFLG1.CANRFLG_BITS._RSTAT1 
#define CSCIF_3  CAN3RFLG1.CANRFLG_BITS._CSCIF 
#define WUPIF_3  CAN3RFLG1.CANRFLG_BITS._WUPIF

/*******************************************************************************************/
/*                      MSCAN12 RECEIVER INTERRUPT ENABLE REGISTER                         */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  CANRIER_TYPE CAN3RIER1 _IO_AT(0x205);               

/*DEFINE REGISTER*/                          
#define CAN3RIER CAN3RIER1.CANRIER_BYTE            

/*DEFINE REGISTER BITS*/                     
#define RFXIE_3   CAN3RIER1.CANRIER_BITS._RFXIE
#define OVRIE_3   CAN3RIER1.CANRIER_BITS._OVRIE  
#define TSTATE0_3 CAN3RIER1.CANRIER_BITS._TSTATE0   
#define TSTATE1_3 CAN3RIER1.CANRIER_BITS._TSTATE1     
#define RSTATE0_3 CAN3RIER1.CANRIER_BITS._RSTATE0     
#define RSTATE1_3 CAN3RIER1.CANRIER_BITS._RSTATE1 
#define CSCIE_3   CAN3RIER1.CANRIER_BITS._CSCIE 
#define WUPIE_3   CAN3RIER1.CANRIER_BITS._WUPIE

/*******************************************************************************************/
/*                          MSCAN12 TRANSMITTER FLAG REGISTER                              */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  CANTFLG_TYPE CAN3TFLG1 _IO_AT(0x206);               

/*DEFINE REGISTER*/                          
#define CAN3TFLG CAN3TFLG1.CANTFLG_BYTE            

/*DEFINE REGISTER BITS*/                     
#define TXE0_3 CAN3TFLG1.CANTFLG_BITS._TXE0
#define TXE1_3 CAN3TFLG1.CANTFLG_BITS._TXE1
#define TXE2_3 CAN3TFLG1.CANTFLG_BITS._TXE2

/*******************************************************************************************/
/*                          MSCAN12 TRANSMITTER CONTROL REGISTER                           */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  CANTIER_TYPE CAN3TIER1 _IO_AT(0x207);               

/*DEFINE REGISTER*/                          
#define CAN3TIER CAN3TIER1.CANTIER_BYTE            

/*DEFINE REGISTER BITS*/                     
#define TXEIE0_3 CAN3TIER1.CANTIER_BITS._TXEIE0
#define TXEIE1_3 CAN3TIER1.CANTIER_BITS._TXEIE1
#define TXEIE2_3 CAN3TIER1.CANTIER_BITS._TXEIE2

/*******************************************************************************************/
/*                          MSCAN12 IDENTIFIER ACCEPTANCE CONTROL REGISTER                 */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  CANTARQ_TYPE CAN3TARQ1 _IO_AT(0x208);               

/*DEFINE REGISTER*/                          
#define CAN3TARQ CAN3TARQ1.CANTARQ_BYTE            

/*DEFINE REGISTER BITS*/                     
#define ABTRQ0_3 CAN3TARQ1.CANTARQ_BITS._ABTRQ0
#define ABTRQ1_3 CAN3TARQ1.CANTARQ_BITS._ABTRQ1
#define ABTRQ2_3 CAN3TARQ1.CANTARQ_BITS._ABTRQ2

/*******************************************************************************************/
/*                                           */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  CANTAAK_TYPE CAN3TAAK1 _IO_AT(0x209);               

/*DEFINE REGISTER*/                          
#define CAN3TAAK CAN3TAAK1.CANTAAK_BYTE            

/*DEFINE REGISTER BITS*/                     
#define ABTAK0_3 CAN3TAAK1.CANTAAK_BITS._ABTAK0
#define ABTAK1_3 CAN3TAAK1.CANTAAK_BITS._ABTAK1
#define ABTAK2_3 CAN3TAAK1.CANTAAK_BITS._ABTAK2

/*******************************************************************************************/
/*                                           */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  CANTBSEL_TYPE CAN3TBSEL1 _IO_AT(0x20A);               

/*DEFINE REGISTER*/                          
#define CAN3TBSEL CAN3TBSEL1.CANTBSEL_BYTE            

/*DEFINE REGISTER BITS*/                     
#define TX0_3 CAN3TBSEL1.CANTBSEL_BITS._TX0
#define TX1_3 CAN3TBSEL1.CANTBSEL_BITS._TX1
#define TX2_3 CAN3TBSEL1.CANTBSEL_BITS._TX2

/*******************************************************************************************/
/*                                           */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  CANIDAC_TYPE CAN3IDAC1 _IO_AT(0x20B);               

/*DEFINE REGISTER*/                          
#define CAN3IDAC CAN3IDAC1.CANIDAC_BYTE            

/*DEFINE REGISTER BITS*/                     
#define IDHI0_3  CAN3IDAC1.CANIDAC_BITS._IDHI0
#define IDHI1_3  CAN3IDAC1.CANIDAC_BITS._IDHI1
#define IDJIT2_3 CAN3IDAC1.CANIDAC_BITS._IDJIT2
#define IDAM0_3  CAN3IDAC1.CANIDAC_BITS._IDAM0
#define IDAM1_3  CAN3IDAC1.CANIDAC_BITS._IDAM1

/**************************************************************************************************/
/*                                      MSCAN12 RECEIVE ERROR COUNTER                             */
/**************************************************************************************************/
__DECL__6812DP256_H__ volatile  unsigned char  CAN3RXERR    _IO_AT(0x20E); 

/**************************************************************************************************/
/*                                     MSCAN12 TRANSMIT ERROR COUNTER                             */
/**************************************************************************************************/
__DECL__6812DP256_H__ volatile  unsigned char  CAN3TXERR    _IO_AT(0x20F); 

/**************************************************************************************************/
/*                            IDENTIFIER ACCEPTANCE REGISTERS (First bank)                        */
/**************************************************************************************************/
__DECL__6812DP256_H__ volatile  unsigned char  CAN3IDAR0    _IO_AT(0x210); 
__DECL__6812DP256_H__ volatile  unsigned char  CAN3IDAR1    _IO_AT(0x211); 
__DECL__6812DP256_H__ volatile  unsigned char  CAN3IDAR2    _IO_AT(0x212); 
__DECL__6812DP256_H__ volatile  unsigned char  CAN3IDAR3    _IO_AT(0x213); 

/**************************************************************************************************/
/*                                  IDENTIFIER MASK REGISTERS (First bank)                        */
/**************************************************************************************************/
__DECL__6812DP256_H__ volatile  unsigned char  CAN3IDMR0    _IO_AT(0x214); 
__DECL__6812DP256_H__ volatile  unsigned char  CAN3IDMR1    _IO_AT(0x215); 
__DECL__6812DP256_H__ volatile  unsigned char  CAN3IDMR2    _IO_AT(0x216); 
__DECL__6812DP256_H__ volatile  unsigned char  CAN3IDMR3    _IO_AT(0x217); 

/**************************************************************************************************/
/*                            IDENTIFIER ACCEPTANCE REGISTERS (Second bank)                       */
/**************************************************************************************************/

__DECL__6812DP256_H__ volatile  unsigned char  CAN3IDAR4    _IO_AT(0x218); 
__DECL__6812DP256_H__ volatile  unsigned char  CAN3IDAR5    _IO_AT(0x219); 
__DECL__6812DP256_H__ volatile  unsigned char  CAN3IDAR6    _IO_AT(0x21A); 
__DECL__6812DP256_H__ volatile  unsigned char  CAN3IDAR7    _IO_AT(0x21B); 

/**************************************************************************************************/
/*                                  IDENTIFIER MASK REGISTERS (Second bank)                       */
/**************************************************************************************************/
__DECL__6812DP256_H__ volatile  unsigned char  CAN3IDMR4    _IO_AT(0x21C); 
__DECL__6812DP256_H__ volatile  unsigned char  CAN3IDMR5    _IO_AT(0x21D); 
__DECL__6812DP256_H__ volatile  unsigned char  CAN3IDMR6    _IO_AT(0x21E); 
__DECL__6812DP256_H__ volatile  unsigned char  CAN3IDMR7    _IO_AT(0x21F); 

/**************************************************************************************************/
/*                                  FOREGROUND RECEIVE BUFFER                                     */
/**************************************************************************************************/
__DECL__6812DP256_H__ volatile  unsigned char  CAN3RXFG[16]    _IO_AT(0x220); 

/**************************************************************************************************/
/*                                  FOREGROUND TRANSMIT BUFFER                                    */
/**************************************************************************************************/
__DECL__6812DP256_H__ volatile  unsigned char  CAN3TXFG[16]    _IO_AT(0x230); 

/*******************************************************************************************/
/*                             MSCAN12 MODULE CONTROL REGISTER 0                           */                                
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  CANCTL0_TYPE CAN4CTL01 _IO_AT(0x280);               

/*DEFINE REGISTER*/                          
#define CAN4CTL0 CAN4CTL01.CANCTL0_BYTE            

/*DEFINE REGISTER BITS*/                     
#define INITRQ_4 CAN4CTL01.CANCTL0_BITS._INITRQ       
#define SLPRQ_4  CAN4CTL01.CANCTL0_BITS._SLPRQ
#define WUPE_4   CAN4CTL01.CANCTL0_BITS._WUPE 
#define TIME_4   CAN4CTL01.CANCTL0_BITS._TIME       
#define SYNCH_4  CAN4CTL01.CANCTL0_BITS._SYNCH 
#define CSWAI_4  CAN4CTL01.CANCTL0_BITS._CSWAI 
#define RXACT_4  CAN4CTL01.CANCTL0_BITS._RXACT 
#define RXFRM_4  CAN4CTL01.CANCTL0_BITS._RXFRM 

/*******************************************************************************************/
/*                             MSCAN12 MODULE CONTROL REGISTER 1                           */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  CANCTL1_TYPE CAN4CTL11 _IO_AT(0x281);               

/*DEFINE REGISTER*/                          
#define CAN4CTL1 CAN4CTL11.CANCTL1_BYTE            

/*DEFINE REGISTER BITS*/                     
#define INITAK_4 CAN4CTL11.CANCTL1_BITS._INITAK      
#define SPLACK_4 CAN4CTL11.CANCTL1_BITS._SPLACK      
#define WUPM_4   CAN4CTL11.CANCTL1_BITS._WUPM
#define LISTEN_4 CAN4CTL11.CANCTL1_BITS._LISTEN      
#define LOOPB_4  CAN4CTL11.CANCTL1_BITS._LOOPB
#define CLKSRC_4 CAN4CTL11.CANCTL1_BITS._CLKSRC      
#define CANE_4   CAN4CTL11.CANCTL1_BITS._CANE      

/*******************************************************************************************/
/*                               MSCAN12 BUS TIMING REGISTER 0                             */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  CANBTR0_TYPE CAN4BTR01 _IO_AT(0x282);               

/*DEFINE REGISTER*/                          
#define CAN4BTR0 CAN4BTR01.CANCBTR0_BYTE            

/*DEFINE REGISTER BITS*/                     
#define BRP0_4 CAN4BTR01.CANBTR0_BITS._BRP0      
#define BRP1_4 CAN4BTR01.CANBTR0_BITS._BRP1      
#define BRP2_4 CAN4BTR01.CANBTR0_BITS._BRP2      
#define BRP3_4 CAN4BTR01.CANBTR0_BITS._BRP3      
#define BRP4_4 CAN4BTR01.CANBTR0_BITS._BRP4      
#define BRP5_4 CAN4BTR01.CANBTR0_BITS._BRP5      
#define SJW0_4 CAN4BTR01.CANBTR0_BITS._SJW0      
#define SJW1_4 CAN4BTR01.CANBTR0_BITS._SJW1

/*******************************************************************************************/
/*                               MSCAN12 BUS TIMING REGISTER 1                             */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  CANBTR1_TYPE CAN4BTR11 _IO_AT(0x283);               

/*DEFINE REGISTER*/                          
#define CAN4BTR1 CAN4BTR11.CANBTR1_BYTE            

/*DEFINE REGISTER BITS*/                     
#define TSEG10_4 CAN4BTR11.CANBTR1_BITS._TSEG10    
#define TSEG11_4 CAN4BTR11.CANBTR1_BITS._TSEG11    
#define TSEG12_4 CAN4BTR11.CANBTR1_BITS._TSEG12    
#define TSEG13_4 CAN4BTR11.CANBTR1_BITS._TSEG13    
#define TSEG20_4 CAN4BTR11.CANBTR1_BITS._TSEG20    
#define TSEG21_4 CAN4BTR11.CANBTR1_BITS._TSEG21    
#define TSEG22_4 CAN4BTR11.CANBTR1_BITS._TSEG22    
#define SAMP_4   CAN4BTR11.CANBTR1_BITS._SAMP

/*******************************************************************************************/
/*                               MSCAN12 RECEIVER FLAG REGISTER                            */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  CANRFLG_TYPE CAN4RFLG1 _IO_AT(0x284);               

/*DEFINE REGISTER*/                          
#define CAN4RFLG CAN4RFLG1.CANRFLG_BYTE            

/*DEFINE REGISTER BITS*/                     
#define RFX_4    CAN4RFLG1.CANRFLG_BITS._RFX
#define OVRIF_4  CAN4RFLG1.CANRFLG_BITS._OVRIF  
#define TSTAT0_4 CAN4RFLG1.CANRFLG_BITS._TSTAT0   
#define TSTAT1_4 CAN4RFLG1.CANRFLG_BITS._TSTAT1     
#define RSTAT0_4 CAN4RFLG1.CANRFLG_BITS._RSTAT0     
#define RSTAT1_4 CAN4RFLG1.CANRFLG_BITS._RSTAT1 
#define CSCIF_4  CAN4RFLG1.CANRFLG_BITS._CSCIF 
#define WUPIF_4  CAN4RFLG1.CANRFLG_BITS._WUPIF

/*******************************************************************************************/
/*                      MSCAN12 RECEIVER INTERRUPT ENABLE REGISTER                         */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  CANRIER_TYPE CAN4RIER1 _IO_AT(0x285);               

/*DEFINE REGISTER*/                          
#define CAN4RIER CAN4RIER1.CANRIER_BYTE            

/*DEFINE REGISTER BITS*/                     
#define RFXIE_4   CAN4RIER1.CANRIER_BITS._RFXIE
#define OVRIE_4   CAN4RIER1.CANRIER_BITS._OVRIE  
#define TSTATE0_4 CAN4RIER1.CANRIER_BITS._TSTATE0   
#define TSTATE1_4 CAN4RIER1.CANRIER_BITS._TSTATE1     
#define RSTATE0_4 CAN4RIER1.CANRIER_BITS._RSTATE0     
#define RSTATE1_4 CAN4RIER1.CANRIER_BITS._RSTATE1 
#define CSCIE_4   CAN4RIER1.CANRIER_BITS._CSCIE 
#define WUPIE_4   CAN4RIER1.CANRIER_BITS._WUPIE

/*******************************************************************************************/
/*                          MSCAN12 TRANSMITTER FLAG REGISTER                              */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  CANTFLG_TYPE CAN4TFLG1 _IO_AT(0x286);               

/*DEFINE REGISTER*/                          
#define CAN4TFLG CAN4TFLG1.CANTFLG_BYTE            

/*DEFINE REGISTER BITS*/                     
#define TXE0_4 CAN4TFLG1.CANTFLG_BITS._TXE0
#define TXE1_4 CAN4TFLG1.CANTFLG_BITS._TXE1
#define TXE2_4 CAN4TFLG1.CANTFLG_BITS._TXE2

/*******************************************************************************************/
/*                          MSCAN12 TRANSMITTER CONTROL REGISTER                           */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  CANTIER_TYPE CAN4TIER1 _IO_AT(0x287);               

/*DEFINE REGISTER*/                          
#define CAN4TIER CAN4TIER1.CANTIER_BYTE            

/*DEFINE REGISTER BITS*/                     
#define TXEIE0_4 CAN4TIER1.CANTIER_BITS._TXEIE0
#define TXEIE1_4 CAN4TIER1.CANTIER_BITS._TXEIE1
#define TXEIE2_4 CAN4TIER1.CANTIER_BITS._TXEIE2

/*******************************************************************************************/
/*                          MSCAN12 IDENTIFIER ACCEPTANCE CONTROL REGISTER                 */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  CANTARQ_TYPE CAN4TARQ1 _IO_AT(0x288);               

/*DEFINE REGISTER*/                          
#define CAN4TARQ CAN4TARQ1.CANTARQ_BYTE            

/*DEFINE REGISTER BITS*/                     
#define ABTRQ0_4 CAN4TARQ1.CANTARQ_BITS._ABTRQ0
#define ABTRQ1_4 CAN4TARQ1.CANTARQ_BITS._ABTRQ1
#define ABTRQ2_4 CAN4TARQ1.CANTARQ_BITS._ABTRQ2

/*******************************************************************************************/
/*                                           */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  CANTAAK_TYPE CAN4TAAK1 _IO_AT(0x289);               

/*DEFINE REGISTER*/                          
#define CAN4TAAK CAN4TAAK1.CANTAAK_BYTE            

/*DEFINE REGISTER BITS*/                     
#define ABTAK0_4 CAN4TAAK1.CANTAAK_BITS._ABTAK0
#define ABTAK1_4 CAN4TAAK1.CANTAAK_BITS._ABTAK1
#define ABTAK2_4 CAN4TAAK1.CANTAAK_BITS._ABTAK2

/*******************************************************************************************/
/*                                           */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  CANTBSEL_TYPE CAN4TBSEL1 _IO_AT(0x28A);               

/*DEFINE REGISTER*/                          
#define CAN4TBSEL CAN4TBSEL1.CANTBSEL_BYTE            

/*DEFINE REGISTER BITS*/                     
#define TX0_4 CAN4TBSEL1.CANTBSEL_BITS._TX0
#define TX1_4 CAN4TBSEL1.CANTBSEL_BITS._TX1
#define TX2_4 CAN4TBSEL1.CANTBSEL_BITS._TX2

/*******************************************************************************************/
/*                                           */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  CANIDAC_TYPE CAN4IDAC1 _IO_AT(0x28B);               

/*DEFINE REGISTER*/                          
#define CAN4IDAC CAN4IDAC1.CANIDAC_BYTE            

/*DEFINE REGISTER BITS*/                     
#define IDHI0_4  CAN4IDAC1.CANIDAC_BITS._IDHI0
#define IDHI1_4  CAN4IDAC1.CANIDAC_BITS._IDHI1
#define IDJIT2_4 CAN4IDAC1.CANIDAC_BITS._IDJIT2
#define IDAM0_4  CAN4IDAC1.CANIDAC_BITS._IDAM0
#define IDAM1_4  CAN4IDAC1.CANIDAC_BITS._IDAM1

/**************************************************************************************************/
/*                                      MSCAN12 RECEIVE ERROR COUNTER                             */
/**************************************************************************************************/
__DECL__6812DP256_H__ volatile  unsigned char  CAN4RXERR    _IO_AT(0x28E); 

/**************************************************************************************************/
/*                                     MSCAN12 TRANSMIT ERROR COUNTER                             */
/**************************************************************************************************/
__DECL__6812DP256_H__ volatile  unsigned char  CAN4TXERR    _IO_AT(0x28F); 

/**************************************************************************************************/
/*                            IDENTIFIER ACCEPTANCE REGISTERS (First bank)                        */
/**************************************************************************************************/
__DECL__6812DP256_H__ volatile  unsigned char  CAN4IDAR0    _IO_AT(0x290); 
__DECL__6812DP256_H__ volatile  unsigned char  CAN4IDAR1    _IO_AT(0x291); 
__DECL__6812DP256_H__ volatile  unsigned char  CAN4IDAR2    _IO_AT(0x292); 
__DECL__6812DP256_H__ volatile  unsigned char  CAN4IDAR3    _IO_AT(0x293); 

/**************************************************************************************************/
/*                                  IDENTIFIER MASK REGISTERS (First bank)                        */
/**************************************************************************************************/
__DECL__6812DP256_H__ volatile  unsigned char  CAN4IDMR0    _IO_AT(0x294); 
__DECL__6812DP256_H__ volatile  unsigned char  CAN4IDMR1    _IO_AT(0x295); 
__DECL__6812DP256_H__ volatile  unsigned char  CAN4IDMR2    _IO_AT(0x296); 
__DECL__6812DP256_H__ volatile  unsigned char  CAN4IDMR3    _IO_AT(0x297); 

/**************************************************************************************************/
/*                            IDENTIFIER ACCEPTANCE REGISTERS (Second bank)                       */
/**************************************************************************************************/
__DECL__6812DP256_H__ volatile  unsigned char  CAN4IDAR4    _IO_AT(0x298); 
__DECL__6812DP256_H__ volatile  unsigned char  CAN4IDAR5    _IO_AT(0x299); 
__DECL__6812DP256_H__ volatile  unsigned char  CAN4IDAR6    _IO_AT(0x29A); 
__DECL__6812DP256_H__ volatile  unsigned char  CAN4IDAR7    _IO_AT(0x29B); 

/**************************************************************************************************/
/*                                  IDENTIFIER MASK REGISTERS (Second bank)                       */
/**************************************************************************************************/
__DECL__6812DP256_H__ volatile  unsigned char  CAN4IDMR4    _IO_AT(0x29C); 
__DECL__6812DP256_H__ volatile  unsigned char  CAN4IDMR5    _IO_AT(0x29D); 
__DECL__6812DP256_H__ volatile  unsigned char  CAN4IDMR6    _IO_AT(0x29E); 
__DECL__6812DP256_H__ volatile  unsigned char  CAN4IDMR7    _IO_AT(0x29F); 

/**************************************************************************************************/
/*                                  FOREGROUND RECEIVE BUFFER                                     */
/**************************************************************************************************/
__DECL__6812DP256_H__ volatile  unsigned char  CAN4RXFG[16]    _IO_AT(0x2A0); 

/**************************************************************************************************/
/*                                  FOREGROUND TRANSMIT BUFFER                                    */
/**************************************************************************************************/
__DECL__6812DP256_H__ volatile  unsigned char  CAN4TXFG[16]    _IO_AT(0x2B0); 

/*******************************************************************************************/
/*                                           PORT T                                        */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  unsigned char PTT     _IO_AT(0x240);  
__DECL__6812DP256_H__ volatile  unsigned char PTIT    _IO_AT(0x241);  
__DECL__6812DP256_H__ volatile  unsigned char DDRT    _IO_AT(0x242);  
__DECL__6812DP256_H__ volatile  unsigned char RDRT    _IO_AT(0x243);  
__DECL__6812DP256_H__ volatile  unsigned char PERT    _IO_AT(0x244);  
__DECL__6812DP256_H__ volatile  unsigned char PPST    _IO_AT(0x245);  

/*******************************************************************************************/
/*                                           PORT S                                        */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  unsigned char PTS     _IO_AT(0x248);  
__DECL__6812DP256_H__ volatile  unsigned char PTIS    _IO_AT(0x249);  
__DECL__6812DP256_H__ volatile  unsigned char DDRS    _IO_AT(0x24A);  
__DECL__6812DP256_H__ volatile  unsigned char RDRS    _IO_AT(0x24B);  
__DECL__6812DP256_H__ volatile  unsigned char PERS    _IO_AT(0x24C);  
__DECL__6812DP256_H__ volatile  unsigned char PPSS    _IO_AT(0x24D);  
__DECL__6812DP256_H__ volatile  unsigned char WOMS    _IO_AT(0x24E);  

/*******************************************************************************************/
/*                                           PORT M                                        */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  unsigned char PTM     _IO_AT(0x250);  
__DECL__6812DP256_H__ volatile  unsigned char PTIM    _IO_AT(0x251);  
__DECL__6812DP256_H__ volatile  unsigned char DDRM    _IO_AT(0x252);  
__DECL__6812DP256_H__ volatile  unsigned char RDRM    _IO_AT(0x253);  
__DECL__6812DP256_H__ volatile  unsigned char PERM    _IO_AT(0x254);  
__DECL__6812DP256_H__ volatile  unsigned char PPSM    _IO_AT(0x255);  
__DECL__6812DP256_H__ volatile  unsigned char WOMM    _IO_AT(0x256);  

/*******************************************************************************************/
/*                                           PORT P                                        */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  unsigned char PTP     _IO_AT(0x258);  
__DECL__6812DP256_H__ volatile  unsigned char PTIP    _IO_AT(0x259);  
__DECL__6812DP256_H__ volatile  unsigned char DDRP    _IO_AT(0x25A);  
__DECL__6812DP256_H__ volatile  unsigned char RDRP    _IO_AT(0x25B);  
__DECL__6812DP256_H__ volatile  unsigned char PERP    _IO_AT(0x25C);  
__DECL__6812DP256_H__ volatile  unsigned char PPSP    _IO_AT(0x25D);  
__DECL__6812DP256_H__ volatile  unsigned char PIEP    _IO_AT(0x25E);  
__DECL__6812DP256_H__ volatile  unsigned char PIFP    _IO_AT(0x25F);  

/*******************************************************************************************/
/*                                           PORT H                                        */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  unsigned char PTH     _IO_AT(0x260);  
__DECL__6812DP256_H__ volatile  unsigned char PTIH    _IO_AT(0x261);  
__DECL__6812DP256_H__ volatile  unsigned char DDRH    _IO_AT(0x262);  
__DECL__6812DP256_H__ volatile  unsigned char RDRH    _IO_AT(0x263);  
__DECL__6812DP256_H__ volatile  unsigned char PERH    _IO_AT(0x264);  
__DECL__6812DP256_H__ volatile  unsigned char PPSH    _IO_AT(0x265);  
__DECL__6812DP256_H__ volatile  unsigned char PIEH    _IO_AT(0x266);  
__DECL__6812DP256_H__ volatile  unsigned char PIFH    _IO_AT(0x267);  

/*******************************************************************************************/
/*                                           PORT J                                        */
/*******************************************************************************************/
__DECL__6812DP256_H__ volatile  unsigned char PTJ     _IO_AT(0x268);  
__DECL__6812DP256_H__ volatile  unsigned char PTIJ    _IO_AT(0x269);  
__DECL__6812DP256_H__ volatile  unsigned char DDRJ    _IO_AT(0x26A);  
__DECL__6812DP256_H__ volatile  unsigned char RDRJ    _IO_AT(0x26B);  
__DECL__6812DP256_H__ volatile  unsigned char PERJ    _IO_AT(0x26C);  
__DECL__6812DP256_H__ volatile  unsigned char PPSJ    _IO_AT(0x26D);  
__DECL__6812DP256_H__ volatile  unsigned char PIEJ    _IO_AT(0x26E);  
__DECL__6812DP256_H__ volatile  unsigned char PIFJ    _IO_AT(0x26F);  


#endif /* __6812DP256_H__ */
