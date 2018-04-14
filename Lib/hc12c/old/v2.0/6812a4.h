/*****************************************************
     6812a4.h - Target interface library
     Describes I/O registers of MC68HC12A4
 ----------------------------------------------------
   Copyright (c) Metrowerks, Basel, Switzerland
                  Do not modify!
 *****************************************************/

#ifndef __6812A4_H__
#define __6812A4_H__

#include <stdtypes.h>

#define _IO_BASE_ADDR 0
#define _IO_AT(x)  @_IO_BASE_ADDR+x

#ifndef __DECL__6812A4_H__
#define __DECL__6812A4_H__  extern
#endif

__DECL__6812A4_H__ volatile  Byte PORTA  _IO_AT(0x00);  /* port A */
__DECL__6812A4_H__ volatile  Byte PORTB  _IO_AT(0x01);  /* port B */
__DECL__6812A4_H__ volatile  Byte DDRA   _IO_AT(0x02);  /* data direction port A */
__DECL__6812A4_H__ volatile  Byte DDRB   _IO_AT(0x03);  /* data direction port B */
__DECL__6812A4_H__ volatile  Byte PORTC  _IO_AT(0x04);  /* port C */
__DECL__6812A4_H__ volatile  Byte PORTD  _IO_AT(0x05);  /* port D */
__DECL__6812A4_H__ volatile  Byte DDRC   _IO_AT(0x06);  /* data direction port C */
__DECL__6812A4_H__ volatile  Byte DDRD   _IO_AT(0x07);  /* data direction port D */
__DECL__6812A4_H__ volatile  Byte PORTE  _IO_AT(0x08);  /* port E */
__DECL__6812A4_H__ volatile  Byte DDRE   _IO_AT(0x09);  /* data direction port E */
__DECL__6812A4_H__ volatile  Byte PEAR   _IO_AT(0x0a);  /* port E assignment register */
__DECL__6812A4_H__ volatile  Byte MODE   _IO_AT(0x0b);  /* mode register */
__DECL__6812A4_H__ volatile  Byte PUCR   _IO_AT(0x0c);  /* pull-up control register */
__DECL__6812A4_H__ volatile  Byte RDRIV  _IO_AT(0x0d);  /* reduced drive of I/O lines */

__DECL__6812A4_H__ volatile  Byte INITRM _IO_AT(0x10);  /* RAM mapping register */
__DECL__6812A4_H__ volatile  Byte INITRG _IO_AT(0x11);  /* IO mapping register */
__DECL__6812A4_H__ volatile  Byte INITEE _IO_AT(0x12);  /* EEPROM mapping register */
__DECL__6812A4_H__ volatile  Byte MISC   _IO_AT(0x13);  /* mapping control register */
__DECL__6812A4_H__ volatile  Byte RTICTL _IO_AT(0x14);  /* real time interrupt control */
__DECL__6812A4_H__ volatile  Byte RTIFLG _IO_AT(0x15);  /* real time interrupt flag */
__DECL__6812A4_H__ volatile  Byte COPCTL _IO_AT(0x16);  /* COP control register */
__DECL__6812A4_H__ volatile  Byte COPRST _IO_AT(0x17);  /* COP arm/reset */
__DECL__6812A4_H__ volatile  Byte ITST0  _IO_AT(0x18);  /* interrupt test 0 */
__DECL__6812A4_H__ volatile  Byte ITST1  _IO_AT(0x19);  /* interrupt test 1 */
__DECL__6812A4_H__ volatile  Byte ITST2  _IO_AT(0x1a);  /* interrupt test 2 */
__DECL__6812A4_H__ volatile  Byte ITST3  _IO_AT(0x1b);  /* interrupt test 3 */
__DECL__6812A4_H__ volatile  Byte INTCR  _IO_AT(0x1e);  /* interrupt control */
__DECL__6812A4_H__ volatile  Byte HPRIO  _IO_AT(0x1f);  /* highest priority */

__DECL__6812A4_H__ volatile  Byte KWIED  _IO_AT(0x20);  /* Wake up interrupt enable D */
__DECL__6812A4_H__ volatile  Byte KWIFD  _IO_AT(0x21);  /* Wake up flag register D */
__DECL__6812A4_H__ volatile  Byte PORTH  _IO_AT(0x24);  /* port H */
__DECL__6812A4_H__ volatile  Byte DDRH   _IO_AT(0x25);  /* data direction port H */
__DECL__6812A4_H__ volatile  Byte KWIEH  _IO_AT(0x26);  /* Wake up interrupt enable H */
__DECL__6812A4_H__ volatile  Byte KWIFH  _IO_AT(0x27);  /* Wake up flag register H */
__DECL__6812A4_H__ volatile  Byte PORTJ  _IO_AT(0x28);  /* port J */
__DECL__6812A4_H__ volatile  Byte DDRJ   _IO_AT(0x29);  /* data direction port J */
__DECL__6812A4_H__ volatile  Byte KWIEJ  _IO_AT(0x2a);  /* Wake up interrupt enable J */
__DECL__6812A4_H__ volatile  Byte KWIFJ  _IO_AT(0x2b);  /* Wake up flag register J */
__DECL__6812A4_H__ volatile  Byte KPOLJ  _IO_AT(0x2c);  /* Wake up polarity J */
__DECL__6812A4_H__ volatile  Byte PUPSJ  _IO_AT(0x2d);  /* pull-up select J */
__DECL__6812A4_H__ volatile  Byte PUPEJ  _IO_AT(0x2e);  /* pull-up enable J */

__DECL__6812A4_H__ volatile  Byte PORTF  _IO_AT(0x30);  /* port F */
__DECL__6812A4_H__ volatile  Byte PORTG  _IO_AT(0x31);  /* port G */
__DECL__6812A4_H__ volatile  Byte DDRF   _IO_AT(0x32);  /* data direction port F */
__DECL__6812A4_H__ volatile  Byte DDRG   _IO_AT(0x33);  /* data direction port G */
__DECL__6812A4_H__ volatile  Byte DPAGE  _IO_AT(0x34);  /* data page register */
__DECL__6812A4_H__ volatile  Byte PPAGE  _IO_AT(0x35);  /* program page register */
__DECL__6812A4_H__ volatile  Byte EPAGE  _IO_AT(0x36);  /* extra page register */
__DECL__6812A4_H__ volatile  Byte WINDEF _IO_AT(0x37);  /* window definition */
__DECL__6812A4_H__ volatile  Byte MXAR   _IO_AT(0x38);  /* memory expansion assignment */
__DECL__6812A4_H__ volatile  Byte CSCTL0 _IO_AT(0x3c);  /* chip select control 0 */
__DECL__6812A4_H__ volatile  Byte CSCTL1 _IO_AT(0x3d);  /* chip select control 1 */
__DECL__6812A4_H__ volatile  Byte CSSTR0 _IO_AT(0x3e);  /* chip select stretch 0 */
__DECL__6812A4_H__ volatile  Byte CSSTR1 _IO_AT(0x3f);  /* chip select stretch 1 */

__DECL__6812A4_H__ volatile  Word LDV    _IO_AT(0x40);  /* pll loop divider */
__DECL__6812A4_H__ volatile  Word RDV    _IO_AT(0x42);  /* pll reference divider */
__DECL__6812A4_H__ volatile  Byte CLKCTL _IO_AT(0x47);  /* clock control register */

__DECL__6812A4_H__ volatile  Byte ATDCTL0 _IO_AT(0x60); /* A/D control register 0 */
__DECL__6812A4_H__ volatile  Byte ATDCTL1 _IO_AT(0x61); /* A/D control register 1 */
__DECL__6812A4_H__ volatile  Byte ATDCTL2 _IO_AT(0x62); /* A/D control register 2 */
__DECL__6812A4_H__ volatile  Byte ATDCTL3 _IO_AT(0x63); /* A/D control register 3 */
__DECL__6812A4_H__ volatile  Byte ATDCTL4 _IO_AT(0x64); /* A/D control register 4 */
__DECL__6812A4_H__ volatile  Byte ATDCTL5 _IO_AT(0x65); /* A/D control register 5 */
__DECL__6812A4_H__ volatile  Word ATDSTAT _IO_AT(0x66); /* A/D status register */
__DECL__6812A4_H__ volatile  Word ATDTEST _IO_AT(0x68); /* A/D test register */
__DECL__6812A4_H__ volatile  Byte PORTAD  _IO_AT(0x6f); /* port AD data input register */
__DECL__6812A4_H__ volatile  Byte ADR0H   _IO_AT(0x70); /* A/D result 0 */
__DECL__6812A4_H__ volatile  Byte ADR1H   _IO_AT(0x72); /* A/D result 1 */
__DECL__6812A4_H__ volatile  Byte ADR2H   _IO_AT(0x74); /* A/D result 2 */
__DECL__6812A4_H__ volatile  Byte ADR3H   _IO_AT(0x76); /* A/D result 3 */
__DECL__6812A4_H__ volatile  Byte ADR4H   _IO_AT(0x78); /* A/D result 4 */
__DECL__6812A4_H__ volatile  Byte ADR5H   _IO_AT(0x7a); /* A/D result 5 */
__DECL__6812A4_H__ volatile  Byte ADR6H   _IO_AT(0x7c); /* A/D result 6 */
__DECL__6812A4_H__ volatile  Byte ADR7H   _IO_AT(0x7e); /* A/D result 7 */

__DECL__6812A4_H__ volatile  Byte TIOS   _IO_AT(0x80);  /* time select */
__DECL__6812A4_H__ volatile  Byte CFORC  _IO_AT(0x81);  /* compare force */
__DECL__6812A4_H__ volatile  Byte OC7M   _IO_AT(0x82);  /* oc7 mask */
__DECL__6812A4_H__ volatile  Byte OC7D   _IO_AT(0x83);  /* oc7 data */
__DECL__6812A4_H__ volatile  Word TCNT   _IO_AT(0x84);  /* timer counter */
__DECL__6812A4_H__ volatile  Byte TSCR   _IO_AT(0x86);  /* timer system control */
__DECL__6812A4_H__ volatile  Byte TQCR   _IO_AT(0x87);  /* timer queue control */
__DECL__6812A4_H__ volatile  Byte TCTL1  _IO_AT(0x88);  /* timer control 1 */
__DECL__6812A4_H__ volatile  Byte TCTL2  _IO_AT(0x89);  /* timer control 2 */
__DECL__6812A4_H__ volatile  Byte TCTL3  _IO_AT(0x8a);  /* timer control 3 */
__DECL__6812A4_H__ volatile  Byte TCTL4  _IO_AT(0x8b);  /* timer control 4 */
__DECL__6812A4_H__ volatile  Byte TMSK1  _IO_AT(0x8c);  /* timer interrupt mask 1 */
__DECL__6812A4_H__ volatile  Byte TMSK2  _IO_AT(0x8d);  /* timer interrupt mask 2 */
__DECL__6812A4_H__ volatile  Byte TFLG1  _IO_AT(0x8e);  /* timer interrupt flag 1 */
__DECL__6812A4_H__ volatile  Byte TFLG2  _IO_AT(0x8f);  /* timer interrupt flag 2 */
__DECL__6812A4_H__ volatile  Word TC0    _IO_AT(0x90);  /* timer capture/compare 0 */
__DECL__6812A4_H__ volatile  Word TC1    _IO_AT(0x92);  /* timer capture/compare 1 */
__DECL__6812A4_H__ volatile  Word TC2    _IO_AT(0x94);  /* timer capture/compare 2 */
__DECL__6812A4_H__ volatile  Word TC3    _IO_AT(0x96);  /* timer capture/compare 3 */
__DECL__6812A4_H__ volatile  Word TC4    _IO_AT(0x98);  /* timer capture/compare 4 */
__DECL__6812A4_H__ volatile  Word TC5    _IO_AT(0x9a);  /* timer capture/compare 5 */
__DECL__6812A4_H__ volatile  Word TC6    _IO_AT(0x9c);  /* timer capture/compare 6 */
__DECL__6812A4_H__ volatile  Word TC7    _IO_AT(0x9e);  /* timer capture/compare 7 */
__DECL__6812A4_H__ volatile  Byte PACTL  _IO_AT(0xa0);  /* pulse accumulator control */
__DECL__6812A4_H__ volatile  Byte PAFLG  _IO_AT(0xa1);  /* pulse accumulator flag */
__DECL__6812A4_H__ volatile  Word PACNT  _IO_AT(0xa2);  /* pulse accumulator count */
__DECL__6812A4_H__ volatile  Byte TIMTST _IO_AT(0xad);  /* timer test register */
__DECL__6812A4_H__ volatile  Byte PORTT  _IO_AT(0xae);  /* timer port data */
__DECL__6812A4_H__ volatile  Byte DDRT   _IO_AT(0xaf);  /* timer data direction */

__DECL__6812A4_H__ volatile  Byte SC0BDH _IO_AT(0xc0);  /* SCI 0 baud rate high */
__DECL__6812A4_H__ volatile  Byte SC0BDL _IO_AT(0xc1);  /* SCI 0 baud rate low */
__DECL__6812A4_H__ volatile  Byte SC0CR1 _IO_AT(0xc2);  /* SCI 0 control register 1 */
__DECL__6812A4_H__ volatile  Byte SC0CR2 _IO_AT(0xc3);  /* SCI 0 control register 2 */
__DECL__6812A4_H__ volatile  Byte SC0SR1 _IO_AT(0xc4);  /* SCI 0 status register 1 */
__DECL__6812A4_H__ volatile  Byte SC0SR2 _IO_AT(0xc5);  /* SCI 0 status register 2 */
__DECL__6812A4_H__ volatile  Byte SC0DRH _IO_AT(0xc6);  /* SCI 0 data register high */
__DECL__6812A4_H__ volatile  Byte SC0DRL _IO_AT(0xc7);  /* SCI 0 data register low */
__DECL__6812A4_H__ volatile  Byte SC1BDH _IO_AT(0xc8);  /* SCI 1 baud rate high */
__DECL__6812A4_H__ volatile  Byte SC1BDL _IO_AT(0xc9);  /* SCI 1 baud rate low */
__DECL__6812A4_H__ volatile  Byte SC1CR1 _IO_AT(0xca);  /* SCI 1 control register 1 */
__DECL__6812A4_H__ volatile  Byte SC1CR2 _IO_AT(0xcb);  /* SCI 1 control register 2 */
__DECL__6812A4_H__ volatile  Byte SC1SR1 _IO_AT(0xcc);  /* SCI 1 status register 1 */
__DECL__6812A4_H__ volatile  Byte SC1SR2 _IO_AT(0xcd);  /* SCI 1 status register 2 */
__DECL__6812A4_H__ volatile  Byte SC1DRH _IO_AT(0xce);  /* SCI 1 data register high */
__DECL__6812A4_H__ volatile  Byte SC1DRL _IO_AT(0xcf);  /* SCI 1 data register low */

__DECL__6812A4_H__ volatile  Byte SP0CR1 _IO_AT(0xd0);  /* SPI control register 1 */
__DECL__6812A4_H__ volatile  Byte SP0CR2 _IO_AT(0xd1);  /* SPI control register 2 */
__DECL__6812A4_H__ volatile  Byte SP0BR  _IO_AT(0xd2);  /* SPI baud rate register */
__DECL__6812A4_H__ volatile  Byte SP0SR  _IO_AT(0xd3);  /* SPI status register */
__DECL__6812A4_H__ volatile  Byte SP0DR  _IO_AT(0xd5);  /* SPI data register */
__DECL__6812A4_H__ volatile  Byte PORTS  _IO_AT(0xd6);  /* port S data register */
__DECL__6812A4_H__ volatile  Byte DDRS   _IO_AT(0xd7);  /* port S data direction */

__DECL__6812A4_H__ volatile  Byte EEMCR  _IO_AT(0xf0);  /* eeprom module configuration */
__DECL__6812A4_H__ volatile  Byte EEPROT _IO_AT(0xf1);  /* eeprom block protect */
__DECL__6812A4_H__ volatile  Byte EETST  _IO_AT(0xf2);  /* eeprom test register */
__DECL__6812A4_H__ volatile  Byte EEPROG _IO_AT(0xf3);  /* eeprom control register */

#endif /* __6812A4_H__ */

