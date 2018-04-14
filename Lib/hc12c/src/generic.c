
#include <generic.h>

volatile ARMCOPSTR _ARMCOP;                                /* CRG COP Timer Arm/Reset Register */
volatile ATD0DIENSTR _ATD0DIEN;                            /* ATD 0 Input Enable Mask Register */
volatile ATD0STAT0STR _ATD0STAT0;                          /* ATD 0 Status Register 0 */
volatile ATD0STAT1STR _ATD0STAT1;                          /* ATD 0 Status Register 1 */
volatile BDMCCRSTR _BDMCCR;                                /* BDM CCR Holding Register */
volatile BDMINRSTR _BDMINR;                                /* BDM Internal Register Position Register */
volatile BDMSTSSTR _BDMSTS;                                /* BDM Status Register */
volatile BKP0HSTR _BKP0H;                                  /* First Address High Byte Breakpoint Register */
volatile BKP0LSTR _BKP0L;                                  /* First Address Low Byte Breakpoint Register */
volatile BKP0XSTR _BKP0X;                                  /* First Address Memory Expansion Breakpoint Register */
volatile BKP1HSTR _BKP1H;                                  /* Data (Second Address) High Byte Breakpoint Register */
volatile BKP1LSTR _BKP1L;                                  /* Data (Second Address) Low Byte Breakpoint Register */
volatile BKP1XSTR _BKP1X;                                  /* Second Address Memory Expansion Breakpoint Register */
volatile BKPCT0STR _BKPCT0;                                /* Breakpoint Control Register 0 */
volatile BKPCT1STR _BKPCT1;                                /* Breakpoint Control Register 1 */
volatile CLKSELSTR _CLKSEL;                                /* CRG Clock Select Register */
volatile COPCTLSTR _COPCTL;                                /* CRG COP Control Register */
volatile CRGFLGSTR _CRGFLG;                                /* CRG Flags Register */
volatile CRGINTSTR _CRGINT;                                /* CRG Interrupt Enable Register */
volatile DDRESTR _DDRE;                                    /* Port E Data Direction Register */
volatile DDRHSTR _DDRH;                                    /* Port H Data Direction Register */
volatile DDRJSTR _DDRJ;                                    /* Port J Data Direction Register */
volatile DDRKSTR _DDRK;                                    /* Port K Data Direction Register */
volatile DDRMSTR _DDRM;                                    /* Port M Data Direction Register */
volatile DDRPSTR _DDRP;                                    /* Port P Data Direction Register */
volatile DDRSSTR _DDRS;                                    /* Port S Data Direction Register */
volatile DDRTSTR _DDRT;                                    /* Port T Data Direction Register */
volatile EBICTLSTR _EBICTL;                                /* External Bus Interface Control */
volatile ECLKDIVSTR _ECLKDIV;                              /* EEPROM Clock Divider Register */
volatile ECMDSTR _ECMD;                                    /* EEPROM Command Buffer and Register */
volatile ECNFGSTR _ECNFG;                                  /* EEPROM Configuration Register */
volatile EPROTSTR _EPROT;                                  /* EEPROM Protection Register */
volatile ESTATSTR _ESTAT;                                  /* EEPROM Status Register */
volatile FCLKDIVSTR _FCLKDIV;                              /* Flash Clock Divider Register */
volatile FCMDSTR _FCMD;                                    /* Flash Command Buffer and Register */
volatile FCNFGSTR _FCNFG;                                  /* Flash Configuration Register */
volatile FORBYPSTR _FORBYP;                                /* Crg force and bypass test register */
volatile FPROTSTR _FPROT;                                  /* Flash Protection Register */
volatile FSECSTR _FSEC;                                    /* Flash Security Register */
volatile FSTATSTR _FSTAT;                                  /* Flash Status Register */
volatile HPRIOSTR _HPRIO;                                  /* Highest Priority I Interrupt */
volatile INITEESTR _INITEE;                                /* Initialization of Internal EEPROM Position Register */
volatile INITRGSTR _INITRG;                                /* Initialization of Internal Register Position Register */
volatile INITRMSTR _INITRM;                                /* Initialization of Internal RAM Position Register */
volatile INTCRSTR _INTCR;                                  /* Interrupt Control Register */
volatile ITCRSTR _ITCR;                                    /* Interrupt Test Control Register */
volatile ITESTSTR _ITEST;                                  /* Interrupt Test Register */
volatile MEMSIZ0STR _MEMSIZ0;                              /* Memory Size Register Zero */
volatile MEMSIZ1STR _MEMSIZ1;                              /* Memory Size Register One */
volatile MISCSTR _MISC;                                    /* Miscellaneous Mapping Control Register */
volatile MODESTR _MODE;                                    /* Mode Register */
volatile MODRRSTR _MODRR;                                  /* Module Routing Register */
volatile MTST0STR _MTST0;                                  /* MTST0 */
volatile MTST1STR _MTST1;                                  /* MTST1 */
volatile PARTIDHSTR _PARTIDH;                              /* Part ID Register High */
volatile PARTIDLSTR _PARTIDL;                              /* Part ID Register Low */
volatile PEARSTR _PEAR;                                    /* Port E Assignment Register */
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
volatile PLLCTLSTR _PLLCTL;                                /* CRG PLL Control Register */
volatile PORTAD0STR _PORTAD0;                              /* Port AD0 Register */
volatile PORTESTR _PORTE;                                  /* Port E Register */
volatile PORTKSTR _PORTK;                                  /* Port K Data Register */
volatile PPAGESTR _PPAGE;                                  /* Page Index Register */
volatile PPSHSTR _PPSH;                                    /* Port H Polarity Select Register */
volatile PPSJSTR _PPSJ;                                    /* PortJP Polarity Select Register */
volatile PPSMSTR _PPSM;                                    /* Port M Polarity Select Register */
volatile PPSPSTR _PPSP;                                    /* Port P Polarity Select Register */
volatile PPSSSTR _PPSS;                                    /* Port S Polarity Select Register */
volatile PPSTSTR _PPST;                                    /* Port T Polarity Select Register */
volatile PTHSTR _PTH;                                      /* Port H I/O Register */
volatile PTIHSTR _PTIH;                                    /* Port H Input Register */
volatile PTIJSTR _PTIJ;                                    /* Port J Input Register */
volatile PTIMSTR _PTIM;                                    /* Port M Input */
volatile PTIPSTR _PTIP;                                    /* Port P Input */
volatile PTISSTR _PTIS;                                    /* Port S Input */
volatile PTITSTR _PTIT;                                    /* Port T Input */
volatile PTJSTR _PTJ;                                      /* Port J I/O Register */
volatile PTMSTR _PTM;                                      /* Port M I/O Register */
volatile PTPSTR _PTP;                                      /* Port P I/O Register */
volatile PTSSTR _PTS;                                      /* Port S I/O Register */
volatile PTTSTR _PTT;                                      /* Port T I/O Register */
volatile PUCRSTR _PUCR;                                    /* Pull-Up Control Register */
volatile RDRHSTR _RDRH;                                    /* Port H Reduced Drive Register */
volatile RDRIVSTR _RDRIV;                                  /* Reduced Drive of I/O Lines */
volatile RDRJSTR _RDRJ;                                    /* Port J Reduced Drive Register */
volatile RDRMSTR _RDRM;                                    /* Port M Reduced Drive Register */
volatile RDRPSTR _RDRP;                                    /* Port P Reduced Drive Register */
volatile RDRSSTR _RDRS;                                    /* Port S Reduced Drive Register */
volatile RDRTSTR _RDRT;                                    /* Port T Reduced Drive Register */
volatile REFDVSTR _REFDV;                                  /* CRG Reference Divider Register */
volatile RTICTLSTR _RTICTL;                                /* CRG RTI Control Register */
volatile SCI0CR1STR _SCI0CR1;                              /* SCI 0 Control Register 1 */
volatile SCI0CR2STR _SCI0CR2;                              /* SCI 0 Control Register 2 */
volatile SCI0DRHSTR _SCI0DRH;                              /* SCI 0 Data Register High */
volatile SCI0DRLSTR _SCI0DRL;                              /* SCI 0 Data Register Low */
volatile SCI0SR1STR _SCI0SR1;                              /* SCI 0 Status Register 1 */
volatile SCI0SR2STR _SCI0SR2;                              /* SCI 0 Status Register 2 */
volatile SPI0BRSTR _SPI0BR;                                /* SPI 0 Baud Rate Register */
volatile SPI0CR1STR _SPI0CR1;                              /* SPI 0 Control Register */
volatile SPI0CR2STR _SPI0CR2;                              /* SPI 0 Control Register 2 */
volatile SPI0DRSTR _SPI0DR;                                /* SPI 0 Data Register */
volatile SPI0SRSTR _SPI0SR;                                /* SPI 0 Status Register */
volatile SYNRSTR _SYNR;                                    /* CRG Synthesizer Register */
volatile WOMMSTR _WOMM;                                    /* Port M Wired-Or Mode Register */
volatile WOMSSTR _WOMS;                                    /* Port S Wired-Or Mode Register */
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
volatile DDRABSTR _DDRAB;                                  /* Port AB Data Direction Register */
volatile PORTABSTR _PORTAB;                                /* Port AB Register */
volatile SCI0BDSTR _SCI0BD;                                /* SCI 0 Baud Rate Register */
