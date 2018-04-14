/* MS CAN module definitions
by Andrew Rutgers, Queen's Solar Car Team

Settings for MC68HC912BC32
*/

#ifndef __MSCAN12_H__
#define __MSCAN12_H__

#define _CAN_BASE_ADDR 0x0100 //Base address of CAN module
#define _CAN_AT(x)  @_CAN_BASE_ADDR+x

#include <stdtypes.h>

volatile  Byte CMCR0    _CAN_AT(0x00);   /* Module Control Register */
volatile  Byte CMCR1    _CAN_AT(0x01);
volatile  Byte CBTR0    _CAN_AT(0x02);   // Bus Timing Register
volatile  Byte CBTR1    _CAN_AT(0x03);
volatile  Byte CRFLG    _CAN_AT(0x04);   // Reciever Flag Register
volatile  Byte CRIER    _CAN_AT(0x05);   // Reciever Interupt Enable
volatile  Byte CTFLG    _CAN_AT(0x06);   // Transmitter flag register
volatile  Byte CTCR     _CAN_AT(0x07);   // Transmitter Control Register
volatile  Byte CIDAC    _CAN_AT(0x08);   // Identifier Acceptance control register
volatile  Byte CRXERR   _CAN_AT(0x0E);   // Recieve Error Conunter
volatile  Byte CTXERR   _CAN_AT(0x0F);   // Transmit Error Counter
volatile  Byte PCTLCAN  _CAN_AT(0x3D);   // Port CAN control register
volatile  Byte PORTCAN  _CAN_AT(0x3E);   // port CAN data register
volatile  Byte DDRCAN   _CAN_AT(0x3F);   // port CAN data direction register
volatile  Byte CIDMR0   _CAN_AT(0x14);   // Identifier mask register
volatile  Byte CIDMR1   _CAN_AT(0x15);   // Identifier mask register
volatile  Byte CIDMR2   _CAN_AT(0x16);   // Identifier mask register
volatile  Byte CIDMR3   _CAN_AT(0x17);   // Identifier mask register
volatile  Byte CIDMR4   _CAN_AT(0x1C);   // Identifier mask register
volatile  Byte CIDMR5   _CAN_AT(0x1D);   // Identifier mask register
volatile  Byte CIDMR6   _CAN_AT(0x1E);   // Identifier mask register
volatile  Byte CIDMR7   _CAN_AT(0x1F);   // Identifier mask register
volatile  Byte CIDAR0   _CAN_AT(0x10);   // Identifier acceptance register
volatile  Byte CIDAR1   _CAN_AT(0x11);   // Identifier acceptance register
volatile  Byte CIDAR2   _CAN_AT(0x12);   // Identifier acceptance register
volatile  Byte CIDAR3   _CAN_AT(0x13);   // Identifier acceptance register
volatile  Byte CIDAR4   _CAN_AT(0x18);   // Identifier acceptance register
volatile  Byte CIDAR5   _CAN_AT(0x19);   // Identifier acceptance register
volatile  Byte CIDAR6   _CAN_AT(0x1A);   // Identifier acceptance register
volatile  Byte CIDAR7   _CAN_AT(0x1B);   // Identifier acceptance register

typedef struct CANBUFFER { // Recieve / Transmit Buffer structure
  Byte IDR[4];
  Byte DSR[8];
  Byte DLR;
  Byte TBPR;
  Byte NILL[2];
};

volatile struct CANBUFFER CANRX _CAN_AT(0x40);
volatile struct CANBUFFER CANTX[3] _CAN_AT(0x50);

#endif
