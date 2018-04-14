/* Based on CPU DB MC9S12XDT512_144, version 2.87.300 (RegistersPrg V1.081) */
/* DataSheet : 9S12XDP512DGV1/D V01.10 */

#include <MC9S12XDT512.h>


/* * * * *  8-BIT REGISTERS  * * * * * * * * * * * * * * * */
volatile ARMCOPSTR _ARMCOP;                                /* CRG COP Timer Arm/Reset Register */
volatile ATD0_PORTAD0STR _ATD0_PORTAD0;                    /* ATD 0 Port AD0 Register */
volatile ATD0DIENSTR _ATD0DIEN;                            /* ATD 0 Input Enable Register */
volatile ATD0STAT0STR _ATD0STAT0;                          /* ATD 0 Status Register 0 */
volatile ATD0STAT1STR _ATD0STAT1;                          /* ATD 0 Status Register 1 */
volatile ATD0STAT2STR _ATD0STAT2;                          /* ATD 0 Status Register 2 */
volatile ATD0TEST1STR _ATD0TEST1;                          /* ATD0 Test Register */
volatile ATD1_PORTAD0STR _ATD1_PORTAD0;                    /* ATD1 Port AD0 Register */
volatile ATD1_PORTAD1STR _ATD1_PORTAD1;                    /* ATD1 Port AD1 Register */
volatile ATD1DIEN0STR _ATD1DIEN0;                          /* ATD 1 Input Enable Register 0 */
volatile ATD1DIEN1STR _ATD1DIEN1;                          /* ATD 1 Input Enable Register 1 */
volatile ATD1STAT0STR _ATD1STAT0;                          /* ATD 1 Status Register 0 */
volatile ATD1STAT1STR _ATD1STAT1;                          /* ATD 1 Status Register 1 */
volatile ATD1STAT2STR _ATD1STAT2;                          /* ATD 1 Status Register 2 */
volatile ATD1TEST1STR _ATD1TEST1;                          /* ATD1 Test Register */
volatile CAN0BTR0STR _CAN0BTR0;                            /* MSCAN 0 Bus Timing Register 0 */
volatile CAN0BTR1STR _CAN0BTR1;                            /* MSCAN 0 Bus Timing Register 1 */
volatile CAN0CTL0STR _CAN0CTL0;                            /* MSCAN 0 Control 0 Register */
volatile CAN0CTL1STR _CAN0CTL1;                            /* MSCAN 0 Control 1 Register */
volatile CAN0IDACSTR _CAN0IDAC;                            /* MSCAN 0 Identifier Acceptance Control Register */
volatile CAN0IDAR0STR _CAN0IDAR0;                          /* MSCAN 0 Identifier Acceptance Register 0 */
volatile CAN0IDAR1STR _CAN0IDAR1;                          /* MSCAN 0 Identifier Acceptance Register 1 */
volatile CAN0IDAR2STR _CAN0IDAR2;                          /* MSCAN 0 Identifier Acceptance Register 2 */
volatile CAN0IDAR3STR _CAN0IDAR3;                          /* MSCAN 0 Identifier Acceptance Register 3 */
volatile CAN0IDAR4STR _CAN0IDAR4;                          /* MSCAN 0 Identifier Acceptance Register 4 */
volatile CAN0IDAR5STR _CAN0IDAR5;                          /* MSCAN 0 Identifier Acceptance Register 5 */
volatile CAN0IDAR6STR _CAN0IDAR6;                          /* MSCAN 0 Identifier Acceptance Register 6 */
volatile CAN0IDAR7STR _CAN0IDAR7;                          /* MSCAN 0 Identifier Acceptance Register 7 */
volatile CAN0IDMR0STR _CAN0IDMR0;                          /* MSCAN 0 Identifier Mask Register 0 */
volatile CAN0IDMR1STR _CAN0IDMR1;                          /* MSCAN 0 Identifier Mask Register 1 */
volatile CAN0IDMR2STR _CAN0IDMR2;                          /* MSCAN 0 Identifier Mask Register 2 */
volatile CAN0IDMR3STR _CAN0IDMR3;                          /* MSCAN 0 Identifier Mask Register 3 */
volatile CAN0IDMR4STR _CAN0IDMR4;                          /* MSCAN 0 Identifier Mask Register 4 */
volatile CAN0IDMR5STR _CAN0IDMR5;                          /* MSCAN 0 Identifier Mask Register 5 */
volatile CAN0IDMR6STR _CAN0IDMR6;                          /* MSCAN 0 Identifier Mask Register 6 */
volatile CAN0IDMR7STR _CAN0IDMR7;                          /* MSCAN 0 Identifier Mask Register 7 */
volatile CAN0MISCSTR _CAN0MISC;                            /* MSCAN 0 Miscellaneous Register */
volatile CAN0RFLGSTR _CAN0RFLG;                            /* MSCAN 0 Receiver Flag Register */
volatile CAN0RIERSTR _CAN0RIER;                            /* MSCAN 0 Receiver Interrupt Enable Register */
volatile CAN0RXDLRSTR _CAN0RXDLR;                          /* MSCAN 0 Receive Data Length Register */
volatile CAN0RXDSR0STR _CAN0RXDSR0;                        /* MSCAN 0 Receive Data Segment Register 0 */
volatile CAN0RXDSR1STR _CAN0RXDSR1;                        /* MSCAN 0 Receive Data Segment Register 1 */
volatile CAN0RXDSR2STR _CAN0RXDSR2;                        /* MSCAN 0 Receive Data Segment Register 2 */
volatile CAN0RXDSR3STR _CAN0RXDSR3;                        /* MSCAN 0 Receive Data Segment Register 3 */
volatile CAN0RXDSR4STR _CAN0RXDSR4;                        /* MSCAN 0 Receive Data Segment Register 4 */
volatile CAN0RXDSR5STR _CAN0RXDSR5;                        /* MSCAN 0 Receive Data Segment Register 5 */
volatile CAN0RXDSR6STR _CAN0RXDSR6;                        /* MSCAN 0 Receive Data Segment Register 6 */
volatile CAN0RXDSR7STR _CAN0RXDSR7;                        /* MSCAN 0 Receive Data Segment Register 7 */
volatile CAN0RXERRSTR _CAN0RXERR;                          /* MSCAN 0 Receive Error Counter Register */
volatile CAN0RXIDR0STR _CAN0RXIDR0;                        /* MSCAN 0 Receive Identifier Register 0 */
volatile CAN0RXIDR1STR _CAN0RXIDR1;                        /* MSCAN 0 Receive Identifier Register 1 */
volatile CAN0RXIDR2STR _CAN0RXIDR2;                        /* MSCAN 0 Receive Identifier Register 2 */
volatile CAN0RXIDR3STR _CAN0RXIDR3;                        /* MSCAN 0 Receive Identifier Register 3 */
volatile CAN0TAAKSTR _CAN0TAAK;                            /* MSCAN 0 Transmitter Message Abort Control */
volatile CAN0TARQSTR _CAN0TARQ;                            /* MSCAN 0 Transmitter Message Abort Request */
volatile CAN0TBSELSTR _CAN0TBSEL;                          /* MSCAN 0 Transmit Buffer Selection */
volatile CAN0TFLGSTR _CAN0TFLG;                            /* MSCAN 0 Transmitter Flag Register */
volatile CAN0TIERSTR _CAN0TIER;                            /* MSCAN 0 Transmitter Interrupt Enable Register */
volatile CAN0TXDLRSTR _CAN0TXDLR;                          /* MSCAN 0 Transmit Data Length Register */
volatile CAN0TXDSR0STR _CAN0TXDSR0;                        /* MSCAN 0 Transmit Data Segment Register 0 */
volatile CAN0TXDSR1STR _CAN0TXDSR1;                        /* MSCAN 0 Transmit Data Segment Register 1 */
volatile CAN0TXDSR2STR _CAN0TXDSR2;                        /* MSCAN 0 Transmit Data Segment Register 2 */
volatile CAN0TXDSR3STR _CAN0TXDSR3;                        /* MSCAN 0 Transmit Data Segment Register 3 */
volatile CAN0TXDSR4STR _CAN0TXDSR4;                        /* MSCAN 0 Transmit Data Segment Register 4 */
volatile CAN0TXDSR5STR _CAN0TXDSR5;                        /* MSCAN 0 Transmit Data Segment Register 5 */
volatile CAN0TXDSR6STR _CAN0TXDSR6;                        /* MSCAN 0 Transmit Data Segment Register 6 */
volatile CAN0TXDSR7STR _CAN0TXDSR7;                        /* MSCAN 0 Transmit Data Segment Register 7 */
volatile CAN0TXERRSTR _CAN0TXERR;                          /* MSCAN 0 Transmit Error Counter Register */
volatile CAN0TXIDR0STR _CAN0TXIDR0;                        /* MSCAN 0 Transmit Identifier Register 0 */
volatile CAN0TXIDR1STR _CAN0TXIDR1;                        /* MSCAN 0 Transmit Identifier Register 1 */
volatile CAN0TXIDR2STR _CAN0TXIDR2;                        /* MSCAN 0 Transmit Identifier Register 2 */
volatile CAN0TXIDR3STR _CAN0TXIDR3;                        /* MSCAN 0 Transmit Identifier Register 3 */
volatile CAN0TXTBPRSTR _CAN0TXTBPR;                        /* MSCAN 0 Transmit Buffer Priority */
volatile CAN1BTR0STR _CAN1BTR0;                            /* MSCAN 1 Bus Timing Register 0 */
volatile CAN1BTR1STR _CAN1BTR1;                            /* MSCAN 1 Bus Timing Register 1 */
volatile CAN1CTL0STR _CAN1CTL0;                            /* MSCAN 1 Control 0 Register */
volatile CAN1CTL1STR _CAN1CTL1;                            /* MSCAN 1 Control 1 Register */
volatile CAN1IDACSTR _CAN1IDAC;                            /* MSCAN 1 Identifier Acceptance Control Register */
volatile CAN1IDAR0STR _CAN1IDAR0;                          /* MSCAN 1 Identifier Acceptance Register 0 */
volatile CAN1IDAR1STR _CAN1IDAR1;                          /* MSCAN 1 Identifier Acceptance Register 1 */
volatile CAN1IDAR2STR _CAN1IDAR2;                          /* MSCAN 1 Identifier Acceptance Register 2 */
volatile CAN1IDAR3STR _CAN1IDAR3;                          /* MSCAN 1 Identifier Acceptance Register 3 */
volatile CAN1IDAR4STR _CAN1IDAR4;                          /* MSCAN 1 Identifier Acceptance Register 4 */
volatile CAN1IDAR5STR _CAN1IDAR5;                          /* MSCAN 1 Identifier Acceptance Register 5 */
volatile CAN1IDAR6STR _CAN1IDAR6;                          /* MSCAN 1 Identifier Acceptance Register 6 */
volatile CAN1IDAR7STR _CAN1IDAR7;                          /* MSCAN 1 Identifier Acceptance Register 7 */
volatile CAN1IDMR0STR _CAN1IDMR0;                          /* MSCAN 1 Identifier Mask Register 0 */
volatile CAN1IDMR1STR _CAN1IDMR1;                          /* MSCAN 1 Identifier Mask Register 1 */
volatile CAN1IDMR2STR _CAN1IDMR2;                          /* MSCAN 1 Identifier Mask Register 2 */
volatile CAN1IDMR3STR _CAN1IDMR3;                          /* MSCAN 1 Identifier Mask Register 3 */
volatile CAN1IDMR4STR _CAN1IDMR4;                          /* MSCAN 1 Identifier Mask Register 4 */
volatile CAN1IDMR5STR _CAN1IDMR5;                          /* MSCAN 1 Identifier Mask Register 5 */
volatile CAN1IDMR6STR _CAN1IDMR6;                          /* MSCAN 1 Identifier Mask Register 6 */
volatile CAN1IDMR7STR _CAN1IDMR7;                          /* MSCAN 1 Identifier Mask Register 7 */
volatile CAN1MISCSTR _CAN1MISC;                            /* MSCAN 1 Miscellaneous Register */
volatile CAN1RFLGSTR _CAN1RFLG;                            /* MSCAN 1 Receiver Flag Register */
volatile CAN1RIERSTR _CAN1RIER;                            /* MSCAN 1 Receiver Interrupt Enable Register */
volatile CAN1RXDLRSTR _CAN1RXDLR;                          /* MSCAN 1 Receive Data Length Register */
volatile CAN1RXDSR0STR _CAN1RXDSR0;                        /* MSCAN 1 Receive Data Segment Register 0 */
volatile CAN1RXDSR1STR _CAN1RXDSR1;                        /* MSCAN 1 Receive Data Segment Register 1 */
volatile CAN1RXDSR2STR _CAN1RXDSR2;                        /* MSCAN 1 Receive Data Segment Register 2 */
volatile CAN1RXDSR3STR _CAN1RXDSR3;                        /* MSCAN 1 Receive Data Segment Register 3 */
volatile CAN1RXDSR4STR _CAN1RXDSR4;                        /* MSCAN 1 Receive Data Segment Register 4 */
volatile CAN1RXDSR5STR _CAN1RXDSR5;                        /* MSCAN 1 Receive Data Segment Register 5 */
volatile CAN1RXDSR6STR _CAN1RXDSR6;                        /* MSCAN 1 Receive Data Segment Register 6 */
volatile CAN1RXDSR7STR _CAN1RXDSR7;                        /* MSCAN 1 Receive Data Segment Register 7 */
volatile CAN1RXERRSTR _CAN1RXERR;                          /* MSCAN 1 Receive Error Counter Register */
volatile CAN1RXIDR0STR _CAN1RXIDR0;                        /* MSCAN 1 Receive Identifier Register 0 */
volatile CAN1RXIDR1STR _CAN1RXIDR1;                        /* MSCAN 1 Receive Identifier Register 1 */
volatile CAN1RXIDR2STR _CAN1RXIDR2;                        /* MSCAN 1 Receive Identifier Register 2 */
volatile CAN1RXIDR3STR _CAN1RXIDR3;                        /* MSCAN 1 Receive Identifier Register 3 */
volatile CAN1TAAKSTR _CAN1TAAK;                            /* MSCAN 1 Transmitter Message Abort Control */
volatile CAN1TARQSTR _CAN1TARQ;                            /* MSCAN 1 Transmitter Message Abort Request */
volatile CAN1TBSELSTR _CAN1TBSEL;                          /* MSCAN 1 Transmit Buffer Selection */
volatile CAN1TFLGSTR _CAN1TFLG;                            /* MSCAN 1 Transmitter Flag Register */
volatile CAN1TIERSTR _CAN1TIER;                            /* MSCAN 1 Transmitter Interrupt Enable Register */
volatile CAN1TXDLRSTR _CAN1TXDLR;                          /* MSCAN 1 Transmit Data Length Register */
volatile CAN1TXDSR0STR _CAN1TXDSR0;                        /* MSCAN 1 Transmit Data Segment Register 0 */
volatile CAN1TXDSR1STR _CAN1TXDSR1;                        /* MSCAN 1 Transmit Data Segment Register 1 */
volatile CAN1TXDSR2STR _CAN1TXDSR2;                        /* MSCAN 1 Transmit Data Segment Register 2 */
volatile CAN1TXDSR3STR _CAN1TXDSR3;                        /* MSCAN 1 Transmit Data Segment Register 3 */
volatile CAN1TXDSR4STR _CAN1TXDSR4;                        /* MSCAN 1 Transmit Data Segment Register 4 */
volatile CAN1TXDSR5STR _CAN1TXDSR5;                        /* MSCAN 1 Transmit Data Segment Register 5 */
volatile CAN1TXDSR6STR _CAN1TXDSR6;                        /* MSCAN 1 Transmit Data Segment Register 6 */
volatile CAN1TXDSR7STR _CAN1TXDSR7;                        /* MSCAN 1 Transmit Data Segment Register 7 */
volatile CAN1TXERRSTR _CAN1TXERR;                          /* MSCAN 1 Transmit Error Counter Register */
volatile CAN1TXIDR0STR _CAN1TXIDR0;                        /* MSCAN 1 Transmit Identifier Register 0 */
volatile CAN1TXIDR1STR _CAN1TXIDR1;                        /* MSCAN 1 Transmit Identifier Register 1 */
volatile CAN1TXIDR2STR _CAN1TXIDR2;                        /* MSCAN 1 Transmit Identifier Register 2 */
volatile CAN1TXIDR3STR _CAN1TXIDR3;                        /* MSCAN 1 Transmit Identifier Register 3 */
volatile CAN1TXTBPRSTR _CAN1TXTBPR;                        /* MSCAN 1 Transmit Buffer Priority */
volatile CAN4BTR0STR _CAN4BTR0;                            /* MSCAN 4 Bus Timing Register 0 */
volatile CAN4BTR1STR _CAN4BTR1;                            /* MSCAN 4 Bus Timing Register 1 */
volatile CAN4CTL0STR _CAN4CTL0;                            /* MSCAN 4 Control 0 Register */
volatile CAN4CTL1STR _CAN4CTL1;                            /* MSCAN 4 Control 1 Register */
volatile CAN4IDACSTR _CAN4IDAC;                            /* MSCAN 4 Identifier Acceptance Control Register */
volatile CAN4IDAR0STR _CAN4IDAR0;                          /* MSCAN 4 Identifier Acceptance Register 0 */
volatile CAN4IDAR1STR _CAN4IDAR1;                          /* MSCAN 4 Identifier Acceptance Register 1 */
volatile CAN4IDAR2STR _CAN4IDAR2;                          /* MSCAN 4 Identifier Acceptance Register 2 */
volatile CAN4IDAR3STR _CAN4IDAR3;                          /* MSCAN 4 Identifier Acceptance Register 3 */
volatile CAN4IDAR4STR _CAN4IDAR4;                          /* MSCAN 4 Identifier Acceptance Register 4 */
volatile CAN4IDAR5STR _CAN4IDAR5;                          /* MSCAN 4 Identifier Acceptance Register 5 */
volatile CAN4IDAR6STR _CAN4IDAR6;                          /* MSCAN 4 Identifier Acceptance Register 6 */
volatile CAN4IDAR7STR _CAN4IDAR7;                          /* MSCAN 4 Identifier Acceptance Register 7 */
volatile CAN4IDMR0STR _CAN4IDMR0;                          /* MSCAN 4 Identifier Mask Register 0 */
volatile CAN4IDMR1STR _CAN4IDMR1;                          /* MSCAN 4 Identifier Mask Register 1 */
volatile CAN4IDMR2STR _CAN4IDMR2;                          /* MSCAN 4 Identifier Mask Register 2 */
volatile CAN4IDMR3STR _CAN4IDMR3;                          /* MSCAN 4 Identifier Mask Register 3 */
volatile CAN4IDMR4STR _CAN4IDMR4;                          /* MSCAN 4 Identifier Mask Register 4 */
volatile CAN4IDMR5STR _CAN4IDMR5;                          /* MSCAN 4 Identifier Mask Register 5 */
volatile CAN4IDMR6STR _CAN4IDMR6;                          /* MSCAN 4 Identifier Mask Register 6 */
volatile CAN4IDMR7STR _CAN4IDMR7;                          /* MSCAN 4 Identifier Mask Register 7 */
volatile CAN4MISCSTR _CAN4MISC;                            /* MSCAN 4 Miscellaneous Register */
volatile CAN4RFLGSTR _CAN4RFLG;                            /* MSCAN 4 Receiver Flag Register */
volatile CAN4RIERSTR _CAN4RIER;                            /* MSCAN 4 Receiver Interrupt Enable Register */
volatile CAN4RXDLRSTR _CAN4RXDLR;                          /* MSCAN 4 Receive Data Length Register */
volatile CAN4RXDSR0STR _CAN4RXDSR0;                        /* MSCAN 4 Receive Data Segment Register 0 */
volatile CAN4RXDSR1STR _CAN4RXDSR1;                        /* MSCAN 4 Receive Data Segment Register 1 */
volatile CAN4RXDSR2STR _CAN4RXDSR2;                        /* MSCAN 4 Receive Data Segment Register 2 */
volatile CAN4RXDSR3STR _CAN4RXDSR3;                        /* MSCAN 4 Receive Data Segment Register 3 */
volatile CAN4RXDSR4STR _CAN4RXDSR4;                        /* MSCAN 4 Receive Data Segment Register 4 */
volatile CAN4RXDSR5STR _CAN4RXDSR5;                        /* MSCAN 4 Receive Data Segment Register 5 */
volatile CAN4RXDSR6STR _CAN4RXDSR6;                        /* MSCAN 4 Receive Data Segment Register 6 */
volatile CAN4RXDSR7STR _CAN4RXDSR7;                        /* MSCAN 4 Receive Data Segment Register 7 */
volatile CAN4RXERRSTR _CAN4RXERR;                          /* MSCAN 4 Receive Error Counter Register */
volatile CAN4RXIDR0STR _CAN4RXIDR0;                        /* MSCAN 4 Receive Identifier Register 0 */
volatile CAN4RXIDR1STR _CAN4RXIDR1;                        /* MSCAN 4 Receive Identifier Register 1 */
volatile CAN4RXIDR2STR _CAN4RXIDR2;                        /* MSCAN 4 Receive Identifier Register 2 */
volatile CAN4RXIDR3STR _CAN4RXIDR3;                        /* MSCAN 4 Receive Identifier Register 3 */
volatile CAN4TAAKSTR _CAN4TAAK;                            /* MSCAN 4 Transmitter Message Abort Control */
volatile CAN4TARQSTR _CAN4TARQ;                            /* MSCAN 4 Transmitter Message Abort Request */
volatile CAN4TBSELSTR _CAN4TBSEL;                          /* MSCAN 4 Transmit Buffer Selection */
volatile CAN4TFLGSTR _CAN4TFLG;                            /* MSCAN 4 Transmitter Flag Register */
volatile CAN4TIERSTR _CAN4TIER;                            /* MSCAN 4 Transmitter Interrupt Enable Register */
volatile CAN4TXDLRSTR _CAN4TXDLR;                          /* MSCAN 4 Transmit Data Length Register */
volatile CAN4TXDSR0STR _CAN4TXDSR0;                        /* MSCAN 4 Transmit Data Segment Register 0 */
volatile CAN4TXDSR1STR _CAN4TXDSR1;                        /* MSCAN 4 Transmit Data Segment Register 1 */
volatile CAN4TXDSR2STR _CAN4TXDSR2;                        /* MSCAN 4 Transmit Data Segment Register 2 */
volatile CAN4TXDSR3STR _CAN4TXDSR3;                        /* MSCAN 4 Transmit Data Segment Register 3 */
volatile CAN4TXDSR4STR _CAN4TXDSR4;                        /* MSCAN 4 Transmit Data Segment Register 4 */
volatile CAN4TXDSR5STR _CAN4TXDSR5;                        /* MSCAN 4 Transmit Data Segment Register 5 */
volatile CAN4TXDSR6STR _CAN4TXDSR6;                        /* MSCAN 4 Transmit Data Segment Register 6 */
volatile CAN4TXDSR7STR _CAN4TXDSR7;                        /* MSCAN 4 Transmit Data Segment Register 7 */
volatile CAN4TXERRSTR _CAN4TXERR;                          /* MSCAN 4 Transmit Error Counter Register */
volatile CAN4TXIDR0STR _CAN4TXIDR0;                        /* MSCAN 4 Transmit Identifier Register 0 */
volatile CAN4TXIDR1STR _CAN4TXIDR1;                        /* MSCAN 4 Transmit Identifier Register 1 */
volatile CAN4TXIDR2STR _CAN4TXIDR2;                        /* MSCAN 4 Transmit Identifier Register 2 */
volatile CAN4TXIDR3STR _CAN4TXIDR3;                        /* MSCAN 4 Transmit Identifier Register 3 */
volatile CAN4TXTBPRSTR _CAN4TXTBPR;                        /* MSCAN 4 Transmit Buffer Priority */
volatile CFORCSTR _CFORC;                                  /* Timer Compare Force Register */
volatile CLKSELSTR _CLKSEL;                                /* CRG Clock Select Register */
volatile COPCTLSTR _COPCTL;                                /* CRG COP Control Register */
volatile CRGFLGSTR _CRGFLG;                                /* CRG Flags Register */
volatile CRGINTSTR _CRGINT;                                /* CRG Interrupt Enable Register */
volatile DBGC1STR _DBGC1;                                  /* Debug Control Register 1 */
volatile DBGC2STR _DBGC2;                                  /* Debug Control Register 2 */
volatile DBGCNTSTR _DBGCNT;                                /* Debug Count Register */
volatile DBGSCRXSTR _DBGSCRX;                              /* Debug State Control Register 0 */
volatile DBGSRSTR _DBGSR;                                  /* Debug Status Register */
volatile DBGTCRSTR _DBGTCR;                                /* Debug Trace Control Register */
volatile DBGXAHSTR _DBGXAH;                                /* Debug Comparator Address High Register */
volatile DBGXALSTR _DBGXAL;                                /* Debug Comparator Address Low Register */
volatile DBGXAMSTR _DBGXAM;                                /* Debug Comparator Address Mid Register */
volatile DBGXCTLSTR _DBGXCTL;                              /* Debug Comparator Control Register */
volatile DBGXDHSTR _DBGXDH;                                /* Debug Comparator Data High Register */
volatile DBGXDHMSTR _DBGXDHM;                              /* Debug Comparator Data High Mask Register */
volatile DBGXDLSTR _DBGXDL;                                /* Debug Comparator Data Low Register */
volatile DBGXDLMSTR _DBGXDLM;                              /* Debug Comparator Data Low Mask Register */
volatile DDR0AD1STR _DDR0AD1;                              /* Port AD1 Data Direction Register 0 */
volatile DDR1AD0STR _DDR1AD0;                              /* Port AD0 Data Direction Register 1 */
volatile DDR1AD1STR _DDR1AD1;                              /* Port AD1 Data Direction Register 1 */
volatile DDRESTR _DDRE;                                    /* Port E Data Direction Register */
volatile DDRHSTR _DDRH;                                    /* Port H Data Direction Register */
volatile DDRJSTR _DDRJ;                                    /* Port J Data Direction Register */
volatile DDRKSTR _DDRK;                                    /* Port K Data Direction Register */
volatile DDRMSTR _DDRM;                                    /* Port M Data Direction Register */
volatile DDRPSTR _DDRP;                                    /* Port P Data Direction Register */
volatile DDRSSTR _DDRS;                                    /* Port S Data Direction Register */
volatile DDRTSTR _DDRT;                                    /* Port T Data Direction Register */
volatile DIRECTSTR _DIRECT;                                /* Direct Page Register */
volatile DLYCTSTR _DLYCT;                                  /* Delay Counter Control Register */
volatile EADDRHISTR _EADDRHI;                              /* EEPROM Address High Register */
volatile EADDRLOSTR _EADDRLO;                              /* EEPROM Address Low Register */
volatile ECLKDIVSTR _ECLKDIV;                              /* EEPROM Clock Divider Register */
volatile ECMDSTR _ECMD;                                    /* EEPROM Command Buffer and Register */
volatile ECNFGSTR _ECNFG;                                  /* EEPROM Configuration Register */
volatile EDATAHISTR _EDATAHI;                              /* EEPROM Data High Register */
volatile EDATALOSTR _EDATALO;                              /* EEPROM Data Low Register */
volatile EIFCTLSTR _EIFCTL;                                /* External Bus Interface Control Register */
volatile EPAGESTR _EPAGE;                                  /* EEPROM Page Index Register */
volatile EPROTSTR _EPROT;                                  /* EEPROM Protection Register */
volatile ESTATSTR _ESTAT;                                  /* EEPROM Status Register */
volatile FADDRHISTR _FADDRHI;                              /* Flash Address High Register */
volatile FADDRLOSTR _FADDRLO;                              /* Flash Address Low Register */
volatile FCLKDIVSTR _FCLKDIV;                              /* Flash Clock Divider Register */
volatile FCMDSTR _FCMD;                                    /* Flash Command Buffer and Register */
volatile FCNFGSTR _FCNFG;                                  /* Flash Configuration Register */
volatile FDATAHISTR _FDATAHI;                              /* Flash Data High Register */
volatile FDATALOSTR _FDATALO;                              /* Flash Data Low Register */
volatile FPROTSTR _FPROT;                                  /* Flash Protection Register */
volatile FSECSTR _FSEC;                                    /* Flash Security Register */
volatile FSTATSTR _FSTAT;                                  /* Flash Status Register */
volatile GPAGESTR _GPAGE;                                  /* Global Page Index Register */
volatile ICOVWSTR _ICOVW;                                  /* Input Control Overwrite Register */
volatile ICPARSTR _ICPAR;                                  /* Input Control Pulse Accumulator Register */
volatile ICSYSSTR _ICSYS;                                  /* Input Control System Control Register */
volatile IIC0_IBADSTR _IIC0_IBAD;                          /* IIC 0 Address Register */
volatile IIC0_IBCRSTR _IIC0_IBCR;                          /* IIC 0 Control Register */
volatile IIC0_IBDRSTR _IIC0_IBDR;                          /* IIC 0 Data I/O Register */
volatile IIC0_IBFDSTR _IIC0_IBFD;                          /* IIC 0 Frequency Divider Register */
volatile IIC0_IBSRSTR _IIC0_IBSR;                          /* IIC 0 Status Register */
volatile IIC1_IBADSTR _IIC1_IBAD;                          /* IIC 1 Address Register */
volatile IIC1_IBCRSTR _IIC1_IBCR;                          /* IIC 1 Control Register */
volatile IIC1_IBDRSTR _IIC1_IBDR;                          /* IIC 1 Data I/O Register */
volatile IIC1_IBFDSTR _IIC1_IBFD;                          /* IIC 1 Frequency Divider Register */
volatile IIC1_IBSRSTR _IIC1_IBSR;                          /* IIC 1 Status Register */
volatile INT_CFADDRSTR _INT_CFADDR;                        /* Interrupt Configuration Address Register */
volatile INT_CFDATA0STR _INT_CFDATA0;                      /* Interrupt Configuration Data Register 0 */
volatile INT_CFDATA1STR _INT_CFDATA1;                      /* Interrupt Configuration Data Register 1 */
volatile INT_CFDATA2STR _INT_CFDATA2;                      /* Interrupt Configuration Data Register 2 */
volatile INT_CFDATA3STR _INT_CFDATA3;                      /* Interrupt Configuration Data Register 3 */
volatile INT_CFDATA4STR _INT_CFDATA4;                      /* Interrupt Configuration Data Register 4 */
volatile INT_CFDATA5STR _INT_CFDATA5;                      /* Interrupt Configuration Data Register 5 */
volatile INT_CFDATA6STR _INT_CFDATA6;                      /* Interrupt Configuration Data Register 6 */
volatile INT_CFDATA7STR _INT_CFDATA7;                      /* Interrupt Configuration Data Register 7 */
volatile INT_XGPRIOSTR _INT_XGPRIO;                        /* XGATE Interrupt Priority Configuration Register */
volatile IRQCRSTR _IRQCR;                                  /* Interrupt Control Register */
volatile IVBRSTR _IVBR;                                    /* Interrupt Vector Base Register */
volatile MCCTLSTR _MCCTL;                                  /* Modulus Down Counter underflow */
volatile MCFLGSTR _MCFLG;                                  /* 16-Bit Modulus Down Counter Flag Register */
volatile MISCSTR _MISC;                                    /* Miscellaneous System Control Register */
volatile MODESTR _MODE;                                    /* Mode Register */
volatile MODRRSTR _MODRR;                                  /* Module Routing Register */
volatile OC7DSTR _OC7D;                                    /* Output Compare 7 Data Register */
volatile OC7MSTR _OC7M;                                    /* Output Compare 7 Mask Register */
volatile PACTLSTR _PACTL;                                  /* 16-Bit Pulse Accumulator A Control Register */
volatile PAFLGSTR _PAFLG;                                  /* Pulse Accumulator A Flag Register */
volatile PARTIDHSTR _PARTIDH;                              /* Part ID Register High */
volatile PARTIDLSTR _PARTIDL;                              /* Part ID Register Low */
volatile PBCTLSTR _PBCTL;                                  /* 16-Bit Pulse Accumulator B Control Register */
volatile PBFLGSTR _PBFLG;                                  /* Pulse Accumulator B Flag Register */
volatile PER0AD1STR _PER0AD1;                              /* Port AD1 Pull Up Enable Register 0 */
volatile PER1AD0STR _PER1AD0;                              /* Port AD0 Pull Up Enable Register 1 */
volatile PER1AD1STR _PER1AD1;                              /* Port AD1 Pull Up Enable Register 1 */
volatile PERHSTR _PERH;                                    /* Port H Pull Device Enable Register */
volatile PERJSTR _PERJ;                                    /* Port J Pull Device Enable Register */
volatile PERMSTR _PERM;                                    /* Port M Pull Device Enable Register */
volatile PERPSTR _PERP;                                    /* Port P Pull Device Enable Register */
volatile PERSSTR _PERS;                                    /* Port S Pull Device Enable Register */
volatile PERTSTR _PERT;                                    /* Port T Pull Device Enable Register */
volatile PIEHSTR _PIEH;                                    /* Port H Interrupt Enable Register */
volatile PIEJSTR _PIEJ;                                    /* Port J Interrupt Enable Register */
volatile PIEPSTR _PIEP;                                    /* Port P Interrupt Enable Register */
volatile PIFHSTR _PIFH;                                    /* Port H Interrupt Flag Register */
volatile PIFJSTR _PIFJ;                                    /* Port J Interrupt Flag Register */
volatile PIFPSTR _PIFP;                                    /* Port P Interrupt Flag Register */
volatile PITCESTR _PITCE;                                  /* PIT Channel Enable Register */
volatile PITCFLMTSTR _PITCFLMT;                            /* PIT Control and Force Load Micro Timer Register */
volatile PITFLTSTR _PITFLT;                                /* PIT Force Load Timer Register */
volatile PITINTESTR _PITINTE;                              /* PIT Interrupt Enable Register */
volatile PITMTLD0STR _PITMTLD0;                            /* PIT Micro Timer Load Register 0 */
volatile PITMTLD1STR _PITMTLD1;                            /* PIT Micro Timer Load Register 1 */
volatile PITMUXSTR _PITMUX;                                /* PIT Multiplex Register */
volatile PITTFSTR _PITTF;                                  /* PIT Time-out Flag Register */
volatile PLLCTLSTR _PLLCTL;                                /* CRG PLL Control Register */
volatile PORTESTR _PORTE;                                  /* Port E Register */
volatile PORTKSTR _PORTK;                                  /* Port K Data Register */
volatile PPAGESTR _PPAGE;                                  /* Program Page Index Register */
volatile PPSHSTR _PPSH;                                    /* Port H Polarity Select Register */
volatile PPSJSTR _PPSJ;                                    /* Port J Polarity Select Register */
volatile PPSMSTR _PPSM;                                    /* Port M Polarity Select Register */
volatile PPSPSTR _PPSP;                                    /* Port P Polarity Select Register */
volatile PPSSSTR _PPSS;                                    /* Port S Polarity Select Register */
volatile PPSTSTR _PPST;                                    /* Port T Polarity Select Register */
volatile PT0AD1STR _PT0AD1;                                /* Port AD1 Data Register 0 */
volatile PT1AD0STR _PT1AD0;                                /* Port AD0 Data Register 1 */
volatile PT1AD1STR _PT1AD1;                                /* Port AD1 Data Register 1 */
volatile PTHSTR _PTH;                                      /* Port H I/O Register */
volatile PTIHSTR _PTIH;                                    /* Port H Input Register */
volatile PTIJSTR _PTIJ;                                    /* Port J Input Register */
volatile PTIMSTR _PTIM;                                    /* Port M Input Register */
volatile PTIPSTR _PTIP;                                    /* Port P Input Register */
volatile PTISSTR _PTIS;                                    /* Port S Input Register */
volatile PTITSTR _PTIT;                                    /* Port T Input Register */
volatile PTJSTR _PTJ;                                      /* Port J I/O Register */
volatile PTMSTR _PTM;                                      /* Port M I/O Register */
volatile PTMCPSRSTR _PTMCPSR;                              /* Precision Timer Modulus Counter Prescaler Select Register */
volatile PTPSTR _PTP;                                      /* Port P I/O Register */
volatile PTPSRSTR _PTPSR;                                  /* Precision Timer Prescaler Select */
volatile PTSSTR _PTS;                                      /* Port S I/O Register */
volatile PTTSTR _PTT;                                      /* Port T I/O Register */
volatile PUCRSTR _PUCR;                                    /* Pull-Up Control Register */
volatile PWMCAESTR _PWMCAE;                                /* PWM Center Align Enable Register */
volatile PWMCLKSTR _PWMCLK;                                /* PWM Clock Select Register */
volatile PWMCTLSTR _PWMCTL;                                /* PWM Control Register */
volatile PWMESTR _PWME;                                    /* PWM Enable Register */
volatile PWMPOLSTR _PWMPOL;                                /* PWM Polarity Register */
volatile PWMPRCLKSTR _PWMPRCLK;                            /* PWM Prescale Clock Select Register */
volatile PWMSCLASTR _PWMSCLA;                              /* PWM Scale A Register */
volatile PWMSCLBSTR _PWMSCLB;                              /* PWM Scale B Register */
volatile PWMSDNSTR _PWMSDN;                                /* PWM Shutdown Register */
volatile RDR0AD1STR _RDR0AD1;                              /* Port AD1 Reduced Drive Register 0 */
volatile RDR1AD0STR _RDR1AD0;                              /* Port AD0 Reduced Drive Register 1 */
volatile RDR1AD1STR _RDR1AD1;                              /* Port AD1 Reduced Drive Register 1 */
volatile RDRHSTR _RDRH;                                    /* Port H Reduced Drive Register */
volatile RDRIVSTR _RDRIV;                                  /* Reduced Drive of I/O Lines */
volatile RDRJSTR _RDRJ;                                    /* Port J Reduced Drive Register */
volatile RDRMSTR _RDRM;                                    /* Port M Reduced Drive Register */
volatile RDRPSTR _RDRP;                                    /* Port P Reduced Drive Register */
volatile RDRSSTR _RDRS;                                    /* Port S Reduced Drive Register */
volatile RDRTSTR _RDRT;                                    /* Port T Reduced Drive Register */
volatile REFDVSTR _REFDV;                                  /* CRG Reference Divider Register */
volatile RPAGESTR _RPAGE;                                  /* RAM Page Index Register */
volatile RTICTLSTR _RTICTL;                                /* CRG RTI Control Register */
volatile SCI0ASR1STR _SCI0ASR1;                            /* SCI 0 Alternative Status Register 1 */
volatile SCI0CR2STR _SCI0CR2;                              /* SCI 0 Control Register 2 */
volatile SCI0DRHSTR _SCI0DRH;                              /* SCI 0 Data Register High */
volatile SCI0DRLSTR _SCI0DRL;                              /* SCI 0 Data Register Low */
volatile SCI0SR1STR _SCI0SR1;                              /* SCI 0 Status Register 1 */
volatile SCI0SR2STR _SCI0SR2;                              /* SCI 0 Status Register 2 */
volatile SCI1ASR1STR _SCI1ASR1;                            /* SCI 1 Alternative Status Register 1 */
volatile SCI1CR2STR _SCI1CR2;                              /* SCI 1 Control Register 2 */
volatile SCI1DRHSTR _SCI1DRH;                              /* SCI 1 Data Register High */
volatile SCI1DRLSTR _SCI1DRL;                              /* SCI 1 Data Register Low */
volatile SCI1SR1STR _SCI1SR1;                              /* SCI 1 Status Register 1 */
volatile SCI1SR2STR _SCI1SR2;                              /* SCI 1 Status Register 2 */
volatile SCI2ASR1STR _SCI2ASR1;                            /* SCI 2 Alternative Status Register 1 */
volatile SCI2CR2STR _SCI2CR2;                              /* SCI 2 Control Register 2 */
volatile SCI2DRHSTR _SCI2DRH;                              /* SCI 2 Data Register High */
volatile SCI2DRLSTR _SCI2DRL;                              /* SCI 2 Data Register Low */
volatile SCI2SR1STR _SCI2SR1;                              /* SCI 2 Status Register 1 */
volatile SCI2SR2STR _SCI2SR2;                              /* SCI 2 Status Register 2 */
volatile SCI3ASR1STR _SCI3ASR1;                            /* SCI 3 Alternative Status Register 1 */
volatile SCI3CR2STR _SCI3CR2;                              /* SCI 3 Control Register 2 */
volatile SCI3DRHSTR _SCI3DRH;                              /* SCI 3 Data Register High */
volatile SCI3DRLSTR _SCI3DRL;                              /* SCI 3 Data Register Low */
volatile SCI3SR1STR _SCI3SR1;                              /* SCI 3 Status Register 1 */
volatile SCI3SR2STR _SCI3SR2;                              /* SCI 3 Status Register 2 */
volatile SCI4ASR1STR _SCI4ASR1;                            /* SCI 4 Alternative Status Register 1 */
volatile SCI4CR2STR _SCI4CR2;                              /* SCI 4 Control Register 2 */
volatile SCI4DRHSTR _SCI4DRH;                              /* SCI 4 Data Register High */
volatile SCI4DRLSTR _SCI4DRL;                              /* SCI 4 Data Register Low */
volatile SCI4SR1STR _SCI4SR1;                              /* SCI 4 Status Register 1 */
volatile SCI4SR2STR _SCI4SR2;                              /* SCI 4 Status Register 2 */
volatile SCI5ASR1STR _SCI5ASR1;                            /* SCI 5 Alternative Status Register 1 */
volatile SCI5CR2STR _SCI5CR2;                              /* SCI 5 Control Register 2 */
volatile SCI5DRHSTR _SCI5DRH;                              /* SCI 5 Data Register High */
volatile SCI5DRLSTR _SCI5DRL;                              /* SCI 5 Data Register Low */
volatile SCI5SR1STR _SCI5SR1;                              /* SCI 5 Status Register 1 */
volatile SCI5SR2STR _SCI5SR2;                              /* SCI 5 Status Register 2 */
volatile SPI0BRSTR _SPI0BR;                                /* SPI 0 Baud Rate Register */
volatile SPI0CR1STR _SPI0CR1;                              /* SPI 0 Control Register */
volatile SPI0CR2STR _SPI0CR2;                              /* SPI 0 Control Register 2 */
volatile SPI0DRSTR _SPI0DR;                                /* SPI 0 Data Register */
volatile SPI0SRSTR _SPI0SR;                                /* SPI 0 Status Register */
volatile SPI1BRSTR _SPI1BR;                                /* SPI 1 Baud Rate Register */
volatile SPI1CR1STR _SPI1CR1;                              /* SPI 1 Control Register */
volatile SPI1CR2STR _SPI1CR2;                              /* SPI 1 Control Register 2 */
volatile SPI1DRSTR _SPI1DR;                                /* SPI 1 Data Register */
volatile SPI1SRSTR _SPI1SR;                                /* SPI 1 Status Register */
volatile SPI2BRSTR _SPI2BR;                                /* SPI 2 Baud Rate Register */
volatile SPI2CR1STR _SPI2CR1;                              /* SPI 2 Control Register */
volatile SPI2CR2STR _SPI2CR2;                              /* SPI 2 Control Register 2 */
volatile SPI2DRSTR _SPI2DR;                                /* SPI 2 Data Register */
volatile SPI2SRSTR _SPI2SR;                                /* SPI 2 Status Register */
volatile SYNRSTR _SYNR;                                    /* CRG Synthesizer Register */
volatile TCTL1STR _TCTL1;                                  /* Timer Control Register 1 */
volatile TCTL2STR _TCTL2;                                  /* Timer Control Register 2 */
volatile TCTL3STR _TCTL3;                                  /* Timer Control Register 3 */
volatile TCTL4STR _TCTL4;                                  /* Timer Control Register 4 */
volatile TFLG1STR _TFLG1;                                  /* Main Timer Interrupt Flag 1 */
volatile TFLG2STR _TFLG2;                                  /* Main Timer Interrupt Flag 2 */
volatile TIESTR _TIE;                                      /* Timer Interrupt Enable Register */
volatile TIOSSTR _TIOS;                                    /* Timer Input Capture/Output Compare Select */
volatile TSCR1STR _TSCR1;                                  /* Timer System Control Register1 */
volatile TSCR2STR _TSCR2;                                  /* Timer System Control Register 2 */
volatile TTOVSTR _TTOV;                                    /* Timer Toggle On Overflow Register */
volatile VREGAPICLSTR _VREGAPICL;                          /* VREG_3V3 - Autonomous Periodical Interrupt Control Register */
volatile VREGAPITRSTR _VREGAPITR;                          /* VREG_3V3 - Autonomous Periodical Interrupt Trimming Register */
volatile VREGCTRLSTR _VREGCTRL;                            /* VREG_3V3 - Control Register */
volatile WOMMSTR _WOMM;                                    /* Port M Wired-Or Mode Register */
volatile WOMSSTR _WOMS;                                    /* Port S Wired-Or Mode Register */
volatile XGCHIDSTR _XGCHID;                                /* XGATE Channel ID Register */
volatile XGMCTLSTR _XGMCTL;                                /* XGATE Module Control Register */
volatile XSCTRLSTR _XSCTRL;                                /* XSRAM Control Register */
volatile XSSRLBSTR _XSSRLB;                                /* XSRAM XGATE Code Region Lower Boundary Register */
volatile XSSRUBSTR _XSSRUB;                                /* XSRAM Shared Region Upper Boundary Register */
volatile XSXCUBSTR _XSXCUB;                                /* XSRAM XGATE Code Region Upper Boundary Register */


/* * * * *  16-BIT REGISTERS  * * * * * * * * * * * * * * * */
volatile ATD0CTL01STR _ATD0CTL01;                          /* ATD 0 Control Register 01 */
volatile ATD0CTL23STR _ATD0CTL23;                          /* ATD 0 Control Register 23 */
volatile ATD0CTL45STR _ATD0CTL45;                          /* ATD 0 Control Register 45 */
volatile ATD0DR0STR _ATD0DR0;                              /* ATD 0 Conversion Result Register 0 */
volatile ATD0DR1STR _ATD0DR1;                              /* ATD 0 Conversion Result Register 1 */
volatile ATD0DR2STR _ATD0DR2;                              /* ATD 0 Conversion Result Register 2 */
volatile ATD0DR3STR _ATD0DR3;                              /* ATD 0 Conversion Result Register 3 */
volatile ATD0DR4STR _ATD0DR4;                              /* ATD 0 Conversion Result Register 4 */
volatile ATD0DR5STR _ATD0DR5;                              /* ATD 0 Conversion Result Register 5 */
volatile ATD0DR6STR _ATD0DR6;                              /* ATD 0 Conversion Result Register 6 */
volatile ATD0DR7STR _ATD0DR7;                              /* ATD 0 Conversion Result Register 7 */
volatile ATD1CTL01STR _ATD1CTL01;                          /* ATD 1 Control Register 01 */
volatile ATD1CTL23STR _ATD1CTL23;                          /* ATD 1 Control Register 23 */
volatile ATD1CTL45STR _ATD1CTL45;                          /* ATD 1 Control Register 45 */
volatile ATD1DR0STR _ATD1DR0;                              /* ATD 1 Conversion Result Register 0 */
volatile ATD1DR1STR _ATD1DR1;                              /* ATD 1 Conversion Result Register 1 */
volatile ATD1DR10STR _ATD1DR10;                            /* ATD 1 Conversion Result Register 10 */
volatile ATD1DR11STR _ATD1DR11;                            /* ATD 1 Conversion Result Register 11 */
volatile ATD1DR12STR _ATD1DR12;                            /* ATD 1 Conversion Result Register 12 */
volatile ATD1DR13STR _ATD1DR13;                            /* ATD 1 Conversion Result Register 13 */
volatile ATD1DR14STR _ATD1DR14;                            /* ATD 1 Conversion Result Register 14 */
volatile ATD1DR15STR _ATD1DR15;                            /* ATD 1 Conversion Result Register 15 */
volatile ATD1DR2STR _ATD1DR2;                              /* ATD 1 Conversion Result Register 2 */
volatile ATD1DR3STR _ATD1DR3;                              /* ATD 1 Conversion Result Register 3 */
volatile ATD1DR4STR _ATD1DR4;                              /* ATD 1 Conversion Result Register 4 */
volatile ATD1DR5STR _ATD1DR5;                              /* ATD 1 Conversion Result Register 5 */
volatile ATD1DR6STR _ATD1DR6;                              /* ATD 1 Conversion Result Register 6 */
volatile ATD1DR7STR _ATD1DR7;                              /* ATD 1 Conversion Result Register 7 */
volatile ATD1DR8STR _ATD1DR8;                              /* ATD 1 Conversion Result Register 8 */
volatile ATD1DR9STR _ATD1DR9;                              /* ATD 1 Conversion Result Register 9 */
volatile CAN0RXTSRSTR _CAN0RXTSR;                          /* MSCAN 0 Receive Time Stamp Register */
volatile CAN0TXTSRSTR _CAN0TXTSR;                          /* MSCAN 0 Transmit Time Stamp Register */
volatile CAN1RXTSRSTR _CAN1RXTSR;                          /* MSCAN 1 Receive Time Stamp Register */
volatile CAN1TXTSRSTR _CAN1TXTSR;                          /* MSCAN 1 Transmit Time Stamp Register */
volatile CAN4RXTSRSTR _CAN4RXTSR;                          /* MSCAN 4 Receive Time Stamp Register */
volatile CAN4TXTSRSTR _CAN4TXTSR;                          /* MSCAN 4 Transmit Time Stamp Register */
volatile DBGTBSTR _DBGTB;                                  /* Debug Trace Buffer Register */
volatile DDRABSTR _DDRAB;                                  /* Port AB Data Direction */
volatile DDRCDSTR _DDRCD;                                  /* Port CD Data Direction */
volatile MCCNTSTR _MCCNT;                                  /* Modulus Down-Counter Count Register */
volatile PA10HSTR _PA10H;                                  /* 8-Bit Pulse Accumulators Holding 10 Register */
volatile PA32HSTR _PA32H;                                  /* 8-Bit Pulse Accumulators Holding 32 Register */
volatile PACN10STR _PACN10;                                /* Pulse Accumulators Count 10 Register */
volatile PACN32STR _PACN32;                                /* Pulse Accumulators Count 32 Register */
volatile PITCNT0STR _PITCNT0;                              /* PIT Count Register 0 */
volatile PITCNT1STR _PITCNT1;                              /* PIT Count Register 1 */
volatile PITCNT2STR _PITCNT2;                              /* PIT Count Register 2 */
volatile PITCNT3STR _PITCNT3;                              /* PIT Count Register 3 */
volatile PITLD0STR _PITLD0;                                /* PIT Load Register 0 */
volatile PITLD1STR _PITLD1;                                /* PIT Load Register 1 */
volatile PITLD2STR _PITLD2;                                /* PIT Load Register 2 */
volatile PITLD3STR _PITLD3;                                /* PIT Load Register 3 */
volatile PORTABSTR _PORTAB;                                /* Port AB */
volatile PORTCDSTR _PORTCD;                                /* Port CD */
volatile PWMCNT01STR _PWMCNT01;                            /* PWM Channel Counter 01 Register */
volatile PWMCNT23STR _PWMCNT23;                            /* PWM Channel Counter 23 Register */
volatile PWMCNT45STR _PWMCNT45;                            /* PWM Channel Counter 45 Register */
volatile PWMCNT67STR _PWMCNT67;                            /* PWM Channel Counter 67 Register */
volatile PWMDTY01STR _PWMDTY01;                            /* PWM Channel Duty 01 Register */
volatile PWMDTY23STR _PWMDTY23;                            /* PWM Channel Duty 23 Register */
volatile PWMDTY45STR _PWMDTY45;                            /* PWM Channel Duty 45 Register */
volatile PWMDTY67STR _PWMDTY67;                            /* PWM Channel Duty 67 Register */
volatile PWMPER01STR _PWMPER01;                            /* PWM Channel Period 01 Register */
volatile PWMPER23STR _PWMPER23;                            /* PWM Channel Period 23 Register */
volatile PWMPER45STR _PWMPER45;                            /* PWM Channel Period 45 Register */
volatile PWMPER67STR _PWMPER67;                            /* PWM Channel Period 67 Register */
volatile SCI0BDSTR _SCI0BD;                                /* SCI 0 Baud Rate Register */
volatile SCI1BDSTR _SCI1BD;                                /* SCI 1 Baud Rate Register */
volatile SCI2BDSTR _SCI2BD;                                /* SCI 2 Baud Rate Register */
volatile SCI3BDSTR _SCI3BD;                                /* SCI 3 Baud Rate Register */
volatile SCI4BDSTR _SCI4BD;                                /* SCI 4 Baud Rate Register */
volatile SCI5BDSTR _SCI5BD;                                /* SCI 5 Baud Rate Register */
volatile TC0STR _TC0;                                      /* Timer Input Capture/Output Compare Register 0 */
volatile TC0HSTR _TC0H;                                    /* Timer Input Capture Holding Registers 0 */
volatile TC1STR _TC1;                                      /* Timer Input Capture/Output Compare Register 1 */
volatile TC1HSTR _TC1H;                                    /* Timer Input Capture Holding Registers 1 */
volatile TC2STR _TC2;                                      /* Timer Input Capture/Output Compare Register 2 */
volatile TC2HSTR _TC2H;                                    /* Timer Input Capture Holding Registers 2 */
volatile TC3STR _TC3;                                      /* Timer Input Capture/Output Compare Register 3 */
volatile TC3HSTR _TC3H;                                    /* Timer Input Capture Holding Registers 3 */
volatile TC4STR _TC4;                                      /* Timer Input Capture/Output Compare Register 4 */
volatile TC5STR _TC5;                                      /* Timer Input Capture/Output Compare Register 5 */
volatile TC6STR _TC6;                                      /* Timer Input Capture/Output Compare Register 6 */
volatile TC7STR _TC7;                                      /* Timer Input Capture/Output Compare Register 7 */
volatile TCNTSTR _TCNT;                                    /* Timer Count Register */
volatile XGIF0STR _XGIF0;                                  /* XGATE Channel Interrupt Flag Vector 0 */
volatile XGIF1STR _XGIF1;                                  /* XGATE Channel Interrupt Flag Vector 1 */
volatile XGIF2STR _XGIF2;                                  /* XGATE Channel Interrupt Flag Vector 2 */
volatile XGIF3STR _XGIF3;                                  /* XGATE Channel Interrupt Flag Vector 3 */
volatile XGIF4STR _XGIF4;                                  /* XGATE Channel Interrupt Flag Vector 4 */
volatile XGIF5STR _XGIF5;                                  /* XGATE Channel Interrupt Flag Vector 5 */
volatile XGIF6STR _XGIF6;                                  /* XGATE Channel Interrupt Flag Vector 6 */
volatile XGIF7STR _XGIF7;                                  /* XGATE Channel Interrupt Flag Vector 7 */
volatile XGPCSTR _XGPC;                                    /* XGATE Program Counter Register */
volatile XGR1STR _XGR1;                                    /* XGATE Register 1 */
volatile XGR2STR _XGR2;                                    /* XGATE Register 2 */
volatile XGR3STR _XGR3;                                    /* XGATE Register 3 */
volatile XGR4STR _XGR4;                                    /* XGATE Register 4 */
volatile XGR5STR _XGR5;                                    /* XGATE Register 5 */
volatile XGR6STR _XGR6;                                    /* XGATE Register 6 */
volatile XGR7STR _XGR7;                                    /* XGATE Register 7 */
volatile XGSEMSTR _XGSEM;                                  /* XGATE Semaphore Register */
volatile XGSWTSTR _XGSWT;                                  /* XGATE Software Trigger Register */


/* * * * *  32-BIT REGISTERS  * * * * * * * * * * * * * * * */
volatile XGVBR01STR _XGVBR01;                              /* XGATE Vector Base Address Register */

/* EOF */
