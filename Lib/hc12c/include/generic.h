
#ifndef _MC9S12_GENERIC_H
#define _MC9S12_GENERIC_H

/* Types definition */
typedef unsigned char byte;
typedef unsigned int word;
typedef unsigned long dword;
typedef unsigned long dlong[2];

#define REG_BASE 0x0000                /* Base address for the I/O register block */


#pragma MESSAGE DISABLE C1106 /* WARNING C1106: Non-standard bitfield type */

/*** PORTAB - Port AB Register; 0x00000000 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** PORTA - Port A Register; 0x00000000 ***/
    union {
      byte Byte;
      struct {
        byte BIT0        :1;                                       /* Port A Bit0, ADDR8, DATA8, DATA0 */
        byte BIT1        :1;                                       /* Port A Bit1, ADDR9, DATA9 DATA1 */
        byte BIT2        :1;                                       /* Port A Bit2, ADDR10, DATA10, DATA2 */
        byte BIT3        :1;                                       /* Port A Bit3, ADDR11, DATA11, DATA3 */
        byte BIT4        :1;                                       /* Port A Bit4, ADDR12, DATA12, DATA4 */
        byte BIT5        :1;                                       /* Port A Bit5, ADDR13, DATA13, DATA5 */
        byte BIT6        :1;                                       /* Port A Bit6, ADDR14, DATA14, DATA6 */
        byte BIT7        :1;                                       /* Port A Bit7, ADDR15, DATA15, DATA7 */
      } Bits;
      struct {
        byte grpBIT :8;
      } MergedBits;
    } PORTASTR;
    #define PORTA _PORTAB.Overlap_STR.PORTASTR.Byte
    #define PORTA_BIT0 _PORTAB.Overlap_STR.PORTASTR.Bits.BIT0
    #define PORTA_BIT1 _PORTAB.Overlap_STR.PORTASTR.Bits.BIT1
    #define PORTA_BIT2 _PORTAB.Overlap_STR.PORTASTR.Bits.BIT2
    #define PORTA_BIT3 _PORTAB.Overlap_STR.PORTASTR.Bits.BIT3
    #define PORTA_BIT4 _PORTAB.Overlap_STR.PORTASTR.Bits.BIT4
    #define PORTA_BIT5 _PORTAB.Overlap_STR.PORTASTR.Bits.BIT5
    #define PORTA_BIT6 _PORTAB.Overlap_STR.PORTASTR.Bits.BIT6
    #define PORTA_BIT7 _PORTAB.Overlap_STR.PORTASTR.Bits.BIT7
    #define PORTA_BIT _PORTAB.Overlap_STR.PORTASTR.MergedBits.grpBIT

    /*** PORTB - Port B Register; 0x00000001 ***/
    union {
      byte Byte;
      struct {
        byte BIT0        :1;                                       /* Port B Bit 0, ADDR0, DATA0 */
        byte BIT1        :1;                                       /* Port B Bit1, ADDR1, DATA1 */
        byte BIT2        :1;                                       /* Port B Bit2, ADDR2, DATA2 */
        byte BIT3        :1;                                       /* Port B Bit3, ADDR3, DATA3 */
        byte BIT4        :1;                                       /* Port B Bit4, ADDR4, DATA4 */
        byte BIT5        :1;                                       /* Port B Bit5, ADDR5, DATA5 */
        byte BIT6        :1;                                       /* Port B Bit6, ADDR6, DATA6 */
        byte BIT7        :1;                                       /* Port B Bit7, ADDR7, DATA7 */
      } Bits;
      struct {
        byte grpBIT :8;
      } MergedBits;
    } PORTBSTR;
    #define PORTB _PORTAB.Overlap_STR.PORTBSTR.Byte
    #define PORTB_BIT0 _PORTAB.Overlap_STR.PORTBSTR.Bits.BIT0
    #define PORTB_BIT1 _PORTAB.Overlap_STR.PORTBSTR.Bits.BIT1
    #define PORTB_BIT2 _PORTAB.Overlap_STR.PORTBSTR.Bits.BIT2
    #define PORTB_BIT3 _PORTAB.Overlap_STR.PORTBSTR.Bits.BIT3
    #define PORTB_BIT4 _PORTAB.Overlap_STR.PORTBSTR.Bits.BIT4
    #define PORTB_BIT5 _PORTAB.Overlap_STR.PORTBSTR.Bits.BIT5
    #define PORTB_BIT6 _PORTAB.Overlap_STR.PORTBSTR.Bits.BIT6
    #define PORTB_BIT7 _PORTAB.Overlap_STR.PORTBSTR.Bits.BIT7
    #define PORTB_BIT _PORTAB.Overlap_STR.PORTBSTR.MergedBits.grpBIT

  } Overlap_STR;

  struct {
    word BIT0        :1;                                       /* Port B Bit 0, ADDR0, DATA0 */
    word BIT1        :1;                                       /* Port B Bit1, ADDR1, DATA1 */
    word BIT2        :1;                                       /* Port B Bit2, ADDR2, DATA2 */
    word BIT3        :1;                                       /* Port B Bit3, ADDR3, DATA3 */
    word BIT4        :1;                                       /* Port B Bit4, ADDR4, DATA4 */
    word BIT5        :1;                                       /* Port B Bit5, ADDR5, DATA5 */
    word BIT6        :1;                                       /* Port B Bit6, ADDR6, DATA6 */
    word BIT7        :1;                                       /* Port B Bit7, ADDR7, DATA7 */
    word BIT8        :1;                                       /* Port A Bit0, ADDR8, DATA8, DATA0 */
    word BIT9        :1;                                       /* Port A Bit1, ADDR9, DATA9 DATA1 */
    word BIT10       :1;                                       /* Port A Bit2, ADDR10, DATA10, DATA2 */
    word BIT11       :1;                                       /* Port A Bit3, ADDR11, DATA11, DATA3 */
    word BIT12       :1;                                       /* Port A Bit4, ADDR12, DATA12, DATA4 */
    word BIT13       :1;                                       /* Port A Bit5, ADDR13, DATA13, DATA5 */
    word BIT14       :1;                                       /* Port A Bit6, ADDR14, DATA14, DATA6 */
    word BIT15       :1;                                       /* Port A Bit7, ADDR15, DATA15, DATA7 */
  } Bits;
  struct {
    word grpBIT  :16;
  } MergedBits;
} PORTABSTR;
extern volatile PORTABSTR _PORTAB @(REG_BASE + 0x00000000);
#define PORTAB _PORTAB.Word
#define PORTAB_BIT0 _PORTAB.Bits.BIT0
#define PORTAB_BIT1 _PORTAB.Bits.BIT1
#define PORTAB_BIT2 _PORTAB.Bits.BIT2
#define PORTAB_BIT3 _PORTAB.Bits.BIT3
#define PORTAB_BIT4 _PORTAB.Bits.BIT4
#define PORTAB_BIT5 _PORTAB.Bits.BIT5
#define PORTAB_BIT6 _PORTAB.Bits.BIT6
#define PORTAB_BIT7 _PORTAB.Bits.BIT7
#define PORTAB_BIT8 _PORTAB.Bits.BIT8
#define PORTAB_BIT9 _PORTAB.Bits.BIT9
#define PORTAB_BIT10 _PORTAB.Bits.BIT10
#define PORTAB_BIT11 _PORTAB.Bits.BIT11
#define PORTAB_BIT12 _PORTAB.Bits.BIT12
#define PORTAB_BIT13 _PORTAB.Bits.BIT13
#define PORTAB_BIT14 _PORTAB.Bits.BIT14
#define PORTAB_BIT15 _PORTAB.Bits.BIT15
#define PORTAB_BIT _PORTAB.MergedBits.grpBIT


/*** DDRAB - Port AB Data Direction Register; 0x00000002 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** DDRA - Port A Data Direction Register; 0x00000002 ***/
    union {
      byte Byte;
      struct {
        byte BIT0        :1;                                       /* Data Direction Port A Bit 0 */
        byte BIT1        :1;                                       /* Data Direction Port A Bit 1 */
        byte BIT2        :1;                                       /* Data Direction Port A Bit 2 */
        byte BIT3        :1;                                       /* Data Direction Port A Bit 3 */
        byte BIT4        :1;                                       /* Data Direction Port A Bit 4 */
        byte BIT5        :1;                                       /* Data Direction Port A Bit 5 */
        byte BIT6        :1;                                       /* Data Direction Port A Bit 6 */
        byte BIT7        :1;                                       /* Data Direction Port A Bit 7 */
      } Bits;
      struct {
        byte grpBIT :8;
      } MergedBits;
    } DDRASTR;
    #define DDRA _DDRAB.Overlap_STR.DDRASTR.Byte
    #define DDRA_BIT0 _DDRAB.Overlap_STR.DDRASTR.Bits.BIT0
    #define DDRA_BIT1 _DDRAB.Overlap_STR.DDRASTR.Bits.BIT1
    #define DDRA_BIT2 _DDRAB.Overlap_STR.DDRASTR.Bits.BIT2
    #define DDRA_BIT3 _DDRAB.Overlap_STR.DDRASTR.Bits.BIT3
    #define DDRA_BIT4 _DDRAB.Overlap_STR.DDRASTR.Bits.BIT4
    #define DDRA_BIT5 _DDRAB.Overlap_STR.DDRASTR.Bits.BIT5
    #define DDRA_BIT6 _DDRAB.Overlap_STR.DDRASTR.Bits.BIT6
    #define DDRA_BIT7 _DDRAB.Overlap_STR.DDRASTR.Bits.BIT7
    #define DDRA_BIT _DDRAB.Overlap_STR.DDRASTR.MergedBits.grpBIT

    /*** DDRB - Port B Data Direction Register; 0x00000003 ***/
    union {
      byte Byte;
      struct {
        byte BIT0        :1;                                       /* Data Direction Port B Bit 0 */
        byte BIT1        :1;                                       /* Data Direction Port B Bit 1 */
        byte BIT2        :1;                                       /* Data Direction Port B Bit 2 */
        byte BIT3        :1;                                       /* Data Direction Port B Bit 3 */
        byte BIT4        :1;                                       /* Data Direction Port B Bit 4 */
        byte BIT5        :1;                                       /* Data Direction Port B Bit 5 */
        byte BIT6        :1;                                       /* Data Direction Port B Bit 6 */
        byte BIT7        :1;                                       /* Data Direction Port B Bit 7 */
      } Bits;
      struct {
        byte grpBIT :8;
      } MergedBits;
    } DDRBSTR;
    #define DDRB _DDRAB.Overlap_STR.DDRBSTR.Byte
    #define DDRB_BIT0 _DDRAB.Overlap_STR.DDRBSTR.Bits.BIT0
    #define DDRB_BIT1 _DDRAB.Overlap_STR.DDRBSTR.Bits.BIT1
    #define DDRB_BIT2 _DDRAB.Overlap_STR.DDRBSTR.Bits.BIT2
    #define DDRB_BIT3 _DDRAB.Overlap_STR.DDRBSTR.Bits.BIT3
    #define DDRB_BIT4 _DDRAB.Overlap_STR.DDRBSTR.Bits.BIT4
    #define DDRB_BIT5 _DDRAB.Overlap_STR.DDRBSTR.Bits.BIT5
    #define DDRB_BIT6 _DDRAB.Overlap_STR.DDRBSTR.Bits.BIT6
    #define DDRB_BIT7 _DDRAB.Overlap_STR.DDRBSTR.Bits.BIT7
    #define DDRB_BIT _DDRAB.Overlap_STR.DDRBSTR.MergedBits.grpBIT

  } Overlap_STR;

  struct {
    word BIT0        :1;                                       /* Data Direction Port B Bit 0 */
    word BIT1        :1;                                       /* Data Direction Port B Bit 1 */
    word BIT2        :1;                                       /* Data Direction Port B Bit 2 */
    word BIT3        :1;                                       /* Data Direction Port B Bit 3 */
    word BIT4        :1;                                       /* Data Direction Port B Bit 4 */
    word BIT5        :1;                                       /* Data Direction Port B Bit 5 */
    word BIT6        :1;                                       /* Data Direction Port B Bit 6 */
    word BIT7        :1;                                       /* Data Direction Port B Bit 7 */
    word BIT8        :1;                                       /* Data Direction Port A Bit 8 */
    word BIT9        :1;                                       /* Data Direction Port A Bit 9 */
    word BIT10       :1;                                       /* Data Direction Port A Bit 10 */
    word BIT11       :1;                                       /* Data Direction Port A Bit 11 */
    word BIT12       :1;                                       /* Data Direction Port A Bit 12 */
    word BIT13       :1;                                       /* Data Direction Port A Bit 13 */
    word BIT14       :1;                                       /* Data Direction Port A Bit 14 */
    word BIT15       :1;                                       /* Data Direction Port A Bit 15 */
  } Bits;
  struct {
    word grpBIT  :16;
  } MergedBits;
} DDRABSTR;
extern volatile DDRABSTR _DDRAB @(REG_BASE + 0x00000002);
#define DDRAB _DDRAB.Word
#define DDRAB_BIT0 _DDRAB.Bits.BIT0
#define DDRAB_BIT1 _DDRAB.Bits.BIT1
#define DDRAB_BIT2 _DDRAB.Bits.BIT2
#define DDRAB_BIT3 _DDRAB.Bits.BIT3
#define DDRAB_BIT4 _DDRAB.Bits.BIT4
#define DDRAB_BIT5 _DDRAB.Bits.BIT5
#define DDRAB_BIT6 _DDRAB.Bits.BIT6
#define DDRAB_BIT7 _DDRAB.Bits.BIT7
#define DDRAB_BIT8 _DDRAB.Bits.BIT8
#define DDRAB_BIT9 _DDRAB.Bits.BIT9
#define DDRAB_BIT10 _DDRAB.Bits.BIT10
#define DDRAB_BIT11 _DDRAB.Bits.BIT11
#define DDRAB_BIT12 _DDRAB.Bits.BIT12
#define DDRAB_BIT13 _DDRAB.Bits.BIT13
#define DDRAB_BIT14 _DDRAB.Bits.BIT14
#define DDRAB_BIT15 _DDRAB.Bits.BIT15
#define DDRAB_BIT _DDRAB.MergedBits.grpBIT


/*** ATD0CTL23 - ATD 0 Control Register 23; 0x00000082 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ATD0CTL2 - ATD 0 Control Register 2; 0x00000082 ***/
    union {
      byte Byte;
      struct {
        byte ASCIF       :1;                                       /* ATD 0 Sequence Complete Interrupt Flag */
        byte ASCIE       :1;                                       /* ATD 0 Sequence Complete Interrupt Enable */
        byte ETRIGE      :1;                                       /* External Trigger Mode enable */
        byte ETRIGP      :1;                                       /* External Trigger Polarity */
        byte ETRIGLE     :1;                                       /* External Trigger Level/Edge control */
        byte AWAI        :1;                                       /* ATD 0 Wait Mode */
        byte AFFC        :1;                                       /* ATD 0 Fast Conversion Complete Flag Clear */
        byte ADPU        :1;                                       /* ATD 0 Disable / Power Down */
      } Bits;
    } ATD0CTL2STR;
    #define ATD0CTL2 _ATD0CTL23.Overlap_STR.ATD0CTL2STR.Byte
    #define ATD0CTL2_ASCIF _ATD0CTL23.Overlap_STR.ATD0CTL2STR.Bits.ASCIF
    #define ATD0CTL2_ASCIE _ATD0CTL23.Overlap_STR.ATD0CTL2STR.Bits.ASCIE
    #define ATD0CTL2_ETRIGE _ATD0CTL23.Overlap_STR.ATD0CTL2STR.Bits.ETRIGE
    #define ATD0CTL2_ETRIGP _ATD0CTL23.Overlap_STR.ATD0CTL2STR.Bits.ETRIGP
    #define ATD0CTL2_ETRIGLE _ATD0CTL23.Overlap_STR.ATD0CTL2STR.Bits.ETRIGLE
    #define ATD0CTL2_AWAI _ATD0CTL23.Overlap_STR.ATD0CTL2STR.Bits.AWAI
    #define ATD0CTL2_AFFC _ATD0CTL23.Overlap_STR.ATD0CTL2STR.Bits.AFFC
    #define ATD0CTL2_ADPU _ATD0CTL23.Overlap_STR.ATD0CTL2STR.Bits.ADPU

    /*** ATD0CTL3 - ATD 0 Control Register 3; 0x00000083 ***/
    union {
      byte Byte;
      struct {
        byte FRZ0        :1;                                       /* Background Debug Freeze Enable */
        byte FRZ1        :1;                                       /* Background Debug Freeze Enable */
        byte FIFO        :1;                                       /* Result Register FIFO Mode */
        byte S1C         :1;                                       /* Conversion Sequence Length 1 */
        byte S2C         :1;                                       /* Conversion Sequence Length 2 */
        byte S4C         :1;                                       /* Conversion Sequence Length 4 */
        byte S8C         :1;                                       /* Conversion Sequence Length 8 */
        byte             :1;
      } Bits;
      struct {
        byte grpFRZ :2;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
      } MergedBits;
    } ATD0CTL3STR;
    #define ATD0CTL3 _ATD0CTL23.Overlap_STR.ATD0CTL3STR.Byte
    #define ATD0CTL3_FRZ0 _ATD0CTL23.Overlap_STR.ATD0CTL3STR.Bits.FRZ0
    #define ATD0CTL3_FRZ1 _ATD0CTL23.Overlap_STR.ATD0CTL3STR.Bits.FRZ1
    #define ATD0CTL3_FIFO _ATD0CTL23.Overlap_STR.ATD0CTL3STR.Bits.FIFO
    #define ATD0CTL3_S1C _ATD0CTL23.Overlap_STR.ATD0CTL3STR.Bits.S1C
    #define ATD0CTL3_S2C _ATD0CTL23.Overlap_STR.ATD0CTL3STR.Bits.S2C
    #define ATD0CTL3_S4C _ATD0CTL23.Overlap_STR.ATD0CTL3STR.Bits.S4C
    #define ATD0CTL3_S8C _ATD0CTL23.Overlap_STR.ATD0CTL3STR.Bits.S8C
    #define ATD0CTL3_FRZ _ATD0CTL23.Overlap_STR.ATD0CTL3STR.MergedBits.grpFRZ

  } Overlap_STR;

  struct {
    word FRZ0        :1;                                       /* Background Debug Freeze Enable */
    word FRZ1        :1;                                       /* Background Debug Freeze Enable */
    word FIFO        :1;                                       /* Result Register FIFO Mode */
    word S1C         :1;                                       /* Conversion Sequence Length 1 */
    word S2C         :1;                                       /* Conversion Sequence Length 2 */
    word S4C         :1;                                       /* Conversion Sequence Length 4 */
    word S8C         :1;                                       /* Conversion Sequence Length 8 */
    word             :1;
    word ASCIF       :1;                                       /* ATD 0 Sequence Complete Interrupt Flag */
    word ASCIE       :1;                                       /* ATD 0 Sequence Complete Interrupt Enable */
    word ETRIGE      :1;                                       /* External Trigger Mode enable */
    word ETRIGP      :1;                                       /* External Trigger Polarity */
    word ETRIGLE     :1;                                       /* External Trigger Level/Edge control */
    word AWAI        :1;                                       /* ATD 0 Wait Mode */
    word AFFC        :1;                                       /* ATD 0 Fast Conversion Complete Flag Clear */
    word ADPU        :1;                                       /* ATD 0 Disable / Power Down */
  } Bits;
  struct {
    word grpFRZ  :2;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
  } MergedBits;
} ATD0CTL23STR;
extern volatile ATD0CTL23STR _ATD0CTL23 @(REG_BASE + 0x00000082);
#define ATD0CTL23 _ATD0CTL23.Word
#define ATD0CTL23_FRZ0 _ATD0CTL23.Bits.FRZ0
#define ATD0CTL23_FRZ1 _ATD0CTL23.Bits.FRZ1
#define ATD0CTL23_FIFO _ATD0CTL23.Bits.FIFO
#define ATD0CTL23_S1C _ATD0CTL23.Bits.S1C
#define ATD0CTL23_S2C _ATD0CTL23.Bits.S2C
#define ATD0CTL23_S4C _ATD0CTL23.Bits.S4C
#define ATD0CTL23_S8C _ATD0CTL23.Bits.S8C
#define ATD0CTL23_ASCIF _ATD0CTL23.Bits.ASCIF
#define ATD0CTL23_ASCIE _ATD0CTL23.Bits.ASCIE
#define ATD0CTL23_ETRIGE _ATD0CTL23.Bits.ETRIGE
#define ATD0CTL23_ETRIGP _ATD0CTL23.Bits.ETRIGP
#define ATD0CTL23_ETRIGLE _ATD0CTL23.Bits.ETRIGLE
#define ATD0CTL23_AWAI _ATD0CTL23.Bits.AWAI
#define ATD0CTL23_AFFC _ATD0CTL23.Bits.AFFC
#define ATD0CTL23_ADPU _ATD0CTL23.Bits.ADPU
#define ATD0CTL23_FRZ _ATD0CTL23.MergedBits.grpFRZ


/*** ATD0CTL45 - ATD 0 Control Register 45; 0x00000084 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ATD0CTL4 - ATD 0 Control Register 4; 0x00000084 ***/
    union {
      byte Byte;
      struct {
        byte PRS0        :1;                                       /* ATD 0 Clock Prescaler 0 */
        byte PRS1        :1;                                       /* ATD 0 Clock Prescaler 1 */
        byte PRS2        :1;                                       /* ATD 0 Clock Prescaler 2 */
        byte PRS3        :1;                                       /* ATD 0 Clock Prescaler 3 */
        byte PRS4        :1;                                       /* ATD 0 Clock Prescaler 4 */
        byte SMP0        :1;                                       /* Sample Time Select 0 */
        byte SMP1        :1;                                       /* Sample Time Select 1 */
        byte SRES8       :1;                                       /* ATD 0 Resolution Select */
      } Bits;
      struct {
        byte grpPRS :5;
        byte grpSMP :2;
        byte grpSRES_8 :1;
      } MergedBits;
    } ATD0CTL4STR;
    #define ATD0CTL4 _ATD0CTL45.Overlap_STR.ATD0CTL4STR.Byte
    #define ATD0CTL4_PRS0 _ATD0CTL45.Overlap_STR.ATD0CTL4STR.Bits.PRS0
    #define ATD0CTL4_PRS1 _ATD0CTL45.Overlap_STR.ATD0CTL4STR.Bits.PRS1
    #define ATD0CTL4_PRS2 _ATD0CTL45.Overlap_STR.ATD0CTL4STR.Bits.PRS2
    #define ATD0CTL4_PRS3 _ATD0CTL45.Overlap_STR.ATD0CTL4STR.Bits.PRS3
    #define ATD0CTL4_PRS4 _ATD0CTL45.Overlap_STR.ATD0CTL4STR.Bits.PRS4
    #define ATD0CTL4_SMP0 _ATD0CTL45.Overlap_STR.ATD0CTL4STR.Bits.SMP0
    #define ATD0CTL4_SMP1 _ATD0CTL45.Overlap_STR.ATD0CTL4STR.Bits.SMP1
    #define ATD0CTL4_SRES8 _ATD0CTL45.Overlap_STR.ATD0CTL4STR.Bits.SRES8
    #define ATD0CTL4_PRS _ATD0CTL45.Overlap_STR.ATD0CTL4STR.MergedBits.grpPRS
    #define ATD0CTL4_SMP _ATD0CTL45.Overlap_STR.ATD0CTL4STR.MergedBits.grpSMP

    /*** ATD0CTL5 - ATD 0 Control Register 5; 0x00000085 ***/
    union {
      byte Byte;
      struct {
        byte CA          :1;                                       /* Analog Input Channel Select Code A */
        byte CB          :1;                                       /* Analog Input Channel Select Code B */
        byte CC          :1;                                       /* Analog Input Channel Select Code C */
        byte             :1;
        byte MULT        :1;                                       /* Multi-Channel Sample Mode */
        byte SCAN        :1;                                       /* Continuous Conversion Sequence Mode */
        byte DSGN        :1;                                       /* Signed/Unsigned Result Data Mode */
        byte DJM         :1;                                       /* Result Register Data Justification Mode */
      } Bits;
    } ATD0CTL5STR;
    #define ATD0CTL5 _ATD0CTL45.Overlap_STR.ATD0CTL5STR.Byte
    #define ATD0CTL5_CA _ATD0CTL45.Overlap_STR.ATD0CTL5STR.Bits.CA
    #define ATD0CTL5_CB _ATD0CTL45.Overlap_STR.ATD0CTL5STR.Bits.CB
    #define ATD0CTL5_CC _ATD0CTL45.Overlap_STR.ATD0CTL5STR.Bits.CC
    #define ATD0CTL5_MULT _ATD0CTL45.Overlap_STR.ATD0CTL5STR.Bits.MULT
    #define ATD0CTL5_SCAN _ATD0CTL45.Overlap_STR.ATD0CTL5STR.Bits.SCAN
    #define ATD0CTL5_DSGN _ATD0CTL45.Overlap_STR.ATD0CTL5STR.Bits.DSGN
    #define ATD0CTL5_DJM _ATD0CTL45.Overlap_STR.ATD0CTL5STR.Bits.DJM

  } Overlap_STR;

  struct {
    word CA          :1;                                       /* Analog Input Channel Select Code A */
    word CB          :1;                                       /* Analog Input Channel Select Code B */
    word CC          :1;                                       /* Analog Input Channel Select Code C */
    word             :1;
    word MULT        :1;                                       /* Multi-Channel Sample Mode */
    word SCAN        :1;                                       /* Continuous Conversion Sequence Mode */
    word DSGN        :1;                                       /* Signed/Unsigned Result Data Mode */
    word DJM         :1;                                       /* Result Register Data Justification Mode */
    word PRS0        :1;                                       /* ATD 0 Clock Prescaler 0 */
    word PRS1        :1;                                       /* ATD 0 Clock Prescaler 1 */
    word PRS2        :1;                                       /* ATD 0 Clock Prescaler 2 */
    word PRS3        :1;                                       /* ATD 0 Clock Prescaler 3 */
    word PRS4        :1;                                       /* ATD 0 Clock Prescaler 4 */
    word SMP0        :1;                                       /* Sample Time Select 0 */
    word SMP1        :1;                                       /* Sample Time Select 1 */
    word SRES8       :1;                                       /* ATD 0 Resolution Select */
  } Bits;
  struct {
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word grpPRS  :5;
    word grpSMP  :2;
    word grpSRES_8 :1;
  } MergedBits;
} ATD0CTL45STR;
extern volatile ATD0CTL45STR _ATD0CTL45 @(REG_BASE + 0x00000084);
#define ATD0CTL45 _ATD0CTL45.Word
#define ATD0CTL45_CA _ATD0CTL45.Bits.CA
#define ATD0CTL45_CB _ATD0CTL45.Bits.CB
#define ATD0CTL45_CC _ATD0CTL45.Bits.CC
#define ATD0CTL45_MULT _ATD0CTL45.Bits.MULT
#define ATD0CTL45_SCAN _ATD0CTL45.Bits.SCAN
#define ATD0CTL45_DSGN _ATD0CTL45.Bits.DSGN
#define ATD0CTL45_DJM _ATD0CTL45.Bits.DJM
#define ATD0CTL45_PRS0 _ATD0CTL45.Bits.PRS0
#define ATD0CTL45_PRS1 _ATD0CTL45.Bits.PRS1
#define ATD0CTL45_PRS2 _ATD0CTL45.Bits.PRS2
#define ATD0CTL45_PRS3 _ATD0CTL45.Bits.PRS3
#define ATD0CTL45_PRS4 _ATD0CTL45.Bits.PRS4
#define ATD0CTL45_SMP0 _ATD0CTL45.Bits.SMP0
#define ATD0CTL45_SMP1 _ATD0CTL45.Bits.SMP1
#define ATD0CTL45_SRES8 _ATD0CTL45.Bits.SRES8
#define ATD0CTL45_PRS _ATD0CTL45.MergedBits.grpPRS
#define ATD0CTL45_SMP _ATD0CTL45.MergedBits.grpSMP


/*** ATD0DR0 - ATD 0 Conversion Result Register 0; 0x00000090 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ATD0DR0H - ATD 0 Conversion Result Register 0 High; 0x00000090 ***/
    union {
      byte Byte;
      struct {
        byte BIT8        :1;                                       /* Bit 8 */
        byte BIT9        :1;                                       /* Bit 9 */
        byte BIT10       :1;                                       /* Bit 10 */
        byte BIT11       :1;                                       /* Bit 11 */
        byte BIT12       :1;                                       /* Bit 12 */
        byte BIT13       :1;                                       /* Bit 13 */
        byte BIT14       :1;                                       /* Bit 14 */
        byte BIT15       :1;                                       /* Bit 15 */
      } Bits;
      struct {
        byte grpBIT_8 :8;
      } MergedBits;
    } ATD0DR0HSTR;
    #define ATD0DR0H _ATD0DR0.Overlap_STR.ATD0DR0HSTR.Byte
    #define ATD0DR0H_BIT8 _ATD0DR0.Overlap_STR.ATD0DR0HSTR.Bits.BIT8
    #define ATD0DR0H_BIT9 _ATD0DR0.Overlap_STR.ATD0DR0HSTR.Bits.BIT9
    #define ATD0DR0H_BIT10 _ATD0DR0.Overlap_STR.ATD0DR0HSTR.Bits.BIT10
    #define ATD0DR0H_BIT11 _ATD0DR0.Overlap_STR.ATD0DR0HSTR.Bits.BIT11
    #define ATD0DR0H_BIT12 _ATD0DR0.Overlap_STR.ATD0DR0HSTR.Bits.BIT12
    #define ATD0DR0H_BIT13 _ATD0DR0.Overlap_STR.ATD0DR0HSTR.Bits.BIT13
    #define ATD0DR0H_BIT14 _ATD0DR0.Overlap_STR.ATD0DR0HSTR.Bits.BIT14
    #define ATD0DR0H_BIT15 _ATD0DR0.Overlap_STR.ATD0DR0HSTR.Bits.BIT15
    #define ATD0DR0H_BIT_8 _ATD0DR0.Overlap_STR.ATD0DR0HSTR.MergedBits.grpBIT_8
    #define ATD0DR0H_BIT ATD0DR0H_BIT_8

    /*** ATD0DR0L - ATD 0 Conversion Result Register 0 Low; 0x00000091 ***/
    union {
      byte Byte;
      struct {
        byte             :1;
        byte             :1;
        byte             :1;
        byte             :1;
        byte             :1;
        byte             :1;
        byte BIT6        :1;                                       /* Bit 6 */
        byte BIT7        :1;                                       /* Bit 7 */
      } Bits;
      struct {
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
        byte grpBIT_6 :2;
      } MergedBits;
    } ATD0DR0LSTR;
    #define ATD0DR0L _ATD0DR0.Overlap_STR.ATD0DR0LSTR.Byte
    #define ATD0DR0L_BIT6 _ATD0DR0.Overlap_STR.ATD0DR0LSTR.Bits.BIT6
    #define ATD0DR0L_BIT7 _ATD0DR0.Overlap_STR.ATD0DR0LSTR.Bits.BIT7
    #define ATD0DR0L_BIT_6 _ATD0DR0.Overlap_STR.ATD0DR0LSTR.MergedBits.grpBIT_6
    #define ATD0DR0L_BIT ATD0DR0L_BIT_6

  } Overlap_STR;

  struct {
    word             :1;
    word             :1;
    word             :1;
    word             :1;
    word             :1;
    word             :1;
    word BIT6        :1;                                       /* Bit 6 */
    word BIT7        :1;                                       /* Bit 7 */
    word BIT8        :1;                                       /* Bit 8 */
    word BIT9        :1;                                       /* Bit 9 */
    word BIT10       :1;                                       /* Bit 10 */
    word BIT11       :1;                                       /* Bit 11 */
    word BIT12       :1;                                       /* Bit 12 */
    word BIT13       :1;                                       /* Bit 13 */
    word BIT14       :1;                                       /* Bit 14 */
    word BIT15       :1;                                       /* Bit 15 */
  } Bits;
  struct {
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word grpBIT_6 :10;
  } MergedBits;
} ATD0DR0STR;
extern volatile ATD0DR0STR _ATD0DR0 @(REG_BASE + 0x00000090);
#define ATD0DR0 _ATD0DR0.Word
#define ATD0DR0_BIT6 _ATD0DR0.Bits.BIT6
#define ATD0DR0_BIT7 _ATD0DR0.Bits.BIT7
#define ATD0DR0_BIT8 _ATD0DR0.Bits.BIT8
#define ATD0DR0_BIT9 _ATD0DR0.Bits.BIT9
#define ATD0DR0_BIT10 _ATD0DR0.Bits.BIT10
#define ATD0DR0_BIT11 _ATD0DR0.Bits.BIT11
#define ATD0DR0_BIT12 _ATD0DR0.Bits.BIT12
#define ATD0DR0_BIT13 _ATD0DR0.Bits.BIT13
#define ATD0DR0_BIT14 _ATD0DR0.Bits.BIT14
#define ATD0DR0_BIT15 _ATD0DR0.Bits.BIT15
#define ATD0DR0_BIT_6 _ATD0DR0.MergedBits.grpBIT_6
#define ATD0DR0_BIT ATD0DR0_BIT_6


/*** ATD0DR1 - ATD 0 Conversion Result Register 1; 0x00000092 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ATD0DR1H - ATD 0 Conversion Result Register 1 High; 0x00000092 ***/
    union {
      byte Byte;
      struct {
        byte BIT8        :1;                                       /* Bit 8 */
        byte BIT9        :1;                                       /* Bit 9 */
        byte BIT10       :1;                                       /* Bit 10 */
        byte BIT11       :1;                                       /* Bit 11 */
        byte BIT12       :1;                                       /* Bit 12 */
        byte BIT13       :1;                                       /* Bit 13 */
        byte BIT14       :1;                                       /* Bit 14 */
        byte BIT15       :1;                                       /* Bit 15 */
      } Bits;
      struct {
        byte grpBIT_8 :8;
      } MergedBits;
    } ATD0DR1HSTR;
    #define ATD0DR1H _ATD0DR1.Overlap_STR.ATD0DR1HSTR.Byte
    #define ATD0DR1H_BIT8 _ATD0DR1.Overlap_STR.ATD0DR1HSTR.Bits.BIT8
    #define ATD0DR1H_BIT9 _ATD0DR1.Overlap_STR.ATD0DR1HSTR.Bits.BIT9
    #define ATD0DR1H_BIT10 _ATD0DR1.Overlap_STR.ATD0DR1HSTR.Bits.BIT10
    #define ATD0DR1H_BIT11 _ATD0DR1.Overlap_STR.ATD0DR1HSTR.Bits.BIT11
    #define ATD0DR1H_BIT12 _ATD0DR1.Overlap_STR.ATD0DR1HSTR.Bits.BIT12
    #define ATD0DR1H_BIT13 _ATD0DR1.Overlap_STR.ATD0DR1HSTR.Bits.BIT13
    #define ATD0DR1H_BIT14 _ATD0DR1.Overlap_STR.ATD0DR1HSTR.Bits.BIT14
    #define ATD0DR1H_BIT15 _ATD0DR1.Overlap_STR.ATD0DR1HSTR.Bits.BIT15
    #define ATD0DR1H_BIT_8 _ATD0DR1.Overlap_STR.ATD0DR1HSTR.MergedBits.grpBIT_8
    #define ATD0DR1H_BIT ATD0DR1H_BIT_8

    /*** ATD0DR1L - ATD 0 Conversion Result Register 1 Low; 0x00000093 ***/
    union {
      byte Byte;
      struct {
        byte             :1;
        byte             :1;
        byte             :1;
        byte             :1;
        byte             :1;
        byte             :1;
        byte BIT6        :1;                                       /* Bit 6 */
        byte BIT7        :1;                                       /* Bit 7 */
      } Bits;
      struct {
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
        byte grpBIT_6 :2;
      } MergedBits;
    } ATD0DR1LSTR;
    #define ATD0DR1L _ATD0DR1.Overlap_STR.ATD0DR1LSTR.Byte
    #define ATD0DR1L_BIT6 _ATD0DR1.Overlap_STR.ATD0DR1LSTR.Bits.BIT6
    #define ATD0DR1L_BIT7 _ATD0DR1.Overlap_STR.ATD0DR1LSTR.Bits.BIT7
    #define ATD0DR1L_BIT_6 _ATD0DR1.Overlap_STR.ATD0DR1LSTR.MergedBits.grpBIT_6
    #define ATD0DR1L_BIT ATD0DR1L_BIT_6

  } Overlap_STR;

  struct {
    word             :1;
    word             :1;
    word             :1;
    word             :1;
    word             :1;
    word             :1;
    word BIT6        :1;                                       /* Bit 6 */
    word BIT7        :1;                                       /* Bit 7 */
    word BIT8        :1;                                       /* Bit 8 */
    word BIT9        :1;                                       /* Bit 9 */
    word BIT10       :1;                                       /* Bit 10 */
    word BIT11       :1;                                       /* Bit 11 */
    word BIT12       :1;                                       /* Bit 12 */
    word BIT13       :1;                                       /* Bit 13 */
    word BIT14       :1;                                       /* Bit 14 */
    word BIT15       :1;                                       /* Bit 15 */
  } Bits;
  struct {
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word grpBIT_6 :10;
  } MergedBits;
} ATD0DR1STR;
extern volatile ATD0DR1STR _ATD0DR1 @(REG_BASE + 0x00000092);
#define ATD0DR1 _ATD0DR1.Word
#define ATD0DR1_BIT6 _ATD0DR1.Bits.BIT6
#define ATD0DR1_BIT7 _ATD0DR1.Bits.BIT7
#define ATD0DR1_BIT8 _ATD0DR1.Bits.BIT8
#define ATD0DR1_BIT9 _ATD0DR1.Bits.BIT9
#define ATD0DR1_BIT10 _ATD0DR1.Bits.BIT10
#define ATD0DR1_BIT11 _ATD0DR1.Bits.BIT11
#define ATD0DR1_BIT12 _ATD0DR1.Bits.BIT12
#define ATD0DR1_BIT13 _ATD0DR1.Bits.BIT13
#define ATD0DR1_BIT14 _ATD0DR1.Bits.BIT14
#define ATD0DR1_BIT15 _ATD0DR1.Bits.BIT15
#define ATD0DR1_BIT_6 _ATD0DR1.MergedBits.grpBIT_6
#define ATD0DR1_BIT ATD0DR1_BIT_6


/*** ATD0DR2 - ATD 0 Conversion Result Register 2; 0x00000094 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ATD0DR2H - ATD 0 Conversion Result Register 2 High; 0x00000094 ***/
    union {
      byte Byte;
      struct {
        byte BIT8        :1;                                       /* Bit 8 */
        byte BIT9        :1;                                       /* Bit 9 */
        byte BIT10       :1;                                       /* Bit 10 */
        byte BIT11       :1;                                       /* Bit 11 */
        byte BIT12       :1;                                       /* Bit 12 */
        byte BIT13       :1;                                       /* Bit 13 */
        byte BIT14       :1;                                       /* Bit 14 */
        byte BIT15       :1;                                       /* Bit 15 */
      } Bits;
      struct {
        byte grpBIT_8 :8;
      } MergedBits;
    } ATD0DR2HSTR;
    #define ATD0DR2H _ATD0DR2.Overlap_STR.ATD0DR2HSTR.Byte
    #define ATD0DR2H_BIT8 _ATD0DR2.Overlap_STR.ATD0DR2HSTR.Bits.BIT8
    #define ATD0DR2H_BIT9 _ATD0DR2.Overlap_STR.ATD0DR2HSTR.Bits.BIT9
    #define ATD0DR2H_BIT10 _ATD0DR2.Overlap_STR.ATD0DR2HSTR.Bits.BIT10
    #define ATD0DR2H_BIT11 _ATD0DR2.Overlap_STR.ATD0DR2HSTR.Bits.BIT11
    #define ATD0DR2H_BIT12 _ATD0DR2.Overlap_STR.ATD0DR2HSTR.Bits.BIT12
    #define ATD0DR2H_BIT13 _ATD0DR2.Overlap_STR.ATD0DR2HSTR.Bits.BIT13
    #define ATD0DR2H_BIT14 _ATD0DR2.Overlap_STR.ATD0DR2HSTR.Bits.BIT14
    #define ATD0DR2H_BIT15 _ATD0DR2.Overlap_STR.ATD0DR2HSTR.Bits.BIT15
    #define ATD0DR2H_BIT_8 _ATD0DR2.Overlap_STR.ATD0DR2HSTR.MergedBits.grpBIT_8
    #define ATD0DR2H_BIT ATD0DR2H_BIT_8

    /*** ATD0DR2L - ATD 0 Conversion Result Register 2 Low; 0x00000095 ***/
    union {
      byte Byte;
      struct {
        byte             :1;
        byte             :1;
        byte             :1;
        byte             :1;
        byte             :1;
        byte             :1;
        byte BIT6        :1;                                       /* Bit 6 */
        byte BIT7        :1;                                       /* Bit 7 */
      } Bits;
      struct {
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
        byte grpBIT_6 :2;
      } MergedBits;
    } ATD0DR2LSTR;
    #define ATD0DR2L _ATD0DR2.Overlap_STR.ATD0DR2LSTR.Byte
    #define ATD0DR2L_BIT6 _ATD0DR2.Overlap_STR.ATD0DR2LSTR.Bits.BIT6
    #define ATD0DR2L_BIT7 _ATD0DR2.Overlap_STR.ATD0DR2LSTR.Bits.BIT7
    #define ATD0DR2L_BIT_6 _ATD0DR2.Overlap_STR.ATD0DR2LSTR.MergedBits.grpBIT_6
    #define ATD0DR2L_BIT ATD0DR2L_BIT_6

  } Overlap_STR;

  struct {
    word             :1;
    word             :1;
    word             :1;
    word             :1;
    word             :1;
    word             :1;
    word BIT6        :1;                                       /* Bit 6 */
    word BIT7        :1;                                       /* Bit 7 */
    word BIT8        :1;                                       /* Bit 8 */
    word BIT9        :1;                                       /* Bit 9 */
    word BIT10       :1;                                       /* Bit 10 */
    word BIT11       :1;                                       /* Bit 11 */
    word BIT12       :1;                                       /* Bit 12 */
    word BIT13       :1;                                       /* Bit 13 */
    word BIT14       :1;                                       /* Bit 14 */
    word BIT15       :1;                                       /* Bit 15 */
  } Bits;
  struct {
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word grpBIT_6 :10;
  } MergedBits;
} ATD0DR2STR;
extern volatile ATD0DR2STR _ATD0DR2 @(REG_BASE + 0x00000094);
#define ATD0DR2 _ATD0DR2.Word
#define ATD0DR2_BIT6 _ATD0DR2.Bits.BIT6
#define ATD0DR2_BIT7 _ATD0DR2.Bits.BIT7
#define ATD0DR2_BIT8 _ATD0DR2.Bits.BIT8
#define ATD0DR2_BIT9 _ATD0DR2.Bits.BIT9
#define ATD0DR2_BIT10 _ATD0DR2.Bits.BIT10
#define ATD0DR2_BIT11 _ATD0DR2.Bits.BIT11
#define ATD0DR2_BIT12 _ATD0DR2.Bits.BIT12
#define ATD0DR2_BIT13 _ATD0DR2.Bits.BIT13
#define ATD0DR2_BIT14 _ATD0DR2.Bits.BIT14
#define ATD0DR2_BIT15 _ATD0DR2.Bits.BIT15
#define ATD0DR2_BIT_6 _ATD0DR2.MergedBits.grpBIT_6
#define ATD0DR2_BIT ATD0DR2_BIT_6


/*** ATD0DR3 - ATD 0 Conversion Result Register 3; 0x00000096 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ATD0DR3H - ATD 0 Conversion Result Register 3 High; 0x00000096 ***/
    union {
      byte Byte;
      struct {
        byte BIT8        :1;                                       /* Bit 8 */
        byte BIT9        :1;                                       /* Bit 9 */
        byte BIT10       :1;                                       /* Bit 10 */
        byte BIT11       :1;                                       /* Bit 11 */
        byte BIT12       :1;                                       /* Bit 12 */
        byte BIT13       :1;                                       /* Bit 13 */
        byte BIT14       :1;                                       /* Bit 14 */
        byte BIT15       :1;                                       /* Bit 15 */
      } Bits;
      struct {
        byte grpBIT_8 :8;
      } MergedBits;
    } ATD0DR3HSTR;
    #define ATD0DR3H _ATD0DR3.Overlap_STR.ATD0DR3HSTR.Byte
    #define ATD0DR3H_BIT8 _ATD0DR3.Overlap_STR.ATD0DR3HSTR.Bits.BIT8
    #define ATD0DR3H_BIT9 _ATD0DR3.Overlap_STR.ATD0DR3HSTR.Bits.BIT9
    #define ATD0DR3H_BIT10 _ATD0DR3.Overlap_STR.ATD0DR3HSTR.Bits.BIT10
    #define ATD0DR3H_BIT11 _ATD0DR3.Overlap_STR.ATD0DR3HSTR.Bits.BIT11
    #define ATD0DR3H_BIT12 _ATD0DR3.Overlap_STR.ATD0DR3HSTR.Bits.BIT12
    #define ATD0DR3H_BIT13 _ATD0DR3.Overlap_STR.ATD0DR3HSTR.Bits.BIT13
    #define ATD0DR3H_BIT14 _ATD0DR3.Overlap_STR.ATD0DR3HSTR.Bits.BIT14
    #define ATD0DR3H_BIT15 _ATD0DR3.Overlap_STR.ATD0DR3HSTR.Bits.BIT15
    #define ATD0DR3H_BIT_8 _ATD0DR3.Overlap_STR.ATD0DR3HSTR.MergedBits.grpBIT_8
    #define ATD0DR3H_BIT ATD0DR3H_BIT_8

    /*** ATD0DR3L - ATD 0 Conversion Result Register 3 Low; 0x00000097 ***/
    union {
      byte Byte;
      struct {
        byte             :1;
        byte             :1;
        byte             :1;
        byte             :1;
        byte             :1;
        byte             :1;
        byte BIT6        :1;                                       /* Bit 6 */
        byte BIT7        :1;                                       /* Bit 7 */
      } Bits;
      struct {
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
        byte grpBIT_6 :2;
      } MergedBits;
    } ATD0DR3LSTR;
    #define ATD0DR3L _ATD0DR3.Overlap_STR.ATD0DR3LSTR.Byte
    #define ATD0DR3L_BIT6 _ATD0DR3.Overlap_STR.ATD0DR3LSTR.Bits.BIT6
    #define ATD0DR3L_BIT7 _ATD0DR3.Overlap_STR.ATD0DR3LSTR.Bits.BIT7
    #define ATD0DR3L_BIT_6 _ATD0DR3.Overlap_STR.ATD0DR3LSTR.MergedBits.grpBIT_6
    #define ATD0DR3L_BIT ATD0DR3L_BIT_6

  } Overlap_STR;

  struct {
    word             :1;
    word             :1;
    word             :1;
    word             :1;
    word             :1;
    word             :1;
    word BIT6        :1;                                       /* Bit 6 */
    word BIT7        :1;                                       /* Bit 7 */
    word BIT8        :1;                                       /* Bit 8 */
    word BIT9        :1;                                       /* Bit 9 */
    word BIT10       :1;                                       /* Bit 10 */
    word BIT11       :1;                                       /* Bit 11 */
    word BIT12       :1;                                       /* Bit 12 */
    word BIT13       :1;                                       /* Bit 13 */
    word BIT14       :1;                                       /* Bit 14 */
    word BIT15       :1;                                       /* Bit 15 */
  } Bits;
  struct {
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word grpBIT_6 :10;
  } MergedBits;
} ATD0DR3STR;
extern volatile ATD0DR3STR _ATD0DR3 @(REG_BASE + 0x00000096);
#define ATD0DR3 _ATD0DR3.Word
#define ATD0DR3_BIT6 _ATD0DR3.Bits.BIT6
#define ATD0DR3_BIT7 _ATD0DR3.Bits.BIT7
#define ATD0DR3_BIT8 _ATD0DR3.Bits.BIT8
#define ATD0DR3_BIT9 _ATD0DR3.Bits.BIT9
#define ATD0DR3_BIT10 _ATD0DR3.Bits.BIT10
#define ATD0DR3_BIT11 _ATD0DR3.Bits.BIT11
#define ATD0DR3_BIT12 _ATD0DR3.Bits.BIT12
#define ATD0DR3_BIT13 _ATD0DR3.Bits.BIT13
#define ATD0DR3_BIT14 _ATD0DR3.Bits.BIT14
#define ATD0DR3_BIT15 _ATD0DR3.Bits.BIT15
#define ATD0DR3_BIT_6 _ATD0DR3.MergedBits.grpBIT_6
#define ATD0DR3_BIT ATD0DR3_BIT_6


/*** ATD0DR4 - ATD 0 Conversion Result Register 4; 0x00000098 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ATD0DR4H - ATD 0 Conversion Result Register 4 High; 0x00000098 ***/
    union {
      byte Byte;
      struct {
        byte BIT8        :1;                                       /* Bit 8 */
        byte BIT9        :1;                                       /* Bit 9 */
        byte BIT10       :1;                                       /* Bit 10 */
        byte BIT11       :1;                                       /* Bit 11 */
        byte BIT12       :1;                                       /* Bit 12 */
        byte BIT13       :1;                                       /* Bit 13 */
        byte BIT14       :1;                                       /* Bit 14 */
        byte BIT15       :1;                                       /* Bit 15 */
      } Bits;
      struct {
        byte grpBIT_8 :8;
      } MergedBits;
    } ATD0DR4HSTR;
    #define ATD0DR4H _ATD0DR4.Overlap_STR.ATD0DR4HSTR.Byte
    #define ATD0DR4H_BIT8 _ATD0DR4.Overlap_STR.ATD0DR4HSTR.Bits.BIT8
    #define ATD0DR4H_BIT9 _ATD0DR4.Overlap_STR.ATD0DR4HSTR.Bits.BIT9
    #define ATD0DR4H_BIT10 _ATD0DR4.Overlap_STR.ATD0DR4HSTR.Bits.BIT10
    #define ATD0DR4H_BIT11 _ATD0DR4.Overlap_STR.ATD0DR4HSTR.Bits.BIT11
    #define ATD0DR4H_BIT12 _ATD0DR4.Overlap_STR.ATD0DR4HSTR.Bits.BIT12
    #define ATD0DR4H_BIT13 _ATD0DR4.Overlap_STR.ATD0DR4HSTR.Bits.BIT13
    #define ATD0DR4H_BIT14 _ATD0DR4.Overlap_STR.ATD0DR4HSTR.Bits.BIT14
    #define ATD0DR4H_BIT15 _ATD0DR4.Overlap_STR.ATD0DR4HSTR.Bits.BIT15
    #define ATD0DR4H_BIT_8 _ATD0DR4.Overlap_STR.ATD0DR4HSTR.MergedBits.grpBIT_8
    #define ATD0DR4H_BIT ATD0DR4H_BIT_8

    /*** ATD0DR4L - ATD 0 Conversion Result Register 4 Low; 0x00000099 ***/
    union {
      byte Byte;
      struct {
        byte             :1;
        byte             :1;
        byte             :1;
        byte             :1;
        byte             :1;
        byte             :1;
        byte BIT6        :1;                                       /* Bit 6 */
        byte BIT7        :1;                                       /* Bit 7 */
      } Bits;
      struct {
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
        byte grpBIT_6 :2;
      } MergedBits;
    } ATD0DR4LSTR;
    #define ATD0DR4L _ATD0DR4.Overlap_STR.ATD0DR4LSTR.Byte
    #define ATD0DR4L_BIT6 _ATD0DR4.Overlap_STR.ATD0DR4LSTR.Bits.BIT6
    #define ATD0DR4L_BIT7 _ATD0DR4.Overlap_STR.ATD0DR4LSTR.Bits.BIT7
    #define ATD0DR4L_BIT_6 _ATD0DR4.Overlap_STR.ATD0DR4LSTR.MergedBits.grpBIT_6
    #define ATD0DR4L_BIT ATD0DR4L_BIT_6

  } Overlap_STR;

  struct {
    word             :1;
    word             :1;
    word             :1;
    word             :1;
    word             :1;
    word             :1;
    word BIT6        :1;                                       /* Bit 6 */
    word BIT7        :1;                                       /* Bit 7 */
    word BIT8        :1;                                       /* Bit 8 */
    word BIT9        :1;                                       /* Bit 9 */
    word BIT10       :1;                                       /* Bit 10 */
    word BIT11       :1;                                       /* Bit 11 */
    word BIT12       :1;                                       /* Bit 12 */
    word BIT13       :1;                                       /* Bit 13 */
    word BIT14       :1;                                       /* Bit 14 */
    word BIT15       :1;                                       /* Bit 15 */
  } Bits;
  struct {
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word grpBIT_6 :10;
  } MergedBits;
} ATD0DR4STR;
extern volatile ATD0DR4STR _ATD0DR4 @(REG_BASE + 0x00000098);
#define ATD0DR4 _ATD0DR4.Word
#define ATD0DR4_BIT6 _ATD0DR4.Bits.BIT6
#define ATD0DR4_BIT7 _ATD0DR4.Bits.BIT7
#define ATD0DR4_BIT8 _ATD0DR4.Bits.BIT8
#define ATD0DR4_BIT9 _ATD0DR4.Bits.BIT9
#define ATD0DR4_BIT10 _ATD0DR4.Bits.BIT10
#define ATD0DR4_BIT11 _ATD0DR4.Bits.BIT11
#define ATD0DR4_BIT12 _ATD0DR4.Bits.BIT12
#define ATD0DR4_BIT13 _ATD0DR4.Bits.BIT13
#define ATD0DR4_BIT14 _ATD0DR4.Bits.BIT14
#define ATD0DR4_BIT15 _ATD0DR4.Bits.BIT15
#define ATD0DR4_BIT_6 _ATD0DR4.MergedBits.grpBIT_6
#define ATD0DR4_BIT ATD0DR4_BIT_6


/*** ATD0DR5 - ATD 0 Conversion Result Register 5; 0x0000009A ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ATD0DR5H - ATD 0 Conversion Result Register 5 High; 0x0000009A ***/
    union {
      byte Byte;
      struct {
        byte BIT8        :1;                                       /* Bit 8 */
        byte BIT9        :1;                                       /* Bit 9 */
        byte BIT10       :1;                                       /* Bit 10 */
        byte BIT11       :1;                                       /* Bit 11 */
        byte BIT12       :1;                                       /* Bit 12 */
        byte BIT13       :1;                                       /* Bit 13 */
        byte BIT14       :1;                                       /* Bit 14 */
        byte BIT15       :1;                                       /* Bit 15 */
      } Bits;
      struct {
        byte grpBIT_8 :8;
      } MergedBits;
    } ATD0DR5HSTR;
    #define ATD0DR5H _ATD0DR5.Overlap_STR.ATD0DR5HSTR.Byte
    #define ATD0DR5H_BIT8 _ATD0DR5.Overlap_STR.ATD0DR5HSTR.Bits.BIT8
    #define ATD0DR5H_BIT9 _ATD0DR5.Overlap_STR.ATD0DR5HSTR.Bits.BIT9
    #define ATD0DR5H_BIT10 _ATD0DR5.Overlap_STR.ATD0DR5HSTR.Bits.BIT10
    #define ATD0DR5H_BIT11 _ATD0DR5.Overlap_STR.ATD0DR5HSTR.Bits.BIT11
    #define ATD0DR5H_BIT12 _ATD0DR5.Overlap_STR.ATD0DR5HSTR.Bits.BIT12
    #define ATD0DR5H_BIT13 _ATD0DR5.Overlap_STR.ATD0DR5HSTR.Bits.BIT13
    #define ATD0DR5H_BIT14 _ATD0DR5.Overlap_STR.ATD0DR5HSTR.Bits.BIT14
    #define ATD0DR5H_BIT15 _ATD0DR5.Overlap_STR.ATD0DR5HSTR.Bits.BIT15
    #define ATD0DR5H_BIT_8 _ATD0DR5.Overlap_STR.ATD0DR5HSTR.MergedBits.grpBIT_8
    #define ATD0DR5H_BIT ATD0DR5H_BIT_8

    /*** ATD0DR5L - ATD 0 Conversion Result Register 5 Low; 0x0000009B ***/
    union {
      byte Byte;
      struct {
        byte             :1;
        byte             :1;
        byte             :1;
        byte             :1;
        byte             :1;
        byte             :1;
        byte BIT6        :1;                                       /* Bit 6 */
        byte BIT7        :1;                                       /* Bit 7 */
      } Bits;
      struct {
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
        byte grpBIT_6 :2;
      } MergedBits;
    } ATD0DR5LSTR;
    #define ATD0DR5L _ATD0DR5.Overlap_STR.ATD0DR5LSTR.Byte
    #define ATD0DR5L_BIT6 _ATD0DR5.Overlap_STR.ATD0DR5LSTR.Bits.BIT6
    #define ATD0DR5L_BIT7 _ATD0DR5.Overlap_STR.ATD0DR5LSTR.Bits.BIT7
    #define ATD0DR5L_BIT_6 _ATD0DR5.Overlap_STR.ATD0DR5LSTR.MergedBits.grpBIT_6
    #define ATD0DR5L_BIT ATD0DR5L_BIT_6

  } Overlap_STR;

  struct {
    word             :1;
    word             :1;
    word             :1;
    word             :1;
    word             :1;
    word             :1;
    word BIT6        :1;                                       /* Bit 6 */
    word BIT7        :1;                                       /* Bit 7 */
    word BIT8        :1;                                       /* Bit 8 */
    word BIT9        :1;                                       /* Bit 9 */
    word BIT10       :1;                                       /* Bit 10 */
    word BIT11       :1;                                       /* Bit 11 */
    word BIT12       :1;                                       /* Bit 12 */
    word BIT13       :1;                                       /* Bit 13 */
    word BIT14       :1;                                       /* Bit 14 */
    word BIT15       :1;                                       /* Bit 15 */
  } Bits;
  struct {
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word grpBIT_6 :10;
  } MergedBits;
} ATD0DR5STR;
extern volatile ATD0DR5STR _ATD0DR5 @(REG_BASE + 0x0000009A);
#define ATD0DR5 _ATD0DR5.Word
#define ATD0DR5_BIT6 _ATD0DR5.Bits.BIT6
#define ATD0DR5_BIT7 _ATD0DR5.Bits.BIT7
#define ATD0DR5_BIT8 _ATD0DR5.Bits.BIT8
#define ATD0DR5_BIT9 _ATD0DR5.Bits.BIT9
#define ATD0DR5_BIT10 _ATD0DR5.Bits.BIT10
#define ATD0DR5_BIT11 _ATD0DR5.Bits.BIT11
#define ATD0DR5_BIT12 _ATD0DR5.Bits.BIT12
#define ATD0DR5_BIT13 _ATD0DR5.Bits.BIT13
#define ATD0DR5_BIT14 _ATD0DR5.Bits.BIT14
#define ATD0DR5_BIT15 _ATD0DR5.Bits.BIT15
#define ATD0DR5_BIT_6 _ATD0DR5.MergedBits.grpBIT_6
#define ATD0DR5_BIT ATD0DR5_BIT_6


/*** ATD0DR6 - ATD 0 Conversion Result Register 6; 0x0000009C ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ATD0DR6H - ATD 0 Conversion Result Register 6 High; 0x0000009C ***/
    union {
      byte Byte;
      struct {
        byte BIT8        :1;                                       /* Bit 8 */
        byte BIT9        :1;                                       /* Bit 9 */
        byte BIT10       :1;                                       /* Bit 10 */
        byte BIT11       :1;                                       /* Bit 11 */
        byte BIT12       :1;                                       /* Bit 12 */
        byte BIT13       :1;                                       /* Bit 13 */
        byte BIT14       :1;                                       /* Bit 14 */
        byte BIT15       :1;                                       /* Bit 15 */
      } Bits;
      struct {
        byte grpBIT_8 :8;
      } MergedBits;
    } ATD0DR6HSTR;
    #define ATD0DR6H _ATD0DR6.Overlap_STR.ATD0DR6HSTR.Byte
    #define ATD0DR6H_BIT8 _ATD0DR6.Overlap_STR.ATD0DR6HSTR.Bits.BIT8
    #define ATD0DR6H_BIT9 _ATD0DR6.Overlap_STR.ATD0DR6HSTR.Bits.BIT9
    #define ATD0DR6H_BIT10 _ATD0DR6.Overlap_STR.ATD0DR6HSTR.Bits.BIT10
    #define ATD0DR6H_BIT11 _ATD0DR6.Overlap_STR.ATD0DR6HSTR.Bits.BIT11
    #define ATD0DR6H_BIT12 _ATD0DR6.Overlap_STR.ATD0DR6HSTR.Bits.BIT12
    #define ATD0DR6H_BIT13 _ATD0DR6.Overlap_STR.ATD0DR6HSTR.Bits.BIT13
    #define ATD0DR6H_BIT14 _ATD0DR6.Overlap_STR.ATD0DR6HSTR.Bits.BIT14
    #define ATD0DR6H_BIT15 _ATD0DR6.Overlap_STR.ATD0DR6HSTR.Bits.BIT15
    #define ATD0DR6H_BIT_8 _ATD0DR6.Overlap_STR.ATD0DR6HSTR.MergedBits.grpBIT_8
    #define ATD0DR6H_BIT ATD0DR6H_BIT_8

    /*** ATD0DR6L - ATD 0 Conversion Result Register 6 Low; 0x0000009D ***/
    union {
      byte Byte;
      struct {
        byte             :1;
        byte             :1;
        byte             :1;
        byte             :1;
        byte             :1;
        byte             :1;
        byte BIT6        :1;                                       /* Bit 6 */
        byte BIT7        :1;                                       /* Bit 7 */
      } Bits;
      struct {
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
        byte grpBIT_6 :2;
      } MergedBits;
    } ATD0DR6LSTR;
    #define ATD0DR6L _ATD0DR6.Overlap_STR.ATD0DR6LSTR.Byte
    #define ATD0DR6L_BIT6 _ATD0DR6.Overlap_STR.ATD0DR6LSTR.Bits.BIT6
    #define ATD0DR6L_BIT7 _ATD0DR6.Overlap_STR.ATD0DR6LSTR.Bits.BIT7
    #define ATD0DR6L_BIT_6 _ATD0DR6.Overlap_STR.ATD0DR6LSTR.MergedBits.grpBIT_6
    #define ATD0DR6L_BIT ATD0DR6L_BIT_6

  } Overlap_STR;

  struct {
    word             :1;
    word             :1;
    word             :1;
    word             :1;
    word             :1;
    word             :1;
    word BIT6        :1;                                       /* Bit 6 */
    word BIT7        :1;                                       /* Bit 7 */
    word BIT8        :1;                                       /* Bit 8 */
    word BIT9        :1;                                       /* Bit 9 */
    word BIT10       :1;                                       /* Bit 10 */
    word BIT11       :1;                                       /* Bit 11 */
    word BIT12       :1;                                       /* Bit 12 */
    word BIT13       :1;                                       /* Bit 13 */
    word BIT14       :1;                                       /* Bit 14 */
    word BIT15       :1;                                       /* Bit 15 */
  } Bits;
  struct {
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word grpBIT_6 :10;
  } MergedBits;
} ATD0DR6STR;
extern volatile ATD0DR6STR _ATD0DR6 @(REG_BASE + 0x0000009C);
#define ATD0DR6 _ATD0DR6.Word
#define ATD0DR6_BIT6 _ATD0DR6.Bits.BIT6
#define ATD0DR6_BIT7 _ATD0DR6.Bits.BIT7
#define ATD0DR6_BIT8 _ATD0DR6.Bits.BIT8
#define ATD0DR6_BIT9 _ATD0DR6.Bits.BIT9
#define ATD0DR6_BIT10 _ATD0DR6.Bits.BIT10
#define ATD0DR6_BIT11 _ATD0DR6.Bits.BIT11
#define ATD0DR6_BIT12 _ATD0DR6.Bits.BIT12
#define ATD0DR6_BIT13 _ATD0DR6.Bits.BIT13
#define ATD0DR6_BIT14 _ATD0DR6.Bits.BIT14
#define ATD0DR6_BIT15 _ATD0DR6.Bits.BIT15
#define ATD0DR6_BIT_6 _ATD0DR6.MergedBits.grpBIT_6
#define ATD0DR6_BIT ATD0DR6_BIT_6


/*** ATD0DR7 - ATD 0 Conversion Result Register 7; 0x0000009E ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ATD0DR7H - ATD 0 Conversion Result Register 7 High; 0x0000009E ***/
    union {
      byte Byte;
      struct {
        byte BIT8        :1;                                       /* Bit 8 */
        byte BIT9        :1;                                       /* Bit 9 */
        byte BIT10       :1;                                       /* Bit 10 */
        byte BIT11       :1;                                       /* Bit 11 */
        byte BIT12       :1;                                       /* Bit 12 */
        byte BIT13       :1;                                       /* Bit 13 */
        byte BIT14       :1;                                       /* Bit 14 */
        byte BIT15       :1;                                       /* Bit 15 */
      } Bits;
      struct {
        byte grpBIT_8 :8;
      } MergedBits;
    } ATD0DR7HSTR;
    #define ATD0DR7H _ATD0DR7.Overlap_STR.ATD0DR7HSTR.Byte
    #define ATD0DR7H_BIT8 _ATD0DR7.Overlap_STR.ATD0DR7HSTR.Bits.BIT8
    #define ATD0DR7H_BIT9 _ATD0DR7.Overlap_STR.ATD0DR7HSTR.Bits.BIT9
    #define ATD0DR7H_BIT10 _ATD0DR7.Overlap_STR.ATD0DR7HSTR.Bits.BIT10
    #define ATD0DR7H_BIT11 _ATD0DR7.Overlap_STR.ATD0DR7HSTR.Bits.BIT11
    #define ATD0DR7H_BIT12 _ATD0DR7.Overlap_STR.ATD0DR7HSTR.Bits.BIT12
    #define ATD0DR7H_BIT13 _ATD0DR7.Overlap_STR.ATD0DR7HSTR.Bits.BIT13
    #define ATD0DR7H_BIT14 _ATD0DR7.Overlap_STR.ATD0DR7HSTR.Bits.BIT14
    #define ATD0DR7H_BIT15 _ATD0DR7.Overlap_STR.ATD0DR7HSTR.Bits.BIT15
    #define ATD0DR7H_BIT_8 _ATD0DR7.Overlap_STR.ATD0DR7HSTR.MergedBits.grpBIT_8
    #define ATD0DR7H_BIT ATD0DR7H_BIT_8

    /*** ATD0DR7L - ATD 0 Conversion Result Register 7 Low; 0x0000009F ***/
    union {
      byte Byte;
      struct {
        byte             :1;
        byte             :1;
        byte             :1;
        byte             :1;
        byte             :1;
        byte             :1;
        byte BIT6        :1;                                       /* Bit 6 */
        byte BIT7        :1;                                       /* Bit 7 */
      } Bits;
      struct {
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
        byte grpBIT_6 :2;
      } MergedBits;
    } ATD0DR7LSTR;
    #define ATD0DR7L _ATD0DR7.Overlap_STR.ATD0DR7LSTR.Byte
    #define ATD0DR7L_BIT6 _ATD0DR7.Overlap_STR.ATD0DR7LSTR.Bits.BIT6
    #define ATD0DR7L_BIT7 _ATD0DR7.Overlap_STR.ATD0DR7LSTR.Bits.BIT7
    #define ATD0DR7L_BIT_6 _ATD0DR7.Overlap_STR.ATD0DR7LSTR.MergedBits.grpBIT_6
    #define ATD0DR7L_BIT ATD0DR7L_BIT_6

  } Overlap_STR;

  struct {
    word             :1;
    word             :1;
    word             :1;
    word             :1;
    word             :1;
    word             :1;
    word BIT6        :1;                                       /* Bit 6 */
    word BIT7        :1;                                       /* Bit 7 */
    word BIT8        :1;                                       /* Bit 8 */
    word BIT9        :1;                                       /* Bit 9 */
    word BIT10       :1;                                       /* Bit 10 */
    word BIT11       :1;                                       /* Bit 11 */
    word BIT12       :1;                                       /* Bit 12 */
    word BIT13       :1;                                       /* Bit 13 */
    word BIT14       :1;                                       /* Bit 14 */
    word BIT15       :1;                                       /* Bit 15 */
  } Bits;
  struct {
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word grpBIT_6 :10;
  } MergedBits;
} ATD0DR7STR;
extern volatile ATD0DR7STR _ATD0DR7 @(REG_BASE + 0x0000009E);
#define ATD0DR7 _ATD0DR7.Word
#define ATD0DR7_BIT6 _ATD0DR7.Bits.BIT6
#define ATD0DR7_BIT7 _ATD0DR7.Bits.BIT7
#define ATD0DR7_BIT8 _ATD0DR7.Bits.BIT8
#define ATD0DR7_BIT9 _ATD0DR7.Bits.BIT9
#define ATD0DR7_BIT10 _ATD0DR7.Bits.BIT10
#define ATD0DR7_BIT11 _ATD0DR7.Bits.BIT11
#define ATD0DR7_BIT12 _ATD0DR7.Bits.BIT12
#define ATD0DR7_BIT13 _ATD0DR7.Bits.BIT13
#define ATD0DR7_BIT14 _ATD0DR7.Bits.BIT14
#define ATD0DR7_BIT15 _ATD0DR7.Bits.BIT15
#define ATD0DR7_BIT_6 _ATD0DR7.MergedBits.grpBIT_6
#define ATD0DR7_BIT ATD0DR7_BIT_6


/*** SCI0BD - SCI 0 Baud Rate Register; 0x000000C8 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** SCI0BDH - SCI 0 Baud Rate Register High; 0x000000C8 ***/
    union {
      byte Byte;
      struct {
        byte SBR8        :1;                                       /* SCI 0 baud rate Bit 8 */
        byte SBR9        :1;                                       /* SCI 0 baud rate Bit 9 */
        byte SBR10       :1;                                       /* SCI 0 baud rate Bit 10 */
        byte SBR11       :1;                                       /* SCI 0 baud rate Bit 11 */
        byte SBR12       :1;                                       /* SCI 0 baud rate Bit 12 */
        byte             :1;
        byte             :1;
        byte             :1;
      } Bits;
      struct {
        byte grpSBR_8 :5;
        byte     :1;
        byte     :1;
        byte     :1;
      } MergedBits;
    } SCI0BDHSTR;
    #define SCI0BDH _SCI0BD.Overlap_STR.SCI0BDHSTR.Byte
    #define SCI0BDH_SBR8 _SCI0BD.Overlap_STR.SCI0BDHSTR.Bits.SBR8
    #define SCI0BDH_SBR9 _SCI0BD.Overlap_STR.SCI0BDHSTR.Bits.SBR9
    #define SCI0BDH_SBR10 _SCI0BD.Overlap_STR.SCI0BDHSTR.Bits.SBR10
    #define SCI0BDH_SBR11 _SCI0BD.Overlap_STR.SCI0BDHSTR.Bits.SBR11
    #define SCI0BDH_SBR12 _SCI0BD.Overlap_STR.SCI0BDHSTR.Bits.SBR12
    #define SCI0BDH_SBR_8 _SCI0BD.Overlap_STR.SCI0BDHSTR.MergedBits.grpSBR_8
    #define SCI0BDH_SBR SCI0BDH_SBR_8

    /*** SCI0BDL - SCI 0 Baud Rate Register Low; 0x000000C9 ***/
    union {
      byte Byte;
      struct {
        byte SBR0        :1;                                       /* SCI 0 baud rate Bit 0 */
        byte SBR1        :1;                                       /* SCI 0 baud rate Bit 1 */
        byte SBR2        :1;                                       /* SCI 0 baud rate Bit 2 */
        byte SBR3        :1;                                       /* SCI 0 baud rate Bit 3 */
        byte SBR4        :1;                                       /* SCI 0 baud rate Bit 4 */
        byte SBR5        :1;                                       /* SCI 0 baud rate Bit 5 */
        byte SBR6        :1;                                       /* SCI 0 baud rate Bit 6 */
        byte SBR7        :1;                                       /* SCI 0 baud rate Bit 7 */
      } Bits;
      struct {
        byte grpSBR :8;
      } MergedBits;
    } SCI0BDLSTR;
    #define SCI0BDL _SCI0BD.Overlap_STR.SCI0BDLSTR.Byte
    #define SCI0BDL_SBR0 _SCI0BD.Overlap_STR.SCI0BDLSTR.Bits.SBR0
    #define SCI0BDL_SBR1 _SCI0BD.Overlap_STR.SCI0BDLSTR.Bits.SBR1
    #define SCI0BDL_SBR2 _SCI0BD.Overlap_STR.SCI0BDLSTR.Bits.SBR2
    #define SCI0BDL_SBR3 _SCI0BD.Overlap_STR.SCI0BDLSTR.Bits.SBR3
    #define SCI0BDL_SBR4 _SCI0BD.Overlap_STR.SCI0BDLSTR.Bits.SBR4
    #define SCI0BDL_SBR5 _SCI0BD.Overlap_STR.SCI0BDLSTR.Bits.SBR5
    #define SCI0BDL_SBR6 _SCI0BD.Overlap_STR.SCI0BDLSTR.Bits.SBR6
    #define SCI0BDL_SBR7 _SCI0BD.Overlap_STR.SCI0BDLSTR.Bits.SBR7
    #define SCI0BDL_SBR _SCI0BD.Overlap_STR.SCI0BDLSTR.MergedBits.grpSBR

  } Overlap_STR;

  struct {
    word SBR0        :1;                                       /* SCI 0 baud rate Bit 0 */
    word SBR1        :1;                                       /* SCI 0 baud rate Bit 1 */
    word SBR2        :1;                                       /* SCI 0 baud rate Bit 2 */
    word SBR3        :1;                                       /* SCI 0 baud rate Bit 3 */
    word SBR4        :1;                                       /* SCI 0 baud rate Bit 4 */
    word SBR5        :1;                                       /* SCI 0 baud rate Bit 5 */
    word SBR6        :1;                                       /* SCI 0 baud rate Bit 6 */
    word SBR7        :1;                                       /* SCI 0 baud rate Bit 7 */
    word SBR8        :1;                                       /* SCI 0 baud rate Bit 8 */
    word SBR9        :1;                                       /* SCI 0 baud rate Bit 9 */
    word SBR10       :1;                                       /* SCI 0 baud rate Bit 10 */
    word SBR11       :1;                                       /* SCI 0 baud rate Bit 11 */
    word SBR12       :1;                                       /* SCI 0 baud rate Bit 12 */
    word             :1;
    word             :1;
    word             :1;
  } Bits;
  struct {
    word grpSBR  :13;
    word         :1;
    word         :1;
    word         :1;
  } MergedBits;
} SCI0BDSTR;
extern volatile SCI0BDSTR _SCI0BD @(REG_BASE + 0x000000C8);
#define SCI0BD _SCI0BD.Word
#define SCI0BD_SBR0 _SCI0BD.Bits.SBR0
#define SCI0BD_SBR1 _SCI0BD.Bits.SBR1
#define SCI0BD_SBR2 _SCI0BD.Bits.SBR2
#define SCI0BD_SBR3 _SCI0BD.Bits.SBR3
#define SCI0BD_SBR4 _SCI0BD.Bits.SBR4
#define SCI0BD_SBR5 _SCI0BD.Bits.SBR5
#define SCI0BD_SBR6 _SCI0BD.Bits.SBR6
#define SCI0BD_SBR7 _SCI0BD.Bits.SBR7
#define SCI0BD_SBR8 _SCI0BD.Bits.SBR8
#define SCI0BD_SBR9 _SCI0BD.Bits.SBR9
#define SCI0BD_SBR10 _SCI0BD.Bits.SBR10
#define SCI0BD_SBR11 _SCI0BD.Bits.SBR11
#define SCI0BD_SBR12 _SCI0BD.Bits.SBR12
#define SCI0BD_SBR _SCI0BD.MergedBits.grpSBR


/*** PORTE - Port E Register; 0x00000008 ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* Port E Bit 0, XIRQ */
    byte BIT1        :1;                                       /* Port E Bit 1, IRQ */
    byte BIT2        :1;                                       /* Port E Bit 2, R/W */
    byte BIT3        :1;                                       /* Port E Bit 3, LSTRB, TAGLO */
    byte BIT4        :1;                                       /* Port E Bit 4, ECLK */
    byte BIT5        :1;                                       /* Port E Bit 5, MODA, IPIPE0, RCRTO */
    byte BIT6        :1;                                       /* Port E Bit 6, MODB, IPIPE1, SCGTO */
    byte BIT7        :1;                                       /* Port E Bit 7, XCLKS, NOACC */
  } Bits;
  struct {
    byte grpBIT  :8;
  } MergedBits;
} PORTESTR;
extern volatile PORTESTR _PORTE @(REG_BASE + 0x00000008);
#define PORTE _PORTE.Byte
#define PORTE_BIT0 _PORTE.Bits.BIT0
#define PORTE_BIT1 _PORTE.Bits.BIT1
#define PORTE_BIT2 _PORTE.Bits.BIT2
#define PORTE_BIT3 _PORTE.Bits.BIT3
#define PORTE_BIT4 _PORTE.Bits.BIT4
#define PORTE_BIT5 _PORTE.Bits.BIT5
#define PORTE_BIT6 _PORTE.Bits.BIT6
#define PORTE_BIT7 _PORTE.Bits.BIT7
#define PORTE_BIT _PORTE.MergedBits.grpBIT


/*** DDRE - Port E Data Direction Register; 0x00000009 ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* Data Direction Port A Bit 0 */
    byte BIT1        :1;                                       /* Data Direction Port A Bit 1 */
    byte BIT2        :1;                                       /* Data Direction Port A Bit 2 */
    byte BIT3        :1;                                       /* Data Direction Port A Bit 3 */
    byte BIT4        :1;                                       /* Data Direction Port A Bit 4 */
    byte BIT5        :1;                                       /* Data Direction Port A Bit 5 */
    byte BIT6        :1;                                       /* Data Direction Port A Bit 6 */
    byte BIT7        :1;                                       /* Data Direction Port A Bit 7 */
  } Bits;
  struct {
    byte grpBIT  :8;
  } MergedBits;
} DDRESTR;
extern volatile DDRESTR _DDRE @(REG_BASE + 0x00000009);
#define DDRE _DDRE.Byte
#define DDRE_BIT0 _DDRE.Bits.BIT0
#define DDRE_BIT1 _DDRE.Bits.BIT1
#define DDRE_BIT2 _DDRE.Bits.BIT2
#define DDRE_BIT3 _DDRE.Bits.BIT3
#define DDRE_BIT4 _DDRE.Bits.BIT4
#define DDRE_BIT5 _DDRE.Bits.BIT5
#define DDRE_BIT6 _DDRE.Bits.BIT6
#define DDRE_BIT7 _DDRE.Bits.BIT7
#define DDRE_BIT _DDRE.MergedBits.grpBIT


/*** PEAR - Port E Assignment Register; 0x0000000A ***/
typedef union {
  byte Byte;
  struct {
    byte             :1;
    byte             :1;
    byte RDWE        :1;                                       /* Read / Write Enable */
    byte LSTRE       :1;                                       /* Low Strobe (LSTRB) Enable */
    byte NECLK       :1;                                       /* No External E Clock */
    byte PIPOE       :1;                                       /* Pipe Status Signal Output Enable */
    byte             :1;
    byte NOACCE      :1;                                       /* CPU No Access Output Enable */
  } Bits;
} PEARSTR;
extern volatile PEARSTR _PEAR @(REG_BASE + 0x0000000A);
#define PEAR _PEAR.Byte
#define PEAR_RDWE _PEAR.Bits.RDWE
#define PEAR_LSTRE _PEAR.Bits.LSTRE
#define PEAR_NECLK _PEAR.Bits.NECLK
#define PEAR_PIPOE _PEAR.Bits.PIPOE
#define PEAR_NOACCE _PEAR.Bits.NOACCE


/*** MODE - Mode Register; 0x0000000B ***/
typedef union {
  byte Byte;
  struct {
    byte EME         :1;                                       /* Emulate Port E */
    byte EMK         :1;                                       /* Emulate Port K */
    byte             :1;
    byte IVIS        :1;                                       /* Internal Visibility */
    byte             :1;
    byte MODA        :1;                                       /* Mode Select Bit A */
    byte MODB        :1;                                       /* Mode Select Bit B */
    byte MODC        :1;                                       /* Mode Select Bit C */
  } Bits;
} MODESTR;
extern volatile MODESTR _MODE @(REG_BASE + 0x0000000B);
#define MODE _MODE.Byte
#define MODE_EME _MODE.Bits.EME
#define MODE_EMK _MODE.Bits.EMK
#define MODE_IVIS _MODE.Bits.IVIS
#define MODE_MODA _MODE.Bits.MODA
#define MODE_MODB _MODE.Bits.MODB
#define MODE_MODC _MODE.Bits.MODC


/*** PUCR - Pull-Up Control Register; 0x0000000C ***/
typedef union {
  byte Byte;
  struct {
    byte PUPAE       :1;                                       /* Pull-Up Port A Enable */
    byte PUPBE       :1;                                       /* Pull-Up Port B Enable */
    byte             :1;
    byte             :1;
    byte PUPEE       :1;                                       /* Pull-Up Port E Enable */
    byte             :1;
    byte             :1;
    byte PUPKE       :1;                                       /* Pull-Up Port K Enable */
  } Bits;
} PUCRSTR;
extern volatile PUCRSTR _PUCR @(REG_BASE + 0x0000000C);
#define PUCR _PUCR.Byte
#define PUCR_PUPAE _PUCR.Bits.PUPAE
#define PUCR_PUPBE _PUCR.Bits.PUPBE
#define PUCR_PUPEE _PUCR.Bits.PUPEE
#define PUCR_PUPKE _PUCR.Bits.PUPKE


/*** RDRIV - Reduced Drive of I/O Lines; 0x0000000D ***/
typedef union {
  byte Byte;
  struct {
    byte RDPA        :1;                                       /* Reduced Drive of Port A */
    byte RDPB        :1;                                       /* Reduced Drive of Port B */
    byte             :1;
    byte             :1;
    byte RDPE        :1;                                       /* Reduced Drive of Port E */
    byte             :1;
    byte             :1;
    byte RDPK        :1;                                       /* Reduced Drive of Port K */
  } Bits;
} RDRIVSTR;
extern volatile RDRIVSTR _RDRIV @(REG_BASE + 0x0000000D);
#define RDRIV _RDRIV.Byte
#define RDRIV_RDPA _RDRIV.Bits.RDPA
#define RDRIV_RDPB _RDRIV.Bits.RDPB
#define RDRIV_RDPE _RDRIV.Bits.RDPE
#define RDRIV_RDPK _RDRIV.Bits.RDPK


/*** EBICTL - External Bus Interface Control; 0x0000000E ***/
typedef union {
  byte Byte;
  struct {
    byte ESTR        :1;                                       /* E Stretches */
    byte             :1;
    byte             :1;
    byte             :1;
    byte             :1;
    byte             :1;
    byte             :1;
    byte             :1;
  } Bits;
} EBICTLSTR;
extern volatile EBICTLSTR _EBICTL @(REG_BASE + 0x0000000E);
#define EBICTL _EBICTL.Byte
#define EBICTL_ESTR _EBICTL.Bits.ESTR


/*** INITRM - Initialization of Internal RAM Position Register; 0x00000010 ***/
typedef union {
  byte Byte;
  struct {
    byte RAMHAL      :1;                                       /* Internal RAM map alignment */
    byte             :1;
    byte             :1;
    byte RAM11       :1;                                       /* Internal RAM map position Bit 11 */
    byte RAM12       :1;                                       /* Internal RAM map position Bit 12 */
    byte RAM13       :1;                                       /* Internal RAM map position Bit 13 */
    byte RAM14       :1;                                       /* Internal RAM map position Bit 14 */
    byte RAM15       :1;                                       /* Internal RAM map position Bit 15 */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpRAM_11 :5;
  } MergedBits;
} INITRMSTR;
extern volatile INITRMSTR _INITRM @(REG_BASE + 0x00000010);
#define INITRM _INITRM.Byte
#define INITRM_RAMHAL _INITRM.Bits.RAMHAL
#define INITRM_RAM11 _INITRM.Bits.RAM11
#define INITRM_RAM12 _INITRM.Bits.RAM12
#define INITRM_RAM13 _INITRM.Bits.RAM13
#define INITRM_RAM14 _INITRM.Bits.RAM14
#define INITRM_RAM15 _INITRM.Bits.RAM15
#define INITRM_RAM_11 _INITRM.MergedBits.grpRAM_11
#define INITRM_RAM INITRM_RAM_11


/*** INITRG - Initialization of Internal Register Position Register; 0x00000011 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1;
    byte             :1;
    byte             :1;
    byte REG11       :1;                                       /* Internal register map position REG11 */
    byte REG12       :1;                                       /* Internal register map position REG12 */
    byte REG13       :1;                                       /* Internal register map position REG13 */
    byte REG14       :1;                                       /* Internal register map position REG14 */
    byte             :1;
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpREG_11 :4;
    byte         :1;
  } MergedBits;
} INITRGSTR;
extern volatile INITRGSTR _INITRG @(REG_BASE + 0x00000011);
#define INITRG _INITRG.Byte
#define INITRG_REG11 _INITRG.Bits.REG11
#define INITRG_REG12 _INITRG.Bits.REG12
#define INITRG_REG13 _INITRG.Bits.REG13
#define INITRG_REG14 _INITRG.Bits.REG14
#define INITRG_REG_11 _INITRG.MergedBits.grpREG_11
#define INITRG_REG INITRG_REG_11


/*** INITEE - Initialization of Internal EEPROM Position Register; 0x00000012 ***/
typedef union {
  byte Byte;
  struct {
    byte EEON        :1;                                       /* Internal EEPROM On */
    byte             :1;
    byte             :1;
    byte             :1;
    byte EE12        :1;                                       /* Internal EEPROM map position Bit 12 */
    byte EE13        :1;                                       /* Internal EEPROM map position Bit 13 */
    byte EE14        :1;                                       /* Internal EEPROM map position Bit 14 */
    byte EE15        :1;                                       /* Internal EEPROM map position Bit 15 */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpEE_12 :4;
  } MergedBits;
} INITEESTR;
extern volatile INITEESTR _INITEE @(REG_BASE + 0x00000012);
#define INITEE _INITEE.Byte
#define INITEE_EEON _INITEE.Bits.EEON
#define INITEE_EE12 _INITEE.Bits.EE12
#define INITEE_EE13 _INITEE.Bits.EE13
#define INITEE_EE14 _INITEE.Bits.EE14
#define INITEE_EE15 _INITEE.Bits.EE15
#define INITEE_EE_12 _INITEE.MergedBits.grpEE_12
#define INITEE_EE INITEE_EE_12


/*** MISC - Miscellaneous Mapping Control Register; 0x00000013 ***/
typedef union {
  byte Byte;
  struct {
    byte ROMON       :1;                                       /* Enable Flash EEPROM */
    byte ROMHM       :1;                                       /* Flash EEPROM only in second half of memory map */
    byte EXSTR0      :1;                                       /* External Access Stretch Bit 0 */
    byte EXSTR1      :1;                                       /* External Access Stretch Bit 1 */
    byte             :1;
    byte             :1;
    byte             :1;
    byte             :1;
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpEXSTR :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} MISCSTR;
extern volatile MISCSTR _MISC @(REG_BASE + 0x00000013);
#define MISC _MISC.Byte
#define MISC_ROMON _MISC.Bits.ROMON
#define MISC_ROMHM _MISC.Bits.ROMHM
#define MISC_EXSTR0 _MISC.Bits.EXSTR0
#define MISC_EXSTR1 _MISC.Bits.EXSTR1
#define MISC_EXSTR _MISC.MergedBits.grpEXSTR


/*** MTST0 - MTST0; 0x00000014 ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* MTST0 Bit 0 */
    byte BIT1        :1;                                       /* MTST0 Bit 1 */
    byte BIT2        :1;                                       /* MTST0 Bit 2 */
    byte BIT3        :1;                                       /* MTST0 Bit 3 */
    byte BIT4        :1;                                       /* MTST0 Bit 4 */
    byte BIT5        :1;                                       /* MTST0 Bit 5 */
    byte BIT6        :1;                                       /* MTST0 Bit 6 */
    byte BIT7        :1;                                       /* MTST0 Bit 7 */
  } Bits;
  struct {
    byte grpBIT  :8;
  } MergedBits;
} MTST0STR;
extern volatile MTST0STR _MTST0 @(REG_BASE + 0x00000014);
#define MTST0 _MTST0.Byte
#define MTST0_BIT0 _MTST0.Bits.BIT0
#define MTST0_BIT1 _MTST0.Bits.BIT1
#define MTST0_BIT2 _MTST0.Bits.BIT2
#define MTST0_BIT3 _MTST0.Bits.BIT3
#define MTST0_BIT4 _MTST0.Bits.BIT4
#define MTST0_BIT5 _MTST0.Bits.BIT5
#define MTST0_BIT6 _MTST0.Bits.BIT6
#define MTST0_BIT7 _MTST0.Bits.BIT7
#define MTST0_BIT _MTST0.MergedBits.grpBIT


/*** ITCR - Interrupt Test Control Register; 0x00000015 ***/
typedef union {
  byte Byte;
  struct {
    byte ADR0        :1;                                       /* Test register select Bit 0 */
    byte ADR1        :1;                                       /* Test register select Bit 1 */
    byte ADR2        :1;                                       /* Test register select Bit 2 */
    byte ADR3        :1;                                       /* Test register select Bit 3 */
    byte WRTINT      :1;                                       /* Write to the Interrupt Test Registers */
    byte             :1;
    byte             :1;
    byte             :1;
  } Bits;
  struct {
    byte grpADR  :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} ITCRSTR;
extern volatile ITCRSTR _ITCR @(REG_BASE + 0x00000015);
#define ITCR _ITCR.Byte
#define ITCR_ADR0 _ITCR.Bits.ADR0
#define ITCR_ADR1 _ITCR.Bits.ADR1
#define ITCR_ADR2 _ITCR.Bits.ADR2
#define ITCR_ADR3 _ITCR.Bits.ADR3
#define ITCR_WRTINT _ITCR.Bits.WRTINT
#define ITCR_ADR _ITCR.MergedBits.grpADR


/*** ITEST - Interrupt Test Register; 0x00000016 ***/
typedef union {
  byte Byte;
  struct {
    byte INT0        :1;                                       /* Interrupt Test Register Bit 0 */
    byte INT2        :1;                                       /* Interrupt Test Register Bit 1 */
    byte INT4        :1;                                       /* Interrupt Test Register Bit 2 */
    byte INT6        :1;                                       /* Interrupt Test Register Bit 3 */
    byte INT8        :1;                                       /* Interrupt Test Register Bit 4 */
    byte INTA        :1;                                       /* Interrupt Test Register Bit 5 */
    byte INTC        :1;                                       /* Interrupt Test Register Bit 6 */
    byte INTE        :1;                                       /* Interrupt Test Register Bit 7 */
  } Bits;
} ITESTSTR;
extern volatile ITESTSTR _ITEST @(REG_BASE + 0x00000016);
#define ITEST _ITEST.Byte
#define ITEST_INT0 _ITEST.Bits.INT0
#define ITEST_INT2 _ITEST.Bits.INT2
#define ITEST_INT4 _ITEST.Bits.INT4
#define ITEST_INT6 _ITEST.Bits.INT6
#define ITEST_INT8 _ITEST.Bits.INT8
#define ITEST_INTA _ITEST.Bits.INTA
#define ITEST_INTC _ITEST.Bits.INTC
#define ITEST_INTE _ITEST.Bits.INTE


/*** MTST1 - MTST1; 0x00000017 ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* MTST1 Bit 0 */
    byte BIT1        :1;                                       /* MTST1 Bit 1 */
    byte BIT2        :1;                                       /* MTST1 Bit 2 */
    byte BIT3        :1;                                       /* MTST1 Bit 3 */
    byte BIT4        :1;                                       /* MTST1 Bit 4 */
    byte BIT5        :1;                                       /* MTST1 Bit 5 */
    byte BIT6        :1;                                       /* MTST1 Bit 6 */
    byte BIT7        :1;                                       /* MTST1 Bit 7 */
  } Bits;
  struct {
    byte grpBIT  :8;
  } MergedBits;
} MTST1STR;
extern volatile MTST1STR _MTST1 @(REG_BASE + 0x00000017);
#define MTST1 _MTST1.Byte
#define MTST1_BIT0 _MTST1.Bits.BIT0
#define MTST1_BIT1 _MTST1.Bits.BIT1
#define MTST1_BIT2 _MTST1.Bits.BIT2
#define MTST1_BIT3 _MTST1.Bits.BIT3
#define MTST1_BIT4 _MTST1.Bits.BIT4
#define MTST1_BIT5 _MTST1.Bits.BIT5
#define MTST1_BIT6 _MTST1.Bits.BIT6
#define MTST1_BIT7 _MTST1.Bits.BIT7
#define MTST1_BIT _MTST1.MergedBits.grpBIT


/*** PARTIDH - Part ID Register High; 0x0000001A ***/
typedef union {
  byte Byte;
  struct {
    byte ID15        :1;                                       /* Part ID Register Bit 15 */
    byte ID14        :1;                                       /* Part ID Register Bit 14 */
    byte ID13        :1;                                       /* Part ID Register Bit 13 */
    byte ID12        :1;                                       /* Part ID Register Bit 12 */
    byte ID11        :1;                                       /* Part ID Register Bit 11 */
    byte ID10        :1;                                       /* Part ID Register Bit 10 */
    byte ID9         :1;                                       /* Part ID Register Bit 9 */
    byte ID8         :1;                                       /* Part ID Register Bit 8 */
  } Bits;
} PARTIDHSTR;
extern volatile PARTIDHSTR _PARTIDH @(REG_BASE + 0x0000001A);
#define PARTIDH _PARTIDH.Byte
#define PARTIDH_ID15 _PARTIDH.Bits.ID15
#define PARTIDH_ID14 _PARTIDH.Bits.ID14
#define PARTIDH_ID13 _PARTIDH.Bits.ID13
#define PARTIDH_ID12 _PARTIDH.Bits.ID12
#define PARTIDH_ID11 _PARTIDH.Bits.ID11
#define PARTIDH_ID10 _PARTIDH.Bits.ID10
#define PARTIDH_ID9 _PARTIDH.Bits.ID9
#define PARTIDH_ID8 _PARTIDH.Bits.ID8


/*** PARTIDL - Part ID Register Low; 0x0000001B ***/
typedef union {
  byte Byte;
  struct {
    byte ID0         :1;                                       /* Part ID Register Bit 0 */
    byte ID1         :1;                                       /* Part ID Register Bit 1 */
    byte ID2         :1;                                       /* Part ID Register Bit 2 */
    byte ID3         :1;                                       /* Part ID Register Bit 3 */
    byte ID4         :1;                                       /* Part ID Register Bit 4 */
    byte ID5         :1;                                       /* Part ID Register Bit 5 */
    byte ID6         :1;                                       /* Part ID Register Bit 6 */
    byte ID7         :1;                                       /* Part ID Register Bit 7 */
  } Bits;
  struct {
    byte grpID   :8;
  } MergedBits;
} PARTIDLSTR;
extern volatile PARTIDLSTR _PARTIDL @(REG_BASE + 0x0000001B);
#define PARTIDL _PARTIDL.Byte
#define PARTIDL_ID0 _PARTIDL.Bits.ID0
#define PARTIDL_ID1 _PARTIDL.Bits.ID1
#define PARTIDL_ID2 _PARTIDL.Bits.ID2
#define PARTIDL_ID3 _PARTIDL.Bits.ID3
#define PARTIDL_ID4 _PARTIDL.Bits.ID4
#define PARTIDL_ID5 _PARTIDL.Bits.ID5
#define PARTIDL_ID6 _PARTIDL.Bits.ID6
#define PARTIDL_ID7 _PARTIDL.Bits.ID7
#define PARTIDL_ID _PARTIDL.MergedBits.grpID


/*** MEMSIZ0 - Memory Size Register Zero; 0x0000001C ***/
typedef union {
  byte Byte;
  struct {
    byte ram_sw0     :1;                                       /* Allocated RAM Memory Space Bit 0 */
    byte ram_sw1     :1;                                       /* Allocated RAM Memory Space Bit 1 */
    byte ram_sw2     :1;                                       /* Allocated RAM Memory Space Bit 2 */
    byte             :1;
    byte eep_sw0     :1;                                       /* Allocated EEPROM Memory Space Bit 0 */
    byte eep_sw1     :1;                                       /* Allocated EEPROM Memory Space Bit 1 */
    byte             :1;
    byte reg_sw0     :1;                                       /* Allocated System Register Space */
  } Bits;
  struct {
    byte grpram_sw :3;
    byte         :1;
    byte grpeep_sw :2;
    byte         :1;
    byte grpreg_sw :1;
  } MergedBits;
} MEMSIZ0STR;
extern volatile MEMSIZ0STR _MEMSIZ0 @(REG_BASE + 0x0000001C);
#define MEMSIZ0 _MEMSIZ0.Byte
#define MEMSIZ0_ram_sw0 _MEMSIZ0.Bits.ram_sw0
#define MEMSIZ0_ram_sw1 _MEMSIZ0.Bits.ram_sw1
#define MEMSIZ0_ram_sw2 _MEMSIZ0.Bits.ram_sw2
#define MEMSIZ0_eep_sw0 _MEMSIZ0.Bits.eep_sw0
#define MEMSIZ0_eep_sw1 _MEMSIZ0.Bits.eep_sw1
#define MEMSIZ0_reg_sw0 _MEMSIZ0.Bits.reg_sw0
#define MEMSIZ0_ram_sw _MEMSIZ0.MergedBits.grpram_sw
#define MEMSIZ0_eep_sw _MEMSIZ0.MergedBits.grpeep_sw


/*** MEMSIZ1 - Memory Size Register One; 0x0000001D ***/
typedef union {
  byte Byte;
  struct {
    byte pag_sw0     :1;                                       /* Allocated Off-Chip Memory Options Bit 0 */
    byte pag_sw1     :1;                                       /* Allocated Off-Chip Memory Options Bit 1 */
    byte             :1;
    byte             :1;
    byte             :1;
    byte             :1;
    byte rom_sw0     :1;                                       /* Allocated Flash EEPROM/ROM Physical Memory Space Bit 0 */
    byte rom_sw1     :1;                                       /* Allocated Flash EEPROM/ROM Physical Memory Space Bit 1 */
  } Bits;
  struct {
    byte grppag_sw :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte grprom_sw :2;
  } MergedBits;
} MEMSIZ1STR;
extern volatile MEMSIZ1STR _MEMSIZ1 @(REG_BASE + 0x0000001D);
#define MEMSIZ1 _MEMSIZ1.Byte
#define MEMSIZ1_pag_sw0 _MEMSIZ1.Bits.pag_sw0
#define MEMSIZ1_pag_sw1 _MEMSIZ1.Bits.pag_sw1
#define MEMSIZ1_rom_sw0 _MEMSIZ1.Bits.rom_sw0
#define MEMSIZ1_rom_sw1 _MEMSIZ1.Bits.rom_sw1
#define MEMSIZ1_pag_sw _MEMSIZ1.MergedBits.grppag_sw
#define MEMSIZ1_rom_sw _MEMSIZ1.MergedBits.grprom_sw


/*** INTCR - Interrupt Control Register; 0x0000001E ***/
typedef union {
  byte Byte;
  struct {
    byte             :1;
    byte             :1;
    byte             :1;
    byte             :1;
    byte             :1;
    byte             :1;
    byte IRQEN       :1;                                       /* External IRQ Enable */
    byte IRQE        :1;                                       /* IRQ Select Edge Sensitive Only */
  } Bits;
} INTCRSTR;
extern volatile INTCRSTR _INTCR @(REG_BASE + 0x0000001E);
#define INTCR _INTCR.Byte
#define INTCR_IRQEN _INTCR.Bits.IRQEN
#define INTCR_IRQE _INTCR.Bits.IRQE


/*** HPRIO - Highest Priority I Interrupt; 0x0000001F ***/
typedef union {
  byte Byte;
  struct {
    byte             :1;
    byte PSEL1       :1;                                       /* Highest Priority I Interrupt Bit 1 */
    byte PSEL2       :1;                                       /* Highest Priority I Interrupt Bit 2 */
    byte PSEL3       :1;                                       /* Highest Priority I Interrupt Bit 3 */
    byte PSEL4       :1;                                       /* Highest Priority I Interrupt Bit 4 */
    byte PSEL5       :1;                                       /* Highest Priority I Interrupt Bit 5 */
    byte PSEL6       :1;                                       /* Highest Priority I Interrupt Bit 6 */
    byte PSEL7       :1;                                       /* Highest Priority I Interrupt Bit 7 */
  } Bits;
  struct {
    byte         :1;
    byte grpPSEL_1 :7;
  } MergedBits;
} HPRIOSTR;
extern volatile HPRIOSTR _HPRIO @(REG_BASE + 0x0000001F);
#define HPRIO _HPRIO.Byte
#define HPRIO_PSEL1 _HPRIO.Bits.PSEL1
#define HPRIO_PSEL2 _HPRIO.Bits.PSEL2
#define HPRIO_PSEL3 _HPRIO.Bits.PSEL3
#define HPRIO_PSEL4 _HPRIO.Bits.PSEL4
#define HPRIO_PSEL5 _HPRIO.Bits.PSEL5
#define HPRIO_PSEL6 _HPRIO.Bits.PSEL6
#define HPRIO_PSEL7 _HPRIO.Bits.PSEL7
#define HPRIO_PSEL_1 _HPRIO.MergedBits.grpPSEL_1
#define HPRIO_PSEL HPRIO_PSEL_1


/*** BKPCT0 - Breakpoint Control Register 0; 0x00000028 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1;
    byte             :1;
    byte             :1;
    byte             :1;
    byte BKTAG       :1;                                       /* Breakpoint on Tag */
    byte BKBDM       :1;                                       /* Breakpoint Background Debug Mode Enable */
    byte BKFULL      :1;                                       /* Full Breakpoint Mode Enable */
    byte BKEN        :1;                                       /* Breakpoint Enable */
  } Bits;
} BKPCT0STR;
extern volatile BKPCT0STR _BKPCT0 @(REG_BASE + 0x00000028);
#define BKPCT0 _BKPCT0.Byte
#define BKPCT0_BKTAG _BKPCT0.Bits.BKTAG
#define BKPCT0_BKBDM _BKPCT0.Bits.BKBDM
#define BKPCT0_BKFULL _BKPCT0.Bits.BKFULL
#define BKPCT0_BKEN _BKPCT0.Bits.BKEN


/*** BKPCT1 - Breakpoint Control Register 1; 0x00000029 ***/
typedef union {
  byte Byte;
  struct {
    byte BK1RW       :1;                                       /* R/W Compare Value 1 */
    byte BK1RWE      :1;                                       /* R/W Compare Enable 1 */
    byte BK0RW       :1;                                       /* R/W Compare Value 0 */
    byte BK0RWE      :1;                                       /* R/W Compare Enable 0 */
    byte BK1MBL      :1;                                       /* Breakpoint Mask Low Byte for Second Address */
    byte BK1MBH      :1;                                       /* Breakpoint Mask High Byte for Second Address */
    byte BK0MBL      :1;                                       /* Breakpoint Mask Low Byte for First Address */
    byte BK0MBH      :1;                                       /* Breakpoint Mask High Byte for First Address */
  } Bits;
} BKPCT1STR;
extern volatile BKPCT1STR _BKPCT1 @(REG_BASE + 0x00000029);
#define BKPCT1 _BKPCT1.Byte
#define BKPCT1_BK1RW _BKPCT1.Bits.BK1RW
#define BKPCT1_BK1RWE _BKPCT1.Bits.BK1RWE
#define BKPCT1_BK0RW _BKPCT1.Bits.BK0RW
#define BKPCT1_BK0RWE _BKPCT1.Bits.BK0RWE
#define BKPCT1_BK1MBL _BKPCT1.Bits.BK1MBL
#define BKPCT1_BK1MBH _BKPCT1.Bits.BK1MBH
#define BKPCT1_BK0MBL _BKPCT1.Bits.BK0MBL
#define BKPCT1_BK0MBH _BKPCT1.Bits.BK0MBH


/*** BKP0X - First Address Memory Expansion Breakpoint Register; 0x0000002A ***/
typedef union {
  byte Byte;
  struct {
    byte BK0V0       :1;                                       /* First Address Breakpoint Expansion Address Value Bit 0 */
    byte BK0V1       :1;                                       /* First Address Breakpoint Expansion Address Value Bit 1 */
    byte BK0V2       :1;                                       /* First Address Breakpoint Expansion Address Value Bit 2 */
    byte BK0V3       :1;                                       /* First Address Breakpoint Expansion Address Value Bit 3 */
    byte BK0V4       :1;                                       /* First Address Breakpoint Expansion Address Value Bit 4 */
    byte BK0V5       :1;                                       /* First Address Breakpoint Expansion Address Value Bit 5 */
    byte             :1;
    byte             :1;
  } Bits;
  struct {
    byte grpBK0V :6;
    byte         :1;
    byte         :1;
  } MergedBits;
} BKP0XSTR;
extern volatile BKP0XSTR _BKP0X @(REG_BASE + 0x0000002A);
#define BKP0X _BKP0X.Byte
#define BKP0X_BK0V0 _BKP0X.Bits.BK0V0
#define BKP0X_BK0V1 _BKP0X.Bits.BK0V1
#define BKP0X_BK0V2 _BKP0X.Bits.BK0V2
#define BKP0X_BK0V3 _BKP0X.Bits.BK0V3
#define BKP0X_BK0V4 _BKP0X.Bits.BK0V4
#define BKP0X_BK0V5 _BKP0X.Bits.BK0V5
#define BKP0X_BK0V _BKP0X.MergedBits.grpBK0V


/*** BKP0H - First Address High Byte Breakpoint Register; 0x0000002B ***/
typedef union {
  byte Byte;
  struct {
    byte BIT8        :1;                                       /* First Address Breakpoint Register Bit 8 */
    byte BIT9        :1;                                       /* First Address Breakpoint Register Bit 9 */
    byte BIT10       :1;                                       /* First Address Breakpoint Register Bit 10 */
    byte BIT11       :1;                                       /* First Address Breakpoint Register Bit 11 */
    byte BIT12       :1;                                       /* First Address Breakpoint Register Bit 12 */
    byte BIT13       :1;                                       /* First Address Breakpoint Register Bit 13 */
    byte BIT14       :1;                                       /* First Address Breakpoint Register Bit 14 */
    byte BIT15       :1;                                       /* First Address Breakpoint Register Bit 15 */
  } Bits;
  struct {
    byte grpBIT_8 :8;
  } MergedBits;
} BKP0HSTR;
extern volatile BKP0HSTR _BKP0H @(REG_BASE + 0x0000002B);
#define BKP0H _BKP0H.Byte
#define BKP0H_BIT8 _BKP0H.Bits.BIT8
#define BKP0H_BIT9 _BKP0H.Bits.BIT9
#define BKP0H_BIT10 _BKP0H.Bits.BIT10
#define BKP0H_BIT11 _BKP0H.Bits.BIT11
#define BKP0H_BIT12 _BKP0H.Bits.BIT12
#define BKP0H_BIT13 _BKP0H.Bits.BIT13
#define BKP0H_BIT14 _BKP0H.Bits.BIT14
#define BKP0H_BIT15 _BKP0H.Bits.BIT15
#define BKP0H_BIT_8 _BKP0H.MergedBits.grpBIT_8
#define BKP0H_BIT BKP0H_BIT_8


/*** BKP0L - First Address Low Byte Breakpoint Register; 0x0000002C ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* First Address Breakpoint Register Bit 0 */
    byte BIT1        :1;                                       /* First Address Breakpoint Register Bit 1 */
    byte BIT2        :1;                                       /* First Address Breakpoint Register Bit 2 */
    byte BIT3        :1;                                       /* First Address Breakpoint Register Bit 3 */
    byte BIT4        :1;                                       /* First Address Breakpoint Register Bit 4 */
    byte BIT5        :1;                                       /* First Address Breakpoint Register Bit 5 */
    byte BIT6        :1;                                       /* First Address Breakpoint Register Bit 6 */
    byte BIT7        :1;                                       /* First Address Breakpoint Register Bit 7 */
  } Bits;
  struct {
    byte grpBIT  :8;
  } MergedBits;
} BKP0LSTR;
extern volatile BKP0LSTR _BKP0L @(REG_BASE + 0x0000002C);
#define BKP0L _BKP0L.Byte
#define BKP0L_BIT0 _BKP0L.Bits.BIT0
#define BKP0L_BIT1 _BKP0L.Bits.BIT1
#define BKP0L_BIT2 _BKP0L.Bits.BIT2
#define BKP0L_BIT3 _BKP0L.Bits.BIT3
#define BKP0L_BIT4 _BKP0L.Bits.BIT4
#define BKP0L_BIT5 _BKP0L.Bits.BIT5
#define BKP0L_BIT6 _BKP0L.Bits.BIT6
#define BKP0L_BIT7 _BKP0L.Bits.BIT7
#define BKP0L_BIT _BKP0L.MergedBits.grpBIT


/*** BKP1X - Second Address Memory Expansion Breakpoint Register; 0x0000002D ***/
typedef union {
  byte Byte;
  struct {
    byte BK1V0       :1;                                       /* Second Address Breakpoint Expansion Address Value Bit 0 */
    byte BK1V1       :1;                                       /* Second Address Breakpoint Expansion Address Value Bit 1 */
    byte BK1V2       :1;                                       /* Second Address Breakpoint Expansion Address Value Bit 2 */
    byte BK1V3       :1;                                       /* Second Address Breakpoint Expansion Address Value Bit 3 */
    byte BK1V4       :1;                                       /* Second Address Breakpoint Expansion Address Value Bit 4 */
    byte BK1V5       :1;                                       /* Second Address Breakpoint Expansion Address Value Bit 5 */
    byte             :1;
    byte             :1;
  } Bits;
  struct {
    byte grpBK1V :6;
    byte         :1;
    byte         :1;
  } MergedBits;
} BKP1XSTR;
extern volatile BKP1XSTR _BKP1X @(REG_BASE + 0x0000002D);
#define BKP1X _BKP1X.Byte
#define BKP1X_BK1V0 _BKP1X.Bits.BK1V0
#define BKP1X_BK1V1 _BKP1X.Bits.BK1V1
#define BKP1X_BK1V2 _BKP1X.Bits.BK1V2
#define BKP1X_BK1V3 _BKP1X.Bits.BK1V3
#define BKP1X_BK1V4 _BKP1X.Bits.BK1V4
#define BKP1X_BK1V5 _BKP1X.Bits.BK1V5
#define BKP1X_BK1V _BKP1X.MergedBits.grpBK1V


/*** BKP1H - Data (Second Address) High Byte Breakpoint Register; 0x0000002E ***/
typedef union {
  byte Byte;
  struct {
    byte BIT8        :1;                                       /* Data (Second Address) Breakpoint Register Bit 8 */
    byte BIT9        :1;                                       /* Data (Second Address) Breakpoint Register Bit 9 */
    byte BIT10       :1;                                       /* Data (Second Address) Breakpoint Register Bit 10 */
    byte BIT11       :1;                                       /* Data (Second Address) Breakpoint Register Bit 11 */
    byte BIT12       :1;                                       /* Data (Second Address) Breakpoint Register Bit 12 */
    byte BIT13       :1;                                       /* Data (Second Address) Breakpoint Register Bit 13 */
    byte BIT14       :1;                                       /* Data (Second Address) Breakpoint Register Bit 14 */
    byte BIT15       :1;                                       /* Data (Second Address) Breakpoint Register Bit 15 */
  } Bits;
  struct {
    byte grpBIT_8 :8;
  } MergedBits;
} BKP1HSTR;
extern volatile BKP1HSTR _BKP1H @(REG_BASE + 0x0000002E);
#define BKP1H _BKP1H.Byte
#define BKP1H_BIT8 _BKP1H.Bits.BIT8
#define BKP1H_BIT9 _BKP1H.Bits.BIT9
#define BKP1H_BIT10 _BKP1H.Bits.BIT10
#define BKP1H_BIT11 _BKP1H.Bits.BIT11
#define BKP1H_BIT12 _BKP1H.Bits.BIT12
#define BKP1H_BIT13 _BKP1H.Bits.BIT13
#define BKP1H_BIT14 _BKP1H.Bits.BIT14
#define BKP1H_BIT15 _BKP1H.Bits.BIT15
#define BKP1H_BIT_8 _BKP1H.MergedBits.grpBIT_8
#define BKP1H_BIT BKP1H_BIT_8


/*** BKP1L - Data (Second Address) Low Byte Breakpoint Register; 0x0000002F ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* Data (Second Address) Breakpoint Register Bit 0 */
    byte BIT1        :1;                                       /* Data (Second Address) Breakpoint Register Bit 1 */
    byte BIT2        :1;                                       /* Data (Second Address) Breakpoint Register Bit 2 */
    byte BIT3        :1;                                       /* Data (Second Address) Breakpoint Register Bit 3 */
    byte BIT4        :1;                                       /* Data (Second Address) Breakpoint Register Bit 4 */
    byte BIT5        :1;                                       /* Data (Second Address) Breakpoint Register Bit 5 */
    byte BIT6        :1;                                       /* Data (Second Address) Breakpoint Register Bit 6 */
    byte BIT7        :1;                                       /* Data (Second Address) Breakpoint Register Bit 7 */
  } Bits;
  struct {
    byte grpBIT  :8;
  } MergedBits;
} BKP1LSTR;
extern volatile BKP1LSTR _BKP1L @(REG_BASE + 0x0000002F);
#define BKP1L _BKP1L.Byte
#define BKP1L_BIT0 _BKP1L.Bits.BIT0
#define BKP1L_BIT1 _BKP1L.Bits.BIT1
#define BKP1L_BIT2 _BKP1L.Bits.BIT2
#define BKP1L_BIT3 _BKP1L.Bits.BIT3
#define BKP1L_BIT4 _BKP1L.Bits.BIT4
#define BKP1L_BIT5 _BKP1L.Bits.BIT5
#define BKP1L_BIT6 _BKP1L.Bits.BIT6
#define BKP1L_BIT7 _BKP1L.Bits.BIT7
#define BKP1L_BIT _BKP1L.MergedBits.grpBIT


/*** PPAGE - Page Index Register; 0x00000030 ***/
typedef union {
  byte Byte;
  struct {
    byte PIX0        :1;                                       /* Page Index Register Bit 0 */
    byte PIX1        :1;                                       /* Page Index Register Bit 1 */
    byte PIX2        :1;                                       /* Page Index Register Bit 2 */
    byte PIX3        :1;                                       /* Page Index Register Bit 3 */
    byte PIX4        :1;                                       /* Page Index Register Bit 4 */
    byte PIX5        :1;                                       /* Page Index Register Bit 5 */
    byte             :1;
    byte             :1;
  } Bits;
  struct {
    byte grpPIX  :6;
    byte         :1;
    byte         :1;
  } MergedBits;
} PPAGESTR;
extern volatile PPAGESTR _PPAGE @(REG_BASE + 0x00000030);
#define PPAGE _PPAGE.Byte
#define PPAGE_PIX0 _PPAGE.Bits.PIX0
#define PPAGE_PIX1 _PPAGE.Bits.PIX1
#define PPAGE_PIX2 _PPAGE.Bits.PIX2
#define PPAGE_PIX3 _PPAGE.Bits.PIX3
#define PPAGE_PIX4 _PPAGE.Bits.PIX4
#define PPAGE_PIX5 _PPAGE.Bits.PIX5
#define PPAGE_PIX _PPAGE.MergedBits.grpPIX


/*** PORTK - Port K Data Register; 0x00000032 ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* Port K Bit 0 */
    byte BIT1        :1;                                       /* Port K Bit 1 */
    byte BIT2        :1;                                       /* Port K Bit 2 */
    byte BIT3        :1;                                       /* Port K Bit 3 */
    byte BIT4        :1;                                       /* Port K Bit 4 */
    byte BIT5        :1;                                       /* Port K Bit 5 */
    byte             :1;
    byte BIT7        :1;                                       /* Port K Bit 7 */
  } Bits;
  struct {
    byte grpBIT  :6;
    byte         :1;
    byte grpBIT_7 :1;
  } MergedBits;
} PORTKSTR;
extern volatile PORTKSTR _PORTK @(REG_BASE + 0x00000032);
#define PORTK _PORTK.Byte
#define PORTK_BIT0 _PORTK.Bits.BIT0
#define PORTK_BIT1 _PORTK.Bits.BIT1
#define PORTK_BIT2 _PORTK.Bits.BIT2
#define PORTK_BIT3 _PORTK.Bits.BIT3
#define PORTK_BIT4 _PORTK.Bits.BIT4
#define PORTK_BIT5 _PORTK.Bits.BIT5
#define PORTK_BIT7 _PORTK.Bits.BIT7
#define PORTK_BIT _PORTK.MergedBits.grpBIT


/*** DDRK - Port K Data Direction Register; 0x00000033 ***/
typedef union {
  byte Byte;
  struct {
    byte DDK0        :1;                                       /* Port K Data Direction Bit 0 */
    byte DDK1        :1;                                       /* Port K Data Direction Bit 1 */
    byte DDK2        :1;                                       /* Port K Data Direction Bit 2 */
    byte DDK3        :1;                                       /* Port K Data Direction Bit 3 */
    byte DDK4        :1;                                       /* Port K Data Direction Bit 4 */
    byte DDK5        :1;                                       /* Port K Data Direction Bit 5 */
    byte             :1;
    byte DDK7        :1;                                       /* Port K Data Direction Bit 7 */
  } Bits;
  struct {
    byte grpDDK  :6;
    byte         :1;
    byte grpDDK_7 :1;
  } MergedBits;
} DDRKSTR;
extern volatile DDRKSTR _DDRK @(REG_BASE + 0x00000033);
#define DDRK _DDRK.Byte
#define DDRK_DDK0 _DDRK.Bits.DDK0
#define DDRK_DDK1 _DDRK.Bits.DDK1
#define DDRK_DDK2 _DDRK.Bits.DDK2
#define DDRK_DDK3 _DDRK.Bits.DDK3
#define DDRK_DDK4 _DDRK.Bits.DDK4
#define DDRK_DDK5 _DDRK.Bits.DDK5
#define DDRK_DDK7 _DDRK.Bits.DDK7
#define DDRK_DDK _DDRK.MergedBits.grpDDK


/*** SYNR - CRG Synthesizer Register; 0x00000034 ***/
typedef union {
  byte Byte;
  struct {
    byte SYN0        :1;                                       /* CRG Synthesizer Bit 0 */
    byte SYN1        :1;                                       /* CRG Synthesizer Bit 1 */
    byte SYN2        :1;                                       /* CRG Synthesizer Bit 2 */
    byte SYN3        :1;                                       /* CRG Synthesizer Bit 3 */
    byte SYN4        :1;                                       /* CRG Synthesizer Bit 4 */
    byte SYN5        :1;                                       /* CRG Synthesizer Bit 5 */
    byte             :1;
    byte             :1;
  } Bits;
  struct {
    byte grpSYN  :6;
    byte         :1;
    byte         :1;
  } MergedBits;
} SYNRSTR;
extern volatile SYNRSTR _SYNR @(REG_BASE + 0x00000034);
#define SYNR _SYNR.Byte
#define SYNR_SYN0 _SYNR.Bits.SYN0
#define SYNR_SYN1 _SYNR.Bits.SYN1
#define SYNR_SYN2 _SYNR.Bits.SYN2
#define SYNR_SYN3 _SYNR.Bits.SYN3
#define SYNR_SYN4 _SYNR.Bits.SYN4
#define SYNR_SYN5 _SYNR.Bits.SYN5
#define SYNR_SYN _SYNR.MergedBits.grpSYN


/*** REFDV - CRG Reference Divider Register; 0x00000035 ***/
typedef union {
  byte Byte;
  struct {
    byte REFDV0      :1;                                       /* CRG Reference Divider Bit 0 */
    byte REFDV1      :1;                                       /* CRG Reference Divider Bit 1 */
    byte REFDV2      :1;                                       /* CRG Reference Divider Bit 2 */
    byte REFDV3      :1;                                       /* CRG Reference Divider Bit 3 */
    byte             :1;
    byte             :1;
    byte             :1;
    byte             :1;
  } Bits;
  struct {
    byte grpREFDV :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} REFDVSTR;
extern volatile REFDVSTR _REFDV @(REG_BASE + 0x00000035);
#define REFDV _REFDV.Byte
#define REFDV_REFDV0 _REFDV.Bits.REFDV0
#define REFDV_REFDV1 _REFDV.Bits.REFDV1
#define REFDV_REFDV2 _REFDV.Bits.REFDV2
#define REFDV_REFDV3 _REFDV.Bits.REFDV3
#define REFDV_REFDV _REFDV.MergedBits.grpREFDV


/*** CRGFLG - CRG Flags Register; 0x00000037 ***/
typedef union {
  byte Byte;
  struct {
    byte SCM         :1;                                       /* Self-clock mode Status */
    byte SCMIF       :1;                                       /* Self-clock mode Interrupt Flag */
    byte TRACK       :1;                                       /* Track Status */
    byte LOCK        :1;                                       /* Lock Status */
    byte LOCKIF      :1;                                       /* PLL Lock Interrupt Flag */
    byte             :1;
    byte PORF        :1;                                       /* Power on Reset Flag */
    byte RTIF        :1;                                       /* Real Time Interrupt Flag */
  } Bits;
} CRGFLGSTR;
extern volatile CRGFLGSTR _CRGFLG @(REG_BASE + 0x00000037);
#define CRGFLG _CRGFLG.Byte
#define CRGFLG_SCM _CRGFLG.Bits.SCM
#define CRGFLG_SCMIF _CRGFLG.Bits.SCMIF
#define CRGFLG_TRACK _CRGFLG.Bits.TRACK
#define CRGFLG_LOCK _CRGFLG.Bits.LOCK
#define CRGFLG_LOCKIF _CRGFLG.Bits.LOCKIF
#define CRGFLG_PORF _CRGFLG.Bits.PORF
#define CRGFLG_RTIF _CRGFLG.Bits.RTIF


/*** CRGINT - CRG Interrupt Enable Register; 0x00000038 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1;
    byte SCMIE       :1;                                       /* Self-clock mode Interrupt Enable */
    byte             :1;
    byte             :1;
    byte LOCKIE      :1;                                       /* Lock Interrupt Enable */
    byte             :1;
    byte             :1;
    byte RTIE        :1;                                       /* Real Time Interrupt Enable */
  } Bits;
} CRGINTSTR;
extern volatile CRGINTSTR _CRGINT @(REG_BASE + 0x00000038);
#define CRGINT _CRGINT.Byte
#define CRGINT_SCMIE _CRGINT.Bits.SCMIE
#define CRGINT_LOCKIE _CRGINT.Bits.LOCKIE
#define CRGINT_RTIE _CRGINT.Bits.RTIE


/*** CLKSEL - CRG Clock Select Register; 0x00000039 ***/
typedef union {
  byte Byte;
  struct {
    byte COPWAI      :1;                                       /* COP stops in WAIT mode */
    byte RTIWAI      :1;                                       /* RTI stops in WAIT mode */
    byte CWAI        :1;                                       /* CLK24 and CLK23 stop in WAIT mode */
    byte PLLWAI      :1;                                       /* PLL stops in WAIT mode */
    byte ROAWAI      :1;                                       /* Reduced Oscillator Amplitude in WAIT mode */
    byte SYSWAI      :1;                                       /* System clocks stop in WAIT mode */
    byte PSTP        :1;                                       /* Pseudo Stop */
    byte PLLSEL      :1;                                       /* PLL selected for system clock */
  } Bits;
} CLKSELSTR;
extern volatile CLKSELSTR _CLKSEL @(REG_BASE + 0x00000039);
#define CLKSEL _CLKSEL.Byte
#define CLKSEL_COPWAI _CLKSEL.Bits.COPWAI
#define CLKSEL_RTIWAI _CLKSEL.Bits.RTIWAI
#define CLKSEL_CWAI _CLKSEL.Bits.CWAI
#define CLKSEL_PLLWAI _CLKSEL.Bits.PLLWAI
#define CLKSEL_ROAWAI _CLKSEL.Bits.ROAWAI
#define CLKSEL_SYSWAI _CLKSEL.Bits.SYSWAI
#define CLKSEL_PSTP _CLKSEL.Bits.PSTP
#define CLKSEL_PLLSEL _CLKSEL.Bits.PLLSEL


/*** PLLCTL - CRG PLL Control Register; 0x0000003A ***/
typedef union {
  byte Byte;
  struct {
    byte SCME        :1;                                       /* Self-clock mode enable */
    byte             :1;
    byte             :1;
    byte             :1;
    byte ACQ         :1;                                       /* Acquisition */
    byte AUTO        :1;                                       /* Automatic Bandwidth Control */
    byte PLLON       :1;                                       /* Phase Lock Loop On */
    byte CME         :1;                                       /* Crystal Monitor Enable */
  } Bits;
} PLLCTLSTR;
extern volatile PLLCTLSTR _PLLCTL @(REG_BASE + 0x0000003A);
#define PLLCTL _PLLCTL.Byte
#define PLLCTL_SCME _PLLCTL.Bits.SCME
#define PLLCTL_ACQ _PLLCTL.Bits.ACQ
#define PLLCTL_AUTO _PLLCTL.Bits.AUTO
#define PLLCTL_PLLON _PLLCTL.Bits.PLLON
#define PLLCTL_CME _PLLCTL.Bits.CME


/*** RTICTL - CRG RTI Control Register; 0x0000003B ***/
typedef union {
  byte Byte;
  struct {
    byte RTR0        :1;                                       /* Real Time Interrupt Modulus Counter Select */
    byte RTR1        :1;                                       /* Real Time Interrupt Modulus Counter Select */
    byte RTR2        :1;                                       /* Real Time Interrupt Modulus Counter Select */
    byte RTR3        :1;                                       /* Real Time Interrupt Modulus Counter Select */
    byte RTR4        :1;                                       /* Real Time Interrupt Prescale Rate Select */
    byte RTR5        :1;                                       /* Real Time Interrupt Prescale Rate Select */
    byte RTR6        :1;                                       /* Real Time Interrupt Prescale Rate Select */
    byte             :1;
  } Bits;
  struct {
    byte grpRTR  :7;
    byte         :1;
  } MergedBits;
} RTICTLSTR;
extern volatile RTICTLSTR _RTICTL @(REG_BASE + 0x0000003B);
#define RTICTL _RTICTL.Byte
#define RTICTL_RTR0 _RTICTL.Bits.RTR0
#define RTICTL_RTR1 _RTICTL.Bits.RTR1
#define RTICTL_RTR2 _RTICTL.Bits.RTR2
#define RTICTL_RTR3 _RTICTL.Bits.RTR3
#define RTICTL_RTR4 _RTICTL.Bits.RTR4
#define RTICTL_RTR5 _RTICTL.Bits.RTR5
#define RTICTL_RTR6 _RTICTL.Bits.RTR6
#define RTICTL_RTR _RTICTL.MergedBits.grpRTR


/*** COPCTL - CRG COP Control Register; 0x0000003C ***/
typedef union {
  byte Byte;
  struct {
    byte CR0         :1;                                       /* COP Watchdog Timer Rate select Bit 0 */
    byte CR1         :1;                                       /* COP Watchdog Timer Rate select Bit 1 */
    byte CR2         :1;                                       /* COP Watchdog Timer Rate select Bit 2 */
    byte             :1;
    byte             :1;
    byte             :1;
    byte RSBCK       :1;                                       /* COP and RTI stop in Active BDM mode Bit */
    byte WCOP        :1;                                       /* Window COP mode */
  } Bits;
  struct {
    byte grpCR   :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} COPCTLSTR;
extern volatile COPCTLSTR _COPCTL @(REG_BASE + 0x0000003C);
#define COPCTL _COPCTL.Byte
#define COPCTL_CR0 _COPCTL.Bits.CR0
#define COPCTL_CR1 _COPCTL.Bits.CR1
#define COPCTL_CR2 _COPCTL.Bits.CR2
#define COPCTL_RSBCK _COPCTL.Bits.RSBCK
#define COPCTL_WCOP _COPCTL.Bits.WCOP
#define COPCTL_CR _COPCTL.MergedBits.grpCR


/*** FORBYP - Crg force and bypass test register; 0x0000003D ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* Bit 0 */
    byte BIT1        :1;                                       /* Bit 1 */
    byte BIT2        :1;                                       /* Bit 2 */
    byte BIT3        :1;                                       /* Bit 3 */
    byte BIT4        :1;                                       /* Bit 4 */
    byte BIT5        :1;                                       /* Bit 5 */
    byte BIT6        :1;                                       /* Bit 6 */
    byte BIT7        :1;                                       /* Bit 7 */
  } Bits;
  struct {
    byte grpBIT  :8;
  } MergedBits;
} FORBYPSTR;
extern volatile FORBYPSTR _FORBYP @(REG_BASE + 0x0000003D);
#define FORBYP _FORBYP.Byte
#define FORBYP_BIT0 _FORBYP.Bits.BIT0
#define FORBYP_BIT1 _FORBYP.Bits.BIT1
#define FORBYP_BIT2 _FORBYP.Bits.BIT2
#define FORBYP_BIT3 _FORBYP.Bits.BIT3
#define FORBYP_BIT4 _FORBYP.Bits.BIT4
#define FORBYP_BIT5 _FORBYP.Bits.BIT5
#define FORBYP_BIT6 _FORBYP.Bits.BIT6
#define FORBYP_BIT7 _FORBYP.Bits.BIT7
#define FORBYP_BIT _FORBYP.MergedBits.grpBIT


/*** ARMCOP - CRG COP Timer Arm/Reset Register; 0x0000003F ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* CRG COP Timer Arm/Reset Bit 0 */
    byte BIT1        :1;                                       /* CRG COP Timer Arm/Reset Bit 1 */
    byte BIT2        :1;                                       /* CRG COP Timer Arm/Reset Bit 2 */
    byte BIT3        :1;                                       /* CRG COP Timer Arm/Reset Bit 3 */
    byte BIT4        :1;                                       /* CRG COP Timer Arm/Reset Bit 4 */
    byte BIT5        :1;                                       /* CRG COP Timer Arm/Reset Bit 5 */
    byte BIT6        :1;                                       /* CRG COP Timer Arm/Reset Bit 6 */
    byte BIT7        :1;                                       /* CRG COP Timer Arm/Reset Bit 7 */
  } Bits;
  struct {
    byte grpBIT  :8;
  } MergedBits;
} ARMCOPSTR;
extern volatile ARMCOPSTR _ARMCOP @(REG_BASE + 0x0000003F);
#define ARMCOP _ARMCOP.Byte
#define ARMCOP_BIT0 _ARMCOP.Bits.BIT0
#define ARMCOP_BIT1 _ARMCOP.Bits.BIT1
#define ARMCOP_BIT2 _ARMCOP.Bits.BIT2
#define ARMCOP_BIT3 _ARMCOP.Bits.BIT3
#define ARMCOP_BIT4 _ARMCOP.Bits.BIT4
#define ARMCOP_BIT5 _ARMCOP.Bits.BIT5
#define ARMCOP_BIT6 _ARMCOP.Bits.BIT6
#define ARMCOP_BIT7 _ARMCOP.Bits.BIT7
#define ARMCOP_BIT _ARMCOP.MergedBits.grpBIT


/*** ATD0STAT0 - ATD 0 Status Register 0; 0x00000086 ***/
typedef union {
  byte Byte;
  struct {
    byte CC0         :1;                                       /* Conversion Counter 0 */
    byte CC1         :1;                                       /* Conversion Counter 1 */
    byte CC2         :1;                                       /* Conversion Counter 2 */
    byte             :1;
    byte FIFOR       :1;                                       /* FIFO Over Run Flag */
    byte ETORF       :1;                                       /* External Trigger Overrun Flag */
    byte             :1;
    byte SCF         :1;                                       /* Sequence Complete Flag */
  } Bits;
  struct {
    byte grpCC   :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} ATD0STAT0STR;
extern volatile ATD0STAT0STR _ATD0STAT0 @(REG_BASE + 0x00000086);
#define ATD0STAT0 _ATD0STAT0.Byte
#define ATD0STAT0_CC0 _ATD0STAT0.Bits.CC0
#define ATD0STAT0_CC1 _ATD0STAT0.Bits.CC1
#define ATD0STAT0_CC2 _ATD0STAT0.Bits.CC2
#define ATD0STAT0_FIFOR _ATD0STAT0.Bits.FIFOR
#define ATD0STAT0_ETORF _ATD0STAT0.Bits.ETORF
#define ATD0STAT0_SCF _ATD0STAT0.Bits.SCF
#define ATD0STAT0_CC _ATD0STAT0.MergedBits.grpCC


/*** ATD0STAT1 - ATD 0 Status Register 1; 0x0000008B ***/
typedef union {
  byte Byte;
  struct {
    byte CCF0        :1;                                       /* Conversion Complete Flag 0 */
    byte CCF1        :1;                                       /* Conversion Complete Flag 1 */
    byte CCF2        :1;                                       /* Conversion Complete Flag 2 */
    byte CCF3        :1;                                       /* Conversion Complete Flag 3 */
    byte CCF4        :1;                                       /* Conversion Complete Flag 4 */
    byte CCF5        :1;                                       /* Conversion Complete Flag 5 */
    byte CCF6        :1;                                       /* Conversion Complete Flag 6 */
    byte CCF7        :1;                                       /* Conversion Complete Flag 7 */
  } Bits;
  struct {
    byte grpCCF  :8;
  } MergedBits;
} ATD0STAT1STR;
extern volatile ATD0STAT1STR _ATD0STAT1 @(REG_BASE + 0x0000008B);
#define ATD0STAT1 _ATD0STAT1.Byte
#define ATD0STAT1_CCF0 _ATD0STAT1.Bits.CCF0
#define ATD0STAT1_CCF1 _ATD0STAT1.Bits.CCF1
#define ATD0STAT1_CCF2 _ATD0STAT1.Bits.CCF2
#define ATD0STAT1_CCF3 _ATD0STAT1.Bits.CCF3
#define ATD0STAT1_CCF4 _ATD0STAT1.Bits.CCF4
#define ATD0STAT1_CCF5 _ATD0STAT1.Bits.CCF5
#define ATD0STAT1_CCF6 _ATD0STAT1.Bits.CCF6
#define ATD0STAT1_CCF7 _ATD0STAT1.Bits.CCF7
#define ATD0STAT1_CCF _ATD0STAT1.MergedBits.grpCCF


/*** ATD0DIEN - ATD 0 Input Enable Mask Register; 0x0000008D ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* Disable/Enable Digital Input Buffer Bit 0 */
    byte BIT1        :1;                                       /* Disable/Enable Digital Input Buffer Bit 1 */
    byte BIT2        :1;                                       /* Disable/Enable Digital Input Buffer Bit 2 */
    byte BIT3        :1;                                       /* Disable/Enable Digital Input Buffer Bit 3 */
    byte BIT4        :1;                                       /* Disable/Enable Digital Input Buffer Bit 4 */
    byte BIT5        :1;                                       /* Disable/Enable Digital Input Buffer Bit 5 */
    byte BIT6        :1;                                       /* Disable/Enable Digital Input Buffer Bit 6 */
    byte BIT7        :1;                                       /* Disable/Enable Digital Input Buffer Bit 7 */
  } Bits;
  struct {
    byte grpBIT  :8;
  } MergedBits;
} ATD0DIENSTR;
extern volatile ATD0DIENSTR _ATD0DIEN @(REG_BASE + 0x0000008D);
#define ATD0DIEN _ATD0DIEN.Byte
#define ATD0DIEN_BIT0 _ATD0DIEN.Bits.BIT0
#define ATD0DIEN_BIT1 _ATD0DIEN.Bits.BIT1
#define ATD0DIEN_BIT2 _ATD0DIEN.Bits.BIT2
#define ATD0DIEN_BIT3 _ATD0DIEN.Bits.BIT3
#define ATD0DIEN_BIT4 _ATD0DIEN.Bits.BIT4
#define ATD0DIEN_BIT5 _ATD0DIEN.Bits.BIT5
#define ATD0DIEN_BIT6 _ATD0DIEN.Bits.BIT6
#define ATD0DIEN_BIT7 _ATD0DIEN.Bits.BIT7
#define ATD0DIEN_BIT _ATD0DIEN.MergedBits.grpBIT


/*** PORTAD0 - Port AD0 Register; 0x0000008F ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* AN0 */
    byte BIT1        :1;                                       /* AN1 */
    byte BIT2        :1;                                       /* AN2 */
    byte BIT3        :1;                                       /* AN3 */
    byte BIT4        :1;                                       /* AN4 */
    byte BIT5        :1;                                       /* AN5 */
    byte BIT6        :1;                                       /* AN6 */
    byte BIT7        :1;                                       /* AN7 */
  } Bits;
  struct {
    byte grpBIT  :8;
  } MergedBits;
} PORTAD0STR;
extern volatile PORTAD0STR _PORTAD0 @(REG_BASE + 0x0000008F);
#define PORTAD0 _PORTAD0.Byte
#define PORTAD0_BIT0 _PORTAD0.Bits.BIT0
#define PORTAD0_BIT1 _PORTAD0.Bits.BIT1
#define PORTAD0_BIT2 _PORTAD0.Bits.BIT2
#define PORTAD0_BIT3 _PORTAD0.Bits.BIT3
#define PORTAD0_BIT4 _PORTAD0.Bits.BIT4
#define PORTAD0_BIT5 _PORTAD0.Bits.BIT5
#define PORTAD0_BIT6 _PORTAD0.Bits.BIT6
#define PORTAD0_BIT7 _PORTAD0.Bits.BIT7
#define PORTAD0_BIT _PORTAD0.MergedBits.grpBIT


/*** SCI0CR1 - SCI 0 Control Register 1; 0x000000CA ***/
typedef union {
  byte Byte;
  struct {
    byte PT          :1;                                       /* Parity Type Bit */
    byte PE          :1;                                       /* Parity Enable Bit */
    byte ILT         :1;                                       /* Idle Line Type Bit */
    byte WAKE        :1;                                       /* Wakeup Condition Bit */
    byte M           :1;                                       /* Data Format Mode Bit */
    byte RSRC        :1;                                       /* Receiver Source Bit */
    byte SCISWAI     :1;                                       /* SCI 0 Stop in Wait Mode Bit */
    byte LOOPS       :1;                                       /* Loop Select Bit */
  } Bits;
} SCI0CR1STR;
extern volatile SCI0CR1STR _SCI0CR1 @(REG_BASE + 0x000000CA);
#define SCI0CR1 _SCI0CR1.Byte
#define SCI0CR1_PT _SCI0CR1.Bits.PT
#define SCI0CR1_PE _SCI0CR1.Bits.PE
#define SCI0CR1_ILT _SCI0CR1.Bits.ILT
#define SCI0CR1_WAKE _SCI0CR1.Bits.WAKE
#define SCI0CR1_M _SCI0CR1.Bits.M
#define SCI0CR1_RSRC _SCI0CR1.Bits.RSRC
#define SCI0CR1_SCISWAI _SCI0CR1.Bits.SCISWAI
#define SCI0CR1_LOOPS _SCI0CR1.Bits.LOOPS


/*** SCI0CR2 - SCI 0 Control Register 2; 0x000000CB ***/
typedef union {
  byte Byte;
  struct {
    byte SBK         :1;                                       /* Send Break Bit */
    byte RWU         :1;                                       /* Receiver Wakeup Bit */
    byte RE          :1;                                       /* Receiver Enable Bit */
    byte TE          :1;                                       /* Transmitter Enable Bit */
    byte ILIE        :1;                                       /* Idle Line Interrupt Enable Bit */
    byte RIE         :1;                                       /* Receiver Full Interrupt Enable Bit */
    byte TCIE        :1;                                       /* Transmission Complete Interrupt Enable Bit */
    byte SCTIE       :1;                                       /* Transmitter Interrupt Enable Bit */
  } Bits;
} SCI0CR2STR;
extern volatile SCI0CR2STR _SCI0CR2 @(REG_BASE + 0x000000CB);
#define SCI0CR2 _SCI0CR2.Byte
#define SCI0CR2_SBK _SCI0CR2.Bits.SBK
#define SCI0CR2_RWU _SCI0CR2.Bits.RWU
#define SCI0CR2_RE _SCI0CR2.Bits.RE
#define SCI0CR2_TE _SCI0CR2.Bits.TE
#define SCI0CR2_ILIE _SCI0CR2.Bits.ILIE
#define SCI0CR2_RIE _SCI0CR2.Bits.RIE
#define SCI0CR2_TCIE _SCI0CR2.Bits.TCIE
#define SCI0CR2_SCTIE _SCI0CR2.Bits.SCTIE


/*** SCI0SR1 - SCI 0 Status Register 1; 0x000000CC ***/
typedef union {
  byte Byte;
  struct {
    byte PF          :1;                                       /* Parity Error Flag */
    byte FE          :1;                                       /* Framing Error Flag */
    byte NF          :1;                                       /* Noise Flag */
    byte OR          :1;                                       /* Overrun Flag */
    byte IDLE        :1;                                       /* Idle Line Flag */
    byte RDRF        :1;                                       /* Receive Data Register Full Flag */
    byte TC          :1;                                       /* Transmit Complete Flag */
    byte TDRE        :1;                                       /* Transmit Data Register Empty Flag */
  } Bits;
} SCI0SR1STR;
extern volatile SCI0SR1STR _SCI0SR1 @(REG_BASE + 0x000000CC);
#define SCI0SR1 _SCI0SR1.Byte
#define SCI0SR1_PF _SCI0SR1.Bits.PF
#define SCI0SR1_FE _SCI0SR1.Bits.FE
#define SCI0SR1_NF _SCI0SR1.Bits.NF
#define SCI0SR1_OR _SCI0SR1.Bits.OR
#define SCI0SR1_IDLE _SCI0SR1.Bits.IDLE
#define SCI0SR1_RDRF _SCI0SR1.Bits.RDRF
#define SCI0SR1_TC _SCI0SR1.Bits.TC
#define SCI0SR1_TDRE _SCI0SR1.Bits.TDRE


/*** SCI0SR2 - SCI 0 Status Register 2; 0x000000CD ***/
typedef union {
  byte Byte;
  struct {
    byte RAF         :1;                                       /* Receiver Active Flag */
    byte TXDIR       :1;                                       /* Transmitter pin data direction in Single-Wire mode */
    byte BRK13       :1;                                       /* Break Transmit character length */
    byte             :1;
    byte             :1;
    byte             :1;
    byte             :1;
    byte             :1;
  } Bits;
} SCI0SR2STR;
extern volatile SCI0SR2STR _SCI0SR2 @(REG_BASE + 0x000000CD);
#define SCI0SR2 _SCI0SR2.Byte
#define SCI0SR2_RAF _SCI0SR2.Bits.RAF
#define SCI0SR2_TXDIR _SCI0SR2.Bits.TXDIR
#define SCI0SR2_BRK13 _SCI0SR2.Bits.BRK13


/*** SCI0DRH - SCI 0 Data Register High; 0x000000CE ***/
typedef union {
  byte Byte;
  struct {
    byte             :1;
    byte             :1;
    byte             :1;
    byte             :1;
    byte             :1;
    byte             :1;
    byte T8          :1;                                       /* Transmit Bit 8 */
    byte R8          :1;                                       /* Received Bit 8 */
  } Bits;
} SCI0DRHSTR;
extern volatile SCI0DRHSTR _SCI0DRH @(REG_BASE + 0x000000CE);
#define SCI0DRH _SCI0DRH.Byte
#define SCI0DRH_T8 _SCI0DRH.Bits.T8
#define SCI0DRH_R8 _SCI0DRH.Bits.R8


/*** SCI0DRL - SCI 0 Data Register Low; 0x000000CF ***/
typedef union {
  byte Byte;
  struct {
    byte R0_T0       :1;                                       /* Received bit 0 or Transmit bit 0 */
    byte R1_T1       :1;                                       /* Received bit 1 or Transmit bit 1 */
    byte R2_T2       :1;                                       /* Received bit 2 or Transmit bit 2 */
    byte R3_T3       :1;                                       /* Received bit 3 or Transmit bit 3 */
    byte R4_T4       :1;                                       /* Received bit 4 or Transmit bit 4 */
    byte R5_T5       :1;                                       /* Received bit 5 or Transmit bit 5 */
    byte R6_T6       :1;                                       /* Received bit 6 or Transmit bit 6 */
    byte R7_T7       :1;                                       /* Received bit 7 or Transmit bit 7 */
  } Bits;
} SCI0DRLSTR;
extern volatile SCI0DRLSTR _SCI0DRL @(REG_BASE + 0x000000CF);
#define SCI0DRL _SCI0DRL.Byte
#define SCI0DRL_R0_T0 _SCI0DRL.Bits.R0_T0
#define SCI0DRL_R1_T1 _SCI0DRL.Bits.R1_T1
#define SCI0DRL_R2_T2 _SCI0DRL.Bits.R2_T2
#define SCI0DRL_R3_T3 _SCI0DRL.Bits.R3_T3
#define SCI0DRL_R4_T4 _SCI0DRL.Bits.R4_T4
#define SCI0DRL_R5_T5 _SCI0DRL.Bits.R5_T5
#define SCI0DRL_R6_T6 _SCI0DRL.Bits.R6_T6
#define SCI0DRL_R7_T7 _SCI0DRL.Bits.R7_T7


/*** SPI0CR1 - SPI 0 Control Register; 0x000000D8 ***/
typedef union {
  byte Byte;
  struct {
    byte LSBFE       :1;                                       /* SPI 0 LSB-First Enable */
    byte SSOE        :1;                                       /* Slave Select Output Enable */
    byte CPHA        :1;                                       /* SPI 0 Clock Phase Bit */
    byte CPOL        :1;                                       /* SPI 0 Clock Polarity Bit */
    byte MSTR        :1;                                       /* SPI 0 Master/Slave Mode Select Bit */
    byte SPTIE       :1;                                       /* SPI 0 Transmit Interrupt Enable */
    byte SPE         :1;                                       /* SPI 0 System Enable Bit */
    byte SPIE        :1;                                       /* SPI 0 Interrupt Enable Bit */
  } Bits;
} SPI0CR1STR;
extern volatile SPI0CR1STR _SPI0CR1 @(REG_BASE + 0x000000D8);
#define SPI0CR1 _SPI0CR1.Byte
#define SPI0CR1_LSBFE _SPI0CR1.Bits.LSBFE
#define SPI0CR1_SSOE _SPI0CR1.Bits.SSOE
#define SPI0CR1_CPHA _SPI0CR1.Bits.CPHA
#define SPI0CR1_CPOL _SPI0CR1.Bits.CPOL
#define SPI0CR1_MSTR _SPI0CR1.Bits.MSTR
#define SPI0CR1_SPTIE _SPI0CR1.Bits.SPTIE
#define SPI0CR1_SPE _SPI0CR1.Bits.SPE
#define SPI0CR1_SPIE _SPI0CR1.Bits.SPIE


/*** SPI0CR2 - SPI 0 Control Register 2; 0x000000D9 ***/
typedef union {
  byte Byte;
  struct {
    byte SPC0        :1;                                       /* Serial Pin Control Bit 0 */
    byte SPISWAI     :1;                                       /* SPI 0 Stop in Wait Mode Bit */
    byte             :1;
    byte BIDIROE     :1;                                       /* Output enable in the Bidirectional mode of operation */
    byte MODFEN      :1;                                       /* Mode Fault Enable Bit */
    byte             :1;
    byte             :1;
    byte             :1;
  } Bits;
} SPI0CR2STR;
extern volatile SPI0CR2STR _SPI0CR2 @(REG_BASE + 0x000000D9);
#define SPI0CR2 _SPI0CR2.Byte
#define SPI0CR2_SPC0 _SPI0CR2.Bits.SPC0
#define SPI0CR2_SPISWAI _SPI0CR2.Bits.SPISWAI
#define SPI0CR2_BIDIROE _SPI0CR2.Bits.BIDIROE
#define SPI0CR2_MODFEN _SPI0CR2.Bits.MODFEN


/*** SPI0BR - SPI 0 Baud Rate Register; 0x000000DA ***/
typedef union {
  byte Byte;
  struct {
    byte SPR0        :1;                                       /* SPI 0 Baud Rate Selection Bit 0 */
    byte SPR1        :1;                                       /* SPI 0 Baud Rate Selection Bit 1 */
    byte SPR2        :1;                                       /* SPI 0 Baud Rate Selection Bit 2 */
    byte             :1;
    byte SPPR0       :1;                                       /* SPI 0 Baud Rate Preselection Bits 0 */
    byte SPPR1       :1;                                       /* SPI 0 Baud Rate Preselection Bits 1 */
    byte SPPR2       :1;                                       /* SPI 0 Baud Rate Preselection Bits 2 */
    byte             :1;
  } Bits;
  struct {
    byte grpSPR  :3;
    byte         :1;
    byte grpSPPR :3;
    byte         :1;
  } MergedBits;
} SPI0BRSTR;
extern volatile SPI0BRSTR _SPI0BR @(REG_BASE + 0x000000DA);
#define SPI0BR _SPI0BR.Byte
#define SPI0BR_SPR0 _SPI0BR.Bits.SPR0
#define SPI0BR_SPR1 _SPI0BR.Bits.SPR1
#define SPI0BR_SPR2 _SPI0BR.Bits.SPR2
#define SPI0BR_SPPR0 _SPI0BR.Bits.SPPR0
#define SPI0BR_SPPR1 _SPI0BR.Bits.SPPR1
#define SPI0BR_SPPR2 _SPI0BR.Bits.SPPR2
#define SPI0BR_SPR _SPI0BR.MergedBits.grpSPR
#define SPI0BR_SPPR _SPI0BR.MergedBits.grpSPPR


/*** SPI0SR - SPI 0 Status Register; 0x000000DB ***/
typedef union {
  byte Byte;
  struct {
    byte             :1;
    byte             :1;
    byte             :1;
    byte             :1;
    byte MODF        :1;                                       /* Mode Fault Flag */
    byte SPTEF       :1;                                       /* SPI 0 Transmit Empty Interrupt Flag */
    byte             :1;
    byte SPIF        :1;                                       /* SPIF Receive Interrupt Flag */
  } Bits;
} SPI0SRSTR;
extern volatile SPI0SRSTR _SPI0SR @(REG_BASE + 0x000000DB);
#define SPI0SR _SPI0SR.Byte
#define SPI0SR_MODF _SPI0SR.Bits.MODF
#define SPI0SR_SPTEF _SPI0SR.Bits.SPTEF
#define SPI0SR_SPIF _SPI0SR.Bits.SPIF


/*** SPI0DR - SPI 0 Data Register; 0x000000DD ***/
typedef union {
  byte Byte;
  struct {
    byte grpBIT  :8;
  } MergedBits;
} SPI0DRSTR;
extern volatile SPI0DRSTR _SPI0DR @(REG_BASE + 0x000000DD);
#define SPI0DR _SPI0DR.Byte
#define SPI0DR_BIT _SPI0DR.MergedBits.grpBIT


/*** FCLKDIV - Flash Clock Divider Register; 0x00000100 ***/
typedef union {
  byte Byte;
  struct {
    byte FDIV0       :1;                                       /* Flash Clock Divider Bit 0 */
    byte FDIV1       :1;                                       /* Flash Clock Divider Bit 1 */
    byte FDIV2       :1;                                       /* Flash Clock Divider Bit 2 */
    byte FDIV3       :1;                                       /* Flash Clock Divider Bit 3 */
    byte FDIV4       :1;                                       /* Flash Clock Divider Bit 4 */
    byte FDIV5       :1;                                       /* Flash Clock Divider Bit 5 */
    byte PRDIV8      :1;                                       /* Enable Prescaler by 8 */
    byte FDIVLD      :1;                                       /* Flash Clock Divider Loaded */
  } Bits;
  struct {
    byte grpFDIV :6;
    byte grpPRDIV_8 :1;
    byte         :1;
  } MergedBits;
} FCLKDIVSTR;
extern volatile FCLKDIVSTR _FCLKDIV @(REG_BASE + 0x00000100);
#define FCLKDIV _FCLKDIV.Byte
#define FCLKDIV_FDIV0 _FCLKDIV.Bits.FDIV0
#define FCLKDIV_FDIV1 _FCLKDIV.Bits.FDIV1
#define FCLKDIV_FDIV2 _FCLKDIV.Bits.FDIV2
#define FCLKDIV_FDIV3 _FCLKDIV.Bits.FDIV3
#define FCLKDIV_FDIV4 _FCLKDIV.Bits.FDIV4
#define FCLKDIV_FDIV5 _FCLKDIV.Bits.FDIV5
#define FCLKDIV_PRDIV8 _FCLKDIV.Bits.PRDIV8
#define FCLKDIV_FDIVLD _FCLKDIV.Bits.FDIVLD
#define FCLKDIV_FDIV _FCLKDIV.MergedBits.grpFDIV


/*** FSEC - Flash Security Register; 0x00000101 ***/
typedef union {
  byte Byte;
  struct {
    byte SEC0        :1;                                       /* Memory security bit 0 */
    byte SEC1        :1;                                       /* Memory security bit 1 */
    byte NV2         :1;                                       /* Non Volatile flag bit 2 */
    byte NV3         :1;                                       /* Non Volatile flag bit 3 */
    byte NV4         :1;                                       /* Non Volatile flag bit 4 */
    byte NV5         :1;                                       /* Non Volatile flag bit 5 */
    byte NV6         :1;                                       /* Non Volatile flag bit 6 */
    byte KEYEN       :1;                                       /* Enable backdoor key to security */
  } Bits;
  struct {
    byte grpSEC  :2;
    byte grpNV_2 :5;
    byte         :1;
  } MergedBits;
} FSECSTR;
extern volatile FSECSTR _FSEC @(REG_BASE + 0x00000101);
#define FSEC _FSEC.Byte
#define FSEC_SEC0 _FSEC.Bits.SEC0
#define FSEC_SEC1 _FSEC.Bits.SEC1
#define FSEC_NV2 _FSEC.Bits.NV2
#define FSEC_NV3 _FSEC.Bits.NV3
#define FSEC_NV4 _FSEC.Bits.NV4
#define FSEC_NV5 _FSEC.Bits.NV5
#define FSEC_NV6 _FSEC.Bits.NV6
#define FSEC_KEYEN _FSEC.Bits.KEYEN
#define FSEC_SEC _FSEC.MergedBits.grpSEC
#define FSEC_NV_2 _FSEC.MergedBits.grpNV_2
#define FSEC_NV FSEC_NV_2


/*** FCNFG - Flash Configuration Register; 0x00000103 ***/
typedef union {
  byte Byte;
  struct {
    byte BKSEL0      :1;                                       /* Register bank select 0 */
    byte BKSEL1      :1;                                       /* Register bank select 1 */
    byte             :1;
    byte             :1;
    byte             :1;
    byte KEYACC      :1;                                       /* Enable Security Key Writing */
    byte CCIE        :1;                                       /* Command Complete Interrupt Enable */
    byte CBEIE       :1;                                       /* Command Buffers Empty Interrupt Enable */
  } Bits;
  struct {
    byte grpBKSEL :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} FCNFGSTR;
extern volatile FCNFGSTR _FCNFG @(REG_BASE + 0x00000103);
#define FCNFG _FCNFG.Byte
#define FCNFG_BKSEL0 _FCNFG.Bits.BKSEL0
#define FCNFG_BKSEL1 _FCNFG.Bits.BKSEL1
#define FCNFG_KEYACC _FCNFG.Bits.KEYACC
#define FCNFG_CCIE _FCNFG.Bits.CCIE
#define FCNFG_CBEIE _FCNFG.Bits.CBEIE
#define FCNFG_BKSEL _FCNFG.MergedBits.grpBKSEL


/*** FPROT - Flash Protection Register; 0x00000104 ***/
typedef union {
  byte Byte;
  struct {
    byte FPLS0       :1;                                       /* Flash Protection Lower Address size 0 */
    byte FPLS1       :1;                                       /* Flash Protection Lower Address size 1 */
    byte FPLDIS      :1;                                       /* Flash Protection Lower address range disable */
    byte FPHS0       :1;                                       /* Flash Protection Higher address size 0 */
    byte FPHS1       :1;                                       /* Flash Protection Higher address size 1 */
    byte FPHDIS      :1;                                       /* Flash Protection Higher address range disable */
    byte NV6         :1;                                       /* Non Volatile Flag Bit */
    byte FPOPEN      :1;                                       /* Opens the flash block or subsections of it for program or erase */
  } Bits;
  struct {
    byte grpFPLS :2;
    byte         :1;
    byte grpFPHS :2;
    byte         :1;
    byte grpNV_6 :1;
    byte         :1;
  } MergedBits;
} FPROTSTR;
extern volatile FPROTSTR _FPROT @(REG_BASE + 0x00000104);
#define FPROT _FPROT.Byte
#define FPROT_FPLS0 _FPROT.Bits.FPLS0
#define FPROT_FPLS1 _FPROT.Bits.FPLS1
#define FPROT_FPLDIS _FPROT.Bits.FPLDIS
#define FPROT_FPHS0 _FPROT.Bits.FPHS0
#define FPROT_FPHS1 _FPROT.Bits.FPHS1
#define FPROT_FPHDIS _FPROT.Bits.FPHDIS
#define FPROT_NV6 _FPROT.Bits.NV6
#define FPROT_FPOPEN _FPROT.Bits.FPOPEN
#define FPROT_FPLS _FPROT.MergedBits.grpFPLS
#define FPROT_FPHS _FPROT.MergedBits.grpFPHS


/*** FSTAT - Flash Status Register; 0x00000105 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1;
    byte             :1;
    byte BLANK       :1;                                       /* Blank Verify Flag */
    byte             :1;
    byte ACCERR      :1;                                       /* Access error */
    byte PVIOL       :1;                                       /* Protection violation */
    byte CCIF        :1;                                       /* Command Complete Interrupt Flag */
    byte CBEIF       :1;                                       /* Command Buffers Empty Interrupt Flag */
  } Bits;
} FSTATSTR;
extern volatile FSTATSTR _FSTAT @(REG_BASE + 0x00000105);
#define FSTAT _FSTAT.Byte
#define FSTAT_BLANK _FSTAT.Bits.BLANK
#define FSTAT_ACCERR _FSTAT.Bits.ACCERR
#define FSTAT_PVIOL _FSTAT.Bits.PVIOL
#define FSTAT_CCIF _FSTAT.Bits.CCIF
#define FSTAT_CBEIF _FSTAT.Bits.CBEIF


/*** FCMD - Flash Command Buffer and Register; 0x00000106 ***/
typedef union {
  byte Byte;
  struct {
    byte CMDB0       :1;                                       /* NVM User Mode Command Bit 0 */
    byte             :1;
    byte CMDB2       :1;                                       /* NVM User Mode Command Bit 2 */
    byte             :1;
    byte             :1;
    byte CMDB5       :1;                                       /* NVM User Mode Command Bit 5 */
    byte CMDB6       :1;                                       /* NVM User Mode Command Bit 6 */
    byte             :1;
  } Bits;
  struct {
    byte grpCMDB :1;
    byte         :1;
    byte grpCMDB_2 :1;
    byte         :1;
    byte         :1;
    byte grpCMDB_5 :2;
    byte         :1;
  } MergedBits;
} FCMDSTR;
extern volatile FCMDSTR _FCMD @(REG_BASE + 0x00000106);
#define FCMD _FCMD.Byte
#define FCMD_CMDB0 _FCMD.Bits.CMDB0
#define FCMD_CMDB2 _FCMD.Bits.CMDB2
#define FCMD_CMDB5 _FCMD.Bits.CMDB5
#define FCMD_CMDB6 _FCMD.Bits.CMDB6
#define FCMD_CMDB_5 _FCMD.MergedBits.grpCMDB_5
#define FCMD_CMDB FCMD_CMDB_5


/*** ECLKDIV - EEPROM Clock Divider Register; 0x00000110 ***/
typedef union {
  byte Byte;
  struct {
    byte EDIV0       :1;                                       /* EEPROM Clock Divider 0 */
    byte EDIV1       :1;                                       /* EEPROM Clock Divider 1 */
    byte EDIV2       :1;                                       /* EEPROM Clock Divider 2 */
    byte EDIV3       :1;                                       /* EEPROM Clock Divider 3 */
    byte EDIV4       :1;                                       /* EEPROM Clock Divider 4 */
    byte EDIV5       :1;                                       /* EEPROM Clock Divider 5 */
    byte PRDIV8      :1;                                       /* Enable Prescaler by 8 */
    byte EDIVLD      :1;                                       /* EEPROM Clock Divider Loaded */
  } Bits;
  struct {
    byte grpEDIV :6;
    byte grpPRDIV_8 :1;
    byte         :1;
  } MergedBits;
} ECLKDIVSTR;
extern volatile ECLKDIVSTR _ECLKDIV @(REG_BASE + 0x00000110);
#define ECLKDIV _ECLKDIV.Byte
#define ECLKDIV_EDIV0 _ECLKDIV.Bits.EDIV0
#define ECLKDIV_EDIV1 _ECLKDIV.Bits.EDIV1
#define ECLKDIV_EDIV2 _ECLKDIV.Bits.EDIV2
#define ECLKDIV_EDIV3 _ECLKDIV.Bits.EDIV3
#define ECLKDIV_EDIV4 _ECLKDIV.Bits.EDIV4
#define ECLKDIV_EDIV5 _ECLKDIV.Bits.EDIV5
#define ECLKDIV_PRDIV8 _ECLKDIV.Bits.PRDIV8
#define ECLKDIV_EDIVLD _ECLKDIV.Bits.EDIVLD
#define ECLKDIV_EDIV _ECLKDIV.MergedBits.grpEDIV


/*** ECNFG - EEPROM Configuration Register; 0x00000113 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1;
    byte             :1;
    byte             :1;
    byte             :1;
    byte             :1;
    byte             :1;
    byte CCIE        :1;                                       /* Command Complete Interrupt Enable */
    byte CBEIE       :1;                                       /* Command Buffers Empty Interrupt Enable */
  } Bits;
} ECNFGSTR;
extern volatile ECNFGSTR _ECNFG @(REG_BASE + 0x00000113);
#define ECNFG _ECNFG.Byte
#define ECNFG_CCIE _ECNFG.Bits.CCIE
#define ECNFG_CBEIE _ECNFG.Bits.CBEIE


/*** EPROT - EEPROM Protection Register; 0x00000114 ***/
typedef union {
  byte Byte;
  struct {
    byte EP0         :1;                                       /* EEPROM Protection address size 0 */
    byte EP1         :1;                                       /* EEPROM Protection address size 1 */
    byte EP2         :1;                                       /* EEPROM Protection address size 2 */
    byte EPDIS       :1;                                       /* EEPROM Protection disable */
    byte             :1;
    byte             :1;
    byte             :1;
    byte EPOPEN      :1;                                       /* Opens the EEPROM block or a subsection of it for program or erase */
  } Bits;
  struct {
    byte grpEP   :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} EPROTSTR;
extern volatile EPROTSTR _EPROT @(REG_BASE + 0x00000114);
#define EPROT _EPROT.Byte
#define EPROT_EP0 _EPROT.Bits.EP0
#define EPROT_EP1 _EPROT.Bits.EP1
#define EPROT_EP2 _EPROT.Bits.EP2
#define EPROT_EPDIS _EPROT.Bits.EPDIS
#define EPROT_EPOPEN _EPROT.Bits.EPOPEN
#define EPROT_EP _EPROT.MergedBits.grpEP


/*** ESTAT - EEPROM Status Register; 0x00000115 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1;
    byte             :1;
    byte BLANK       :1;                                       /* Blank Verify Flag */
    byte             :1;
    byte ACCERR      :1;                                       /* Access error */
    byte PVIOL       :1;                                       /* Protection violation */
    byte CCIF        :1;                                       /* Command Complete Interrupt Flag */
    byte CBEIF       :1;                                       /* Command Buffer Empty Interrupt Flag */
  } Bits;
} ESTATSTR;
extern volatile ESTATSTR _ESTAT @(REG_BASE + 0x00000115);
#define ESTAT _ESTAT.Byte
#define ESTAT_BLANK _ESTAT.Bits.BLANK
#define ESTAT_ACCERR _ESTAT.Bits.ACCERR
#define ESTAT_PVIOL _ESTAT.Bits.PVIOL
#define ESTAT_CCIF _ESTAT.Bits.CCIF
#define ESTAT_CBEIF _ESTAT.Bits.CBEIF


/*** ECMD - EEPROM Command Buffer and Register; 0x00000116 ***/
typedef union {
  byte Byte;
  struct {
    byte CMDB0       :1;                                       /* EEPROM User Mode Command 0 */
    byte             :1;
    byte CMDB2       :1;                                       /* EEPROM User Mode Command 2 */
    byte             :1;
    byte             :1;
    byte CMDB5       :1;                                       /* EEPROM User Mode Command 5 */
    byte CMDB6       :1;                                       /* EEPROM User Mode Command 6 */
    byte             :1;
  } Bits;
  struct {
    byte grpCMDB :1;
    byte         :1;
    byte grpCMDB_2 :1;
    byte         :1;
    byte         :1;
    byte grpCMDB_5 :2;
    byte         :1;
  } MergedBits;
} ECMDSTR;
extern volatile ECMDSTR _ECMD @(REG_BASE + 0x00000116);
#define ECMD _ECMD.Byte
#define ECMD_CMDB0 _ECMD.Bits.CMDB0
#define ECMD_CMDB2 _ECMD.Bits.CMDB2
#define ECMD_CMDB5 _ECMD.Bits.CMDB5
#define ECMD_CMDB6 _ECMD.Bits.CMDB6
#define ECMD_CMDB_5 _ECMD.MergedBits.grpCMDB_5
#define ECMD_CMDB ECMD_CMDB_5


/*** PTT - Port T I/O Register; 0x00000240 ***/
typedef union {
  byte Byte;
  struct {
    byte PTT0        :1;                                       /* Port T Bit 0 */
    byte PTT1        :1;                                       /* Port T Bit 1 */
    byte PTT2        :1;                                       /* Port T Bit 2 */
    byte PTT3        :1;                                       /* Port T Bit 3 */
    byte PTT4        :1;                                       /* Port T Bit 4 */
    byte PTT5        :1;                                       /* Port T Bit 5 */
    byte PTT6        :1;                                       /* Port T Bit 6 */
    byte PTT7        :1;                                       /* Port T Bit 7 */
  } Bits;
  struct {
    byte grpPTT  :8;
  } MergedBits;
} PTTSTR;
extern volatile PTTSTR _PTT @(REG_BASE + 0x00000240);
#define PTT _PTT.Byte
#define PTT_PTT0 _PTT.Bits.PTT0
#define PTT_PTT1 _PTT.Bits.PTT1
#define PTT_PTT2 _PTT.Bits.PTT2
#define PTT_PTT3 _PTT.Bits.PTT3
#define PTT_PTT4 _PTT.Bits.PTT4
#define PTT_PTT5 _PTT.Bits.PTT5
#define PTT_PTT6 _PTT.Bits.PTT6
#define PTT_PTT7 _PTT.Bits.PTT7
#define PTT_PTT _PTT.MergedBits.grpPTT


/*** PTIT - Port T Input; 0x00000241 ***/
typedef union {
  byte Byte;
  struct {
    byte PTIT0       :1;                                       /* Port T Bit 0 */
    byte PTIT1       :1;                                       /* Port T Bit 1 */
    byte PTIT2       :1;                                       /* Port T Bit 2 */
    byte PTIT3       :1;                                       /* Port T Bit 3 */
    byte PTIT4       :1;                                       /* Port T Bit 4 */
    byte PTIT5       :1;                                       /* Port T Bit 5 */
    byte PTIT6       :1;                                       /* Port T Bit 6 */
    byte PTIT7       :1;                                       /* Port T Bit 7 */
  } Bits;
  struct {
    byte grpPTIT :8;
  } MergedBits;
} PTITSTR;
extern volatile PTITSTR _PTIT @(REG_BASE + 0x00000241);
#define PTIT _PTIT.Byte
#define PTIT_PTIT0 _PTIT.Bits.PTIT0
#define PTIT_PTIT1 _PTIT.Bits.PTIT1
#define PTIT_PTIT2 _PTIT.Bits.PTIT2
#define PTIT_PTIT3 _PTIT.Bits.PTIT3
#define PTIT_PTIT4 _PTIT.Bits.PTIT4
#define PTIT_PTIT5 _PTIT.Bits.PTIT5
#define PTIT_PTIT6 _PTIT.Bits.PTIT6
#define PTIT_PTIT7 _PTIT.Bits.PTIT7
#define PTIT_PTIT _PTIT.MergedBits.grpPTIT


/*** DDRT - Port T Data Direction Register; 0x00000242 ***/
typedef union {
  byte Byte;
  struct {
    byte DDRT0       :1;                                       /* Data Direction Port T Bit 0 */
    byte DDRT1       :1;                                       /* Data Direction Port T Bit 1 */
    byte DDRT2       :1;                                       /* Data Direction Port T Bit 2 */
    byte DDRT3       :1;                                       /* Data Direction Port T Bit 3 */
    byte DDRT4       :1;                                       /* Data Direction Port T Bit 4 */
    byte DDRT5       :1;                                       /* Data Direction Port T Bit 5 */
    byte DDRT6       :1;                                       /* Data Direction Port T Bit 6 */
    byte DDRT7       :1;                                       /* Data Direction Port T Bit 7 */
  } Bits;
  struct {
    byte grpDDRT :8;
  } MergedBits;
} DDRTSTR;
extern volatile DDRTSTR _DDRT @(REG_BASE + 0x00000242);
#define DDRT _DDRT.Byte
#define DDRT_DDRT0 _DDRT.Bits.DDRT0
#define DDRT_DDRT1 _DDRT.Bits.DDRT1
#define DDRT_DDRT2 _DDRT.Bits.DDRT2
#define DDRT_DDRT3 _DDRT.Bits.DDRT3
#define DDRT_DDRT4 _DDRT.Bits.DDRT4
#define DDRT_DDRT5 _DDRT.Bits.DDRT5
#define DDRT_DDRT6 _DDRT.Bits.DDRT6
#define DDRT_DDRT7 _DDRT.Bits.DDRT7
#define DDRT_DDRT _DDRT.MergedBits.grpDDRT


/*** RDRT - Port T Reduced Drive Register; 0x00000243 ***/
typedef union {
  byte Byte;
  struct {
    byte RDRT0       :1;                                       /* Reduced Drive Port T Bit 0 */
    byte RDRT1       :1;                                       /* Reduced Drive Port T Bit 1 */
    byte RDRT2       :1;                                       /* Reduced Drive Port T Bit 2 */
    byte RDRT3       :1;                                       /* Reduced Drive Port T Bit 3 */
    byte RDRT4       :1;                                       /* Reduced Drive Port T Bit 4 */
    byte RDRT5       :1;                                       /* Reduced Drive Port T Bit 5 */
    byte RDRT6       :1;                                       /* Reduced Drive Port T Bit 6 */
    byte RDRT7       :1;                                       /* Reduced Drive Port T Bit 7 */
  } Bits;
  struct {
    byte grpRDRT :8;
  } MergedBits;
} RDRTSTR;
extern volatile RDRTSTR _RDRT @(REG_BASE + 0x00000243);
#define RDRT _RDRT.Byte
#define RDRT_RDRT0 _RDRT.Bits.RDRT0
#define RDRT_RDRT1 _RDRT.Bits.RDRT1
#define RDRT_RDRT2 _RDRT.Bits.RDRT2
#define RDRT_RDRT3 _RDRT.Bits.RDRT3
#define RDRT_RDRT4 _RDRT.Bits.RDRT4
#define RDRT_RDRT5 _RDRT.Bits.RDRT5
#define RDRT_RDRT6 _RDRT.Bits.RDRT6
#define RDRT_RDRT7 _RDRT.Bits.RDRT7
#define RDRT_RDRT _RDRT.MergedBits.grpRDRT


/*** PERT - Port T Pull Device Enable Register; 0x00000244 ***/
typedef union {
  byte Byte;
  struct {
    byte PERT0       :1;                                       /* Pull Device Enable Port T Bit 0 */
    byte PERT1       :1;                                       /* Pull Device Enable Port T Bit 1 */
    byte PERT2       :1;                                       /* Pull Device Enable Port T Bit 2 */
    byte PERT3       :1;                                       /* Pull Device Enable Port T Bit 3 */
    byte PERT4       :1;                                       /* Pull Device Enable Port T Bit 4 */
    byte PERT5       :1;                                       /* Pull Device Enable Port T Bit 5 */
    byte PERT6       :1;                                       /* Pull Device Enable Port T Bit 6 */
    byte PERT7       :1;                                       /* Pull Device Enable Port T Bit 7 */
  } Bits;
  struct {
    byte grpPERT :8;
  } MergedBits;
} PERTSTR;
extern volatile PERTSTR _PERT @(REG_BASE + 0x00000244);
#define PERT _PERT.Byte
#define PERT_PERT0 _PERT.Bits.PERT0
#define PERT_PERT1 _PERT.Bits.PERT1
#define PERT_PERT2 _PERT.Bits.PERT2
#define PERT_PERT3 _PERT.Bits.PERT3
#define PERT_PERT4 _PERT.Bits.PERT4
#define PERT_PERT5 _PERT.Bits.PERT5
#define PERT_PERT6 _PERT.Bits.PERT6
#define PERT_PERT7 _PERT.Bits.PERT7
#define PERT_PERT _PERT.MergedBits.grpPERT


/*** PPST - Port T Polarity Select Register; 0x00000245 ***/
typedef union {
  byte Byte;
  struct {
    byte PPST0       :1;                                       /* Pull Select Port T Bit 0 */
    byte PPST1       :1;                                       /* Pull Select Port T Bit 1 */
    byte PPST2       :1;                                       /* Pull Select Port T Bit 2 */
    byte PPST3       :1;                                       /* Pull Select Port T Bit 3 */
    byte PPST4       :1;                                       /* Pull Select Port T Bit 4 */
    byte PPST5       :1;                                       /* Pull Select Port T Bit 5 */
    byte PPST6       :1;                                       /* Pull Select Port T Bit 6 */
    byte PPST7       :1;                                       /* Pull Select Port T Bit 7 */
  } Bits;
  struct {
    byte grpPPST :8;
  } MergedBits;
} PPSTSTR;
extern volatile PPSTSTR _PPST @(REG_BASE + 0x00000245);
#define PPST _PPST.Byte
#define PPST_PPST0 _PPST.Bits.PPST0
#define PPST_PPST1 _PPST.Bits.PPST1
#define PPST_PPST2 _PPST.Bits.PPST2
#define PPST_PPST3 _PPST.Bits.PPST3
#define PPST_PPST4 _PPST.Bits.PPST4
#define PPST_PPST5 _PPST.Bits.PPST5
#define PPST_PPST6 _PPST.Bits.PPST6
#define PPST_PPST7 _PPST.Bits.PPST7
#define PPST_PPST _PPST.MergedBits.grpPPST


/*** PTS - Port S I/O Register; 0x00000248 ***/
typedef union {
  byte Byte;
  struct {
    byte PTS0        :1;                                       /* Port S Bit 0 */
    byte PTS1        :1;                                       /* Port S Bit 1 */
    byte PTS2        :1;                                       /* Port S Bit 2 */
    byte PTS3        :1;                                       /* Port S Bit 3 */
    byte PTS4        :1;                                       /* Port S Bit 4 */
    byte PTS5        :1;                                       /* Port S Bit 5 */
    byte PTS6        :1;                                       /* Port S Bit 6 */
    byte PTS7        :1;                                       /* Port S Bit 7 */
  } Bits;
  struct {
    byte grpPTS  :8;
  } MergedBits;
} PTSSTR;
extern volatile PTSSTR _PTS @(REG_BASE + 0x00000248);
#define PTS _PTS.Byte
#define PTS_PTS0 _PTS.Bits.PTS0
#define PTS_PTS1 _PTS.Bits.PTS1
#define PTS_PTS2 _PTS.Bits.PTS2
#define PTS_PTS3 _PTS.Bits.PTS3
#define PTS_PTS4 _PTS.Bits.PTS4
#define PTS_PTS5 _PTS.Bits.PTS5
#define PTS_PTS6 _PTS.Bits.PTS6
#define PTS_PTS7 _PTS.Bits.PTS7
#define PTS_PTS _PTS.MergedBits.grpPTS


/*** PTIS - Port S Input; 0x00000249 ***/
typedef union {
  byte Byte;
  struct {
    byte PTIS0       :1;                                       /* Port S Bit 0 */
    byte PTIS1       :1;                                       /* Port S Bit 1 */
    byte PTIS2       :1;                                       /* Port S Bit 2 */
    byte PTIS3       :1;                                       /* Port S Bit 3 */
    byte PTIS4       :1;                                       /* Port S Bit 4 */
    byte PTIS5       :1;                                       /* Port S Bit 5 */
    byte PTIS6       :1;                                       /* Port S Bit 6 */
    byte PTIS7       :1;                                       /* Port S Bit 7 */
  } Bits;
  struct {
    byte grpPTIS :8;
  } MergedBits;
} PTISSTR;
extern volatile PTISSTR _PTIS @(REG_BASE + 0x00000249);
#define PTIS _PTIS.Byte
#define PTIS_PTIS0 _PTIS.Bits.PTIS0
#define PTIS_PTIS1 _PTIS.Bits.PTIS1
#define PTIS_PTIS2 _PTIS.Bits.PTIS2
#define PTIS_PTIS3 _PTIS.Bits.PTIS3
#define PTIS_PTIS4 _PTIS.Bits.PTIS4
#define PTIS_PTIS5 _PTIS.Bits.PTIS5
#define PTIS_PTIS6 _PTIS.Bits.PTIS6
#define PTIS_PTIS7 _PTIS.Bits.PTIS7
#define PTIS_PTIS _PTIS.MergedBits.grpPTIS


/*** DDRS - Port S Data Direction Register; 0x0000024A ***/
typedef union {
  byte Byte;
  struct {
    byte DDRS0       :1;                                       /* Data Direction Port S Bit 0 */
    byte DDRS1       :1;                                       /* Data Direction Port S Bit 1 */
    byte DDRS2       :1;                                       /* Data Direction Port S Bit  2 */
    byte DDRS3       :1;                                       /* Data Direction Port S Bit 3 */
    byte DDRS4       :1;                                       /* Data Direction Port S Bit 4 */
    byte DDRS5       :1;                                       /* Data Direction Port S Bit 5 */
    byte DDRS6       :1;                                       /* Data Direction Port S Bit 6 */
    byte DDRS7       :1;                                       /* Data Direction Port S Bit 7 */
  } Bits;
  struct {
    byte grpDDRS :8;
  } MergedBits;
} DDRSSTR;
extern volatile DDRSSTR _DDRS @(REG_BASE + 0x0000024A);
#define DDRS _DDRS.Byte
#define DDRS_DDRS0 _DDRS.Bits.DDRS0
#define DDRS_DDRS1 _DDRS.Bits.DDRS1
#define DDRS_DDRS2 _DDRS.Bits.DDRS2
#define DDRS_DDRS3 _DDRS.Bits.DDRS3
#define DDRS_DDRS4 _DDRS.Bits.DDRS4
#define DDRS_DDRS5 _DDRS.Bits.DDRS5
#define DDRS_DDRS6 _DDRS.Bits.DDRS6
#define DDRS_DDRS7 _DDRS.Bits.DDRS7
#define DDRS_DDRS _DDRS.MergedBits.grpDDRS


/*** RDRS - Port S Reduced Drive Register; 0x0000024B ***/
typedef union {
  byte Byte;
  struct {
    byte RDRS0       :1;                                       /* Reduced Drive Port S Bit 0 */
    byte RDRS1       :1;                                       /* Reduced Drive Port S Bit 1 */
    byte RDRS2       :1;                                       /* Reduced Drive Port S Bit 2 */
    byte RDRS3       :1;                                       /* Reduced Drive Port S Bit 3 */
    byte RDRS4       :1;                                       /* Reduced Drive Port S Bit 4 */
    byte RDRS5       :1;                                       /* Reduced Drive Port S Bit 5 */
    byte RDRS6       :1;                                       /* Reduced Drive Port S Bit 6 */
    byte RDRS7       :1;                                       /* Reduced Drive Port S Bit 7 */
  } Bits;
  struct {
    byte grpRDRS :8;
  } MergedBits;
} RDRSSTR;
extern volatile RDRSSTR _RDRS @(REG_BASE + 0x0000024B);
#define RDRS _RDRS.Byte
#define RDRS_RDRS0 _RDRS.Bits.RDRS0
#define RDRS_RDRS1 _RDRS.Bits.RDRS1
#define RDRS_RDRS2 _RDRS.Bits.RDRS2
#define RDRS_RDRS3 _RDRS.Bits.RDRS3
#define RDRS_RDRS4 _RDRS.Bits.RDRS4
#define RDRS_RDRS5 _RDRS.Bits.RDRS5
#define RDRS_RDRS6 _RDRS.Bits.RDRS6
#define RDRS_RDRS7 _RDRS.Bits.RDRS7
#define RDRS_RDRS _RDRS.MergedBits.grpRDRS


/*** PERS - Port S Pull Device Enable Register; 0x0000024C ***/
typedef union {
  byte Byte;
  struct {
    byte PERS0       :1;                                       /* Pull Device Enable Port S Bit 0 */
    byte PERS1       :1;                                       /* Pull Device Enable Port S Bit 1 */
    byte PERS2       :1;                                       /* Pull Device Enable Port S Bit 2 */
    byte PERS3       :1;                                       /* Pull Device Enable Port S Bit 3 */
    byte PERS4       :1;                                       /* Pull Device Enable Port S Bit 4 */
    byte PERS5       :1;                                       /* Pull Device Enable Port S Bit 5 */
    byte PERS6       :1;                                       /* Pull Device Enable Port S Bit 6 */
    byte PERS7       :1;                                       /* Pull Device Enable Port S Bit 7 */
  } Bits;
  struct {
    byte grpPERS :8;
  } MergedBits;
} PERSSTR;
extern volatile PERSSTR _PERS @(REG_BASE + 0x0000024C);
#define PERS _PERS.Byte
#define PERS_PERS0 _PERS.Bits.PERS0
#define PERS_PERS1 _PERS.Bits.PERS1
#define PERS_PERS2 _PERS.Bits.PERS2
#define PERS_PERS3 _PERS.Bits.PERS3
#define PERS_PERS4 _PERS.Bits.PERS4
#define PERS_PERS5 _PERS.Bits.PERS5
#define PERS_PERS6 _PERS.Bits.PERS6
#define PERS_PERS7 _PERS.Bits.PERS7
#define PERS_PERS _PERS.MergedBits.grpPERS


/*** PPSS - Port S Polarity Select Register; 0x0000024D ***/
typedef union {
  byte Byte;
  struct {
    byte PPSS0       :1;                                       /* Pull Select Port S Bit 0 */
    byte PPSS1       :1;                                       /* Pull Select Port S Bit 1 */
    byte PPSS2       :1;                                       /* Pull Select Port S Bit 2 */
    byte PPSS3       :1;                                       /* Pull Select Port S Bit 3 */
    byte PPSS4       :1;                                       /* Pull Select Port S Bit 4 */
    byte PPSS5       :1;                                       /* Pull Select Port S Bit 5 */
    byte PPSS6       :1;                                       /* Pull Select Port S Bit 6 */
    byte PPSS7       :1;                                       /* Pull Select Port S Bit 7 */
  } Bits;
  struct {
    byte grpPPSS :8;
  } MergedBits;
} PPSSSTR;
extern volatile PPSSSTR _PPSS @(REG_BASE + 0x0000024D);
#define PPSS _PPSS.Byte
#define PPSS_PPSS0 _PPSS.Bits.PPSS0
#define PPSS_PPSS1 _PPSS.Bits.PPSS1
#define PPSS_PPSS2 _PPSS.Bits.PPSS2
#define PPSS_PPSS3 _PPSS.Bits.PPSS3
#define PPSS_PPSS4 _PPSS.Bits.PPSS4
#define PPSS_PPSS5 _PPSS.Bits.PPSS5
#define PPSS_PPSS6 _PPSS.Bits.PPSS6
#define PPSS_PPSS7 _PPSS.Bits.PPSS7
#define PPSS_PPSS _PPSS.MergedBits.grpPPSS


/*** WOMS - Port S Wired-Or Mode Register; 0x0000024E ***/
typedef union {
  byte Byte;
  struct {
    byte WOMS0       :1;                                       /* Wired-Or Mode Port S Bit 0 */
    byte WOMS1       :1;                                       /* Wired-Or Mode Port S Bit 1 */
    byte WOMS2       :1;                                       /* Wired-Or Mode Port S Bit 2 */
    byte WOMS3       :1;                                       /* Wired-Or Mode Port S Bit 3 */
    byte WOMS4       :1;                                       /* Wired-Or Mode Port S Bit 4 */
    byte WOMS5       :1;                                       /* Wired-Or Mode Port S Bit 5 */
    byte WOMS6       :1;                                       /* Wired-Or Mode Port S Bit 6 */
    byte WOMS7       :1;                                       /* Wired-Or Mode Port S Bit 7 */
  } Bits;
  struct {
    byte grpWOMS :8;
  } MergedBits;
} WOMSSTR;
extern volatile WOMSSTR _WOMS @(REG_BASE + 0x0000024E);
#define WOMS _WOMS.Byte
#define WOMS_WOMS0 _WOMS.Bits.WOMS0
#define WOMS_WOMS1 _WOMS.Bits.WOMS1
#define WOMS_WOMS2 _WOMS.Bits.WOMS2
#define WOMS_WOMS3 _WOMS.Bits.WOMS3
#define WOMS_WOMS4 _WOMS.Bits.WOMS4
#define WOMS_WOMS5 _WOMS.Bits.WOMS5
#define WOMS_WOMS6 _WOMS.Bits.WOMS6
#define WOMS_WOMS7 _WOMS.Bits.WOMS7
#define WOMS_WOMS _WOMS.MergedBits.grpWOMS


/*** PTM - Port M I/O Register; 0x00000250 ***/
typedef union {
  byte Byte;
  struct {
    byte PTM0        :1;                                       /* Port T Bit 0 */
    byte PTM1        :1;                                       /* Port T Bit 1 */
    byte PTM2        :1;                                       /* Port T Bit 2 */
    byte PTM3        :1;                                       /* Port T Bit 3 */
    byte PTM4        :1;                                       /* Port T Bit 4 */
    byte PTM5        :1;                                       /* Port T Bit 5 */
    byte PTM6        :1;                                       /* Port T Bit 6 */
    byte PTM7        :1;                                       /* Port T Bit 7 */
  } Bits;
  struct {
    byte grpPTM  :8;
  } MergedBits;
} PTMSTR;
extern volatile PTMSTR _PTM @(REG_BASE + 0x00000250);
#define PTM _PTM.Byte
#define PTM_PTM0 _PTM.Bits.PTM0
#define PTM_PTM1 _PTM.Bits.PTM1
#define PTM_PTM2 _PTM.Bits.PTM2
#define PTM_PTM3 _PTM.Bits.PTM3
#define PTM_PTM4 _PTM.Bits.PTM4
#define PTM_PTM5 _PTM.Bits.PTM5
#define PTM_PTM6 _PTM.Bits.PTM6
#define PTM_PTM7 _PTM.Bits.PTM7
#define PTM_PTM _PTM.MergedBits.grpPTM


/*** PTIM - Port M Input; 0x00000251 ***/
typedef union {
  byte Byte;
  struct {
    byte PTIM0       :1;                                       /* Port M Bit 0 */
    byte PTIM1       :1;                                       /* Port M Bit 1 */
    byte PTIM2       :1;                                       /* Port M Bit 2 */
    byte PTIM3       :1;                                       /* Port M Bit 3 */
    byte PTIM4       :1;                                       /* Port M Bit 4 */
    byte PTIM5       :1;                                       /* Port M Bit 5 */
    byte PTIM6       :1;                                       /* Port M Bit 6 */
    byte PTIM7       :1;                                       /* Port M Bit 7 */
  } Bits;
  struct {
    byte grpPTIM :8;
  } MergedBits;
} PTIMSTR;
extern volatile PTIMSTR _PTIM @(REG_BASE + 0x00000251);
#define PTIM _PTIM.Byte
#define PTIM_PTIM0 _PTIM.Bits.PTIM0
#define PTIM_PTIM1 _PTIM.Bits.PTIM1
#define PTIM_PTIM2 _PTIM.Bits.PTIM2
#define PTIM_PTIM3 _PTIM.Bits.PTIM3
#define PTIM_PTIM4 _PTIM.Bits.PTIM4
#define PTIM_PTIM5 _PTIM.Bits.PTIM5
#define PTIM_PTIM6 _PTIM.Bits.PTIM6
#define PTIM_PTIM7 _PTIM.Bits.PTIM7
#define PTIM_PTIM _PTIM.MergedBits.grpPTIM


/*** DDRM - Port M Data Direction Register; 0x00000252 ***/
typedef union {
  byte Byte;
  struct {
    byte DDRM0       :1;                                       /* Data Direction Port M Bit 0 */
    byte DDRM1       :1;                                       /* Data Direction Port M Bit 1 */
    byte DDRM2       :1;                                       /* Data Direction Port M Bit 2 */
    byte DDRM3       :1;                                       /* Data Direction Port M Bit 3 */
    byte DDRM4       :1;                                       /* Data Direction Port M Bit 4 */
    byte DDRM5       :1;                                       /* Data Direction Port M Bit 5 */
    byte DDRM6       :1;                                       /* Data Direction Port M Bit 6 */
    byte DDRM7       :1;                                       /* Data Direction Port M Bit 7 */
  } Bits;
  struct {
    byte grpDDRM :8;
  } MergedBits;
} DDRMSTR;
extern volatile DDRMSTR _DDRM @(REG_BASE + 0x00000252);
#define DDRM _DDRM.Byte
#define DDRM_DDRM0 _DDRM.Bits.DDRM0
#define DDRM_DDRM1 _DDRM.Bits.DDRM1
#define DDRM_DDRM2 _DDRM.Bits.DDRM2
#define DDRM_DDRM3 _DDRM.Bits.DDRM3
#define DDRM_DDRM4 _DDRM.Bits.DDRM4
#define DDRM_DDRM5 _DDRM.Bits.DDRM5
#define DDRM_DDRM6 _DDRM.Bits.DDRM6
#define DDRM_DDRM7 _DDRM.Bits.DDRM7
#define DDRM_DDRM _DDRM.MergedBits.grpDDRM


/*** RDRM - Port M Reduced Drive Register; 0x00000253 ***/
typedef union {
  byte Byte;
  struct {
    byte RDRM0       :1;                                       /* Reduced Drive Port M Bit 0 */
    byte RDRM1       :1;                                       /* Reduced Drive Port M Bit 1 */
    byte RDRM2       :1;                                       /* Reduced Drive Port M Bit 2 */
    byte RDRM3       :1;                                       /* Reduced Drive Port M Bit 3 */
    byte RDRM4       :1;                                       /* Reduced Drive Port M Bit 4 */
    byte RDRM5       :1;                                       /* Reduced Drive Port M Bit 5 */
    byte RDRM6       :1;                                       /* Reduced Drive Port M Bit 6 */
    byte RDRM7       :1;                                       /* Reduced Drive Port M Bit 7 */
  } Bits;
  struct {
    byte grpRDRM :8;
  } MergedBits;
} RDRMSTR;
extern volatile RDRMSTR _RDRM @(REG_BASE + 0x00000253);
#define RDRM _RDRM.Byte
#define RDRM_RDRM0 _RDRM.Bits.RDRM0
#define RDRM_RDRM1 _RDRM.Bits.RDRM1
#define RDRM_RDRM2 _RDRM.Bits.RDRM2
#define RDRM_RDRM3 _RDRM.Bits.RDRM3
#define RDRM_RDRM4 _RDRM.Bits.RDRM4
#define RDRM_RDRM5 _RDRM.Bits.RDRM5
#define RDRM_RDRM6 _RDRM.Bits.RDRM6
#define RDRM_RDRM7 _RDRM.Bits.RDRM7
#define RDRM_RDRM _RDRM.MergedBits.grpRDRM


/*** PERM - Port M Pull Device Enable Register; 0x00000254 ***/
typedef union {
  byte Byte;
  struct {
    byte PERM0       :1;                                       /* Pull Device Enable Port M Bit 0 */
    byte PERM1       :1;                                       /* Pull Device Enable Port M Bit 1 */
    byte PERM2       :1;                                       /* Pull Device Enable Port M Bit 2 */
    byte PERM3       :1;                                       /* Pull Device Enable Port M Bit 3 */
    byte PERM4       :1;                                       /* Pull Device Enable Port M Bit 4 */
    byte PERM5       :1;                                       /* Pull Device Enable Port M Bit 5 */
    byte PERM6       :1;                                       /* Pull Device Enable Port M Bit 6 */
    byte PERM7       :1;                                       /* Pull Device Enable Port M Bit 7 */
  } Bits;
  struct {
    byte grpPERM :8;
  } MergedBits;
} PERMSTR;
extern volatile PERMSTR _PERM @(REG_BASE + 0x00000254);
#define PERM _PERM.Byte
#define PERM_PERM0 _PERM.Bits.PERM0
#define PERM_PERM1 _PERM.Bits.PERM1
#define PERM_PERM2 _PERM.Bits.PERM2
#define PERM_PERM3 _PERM.Bits.PERM3
#define PERM_PERM4 _PERM.Bits.PERM4
#define PERM_PERM5 _PERM.Bits.PERM5
#define PERM_PERM6 _PERM.Bits.PERM6
#define PERM_PERM7 _PERM.Bits.PERM7
#define PERM_PERM _PERM.MergedBits.grpPERM


/*** PPSM - Port M Polarity Select Register; 0x00000255 ***/
typedef union {
  byte Byte;
  struct {
    byte PPSM0       :1;                                       /* Pull Select Port M Bit 0 */
    byte PPSM1       :1;                                       /* Pull Select Port M Bit 1 */
    byte PPSM2       :1;                                       /* Pull Select Port M Bit 2 */
    byte PPSM3       :1;                                       /* Pull Select Port M Bit 3 */
    byte PPSM4       :1;                                       /* Pull Select Port M Bit 4 */
    byte PPSM5       :1;                                       /* Pull Select Port M Bit 5 */
    byte PPSM6       :1;                                       /* Pull Select Port M Bit 6 */
    byte PPSM7       :1;                                       /* Pull Select Port M Bit 7 */
  } Bits;
  struct {
    byte grpPPSM :8;
  } MergedBits;
} PPSMSTR;
extern volatile PPSMSTR _PPSM @(REG_BASE + 0x00000255);
#define PPSM _PPSM.Byte
#define PPSM_PPSM0 _PPSM.Bits.PPSM0
#define PPSM_PPSM1 _PPSM.Bits.PPSM1
#define PPSM_PPSM2 _PPSM.Bits.PPSM2
#define PPSM_PPSM3 _PPSM.Bits.PPSM3
#define PPSM_PPSM4 _PPSM.Bits.PPSM4
#define PPSM_PPSM5 _PPSM.Bits.PPSM5
#define PPSM_PPSM6 _PPSM.Bits.PPSM6
#define PPSM_PPSM7 _PPSM.Bits.PPSM7
#define PPSM_PPSM _PPSM.MergedBits.grpPPSM


/*** WOMM - Port M Wired-Or Mode Register; 0x00000256 ***/
typedef union {
  byte Byte;
  struct {
    byte WOMM0       :1;                                       /* Wired-Or Mode Port M Bit 0 */
    byte WOMM1       :1;                                       /* Wired-Or Mode Port M Bit 1 */
    byte WOMM2       :1;                                       /* Wired-Or Mode Port M Bit 2 */
    byte WOMM3       :1;                                       /* Wired-Or Mode Port M Bit 3 */
    byte WOMM4       :1;                                       /* Wired-Or Mode Port M Bit 4 */
    byte WOMM5       :1;                                       /* Wired-Or Mode Port M Bit 5 */
    byte WOMM6       :1;                                       /* Wired-Or Mode Port M Bit 6 */
    byte WOMM7       :1;                                       /* Wired-Or Mode Port M Bit 7 */
  } Bits;
  struct {
    byte grpWOMM :8;
  } MergedBits;
} WOMMSTR;
extern volatile WOMMSTR _WOMM @(REG_BASE + 0x00000256);
#define WOMM _WOMM.Byte
#define WOMM_WOMM0 _WOMM.Bits.WOMM0
#define WOMM_WOMM1 _WOMM.Bits.WOMM1
#define WOMM_WOMM2 _WOMM.Bits.WOMM2
#define WOMM_WOMM3 _WOMM.Bits.WOMM3
#define WOMM_WOMM4 _WOMM.Bits.WOMM4
#define WOMM_WOMM5 _WOMM.Bits.WOMM5
#define WOMM_WOMM6 _WOMM.Bits.WOMM6
#define WOMM_WOMM7 _WOMM.Bits.WOMM7
#define WOMM_WOMM _WOMM.MergedBits.grpWOMM


/*** MODRR - Module Routing Register; 0x00000257 ***/
typedef union {
  byte Byte;
  struct {
    byte MODRR0      :1;                                       /* CAN0 Routing */
    byte MODRR1      :1;                                       /* CAN0 Routing */
    byte MODRR2      :1;                                       /* CAN4 Routing */
    byte MODRR3      :1;                                       /* CAN4 Routing */
    byte MODRR4      :1;                                       /* SPI0 Routing */
    byte MODRR5      :1;                                       /* SPI1 Routing */
    byte MODRR6      :1;                                       /* SPI2 Routing */
    byte             :1;
  } Bits;
  struct {
    byte grpMODRR :7;
    byte         :1;
  } MergedBits;
} MODRRSTR;
extern volatile MODRRSTR _MODRR @(REG_BASE + 0x00000257);
#define MODRR _MODRR.Byte
#define MODRR_MODRR0 _MODRR.Bits.MODRR0
#define MODRR_MODRR1 _MODRR.Bits.MODRR1
#define MODRR_MODRR2 _MODRR.Bits.MODRR2
#define MODRR_MODRR3 _MODRR.Bits.MODRR3
#define MODRR_MODRR4 _MODRR.Bits.MODRR4
#define MODRR_MODRR5 _MODRR.Bits.MODRR5
#define MODRR_MODRR6 _MODRR.Bits.MODRR6
#define MODRR_MODRR _MODRR.MergedBits.grpMODRR


/*** PTP - Port P I/O Register; 0x00000258 ***/
typedef union {
  byte Byte;
  struct {
    byte PTP0        :1;                                       /* Port P Bit 0 */
    byte PTP1        :1;                                       /* Port P Bit 1 */
    byte PTP2        :1;                                       /* Port P Bit 2 */
    byte PTP3        :1;                                       /* Port P Bit 3 */
    byte PTP4        :1;                                       /* Port P Bit 4 */
    byte PTP5        :1;                                       /* Port P Bit 5 */
    byte PTP6        :1;                                       /* Port P Bit 6 */
    byte PTP7        :1;                                       /* Port P Bit 7 */
  } Bits;
  struct {
    byte grpPTP  :8;
  } MergedBits;
} PTPSTR;
extern volatile PTPSTR _PTP @(REG_BASE + 0x00000258);
#define PTP _PTP.Byte
#define PTP_PTP0 _PTP.Bits.PTP0
#define PTP_PTP1 _PTP.Bits.PTP1
#define PTP_PTP2 _PTP.Bits.PTP2
#define PTP_PTP3 _PTP.Bits.PTP3
#define PTP_PTP4 _PTP.Bits.PTP4
#define PTP_PTP5 _PTP.Bits.PTP5
#define PTP_PTP6 _PTP.Bits.PTP6
#define PTP_PTP7 _PTP.Bits.PTP7
#define PTP_PTP _PTP.MergedBits.grpPTP


/*** PTIP - Port P Input; 0x00000259 ***/
typedef union {
  byte Byte;
  struct {
    byte PTIP0       :1;                                       /* Port P Bit 0 */
    byte PTIP1       :1;                                       /* Port P Bit 1 */
    byte PTIP2       :1;                                       /* Port P Bit 2 */
    byte PTIP3       :1;                                       /* Port P Bit 3 */
    byte PTIP4       :1;                                       /* Port P Bit 4 */
    byte PTIP5       :1;                                       /* Port P Bit 5 */
    byte PTIP6       :1;                                       /* Port P Bit 6 */
    byte PTIP7       :1;                                       /* Port P Bit 7 */
  } Bits;
  struct {
    byte grpPTIP :8;
  } MergedBits;
} PTIPSTR;
extern volatile PTIPSTR _PTIP @(REG_BASE + 0x00000259);
#define PTIP _PTIP.Byte
#define PTIP_PTIP0 _PTIP.Bits.PTIP0
#define PTIP_PTIP1 _PTIP.Bits.PTIP1
#define PTIP_PTIP2 _PTIP.Bits.PTIP2
#define PTIP_PTIP3 _PTIP.Bits.PTIP3
#define PTIP_PTIP4 _PTIP.Bits.PTIP4
#define PTIP_PTIP5 _PTIP.Bits.PTIP5
#define PTIP_PTIP6 _PTIP.Bits.PTIP6
#define PTIP_PTIP7 _PTIP.Bits.PTIP7
#define PTIP_PTIP _PTIP.MergedBits.grpPTIP


/*** DDRP - Port P Data Direction Register; 0x0000025A ***/
typedef union {
  byte Byte;
  struct {
    byte DDRP0       :1;                                       /* Data Direction Port P Bit 0 */
    byte DDRP1       :1;                                       /* Data Direction Port P Bit 1 */
    byte DDRP2       :1;                                       /* Data Direction Port P Bit 2 */
    byte DDRP3       :1;                                       /* Data Direction Port P Bit 3 */
    byte DDRP4       :1;                                       /* Data Direction Port P Bit 4 */
    byte DDRP5       :1;                                       /* Data Direction Port P Bit 5 */
    byte DDRP6       :1;                                       /* Data Direction Port P Bit 6 */
    byte DDRP7       :1;                                       /* Data Direction Port P Bit 7 */
  } Bits;
  struct {
    byte grpDDRP :8;
  } MergedBits;
} DDRPSTR;
extern volatile DDRPSTR _DDRP @(REG_BASE + 0x0000025A);
#define DDRP _DDRP.Byte
#define DDRP_DDRP0 _DDRP.Bits.DDRP0
#define DDRP_DDRP1 _DDRP.Bits.DDRP1
#define DDRP_DDRP2 _DDRP.Bits.DDRP2
#define DDRP_DDRP3 _DDRP.Bits.DDRP3
#define DDRP_DDRP4 _DDRP.Bits.DDRP4
#define DDRP_DDRP5 _DDRP.Bits.DDRP5
#define DDRP_DDRP6 _DDRP.Bits.DDRP6
#define DDRP_DDRP7 _DDRP.Bits.DDRP7
#define DDRP_DDRP _DDRP.MergedBits.grpDDRP


/*** RDRP - Port P Reduced Drive Register; 0x0000025B ***/
typedef union {
  byte Byte;
  struct {
    byte RDRP0       :1;                                       /* Reduced Drive Port P Bit 0 */
    byte RDRP1       :1;                                       /* Reduced Drive Port P Bit 1 */
    byte RDRP2       :1;                                       /* Reduced Drive Port P Bit 2 */
    byte RDRP3       :1;                                       /* Reduced Drive Port P Bit 3 */
    byte RDRP4       :1;                                       /* Reduced Drive Port P Bit 4 */
    byte RDRP5       :1;                                       /* Reduced Drive Port P Bit 5 */
    byte RDRP6       :1;                                       /* Reduced Drive Port P Bit 6 */
    byte RDRP7       :1;                                       /* Reduced Drive Port P Bit 7 */
  } Bits;
  struct {
    byte grpRDRP :8;
  } MergedBits;
} RDRPSTR;
extern volatile RDRPSTR _RDRP @(REG_BASE + 0x0000025B);
#define RDRP _RDRP.Byte
#define RDRP_RDRP0 _RDRP.Bits.RDRP0
#define RDRP_RDRP1 _RDRP.Bits.RDRP1
#define RDRP_RDRP2 _RDRP.Bits.RDRP2
#define RDRP_RDRP3 _RDRP.Bits.RDRP3
#define RDRP_RDRP4 _RDRP.Bits.RDRP4
#define RDRP_RDRP5 _RDRP.Bits.RDRP5
#define RDRP_RDRP6 _RDRP.Bits.RDRP6
#define RDRP_RDRP7 _RDRP.Bits.RDRP7
#define RDRP_RDRP _RDRP.MergedBits.grpRDRP


/*** PERP - Port P Pull Device Enable Register; 0x0000025C ***/
typedef union {
  byte Byte;
  struct {
    byte PERP0       :1;                                       /* Pull Device Enable Port P Bit 0 */
    byte PERP1       :1;                                       /* Pull Device Enable Port P Bit 1 */
    byte PERP2       :1;                                       /* Pull Device Enable Port P Bit 2 */
    byte PERP3       :1;                                       /* Pull Device Enable Port P Bit 3 */
    byte PERP4       :1;                                       /* Pull Device Enable Port P Bit 4 */
    byte PERP5       :1;                                       /* Pull Device Enable Port P Bit 5 */
    byte PERP6       :1;                                       /* Pull Device Enable Port P Bit 6 */
    byte PERP7       :1;                                       /* Pull Device Enable Port P Bit 7 */
  } Bits;
  struct {
    byte grpPERP :8;
  } MergedBits;
} PERPSTR;
extern volatile PERPSTR _PERP @(REG_BASE + 0x0000025C);
#define PERP _PERP.Byte
#define PERP_PERP0 _PERP.Bits.PERP0
#define PERP_PERP1 _PERP.Bits.PERP1
#define PERP_PERP2 _PERP.Bits.PERP2
#define PERP_PERP3 _PERP.Bits.PERP3
#define PERP_PERP4 _PERP.Bits.PERP4
#define PERP_PERP5 _PERP.Bits.PERP5
#define PERP_PERP6 _PERP.Bits.PERP6
#define PERP_PERP7 _PERP.Bits.PERP7
#define PERP_PERP _PERP.MergedBits.grpPERP


/*** PPSP - Port P Polarity Select Register; 0x0000025D ***/
typedef union {
  byte Byte;
  struct {
    byte PPSP0       :1;                                       /* Pull Select Port P Bit 0 */
    byte PPSP1       :1;                                       /* Pull Select Port P Bit 1 */
    byte PPSP2       :1;                                       /* Pull Select Port P Bit 2 */
    byte PPSP3       :1;                                       /* Pull Select Port P Bit 3 */
    byte PPSP4       :1;                                       /* Pull Select Port P Bit 4 */
    byte PPSP5       :1;                                       /* Pull Select Port P Bit 5 */
    byte PPSP6       :1;                                       /* Pull Select Port P Bit 6 */
    byte PPSP7       :1;                                       /* Pull Select Port P Bit 7 */
  } Bits;
  struct {
    byte grpPPSP :8;
  } MergedBits;
} PPSPSTR;
extern volatile PPSPSTR _PPSP @(REG_BASE + 0x0000025D);
#define PPSP _PPSP.Byte
#define PPSP_PPSP0 _PPSP.Bits.PPSP0
#define PPSP_PPSP1 _PPSP.Bits.PPSP1
#define PPSP_PPSP2 _PPSP.Bits.PPSP2
#define PPSP_PPSP3 _PPSP.Bits.PPSP3
#define PPSP_PPSP4 _PPSP.Bits.PPSP4
#define PPSP_PPSP5 _PPSP.Bits.PPSP5
#define PPSP_PPSP6 _PPSP.Bits.PPSP6
#define PPSP_PPSP7 _PPSP.Bits.PPSP7
#define PPSP_PPSP _PPSP.MergedBits.grpPPSP


/*** PIEP - Port P Interrupt Enable Register; 0x0000025E ***/
typedef union {
  byte Byte;
  struct {
    byte PIEP0       :1;                                       /* Interrupt Enable Port P Bit 0 */
    byte PIEP1       :1;                                       /* Interrupt Enable Port P Bit 1 */
    byte PIEP2       :1;                                       /* Interrupt Enable Port P Bit 2 */
    byte PIEP3       :1;                                       /* Interrupt Enable Port P Bit 3 */
    byte PIEP4       :1;                                       /* Interrupt Enable Port P Bit 4 */
    byte PIEP5       :1;                                       /* Interrupt Enable Port P Bit 5 */
    byte PIEP6       :1;                                       /* Interrupt Enable Port P Bit 6 */
    byte PIEP7       :1;                                       /* Interrupt Enable Port P Bit 7 */
  } Bits;
  struct {
    byte grpPIEP :8;
  } MergedBits;
} PIEPSTR;
extern volatile PIEPSTR _PIEP @(REG_BASE + 0x0000025E);
#define PIEP _PIEP.Byte
#define PIEP_PIEP0 _PIEP.Bits.PIEP0
#define PIEP_PIEP1 _PIEP.Bits.PIEP1
#define PIEP_PIEP2 _PIEP.Bits.PIEP2
#define PIEP_PIEP3 _PIEP.Bits.PIEP3
#define PIEP_PIEP4 _PIEP.Bits.PIEP4
#define PIEP_PIEP5 _PIEP.Bits.PIEP5
#define PIEP_PIEP6 _PIEP.Bits.PIEP6
#define PIEP_PIEP7 _PIEP.Bits.PIEP7
#define PIEP_PIEP _PIEP.MergedBits.grpPIEP


/*** PIFP - Port P Interrupt Flag Register; 0x0000025F ***/
typedef union {
  byte Byte;
  struct {
    byte PIFP0       :1;                                       /* Interrupt Flags Port P Bit 0 */
    byte PIFP1       :1;                                       /* Interrupt Flags Port P Bit 1 */
    byte PIFP2       :1;                                       /* Interrupt Flags Port P Bit 2 */
    byte PIFP3       :1;                                       /* Interrupt Flags Port P Bit 3 */
    byte PIFP4       :1;                                       /* Interrupt Flags Port P Bit 4 */
    byte PIFP5       :1;                                       /* Interrupt Flags Port P Bit 5 */
    byte PIFP6       :1;                                       /* Interrupt Flags Port P Bit 6 */
    byte PIFP7       :1;                                       /* Interrupt Flags Port P Bit 7 */
  } Bits;
  struct {
    byte grpPIFP :8;
  } MergedBits;
} PIFPSTR;
extern volatile PIFPSTR _PIFP @(REG_BASE + 0x0000025F);
#define PIFP _PIFP.Byte
#define PIFP_PIFP0 _PIFP.Bits.PIFP0
#define PIFP_PIFP1 _PIFP.Bits.PIFP1
#define PIFP_PIFP2 _PIFP.Bits.PIFP2
#define PIFP_PIFP3 _PIFP.Bits.PIFP3
#define PIFP_PIFP4 _PIFP.Bits.PIFP4
#define PIFP_PIFP5 _PIFP.Bits.PIFP5
#define PIFP_PIFP6 _PIFP.Bits.PIFP6
#define PIFP_PIFP7 _PIFP.Bits.PIFP7
#define PIFP_PIFP _PIFP.MergedBits.grpPIFP


/*** PTH - Port H I/O Register; 0x00000260 ***/
typedef union {
  byte Byte;
  struct {
    byte PTH0        :1;                                       /* Port H Bit 0 */
    byte PTH1        :1;                                       /* Port H Bit 1 */
    byte PTH2        :1;                                       /* Port H Bit 2 */
    byte PTH3        :1;                                       /* Port H Bit 3 */
    byte PTH4        :1;                                       /* Port H Bit 4 */
    byte PTH5        :1;                                       /* Port H Bit 5 */
    byte PTH6        :1;                                       /* Port H Bit 6 */
    byte PTH7        :1;                                       /* Port H Bit 7 */
  } Bits;
  struct {
    byte grpPTH  :8;
  } MergedBits;
} PTHSTR;
extern volatile PTHSTR _PTH @(REG_BASE + 0x00000260);
#define PTH _PTH.Byte
#define PTH_PTH0 _PTH.Bits.PTH0
#define PTH_PTH1 _PTH.Bits.PTH1
#define PTH_PTH2 _PTH.Bits.PTH2
#define PTH_PTH3 _PTH.Bits.PTH3
#define PTH_PTH4 _PTH.Bits.PTH4
#define PTH_PTH5 _PTH.Bits.PTH5
#define PTH_PTH6 _PTH.Bits.PTH6
#define PTH_PTH7 _PTH.Bits.PTH7
#define PTH_PTH _PTH.MergedBits.grpPTH


/*** PTIH - Port H Input Register; 0x00000261 ***/
typedef union {
  byte Byte;
  struct {
    byte PTIH0       :1;                                       /* Port H Bit 0 */
    byte PTIH1       :1;                                       /* Port H Bit 1 */
    byte PTIH2       :1;                                       /* Port H Bit 2 */
    byte PTIH3       :1;                                       /* Port H Bit 3 */
    byte PTIH4       :1;                                       /* Port H Bit 4 */
    byte PTIH5       :1;                                       /* Port H Bit 5 */
    byte PTIH6       :1;                                       /* Port H Bit 6 */
    byte PTIH7       :1;                                       /* Port H Bit 7 */
  } Bits;
  struct {
    byte grpPTIH :8;
  } MergedBits;
} PTIHSTR;
extern volatile PTIHSTR _PTIH @(REG_BASE + 0x00000261);
#define PTIH _PTIH.Byte
#define PTIH_PTIH0 _PTIH.Bits.PTIH0
#define PTIH_PTIH1 _PTIH.Bits.PTIH1
#define PTIH_PTIH2 _PTIH.Bits.PTIH2
#define PTIH_PTIH3 _PTIH.Bits.PTIH3
#define PTIH_PTIH4 _PTIH.Bits.PTIH4
#define PTIH_PTIH5 _PTIH.Bits.PTIH5
#define PTIH_PTIH6 _PTIH.Bits.PTIH6
#define PTIH_PTIH7 _PTIH.Bits.PTIH7
#define PTIH_PTIH _PTIH.MergedBits.grpPTIH


/*** DDRH - Port H Data Direction Register; 0x00000262 ***/
typedef union {
  byte Byte;
  struct {
    byte DDRH0       :1;                                       /* Data Direction Port H Bit 0 */
    byte DDRH1       :1;                                       /* Data Direction Port H Bit 1 */
    byte DDRH2       :1;                                       /* Data Direction Port H Bit 2 */
    byte DDRH3       :1;                                       /* Data Direction Port H Bit 3 */
    byte DDRH4       :1;                                       /* Data Direction Port H Bit 4 */
    byte DDRH5       :1;                                       /* Data Direction Port H Bit 5 */
    byte DDRH6       :1;                                       /* Data Direction Port H Bit 6 */
    byte DDRH7       :1;                                       /* Data Direction Port H Bit 7 */
  } Bits;
  struct {
    byte grpDDRH :8;
  } MergedBits;
} DDRHSTR;
extern volatile DDRHSTR _DDRH @(REG_BASE + 0x00000262);
#define DDRH _DDRH.Byte
#define DDRH_DDRH0 _DDRH.Bits.DDRH0
#define DDRH_DDRH1 _DDRH.Bits.DDRH1
#define DDRH_DDRH2 _DDRH.Bits.DDRH2
#define DDRH_DDRH3 _DDRH.Bits.DDRH3
#define DDRH_DDRH4 _DDRH.Bits.DDRH4
#define DDRH_DDRH5 _DDRH.Bits.DDRH5
#define DDRH_DDRH6 _DDRH.Bits.DDRH6
#define DDRH_DDRH7 _DDRH.Bits.DDRH7
#define DDRH_DDRH _DDRH.MergedBits.grpDDRH


/*** RDRH - Port H Reduced Drive Register; 0x00000263 ***/
typedef union {
  byte Byte;
  struct {
    byte RDRH0       :1;                                       /* Reduced Drive Port H Bit 0 */
    byte RDRH1       :1;                                       /* Reduced Drive Port H Bit 1 */
    byte RDRH2       :1;                                       /* Reduced Drive Port H Bit 2 */
    byte RDRH3       :1;                                       /* Reduced Drive Port H Bit 3 */
    byte RDRH4       :1;                                       /* Reduced Drive Port H Bit 4 */
    byte RDRH5       :1;                                       /* Reduced Drive Port H Bit 5 */
    byte RDRH6       :1;                                       /* Reduced Drive Port H Bit 6 */
    byte RDRH7       :1;                                       /* Reduced Drive Port H Bit 7 */
  } Bits;
  struct {
    byte grpRDRH :8;
  } MergedBits;
} RDRHSTR;
extern volatile RDRHSTR _RDRH @(REG_BASE + 0x00000263);
#define RDRH _RDRH.Byte
#define RDRH_RDRH0 _RDRH.Bits.RDRH0
#define RDRH_RDRH1 _RDRH.Bits.RDRH1
#define RDRH_RDRH2 _RDRH.Bits.RDRH2
#define RDRH_RDRH3 _RDRH.Bits.RDRH3
#define RDRH_RDRH4 _RDRH.Bits.RDRH4
#define RDRH_RDRH5 _RDRH.Bits.RDRH5
#define RDRH_RDRH6 _RDRH.Bits.RDRH6
#define RDRH_RDRH7 _RDRH.Bits.RDRH7
#define RDRH_RDRH _RDRH.MergedBits.grpRDRH


/*** PERH - Port H Pull Device Enable Register; 0x00000264 ***/
typedef union {
  byte Byte;
  struct {
    byte PERH0       :1;                                       /* Pull Device Enable Port H Bit 0 */
    byte PERH1       :1;                                       /* Pull Device Enable Port H Bit 1 */
    byte PERH2       :1;                                       /* Pull Device Enable Port H Bit 2 */
    byte PERH3       :1;                                       /* Pull Device Enable Port H Bit 3 */
    byte PERH4       :1;                                       /* Pull Device Enable Port H Bit 4 */
    byte PERH5       :1;                                       /* Pull Device Enable Port H Bit 5 */
    byte PERH6       :1;                                       /* Pull Device Enable Port H Bit 6 */
    byte PERH7       :1;                                       /* Pull Device Enable Port H Bit 7 */
  } Bits;
  struct {
    byte grpPERH :8;
  } MergedBits;
} PERHSTR;
extern volatile PERHSTR _PERH @(REG_BASE + 0x00000264);
#define PERH _PERH.Byte
#define PERH_PERH0 _PERH.Bits.PERH0
#define PERH_PERH1 _PERH.Bits.PERH1
#define PERH_PERH2 _PERH.Bits.PERH2
#define PERH_PERH3 _PERH.Bits.PERH3
#define PERH_PERH4 _PERH.Bits.PERH4
#define PERH_PERH5 _PERH.Bits.PERH5
#define PERH_PERH6 _PERH.Bits.PERH6
#define PERH_PERH7 _PERH.Bits.PERH7
#define PERH_PERH _PERH.MergedBits.grpPERH


/*** PPSH - Port H Polarity Select Register; 0x00000265 ***/
typedef union {
  byte Byte;
  struct {
    byte PPSH0       :1;                                       /* Pull Select Port H Bit 0 */
    byte PPSH1       :1;                                       /* Pull Select Port H Bit 1 */
    byte PPSH2       :1;                                       /* Pull Select Port H Bit 2 */
    byte PPSH3       :1;                                       /* Pull Select Port H Bit 3 */
    byte PPSH4       :1;                                       /* Pull Select Port H Bit 4 */
    byte PPSH5       :1;                                       /* Pull Select Port H Bit 5 */
    byte PPSH6       :1;                                       /* Pull Select Port H Bit 6 */
    byte PPSH7       :1;                                       /* Pull Select Port H Bit 7 */
  } Bits;
  struct {
    byte grpPPSH :8;
  } MergedBits;
} PPSHSTR;
extern volatile PPSHSTR _PPSH @(REG_BASE + 0x00000265);
#define PPSH _PPSH.Byte
#define PPSH_PPSH0 _PPSH.Bits.PPSH0
#define PPSH_PPSH1 _PPSH.Bits.PPSH1
#define PPSH_PPSH2 _PPSH.Bits.PPSH2
#define PPSH_PPSH3 _PPSH.Bits.PPSH3
#define PPSH_PPSH4 _PPSH.Bits.PPSH4
#define PPSH_PPSH5 _PPSH.Bits.PPSH5
#define PPSH_PPSH6 _PPSH.Bits.PPSH6
#define PPSH_PPSH7 _PPSH.Bits.PPSH7
#define PPSH_PPSH _PPSH.MergedBits.grpPPSH


/*** PIEH - Port H Interrupt Enable Register; 0x00000266 ***/
typedef union {
  byte Byte;
  struct {
    byte PIEH0       :1;                                       /* Interrupt Enable Port H Bit 0 */
    byte PIEH1       :1;                                       /* Interrupt Enable Port H Bit 1 */
    byte PIEH2       :1;                                       /* Interrupt Enable Port H Bit 2 */
    byte PIEH3       :1;                                       /* Interrupt Enable Port H Bit 3 */
    byte PIEH4       :1;                                       /* Interrupt Enable Port H Bit 4 */
    byte PIEH5       :1;                                       /* Interrupt Enable Port H Bit 5 */
    byte PIEH6       :1;                                       /* Interrupt Enable Port H Bit 6 */
    byte PIEH7       :1;                                       /* Interrupt Enable Port H Bit 7 */
  } Bits;
  struct {
    byte grpPIEH :8;
  } MergedBits;
} PIEHSTR;
extern volatile PIEHSTR _PIEH @(REG_BASE + 0x00000266);
#define PIEH _PIEH.Byte
#define PIEH_PIEH0 _PIEH.Bits.PIEH0
#define PIEH_PIEH1 _PIEH.Bits.PIEH1
#define PIEH_PIEH2 _PIEH.Bits.PIEH2
#define PIEH_PIEH3 _PIEH.Bits.PIEH3
#define PIEH_PIEH4 _PIEH.Bits.PIEH4
#define PIEH_PIEH5 _PIEH.Bits.PIEH5
#define PIEH_PIEH6 _PIEH.Bits.PIEH6
#define PIEH_PIEH7 _PIEH.Bits.PIEH7
#define PIEH_PIEH _PIEH.MergedBits.grpPIEH


/*** PIFH - Port H Interrupt Flag Register; 0x00000267 ***/
typedef union {
  byte Byte;
  struct {
    byte PIFH0       :1;                                       /* Interrupt Flags Port H Bit 0 */
    byte PIFH1       :1;                                       /* Interrupt Flags Port H Bit 1 */
    byte PIFH2       :1;                                       /* Interrupt Flags Port H Bit 2 */
    byte PIFH3       :1;                                       /* Interrupt Flags Port H Bit 3 */
    byte PIFH4       :1;                                       /* Interrupt Flags Port H Bit 4 */
    byte PIFH5       :1;                                       /* Interrupt Flags Port H Bit 5 */
    byte PIFH6       :1;                                       /* Interrupt Flags Port H Bit 6 */
    byte PIFH7       :1;                                       /* Interrupt Flags Port H Bit 7 */
  } Bits;
  struct {
    byte grpPIFH :8;
  } MergedBits;
} PIFHSTR;
extern volatile PIFHSTR _PIFH @(REG_BASE + 0x00000267);
#define PIFH _PIFH.Byte
#define PIFH_PIFH0 _PIFH.Bits.PIFH0
#define PIFH_PIFH1 _PIFH.Bits.PIFH1
#define PIFH_PIFH2 _PIFH.Bits.PIFH2
#define PIFH_PIFH3 _PIFH.Bits.PIFH3
#define PIFH_PIFH4 _PIFH.Bits.PIFH4
#define PIFH_PIFH5 _PIFH.Bits.PIFH5
#define PIFH_PIFH6 _PIFH.Bits.PIFH6
#define PIFH_PIFH7 _PIFH.Bits.PIFH7
#define PIFH_PIFH _PIFH.MergedBits.grpPIFH


/*** PTJ - Port J I/O Register; 0x00000268 ***/
typedef union {
  byte Byte;
  struct {
    byte PTJ0        :1;                                       /* Port J Bit 0 */
    byte PTJ1        :1;                                       /* Port J Bit 1 */
    byte             :1;
    byte             :1;
    byte             :1;
    byte             :1;
    byte PTJ6        :1;                                       /* Port J Bit 6 */
    byte PTJ7        :1;                                       /* Port J Bit 7 */
  } Bits;
  struct {
    byte grpPTJ  :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpPTJ_6 :2;
  } MergedBits;
} PTJSTR;
extern volatile PTJSTR _PTJ @(REG_BASE + 0x00000268);
#define PTJ _PTJ.Byte
#define PTJ_PTJ0 _PTJ.Bits.PTJ0
#define PTJ_PTJ1 _PTJ.Bits.PTJ1
#define PTJ_PTJ6 _PTJ.Bits.PTJ6
#define PTJ_PTJ7 _PTJ.Bits.PTJ7
#define PTJ_PTJ _PTJ.MergedBits.grpPTJ
#define PTJ_PTJ_6 _PTJ.MergedBits.grpPTJ_6


/*** PTIJ - Port J Input Register; 0x00000269 ***/
typedef union {
  byte Byte;
  struct {
    byte PTIJ0       :1;                                       /* Port J Bit 0 */
    byte PTIJ1       :1;                                       /* Port J Bit 1 */
    byte             :1;
    byte             :1;
    byte             :1;
    byte             :1;
    byte PTIJ6       :1;                                       /* Port J Bit 6 */
    byte PTIJ7       :1;                                       /* Port J Bit 7 */
  } Bits;
  struct {
    byte grpPTIJ :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpPTIJ_6 :2;
  } MergedBits;
} PTIJSTR;
extern volatile PTIJSTR _PTIJ @(REG_BASE + 0x00000269);
#define PTIJ _PTIJ.Byte
#define PTIJ_PTIJ0 _PTIJ.Bits.PTIJ0
#define PTIJ_PTIJ1 _PTIJ.Bits.PTIJ1
#define PTIJ_PTIJ6 _PTIJ.Bits.PTIJ6
#define PTIJ_PTIJ7 _PTIJ.Bits.PTIJ7
#define PTIJ_PTIJ _PTIJ.MergedBits.grpPTIJ
#define PTIJ_PTIJ_6 _PTIJ.MergedBits.grpPTIJ_6


/*** DDRJ - Port J Data Direction Register; 0x0000026A ***/
typedef union {
  byte Byte;
  struct {
    byte DDRJ0       :1;                                       /* Data Direction Port J Bit 0 */
    byte DDRJ1       :1;                                       /* Data Direction Port J Bit 1 */
    byte             :1;
    byte             :1;
    byte             :1;
    byte             :1;
    byte DDRJ6       :1;                                       /* Data Direction Port J Bit 6 */
    byte DDRJ7       :1;                                       /* Data Direction Port J Bit 7 */
  } Bits;
  struct {
    byte grpDDRJ :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpDDRJ_6 :2;
  } MergedBits;
} DDRJSTR;
extern volatile DDRJSTR _DDRJ @(REG_BASE + 0x0000026A);
#define DDRJ _DDRJ.Byte
#define DDRJ_DDRJ0 _DDRJ.Bits.DDRJ0
#define DDRJ_DDRJ1 _DDRJ.Bits.DDRJ1
#define DDRJ_DDRJ6 _DDRJ.Bits.DDRJ6
#define DDRJ_DDRJ7 _DDRJ.Bits.DDRJ7
#define DDRJ_DDRJ _DDRJ.MergedBits.grpDDRJ
#define DDRJ_DDRJ_6 _DDRJ.MergedBits.grpDDRJ_6


/*** RDRJ - Port J Reduced Drive Register; 0x0000026B ***/
typedef union {
  byte Byte;
  struct {
    byte RDRJ0       :1;                                       /* Reduced Drive Port J Bit 0 */
    byte RDRJ1       :1;                                       /* Reduced Drive Port J Bit 1 */
    byte             :1;
    byte             :1;
    byte             :1;
    byte             :1;
    byte RDRJ6       :1;                                       /* Reduced Drive Port J Bit 6 */
    byte RDRJ7       :1;                                       /* Reduced Drive Port J Bit 7 */
  } Bits;
  struct {
    byte grpRDRJ :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpRDRJ_6 :2;
  } MergedBits;
} RDRJSTR;
extern volatile RDRJSTR _RDRJ @(REG_BASE + 0x0000026B);
#define RDRJ _RDRJ.Byte
#define RDRJ_RDRJ0 _RDRJ.Bits.RDRJ0
#define RDRJ_RDRJ1 _RDRJ.Bits.RDRJ1
#define RDRJ_RDRJ6 _RDRJ.Bits.RDRJ6
#define RDRJ_RDRJ7 _RDRJ.Bits.RDRJ7
#define RDRJ_RDRJ _RDRJ.MergedBits.grpRDRJ
#define RDRJ_RDRJ_6 _RDRJ.MergedBits.grpRDRJ_6


/*** PERJ - Port J Pull Device Enable Register; 0x0000026C ***/
typedef union {
  byte Byte;
  struct {
    byte PERJ0       :1;                                       /* Pull Device Enable Port J Bit 0 */
    byte PERJ1       :1;                                       /* Pull Device Enable Port J Bit 1 */
    byte             :1;
    byte             :1;
    byte             :1;
    byte             :1;
    byte PERJ6       :1;                                       /* Pull Device Enable Port J Bit 6 */
    byte PERJ7       :1;                                       /* Pull Device Enable Port J Bit 7 */
  } Bits;
  struct {
    byte grpPERJ :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpPERJ_6 :2;
  } MergedBits;
} PERJSTR;
extern volatile PERJSTR _PERJ @(REG_BASE + 0x0000026C);
#define PERJ _PERJ.Byte
#define PERJ_PERJ0 _PERJ.Bits.PERJ0
#define PERJ_PERJ1 _PERJ.Bits.PERJ1
#define PERJ_PERJ6 _PERJ.Bits.PERJ6
#define PERJ_PERJ7 _PERJ.Bits.PERJ7
#define PERJ_PERJ _PERJ.MergedBits.grpPERJ
#define PERJ_PERJ_6 _PERJ.MergedBits.grpPERJ_6


/*** PPSJ - PortJP Polarity Select Register; 0x0000026D ***/
typedef union {
  byte Byte;
  struct {
    byte PPSJ0       :1;                                       /* Pull Select Port J Bit 0 */
    byte PPSJ1       :1;                                       /* Pull Select Port J Bit 1 */
    byte             :1;
    byte             :1;
    byte             :1;
    byte             :1;
    byte PPSJ6       :1;                                       /* Pull Select Port J Bit 6 */
    byte PPSJ7       :1;                                       /* Pull Select Port J Bit 7 */
  } Bits;
  struct {
    byte grpPPSJ :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpPPSJ_6 :2;
  } MergedBits;
} PPSJSTR;
extern volatile PPSJSTR _PPSJ @(REG_BASE + 0x0000026D);
#define PPSJ _PPSJ.Byte
#define PPSJ_PPSJ0 _PPSJ.Bits.PPSJ0
#define PPSJ_PPSJ1 _PPSJ.Bits.PPSJ1
#define PPSJ_PPSJ6 _PPSJ.Bits.PPSJ6
#define PPSJ_PPSJ7 _PPSJ.Bits.PPSJ7
#define PPSJ_PPSJ _PPSJ.MergedBits.grpPPSJ
#define PPSJ_PPSJ_6 _PPSJ.MergedBits.grpPPSJ_6


/*** PIEJ - Port J Interrupt Enable Register; 0x0000026E ***/
typedef union {
  byte Byte;
  struct {
    byte PIEJ0       :1;                                       /* Interrupt Enable Port J Bit 0 */
    byte PIEJ1       :1;                                       /* Interrupt Enable Port J Bit 1 */
    byte             :1;
    byte             :1;
    byte             :1;
    byte             :1;
    byte PIEJ6       :1;                                       /* Interrupt Enable Port J Bit 6 */
    byte PIEJ7       :1;                                       /* Interrupt Enable Port J Bit 7 */
  } Bits;
  struct {
    byte grpPIEJ :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpPIEJ_6 :2;
  } MergedBits;
} PIEJSTR;
extern volatile PIEJSTR _PIEJ @(REG_BASE + 0x0000026E);
#define PIEJ _PIEJ.Byte
#define PIEJ_PIEJ0 _PIEJ.Bits.PIEJ0
#define PIEJ_PIEJ1 _PIEJ.Bits.PIEJ1
#define PIEJ_PIEJ6 _PIEJ.Bits.PIEJ6
#define PIEJ_PIEJ7 _PIEJ.Bits.PIEJ7
#define PIEJ_PIEJ _PIEJ.MergedBits.grpPIEJ
#define PIEJ_PIEJ_6 _PIEJ.MergedBits.grpPIEJ_6


/*** PIFJ - Port J Interrupt Flag Register; 0x0000026F ***/
typedef union {
  byte Byte;
  struct {
    byte PIFJ0       :1;                                       /* Interrupt Flags Port J Bit 0 */
    byte PIFJ1       :1;                                       /* Interrupt Flags Port J Bit 1 */
    byte             :1;
    byte             :1;
    byte             :1;
    byte             :1;
    byte PIFJ6       :1;                                       /* Interrupt Flags Port J Bit 6 */
    byte PIFJ7       :1;                                       /* Interrupt Flags Port J Bit 7 */
  } Bits;
  struct {
    byte grpPIFJ :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpPIFJ_6 :2;
  } MergedBits;
} PIFJSTR;
extern volatile PIFJSTR _PIFJ @(REG_BASE + 0x0000026F);
#define PIFJ _PIFJ.Byte
#define PIFJ_PIFJ0 _PIFJ.Bits.PIFJ0
#define PIFJ_PIFJ1 _PIFJ.Bits.PIFJ1
#define PIFJ_PIFJ6 _PIFJ.Bits.PIFJ6
#define PIFJ_PIFJ7 _PIFJ.Bits.PIFJ7
#define PIFJ_PIFJ _PIFJ.MergedBits.grpPIFJ
#define PIFJ_PIFJ_6 _PIFJ.MergedBits.grpPIFJ_6


/*** BDMSTS - BDM Status Register; 0x0000FF01 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1;
    byte UNSEC       :1;                                       /* Unsecure */
    byte CLKSW       :1;                                       /* Clock switch */
    byte TRACE       :1;                                       /* TRACE1 BDM firmware command is being executed */
    byte SDV         :1;                                       /* Shift data valid */
    byte ENTAG       :1;                                       /* Tagging enable */
    byte BDMACT      :1;                                       /* BDM active status */
    byte ENBDM       :1;                                       /* Enable BDM */
  } Bits;
} BDMSTSSTR;
extern volatile BDMSTSSTR _BDMSTS @(0x0000FF01);
#define BDMSTS _BDMSTS.Byte
#define BDMSTS_UNSEC _BDMSTS.Bits.UNSEC
#define BDMSTS_CLKSW _BDMSTS.Bits.CLKSW
#define BDMSTS_TRACE _BDMSTS.Bits.TRACE
#define BDMSTS_SDV _BDMSTS.Bits.SDV
#define BDMSTS_ENTAG _BDMSTS.Bits.ENTAG
#define BDMSTS_BDMACT _BDMSTS.Bits.BDMACT
#define BDMSTS_ENBDM _BDMSTS.Bits.ENBDM


/*** BDMCCR - BDM CCR Holding Register; 0x0000FF06 ***/
typedef union {
  byte Byte;
  struct {
    byte CCR0        :1;                                       /* BDM CCR Holding Bit 0 */
    byte CCR1        :1;                                       /* BDM CCR Holding Bit 1 */
    byte CCR2        :1;                                       /* BDM CCR Holding Bit 2 */
    byte CCR3        :1;                                       /* BDM CCR Holding Bit 3 */
    byte CCR4        :1;                                       /* BDM CCR Holding Bit 4 */
    byte CCR5        :1;                                       /* BDM CCR Holding Bit 5 */
    byte CCR6        :1;                                       /* BDM CCR Holding Bit 6 */
    byte CCR7        :1;                                       /* BDM CCR Holding Bit 7 */
  } Bits;
  struct {
    byte grpCCR  :8;
  } MergedBits;
} BDMCCRSTR;
extern volatile BDMCCRSTR _BDMCCR @(0x0000FF06);
#define BDMCCR _BDMCCR.Byte
#define BDMCCR_CCR0 _BDMCCR.Bits.CCR0
#define BDMCCR_CCR1 _BDMCCR.Bits.CCR1
#define BDMCCR_CCR2 _BDMCCR.Bits.CCR2
#define BDMCCR_CCR3 _BDMCCR.Bits.CCR3
#define BDMCCR_CCR4 _BDMCCR.Bits.CCR4
#define BDMCCR_CCR5 _BDMCCR.Bits.CCR5
#define BDMCCR_CCR6 _BDMCCR.Bits.CCR6
#define BDMCCR_CCR7 _BDMCCR.Bits.CCR7
#define BDMCCR_CCR _BDMCCR.MergedBits.grpCCR


/*** BDMINR - BDM Internal Register Position Register; 0x0000FF07 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1;
    byte             :1;
    byte             :1;
    byte REG11       :1;                                       /* Internal register map position */
    byte REG12       :1;                                       /* Internal register map position */
    byte REG13       :1;                                       /* Internal register map position */
    byte REG14       :1;                                       /* Internal register map position */
    byte REG15       :1;                                       /* Internal register map position */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpREG_11 :5;
  } MergedBits;
} BDMINRSTR;
extern volatile BDMINRSTR _BDMINR @(0x0000FF07);
#define BDMINR _BDMINR.Byte
#define BDMINR_REG11 _BDMINR.Bits.REG11
#define BDMINR_REG12 _BDMINR.Bits.REG12
#define BDMINR_REG13 _BDMINR.Bits.REG13
#define BDMINR_REG14 _BDMINR.Bits.REG14
#define BDMINR_REG15 _BDMINR.Bits.REG15
#define BDMINR_REG_11 _BDMINR.MergedBits.grpREG_11
#define BDMINR_REG BDMINR_REG_11


  /* Watchdog reset macro */
#ifdef _lint
  #define __RESET_WATCHDOG()  /* empty */
#else
  #define __RESET_WATCHDOG() (void)(ARMCOP = 0x55, ARMCOP = 0xAA)  /* Just write a byte to feed the dog */
#endif

#endif

