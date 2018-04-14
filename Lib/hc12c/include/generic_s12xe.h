
#ifndef _MC9S12XE_GENERIC_H
#define _MC9S12XE_GENERIC_H

/* Types definition */
typedef unsigned char byte;
typedef unsigned int word;
typedef unsigned long dword;
typedef unsigned long dlong[2];

#define REG_BASE 0x0000                /* Base address for the I/O register block */


#pragma MESSAGE DISABLE C1106 /* WARNING C1106: Non-standard bitfield type */


/*** IVBR - Interrupt Vector Base Register; 0x00000121 ***/
typedef union {
  byte Byte;
  struct {
    byte IVB_ADDR    :8;                                       /* Interrupt vector base address bits */
  } Bits;
} IVBRSTR;
extern volatile IVBRSTR _IVBR @(REG_BASE + 0x00000121);
#define IVBR                            _IVBR.Byte
#define IVBR_IVB_ADDR                   _IVBR.Bits.IVB_ADDR

#define IVBR_IVB_ADDR_MASK              255
#define IVBR_IVB_ADDR_BITNUM            0


/*** INT_XGPRIO - XGATE Interrupt Priority Configuration Register; 0x00000126 ***/
typedef union {
  byte Byte;
  struct {
    byte XILVL       :3;                                       /* XGATE Interrupt Priority Level */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} INT_XGPRIOSTR;
extern volatile INT_XGPRIOSTR _INT_XGPRIO @(REG_BASE + 0x00000126);
#define INT_XGPRIO                      _INT_XGPRIO.Byte
#define INT_XGPRIO_XILVL                _INT_XGPRIO.Bits.XILVL

#define INT_XGPRIO_XILVL_MASK           7
#define INT_XGPRIO_XILVL_BITNUM         0


/*** INT_CFADDR - Interrupt Configuration Address Register; 0x00000127 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte INT_CFADDRGrp :4;                                     /* Interrupt Request Configuration Data Register select bits */
  } Bits;
} INT_CFADDRSTR;
extern volatile INT_CFADDRSTR _INT_CFADDR @(REG_BASE + 0x00000127);
#define INT_CFADDR                      _INT_CFADDR.Byte
#define INT_CFADDR_INT_CFADDRGrp        _INT_CFADDR.Bits.INT_CFADDRGrp

#define INT_CFADDR_INT_CFADDRGrp_MASK   240
#define INT_CFADDR_INT_CFADDRGrp_BITNUM 4


/*** INT_CFDATA0 - Interrupt Configuration Data Register 0; 0x00000128 ***/
typedef union {
  byte Byte;
  struct {
    byte PRIOLVL     :3;                                       /* Interrupt Request Priority Level Bits */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte RQST        :1;                                       /* XGATE Request Enable */
  } Bits;
} INT_CFDATA0STR;
extern volatile INT_CFDATA0STR _INT_CFDATA0 @(REG_BASE + 0x00000128);
#define INT_CFDATA0                     _INT_CFDATA0.Byte
#define INT_CFDATA0_PRIOLVL             _INT_CFDATA0.Bits.PRIOLVL
#define INT_CFDATA0_RQST                _INT_CFDATA0.Bits.RQST
/* INT_CFDATA_ARR: Access 8 INT_CFDATAx registers in an array */
#define INT_CFDATA_ARR                  ((volatile byte *) &INT_CFDATA0)

#define INT_CFDATA0_PRIOLVL_MASK        7
#define INT_CFDATA0_PRIOLVL_BITNUM      0
#define INT_CFDATA0_RQST_MASK           128


/*** INT_CFDATA1 - Interrupt Configuration Data Register 1; 0x00000129 ***/
typedef union {
  byte Byte;
  struct {
    byte PRIOLVL     :3;                                       /* Interrupt Request Priority Level Bits */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte RQST        :1;                                       /* XGATE Request Enable */
  } Bits;
} INT_CFDATA1STR;
extern volatile INT_CFDATA1STR _INT_CFDATA1 @(REG_BASE + 0x00000129);
#define INT_CFDATA1                     _INT_CFDATA1.Byte
#define INT_CFDATA1_PRIOLVL             _INT_CFDATA1.Bits.PRIOLVL
#define INT_CFDATA1_RQST                _INT_CFDATA1.Bits.RQST

#define INT_CFDATA1_PRIOLVL_MASK        7
#define INT_CFDATA1_PRIOLVL_BITNUM      0
#define INT_CFDATA1_RQST_MASK           128


/*** INT_CFDATA2 - Interrupt Configuration Data Register 2; 0x0000012A ***/
typedef union {
  byte Byte;
  struct {
    byte PRIOLVL     :3;                                       /* Interrupt Request Priority Level Bits */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte RQST        :1;                                       /* XGATE Request Enable */
  } Bits;
} INT_CFDATA2STR;
extern volatile INT_CFDATA2STR _INT_CFDATA2 @(REG_BASE + 0x0000012A);
#define INT_CFDATA2                     _INT_CFDATA2.Byte
#define INT_CFDATA2_PRIOLVL             _INT_CFDATA2.Bits.PRIOLVL
#define INT_CFDATA2_RQST                _INT_CFDATA2.Bits.RQST

#define INT_CFDATA2_PRIOLVL_MASK        7
#define INT_CFDATA2_PRIOLVL_BITNUM      0
#define INT_CFDATA2_RQST_MASK           128


/*** INT_CFDATA3 - Interrupt Configuration Data Register 3; 0x0000012B ***/
typedef union {
  byte Byte;
  struct {
    byte PRIOLVL     :3;                                       /* Interrupt Request Priority Level Bits */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte RQST        :1;                                       /* XGATE Request Enable */
  } Bits;
} INT_CFDATA3STR;
extern volatile INT_CFDATA3STR _INT_CFDATA3 @(REG_BASE + 0x0000012B);
#define INT_CFDATA3                     _INT_CFDATA3.Byte
#define INT_CFDATA3_PRIOLVL             _INT_CFDATA3.Bits.PRIOLVL
#define INT_CFDATA3_RQST                _INT_CFDATA3.Bits.RQST

#define INT_CFDATA3_PRIOLVL_MASK        7
#define INT_CFDATA3_PRIOLVL_BITNUM      0
#define INT_CFDATA3_RQST_MASK           128


/*** INT_CFDATA4 - Interrupt Configuration Data Register 4; 0x0000012C ***/
typedef union {
  byte Byte;
  struct {
    byte PRIOLVL     :3;                                       /* Interrupt Request Priority Level Bits */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte RQST        :1;                                       /* XGATE Request Enable */
  } Bits;
} INT_CFDATA4STR;
extern volatile INT_CFDATA4STR _INT_CFDATA4 @(REG_BASE + 0x0000012C);
#define INT_CFDATA4                     _INT_CFDATA4.Byte
#define INT_CFDATA4_PRIOLVL             _INT_CFDATA4.Bits.PRIOLVL
#define INT_CFDATA4_RQST                _INT_CFDATA4.Bits.RQST

#define INT_CFDATA4_PRIOLVL_MASK        7
#define INT_CFDATA4_PRIOLVL_BITNUM      0
#define INT_CFDATA4_RQST_MASK           128


/*** INT_CFDATA5 - Interrupt Configuration Data Register 5; 0x0000012D ***/
typedef union {
  byte Byte;
  struct {
    byte PRIOLVL     :3;                                       /* Interrupt Request Priority Level Bits */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte RQST        :1;                                       /* XGATE Request Enable */
  } Bits;
} INT_CFDATA5STR;
extern volatile INT_CFDATA5STR _INT_CFDATA5 @(REG_BASE + 0x0000012D);
#define INT_CFDATA5                     _INT_CFDATA5.Byte
#define INT_CFDATA5_PRIOLVL             _INT_CFDATA5.Bits.PRIOLVL
#define INT_CFDATA5_RQST                _INT_CFDATA5.Bits.RQST

#define INT_CFDATA5_PRIOLVL_MASK        7
#define INT_CFDATA5_PRIOLVL_BITNUM      0
#define INT_CFDATA5_RQST_MASK           128


/*** INT_CFDATA6 - Interrupt Configuration Data Register 6; 0x0000012E ***/
typedef union {
  byte Byte;
  struct {
    byte PRIOLVL     :3;                                       /* Interrupt Request Priority Level Bits */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte RQST        :1;                                       /* XGATE Request Enable */
  } Bits;
} INT_CFDATA6STR;
extern volatile INT_CFDATA6STR _INT_CFDATA6 @(REG_BASE + 0x0000012E);
#define INT_CFDATA6                     _INT_CFDATA6.Byte
#define INT_CFDATA6_PRIOLVL             _INT_CFDATA6.Bits.PRIOLVL
#define INT_CFDATA6_RQST                _INT_CFDATA6.Bits.RQST

#define INT_CFDATA6_PRIOLVL_MASK        7
#define INT_CFDATA6_PRIOLVL_BITNUM      0
#define INT_CFDATA6_RQST_MASK           128


/*** INT_CFDATA7 - Interrupt Configuration Data Register 7; 0x0000012F ***/
typedef union {
  byte Byte;
  struct {
    byte PRIOLVL     :3;                                       /* Interrupt Request Priority Level Bits */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte RQST        :1;                                       /* XGATE Request Enable */
  } Bits;
} INT_CFDATA7STR;
extern volatile INT_CFDATA7STR _INT_CFDATA7 @(REG_BASE + 0x0000012F);
#define INT_CFDATA7                     _INT_CFDATA7.Byte
#define INT_CFDATA7_PRIOLVL             _INT_CFDATA7.Bits.PRIOLVL
#define INT_CFDATA7_RQST                _INT_CFDATA7.Bits.RQST

#define INT_CFDATA7_PRIOLVL_MASK        7
#define INT_CFDATA7_PRIOLVL_BITNUM      0
#define INT_CFDATA7_RQST_MASK           128





/*** XGMCTL - XGATE Module Control Register; 0x00000380 ***/
typedef union {
  word Word;
  struct {
    word XGIE        :1;                                       /* XGATE Interrupt Enable */
    word XGSWEIF     :1;                                       /* XGATE Software Error Interrupt Flag */
    word             :1; 
    word XGFACT      :1;                                       /* Fake XGATE Activity */
    word XGSS        :1;                                       /* XGATE Single Step */
    word XGDBG       :1;                                       /* XGATE Debug Mode */
    word XGFRZ       :1;                                       /* Halt XGATE in Freeze Mode */
    word XGE         :1;                                       /* XGATE Module Enable */
    word XGIEM       :1;                                       /* XGIE Mask */
    word XGSWEIFM    :1;                                       /* XGSWEIF Mask */
    word             :1; 
    word XGFACTM     :1;                                       /* XGFACT Mask */
    word XGSSM       :1;                                       /* XGSS Mask */
    word XGDBGM      :1;                                       /* XGDBG Mask */
    word XGFRZM      :1;                                       /* XGFRZ Mask */
    word XGEM        :1;                                       /* XGE Mask */
  } Bits;
} XGMCTLSTR;
extern volatile XGMCTLSTR _XGMCTL @(REG_BASE + 0x00000380);
#define XGMCTL                          _XGMCTL.Word
#define XGMCTL_XGIE                     _XGMCTL.Bits.XGIE
#define XGMCTL_XGSWEIF                  _XGMCTL.Bits.XGSWEIF
#define XGMCTL_XGFACT                   _XGMCTL.Bits.XGFACT
#define XGMCTL_XGSS                     _XGMCTL.Bits.XGSS
#define XGMCTL_XGDBG                    _XGMCTL.Bits.XGDBG
#define XGMCTL_XGFRZ                    _XGMCTL.Bits.XGFRZ
#define XGMCTL_XGE                      _XGMCTL.Bits.XGE
#define XGMCTL_XGIEM                    _XGMCTL.Bits.XGIEM
#define XGMCTL_XGSWEIFM                 _XGMCTL.Bits.XGSWEIFM
#define XGMCTL_XGFACTM                  _XGMCTL.Bits.XGFACTM
#define XGMCTL_XGSSM                    _XGMCTL.Bits.XGSSM
#define XGMCTL_XGDBGM                   _XGMCTL.Bits.XGDBGM
#define XGMCTL_XGFRZM                   _XGMCTL.Bits.XGFRZM
#define XGMCTL_XGEM                     _XGMCTL.Bits.XGEM

#define XGMCTL_XGIE_MASK                1
#define XGMCTL_XGSWEIF_MASK             2
#define XGMCTL_XGFACT_MASK              8
#define XGMCTL_XGSS_MASK                16
#define XGMCTL_XGDBG_MASK               32
#define XGMCTL_XGFRZ_MASK               64
#define XGMCTL_XGE_MASK                 128
#define XGMCTL_XGIEM_MASK               256
#define XGMCTL_XGSWEIFM_MASK            512
#define XGMCTL_XGFACTM_MASK             2048
#define XGMCTL_XGSSM_MASK               4096
#define XGMCTL_XGDBGM_MASK              8192
#define XGMCTL_XGFRZM_MASK              16384
#define XGMCTL_XGEM_MASK                32768


/*** XGCHID - XGATE Channel ID Register; 0x00000382 ***/
typedef union {
  byte Byte;
  struct {
    byte XGCHIDGrp   :7;                                       /* Request Identifier */
    byte             :1; 
  } Bits;
} XGCHIDSTR;
extern volatile XGCHIDSTR _XGCHID @(REG_BASE + 0x00000382);
#define XGCHID                          _XGCHID.Byte
#define XGCHID_XGCHIDGrp                _XGCHID.Bits.XGCHIDGrp

#define XGCHID_XGCHIDGrp_MASK           127
#define XGCHID_XGCHIDGrp_BITNUM         0


/*** XGCHPL - XGATE Channel XGATE Channel Priority Level ***/
extern volatile byte _XGCHPL @(REG_BASE + 0x00000383);

/*** XGISPSEL - XGATE Initial Stack Pointer Select Register (XGISPSEL) ***/
extern volatile byte XGISPSEL @(REG_BASE + 0x00000385);

/*** XGVBR - XGATE Vector Base Address Register; 0x00000386 ***/
typedef union {
  word Word;
  struct {
    word             :1; 
    word XGVBRGrp    :15;                                      /* Vector Base Address */
  } Bits;
} XGVBRSTR;
extern volatile XGVBRSTR _XGVBR @(REG_BASE + 0x00000386);
#define XGVBR                           _XGVBR.Word
#define XGVBR_XGVBRGrp                  _XGVBR.Bits.XGVBRGrp

#define XGVBR_XGVBRGrp_MASK             65534
#define XGVBR_XGVBRGrp_BITNUM           1


/*** XGISP74 - XGATE Initial Stack Pointer for Interrupt Priorities 7 to 4 ***/
#define XGISP74 XGVBR


/*** XGISP31 - XGATE Initial Stack Pointer for Interrupt Priorities 3 to 1 ***/
#define XGISP31 XGVBR


/*** XGIF0 - XGATE Channel Interrupt Flag Vector 0; 0x00000388 ***/
typedef union {
  word Word;
  struct {
    word XGIF_70     :1;                                       /* Channel Interrupt Flag 70 */
    word XGIF_71     :1;                                       /* Channel Interrupt Flag 71 */
    word XGIF_72     :1;                                       /* Channel Interrupt Flag 72 */
    word XGIF_73     :1;                                       /* Channel Interrupt Flag 73 */
    word XGIF_74     :1;                                       /* Channel Interrupt Flag 74 */
    word XGIF_75     :1;                                       /* Channel Interrupt Flag 75 */
    word XGIF_76     :1;                                       /* Channel Interrupt Flag 76 */
    word XGIF_77     :1;                                       /* Channel Interrupt Flag 77 */
    word XGIF_78     :1;                                       /* Channel Interrupt Flag 78 */
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
  } Bits;
  struct {
    word grpXGIF__70 :9;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
  } MergedBits;
} XGIF0STR;
extern volatile XGIF0STR _XGIF0 @(REG_BASE + 0x00000388);
#define XGIF0                           _XGIF0.Word
#define XGIF0_XGIF_70                   _XGIF0.Bits.XGIF_70
#define XGIF0_XGIF_71                   _XGIF0.Bits.XGIF_71
#define XGIF0_XGIF_72                   _XGIF0.Bits.XGIF_72
#define XGIF0_XGIF_73                   _XGIF0.Bits.XGIF_73
#define XGIF0_XGIF_74                   _XGIF0.Bits.XGIF_74
#define XGIF0_XGIF_75                   _XGIF0.Bits.XGIF_75
#define XGIF0_XGIF_76                   _XGIF0.Bits.XGIF_76
#define XGIF0_XGIF_77                   _XGIF0.Bits.XGIF_77
#define XGIF0_XGIF_78                   _XGIF0.Bits.XGIF_78
/* XGIF_ARR: Access 8 XGIFx registers in an array */
#define XGIF_ARR                        ((word *) &XGIF0)
#define XGIF0_XGIF__70                  _XGIF0.MergedBits.grpXGIF__70
#define XGIF0_XGIF_                     XGIF0_XGIF__70

#define XGIF0_XGIF_70_MASK              1
#define XGIF0_XGIF_71_MASK              2
#define XGIF0_XGIF_72_MASK              4
#define XGIF0_XGIF_73_MASK              8
#define XGIF0_XGIF_74_MASK              16
#define XGIF0_XGIF_75_MASK              32
#define XGIF0_XGIF_76_MASK              64
#define XGIF0_XGIF_77_MASK              128
#define XGIF0_XGIF_78_MASK              256
#define XGIF0_XGIF__70_MASK             511
#define XGIF0_XGIF__70_BITNUM           0


/*** XGIF1 - XGATE Channel Interrupt Flag Vector 1; 0x0000038A ***/
typedef union {
  word Word;
  struct {
    word XGIF_60     :1;                                       /* Channel Interrupt Flag 60 */
    word XGIF_61     :1;                                       /* Channel Interrupt Flag 61 */
    word XGIF_62     :1;                                       /* Channel Interrupt Flag 62 */
    word XGIF_63     :1;                                       /* Channel Interrupt Flag 63 */
    word XGIF_64     :1;                                       /* Channel Interrupt Flag 64 */
    word XGIF_65     :1;                                       /* Channel Interrupt Flag 65 */
    word XGIF_66     :1;                                       /* Channel Interrupt Flag 66 */
    word XGIF_67     :1;                                       /* Channel Interrupt Flag 67 */
    word XGIF_68     :1;                                       /* Channel Interrupt Flag 68 */
    word XGIF_69     :1;                                       /* Channel Interrupt Flag 69 */
    word XGIF_6A     :1;                                       /* Channel Interrupt Flag 6A */
    word XGIF_6B     :1;                                       /* Channel Interrupt Flag 6B */
    word XGIF_6C     :1;                                       /* Channel Interrupt Flag 6C */
    word XGIF_6D     :1;                                       /* Channel Interrupt Flag 6D */
    word XGIF_6E     :1;                                       /* Channel Interrupt Flag 6E */
    word XGIF_6F     :1;                                       /* Channel Interrupt Flag 6F */
  } Bits;
  struct {
    word grpXGIF__60 :10;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
  } MergedBits;
} XGIF1STR;
extern volatile XGIF1STR _XGIF1 @(REG_BASE + 0x0000038A);
#define XGIF1                           _XGIF1.Word
#define XGIF1_XGIF_60                   _XGIF1.Bits.XGIF_60
#define XGIF1_XGIF_61                   _XGIF1.Bits.XGIF_61
#define XGIF1_XGIF_62                   _XGIF1.Bits.XGIF_62
#define XGIF1_XGIF_63                   _XGIF1.Bits.XGIF_63
#define XGIF1_XGIF_64                   _XGIF1.Bits.XGIF_64
#define XGIF1_XGIF_65                   _XGIF1.Bits.XGIF_65
#define XGIF1_XGIF_66                   _XGIF1.Bits.XGIF_66
#define XGIF1_XGIF_67                   _XGIF1.Bits.XGIF_67
#define XGIF1_XGIF_68                   _XGIF1.Bits.XGIF_68
#define XGIF1_XGIF_69                   _XGIF1.Bits.XGIF_69
#define XGIF1_XGIF_6A                   _XGIF1.Bits.XGIF_6A
#define XGIF1_XGIF_6B                   _XGIF1.Bits.XGIF_6B
#define XGIF1_XGIF_6C                   _XGIF1.Bits.XGIF_6C
#define XGIF1_XGIF_6D                   _XGIF1.Bits.XGIF_6D
#define XGIF1_XGIF_6E                   _XGIF1.Bits.XGIF_6E
#define XGIF1_XGIF_6F                   _XGIF1.Bits.XGIF_6F
#define XGIF1_XGIF__60                  _XGIF1.MergedBits.grpXGIF__60
#define XGIF1_XGIF_                     XGIF1_XGIF__60

#define XGIF1_XGIF_60_MASK              1
#define XGIF1_XGIF_61_MASK              2
#define XGIF1_XGIF_62_MASK              4
#define XGIF1_XGIF_63_MASK              8
#define XGIF1_XGIF_64_MASK              16
#define XGIF1_XGIF_65_MASK              32
#define XGIF1_XGIF_66_MASK              64
#define XGIF1_XGIF_67_MASK              128
#define XGIF1_XGIF_68_MASK              256
#define XGIF1_XGIF_69_MASK              512
#define XGIF1_XGIF_6A_MASK              1024
#define XGIF1_XGIF_6B_MASK              2048
#define XGIF1_XGIF_6C_MASK              4096
#define XGIF1_XGIF_6D_MASK              8192
#define XGIF1_XGIF_6E_MASK              16384
#define XGIF1_XGIF_6F_MASK              32768
#define XGIF1_XGIF__60_MASK             1023
#define XGIF1_XGIF__60_BITNUM           0


/*** XGIF2 - XGATE Channel Interrupt Flag Vector 2; 0x0000038C ***/
typedef union {
  word Word;
  struct {
    word XGIF_50     :1;                                       /* Channel Interrupt Flag 50 */
    word XGIF_51     :1;                                       /* Channel Interrupt Flag 51 */
    word XGIF_52     :1;                                       /* Channel Interrupt Flag 52 */
    word XGIF_53     :1;                                       /* Channel Interrupt Flag 53 */
    word XGIF_54     :1;                                       /* Channel Interrupt Flag 54 */
    word XGIF_55     :1;                                       /* Channel Interrupt Flag 55 */
    word XGIF_56     :1;                                       /* Channel Interrupt Flag 56 */
    word XGIF_57     :1;                                       /* Channel Interrupt Flag 57 */
    word XGIF_58     :1;                                       /* Channel Interrupt Flag 58 */
    word XGIF_59     :1;                                       /* Channel Interrupt Flag 59 */
    word XGIF_5A     :1;                                       /* Channel Interrupt Flag 5A */
    word XGIF_5B     :1;                                       /* Channel Interrupt Flag 5B */
    word XGIF_5C     :1;                                       /* Channel Interrupt Flag 5C */
    word XGIF_5D     :1;                                       /* Channel Interrupt Flag 5D */
    word XGIF_5E     :1;                                       /* Channel Interrupt Flag 5E */
    word XGIF_5F     :1;                                       /* Channel Interrupt Flag 5F */
  } Bits;
  struct {
    word grpXGIF__50 :10;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
  } MergedBits;
} XGIF2STR;
extern volatile XGIF2STR _XGIF2 @(REG_BASE + 0x0000038C);
#define XGIF2                           _XGIF2.Word
#define XGIF2_XGIF_50                   _XGIF2.Bits.XGIF_50
#define XGIF2_XGIF_51                   _XGIF2.Bits.XGIF_51
#define XGIF2_XGIF_52                   _XGIF2.Bits.XGIF_52
#define XGIF2_XGIF_53                   _XGIF2.Bits.XGIF_53
#define XGIF2_XGIF_54                   _XGIF2.Bits.XGIF_54
#define XGIF2_XGIF_55                   _XGIF2.Bits.XGIF_55
#define XGIF2_XGIF_56                   _XGIF2.Bits.XGIF_56
#define XGIF2_XGIF_57                   _XGIF2.Bits.XGIF_57
#define XGIF2_XGIF_58                   _XGIF2.Bits.XGIF_58
#define XGIF2_XGIF_59                   _XGIF2.Bits.XGIF_59
#define XGIF2_XGIF_5A                   _XGIF2.Bits.XGIF_5A
#define XGIF2_XGIF_5B                   _XGIF2.Bits.XGIF_5B
#define XGIF2_XGIF_5C                   _XGIF2.Bits.XGIF_5C
#define XGIF2_XGIF_5D                   _XGIF2.Bits.XGIF_5D
#define XGIF2_XGIF_5E                   _XGIF2.Bits.XGIF_5E
#define XGIF2_XGIF_5F                   _XGIF2.Bits.XGIF_5F
#define XGIF2_XGIF__50                  _XGIF2.MergedBits.grpXGIF__50
#define XGIF2_XGIF_                     XGIF2_XGIF__50

#define XGIF2_XGIF_50_MASK              1
#define XGIF2_XGIF_51_MASK              2
#define XGIF2_XGIF_52_MASK              4
#define XGIF2_XGIF_53_MASK              8
#define XGIF2_XGIF_54_MASK              16
#define XGIF2_XGIF_55_MASK              32
#define XGIF2_XGIF_56_MASK              64
#define XGIF2_XGIF_57_MASK              128
#define XGIF2_XGIF_58_MASK              256
#define XGIF2_XGIF_59_MASK              512
#define XGIF2_XGIF_5A_MASK              1024
#define XGIF2_XGIF_5B_MASK              2048
#define XGIF2_XGIF_5C_MASK              4096
#define XGIF2_XGIF_5D_MASK              8192
#define XGIF2_XGIF_5E_MASK              16384
#define XGIF2_XGIF_5F_MASK              32768
#define XGIF2_XGIF__50_MASK             1023
#define XGIF2_XGIF__50_BITNUM           0


/*** XGIF3 - XGATE Channel Interrupt Flag Vector 3; 0x0000038E ***/
typedef union {
  word Word;
  struct {
    word XGIF_40     :1;                                       /* Channel Interrupt Flag 40 */
    word XGIF_41     :1;                                       /* Channel Interrupt Flag 41 */
    word XGIF_42     :1;                                       /* Channel Interrupt Flag 42 */
    word XGIF_43     :1;                                       /* Channel Interrupt Flag 43 */
    word XGIF_44     :1;                                       /* Channel Interrupt Flag 44 */
    word XGIF_45     :1;                                       /* Channel Interrupt Flag 45 */
    word XGIF_46     :1;                                       /* Channel Interrupt Flag 46 */
    word XGIF_47     :1;                                       /* Channel Interrupt Flag 47 */
    word XGIF_48     :1;                                       /* Channel Interrupt Flag 48 */
    word XGIF_49     :1;                                       /* Channel Interrupt Flag 49 */
    word XGIF_4A     :1;                                       /* Channel Interrupt Flag 4A */
    word XGIF_4B     :1;                                       /* Channel Interrupt Flag 4B */
    word XGIF_4C     :1;                                       /* Channel Interrupt Flag 4C */
    word XGIF_4D     :1;                                       /* Channel Interrupt Flag 4D */
    word XGIF_4E     :1;                                       /* Channel Interrupt Flag 4E */
    word XGIF_4F     :1;                                       /* Channel Interrupt Flag 4F */
  } Bits;
  struct {
    word grpXGIF__40 :10;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
  } MergedBits;
} XGIF3STR;
extern volatile XGIF3STR _XGIF3 @(REG_BASE + 0x0000038E);
#define XGIF3                           _XGIF3.Word
#define XGIF3_XGIF_40                   _XGIF3.Bits.XGIF_40
#define XGIF3_XGIF_41                   _XGIF3.Bits.XGIF_41
#define XGIF3_XGIF_42                   _XGIF3.Bits.XGIF_42
#define XGIF3_XGIF_43                   _XGIF3.Bits.XGIF_43
#define XGIF3_XGIF_44                   _XGIF3.Bits.XGIF_44
#define XGIF3_XGIF_45                   _XGIF3.Bits.XGIF_45
#define XGIF3_XGIF_46                   _XGIF3.Bits.XGIF_46
#define XGIF3_XGIF_47                   _XGIF3.Bits.XGIF_47
#define XGIF3_XGIF_48                   _XGIF3.Bits.XGIF_48
#define XGIF3_XGIF_49                   _XGIF3.Bits.XGIF_49
#define XGIF3_XGIF_4A                   _XGIF3.Bits.XGIF_4A
#define XGIF3_XGIF_4B                   _XGIF3.Bits.XGIF_4B
#define XGIF3_XGIF_4C                   _XGIF3.Bits.XGIF_4C
#define XGIF3_XGIF_4D                   _XGIF3.Bits.XGIF_4D
#define XGIF3_XGIF_4E                   _XGIF3.Bits.XGIF_4E
#define XGIF3_XGIF_4F                   _XGIF3.Bits.XGIF_4F
#define XGIF3_XGIF__40                  _XGIF3.MergedBits.grpXGIF__40
#define XGIF3_XGIF_                     XGIF3_XGIF__40

#define XGIF3_XGIF_40_MASK              1
#define XGIF3_XGIF_41_MASK              2
#define XGIF3_XGIF_42_MASK              4
#define XGIF3_XGIF_43_MASK              8
#define XGIF3_XGIF_44_MASK              16
#define XGIF3_XGIF_45_MASK              32
#define XGIF3_XGIF_46_MASK              64
#define XGIF3_XGIF_47_MASK              128
#define XGIF3_XGIF_48_MASK              256
#define XGIF3_XGIF_49_MASK              512
#define XGIF3_XGIF_4A_MASK              1024
#define XGIF3_XGIF_4B_MASK              2048
#define XGIF3_XGIF_4C_MASK              4096
#define XGIF3_XGIF_4D_MASK              8192
#define XGIF3_XGIF_4E_MASK              16384
#define XGIF3_XGIF_4F_MASK              32768
#define XGIF3_XGIF__40_MASK             1023
#define XGIF3_XGIF__40_BITNUM           0


/*** XGIF4 - XGATE Channel Interrupt Flag Vector 4; 0x00000390 ***/
typedef union {
  word Word;
  struct {
    word XGIF_30     :1;                                       /* Channel Interrupt Flag 30 */
    word XGIF_31     :1;                                       /* Channel Interrupt Flag 31 */
    word XGIF_32     :1;                                       /* Channel Interrupt Flag 32 */
    word XGIF_33     :1;                                       /* Channel Interrupt Flag 33 */
    word XGIF_34     :1;                                       /* Channel Interrupt Flag 34 */
    word XGIF_35     :1;                                       /* Channel Interrupt Flag 35 */
    word XGIF_36     :1;                                       /* Channel Interrupt Flag 36 */
    word XGIF_37     :1;                                       /* Channel Interrupt Flag 37 */
    word XGIF_38     :1;                                       /* Channel Interrupt Flag 38 */
    word XGIF_39     :1;                                       /* Channel Interrupt Flag 39 */
    word XGIF_3A     :1;                                       /* Channel Interrupt Flag 3A */
    word XGIF_3B     :1;                                       /* Channel Interrupt Flag 3B */
    word XGIF_3C     :1;                                       /* Channel Interrupt Flag 3C */
    word XGIF_3D     :1;                                       /* Channel Interrupt Flag 3D */
    word XGIF_3E     :1;                                       /* Channel Interrupt Flag 3E */
    word XGIF_3F     :1;                                       /* Channel Interrupt Flag 3F */
  } Bits;
  struct {
    word grpXGIF__30 :10;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
  } MergedBits;
} XGIF4STR;
extern volatile XGIF4STR _XGIF4 @(REG_BASE + 0x00000390);
#define XGIF4                           _XGIF4.Word
#define XGIF4_XGIF_30                   _XGIF4.Bits.XGIF_30
#define XGIF4_XGIF_31                   _XGIF4.Bits.XGIF_31
#define XGIF4_XGIF_32                   _XGIF4.Bits.XGIF_32
#define XGIF4_XGIF_33                   _XGIF4.Bits.XGIF_33
#define XGIF4_XGIF_34                   _XGIF4.Bits.XGIF_34
#define XGIF4_XGIF_35                   _XGIF4.Bits.XGIF_35
#define XGIF4_XGIF_36                   _XGIF4.Bits.XGIF_36
#define XGIF4_XGIF_37                   _XGIF4.Bits.XGIF_37
#define XGIF4_XGIF_38                   _XGIF4.Bits.XGIF_38
#define XGIF4_XGIF_39                   _XGIF4.Bits.XGIF_39
#define XGIF4_XGIF_3A                   _XGIF4.Bits.XGIF_3A
#define XGIF4_XGIF_3B                   _XGIF4.Bits.XGIF_3B
#define XGIF4_XGIF_3C                   _XGIF4.Bits.XGIF_3C
#define XGIF4_XGIF_3D                   _XGIF4.Bits.XGIF_3D
#define XGIF4_XGIF_3E                   _XGIF4.Bits.XGIF_3E
#define XGIF4_XGIF_3F                   _XGIF4.Bits.XGIF_3F
#define XGIF4_XGIF__30                  _XGIF4.MergedBits.grpXGIF__30
#define XGIF4_XGIF_                     XGIF4_XGIF__30

#define XGIF4_XGIF_30_MASK              1
#define XGIF4_XGIF_31_MASK              2
#define XGIF4_XGIF_32_MASK              4
#define XGIF4_XGIF_33_MASK              8
#define XGIF4_XGIF_34_MASK              16
#define XGIF4_XGIF_35_MASK              32
#define XGIF4_XGIF_36_MASK              64
#define XGIF4_XGIF_37_MASK              128
#define XGIF4_XGIF_38_MASK              256
#define XGIF4_XGIF_39_MASK              512
#define XGIF4_XGIF_3A_MASK              1024
#define XGIF4_XGIF_3B_MASK              2048
#define XGIF4_XGIF_3C_MASK              4096
#define XGIF4_XGIF_3D_MASK              8192
#define XGIF4_XGIF_3E_MASK              16384
#define XGIF4_XGIF_3F_MASK              32768
#define XGIF4_XGIF__30_MASK             1023
#define XGIF4_XGIF__30_BITNUM           0


/*** XGIF5 - XGATE Channel Interrupt Flag Vector 5; 0x00000392 ***/
typedef union {
  word Word;
  struct {
    word XGIF_20     :1;                                       /* Channel Interrupt Flag 20 */
    word XGIF_21     :1;                                       /* Channel Interrupt Flag 21 */
    word XGIF_22     :1;                                       /* Channel Interrupt Flag 22 */
    word XGIF_23     :1;                                       /* Channel Interrupt Flag 23 */
    word XGIF_24     :1;                                       /* Channel Interrupt Flag 24 */
    word XGIF_25     :1;                                       /* Channel Interrupt Flag 25 */
    word XGIF_26     :1;                                       /* Channel Interrupt Flag 26 */
    word XGIF_27     :1;                                       /* Channel Interrupt Flag 27 */
    word XGIF_28     :1;                                       /* Channel Interrupt Flag 28 */
    word XGIF_29     :1;                                       /* Channel Interrupt Flag 29 */
    word XGIF_2A     :1;                                       /* Channel Interrupt Flag 2A */
    word XGIF_2B     :1;                                       /* Channel Interrupt Flag 2B */
    word XGIF_2C     :1;                                       /* Channel Interrupt Flag 2C */
    word XGIF_2D     :1;                                       /* Channel Interrupt Flag 2D */
    word XGIF_2E     :1;                                       /* Channel Interrupt Flag 2E */
    word XGIF_2F     :1;                                       /* Channel Interrupt Flag 2F */
  } Bits;
  struct {
    word grpXGIF__20 :10;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
  } MergedBits;
} XGIF5STR;
extern volatile XGIF5STR _XGIF5 @(REG_BASE + 0x00000392);
#define XGIF5                           _XGIF5.Word
#define XGIF5_XGIF_20                   _XGIF5.Bits.XGIF_20
#define XGIF5_XGIF_21                   _XGIF5.Bits.XGIF_21
#define XGIF5_XGIF_22                   _XGIF5.Bits.XGIF_22
#define XGIF5_XGIF_23                   _XGIF5.Bits.XGIF_23
#define XGIF5_XGIF_24                   _XGIF5.Bits.XGIF_24
#define XGIF5_XGIF_25                   _XGIF5.Bits.XGIF_25
#define XGIF5_XGIF_26                   _XGIF5.Bits.XGIF_26
#define XGIF5_XGIF_27                   _XGIF5.Bits.XGIF_27
#define XGIF5_XGIF_28                   _XGIF5.Bits.XGIF_28
#define XGIF5_XGIF_29                   _XGIF5.Bits.XGIF_29
#define XGIF5_XGIF_2A                   _XGIF5.Bits.XGIF_2A
#define XGIF5_XGIF_2B                   _XGIF5.Bits.XGIF_2B
#define XGIF5_XGIF_2C                   _XGIF5.Bits.XGIF_2C
#define XGIF5_XGIF_2D                   _XGIF5.Bits.XGIF_2D
#define XGIF5_XGIF_2E                   _XGIF5.Bits.XGIF_2E
#define XGIF5_XGIF_2F                   _XGIF5.Bits.XGIF_2F
#define XGIF5_XGIF__20                  _XGIF5.MergedBits.grpXGIF__20
#define XGIF5_XGIF_                     XGIF5_XGIF__20

#define XGIF5_XGIF_20_MASK              1
#define XGIF5_XGIF_21_MASK              2
#define XGIF5_XGIF_22_MASK              4
#define XGIF5_XGIF_23_MASK              8
#define XGIF5_XGIF_24_MASK              16
#define XGIF5_XGIF_25_MASK              32
#define XGIF5_XGIF_26_MASK              64
#define XGIF5_XGIF_27_MASK              128
#define XGIF5_XGIF_28_MASK              256
#define XGIF5_XGIF_29_MASK              512
#define XGIF5_XGIF_2A_MASK              1024
#define XGIF5_XGIF_2B_MASK              2048
#define XGIF5_XGIF_2C_MASK              4096
#define XGIF5_XGIF_2D_MASK              8192
#define XGIF5_XGIF_2E_MASK              16384
#define XGIF5_XGIF_2F_MASK              32768
#define XGIF5_XGIF__20_MASK             1023
#define XGIF5_XGIF__20_BITNUM           0


/*** XGIF6 - XGATE Channel Interrupt Flag Vector 6; 0x00000394 ***/
typedef union {
  word Word;
  struct {
    word XGIF_10     :1;                                       /* Channel Interrupt Flag 10 */
    word XGIF_11     :1;                                       /* Channel Interrupt Flag 11 */
    word XGIF_12     :1;                                       /* Channel Interrupt Flag 12 */
    word XGIF_13     :1;                                       /* Channel Interrupt Flag 13 */
    word XGIF_14     :1;                                       /* Channel Interrupt Flag 14 */
    word XGIF_15     :1;                                       /* Channel Interrupt Flag 15 */
    word XGIF_16     :1;                                       /* Channel Interrupt Flag 16 */
    word XGIF_17     :1;                                       /* Channel Interrupt Flag 17 */
    word XGIF_18     :1;                                       /* Channel Interrupt Flag 18 */
    word XGIF_19     :1;                                       /* Channel Interrupt Flag 19 */
    word XGIF_1A     :1;                                       /* Channel Interrupt Flag 1A */
    word XGIF_1B     :1;                                       /* Channel Interrupt Flag 1B */
    word XGIF_1C     :1;                                       /* Channel Interrupt Flag 1C */
    word XGIF_1D     :1;                                       /* Channel Interrupt Flag 1D */
    word XGIF_1E     :1;                                       /* Channel Interrupt Flag 1E */
    word XGIF_1F     :1;                                       /* Channel Interrupt Flag 1F */
  } Bits;
  struct {
    word grpXGIF__10 :10;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
  } MergedBits;
} XGIF6STR;
extern volatile XGIF6STR _XGIF6 @(REG_BASE + 0x00000394);
#define XGIF6                           _XGIF6.Word
#define XGIF6_XGIF_10                   _XGIF6.Bits.XGIF_10
#define XGIF6_XGIF_11                   _XGIF6.Bits.XGIF_11
#define XGIF6_XGIF_12                   _XGIF6.Bits.XGIF_12
#define XGIF6_XGIF_13                   _XGIF6.Bits.XGIF_13
#define XGIF6_XGIF_14                   _XGIF6.Bits.XGIF_14
#define XGIF6_XGIF_15                   _XGIF6.Bits.XGIF_15
#define XGIF6_XGIF_16                   _XGIF6.Bits.XGIF_16
#define XGIF6_XGIF_17                   _XGIF6.Bits.XGIF_17
#define XGIF6_XGIF_18                   _XGIF6.Bits.XGIF_18
#define XGIF6_XGIF_19                   _XGIF6.Bits.XGIF_19
#define XGIF6_XGIF_1A                   _XGIF6.Bits.XGIF_1A
#define XGIF6_XGIF_1B                   _XGIF6.Bits.XGIF_1B
#define XGIF6_XGIF_1C                   _XGIF6.Bits.XGIF_1C
#define XGIF6_XGIF_1D                   _XGIF6.Bits.XGIF_1D
#define XGIF6_XGIF_1E                   _XGIF6.Bits.XGIF_1E
#define XGIF6_XGIF_1F                   _XGIF6.Bits.XGIF_1F
#define XGIF6_XGIF__10                  _XGIF6.MergedBits.grpXGIF__10
#define XGIF6_XGIF_                     XGIF6_XGIF__10

#define XGIF6_XGIF_10_MASK              1
#define XGIF6_XGIF_11_MASK              2
#define XGIF6_XGIF_12_MASK              4
#define XGIF6_XGIF_13_MASK              8
#define XGIF6_XGIF_14_MASK              16
#define XGIF6_XGIF_15_MASK              32
#define XGIF6_XGIF_16_MASK              64
#define XGIF6_XGIF_17_MASK              128
#define XGIF6_XGIF_18_MASK              256
#define XGIF6_XGIF_19_MASK              512
#define XGIF6_XGIF_1A_MASK              1024
#define XGIF6_XGIF_1B_MASK              2048
#define XGIF6_XGIF_1C_MASK              4096
#define XGIF6_XGIF_1D_MASK              8192
#define XGIF6_XGIF_1E_MASK              16384
#define XGIF6_XGIF_1F_MASK              32768
#define XGIF6_XGIF__10_MASK             1023
#define XGIF6_XGIF__10_BITNUM           0


/*** XGIF7 - XGATE Channel Interrupt Flag Vector 7; 0x00000396 ***/
typedef union {
  word Word;
  struct {
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word XGIF_09     :1;                                       /* Channel Interrupt Flag 09 */
    word XGIF_0A     :1;                                       /* Channel Interrupt Flag 0A */
    word XGIF_0B     :1;                                       /* Channel Interrupt Flag 0B */
    word XGIF_0C     :1;                                       /* Channel Interrupt Flag 0C */
    word XGIF_0D     :1;                                       /* Channel Interrupt Flag 0D */
    word XGIF_0E     :1;                                       /* Channel Interrupt Flag 0E */
    word XGIF_0F     :1;                                       /* Channel Interrupt Flag 0F */
  } Bits;
} XGIF7STR;
extern volatile XGIF7STR _XGIF7 @(REG_BASE + 0x00000396);
#define XGIF7                           _XGIF7.Word
#define XGIF7_XGIF_09                   _XGIF7.Bits.XGIF_09
#define XGIF7_XGIF_0A                   _XGIF7.Bits.XGIF_0A
#define XGIF7_XGIF_0B                   _XGIF7.Bits.XGIF_0B
#define XGIF7_XGIF_0C                   _XGIF7.Bits.XGIF_0C
#define XGIF7_XGIF_0D                   _XGIF7.Bits.XGIF_0D
#define XGIF7_XGIF_0E                   _XGIF7.Bits.XGIF_0E
#define XGIF7_XGIF_0F                   _XGIF7.Bits.XGIF_0F

#define XGIF7_XGIF_09_MASK              512
#define XGIF7_XGIF_0A_MASK              1024
#define XGIF7_XGIF_0B_MASK              2048
#define XGIF7_XGIF_0C_MASK              4096
#define XGIF7_XGIF_0D_MASK              8192
#define XGIF7_XGIF_0E_MASK              16384
#define XGIF7_XGIF_0F_MASK              32768


/*** XGSWT - XGATE Software Trigger Register; 0x00000398 ***/
typedef union {
  word Word;
  struct {
    word XGSWTGrp    :8;                                       /* Software Trigger Bits */
    word XGSWTM      :8;                                       /* Software Trigger Mask */
  } Bits;
} XGSWTSTR;
extern volatile XGSWTSTR _XGSWT @(REG_BASE + 0x00000398);
#define XGSWT                           _XGSWT.Word
#define XGSWT_XGSWTGrp                  _XGSWT.Bits.XGSWTGrp
#define XGSWT_XGSWTM                    _XGSWT.Bits.XGSWTM

#define XGSWT_XGSWTGrp_MASK             255
#define XGSWT_XGSWTGrp_BITNUM           0
#define XGSWT_XGSWTM_MASK               65280
#define XGSWT_XGSWTM_BITNUM             8


/*** XGSEM - XGATE Semaphore Register; 0x0000039A ***/
typedef union {
  word Word;
  struct {
    word XGSEMGrp    :8;                                       /* Semaphore Mask */
    word XGSEMM      :8;                                       /* Semaphore Bits */
  } Bits;
} XGSEMSTR;
extern volatile XGSEMSTR _XGSEM @(REG_BASE + 0x0000039A);
#define XGSEM                           _XGSEM.Word
#define XGSEM_XGSEMGrp                  _XGSEM.Bits.XGSEMGrp
#define XGSEM_XGSEMM                    _XGSEM.Bits.XGSEMM

#define XGSEM_XGSEMGrp_MASK             255
#define XGSEM_XGSEMGrp_BITNUM           0
#define XGSEM_XGSEMM_MASK               65280
#define XGSEM_XGSEMM_BITNUM             8


/*** XGPC - XGATE Program Counter Register; 0x0000039E ***/
typedef union {
  word Word;
} XGPCSTR;
extern volatile XGPCSTR _XGPC @(REG_BASE + 0x0000039E);
#define XGPC                            _XGPC.Word



/*** XGR1 - XGATE Register 1; 0x000003A2 ***/
typedef union {
  word Word;
} XGR1STR;
extern volatile XGR1STR _XGR1 @(REG_BASE + 0x000003A2);
#define XGR1                            _XGR1.Word



/*** XGR2 - XGATE Register 2; 0x000003A4 ***/
typedef union {
  word Word;
} XGR2STR;
extern volatile XGR2STR _XGR2 @(REG_BASE + 0x000003A4);
#define XGR2                            _XGR2.Word



/*** XGR3 - XGATE Register 3; 0x000003A6 ***/
typedef union {
  word Word;
} XGR3STR;
extern volatile XGR3STR _XGR3 @(REG_BASE + 0x000003A6);
#define XGR3                            _XGR3.Word



/*** XGR4 - XGATE Register 4; 0x000003A8 ***/
typedef union {
  word Word;
} XGR4STR;
extern volatile XGR4STR _XGR4 @(REG_BASE + 0x000003A8);
#define XGR4                            _XGR4.Word



/*** XGR5 - XGATE Register 5; 0x000003AA ***/
typedef union {
  word Word;
} XGR5STR;
extern volatile XGR5STR _XGR5 @(REG_BASE + 0x000003AA);
#define XGR5                            _XGR5.Word



/*** XGR6 - XGATE Register 6; 0x000003AC ***/
typedef union {
  word Word;
} XGR6STR;
extern volatile XGR6STR _XGR6 @(REG_BASE + 0x000003AC);
#define XGR6                            _XGR6.Word



/*** XGR7 - XGATE Register 7; 0x000003AE ***/
typedef union {
  word Word;
} XGR7STR;
extern volatile XGR7STR _XGR7 @(REG_BASE + 0x000003AE);
#define XGR7                            _XGR7.Word

  /* Watchdog reset macro */
#ifdef _lint
  #define __RESET_WATCHDOG()  /* empty */
#else
  #define __RESET_WATCHDOG() (void)(ARMCOP = 0x55, ARMCOP = 0xAA)  /* Just write a byte to feed the dog */
#endif

#endif /* _MC9S12XE_GENERIC_H */

