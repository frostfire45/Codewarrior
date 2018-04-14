; Based on CPU DB MC9S12XS256_112, version 3.00.011 (RegistersPrg V2.28)

; ###################################################################
;     Filename  : mc9s12xs256.inc
;     Processor : MC9S12XS256CAL
;     FileFormat: V2.28
;     DataSheet : MC9S12XS256RMV1 Rev. 1.03 06/2008
;     Compiler  : CodeWarrior compiler
;     Date/Time : 2.7.2009, 9:25
;     Abstract  :
;         This header implements the mapping of I/O devices.
;
;     Copyright : 1997 - 2009 Freescale Semiconductor, Inc. All Rights Reserved.
;     
;     http      : www.freescale.com
;     mail      : support@freescale.com
;
;     CPU Registers Revisions:
;      - 20.02.2008, V3.00.0:
;              - Corrected register's address: ATD0DIENL 0x02CC => 0x02CD
;              - Removed bit FSTAT[RSVD].
;              -   REASON: Changes in the data sheet (from Rev. 1.00 5/2007 to Rev. 1.01 8/2007).
;      - 17.04.2008, V3.00.1:
;              - Renamed registers TCNTH/L ==> TCNTHi/Lo, TCxH/L ==> TCxHi/Lo.
;              -   REASON: Bug-fix (#6048 in Issue Manager).
;      - 21.05.2008, V3.00.2:
;              - Added register VREGHTTR. Added interrupt vector Vhti.
;              -   REASON: Changes in the data sheet (from Rev. 1.01 08/2007 to Rev. 1.02 02/2008).
;      - 23.02.2009, V3.00.3:
;              - Corrected definition of 16-bit Port AD0 registers to use properly AD0L/AD0H parts.
;              -   REASON: Bug-fix (#7029 in Issue Manager).
;
;     File-Format-Revisions:
;      - 19.07.2007, V2.18 :
;               - Improved number of blanked lines inside register structures
;      - 06.08.2007, V2.19 :
;               - CPUDB revisions generated ahead of the file-format revisions.
;      - 11.09.2007, V2.20 :
;               - Added comment about initialization of unbonded pins.
;      - 02.01.2008, V2.21 :
;               - Changes have not affected this file (because they are related to another family)
;      - 13.02.2008, V2.22 :
;               - Changes have not affected this file (because they are related to another family)
;      - 20.02.2008, V2.23 :
;               - Termination of pragma V30toV31Compatible added, #5708
;      - 03.07.2008, V2.24 :
;               - Added support for bits with name starting with number (like "1HZ")
;      - 28.11.2008, V2.25 :
;               - StandBy RAM array declaration for ANSI-C added
;      - 1.12.2008, V2.26 :
;               - Duplication of bit (or bit-group) name with register name is not marked as a problem, is register is internal only and it is not displayed in I/O map.
;      - 17.3.2009, V2.27 :
;               - Merged bit-group is not generated, if the name matches with another bit name in the register
;      - 6.4.2009, V2.28 :
;               - Fixed generation of merged bits for bit-groups with a digit at the end, if group-name is defined in CPUDB
;
;     Not all general-purpose I/O pins are available on all packages or on all mask sets of a specific
;     derivative device. To avoid extra current drain from floating input pins, the user’s reset
;     initialization routine in the application program must either enable on-chip pull-up devices
;     or change the direction of unconnected pins to outputs so the pins do not float.
; ###################################################################

;*** Memory Map and Interrupt Vectors
;******************************************
RAMStart:           equ   $00002000
RAMEnd:             equ   $00003FFF
ROM_4000Start:      equ   $00004000
ROM_4000End:        equ   $00007FFF
ROM_C000Start:      equ   $0000C000
ROM_C000End:        equ   $0000FEFF
EEPROM_00Start:     equ   $00100000
EEPROM_00End:       equ   $001003FF
EEPROM_01Start:     equ   $00100400
EEPROM_01End:       equ   $001007FF
EEPROM_02Start:     equ   $00100800
EEPROM_02End:       equ   $00100BFF
EEPROM_03Start:     equ   $00100C00
EEPROM_03End:       equ   $00100FFF
EEPROM_04Start:     equ   $00101000
EEPROM_04End:       equ   $001013FF
EEPROM_05Start:     equ   $00101400
EEPROM_05End:       equ   $001017FF
EEPROM_06Start:     equ   $00101800
EEPROM_06End:       equ   $00101BFF
EEPROM_07Start:     equ   $00101C00
EEPROM_07End:       equ   $00101FFF
RAM_FDStart:        equ   $000FD000
RAM_FDEnd:          equ   $000FDFFF
PAGE_F0Start:       equ   $007C0000
PAGE_F0End:         equ   $007C3FFF
PAGE_F1Start:       equ   $007C4000
PAGE_F1End:         equ   $007C7FFF
PAGE_F2Start:       equ   $007C8000
PAGE_F2End:         equ   $007CBFFF
PAGE_F3Start:       equ   $007CC000
PAGE_F3End:         equ   $007CFFFF
PAGE_F4Start:       equ   $007D0000
PAGE_F4End:         equ   $007D3FFF
PAGE_F5Start:       equ   $007D4000
PAGE_F5End:         equ   $007D7FFF
PAGE_F6Start:       equ   $007D8000
PAGE_F6End:         equ   $007DBFFF
PAGE_F7Start:       equ   $007DC000
PAGE_F7End:         equ   $007DFFFF
PAGE_F8Start:       equ   $007E0000
PAGE_F8End:         equ   $007E3FFF
PAGE_F9Start:       equ   $007E4000
PAGE_F9End:         equ   $007E7FFF
PAGE_FAStart:       equ   $007E8000
PAGE_FAEnd:         equ   $007EBFFF
PAGE_FBStart:       equ   $007EC000
PAGE_FBEnd:         equ   $007EFFFF
PAGE_FCStart:       equ   $007F0000
PAGE_FCEnd:         equ   $007F3FFF
PAGE_FEStart:       equ   $007F8000
PAGE_FEEnd:         equ   $007FBFFF
;
Vsi:                equ   $0000FF10
Vsyscall:           equ   $0000FF12
VReserved118:       equ   $0000FF14
VReserved117:       equ   $0000FF16
VReserved116:       equ   $0000FF18
VReserved115:       equ   $0000FF1A
VReserved114:       equ   $0000FF1C
VReserved113:       equ   $0000FF1E
VReserved112:       equ   $0000FF20
VReserved111:       equ   $0000FF22
VReserved110:       equ   $0000FF24
VReserved109:       equ   $0000FF26
VReserved108:       equ   $0000FF28
VReserved107:       equ   $0000FF2A
VReserved106:       equ   $0000FF2C
VReserved105:       equ   $0000FF2E
VReserved104:       equ   $0000FF30
VReserved103:       equ   $0000FF32
VReserved102:       equ   $0000FF34
VReserved101:       equ   $0000FF36
VReserved100:       equ   $0000FF38
VReserved99:        equ   $0000FF3A
VReserved98:        equ   $0000FF3C
Vatd0compare:       equ   $0000FF3E
VReserved96:        equ   $0000FF40
VReserved95:        equ   $0000FF42
VReserved94:        equ   $0000FF44
VReserved93:        equ   $0000FF46
VReserved92:        equ   $0000FF48
VReserved91:        equ   $0000FF4A
VReserved90:        equ   $0000FF4C
VReserved89:        equ   $0000FF4E
VReserved88:        equ   $0000FF50
VReserved87:        equ   $0000FF52
VReserved86:        equ   $0000FF54
VReserved85:        equ   $0000FF56
VReserved84:        equ   $0000FF58
VReserved83:        equ   $0000FF5A
VReserved82:        equ   $0000FF5C
VReserved81:        equ   $0000FF5E
VReserved79:        equ   $0000FF60
VReserved78:        equ   $0000FF62
VReserved77:        equ   $0000FF64
VReserved76:        equ   $0000FF66
VReserved75:        equ   $0000FF68
VReserved74:        equ   $0000FF6A
VReserved73:        equ   $0000FF6C
VReserved72:        equ   $0000FF6E
VReserved71:        equ   $0000FF70
VReserved70:        equ   $0000FF72
Vpit3:              equ   $0000FF74
Vpit2:              equ   $0000FF76
Vpit1:              equ   $0000FF78
Vpit0:              equ   $0000FF7A
Vhti:               equ   $0000FF7C
Vapi:               equ   $0000FF7E
Vlvi:               equ   $0000FF80
VReserved62:        equ   $0000FF82
VReserved61:        equ   $0000FF84
VReserved60:        equ   $0000FF86
VReserved59:        equ   $0000FF88
VReserved58:        equ   $0000FF8A
Vpwmesdn:           equ   $0000FF8C
Vportp:             equ   $0000FF8E
VReserved55:        equ   $0000FF90
VReserved54:        equ   $0000FF92
VReserved53:        equ   $0000FF94
VReserved52:        equ   $0000FF96
VReserved51:        equ   $0000FF98
VReserved50:        equ   $0000FF9A
VReserved49:        equ   $0000FF9C
VReserved48:        equ   $0000FF9E
VReserved47:        equ   $0000FFA0
VReserved46:        equ   $0000FFA2
VReserved45:        equ   $0000FFA4
VReserved44:        equ   $0000FFA6
VReserved43:        equ   $0000FFA8
VReserved42:        equ   $0000FFAA
VReserved41:        equ   $0000FFAC
VReserved40:        equ   $0000FFAE
Vcan0tx:            equ   $0000FFB0
Vcan0rx:            equ   $0000FFB2
Vcan0err:           equ   $0000FFB4
Vcan0wkup:          equ   $0000FFB6
Vflash:             equ   $0000FFB8
Vflashfd:           equ   $0000FFBA
VReserved33:        equ   $0000FFBC
VReserved32:        equ   $0000FFBE
VReserved31:        equ   $0000FFC0
VReserved30:        equ   $0000FFC2
Vcrgscm:            equ   $0000FFC4
Vcrgplllck:         equ   $0000FFC6
VReserved27:        equ   $0000FFC8
VReserved26:        equ   $0000FFCA
Vporth:             equ   $0000FFCC
Vportj:             equ   $0000FFCE
VReserved23:        equ   $0000FFD0
Vatd0:              equ   $0000FFD2
Vsci1:              equ   $0000FFD4
Vsci0:              equ   $0000FFD6
Vspi0:              equ   $0000FFD8
Vtimpaie:           equ   $0000FFDA
Vtimpaaovf:         equ   $0000FFDC
Vtimovf:            equ   $0000FFDE
Vtimch7:            equ   $0000FFE0
Vtimch6:            equ   $0000FFE2
Vtimch5:            equ   $0000FFE4
Vtimch4:            equ   $0000FFE6
Vtimch3:            equ   $0000FFE8
Vtimch2:            equ   $0000FFEA
Vtimch1:            equ   $0000FFEC
Vtimch0:            equ   $0000FFEE
Vrti:               equ   $0000FFF0
Virq:               equ   $0000FFF2
Vxirq:              equ   $0000FFF4
Vswi:               equ   $0000FFF6
Vtrap:              equ   $0000FFF8
Vcop:               equ   $0000FFFA
Vclkmon:            equ   $0000FFFC
Vreset:             equ   $0000FFFE
;


;*** PORTAB - Port AB Data Register; 0x00000000 ***
PORTAB:             equ    $00000000                                ;*** PORTAB - Port AB Data Register; 0x00000000 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PORTAB_PB0:         equ    0                                         ; Port B Bit 0
PORTAB_PB1:         equ    1                                         ; Port B Bit 1
PORTAB_PB2:         equ    2                                         ; Port B Bit 2
PORTAB_PB3:         equ    3                                         ; Port B Bit 3
PORTAB_PB4:         equ    4                                         ; Port B Bit 4
PORTAB_PB5:         equ    5                                         ; Port B Bit 5
PORTAB_PB6:         equ    6                                         ; Port B Bit 6
PORTAB_PB7:         equ    7                                         ; Port B Bit 7
PORTAB_PA0:         equ    8                                         ; Port A Bit 0
PORTAB_PA1:         equ    9                                         ; Port A Bit 1
PORTAB_PA2:         equ    10                                        ; Port A Bit 2
PORTAB_PA3:         equ    11                                        ; Port A Bit 3
PORTAB_PA4:         equ    12                                        ; Port A Bit 4
PORTAB_PA5:         equ    13                                        ; Port A Bit 5
PORTAB_PA6:         equ    14                                        ; Port A Bit 6
PORTAB_PA7:         equ    15                                        ; Port A Bit 7
; bit position masks
mPORTAB_PB0:        equ    %00000001
mPORTAB_PB1:        equ    %00000010
mPORTAB_PB2:        equ    %00000100
mPORTAB_PB3:        equ    %00001000
mPORTAB_PB4:        equ    %00010000
mPORTAB_PB5:        equ    %00100000
mPORTAB_PB6:        equ    %01000000
mPORTAB_PB7:        equ    %10000000
mPORTAB_PA0:        equ    %100000000
mPORTAB_PA1:        equ    %1000000000
mPORTAB_PA2:        equ    %10000000000
mPORTAB_PA3:        equ    %100000000000
mPORTAB_PA4:        equ    %1000000000000
mPORTAB_PA5:        equ    %10000000000000
mPORTAB_PA6:        equ    %100000000000000
mPORTAB_PA7:        equ    %1000000000000000


;*** PORTA - Port A Data Register; 0x00000000 ***
PORTA:              equ    $00000000                                ;*** PORTA - Port A Data Register; 0x00000000 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PORTA_PA0:          equ    0                                         ; Port A Bit 0
PORTA_PA1:          equ    1                                         ; Port A Bit 1
PORTA_PA2:          equ    2                                         ; Port A Bit 2
PORTA_PA3:          equ    3                                         ; Port A Bit 3
PORTA_PA4:          equ    4                                         ; Port A Bit 4
PORTA_PA5:          equ    5                                         ; Port A Bit 5
PORTA_PA6:          equ    6                                         ; Port A Bit 6
PORTA_PA7:          equ    7                                         ; Port A Bit 7
; bit position masks
mPORTA_PA0:         equ    %00000001
mPORTA_PA1:         equ    %00000010
mPORTA_PA2:         equ    %00000100
mPORTA_PA3:         equ    %00001000
mPORTA_PA4:         equ    %00010000
mPORTA_PA5:         equ    %00100000
mPORTA_PA6:         equ    %01000000
mPORTA_PA7:         equ    %10000000


;*** PORTB - Port B Data Register; 0x00000001 ***
PORTB:              equ    $00000001                                ;*** PORTB - Port B Data Register; 0x00000001 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PORTB_PB0:          equ    0                                         ; Port B Bit 0
PORTB_PB1:          equ    1                                         ; Port B Bit 1
PORTB_PB2:          equ    2                                         ; Port B Bit 2
PORTB_PB3:          equ    3                                         ; Port B Bit 3
PORTB_PB4:          equ    4                                         ; Port B Bit 4
PORTB_PB5:          equ    5                                         ; Port B Bit 5
PORTB_PB6:          equ    6                                         ; Port B Bit 6
PORTB_PB7:          equ    7                                         ; Port B Bit 7
; bit position masks
mPORTB_PB0:         equ    %00000001
mPORTB_PB1:         equ    %00000010
mPORTB_PB2:         equ    %00000100
mPORTB_PB3:         equ    %00001000
mPORTB_PB4:         equ    %00010000
mPORTB_PB5:         equ    %00100000
mPORTB_PB6:         equ    %01000000
mPORTB_PB7:         equ    %10000000


;*** DDRAB - Port AB Data Direction Register; 0x00000002 ***
DDRAB:              equ    $00000002                                ;*** DDRAB - Port AB Data Direction Register; 0x00000002 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DDRAB_DDRB0:        equ    0                                         ; Data Direction Port B Bit 0
DDRAB_DDRB1:        equ    1                                         ; Data Direction Port B Bit 1
DDRAB_DDRB2:        equ    2                                         ; Data Direction Port B Bit 2
DDRAB_DDRB3:        equ    3                                         ; Data Direction Port B Bit 3
DDRAB_DDRB4:        equ    4                                         ; Data Direction Port B Bit 4
DDRAB_DDRB5:        equ    5                                         ; Data Direction Port B Bit 5
DDRAB_DDRB6:        equ    6                                         ; Data Direction Port B Bit 6
DDRAB_DDRB7:        equ    7                                         ; Data Direction Port B Bit 7
DDRAB_DDRA0:        equ    8                                         ; Data Direction Port A Bit 0
DDRAB_DDRA1:        equ    9                                         ; Data Direction Port A Bit 1
DDRAB_DDRA2:        equ    10                                        ; Data Direction Port A Bit 2
DDRAB_DDRA3:        equ    11                                        ; Data Direction Port A Bit 3
DDRAB_DDRA4:        equ    12                                        ; Data Direction Port A Bit 4
DDRAB_DDRA5:        equ    13                                        ; Data Direction Port A Bit 5
DDRAB_DDRA6:        equ    14                                        ; Data Direction Port A Bit 6
DDRAB_DDRA7:        equ    15                                        ; Data Direction Port A Bit 7
; bit position masks
mDDRAB_DDRB0:       equ    %00000001
mDDRAB_DDRB1:       equ    %00000010
mDDRAB_DDRB2:       equ    %00000100
mDDRAB_DDRB3:       equ    %00001000
mDDRAB_DDRB4:       equ    %00010000
mDDRAB_DDRB5:       equ    %00100000
mDDRAB_DDRB6:       equ    %01000000
mDDRAB_DDRB7:       equ    %10000000
mDDRAB_DDRA0:       equ    %100000000
mDDRAB_DDRA1:       equ    %1000000000
mDDRAB_DDRA2:       equ    %10000000000
mDDRAB_DDRA3:       equ    %100000000000
mDDRAB_DDRA4:       equ    %1000000000000
mDDRAB_DDRA5:       equ    %10000000000000
mDDRAB_DDRA6:       equ    %100000000000000
mDDRAB_DDRA7:       equ    %1000000000000000


;*** DDRA - Port A Data Direction Register; 0x00000002 ***
DDRA:               equ    $00000002                                ;*** DDRA - Port A Data Direction Register; 0x00000002 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DDRA_DDRA0:         equ    0                                         ; Data Direction Port A Bit 0
DDRA_DDRA1:         equ    1                                         ; Data Direction Port A Bit 1
DDRA_DDRA2:         equ    2                                         ; Data Direction Port A Bit 2
DDRA_DDRA3:         equ    3                                         ; Data Direction Port A Bit 3
DDRA_DDRA4:         equ    4                                         ; Data Direction Port A Bit 4
DDRA_DDRA5:         equ    5                                         ; Data Direction Port A Bit 5
DDRA_DDRA6:         equ    6                                         ; Data Direction Port A Bit 6
DDRA_DDRA7:         equ    7                                         ; Data Direction Port A Bit 7
; bit position masks
mDDRA_DDRA0:        equ    %00000001
mDDRA_DDRA1:        equ    %00000010
mDDRA_DDRA2:        equ    %00000100
mDDRA_DDRA3:        equ    %00001000
mDDRA_DDRA4:        equ    %00010000
mDDRA_DDRA5:        equ    %00100000
mDDRA_DDRA6:        equ    %01000000
mDDRA_DDRA7:        equ    %10000000


;*** DDRB - Port B Data Direction Register; 0x00000003 ***
DDRB:               equ    $00000003                                ;*** DDRB - Port B Data Direction Register; 0x00000003 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DDRB_DDRB0:         equ    0                                         ; Data Direction Port B Bit 0
DDRB_DDRB1:         equ    1                                         ; Data Direction Port B Bit 1
DDRB_DDRB2:         equ    2                                         ; Data Direction Port B Bit 2
DDRB_DDRB3:         equ    3                                         ; Data Direction Port B Bit 3
DDRB_DDRB4:         equ    4                                         ; Data Direction Port B Bit 4
DDRB_DDRB5:         equ    5                                         ; Data Direction Port B Bit 5
DDRB_DDRB6:         equ    6                                         ; Data Direction Port B Bit 6
DDRB_DDRB7:         equ    7                                         ; Data Direction Port B Bit 7
; bit position masks
mDDRB_DDRB0:        equ    %00000001
mDDRB_DDRB1:        equ    %00000010
mDDRB_DDRB2:        equ    %00000100
mDDRB_DDRB3:        equ    %00001000
mDDRB_DDRB4:        equ    %00010000
mDDRB_DDRB5:        equ    %00100000
mDDRB_DDRB6:        equ    %01000000
mDDRB_DDRB7:        equ    %10000000


;*** PORTE - Port E Data Register; 0x00000008 ***
PORTE:              equ    $00000008                                ;*** PORTE - Port E Data Register; 0x00000008 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PORTE_PE0:          equ    0                                         ; Port E Bit 0
PORTE_PE1:          equ    1                                         ; Port E Bit 1
PORTE_PE2:          equ    2                                         ; Port E Bit 2
PORTE_PE3:          equ    3                                         ; Port E Bit 3
PORTE_PE4:          equ    4                                         ; Port E Bit 4
PORTE_PE5:          equ    5                                         ; Port E Bit 5
PORTE_PE6:          equ    6                                         ; Port E Bit 6
PORTE_PE7:          equ    7                                         ; Port E Bit 7
; bit position masks
mPORTE_PE0:         equ    %00000001
mPORTE_PE1:         equ    %00000010
mPORTE_PE2:         equ    %00000100
mPORTE_PE3:         equ    %00001000
mPORTE_PE4:         equ    %00010000
mPORTE_PE5:         equ    %00100000
mPORTE_PE6:         equ    %01000000
mPORTE_PE7:         equ    %10000000


;*** DDRE - Port E Data Direction Register; 0x00000009 ***
DDRE:               equ    $00000009                                ;*** DDRE - Port E Data Direction Register; 0x00000009 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DDRE_DDRE2:         equ    2                                         ; Data Direction Port E Bit 2
DDRE_DDRE3:         equ    3                                         ; Data Direction Port E Bit 3
DDRE_DDRE4:         equ    4                                         ; Data Direction Port E Bit 4
DDRE_DDRE5:         equ    5                                         ; Data Direction Port E Bit 5
DDRE_DDRE6:         equ    6                                         ; Data Direction Port E Bit 6
DDRE_DDRE7:         equ    7                                         ; Data Direction Port E Bit 7
; bit position masks
mDDRE_DDRE2:        equ    %00000100
mDDRE_DDRE3:        equ    %00001000
mDDRE_DDRE4:        equ    %00010000
mDDRE_DDRE5:        equ    %00100000
mDDRE_DDRE6:        equ    %01000000
mDDRE_DDRE7:        equ    %10000000


;*** MODE - Mode Register; 0x0000000B ***
MODE:               equ    $0000000B                                ;*** MODE - Mode Register; 0x0000000B ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
MODE_MODC:          equ    7                                         ; Mode Select Bit
; bit position masks
mMODE_MODC:         equ    %10000000


;*** PUCR - Pull-Up Control Register; 0x0000000C ***
PUCR:               equ    $0000000C                                ;*** PUCR - Pull-Up Control Register; 0x0000000C ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PUCR_PUPAE:         equ    0                                         ; Pull-up Port A Enable
PUCR_PUPBE:         equ    1                                         ; Pull-up Port B Enable
PUCR_PUPEE:         equ    4                                         ; Pull-up Port E Enable
PUCR_BKPUE:         equ    6                                         ; BKGD and VREGEN Pin Pull-up Enable
PUCR_PUPKE:         equ    7                                         ; Pull-up Port K Enable
; bit position masks
mPUCR_PUPAE:        equ    %00000001
mPUCR_PUPBE:        equ    %00000010
mPUCR_PUPEE:        equ    %00010000
mPUCR_BKPUE:        equ    %01000000
mPUCR_PUPKE:        equ    %10000000


;*** RDRIV - Reduced Drive Register; 0x0000000D ***
RDRIV:              equ    $0000000D                                ;*** RDRIV - Reduced Drive Register; 0x0000000D ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
RDRIV_RDPA:         equ    0                                         ; Reduced Drive of Port A
RDRIV_RDPB:         equ    1                                         ; Reduced Drive of Port B
RDRIV_RDPE:         equ    4                                         ; Reduced Drive of Port E
RDRIV_RDPK:         equ    7                                         ; Reduced Drive of Port K
; bit position masks
mRDRIV_RDPA:        equ    %00000001
mRDRIV_RDPB:        equ    %00000010
mRDRIV_RDPE:        equ    %00010000
mRDRIV_RDPK:        equ    %10000000


;*** GPAGE - Global Page Index Register; 0x00000010 ***
GPAGE:              equ    $00000010                                ;*** GPAGE - Global Page Index Register; 0x00000010 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
GPAGE_GP0:          equ    0                                         ; Global Page Index Bit 0
GPAGE_GP1:          equ    1                                         ; Global Page Index Bit 1
GPAGE_GP2:          equ    2                                         ; Global Page Index Bit 2
GPAGE_GP3:          equ    3                                         ; Global Page Index Bit 3
GPAGE_GP4:          equ    4                                         ; Global Page Index Bit 4
GPAGE_GP5:          equ    5                                         ; Global Page Index Bit 5
GPAGE_GP6:          equ    6                                         ; Global Page Index Bit 6
; bit position masks
mGPAGE_GP0:         equ    %00000001
mGPAGE_GP1:         equ    %00000010
mGPAGE_GP2:         equ    %00000100
mGPAGE_GP3:         equ    %00001000
mGPAGE_GP4:         equ    %00010000
mGPAGE_GP5:         equ    %00100000
mGPAGE_GP6:         equ    %01000000


;*** DIRECT - Direct Page Register; 0x00000011 ***
DIRECT:             equ    $00000011                                ;*** DIRECT - Direct Page Register; 0x00000011 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DIRECT_DP8:         equ    0                                         ; Direct Page Index Bit 8
DIRECT_DP9:         equ    1                                         ; Direct Page Index Bit 9
DIRECT_DP10:        equ    2                                         ; Direct Page Index Bit 10
DIRECT_DP11:        equ    3                                         ; Direct Page Index Bit 11
DIRECT_DP12:        equ    4                                         ; Direct Page Index Bit 12
DIRECT_DP13:        equ    5                                         ; Direct Page Index Bit 13
DIRECT_DP14:        equ    6                                         ; Direct Page Index Bit 14
DIRECT_DP15:        equ    7                                         ; Direct Page Index Bit 15
; bit position masks
mDIRECT_DP8:        equ    %00000001
mDIRECT_DP9:        equ    %00000010
mDIRECT_DP10:       equ    %00000100
mDIRECT_DP11:       equ    %00001000
mDIRECT_DP12:       equ    %00010000
mDIRECT_DP13:       equ    %00100000
mDIRECT_DP14:       equ    %01000000
mDIRECT_DP15:       equ    %10000000


;*** MMCCTL1 - MMC Control Register; 0x00000013 ***
MMCCTL1:            equ    $00000013                                ;*** MMCCTL1 - MMC Control Register; 0x00000013 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
MMCCTL1_PGMIFRON:   equ    4                                         ; Program Flash Information Row (IFR) visible in the global memory map
MMCCTL1_DFIFRON:    equ    5                                         ; Data Flash Information Row (IFR) visible in the global memory map
MMCCTL1_MGRAMON:    equ    7                                         ; Flash Memory Controller SCRATCH RAM visible in the global memory map
; bit position masks
mMMCCTL1_PGMIFRON:  equ    %00010000
mMMCCTL1_DFIFRON:   equ    %00100000
mMMCCTL1_MGRAMON:   equ    %10000000


;*** PPAGE - Program Page Index Register; 0x00000015 ***
PPAGE:              equ    $00000015                                ;*** PPAGE - Program Page Index Register; 0x00000015 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PPAGE_PIX0:         equ    0                                         ; Program Page Index Bit 0
PPAGE_PIX1:         equ    1                                         ; Program Page Index Bit 1
PPAGE_PIX2:         equ    2                                         ; Program Page Index Bit 2
PPAGE_PIX3:         equ    3                                         ; Program Page Index Bit 3
PPAGE_PIX4:         equ    4                                         ; Program Page Index Bit 4
PPAGE_PIX5:         equ    5                                         ; Program Page Index Bit 5
PPAGE_PIX6:         equ    6                                         ; Program Page Index Bit 6
PPAGE_PIX7:         equ    7                                         ; Program Page Index Bit 7
; bit position masks
mPPAGE_PIX0:        equ    %00000001
mPPAGE_PIX1:        equ    %00000010
mPPAGE_PIX2:        equ    %00000100
mPPAGE_PIX3:        equ    %00001000
mPPAGE_PIX4:        equ    %00010000
mPPAGE_PIX5:        equ    %00100000
mPPAGE_PIX6:        equ    %01000000
mPPAGE_PIX7:        equ    %10000000


;*** RPAGE - RAM Page Index Register; 0x00000016 ***
RPAGE:              equ    $00000016                                ;*** RPAGE - RAM Page Index Register; 0x00000016 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
RPAGE_RP0:          equ    0                                         ; RAM Page Index Bit 0
RPAGE_RP1:          equ    1                                         ; RAM Page Index Bit 1
RPAGE_RP2:          equ    2                                         ; RAM Page Index Bit 2
RPAGE_RP3:          equ    3                                         ; RAM Page Index Bit 3
RPAGE_RP4:          equ    4                                         ; RAM Page Index Bit 4
RPAGE_RP5:          equ    5                                         ; RAM Page Index Bit 5
RPAGE_RP6:          equ    6                                         ; RAM Page Index Bit 6
RPAGE_RP7:          equ    7                                         ; RAM Page Index Bit 7
; bit position masks
mRPAGE_RP0:         equ    %00000001
mRPAGE_RP1:         equ    %00000010
mRPAGE_RP2:         equ    %00000100
mRPAGE_RP3:         equ    %00001000
mRPAGE_RP4:         equ    %00010000
mRPAGE_RP5:         equ    %00100000
mRPAGE_RP6:         equ    %01000000
mRPAGE_RP7:         equ    %10000000


;*** EPAGE - Data FLASH Page Index Register; 0x00000017 ***
EPAGE:              equ    $00000017                                ;*** EPAGE - Data FLASH Page Index Register; 0x00000017 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
EPAGE_EP0:          equ    0                                         ; Data FLASH Page Index Bit 0
EPAGE_EP1:          equ    1                                         ; Data FLASH Page Index Bit 1
EPAGE_EP2:          equ    2                                         ; Data FLASH Page Index Bit 2
EPAGE_EP3:          equ    3                                         ; Data FLASH Page Index Bit 3
EPAGE_EP4:          equ    4                                         ; Data FLASH Page Index Bit 4
EPAGE_EP5:          equ    5                                         ; Data FLASH Page Index Bit 5
EPAGE_EP6:          equ    6                                         ; Data FLASH Page Index Bit 6
EPAGE_EP7:          equ    7                                         ; Data FLASH Page Index Bit 7
; bit position masks
mEPAGE_EP0:         equ    %00000001
mEPAGE_EP1:         equ    %00000010
mEPAGE_EP2:         equ    %00000100
mEPAGE_EP3:         equ    %00001000
mEPAGE_EP4:         equ    %00010000
mEPAGE_EP5:         equ    %00100000
mEPAGE_EP6:         equ    %01000000
mEPAGE_EP7:         equ    %10000000


;*** PARTID - Part ID Register; 0x0000001A ***
PARTID:             equ    $0000001A                                ;*** PARTID - Part ID Register; 0x0000001A ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PARTID_ID0:         equ    0                                         ; Part ID Register Bit 0
PARTID_ID1:         equ    1                                         ; Part ID Register Bit 1
PARTID_ID2:         equ    2                                         ; Part ID Register Bit 2
PARTID_ID3:         equ    3                                         ; Part ID Register Bit 3
PARTID_ID4:         equ    4                                         ; Part ID Register Bit 4
PARTID_ID5:         equ    5                                         ; Part ID Register Bit 5
PARTID_ID6:         equ    6                                         ; Part ID Register Bit 6
PARTID_ID7:         equ    7                                         ; Part ID Register Bit 7
PARTID_ID8:         equ    8                                         ; Part ID Register Bit 8
PARTID_ID9:         equ    9                                         ; Part ID Register Bit 9
PARTID_ID10:        equ    10                                        ; Part ID Register Bit 10
PARTID_ID11:        equ    11                                        ; Part ID Register Bit 11
PARTID_ID12:        equ    12                                        ; Part ID Register Bit 12
PARTID_ID13:        equ    13                                        ; Part ID Register Bit 13
PARTID_ID14:        equ    14                                        ; Part ID Register Bit 14
PARTID_ID15:        equ    15                                        ; Part ID Register Bit 15
; bit position masks
mPARTID_ID0:        equ    %00000001
mPARTID_ID1:        equ    %00000010
mPARTID_ID2:        equ    %00000100
mPARTID_ID3:        equ    %00001000
mPARTID_ID4:        equ    %00010000
mPARTID_ID5:        equ    %00100000
mPARTID_ID6:        equ    %01000000
mPARTID_ID7:        equ    %10000000
mPARTID_ID8:        equ    %100000000
mPARTID_ID9:        equ    %1000000000
mPARTID_ID10:       equ    %10000000000
mPARTID_ID11:       equ    %100000000000
mPARTID_ID12:       equ    %1000000000000
mPARTID_ID13:       equ    %10000000000000
mPARTID_ID14:       equ    %100000000000000
mPARTID_ID15:       equ    %1000000000000000


;*** PARTIDH - Part ID Register High; 0x0000001A ***
PARTIDH:            equ    $0000001A                                ;*** PARTIDH - Part ID Register High; 0x0000001A ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PARTIDH_ID8:        equ    0                                         ; Part ID Register Bit 8
PARTIDH_ID9:        equ    1                                         ; Part ID Register Bit 9
PARTIDH_ID10:       equ    2                                         ; Part ID Register Bit 10
PARTIDH_ID11:       equ    3                                         ; Part ID Register Bit 11
PARTIDH_ID12:       equ    4                                         ; Part ID Register Bit 12
PARTIDH_ID13:       equ    5                                         ; Part ID Register Bit 13
PARTIDH_ID14:       equ    6                                         ; Part ID Register Bit 14
PARTIDH_ID15:       equ    7                                         ; Part ID Register Bit 15
; bit position masks
mPARTIDH_ID8:       equ    %00000001
mPARTIDH_ID9:       equ    %00000010
mPARTIDH_ID10:      equ    %00000100
mPARTIDH_ID11:      equ    %00001000
mPARTIDH_ID12:      equ    %00010000
mPARTIDH_ID13:      equ    %00100000
mPARTIDH_ID14:      equ    %01000000
mPARTIDH_ID15:      equ    %10000000


;*** PARTIDL - Part ID Register Low; 0x0000001B ***
PARTIDL:            equ    $0000001B                                ;*** PARTIDL - Part ID Register Low; 0x0000001B ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PARTIDL_ID0:        equ    0                                         ; Part ID Register Bit 0
PARTIDL_ID1:        equ    1                                         ; Part ID Register Bit 1
PARTIDL_ID2:        equ    2                                         ; Part ID Register Bit 2
PARTIDL_ID3:        equ    3                                         ; Part ID Register Bit 3
PARTIDL_ID4:        equ    4                                         ; Part ID Register Bit 4
PARTIDL_ID5:        equ    5                                         ; Part ID Register Bit 5
PARTIDL_ID6:        equ    6                                         ; Part ID Register Bit 6
PARTIDL_ID7:        equ    7                                         ; Part ID Register Bit 7
; bit position masks
mPARTIDL_ID0:       equ    %00000001
mPARTIDL_ID1:       equ    %00000010
mPARTIDL_ID2:       equ    %00000100
mPARTIDL_ID3:       equ    %00001000
mPARTIDL_ID4:       equ    %00010000
mPARTIDL_ID5:       equ    %00100000
mPARTIDL_ID6:       equ    %01000000
mPARTIDL_ID7:       equ    %10000000


;*** ECLKCTL - ECLK Control Register; 0x0000001C ***
ECLKCTL:            equ    $0000001C                                ;*** ECLKCTL - ECLK Control Register; 0x0000001C ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ECLKCTL_EDIV0:      equ    0                                         ; Free-running ECLK Divider, bit 0
ECLKCTL_EDIV1:      equ    1                                         ; Free-running ECLK Divider, bit 1
ECLKCTL_EDIV2:      equ    2                                         ; Free-running ECLK Divider, bit 2
ECLKCTL_EDIV3:      equ    3                                         ; Free-running ECLK Divider, bit 3
ECLKCTL_EDIV4:      equ    4                                         ; Free-running ECLK Divider, bit 4
ECLKCTL_DIV16:      equ    5                                         ; Free-running ECLK predivider
ECLKCTL_NCLKX2:     equ    6                                         ; No ECLKX2
ECLKCTL_NECLK:      equ    7                                         ; No ECLK
; bit position masks
mECLKCTL_EDIV0:     equ    %00000001
mECLKCTL_EDIV1:     equ    %00000010
mECLKCTL_EDIV2:     equ    %00000100
mECLKCTL_EDIV3:     equ    %00001000
mECLKCTL_EDIV4:     equ    %00010000
mECLKCTL_DIV16:     equ    %00100000
mECLKCTL_NCLKX2:    equ    %01000000
mECLKCTL_NECLK:     equ    %10000000


;*** IRQCR - Interrupt Control Register; 0x0000001E ***
IRQCR:              equ    $0000001E                                ;*** IRQCR - Interrupt Control Register; 0x0000001E ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IRQCR_IRQEN:        equ    6                                         ; External IRQ Enable
IRQCR_IRQE:         equ    7                                         ; IRQ Select Edge Sensitive Only
; bit position masks
mIRQCR_IRQEN:       equ    %01000000
mIRQCR_IRQE:        equ    %10000000


;*** DBGC1 - Debug Control Register 1; 0x00000020 ***
DBGC1:              equ    $00000020                                ;*** DBGC1 - Debug Control Register 1; 0x00000020 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DBGC1_COMRV:        equ    0                                         ; Comparator Register Visibility Bits
DBGC1_DBGBRK:       equ    3                                         ; S12XDBG Breakpoint Enable Bit 1
DBGC1_BDM:          equ    4                                         ; Background Debug Mode Enable
DBGC1_TRIG:         equ    6                                         ; Immediate Trigger Request Bit
DBGC1_ARM:          equ    7                                         ; Arm Bit
; bit position masks
mDBGC1_COMRV:       equ    %00000011
mDBGC1_DBGBRK:      equ    %00001000
mDBGC1_BDM:         equ    %00010000
mDBGC1_TRIG:        equ    %01000000
mDBGC1_ARM:         equ    %10000000


;*** DBGSR - Debug Status Register; 0x00000021 ***
DBGSR:              equ    $00000021                                ;*** DBGSR - Debug Status Register; 0x00000021 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DBGSR_SSF0:         equ    0                                         ; State Sequencer Flag Bits
DBGSR_SSF1:         equ    1                                         ; State Sequencer Flag Bit 1
DBGSR_SSF2:         equ    2                                         ; State Sequencer Flag Bit 2
DBGSR_TBF:          equ    7                                         ; Trace Buffer Full
; bit position masks
mDBGSR_SSF0:        equ    %00000001
mDBGSR_SSF1:        equ    %00000010
mDBGSR_SSF2:        equ    %00000100
mDBGSR_TBF:         equ    %10000000


;*** DBGTCR - Debug Trace Control Register; 0x00000022 ***
DBGTCR:             equ    $00000022                                ;*** DBGTCR - Debug Trace Control Register; 0x00000022 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DBGTCR_TALIGN:      equ    0                                         ; Trigger Align Bits
DBGTCR_TRCMOD:      equ    2                                         ; Trace Mode Bits
DBGTCR_TRANGE:      equ    4                                         ; Trace Range Bits
DBGTCR_TSOURCE:     equ    6                                         ; Trace Source Control Bits
; bit position masks
mDBGTCR_TALIGN:     equ    %00000011
mDBGTCR_TRCMOD:     equ    %00001100
mDBGTCR_TRANGE:     equ    %00110000
mDBGTCR_TSOURCE:    equ    %01000000


;*** DBGC2 - Debug Control Register 2; 0x00000023 ***
DBGC2:              equ    $00000023                                ;*** DBGC2 - Debug Control Register 2; 0x00000023 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DBGC2_ABCM:         equ    0                                         ; A and B Comparator Match Control
DBGC2_CDCM:         equ    2                                         ; C and D Comparator Match Control
; bit position masks
mDBGC2_ABCM:        equ    %00000011
mDBGC2_CDCM:        equ    %00001100


;*** DBGTB - Debug Trace Buffer Register; 0x00000024 ***
DBGTB:              equ    $00000024                                ;*** DBGTB - Debug Trace Buffer Register; 0x00000024 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DBGTB_BIT0:         equ    0                                         ; Trace Buffer Data Bits
DBGTB_BIT1:         equ    1                                         ; Trace Buffer Data Bit 1
DBGTB_BIT2:         equ    2                                         ; Trace Buffer Data Bit 2
DBGTB_BIT3:         equ    3                                         ; Trace Buffer Data Bit 3
DBGTB_BIT4:         equ    4                                         ; Trace Buffer Data Bit 4
DBGTB_BIT5:         equ    5                                         ; Trace Buffer Data Bit 5
DBGTB_BIT6:         equ    6                                         ; Trace Buffer Data Bit 6
DBGTB_BIT7:         equ    7                                         ; Trace Buffer Data Bit 7
DBGTB_BIT8:         equ    8                                         ; Trace Buffer Data Bit 8
DBGTB_BIT9:         equ    9                                         ; Trace Buffer Data Bit 9
DBGTB_BIT10:        equ    10                                        ; Trace Buffer Data Bit 10
DBGTB_BIT11:        equ    11                                        ; Trace Buffer Data Bit 11
DBGTB_BIT12:        equ    12                                        ; Trace Buffer Data Bit 12
DBGTB_BIT13:        equ    13                                        ; Trace Buffer Data Bit 13
DBGTB_BIT14:        equ    14                                        ; Trace Buffer Data Bit 14
DBGTB_BIT15:        equ    15                                        ; Trace Buffer Data Bit 15
; bit position masks
mDBGTB_BIT0:        equ    %00000001
mDBGTB_BIT1:        equ    %00000010
mDBGTB_BIT2:        equ    %00000100
mDBGTB_BIT3:        equ    %00001000
mDBGTB_BIT4:        equ    %00010000
mDBGTB_BIT5:        equ    %00100000
mDBGTB_BIT6:        equ    %01000000
mDBGTB_BIT7:        equ    %10000000
mDBGTB_BIT8:        equ    %100000000
mDBGTB_BIT9:        equ    %1000000000
mDBGTB_BIT10:       equ    %10000000000
mDBGTB_BIT11:       equ    %100000000000
mDBGTB_BIT12:       equ    %1000000000000
mDBGTB_BIT13:       equ    %10000000000000
mDBGTB_BIT14:       equ    %100000000000000
mDBGTB_BIT15:       equ    %1000000000000000


;*** DBGTBH - Debug Trace Buffer Register High; 0x00000024 ***
DBGTBH:             equ    $00000024                                ;*** DBGTBH - Debug Trace Buffer Register High; 0x00000024 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DBGTBH_BIT8:        equ    0                                         ; Trace Buffer Data Bits
DBGTBH_BIT9:        equ    1                                         ; Trace Buffer Data Bit 9
DBGTBH_BIT10:       equ    2                                         ; Trace Buffer Data Bit 10
DBGTBH_BIT11:       equ    3                                         ; Trace Buffer Data Bit 11
DBGTBH_BIT12:       equ    4                                         ; Trace Buffer Data Bit 12
DBGTBH_BIT13:       equ    5                                         ; Trace Buffer Data Bit 13
DBGTBH_BIT14:       equ    6                                         ; Trace Buffer Data Bit 14
DBGTBH_BIT15:       equ    7                                         ; Trace Buffer Data Bit 15
; bit position masks
mDBGTBH_BIT8:       equ    %00000001
mDBGTBH_BIT9:       equ    %00000010
mDBGTBH_BIT10:      equ    %00000100
mDBGTBH_BIT11:      equ    %00001000
mDBGTBH_BIT12:      equ    %00010000
mDBGTBH_BIT13:      equ    %00100000
mDBGTBH_BIT14:      equ    %01000000
mDBGTBH_BIT15:      equ    %10000000


;*** DBGTBL - Debug Trace Buffer Register Low; 0x00000025 ***
DBGTBL:             equ    $00000025                                ;*** DBGTBL - Debug Trace Buffer Register Low; 0x00000025 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DBGTBL_BIT0:        equ    0                                         ; Trace Buffer Data Bits
DBGTBL_BIT1:        equ    1                                         ; Trace Buffer Data Bit 1
DBGTBL_BIT2:        equ    2                                         ; Trace Buffer Data Bit 2
DBGTBL_BIT3:        equ    3                                         ; Trace Buffer Data Bit 3
DBGTBL_BIT4:        equ    4                                         ; Trace Buffer Data Bit 4
DBGTBL_BIT5:        equ    5                                         ; Trace Buffer Data Bit 5
DBGTBL_BIT6:        equ    6                                         ; Trace Buffer Data Bit 6
DBGTBL_BIT7:        equ    7                                         ; Trace Buffer Data Bit 7
; bit position masks
mDBGTBL_BIT0:       equ    %00000001
mDBGTBL_BIT1:       equ    %00000010
mDBGTBL_BIT2:       equ    %00000100
mDBGTBL_BIT3:       equ    %00001000
mDBGTBL_BIT4:       equ    %00010000
mDBGTBL_BIT5:       equ    %00100000
mDBGTBL_BIT6:       equ    %01000000
mDBGTBL_BIT7:       equ    %10000000


;*** DBGCNT - Debug Count Register; 0x00000026 ***
DBGCNT:             equ    $00000026                                ;*** DBGCNT - Debug Count Register; 0x00000026 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DBGCNT_CNT:         equ    0                                         ; Count Value
; bit position masks
mDBGCNT_CNT:        equ    %01111111


;*** DBGSCRX - Debug State Control Register; 0x00000027 ***
DBGSCRX:            equ    $00000027                                ;*** DBGSCRX - Debug State Control Register; 0x00000027 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DBGSCRX_SC0:        equ    0                                         ; State X Sequencer Next State Selection Bit 0
DBGSCRX_SC1:        equ    1                                         ; State X Sequencer Next State Selection Bit 1
DBGSCRX_SC2:        equ    2                                         ; State X Sequencer Next State Selection Bit 2
DBGSCRX_SC3:        equ    3                                         ; State X Sequencer Next State Selection Bit 3
; bit position masks
mDBGSCRX_SC0:       equ    %00000001
mDBGSCRX_SC1:       equ    %00000010
mDBGSCRX_SC2:       equ    %00000100
mDBGSCRX_SC3:       equ    %00001000


;*** DBGMFR - Debug Match Flag Register; 0x00000027 ***
DBGMFR:             equ    $00000027                                ;*** DBGMFR - Debug Match Flag Register; 0x00000027 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DBGMFR_MC0:         equ    0                                         ; Debug Match Flag Bit 0
DBGMFR_MC1:         equ    1                                         ; Debug Match Flag Bit 1
DBGMFR_MC2:         equ    2                                         ; Debug Match Flag Bit 2
DBGMFR_MC3:         equ    3                                         ; Debug Match Flag Bit 3
; bit position masks
mDBGMFR_MC0:        equ    %00000001
mDBGMFR_MC1:        equ    %00000010
mDBGMFR_MC2:        equ    %00000100
mDBGMFR_MC3:        equ    %00001000


;*** DBGXCTL - Debug Comparator Control Register; 0x00000028 ***
DBGXCTL:            equ    $00000028                                ;*** DBGXCTL - Debug Comparator Control Register; 0x00000028 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DBGXCTL_COMPE:      equ    0                                         ; Determines if comparator is enabled
DBGXCTL_RWE:        equ    2                                         ; Read/Write Enable Bit
DBGXCTL_RW:         equ    3                                         ; Read/Write Comparator Value Bit
DBGXCTL_BRK:        equ    4                                         ; Break
DBGXCTL_TAG:        equ    5                                         ; Tag Select
DBGXCTL_NDB_SZ:     equ    6                                         ; Not Data Bus(Comparators A and C), Size Comparator Value Bit(Comparators B and D)
DBGXCTL_SZE:        equ    7                                         ; Size Comparator Enable Bit
; bit position masks
mDBGXCTL_COMPE:     equ    %00000001
mDBGXCTL_RWE:       equ    %00000100
mDBGXCTL_RW:        equ    %00001000
mDBGXCTL_BRK:       equ    %00010000
mDBGXCTL_TAG:       equ    %00100000
mDBGXCTL_NDB_SZ:    equ    %01000000
mDBGXCTL_SZE:       equ    %10000000


;*** DBGXAH - Debug Comparator Address High Register; 0x00000029 ***
DBGXAH:             equ    $00000029                                ;*** DBGXAH - Debug Comparator Address High Register; 0x00000029 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DBGXAH_BIT16:       equ    0                                         ; Comparator Address High Compare Bits
DBGXAH_BIT17:       equ    1                                         ; Comparator Address High Compare Bit 17
DBGXAH_BIT18:       equ    2                                         ; Comparator Address High Compare Bit 18
DBGXAH_BIT19:       equ    3                                         ; Comparator Address High Compare Bit 19
DBGXAH_BIT20:       equ    4                                         ; Comparator Address High Compare Bit 20
DBGXAH_BIT21:       equ    5                                         ; Comparator Address High Compare Bit 21
DBGXAH_BIT22:       equ    6                                         ; Comparator Address High Compare Bit 22
; bit position masks
mDBGXAH_BIT16:      equ    %00000001
mDBGXAH_BIT17:      equ    %00000010
mDBGXAH_BIT18:      equ    %00000100
mDBGXAH_BIT19:      equ    %00001000
mDBGXAH_BIT20:      equ    %00010000
mDBGXAH_BIT21:      equ    %00100000
mDBGXAH_BIT22:      equ    %01000000


;*** DBGXAM - Debug Comparator Address Mid Register; 0x0000002A ***
DBGXAM:             equ    $0000002A                                ;*** DBGXAM - Debug Comparator Address Mid Register; 0x0000002A ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DBGXAM_BIT8:        equ    0                                         ; Comparator Address Mid Compare Bits
DBGXAM_BIT9:        equ    1                                         ; Comparator Address Mid Compare Bit 9
DBGXAM_BIT10:       equ    2                                         ; Comparator Address Mid Compare Bit 10
DBGXAM_BIT11:       equ    3                                         ; Comparator Address Mid Compare Bit 11
DBGXAM_BIT12:       equ    4                                         ; Comparator Address Mid Compare Bit 12
DBGXAM_BIT13:       equ    5                                         ; Comparator Address Mid Compare Bit 13
DBGXAM_BIT14:       equ    6                                         ; Comparator Address Mid Compare Bit 14
DBGXAM_BIT15:       equ    7                                         ; Comparator Address Mid Compare Bit 15
; bit position masks
mDBGXAM_BIT8:       equ    %00000001
mDBGXAM_BIT9:       equ    %00000010
mDBGXAM_BIT10:      equ    %00000100
mDBGXAM_BIT11:      equ    %00001000
mDBGXAM_BIT12:      equ    %00010000
mDBGXAM_BIT13:      equ    %00100000
mDBGXAM_BIT14:      equ    %01000000
mDBGXAM_BIT15:      equ    %10000000


;*** DBGXAL - Debug Comparator Address Low Register; 0x0000002B ***
DBGXAL:             equ    $0000002B                                ;*** DBGXAL - Debug Comparator Address Low Register; 0x0000002B ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DBGXAL_BIT0:        equ    0                                         ; Comparator Address Low Compare Bits
DBGXAL_BIT1:        equ    1                                         ; Comparator Address Low Compare Bit 1
DBGXAL_BIT2:        equ    2                                         ; Comparator Address Low Compare Bit 2
DBGXAL_BIT3:        equ    3                                         ; Comparator Address Low Compare Bit 3
DBGXAL_BIT4:        equ    4                                         ; Comparator Address Low Compare Bit 4
DBGXAL_BIT5:        equ    5                                         ; Comparator Address Low Compare Bit 5
DBGXAL_BIT6:        equ    6                                         ; Comparator Address Low Compare Bit 6
DBGXAL_BIT7:        equ    7                                         ; Comparator Address Low Compare Bit 7
; bit position masks
mDBGXAL_BIT0:       equ    %00000001
mDBGXAL_BIT1:       equ    %00000010
mDBGXAL_BIT2:       equ    %00000100
mDBGXAL_BIT3:       equ    %00001000
mDBGXAL_BIT4:       equ    %00010000
mDBGXAL_BIT5:       equ    %00100000
mDBGXAL_BIT6:       equ    %01000000
mDBGXAL_BIT7:       equ    %10000000


;*** DBGXDH - Debug Comparator Data High Register; 0x0000002C ***
DBGXDH:             equ    $0000002C                                ;*** DBGXDH - Debug Comparator Data High Register; 0x0000002C ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DBGXDH_BIT8:        equ    0                                         ; Comparator Data High Compare Bit 8
DBGXDH_BIT9:        equ    1                                         ; Comparator Data High Compare Bit 9
DBGXDH_BIT10:       equ    2                                         ; Comparator Data High Compare Bit 10
DBGXDH_BIT11:       equ    3                                         ; Comparator Data High Compare Bit 11
DBGXDH_BIT12:       equ    4                                         ; Comparator Data High Compare Bit 12
DBGXDH_BIT13:       equ    5                                         ; Comparator Data High Compare Bit 13
DBGXDH_BIT14:       equ    6                                         ; Comparator Data High Compare Bit 14
DBGXDH_BIT15:       equ    7                                         ; Comparator Data High Compare Bit 15
; bit position masks
mDBGXDH_BIT8:       equ    %00000001
mDBGXDH_BIT9:       equ    %00000010
mDBGXDH_BIT10:      equ    %00000100
mDBGXDH_BIT11:      equ    %00001000
mDBGXDH_BIT12:      equ    %00010000
mDBGXDH_BIT13:      equ    %00100000
mDBGXDH_BIT14:      equ    %01000000
mDBGXDH_BIT15:      equ    %10000000


;*** DBGXDL - Debug Comparator Data Low Register; 0x0000002D ***
DBGXDL:             equ    $0000002D                                ;*** DBGXDL - Debug Comparator Data Low Register; 0x0000002D ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DBGXDL_BIT0:        equ    0                                         ; Comparator Data Low Compare Bit 0
DBGXDL_BIT1:        equ    1                                         ; Comparator Data Low Compare Bit 1
DBGXDL_BIT2:        equ    2                                         ; Comparator Data Low Compare Bit 2
DBGXDL_BIT3:        equ    3                                         ; Comparator Data Low Compare Bit 3
DBGXDL_BIT4:        equ    4                                         ; Comparator Data Low Compare Bit 4
DBGXDL_BIT5:        equ    5                                         ; Comparator Data Low Compare Bit 5
DBGXDL_BIT6:        equ    6                                         ; Comparator Data Low Compare Bit 6
DBGXDL_BIT7:        equ    7                                         ; Comparator Data Low Compare Bit 7
; bit position masks
mDBGXDL_BIT0:       equ    %00000001
mDBGXDL_BIT1:       equ    %00000010
mDBGXDL_BIT2:       equ    %00000100
mDBGXDL_BIT3:       equ    %00001000
mDBGXDL_BIT4:       equ    %00010000
mDBGXDL_BIT5:       equ    %00100000
mDBGXDL_BIT6:       equ    %01000000
mDBGXDL_BIT7:       equ    %10000000


;*** DBGXDHM - Debug Comparator Data High Mask Register; 0x0000002E ***
DBGXDHM:            equ    $0000002E                                ;*** DBGXDHM - Debug Comparator Data High Mask Register; 0x0000002E ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DBGXDHM_BIT8:       equ    0                                         ; Comparator Data High Mask Bit 8
DBGXDHM_BIT9:       equ    1                                         ; Comparator Data High Mask Bit 9
DBGXDHM_BIT10:      equ    2                                         ; Comparator Data High Mask Bit 10
DBGXDHM_BIT11:      equ    3                                         ; Comparator Data High Mask Bit 11
DBGXDHM_BIT12:      equ    4                                         ; Comparator Data High Mask Bit 12
DBGXDHM_BIT13:      equ    5                                         ; Comparator Data High Mask Bit 13
DBGXDHM_BIT14:      equ    6                                         ; Comparator Data High Mask Bit 14
DBGXDHM_BIT15:      equ    7                                         ; Comparator Data High Mask Bit 15
; bit position masks
mDBGXDHM_BIT8:      equ    %00000001
mDBGXDHM_BIT9:      equ    %00000010
mDBGXDHM_BIT10:     equ    %00000100
mDBGXDHM_BIT11:     equ    %00001000
mDBGXDHM_BIT12:     equ    %00010000
mDBGXDHM_BIT13:     equ    %00100000
mDBGXDHM_BIT14:     equ    %01000000
mDBGXDHM_BIT15:     equ    %10000000


;*** DBGXDLM - Debug Comparator Data Low Mask Register; 0x0000002F ***
DBGXDLM:            equ    $0000002F                                ;*** DBGXDLM - Debug Comparator Data Low Mask Register; 0x0000002F ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DBGXDLM_BIT0:       equ    0                                         ; Comparator Data Low Mask Bit 0
DBGXDLM_BIT1:       equ    1                                         ; Comparator Data Low Mask Bit 1
DBGXDLM_BIT2:       equ    2                                         ; Comparator Data Low Mask Bit 2
DBGXDLM_BIT3:       equ    3                                         ; Comparator Data Low Mask Bit 3
DBGXDLM_BIT4:       equ    4                                         ; Comparator Data Low Mask Bit 4
DBGXDLM_BIT5:       equ    5                                         ; Comparator Data Low Mask Bit 5
DBGXDLM_BIT6:       equ    6                                         ; Comparator Data Low Mask Bit 6
DBGXDLM_BIT7:       equ    7                                         ; Comparator Data Low Mask Bit 7
; bit position masks
mDBGXDLM_BIT0:      equ    %00000001
mDBGXDLM_BIT1:      equ    %00000010
mDBGXDLM_BIT2:      equ    %00000100
mDBGXDLM_BIT3:      equ    %00001000
mDBGXDLM_BIT4:      equ    %00010000
mDBGXDLM_BIT5:      equ    %00100000
mDBGXDLM_BIT6:      equ    %01000000
mDBGXDLM_BIT7:      equ    %10000000


;*** PORTK - Port K Data Register; 0x00000032 ***
PORTK:              equ    $00000032                                ;*** PORTK - Port K Data Register; 0x00000032 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PORTK_PK0:          equ    0                                         ; Port K Bit 0
PORTK_PK1:          equ    1                                         ; Port K Bit 1
PORTK_PK2:          equ    2                                         ; Port K Bit 2
PORTK_PK3:          equ    3                                         ; Port K Bit 3
PORTK_PK4:          equ    4                                         ; Port K Bit 4
PORTK_PK5:          equ    5                                         ; Port K Bit 5
PORTK_PK7:          equ    7                                         ; Port K Bit 7
; bit position masks
mPORTK_PK0:         equ    %00000001
mPORTK_PK1:         equ    %00000010
mPORTK_PK2:         equ    %00000100
mPORTK_PK3:         equ    %00001000
mPORTK_PK4:         equ    %00010000
mPORTK_PK5:         equ    %00100000
mPORTK_PK7:         equ    %10000000


;*** DDRK - Port K Data Direction Register; 0x00000033 ***
DDRK:               equ    $00000033                                ;*** DDRK - Port K Data Direction Register; 0x00000033 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DDRK_DDRK0:         equ    0                                         ; Data Direction Port K Bit 0
DDRK_DDRK1:         equ    1                                         ; Data Direction Port K Bit 1
DDRK_DDRK2:         equ    2                                         ; Data Direction Port K Bit 2
DDRK_DDRK3:         equ    3                                         ; Data Direction Port K Bit 3
DDRK_DDRK4:         equ    4                                         ; Data Direction Port K Bit 4
DDRK_DDRK5:         equ    5                                         ; Data Direction Port K Bit 5
DDRK_DDRK7:         equ    7                                         ; Data Direction Port K Bit 7
; bit position masks
mDDRK_DDRK0:        equ    %00000001
mDDRK_DDRK1:        equ    %00000010
mDDRK_DDRK2:        equ    %00000100
mDDRK_DDRK3:        equ    %00001000
mDDRK_DDRK4:        equ    %00010000
mDDRK_DDRK5:        equ    %00100000
mDDRK_DDRK7:        equ    %10000000


;*** SYNR - S12XECRG Synthesizer Register; 0x00000034 ***
SYNR:               equ    $00000034                                ;*** SYNR - S12XECRG Synthesizer Register; 0x00000034 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SYNR_SYNDIV0:       equ    0                                         ; Multiplication factor of the IPLL bit 0
SYNR_SYNDIV1:       equ    1                                         ; Multiplication factor of the IPLL bit 1
SYNR_SYNDIV2:       equ    2                                         ; Multiplication factor of the IPLL bit 2
SYNR_SYNDIV3:       equ    3                                         ; Multiplication factor of the IPLL bit 3
SYNR_SYNDIV4:       equ    4                                         ; Multiplication factor of the IPLL bit 4
SYNR_SYNDIV5:       equ    5                                         ; Multiplication factor of the IPLL bit 5
SYNR_VCOFRQ0:       equ    6                                         ; VCO frequency range bit 0
SYNR_VCOFRQ1:       equ    7                                         ; VCO frequency range bit 1
; bit position masks
mSYNR_SYNDIV0:      equ    %00000001
mSYNR_SYNDIV1:      equ    %00000010
mSYNR_SYNDIV2:      equ    %00000100
mSYNR_SYNDIV3:      equ    %00001000
mSYNR_SYNDIV4:      equ    %00010000
mSYNR_SYNDIV5:      equ    %00100000
mSYNR_VCOFRQ0:      equ    %01000000
mSYNR_VCOFRQ1:      equ    %10000000


;*** REFDV - S12XECRG Reference Divider Register; 0x00000035 ***
REFDV:              equ    $00000035                                ;*** REFDV - S12XECRG Reference Divider Register; 0x00000035 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
REFDV_REFDIV0:      equ    0                                         ; Finer granularity for the IPLL multiplier steps bit 0
REFDV_REFDIV1:      equ    1                                         ; Finer granularity for the IPLL multiplier steps bit 1
REFDV_REFDIV2:      equ    2                                         ; Finer granularity for the IPLL multiplier steps bit 2
REFDV_REFDIV3:      equ    3                                         ; Finer granularity for the IPLL multiplier steps bit 3
REFDV_REFDIV4:      equ    4                                         ; Finer granularity for the IPLL multiplier steps bit 4
REFDV_REFDIV5:      equ    5                                         ; Finer granularity for the IPLL multiplier steps bit 5
REFDV_REFFRQ0:      equ    6                                         ; IPLL optimal stability and lock time configuration bit 0
REFDV_REFFRQ1:      equ    7                                         ; IPLL optimal stability and lock time configuration bit 1
; bit position masks
mREFDV_REFDIV0:     equ    %00000001
mREFDV_REFDIV1:     equ    %00000010
mREFDV_REFDIV2:     equ    %00000100
mREFDV_REFDIV3:     equ    %00001000
mREFDV_REFDIV4:     equ    %00010000
mREFDV_REFDIV5:     equ    %00100000
mREFDV_REFFRQ0:     equ    %01000000
mREFDV_REFFRQ1:     equ    %10000000


;*** POSTDIV - S12XECRG Post Divider Register; 0x00000036 ***
POSTDIV:            equ    $00000036                                ;*** POSTDIV - S12XECRG Post Divider Register; 0x00000036 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
POSTDIV_POSTDIV0:   equ    0                                         ; Frequency ratio between the VCOCLK and PLLCLK control bit 0
POSTDIV_POSTDIV1:   equ    1                                         ; Frequency ratio between the VCOCLK and PLLCLK control bit 1
POSTDIV_POSTDIV2:   equ    2                                         ; Frequency ratio between the VCOCLK and PLLCLK control bit 2
POSTDIV_POSTDIV3:   equ    3                                         ; Frequency ratio between the VCOCLK and PLLCLK control bit 3
POSTDIV_POSTDIV4:   equ    4                                         ; Frequency ratio between the VCOCLK and PLLCLK control bit 4
; bit position masks
mPOSTDIV_POSTDIV0:  equ    %00000001
mPOSTDIV_POSTDIV1:  equ    %00000010
mPOSTDIV_POSTDIV2:  equ    %00000100
mPOSTDIV_POSTDIV3:  equ    %00001000
mPOSTDIV_POSTDIV4:  equ    %00010000


;*** CRGFLG - S12XECRG Flags Register; 0x00000037 ***
CRGFLG:             equ    $00000037                                ;*** CRGFLG - S12XECRG Flags Register; 0x00000037 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CRGFLG_SCM:         equ    0                                         ; Self Clock Mode Status Bit
CRGFLG_SCMIF:       equ    1                                         ; Self Clock Mode Interrupt Flag
CRGFLG_ILAF:        equ    2                                         ; Illegal Address Reset Flag
CRGFLG_LOCK:        equ    3                                         ; Lock Status Bit
CRGFLG_LOCKIF:      equ    4                                         ; IPLL Lock Interrupt Flag
CRGFLG_LVRF:        equ    5                                         ; Low Voltage Reset Flag
CRGFLG_PORF:        equ    6                                         ; Power on Reset Flag
CRGFLG_RTIF:        equ    7                                         ; Real Time Interrupt Flag
; bit position masks
mCRGFLG_SCM:        equ    %00000001
mCRGFLG_SCMIF:      equ    %00000010
mCRGFLG_ILAF:       equ    %00000100
mCRGFLG_LOCK:       equ    %00001000
mCRGFLG_LOCKIF:     equ    %00010000
mCRGFLG_LVRF:       equ    %00100000
mCRGFLG_PORF:       equ    %01000000
mCRGFLG_RTIF:       equ    %10000000


;*** CRGINT - S12XECRG Interrupt Enable Register; 0x00000038 ***
CRGINT:             equ    $00000038                                ;*** CRGINT - S12XECRG Interrupt Enable Register; 0x00000038 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CRGINT_SCMIE:       equ    1                                         ; Self Clock Mode Interrupt Enable Bit
CRGINT_LOCKIE:      equ    4                                         ; Lock Interrupt Enable Bit
CRGINT_RTIE:        equ    7                                         ; Real Time Interrupt Enable Bit
; bit position masks
mCRGINT_SCMIE:      equ    %00000010
mCRGINT_LOCKIE:     equ    %00010000
mCRGINT_RTIE:       equ    %10000000


;*** CLKSEL - S12XECRG Clock Select Register; 0x00000039 ***
CLKSEL:             equ    $00000039                                ;*** CLKSEL - S12XECRG Clock Select Register; 0x00000039 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CLKSEL_COPWAI:      equ    0                                         ; COP Stops in Wait Mode Bit
CLKSEL_RTIWAI:      equ    1                                         ; RTI Stops in Wait Mode Bit
CLKSEL_PLLWAI:      equ    3                                         ; PLL Stops in Wait Mode Bit
CLKSEL_XCLKS:       equ    5                                         ; Oscillator Configuration Status Bit
CLKSEL_PSTP:        equ    6                                         ; Pseudo Stop Bit
CLKSEL_PLLSEL:      equ    7                                         ; PLL Select Bit
; bit position masks
mCLKSEL_COPWAI:     equ    %00000001
mCLKSEL_RTIWAI:     equ    %00000010
mCLKSEL_PLLWAI:     equ    %00001000
mCLKSEL_XCLKS:      equ    %00100000
mCLKSEL_PSTP:       equ    %01000000
mCLKSEL_PLLSEL:     equ    %10000000


;*** PLLCTL - S12XECRG IPLL Control Register; 0x0000003A ***
PLLCTL:             equ    $0000003A                                ;*** PLLCTL - S12XECRG IPLL Control Register; 0x0000003A ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PLLCTL_SCME:        equ    0                                         ; Self Clock Mode Enable Bit
PLLCTL_PCE:         equ    1                                         ; COP Enable During Pseudo Stop Bit
PLLCTL_PRE:         equ    2                                         ; RTI Enable During Pseudo Stop Bit
PLLCTL_FSTWKP:      equ    3                                         ; Fast Wake-up from Full Stop Bit
PLLCTL_FM0:         equ    4                                         ; IPLL Frequency Modulation Enable Bit 0
PLLCTL_FM1:         equ    5                                         ; IPLL Frequency Modulation Enable Bit 1
PLLCTL_PLLON:       equ    6                                         ; Phase Lock Loop On Bit
PLLCTL_CME:         equ    7                                         ; Clock Monitor Enable Bit
; bit position masks
mPLLCTL_SCME:       equ    %00000001
mPLLCTL_PCE:        equ    %00000010
mPLLCTL_PRE:        equ    %00000100
mPLLCTL_FSTWKP:     equ    %00001000
mPLLCTL_FM0:        equ    %00010000
mPLLCTL_FM1:        equ    %00100000
mPLLCTL_PLLON:      equ    %01000000
mPLLCTL_CME:        equ    %10000000


;*** RTICTL - ECRG RTI Control Register; 0x0000003B ***
RTICTL:             equ    $0000003B                                ;*** RTICTL - ECRG RTI Control Register; 0x0000003B ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
RTICTL_RTR0:        equ    0                                         ; Real Time Interrupt Modulus Counter Select Bit 0
RTICTL_RTR1:        equ    1                                         ; Real Time Interrupt Modulus Counter Select Bit 1
RTICTL_RTR2:        equ    2                                         ; Real Time Interrupt Modulus Counter Select Bit 2
RTICTL_RTR3:        equ    3                                         ; Real Time Interrupt Modulus Counter Select Bit 3
RTICTL_RTR4:        equ    4                                         ; Real Time Interrupt Prescale Rate Select Bit 4
RTICTL_RTR5:        equ    5                                         ; Real Time Interrupt Prescale Rate Select Bit 5
RTICTL_RTR6:        equ    6                                         ; Real Time Interrupt Prescale Rate Select Bit 6
RTICTL_RTDEC:       equ    7                                         ; Decimal or Binary Divider Select Bit
; bit position masks
mRTICTL_RTR0:       equ    %00000001
mRTICTL_RTR1:       equ    %00000010
mRTICTL_RTR2:       equ    %00000100
mRTICTL_RTR3:       equ    %00001000
mRTICTL_RTR4:       equ    %00010000
mRTICTL_RTR5:       equ    %00100000
mRTICTL_RTR6:       equ    %01000000
mRTICTL_RTDEC:      equ    %10000000


;*** COPCTL - CRG COP Control Register; 0x0000003C ***
COPCTL:             equ    $0000003C                                ;*** COPCTL - CRG COP Control Register; 0x0000003C ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
COPCTL_CR0:         equ    0                                         ; COP Watchdog Timer Rate select Bit 0
COPCTL_CR1:         equ    1                                         ; COP Watchdog Timer Rate select Bit 1
COPCTL_CR2:         equ    2                                         ; COP Watchdog Timer Rate select Bit 2
COPCTL_WRTMASK:     equ    5                                         ; Write Mask for WCOP
COPCTL_RSBCK:       equ    6                                         ; COP and RTI stop in Active BDM mode Bit
COPCTL_WCOP:        equ    7                                         ; Window COP mode
; bit position masks
mCOPCTL_CR0:        equ    %00000001
mCOPCTL_CR1:        equ    %00000010
mCOPCTL_CR2:        equ    %00000100
mCOPCTL_WRTMASK:    equ    %00100000
mCOPCTL_RSBCK:      equ    %01000000
mCOPCTL_WCOP:       equ    %10000000


;*** ARMCOP - CRG COP Timer Arm/Reset Register; 0x0000003F ***
ARMCOP:             equ    $0000003F                                ;*** ARMCOP - CRG COP Timer Arm/Reset Register; 0x0000003F ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ARMCOP_BIT0:        equ    0                                         ; CRG COP Timer Arm/Reset Bit 0
ARMCOP_BIT1:        equ    1                                         ; CRG COP Timer Arm/Reset Bit 1
ARMCOP_BIT2:        equ    2                                         ; CRG COP Timer Arm/Reset Bit 2
ARMCOP_BIT3:        equ    3                                         ; CRG COP Timer Arm/Reset Bit 3
ARMCOP_BIT4:        equ    4                                         ; CRG COP Timer Arm/Reset Bit 4
ARMCOP_BIT5:        equ    5                                         ; CRG COP Timer Arm/Reset Bit 5
ARMCOP_BIT6:        equ    6                                         ; CRG COP Timer Arm/Reset Bit 6
ARMCOP_BIT7:        equ    7                                         ; CRG COP Timer Arm/Reset Bit 7
; bit position masks
mARMCOP_BIT0:       equ    %00000001
mARMCOP_BIT1:       equ    %00000010
mARMCOP_BIT2:       equ    %00000100
mARMCOP_BIT3:       equ    %00001000
mARMCOP_BIT4:       equ    %00010000
mARMCOP_BIT5:       equ    %00100000
mARMCOP_BIT6:       equ    %01000000
mARMCOP_BIT7:       equ    %10000000


;*** TIOS - Timer Input Capture/Output Compare Select; 0x00000040 ***
TIOS:               equ    $00000040                                ;*** TIOS - Timer Input Capture/Output Compare Select; 0x00000040 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TIOS_IOS0:          equ    0                                         ; Input Capture or Output Compare Channel Configuration Bit 0
TIOS_IOS1:          equ    1                                         ; Input Capture or Output Compare Channel Configuration Bit 1
TIOS_IOS2:          equ    2                                         ; Input Capture or Output Compare Channel Configuration Bit 2
TIOS_IOS3:          equ    3                                         ; Input Capture or Output Compare Channel Configuration Bit 3
TIOS_IOS4:          equ    4                                         ; Input Capture or Output Compare Channel Configuration Bit 4
TIOS_IOS5:          equ    5                                         ; Input Capture or Output Compare Channel Configuration Bit 5
TIOS_IOS6:          equ    6                                         ; Input Capture or Output Compare Channel Configuration Bit 6
TIOS_IOS7:          equ    7                                         ; Input Capture or Output Compare Channel Configuration Bit 7
; bit position masks
mTIOS_IOS0:         equ    %00000001
mTIOS_IOS1:         equ    %00000010
mTIOS_IOS2:         equ    %00000100
mTIOS_IOS3:         equ    %00001000
mTIOS_IOS4:         equ    %00010000
mTIOS_IOS5:         equ    %00100000
mTIOS_IOS6:         equ    %01000000
mTIOS_IOS7:         equ    %10000000


;*** CFORC - Timer Compare Force Register; 0x00000041 ***
CFORC:              equ    $00000041                                ;*** CFORC - Timer Compare Force Register; 0x00000041 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CFORC_FOC0:         equ    0                                         ; Force Output Compare Action for Channel 0
CFORC_FOC1:         equ    1                                         ; Force Output Compare Action for Channel 1
CFORC_FOC2:         equ    2                                         ; Force Output Compare Action for Channel 2
CFORC_FOC3:         equ    3                                         ; Force Output Compare Action for Channel 3
CFORC_FOC4:         equ    4                                         ; Force Output Compare Action for Channel 4
CFORC_FOC5:         equ    5                                         ; Force Output Compare Action for Channel 5
CFORC_FOC6:         equ    6                                         ; Force Output Compare Action for Channel 6
CFORC_FOC7:         equ    7                                         ; Force Output Compare Action for Channel 7
; bit position masks
mCFORC_FOC0:        equ    %00000001
mCFORC_FOC1:        equ    %00000010
mCFORC_FOC2:        equ    %00000100
mCFORC_FOC3:        equ    %00001000
mCFORC_FOC4:        equ    %00010000
mCFORC_FOC5:        equ    %00100000
mCFORC_FOC6:        equ    %01000000
mCFORC_FOC7:        equ    %10000000


;*** OC7M - Output Compare 7 Mask Register; 0x00000042 ***
OC7M:               equ    $00000042                                ;*** OC7M - Output Compare 7 Mask Register; 0x00000042 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
OC7M_OC7M0:         equ    0                                         ; Output Compare 7 Mask Bit 0
OC7M_OC7M1:         equ    1                                         ; Output Compare 7 Mask Bit 1
OC7M_OC7M2:         equ    2                                         ; Output Compare 7 Mask Bit 2
OC7M_OC7M3:         equ    3                                         ; Output Compare 7 Mask Bit 3
OC7M_OC7M4:         equ    4                                         ; Output Compare 7 Mask Bit 4
OC7M_OC7M5:         equ    5                                         ; Output Compare 7 Mask Bit 5
OC7M_OC7M6:         equ    6                                         ; Output Compare 7 Mask Bit 6
OC7M_OC7M7:         equ    7                                         ; Output Compare 7 Mask Bit 7
; bit position masks
mOC7M_OC7M0:        equ    %00000001
mOC7M_OC7M1:        equ    %00000010
mOC7M_OC7M2:        equ    %00000100
mOC7M_OC7M3:        equ    %00001000
mOC7M_OC7M4:        equ    %00010000
mOC7M_OC7M5:        equ    %00100000
mOC7M_OC7M6:        equ    %01000000
mOC7M_OC7M7:        equ    %10000000


;*** OC7D - Output Compare 7 Data Register; 0x00000043 ***
OC7D:               equ    $00000043                                ;*** OC7D - Output Compare 7 Data Register; 0x00000043 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
OC7D_OC7D0:         equ    0                                         ; Output Compare 7 Bit 0
OC7D_OC7D1:         equ    1                                         ; Output Compare 7 Bit 1
OC7D_OC7D2:         equ    2                                         ; Output Compare 7 Bit 2
OC7D_OC7D3:         equ    3                                         ; Output Compare 7 Bit 3
OC7D_OC7D4:         equ    4                                         ; Output Compare 7 Bit 4
OC7D_OC7D5:         equ    5                                         ; Output Compare 7 Bit 5
OC7D_OC7D6:         equ    6                                         ; Output Compare 7 Bit 6
OC7D_OC7D7:         equ    7                                         ; Output Compare 7 Bit 7
; bit position masks
mOC7D_OC7D0:        equ    %00000001
mOC7D_OC7D1:        equ    %00000010
mOC7D_OC7D2:        equ    %00000100
mOC7D_OC7D3:        equ    %00001000
mOC7D_OC7D4:        equ    %00010000
mOC7D_OC7D5:        equ    %00100000
mOC7D_OC7D6:        equ    %01000000
mOC7D_OC7D7:        equ    %10000000


;*** TCNT - Timer Count Register; 0x00000044 ***
TCNT:               equ    $00000044                                ;*** TCNT - Timer Count Register; 0x00000044 ***


;*** TCNTHi - Timer Count Register High; 0x00000044 ***
TCNTHi:             equ    $00000044                                ;*** TCNTHi - Timer Count Register High; 0x00000044 ***


;*** TCNTLo - Timer Count Register Low; 0x00000045 ***
TCNTLo:             equ    $00000045                                ;*** TCNTLo - Timer Count Register Low; 0x00000045 ***


;*** TSCR1 - Timer System Control Register1; 0x00000046 ***
TSCR1:              equ    $00000046                                ;*** TSCR1 - Timer System Control Register1; 0x00000046 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TSCR1_PRNT:         equ    3                                         ; Precision Timer
TSCR1_TFFCA:        equ    4                                         ; Timer Fast Flag Clear All
TSCR1_TSFRZ:        equ    5                                         ; Timer and Modulus Counter Stop While in Freeze Mode
TSCR1_TSWAI:        equ    6                                         ; Timer Module Stops While in Wait
TSCR1_TEN:          equ    7                                         ; Timer Enable
; bit position masks
mTSCR1_PRNT:        equ    %00001000
mTSCR1_TFFCA:       equ    %00010000
mTSCR1_TSFRZ:       equ    %00100000
mTSCR1_TSWAI:       equ    %01000000
mTSCR1_TEN:         equ    %10000000


;*** TTOV - Timer Toggle On Overflow Register; 0x00000047 ***
TTOV:               equ    $00000047                                ;*** TTOV - Timer Toggle On Overflow Register; 0x00000047 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TTOV_TOV0:          equ    0                                         ; Toggle On Overflow Bit 0
TTOV_TOV1:          equ    1                                         ; Toggle On Overflow Bit 1
TTOV_TOV2:          equ    2                                         ; Toggle On Overflow Bit 2
TTOV_TOV3:          equ    3                                         ; Toggle On Overflow Bit 3
TTOV_TOV4:          equ    4                                         ; Toggle On Overflow Bit 4
TTOV_TOV5:          equ    5                                         ; Toggle On Overflow Bit 5
TTOV_TOV6:          equ    6                                         ; Toggle On Overflow Bit 6
TTOV_TOV7:          equ    7                                         ; Toggle On Overflow Bit 7
; bit position masks
mTTOV_TOV0:         equ    %00000001
mTTOV_TOV1:         equ    %00000010
mTTOV_TOV2:         equ    %00000100
mTTOV_TOV3:         equ    %00001000
mTTOV_TOV4:         equ    %00010000
mTTOV_TOV5:         equ    %00100000
mTTOV_TOV6:         equ    %01000000
mTTOV_TOV7:         equ    %10000000


;*** TCTL1 - Timer Control Register 1; 0x00000048 ***
TCTL1:              equ    $00000048                                ;*** TCTL1 - Timer Control Register 1; 0x00000048 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TCTL1_OL4:          equ    0                                         ; Output Level Bit 4
TCTL1_OM4:          equ    1                                         ; Output Mode Bit 4
TCTL1_OL5:          equ    2                                         ; Output Level Bit 5
TCTL1_OM5:          equ    3                                         ; Output Mode Bit 5
TCTL1_OL6:          equ    4                                         ; Output Level Bit 6
TCTL1_OM6:          equ    5                                         ; Output Mode Bit 6
TCTL1_OL7:          equ    6                                         ; Output Level Bit 7
TCTL1_OM7:          equ    7                                         ; Output Mode Bit 7
; bit position masks
mTCTL1_OL4:         equ    %00000001
mTCTL1_OM4:         equ    %00000010
mTCTL1_OL5:         equ    %00000100
mTCTL1_OM5:         equ    %00001000
mTCTL1_OL6:         equ    %00010000
mTCTL1_OM6:         equ    %00100000
mTCTL1_OL7:         equ    %01000000
mTCTL1_OM7:         equ    %10000000


;*** TCTL2 - Timer Control Register 2; 0x00000049 ***
TCTL2:              equ    $00000049                                ;*** TCTL2 - Timer Control Register 2; 0x00000049 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TCTL2_OL0:          equ    0                                         ; Output Level Bit 0
TCTL2_OM0:          equ    1                                         ; Output Mode Bit 0
TCTL2_OL1:          equ    2                                         ; Output Lecel Bit 1
TCTL2_OM1:          equ    3                                         ; Output Mode Bit 1
TCTL2_OL2:          equ    4                                         ; Output Level Bit 2
TCTL2_OM2:          equ    5                                         ; Output Mode Bit 2
TCTL2_OL3:          equ    6                                         ; Output Level Bit 3
TCTL2_OM3:          equ    7                                         ; Output Mode Bit 3
; bit position masks
mTCTL2_OL0:         equ    %00000001
mTCTL2_OM0:         equ    %00000010
mTCTL2_OL1:         equ    %00000100
mTCTL2_OM1:         equ    %00001000
mTCTL2_OL2:         equ    %00010000
mTCTL2_OM2:         equ    %00100000
mTCTL2_OL3:         equ    %01000000
mTCTL2_OM3:         equ    %10000000


;*** TCTL3 - Timer Control Register 3; 0x0000004A ***
TCTL3:              equ    $0000004A                                ;*** TCTL3 - Timer Control Register 3; 0x0000004A ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TCTL3_EDG4A:        equ    0                                         ; Input Capture Edge Control 4A
TCTL3_EDG4B:        equ    1                                         ; Input Capture Edge Control 4B
TCTL3_EDG5A:        equ    2                                         ; Input Capture Edge Control 5A
TCTL3_EDG5B:        equ    3                                         ; Input Capture Edge Control 5B
TCTL3_EDG6A:        equ    4                                         ; Input Capture Edge Control 6A
TCTL3_EDG6B:        equ    5                                         ; Input Capture Edge Control 6B
TCTL3_EDG7A:        equ    6                                         ; Input Capture Edge Control 7A
TCTL3_EDG7B:        equ    7                                         ; Input Capture Edge Control 7B
; bit position masks
mTCTL3_EDG4A:       equ    %00000001
mTCTL3_EDG4B:       equ    %00000010
mTCTL3_EDG5A:       equ    %00000100
mTCTL3_EDG5B:       equ    %00001000
mTCTL3_EDG6A:       equ    %00010000
mTCTL3_EDG6B:       equ    %00100000
mTCTL3_EDG7A:       equ    %01000000
mTCTL3_EDG7B:       equ    %10000000


;*** TCTL4 - Timer Control Register 4; 0x0000004B ***
TCTL4:              equ    $0000004B                                ;*** TCTL4 - Timer Control Register 4; 0x0000004B ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TCTL4_EDG0A:        equ    0                                         ; Input Capture Edge Control 0A
TCTL4_EDG0B:        equ    1                                         ; Input Capture Edge Control 0B
TCTL4_EDG1A:        equ    2                                         ; Input Capture Edge Control 1A
TCTL4_EDG1B:        equ    3                                         ; Input Capture Edge Control 1B
TCTL4_EDG2A:        equ    4                                         ; Input Capture Edge Control 2A
TCTL4_EDG2B:        equ    5                                         ; Input Capture Edge Control 2B
TCTL4_EDG3A:        equ    6                                         ; Input Capture Edge Control 3A
TCTL4_EDG3B:        equ    7                                         ; Input Capture Edge Control 3B
; bit position masks
mTCTL4_EDG0A:       equ    %00000001
mTCTL4_EDG0B:       equ    %00000010
mTCTL4_EDG1A:       equ    %00000100
mTCTL4_EDG1B:       equ    %00001000
mTCTL4_EDG2A:       equ    %00010000
mTCTL4_EDG2B:       equ    %00100000
mTCTL4_EDG3A:       equ    %01000000
mTCTL4_EDG3B:       equ    %10000000


;*** TIE - Timer Interrupt Enable Register; 0x0000004C ***
TIE:                equ    $0000004C                                ;*** TIE - Timer Interrupt Enable Register; 0x0000004C ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TIE_C0I:            equ    0                                         ; Input Capture/Output Compare Interrupt Enable Bit 0
TIE_C1I:            equ    1                                         ; Input Capture/Output Compare Interrupt Enable Bit 1
TIE_C2I:            equ    2                                         ; Input Capture/Output Compare Interrupt Enable Bit 2
TIE_C3I:            equ    3                                         ; Input Capture/Output Compare Interrupt Enable Bit 3
TIE_C4I:            equ    4                                         ; Input Capture/Output Compare Interrupt Enable Bit 4
TIE_C5I:            equ    5                                         ; Input Capture/Output Compare Interrupt Enable Bit 5
TIE_C6I:            equ    6                                         ; Input Capture/Output Compare Interrupt Enable Bit 6
TIE_C7I:            equ    7                                         ; Input Capture/Output Compare Interrupt Enable Bit 7
; bit position masks
mTIE_C0I:           equ    %00000001
mTIE_C1I:           equ    %00000010
mTIE_C2I:           equ    %00000100
mTIE_C3I:           equ    %00001000
mTIE_C4I:           equ    %00010000
mTIE_C5I:           equ    %00100000
mTIE_C6I:           equ    %01000000
mTIE_C7I:           equ    %10000000


;*** TSCR2 - Timer System Control Register 2; 0x0000004D ***
TSCR2:              equ    $0000004D                                ;*** TSCR2 - Timer System Control Register 2; 0x0000004D ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TSCR2_PR0:          equ    0                                         ; Timer Prescaler Select Bit 0
TSCR2_PR1:          equ    1                                         ; Timer Prescaler Select Bit 1
TSCR2_PR2:          equ    2                                         ; Timer Prescaler Select Bit 2
TSCR2_TCRE:         equ    3                                         ; Timer Counter Reset Enable
TSCR2_TOI:          equ    7                                         ; Timer Overflow Interrupt Enable
; bit position masks
mTSCR2_PR0:         equ    %00000001
mTSCR2_PR1:         equ    %00000010
mTSCR2_PR2:         equ    %00000100
mTSCR2_TCRE:        equ    %00001000
mTSCR2_TOI:         equ    %10000000


;*** TFLG1 - Main Timer Interrupt Flag 1; 0x0000004E ***
TFLG1:              equ    $0000004E                                ;*** TFLG1 - Main Timer Interrupt Flag 1; 0x0000004E ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TFLG1_C0F:          equ    0                                         ; Input Capture/Output Compare Channel Flag 0
TFLG1_C1F:          equ    1                                         ; Input Capture/Output Compare Channel Flag 1
TFLG1_C2F:          equ    2                                         ; Input Capture/Output Compare Channel Flag 2
TFLG1_C3F:          equ    3                                         ; Input Capture/Output Compare Channel Flag 3
TFLG1_C4F:          equ    4                                         ; Input Capture/Output Compare Channel Flag 4
TFLG1_C5F:          equ    5                                         ; Input Capture/Output Compare Channel Flag 5
TFLG1_C6F:          equ    6                                         ; Input Capture/Output Compare Channel Flag 6
TFLG1_C7F:          equ    7                                         ; Input Capture/Output Compare Channel Flag 7
; bit position masks
mTFLG1_C0F:         equ    %00000001
mTFLG1_C1F:         equ    %00000010
mTFLG1_C2F:         equ    %00000100
mTFLG1_C3F:         equ    %00001000
mTFLG1_C4F:         equ    %00010000
mTFLG1_C5F:         equ    %00100000
mTFLG1_C6F:         equ    %01000000
mTFLG1_C7F:         equ    %10000000


;*** TFLG2 - Main Timer Interrupt Flag 2; 0x0000004F ***
TFLG2:              equ    $0000004F                                ;*** TFLG2 - Main Timer Interrupt Flag 2; 0x0000004F ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TFLG2_TOF:          equ    7                                         ; Timer Overflow Flag
; bit position masks
mTFLG2_TOF:         equ    %10000000


;*** TC0 - Timer Input Capture/Output Compare Register 0; 0x00000050 ***
TC0:                equ    $00000050                                ;*** TC0 - Timer Input Capture/Output Compare Register 0; 0x00000050 ***


;*** TC0Hi - Timer Input Capture/Output Compare Register 0 High; 0x00000050 ***
TC0Hi:              equ    $00000050                                ;*** TC0Hi - Timer Input Capture/Output Compare Register 0 High; 0x00000050 ***


;*** TC0Lo - Timer Input Capture/Output Compare Register 0 Low; 0x00000051 ***
TC0Lo:              equ    $00000051                                ;*** TC0Lo - Timer Input Capture/Output Compare Register 0 Low; 0x00000051 ***


;*** TC1 - Timer Input Capture/Output Compare Register 1; 0x00000052 ***
TC1:                equ    $00000052                                ;*** TC1 - Timer Input Capture/Output Compare Register 1; 0x00000052 ***


;*** TC1Hi - Timer Input Capture/Output Compare Register 1 High; 0x00000052 ***
TC1Hi:              equ    $00000052                                ;*** TC1Hi - Timer Input Capture/Output Compare Register 1 High; 0x00000052 ***


;*** TC1Lo - Timer Input Capture/Output Compare Register 1 Low; 0x00000053 ***
TC1Lo:              equ    $00000053                                ;*** TC1Lo - Timer Input Capture/Output Compare Register 1 Low; 0x00000053 ***


;*** TC2 - Timer Input Capture/Output Compare Register 2; 0x00000054 ***
TC2:                equ    $00000054                                ;*** TC2 - Timer Input Capture/Output Compare Register 2; 0x00000054 ***


;*** TC2Hi - Timer Input Capture/Output Compare Register 2 High; 0x00000054 ***
TC2Hi:              equ    $00000054                                ;*** TC2Hi - Timer Input Capture/Output Compare Register 2 High; 0x00000054 ***


;*** TC2Lo - Timer Input Capture/Output Compare Register 2 Low; 0x00000055 ***
TC2Lo:              equ    $00000055                                ;*** TC2Lo - Timer Input Capture/Output Compare Register 2 Low; 0x00000055 ***


;*** TC3 - Timer Input Capture/Output Compare Register 3; 0x00000056 ***
TC3:                equ    $00000056                                ;*** TC3 - Timer Input Capture/Output Compare Register 3; 0x00000056 ***


;*** TC3Hi - Timer Input Capture/Output Compare Register 3 High; 0x00000056 ***
TC3Hi:              equ    $00000056                                ;*** TC3Hi - Timer Input Capture/Output Compare Register 3 High; 0x00000056 ***


;*** TC3Lo - Timer Input Capture/Output Compare Register 3 Low; 0x00000057 ***
TC3Lo:              equ    $00000057                                ;*** TC3Lo - Timer Input Capture/Output Compare Register 3 Low; 0x00000057 ***


;*** TC4 - Timer Input Capture/Output Compare Register 4; 0x00000058 ***
TC4:                equ    $00000058                                ;*** TC4 - Timer Input Capture/Output Compare Register 4; 0x00000058 ***


;*** TC4Hi - Timer Input Capture/Output Compare Register 4 High; 0x00000058 ***
TC4Hi:              equ    $00000058                                ;*** TC4Hi - Timer Input Capture/Output Compare Register 4 High; 0x00000058 ***


;*** TC4Lo - Timer Input Capture/Output Compare Register 4 Low; 0x00000059 ***
TC4Lo:              equ    $00000059                                ;*** TC4Lo - Timer Input Capture/Output Compare Register 4 Low; 0x00000059 ***


;*** TC5 - Timer Input Capture/Output Compare Register 5; 0x0000005A ***
TC5:                equ    $0000005A                                ;*** TC5 - Timer Input Capture/Output Compare Register 5; 0x0000005A ***


;*** TC5Hi - Timer Input Capture/Output Compare Register 5 High; 0x0000005A ***
TC5Hi:              equ    $0000005A                                ;*** TC5Hi - Timer Input Capture/Output Compare Register 5 High; 0x0000005A ***


;*** TC5Lo - Timer Input Capture/Output Compare Register 5 Low; 0x0000005B ***
TC5Lo:              equ    $0000005B                                ;*** TC5Lo - Timer Input Capture/Output Compare Register 5 Low; 0x0000005B ***


;*** TC6 - Timer Input Capture/Output Compare Register 6; 0x0000005C ***
TC6:                equ    $0000005C                                ;*** TC6 - Timer Input Capture/Output Compare Register 6; 0x0000005C ***


;*** TC6Hi - Timer Input Capture/Output Compare Register 6 High; 0x0000005C ***
TC6Hi:              equ    $0000005C                                ;*** TC6Hi - Timer Input Capture/Output Compare Register 6 High; 0x0000005C ***


;*** TC6Lo - Timer Input Capture/Output Compare Register 6 Low; 0x0000005D ***
TC6Lo:              equ    $0000005D                                ;*** TC6Lo - Timer Input Capture/Output Compare Register 6 Low; 0x0000005D ***


;*** TC7 - Timer Input Capture/Output Compare Register 7; 0x0000005E ***
TC7:                equ    $0000005E                                ;*** TC7 - Timer Input Capture/Output Compare Register 7; 0x0000005E ***


;*** TC7Hi - Timer Input Capture/Output Compare Register 7 High; 0x0000005E ***
TC7Hi:              equ    $0000005E                                ;*** TC7Hi - Timer Input Capture/Output Compare Register 7 High; 0x0000005E ***


;*** TC7Lo - Timer Input Capture/Output Compare Register 7 Low; 0x0000005F ***
TC7Lo:              equ    $0000005F                                ;*** TC7Lo - Timer Input Capture/Output Compare Register 7 Low; 0x0000005F ***


;*** PACTL - 16-Bit Pulse Accumulator A Control Register; 0x00000060 ***
PACTL:              equ    $00000060                                ;*** PACTL - 16-Bit Pulse Accumulator A Control Register; 0x00000060 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PACTL_PAI:          equ    0                                         ; Pulse Accumulator Input Interrupt enable
PACTL_PAOVI:        equ    1                                         ; Pulse Accumulator A Overflow Interrupt enable
PACTL_CLK0:         equ    2                                         ; Clock Select Bit 0
PACTL_CLK1:         equ    3                                         ; Clock Select Bit 1
PACTL_PEDGE:        equ    4                                         ; Pulse Accumulator Edge Control
PACTL_PAMOD:        equ    5                                         ; Pulse Accumulator Mode
PACTL_PAEN:         equ    6                                         ; Pulse Accumulator A System Enable
; bit position masks
mPACTL_PAI:         equ    %00000001
mPACTL_PAOVI:       equ    %00000010
mPACTL_CLK0:        equ    %00000100
mPACTL_CLK1:        equ    %00001000
mPACTL_PEDGE:       equ    %00010000
mPACTL_PAMOD:       equ    %00100000
mPACTL_PAEN:        equ    %01000000


;*** PAFLG - Pulse Accumulator A Flag Register; 0x00000061 ***
PAFLG:              equ    $00000061                                ;*** PAFLG - Pulse Accumulator A Flag Register; 0x00000061 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PAFLG_PAIF:         equ    0                                         ; Pulse Accumulator Input edge Flag
PAFLG_PAOVF:        equ    1                                         ; Pulse Accumulator A Overflow Flag
; bit position masks
mPAFLG_PAIF:        equ    %00000001
mPAFLG_PAOVF:       equ    %00000010


;*** PACNT - Pulse Accumulators Count Register; 0x00000062 ***
PACNT:              equ    $00000062                                ;*** PACNT - Pulse Accumulators Count Register; 0x00000062 ***


;*** PACNTH - Pulse Accumulators Count Register High; 0x00000062 ***
PACNTH:             equ    $00000062                                ;*** PACNTH - Pulse Accumulators Count Register High; 0x00000062 ***


;*** PACNTL - Pulse Accumulators Count Register Low; 0x00000063 ***
PACNTL:             equ    $00000063                                ;*** PACNTL - Pulse Accumulators Count Register Low; 0x00000063 ***


;*** OCPD - Output Compare Pin Disconnect Register; 0x0000006C ***
OCPD:               equ    $0000006C                                ;*** OCPD - Output Compare Pin Disconnect Register; 0x0000006C ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
OCPD_OCPD0:         equ    0                                         ; Output Compare Pin Disconnect Bit 0
OCPD_OCPD1:         equ    1                                         ; Output Compare Pin Disconnect Bit 1
OCPD_OCPD2:         equ    2                                         ; Output Compare Pin Disconnect Bit 2
OCPD_OCPD3:         equ    3                                         ; Output Compare Pin Disconnect Bit 3
OCPD_OCPD4:         equ    4                                         ; Output Compare Pin Disconnect Bit 4
OCPD_OCPD5:         equ    5                                         ; Output Compare Pin Disconnect Bit 5
OCPD_OCPD6:         equ    6                                         ; Output Compare Pin Disconnect Bit 6
OCPD_OCPD7:         equ    7                                         ; Output Compare Pin Disconnect Bit 7
; bit position masks
mOCPD_OCPD0:        equ    %00000001
mOCPD_OCPD1:        equ    %00000010
mOCPD_OCPD2:        equ    %00000100
mOCPD_OCPD3:        equ    %00001000
mOCPD_OCPD4:        equ    %00010000
mOCPD_OCPD5:        equ    %00100000
mOCPD_OCPD6:        equ    %01000000
mOCPD_OCPD7:        equ    %10000000


;*** PTPSR - Precision Timer Prescaler Select Register; 0x0000006E ***
PTPSR:              equ    $0000006E                                ;*** PTPSR - Precision Timer Prescaler Select Register; 0x0000006E ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTPSR_PTPS0:        equ    0                                         ; Precision Timer Prescaler Select Bit 0
PTPSR_PTPS1:        equ    1                                         ; Precision Timer Prescaler Select Bit 1
PTPSR_PTPS2:        equ    2                                         ; Precision Timer Prescaler Select Bit 2
PTPSR_PTPS3:        equ    3                                         ; Precision Timer Prescaler Select Bit 3
PTPSR_PTPS4:        equ    4                                         ; Precision Timer Prescaler Select Bit 4
PTPSR_PTPS5:        equ    5                                         ; Precision Timer Prescaler Select Bit 5
PTPSR_PTPS6:        equ    6                                         ; Precision Timer Prescaler Select Bit 6
PTPSR_PTPS7:        equ    7                                         ; Precision Timer Prescaler Select Bit 7
; bit position masks
mPTPSR_PTPS0:       equ    %00000001
mPTPSR_PTPS1:       equ    %00000010
mPTPSR_PTPS2:       equ    %00000100
mPTPSR_PTPS3:       equ    %00001000
mPTPSR_PTPS4:       equ    %00010000
mPTPSR_PTPS5:       equ    %00100000
mPTPSR_PTPS6:       equ    %01000000
mPTPSR_PTPS7:       equ    %10000000


;*** SCI0BD - SCI 0 Baud Rate Register; 0x000000C8 ***
SCI0BD:             equ    $000000C8                                ;*** SCI0BD - SCI 0 Baud Rate Register; 0x000000C8 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI0BD_SBR0:        equ    0                                         ; SCI Baud Rate Bit 0
SCI0BD_SBR1:        equ    1                                         ; SCI Baud Rate Bit 1
SCI0BD_SBR2:        equ    2                                         ; SCI Baud Rate Bit 2
SCI0BD_SBR3:        equ    3                                         ; SCI Baud Rate Bit 3
SCI0BD_SBR4:        equ    4                                         ; SCI Baud Rate Bit 4
SCI0BD_SBR5:        equ    5                                         ; SCI Baud Rate Bit 5
SCI0BD_SBR6:        equ    6                                         ; SCI Baud Rate Bit 6
SCI0BD_SBR7:        equ    7                                         ; SCI Baud Rate Bit 7
SCI0BD_SBR8:        equ    8                                         ; SCI Baud Rate Bit 8
SCI0BD_SBR9:        equ    9                                         ; SCI Baud Rate Bit 9
SCI0BD_SBR10:       equ    10                                        ; SCI Baud Rate Bit 10
SCI0BD_SBR11:       equ    11                                        ; SCI Baud Rate Bit 11
SCI0BD_SBR12:       equ    12                                        ; SCI Baud Rate Bit 12
SCI0BD_TNP0:        equ    13                                        ; Transmitter Narrow Pulse Bit 0
SCI0BD_TNP1:        equ    14                                        ; Transmitter Narrow Pulse Bit 1
SCI0BD_IREN:        equ    15                                        ; Infrared Enable Bit
; bit position masks
mSCI0BD_SBR0:       equ    %00000001
mSCI0BD_SBR1:       equ    %00000010
mSCI0BD_SBR2:       equ    %00000100
mSCI0BD_SBR3:       equ    %00001000
mSCI0BD_SBR4:       equ    %00010000
mSCI0BD_SBR5:       equ    %00100000
mSCI0BD_SBR6:       equ    %01000000
mSCI0BD_SBR7:       equ    %10000000
mSCI0BD_SBR8:       equ    %100000000
mSCI0BD_SBR9:       equ    %1000000000
mSCI0BD_SBR10:      equ    %10000000000
mSCI0BD_SBR11:      equ    %100000000000
mSCI0BD_SBR12:      equ    %1000000000000
mSCI0BD_TNP0:       equ    %10000000000000
mSCI0BD_TNP1:       equ    %100000000000000
mSCI0BD_IREN:       equ    %1000000000000000


;*** SCI0ASR1 - SCI 0 Alternative Status Register 1; 0x000000C8 ***
SCI0ASR1:           equ    $000000C8                                ;*** SCI0ASR1 - SCI 0 Alternative Status Register 1; 0x000000C8 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI0ASR1_BKDIF:     equ    0                                         ; Break Detect Interrupt Flag
SCI0ASR1_BERRIF:    equ    1                                         ; Bit Error Interrupt Flag
SCI0ASR1_BERRV:     equ    2                                         ; Bit Error Value
SCI0ASR1_RXEDGIF:   equ    7                                         ; Receive Input Active Edge Interrupt Flag
; bit position masks
mSCI0ASR1_BKDIF:    equ    %00000001
mSCI0ASR1_BERRIF:   equ    %00000010
mSCI0ASR1_BERRV:    equ    %00000100
mSCI0ASR1_RXEDGIF:  equ    %10000000


;*** SCI0BDH - SCI 0 Baud Rate Register High; 0x000000C8 ***
SCI0BDH:            equ    $000000C8                                ;*** SCI0BDH - SCI 0 Baud Rate Register High; 0x000000C8 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI0BDH_SBR8:       equ    0                                         ; SCI Baud Rate Bit 8
SCI0BDH_SBR9:       equ    1                                         ; SCI Baud Rate Bit 9
SCI0BDH_SBR10:      equ    2                                         ; SCI Baud Rate Bit 10
SCI0BDH_SBR11:      equ    3                                         ; SCI Baud Rate Bit 11
SCI0BDH_SBR12:      equ    4                                         ; SCI Baud Rate Bit 12
SCI0BDH_TNP0:       equ    5                                         ; Transmitter Narrow Pulse Bit 0
SCI0BDH_TNP1:       equ    6                                         ; Transmitter Narrow Pulse Bit 1
SCI0BDH_IREN:       equ    7                                         ; Infrared Enable Bit
; bit position masks
mSCI0BDH_SBR8:      equ    %00000001
mSCI0BDH_SBR9:      equ    %00000010
mSCI0BDH_SBR10:     equ    %00000100
mSCI0BDH_SBR11:     equ    %00001000
mSCI0BDH_SBR12:     equ    %00010000
mSCI0BDH_TNP0:      equ    %00100000
mSCI0BDH_TNP1:      equ    %01000000
mSCI0BDH_IREN:      equ    %10000000


;*** SCI0ACR1 - SCI 0 Alternative Control Register 1; 0x000000C9 ***
SCI0ACR1:           equ    $000000C9                                ;*** SCI0ACR1 - SCI 0 Alternative Control Register 1; 0x000000C9 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI0ACR1_BKDIE:     equ    0                                         ; Break Detect Interrupt Enable
SCI0ACR1_BERRIE:    equ    1                                         ; Bit Error Interrupt Enable
SCI0ACR1_RXEDGIE:   equ    7                                         ; Receive Input Active Edge Interrupt Enable
; bit position masks
mSCI0ACR1_BKDIE:    equ    %00000001
mSCI0ACR1_BERRIE:   equ    %00000010
mSCI0ACR1_RXEDGIE:  equ    %10000000


;*** SCI0BDL - SCI 0 Baud Rate Register Low; 0x000000C9 ***
SCI0BDL:            equ    $000000C9                                ;*** SCI0BDL - SCI 0 Baud Rate Register Low; 0x000000C9 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI0BDL_SBR0:       equ    0                                         ; SCI Baud Rate Bit 0
SCI0BDL_SBR1:       equ    1                                         ; SCI Baud Rate Bit 1
SCI0BDL_SBR2:       equ    2                                         ; SCI Baud Rate Bit 2
SCI0BDL_SBR3:       equ    3                                         ; SCI Baud Rate Bit 3
SCI0BDL_SBR4:       equ    4                                         ; SCI Baud Rate Bit 4
SCI0BDL_SBR5:       equ    5                                         ; SCI Baud Rate Bit 5
SCI0BDL_SBR6:       equ    6                                         ; SCI Baud Rate Bit 6
SCI0BDL_SBR7:       equ    7                                         ; SCI Baud Rate Bit 7
; bit position masks
mSCI0BDL_SBR0:      equ    %00000001
mSCI0BDL_SBR1:      equ    %00000010
mSCI0BDL_SBR2:      equ    %00000100
mSCI0BDL_SBR3:      equ    %00001000
mSCI0BDL_SBR4:      equ    %00010000
mSCI0BDL_SBR5:      equ    %00100000
mSCI0BDL_SBR6:      equ    %01000000
mSCI0BDL_SBR7:      equ    %10000000


;*** SCI0ACR2 - SCI 0 Alternative Control Register 2; 0x000000CA ***
SCI0ACR2:           equ    $000000CA                                ;*** SCI0ACR2 - SCI 0 Alternative Control Register 2; 0x000000CA ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI0ACR2_BKDFE:     equ    0                                         ; Break Detect Feature Enable
SCI0ACR2_BERRM0:    equ    1                                         ; Bit Error Mode 0
SCI0ACR2_BERRM1:    equ    2                                         ; Bit Error Mode 1
; bit position masks
mSCI0ACR2_BKDFE:    equ    %00000001
mSCI0ACR2_BERRM0:   equ    %00000010
mSCI0ACR2_BERRM1:   equ    %00000100


;*** SCI0CR1 - SCI 0 Control Register 1; 0x000000CA ***
SCI0CR1:            equ    $000000CA                                ;*** SCI0CR1 - SCI 0 Control Register 1; 0x000000CA ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI0CR1_PT:         equ    0                                         ; Parity Type Bit
SCI0CR1_PE:         equ    1                                         ; Parity Enable Bit
SCI0CR1_ILT:        equ    2                                         ; Idle Line Type Bit
SCI0CR1_WAKE:       equ    3                                         ; Wakeup Condition Bit
SCI0CR1_M:          equ    4                                         ; Data Format Mode Bit
SCI0CR1_RSRC:       equ    5                                         ; Receiver Source Bit
SCI0CR1_SCISWAI:    equ    6                                         ; SCI Stop in Wait Mode Bit
SCI0CR1_LOOPS:      equ    7                                         ; Loop Select Bit
; bit position masks
mSCI0CR1_PT:        equ    %00000001
mSCI0CR1_PE:        equ    %00000010
mSCI0CR1_ILT:       equ    %00000100
mSCI0CR1_WAKE:      equ    %00001000
mSCI0CR1_M:         equ    %00010000
mSCI0CR1_RSRC:      equ    %00100000
mSCI0CR1_SCISWAI:   equ    %01000000
mSCI0CR1_LOOPS:     equ    %10000000


;*** SCI0CR2 - SCI 0 Control Register 2; 0x000000CB ***
SCI0CR2:            equ    $000000CB                                ;*** SCI0CR2 - SCI 0 Control Register 2; 0x000000CB ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI0CR2_SBK:        equ    0                                         ; Send Break Bit
SCI0CR2_RWU:        equ    1                                         ; Receiver Wakeup Bit
SCI0CR2_RE:         equ    2                                         ; Receiver Enable Bit
SCI0CR2_TE:         equ    3                                         ; Transmitter Enable Bit
SCI0CR2_ILIE:       equ    4                                         ; Idle Line Interrupt Enable Bit
SCI0CR2_RIE:        equ    5                                         ; Receiver Full Interrupt Enable Bit
SCI0CR2_TCIE:       equ    6                                         ; Transmission Complete Interrupt Enable Bit
SCI0CR2_TIE:        equ    7                                         ; Transmitter Interrupt Enable Bit
; bit position masks
mSCI0CR2_SBK:       equ    %00000001
mSCI0CR2_RWU:       equ    %00000010
mSCI0CR2_RE:        equ    %00000100
mSCI0CR2_TE:        equ    %00001000
mSCI0CR2_ILIE:      equ    %00010000
mSCI0CR2_RIE:       equ    %00100000
mSCI0CR2_TCIE:      equ    %01000000
mSCI0CR2_TIE:       equ    %10000000


;*** SCI0SR1 - SCI 0 Status Register 1; 0x000000CC ***
SCI0SR1:            equ    $000000CC                                ;*** SCI0SR1 - SCI 0 Status Register 1; 0x000000CC ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI0SR1_PF:         equ    0                                         ; Parity Error Flag
SCI0SR1_FE:         equ    1                                         ; Framing Error Flag
SCI0SR1_NF:         equ    2                                         ; Noise Flag
SCI0SR1_OR:         equ    3                                         ; Overrun Flag
SCI0SR1_IDLE:       equ    4                                         ; Idle Line Flag
SCI0SR1_RDRF:       equ    5                                         ; Receive Data Register Full Flag
SCI0SR1_TC:         equ    6                                         ; Transmit Complete Flag
SCI0SR1_TDRE:       equ    7                                         ; Transmit Data Register Empty Flag
; bit position masks
mSCI0SR1_PF:        equ    %00000001
mSCI0SR1_FE:        equ    %00000010
mSCI0SR1_NF:        equ    %00000100
mSCI0SR1_OR:        equ    %00001000
mSCI0SR1_IDLE:      equ    %00010000
mSCI0SR1_RDRF:      equ    %00100000
mSCI0SR1_TC:        equ    %01000000
mSCI0SR1_TDRE:      equ    %10000000


;*** SCI0SR2 - SCI 0 Status Register 2; 0x000000CD ***
SCI0SR2:            equ    $000000CD                                ;*** SCI0SR2 - SCI 0 Status Register 2; 0x000000CD ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI0SR2_RAF:        equ    0                                         ; Receiver Active Flag
SCI0SR2_TXDIR:      equ    1                                         ; Transmitter pin data direction in Single-Wire mode
SCI0SR2_BRK13:      equ    2                                         ; Break Transmit character length
SCI0SR2_RXPOL:      equ    3                                         ; Receive Polarity
SCI0SR2_TXPOL:      equ    4                                         ; Transmit Polarity
SCI0SR2_AMAP:       equ    7                                         ; Alternative Map
; bit position masks
mSCI0SR2_RAF:       equ    %00000001
mSCI0SR2_TXDIR:     equ    %00000010
mSCI0SR2_BRK13:     equ    %00000100
mSCI0SR2_RXPOL:     equ    %00001000
mSCI0SR2_TXPOL:     equ    %00010000
mSCI0SR2_AMAP:      equ    %10000000


;*** SCI0DRH - SCI 0 Data Register High; 0x000000CE ***
SCI0DRH:            equ    $000000CE                                ;*** SCI0DRH - SCI 0 Data Register High; 0x000000CE ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI0DRH_T8:         equ    6                                         ; Transmit Bit 8
SCI0DRH_R8:         equ    7                                         ; Received Bit 8
; bit position masks
mSCI0DRH_T8:        equ    %01000000
mSCI0DRH_R8:        equ    %10000000


;*** SCI0DRL - SCI 0 Data Register Low; 0x000000CF ***
SCI0DRL:            equ    $000000CF                                ;*** SCI0DRL - SCI 0 Data Register Low; 0x000000CF ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI0DRL_R0_T0:      equ    0                                         ; Received bit 0 or Transmit bit 0
SCI0DRL_R1_T1:      equ    1                                         ; Received bit 1 or Transmit bit 1
SCI0DRL_R2_T2:      equ    2                                         ; Received bit 2 or Transmit bit 2
SCI0DRL_R3_T3:      equ    3                                         ; Received bit 3 or Transmit bit 3
SCI0DRL_R4_T4:      equ    4                                         ; Received bit 4 or Transmit bit 4
SCI0DRL_R5_T5:      equ    5                                         ; Received bit 5 or Transmit bit 5
SCI0DRL_R6_T6:      equ    6                                         ; Received bit 6 or Transmit bit 6
SCI0DRL_R7_T7:      equ    7                                         ; Received bit 7 or Transmit bit 7
; bit position masks
mSCI0DRL_R0_T0:     equ    %00000001
mSCI0DRL_R1_T1:     equ    %00000010
mSCI0DRL_R2_T2:     equ    %00000100
mSCI0DRL_R3_T3:     equ    %00001000
mSCI0DRL_R4_T4:     equ    %00010000
mSCI0DRL_R5_T5:     equ    %00100000
mSCI0DRL_R6_T6:     equ    %01000000
mSCI0DRL_R7_T7:     equ    %10000000


;*** SCI1BD - SCI 1 Baud Rate Register; 0x000000D0 ***
SCI1BD:             equ    $000000D0                                ;*** SCI1BD - SCI 1 Baud Rate Register; 0x000000D0 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI1BD_SBR0:        equ    0                                         ; SCI Baud Rate Bit 0
SCI1BD_SBR1:        equ    1                                         ; SCI Baud Rate Bit 1
SCI1BD_SBR2:        equ    2                                         ; SCI Baud Rate Bit 2
SCI1BD_SBR3:        equ    3                                         ; SCI Baud Rate Bit 3
SCI1BD_SBR4:        equ    4                                         ; SCI Baud Rate Bit 4
SCI1BD_SBR5:        equ    5                                         ; SCI Baud Rate Bit 5
SCI1BD_SBR6:        equ    6                                         ; SCI Baud Rate Bit 6
SCI1BD_SBR7:        equ    7                                         ; SCI Baud Rate Bit 7
SCI1BD_SBR8:        equ    8                                         ; SCI Baud Rate Bit 8
SCI1BD_SBR9:        equ    9                                         ; SCI Baud Rate Bit 9
SCI1BD_SBR10:       equ    10                                        ; SCI Baud Rate Bit 10
SCI1BD_SBR11:       equ    11                                        ; SCI Baud Rate Bit 11
SCI1BD_SBR12:       equ    12                                        ; SCI Baud Rate Bit 12
SCI1BD_TNP0:        equ    13                                        ; Transmitter Narrow Pulse Bit 0
SCI1BD_TNP1:        equ    14                                        ; Transmitter Narrow Pulse Bit 1
SCI1BD_IREN:        equ    15                                        ; Infrared Enable Bit
; bit position masks
mSCI1BD_SBR0:       equ    %00000001
mSCI1BD_SBR1:       equ    %00000010
mSCI1BD_SBR2:       equ    %00000100
mSCI1BD_SBR3:       equ    %00001000
mSCI1BD_SBR4:       equ    %00010000
mSCI1BD_SBR5:       equ    %00100000
mSCI1BD_SBR6:       equ    %01000000
mSCI1BD_SBR7:       equ    %10000000
mSCI1BD_SBR8:       equ    %100000000
mSCI1BD_SBR9:       equ    %1000000000
mSCI1BD_SBR10:      equ    %10000000000
mSCI1BD_SBR11:      equ    %100000000000
mSCI1BD_SBR12:      equ    %1000000000000
mSCI1BD_TNP0:       equ    %10000000000000
mSCI1BD_TNP1:       equ    %100000000000000
mSCI1BD_IREN:       equ    %1000000000000000


;*** SCI1ASR1 - SCI 1 Alternative Status Register 1; 0x000000D0 ***
SCI1ASR1:           equ    $000000D0                                ;*** SCI1ASR1 - SCI 1 Alternative Status Register 1; 0x000000D0 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI1ASR1_BKDIF:     equ    0                                         ; Break Detect Interrupt Flag
SCI1ASR1_BERRIF:    equ    1                                         ; Bit Error Interrupt Flag
SCI1ASR1_BERRV:     equ    2                                         ; Bit Error Value
SCI1ASR1_RXEDGIF:   equ    7                                         ; Receive Input Active Edge Interrupt Flag
; bit position masks
mSCI1ASR1_BKDIF:    equ    %00000001
mSCI1ASR1_BERRIF:   equ    %00000010
mSCI1ASR1_BERRV:    equ    %00000100
mSCI1ASR1_RXEDGIF:  equ    %10000000


;*** SCI1BDH - SCI 1 Baud Rate Register High; 0x000000D0 ***
SCI1BDH:            equ    $000000D0                                ;*** SCI1BDH - SCI 1 Baud Rate Register High; 0x000000D0 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI1BDH_SBR8:       equ    0                                         ; SCI Baud Rate Bit 8
SCI1BDH_SBR9:       equ    1                                         ; SCI Baud Rate Bit 9
SCI1BDH_SBR10:      equ    2                                         ; SCI Baud Rate Bit 10
SCI1BDH_SBR11:      equ    3                                         ; SCI Baud Rate Bit 11
SCI1BDH_SBR12:      equ    4                                         ; SCI Baud Rate Bit 12
SCI1BDH_TNP0:       equ    5                                         ; Transmitter Narrow Pulse Bit 0
SCI1BDH_TNP1:       equ    6                                         ; Transmitter Narrow Pulse Bit 1
SCI1BDH_IREN:       equ    7                                         ; Infrared Enable Bit
; bit position masks
mSCI1BDH_SBR8:      equ    %00000001
mSCI1BDH_SBR9:      equ    %00000010
mSCI1BDH_SBR10:     equ    %00000100
mSCI1BDH_SBR11:     equ    %00001000
mSCI1BDH_SBR12:     equ    %00010000
mSCI1BDH_TNP0:      equ    %00100000
mSCI1BDH_TNP1:      equ    %01000000
mSCI1BDH_IREN:      equ    %10000000


;*** SCI1ACR1 - SCI 1 Alternative Control Register 1; 0x000000D1 ***
SCI1ACR1:           equ    $000000D1                                ;*** SCI1ACR1 - SCI 1 Alternative Control Register 1; 0x000000D1 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI1ACR1_BKDIE:     equ    0                                         ; Break Detect Interrupt Enable
SCI1ACR1_BERRIE:    equ    1                                         ; Bit Error Interrupt Enable
SCI1ACR1_RXEDGIE:   equ    7                                         ; Receive Input Active Edge Interrupt Enable
; bit position masks
mSCI1ACR1_BKDIE:    equ    %00000001
mSCI1ACR1_BERRIE:   equ    %00000010
mSCI1ACR1_RXEDGIE:  equ    %10000000


;*** SCI1BDL - SCI 1 Baud Rate Register Low; 0x000000D1 ***
SCI1BDL:            equ    $000000D1                                ;*** SCI1BDL - SCI 1 Baud Rate Register Low; 0x000000D1 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI1BDL_SBR0:       equ    0                                         ; SCI Baud Rate Bit 0
SCI1BDL_SBR1:       equ    1                                         ; SCI Baud Rate Bit 1
SCI1BDL_SBR2:       equ    2                                         ; SCI Baud Rate Bit 2
SCI1BDL_SBR3:       equ    3                                         ; SCI Baud Rate Bit 3
SCI1BDL_SBR4:       equ    4                                         ; SCI Baud Rate Bit 4
SCI1BDL_SBR5:       equ    5                                         ; SCI Baud Rate Bit 5
SCI1BDL_SBR6:       equ    6                                         ; SCI Baud Rate Bit 6
SCI1BDL_SBR7:       equ    7                                         ; SCI Baud Rate Bit 7
; bit position masks
mSCI1BDL_SBR0:      equ    %00000001
mSCI1BDL_SBR1:      equ    %00000010
mSCI1BDL_SBR2:      equ    %00000100
mSCI1BDL_SBR3:      equ    %00001000
mSCI1BDL_SBR4:      equ    %00010000
mSCI1BDL_SBR5:      equ    %00100000
mSCI1BDL_SBR6:      equ    %01000000
mSCI1BDL_SBR7:      equ    %10000000


;*** SCI1ACR2 - SCI 1 Alternative Control Register 2; 0x000000D2 ***
SCI1ACR2:           equ    $000000D2                                ;*** SCI1ACR2 - SCI 1 Alternative Control Register 2; 0x000000D2 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI1ACR2_BKDFE:     equ    0                                         ; Break Detect Feature Enable
SCI1ACR2_BERRM0:    equ    1                                         ; Bit Error Mode 0
SCI1ACR2_BERRM1:    equ    2                                         ; Bit Error Mode 1
; bit position masks
mSCI1ACR2_BKDFE:    equ    %00000001
mSCI1ACR2_BERRM0:   equ    %00000010
mSCI1ACR2_BERRM1:   equ    %00000100


;*** SCI1CR1 - SCI 1 Control Register 1; 0x000000D2 ***
SCI1CR1:            equ    $000000D2                                ;*** SCI1CR1 - SCI 1 Control Register 1; 0x000000D2 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI1CR1_PT:         equ    0                                         ; Parity Type Bit
SCI1CR1_PE:         equ    1                                         ; Parity Enable Bit
SCI1CR1_ILT:        equ    2                                         ; Idle Line Type Bit
SCI1CR1_WAKE:       equ    3                                         ; Wakeup Condition Bit
SCI1CR1_M:          equ    4                                         ; Data Format Mode Bit
SCI1CR1_RSRC:       equ    5                                         ; Receiver Source Bit
SCI1CR1_SCISWAI:    equ    6                                         ; SCI Stop in Wait Mode Bit
SCI1CR1_LOOPS:      equ    7                                         ; Loop Select Bit
; bit position masks
mSCI1CR1_PT:        equ    %00000001
mSCI1CR1_PE:        equ    %00000010
mSCI1CR1_ILT:       equ    %00000100
mSCI1CR1_WAKE:      equ    %00001000
mSCI1CR1_M:         equ    %00010000
mSCI1CR1_RSRC:      equ    %00100000
mSCI1CR1_SCISWAI:   equ    %01000000
mSCI1CR1_LOOPS:     equ    %10000000


;*** SCI1CR2 - SCI 1 Control Register 2; 0x000000D3 ***
SCI1CR2:            equ    $000000D3                                ;*** SCI1CR2 - SCI 1 Control Register 2; 0x000000D3 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI1CR2_SBK:        equ    0                                         ; Send Break Bit
SCI1CR2_RWU:        equ    1                                         ; Receiver Wakeup Bit
SCI1CR2_RE:         equ    2                                         ; Receiver Enable Bit
SCI1CR2_TE:         equ    3                                         ; Transmitter Enable Bit
SCI1CR2_ILIE:       equ    4                                         ; Idle Line Interrupt Enable Bit
SCI1CR2_RIE:        equ    5                                         ; Receiver Full Interrupt Enable Bit
SCI1CR2_TCIE:       equ    6                                         ; Transmission Complete Interrupt Enable Bit
SCI1CR2_TIE:        equ    7                                         ; Transmitter Interrupt Enable Bit
; bit position masks
mSCI1CR2_SBK:       equ    %00000001
mSCI1CR2_RWU:       equ    %00000010
mSCI1CR2_RE:        equ    %00000100
mSCI1CR2_TE:        equ    %00001000
mSCI1CR2_ILIE:      equ    %00010000
mSCI1CR2_RIE:       equ    %00100000
mSCI1CR2_TCIE:      equ    %01000000
mSCI1CR2_TIE:       equ    %10000000


;*** SCI1SR1 - SCI 1 Status Register 1; 0x000000D4 ***
SCI1SR1:            equ    $000000D4                                ;*** SCI1SR1 - SCI 1 Status Register 1; 0x000000D4 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI1SR1_PF:         equ    0                                         ; Parity Error Flag
SCI1SR1_FE:         equ    1                                         ; Framing Error Flag
SCI1SR1_NF:         equ    2                                         ; Noise Flag
SCI1SR1_OR:         equ    3                                         ; Overrun Flag
SCI1SR1_IDLE:       equ    4                                         ; Idle Line Flag
SCI1SR1_RDRF:       equ    5                                         ; Receive Data Register Full Flag
SCI1SR1_TC:         equ    6                                         ; Transmit Complete Flag
SCI1SR1_TDRE:       equ    7                                         ; Transmit Data Register Empty Flag
; bit position masks
mSCI1SR1_PF:        equ    %00000001
mSCI1SR1_FE:        equ    %00000010
mSCI1SR1_NF:        equ    %00000100
mSCI1SR1_OR:        equ    %00001000
mSCI1SR1_IDLE:      equ    %00010000
mSCI1SR1_RDRF:      equ    %00100000
mSCI1SR1_TC:        equ    %01000000
mSCI1SR1_TDRE:      equ    %10000000


;*** SCI1SR2 - SCI 1 Status Register 2; 0x000000D5 ***
SCI1SR2:            equ    $000000D5                                ;*** SCI1SR2 - SCI 1 Status Register 2; 0x000000D5 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI1SR2_RAF:        equ    0                                         ; Receiver Active Flag
SCI1SR2_TXDIR:      equ    1                                         ; Transmitter pin data direction in Single-Wire mode
SCI1SR2_BRK13:      equ    2                                         ; Break Transmit character length
SCI1SR2_RXPOL:      equ    3                                         ; Receive Polarity
SCI1SR2_TXPOL:      equ    4                                         ; Transmit Polarity
SCI1SR2_AMAP:       equ    7                                         ; Alternative Map
; bit position masks
mSCI1SR2_RAF:       equ    %00000001
mSCI1SR2_TXDIR:     equ    %00000010
mSCI1SR2_BRK13:     equ    %00000100
mSCI1SR2_RXPOL:     equ    %00001000
mSCI1SR2_TXPOL:     equ    %00010000
mSCI1SR2_AMAP:      equ    %10000000


;*** SCI1DRH - SCI 1 Data Register High; 0x000000D6 ***
SCI1DRH:            equ    $000000D6                                ;*** SCI1DRH - SCI 1 Data Register High; 0x000000D6 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI1DRH_T8:         equ    6                                         ; Transmit Bit 8
SCI1DRH_R8:         equ    7                                         ; Received Bit 8
; bit position masks
mSCI1DRH_T8:        equ    %01000000
mSCI1DRH_R8:        equ    %10000000


;*** SCI1DRL - SCI 1 Data Register Low; 0x000000D7 ***
SCI1DRL:            equ    $000000D7                                ;*** SCI1DRL - SCI 1 Data Register Low; 0x000000D7 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI1DRL_R0_T0:      equ    0                                         ; Received bit 0 or Transmit bit 0
SCI1DRL_R1_T1:      equ    1                                         ; Received bit 1 or Transmit bit 1
SCI1DRL_R2_T2:      equ    2                                         ; Received bit 2 or Transmit bit 2
SCI1DRL_R3_T3:      equ    3                                         ; Received bit 3 or Transmit bit 3
SCI1DRL_R4_T4:      equ    4                                         ; Received bit 4 or Transmit bit 4
SCI1DRL_R5_T5:      equ    5                                         ; Received bit 5 or Transmit bit 5
SCI1DRL_R6_T6:      equ    6                                         ; Received bit 6 or Transmit bit 6
SCI1DRL_R7_T7:      equ    7                                         ; Received bit 7 or Transmit bit 7
; bit position masks
mSCI1DRL_R0_T0:     equ    %00000001
mSCI1DRL_R1_T1:     equ    %00000010
mSCI1DRL_R2_T2:     equ    %00000100
mSCI1DRL_R3_T3:     equ    %00001000
mSCI1DRL_R4_T4:     equ    %00010000
mSCI1DRL_R5_T5:     equ    %00100000
mSCI1DRL_R6_T6:     equ    %01000000
mSCI1DRL_R7_T7:     equ    %10000000


;*** SPI0CR1 - SPI 0 Control Register 1; 0x000000D8 ***
SPI0CR1:            equ    $000000D8                                ;*** SPI0CR1 - SPI 0 Control Register 1; 0x000000D8 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPI0CR1_LSBFE:      equ    0                                         ; SPI LSB-First Enable
SPI0CR1_SSOE:       equ    1                                         ; Slave Select Output Enable
SPI0CR1_CPHA:       equ    2                                         ; SPI Clock Phase Bit
SPI0CR1_CPOL:       equ    3                                         ; SPI Clock Polarity Bit
SPI0CR1_MSTR:       equ    4                                         ; SPI Master/Slave Mode Select Bit
SPI0CR1_SPTIE:      equ    5                                         ; SPI Transmit Interrupt Enable
SPI0CR1_SPE:        equ    6                                         ; SPI System Enable Bit
SPI0CR1_SPIE:       equ    7                                         ; SPI Interrupt Enable Bit
; bit position masks
mSPI0CR1_LSBFE:     equ    %00000001
mSPI0CR1_SSOE:      equ    %00000010
mSPI0CR1_CPHA:      equ    %00000100
mSPI0CR1_CPOL:      equ    %00001000
mSPI0CR1_MSTR:      equ    %00010000
mSPI0CR1_SPTIE:     equ    %00100000
mSPI0CR1_SPE:       equ    %01000000
mSPI0CR1_SPIE:      equ    %10000000


;*** SPI0CR2 - SPI 0 Control Register 2; 0x000000D9 ***
SPI0CR2:            equ    $000000D9                                ;*** SPI0CR2 - SPI 0 Control Register 2; 0x000000D9 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPI0CR2_SPC0:       equ    0                                         ; Serial Pin Control Bit 0
SPI0CR2_SPISWAI:    equ    1                                         ; SPI Stop in Wait Mode Bit
SPI0CR2_BIDIROE:    equ    3                                         ; Output enable in the Bidirectional mode of operation
SPI0CR2_MODFEN:     equ    4                                         ; Mode Fault Enable Bit
SPI0CR2_XFRW:       equ    6                                         ; Transfer Width
; bit position masks
mSPI0CR2_SPC0:      equ    %00000001
mSPI0CR2_SPISWAI:   equ    %00000010
mSPI0CR2_BIDIROE:   equ    %00001000
mSPI0CR2_MODFEN:    equ    %00010000
mSPI0CR2_XFRW:      equ    %01000000


;*** SPI0BR - SPI 0 Baud Rate Register; 0x000000DA ***
SPI0BR:             equ    $000000DA                                ;*** SPI0BR - SPI 0 Baud Rate Register; 0x000000DA ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPI0BR_SPR0:        equ    0                                         ; SPI Baud Rate Selection Bit 0
SPI0BR_SPR1:        equ    1                                         ; SPI Baud Rate Selection Bit 1
SPI0BR_SPR2:        equ    2                                         ; SPI Baud Rate Selection Bit 2
SPI0BR_SPPR0:       equ    4                                         ; SPI Baud Rate Preselection Bits 0
SPI0BR_SPPR1:       equ    5                                         ; SPI Baud Rate Preselection Bits 1
SPI0BR_SPPR2:       equ    6                                         ; SPI Baud Rate Preselection Bits 2
; bit position masks
mSPI0BR_SPR0:       equ    %00000001
mSPI0BR_SPR1:       equ    %00000010
mSPI0BR_SPR2:       equ    %00000100
mSPI0BR_SPPR0:      equ    %00010000
mSPI0BR_SPPR1:      equ    %00100000
mSPI0BR_SPPR2:      equ    %01000000


;*** SPI0SR - SPI 0 Status Register; 0x000000DB ***
SPI0SR:             equ    $000000DB                                ;*** SPI0SR - SPI 0 Status Register; 0x000000DB ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPI0SR_MODF:        equ    4                                         ; Mode Fault Flag
SPI0SR_SPTEF:       equ    5                                         ; SPI Transmit Empty Interrupt Flag
SPI0SR_SPIF:        equ    7                                         ; SPIF Receive Interrupt Flag
; bit position masks
mSPI0SR_MODF:       equ    %00010000
mSPI0SR_SPTEF:      equ    %00100000
mSPI0SR_SPIF:       equ    %10000000


;*** SPI0DR - SPI 0 Data Register; 0x000000DC ***
SPI0DR:             equ    $000000DC                                ;*** SPI0DR - SPI 0 Data Register; 0x000000DC ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPI0DR_R0_T0:       equ    0                                         ; SPI 0 Data Bit 0
SPI0DR_R1_T1:       equ    1                                         ; SPI 0 Data Bit 1
SPI0DR_R2_T2:       equ    2                                         ; SPI 0 Data Bit 2
SPI0DR_R3_T3:       equ    3                                         ; SPI 0 Data Bit 3
SPI0DR_R4_T4:       equ    4                                         ; SPI 0 Data Bit 4
SPI0DR_R5_T5:       equ    5                                         ; SPI 0 Data Bit 5
SPI0DR_R6_T6:       equ    6                                         ; SPI 0 Data Bit 6
SPI0DR_R7_T7:       equ    7                                         ; SPI 0 Data Bit 7
SPI0DR_R8_T8:       equ    8                                         ; SPI 0 Data Bit 8
SPI0DR_R9_T9:       equ    9                                         ; SPI 0 Data Bit 9
SPI0DR_R10_T10:     equ    10                                        ; SPI 0 Data Bit 10
SPI0DR_R11_T11:     equ    11                                        ; SPI 0 Data Bit 11
SPI0DR_R12_T12:     equ    12                                        ; SPI 0 Data Bit 12
SPI0DR_R13_T13:     equ    13                                        ; SPI 0 Data Bit 13
SPI0DR_R14_T14:     equ    14                                        ; SPI 0 Data Bit 14
SPI0DR_R15_T15:     equ    15                                        ; SPI 0 Data Bit 15
; bit position masks
mSPI0DR_R0_T0:      equ    %00000001
mSPI0DR_R1_T1:      equ    %00000010
mSPI0DR_R2_T2:      equ    %00000100
mSPI0DR_R3_T3:      equ    %00001000
mSPI0DR_R4_T4:      equ    %00010000
mSPI0DR_R5_T5:      equ    %00100000
mSPI0DR_R6_T6:      equ    %01000000
mSPI0DR_R7_T7:      equ    %10000000
mSPI0DR_R8_T8:      equ    %100000000
mSPI0DR_R9_T9:      equ    %1000000000
mSPI0DR_R10_T10:    equ    %10000000000
mSPI0DR_R11_T11:    equ    %100000000000
mSPI0DR_R12_T12:    equ    %1000000000000
mSPI0DR_R13_T13:    equ    %10000000000000
mSPI0DR_R14_T14:    equ    %100000000000000
mSPI0DR_R15_T15:    equ    %1000000000000000


;*** SPI0DRH - SPI 0 Data Register High; 0x000000DC ***
SPI0DRH:            equ    $000000DC                                ;*** SPI0DRH - SPI 0 Data Register High; 0x000000DC ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPI0DRH_R8_T8:      equ    0                                         ; SPI 0 Data Bit 8
SPI0DRH_R9_T9:      equ    1                                         ; SPI 0 Data Bit 9
SPI0DRH_R10_T10:    equ    2                                         ; SPI 0 Data Bit 10
SPI0DRH_R11_T11:    equ    3                                         ; SPI 0 Data Bit 11
SPI0DRH_R12_T12:    equ    4                                         ; SPI 0 Data Bit 12
SPI0DRH_R13_T13:    equ    5                                         ; SPI 0 Data Bit 13
SPI0DRH_R14_T14:    equ    6                                         ; SPI 0 Data Bit 14
SPI0DRH_R15_T15:    equ    7                                         ; SPI 0 Data Bit 15
; bit position masks
mSPI0DRH_R8_T8:     equ    %00000001
mSPI0DRH_R9_T9:     equ    %00000010
mSPI0DRH_R10_T10:   equ    %00000100
mSPI0DRH_R11_T11:   equ    %00001000
mSPI0DRH_R12_T12:   equ    %00010000
mSPI0DRH_R13_T13:   equ    %00100000
mSPI0DRH_R14_T14:   equ    %01000000
mSPI0DRH_R15_T15:   equ    %10000000


;*** SPI0DRL - SPI 0 Data Register Low; 0x000000DD ***
SPI0DRL:            equ    $000000DD                                ;*** SPI0DRL - SPI 0 Data Register Low; 0x000000DD ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPI0DRL_R0_T0:      equ    0                                         ; SPI 0 Data Bit 0
SPI0DRL_R1_T1:      equ    1                                         ; SPI 0 Data Bit 1
SPI0DRL_R2_T2:      equ    2                                         ; SPI 0 Data Bit 2
SPI0DRL_R3_T3:      equ    3                                         ; SPI 0 Data Bit 3
SPI0DRL_R4_T4:      equ    4                                         ; SPI 0 Data Bit 4
SPI0DRL_R5_T5:      equ    5                                         ; SPI 0 Data Bit 5
SPI0DRL_R6_T6:      equ    6                                         ; SPI 0 Data Bit 6
SPI0DRL_R7_T7:      equ    7                                         ; SPI 0 Data Bit 7
; bit position masks
mSPI0DRL_R0_T0:     equ    %00000001
mSPI0DRL_R1_T1:     equ    %00000010
mSPI0DRL_R2_T2:     equ    %00000100
mSPI0DRL_R3_T3:     equ    %00001000
mSPI0DRL_R4_T4:     equ    %00010000
mSPI0DRL_R5_T5:     equ    %00100000
mSPI0DRL_R6_T6:     equ    %01000000
mSPI0DRL_R7_T7:     equ    %10000000


;*** FCLKDIV - Flash Clock Divider Register; 0x00000100 ***
FCLKDIV:            equ    $00000100                                ;*** FCLKDIV - Flash Clock Divider Register; 0x00000100 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FCLKDIV_FDIV0:      equ    0                                         ; Clock Divider Bit 0
FCLKDIV_FDIV1:      equ    1                                         ; Clock Divider Bit 1
FCLKDIV_FDIV2:      equ    2                                         ; Clock Divider Bit 2
FCLKDIV_FDIV3:      equ    3                                         ; Clock Divider Bit 3
FCLKDIV_FDIV4:      equ    4                                         ; Clock Divider Bit 4
FCLKDIV_FDIV5:      equ    5                                         ; Clock Divider Bit 5
FCLKDIV_FDIV6:      equ    6                                         ; Clock Divider Bit 6
FCLKDIV_FDIVLD:     equ    7                                         ; Clock Divider Loaded
; bit position masks
mFCLKDIV_FDIV0:     equ    %00000001
mFCLKDIV_FDIV1:     equ    %00000010
mFCLKDIV_FDIV2:     equ    %00000100
mFCLKDIV_FDIV3:     equ    %00001000
mFCLKDIV_FDIV4:     equ    %00010000
mFCLKDIV_FDIV5:     equ    %00100000
mFCLKDIV_FDIV6:     equ    %01000000
mFCLKDIV_FDIVLD:    equ    %10000000


;*** FSEC - Flash Security Register; 0x00000101 ***
FSEC:               equ    $00000101                                ;*** FSEC - Flash Security Register; 0x00000101 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FSEC_SEC0:          equ    0                                         ; Flash Security Bit 0
FSEC_SEC1:          equ    1                                         ; Flash Security Bit 1
FSEC_RNV2:          equ    2                                         ; Reserved Nonvolatile Bit 2
FSEC_RNV3:          equ    3                                         ; Reserved Nonvolatile Bit 3
FSEC_RNV4:          equ    4                                         ; Reserved Nonvolatile Bit 4
FSEC_RNV5:          equ    5                                         ; Reserved Nonvolatile Bit 5
FSEC_KEYEN0:        equ    6                                         ; Backdoor Key Security Enable Bit 0
FSEC_KEYEN1:        equ    7                                         ; Backdoor Key Security Enable Bit 1
; bit position masks
mFSEC_SEC0:         equ    %00000001
mFSEC_SEC1:         equ    %00000010
mFSEC_RNV2:         equ    %00000100
mFSEC_RNV3:         equ    %00001000
mFSEC_RNV4:         equ    %00010000
mFSEC_RNV5:         equ    %00100000
mFSEC_KEYEN0:       equ    %01000000
mFSEC_KEYEN1:       equ    %10000000


;*** FCCOBIX - Flash CCOB Index Register; 0x00000102 ***
FCCOBIX:            equ    $00000102                                ;*** FCCOBIX - Flash CCOB Index Register; 0x00000102 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FCCOBIX_CCOBIX0:    equ    0                                         ; Common Command Register Index Bit 0
FCCOBIX_CCOBIX1:    equ    1                                         ; Common Command Register Index Bit 1
FCCOBIX_CCOBIX2:    equ    2                                         ; Common Command Register Index Bit 2
; bit position masks
mFCCOBIX_CCOBIX0:   equ    %00000001
mFCCOBIX_CCOBIX1:   equ    %00000010
mFCCOBIX_CCOBIX2:   equ    %00000100


;*** FECCRIX - Flash ECCR Index Register; 0x00000103 ***
FECCRIX:            equ    $00000103                                ;*** FECCRIX - Flash ECCR Index Register; 0x00000103 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FECCRIX_ECCRIX0:    equ    0                                         ; ECC Error Register Index Bit 0
FECCRIX_ECCRIX1:    equ    1                                         ; ECC Error Register Index Bit 1
FECCRIX_ECCRIX2:    equ    2                                         ; ECC Error Register Index Bit 2
; bit position masks
mFECCRIX_ECCRIX0:   equ    %00000001
mFECCRIX_ECCRIX1:   equ    %00000010
mFECCRIX_ECCRIX2:   equ    %00000100


;*** FCNFG - Flash Configuration Register; 0x00000104 ***
FCNFG:              equ    $00000104                                ;*** FCNFG - Flash Configuration Register; 0x00000104 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FCNFG_FSFD:         equ    0                                         ; Force Single Bit Fault Detect
FCNFG_FDFD:         equ    1                                         ; Force Double Bit Fault Detect
FCNFG_IGNSF:        equ    4                                         ; Ignore Single Bit Fault
FCNFG_CCIE:         equ    7                                         ; Command Complete Interrupt Enable
; bit position masks
mFCNFG_FSFD:        equ    %00000001
mFCNFG_FDFD:        equ    %00000010
mFCNFG_IGNSF:       equ    %00010000
mFCNFG_CCIE:        equ    %10000000


;*** FERCNFG - Flash Error Configuration Register; 0x00000105 ***
FERCNFG:            equ    $00000105                                ;*** FERCNFG - Flash Error Configuration Register; 0x00000105 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FERCNFG_SFDIE:      equ    0                                         ; Single Bit Fault Detect Interrupt Enable
FERCNFG_DFDIE:      equ    1                                         ; Double Bit Fault Detect Interrupt Enable
; bit position masks
mFERCNFG_SFDIE:     equ    %00000001
mFERCNFG_DFDIE:     equ    %00000010


;*** FSTAT - Flash Status Register; 0x00000106 ***
FSTAT:              equ    $00000106                                ;*** FSTAT - Flash Status Register; 0x00000106 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FSTAT_MGSTAT0:      equ    0                                         ; Memory Controller Command Completion Status Flag 0
FSTAT_MGSTAT1:      equ    1                                         ; Memory Controller Command Completion Status Flag 1
FSTAT_MGBUSY:       equ    3                                         ; Memory Controller Busy Flag
FSTAT_FPVIOL:       equ    4                                         ; Flash Protection Violation Flag
FSTAT_ACCERR:       equ    5                                         ; Flash Access Error Flag
FSTAT_CCIF:         equ    7                                         ; Command Complete Interrupt Flag
; bit position masks
mFSTAT_MGSTAT0:     equ    %00000001
mFSTAT_MGSTAT1:     equ    %00000010
mFSTAT_MGBUSY:      equ    %00001000
mFSTAT_FPVIOL:      equ    %00010000
mFSTAT_ACCERR:      equ    %00100000
mFSTAT_CCIF:        equ    %10000000


;*** FERSTAT - Flash Error Status Register; 0x00000107 ***
FERSTAT:            equ    $00000107                                ;*** FERSTAT - Flash Error Status Register; 0x00000107 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FERSTAT_SFDIF:      equ    0                                         ; Single Bit Fault Detect Interrupt Flag
FERSTAT_DFDIF:      equ    1                                         ; Double Bit Fault Detect Interrupt Flag
; bit position masks
mFERSTAT_SFDIF:     equ    %00000001
mFERSTAT_DFDIF:     equ    %00000010


;*** FPROT - P-Flash Protection Register; 0x00000108 ***
FPROT:              equ    $00000108                                ;*** FPROT - P-Flash Protection Register; 0x00000108 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FPROT_FPLS0:        equ    0                                         ; Flash Protection Lower Address Size Bit 0
FPROT_FPLS1:        equ    1                                         ; Flash Protection Lower Address Size Bit 1
FPROT_FPLDIS:       equ    2                                         ; Flash Protection Lower Address Range Disable
FPROT_FPHS0:        equ    3                                         ; Flash Protection Higher Address Size Bit 0
FPROT_FPHS1:        equ    4                                         ; Flash Protection Higher Address Size Bit 1
FPROT_FPHDIS:       equ    5                                         ; Flash Protection Higher Address Range Disable
FPROT_RNV6:         equ    6                                         ; Reserved Nonvolatile Bit
FPROT_FPOPEN:       equ    7                                         ; Flash Protection Operation Enable
; bit position masks
mFPROT_FPLS0:       equ    %00000001
mFPROT_FPLS1:       equ    %00000010
mFPROT_FPLDIS:      equ    %00000100
mFPROT_FPHS0:       equ    %00001000
mFPROT_FPHS1:       equ    %00010000
mFPROT_FPHDIS:      equ    %00100000
mFPROT_RNV6:        equ    %01000000
mFPROT_FPOPEN:      equ    %10000000


;*** DFPROT - D-Flash Protection Register; 0x00000109 ***
DFPROT:             equ    $00000109                                ;*** DFPROT - D-Flash Protection Register; 0x00000109 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DFPROT_DPS0:        equ    0                                         ; D-Flash Protection Size Bit 0
DFPROT_DPS1:        equ    1                                         ; D-Flash Protection Size Bit 1
DFPROT_DPS2:        equ    2                                         ; D-Flash Protection Size Bit 2
DFPROT_DPS3:        equ    3                                         ; D-Flash Protection Size Bit 3
DFPROT_DPS4:        equ    4                                         ; D-Flash Protection Size Bit 4
DFPROT_DPOPEN:      equ    7                                         ; D-Flash Protection Control
; bit position masks
mDFPROT_DPS0:       equ    %00000001
mDFPROT_DPS1:       equ    %00000010
mDFPROT_DPS2:       equ    %00000100
mDFPROT_DPS3:       equ    %00001000
mDFPROT_DPS4:       equ    %00010000
mDFPROT_DPOPEN:     equ    %10000000


;*** FCCOB - Flash Common Command Object Register; 0x0000010A ***
FCCOB:              equ    $0000010A                                ;*** FCCOB - Flash Common Command Object Register; 0x0000010A ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FCCOB_CCOB0:        equ    0                                         ; Flash Common Command Object Bit 0
FCCOB_CCOB1:        equ    1                                         ; Flash Common Command Object Bit 1
FCCOB_CCOB2:        equ    2                                         ; Flash Common Command Object Bit 2
FCCOB_CCOB3:        equ    3                                         ; Flash Common Command Object Bit 3
FCCOB_CCOB4:        equ    4                                         ; Flash Common Command Object Bit 4
FCCOB_CCOB5:        equ    5                                         ; Flash Common Command Object Bit 5
FCCOB_CCOB6:        equ    6                                         ; Flash Common Command Object Bit 6
FCCOB_CCOB7:        equ    7                                         ; Flash Common Command Object Bit 7
FCCOB_CCOB8:        equ    8                                         ; Flash Common Command Object Bit 8
FCCOB_CCOB9:        equ    9                                         ; Flash Common Command Object Bit 9
FCCOB_CCOB10:       equ    10                                        ; Flash Common Command Object Bit 10
FCCOB_CCOB11:       equ    11                                        ; Flash Common Command Object Bit 11
FCCOB_CCOB12:       equ    12                                        ; Flash Common Command Object Bit 12
FCCOB_CCOB13:       equ    13                                        ; Flash Common Command Object Bit 13
FCCOB_CCOB14:       equ    14                                        ; Flash Common Command Object Bit 14
FCCOB_CCOB15:       equ    15                                        ; Flash Common Command Object Bit 15
; bit position masks
mFCCOB_CCOB0:       equ    %00000001
mFCCOB_CCOB1:       equ    %00000010
mFCCOB_CCOB2:       equ    %00000100
mFCCOB_CCOB3:       equ    %00001000
mFCCOB_CCOB4:       equ    %00010000
mFCCOB_CCOB5:       equ    %00100000
mFCCOB_CCOB6:       equ    %01000000
mFCCOB_CCOB7:       equ    %10000000
mFCCOB_CCOB8:       equ    %100000000
mFCCOB_CCOB9:       equ    %1000000000
mFCCOB_CCOB10:      equ    %10000000000
mFCCOB_CCOB11:      equ    %100000000000
mFCCOB_CCOB12:      equ    %1000000000000
mFCCOB_CCOB13:      equ    %10000000000000
mFCCOB_CCOB14:      equ    %100000000000000
mFCCOB_CCOB15:      equ    %1000000000000000


;*** FCCOBHI - Flash Common Command Object Register High; 0x0000010A ***
FCCOBHI:            equ    $0000010A                                ;*** FCCOBHI - Flash Common Command Object Register High; 0x0000010A ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FCCOBHI_CCOB8:      equ    0                                         ; Flash Common Command Object Bit 8
FCCOBHI_CCOB9:      equ    1                                         ; Flash Common Command Object Bit 9
FCCOBHI_CCOB10:     equ    2                                         ; Flash Common Command Object Bit 10
FCCOBHI_CCOB11:     equ    3                                         ; Flash Common Command Object Bit 11
FCCOBHI_CCOB12:     equ    4                                         ; Flash Common Command Object Bit 12
FCCOBHI_CCOB13:     equ    5                                         ; Flash Common Command Object Bit 13
FCCOBHI_CCOB14:     equ    6                                         ; Flash Common Command Object Bit 14
FCCOBHI_CCOB15:     equ    7                                         ; Flash Common Command Object Bit 15
; bit position masks
mFCCOBHI_CCOB8:     equ    %00000001
mFCCOBHI_CCOB9:     equ    %00000010
mFCCOBHI_CCOB10:    equ    %00000100
mFCCOBHI_CCOB11:    equ    %00001000
mFCCOBHI_CCOB12:    equ    %00010000
mFCCOBHI_CCOB13:    equ    %00100000
mFCCOBHI_CCOB14:    equ    %01000000
mFCCOBHI_CCOB15:    equ    %10000000


;*** FCCOBLO - Flash Common Command Object Register Low; 0x0000010B ***
FCCOBLO:            equ    $0000010B                                ;*** FCCOBLO - Flash Common Command Object Register Low; 0x0000010B ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FCCOBLO_CCOB0:      equ    0                                         ; Flash Common Command Object Bit 0
FCCOBLO_CCOB1:      equ    1                                         ; Flash Common Command Object Bit 1
FCCOBLO_CCOB2:      equ    2                                         ; Flash Common Command Object Bit 2
FCCOBLO_CCOB3:      equ    3                                         ; Flash Common Command Object Bit 3
FCCOBLO_CCOB4:      equ    4                                         ; Flash Common Command Object Bit 4
FCCOBLO_CCOB5:      equ    5                                         ; Flash Common Command Object Bit 5
FCCOBLO_CCOB6:      equ    6                                         ; Flash Common Command Object Bit 6
FCCOBLO_CCOB7:      equ    7                                         ; Flash Common Command Object Bit 7
; bit position masks
mFCCOBLO_CCOB0:     equ    %00000001
mFCCOBLO_CCOB1:     equ    %00000010
mFCCOBLO_CCOB2:     equ    %00000100
mFCCOBLO_CCOB3:     equ    %00001000
mFCCOBLO_CCOB4:     equ    %00010000
mFCCOBLO_CCOB5:     equ    %00100000
mFCCOBLO_CCOB6:     equ    %01000000
mFCCOBLO_CCOB7:     equ    %10000000


;*** FECCR - Flash ECC Error Results Register; 0x0000010E ***
FECCR:              equ    $0000010E                                ;*** FECCR - Flash ECC Error Results Register; 0x0000010E ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FECCR_ECCR0:        equ    0                                         ; Flash ECC Error Result Bit 0
FECCR_ECCR1:        equ    1                                         ; Flash ECC Error Result Bit 1
FECCR_ECCR2:        equ    2                                         ; Flash ECC Error Result Bit 2
FECCR_ECCR3:        equ    3                                         ; Flash ECC Error Result Bit 3
FECCR_ECCR4:        equ    4                                         ; Flash ECC Error Result Bit 4
FECCR_ECCR5:        equ    5                                         ; Flash ECC Error Result Bit 5
FECCR_ECCR6:        equ    6                                         ; Flash ECC Error Result Bit 6
FECCR_ECCR7:        equ    7                                         ; Flash ECC Error Result Bit 7
FECCR_ECCR8:        equ    8                                         ; Flash ECC Error Result Bit 8
FECCR_ECCR9:        equ    9                                         ; Flash ECC Error Result Bit 9
FECCR_ECCR10:       equ    10                                        ; Flash ECC Error Result Bit 10
FECCR_ECCR11:       equ    11                                        ; Flash ECC Error Result Bit 11
FECCR_ECCR12:       equ    12                                        ; Flash ECC Error Result Bit 12
FECCR_ECCR13:       equ    13                                        ; Flash ECC Error Result Bit 13
FECCR_ECCR14:       equ    14                                        ; Flash ECC Error Result Bit 14
FECCR_ECCR15:       equ    15                                        ; Flash ECC Error Result Bit 15
; bit position masks
mFECCR_ECCR0:       equ    %00000001
mFECCR_ECCR1:       equ    %00000010
mFECCR_ECCR2:       equ    %00000100
mFECCR_ECCR3:       equ    %00001000
mFECCR_ECCR4:       equ    %00010000
mFECCR_ECCR5:       equ    %00100000
mFECCR_ECCR6:       equ    %01000000
mFECCR_ECCR7:       equ    %10000000
mFECCR_ECCR8:       equ    %100000000
mFECCR_ECCR9:       equ    %1000000000
mFECCR_ECCR10:      equ    %10000000000
mFECCR_ECCR11:      equ    %100000000000
mFECCR_ECCR12:      equ    %1000000000000
mFECCR_ECCR13:      equ    %10000000000000
mFECCR_ECCR14:      equ    %100000000000000
mFECCR_ECCR15:      equ    %1000000000000000


;*** FECCRHI - Flash ECC Error Results Register High; 0x0000010E ***
FECCRHI:            equ    $0000010E                                ;*** FECCRHI - Flash ECC Error Results Register High; 0x0000010E ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FECCRHI_ECCR8:      equ    0                                         ; Flash ECC Error Result Bit 8
FECCRHI_ECCR9:      equ    1                                         ; Flash ECC Error Result Bit 9
FECCRHI_ECCR10:     equ    2                                         ; Flash ECC Error Result Bit 10
FECCRHI_ECCR11:     equ    3                                         ; Flash ECC Error Result Bit 11
FECCRHI_ECCR12:     equ    4                                         ; Flash ECC Error Result Bit 12
FECCRHI_ECCR13:     equ    5                                         ; Flash ECC Error Result Bit 13
FECCRHI_ECCR14:     equ    6                                         ; Flash ECC Error Result Bit 14
FECCRHI_ECCR15:     equ    7                                         ; Flash ECC Error Result Bit 15
; bit position masks
mFECCRHI_ECCR8:     equ    %00000001
mFECCRHI_ECCR9:     equ    %00000010
mFECCRHI_ECCR10:    equ    %00000100
mFECCRHI_ECCR11:    equ    %00001000
mFECCRHI_ECCR12:    equ    %00010000
mFECCRHI_ECCR13:    equ    %00100000
mFECCRHI_ECCR14:    equ    %01000000
mFECCRHI_ECCR15:    equ    %10000000


;*** FECCRLO - Flash ECC Error Results Register Low; 0x0000010F ***
FECCRLO:            equ    $0000010F                                ;*** FECCRLO - Flash ECC Error Results Register Low; 0x0000010F ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FECCRLO_ECCR0:      equ    0                                         ; Flash ECC Error Result Bit 0
FECCRLO_ECCR1:      equ    1                                         ; Flash ECC Error Result Bit 1
FECCRLO_ECCR2:      equ    2                                         ; Flash ECC Error Result Bit 2
FECCRLO_ECCR3:      equ    3                                         ; Flash ECC Error Result Bit 3
FECCRLO_ECCR4:      equ    4                                         ; Flash ECC Error Result Bit 4
FECCRLO_ECCR5:      equ    5                                         ; Flash ECC Error Result Bit 5
FECCRLO_ECCR6:      equ    6                                         ; Flash ECC Error Result Bit 6
FECCRLO_ECCR7:      equ    7                                         ; Flash ECC Error Result Bit 7
; bit position masks
mFECCRLO_ECCR0:     equ    %00000001
mFECCRLO_ECCR1:     equ    %00000010
mFECCRLO_ECCR2:     equ    %00000100
mFECCRLO_ECCR3:     equ    %00001000
mFECCRLO_ECCR4:     equ    %00010000
mFECCRLO_ECCR5:     equ    %00100000
mFECCRLO_ECCR6:     equ    %01000000
mFECCRLO_ECCR7:     equ    %10000000


;*** FOPT - Flash Option Register; 0x00000110 ***
FOPT:               equ    $00000110                                ;*** FOPT - Flash Option Register; 0x00000110 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FOPT_NV0:           equ    0                                         ; Nonvolatile Bit 0
FOPT_NV1:           equ    1                                         ; Nonvolatile Bit 1
FOPT_NV2:           equ    2                                         ; Nonvolatile Bit 2
FOPT_NV3:           equ    3                                         ; Nonvolatile Bit 3
FOPT_NV4:           equ    4                                         ; Nonvolatile Bit 4
FOPT_NV5:           equ    5                                         ; Nonvolatile Bit 5
FOPT_NV6:           equ    6                                         ; Nonvolatile Bit 6
FOPT_NV7:           equ    7                                         ; Nonvolatile Bit 7
; bit position masks
mFOPT_NV0:          equ    %00000001
mFOPT_NV1:          equ    %00000010
mFOPT_NV2:          equ    %00000100
mFOPT_NV3:          equ    %00001000
mFOPT_NV4:          equ    %00010000
mFOPT_NV5:          equ    %00100000
mFOPT_NV6:          equ    %01000000
mFOPT_NV7:          equ    %10000000


;*** IVBR - Interrupt Vector Base Register; 0x00000121 ***
IVBR:               equ    $00000121                                ;*** IVBR - Interrupt Vector Base Register; 0x00000121 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IVBR_IVB_ADDR:      equ    0                                         ; Interrupt Vector Base Address Bits
; bit position masks
mIVBR_IVB_ADDR:     equ    %11111111


;*** INT_XGPRIO - XGATE Interrupt Priority Configuration Register; 0x00000126 ***
INT_XGPRIO:         equ    $00000126                                ;*** INT_XGPRIO - XGATE Interrupt Priority Configuration Register; 0x00000126 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
INT_XGPRIO_XILVL:   equ    0                                         ; XGATE Interrupt Priority Level
; bit position masks
mINT_XGPRIO_XILVL:  equ    %00000111


;*** INT_CFADDR - Interrupt Request Configuration Address Register; 0x00000127 ***
INT_CFADDR:         equ    $00000127                                ;*** INT_CFADDR - Interrupt Request Configuration Address Register; 0x00000127 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
INT_CFADDR_INT_CFADDR: equ    4                                      ; Interrupt Request Configuration Data Register Select Bits
; bit position masks
mINT_CFADDR_INT_CFADDR: equ    %11110000


;*** INT_CFDATA0 - Interrupt Request Configuration Data Register 0; 0x00000128 ***
INT_CFDATA0:        equ    $00000128                                ;*** INT_CFDATA0 - Interrupt Request Configuration Data Register 0; 0x00000128 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
INT_CFDATA0_PRIOLVL: equ    0                                        ; Interrupt Request Priority Level Bits
INT_CFDATA0_RQST:   equ    7                                         ; XGATE Request Enable
; bit position masks
mINT_CFDATA0_PRIOLVL: equ    %00000111
mINT_CFDATA0_RQST:  equ    %10000000


;*** INT_CFDATA1 - Interrupt Request Configuration Data Register 1; 0x00000129 ***
INT_CFDATA1:        equ    $00000129                                ;*** INT_CFDATA1 - Interrupt Request Configuration Data Register 1; 0x00000129 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
INT_CFDATA1_PRIOLVL: equ    0                                        ; Interrupt Request Priority Level Bits
INT_CFDATA1_RQST:   equ    7                                         ; XGATE Request Enable
; bit position masks
mINT_CFDATA1_PRIOLVL: equ    %00000111
mINT_CFDATA1_RQST:  equ    %10000000


;*** INT_CFDATA2 - Interrupt Request Configuration Data Register 2; 0x0000012A ***
INT_CFDATA2:        equ    $0000012A                                ;*** INT_CFDATA2 - Interrupt Request Configuration Data Register 2; 0x0000012A ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
INT_CFDATA2_PRIOLVL: equ    0                                        ; Interrupt Request Priority Level Bits
INT_CFDATA2_RQST:   equ    7                                         ; XGATE Request Enable
; bit position masks
mINT_CFDATA2_PRIOLVL: equ    %00000111
mINT_CFDATA2_RQST:  equ    %10000000


;*** INT_CFDATA3 - Interrupt Request Configuration Data Register 3; 0x0000012B ***
INT_CFDATA3:        equ    $0000012B                                ;*** INT_CFDATA3 - Interrupt Request Configuration Data Register 3; 0x0000012B ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
INT_CFDATA3_PRIOLVL: equ    0                                        ; Interrupt Request Priority Level Bits
INT_CFDATA3_RQST:   equ    7                                         ; XGATE Request Enable
; bit position masks
mINT_CFDATA3_PRIOLVL: equ    %00000111
mINT_CFDATA3_RQST:  equ    %10000000


;*** INT_CFDATA4 - Interrupt Request Configuration Data Register 4; 0x0000012C ***
INT_CFDATA4:        equ    $0000012C                                ;*** INT_CFDATA4 - Interrupt Request Configuration Data Register 4; 0x0000012C ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
INT_CFDATA4_PRIOLVL: equ    0                                        ; Interrupt Request Priority Level Bits
INT_CFDATA4_RQST:   equ    7                                         ; XGATE Request Enable
; bit position masks
mINT_CFDATA4_PRIOLVL: equ    %00000111
mINT_CFDATA4_RQST:  equ    %10000000


;*** INT_CFDATA5 - Interrupt Request Configuration Data Register 5; 0x0000012D ***
INT_CFDATA5:        equ    $0000012D                                ;*** INT_CFDATA5 - Interrupt Request Configuration Data Register 5; 0x0000012D ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
INT_CFDATA5_PRIOLVL: equ    0                                        ; Interrupt Request Priority Level Bits
INT_CFDATA5_RQST:   equ    7                                         ; XGATE Request Enable
; bit position masks
mINT_CFDATA5_PRIOLVL: equ    %00000111
mINT_CFDATA5_RQST:  equ    %10000000


;*** INT_CFDATA6 - Interrupt Request Configuration Data Register 6; 0x0000012E ***
INT_CFDATA6:        equ    $0000012E                                ;*** INT_CFDATA6 - Interrupt Request Configuration Data Register 6; 0x0000012E ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
INT_CFDATA6_PRIOLVL: equ    0                                        ; Interrupt Request Priority Level Bits
INT_CFDATA6_RQST:   equ    7                                         ; XGATE Request Enable
; bit position masks
mINT_CFDATA6_PRIOLVL: equ    %00000111
mINT_CFDATA6_RQST:  equ    %10000000


;*** INT_CFDATA7 - Interrupt Request Configuration Data Register 7; 0x0000012F ***
INT_CFDATA7:        equ    $0000012F                                ;*** INT_CFDATA7 - Interrupt Request Configuration Data Register 7; 0x0000012F ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
INT_CFDATA7_PRIOLVL: equ    0                                        ; Interrupt Request Priority Level Bits
INT_CFDATA7_RQST:   equ    7                                         ; XGATE Request Enable
; bit position masks
mINT_CFDATA7_PRIOLVL: equ    %00000111
mINT_CFDATA7_RQST:  equ    %10000000


;*** CAN0CTL0 - MSCAN0 Control 0 Register; 0x00000140 ***
CAN0CTL0:           equ    $00000140                                ;*** CAN0CTL0 - MSCAN0 Control 0 Register; 0x00000140 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CAN0CTL0_INITRQ:    equ    0                                         ; Initialization Mode Request
CAN0CTL0_SLPRQ:     equ    1                                         ; Sleep Mode Request
CAN0CTL0_WUPE:      equ    2                                         ; Wake-Up Enable
CAN0CTL0_TIME:      equ    3                                         ; Timer Enable
CAN0CTL0_SYNCH:     equ    4                                         ; Synchronized Status
CAN0CTL0_CSWAI:     equ    5                                         ; CAN Stops in Wait Mode
CAN0CTL0_RXACT:     equ    6                                         ; Receiver Active Status
CAN0CTL0_RXFRM:     equ    7                                         ; Received Frame Flag
; bit position masks
mCAN0CTL0_INITRQ:   equ    %00000001
mCAN0CTL0_SLPRQ:    equ    %00000010
mCAN0CTL0_WUPE:     equ    %00000100
mCAN0CTL0_TIME:     equ    %00001000
mCAN0CTL0_SYNCH:    equ    %00010000
mCAN0CTL0_CSWAI:    equ    %00100000
mCAN0CTL0_RXACT:    equ    %01000000
mCAN0CTL0_RXFRM:    equ    %10000000


;*** CAN0CTL1 - MSCAN0 Control 1 Register; 0x00000141 ***
CAN0CTL1:           equ    $00000141                                ;*** CAN0CTL1 - MSCAN0 Control 1 Register; 0x00000141 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CAN0CTL1_INITAK:    equ    0                                         ; Initialization Mode Acknowledge
CAN0CTL1_SLPAK:     equ    1                                         ; Sleep Mode Acknowledge
CAN0CTL1_WUPM:      equ    2                                         ; Wake-Up Mode
CAN0CTL1_BORM:      equ    3                                         ; Bus-Off Recovery Mode
CAN0CTL1_LISTEN:    equ    4                                         ; Listen Only Mode
CAN0CTL1_LOOPB:     equ    5                                         ; Loop Back Self Test Mode
CAN0CTL1_CLKSRC:    equ    6                                         ; MSCAN Clock Source
CAN0CTL1_CANE:      equ    7                                         ; MSCAN Enable
; bit position masks
mCAN0CTL1_INITAK:   equ    %00000001
mCAN0CTL1_SLPAK:    equ    %00000010
mCAN0CTL1_WUPM:     equ    %00000100
mCAN0CTL1_BORM:     equ    %00001000
mCAN0CTL1_LISTEN:   equ    %00010000
mCAN0CTL1_LOOPB:    equ    %00100000
mCAN0CTL1_CLKSRC:   equ    %01000000
mCAN0CTL1_CANE:     equ    %10000000


;*** CAN0BTR0 - MSCAN0 Bus Timing Register 0; 0x00000142 ***
CAN0BTR0:           equ    $00000142                                ;*** CAN0BTR0 - MSCAN0 Bus Timing Register 0; 0x00000142 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CAN0BTR0_BRP0:      equ    0                                         ; Baud Rate Prescaler 0
CAN0BTR0_BRP1:      equ    1                                         ; Baud Rate Prescaler 1
CAN0BTR0_BRP2:      equ    2                                         ; Baud Rate Prescaler 2
CAN0BTR0_BRP3:      equ    3                                         ; Baud Rate Prescaler 3
CAN0BTR0_BRP4:      equ    4                                         ; Baud Rate Prescaler 4
CAN0BTR0_BRP5:      equ    5                                         ; Baud Rate Prescaler 5
CAN0BTR0_SJW0:      equ    6                                         ; Synchronization Jump Width 0
CAN0BTR0_SJW1:      equ    7                                         ; Synchronization Jump Width 1
; bit position masks
mCAN0BTR0_BRP0:     equ    %00000001
mCAN0BTR0_BRP1:     equ    %00000010
mCAN0BTR0_BRP2:     equ    %00000100
mCAN0BTR0_BRP3:     equ    %00001000
mCAN0BTR0_BRP4:     equ    %00010000
mCAN0BTR0_BRP5:     equ    %00100000
mCAN0BTR0_SJW0:     equ    %01000000
mCAN0BTR0_SJW1:     equ    %10000000


;*** CAN0BTR1 - MSCAN0 Bus Timing Register 1; 0x00000143 ***
CAN0BTR1:           equ    $00000143                                ;*** CAN0BTR1 - MSCAN0 Bus Timing Register 1; 0x00000143 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CAN0BTR1_TSEG10:    equ    0                                         ; Time Segment 10
CAN0BTR1_TSEG11:    equ    1                                         ; Time Segment 11
CAN0BTR1_TSEG12:    equ    2                                         ; Time Segment 12
CAN0BTR1_TSEG13:    equ    3                                         ; Time Segment 13
CAN0BTR1_TSEG20:    equ    4                                         ; Time Segment 20
CAN0BTR1_TSEG21:    equ    5                                         ; Time Segment 21
CAN0BTR1_TSEG22:    equ    6                                         ; Time Segment 22
CAN0BTR1_SAMP:      equ    7                                         ; Sampling
; bit position masks
mCAN0BTR1_TSEG10:   equ    %00000001
mCAN0BTR1_TSEG11:   equ    %00000010
mCAN0BTR1_TSEG12:   equ    %00000100
mCAN0BTR1_TSEG13:   equ    %00001000
mCAN0BTR1_TSEG20:   equ    %00010000
mCAN0BTR1_TSEG21:   equ    %00100000
mCAN0BTR1_TSEG22:   equ    %01000000
mCAN0BTR1_SAMP:     equ    %10000000


;*** CAN0RFLG - MSCAN0 Receiver Flag Register; 0x00000144 ***
CAN0RFLG:           equ    $00000144                                ;*** CAN0RFLG - MSCAN0 Receiver Flag Register; 0x00000144 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CAN0RFLG_RXF:       equ    0                                         ; Receive Buffer Full
CAN0RFLG_OVRIF:     equ    1                                         ; Overrun Interrupt Flag
CAN0RFLG_TSTAT0:    equ    2                                         ; Transmitter Status Bit 0
CAN0RFLG_TSTAT1:    equ    3                                         ; Transmitter Status Bit 1
CAN0RFLG_RSTAT0:    equ    4                                         ; Receiver Status Bit 0
CAN0RFLG_RSTAT1:    equ    5                                         ; Receiver Status Bit 1
CAN0RFLG_CSCIF:     equ    6                                         ; CAN Status Change Interrupt Flag
CAN0RFLG_WUPIF:     equ    7                                         ; Wake-up Interrupt Flag
; bit position masks
mCAN0RFLG_RXF:      equ    %00000001
mCAN0RFLG_OVRIF:    equ    %00000010
mCAN0RFLG_TSTAT0:   equ    %00000100
mCAN0RFLG_TSTAT1:   equ    %00001000
mCAN0RFLG_RSTAT0:   equ    %00010000
mCAN0RFLG_RSTAT1:   equ    %00100000
mCAN0RFLG_CSCIF:    equ    %01000000
mCAN0RFLG_WUPIF:    equ    %10000000


;*** CAN0RIER - MSCAN0 Receiver Interrupt Enable Register; 0x00000145 ***
CAN0RIER:           equ    $00000145                                ;*** CAN0RIER - MSCAN0 Receiver Interrupt Enable Register; 0x00000145 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CAN0RIER_RXFIE:     equ    0                                         ; Receiver Full Interrupt Enable
CAN0RIER_OVRIE:     equ    1                                         ; Overrun Interrupt Enable
CAN0RIER_TSTATE0:   equ    2                                         ; Transmitter Status Change Enable 0
CAN0RIER_TSTATE1:   equ    3                                         ; Transmitter Status Change Enable 1
CAN0RIER_RSTATE0:   equ    4                                         ; Receiver Status Change Enable 0
CAN0RIER_RSTATE1:   equ    5                                         ; Receiver Status Change Enable 1
CAN0RIER_CSCIE:     equ    6                                         ; CAN Status Change Interrupt Enable
CAN0RIER_WUPIE:     equ    7                                         ; Wake-up Interrupt Enable
; bit position masks
mCAN0RIER_RXFIE:    equ    %00000001
mCAN0RIER_OVRIE:    equ    %00000010
mCAN0RIER_TSTATE0:  equ    %00000100
mCAN0RIER_TSTATE1:  equ    %00001000
mCAN0RIER_RSTATE0:  equ    %00010000
mCAN0RIER_RSTATE1:  equ    %00100000
mCAN0RIER_CSCIE:    equ    %01000000
mCAN0RIER_WUPIE:    equ    %10000000


;*** CAN0TFLG - MSCAN0 Transmitter Flag Register; 0x00000146 ***
CAN0TFLG:           equ    $00000146                                ;*** CAN0TFLG - MSCAN0 Transmitter Flag Register; 0x00000146 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CAN0TFLG_TXE0:      equ    0                                         ; Transmitter Buffer Empty 0
CAN0TFLG_TXE1:      equ    1                                         ; Transmitter Buffer Empty 1
CAN0TFLG_TXE2:      equ    2                                         ; Transmitter Buffer Empty 2
; bit position masks
mCAN0TFLG_TXE0:     equ    %00000001
mCAN0TFLG_TXE1:     equ    %00000010
mCAN0TFLG_TXE2:     equ    %00000100


;*** CAN0TIER - MSCAN0 Transmitter Interrupt Enable Register; 0x00000147 ***
CAN0TIER:           equ    $00000147                                ;*** CAN0TIER - MSCAN0 Transmitter Interrupt Enable Register; 0x00000147 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CAN0TIER_TXEIE0:    equ    0                                         ; Transmitter Empty Interrupt Enable 0
CAN0TIER_TXEIE1:    equ    1                                         ; Transmitter Empty Interrupt Enable 1
CAN0TIER_TXEIE2:    equ    2                                         ; Transmitter Empty Interrupt Enable 2
; bit position masks
mCAN0TIER_TXEIE0:   equ    %00000001
mCAN0TIER_TXEIE1:   equ    %00000010
mCAN0TIER_TXEIE2:   equ    %00000100


;*** CAN0TARQ - MSCAN0 Transmitter Message Abort Request; 0x00000148 ***
CAN0TARQ:           equ    $00000148                                ;*** CAN0TARQ - MSCAN0 Transmitter Message Abort Request; 0x00000148 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CAN0TARQ_ABTRQ0:    equ    0                                         ; Abort Request 0
CAN0TARQ_ABTRQ1:    equ    1                                         ; Abort Request 1
CAN0TARQ_ABTRQ2:    equ    2                                         ; Abort Request 2
; bit position masks
mCAN0TARQ_ABTRQ0:   equ    %00000001
mCAN0TARQ_ABTRQ1:   equ    %00000010
mCAN0TARQ_ABTRQ2:   equ    %00000100


;*** CAN0TAAK - MSCAN0 Transmitter Message Abort Acknowledge; 0x00000149 ***
CAN0TAAK:           equ    $00000149                                ;*** CAN0TAAK - MSCAN0 Transmitter Message Abort Acknowledge; 0x00000149 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CAN0TAAK_ABTAK0:    equ    0                                         ; Abort Acknowledge 0
CAN0TAAK_ABTAK1:    equ    1                                         ; Abort Acknowledge 1
CAN0TAAK_ABTAK2:    equ    2                                         ; Abort Acknowledge 2
; bit position masks
mCAN0TAAK_ABTAK0:   equ    %00000001
mCAN0TAAK_ABTAK1:   equ    %00000010
mCAN0TAAK_ABTAK2:   equ    %00000100


;*** CAN0TBSEL - MSCAN0 Transmit Buffer Selection; 0x0000014A ***
CAN0TBSEL:          equ    $0000014A                                ;*** CAN0TBSEL - MSCAN0 Transmit Buffer Selection; 0x0000014A ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CAN0TBSEL_TX0:      equ    0                                         ; Transmit Buffer Select 0
CAN0TBSEL_TX1:      equ    1                                         ; Transmit Buffer Select 1
CAN0TBSEL_TX2:      equ    2                                         ; Transmit Buffer Select 2
; bit position masks
mCAN0TBSEL_TX0:     equ    %00000001
mCAN0TBSEL_TX1:     equ    %00000010
mCAN0TBSEL_TX2:     equ    %00000100


;*** CAN0IDAC - MSCAN0 Identifier Acceptance Control Register; 0x0000014B ***
CAN0IDAC:           equ    $0000014B                                ;*** CAN0IDAC - MSCAN0 Identifier Acceptance Control Register; 0x0000014B ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CAN0IDAC_IDHIT0:    equ    0                                         ; Identifier Acceptance Hit Indicator 0
CAN0IDAC_IDHIT1:    equ    1                                         ; Identifier Acceptance Hit Indicator 1
CAN0IDAC_IDHIT2:    equ    2                                         ; Identifier Acceptance Hit Indicator 2
CAN0IDAC_IDAM0:     equ    4                                         ; Identifier Acceptance Mode 0
CAN0IDAC_IDAM1:     equ    5                                         ; Identifier Acceptance Mode 1
; bit position masks
mCAN0IDAC_IDHIT0:   equ    %00000001
mCAN0IDAC_IDHIT1:   equ    %00000010
mCAN0IDAC_IDHIT2:   equ    %00000100
mCAN0IDAC_IDAM0:    equ    %00010000
mCAN0IDAC_IDAM1:    equ    %00100000


;*** CAN0MISC - MSCAN0 Miscellaneous Register; 0x0000014D ***
CAN0MISC:           equ    $0000014D                                ;*** CAN0MISC - MSCAN0 Miscellaneous Register; 0x0000014D ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CAN0MISC_BOHOLD:    equ    0                                         ; Bus-off State Hold Until User Request
; bit position masks
mCAN0MISC_BOHOLD:   equ    %00000001


;*** CAN0RXERR - MSCAN0 Receive Error Counter Register; 0x0000014E ***
CAN0RXERR:          equ    $0000014E                                ;*** CAN0RXERR - MSCAN0 Receive Error Counter Register; 0x0000014E ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CAN0RXERR_RXERR0:   equ    0                                         ; Bit 0
CAN0RXERR_RXERR1:   equ    1                                         ; Bit 1
CAN0RXERR_RXERR2:   equ    2                                         ; Bit 2
CAN0RXERR_RXERR3:   equ    3                                         ; Bit 3
CAN0RXERR_RXERR4:   equ    4                                         ; Bit 4
CAN0RXERR_RXERR5:   equ    5                                         ; Bit 5
CAN0RXERR_RXERR6:   equ    6                                         ; Bit 6
CAN0RXERR_RXERR7:   equ    7                                         ; Bit 7
; bit position masks
mCAN0RXERR_RXERR0:  equ    %00000001
mCAN0RXERR_RXERR1:  equ    %00000010
mCAN0RXERR_RXERR2:  equ    %00000100
mCAN0RXERR_RXERR3:  equ    %00001000
mCAN0RXERR_RXERR4:  equ    %00010000
mCAN0RXERR_RXERR5:  equ    %00100000
mCAN0RXERR_RXERR6:  equ    %01000000
mCAN0RXERR_RXERR7:  equ    %10000000


;*** CAN0TXERR - MSCAN0 Transmit Error Counter Register; 0x0000014F ***
CAN0TXERR:          equ    $0000014F                                ;*** CAN0TXERR - MSCAN0 Transmit Error Counter Register; 0x0000014F ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CAN0TXERR_TXERR0:   equ    0                                         ; Bit 0
CAN0TXERR_TXERR1:   equ    1                                         ; Bit 1
CAN0TXERR_TXERR2:   equ    2                                         ; Bit 2
CAN0TXERR_TXERR3:   equ    3                                         ; Bit 3
CAN0TXERR_TXERR4:   equ    4                                         ; Bit 4
CAN0TXERR_TXERR5:   equ    5                                         ; Bit 5
CAN0TXERR_TXERR6:   equ    6                                         ; Bit 6
CAN0TXERR_TXERR7:   equ    7                                         ; Bit 7
; bit position masks
mCAN0TXERR_TXERR0:  equ    %00000001
mCAN0TXERR_TXERR1:  equ    %00000010
mCAN0TXERR_TXERR2:  equ    %00000100
mCAN0TXERR_TXERR3:  equ    %00001000
mCAN0TXERR_TXERR4:  equ    %00010000
mCAN0TXERR_TXERR5:  equ    %00100000
mCAN0TXERR_TXERR6:  equ    %01000000
mCAN0TXERR_TXERR7:  equ    %10000000


;*** CAN0IDAR0 - MSCAN0 Identifier Acceptance Register 0; 0x00000150 ***
CAN0IDAR0:          equ    $00000150                                ;*** CAN0IDAR0 - MSCAN0 Identifier Acceptance Register 0; 0x00000150 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CAN0IDAR0_AC0:      equ    0                                         ; Acceptance Code Bit 0
CAN0IDAR0_AC1:      equ    1                                         ; Acceptance Code Bit 1
CAN0IDAR0_AC2:      equ    2                                         ; Acceptance Code Bit 2
CAN0IDAR0_AC3:      equ    3                                         ; Acceptance Code Bit 3
CAN0IDAR0_AC4:      equ    4                                         ; Acceptance Code Bit 4
CAN0IDAR0_AC5:      equ    5                                         ; Acceptance Code Bit 5
CAN0IDAR0_AC6:      equ    6                                         ; Acceptance Code Bit 6
CAN0IDAR0_AC7:      equ    7                                         ; Acceptance Code Bit 7
; bit position masks
mCAN0IDAR0_AC0:     equ    %00000001
mCAN0IDAR0_AC1:     equ    %00000010
mCAN0IDAR0_AC2:     equ    %00000100
mCAN0IDAR0_AC3:     equ    %00001000
mCAN0IDAR0_AC4:     equ    %00010000
mCAN0IDAR0_AC5:     equ    %00100000
mCAN0IDAR0_AC6:     equ    %01000000
mCAN0IDAR0_AC7:     equ    %10000000


;*** CAN0IDAR1 - MSCAN0 Identifier Acceptance Register 1; 0x00000151 ***
CAN0IDAR1:          equ    $00000151                                ;*** CAN0IDAR1 - MSCAN0 Identifier Acceptance Register 1; 0x00000151 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CAN0IDAR1_AC0:      equ    0                                         ; Acceptance Code Bit 0
CAN0IDAR1_AC1:      equ    1                                         ; Acceptance Code Bit 1
CAN0IDAR1_AC2:      equ    2                                         ; Acceptance Code Bit 2
CAN0IDAR1_AC3:      equ    3                                         ; Acceptance Code Bit 3
CAN0IDAR1_AC4:      equ    4                                         ; Acceptance Code Bit 4
CAN0IDAR1_AC5:      equ    5                                         ; Acceptance Code Bit 5
CAN0IDAR1_AC6:      equ    6                                         ; Acceptance Code Bit 6
CAN0IDAR1_AC7:      equ    7                                         ; Acceptance Code Bit 7
; bit position masks
mCAN0IDAR1_AC0:     equ    %00000001
mCAN0IDAR1_AC1:     equ    %00000010
mCAN0IDAR1_AC2:     equ    %00000100
mCAN0IDAR1_AC3:     equ    %00001000
mCAN0IDAR1_AC4:     equ    %00010000
mCAN0IDAR1_AC5:     equ    %00100000
mCAN0IDAR1_AC6:     equ    %01000000
mCAN0IDAR1_AC7:     equ    %10000000


;*** CAN0IDAR2 - MSCAN0 Identifier Acceptance Register 2; 0x00000152 ***
CAN0IDAR2:          equ    $00000152                                ;*** CAN0IDAR2 - MSCAN0 Identifier Acceptance Register 2; 0x00000152 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CAN0IDAR2_AC0:      equ    0                                         ; Acceptance Code Bit 0
CAN0IDAR2_AC1:      equ    1                                         ; Acceptance Code Bit 1
CAN0IDAR2_AC2:      equ    2                                         ; Acceptance Code Bit 2
CAN0IDAR2_AC3:      equ    3                                         ; Acceptance Code Bit 3
CAN0IDAR2_AC4:      equ    4                                         ; Acceptance Code Bit 4
CAN0IDAR2_AC5:      equ    5                                         ; Acceptance Code Bit 5
CAN0IDAR2_AC6:      equ    6                                         ; Acceptance Code Bit 6
CAN0IDAR2_AC7:      equ    7                                         ; Acceptance Code Bit 7
; bit position masks
mCAN0IDAR2_AC0:     equ    %00000001
mCAN0IDAR2_AC1:     equ    %00000010
mCAN0IDAR2_AC2:     equ    %00000100
mCAN0IDAR2_AC3:     equ    %00001000
mCAN0IDAR2_AC4:     equ    %00010000
mCAN0IDAR2_AC5:     equ    %00100000
mCAN0IDAR2_AC6:     equ    %01000000
mCAN0IDAR2_AC7:     equ    %10000000


;*** CAN0IDAR3 - MSCAN0 Identifier Acceptance Register 3; 0x00000153 ***
CAN0IDAR3:          equ    $00000153                                ;*** CAN0IDAR3 - MSCAN0 Identifier Acceptance Register 3; 0x00000153 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CAN0IDAR3_AC0:      equ    0                                         ; Acceptance Code Bit 0
CAN0IDAR3_AC1:      equ    1                                         ; Acceptance Code Bit 1
CAN0IDAR3_AC2:      equ    2                                         ; Acceptance Code Bit 2
CAN0IDAR3_AC3:      equ    3                                         ; Acceptance Code Bit 3
CAN0IDAR3_AC4:      equ    4                                         ; Acceptance Code Bit 4
CAN0IDAR3_AC5:      equ    5                                         ; Acceptance Code Bit 5
CAN0IDAR3_AC6:      equ    6                                         ; Acceptance Code Bit 6
CAN0IDAR3_AC7:      equ    7                                         ; Acceptance Code Bit 7
; bit position masks
mCAN0IDAR3_AC0:     equ    %00000001
mCAN0IDAR3_AC1:     equ    %00000010
mCAN0IDAR3_AC2:     equ    %00000100
mCAN0IDAR3_AC3:     equ    %00001000
mCAN0IDAR3_AC4:     equ    %00010000
mCAN0IDAR3_AC5:     equ    %00100000
mCAN0IDAR3_AC6:     equ    %01000000
mCAN0IDAR3_AC7:     equ    %10000000


;*** CAN0IDMR0 - MSCAN0 Identifier Mask Register 0; 0x00000154 ***
CAN0IDMR0:          equ    $00000154                                ;*** CAN0IDMR0 - MSCAN0 Identifier Mask Register 0; 0x00000154 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CAN0IDMR0_AM0:      equ    0                                         ; Acceptance Mask Bit 0
CAN0IDMR0_AM1:      equ    1                                         ; Acceptance Mask Bit 1
CAN0IDMR0_AM2:      equ    2                                         ; Acceptance Mask Bit 2
CAN0IDMR0_AM3:      equ    3                                         ; Acceptance Mask Bit 3
CAN0IDMR0_AM4:      equ    4                                         ; Acceptance Mask Bit 4
CAN0IDMR0_AM5:      equ    5                                         ; Acceptance Mask Bit 5
CAN0IDMR0_AM6:      equ    6                                         ; Acceptance Mask Bit 6
CAN0IDMR0_AM7:      equ    7                                         ; Acceptance Mask Bit 7
; bit position masks
mCAN0IDMR0_AM0:     equ    %00000001
mCAN0IDMR0_AM1:     equ    %00000010
mCAN0IDMR0_AM2:     equ    %00000100
mCAN0IDMR0_AM3:     equ    %00001000
mCAN0IDMR0_AM4:     equ    %00010000
mCAN0IDMR0_AM5:     equ    %00100000
mCAN0IDMR0_AM6:     equ    %01000000
mCAN0IDMR0_AM7:     equ    %10000000


;*** CAN0IDMR1 - MSCAN0 Identifier Mask Register 1; 0x00000155 ***
CAN0IDMR1:          equ    $00000155                                ;*** CAN0IDMR1 - MSCAN0 Identifier Mask Register 1; 0x00000155 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CAN0IDMR1_AM0:      equ    0                                         ; Acceptance Mask Bit 0
CAN0IDMR1_AM1:      equ    1                                         ; Acceptance Mask Bit 1
CAN0IDMR1_AM2:      equ    2                                         ; Acceptance Mask Bit 2
CAN0IDMR1_AM3:      equ    3                                         ; Acceptance Mask Bit 3
CAN0IDMR1_AM4:      equ    4                                         ; Acceptance Mask Bit 4
CAN0IDMR1_AM5:      equ    5                                         ; Acceptance Mask Bit 5
CAN0IDMR1_AM6:      equ    6                                         ; Acceptance Mask Bit 6
CAN0IDMR1_AM7:      equ    7                                         ; Acceptance Mask Bit 7
; bit position masks
mCAN0IDMR1_AM0:     equ    %00000001
mCAN0IDMR1_AM1:     equ    %00000010
mCAN0IDMR1_AM2:     equ    %00000100
mCAN0IDMR1_AM3:     equ    %00001000
mCAN0IDMR1_AM4:     equ    %00010000
mCAN0IDMR1_AM5:     equ    %00100000
mCAN0IDMR1_AM6:     equ    %01000000
mCAN0IDMR1_AM7:     equ    %10000000


;*** CAN0IDMR2 - MSCAN0 Identifier Mask Register 2; 0x00000156 ***
CAN0IDMR2:          equ    $00000156                                ;*** CAN0IDMR2 - MSCAN0 Identifier Mask Register 2; 0x00000156 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CAN0IDMR2_AM0:      equ    0                                         ; Acceptance Mask Bit 0
CAN0IDMR2_AM1:      equ    1                                         ; Acceptance Mask Bit 1
CAN0IDMR2_AM2:      equ    2                                         ; Acceptance Mask Bit 2
CAN0IDMR2_AM3:      equ    3                                         ; Acceptance Mask Bit 3
CAN0IDMR2_AM4:      equ    4                                         ; Acceptance Mask Bit 4
CAN0IDMR2_AM5:      equ    5                                         ; Acceptance Mask Bit 5
CAN0IDMR2_AM6:      equ    6                                         ; Acceptance Mask Bit 6
CAN0IDMR2_AM7:      equ    7                                         ; Acceptance Mask Bit 7
; bit position masks
mCAN0IDMR2_AM0:     equ    %00000001
mCAN0IDMR2_AM1:     equ    %00000010
mCAN0IDMR2_AM2:     equ    %00000100
mCAN0IDMR2_AM3:     equ    %00001000
mCAN0IDMR2_AM4:     equ    %00010000
mCAN0IDMR2_AM5:     equ    %00100000
mCAN0IDMR2_AM6:     equ    %01000000
mCAN0IDMR2_AM7:     equ    %10000000


;*** CAN0IDMR3 - MSCAN0 Identifier Mask Register 3; 0x00000157 ***
CAN0IDMR3:          equ    $00000157                                ;*** CAN0IDMR3 - MSCAN0 Identifier Mask Register 3; 0x00000157 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CAN0IDMR3_AM0:      equ    0                                         ; Acceptance Mask Bit 0
CAN0IDMR3_AM1:      equ    1                                         ; Acceptance Mask Bit 1
CAN0IDMR3_AM2:      equ    2                                         ; Acceptance Mask Bit 2
CAN0IDMR3_AM3:      equ    3                                         ; Acceptance Mask Bit 3
CAN0IDMR3_AM4:      equ    4                                         ; Acceptance Mask Bit 4
CAN0IDMR3_AM5:      equ    5                                         ; Acceptance Mask Bit 5
CAN0IDMR3_AM6:      equ    6                                         ; Acceptance Mask Bit 6
CAN0IDMR3_AM7:      equ    7                                         ; Acceptance Mask Bit 7
; bit position masks
mCAN0IDMR3_AM0:     equ    %00000001
mCAN0IDMR3_AM1:     equ    %00000010
mCAN0IDMR3_AM2:     equ    %00000100
mCAN0IDMR3_AM3:     equ    %00001000
mCAN0IDMR3_AM4:     equ    %00010000
mCAN0IDMR3_AM5:     equ    %00100000
mCAN0IDMR3_AM6:     equ    %01000000
mCAN0IDMR3_AM7:     equ    %10000000


;*** CAN0IDAR4 - MSCAN0 Identifier Acceptance Register 4; 0x00000158 ***
CAN0IDAR4:          equ    $00000158                                ;*** CAN0IDAR4 - MSCAN0 Identifier Acceptance Register 4; 0x00000158 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CAN0IDAR4_AC0:      equ    0                                         ; Acceptance Code Bit 0
CAN0IDAR4_AC1:      equ    1                                         ; Acceptance Code Bit 1
CAN0IDAR4_AC2:      equ    2                                         ; Acceptance Code Bit 2
CAN0IDAR4_AC3:      equ    3                                         ; Acceptance Code Bit 3
CAN0IDAR4_AC4:      equ    4                                         ; Acceptance Code Bit 4
CAN0IDAR4_AC5:      equ    5                                         ; Acceptance Code Bit 5
CAN0IDAR4_AC6:      equ    6                                         ; Acceptance Code Bit 6
CAN0IDAR4_AC7:      equ    7                                         ; Acceptance Code Bit 7
; bit position masks
mCAN0IDAR4_AC0:     equ    %00000001
mCAN0IDAR4_AC1:     equ    %00000010
mCAN0IDAR4_AC2:     equ    %00000100
mCAN0IDAR4_AC3:     equ    %00001000
mCAN0IDAR4_AC4:     equ    %00010000
mCAN0IDAR4_AC5:     equ    %00100000
mCAN0IDAR4_AC6:     equ    %01000000
mCAN0IDAR4_AC7:     equ    %10000000


;*** CAN0IDAR5 - MSCAN0 Identifier Acceptance Register 5; 0x00000159 ***
CAN0IDAR5:          equ    $00000159                                ;*** CAN0IDAR5 - MSCAN0 Identifier Acceptance Register 5; 0x00000159 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CAN0IDAR5_AC0:      equ    0                                         ; Acceptance Code Bit 0
CAN0IDAR5_AC1:      equ    1                                         ; Acceptance Code Bit 1
CAN0IDAR5_AC2:      equ    2                                         ; Acceptance Code Bit 2
CAN0IDAR5_AC3:      equ    3                                         ; Acceptance Code Bit 3
CAN0IDAR5_AC4:      equ    4                                         ; Acceptance Code Bit 4
CAN0IDAR5_AC5:      equ    5                                         ; Acceptance Code Bit 5
CAN0IDAR5_AC6:      equ    6                                         ; Acceptance Code Bit 6
CAN0IDAR5_AC7:      equ    7                                         ; Acceptance Code Bit 7
; bit position masks
mCAN0IDAR5_AC0:     equ    %00000001
mCAN0IDAR5_AC1:     equ    %00000010
mCAN0IDAR5_AC2:     equ    %00000100
mCAN0IDAR5_AC3:     equ    %00001000
mCAN0IDAR5_AC4:     equ    %00010000
mCAN0IDAR5_AC5:     equ    %00100000
mCAN0IDAR5_AC6:     equ    %01000000
mCAN0IDAR5_AC7:     equ    %10000000


;*** CAN0IDAR6 - MSCAN0 Identifier Acceptance Register 6; 0x0000015A ***
CAN0IDAR6:          equ    $0000015A                                ;*** CAN0IDAR6 - MSCAN0 Identifier Acceptance Register 6; 0x0000015A ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CAN0IDAR6_AC0:      equ    0                                         ; Acceptance Code Bit 0
CAN0IDAR6_AC1:      equ    1                                         ; Acceptance Code Bit 1
CAN0IDAR6_AC2:      equ    2                                         ; Acceptance Code Bit 2
CAN0IDAR6_AC3:      equ    3                                         ; Acceptance Code Bit 3
CAN0IDAR6_AC4:      equ    4                                         ; Acceptance Code Bit 4
CAN0IDAR6_AC5:      equ    5                                         ; Acceptance Code Bit 5
CAN0IDAR6_AC6:      equ    6                                         ; Acceptance Code Bit 6
CAN0IDAR6_AC7:      equ    7                                         ; Acceptance Code Bit 7
; bit position masks
mCAN0IDAR6_AC0:     equ    %00000001
mCAN0IDAR6_AC1:     equ    %00000010
mCAN0IDAR6_AC2:     equ    %00000100
mCAN0IDAR6_AC3:     equ    %00001000
mCAN0IDAR6_AC4:     equ    %00010000
mCAN0IDAR6_AC5:     equ    %00100000
mCAN0IDAR6_AC6:     equ    %01000000
mCAN0IDAR6_AC7:     equ    %10000000


;*** CAN0IDAR7 - MSCAN0 Identifier Acceptance Register 7; 0x0000015B ***
CAN0IDAR7:          equ    $0000015B                                ;*** CAN0IDAR7 - MSCAN0 Identifier Acceptance Register 7; 0x0000015B ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CAN0IDAR7_AC0:      equ    0                                         ; Acceptance Code Bit 0
CAN0IDAR7_AC1:      equ    1                                         ; Acceptance Code Bit 1
CAN0IDAR7_AC2:      equ    2                                         ; Acceptance Code Bit 2
CAN0IDAR7_AC3:      equ    3                                         ; Acceptance Code Bit 3
CAN0IDAR7_AC4:      equ    4                                         ; Acceptance Code Bit 4
CAN0IDAR7_AC5:      equ    5                                         ; Acceptance Code Bit 5
CAN0IDAR7_AC6:      equ    6                                         ; Acceptance Code Bit 6
CAN0IDAR7_AC7:      equ    7                                         ; Acceptance Code Bit 7
; bit position masks
mCAN0IDAR7_AC0:     equ    %00000001
mCAN0IDAR7_AC1:     equ    %00000010
mCAN0IDAR7_AC2:     equ    %00000100
mCAN0IDAR7_AC3:     equ    %00001000
mCAN0IDAR7_AC4:     equ    %00010000
mCAN0IDAR7_AC5:     equ    %00100000
mCAN0IDAR7_AC6:     equ    %01000000
mCAN0IDAR7_AC7:     equ    %10000000


;*** CAN0IDMR4 - MSCAN0 Identifier Mask Register 4; 0x0000015C ***
CAN0IDMR4:          equ    $0000015C                                ;*** CAN0IDMR4 - MSCAN0 Identifier Mask Register 4; 0x0000015C ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CAN0IDMR4_AM0:      equ    0                                         ; Acceptance Mask Bit 0
CAN0IDMR4_AM1:      equ    1                                         ; Acceptance Mask Bit 1
CAN0IDMR4_AM2:      equ    2                                         ; Acceptance Mask Bit 2
CAN0IDMR4_AM3:      equ    3                                         ; Acceptance Mask Bit 3
CAN0IDMR4_AM4:      equ    4                                         ; Acceptance Mask Bit 4
CAN0IDMR4_AM5:      equ    5                                         ; Acceptance Mask Bit 5
CAN0IDMR4_AM6:      equ    6                                         ; Acceptance Mask Bit 6
CAN0IDMR4_AM7:      equ    7                                         ; Acceptance Mask Bit 7
; bit position masks
mCAN0IDMR4_AM0:     equ    %00000001
mCAN0IDMR4_AM1:     equ    %00000010
mCAN0IDMR4_AM2:     equ    %00000100
mCAN0IDMR4_AM3:     equ    %00001000
mCAN0IDMR4_AM4:     equ    %00010000
mCAN0IDMR4_AM5:     equ    %00100000
mCAN0IDMR4_AM6:     equ    %01000000
mCAN0IDMR4_AM7:     equ    %10000000


;*** CAN0IDMR5 - MSCAN0 Identifier Mask Register 5; 0x0000015D ***
CAN0IDMR5:          equ    $0000015D                                ;*** CAN0IDMR5 - MSCAN0 Identifier Mask Register 5; 0x0000015D ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CAN0IDMR5_AM0:      equ    0                                         ; Acceptance Mask Bit 0
CAN0IDMR5_AM1:      equ    1                                         ; Acceptance Mask Bit 1
CAN0IDMR5_AM2:      equ    2                                         ; Acceptance Mask Bit 2
CAN0IDMR5_AM3:      equ    3                                         ; Acceptance Mask Bit 3
CAN0IDMR5_AM4:      equ    4                                         ; Acceptance Mask Bit 4
CAN0IDMR5_AM5:      equ    5                                         ; Acceptance Mask Bit 5
CAN0IDMR5_AM6:      equ    6                                         ; Acceptance Mask Bit 6
CAN0IDMR5_AM7:      equ    7                                         ; Acceptance Mask Bit 7
; bit position masks
mCAN0IDMR5_AM0:     equ    %00000001
mCAN0IDMR5_AM1:     equ    %00000010
mCAN0IDMR5_AM2:     equ    %00000100
mCAN0IDMR5_AM3:     equ    %00001000
mCAN0IDMR5_AM4:     equ    %00010000
mCAN0IDMR5_AM5:     equ    %00100000
mCAN0IDMR5_AM6:     equ    %01000000
mCAN0IDMR5_AM7:     equ    %10000000


;*** CAN0IDMR6 - MSCAN0 Identifier Mask Register 6; 0x0000015E ***
CAN0IDMR6:          equ    $0000015E                                ;*** CAN0IDMR6 - MSCAN0 Identifier Mask Register 6; 0x0000015E ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CAN0IDMR6_AM0:      equ    0                                         ; Acceptance Mask Bit 0
CAN0IDMR6_AM1:      equ    1                                         ; Acceptance Mask Bit 1
CAN0IDMR6_AM2:      equ    2                                         ; Acceptance Mask Bit 2
CAN0IDMR6_AM3:      equ    3                                         ; Acceptance Mask Bit 3
CAN0IDMR6_AM4:      equ    4                                         ; Acceptance Mask Bit 4
CAN0IDMR6_AM5:      equ    5                                         ; Acceptance Mask Bit 5
CAN0IDMR6_AM6:      equ    6                                         ; Acceptance Mask Bit 6
CAN0IDMR6_AM7:      equ    7                                         ; Acceptance Mask Bit 7
; bit position masks
mCAN0IDMR6_AM0:     equ    %00000001
mCAN0IDMR6_AM1:     equ    %00000010
mCAN0IDMR6_AM2:     equ    %00000100
mCAN0IDMR6_AM3:     equ    %00001000
mCAN0IDMR6_AM4:     equ    %00010000
mCAN0IDMR6_AM5:     equ    %00100000
mCAN0IDMR6_AM6:     equ    %01000000
mCAN0IDMR6_AM7:     equ    %10000000


;*** CAN0IDMR7 - MSCAN0 Identifier Mask Register 7; 0x0000015F ***
CAN0IDMR7:          equ    $0000015F                                ;*** CAN0IDMR7 - MSCAN0 Identifier Mask Register 7; 0x0000015F ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CAN0IDMR7_AM0:      equ    0                                         ; Acceptance Mask Bit 0
CAN0IDMR7_AM1:      equ    1                                         ; Acceptance Mask Bit 1
CAN0IDMR7_AM2:      equ    2                                         ; Acceptance Mask Bit 2
CAN0IDMR7_AM3:      equ    3                                         ; Acceptance Mask Bit 3
CAN0IDMR7_AM4:      equ    4                                         ; Acceptance Mask Bit 4
CAN0IDMR7_AM5:      equ    5                                         ; Acceptance Mask Bit 5
CAN0IDMR7_AM6:      equ    6                                         ; Acceptance Mask Bit 6
CAN0IDMR7_AM7:      equ    7                                         ; Acceptance Mask Bit 7
; bit position masks
mCAN0IDMR7_AM0:     equ    %00000001
mCAN0IDMR7_AM1:     equ    %00000010
mCAN0IDMR7_AM2:     equ    %00000100
mCAN0IDMR7_AM3:     equ    %00001000
mCAN0IDMR7_AM4:     equ    %00010000
mCAN0IDMR7_AM5:     equ    %00100000
mCAN0IDMR7_AM6:     equ    %01000000
mCAN0IDMR7_AM7:     equ    %10000000


;*** CAN0RXIDR0 - MSCAN0 Receive Identifier Register 0; 0x00000160 ***
CAN0RXIDR0:         equ    $00000160                                ;*** CAN0RXIDR0 - MSCAN0 Receive Identifier Register 0; 0x00000160 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CAN0RXIDR0_ID21:    equ    0                                         ; Extended format identifier Bit 21
CAN0RXIDR0_ID22:    equ    1                                         ; Extended format identifier Bit 22
CAN0RXIDR0_ID23:    equ    2                                         ; Extended format identifier Bit 23
CAN0RXIDR0_ID24:    equ    3                                         ; Extended format identifier Bit 24
CAN0RXIDR0_ID25:    equ    4                                         ; Extended format identifier Bit 25
CAN0RXIDR0_ID26:    equ    5                                         ; Extended format identifier Bit 26
CAN0RXIDR0_ID27:    equ    6                                         ; Extended format identifier Bit 27
CAN0RXIDR0_ID28:    equ    7                                         ; Extended format identifier Bit 28
; bit position masks
mCAN0RXIDR0_ID21:   equ    %00000001
mCAN0RXIDR0_ID22:   equ    %00000010
mCAN0RXIDR0_ID23:   equ    %00000100
mCAN0RXIDR0_ID24:   equ    %00001000
mCAN0RXIDR0_ID25:   equ    %00010000
mCAN0RXIDR0_ID26:   equ    %00100000
mCAN0RXIDR0_ID27:   equ    %01000000
mCAN0RXIDR0_ID28:   equ    %10000000


;*** CAN0RXIDR1 - MSCAN0 Receive Identifier Register 1; 0x00000161 ***
CAN0RXIDR1:         equ    $00000161                                ;*** CAN0RXIDR1 - MSCAN0 Receive Identifier Register 1; 0x00000161 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CAN0RXIDR1_ID15:    equ    0                                         ; Extended format identifier Bit 15
CAN0RXIDR1_ID16:    equ    1                                         ; Extended format identifier Bit 16
CAN0RXIDR1_ID17:    equ    2                                         ; Extended format identifier Bit 17
CAN0RXIDR1_IDE:     equ    3                                         ; ID Extended
CAN0RXIDR1_SRR:     equ    4                                         ; Substitute Remote Request
CAN0RXIDR1_ID18:    equ    5                                         ; Extended format identifier Bit 18
CAN0RXIDR1_ID19:    equ    6                                         ; Extended format identifier Bit 19
CAN0RXIDR1_ID20:    equ    7                                         ; Extended format identifier Bit 20
; bit position masks
mCAN0RXIDR1_ID15:   equ    %00000001
mCAN0RXIDR1_ID16:   equ    %00000010
mCAN0RXIDR1_ID17:   equ    %00000100
mCAN0RXIDR1_IDE:    equ    %00001000
mCAN0RXIDR1_SRR:    equ    %00010000
mCAN0RXIDR1_ID18:   equ    %00100000
mCAN0RXIDR1_ID19:   equ    %01000000
mCAN0RXIDR1_ID20:   equ    %10000000


;*** CAN0RXIDR2 - MSCAN0 Receive Identifier Register 2; 0x00000162 ***
CAN0RXIDR2:         equ    $00000162                                ;*** CAN0RXIDR2 - MSCAN0 Receive Identifier Register 2; 0x00000162 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CAN0RXIDR2_ID7:     equ    0                                         ; Extended format identifier Bit 7
CAN0RXIDR2_ID8:     equ    1                                         ; Extended format identifier Bit 8
CAN0RXIDR2_ID9:     equ    2                                         ; Extended format identifier Bit 9
CAN0RXIDR2_ID10:    equ    3                                         ; Extended format identifier Bit 10
CAN0RXIDR2_ID11:    equ    4                                         ; Extended format identifier Bit 11
CAN0RXIDR2_ID12:    equ    5                                         ; Extended format identifier Bit 12
CAN0RXIDR2_ID13:    equ    6                                         ; Extended format identifier Bit 13
CAN0RXIDR2_ID14:    equ    7                                         ; Extended format identifier Bit 14
; bit position masks
mCAN0RXIDR2_ID7:    equ    %00000001
mCAN0RXIDR2_ID8:    equ    %00000010
mCAN0RXIDR2_ID9:    equ    %00000100
mCAN0RXIDR2_ID10:   equ    %00001000
mCAN0RXIDR2_ID11:   equ    %00010000
mCAN0RXIDR2_ID12:   equ    %00100000
mCAN0RXIDR2_ID13:   equ    %01000000
mCAN0RXIDR2_ID14:   equ    %10000000


;*** CAN0RXIDR3 - MSCAN0 Receive Identifier Register 3; 0x00000163 ***
CAN0RXIDR3:         equ    $00000163                                ;*** CAN0RXIDR3 - MSCAN0 Receive Identifier Register 3; 0x00000163 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CAN0RXIDR3_RTR:     equ    0                                         ; Remote Transmission Request
CAN0RXIDR3_ID0:     equ    1                                         ; Extended format identifier Bit 0
CAN0RXIDR3_ID1:     equ    2                                         ; Extended format identifier Bit 1
CAN0RXIDR3_ID2:     equ    3                                         ; Extended format identifier Bit 2
CAN0RXIDR3_ID3:     equ    4                                         ; Extended format identifier Bit 3
CAN0RXIDR3_ID4:     equ    5                                         ; Extended format identifier Bit 4
CAN0RXIDR3_ID5:     equ    6                                         ; Extended format identifier Bit 5
CAN0RXIDR3_ID6:     equ    7                                         ; Extended format identifier Bit 6
; bit position masks
mCAN0RXIDR3_RTR:    equ    %00000001
mCAN0RXIDR3_ID0:    equ    %00000010
mCAN0RXIDR3_ID1:    equ    %00000100
mCAN0RXIDR3_ID2:    equ    %00001000
mCAN0RXIDR3_ID3:    equ    %00010000
mCAN0RXIDR3_ID4:    equ    %00100000
mCAN0RXIDR3_ID5:    equ    %01000000
mCAN0RXIDR3_ID6:    equ    %10000000


;*** CAN0RXDSR0 - MSCAN0 Receive Data Segment Register 0; 0x00000164 ***
CAN0RXDSR0:         equ    $00000164                                ;*** CAN0RXDSR0 - MSCAN0 Receive Data Segment Register 0; 0x00000164 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CAN0RXDSR0_DB0:     equ    0                                         ; Data Bit 0
CAN0RXDSR0_DB1:     equ    1                                         ; Data Bit 1
CAN0RXDSR0_DB2:     equ    2                                         ; Data Bit 2
CAN0RXDSR0_DB3:     equ    3                                         ; Data Bit 3
CAN0RXDSR0_DB4:     equ    4                                         ; Data Bit 4
CAN0RXDSR0_DB5:     equ    5                                         ; Data Bit 5
CAN0RXDSR0_DB6:     equ    6                                         ; Data Bit 6
CAN0RXDSR0_DB7:     equ    7                                         ; Data Bit 7
; bit position masks
mCAN0RXDSR0_DB0:    equ    %00000001
mCAN0RXDSR0_DB1:    equ    %00000010
mCAN0RXDSR0_DB2:    equ    %00000100
mCAN0RXDSR0_DB3:    equ    %00001000
mCAN0RXDSR0_DB4:    equ    %00010000
mCAN0RXDSR0_DB5:    equ    %00100000
mCAN0RXDSR0_DB6:    equ    %01000000
mCAN0RXDSR0_DB7:    equ    %10000000


;*** CAN0RXDSR1 - MSCAN0 Receive Data Segment Register 1; 0x00000165 ***
CAN0RXDSR1:         equ    $00000165                                ;*** CAN0RXDSR1 - MSCAN0 Receive Data Segment Register 1; 0x00000165 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CAN0RXDSR1_DB0:     equ    0                                         ; Data Bit 0
CAN0RXDSR1_DB1:     equ    1                                         ; Data Bit 1
CAN0RXDSR1_DB2:     equ    2                                         ; Data Bit 2
CAN0RXDSR1_DB3:     equ    3                                         ; Data Bit 3
CAN0RXDSR1_DB4:     equ    4                                         ; Data Bit 4
CAN0RXDSR1_DB5:     equ    5                                         ; Data Bit 5
CAN0RXDSR1_DB6:     equ    6                                         ; Data Bit 6
CAN0RXDSR1_DB7:     equ    7                                         ; Data Bit 7
; bit position masks
mCAN0RXDSR1_DB0:    equ    %00000001
mCAN0RXDSR1_DB1:    equ    %00000010
mCAN0RXDSR1_DB2:    equ    %00000100
mCAN0RXDSR1_DB3:    equ    %00001000
mCAN0RXDSR1_DB4:    equ    %00010000
mCAN0RXDSR1_DB5:    equ    %00100000
mCAN0RXDSR1_DB6:    equ    %01000000
mCAN0RXDSR1_DB7:    equ    %10000000


;*** CAN0RXDSR2 - MSCAN0 Receive Data Segment Register 2; 0x00000166 ***
CAN0RXDSR2:         equ    $00000166                                ;*** CAN0RXDSR2 - MSCAN0 Receive Data Segment Register 2; 0x00000166 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CAN0RXDSR2_DB0:     equ    0                                         ; Data Bit 0
CAN0RXDSR2_DB1:     equ    1                                         ; Data Bit 1
CAN0RXDSR2_DB2:     equ    2                                         ; Data Bit 2
CAN0RXDSR2_DB3:     equ    3                                         ; Data Bit 3
CAN0RXDSR2_DB4:     equ    4                                         ; Data Bit 4
CAN0RXDSR2_DB5:     equ    5                                         ; Data Bit 5
CAN0RXDSR2_DB6:     equ    6                                         ; Data Bit 6
CAN0RXDSR2_DB7:     equ    7                                         ; Data Bit 7
; bit position masks
mCAN0RXDSR2_DB0:    equ    %00000001
mCAN0RXDSR2_DB1:    equ    %00000010
mCAN0RXDSR2_DB2:    equ    %00000100
mCAN0RXDSR2_DB3:    equ    %00001000
mCAN0RXDSR2_DB4:    equ    %00010000
mCAN0RXDSR2_DB5:    equ    %00100000
mCAN0RXDSR2_DB6:    equ    %01000000
mCAN0RXDSR2_DB7:    equ    %10000000


;*** CAN0RXDSR3 - MSCAN0 Receive Data Segment Register 3; 0x00000167 ***
CAN0RXDSR3:         equ    $00000167                                ;*** CAN0RXDSR3 - MSCAN0 Receive Data Segment Register 3; 0x00000167 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CAN0RXDSR3_DB0:     equ    0                                         ; Data Bit 0
CAN0RXDSR3_DB1:     equ    1                                         ; Data Bit 1
CAN0RXDSR3_DB2:     equ    2                                         ; Data Bit 2
CAN0RXDSR3_DB3:     equ    3                                         ; Data Bit 3
CAN0RXDSR3_DB4:     equ    4                                         ; Data Bit 4
CAN0RXDSR3_DB5:     equ    5                                         ; Data Bit 5
CAN0RXDSR3_DB6:     equ    6                                         ; Data Bit 6
CAN0RXDSR3_DB7:     equ    7                                         ; Data Bit 7
; bit position masks
mCAN0RXDSR3_DB0:    equ    %00000001
mCAN0RXDSR3_DB1:    equ    %00000010
mCAN0RXDSR3_DB2:    equ    %00000100
mCAN0RXDSR3_DB3:    equ    %00001000
mCAN0RXDSR3_DB4:    equ    %00010000
mCAN0RXDSR3_DB5:    equ    %00100000
mCAN0RXDSR3_DB6:    equ    %01000000
mCAN0RXDSR3_DB7:    equ    %10000000


;*** CAN0RXDSR4 - MSCAN0 Receive Data Segment Register 4; 0x00000168 ***
CAN0RXDSR4:         equ    $00000168                                ;*** CAN0RXDSR4 - MSCAN0 Receive Data Segment Register 4; 0x00000168 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CAN0RXDSR4_DB0:     equ    0                                         ; Data Bit 0
CAN0RXDSR4_DB1:     equ    1                                         ; Data Bit 1
CAN0RXDSR4_DB2:     equ    2                                         ; Data Bit 2
CAN0RXDSR4_DB3:     equ    3                                         ; Data Bit 3
CAN0RXDSR4_DB4:     equ    4                                         ; Data Bit 4
CAN0RXDSR4_DB5:     equ    5                                         ; Data Bit 5
CAN0RXDSR4_DB6:     equ    6                                         ; Data Bit 6
CAN0RXDSR4_DB7:     equ    7                                         ; Data Bit 7
; bit position masks
mCAN0RXDSR4_DB0:    equ    %00000001
mCAN0RXDSR4_DB1:    equ    %00000010
mCAN0RXDSR4_DB2:    equ    %00000100
mCAN0RXDSR4_DB3:    equ    %00001000
mCAN0RXDSR4_DB4:    equ    %00010000
mCAN0RXDSR4_DB5:    equ    %00100000
mCAN0RXDSR4_DB6:    equ    %01000000
mCAN0RXDSR4_DB7:    equ    %10000000


;*** CAN0RXDSR5 - MSCAN0 Receive Data Segment Register 5; 0x00000169 ***
CAN0RXDSR5:         equ    $00000169                                ;*** CAN0RXDSR5 - MSCAN0 Receive Data Segment Register 5; 0x00000169 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CAN0RXDSR5_DB0:     equ    0                                         ; Data Bit 0
CAN0RXDSR5_DB1:     equ    1                                         ; Data Bit 1
CAN0RXDSR5_DB2:     equ    2                                         ; Data Bit 2
CAN0RXDSR5_DB3:     equ    3                                         ; Data Bit 3
CAN0RXDSR5_DB4:     equ    4                                         ; Data Bit 4
CAN0RXDSR5_DB5:     equ    5                                         ; Data Bit 5
CAN0RXDSR5_DB6:     equ    6                                         ; Data Bit 6
CAN0RXDSR5_DB7:     equ    7                                         ; Data Bit 7
; bit position masks
mCAN0RXDSR5_DB0:    equ    %00000001
mCAN0RXDSR5_DB1:    equ    %00000010
mCAN0RXDSR5_DB2:    equ    %00000100
mCAN0RXDSR5_DB3:    equ    %00001000
mCAN0RXDSR5_DB4:    equ    %00010000
mCAN0RXDSR5_DB5:    equ    %00100000
mCAN0RXDSR5_DB6:    equ    %01000000
mCAN0RXDSR5_DB7:    equ    %10000000


;*** CAN0RXDSR6 - MSCAN0 Receive Data Segment Register 6; 0x0000016A ***
CAN0RXDSR6:         equ    $0000016A                                ;*** CAN0RXDSR6 - MSCAN0 Receive Data Segment Register 6; 0x0000016A ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CAN0RXDSR6_DB0:     equ    0                                         ; Data Bit 0
CAN0RXDSR6_DB1:     equ    1                                         ; Data Bit 1
CAN0RXDSR6_DB2:     equ    2                                         ; Data Bit 2
CAN0RXDSR6_DB3:     equ    3                                         ; Data Bit 3
CAN0RXDSR6_DB4:     equ    4                                         ; Data Bit 4
CAN0RXDSR6_DB5:     equ    5                                         ; Data Bit 5
CAN0RXDSR6_DB6:     equ    6                                         ; Data Bit 6
CAN0RXDSR6_DB7:     equ    7                                         ; Data Bit 7
; bit position masks
mCAN0RXDSR6_DB0:    equ    %00000001
mCAN0RXDSR6_DB1:    equ    %00000010
mCAN0RXDSR6_DB2:    equ    %00000100
mCAN0RXDSR6_DB3:    equ    %00001000
mCAN0RXDSR6_DB4:    equ    %00010000
mCAN0RXDSR6_DB5:    equ    %00100000
mCAN0RXDSR6_DB6:    equ    %01000000
mCAN0RXDSR6_DB7:    equ    %10000000


;*** CAN0RXDSR7 - MSCAN0 Receive Data Segment Register 7; 0x0000016B ***
CAN0RXDSR7:         equ    $0000016B                                ;*** CAN0RXDSR7 - MSCAN0 Receive Data Segment Register 7; 0x0000016B ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CAN0RXDSR7_DB0:     equ    0                                         ; Data Bit 0
CAN0RXDSR7_DB1:     equ    1                                         ; Data Bit 1
CAN0RXDSR7_DB2:     equ    2                                         ; Data Bit 2
CAN0RXDSR7_DB3:     equ    3                                         ; Data Bit 3
CAN0RXDSR7_DB4:     equ    4                                         ; Data Bit 4
CAN0RXDSR7_DB5:     equ    5                                         ; Data Bit 5
CAN0RXDSR7_DB6:     equ    6                                         ; Data Bit 6
CAN0RXDSR7_DB7:     equ    7                                         ; Data Bit 7
; bit position masks
mCAN0RXDSR7_DB0:    equ    %00000001
mCAN0RXDSR7_DB1:    equ    %00000010
mCAN0RXDSR7_DB2:    equ    %00000100
mCAN0RXDSR7_DB3:    equ    %00001000
mCAN0RXDSR7_DB4:    equ    %00010000
mCAN0RXDSR7_DB5:    equ    %00100000
mCAN0RXDSR7_DB6:    equ    %01000000
mCAN0RXDSR7_DB7:    equ    %10000000


;*** CAN0RXDLR - MSCAN0 Receive Data Length Register; 0x0000016C ***
CAN0RXDLR:          equ    $0000016C                                ;*** CAN0RXDLR - MSCAN0 Receive Data Length Register; 0x0000016C ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CAN0RXDLR_DLC0:     equ    0                                         ; Data Length Code Bit 0
CAN0RXDLR_DLC1:     equ    1                                         ; Data Length Code Bit 1
CAN0RXDLR_DLC2:     equ    2                                         ; Data Length Code Bit 2
CAN0RXDLR_DLC3:     equ    3                                         ; Data Length Code Bit 3
; bit position masks
mCAN0RXDLR_DLC0:    equ    %00000001
mCAN0RXDLR_DLC1:    equ    %00000010
mCAN0RXDLR_DLC2:    equ    %00000100
mCAN0RXDLR_DLC3:    equ    %00001000


;*** CAN0RXTSR - MSCAN0 Receive Time Stamp Register; 0x0000016E ***
CAN0RXTSR:          equ    $0000016E                                ;*** CAN0RXTSR - MSCAN0 Receive Time Stamp Register; 0x0000016E ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CAN0RXTSR_TSR0:     equ    0                                         ; Time Stamp Bit 0
CAN0RXTSR_TSR1:     equ    1                                         ; Time Stamp Bit 1
CAN0RXTSR_TSR2:     equ    2                                         ; Time Stamp Bit 2
CAN0RXTSR_TSR3:     equ    3                                         ; Time Stamp Bit 3
CAN0RXTSR_TSR4:     equ    4                                         ; Time Stamp Bit 4
CAN0RXTSR_TSR5:     equ    5                                         ; Time Stamp Bit 5
CAN0RXTSR_TSR6:     equ    6                                         ; Time Stamp Bit 6
CAN0RXTSR_TSR7:     equ    7                                         ; Time Stamp Bit 7
CAN0RXTSR_TSR8:     equ    8                                         ; Time Stamp Bit 8
CAN0RXTSR_TSR9:     equ    9                                         ; Time Stamp Bit 9
CAN0RXTSR_TSR10:    equ    10                                        ; Time Stamp Bit 10
CAN0RXTSR_TSR11:    equ    11                                        ; Time Stamp Bit 11
CAN0RXTSR_TSR12:    equ    12                                        ; Time Stamp Bit 12
CAN0RXTSR_TSR13:    equ    13                                        ; Time Stamp Bit 13
CAN0RXTSR_TSR14:    equ    14                                        ; Time Stamp Bit 14
CAN0RXTSR_TSR15:    equ    15                                        ; Time Stamp Bit 15
; bit position masks
mCAN0RXTSR_TSR0:    equ    %00000001
mCAN0RXTSR_TSR1:    equ    %00000010
mCAN0RXTSR_TSR2:    equ    %00000100
mCAN0RXTSR_TSR3:    equ    %00001000
mCAN0RXTSR_TSR4:    equ    %00010000
mCAN0RXTSR_TSR5:    equ    %00100000
mCAN0RXTSR_TSR6:    equ    %01000000
mCAN0RXTSR_TSR7:    equ    %10000000
mCAN0RXTSR_TSR8:    equ    %100000000
mCAN0RXTSR_TSR9:    equ    %1000000000
mCAN0RXTSR_TSR10:   equ    %10000000000
mCAN0RXTSR_TSR11:   equ    %100000000000
mCAN0RXTSR_TSR12:   equ    %1000000000000
mCAN0RXTSR_TSR13:   equ    %10000000000000
mCAN0RXTSR_TSR14:   equ    %100000000000000
mCAN0RXTSR_TSR15:   equ    %1000000000000000


;*** CAN0RXTSRH - MSCAN0 Receive Time Stamp Register High; 0x0000016E ***
CAN0RXTSRH:         equ    $0000016E                                ;*** CAN0RXTSRH - MSCAN0 Receive Time Stamp Register High; 0x0000016E ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CAN0RXTSRH_TSR8:    equ    0                                         ; Time Stamp Bit 8
CAN0RXTSRH_TSR9:    equ    1                                         ; Time Stamp Bit 9
CAN0RXTSRH_TSR10:   equ    2                                         ; Time Stamp Bit 10
CAN0RXTSRH_TSR11:   equ    3                                         ; Time Stamp Bit 11
CAN0RXTSRH_TSR12:   equ    4                                         ; Time Stamp Bit 12
CAN0RXTSRH_TSR13:   equ    5                                         ; Time Stamp Bit 13
CAN0RXTSRH_TSR14:   equ    6                                         ; Time Stamp Bit 14
CAN0RXTSRH_TSR15:   equ    7                                         ; Time Stamp Bit 15
; bit position masks
mCAN0RXTSRH_TSR8:   equ    %00000001
mCAN0RXTSRH_TSR9:   equ    %00000010
mCAN0RXTSRH_TSR10:  equ    %00000100
mCAN0RXTSRH_TSR11:  equ    %00001000
mCAN0RXTSRH_TSR12:  equ    %00010000
mCAN0RXTSRH_TSR13:  equ    %00100000
mCAN0RXTSRH_TSR14:  equ    %01000000
mCAN0RXTSRH_TSR15:  equ    %10000000


;*** CAN0RXTSRL - MSCAN0 Receive Time Stamp Register Low; 0x0000016F ***
CAN0RXTSRL:         equ    $0000016F                                ;*** CAN0RXTSRL - MSCAN0 Receive Time Stamp Register Low; 0x0000016F ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CAN0RXTSRL_TSR0:    equ    0                                         ; Time Stamp Bit 0
CAN0RXTSRL_TSR1:    equ    1                                         ; Time Stamp Bit 1
CAN0RXTSRL_TSR2:    equ    2                                         ; Time Stamp Bit 2
CAN0RXTSRL_TSR3:    equ    3                                         ; Time Stamp Bit 3
CAN0RXTSRL_TSR4:    equ    4                                         ; Time Stamp Bit 4
CAN0RXTSRL_TSR5:    equ    5                                         ; Time Stamp Bit 5
CAN0RXTSRL_TSR6:    equ    6                                         ; Time Stamp Bit 6
CAN0RXTSRL_TSR7:    equ    7                                         ; Time Stamp Bit 7
; bit position masks
mCAN0RXTSRL_TSR0:   equ    %00000001
mCAN0RXTSRL_TSR1:   equ    %00000010
mCAN0RXTSRL_TSR2:   equ    %00000100
mCAN0RXTSRL_TSR3:   equ    %00001000
mCAN0RXTSRL_TSR4:   equ    %00010000
mCAN0RXTSRL_TSR5:   equ    %00100000
mCAN0RXTSRL_TSR6:   equ    %01000000
mCAN0RXTSRL_TSR7:   equ    %10000000


;*** CAN0TXIDR0 - MSCAN0 Transmit Identifier Register 0; 0x00000170 ***
CAN0TXIDR0:         equ    $00000170                                ;*** CAN0TXIDR0 - MSCAN0 Transmit Identifier Register 0; 0x00000170 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CAN0TXIDR0_ID21:    equ    0                                         ; Extended format identifier Bit 21
CAN0TXIDR0_ID22:    equ    1                                         ; Extended format identifier Bit 22
CAN0TXIDR0_ID23:    equ    2                                         ; Extended format identifier Bit 23
CAN0TXIDR0_ID24:    equ    3                                         ; Extended format identifier Bit 24
CAN0TXIDR0_ID25:    equ    4                                         ; Extended format identifier Bit 25
CAN0TXIDR0_ID26:    equ    5                                         ; Extended format identifier Bit 26
CAN0TXIDR0_ID27:    equ    6                                         ; Extended format identifier Bit 27
CAN0TXIDR0_ID28:    equ    7                                         ; Extended format identifier Bit 28
; bit position masks
mCAN0TXIDR0_ID21:   equ    %00000001
mCAN0TXIDR0_ID22:   equ    %00000010
mCAN0TXIDR0_ID23:   equ    %00000100
mCAN0TXIDR0_ID24:   equ    %00001000
mCAN0TXIDR0_ID25:   equ    %00010000
mCAN0TXIDR0_ID26:   equ    %00100000
mCAN0TXIDR0_ID27:   equ    %01000000
mCAN0TXIDR0_ID28:   equ    %10000000


;*** CAN0TXIDR1 - MSCAN0 Transmit Identifier Register 1; 0x00000171 ***
CAN0TXIDR1:         equ    $00000171                                ;*** CAN0TXIDR1 - MSCAN0 Transmit Identifier Register 1; 0x00000171 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CAN0TXIDR1_ID15:    equ    0                                         ; Extended format identifier Bit 15
CAN0TXIDR1_ID16:    equ    1                                         ; Extended format identifier Bit 16
CAN0TXIDR1_ID17:    equ    2                                         ; Extended format identifier Bit 17
CAN0TXIDR1_IDE:     equ    3                                         ; ID Extended
CAN0TXIDR1_SRR:     equ    4                                         ; Substitute Remote Request
CAN0TXIDR1_ID18:    equ    5                                         ; Extended format identifier Bit 18
CAN0TXIDR1_ID19:    equ    6                                         ; Extended format identifier Bit 19
CAN0TXIDR1_ID20:    equ    7                                         ; Extended format identifier Bit 20
; bit position masks
mCAN0TXIDR1_ID15:   equ    %00000001
mCAN0TXIDR1_ID16:   equ    %00000010
mCAN0TXIDR1_ID17:   equ    %00000100
mCAN0TXIDR1_IDE:    equ    %00001000
mCAN0TXIDR1_SRR:    equ    %00010000
mCAN0TXIDR1_ID18:   equ    %00100000
mCAN0TXIDR1_ID19:   equ    %01000000
mCAN0TXIDR1_ID20:   equ    %10000000


;*** CAN0TXIDR2 - MSCAN0 Transmit Identifier Register 2; 0x00000172 ***
CAN0TXIDR2:         equ    $00000172                                ;*** CAN0TXIDR2 - MSCAN0 Transmit Identifier Register 2; 0x00000172 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CAN0TXIDR2_ID7:     equ    0                                         ; Extended format identifier Bit 7
CAN0TXIDR2_ID8:     equ    1                                         ; Extended format identifier Bit 8
CAN0TXIDR2_ID9:     equ    2                                         ; Extended format identifier Bit 9
CAN0TXIDR2_ID10:    equ    3                                         ; Extended format identifier Bit 10
CAN0TXIDR2_ID11:    equ    4                                         ; Extended format identifier Bit 11
CAN0TXIDR2_ID12:    equ    5                                         ; Extended format identifier Bit 12
CAN0TXIDR2_ID13:    equ    6                                         ; Extended format identifier Bit 13
CAN0TXIDR2_ID14:    equ    7                                         ; Extended format identifier Bit 14
; bit position masks
mCAN0TXIDR2_ID7:    equ    %00000001
mCAN0TXIDR2_ID8:    equ    %00000010
mCAN0TXIDR2_ID9:    equ    %00000100
mCAN0TXIDR2_ID10:   equ    %00001000
mCAN0TXIDR2_ID11:   equ    %00010000
mCAN0TXIDR2_ID12:   equ    %00100000
mCAN0TXIDR2_ID13:   equ    %01000000
mCAN0TXIDR2_ID14:   equ    %10000000


;*** CAN0TXIDR3 - MSCAN0 Transmit Identifier Register 3; 0x00000173 ***
CAN0TXIDR3:         equ    $00000173                                ;*** CAN0TXIDR3 - MSCAN0 Transmit Identifier Register 3; 0x00000173 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CAN0TXIDR3_RTR:     equ    0                                         ; Remote Transmission Request
CAN0TXIDR3_ID0:     equ    1                                         ; Extended format identifier Bit 0
CAN0TXIDR3_ID1:     equ    2                                         ; Extended format identifier Bit 1
CAN0TXIDR3_ID2:     equ    3                                         ; Extended format identifier Bit 2
CAN0TXIDR3_ID3:     equ    4                                         ; Extended format identifier Bit 3
CAN0TXIDR3_ID4:     equ    5                                         ; Extended format identifier Bit 4
CAN0TXIDR3_ID5:     equ    6                                         ; Extended format identifier Bit 5
CAN0TXIDR3_ID6:     equ    7                                         ; Extended format identifier Bit 6
; bit position masks
mCAN0TXIDR3_RTR:    equ    %00000001
mCAN0TXIDR3_ID0:    equ    %00000010
mCAN0TXIDR3_ID1:    equ    %00000100
mCAN0TXIDR3_ID2:    equ    %00001000
mCAN0TXIDR3_ID3:    equ    %00010000
mCAN0TXIDR3_ID4:    equ    %00100000
mCAN0TXIDR3_ID5:    equ    %01000000
mCAN0TXIDR3_ID6:    equ    %10000000


;*** CAN0TXDSR0 - MSCAN0 Transmit Data Segment Register 0; 0x00000174 ***
CAN0TXDSR0:         equ    $00000174                                ;*** CAN0TXDSR0 - MSCAN0 Transmit Data Segment Register 0; 0x00000174 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CAN0TXDSR0_DB0:     equ    0                                         ; Data Bit 0
CAN0TXDSR0_DB1:     equ    1                                         ; Data Bit 1
CAN0TXDSR0_DB2:     equ    2                                         ; Data Bit 2
CAN0TXDSR0_DB3:     equ    3                                         ; Data Bit 3
CAN0TXDSR0_DB4:     equ    4                                         ; Data Bit 4
CAN0TXDSR0_DB5:     equ    5                                         ; Data Bit 5
CAN0TXDSR0_DB6:     equ    6                                         ; Data Bit 6
CAN0TXDSR0_DB7:     equ    7                                         ; Data Bit 7
; bit position masks
mCAN0TXDSR0_DB0:    equ    %00000001
mCAN0TXDSR0_DB1:    equ    %00000010
mCAN0TXDSR0_DB2:    equ    %00000100
mCAN0TXDSR0_DB3:    equ    %00001000
mCAN0TXDSR0_DB4:    equ    %00010000
mCAN0TXDSR0_DB5:    equ    %00100000
mCAN0TXDSR0_DB6:    equ    %01000000
mCAN0TXDSR0_DB7:    equ    %10000000


;*** CAN0TXDSR1 - MSCAN0 Transmit Data Segment Register 1; 0x00000175 ***
CAN0TXDSR1:         equ    $00000175                                ;*** CAN0TXDSR1 - MSCAN0 Transmit Data Segment Register 1; 0x00000175 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CAN0TXDSR1_DB0:     equ    0                                         ; Data Bit 0
CAN0TXDSR1_DB1:     equ    1                                         ; Data Bit 1
CAN0TXDSR1_DB2:     equ    2                                         ; Data Bit 2
CAN0TXDSR1_DB3:     equ    3                                         ; Data Bit 3
CAN0TXDSR1_DB4:     equ    4                                         ; Data Bit 4
CAN0TXDSR1_DB5:     equ    5                                         ; Data Bit 5
CAN0TXDSR1_DB6:     equ    6                                         ; Data Bit 6
CAN0TXDSR1_DB7:     equ    7                                         ; Data Bit 7
; bit position masks
mCAN0TXDSR1_DB0:    equ    %00000001
mCAN0TXDSR1_DB1:    equ    %00000010
mCAN0TXDSR1_DB2:    equ    %00000100
mCAN0TXDSR1_DB3:    equ    %00001000
mCAN0TXDSR1_DB4:    equ    %00010000
mCAN0TXDSR1_DB5:    equ    %00100000
mCAN0TXDSR1_DB6:    equ    %01000000
mCAN0TXDSR1_DB7:    equ    %10000000


;*** CAN0TXDSR2 - MSCAN0 Transmit Data Segment Register 2; 0x00000176 ***
CAN0TXDSR2:         equ    $00000176                                ;*** CAN0TXDSR2 - MSCAN0 Transmit Data Segment Register 2; 0x00000176 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CAN0TXDSR2_DB0:     equ    0                                         ; Data Bit 0
CAN0TXDSR2_DB1:     equ    1                                         ; Data Bit 1
CAN0TXDSR2_DB2:     equ    2                                         ; Data Bit 2
CAN0TXDSR2_DB3:     equ    3                                         ; Data Bit 3
CAN0TXDSR2_DB4:     equ    4                                         ; Data Bit 4
CAN0TXDSR2_DB5:     equ    5                                         ; Data Bit 5
CAN0TXDSR2_DB6:     equ    6                                         ; Data Bit 6
CAN0TXDSR2_DB7:     equ    7                                         ; Data Bit 7
; bit position masks
mCAN0TXDSR2_DB0:    equ    %00000001
mCAN0TXDSR2_DB1:    equ    %00000010
mCAN0TXDSR2_DB2:    equ    %00000100
mCAN0TXDSR2_DB3:    equ    %00001000
mCAN0TXDSR2_DB4:    equ    %00010000
mCAN0TXDSR2_DB5:    equ    %00100000
mCAN0TXDSR2_DB6:    equ    %01000000
mCAN0TXDSR2_DB7:    equ    %10000000


;*** CAN0TXDSR3 - MSCAN0 Transmit Data Segment Register 3; 0x00000177 ***
CAN0TXDSR3:         equ    $00000177                                ;*** CAN0TXDSR3 - MSCAN0 Transmit Data Segment Register 3; 0x00000177 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CAN0TXDSR3_DB0:     equ    0                                         ; Data Bit 0
CAN0TXDSR3_DB1:     equ    1                                         ; Data Bit 1
CAN0TXDSR3_DB2:     equ    2                                         ; Data Bit 2
CAN0TXDSR3_DB3:     equ    3                                         ; Data Bit 3
CAN0TXDSR3_DB4:     equ    4                                         ; Data Bit 4
CAN0TXDSR3_DB5:     equ    5                                         ; Data Bit 5
CAN0TXDSR3_DB6:     equ    6                                         ; Data Bit 6
CAN0TXDSR3_DB7:     equ    7                                         ; Data Bit 7
; bit position masks
mCAN0TXDSR3_DB0:    equ    %00000001
mCAN0TXDSR3_DB1:    equ    %00000010
mCAN0TXDSR3_DB2:    equ    %00000100
mCAN0TXDSR3_DB3:    equ    %00001000
mCAN0TXDSR3_DB4:    equ    %00010000
mCAN0TXDSR3_DB5:    equ    %00100000
mCAN0TXDSR3_DB6:    equ    %01000000
mCAN0TXDSR3_DB7:    equ    %10000000


;*** CAN0TXDSR4 - MSCAN0 Transmit Data Segment Register 4; 0x00000178 ***
CAN0TXDSR4:         equ    $00000178                                ;*** CAN0TXDSR4 - MSCAN0 Transmit Data Segment Register 4; 0x00000178 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CAN0TXDSR4_DB0:     equ    0                                         ; Data Bit 0
CAN0TXDSR4_DB1:     equ    1                                         ; Data Bit 1
CAN0TXDSR4_DB2:     equ    2                                         ; Data Bit 2
CAN0TXDSR4_DB3:     equ    3                                         ; Data Bit 3
CAN0TXDSR4_DB4:     equ    4                                         ; Data Bit 4
CAN0TXDSR4_DB5:     equ    5                                         ; Data Bit 5
CAN0TXDSR4_DB6:     equ    6                                         ; Data Bit 6
CAN0TXDSR4_DB7:     equ    7                                         ; Data Bit 7
; bit position masks
mCAN0TXDSR4_DB0:    equ    %00000001
mCAN0TXDSR4_DB1:    equ    %00000010
mCAN0TXDSR4_DB2:    equ    %00000100
mCAN0TXDSR4_DB3:    equ    %00001000
mCAN0TXDSR4_DB4:    equ    %00010000
mCAN0TXDSR4_DB5:    equ    %00100000
mCAN0TXDSR4_DB6:    equ    %01000000
mCAN0TXDSR4_DB7:    equ    %10000000


;*** CAN0TXDSR5 - MSCAN0 Transmit Data Segment Register 5; 0x00000179 ***
CAN0TXDSR5:         equ    $00000179                                ;*** CAN0TXDSR5 - MSCAN0 Transmit Data Segment Register 5; 0x00000179 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CAN0TXDSR5_DB0:     equ    0                                         ; Data Bit 0
CAN0TXDSR5_DB1:     equ    1                                         ; Data Bit 1
CAN0TXDSR5_DB2:     equ    2                                         ; Data Bit 2
CAN0TXDSR5_DB3:     equ    3                                         ; Data Bit 3
CAN0TXDSR5_DB4:     equ    4                                         ; Data Bit 4
CAN0TXDSR5_DB5:     equ    5                                         ; Data Bit 5
CAN0TXDSR5_DB6:     equ    6                                         ; Data Bit 6
CAN0TXDSR5_DB7:     equ    7                                         ; Data Bit 7
; bit position masks
mCAN0TXDSR5_DB0:    equ    %00000001
mCAN0TXDSR5_DB1:    equ    %00000010
mCAN0TXDSR5_DB2:    equ    %00000100
mCAN0TXDSR5_DB3:    equ    %00001000
mCAN0TXDSR5_DB4:    equ    %00010000
mCAN0TXDSR5_DB5:    equ    %00100000
mCAN0TXDSR5_DB6:    equ    %01000000
mCAN0TXDSR5_DB7:    equ    %10000000


;*** CAN0TXDSR6 - MSCAN0 Transmit Data Segment Register 6; 0x0000017A ***
CAN0TXDSR6:         equ    $0000017A                                ;*** CAN0TXDSR6 - MSCAN0 Transmit Data Segment Register 6; 0x0000017A ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CAN0TXDSR6_DB0:     equ    0                                         ; Data Bit 0
CAN0TXDSR6_DB1:     equ    1                                         ; Data Bit 1
CAN0TXDSR6_DB2:     equ    2                                         ; Data Bit 2
CAN0TXDSR6_DB3:     equ    3                                         ; Data Bit 3
CAN0TXDSR6_DB4:     equ    4                                         ; Data Bit 4
CAN0TXDSR6_DB5:     equ    5                                         ; Data Bit 5
CAN0TXDSR6_DB6:     equ    6                                         ; Data Bit 6
CAN0TXDSR6_DB7:     equ    7                                         ; Data Bit 7
; bit position masks
mCAN0TXDSR6_DB0:    equ    %00000001
mCAN0TXDSR6_DB1:    equ    %00000010
mCAN0TXDSR6_DB2:    equ    %00000100
mCAN0TXDSR6_DB3:    equ    %00001000
mCAN0TXDSR6_DB4:    equ    %00010000
mCAN0TXDSR6_DB5:    equ    %00100000
mCAN0TXDSR6_DB6:    equ    %01000000
mCAN0TXDSR6_DB7:    equ    %10000000


;*** CAN0TXDSR7 - MSCAN0 Transmit Data Segment Register 7; 0x0000017B ***
CAN0TXDSR7:         equ    $0000017B                                ;*** CAN0TXDSR7 - MSCAN0 Transmit Data Segment Register 7; 0x0000017B ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CAN0TXDSR7_DB0:     equ    0                                         ; Data Bit 0
CAN0TXDSR7_DB1:     equ    1                                         ; Data Bit 1
CAN0TXDSR7_DB2:     equ    2                                         ; Data Bit 2
CAN0TXDSR7_DB3:     equ    3                                         ; Data Bit 3
CAN0TXDSR7_DB4:     equ    4                                         ; Data Bit 4
CAN0TXDSR7_DB5:     equ    5                                         ; Data Bit 5
CAN0TXDSR7_DB6:     equ    6                                         ; Data Bit 6
CAN0TXDSR7_DB7:     equ    7                                         ; Data Bit 7
; bit position masks
mCAN0TXDSR7_DB0:    equ    %00000001
mCAN0TXDSR7_DB1:    equ    %00000010
mCAN0TXDSR7_DB2:    equ    %00000100
mCAN0TXDSR7_DB3:    equ    %00001000
mCAN0TXDSR7_DB4:    equ    %00010000
mCAN0TXDSR7_DB5:    equ    %00100000
mCAN0TXDSR7_DB6:    equ    %01000000
mCAN0TXDSR7_DB7:    equ    %10000000


;*** CAN0TXDLR - MSCAN0 Transmit Data Length Register; 0x0000017C ***
CAN0TXDLR:          equ    $0000017C                                ;*** CAN0TXDLR - MSCAN0 Transmit Data Length Register; 0x0000017C ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CAN0TXDLR_DLC0:     equ    0                                         ; Data Length Code Bit 0
CAN0TXDLR_DLC1:     equ    1                                         ; Data Length Code Bit 1
CAN0TXDLR_DLC2:     equ    2                                         ; Data Length Code Bit 2
CAN0TXDLR_DLC3:     equ    3                                         ; Data Length Code Bit 3
; bit position masks
mCAN0TXDLR_DLC0:    equ    %00000001
mCAN0TXDLR_DLC1:    equ    %00000010
mCAN0TXDLR_DLC2:    equ    %00000100
mCAN0TXDLR_DLC3:    equ    %00001000


;*** CAN0TXTBPR - MSCAN0 Transmit Buffer Priority; 0x0000017D ***
CAN0TXTBPR:         equ    $0000017D                                ;*** CAN0TXTBPR - MSCAN0 Transmit Buffer Priority; 0x0000017D ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CAN0TXTBPR_PRIO0:   equ    0                                         ; Transmit Buffer Priority Bit 0
CAN0TXTBPR_PRIO1:   equ    1                                         ; Transmit Buffer Priority Bit 1
CAN0TXTBPR_PRIO2:   equ    2                                         ; Transmit Buffer Priority Bit 2
CAN0TXTBPR_PRIO3:   equ    3                                         ; Transmit Buffer Priority Bit 3
CAN0TXTBPR_PRIO4:   equ    4                                         ; Transmit Buffer Priority Bit 4
CAN0TXTBPR_PRIO5:   equ    5                                         ; Transmit Buffer Priority Bit 5
CAN0TXTBPR_PRIO6:   equ    6                                         ; Transmit Buffer Priority Bit 6
CAN0TXTBPR_PRIO7:   equ    7                                         ; Transmit Buffer Priority Bit 7
; bit position masks
mCAN0TXTBPR_PRIO0:  equ    %00000001
mCAN0TXTBPR_PRIO1:  equ    %00000010
mCAN0TXTBPR_PRIO2:  equ    %00000100
mCAN0TXTBPR_PRIO3:  equ    %00001000
mCAN0TXTBPR_PRIO4:  equ    %00010000
mCAN0TXTBPR_PRIO5:  equ    %00100000
mCAN0TXTBPR_PRIO6:  equ    %01000000
mCAN0TXTBPR_PRIO7:  equ    %10000000


;*** CAN0TXTSR - MSCAN0 Transmit Time Stamp Register; 0x0000017E ***
CAN0TXTSR:          equ    $0000017E                                ;*** CAN0TXTSR - MSCAN0 Transmit Time Stamp Register; 0x0000017E ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CAN0TXTSR_TSR0:     equ    0                                         ; Time Stamp Bit 0
CAN0TXTSR_TSR1:     equ    1                                         ; Time Stamp Bit 1
CAN0TXTSR_TSR2:     equ    2                                         ; Time Stamp Bit 2
CAN0TXTSR_TSR3:     equ    3                                         ; Time Stamp Bit 3
CAN0TXTSR_TSR4:     equ    4                                         ; Time Stamp Bit 4
CAN0TXTSR_TSR5:     equ    5                                         ; Time Stamp Bit 5
CAN0TXTSR_TSR6:     equ    6                                         ; Time Stamp Bit 6
CAN0TXTSR_TSR7:     equ    7                                         ; Time Stamp Bit 7
CAN0TXTSR_TSR8:     equ    8                                         ; Time Stamp Bit 8
CAN0TXTSR_TSR9:     equ    9                                         ; Time Stamp Bit 9
CAN0TXTSR_TSR10:    equ    10                                        ; Time Stamp Bit 10
CAN0TXTSR_TSR11:    equ    11                                        ; Time Stamp Bit 11
CAN0TXTSR_TSR12:    equ    12                                        ; Time Stamp Bit 12
CAN0TXTSR_TSR13:    equ    13                                        ; Time Stamp Bit 13
CAN0TXTSR_TSR14:    equ    14                                        ; Time Stamp Bit 14
CAN0TXTSR_TSR15:    equ    15                                        ; Time Stamp Bit 15
; bit position masks
mCAN0TXTSR_TSR0:    equ    %00000001
mCAN0TXTSR_TSR1:    equ    %00000010
mCAN0TXTSR_TSR2:    equ    %00000100
mCAN0TXTSR_TSR3:    equ    %00001000
mCAN0TXTSR_TSR4:    equ    %00010000
mCAN0TXTSR_TSR5:    equ    %00100000
mCAN0TXTSR_TSR6:    equ    %01000000
mCAN0TXTSR_TSR7:    equ    %10000000
mCAN0TXTSR_TSR8:    equ    %100000000
mCAN0TXTSR_TSR9:    equ    %1000000000
mCAN0TXTSR_TSR10:   equ    %10000000000
mCAN0TXTSR_TSR11:   equ    %100000000000
mCAN0TXTSR_TSR12:   equ    %1000000000000
mCAN0TXTSR_TSR13:   equ    %10000000000000
mCAN0TXTSR_TSR14:   equ    %100000000000000
mCAN0TXTSR_TSR15:   equ    %1000000000000000


;*** CAN0TXTSRH - MSCAN0 Transmit Time Stamp Register High; 0x0000017E ***
CAN0TXTSRH:         equ    $0000017E                                ;*** CAN0TXTSRH - MSCAN0 Transmit Time Stamp Register High; 0x0000017E ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CAN0TXTSRH_TSR8:    equ    0                                         ; Time Stamp Bit 8
CAN0TXTSRH_TSR9:    equ    1                                         ; Time Stamp Bit 9
CAN0TXTSRH_TSR10:   equ    2                                         ; Time Stamp Bit 10
CAN0TXTSRH_TSR11:   equ    3                                         ; Time Stamp Bit 11
CAN0TXTSRH_TSR12:   equ    4                                         ; Time Stamp Bit 12
CAN0TXTSRH_TSR13:   equ    5                                         ; Time Stamp Bit 13
CAN0TXTSRH_TSR14:   equ    6                                         ; Time Stamp Bit 14
CAN0TXTSRH_TSR15:   equ    7                                         ; Time Stamp Bit 15
; bit position masks
mCAN0TXTSRH_TSR8:   equ    %00000001
mCAN0TXTSRH_TSR9:   equ    %00000010
mCAN0TXTSRH_TSR10:  equ    %00000100
mCAN0TXTSRH_TSR11:  equ    %00001000
mCAN0TXTSRH_TSR12:  equ    %00010000
mCAN0TXTSRH_TSR13:  equ    %00100000
mCAN0TXTSRH_TSR14:  equ    %01000000
mCAN0TXTSRH_TSR15:  equ    %10000000


;*** CAN0TXTSRL - MSCAN0 Transmit Time Stamp Register Low; 0x0000017F ***
CAN0TXTSRL:         equ    $0000017F                                ;*** CAN0TXTSRL - MSCAN0 Transmit Time Stamp Register Low; 0x0000017F ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CAN0TXTSRL_TSR0:    equ    0                                         ; Time Stamp Bit 0
CAN0TXTSRL_TSR1:    equ    1                                         ; Time Stamp Bit 1
CAN0TXTSRL_TSR2:    equ    2                                         ; Time Stamp Bit 2
CAN0TXTSRL_TSR3:    equ    3                                         ; Time Stamp Bit 3
CAN0TXTSRL_TSR4:    equ    4                                         ; Time Stamp Bit 4
CAN0TXTSRL_TSR5:    equ    5                                         ; Time Stamp Bit 5
CAN0TXTSRL_TSR6:    equ    6                                         ; Time Stamp Bit 6
CAN0TXTSRL_TSR7:    equ    7                                         ; Time Stamp Bit 7
; bit position masks
mCAN0TXTSRL_TSR0:   equ    %00000001
mCAN0TXTSRL_TSR1:   equ    %00000010
mCAN0TXTSRL_TSR2:   equ    %00000100
mCAN0TXTSRL_TSR3:   equ    %00001000
mCAN0TXTSRL_TSR4:   equ    %00010000
mCAN0TXTSRL_TSR5:   equ    %00100000
mCAN0TXTSRL_TSR6:   equ    %01000000
mCAN0TXTSRL_TSR7:   equ    %10000000


;*** PTT - Port T Data Register; 0x00000240 ***
PTT:                equ    $00000240                                ;*** PTT - Port T Data Register; 0x00000240 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTT_PTT0:           equ    0                                         ; Port T general purpose input/output data bit 0
PTT_PTT1:           equ    1                                         ; Port T general purpose input/output data bit 1
PTT_PTT2:           equ    2                                         ; Port T general purpose input/output data bit 2
PTT_PTT3:           equ    3                                         ; Port T general purpose input/output data bit 3
PTT_PTT4:           equ    4                                         ; Port T general purpose input/output data bit 4
PTT_PTT5:           equ    5                                         ; Port T general purpose input/output data bit 5
PTT_PTT6:           equ    6                                         ; Port T general purpose input/output data bit 6
PTT_PTT7:           equ    7                                         ; Port T general purpose input/output data bit 7
; bit position masks
mPTT_PTT0:          equ    %00000001
mPTT_PTT1:          equ    %00000010
mPTT_PTT2:          equ    %00000100
mPTT_PTT3:          equ    %00001000
mPTT_PTT4:          equ    %00010000
mPTT_PTT5:          equ    %00100000
mPTT_PTT6:          equ    %01000000
mPTT_PTT7:          equ    %10000000


;*** PTIT - Port T Input Register; 0x00000241 ***
PTIT:               equ    $00000241                                ;*** PTIT - Port T Input Register; 0x00000241 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTIT_PTIT0:         equ    0                                         ; Port T input data bit 0
PTIT_PTIT1:         equ    1                                         ; Port T input data bit 1
PTIT_PTIT2:         equ    2                                         ; Port T input data bit 2
PTIT_PTIT3:         equ    3                                         ; Port T input data bit 3
PTIT_PTIT4:         equ    4                                         ; Port T input data bit 4
PTIT_PTIT5:         equ    5                                         ; Port T input data bit 5
PTIT_PTIT6:         equ    6                                         ; Port T input data bit 6
PTIT_PTIT7:         equ    7                                         ; Port T input data bit 7
; bit position masks
mPTIT_PTIT0:        equ    %00000001
mPTIT_PTIT1:        equ    %00000010
mPTIT_PTIT2:        equ    %00000100
mPTIT_PTIT3:        equ    %00001000
mPTIT_PTIT4:        equ    %00010000
mPTIT_PTIT5:        equ    %00100000
mPTIT_PTIT6:        equ    %01000000
mPTIT_PTIT7:        equ    %10000000


;*** DDRT - Port T Data Direction Register; 0x00000242 ***
DDRT:               equ    $00000242                                ;*** DDRT - Port T Data Direction Register; 0x00000242 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DDRT_DDRT0:         equ    0                                         ; Port T data direction bit 0
DDRT_DDRT1:         equ    1                                         ; Port T data direction bit 1
DDRT_DDRT2:         equ    2                                         ; Port T data direction bit 2
DDRT_DDRT3:         equ    3                                         ; Port T data direction bit 3
DDRT_DDRT4:         equ    4                                         ; Port T data direction bit 4
DDRT_DDRT5:         equ    5                                         ; Port T data direction bit 5
DDRT_DDRT6:         equ    6                                         ; Port T data direction bit 6
DDRT_DDRT7:         equ    7                                         ; Port T data direction bit 7
; bit position masks
mDDRT_DDRT0:        equ    %00000001
mDDRT_DDRT1:        equ    %00000010
mDDRT_DDRT2:        equ    %00000100
mDDRT_DDRT3:        equ    %00001000
mDDRT_DDRT4:        equ    %00010000
mDDRT_DDRT5:        equ    %00100000
mDDRT_DDRT6:        equ    %01000000
mDDRT_DDRT7:        equ    %10000000


;*** RDRT - Port T Reduced Drive Register; 0x00000243 ***
RDRT:               equ    $00000243                                ;*** RDRT - Port T Reduced Drive Register; 0x00000243 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
RDRT_RDRT0:         equ    0                                         ; Port T reduced drive bit 0
RDRT_RDRT1:         equ    1                                         ; Port T reduced drive bit 1
RDRT_RDRT2:         equ    2                                         ; Port T reduced drive bit 2
RDRT_RDRT3:         equ    3                                         ; Port T reduced drive bit 3
RDRT_RDRT4:         equ    4                                         ; Port T reduced drive bit 4
RDRT_RDRT5:         equ    5                                         ; Port T reduced drive bit 5
RDRT_RDRT6:         equ    6                                         ; Port T reduced drive bit 6
RDRT_RDRT7:         equ    7                                         ; Port T reduced drive bit 7
; bit position masks
mRDRT_RDRT0:        equ    %00000001
mRDRT_RDRT1:        equ    %00000010
mRDRT_RDRT2:        equ    %00000100
mRDRT_RDRT3:        equ    %00001000
mRDRT_RDRT4:        equ    %00010000
mRDRT_RDRT5:        equ    %00100000
mRDRT_RDRT6:        equ    %01000000
mRDRT_RDRT7:        equ    %10000000


;*** PERT - Port T Pull Device Enable Register; 0x00000244 ***
PERT:               equ    $00000244                                ;*** PERT - Port T Pull Device Enable Register; 0x00000244 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PERT_PERT0:         equ    0                                         ; Port T pull device enable bit 0
PERT_PERT1:         equ    1                                         ; Port T pull device enable bit 1
PERT_PERT2:         equ    2                                         ; Port T pull device enable bit 2
PERT_PERT3:         equ    3                                         ; Port T pull device enable bit 3
PERT_PERT4:         equ    4                                         ; Port T pull device enable bit 4
PERT_PERT5:         equ    5                                         ; Port T pull device enable bit 5
PERT_PERT6:         equ    6                                         ; Port T pull device enable bit 6
PERT_PERT7:         equ    7                                         ; Port T pull device enable bit 7
; bit position masks
mPERT_PERT0:        equ    %00000001
mPERT_PERT1:        equ    %00000010
mPERT_PERT2:        equ    %00000100
mPERT_PERT3:        equ    %00001000
mPERT_PERT4:        equ    %00010000
mPERT_PERT5:        equ    %00100000
mPERT_PERT6:        equ    %01000000
mPERT_PERT7:        equ    %10000000


;*** PPST - Port T Polarity Select Register; 0x00000245 ***
PPST:               equ    $00000245                                ;*** PPST - Port T Polarity Select Register; 0x00000245 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PPST_PPST0:         equ    0                                         ; Port T pull device select bit 0
PPST_PPST1:         equ    1                                         ; Port T pull device select bit 1
PPST_PPST2:         equ    2                                         ; Port T pull device select bit 2
PPST_PPST3:         equ    3                                         ; Port T pull device select bit 3
PPST_PPST4:         equ    4                                         ; Port T pull device select bit 4
PPST_PPST5:         equ    5                                         ; Port T pull device select bit 5
PPST_PPST6:         equ    6                                         ; Port T pull device select bit 6
PPST_PPST7:         equ    7                                         ; Port T pull device select bit 7
; bit position masks
mPPST_PPST0:        equ    %00000001
mPPST_PPST1:        equ    %00000010
mPPST_PPST2:        equ    %00000100
mPPST_PPST3:        equ    %00001000
mPPST_PPST4:        equ    %00010000
mPPST_PPST5:        equ    %00100000
mPPST_PPST6:        equ    %01000000
mPPST_PPST7:        equ    %10000000


;*** PTTRR - Port T Routing Register; 0x00000247 ***
PTTRR:              equ    $00000247                                ;*** PTTRR - Port T Routing Register; 0x00000247 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTTRR_PTTRR0:       equ    0                                         ; Port T  routing
PTTRR_PTTRR1:       equ    1                                         ; Port T  routing
PTTRR_PTTRR2:       equ    2                                         ; Port T  routing
PTTRR_PTTRR4:       equ    4                                         ; Port T  routing
PTTRR_PTTRR5:       equ    5                                         ; Port T  routing
PTTRR_PTTRR6:       equ    6                                         ; Port T  routing
PTTRR_PTTRR7:       equ    7                                         ; Port T  routing
; bit position masks
mPTTRR_PTTRR0:      equ    %00000001
mPTTRR_PTTRR1:      equ    %00000010
mPTTRR_PTTRR2:      equ    %00000100
mPTTRR_PTTRR4:      equ    %00010000
mPTTRR_PTTRR5:      equ    %00100000
mPTTRR_PTTRR6:      equ    %01000000
mPTTRR_PTTRR7:      equ    %10000000


;*** PTS - Port S Data Register; 0x00000248 ***
PTS:                equ    $00000248                                ;*** PTS - Port S Data Register; 0x00000248 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTS_PTS0:           equ    0                                         ; Port S general purpose input/output data bit 0
PTS_PTS1:           equ    1                                         ; Port S general purpose input/output data bit 1
PTS_PTS2:           equ    2                                         ; Port S general purpose input/output data bit 2
PTS_PTS3:           equ    3                                         ; Port S general purpose input/output data bit 3
PTS_PTS4:           equ    4                                         ; Port S general purpose input/output data bit 4
PTS_PTS5:           equ    5                                         ; Port S general purpose input/output data bit 5
PTS_PTS6:           equ    6                                         ; Port S general purpose input/output data bit 6
PTS_PTS7:           equ    7                                         ; Port S general purpose input/output data bit 7
; bit position masks
mPTS_PTS0:          equ    %00000001
mPTS_PTS1:          equ    %00000010
mPTS_PTS2:          equ    %00000100
mPTS_PTS3:          equ    %00001000
mPTS_PTS4:          equ    %00010000
mPTS_PTS5:          equ    %00100000
mPTS_PTS6:          equ    %01000000
mPTS_PTS7:          equ    %10000000


;*** PTIS - Port S Input Register; 0x00000249 ***
PTIS:               equ    $00000249                                ;*** PTIS - Port S Input Register; 0x00000249 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTIS_PTIS0:         equ    0                                         ; Port S input data bit 0
PTIS_PTIS1:         equ    1                                         ; Port S input data bit 1
PTIS_PTIS2:         equ    2                                         ; Port S input data bit 2
PTIS_PTIS3:         equ    3                                         ; Port S input data bit 3
PTIS_PTIS4:         equ    4                                         ; Port S input data bit 4
PTIS_PTIS5:         equ    5                                         ; Port S input data bit 5
PTIS_PTIS6:         equ    6                                         ; Port S input data bit 6
PTIS_PTIS7:         equ    7                                         ; Port S input data bit 7
; bit position masks
mPTIS_PTIS0:        equ    %00000001
mPTIS_PTIS1:        equ    %00000010
mPTIS_PTIS2:        equ    %00000100
mPTIS_PTIS3:        equ    %00001000
mPTIS_PTIS4:        equ    %00010000
mPTIS_PTIS5:        equ    %00100000
mPTIS_PTIS6:        equ    %01000000
mPTIS_PTIS7:        equ    %10000000


;*** DDRS - Port S Data Direction Register; 0x0000024A ***
DDRS:               equ    $0000024A                                ;*** DDRS - Port S Data Direction Register; 0x0000024A ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DDRS_DDRS0:         equ    0                                         ; Port S data direction bit 0
DDRS_DDRS1:         equ    1                                         ; Port S data direction bit 1
DDRS_DDRS2:         equ    2                                         ; Port S data direction bit 2
DDRS_DDRS3:         equ    3                                         ; Port S data direction bit 3
DDRS_DDRS4:         equ    4                                         ; Port S data direction bit 4
DDRS_DDRS5:         equ    5                                         ; Port S data direction bit 5
DDRS_DDRS6:         equ    6                                         ; Port S data direction bit 6
DDRS_DDRS7:         equ    7                                         ; Port S data direction bit 7
; bit position masks
mDDRS_DDRS0:        equ    %00000001
mDDRS_DDRS1:        equ    %00000010
mDDRS_DDRS2:        equ    %00000100
mDDRS_DDRS3:        equ    %00001000
mDDRS_DDRS4:        equ    %00010000
mDDRS_DDRS5:        equ    %00100000
mDDRS_DDRS6:        equ    %01000000
mDDRS_DDRS7:        equ    %10000000


;*** RDRS - Port S Reduced Drive Register; 0x0000024B ***
RDRS:               equ    $0000024B                                ;*** RDRS - Port S Reduced Drive Register; 0x0000024B ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
RDRS_RDRS0:         equ    0                                         ; Port S reduced drive bit 0
RDRS_RDRS1:         equ    1                                         ; Port S reduced drive bit 1
RDRS_RDRS2:         equ    2                                         ; Port S reduced drive bit 2
RDRS_RDRS3:         equ    3                                         ; Port S reduced drive bit 3
RDRS_RDRS4:         equ    4                                         ; Port S reduced drive bit 4
RDRS_RDRS5:         equ    5                                         ; Port S reduced drive bit 5
RDRS_RDRS6:         equ    6                                         ; Port S reduced drive bit 6
RDRS_RDRS7:         equ    7                                         ; Port S reduced drive bit 7
; bit position masks
mRDRS_RDRS0:        equ    %00000001
mRDRS_RDRS1:        equ    %00000010
mRDRS_RDRS2:        equ    %00000100
mRDRS_RDRS3:        equ    %00001000
mRDRS_RDRS4:        equ    %00010000
mRDRS_RDRS5:        equ    %00100000
mRDRS_RDRS6:        equ    %01000000
mRDRS_RDRS7:        equ    %10000000


;*** PERS - Port S Pull Device Enable Register; 0x0000024C ***
PERS:               equ    $0000024C                                ;*** PERS - Port S Pull Device Enable Register; 0x0000024C ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PERS_PERS0:         equ    0                                         ; Port S pull device enable bit 0
PERS_PERS1:         equ    1                                         ; Port S pull device enable bit 1
PERS_PERS2:         equ    2                                         ; Port S pull device enable bit 2
PERS_PERS3:         equ    3                                         ; Port S pull device enable bit 3
PERS_PERS4:         equ    4                                         ; Port S pull device enable bit 4
PERS_PERS5:         equ    5                                         ; Port S pull device enable bit 5
PERS_PERS6:         equ    6                                         ; Port S pull device enable bit 6
PERS_PERS7:         equ    7                                         ; Port S pull device enable bit 7
; bit position masks
mPERS_PERS0:        equ    %00000001
mPERS_PERS1:        equ    %00000010
mPERS_PERS2:        equ    %00000100
mPERS_PERS3:        equ    %00001000
mPERS_PERS4:        equ    %00010000
mPERS_PERS5:        equ    %00100000
mPERS_PERS6:        equ    %01000000
mPERS_PERS7:        equ    %10000000


;*** PPSS - Port S Polarity Select Register; 0x0000024D ***
PPSS:               equ    $0000024D                                ;*** PPSS - Port S Polarity Select Register; 0x0000024D ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PPSS_PPSS0:         equ    0                                         ; Port S pull device select bit 0
PPSS_PPSS1:         equ    1                                         ; Port S pull device select bit 1
PPSS_PPSS2:         equ    2                                         ; Port S pull device select bit 2
PPSS_PPSS3:         equ    3                                         ; Port S pull device select bit 3
PPSS_PPSS4:         equ    4                                         ; Port S pull device select bit 4
PPSS_PPSS5:         equ    5                                         ; Port S pull device select bit 5
PPSS_PPSS6:         equ    6                                         ; Port S pull device select bit 6
PPSS_PPSS7:         equ    7                                         ; Port S pull device select bit 7
; bit position masks
mPPSS_PPSS0:        equ    %00000001
mPPSS_PPSS1:        equ    %00000010
mPPSS_PPSS2:        equ    %00000100
mPPSS_PPSS3:        equ    %00001000
mPPSS_PPSS4:        equ    %00010000
mPPSS_PPSS5:        equ    %00100000
mPPSS_PPSS6:        equ    %01000000
mPPSS_PPSS7:        equ    %10000000


;*** WOMS - Port S Wired-Or Mode Register; 0x0000024E ***
WOMS:               equ    $0000024E                                ;*** WOMS - Port S Wired-Or Mode Register; 0x0000024E ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
WOMS_WOMS0:         equ    0                                         ; Port S wired-or mode bit 0
WOMS_WOMS1:         equ    1                                         ; Port S wired-or mode bit 1
WOMS_WOMS2:         equ    2                                         ; Port S wired-or mode bit 2
WOMS_WOMS3:         equ    3                                         ; Port S wired-or mode bit 3
WOMS_WOMS4:         equ    4                                         ; Port S wired-or mode bit 4
WOMS_WOMS5:         equ    5                                         ; Port S wired-or mode bit 5
WOMS_WOMS6:         equ    6                                         ; Port S wired-or mode bit 6
WOMS_WOMS7:         equ    7                                         ; Port S wired-or mode bit 7
; bit position masks
mWOMS_WOMS0:        equ    %00000001
mWOMS_WOMS1:        equ    %00000010
mWOMS_WOMS2:        equ    %00000100
mWOMS_WOMS3:        equ    %00001000
mWOMS_WOMS4:        equ    %00010000
mWOMS_WOMS5:        equ    %00100000
mWOMS_WOMS6:        equ    %01000000
mWOMS_WOMS7:        equ    %10000000


;*** PTM - Port M Data Register; 0x00000250 ***
PTM:                equ    $00000250                                ;*** PTM - Port M Data Register; 0x00000250 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTM_PTM0:           equ    0                                         ; Port M general purpose input/output data bit 0
PTM_PTM1:           equ    1                                         ; Port M general purpose input/output data bit 1
PTM_PTM2:           equ    2                                         ; Port M general purpose input/output data bit 2
PTM_PTM3:           equ    3                                         ; Port M general purpose input/output data bit 3
PTM_PTM4:           equ    4                                         ; Port M general purpose input/output data bit 4
PTM_PTM5:           equ    5                                         ; Port M general purpose input/output data bit 5
PTM_PTM6:           equ    6                                         ; Port M general purpose input/output data bit 6
PTM_PTM7:           equ    7                                         ; Port M general purpose input/output data bit 7
; bit position masks
mPTM_PTM0:          equ    %00000001
mPTM_PTM1:          equ    %00000010
mPTM_PTM2:          equ    %00000100
mPTM_PTM3:          equ    %00001000
mPTM_PTM4:          equ    %00010000
mPTM_PTM5:          equ    %00100000
mPTM_PTM6:          equ    %01000000
mPTM_PTM7:          equ    %10000000


;*** PTIM - Port M Input Register; 0x00000251 ***
PTIM:               equ    $00000251                                ;*** PTIM - Port M Input Register; 0x00000251 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTIM_PTIM0:         equ    0                                         ; Port M input data bit 0
PTIM_PTIM1:         equ    1                                         ; Port M input data bit 1
PTIM_PTIM2:         equ    2                                         ; Port M input data bit 2
PTIM_PTIM3:         equ    3                                         ; Port M input data bit 3
PTIM_PTIM4:         equ    4                                         ; Port M input data bit 4
PTIM_PTIM5:         equ    5                                         ; Port M input data bit 5
PTIM_PTIM6:         equ    6                                         ; Port M input data bit 6
PTIM_PTIM7:         equ    7                                         ; Port M input data bit 7
; bit position masks
mPTIM_PTIM0:        equ    %00000001
mPTIM_PTIM1:        equ    %00000010
mPTIM_PTIM2:        equ    %00000100
mPTIM_PTIM3:        equ    %00001000
mPTIM_PTIM4:        equ    %00010000
mPTIM_PTIM5:        equ    %00100000
mPTIM_PTIM6:        equ    %01000000
mPTIM_PTIM7:        equ    %10000000


;*** DDRM - Port M Data Direction Register; 0x00000252 ***
DDRM:               equ    $00000252                                ;*** DDRM - Port M Data Direction Register; 0x00000252 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DDRM_DDRM0:         equ    0                                         ; Port M data direction bit 0
DDRM_DDRM1:         equ    1                                         ; Port M data direction bit 1
DDRM_DDRM2:         equ    2                                         ; Port M data direction bit 2
DDRM_DDRM3:         equ    3                                         ; Port M data direction bit 3
DDRM_DDRM4:         equ    4                                         ; Port M data direction bit 4
DDRM_DDRM5:         equ    5                                         ; Port M data direction bit 5
DDRM_DDRM6:         equ    6                                         ; Port M data direction bit 6
DDRM_DDRM7:         equ    7                                         ; Port M data direction bit 7
; bit position masks
mDDRM_DDRM0:        equ    %00000001
mDDRM_DDRM1:        equ    %00000010
mDDRM_DDRM2:        equ    %00000100
mDDRM_DDRM3:        equ    %00001000
mDDRM_DDRM4:        equ    %00010000
mDDRM_DDRM5:        equ    %00100000
mDDRM_DDRM6:        equ    %01000000
mDDRM_DDRM7:        equ    %10000000


;*** RDRM - Port M Reduced Drive Register; 0x00000253 ***
RDRM:               equ    $00000253                                ;*** RDRM - Port M Reduced Drive Register; 0x00000253 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
RDRM_RDRM0:         equ    0                                         ; Port M reduced drive bit 0
RDRM_RDRM1:         equ    1                                         ; Port M reduced drive bit 1
RDRM_RDRM2:         equ    2                                         ; Port M reduced drive bit 2
RDRM_RDRM3:         equ    3                                         ; Port M reduced drive bit 3
RDRM_RDRM4:         equ    4                                         ; Port M reduced drive bit 4
RDRM_RDRM5:         equ    5                                         ; Port M reduced drive bit 5
RDRM_RDRM6:         equ    6                                         ; Port M reduced drive bit 6
RDRM_RDRM7:         equ    7                                         ; Port M reduced drive bit 7
; bit position masks
mRDRM_RDRM0:        equ    %00000001
mRDRM_RDRM1:        equ    %00000010
mRDRM_RDRM2:        equ    %00000100
mRDRM_RDRM3:        equ    %00001000
mRDRM_RDRM4:        equ    %00010000
mRDRM_RDRM5:        equ    %00100000
mRDRM_RDRM6:        equ    %01000000
mRDRM_RDRM7:        equ    %10000000


;*** PERM - Port M Pull Device Enable Register; 0x00000254 ***
PERM:               equ    $00000254                                ;*** PERM - Port M Pull Device Enable Register; 0x00000254 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PERM_PERM0:         equ    0                                         ; Port M pull device enable bit 0
PERM_PERM1:         equ    1                                         ; Port M pull device enable bit 1
PERM_PERM2:         equ    2                                         ; Port M pull device enable bit 2
PERM_PERM3:         equ    3                                         ; Port M pull device enable bit 3
PERM_PERM4:         equ    4                                         ; Port M pull device enable bit 4
PERM_PERM5:         equ    5                                         ; Port M pull device enable bit 5
PERM_PERM6:         equ    6                                         ; Port M pull device enable bit 6
PERM_PERM7:         equ    7                                         ; Port M pull device enable bit 7
; bit position masks
mPERM_PERM0:        equ    %00000001
mPERM_PERM1:        equ    %00000010
mPERM_PERM2:        equ    %00000100
mPERM_PERM3:        equ    %00001000
mPERM_PERM4:        equ    %00010000
mPERM_PERM5:        equ    %00100000
mPERM_PERM6:        equ    %01000000
mPERM_PERM7:        equ    %10000000


;*** PPSM - Port M Polarity Select Register; 0x00000255 ***
PPSM:               equ    $00000255                                ;*** PPSM - Port M Polarity Select Register; 0x00000255 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PPSM_PPSM0:         equ    0                                         ; Port M pull device select bit 0
PPSM_PPSM1:         equ    1                                         ; Port M pull device select bit 1
PPSM_PPSM2:         equ    2                                         ; Port M pull device select bit 2
PPSM_PPSM3:         equ    3                                         ; Port M pull device select bit 3
PPSM_PPSM4:         equ    4                                         ; Port M pull device select bit 4
PPSM_PPSM5:         equ    5                                         ; Port M pull device select bit 5
PPSM_PPSM6:         equ    6                                         ; Port M pull device select bit 6
PPSM_PPSM7:         equ    7                                         ; Port M pull device select bit 7
; bit position masks
mPPSM_PPSM0:        equ    %00000001
mPPSM_PPSM1:        equ    %00000010
mPPSM_PPSM2:        equ    %00000100
mPPSM_PPSM3:        equ    %00001000
mPPSM_PPSM4:        equ    %00010000
mPPSM_PPSM5:        equ    %00100000
mPPSM_PPSM6:        equ    %01000000
mPPSM_PPSM7:        equ    %10000000


;*** WOMM - Port M Wired-Or Mode Register; 0x00000256 ***
WOMM:               equ    $00000256                                ;*** WOMM - Port M Wired-Or Mode Register; 0x00000256 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
WOMM_WOMM0:         equ    0                                         ; Port M wired-or mode bit 0
WOMM_WOMM1:         equ    1                                         ; Port M wired-or mode bit 1
WOMM_WOMM2:         equ    2                                         ; Port M wired-or mode bit 2
WOMM_WOMM3:         equ    3                                         ; Port M wired-or mode bit 3
WOMM_WOMM4:         equ    4                                         ; Port M wired-or mode bit 4
WOMM_WOMM5:         equ    5                                         ; Port M wired-or mode bit 5
WOMM_WOMM6:         equ    6                                         ; Port M wired-or mode bit 6
WOMM_WOMM7:         equ    7                                         ; Port M wired-or mode bit 7
; bit position masks
mWOMM_WOMM0:        equ    %00000001
mWOMM_WOMM1:        equ    %00000010
mWOMM_WOMM2:        equ    %00000100
mWOMM_WOMM3:        equ    %00001000
mWOMM_WOMM4:        equ    %00010000
mWOMM_WOMM5:        equ    %00100000
mWOMM_WOMM6:        equ    %01000000
mWOMM_WOMM7:        equ    %10000000


;*** MODRR - Module Routing Register; 0x00000257 ***
MODRR:              equ    $00000257                                ;*** MODRR - Module Routing Register; 0x00000257 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
MODRR_MODRR4:       equ    4                                         ; Module Routing bit 4
MODRR_MODRR6:       equ    6                                         ; Module Routing bit 6
MODRR_MODRR7:       equ    7                                         ; Module Routing bit 7
; bit position masks
mMODRR_MODRR4:      equ    %00010000
mMODRR_MODRR6:      equ    %01000000
mMODRR_MODRR7:      equ    %10000000


;*** PTP - Port P Data Register; 0x00000258 ***
PTP:                equ    $00000258                                ;*** PTP - Port P Data Register; 0x00000258 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTP_PTP0:           equ    0                                         ; Port P general purpose input/output data bit 0
PTP_PTP1:           equ    1                                         ; Port P general purpose input/output data bit 1
PTP_PTP2:           equ    2                                         ; Port P general purpose input/output data bit 2
PTP_PTP3:           equ    3                                         ; Port P general purpose input/output data bit 3
PTP_PTP4:           equ    4                                         ; Port P general purpose input/output data bit 4
PTP_PTP5:           equ    5                                         ; Port P general purpose input/output data bit 5
PTP_PTP6:           equ    6                                         ; Port P general purpose input/output data bit 6
PTP_PTP7:           equ    7                                         ; Port P general purpose input/output data bit 7
; bit position masks
mPTP_PTP0:          equ    %00000001
mPTP_PTP1:          equ    %00000010
mPTP_PTP2:          equ    %00000100
mPTP_PTP3:          equ    %00001000
mPTP_PTP4:          equ    %00010000
mPTP_PTP5:          equ    %00100000
mPTP_PTP6:          equ    %01000000
mPTP_PTP7:          equ    %10000000


;*** PTIP - Port P Input Register; 0x00000259 ***
PTIP:               equ    $00000259                                ;*** PTIP - Port P Input Register; 0x00000259 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTIP_PTIP0:         equ    0                                         ; Port P input data bit 0
PTIP_PTIP1:         equ    1                                         ; Port P input data bit 1
PTIP_PTIP2:         equ    2                                         ; Port P input data bit 2
PTIP_PTIP3:         equ    3                                         ; Port P input data bit 3
PTIP_PTIP4:         equ    4                                         ; Port P input data bit 4
PTIP_PTIP5:         equ    5                                         ; Port P input data bit 5
PTIP_PTIP6:         equ    6                                         ; Port P input data bit 6
PTIP_PTIP7:         equ    7                                         ; Port P input data bit 7
; bit position masks
mPTIP_PTIP0:        equ    %00000001
mPTIP_PTIP1:        equ    %00000010
mPTIP_PTIP2:        equ    %00000100
mPTIP_PTIP3:        equ    %00001000
mPTIP_PTIP4:        equ    %00010000
mPTIP_PTIP5:        equ    %00100000
mPTIP_PTIP6:        equ    %01000000
mPTIP_PTIP7:        equ    %10000000


;*** DDRP - Port P Data Direction Register; 0x0000025A ***
DDRP:               equ    $0000025A                                ;*** DDRP - Port P Data Direction Register; 0x0000025A ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DDRP_DDRP0:         equ    0                                         ; Port P data direction bit 0
DDRP_DDRP1:         equ    1                                         ; Port P data direction bit 1
DDRP_DDRP2:         equ    2                                         ; Port P data direction bit 2
DDRP_DDRP3:         equ    3                                         ; Port P data direction bit 3
DDRP_DDRP4:         equ    4                                         ; Port P data direction bit 4
DDRP_DDRP5:         equ    5                                         ; Port P data direction bit 5
DDRP_DDRP6:         equ    6                                         ; Port P data direction bit 6
DDRP_DDRP7:         equ    7                                         ; Port P data direction bit 7
; bit position masks
mDDRP_DDRP0:        equ    %00000001
mDDRP_DDRP1:        equ    %00000010
mDDRP_DDRP2:        equ    %00000100
mDDRP_DDRP3:        equ    %00001000
mDDRP_DDRP4:        equ    %00010000
mDDRP_DDRP5:        equ    %00100000
mDDRP_DDRP6:        equ    %01000000
mDDRP_DDRP7:        equ    %10000000


;*** RDRP - Port P Reduced Drive Register; 0x0000025B ***
RDRP:               equ    $0000025B                                ;*** RDRP - Port P Reduced Drive Register; 0x0000025B ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
RDRP_RDRP0:         equ    0                                         ; Port P reduced drive bit 0
RDRP_RDRP1:         equ    1                                         ; Port P reduced drive bit 1
RDRP_RDRP2:         equ    2                                         ; Port P reduced drive bit 2
RDRP_RDRP3:         equ    3                                         ; Port P reduced drive bit 3
RDRP_RDRP4:         equ    4                                         ; Port P reduced drive bit 4
RDRP_RDRP5:         equ    5                                         ; Port P reduced drive bit 5
RDRP_RDRP6:         equ    6                                         ; Port P reduced drive bit 6
RDRP_RDRP7:         equ    7                                         ; Port P reduced drive bit 7
; bit position masks
mRDRP_RDRP0:        equ    %00000001
mRDRP_RDRP1:        equ    %00000010
mRDRP_RDRP2:        equ    %00000100
mRDRP_RDRP3:        equ    %00001000
mRDRP_RDRP4:        equ    %00010000
mRDRP_RDRP5:        equ    %00100000
mRDRP_RDRP6:        equ    %01000000
mRDRP_RDRP7:        equ    %10000000


;*** PERP - Port P Pull Device Enable Register; 0x0000025C ***
PERP:               equ    $0000025C                                ;*** PERP - Port P Pull Device Enable Register; 0x0000025C ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PERP_PERP0:         equ    0                                         ; Port P pull device enable bit 0
PERP_PERP1:         equ    1                                         ; Port P pull device enable bit 1
PERP_PERP2:         equ    2                                         ; Port P pull device enable bit 2
PERP_PERP3:         equ    3                                         ; Port P pull device enable bit 3
PERP_PERP4:         equ    4                                         ; Port P pull device enable bit 4
PERP_PERP5:         equ    5                                         ; Port P pull device enable bit 5
PERP_PERP6:         equ    6                                         ; Port P pull device enable bit 6
PERP_PERP7:         equ    7                                         ; Port P pull device enable bit 7
; bit position masks
mPERP_PERP0:        equ    %00000001
mPERP_PERP1:        equ    %00000010
mPERP_PERP2:        equ    %00000100
mPERP_PERP3:        equ    %00001000
mPERP_PERP4:        equ    %00010000
mPERP_PERP5:        equ    %00100000
mPERP_PERP6:        equ    %01000000
mPERP_PERP7:        equ    %10000000


;*** PPSP - Port P Polarity Select Register; 0x0000025D ***
PPSP:               equ    $0000025D                                ;*** PPSP - Port P Polarity Select Register; 0x0000025D ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PPSP_PPSP0:         equ    0                                         ; Port P pull device select bit 0
PPSP_PPSP1:         equ    1                                         ; Port P pull device select bit 1
PPSP_PPSP2:         equ    2                                         ; Port P pull device select bit 2
PPSP_PPSP3:         equ    3                                         ; Port P pull device select bit 3
PPSP_PPSP4:         equ    4                                         ; Port P pull device select bit 4
PPSP_PPSP5:         equ    5                                         ; Port P pull device select bit 5
PPSP_PPSP6:         equ    6                                         ; Port P pull device select bit 6
PPSP_PPSP7:         equ    7                                         ; Port P pull device select bit 7
; bit position masks
mPPSP_PPSP0:        equ    %00000001
mPPSP_PPSP1:        equ    %00000010
mPPSP_PPSP2:        equ    %00000100
mPPSP_PPSP3:        equ    %00001000
mPPSP_PPSP4:        equ    %00010000
mPPSP_PPSP5:        equ    %00100000
mPPSP_PPSP6:        equ    %01000000
mPPSP_PPSP7:        equ    %10000000


;*** PIEP - Port P Interrupt Enable Register; 0x0000025E ***
PIEP:               equ    $0000025E                                ;*** PIEP - Port P Interrupt Enable Register; 0x0000025E ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PIEP_PIEP0:         equ    0                                         ; Port P interrupt enable bit 0
PIEP_PIEP1:         equ    1                                         ; Port P interrupt enable bit 1
PIEP_PIEP2:         equ    2                                         ; Port P interrupt enable bit 2
PIEP_PIEP3:         equ    3                                         ; Port P interrupt enable bit 3
PIEP_PIEP4:         equ    4                                         ; Port P interrupt enable bit 4
PIEP_PIEP5:         equ    5                                         ; Port P interrupt enable bit 5
PIEP_PIEP6:         equ    6                                         ; Port P interrupt enable bit 6
PIEP_PIEP7:         equ    7                                         ; Port P interrupt enable bit 7
; bit position masks
mPIEP_PIEP0:        equ    %00000001
mPIEP_PIEP1:        equ    %00000010
mPIEP_PIEP2:        equ    %00000100
mPIEP_PIEP3:        equ    %00001000
mPIEP_PIEP4:        equ    %00010000
mPIEP_PIEP5:        equ    %00100000
mPIEP_PIEP6:        equ    %01000000
mPIEP_PIEP7:        equ    %10000000


;*** PIFP - Port P Interrupt Flag Register; 0x0000025F ***
PIFP:               equ    $0000025F                                ;*** PIFP - Port P Interrupt Flag Register; 0x0000025F ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PIFP_PIFP0:         equ    0                                         ; Port P interrupt flag bit 0
PIFP_PIFP1:         equ    1                                         ; Port P interrupt flag bit 1
PIFP_PIFP2:         equ    2                                         ; Port P interrupt flag bit 2
PIFP_PIFP3:         equ    3                                         ; Port P interrupt flag bit 3
PIFP_PIFP4:         equ    4                                         ; Port P interrupt flag bit 4
PIFP_PIFP5:         equ    5                                         ; Port P interrupt flag bit 5
PIFP_PIFP6:         equ    6                                         ; Port P interrupt flag bit 6
PIFP_PIFP7:         equ    7                                         ; Port P interrupt flag bit 7
; bit position masks
mPIFP_PIFP0:        equ    %00000001
mPIFP_PIFP1:        equ    %00000010
mPIFP_PIFP2:        equ    %00000100
mPIFP_PIFP3:        equ    %00001000
mPIFP_PIFP4:        equ    %00010000
mPIFP_PIFP5:        equ    %00100000
mPIFP_PIFP6:        equ    %01000000
mPIFP_PIFP7:        equ    %10000000


;*** PTH - Port H Data Register; 0x00000260 ***
PTH:                equ    $00000260                                ;*** PTH - Port H Data Register; 0x00000260 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTH_PTH0:           equ    0                                         ; Port H general purpose input/output data bit 0
PTH_PTH1:           equ    1                                         ; Port H general purpose input/output data bit 1
PTH_PTH2:           equ    2                                         ; Port H general purpose input/output data bit 2
PTH_PTH3:           equ    3                                         ; Port H general purpose input/output data bit 3
PTH_PTH4:           equ    4                                         ; Port H general purpose input/output data bit 4
PTH_PTH5:           equ    5                                         ; Port H general purpose input/output data bit 5
PTH_PTH6:           equ    6                                         ; Port H general purpose input/output data bit 6
PTH_PTH7:           equ    7                                         ; Port H general purpose input/output data bit 7
; bit position masks
mPTH_PTH0:          equ    %00000001
mPTH_PTH1:          equ    %00000010
mPTH_PTH2:          equ    %00000100
mPTH_PTH3:          equ    %00001000
mPTH_PTH4:          equ    %00010000
mPTH_PTH5:          equ    %00100000
mPTH_PTH6:          equ    %01000000
mPTH_PTH7:          equ    %10000000


;*** PTIH - Port H Input Register; 0x00000261 ***
PTIH:               equ    $00000261                                ;*** PTIH - Port H Input Register; 0x00000261 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTIH_PTIH0:         equ    0                                         ; Port H input data bit 0
PTIH_PTIH1:         equ    1                                         ; Port H input data bit 1
PTIH_PTIH2:         equ    2                                         ; Port H input data bit 2
PTIH_PTIH3:         equ    3                                         ; Port H input data bit 3
PTIH_PTIH4:         equ    4                                         ; Port H input data bit 4
PTIH_PTIH5:         equ    5                                         ; Port H input data bit 5
PTIH_PTIH6:         equ    6                                         ; Port H input data bit 6
PTIH_PTIH7:         equ    7                                         ; Port H input data bit 7
; bit position masks
mPTIH_PTIH0:        equ    %00000001
mPTIH_PTIH1:        equ    %00000010
mPTIH_PTIH2:        equ    %00000100
mPTIH_PTIH3:        equ    %00001000
mPTIH_PTIH4:        equ    %00010000
mPTIH_PTIH5:        equ    %00100000
mPTIH_PTIH6:        equ    %01000000
mPTIH_PTIH7:        equ    %10000000


;*** DDRH - Port H Data Direction Register; 0x00000262 ***
DDRH:               equ    $00000262                                ;*** DDRH - Port H Data Direction Register; 0x00000262 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DDRH_DDRH0:         equ    0                                         ; Port H data direction bit 0
DDRH_DDRH1:         equ    1                                         ; Port H data direction bit 1
DDRH_DDRH2:         equ    2                                         ; Port H data direction bit 2
DDRH_DDRH3:         equ    3                                         ; Port H data direction bit 3
DDRH_DDRH4:         equ    4                                         ; Port H data direction bit 4
DDRH_DDRH5:         equ    5                                         ; Port H data direction bit 5
DDRH_DDRH6:         equ    6                                         ; Port H data direction bit 6
DDRH_DDRH7:         equ    7                                         ; Port H data direction bit 7
; bit position masks
mDDRH_DDRH0:        equ    %00000001
mDDRH_DDRH1:        equ    %00000010
mDDRH_DDRH2:        equ    %00000100
mDDRH_DDRH3:        equ    %00001000
mDDRH_DDRH4:        equ    %00010000
mDDRH_DDRH5:        equ    %00100000
mDDRH_DDRH6:        equ    %01000000
mDDRH_DDRH7:        equ    %10000000


;*** RDRH - Port H Reduced Drive Register; 0x00000263 ***
RDRH:               equ    $00000263                                ;*** RDRH - Port H Reduced Drive Register; 0x00000263 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
RDRH_RDRH0:         equ    0                                         ; Port H reduced drive bit 0
RDRH_RDRH1:         equ    1                                         ; Port H reduced drive bit 1
RDRH_RDRH2:         equ    2                                         ; Port H reduced drive bit 2
RDRH_RDRH3:         equ    3                                         ; Port H reduced drive bit 3
RDRH_RDRH4:         equ    4                                         ; Port H reduced drive bit 4
RDRH_RDRH5:         equ    5                                         ; Port H reduced drive bit 5
RDRH_RDRH6:         equ    6                                         ; Port H reduced drive bit 6
RDRH_RDRH7:         equ    7                                         ; Port H reduced drive bit 7
; bit position masks
mRDRH_RDRH0:        equ    %00000001
mRDRH_RDRH1:        equ    %00000010
mRDRH_RDRH2:        equ    %00000100
mRDRH_RDRH3:        equ    %00001000
mRDRH_RDRH4:        equ    %00010000
mRDRH_RDRH5:        equ    %00100000
mRDRH_RDRH6:        equ    %01000000
mRDRH_RDRH7:        equ    %10000000


;*** PERH - Port H Pull Device Enable Register; 0x00000264 ***
PERH:               equ    $00000264                                ;*** PERH - Port H Pull Device Enable Register; 0x00000264 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PERH_PERH0:         equ    0                                         ; Port H pull device enable bit 0
PERH_PERH1:         equ    1                                         ; Port H pull device enable bit 1
PERH_PERH2:         equ    2                                         ; Port H pull device enable bit 2
PERH_PERH3:         equ    3                                         ; Port H pull device enable bit 3
PERH_PERH4:         equ    4                                         ; Port H pull device enable bit 4
PERH_PERH5:         equ    5                                         ; Port H pull device enable bit 5
PERH_PERH6:         equ    6                                         ; Port H pull device enable bit 6
PERH_PERH7:         equ    7                                         ; Port H pull device enable bit 7
; bit position masks
mPERH_PERH0:        equ    %00000001
mPERH_PERH1:        equ    %00000010
mPERH_PERH2:        equ    %00000100
mPERH_PERH3:        equ    %00001000
mPERH_PERH4:        equ    %00010000
mPERH_PERH5:        equ    %00100000
mPERH_PERH6:        equ    %01000000
mPERH_PERH7:        equ    %10000000


;*** PPSH - Port H Polarity Select Register; 0x00000265 ***
PPSH:               equ    $00000265                                ;*** PPSH - Port H Polarity Select Register; 0x00000265 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PPSH_PPSH0:         equ    0                                         ; Port H pull device select bit 0
PPSH_PPSH1:         equ    1                                         ; Port H pull device select bit 1
PPSH_PPSH2:         equ    2                                         ; Port H pull device select bit 2
PPSH_PPSH3:         equ    3                                         ; Port H pull device select bit 3
PPSH_PPSH4:         equ    4                                         ; Port H pull device select bit 4
PPSH_PPSH5:         equ    5                                         ; Port H pull device select bit 5
PPSH_PPSH6:         equ    6                                         ; Port H pull device select bit 6
PPSH_PPSH7:         equ    7                                         ; Port H pull device select bit 7
; bit position masks
mPPSH_PPSH0:        equ    %00000001
mPPSH_PPSH1:        equ    %00000010
mPPSH_PPSH2:        equ    %00000100
mPPSH_PPSH3:        equ    %00001000
mPPSH_PPSH4:        equ    %00010000
mPPSH_PPSH5:        equ    %00100000
mPPSH_PPSH6:        equ    %01000000
mPPSH_PPSH7:        equ    %10000000


;*** PIEH - Port H Interrupt Enable Register; 0x00000266 ***
PIEH:               equ    $00000266                                ;*** PIEH - Port H Interrupt Enable Register; 0x00000266 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PIEH_PIEH0:         equ    0                                         ; Port H interrupt enable bit 0
PIEH_PIEH1:         equ    1                                         ; Port H interrupt enable bit 1
PIEH_PIEH2:         equ    2                                         ; Port H interrupt enable bit 2
PIEH_PIEH3:         equ    3                                         ; Port H interrupt enable bit 3
PIEH_PIEH4:         equ    4                                         ; Port H interrupt enable bit 4
PIEH_PIEH5:         equ    5                                         ; Port H interrupt enable bit 5
PIEH_PIEH6:         equ    6                                         ; Port H interrupt enable bit 6
PIEH_PIEH7:         equ    7                                         ; Port H interrupt enable bit 7
; bit position masks
mPIEH_PIEH0:        equ    %00000001
mPIEH_PIEH1:        equ    %00000010
mPIEH_PIEH2:        equ    %00000100
mPIEH_PIEH3:        equ    %00001000
mPIEH_PIEH4:        equ    %00010000
mPIEH_PIEH5:        equ    %00100000
mPIEH_PIEH6:        equ    %01000000
mPIEH_PIEH7:        equ    %10000000


;*** PIFH - Port H Interrupt Flag Register; 0x00000267 ***
PIFH:               equ    $00000267                                ;*** PIFH - Port H Interrupt Flag Register; 0x00000267 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PIFH_PIFH0:         equ    0                                         ; Port H interrupt flag bit 0
PIFH_PIFH1:         equ    1                                         ; Port H interrupt flag bit 1
PIFH_PIFH2:         equ    2                                         ; Port H interrupt flag bit 2
PIFH_PIFH3:         equ    3                                         ; Port H interrupt flag bit 3
PIFH_PIFH4:         equ    4                                         ; Port H interrupt flag bit 4
PIFH_PIFH5:         equ    5                                         ; Port H interrupt flag bit 5
PIFH_PIFH6:         equ    6                                         ; Port H interrupt flag bit 6
PIFH_PIFH7:         equ    7                                         ; Port H interrupt flag bit 7
; bit position masks
mPIFH_PIFH0:        equ    %00000001
mPIFH_PIFH1:        equ    %00000010
mPIFH_PIFH2:        equ    %00000100
mPIFH_PIFH3:        equ    %00001000
mPIFH_PIFH4:        equ    %00010000
mPIFH_PIFH5:        equ    %00100000
mPIFH_PIFH6:        equ    %01000000
mPIFH_PIFH7:        equ    %10000000


;*** PTJ - Port J Data Register; 0x00000268 ***
PTJ:                equ    $00000268                                ;*** PTJ - Port J Data Register; 0x00000268 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTJ_PTJ0:           equ    0                                         ; Port J general purpose input/output data bit 0
PTJ_PTJ1:           equ    1                                         ; Port J general purpose input/output data bit 1
PTJ_PTJ6:           equ    6                                         ; Port J general purpose input/output data bit 6
PTJ_PTJ7:           equ    7                                         ; Port J general purpose input/output data bit 7
; bit position masks
mPTJ_PTJ0:          equ    %00000001
mPTJ_PTJ1:          equ    %00000010
mPTJ_PTJ6:          equ    %01000000
mPTJ_PTJ7:          equ    %10000000


;*** PTIJ - Port J Input Register; 0x00000269 ***
PTIJ:               equ    $00000269                                ;*** PTIJ - Port J Input Register; 0x00000269 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTIJ_PTIJ0:         equ    0                                         ; Port J input data bit 0
PTIJ_PTIJ1:         equ    1                                         ; Port J input data bit 1
PTIJ_PTIJ6:         equ    6                                         ; Port J input data bit 6
PTIJ_PTIJ7:         equ    7                                         ; Port J input data bit 7
; bit position masks
mPTIJ_PTIJ0:        equ    %00000001
mPTIJ_PTIJ1:        equ    %00000010
mPTIJ_PTIJ6:        equ    %01000000
mPTIJ_PTIJ7:        equ    %10000000


;*** DDRJ - Port J Data Direction Register; 0x0000026A ***
DDRJ:               equ    $0000026A                                ;*** DDRJ - Port J Data Direction Register; 0x0000026A ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DDRJ_DDRJ0:         equ    0                                         ; Port J data direction bit 0
DDRJ_DDRJ1:         equ    1                                         ; Port J data direction bit 1
DDRJ_DDRJ6:         equ    6                                         ; Port J data direction bit 6
DDRJ_DDRJ7:         equ    7                                         ; Port J data direction bit 7
; bit position masks
mDDRJ_DDRJ0:        equ    %00000001
mDDRJ_DDRJ1:        equ    %00000010
mDDRJ_DDRJ6:        equ    %01000000
mDDRJ_DDRJ7:        equ    %10000000


;*** RDRJ - Port J Reduced Drive Register; 0x0000026B ***
RDRJ:               equ    $0000026B                                ;*** RDRJ - Port J Reduced Drive Register; 0x0000026B ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
RDRJ_RDRJ0:         equ    0                                         ; Port J reduced drive bit 0
RDRJ_RDRJ1:         equ    1                                         ; Port J reduced drive bit 1
RDRJ_RDRJ6:         equ    6                                         ; Port J reduced drive bit 6
RDRJ_RDRJ7:         equ    7                                         ; Port J reduced drive bit 7
; bit position masks
mRDRJ_RDRJ0:        equ    %00000001
mRDRJ_RDRJ1:        equ    %00000010
mRDRJ_RDRJ6:        equ    %01000000
mRDRJ_RDRJ7:        equ    %10000000


;*** PERJ - Port J Pull Device Enable Register; 0x0000026C ***
PERJ:               equ    $0000026C                                ;*** PERJ - Port J Pull Device Enable Register; 0x0000026C ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PERJ_PERJ0:         equ    0                                         ; Port J pull device enable bit 0
PERJ_PERJ1:         equ    1                                         ; Port J pull device enable bit 1
PERJ_PERJ6:         equ    6                                         ; Port J pull device enable bit 6
PERJ_PERJ7:         equ    7                                         ; Port J pull device enable bit 7
; bit position masks
mPERJ_PERJ0:        equ    %00000001
mPERJ_PERJ1:        equ    %00000010
mPERJ_PERJ6:        equ    %01000000
mPERJ_PERJ7:        equ    %10000000


;*** PPSJ - Port J Polarity Select Register; 0x0000026D ***
PPSJ:               equ    $0000026D                                ;*** PPSJ - Port J Polarity Select Register; 0x0000026D ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PPSJ_PPSJ0:         equ    0                                         ; Port J pull device select bit 0
PPSJ_PPSJ1:         equ    1                                         ; Port J pull device select bit 1
PPSJ_PPSJ6:         equ    6                                         ; Port J pull device select bit 6
PPSJ_PPSJ7:         equ    7                                         ; Port J pull device select bit 7
; bit position masks
mPPSJ_PPSJ0:        equ    %00000001
mPPSJ_PPSJ1:        equ    %00000010
mPPSJ_PPSJ6:        equ    %01000000
mPPSJ_PPSJ7:        equ    %10000000


;*** PIEJ - Port J Interrupt Enable Register; 0x0000026E ***
PIEJ:               equ    $0000026E                                ;*** PIEJ - Port J Interrupt Enable Register; 0x0000026E ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PIEJ_PIEJ0:         equ    0                                         ; Port J interrupt enable bit 0
PIEJ_PIEJ1:         equ    1                                         ; Port J interrupt enable bit 1
PIEJ_PIEJ6:         equ    6                                         ; Port J interrupt enable bit 6
PIEJ_PIEJ7:         equ    7                                         ; Port J interrupt enable bit 7
; bit position masks
mPIEJ_PIEJ0:        equ    %00000001
mPIEJ_PIEJ1:        equ    %00000010
mPIEJ_PIEJ6:        equ    %01000000
mPIEJ_PIEJ7:        equ    %10000000


;*** PIFJ - Port J Interrupt Flag Register; 0x0000026F ***
PIFJ:               equ    $0000026F                                ;*** PIFJ - Port J Interrupt Flag Register; 0x0000026F ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PIFJ_PIFJ0:         equ    0                                         ; Port J interrupt flag bit 0
PIFJ_PIFJ1:         equ    1                                         ; Port J interrupt flag bit 1
PIFJ_PIFJ6:         equ    6                                         ; Port J interrupt flag bit 6
PIFJ_PIFJ7:         equ    7                                         ; Port J interrupt flag bit 7
; bit position masks
mPIFJ_PIFJ0:        equ    %00000001
mPIFJ_PIFJ1:        equ    %00000010
mPIFJ_PIFJ6:        equ    %01000000
mPIFJ_PIFJ7:        equ    %10000000


;*** PT01AD0 - Port AD0 Data Register; 0x00000270 ***
PT01AD0:            equ    $00000270                                ;*** PT01AD0 - Port AD0 Data Register; 0x00000270 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PT01AD0_PT1AD00:    equ    0                                         ; Port AD0 data bit 0
PT01AD0_PT1AD01:    equ    1                                         ; Port AD0 data bit 1
PT01AD0_PT1AD02:    equ    2                                         ; Port AD0 data bit 2
PT01AD0_PT1AD03:    equ    3                                         ; Port AD0 data bit 3
PT01AD0_PT1AD04:    equ    4                                         ; Port AD0 data bit 4
PT01AD0_PT1AD05:    equ    5                                         ; Port AD0 data bit 5
PT01AD0_PT1AD06:    equ    6                                         ; Port AD0 data bit 6
PT01AD0_PT1AD07:    equ    7                                         ; Port AD0 data bit 7
PT01AD0_PT0AD00:    equ    8                                         ; Port AD0 data bit 8
PT01AD0_PT0AD01:    equ    9                                         ; Port AD0 data bit 9
PT01AD0_PT0AD02:    equ    10                                        ; Port AD0 data bit 10
PT01AD0_PT0AD03:    equ    11                                        ; Port AD0 data bit 11
PT01AD0_PT0AD04:    equ    12                                        ; Port AD0 data bit 12
PT01AD0_PT0AD05:    equ    13                                        ; Port AD0 data bit 13
PT01AD0_PT0AD06:    equ    14                                        ; Port AD0 data bit 14
PT01AD0_PT0AD07:    equ    15                                        ; Port AD0 data bit 15
; bit position masks
mPT01AD0_PT1AD00:   equ    %00000001
mPT01AD0_PT1AD01:   equ    %00000010
mPT01AD0_PT1AD02:   equ    %00000100
mPT01AD0_PT1AD03:   equ    %00001000
mPT01AD0_PT1AD04:   equ    %00010000
mPT01AD0_PT1AD05:   equ    %00100000
mPT01AD0_PT1AD06:   equ    %01000000
mPT01AD0_PT1AD07:   equ    %10000000
mPT01AD0_PT0AD00:   equ    %100000000
mPT01AD0_PT0AD01:   equ    %1000000000
mPT01AD0_PT0AD02:   equ    %10000000000
mPT01AD0_PT0AD03:   equ    %100000000000
mPT01AD0_PT0AD04:   equ    %1000000000000
mPT01AD0_PT0AD05:   equ    %10000000000000
mPT01AD0_PT0AD06:   equ    %100000000000000
mPT01AD0_PT0AD07:   equ    %1000000000000000


;*** PT0AD0 - Port AD0H Data Register; 0x00000270 ***
PT0AD0:             equ    $00000270                                ;*** PT0AD0 - Port AD0H Data Register; 0x00000270 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PT0AD0_PT0AD00:     equ    0                                         ; Port AD0 data bit 0
PT0AD0_PT0AD01:     equ    1                                         ; Port AD0 data bit 1
PT0AD0_PT0AD02:     equ    2                                         ; Port AD0 data bit 2
PT0AD0_PT0AD03:     equ    3                                         ; Port AD0 data bit 3
PT0AD0_PT0AD04:     equ    4                                         ; Port AD0 data bit 4
PT0AD0_PT0AD05:     equ    5                                         ; Port AD0 data bit 5
PT0AD0_PT0AD06:     equ    6                                         ; Port AD0 data bit 6
PT0AD0_PT0AD07:     equ    7                                         ; Port AD0 data bit 7
; bit position masks
mPT0AD0_PT0AD00:    equ    %00000001
mPT0AD0_PT0AD01:    equ    %00000010
mPT0AD0_PT0AD02:    equ    %00000100
mPT0AD0_PT0AD03:    equ    %00001000
mPT0AD0_PT0AD04:    equ    %00010000
mPT0AD0_PT0AD05:    equ    %00100000
mPT0AD0_PT0AD06:    equ    %01000000
mPT0AD0_PT0AD07:    equ    %10000000


;*** PT1AD0 - Port AD0L Data Register; 0x00000271 ***
PT1AD0:             equ    $00000271                                ;*** PT1AD0 - Port AD0L Data Register; 0x00000271 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PT1AD0_PT1AD00:     equ    0                                         ; Port AD0 data bit 0
PT1AD0_PT1AD01:     equ    1                                         ; Port AD0 data bit 1
PT1AD0_PT1AD02:     equ    2                                         ; Port AD0 data bit 2
PT1AD0_PT1AD03:     equ    3                                         ; Port AD0 data bit 3
PT1AD0_PT1AD04:     equ    4                                         ; Port AD0 data bit 4
PT1AD0_PT1AD05:     equ    5                                         ; Port AD0 data bit 5
PT1AD0_PT1AD06:     equ    6                                         ; Port AD0 data bit 6
PT1AD0_PT1AD07:     equ    7                                         ; Port AD0 data bit 7
; bit position masks
mPT1AD0_PT1AD00:    equ    %00000001
mPT1AD0_PT1AD01:    equ    %00000010
mPT1AD0_PT1AD02:    equ    %00000100
mPT1AD0_PT1AD03:    equ    %00001000
mPT1AD0_PT1AD04:    equ    %00010000
mPT1AD0_PT1AD05:    equ    %00100000
mPT1AD0_PT1AD06:    equ    %01000000
mPT1AD0_PT1AD07:    equ    %10000000


;*** DDR01AD0 - Port AD0 Data Direction Register; 0x00000272 ***
DDR01AD0:           equ    $00000272                                ;*** DDR01AD0 - Port AD0 Data Direction Register; 0x00000272 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DDR01AD0_DDR1AD00:  equ    0                                         ; Port AD0 data direction bit 0
DDR01AD0_DDR1AD01:  equ    1                                         ; Port AD0 data direction bit 1
DDR01AD0_DDR1AD02:  equ    2                                         ; Port AD0 data direction bit 2
DDR01AD0_DDR1AD03:  equ    3                                         ; Port AD0 data direction bit 3
DDR01AD0_DDR1AD04:  equ    4                                         ; Port AD0 data direction bit 4
DDR01AD0_DDR1AD05:  equ    5                                         ; Port AD0 data direction bit 5
DDR01AD0_DDR1AD06:  equ    6                                         ; Port AD0 data direction bit 6
DDR01AD0_DDR1AD07:  equ    7                                         ; Port AD0 data direction bit 7
DDR01AD0_DDR0AD00:  equ    8                                         ; Port AD0 data direction bit 8
DDR01AD0_DDR0AD01:  equ    9                                         ; Port AD0 data direction bit 9
DDR01AD0_DDR0AD02:  equ    10                                        ; Port AD0 data direction bit 10
DDR01AD0_DDR0AD03:  equ    11                                        ; Port AD0 data direction bit 11
DDR01AD0_DDR0AD04:  equ    12                                        ; Port AD0 data direction bit 12
DDR01AD0_DDR0AD05:  equ    13                                        ; Port AD0 data direction bit 13
DDR01AD0_DDR0AD06:  equ    14                                        ; Port AD0 data direction bit 14
DDR01AD0_DDR0AD07:  equ    15                                        ; Port AD0 data direction bit 15
; bit position masks
mDDR01AD0_DDR1AD00: equ    %00000001
mDDR01AD0_DDR1AD01: equ    %00000010
mDDR01AD0_DDR1AD02: equ    %00000100
mDDR01AD0_DDR1AD03: equ    %00001000
mDDR01AD0_DDR1AD04: equ    %00010000
mDDR01AD0_DDR1AD05: equ    %00100000
mDDR01AD0_DDR1AD06: equ    %01000000
mDDR01AD0_DDR1AD07: equ    %10000000
mDDR01AD0_DDR0AD00: equ    %100000000
mDDR01AD0_DDR0AD01: equ    %1000000000
mDDR01AD0_DDR0AD02: equ    %10000000000
mDDR01AD0_DDR0AD03: equ    %100000000000
mDDR01AD0_DDR0AD04: equ    %1000000000000
mDDR01AD0_DDR0AD05: equ    %10000000000000
mDDR01AD0_DDR0AD06: equ    %100000000000000
mDDR01AD0_DDR0AD07: equ    %1000000000000000


;*** DDR0AD0 - Port AD0H Data Direction Register; 0x00000272 ***
DDR0AD0:            equ    $00000272                                ;*** DDR0AD0 - Port AD0H Data Direction Register; 0x00000272 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DDR0AD0_DDR0AD00:   equ    0                                         ; Port AD0 data direction bit 0
DDR0AD0_DDR0AD01:   equ    1                                         ; Port AD0 data direction bit 1
DDR0AD0_DDR0AD02:   equ    2                                         ; Port AD0 data direction bit 2
DDR0AD0_DDR0AD03:   equ    3                                         ; Port AD0 data direction bit 3
DDR0AD0_DDR0AD04:   equ    4                                         ; Port AD0 data direction bit 4
DDR0AD0_DDR0AD05:   equ    5                                         ; Port AD0 data direction bit 5
DDR0AD0_DDR0AD06:   equ    6                                         ; Port AD0 data direction bit 6
DDR0AD0_DDR0AD07:   equ    7                                         ; Port AD0 data direction bit 7
; bit position masks
mDDR0AD0_DDR0AD00:  equ    %00000001
mDDR0AD0_DDR0AD01:  equ    %00000010
mDDR0AD0_DDR0AD02:  equ    %00000100
mDDR0AD0_DDR0AD03:  equ    %00001000
mDDR0AD0_DDR0AD04:  equ    %00010000
mDDR0AD0_DDR0AD05:  equ    %00100000
mDDR0AD0_DDR0AD06:  equ    %01000000
mDDR0AD0_DDR0AD07:  equ    %10000000


;*** DDR1AD0 - Port AD0L Data Direction Register; 0x00000273 ***
DDR1AD0:            equ    $00000273                                ;*** DDR1AD0 - Port AD0L Data Direction Register; 0x00000273 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DDR1AD0_DDR1AD00:   equ    0                                         ; Port AD0 data direction bit 0
DDR1AD0_DDR1AD01:   equ    1                                         ; Port AD0 data direction bit 1
DDR1AD0_DDR1AD02:   equ    2                                         ; Port AD0 data direction bit 2
DDR1AD0_DDR1AD03:   equ    3                                         ; Port AD0 data direction bit 3
DDR1AD0_DDR1AD04:   equ    4                                         ; Port AD0 data direction bit 4
DDR1AD0_DDR1AD05:   equ    5                                         ; Port AD0 data direction bit 5
DDR1AD0_DDR1AD06:   equ    6                                         ; Port AD0 data direction bit 6
DDR1AD0_DDR1AD07:   equ    7                                         ; Port AD0 data direction bit 7
; bit position masks
mDDR1AD0_DDR1AD00:  equ    %00000001
mDDR1AD0_DDR1AD01:  equ    %00000010
mDDR1AD0_DDR1AD02:  equ    %00000100
mDDR1AD0_DDR1AD03:  equ    %00001000
mDDR1AD0_DDR1AD04:  equ    %00010000
mDDR1AD0_DDR1AD05:  equ    %00100000
mDDR1AD0_DDR1AD06:  equ    %01000000
mDDR1AD0_DDR1AD07:  equ    %10000000


;*** RDR01AD0 - Port AD0 Reduced Drive Register; 0x00000274 ***
RDR01AD0:           equ    $00000274                                ;*** RDR01AD0 - Port AD0 Reduced Drive Register; 0x00000274 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
RDR01AD0_RDR1AD00:  equ    0                                         ; Port AD0 reduced drive bit 0
RDR01AD0_RDR1AD01:  equ    1                                         ; Port AD0 reduced drive bit 1
RDR01AD0_RDR1AD02:  equ    2                                         ; Port AD0 reduced drive bit 2
RDR01AD0_RDR1AD03:  equ    3                                         ; Port AD0 reduced drive bit 3
RDR01AD0_RDR1AD04:  equ    4                                         ; Port AD0 reduced drive bit 4
RDR01AD0_RDR1AD05:  equ    5                                         ; Port AD0 reduced drive bit 5
RDR01AD0_RDR1AD06:  equ    6                                         ; Port AD0 reduced drive bit 6
RDR01AD0_RDR1AD07:  equ    7                                         ; Port AD0 reduced drive bit 7
RDR01AD0_RDR0AD00:  equ    8                                         ; Port AD0 reduced drive bit 8
RDR01AD0_RDR0AD01:  equ    9                                         ; Port AD0 reduced drive bit 9
RDR01AD0_RDR0AD02:  equ    10                                        ; Port AD0 reduced drive bit 10
RDR01AD0_RDR0AD03:  equ    11                                        ; Port AD0 reduced drive bit 11
RDR01AD0_RDR0AD04:  equ    12                                        ; Port AD0 reduced drive bit 12
RDR01AD0_RDR0AD05:  equ    13                                        ; Port AD0 reduced drive bit 13
RDR01AD0_RDR0AD06:  equ    14                                        ; Port AD0 reduced drive bit 14
RDR01AD0_RDR0AD07:  equ    15                                        ; Port AD0 reduced drive bit 15
; bit position masks
mRDR01AD0_RDR1AD00: equ    %00000001
mRDR01AD0_RDR1AD01: equ    %00000010
mRDR01AD0_RDR1AD02: equ    %00000100
mRDR01AD0_RDR1AD03: equ    %00001000
mRDR01AD0_RDR1AD04: equ    %00010000
mRDR01AD0_RDR1AD05: equ    %00100000
mRDR01AD0_RDR1AD06: equ    %01000000
mRDR01AD0_RDR1AD07: equ    %10000000
mRDR01AD0_RDR0AD00: equ    %100000000
mRDR01AD0_RDR0AD01: equ    %1000000000
mRDR01AD0_RDR0AD02: equ    %10000000000
mRDR01AD0_RDR0AD03: equ    %100000000000
mRDR01AD0_RDR0AD04: equ    %1000000000000
mRDR01AD0_RDR0AD05: equ    %10000000000000
mRDR01AD0_RDR0AD06: equ    %100000000000000
mRDR01AD0_RDR0AD07: equ    %1000000000000000


;*** RDR0AD0 - Port AD0H Reduced Drive Register; 0x00000274 ***
RDR0AD0:            equ    $00000274                                ;*** RDR0AD0 - Port AD0H Reduced Drive Register; 0x00000274 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
RDR0AD0_RDR0AD00:   equ    0                                         ; Port AD0H reduced drive bit 0
RDR0AD0_RDR0AD01:   equ    1                                         ; Port AD0H reduced drive bit 1
RDR0AD0_RDR0AD02:   equ    2                                         ; Port AD0H reduced drive bit 2
RDR0AD0_RDR0AD03:   equ    3                                         ; Port AD0H reduced drive bit 3
RDR0AD0_RDR0AD04:   equ    4                                         ; Port AD0H reduced drive bit 4
RDR0AD0_RDR0AD05:   equ    5                                         ; Port AD0H reduced drive bit 5
RDR0AD0_RDR0AD06:   equ    6                                         ; Port AD0H reduced drive bit 6
RDR0AD0_RDR0AD07:   equ    7                                         ; Port AD0H reduced drive bit 7
; bit position masks
mRDR0AD0_RDR0AD00:  equ    %00000001
mRDR0AD0_RDR0AD01:  equ    %00000010
mRDR0AD0_RDR0AD02:  equ    %00000100
mRDR0AD0_RDR0AD03:  equ    %00001000
mRDR0AD0_RDR0AD04:  equ    %00010000
mRDR0AD0_RDR0AD05:  equ    %00100000
mRDR0AD0_RDR0AD06:  equ    %01000000
mRDR0AD0_RDR0AD07:  equ    %10000000


;*** RDR1AD0 - Port AD0L Reduced Drive Register; 0x00000275 ***
RDR1AD0:            equ    $00000275                                ;*** RDR1AD0 - Port AD0L Reduced Drive Register; 0x00000275 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
RDR1AD0_RDR1AD00:   equ    0                                         ; Port AD0L reduced drive bit 0
RDR1AD0_RDR1AD01:   equ    1                                         ; Port AD0L reduced drive bit 1
RDR1AD0_RDR1AD02:   equ    2                                         ; Port AD0L reduced drive bit 2
RDR1AD0_RDR1AD03:   equ    3                                         ; Port AD0L reduced drive bit 3
RDR1AD0_RDR1AD04:   equ    4                                         ; Port AD0L reduced drive bit 4
RDR1AD0_RDR1AD05:   equ    5                                         ; Port AD0L reduced drive bit 5
RDR1AD0_RDR1AD06:   equ    6                                         ; Port AD0L reduced drive bit 6
RDR1AD0_RDR1AD07:   equ    7                                         ; Port AD0L reduced drive bit 7
; bit position masks
mRDR1AD0_RDR1AD00:  equ    %00000001
mRDR1AD0_RDR1AD01:  equ    %00000010
mRDR1AD0_RDR1AD02:  equ    %00000100
mRDR1AD0_RDR1AD03:  equ    %00001000
mRDR1AD0_RDR1AD04:  equ    %00010000
mRDR1AD0_RDR1AD05:  equ    %00100000
mRDR1AD0_RDR1AD06:  equ    %01000000
mRDR1AD0_RDR1AD07:  equ    %10000000


;*** PER01AD0 - Port AD0 Pull Up Enable Register; 0x00000276 ***
PER01AD0:           equ    $00000276                                ;*** PER01AD0 - Port AD0 Pull Up Enable Register; 0x00000276 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PER01AD0_PER1AD00:  equ    0                                         ; Port AD0 pull up enable bit 0
PER01AD0_PER1AD01:  equ    1                                         ; Port AD0 pull up enable bit 1
PER01AD0_PER1AD02:  equ    2                                         ; Port AD0 pull up enable bit 2
PER01AD0_PER1AD03:  equ    3                                         ; Port AD0 pull up enable bit 3
PER01AD0_PER1AD04:  equ    4                                         ; Port AD0 pull up enable bit 4
PER01AD0_PER1AD05:  equ    5                                         ; Port AD0 pull up enable bit 5
PER01AD0_PER1AD06:  equ    6                                         ; Port AD0 pull up enable bit 6
PER01AD0_PER1AD07:  equ    7                                         ; Port AD0 pull up enable bit 7
PER01AD0_PER0AD00:  equ    8                                         ; Port AD0 pull up enable bit 8
PER01AD0_PER0AD01:  equ    9                                         ; Port AD0 pull up enable bit 9
PER01AD0_PER0AD02:  equ    10                                        ; Port AD0 pull up enable bit 10
PER01AD0_PER0AD03:  equ    11                                        ; Port AD0 pull up enable bit 11
PER01AD0_PER0AD04:  equ    12                                        ; Port AD0 pull up enable bit 12
PER01AD0_PER0AD05:  equ    13                                        ; Port AD0 pull up enable bit 13
PER01AD0_PER0AD06:  equ    14                                        ; Port AD0 pull up enable bit 14
PER01AD0_PER0AD07:  equ    15                                        ; Port AD0 pull up enable bit 15
; bit position masks
mPER01AD0_PER1AD00: equ    %00000001
mPER01AD0_PER1AD01: equ    %00000010
mPER01AD0_PER1AD02: equ    %00000100
mPER01AD0_PER1AD03: equ    %00001000
mPER01AD0_PER1AD04: equ    %00010000
mPER01AD0_PER1AD05: equ    %00100000
mPER01AD0_PER1AD06: equ    %01000000
mPER01AD0_PER1AD07: equ    %10000000
mPER01AD0_PER0AD00: equ    %100000000
mPER01AD0_PER0AD01: equ    %1000000000
mPER01AD0_PER0AD02: equ    %10000000000
mPER01AD0_PER0AD03: equ    %100000000000
mPER01AD0_PER0AD04: equ    %1000000000000
mPER01AD0_PER0AD05: equ    %10000000000000
mPER01AD0_PER0AD06: equ    %100000000000000
mPER01AD0_PER0AD07: equ    %1000000000000000


;*** PER0AD0 - Port AD0H Pull Up Enable Register; 0x00000276 ***
PER0AD0:            equ    $00000276                                ;*** PER0AD0 - Port AD0H Pull Up Enable Register; 0x00000276 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PER0AD0_PER0AD00:   equ    0                                         ; Port AD0H pull up enable bit 0
PER0AD0_PER0AD01:   equ    1                                         ; Port AD0H pull up enable bit 1
PER0AD0_PER0AD02:   equ    2                                         ; Port AD0H pull up enable bit 2
PER0AD0_PER0AD03:   equ    3                                         ; Port AD0H pull up enable bit 3
PER0AD0_PER0AD04:   equ    4                                         ; Port AD0H pull up enable bit 4
PER0AD0_PER0AD05:   equ    5                                         ; Port AD0H pull up enable bit 5
PER0AD0_PER0AD06:   equ    6                                         ; Port AD0H pull up enable bit 6
PER0AD0_PER0AD07:   equ    7                                         ; Port AD0H pull up enable bit 7
; bit position masks
mPER0AD0_PER0AD00:  equ    %00000001
mPER0AD0_PER0AD01:  equ    %00000010
mPER0AD0_PER0AD02:  equ    %00000100
mPER0AD0_PER0AD03:  equ    %00001000
mPER0AD0_PER0AD04:  equ    %00010000
mPER0AD0_PER0AD05:  equ    %00100000
mPER0AD0_PER0AD06:  equ    %01000000
mPER0AD0_PER0AD07:  equ    %10000000


;*** PER1AD0 - Port AD0L Pull Up Enable Register; 0x00000277 ***
PER1AD0:            equ    $00000277                                ;*** PER1AD0 - Port AD0L Pull Up Enable Register; 0x00000277 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PER1AD0_PER1AD00:   equ    0                                         ; Port AD0L pull up enable bit 0
PER1AD0_PER1AD01:   equ    1                                         ; Port AD0L pull up enable bit 1
PER1AD0_PER1AD02:   equ    2                                         ; Port AD0L pull up enable bit 2
PER1AD0_PER1AD03:   equ    3                                         ; Port AD0L pull up enable bit 3
PER1AD0_PER1AD04:   equ    4                                         ; Port AD0L pull up enable bit 4
PER1AD0_PER1AD05:   equ    5                                         ; Port AD0L pull up enable bit 5
PER1AD0_PER1AD06:   equ    6                                         ; Port AD0L pull up enable bit 6
PER1AD0_PER1AD07:   equ    7                                         ; Port AD0L pull up enable bit 7
; bit position masks
mPER1AD0_PER1AD00:  equ    %00000001
mPER1AD0_PER1AD01:  equ    %00000010
mPER1AD0_PER1AD02:  equ    %00000100
mPER1AD0_PER1AD03:  equ    %00001000
mPER1AD0_PER1AD04:  equ    %00010000
mPER1AD0_PER1AD05:  equ    %00100000
mPER1AD0_PER1AD06:  equ    %01000000
mPER1AD0_PER1AD07:  equ    %10000000


;*** ATD0CTL01 - ATD 0 Control Register 01; 0x000002C0 ***
ATD0CTL01:          equ    $000002C0                                ;*** ATD0CTL01 - ATD 0 Control Register 01; 0x000002C0 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ATD0CTL01_ETRIGCH0: equ    0                                         ; External Trigger Channel Select Bit 0
ATD0CTL01_ETRIGCH1: equ    1                                         ; External Trigger Channel Select Bit 1
ATD0CTL01_ETRIGCH2: equ    2                                         ; External Trigger Channel Select Bit 2
ATD0CTL01_ETRIGCH3: equ    3                                         ; External Trigger Channel Select Bit 3
ATD0CTL01_SMP_DIS:  equ    4                                         ; Discharge Before Sampling Bit
ATD0CTL01_SRES0:    equ    5                                         ; A/D Resolution Select Bit 0
ATD0CTL01_SRES1:    equ    6                                         ; A/D Resolution Select Bit 1
ATD0CTL01_ETRIGSEL: equ    7                                         ; External Trigger Source Select
ATD0CTL01_WRAP0:    equ    8                                         ; Wrap Around Channel Select Bit 0
ATD0CTL01_WRAP1:    equ    9                                         ; Wrap Around Channel Select Bit 1
ATD0CTL01_WRAP2:    equ    10                                        ; Wrap Around Channel Select Bit 2
ATD0CTL01_WRAP3:    equ    11                                        ; Wrap Around Channel Select Bit 3
; bit position masks
mATD0CTL01_ETRIGCH0: equ    %00000001
mATD0CTL01_ETRIGCH1: equ    %00000010
mATD0CTL01_ETRIGCH2: equ    %00000100
mATD0CTL01_ETRIGCH3: equ    %00001000
mATD0CTL01_SMP_DIS: equ    %00010000
mATD0CTL01_SRES0:   equ    %00100000
mATD0CTL01_SRES1:   equ    %01000000
mATD0CTL01_ETRIGSEL: equ    %10000000
mATD0CTL01_WRAP0:   equ    %100000000
mATD0CTL01_WRAP1:   equ    %1000000000
mATD0CTL01_WRAP2:   equ    %10000000000
mATD0CTL01_WRAP3:   equ    %100000000000


;*** ATD0CTL0 - ATD 0 Control Register 0; 0x000002C0 ***
ATD0CTL0:           equ    $000002C0                                ;*** ATD0CTL0 - ATD 0 Control Register 0; 0x000002C0 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ATD0CTL0_WRAP0:     equ    0                                         ; Wrap Around Channel Select Bit 0
ATD0CTL0_WRAP1:     equ    1                                         ; Wrap Around Channel Select Bit 1
ATD0CTL0_WRAP2:     equ    2                                         ; Wrap Around Channel Select Bit 2
ATD0CTL0_WRAP3:     equ    3                                         ; Wrap Around Channel Select Bit 3
; bit position masks
mATD0CTL0_WRAP0:    equ    %00000001
mATD0CTL0_WRAP1:    equ    %00000010
mATD0CTL0_WRAP2:    equ    %00000100
mATD0CTL0_WRAP3:    equ    %00001000


;*** ATD0CTL1 - ATD 0 Control Register 1; 0x000002C1 ***
ATD0CTL1:           equ    $000002C1                                ;*** ATD0CTL1 - ATD 0 Control Register 1; 0x000002C1 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ATD0CTL1_ETRIGCH0:  equ    0                                         ; External Trigger Channel Select Bit 0
ATD0CTL1_ETRIGCH1:  equ    1                                         ; External Trigger Channel Select Bit 1
ATD0CTL1_ETRIGCH2:  equ    2                                         ; External Trigger Channel Select Bit 2
ATD0CTL1_ETRIGCH3:  equ    3                                         ; External Trigger Channel Select Bit 3
ATD0CTL1_SMP_DIS:   equ    4                                         ; Discharge Before Sampling Bit
ATD0CTL1_SRES0:     equ    5                                         ; A/D Resolution Select Bit 0
ATD0CTL1_SRES1:     equ    6                                         ; A/D Resolution Select Bit 1
ATD0CTL1_ETRIGSEL:  equ    7                                         ; External Trigger Source Select
; bit position masks
mATD0CTL1_ETRIGCH0: equ    %00000001
mATD0CTL1_ETRIGCH1: equ    %00000010
mATD0CTL1_ETRIGCH2: equ    %00000100
mATD0CTL1_ETRIGCH3: equ    %00001000
mATD0CTL1_SMP_DIS:  equ    %00010000
mATD0CTL1_SRES0:    equ    %00100000
mATD0CTL1_SRES1:    equ    %01000000
mATD0CTL1_ETRIGSEL: equ    %10000000


;*** ATD0CTL23 - ATD 0 Control Register 23; 0x000002C2 ***
ATD0CTL23:          equ    $000002C2                                ;*** ATD0CTL23 - ATD 0 Control Register 23; 0x000002C2 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ATD0CTL23_FRZ0:     equ    0                                         ; Background Debug Freeze Enable Bit 0
ATD0CTL23_FRZ1:     equ    1                                         ; Background Debug Freeze Enable Bit 1
ATD0CTL23_FIFO:     equ    2                                         ; Result Register FIFO Mode
ATD0CTL23_S1C:      equ    3                                         ; Conversion Sequence Length 1
ATD0CTL23_S2C:      equ    4                                         ; Conversion Sequence Length 2
ATD0CTL23_S4C:      equ    5                                         ; Conversion Sequence Length 4
ATD0CTL23_S8C:      equ    6                                         ; Conversion Sequence Length 8
ATD0CTL23_DJM:      equ    7                                         ; Result Register Data Justification
ATD0CTL23_ACMPIE:   equ    8                                         ; ATD Compare Interrupt Enable
ATD0CTL23_ASCIE:    equ    9                                         ; ATD Sequence Complete Interrupt Enable
ATD0CTL23_ETRIGE:   equ    10                                        ; External Trigger Mode enable
ATD0CTL23_ETRIGP:   equ    11                                        ; External Trigger Polarity
ATD0CTL23_ETRIGLE:  equ    12                                        ; External Trigger Level/Edge control
ATD0CTL23_ICLKSTP:  equ    13                                        ; Internal Clock in Stop Mode Bit
ATD0CTL23_AFFC:     equ    14                                        ; ATD Fast Conversion Complete Flag Clear
; bit position masks
mATD0CTL23_FRZ0:    equ    %00000001
mATD0CTL23_FRZ1:    equ    %00000010
mATD0CTL23_FIFO:    equ    %00000100
mATD0CTL23_S1C:     equ    %00001000
mATD0CTL23_S2C:     equ    %00010000
mATD0CTL23_S4C:     equ    %00100000
mATD0CTL23_S8C:     equ    %01000000
mATD0CTL23_DJM:     equ    %10000000
mATD0CTL23_ACMPIE:  equ    %100000000
mATD0CTL23_ASCIE:   equ    %1000000000
mATD0CTL23_ETRIGE:  equ    %10000000000
mATD0CTL23_ETRIGP:  equ    %100000000000
mATD0CTL23_ETRIGLE: equ    %1000000000000
mATD0CTL23_ICLKSTP: equ    %10000000000000
mATD0CTL23_AFFC:    equ    %100000000000000


;*** ATD0CTL2 - ATD 0 Control Register 2; 0x000002C2 ***
ATD0CTL2:           equ    $000002C2                                ;*** ATD0CTL2 - ATD 0 Control Register 2; 0x000002C2 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ATD0CTL2_ACMPIE:    equ    0                                         ; ATD Compare Interrupt Enable
ATD0CTL2_ASCIE:     equ    1                                         ; ATD Sequence Complete Interrupt Enable
ATD0CTL2_ETRIGE:    equ    2                                         ; External Trigger Mode enable
ATD0CTL2_ETRIGP:    equ    3                                         ; External Trigger Polarity
ATD0CTL2_ETRIGLE:   equ    4                                         ; External Trigger Level/Edge control
ATD0CTL2_ICLKSTP:   equ    5                                         ; Internal Clock in Stop Mode Bit
ATD0CTL2_AFFC:      equ    6                                         ; ATD Fast Conversion Complete Flag Clear
; bit position masks
mATD0CTL2_ACMPIE:   equ    %00000001
mATD0CTL2_ASCIE:    equ    %00000010
mATD0CTL2_ETRIGE:   equ    %00000100
mATD0CTL2_ETRIGP:   equ    %00001000
mATD0CTL2_ETRIGLE:  equ    %00010000
mATD0CTL2_ICLKSTP:  equ    %00100000
mATD0CTL2_AFFC:     equ    %01000000


;*** ATD0CTL3 - ATD 0 Control Register 3; 0x000002C3 ***
ATD0CTL3:           equ    $000002C3                                ;*** ATD0CTL3 - ATD 0 Control Register 3; 0x000002C3 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ATD0CTL3_FRZ0:      equ    0                                         ; Background Debug Freeze Enable Bit 0
ATD0CTL3_FRZ1:      equ    1                                         ; Background Debug Freeze Enable Bit 1
ATD0CTL3_FIFO:      equ    2                                         ; Result Register FIFO Mode
ATD0CTL3_S1C:       equ    3                                         ; Conversion Sequence Length 1
ATD0CTL3_S2C:       equ    4                                         ; Conversion Sequence Length 2
ATD0CTL3_S4C:       equ    5                                         ; Conversion Sequence Length 4
ATD0CTL3_S8C:       equ    6                                         ; Conversion Sequence Length 8
ATD0CTL3_DJM:       equ    7                                         ; Result Register Data Justification
; bit position masks
mATD0CTL3_FRZ0:     equ    %00000001
mATD0CTL3_FRZ1:     equ    %00000010
mATD0CTL3_FIFO:     equ    %00000100
mATD0CTL3_S1C:      equ    %00001000
mATD0CTL3_S2C:      equ    %00010000
mATD0CTL3_S4C:      equ    %00100000
mATD0CTL3_S8C:      equ    %01000000
mATD0CTL3_DJM:      equ    %10000000


;*** ATD0CTL45 - ATD 0 Control Register 45; 0x000002C4 ***
ATD0CTL45:          equ    $000002C4                                ;*** ATD0CTL45 - ATD 0 Control Register 45; 0x000002C4 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ATD0CTL45_CA:       equ    0                                         ; Analog Input Channel Select Code A
ATD0CTL45_CB:       equ    1                                         ; Analog Input Channel Select Code B
ATD0CTL45_CC:       equ    2                                         ; Analog Input Channel Select Code C
ATD0CTL45_CD:       equ    3                                         ; Analog Input Channel Select Code D
ATD0CTL45_MULT:     equ    4                                         ; Multi-Channel Sample Mode
ATD0CTL45_SCAN:     equ    5                                         ; Continuous Conversion Sequence Mode
ATD0CTL45_SC:       equ    6                                         ; Special Channel Conversion Bit
ATD0CTL45_PRS0:     equ    8                                         ; ATD Clock Prescaler 0
ATD0CTL45_PRS1:     equ    9                                         ; ATD Clock Prescaler 1
ATD0CTL45_PRS2:     equ    10                                        ; ATD Clock Prescaler 2
ATD0CTL45_PRS3:     equ    11                                        ; ATD Clock Prescaler 3
ATD0CTL45_PRS4:     equ    12                                        ; ATD Clock Prescaler 4
ATD0CTL45_SMP0:     equ    13                                        ; Sample Time Select 0
ATD0CTL45_SMP1:     equ    14                                        ; Sample Time Select 1
ATD0CTL45_SMP2:     equ    15                                        ; Sample Time Select 2
; bit position masks
mATD0CTL45_CA:      equ    %00000001
mATD0CTL45_CB:      equ    %00000010
mATD0CTL45_CC:      equ    %00000100
mATD0CTL45_CD:      equ    %00001000
mATD0CTL45_MULT:    equ    %00010000
mATD0CTL45_SCAN:    equ    %00100000
mATD0CTL45_SC:      equ    %01000000
mATD0CTL45_PRS0:    equ    %100000000
mATD0CTL45_PRS1:    equ    %1000000000
mATD0CTL45_PRS2:    equ    %10000000000
mATD0CTL45_PRS3:    equ    %100000000000
mATD0CTL45_PRS4:    equ    %1000000000000
mATD0CTL45_SMP0:    equ    %10000000000000
mATD0CTL45_SMP1:    equ    %100000000000000
mATD0CTL45_SMP2:    equ    %1000000000000000


;*** ATD0CTL4 - ATD 0 Control Register 4; 0x000002C4 ***
ATD0CTL4:           equ    $000002C4                                ;*** ATD0CTL4 - ATD 0 Control Register 4; 0x000002C4 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ATD0CTL4_PRS0:      equ    0                                         ; ATD Clock Prescaler 0
ATD0CTL4_PRS1:      equ    1                                         ; ATD Clock Prescaler 1
ATD0CTL4_PRS2:      equ    2                                         ; ATD Clock Prescaler 2
ATD0CTL4_PRS3:      equ    3                                         ; ATD Clock Prescaler 3
ATD0CTL4_PRS4:      equ    4                                         ; ATD Clock Prescaler 4
ATD0CTL4_SMP0:      equ    5                                         ; Sample Time Select 0
ATD0CTL4_SMP1:      equ    6                                         ; Sample Time Select 1
ATD0CTL4_SMP2:      equ    7                                         ; Sample Time Select 2
; bit position masks
mATD0CTL4_PRS0:     equ    %00000001
mATD0CTL4_PRS1:     equ    %00000010
mATD0CTL4_PRS2:     equ    %00000100
mATD0CTL4_PRS3:     equ    %00001000
mATD0CTL4_PRS4:     equ    %00010000
mATD0CTL4_SMP0:     equ    %00100000
mATD0CTL4_SMP1:     equ    %01000000
mATD0CTL4_SMP2:     equ    %10000000


;*** ATD0CTL5 - ATD 0 Control Register 5; 0x000002C5 ***
ATD0CTL5:           equ    $000002C5                                ;*** ATD0CTL5 - ATD 0 Control Register 5; 0x000002C5 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ATD0CTL5_CA:        equ    0                                         ; Analog Input Channel Select Code A
ATD0CTL5_CB:        equ    1                                         ; Analog Input Channel Select Code B
ATD0CTL5_CC:        equ    2                                         ; Analog Input Channel Select Code C
ATD0CTL5_CD:        equ    3                                         ; Analog Input Channel Select Code D
ATD0CTL5_MULT:      equ    4                                         ; Multi-Channel Sample Mode
ATD0CTL5_SCAN:      equ    5                                         ; Continuous Conversion Sequence Mode
ATD0CTL5_SC:        equ    6                                         ; Special Channel Conversion Bit
; bit position masks
mATD0CTL5_CA:       equ    %00000001
mATD0CTL5_CB:       equ    %00000010
mATD0CTL5_CC:       equ    %00000100
mATD0CTL5_CD:       equ    %00001000
mATD0CTL5_MULT:     equ    %00010000
mATD0CTL5_SCAN:     equ    %00100000
mATD0CTL5_SC:       equ    %01000000


;*** ATD0STAT0 - ATD 0 Status Register 0; 0x000002C6 ***
ATD0STAT0:          equ    $000002C6                                ;*** ATD0STAT0 - ATD 0 Status Register 0; 0x000002C6 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ATD0STAT0_CC0:      equ    0                                         ; Conversion Counter 0
ATD0STAT0_CC1:      equ    1                                         ; Conversion Counter 1
ATD0STAT0_CC2:      equ    2                                         ; Conversion Counter 2
ATD0STAT0_CC3:      equ    3                                         ; Conversion Counter 3
ATD0STAT0_FIFOR:    equ    4                                         ; FIFO Over Run Flag
ATD0STAT0_ETORF:    equ    5                                         ; External Trigger Overrun Flag
ATD0STAT0_SCF:      equ    7                                         ; Sequence Complete Flag
; bit position masks
mATD0STAT0_CC0:     equ    %00000001
mATD0STAT0_CC1:     equ    %00000010
mATD0STAT0_CC2:     equ    %00000100
mATD0STAT0_CC3:     equ    %00001000
mATD0STAT0_FIFOR:   equ    %00010000
mATD0STAT0_ETORF:   equ    %00100000
mATD0STAT0_SCF:     equ    %10000000


;*** ATD0CMPE - ATD 0 Compare Enable Register; 0x000002C8 ***
ATD0CMPE:           equ    $000002C8                                ;*** ATD0CMPE - ATD 0 Compare Enable Register; 0x000002C8 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ATD0CMPE_CMPE0:     equ    0                                         ; Compare Enable for Conversion Number 0 of a Sequence
ATD0CMPE_CMPE1:     equ    1                                         ; Compare Enable for Conversion Number 1 of a Sequence
ATD0CMPE_CMPE2:     equ    2                                         ; Compare Enable for Conversion Number 2 of a Sequence
ATD0CMPE_CMPE3:     equ    3                                         ; Compare Enable for Conversion Number 3 of a Sequence
ATD0CMPE_CMPE4:     equ    4                                         ; Compare Enable for Conversion Number 4 of a Sequence
ATD0CMPE_CMPE5:     equ    5                                         ; Compare Enable for Conversion Number 5 of a Sequence
ATD0CMPE_CMPE6:     equ    6                                         ; Compare Enable for Conversion Number 6 of a Sequence
ATD0CMPE_CMPE7:     equ    7                                         ; Compare Enable for Conversion Number 7 of a Sequence
ATD0CMPE_CMPE8:     equ    8                                         ; Compare Enable for Conversion Number 8 of a Sequence
ATD0CMPE_CMPE9:     equ    9                                         ; Compare Enable for Conversion Number 9 of a Sequence
ATD0CMPE_CMPE10:    equ    10                                        ; Compare Enable for Conversion Number 10 of a Sequence
ATD0CMPE_CMPE11:    equ    11                                        ; Compare Enable for Conversion Number 11 of a Sequence
ATD0CMPE_CMPE12:    equ    12                                        ; Compare Enable for Conversion Number 12 of a Sequence
ATD0CMPE_CMPE13:    equ    13                                        ; Compare Enable for Conversion Number 13 of a Sequence
ATD0CMPE_CMPE14:    equ    14                                        ; Compare Enable for Conversion Number 14 of a Sequence
ATD0CMPE_CMPE15:    equ    15                                        ; Compare Enable for Conversion Number 15 of a Sequence
; bit position masks
mATD0CMPE_CMPE0:    equ    %00000001
mATD0CMPE_CMPE1:    equ    %00000010
mATD0CMPE_CMPE2:    equ    %00000100
mATD0CMPE_CMPE3:    equ    %00001000
mATD0CMPE_CMPE4:    equ    %00010000
mATD0CMPE_CMPE5:    equ    %00100000
mATD0CMPE_CMPE6:    equ    %01000000
mATD0CMPE_CMPE7:    equ    %10000000
mATD0CMPE_CMPE8:    equ    %100000000
mATD0CMPE_CMPE9:    equ    %1000000000
mATD0CMPE_CMPE10:   equ    %10000000000
mATD0CMPE_CMPE11:   equ    %100000000000
mATD0CMPE_CMPE12:   equ    %1000000000000
mATD0CMPE_CMPE13:   equ    %10000000000000
mATD0CMPE_CMPE14:   equ    %100000000000000
mATD0CMPE_CMPE15:   equ    %1000000000000000


;*** ATD0CMPEH - ATD 0 Compare Enable Register High; 0x000002C8 ***
ATD0CMPEH:          equ    $000002C8                                ;*** ATD0CMPEH - ATD 0 Compare Enable Register High; 0x000002C8 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ATD0CMPEH_CMPE8:    equ    0                                         ; Compare Enable for Conversion Number 8 of a Sequence
ATD0CMPEH_CMPE9:    equ    1                                         ; Compare Enable for Conversion Number 9 of a Sequence
ATD0CMPEH_CMPE10:   equ    2                                         ; Compare Enable for Conversion Number 10 of a Sequence
ATD0CMPEH_CMPE11:   equ    3                                         ; Compare Enable for Conversion Number 11 of a Sequence
ATD0CMPEH_CMPE12:   equ    4                                         ; Compare Enable for Conversion Number 12 of a Sequence
ATD0CMPEH_CMPE13:   equ    5                                         ; Compare Enable for Conversion Number 13 of a Sequence
ATD0CMPEH_CMPE14:   equ    6                                         ; Compare Enable for Conversion Number 14 of a Sequence
ATD0CMPEH_CMPE15:   equ    7                                         ; Compare Enable for Conversion Number 15 of a Sequence
; bit position masks
mATD0CMPEH_CMPE8:   equ    %00000001
mATD0CMPEH_CMPE9:   equ    %00000010
mATD0CMPEH_CMPE10:  equ    %00000100
mATD0CMPEH_CMPE11:  equ    %00001000
mATD0CMPEH_CMPE12:  equ    %00010000
mATD0CMPEH_CMPE13:  equ    %00100000
mATD0CMPEH_CMPE14:  equ    %01000000
mATD0CMPEH_CMPE15:  equ    %10000000


;*** ATD0CMPEL - ATD 0 Compare Enable Register Low; 0x000002C9 ***
ATD0CMPEL:          equ    $000002C9                                ;*** ATD0CMPEL - ATD 0 Compare Enable Register Low; 0x000002C9 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ATD0CMPEL_CMPE0:    equ    0                                         ; Compare Enable for Conversion Number 0 of a Sequence
ATD0CMPEL_CMPE1:    equ    1                                         ; Compare Enable for Conversion Number 1 of a Sequence
ATD0CMPEL_CMPE2:    equ    2                                         ; Compare Enable for Conversion Number 2 of a Sequence
ATD0CMPEL_CMPE3:    equ    3                                         ; Compare Enable for Conversion Number 3 of a Sequence
ATD0CMPEL_CMPE4:    equ    4                                         ; Compare Enable for Conversion Number 4 of a Sequence
ATD0CMPEL_CMPE5:    equ    5                                         ; Compare Enable for Conversion Number 5 of a Sequence
ATD0CMPEL_CMPE6:    equ    6                                         ; Compare Enable for Conversion Number 6 of a Sequence
ATD0CMPEL_CMPE7:    equ    7                                         ; Compare Enable for Conversion Number 7 of a Sequence
; bit position masks
mATD0CMPEL_CMPE0:   equ    %00000001
mATD0CMPEL_CMPE1:   equ    %00000010
mATD0CMPEL_CMPE2:   equ    %00000100
mATD0CMPEL_CMPE3:   equ    %00001000
mATD0CMPEL_CMPE4:   equ    %00010000
mATD0CMPEL_CMPE5:   equ    %00100000
mATD0CMPEL_CMPE6:   equ    %01000000
mATD0CMPEL_CMPE7:   equ    %10000000


;*** ATD0STAT2 - ATD 0 Status Register 2; 0x000002CA ***
ATD0STAT2:          equ    $000002CA                                ;*** ATD0STAT2 - ATD 0 Status Register 2; 0x000002CA ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ATD0STAT2_CCF0:     equ    0                                         ; Conversion Complete Flag 0
ATD0STAT2_CCF1:     equ    1                                         ; Conversion Complete Flag 1
ATD0STAT2_CCF2:     equ    2                                         ; Conversion Complete Flag 2
ATD0STAT2_CCF3:     equ    3                                         ; Conversion Complete Flag 3
ATD0STAT2_CCF4:     equ    4                                         ; Conversion Complete Flag 4
ATD0STAT2_CCF5:     equ    5                                         ; Conversion Complete Flag 5
ATD0STAT2_CCF6:     equ    6                                         ; Conversion Complete Flag 6
ATD0STAT2_CCF7:     equ    7                                         ; Conversion Complete Flag 7
ATD0STAT2_CCF8:     equ    8                                         ; Conversion Complete Flag 8
ATD0STAT2_CCF9:     equ    9                                         ; Conversion Complete Flag 9
ATD0STAT2_CCF10:    equ    10                                        ; Conversion Complete Flag 10
ATD0STAT2_CCF11:    equ    11                                        ; Conversion Complete Flag 11
ATD0STAT2_CCF12:    equ    12                                        ; Conversion Complete Flag 12
ATD0STAT2_CCF13:    equ    13                                        ; Conversion Complete Flag 13
ATD0STAT2_CCF14:    equ    14                                        ; Conversion Complete Flag 14
ATD0STAT2_CCF15:    equ    15                                        ; Conversion Complete Flag 15
; bit position masks
mATD0STAT2_CCF0:    equ    %00000001
mATD0STAT2_CCF1:    equ    %00000010
mATD0STAT2_CCF2:    equ    %00000100
mATD0STAT2_CCF3:    equ    %00001000
mATD0STAT2_CCF4:    equ    %00010000
mATD0STAT2_CCF5:    equ    %00100000
mATD0STAT2_CCF6:    equ    %01000000
mATD0STAT2_CCF7:    equ    %10000000
mATD0STAT2_CCF8:    equ    %100000000
mATD0STAT2_CCF9:    equ    %1000000000
mATD0STAT2_CCF10:   equ    %10000000000
mATD0STAT2_CCF11:   equ    %100000000000
mATD0STAT2_CCF12:   equ    %1000000000000
mATD0STAT2_CCF13:   equ    %10000000000000
mATD0STAT2_CCF14:   equ    %100000000000000
mATD0STAT2_CCF15:   equ    %1000000000000000


;*** ATD0STAT2H - ATD 0 Status Register 2 High; 0x000002CA ***
ATD0STAT2H:         equ    $000002CA                                ;*** ATD0STAT2H - ATD 0 Status Register 2 High; 0x000002CA ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ATD0STAT2H_CCF8:    equ    0                                         ; Conversion Complete Flag 8
ATD0STAT2H_CCF9:    equ    1                                         ; Conversion Complete Flag 9
ATD0STAT2H_CCF10:   equ    2                                         ; Conversion Complete Flag 10
ATD0STAT2H_CCF11:   equ    3                                         ; Conversion Complete Flag 11
ATD0STAT2H_CCF12:   equ    4                                         ; Conversion Complete Flag 12
ATD0STAT2H_CCF13:   equ    5                                         ; Conversion Complete Flag 13
ATD0STAT2H_CCF14:   equ    6                                         ; Conversion Complete Flag 14
ATD0STAT2H_CCF15:   equ    7                                         ; Conversion Complete Flag 15
; bit position masks
mATD0STAT2H_CCF8:   equ    %00000001
mATD0STAT2H_CCF9:   equ    %00000010
mATD0STAT2H_CCF10:  equ    %00000100
mATD0STAT2H_CCF11:  equ    %00001000
mATD0STAT2H_CCF12:  equ    %00010000
mATD0STAT2H_CCF13:  equ    %00100000
mATD0STAT2H_CCF14:  equ    %01000000
mATD0STAT2H_CCF15:  equ    %10000000


;*** ATD0STAT2L - ATD 0 Status Register 2 Low; 0x000002CB ***
ATD0STAT2L:         equ    $000002CB                                ;*** ATD0STAT2L - ATD 0 Status Register 2 Low; 0x000002CB ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ATD0STAT2L_CCF0:    equ    0                                         ; Conversion Complete Flag 0
ATD0STAT2L_CCF1:    equ    1                                         ; Conversion Complete Flag 1
ATD0STAT2L_CCF2:    equ    2                                         ; Conversion Complete Flag 2
ATD0STAT2L_CCF3:    equ    3                                         ; Conversion Complete Flag 3
ATD0STAT2L_CCF4:    equ    4                                         ; Conversion Complete Flag 4
ATD0STAT2L_CCF5:    equ    5                                         ; Conversion Complete Flag 5
ATD0STAT2L_CCF6:    equ    6                                         ; Conversion Complete Flag 6
ATD0STAT2L_CCF7:    equ    7                                         ; Conversion Complete Flag 7
; bit position masks
mATD0STAT2L_CCF0:   equ    %00000001
mATD0STAT2L_CCF1:   equ    %00000010
mATD0STAT2L_CCF2:   equ    %00000100
mATD0STAT2L_CCF3:   equ    %00001000
mATD0STAT2L_CCF4:   equ    %00010000
mATD0STAT2L_CCF5:   equ    %00100000
mATD0STAT2L_CCF6:   equ    %01000000
mATD0STAT2L_CCF7:   equ    %10000000


;*** ATD0DIEN - ATD 0 Input Enable Register; 0x000002CC ***
ATD0DIEN:           equ    $000002CC                                ;*** ATD0DIEN - ATD 0 Input Enable Register; 0x000002CC ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ATD0DIEN_IEN0:      equ    0                                         ; ATD Digital Input Enable on channel 0
ATD0DIEN_IEN1:      equ    1                                         ; ATD Digital Input Enable on channel 1
ATD0DIEN_IEN2:      equ    2                                         ; ATD Digital Input Enable on channel 2
ATD0DIEN_IEN3:      equ    3                                         ; ATD Digital Input Enable on channel 3
ATD0DIEN_IEN4:      equ    4                                         ; ATD Digital Input Enable on channel 4
ATD0DIEN_IEN5:      equ    5                                         ; ATD Digital Input Enable on channel 5
ATD0DIEN_IEN6:      equ    6                                         ; ATD Digital Input Enable on channel 6
ATD0DIEN_IEN7:      equ    7                                         ; ATD Digital Input Enable on channel 7
ATD0DIEN_IEN8:      equ    8                                         ; ATD Digital Input Enable on channel 8
ATD0DIEN_IEN9:      equ    9                                         ; ATD Digital Input Enable on channel 9
ATD0DIEN_IEN10:     equ    10                                        ; ATD Digital Input Enable on channel 10
ATD0DIEN_IEN11:     equ    11                                        ; ATD Digital Input Enable on channel 11
ATD0DIEN_IEN12:     equ    12                                        ; ATD Digital Input Enable on channel 12
ATD0DIEN_IEN13:     equ    13                                        ; ATD Digital Input Enable on channel 13
ATD0DIEN_IEN14:     equ    14                                        ; ATD Digital Input Enable on channel 14
ATD0DIEN_IEN15:     equ    15                                        ; ATD Digital Input Enable on channel 15
; bit position masks
mATD0DIEN_IEN0:     equ    %00000001
mATD0DIEN_IEN1:     equ    %00000010
mATD0DIEN_IEN2:     equ    %00000100
mATD0DIEN_IEN3:     equ    %00001000
mATD0DIEN_IEN4:     equ    %00010000
mATD0DIEN_IEN5:     equ    %00100000
mATD0DIEN_IEN6:     equ    %01000000
mATD0DIEN_IEN7:     equ    %10000000
mATD0DIEN_IEN8:     equ    %100000000
mATD0DIEN_IEN9:     equ    %1000000000
mATD0DIEN_IEN10:    equ    %10000000000
mATD0DIEN_IEN11:    equ    %100000000000
mATD0DIEN_IEN12:    equ    %1000000000000
mATD0DIEN_IEN13:    equ    %10000000000000
mATD0DIEN_IEN14:    equ    %100000000000000
mATD0DIEN_IEN15:    equ    %1000000000000000


;*** ATD0DIENH - ATD 0 Input Enable Register High; 0x000002CC ***
ATD0DIENH:          equ    $000002CC                                ;*** ATD0DIENH - ATD 0 Input Enable Register High; 0x000002CC ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ATD0DIENH_IEN8:     equ    0                                         ; ATD Digital Input Enable on channel 8
ATD0DIENH_IEN9:     equ    1                                         ; ATD Digital Input Enable on channel 9
ATD0DIENH_IEN10:    equ    2                                         ; ATD Digital Input Enable on channel 10
ATD0DIENH_IEN11:    equ    3                                         ; ATD Digital Input Enable on channel 11
ATD0DIENH_IEN12:    equ    4                                         ; ATD Digital Input Enable on channel 12
ATD0DIENH_IEN13:    equ    5                                         ; ATD Digital Input Enable on channel 13
ATD0DIENH_IEN14:    equ    6                                         ; ATD Digital Input Enable on channel 14
ATD0DIENH_IEN15:    equ    7                                         ; ATD Digital Input Enable on channel 15
; bit position masks
mATD0DIENH_IEN8:    equ    %00000001
mATD0DIENH_IEN9:    equ    %00000010
mATD0DIENH_IEN10:   equ    %00000100
mATD0DIENH_IEN11:   equ    %00001000
mATD0DIENH_IEN12:   equ    %00010000
mATD0DIENH_IEN13:   equ    %00100000
mATD0DIENH_IEN14:   equ    %01000000
mATD0DIENH_IEN15:   equ    %10000000


;*** ATD0DIENL - ATD 0 Input Enable Register Low; 0x000002CD ***
ATD0DIENL:          equ    $000002CD                                ;*** ATD0DIENL - ATD 0 Input Enable Register Low; 0x000002CD ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ATD0DIENL_IEN0:     equ    0                                         ; ATD Digital Input Enable on channel 0
ATD0DIENL_IEN1:     equ    1                                         ; ATD Digital Input Enable on channel 1
ATD0DIENL_IEN2:     equ    2                                         ; ATD Digital Input Enable on channel 2
ATD0DIENL_IEN3:     equ    3                                         ; ATD Digital Input Enable on channel 3
ATD0DIENL_IEN4:     equ    4                                         ; ATD Digital Input Enable on channel 4
ATD0DIENL_IEN5:     equ    5                                         ; ATD Digital Input Enable on channel 5
ATD0DIENL_IEN6:     equ    6                                         ; ATD Digital Input Enable on channel 6
ATD0DIENL_IEN7:     equ    7                                         ; ATD Digital Input Enable on channel 7
; bit position masks
mATD0DIENL_IEN0:    equ    %00000001
mATD0DIENL_IEN1:    equ    %00000010
mATD0DIENL_IEN2:    equ    %00000100
mATD0DIENL_IEN3:    equ    %00001000
mATD0DIENL_IEN4:    equ    %00010000
mATD0DIENL_IEN5:    equ    %00100000
mATD0DIENL_IEN6:    equ    %01000000
mATD0DIENL_IEN7:    equ    %10000000


;*** ATD0CMPHT - ATD 0 Compare Higher Than Register; 0x000002CE ***
ATD0CMPHT:          equ    $000002CE                                ;*** ATD0CMPHT - ATD 0 Compare Higher Than Register; 0x000002CE ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ATD0CMPHT_CMPHT0:   equ    0                                         ; Compare Operation Higher Than Enable for Conversion Number 0 of a Sequence
ATD0CMPHT_CMPHT1:   equ    1                                         ; Compare Operation Higher Than Enable for Conversion Number 1 of a Sequence
ATD0CMPHT_CMPHT2:   equ    2                                         ; Compare Operation Higher Than Enable for Conversion Number 2 of a Sequence
ATD0CMPHT_CMPHT3:   equ    3                                         ; Compare Operation Higher Than Enable for Conversion Number 3 of a Sequence
ATD0CMPHT_CMPHT4:   equ    4                                         ; Compare Operation Higher Than Enable for Conversion Number 4 of a Sequence
ATD0CMPHT_CMPHT5:   equ    5                                         ; Compare Operation Higher Than Enable for Conversion Number 5 of a Sequence
ATD0CMPHT_CMPHT6:   equ    6                                         ; Compare Operation Higher Than Enable for Conversion Number 6 of a Sequence
ATD0CMPHT_CMPHT7:   equ    7                                         ; Compare Operation Higher Than Enable for Conversion Number 7 of a Sequence
ATD0CMPHT_CMPHT8:   equ    8                                         ; Compare Operation Higher Than Enable for Conversion Number 8 of a Sequence
ATD0CMPHT_CMPHT9:   equ    9                                         ; Compare Operation Higher Than Enable for Conversion Number 9 of a Sequence
ATD0CMPHT_CMPHT10:  equ    10                                        ; Compare Operation Higher Than Enable for Conversion Number 10 of a Sequence
ATD0CMPHT_CMPHT11:  equ    11                                        ; Compare Operation Higher Than Enable for Conversion Number 11 of a Sequence
ATD0CMPHT_CMPHT12:  equ    12                                        ; Compare Operation Higher Than Enable for Conversion Number 12 of a Sequence
ATD0CMPHT_CMPHT13:  equ    13                                        ; Compare Operation Higher Than Enable for Conversion Number 13 of a Sequence
ATD0CMPHT_CMPHT14:  equ    14                                        ; Compare Operation Higher Than Enable for Conversion Number 14 of a Sequence
ATD0CMPHT_CMPHT15:  equ    15                                        ; Compare Operation Higher Than Enable for Conversion Number 15 of a Sequence
; bit position masks
mATD0CMPHT_CMPHT0:  equ    %00000001
mATD0CMPHT_CMPHT1:  equ    %00000010
mATD0CMPHT_CMPHT2:  equ    %00000100
mATD0CMPHT_CMPHT3:  equ    %00001000
mATD0CMPHT_CMPHT4:  equ    %00010000
mATD0CMPHT_CMPHT5:  equ    %00100000
mATD0CMPHT_CMPHT6:  equ    %01000000
mATD0CMPHT_CMPHT7:  equ    %10000000
mATD0CMPHT_CMPHT8:  equ    %100000000
mATD0CMPHT_CMPHT9:  equ    %1000000000
mATD0CMPHT_CMPHT10: equ    %10000000000
mATD0CMPHT_CMPHT11: equ    %100000000000
mATD0CMPHT_CMPHT12: equ    %1000000000000
mATD0CMPHT_CMPHT13: equ    %10000000000000
mATD0CMPHT_CMPHT14: equ    %100000000000000
mATD0CMPHT_CMPHT15: equ    %1000000000000000


;*** ATD0CMPHTH - ATD 0 Compare Higher Than Register High; 0x000002CE ***
ATD0CMPHTH:         equ    $000002CE                                ;*** ATD0CMPHTH - ATD 0 Compare Higher Than Register High; 0x000002CE ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ATD0CMPHTH_CMPHT8:  equ    0                                         ; Compare Operation Higher Than Enable for Conversion Number 8 of a Sequence
ATD0CMPHTH_CMPHT9:  equ    1                                         ; Compare Operation Higher Than Enable for Conversion Number 9 of a Sequence
ATD0CMPHTH_CMPHT10: equ    2                                         ; Compare Operation Higher Than Enable for Conversion Number 10 of a Sequence
ATD0CMPHTH_CMPHT11: equ    3                                         ; Compare Operation Higher Than Enable for Conversion Number 11 of a Sequence
ATD0CMPHTH_CMPHT12: equ    4                                         ; Compare Operation Higher Than Enable for Conversion Number 12 of a Sequence
ATD0CMPHTH_CMPHT13: equ    5                                         ; Compare Operation Higher Than Enable for Conversion Number 13 of a Sequence
ATD0CMPHTH_CMPHT14: equ    6                                         ; Compare Operation Higher Than Enable for Conversion Number 14 of a Sequence
ATD0CMPHTH_CMPHT15: equ    7                                         ; Compare Operation Higher Than Enable for Conversion Number 15 of a Sequence
; bit position masks
mATD0CMPHTH_CMPHT8: equ    %00000001
mATD0CMPHTH_CMPHT9: equ    %00000010
mATD0CMPHTH_CMPHT10: equ    %00000100
mATD0CMPHTH_CMPHT11: equ    %00001000
mATD0CMPHTH_CMPHT12: equ    %00010000
mATD0CMPHTH_CMPHT13: equ    %00100000
mATD0CMPHTH_CMPHT14: equ    %01000000
mATD0CMPHTH_CMPHT15: equ    %10000000


;*** ATD0CMPHTL - ATD 0 Compare Higher Than Register Low; 0x000002CF ***
ATD0CMPHTL:         equ    $000002CF                                ;*** ATD0CMPHTL - ATD 0 Compare Higher Than Register Low; 0x000002CF ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ATD0CMPHTL_CMPHT0:  equ    0                                         ; Compare Operation Higher Than Enable for Conversion Number 0 of a Sequence
ATD0CMPHTL_CMPHT1:  equ    1                                         ; Compare Operation Higher Than Enable for Conversion Number 1 of a Sequence
ATD0CMPHTL_CMPHT2:  equ    2                                         ; Compare Operation Higher Than Enable for Conversion Number 2 of a Sequence
ATD0CMPHTL_CMPHT3:  equ    3                                         ; Compare Operation Higher Than Enable for Conversion Number 3 of a Sequence
ATD0CMPHTL_CMPHT4:  equ    4                                         ; Compare Operation Higher Than Enable for Conversion Number 4 of a Sequence
ATD0CMPHTL_CMPHT5:  equ    5                                         ; Compare Operation Higher Than Enable for Conversion Number 5 of a Sequence
ATD0CMPHTL_CMPHT6:  equ    6                                         ; Compare Operation Higher Than Enable for Conversion Number 6 of a Sequence
ATD0CMPHTL_CMPHT7:  equ    7                                         ; Compare Operation Higher Than Enable for Conversion Number 7 of a Sequence
; bit position masks
mATD0CMPHTL_CMPHT0: equ    %00000001
mATD0CMPHTL_CMPHT1: equ    %00000010
mATD0CMPHTL_CMPHT2: equ    %00000100
mATD0CMPHTL_CMPHT3: equ    %00001000
mATD0CMPHTL_CMPHT4: equ    %00010000
mATD0CMPHTL_CMPHT5: equ    %00100000
mATD0CMPHTL_CMPHT6: equ    %01000000
mATD0CMPHTL_CMPHT7: equ    %10000000


;*** ATD0DR0 - ATD 0 Conversion Result Register 0; 0x000002D0 ***
ATD0DR0:            equ    $000002D0                                ;*** ATD0DR0 - ATD 0 Conversion Result Register 0; 0x000002D0 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ATD0DR0_BIT0:       equ    0                                         ; Bit 0
ATD0DR0_BIT1:       equ    1                                         ; Bit 1
ATD0DR0_BIT2:       equ    2                                         ; Bit 2
ATD0DR0_BIT3:       equ    3                                         ; Bit 3
ATD0DR0_BIT4:       equ    4                                         ; Bit 4
ATD0DR0_BIT5:       equ    5                                         ; Bit 5
ATD0DR0_BIT6:       equ    6                                         ; Bit 6
ATD0DR0_BIT7:       equ    7                                         ; Bit 7
ATD0DR0_BIT8:       equ    8                                         ; Bit 8
ATD0DR0_BIT9:       equ    9                                         ; Bit 9
ATD0DR0_BIT10:      equ    10                                        ; Bit 10
ATD0DR0_BIT11:      equ    11                                        ; Bit 11
ATD0DR0_BIT12:      equ    12                                        ; Bit 12
ATD0DR0_BIT13:      equ    13                                        ; Bit 13
ATD0DR0_BIT14:      equ    14                                        ; Bit 14
ATD0DR0_BIT15:      equ    15                                        ; Bit 15
; bit position masks
mATD0DR0_BIT0:      equ    %00000001
mATD0DR0_BIT1:      equ    %00000010
mATD0DR0_BIT2:      equ    %00000100
mATD0DR0_BIT3:      equ    %00001000
mATD0DR0_BIT4:      equ    %00010000
mATD0DR0_BIT5:      equ    %00100000
mATD0DR0_BIT6:      equ    %01000000
mATD0DR0_BIT7:      equ    %10000000
mATD0DR0_BIT8:      equ    %100000000
mATD0DR0_BIT9:      equ    %1000000000
mATD0DR0_BIT10:     equ    %10000000000
mATD0DR0_BIT11:     equ    %100000000000
mATD0DR0_BIT12:     equ    %1000000000000
mATD0DR0_BIT13:     equ    %10000000000000
mATD0DR0_BIT14:     equ    %100000000000000
mATD0DR0_BIT15:     equ    %1000000000000000


;*** ATD0DR0H - ATD 0 Conversion Result Register 0 High; 0x000002D0 ***
ATD0DR0H:           equ    $000002D0                                ;*** ATD0DR0H - ATD 0 Conversion Result Register 0 High; 0x000002D0 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ATD0DR0H_BIT8:      equ    0                                         ; Bit 8
ATD0DR0H_BIT9:      equ    1                                         ; Bit 9
ATD0DR0H_BIT10:     equ    2                                         ; Bit 10
ATD0DR0H_BIT11:     equ    3                                         ; Bit 11
ATD0DR0H_BIT12:     equ    4                                         ; Bit 12
ATD0DR0H_BIT13:     equ    5                                         ; Bit 13
ATD0DR0H_BIT14:     equ    6                                         ; Bit 14
ATD0DR0H_BIT15:     equ    7                                         ; Bit 15
; bit position masks
mATD0DR0H_BIT8:     equ    %00000001
mATD0DR0H_BIT9:     equ    %00000010
mATD0DR0H_BIT10:    equ    %00000100
mATD0DR0H_BIT11:    equ    %00001000
mATD0DR0H_BIT12:    equ    %00010000
mATD0DR0H_BIT13:    equ    %00100000
mATD0DR0H_BIT14:    equ    %01000000
mATD0DR0H_BIT15:    equ    %10000000


;*** ATD0DR0L - ATD 0 Conversion Result Register 0 Low; 0x000002D1 ***
ATD0DR0L:           equ    $000002D1                                ;*** ATD0DR0L - ATD 0 Conversion Result Register 0 Low; 0x000002D1 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ATD0DR0L_BIT0:      equ    0                                         ; Bit 0
ATD0DR0L_BIT1:      equ    1                                         ; Bit 1
ATD0DR0L_BIT2:      equ    2                                         ; Bit 2
ATD0DR0L_BIT3:      equ    3                                         ; Bit 3
ATD0DR0L_BIT4:      equ    4                                         ; Bit 4
ATD0DR0L_BIT5:      equ    5                                         ; Bit 5
ATD0DR0L_BIT6:      equ    6                                         ; Bit 6
ATD0DR0L_BIT7:      equ    7                                         ; Bit 7
; bit position masks
mATD0DR0L_BIT0:     equ    %00000001
mATD0DR0L_BIT1:     equ    %00000010
mATD0DR0L_BIT2:     equ    %00000100
mATD0DR0L_BIT3:     equ    %00001000
mATD0DR0L_BIT4:     equ    %00010000
mATD0DR0L_BIT5:     equ    %00100000
mATD0DR0L_BIT6:     equ    %01000000
mATD0DR0L_BIT7:     equ    %10000000


;*** ATD0DR1 - ATD 0 Conversion Result Register 1; 0x000002D2 ***
ATD0DR1:            equ    $000002D2                                ;*** ATD0DR1 - ATD 0 Conversion Result Register 1; 0x000002D2 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ATD0DR1_BIT0:       equ    0                                         ; Bit 0
ATD0DR1_BIT1:       equ    1                                         ; Bit 1
ATD0DR1_BIT2:       equ    2                                         ; Bit 2
ATD0DR1_BIT3:       equ    3                                         ; Bit 3
ATD0DR1_BIT4:       equ    4                                         ; Bit 4
ATD0DR1_BIT5:       equ    5                                         ; Bit 5
ATD0DR1_BIT6:       equ    6                                         ; Bit 6
ATD0DR1_BIT7:       equ    7                                         ; Bit 7
ATD0DR1_BIT8:       equ    8                                         ; Bit 8
ATD0DR1_BIT9:       equ    9                                         ; Bit 9
ATD0DR1_BIT10:      equ    10                                        ; Bit 10
ATD0DR1_BIT11:      equ    11                                        ; Bit 11
ATD0DR1_BIT12:      equ    12                                        ; Bit 12
ATD0DR1_BIT13:      equ    13                                        ; Bit 13
ATD0DR1_BIT14:      equ    14                                        ; Bit 14
ATD0DR1_BIT15:      equ    15                                        ; Bit 15
; bit position masks
mATD0DR1_BIT0:      equ    %00000001
mATD0DR1_BIT1:      equ    %00000010
mATD0DR1_BIT2:      equ    %00000100
mATD0DR1_BIT3:      equ    %00001000
mATD0DR1_BIT4:      equ    %00010000
mATD0DR1_BIT5:      equ    %00100000
mATD0DR1_BIT6:      equ    %01000000
mATD0DR1_BIT7:      equ    %10000000
mATD0DR1_BIT8:      equ    %100000000
mATD0DR1_BIT9:      equ    %1000000000
mATD0DR1_BIT10:     equ    %10000000000
mATD0DR1_BIT11:     equ    %100000000000
mATD0DR1_BIT12:     equ    %1000000000000
mATD0DR1_BIT13:     equ    %10000000000000
mATD0DR1_BIT14:     equ    %100000000000000
mATD0DR1_BIT15:     equ    %1000000000000000


;*** ATD0DR1H - ATD 0 Conversion Result Register 1 High; 0x000002D2 ***
ATD0DR1H:           equ    $000002D2                                ;*** ATD0DR1H - ATD 0 Conversion Result Register 1 High; 0x000002D2 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ATD0DR1H_BIT8:      equ    0                                         ; Bit 8
ATD0DR1H_BIT9:      equ    1                                         ; Bit 9
ATD0DR1H_BIT10:     equ    2                                         ; Bit 10
ATD0DR1H_BIT11:     equ    3                                         ; Bit 11
ATD0DR1H_BIT12:     equ    4                                         ; Bit 12
ATD0DR1H_BIT13:     equ    5                                         ; Bit 13
ATD0DR1H_BIT14:     equ    6                                         ; Bit 14
ATD0DR1H_BIT15:     equ    7                                         ; Bit 15
; bit position masks
mATD0DR1H_BIT8:     equ    %00000001
mATD0DR1H_BIT9:     equ    %00000010
mATD0DR1H_BIT10:    equ    %00000100
mATD0DR1H_BIT11:    equ    %00001000
mATD0DR1H_BIT12:    equ    %00010000
mATD0DR1H_BIT13:    equ    %00100000
mATD0DR1H_BIT14:    equ    %01000000
mATD0DR1H_BIT15:    equ    %10000000


;*** ATD0DR1L - ATD 0 Conversion Result Register 1 Low; 0x000002D3 ***
ATD0DR1L:           equ    $000002D3                                ;*** ATD0DR1L - ATD 0 Conversion Result Register 1 Low; 0x000002D3 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ATD0DR1L_BIT0:      equ    0                                         ; Bit 0
ATD0DR1L_BIT1:      equ    1                                         ; Bit 1
ATD0DR1L_BIT2:      equ    2                                         ; Bit 2
ATD0DR1L_BIT3:      equ    3                                         ; Bit 3
ATD0DR1L_BIT4:      equ    4                                         ; Bit 4
ATD0DR1L_BIT5:      equ    5                                         ; Bit 5
ATD0DR1L_BIT6:      equ    6                                         ; Bit 6
ATD0DR1L_BIT7:      equ    7                                         ; Bit 7
; bit position masks
mATD0DR1L_BIT0:     equ    %00000001
mATD0DR1L_BIT1:     equ    %00000010
mATD0DR1L_BIT2:     equ    %00000100
mATD0DR1L_BIT3:     equ    %00001000
mATD0DR1L_BIT4:     equ    %00010000
mATD0DR1L_BIT5:     equ    %00100000
mATD0DR1L_BIT6:     equ    %01000000
mATD0DR1L_BIT7:     equ    %10000000


;*** ATD0DR2 - ATD 0 Conversion Result Register 2; 0x000002D4 ***
ATD0DR2:            equ    $000002D4                                ;*** ATD0DR2 - ATD 0 Conversion Result Register 2; 0x000002D4 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ATD0DR2_BIT0:       equ    0                                         ; Bit 0
ATD0DR2_BIT1:       equ    1                                         ; Bit 1
ATD0DR2_BIT2:       equ    2                                         ; Bit 2
ATD0DR2_BIT3:       equ    3                                         ; Bit 3
ATD0DR2_BIT4:       equ    4                                         ; Bit 4
ATD0DR2_BIT5:       equ    5                                         ; Bit 5
ATD0DR2_BIT6:       equ    6                                         ; Bit 6
ATD0DR2_BIT7:       equ    7                                         ; Bit 7
ATD0DR2_BIT8:       equ    8                                         ; Bit 8
ATD0DR2_BIT9:       equ    9                                         ; Bit 9
ATD0DR2_BIT10:      equ    10                                        ; Bit 10
ATD0DR2_BIT11:      equ    11                                        ; Bit 11
ATD0DR2_BIT12:      equ    12                                        ; Bit 12
ATD0DR2_BIT13:      equ    13                                        ; Bit 13
ATD0DR2_BIT14:      equ    14                                        ; Bit 14
ATD0DR2_BIT15:      equ    15                                        ; Bit 15
; bit position masks
mATD0DR2_BIT0:      equ    %00000001
mATD0DR2_BIT1:      equ    %00000010
mATD0DR2_BIT2:      equ    %00000100
mATD0DR2_BIT3:      equ    %00001000
mATD0DR2_BIT4:      equ    %00010000
mATD0DR2_BIT5:      equ    %00100000
mATD0DR2_BIT6:      equ    %01000000
mATD0DR2_BIT7:      equ    %10000000
mATD0DR2_BIT8:      equ    %100000000
mATD0DR2_BIT9:      equ    %1000000000
mATD0DR2_BIT10:     equ    %10000000000
mATD0DR2_BIT11:     equ    %100000000000
mATD0DR2_BIT12:     equ    %1000000000000
mATD0DR2_BIT13:     equ    %10000000000000
mATD0DR2_BIT14:     equ    %100000000000000
mATD0DR2_BIT15:     equ    %1000000000000000


;*** ATD0DR2H - ATD 0 Conversion Result Register 2 High; 0x000002D4 ***
ATD0DR2H:           equ    $000002D4                                ;*** ATD0DR2H - ATD 0 Conversion Result Register 2 High; 0x000002D4 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ATD0DR2H_BIT8:      equ    0                                         ; Bit 8
ATD0DR2H_BIT9:      equ    1                                         ; Bit 9
ATD0DR2H_BIT10:     equ    2                                         ; Bit 10
ATD0DR2H_BIT11:     equ    3                                         ; Bit 11
ATD0DR2H_BIT12:     equ    4                                         ; Bit 12
ATD0DR2H_BIT13:     equ    5                                         ; Bit 13
ATD0DR2H_BIT14:     equ    6                                         ; Bit 14
ATD0DR2H_BIT15:     equ    7                                         ; Bit 15
; bit position masks
mATD0DR2H_BIT8:     equ    %00000001
mATD0DR2H_BIT9:     equ    %00000010
mATD0DR2H_BIT10:    equ    %00000100
mATD0DR2H_BIT11:    equ    %00001000
mATD0DR2H_BIT12:    equ    %00010000
mATD0DR2H_BIT13:    equ    %00100000
mATD0DR2H_BIT14:    equ    %01000000
mATD0DR2H_BIT15:    equ    %10000000


;*** ATD0DR2L - ATD 0 Conversion Result Register 2 Low; 0x000002D5 ***
ATD0DR2L:           equ    $000002D5                                ;*** ATD0DR2L - ATD 0 Conversion Result Register 2 Low; 0x000002D5 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ATD0DR2L_BIT0:      equ    0                                         ; Bit 0
ATD0DR2L_BIT1:      equ    1                                         ; Bit 1
ATD0DR2L_BIT2:      equ    2                                         ; Bit 2
ATD0DR2L_BIT3:      equ    3                                         ; Bit 3
ATD0DR2L_BIT4:      equ    4                                         ; Bit 4
ATD0DR2L_BIT5:      equ    5                                         ; Bit 5
ATD0DR2L_BIT6:      equ    6                                         ; Bit 6
ATD0DR2L_BIT7:      equ    7                                         ; Bit 7
; bit position masks
mATD0DR2L_BIT0:     equ    %00000001
mATD0DR2L_BIT1:     equ    %00000010
mATD0DR2L_BIT2:     equ    %00000100
mATD0DR2L_BIT3:     equ    %00001000
mATD0DR2L_BIT4:     equ    %00010000
mATD0DR2L_BIT5:     equ    %00100000
mATD0DR2L_BIT6:     equ    %01000000
mATD0DR2L_BIT7:     equ    %10000000


;*** ATD0DR3 - ATD 0 Conversion Result Register 3; 0x000002D6 ***
ATD0DR3:            equ    $000002D6                                ;*** ATD0DR3 - ATD 0 Conversion Result Register 3; 0x000002D6 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ATD0DR3_BIT0:       equ    0                                         ; Bit 0
ATD0DR3_BIT1:       equ    1                                         ; Bit 1
ATD0DR3_BIT2:       equ    2                                         ; Bit 2
ATD0DR3_BIT3:       equ    3                                         ; Bit 3
ATD0DR3_BIT4:       equ    4                                         ; Bit 4
ATD0DR3_BIT5:       equ    5                                         ; Bit 5
ATD0DR3_BIT6:       equ    6                                         ; Bit 6
ATD0DR3_BIT7:       equ    7                                         ; Bit 7
ATD0DR3_BIT8:       equ    8                                         ; Bit 8
ATD0DR3_BIT9:       equ    9                                         ; Bit 9
ATD0DR3_BIT10:      equ    10                                        ; Bit 10
ATD0DR3_BIT11:      equ    11                                        ; Bit 11
ATD0DR3_BIT12:      equ    12                                        ; Bit 12
ATD0DR3_BIT13:      equ    13                                        ; Bit 13
ATD0DR3_BIT14:      equ    14                                        ; Bit 14
ATD0DR3_BIT15:      equ    15                                        ; Bit 15
; bit position masks
mATD0DR3_BIT0:      equ    %00000001
mATD0DR3_BIT1:      equ    %00000010
mATD0DR3_BIT2:      equ    %00000100
mATD0DR3_BIT3:      equ    %00001000
mATD0DR3_BIT4:      equ    %00010000
mATD0DR3_BIT5:      equ    %00100000
mATD0DR3_BIT6:      equ    %01000000
mATD0DR3_BIT7:      equ    %10000000
mATD0DR3_BIT8:      equ    %100000000
mATD0DR3_BIT9:      equ    %1000000000
mATD0DR3_BIT10:     equ    %10000000000
mATD0DR3_BIT11:     equ    %100000000000
mATD0DR3_BIT12:     equ    %1000000000000
mATD0DR3_BIT13:     equ    %10000000000000
mATD0DR3_BIT14:     equ    %100000000000000
mATD0DR3_BIT15:     equ    %1000000000000000


;*** ATD0DR3H - ATD 0 Conversion Result Register 3 High; 0x000002D6 ***
ATD0DR3H:           equ    $000002D6                                ;*** ATD0DR3H - ATD 0 Conversion Result Register 3 High; 0x000002D6 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ATD0DR3H_BIT8:      equ    0                                         ; Bit 8
ATD0DR3H_BIT9:      equ    1                                         ; Bit 9
ATD0DR3H_BIT10:     equ    2                                         ; Bit 10
ATD0DR3H_BIT11:     equ    3                                         ; Bit 11
ATD0DR3H_BIT12:     equ    4                                         ; Bit 12
ATD0DR3H_BIT13:     equ    5                                         ; Bit 13
ATD0DR3H_BIT14:     equ    6                                         ; Bit 14
ATD0DR3H_BIT15:     equ    7                                         ; Bit 15
; bit position masks
mATD0DR3H_BIT8:     equ    %00000001
mATD0DR3H_BIT9:     equ    %00000010
mATD0DR3H_BIT10:    equ    %00000100
mATD0DR3H_BIT11:    equ    %00001000
mATD0DR3H_BIT12:    equ    %00010000
mATD0DR3H_BIT13:    equ    %00100000
mATD0DR3H_BIT14:    equ    %01000000
mATD0DR3H_BIT15:    equ    %10000000


;*** ATD0DR3L - ATD 0 Conversion Result Register 3 Low; 0x000002D7 ***
ATD0DR3L:           equ    $000002D7                                ;*** ATD0DR3L - ATD 0 Conversion Result Register 3 Low; 0x000002D7 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ATD0DR3L_BIT0:      equ    0                                         ; Bit 0
ATD0DR3L_BIT1:      equ    1                                         ; Bit 1
ATD0DR3L_BIT2:      equ    2                                         ; Bit 2
ATD0DR3L_BIT3:      equ    3                                         ; Bit 3
ATD0DR3L_BIT4:      equ    4                                         ; Bit 4
ATD0DR3L_BIT5:      equ    5                                         ; Bit 5
ATD0DR3L_BIT6:      equ    6                                         ; Bit 6
ATD0DR3L_BIT7:      equ    7                                         ; Bit 7
; bit position masks
mATD0DR3L_BIT0:     equ    %00000001
mATD0DR3L_BIT1:     equ    %00000010
mATD0DR3L_BIT2:     equ    %00000100
mATD0DR3L_BIT3:     equ    %00001000
mATD0DR3L_BIT4:     equ    %00010000
mATD0DR3L_BIT5:     equ    %00100000
mATD0DR3L_BIT6:     equ    %01000000
mATD0DR3L_BIT7:     equ    %10000000


;*** ATD0DR4 - ATD 0 Conversion Result Register 4; 0x000002D8 ***
ATD0DR4:            equ    $000002D8                                ;*** ATD0DR4 - ATD 0 Conversion Result Register 4; 0x000002D8 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ATD0DR4_BIT0:       equ    0                                         ; Bit 0
ATD0DR4_BIT1:       equ    1                                         ; Bit 1
ATD0DR4_BIT2:       equ    2                                         ; Bit 2
ATD0DR4_BIT3:       equ    3                                         ; Bit 3
ATD0DR4_BIT4:       equ    4                                         ; Bit 4
ATD0DR4_BIT5:       equ    5                                         ; Bit 5
ATD0DR4_BIT6:       equ    6                                         ; Bit 6
ATD0DR4_BIT7:       equ    7                                         ; Bit 7
ATD0DR4_BIT8:       equ    8                                         ; Bit 8
ATD0DR4_BIT9:       equ    9                                         ; Bit 9
ATD0DR4_BIT10:      equ    10                                        ; Bit 10
ATD0DR4_BIT11:      equ    11                                        ; Bit 11
ATD0DR4_BIT12:      equ    12                                        ; Bit 12
ATD0DR4_BIT13:      equ    13                                        ; Bit 13
ATD0DR4_BIT14:      equ    14                                        ; Bit 14
ATD0DR4_BIT15:      equ    15                                        ; Bit 15
; bit position masks
mATD0DR4_BIT0:      equ    %00000001
mATD0DR4_BIT1:      equ    %00000010
mATD0DR4_BIT2:      equ    %00000100
mATD0DR4_BIT3:      equ    %00001000
mATD0DR4_BIT4:      equ    %00010000
mATD0DR4_BIT5:      equ    %00100000
mATD0DR4_BIT6:      equ    %01000000
mATD0DR4_BIT7:      equ    %10000000
mATD0DR4_BIT8:      equ    %100000000
mATD0DR4_BIT9:      equ    %1000000000
mATD0DR4_BIT10:     equ    %10000000000
mATD0DR4_BIT11:     equ    %100000000000
mATD0DR4_BIT12:     equ    %1000000000000
mATD0DR4_BIT13:     equ    %10000000000000
mATD0DR4_BIT14:     equ    %100000000000000
mATD0DR4_BIT15:     equ    %1000000000000000


;*** ATD0DR4H - ATD 0 Conversion Result Register 4 High; 0x000002D8 ***
ATD0DR4H:           equ    $000002D8                                ;*** ATD0DR4H - ATD 0 Conversion Result Register 4 High; 0x000002D8 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ATD0DR4H_BIT8:      equ    0                                         ; Bit 8
ATD0DR4H_BIT9:      equ    1                                         ; Bit 9
ATD0DR4H_BIT10:     equ    2                                         ; Bit 10
ATD0DR4H_BIT11:     equ    3                                         ; Bit 11
ATD0DR4H_BIT12:     equ    4                                         ; Bit 12
ATD0DR4H_BIT13:     equ    5                                         ; Bit 13
ATD0DR4H_BIT14:     equ    6                                         ; Bit 14
ATD0DR4H_BIT15:     equ    7                                         ; Bit 15
; bit position masks
mATD0DR4H_BIT8:     equ    %00000001
mATD0DR4H_BIT9:     equ    %00000010
mATD0DR4H_BIT10:    equ    %00000100
mATD0DR4H_BIT11:    equ    %00001000
mATD0DR4H_BIT12:    equ    %00010000
mATD0DR4H_BIT13:    equ    %00100000
mATD0DR4H_BIT14:    equ    %01000000
mATD0DR4H_BIT15:    equ    %10000000


;*** ATD0DR4L - ATD 0 Conversion Result Register 4 Low; 0x000002D9 ***
ATD0DR4L:           equ    $000002D9                                ;*** ATD0DR4L - ATD 0 Conversion Result Register 4 Low; 0x000002D9 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ATD0DR4L_BIT0:      equ    0                                         ; Bit 0
ATD0DR4L_BIT1:      equ    1                                         ; Bit 1
ATD0DR4L_BIT2:      equ    2                                         ; Bit 2
ATD0DR4L_BIT3:      equ    3                                         ; Bit 3
ATD0DR4L_BIT4:      equ    4                                         ; Bit 4
ATD0DR4L_BIT5:      equ    5                                         ; Bit 5
ATD0DR4L_BIT6:      equ    6                                         ; Bit 6
ATD0DR4L_BIT7:      equ    7                                         ; Bit 7
; bit position masks
mATD0DR4L_BIT0:     equ    %00000001
mATD0DR4L_BIT1:     equ    %00000010
mATD0DR4L_BIT2:     equ    %00000100
mATD0DR4L_BIT3:     equ    %00001000
mATD0DR4L_BIT4:     equ    %00010000
mATD0DR4L_BIT5:     equ    %00100000
mATD0DR4L_BIT6:     equ    %01000000
mATD0DR4L_BIT7:     equ    %10000000


;*** ATD0DR5 - ATD 0 Conversion Result Register 5; 0x000002DA ***
ATD0DR5:            equ    $000002DA                                ;*** ATD0DR5 - ATD 0 Conversion Result Register 5; 0x000002DA ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ATD0DR5_BIT0:       equ    0                                         ; Bit 0
ATD0DR5_BIT1:       equ    1                                         ; Bit 1
ATD0DR5_BIT2:       equ    2                                         ; Bit 2
ATD0DR5_BIT3:       equ    3                                         ; Bit 3
ATD0DR5_BIT4:       equ    4                                         ; Bit 4
ATD0DR5_BIT5:       equ    5                                         ; Bit 5
ATD0DR5_BIT6:       equ    6                                         ; Bit 6
ATD0DR5_BIT7:       equ    7                                         ; Bit 7
ATD0DR5_BIT8:       equ    8                                         ; Bit 8
ATD0DR5_BIT9:       equ    9                                         ; Bit 9
ATD0DR5_BIT10:      equ    10                                        ; Bit 10
ATD0DR5_BIT11:      equ    11                                        ; Bit 11
ATD0DR5_BIT12:      equ    12                                        ; Bit 12
ATD0DR5_BIT13:      equ    13                                        ; Bit 13
ATD0DR5_BIT14:      equ    14                                        ; Bit 14
ATD0DR5_BIT15:      equ    15                                        ; Bit 15
; bit position masks
mATD0DR5_BIT0:      equ    %00000001
mATD0DR5_BIT1:      equ    %00000010
mATD0DR5_BIT2:      equ    %00000100
mATD0DR5_BIT3:      equ    %00001000
mATD0DR5_BIT4:      equ    %00010000
mATD0DR5_BIT5:      equ    %00100000
mATD0DR5_BIT6:      equ    %01000000
mATD0DR5_BIT7:      equ    %10000000
mATD0DR5_BIT8:      equ    %100000000
mATD0DR5_BIT9:      equ    %1000000000
mATD0DR5_BIT10:     equ    %10000000000
mATD0DR5_BIT11:     equ    %100000000000
mATD0DR5_BIT12:     equ    %1000000000000
mATD0DR5_BIT13:     equ    %10000000000000
mATD0DR5_BIT14:     equ    %100000000000000
mATD0DR5_BIT15:     equ    %1000000000000000


;*** ATD0DR5H - ATD 0 Conversion Result Register 5 High; 0x000002DA ***
ATD0DR5H:           equ    $000002DA                                ;*** ATD0DR5H - ATD 0 Conversion Result Register 5 High; 0x000002DA ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ATD0DR5H_BIT8:      equ    0                                         ; Bit 8
ATD0DR5H_BIT9:      equ    1                                         ; Bit 9
ATD0DR5H_BIT10:     equ    2                                         ; Bit 10
ATD0DR5H_BIT11:     equ    3                                         ; Bit 11
ATD0DR5H_BIT12:     equ    4                                         ; Bit 12
ATD0DR5H_BIT13:     equ    5                                         ; Bit 13
ATD0DR5H_BIT14:     equ    6                                         ; Bit 14
ATD0DR5H_BIT15:     equ    7                                         ; Bit 15
; bit position masks
mATD0DR5H_BIT8:     equ    %00000001
mATD0DR5H_BIT9:     equ    %00000010
mATD0DR5H_BIT10:    equ    %00000100
mATD0DR5H_BIT11:    equ    %00001000
mATD0DR5H_BIT12:    equ    %00010000
mATD0DR5H_BIT13:    equ    %00100000
mATD0DR5H_BIT14:    equ    %01000000
mATD0DR5H_BIT15:    equ    %10000000


;*** ATD0DR5L - ATD 0 Conversion Result Register 5 Low; 0x000002DB ***
ATD0DR5L:           equ    $000002DB                                ;*** ATD0DR5L - ATD 0 Conversion Result Register 5 Low; 0x000002DB ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ATD0DR5L_BIT0:      equ    0                                         ; Bit 0
ATD0DR5L_BIT1:      equ    1                                         ; Bit 1
ATD0DR5L_BIT2:      equ    2                                         ; Bit 2
ATD0DR5L_BIT3:      equ    3                                         ; Bit 3
ATD0DR5L_BIT4:      equ    4                                         ; Bit 4
ATD0DR5L_BIT5:      equ    5                                         ; Bit 5
ATD0DR5L_BIT6:      equ    6                                         ; Bit 6
ATD0DR5L_BIT7:      equ    7                                         ; Bit 7
; bit position masks
mATD0DR5L_BIT0:     equ    %00000001
mATD0DR5L_BIT1:     equ    %00000010
mATD0DR5L_BIT2:     equ    %00000100
mATD0DR5L_BIT3:     equ    %00001000
mATD0DR5L_BIT4:     equ    %00010000
mATD0DR5L_BIT5:     equ    %00100000
mATD0DR5L_BIT6:     equ    %01000000
mATD0DR5L_BIT7:     equ    %10000000


;*** ATD0DR6 - ATD 0 Conversion Result Register 6; 0x000002DC ***
ATD0DR6:            equ    $000002DC                                ;*** ATD0DR6 - ATD 0 Conversion Result Register 6; 0x000002DC ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ATD0DR6_BIT0:       equ    0                                         ; Bit 0
ATD0DR6_BIT1:       equ    1                                         ; Bit 1
ATD0DR6_BIT2:       equ    2                                         ; Bit 2
ATD0DR6_BIT3:       equ    3                                         ; Bit 3
ATD0DR6_BIT4:       equ    4                                         ; Bit 4
ATD0DR6_BIT5:       equ    5                                         ; Bit 5
ATD0DR6_BIT6:       equ    6                                         ; Bit 6
ATD0DR6_BIT7:       equ    7                                         ; Bit 7
ATD0DR6_BIT8:       equ    8                                         ; Bit 8
ATD0DR6_BIT9:       equ    9                                         ; Bit 9
ATD0DR6_BIT10:      equ    10                                        ; Bit 10
ATD0DR6_BIT11:      equ    11                                        ; Bit 11
ATD0DR6_BIT12:      equ    12                                        ; Bit 12
ATD0DR6_BIT13:      equ    13                                        ; Bit 13
ATD0DR6_BIT14:      equ    14                                        ; Bit 14
ATD0DR6_BIT15:      equ    15                                        ; Bit 15
; bit position masks
mATD0DR6_BIT0:      equ    %00000001
mATD0DR6_BIT1:      equ    %00000010
mATD0DR6_BIT2:      equ    %00000100
mATD0DR6_BIT3:      equ    %00001000
mATD0DR6_BIT4:      equ    %00010000
mATD0DR6_BIT5:      equ    %00100000
mATD0DR6_BIT6:      equ    %01000000
mATD0DR6_BIT7:      equ    %10000000
mATD0DR6_BIT8:      equ    %100000000
mATD0DR6_BIT9:      equ    %1000000000
mATD0DR6_BIT10:     equ    %10000000000
mATD0DR6_BIT11:     equ    %100000000000
mATD0DR6_BIT12:     equ    %1000000000000
mATD0DR6_BIT13:     equ    %10000000000000
mATD0DR6_BIT14:     equ    %100000000000000
mATD0DR6_BIT15:     equ    %1000000000000000


;*** ATD0DR6H - ATD 0 Conversion Result Register 6 High; 0x000002DC ***
ATD0DR6H:           equ    $000002DC                                ;*** ATD0DR6H - ATD 0 Conversion Result Register 6 High; 0x000002DC ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ATD0DR6H_BIT8:      equ    0                                         ; Bit 8
ATD0DR6H_BIT9:      equ    1                                         ; Bit 9
ATD0DR6H_BIT10:     equ    2                                         ; Bit 10
ATD0DR6H_BIT11:     equ    3                                         ; Bit 11
ATD0DR6H_BIT12:     equ    4                                         ; Bit 12
ATD0DR6H_BIT13:     equ    5                                         ; Bit 13
ATD0DR6H_BIT14:     equ    6                                         ; Bit 14
ATD0DR6H_BIT15:     equ    7                                         ; Bit 15
; bit position masks
mATD0DR6H_BIT8:     equ    %00000001
mATD0DR6H_BIT9:     equ    %00000010
mATD0DR6H_BIT10:    equ    %00000100
mATD0DR6H_BIT11:    equ    %00001000
mATD0DR6H_BIT12:    equ    %00010000
mATD0DR6H_BIT13:    equ    %00100000
mATD0DR6H_BIT14:    equ    %01000000
mATD0DR6H_BIT15:    equ    %10000000


;*** ATD0DR6L - ATD 0 Conversion Result Register 6 Low; 0x000002DD ***
ATD0DR6L:           equ    $000002DD                                ;*** ATD0DR6L - ATD 0 Conversion Result Register 6 Low; 0x000002DD ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ATD0DR6L_BIT0:      equ    0                                         ; Bit 0
ATD0DR6L_BIT1:      equ    1                                         ; Bit 1
ATD0DR6L_BIT2:      equ    2                                         ; Bit 2
ATD0DR6L_BIT3:      equ    3                                         ; Bit 3
ATD0DR6L_BIT4:      equ    4                                         ; Bit 4
ATD0DR6L_BIT5:      equ    5                                         ; Bit 5
ATD0DR6L_BIT6:      equ    6                                         ; Bit 6
ATD0DR6L_BIT7:      equ    7                                         ; Bit 7
; bit position masks
mATD0DR6L_BIT0:     equ    %00000001
mATD0DR6L_BIT1:     equ    %00000010
mATD0DR6L_BIT2:     equ    %00000100
mATD0DR6L_BIT3:     equ    %00001000
mATD0DR6L_BIT4:     equ    %00010000
mATD0DR6L_BIT5:     equ    %00100000
mATD0DR6L_BIT6:     equ    %01000000
mATD0DR6L_BIT7:     equ    %10000000


;*** ATD0DR7 - ATD 0 Conversion Result Register 7; 0x000002DE ***
ATD0DR7:            equ    $000002DE                                ;*** ATD0DR7 - ATD 0 Conversion Result Register 7; 0x000002DE ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ATD0DR7_BIT0:       equ    0                                         ; Bit 0
ATD0DR7_BIT1:       equ    1                                         ; Bit 1
ATD0DR7_BIT2:       equ    2                                         ; Bit 2
ATD0DR7_BIT3:       equ    3                                         ; Bit 3
ATD0DR7_BIT4:       equ    4                                         ; Bit 4
ATD0DR7_BIT5:       equ    5                                         ; Bit 5
ATD0DR7_BIT6:       equ    6                                         ; Bit 6
ATD0DR7_BIT7:       equ    7                                         ; Bit 7
ATD0DR7_BIT8:       equ    8                                         ; Bit 8
ATD0DR7_BIT9:       equ    9                                         ; Bit 9
ATD0DR7_BIT10:      equ    10                                        ; Bit 10
ATD0DR7_BIT11:      equ    11                                        ; Bit 11
ATD0DR7_BIT12:      equ    12                                        ; Bit 12
ATD0DR7_BIT13:      equ    13                                        ; Bit 13
ATD0DR7_BIT14:      equ    14                                        ; Bit 14
ATD0DR7_BIT15:      equ    15                                        ; Bit 15
; bit position masks
mATD0DR7_BIT0:      equ    %00000001
mATD0DR7_BIT1:      equ    %00000010
mATD0DR7_BIT2:      equ    %00000100
mATD0DR7_BIT3:      equ    %00001000
mATD0DR7_BIT4:      equ    %00010000
mATD0DR7_BIT5:      equ    %00100000
mATD0DR7_BIT6:      equ    %01000000
mATD0DR7_BIT7:      equ    %10000000
mATD0DR7_BIT8:      equ    %100000000
mATD0DR7_BIT9:      equ    %1000000000
mATD0DR7_BIT10:     equ    %10000000000
mATD0DR7_BIT11:     equ    %100000000000
mATD0DR7_BIT12:     equ    %1000000000000
mATD0DR7_BIT13:     equ    %10000000000000
mATD0DR7_BIT14:     equ    %100000000000000
mATD0DR7_BIT15:     equ    %1000000000000000


;*** ATD0DR7H - ATD 0 Conversion Result Register 7 High; 0x000002DE ***
ATD0DR7H:           equ    $000002DE                                ;*** ATD0DR7H - ATD 0 Conversion Result Register 7 High; 0x000002DE ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ATD0DR7H_BIT8:      equ    0                                         ; Bit 8
ATD0DR7H_BIT9:      equ    1                                         ; Bit 9
ATD0DR7H_BIT10:     equ    2                                         ; Bit 10
ATD0DR7H_BIT11:     equ    3                                         ; Bit 11
ATD0DR7H_BIT12:     equ    4                                         ; Bit 12
ATD0DR7H_BIT13:     equ    5                                         ; Bit 13
ATD0DR7H_BIT14:     equ    6                                         ; Bit 14
ATD0DR7H_BIT15:     equ    7                                         ; Bit 15
; bit position masks
mATD0DR7H_BIT8:     equ    %00000001
mATD0DR7H_BIT9:     equ    %00000010
mATD0DR7H_BIT10:    equ    %00000100
mATD0DR7H_BIT11:    equ    %00001000
mATD0DR7H_BIT12:    equ    %00010000
mATD0DR7H_BIT13:    equ    %00100000
mATD0DR7H_BIT14:    equ    %01000000
mATD0DR7H_BIT15:    equ    %10000000


;*** ATD0DR7L - ATD 0 Conversion Result Register 7 Low; 0x000002DF ***
ATD0DR7L:           equ    $000002DF                                ;*** ATD0DR7L - ATD 0 Conversion Result Register 7 Low; 0x000002DF ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ATD0DR7L_BIT0:      equ    0                                         ; Bit 0
ATD0DR7L_BIT1:      equ    1                                         ; Bit 1
ATD0DR7L_BIT2:      equ    2                                         ; Bit 2
ATD0DR7L_BIT3:      equ    3                                         ; Bit 3
ATD0DR7L_BIT4:      equ    4                                         ; Bit 4
ATD0DR7L_BIT5:      equ    5                                         ; Bit 5
ATD0DR7L_BIT6:      equ    6                                         ; Bit 6
ATD0DR7L_BIT7:      equ    7                                         ; Bit 7
; bit position masks
mATD0DR7L_BIT0:     equ    %00000001
mATD0DR7L_BIT1:     equ    %00000010
mATD0DR7L_BIT2:     equ    %00000100
mATD0DR7L_BIT3:     equ    %00001000
mATD0DR7L_BIT4:     equ    %00010000
mATD0DR7L_BIT5:     equ    %00100000
mATD0DR7L_BIT6:     equ    %01000000
mATD0DR7L_BIT7:     equ    %10000000


;*** ATD0DR8 - ATD 0 Conversion Result Register 8; 0x000002E0 ***
ATD0DR8:            equ    $000002E0                                ;*** ATD0DR8 - ATD 0 Conversion Result Register 8; 0x000002E0 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ATD0DR8_BIT0:       equ    0                                         ; Bit 0
ATD0DR8_BIT1:       equ    1                                         ; Bit 1
ATD0DR8_BIT2:       equ    2                                         ; Bit 2
ATD0DR8_BIT3:       equ    3                                         ; Bit 3
ATD0DR8_BIT4:       equ    4                                         ; Bit 4
ATD0DR8_BIT5:       equ    5                                         ; Bit 5
ATD0DR8_BIT6:       equ    6                                         ; Bit 6
ATD0DR8_BIT7:       equ    7                                         ; Bit 7
ATD0DR8_BIT8:       equ    8                                         ; Bit 8
ATD0DR8_BIT9:       equ    9                                         ; Bit 9
ATD0DR8_BIT10:      equ    10                                        ; Bit 10
ATD0DR8_BIT11:      equ    11                                        ; Bit 11
ATD0DR8_BIT12:      equ    12                                        ; Bit 12
ATD0DR8_BIT13:      equ    13                                        ; Bit 13
ATD0DR8_BIT14:      equ    14                                        ; Bit 14
ATD0DR8_BIT15:      equ    15                                        ; Bit 15
; bit position masks
mATD0DR8_BIT0:      equ    %00000001
mATD0DR8_BIT1:      equ    %00000010
mATD0DR8_BIT2:      equ    %00000100
mATD0DR8_BIT3:      equ    %00001000
mATD0DR8_BIT4:      equ    %00010000
mATD0DR8_BIT5:      equ    %00100000
mATD0DR8_BIT6:      equ    %01000000
mATD0DR8_BIT7:      equ    %10000000
mATD0DR8_BIT8:      equ    %100000000
mATD0DR8_BIT9:      equ    %1000000000
mATD0DR8_BIT10:     equ    %10000000000
mATD0DR8_BIT11:     equ    %100000000000
mATD0DR8_BIT12:     equ    %1000000000000
mATD0DR8_BIT13:     equ    %10000000000000
mATD0DR8_BIT14:     equ    %100000000000000
mATD0DR8_BIT15:     equ    %1000000000000000


;*** ATD0DR8H - ATD 0 Conversion Result Register 8 High; 0x000002E0 ***
ATD0DR8H:           equ    $000002E0                                ;*** ATD0DR8H - ATD 0 Conversion Result Register 8 High; 0x000002E0 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ATD0DR8H_BIT8:      equ    0                                         ; Bit 8
ATD0DR8H_BIT9:      equ    1                                         ; Bit 9
ATD0DR8H_BIT10:     equ    2                                         ; Bit 10
ATD0DR8H_BIT11:     equ    3                                         ; Bit 11
ATD0DR8H_BIT12:     equ    4                                         ; Bit 12
ATD0DR8H_BIT13:     equ    5                                         ; Bit 13
ATD0DR8H_BIT14:     equ    6                                         ; Bit 14
ATD0DR8H_BIT15:     equ    7                                         ; Bit 15
; bit position masks
mATD0DR8H_BIT8:     equ    %00000001
mATD0DR8H_BIT9:     equ    %00000010
mATD0DR8H_BIT10:    equ    %00000100
mATD0DR8H_BIT11:    equ    %00001000
mATD0DR8H_BIT12:    equ    %00010000
mATD0DR8H_BIT13:    equ    %00100000
mATD0DR8H_BIT14:    equ    %01000000
mATD0DR8H_BIT15:    equ    %10000000


;*** ATD0DR8L - ATD 0 Conversion Result Register 8 Low; 0x000002E1 ***
ATD0DR8L:           equ    $000002E1                                ;*** ATD0DR8L - ATD 0 Conversion Result Register 8 Low; 0x000002E1 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ATD0DR8L_BIT0:      equ    0                                         ; Bit 0
ATD0DR8L_BIT1:      equ    1                                         ; Bit 1
ATD0DR8L_BIT2:      equ    2                                         ; Bit 2
ATD0DR8L_BIT3:      equ    3                                         ; Bit 3
ATD0DR8L_BIT4:      equ    4                                         ; Bit 4
ATD0DR8L_BIT5:      equ    5                                         ; Bit 5
ATD0DR8L_BIT6:      equ    6                                         ; Bit 6
ATD0DR8L_BIT7:      equ    7                                         ; Bit 7
; bit position masks
mATD0DR8L_BIT0:     equ    %00000001
mATD0DR8L_BIT1:     equ    %00000010
mATD0DR8L_BIT2:     equ    %00000100
mATD0DR8L_BIT3:     equ    %00001000
mATD0DR8L_BIT4:     equ    %00010000
mATD0DR8L_BIT5:     equ    %00100000
mATD0DR8L_BIT6:     equ    %01000000
mATD0DR8L_BIT7:     equ    %10000000


;*** ATD0DR9 - ATD 0 Conversion Result Register 9; 0x000002E2 ***
ATD0DR9:            equ    $000002E2                                ;*** ATD0DR9 - ATD 0 Conversion Result Register 9; 0x000002E2 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ATD0DR9_BIT0:       equ    0                                         ; Bit 0
ATD0DR9_BIT1:       equ    1                                         ; Bit 1
ATD0DR9_BIT2:       equ    2                                         ; Bit 2
ATD0DR9_BIT3:       equ    3                                         ; Bit 3
ATD0DR9_BIT4:       equ    4                                         ; Bit 4
ATD0DR9_BIT5:       equ    5                                         ; Bit 5
ATD0DR9_BIT6:       equ    6                                         ; Bit 6
ATD0DR9_BIT7:       equ    7                                         ; Bit 7
ATD0DR9_BIT8:       equ    8                                         ; Bit 8
ATD0DR9_BIT9:       equ    9                                         ; Bit 9
ATD0DR9_BIT10:      equ    10                                        ; Bit 10
ATD0DR9_BIT11:      equ    11                                        ; Bit 11
ATD0DR9_BIT12:      equ    12                                        ; Bit 12
ATD0DR9_BIT13:      equ    13                                        ; Bit 13
ATD0DR9_BIT14:      equ    14                                        ; Bit 14
ATD0DR9_BIT15:      equ    15                                        ; Bit 15
; bit position masks
mATD0DR9_BIT0:      equ    %00000001
mATD0DR9_BIT1:      equ    %00000010
mATD0DR9_BIT2:      equ    %00000100
mATD0DR9_BIT3:      equ    %00001000
mATD0DR9_BIT4:      equ    %00010000
mATD0DR9_BIT5:      equ    %00100000
mATD0DR9_BIT6:      equ    %01000000
mATD0DR9_BIT7:      equ    %10000000
mATD0DR9_BIT8:      equ    %100000000
mATD0DR9_BIT9:      equ    %1000000000
mATD0DR9_BIT10:     equ    %10000000000
mATD0DR9_BIT11:     equ    %100000000000
mATD0DR9_BIT12:     equ    %1000000000000
mATD0DR9_BIT13:     equ    %10000000000000
mATD0DR9_BIT14:     equ    %100000000000000
mATD0DR9_BIT15:     equ    %1000000000000000


;*** ATD0DR9H - ATD 0 Conversion Result Register 9 High; 0x000002E2 ***
ATD0DR9H:           equ    $000002E2                                ;*** ATD0DR9H - ATD 0 Conversion Result Register 9 High; 0x000002E2 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ATD0DR9H_BIT8:      equ    0                                         ; Bit 8
ATD0DR9H_BIT9:      equ    1                                         ; Bit 9
ATD0DR9H_BIT10:     equ    2                                         ; Bit 10
ATD0DR9H_BIT11:     equ    3                                         ; Bit 11
ATD0DR9H_BIT12:     equ    4                                         ; Bit 12
ATD0DR9H_BIT13:     equ    5                                         ; Bit 13
ATD0DR9H_BIT14:     equ    6                                         ; Bit 14
ATD0DR9H_BIT15:     equ    7                                         ; Bit 15
; bit position masks
mATD0DR9H_BIT8:     equ    %00000001
mATD0DR9H_BIT9:     equ    %00000010
mATD0DR9H_BIT10:    equ    %00000100
mATD0DR9H_BIT11:    equ    %00001000
mATD0DR9H_BIT12:    equ    %00010000
mATD0DR9H_BIT13:    equ    %00100000
mATD0DR9H_BIT14:    equ    %01000000
mATD0DR9H_BIT15:    equ    %10000000


;*** ATD0DR9L - ATD 0 Conversion Result Register 9 Low; 0x000002E3 ***
ATD0DR9L:           equ    $000002E3                                ;*** ATD0DR9L - ATD 0 Conversion Result Register 9 Low; 0x000002E3 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ATD0DR9L_BIT0:      equ    0                                         ; Bit 0
ATD0DR9L_BIT1:      equ    1                                         ; Bit 1
ATD0DR9L_BIT2:      equ    2                                         ; Bit 2
ATD0DR9L_BIT3:      equ    3                                         ; Bit 3
ATD0DR9L_BIT4:      equ    4                                         ; Bit 4
ATD0DR9L_BIT5:      equ    5                                         ; Bit 5
ATD0DR9L_BIT6:      equ    6                                         ; Bit 6
ATD0DR9L_BIT7:      equ    7                                         ; Bit 7
; bit position masks
mATD0DR9L_BIT0:     equ    %00000001
mATD0DR9L_BIT1:     equ    %00000010
mATD0DR9L_BIT2:     equ    %00000100
mATD0DR9L_BIT3:     equ    %00001000
mATD0DR9L_BIT4:     equ    %00010000
mATD0DR9L_BIT5:     equ    %00100000
mATD0DR9L_BIT6:     equ    %01000000
mATD0DR9L_BIT7:     equ    %10000000


;*** ATD0DR10 - ATD 0 Conversion Result Register 10; 0x000002E4 ***
ATD0DR10:           equ    $000002E4                                ;*** ATD0DR10 - ATD 0 Conversion Result Register 10; 0x000002E4 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ATD0DR10_BIT0:      equ    0                                         ; Bit 0
ATD0DR10_BIT1:      equ    1                                         ; Bit 1
ATD0DR10_BIT2:      equ    2                                         ; Bit 2
ATD0DR10_BIT3:      equ    3                                         ; Bit 3
ATD0DR10_BIT4:      equ    4                                         ; Bit 4
ATD0DR10_BIT5:      equ    5                                         ; Bit 5
ATD0DR10_BIT6:      equ    6                                         ; Bit 6
ATD0DR10_BIT7:      equ    7                                         ; Bit 7
ATD0DR10_BIT8:      equ    8                                         ; Bit 8
ATD0DR10_BIT9:      equ    9                                         ; Bit 9
ATD0DR10_BIT10:     equ    10                                        ; Bit 10
ATD0DR10_BIT11:     equ    11                                        ; Bit 11
ATD0DR10_BIT12:     equ    12                                        ; Bit 12
ATD0DR10_BIT13:     equ    13                                        ; Bit 13
ATD0DR10_BIT14:     equ    14                                        ; Bit 14
ATD0DR10_BIT15:     equ    15                                        ; Bit 15
; bit position masks
mATD0DR10_BIT0:     equ    %00000001
mATD0DR10_BIT1:     equ    %00000010
mATD0DR10_BIT2:     equ    %00000100
mATD0DR10_BIT3:     equ    %00001000
mATD0DR10_BIT4:     equ    %00010000
mATD0DR10_BIT5:     equ    %00100000
mATD0DR10_BIT6:     equ    %01000000
mATD0DR10_BIT7:     equ    %10000000
mATD0DR10_BIT8:     equ    %100000000
mATD0DR10_BIT9:     equ    %1000000000
mATD0DR10_BIT10:    equ    %10000000000
mATD0DR10_BIT11:    equ    %100000000000
mATD0DR10_BIT12:    equ    %1000000000000
mATD0DR10_BIT13:    equ    %10000000000000
mATD0DR10_BIT14:    equ    %100000000000000
mATD0DR10_BIT15:    equ    %1000000000000000


;*** ATD0DR10H - ATD 0 Conversion Result Register 10 High; 0x000002E4 ***
ATD0DR10H:          equ    $000002E4                                ;*** ATD0DR10H - ATD 0 Conversion Result Register 10 High; 0x000002E4 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ATD0DR10H_BIT8:     equ    0                                         ; Bit 8
ATD0DR10H_BIT9:     equ    1                                         ; Bit 9
ATD0DR10H_BIT10:    equ    2                                         ; Bit 10
ATD0DR10H_BIT11:    equ    3                                         ; Bit 11
ATD0DR10H_BIT12:    equ    4                                         ; Bit 12
ATD0DR10H_BIT13:    equ    5                                         ; Bit 13
ATD0DR10H_BIT14:    equ    6                                         ; Bit 14
ATD0DR10H_BIT15:    equ    7                                         ; Bit 15
; bit position masks
mATD0DR10H_BIT8:    equ    %00000001
mATD0DR10H_BIT9:    equ    %00000010
mATD0DR10H_BIT10:   equ    %00000100
mATD0DR10H_BIT11:   equ    %00001000
mATD0DR10H_BIT12:   equ    %00010000
mATD0DR10H_BIT13:   equ    %00100000
mATD0DR10H_BIT14:   equ    %01000000
mATD0DR10H_BIT15:   equ    %10000000


;*** ATD0DR10L - ATD 0 Conversion Result Register 10 Low; 0x000002E5 ***
ATD0DR10L:          equ    $000002E5                                ;*** ATD0DR10L - ATD 0 Conversion Result Register 10 Low; 0x000002E5 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ATD0DR10L_BIT0:     equ    0                                         ; Bit 0
ATD0DR10L_BIT1:     equ    1                                         ; Bit 1
ATD0DR10L_BIT2:     equ    2                                         ; Bit 2
ATD0DR10L_BIT3:     equ    3                                         ; Bit 3
ATD0DR10L_BIT4:     equ    4                                         ; Bit 4
ATD0DR10L_BIT5:     equ    5                                         ; Bit 5
ATD0DR10L_BIT6:     equ    6                                         ; Bit 6
ATD0DR10L_BIT7:     equ    7                                         ; Bit 7
; bit position masks
mATD0DR10L_BIT0:    equ    %00000001
mATD0DR10L_BIT1:    equ    %00000010
mATD0DR10L_BIT2:    equ    %00000100
mATD0DR10L_BIT3:    equ    %00001000
mATD0DR10L_BIT4:    equ    %00010000
mATD0DR10L_BIT5:    equ    %00100000
mATD0DR10L_BIT6:    equ    %01000000
mATD0DR10L_BIT7:    equ    %10000000


;*** ATD0DR11 - ATD 0 Conversion Result Register 11; 0x000002E6 ***
ATD0DR11:           equ    $000002E6                                ;*** ATD0DR11 - ATD 0 Conversion Result Register 11; 0x000002E6 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ATD0DR11_BIT0:      equ    0                                         ; Bit 0
ATD0DR11_BIT1:      equ    1                                         ; Bit 1
ATD0DR11_BIT2:      equ    2                                         ; Bit 2
ATD0DR11_BIT3:      equ    3                                         ; Bit 3
ATD0DR11_BIT4:      equ    4                                         ; Bit 4
ATD0DR11_BIT5:      equ    5                                         ; Bit 5
ATD0DR11_BIT6:      equ    6                                         ; Bit 6
ATD0DR11_BIT7:      equ    7                                         ; Bit 7
ATD0DR11_BIT8:      equ    8                                         ; Bit 8
ATD0DR11_BIT9:      equ    9                                         ; Bit 9
ATD0DR11_BIT10:     equ    10                                        ; Bit 10
ATD0DR11_BIT11:     equ    11                                        ; Bit 11
ATD0DR11_BIT12:     equ    12                                        ; Bit 12
ATD0DR11_BIT13:     equ    13                                        ; Bit 13
ATD0DR11_BIT14:     equ    14                                        ; Bit 14
ATD0DR11_BIT15:     equ    15                                        ; Bit 15
; bit position masks
mATD0DR11_BIT0:     equ    %00000001
mATD0DR11_BIT1:     equ    %00000010
mATD0DR11_BIT2:     equ    %00000100
mATD0DR11_BIT3:     equ    %00001000
mATD0DR11_BIT4:     equ    %00010000
mATD0DR11_BIT5:     equ    %00100000
mATD0DR11_BIT6:     equ    %01000000
mATD0DR11_BIT7:     equ    %10000000
mATD0DR11_BIT8:     equ    %100000000
mATD0DR11_BIT9:     equ    %1000000000
mATD0DR11_BIT10:    equ    %10000000000
mATD0DR11_BIT11:    equ    %100000000000
mATD0DR11_BIT12:    equ    %1000000000000
mATD0DR11_BIT13:    equ    %10000000000000
mATD0DR11_BIT14:    equ    %100000000000000
mATD0DR11_BIT15:    equ    %1000000000000000


;*** ATD0DR11H - ATD 0 Conversion Result Register 11 High; 0x000002E6 ***
ATD0DR11H:          equ    $000002E6                                ;*** ATD0DR11H - ATD 0 Conversion Result Register 11 High; 0x000002E6 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ATD0DR11H_BIT8:     equ    0                                         ; Bit 8
ATD0DR11H_BIT9:     equ    1                                         ; Bit 9
ATD0DR11H_BIT10:    equ    2                                         ; Bit 10
ATD0DR11H_BIT11:    equ    3                                         ; Bit 11
ATD0DR11H_BIT12:    equ    4                                         ; Bit 12
ATD0DR11H_BIT13:    equ    5                                         ; Bit 13
ATD0DR11H_BIT14:    equ    6                                         ; Bit 14
ATD0DR11H_BIT15:    equ    7                                         ; Bit 15
; bit position masks
mATD0DR11H_BIT8:    equ    %00000001
mATD0DR11H_BIT9:    equ    %00000010
mATD0DR11H_BIT10:   equ    %00000100
mATD0DR11H_BIT11:   equ    %00001000
mATD0DR11H_BIT12:   equ    %00010000
mATD0DR11H_BIT13:   equ    %00100000
mATD0DR11H_BIT14:   equ    %01000000
mATD0DR11H_BIT15:   equ    %10000000


;*** ATD0DR11L - ATD 0 Conversion Result Register 11 Low; 0x000002E7 ***
ATD0DR11L:          equ    $000002E7                                ;*** ATD0DR11L - ATD 0 Conversion Result Register 11 Low; 0x000002E7 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ATD0DR11L_BIT0:     equ    0                                         ; Bit 0
ATD0DR11L_BIT1:     equ    1                                         ; Bit 1
ATD0DR11L_BIT2:     equ    2                                         ; Bit 2
ATD0DR11L_BIT3:     equ    3                                         ; Bit 3
ATD0DR11L_BIT4:     equ    4                                         ; Bit 4
ATD0DR11L_BIT5:     equ    5                                         ; Bit 5
ATD0DR11L_BIT6:     equ    6                                         ; Bit 6
ATD0DR11L_BIT7:     equ    7                                         ; Bit 7
; bit position masks
mATD0DR11L_BIT0:    equ    %00000001
mATD0DR11L_BIT1:    equ    %00000010
mATD0DR11L_BIT2:    equ    %00000100
mATD0DR11L_BIT3:    equ    %00001000
mATD0DR11L_BIT4:    equ    %00010000
mATD0DR11L_BIT5:    equ    %00100000
mATD0DR11L_BIT6:    equ    %01000000
mATD0DR11L_BIT7:    equ    %10000000


;*** ATD0DR12 - ATD 0 Conversion Result Register 12; 0x000002E8 ***
ATD0DR12:           equ    $000002E8                                ;*** ATD0DR12 - ATD 0 Conversion Result Register 12; 0x000002E8 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ATD0DR12_BIT0:      equ    0                                         ; Bit 0
ATD0DR12_BIT1:      equ    1                                         ; Bit 1
ATD0DR12_BIT2:      equ    2                                         ; Bit 2
ATD0DR12_BIT3:      equ    3                                         ; Bit 3
ATD0DR12_BIT4:      equ    4                                         ; Bit 4
ATD0DR12_BIT5:      equ    5                                         ; Bit 5
ATD0DR12_BIT6:      equ    6                                         ; Bit 6
ATD0DR12_BIT7:      equ    7                                         ; Bit 7
ATD0DR12_BIT8:      equ    8                                         ; Bit 8
ATD0DR12_BIT9:      equ    9                                         ; Bit 9
ATD0DR12_BIT10:     equ    10                                        ; Bit 10
ATD0DR12_BIT11:     equ    11                                        ; Bit 11
ATD0DR12_BIT12:     equ    12                                        ; Bit 12
ATD0DR12_BIT13:     equ    13                                        ; Bit 13
ATD0DR12_BIT14:     equ    14                                        ; Bit 14
ATD0DR12_BIT15:     equ    15                                        ; Bit 15
; bit position masks
mATD0DR12_BIT0:     equ    %00000001
mATD0DR12_BIT1:     equ    %00000010
mATD0DR12_BIT2:     equ    %00000100
mATD0DR12_BIT3:     equ    %00001000
mATD0DR12_BIT4:     equ    %00010000
mATD0DR12_BIT5:     equ    %00100000
mATD0DR12_BIT6:     equ    %01000000
mATD0DR12_BIT7:     equ    %10000000
mATD0DR12_BIT8:     equ    %100000000
mATD0DR12_BIT9:     equ    %1000000000
mATD0DR12_BIT10:    equ    %10000000000
mATD0DR12_BIT11:    equ    %100000000000
mATD0DR12_BIT12:    equ    %1000000000000
mATD0DR12_BIT13:    equ    %10000000000000
mATD0DR12_BIT14:    equ    %100000000000000
mATD0DR12_BIT15:    equ    %1000000000000000


;*** ATD0DR12H - ATD 0 Conversion Result Register 12 High; 0x000002E8 ***
ATD0DR12H:          equ    $000002E8                                ;*** ATD0DR12H - ATD 0 Conversion Result Register 12 High; 0x000002E8 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ATD0DR12H_BIT8:     equ    0                                         ; Bit 8
ATD0DR12H_BIT9:     equ    1                                         ; Bit 9
ATD0DR12H_BIT10:    equ    2                                         ; Bit 10
ATD0DR12H_BIT11:    equ    3                                         ; Bit 11
ATD0DR12H_BIT12:    equ    4                                         ; Bit 12
ATD0DR12H_BIT13:    equ    5                                         ; Bit 13
ATD0DR12H_BIT14:    equ    6                                         ; Bit 14
ATD0DR12H_BIT15:    equ    7                                         ; Bit 15
; bit position masks
mATD0DR12H_BIT8:    equ    %00000001
mATD0DR12H_BIT9:    equ    %00000010
mATD0DR12H_BIT10:   equ    %00000100
mATD0DR12H_BIT11:   equ    %00001000
mATD0DR12H_BIT12:   equ    %00010000
mATD0DR12H_BIT13:   equ    %00100000
mATD0DR12H_BIT14:   equ    %01000000
mATD0DR12H_BIT15:   equ    %10000000


;*** ATD0DR12L - ATD 0 Conversion Result Register 12 Low; 0x000002E9 ***
ATD0DR12L:          equ    $000002E9                                ;*** ATD0DR12L - ATD 0 Conversion Result Register 12 Low; 0x000002E9 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ATD0DR12L_BIT0:     equ    0                                         ; Bit 0
ATD0DR12L_BIT1:     equ    1                                         ; Bit 1
ATD0DR12L_BIT2:     equ    2                                         ; Bit 2
ATD0DR12L_BIT3:     equ    3                                         ; Bit 3
ATD0DR12L_BIT4:     equ    4                                         ; Bit 4
ATD0DR12L_BIT5:     equ    5                                         ; Bit 5
ATD0DR12L_BIT6:     equ    6                                         ; Bit 6
ATD0DR12L_BIT7:     equ    7                                         ; Bit 7
; bit position masks
mATD0DR12L_BIT0:    equ    %00000001
mATD0DR12L_BIT1:    equ    %00000010
mATD0DR12L_BIT2:    equ    %00000100
mATD0DR12L_BIT3:    equ    %00001000
mATD0DR12L_BIT4:    equ    %00010000
mATD0DR12L_BIT5:    equ    %00100000
mATD0DR12L_BIT6:    equ    %01000000
mATD0DR12L_BIT7:    equ    %10000000


;*** ATD0DR13 - ATD 0 Conversion Result Register 13; 0x000002EA ***
ATD0DR13:           equ    $000002EA                                ;*** ATD0DR13 - ATD 0 Conversion Result Register 13; 0x000002EA ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ATD0DR13_BIT0:      equ    0                                         ; Bit 0
ATD0DR13_BIT1:      equ    1                                         ; Bit 1
ATD0DR13_BIT2:      equ    2                                         ; Bit 2
ATD0DR13_BIT3:      equ    3                                         ; Bit 3
ATD0DR13_BIT4:      equ    4                                         ; Bit 4
ATD0DR13_BIT5:      equ    5                                         ; Bit 5
ATD0DR13_BIT6:      equ    6                                         ; Bit 6
ATD0DR13_BIT7:      equ    7                                         ; Bit 7
ATD0DR13_BIT8:      equ    8                                         ; Bit 8
ATD0DR13_BIT9:      equ    9                                         ; Bit 9
ATD0DR13_BIT10:     equ    10                                        ; Bit 10
ATD0DR13_BIT11:     equ    11                                        ; Bit 11
ATD0DR13_BIT12:     equ    12                                        ; Bit 12
ATD0DR13_BIT13:     equ    13                                        ; Bit 13
ATD0DR13_BIT14:     equ    14                                        ; Bit 14
ATD0DR13_BIT15:     equ    15                                        ; Bit 15
; bit position masks
mATD0DR13_BIT0:     equ    %00000001
mATD0DR13_BIT1:     equ    %00000010
mATD0DR13_BIT2:     equ    %00000100
mATD0DR13_BIT3:     equ    %00001000
mATD0DR13_BIT4:     equ    %00010000
mATD0DR13_BIT5:     equ    %00100000
mATD0DR13_BIT6:     equ    %01000000
mATD0DR13_BIT7:     equ    %10000000
mATD0DR13_BIT8:     equ    %100000000
mATD0DR13_BIT9:     equ    %1000000000
mATD0DR13_BIT10:    equ    %10000000000
mATD0DR13_BIT11:    equ    %100000000000
mATD0DR13_BIT12:    equ    %1000000000000
mATD0DR13_BIT13:    equ    %10000000000000
mATD0DR13_BIT14:    equ    %100000000000000
mATD0DR13_BIT15:    equ    %1000000000000000


;*** ATD0DR13H - ATD 0 Conversion Result Register 13 High; 0x000002EA ***
ATD0DR13H:          equ    $000002EA                                ;*** ATD0DR13H - ATD 0 Conversion Result Register 13 High; 0x000002EA ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ATD0DR13H_BIT8:     equ    0                                         ; Bit 8
ATD0DR13H_BIT9:     equ    1                                         ; Bit 9
ATD0DR13H_BIT10:    equ    2                                         ; Bit 10
ATD0DR13H_BIT11:    equ    3                                         ; Bit 11
ATD0DR13H_BIT12:    equ    4                                         ; Bit 12
ATD0DR13H_BIT13:    equ    5                                         ; Bit 13
ATD0DR13H_BIT14:    equ    6                                         ; Bit 14
ATD0DR13H_BIT15:    equ    7                                         ; Bit 15
; bit position masks
mATD0DR13H_BIT8:    equ    %00000001
mATD0DR13H_BIT9:    equ    %00000010
mATD0DR13H_BIT10:   equ    %00000100
mATD0DR13H_BIT11:   equ    %00001000
mATD0DR13H_BIT12:   equ    %00010000
mATD0DR13H_BIT13:   equ    %00100000
mATD0DR13H_BIT14:   equ    %01000000
mATD0DR13H_BIT15:   equ    %10000000


;*** ATD0DR13L - ATD 0 Conversion Result Register 13 Low; 0x000002EB ***
ATD0DR13L:          equ    $000002EB                                ;*** ATD0DR13L - ATD 0 Conversion Result Register 13 Low; 0x000002EB ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ATD0DR13L_BIT0:     equ    0                                         ; Bit 0
ATD0DR13L_BIT1:     equ    1                                         ; Bit 1
ATD0DR13L_BIT2:     equ    2                                         ; Bit 2
ATD0DR13L_BIT3:     equ    3                                         ; Bit 3
ATD0DR13L_BIT4:     equ    4                                         ; Bit 4
ATD0DR13L_BIT5:     equ    5                                         ; Bit 5
ATD0DR13L_BIT6:     equ    6                                         ; Bit 6
ATD0DR13L_BIT7:     equ    7                                         ; Bit 7
; bit position masks
mATD0DR13L_BIT0:    equ    %00000001
mATD0DR13L_BIT1:    equ    %00000010
mATD0DR13L_BIT2:    equ    %00000100
mATD0DR13L_BIT3:    equ    %00001000
mATD0DR13L_BIT4:    equ    %00010000
mATD0DR13L_BIT5:    equ    %00100000
mATD0DR13L_BIT6:    equ    %01000000
mATD0DR13L_BIT7:    equ    %10000000


;*** ATD0DR14 - ATD 0 Conversion Result Register 14; 0x000002EC ***
ATD0DR14:           equ    $000002EC                                ;*** ATD0DR14 - ATD 0 Conversion Result Register 14; 0x000002EC ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ATD0DR14_BIT0:      equ    0                                         ; Bit 0
ATD0DR14_BIT1:      equ    1                                         ; Bit 1
ATD0DR14_BIT2:      equ    2                                         ; Bit 2
ATD0DR14_BIT3:      equ    3                                         ; Bit 3
ATD0DR14_BIT4:      equ    4                                         ; Bit 4
ATD0DR14_BIT5:      equ    5                                         ; Bit 5
ATD0DR14_BIT6:      equ    6                                         ; Bit 6
ATD0DR14_BIT7:      equ    7                                         ; Bit 7
ATD0DR14_BIT8:      equ    8                                         ; Bit 8
ATD0DR14_BIT9:      equ    9                                         ; Bit 9
ATD0DR14_BIT10:     equ    10                                        ; Bit 10
ATD0DR14_BIT11:     equ    11                                        ; Bit 11
ATD0DR14_BIT12:     equ    12                                        ; Bit 12
ATD0DR14_BIT13:     equ    13                                        ; Bit 13
ATD0DR14_BIT14:     equ    14                                        ; Bit 14
ATD0DR14_BIT15:     equ    15                                        ; Bit 15
; bit position masks
mATD0DR14_BIT0:     equ    %00000001
mATD0DR14_BIT1:     equ    %00000010
mATD0DR14_BIT2:     equ    %00000100
mATD0DR14_BIT3:     equ    %00001000
mATD0DR14_BIT4:     equ    %00010000
mATD0DR14_BIT5:     equ    %00100000
mATD0DR14_BIT6:     equ    %01000000
mATD0DR14_BIT7:     equ    %10000000
mATD0DR14_BIT8:     equ    %100000000
mATD0DR14_BIT9:     equ    %1000000000
mATD0DR14_BIT10:    equ    %10000000000
mATD0DR14_BIT11:    equ    %100000000000
mATD0DR14_BIT12:    equ    %1000000000000
mATD0DR14_BIT13:    equ    %10000000000000
mATD0DR14_BIT14:    equ    %100000000000000
mATD0DR14_BIT15:    equ    %1000000000000000


;*** ATD0DR14H - ATD 0 Conversion Result Register 14 High; 0x000002EC ***
ATD0DR14H:          equ    $000002EC                                ;*** ATD0DR14H - ATD 0 Conversion Result Register 14 High; 0x000002EC ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ATD0DR14H_BIT8:     equ    0                                         ; Bit 8
ATD0DR14H_BIT9:     equ    1                                         ; Bit 9
ATD0DR14H_BIT10:    equ    2                                         ; Bit 10
ATD0DR14H_BIT11:    equ    3                                         ; Bit 11
ATD0DR14H_BIT12:    equ    4                                         ; Bit 12
ATD0DR14H_BIT13:    equ    5                                         ; Bit 13
ATD0DR14H_BIT14:    equ    6                                         ; Bit 14
ATD0DR14H_BIT15:    equ    7                                         ; Bit 15
; bit position masks
mATD0DR14H_BIT8:    equ    %00000001
mATD0DR14H_BIT9:    equ    %00000010
mATD0DR14H_BIT10:   equ    %00000100
mATD0DR14H_BIT11:   equ    %00001000
mATD0DR14H_BIT12:   equ    %00010000
mATD0DR14H_BIT13:   equ    %00100000
mATD0DR14H_BIT14:   equ    %01000000
mATD0DR14H_BIT15:   equ    %10000000


;*** ATD0DR14L - ATD 0 Conversion Result Register 14 Low; 0x000002ED ***
ATD0DR14L:          equ    $000002ED                                ;*** ATD0DR14L - ATD 0 Conversion Result Register 14 Low; 0x000002ED ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ATD0DR14L_BIT0:     equ    0                                         ; Bit 0
ATD0DR14L_BIT1:     equ    1                                         ; Bit 1
ATD0DR14L_BIT2:     equ    2                                         ; Bit 2
ATD0DR14L_BIT3:     equ    3                                         ; Bit 3
ATD0DR14L_BIT4:     equ    4                                         ; Bit 4
ATD0DR14L_BIT5:     equ    5                                         ; Bit 5
ATD0DR14L_BIT6:     equ    6                                         ; Bit 6
ATD0DR14L_BIT7:     equ    7                                         ; Bit 7
; bit position masks
mATD0DR14L_BIT0:    equ    %00000001
mATD0DR14L_BIT1:    equ    %00000010
mATD0DR14L_BIT2:    equ    %00000100
mATD0DR14L_BIT3:    equ    %00001000
mATD0DR14L_BIT4:    equ    %00010000
mATD0DR14L_BIT5:    equ    %00100000
mATD0DR14L_BIT6:    equ    %01000000
mATD0DR14L_BIT7:    equ    %10000000


;*** ATD0DR15 - ATD 0 Conversion Result Register 15; 0x000002EE ***
ATD0DR15:           equ    $000002EE                                ;*** ATD0DR15 - ATD 0 Conversion Result Register 15; 0x000002EE ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ATD0DR15_BIT0:      equ    0                                         ; Bit 0
ATD0DR15_BIT1:      equ    1                                         ; Bit 1
ATD0DR15_BIT2:      equ    2                                         ; Bit 2
ATD0DR15_BIT3:      equ    3                                         ; Bit 3
ATD0DR15_BIT4:      equ    4                                         ; Bit 4
ATD0DR15_BIT5:      equ    5                                         ; Bit 5
ATD0DR15_BIT6:      equ    6                                         ; Bit 6
ATD0DR15_BIT7:      equ    7                                         ; Bit 7
ATD0DR15_BIT8:      equ    8                                         ; Bit 8
ATD0DR15_BIT9:      equ    9                                         ; Bit 9
ATD0DR15_BIT10:     equ    10                                        ; Bit 10
ATD0DR15_BIT11:     equ    11                                        ; Bit 11
ATD0DR15_BIT12:     equ    12                                        ; Bit 12
ATD0DR15_BIT13:     equ    13                                        ; Bit 13
ATD0DR15_BIT14:     equ    14                                        ; Bit 14
ATD0DR15_BIT15:     equ    15                                        ; Bit 15
; bit position masks
mATD0DR15_BIT0:     equ    %00000001
mATD0DR15_BIT1:     equ    %00000010
mATD0DR15_BIT2:     equ    %00000100
mATD0DR15_BIT3:     equ    %00001000
mATD0DR15_BIT4:     equ    %00010000
mATD0DR15_BIT5:     equ    %00100000
mATD0DR15_BIT6:     equ    %01000000
mATD0DR15_BIT7:     equ    %10000000
mATD0DR15_BIT8:     equ    %100000000
mATD0DR15_BIT9:     equ    %1000000000
mATD0DR15_BIT10:    equ    %10000000000
mATD0DR15_BIT11:    equ    %100000000000
mATD0DR15_BIT12:    equ    %1000000000000
mATD0DR15_BIT13:    equ    %10000000000000
mATD0DR15_BIT14:    equ    %100000000000000
mATD0DR15_BIT15:    equ    %1000000000000000


;*** ATD0DR15H - ATD 0 Conversion Result Register 15 High; 0x000002EE ***
ATD0DR15H:          equ    $000002EE                                ;*** ATD0DR15H - ATD 0 Conversion Result Register 15 High; 0x000002EE ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ATD0DR15H_BIT8:     equ    0                                         ; Bit 8
ATD0DR15H_BIT9:     equ    1                                         ; Bit 9
ATD0DR15H_BIT10:    equ    2                                         ; Bit 10
ATD0DR15H_BIT11:    equ    3                                         ; Bit 11
ATD0DR15H_BIT12:    equ    4                                         ; Bit 12
ATD0DR15H_BIT13:    equ    5                                         ; Bit 13
ATD0DR15H_BIT14:    equ    6                                         ; Bit 14
ATD0DR15H_BIT15:    equ    7                                         ; Bit 15
; bit position masks
mATD0DR15H_BIT8:    equ    %00000001
mATD0DR15H_BIT9:    equ    %00000010
mATD0DR15H_BIT10:   equ    %00000100
mATD0DR15H_BIT11:   equ    %00001000
mATD0DR15H_BIT12:   equ    %00010000
mATD0DR15H_BIT13:   equ    %00100000
mATD0DR15H_BIT14:   equ    %01000000
mATD0DR15H_BIT15:   equ    %10000000


;*** ATD0DR15L - ATD 0 Conversion Result Register 15 Low; 0x000002EF ***
ATD0DR15L:          equ    $000002EF                                ;*** ATD0DR15L - ATD 0 Conversion Result Register 15 Low; 0x000002EF ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ATD0DR15L_BIT0:     equ    0                                         ; Bit 0
ATD0DR15L_BIT1:     equ    1                                         ; Bit 1
ATD0DR15L_BIT2:     equ    2                                         ; Bit 2
ATD0DR15L_BIT3:     equ    3                                         ; Bit 3
ATD0DR15L_BIT4:     equ    4                                         ; Bit 4
ATD0DR15L_BIT5:     equ    5                                         ; Bit 5
ATD0DR15L_BIT6:     equ    6                                         ; Bit 6
ATD0DR15L_BIT7:     equ    7                                         ; Bit 7
; bit position masks
mATD0DR15L_BIT0:    equ    %00000001
mATD0DR15L_BIT1:    equ    %00000010
mATD0DR15L_BIT2:    equ    %00000100
mATD0DR15L_BIT3:    equ    %00001000
mATD0DR15L_BIT4:    equ    %00010000
mATD0DR15L_BIT5:    equ    %00100000
mATD0DR15L_BIT6:    equ    %01000000
mATD0DR15L_BIT7:    equ    %10000000


;*** VREGHTCL - HT Control Register; 0x000002F0 ***
VREGHTCL:           equ    $000002F0                                ;*** VREGHTCL - HT Control Register; 0x000002F0 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
VREGHTCL_HTIF:      equ    0                                         ; High Temperature Interrupt Flag
VREGHTCL_HTIE:      equ    1                                         ; High Temperature Interrupt Enable Bit
VREGHTCL_HTDS:      equ    2                                         ; High Temperature Detect Status Bi
VREGHTCL_HTEN:      equ    3                                         ; High Temperature Enable Bit
VREGHTCL_VAE:       equ    4                                         ; Voltage Access Enable Bit
VREGHTCL_VSEL:      equ    5                                         ; Voltage Access Select Bit
; bit position masks
mVREGHTCL_HTIF:     equ    %00000001
mVREGHTCL_HTIE:     equ    %00000010
mVREGHTCL_HTDS:     equ    %00000100
mVREGHTCL_HTEN:     equ    %00001000
mVREGHTCL_VAE:      equ    %00010000
mVREGHTCL_VSEL:     equ    %00100000


;*** VREGCTRL - Control Register; 0x000002F1 ***
VREGCTRL:           equ    $000002F1                                ;*** VREGCTRL - Control Register; 0x000002F1 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
VREGCTRL_LVIF:      equ    0                                         ; Low-Voltage Interrupt Flag
VREGCTRL_LVIE:      equ    1                                         ; Low-Voltage Interrupt Enable Bit
VREGCTRL_LVDS:      equ    2                                         ; Low-Voltage Detect Status Bit
; bit position masks
mVREGCTRL_LVIF:     equ    %00000001
mVREGCTRL_LVIE:     equ    %00000010
mVREGCTRL_LVDS:     equ    %00000100


;*** VREGAPICL - Autonomous Periodical Interrupt Control Register; 0x000002F2 ***
VREGAPICL:          equ    $000002F2                                ;*** VREGAPICL - Autonomous Periodical Interrupt Control Register; 0x000002F2 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
VREGAPICL_APIF:     equ    0                                         ; Autonomous Periodical Interrupt Flag
VREGAPICL_APIE:     equ    1                                         ; Autonomous Periodical Interrupt Enable Bit
VREGAPICL_APIFE:    equ    2                                         ; Autonomous Periodical Interrupt Feature Enable Bit
VREGAPICL_APIEA:    equ    3                                         ; Autonomous Periodical Interrupt External Access Enable Bit
VREGAPICL_APIES:    equ    4                                         ; Autonomous Periodical Interrupt External Select Bit
VREGAPICL_APICLK:   equ    7                                         ; Autonomous Periodical Interrupt Clock Select Bit
; bit position masks
mVREGAPICL_APIF:    equ    %00000001
mVREGAPICL_APIE:    equ    %00000010
mVREGAPICL_APIFE:   equ    %00000100
mVREGAPICL_APIEA:   equ    %00001000
mVREGAPICL_APIES:   equ    %00010000
mVREGAPICL_APICLK:  equ    %10000000


;*** VREGAPITR - Autonomous Periodical Interrupt Trimming Register; 0x000002F3 ***
VREGAPITR:          equ    $000002F3                                ;*** VREGAPITR - Autonomous Periodical Interrupt Trimming Register; 0x000002F3 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
VREGAPITR_APITR0:   equ    2                                         ; Autonomous Periodical Interrupt Period Trimming Bit 0
VREGAPITR_APITR1:   equ    3                                         ; Autonomous Periodical Interrupt Period Trimming Bit 1
VREGAPITR_APITR2:   equ    4                                         ; Autonomous Periodical Interrupt Period Trimming Bit 2
VREGAPITR_APITR3:   equ    5                                         ; Autonomous Periodical Interrupt Period Trimming Bit 3
VREGAPITR_APITR4:   equ    6                                         ; Autonomous Periodical Interrupt Period Trimming Bit 4
VREGAPITR_APITR5:   equ    7                                         ; Autonomous Periodical Interrupt Period Trimming Bit 5
; bit position masks
mVREGAPITR_APITR0:  equ    %00000100
mVREGAPITR_APITR1:  equ    %00001000
mVREGAPITR_APITR2:  equ    %00010000
mVREGAPITR_APITR3:  equ    %00100000
mVREGAPITR_APITR4:  equ    %01000000
mVREGAPITR_APITR5:  equ    %10000000


;*** VREGAPIR - Autonomous Periodical Interrupt Rate Register; 0x000002F4 ***
VREGAPIR:           equ    $000002F4                                ;*** VREGAPIR - Autonomous Periodical Interrupt Rate Register; 0x000002F4 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
VREGAPIR_APIR0:     equ    0                                         ; Autonomous Periodical Interrupt Rate Bit 0
VREGAPIR_APIR1:     equ    1                                         ; Autonomous Periodical Interrupt Rate Bit 1
VREGAPIR_APIR2:     equ    2                                         ; Autonomous Periodical Interrupt Rate Bit 2
VREGAPIR_APIR3:     equ    3                                         ; Autonomous Periodical Interrupt Rate Bit 3
VREGAPIR_APIR4:     equ    4                                         ; Autonomous Periodical Interrupt Rate Bit 4
VREGAPIR_APIR5:     equ    5                                         ; Autonomous Periodical Interrupt Rate Bit 5
VREGAPIR_APIR6:     equ    6                                         ; Autonomous Periodical Interrupt Rate Bit 6
VREGAPIR_APIR7:     equ    7                                         ; Autonomous Periodical Interrupt Rate Bit 7
VREGAPIR_APIR8:     equ    8                                         ; Autonomous Periodical Interrupt Rate Bit 8
VREGAPIR_APIR9:     equ    9                                         ; Autonomous Periodical Interrupt Rate Bit 9
VREGAPIR_APIR10:    equ    10                                        ; Autonomous Periodical Interrupt Rate Bit 10
VREGAPIR_APIR11:    equ    11                                        ; Autonomous Periodical Interrupt Rate Bit 11
VREGAPIR_APIR12:    equ    12                                        ; Autonomous Periodical Interrupt Rate Bit 12
VREGAPIR_APIR13:    equ    13                                        ; Autonomous Periodical Interrupt Rate Bit 13
VREGAPIR_APIR14:    equ    14                                        ; Autonomous Periodical Interrupt Rate Bit 14
VREGAPIR_APIR15:    equ    15                                        ; Autonomous Periodical Interrupt Rate Bit 15
; bit position masks
mVREGAPIR_APIR0:    equ    %00000001
mVREGAPIR_APIR1:    equ    %00000010
mVREGAPIR_APIR2:    equ    %00000100
mVREGAPIR_APIR3:    equ    %00001000
mVREGAPIR_APIR4:    equ    %00010000
mVREGAPIR_APIR5:    equ    %00100000
mVREGAPIR_APIR6:    equ    %01000000
mVREGAPIR_APIR7:    equ    %10000000
mVREGAPIR_APIR8:    equ    %100000000
mVREGAPIR_APIR9:    equ    %1000000000
mVREGAPIR_APIR10:   equ    %10000000000
mVREGAPIR_APIR11:   equ    %100000000000
mVREGAPIR_APIR12:   equ    %1000000000000
mVREGAPIR_APIR13:   equ    %10000000000000
mVREGAPIR_APIR14:   equ    %100000000000000
mVREGAPIR_APIR15:   equ    %1000000000000000


;*** VREGAPIRH - Autonomous Periodical Interrupt Rate Register High; 0x000002F4 ***
VREGAPIRH:          equ    $000002F4                                ;*** VREGAPIRH - Autonomous Periodical Interrupt Rate Register High; 0x000002F4 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
VREGAPIRH_APIR8:    equ    0                                         ; Autonomous Periodical Interrupt Rate Bit 8
VREGAPIRH_APIR9:    equ    1                                         ; Autonomous Periodical Interrupt Rate Bit 9
VREGAPIRH_APIR10:   equ    2                                         ; Autonomous Periodical Interrupt Rate Bit 10
VREGAPIRH_APIR11:   equ    3                                         ; Autonomous Periodical Interrupt Rate Bit 11
VREGAPIRH_APIR12:   equ    4                                         ; Autonomous Periodical Interrupt Rate Bit 12
VREGAPIRH_APIR13:   equ    5                                         ; Autonomous Periodical Interrupt Rate Bit 13
VREGAPIRH_APIR14:   equ    6                                         ; Autonomous Periodical Interrupt Rate Bit 14
VREGAPIRH_APIR15:   equ    7                                         ; Autonomous Periodical Interrupt Rate Bit 15
; bit position masks
mVREGAPIRH_APIR8:   equ    %00000001
mVREGAPIRH_APIR9:   equ    %00000010
mVREGAPIRH_APIR10:  equ    %00000100
mVREGAPIRH_APIR11:  equ    %00001000
mVREGAPIRH_APIR12:  equ    %00010000
mVREGAPIRH_APIR13:  equ    %00100000
mVREGAPIRH_APIR14:  equ    %01000000
mVREGAPIRH_APIR15:  equ    %10000000


;*** VREGAPIRL - Autonomous Periodical Interrupt Rate Register Low; 0x000002F5 ***
VREGAPIRL:          equ    $000002F5                                ;*** VREGAPIRL - Autonomous Periodical Interrupt Rate Register Low; 0x000002F5 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
VREGAPIRL_APIR0:    equ    0                                         ; Autonomous Periodical Interrupt Rate Bit 0
VREGAPIRL_APIR1:    equ    1                                         ; Autonomous Periodical Interrupt Rate Bit 1
VREGAPIRL_APIR2:    equ    2                                         ; Autonomous Periodical Interrupt Rate Bit 2
VREGAPIRL_APIR3:    equ    3                                         ; Autonomous Periodical Interrupt Rate Bit 3
VREGAPIRL_APIR4:    equ    4                                         ; Autonomous Periodical Interrupt Rate Bit 4
VREGAPIRL_APIR5:    equ    5                                         ; Autonomous Periodical Interrupt Rate Bit 5
VREGAPIRL_APIR6:    equ    6                                         ; Autonomous Periodical Interrupt Rate Bit 6
VREGAPIRL_APIR7:    equ    7                                         ; Autonomous Periodical Interrupt Rate Bit 7
; bit position masks
mVREGAPIRL_APIR0:   equ    %00000001
mVREGAPIRL_APIR1:   equ    %00000010
mVREGAPIRL_APIR2:   equ    %00000100
mVREGAPIRL_APIR3:   equ    %00001000
mVREGAPIRL_APIR4:   equ    %00010000
mVREGAPIRL_APIR5:   equ    %00100000
mVREGAPIRL_APIR6:   equ    %01000000
mVREGAPIRL_APIR7:   equ    %10000000


;*** VREGHTTR - HTTrimming Register; 0x000002F7 ***
VREGHTTR:           equ    $000002F7                                ;*** VREGHTTR - HTTrimming Register; 0x000002F7 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
VREGHTTR_HTTR:      equ    0                                         ; High Temperature Trimming Bits
VREGHTTR_HTOEN:     equ    7                                         ; High Temperature Offeset Enable Bit
; bit position masks
mVREGHTTR_HTTR:     equ    %00001111
mVREGHTTR_HTOEN:    equ    %10000000


;*** PWME - PWM Enable Register; 0x00000300 ***
PWME:               equ    $00000300                                ;*** PWME - PWM Enable Register; 0x00000300 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PWME_PWME0:         equ    0                                         ; Pulse Width Channel 0 Enable
PWME_PWME1:         equ    1                                         ; Pulse Width Channel 1 Enable
PWME_PWME2:         equ    2                                         ; Pulse Width Channel 2 Enable
PWME_PWME3:         equ    3                                         ; Pulse Width Channel 3 Enable
PWME_PWME4:         equ    4                                         ; Pulse Width Channel 4 Enable
PWME_PWME5:         equ    5                                         ; Pulse Width Channel 5 Enable
PWME_PWME6:         equ    6                                         ; Pulse Width Channel 6 Enable
PWME_PWME7:         equ    7                                         ; Pulse Width Channel 7 Enable
; bit position masks
mPWME_PWME0:        equ    %00000001
mPWME_PWME1:        equ    %00000010
mPWME_PWME2:        equ    %00000100
mPWME_PWME3:        equ    %00001000
mPWME_PWME4:        equ    %00010000
mPWME_PWME5:        equ    %00100000
mPWME_PWME6:        equ    %01000000
mPWME_PWME7:        equ    %10000000


;*** PWMPOL - PWM Polarity Register; 0x00000301 ***
PWMPOL:             equ    $00000301                                ;*** PWMPOL - PWM Polarity Register; 0x00000301 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PWMPOL_PPOL0:       equ    0                                         ; Pulse Width Channel 0 Polarity
PWMPOL_PPOL1:       equ    1                                         ; Pulse Width Channel 1 Polarity
PWMPOL_PPOL2:       equ    2                                         ; Pulse Width Channel 2 Polarity
PWMPOL_PPOL3:       equ    3                                         ; Pulse Width Channel 3 Polarity
PWMPOL_PPOL4:       equ    4                                         ; Pulse Width Channel 4 Polarity
PWMPOL_PPOL5:       equ    5                                         ; Pulse Width Channel 5 Polarity
PWMPOL_PPOL6:       equ    6                                         ; Pulse Width Channel 6 Polarity
PWMPOL_PPOL7:       equ    7                                         ; Pulse Width Channel 7 Polarity
; bit position masks
mPWMPOL_PPOL0:      equ    %00000001
mPWMPOL_PPOL1:      equ    %00000010
mPWMPOL_PPOL2:      equ    %00000100
mPWMPOL_PPOL3:      equ    %00001000
mPWMPOL_PPOL4:      equ    %00010000
mPWMPOL_PPOL5:      equ    %00100000
mPWMPOL_PPOL6:      equ    %01000000
mPWMPOL_PPOL7:      equ    %10000000


;*** PWMCLK - PWM Clock Select Register; 0x00000302 ***
PWMCLK:             equ    $00000302                                ;*** PWMCLK - PWM Clock Select Register; 0x00000302 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PWMCLK_PCLK0:       equ    0                                         ; Pulse Width Channel 0 Clock Select
PWMCLK_PCLK1:       equ    1                                         ; Pulse Width Channel 1 Clock Select
PWMCLK_PCLK2:       equ    2                                         ; Pulse Width Channel 2 Clock Select
PWMCLK_PCLK3:       equ    3                                         ; Pulse Width Channel 3 Clock Select
PWMCLK_PCLK4:       equ    4                                         ; Pulse Width Channel 4 Clock Select
PWMCLK_PCLK5:       equ    5                                         ; Pulse Width Channel 5 Clock Select
PWMCLK_PCLK6:       equ    6                                         ; Pulse Width Channel 6 Clock Select
PWMCLK_PCLK7:       equ    7                                         ; Pulse Width Channel 7 Clock Select
; bit position masks
mPWMCLK_PCLK0:      equ    %00000001
mPWMCLK_PCLK1:      equ    %00000010
mPWMCLK_PCLK2:      equ    %00000100
mPWMCLK_PCLK3:      equ    %00001000
mPWMCLK_PCLK4:      equ    %00010000
mPWMCLK_PCLK5:      equ    %00100000
mPWMCLK_PCLK6:      equ    %01000000
mPWMCLK_PCLK7:      equ    %10000000


;*** PWMPRCLK - PWM Prescale Clock Select Register; 0x00000303 ***
PWMPRCLK:           equ    $00000303                                ;*** PWMPRCLK - PWM Prescale Clock Select Register; 0x00000303 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PWMPRCLK_PCKA0:     equ    0                                         ; Prescaler Select for Clock A 0
PWMPRCLK_PCKA1:     equ    1                                         ; Prescaler Select for Clock A 1
PWMPRCLK_PCKA2:     equ    2                                         ; Prescaler Select for Clock A 2
PWMPRCLK_PCKB0:     equ    4                                         ; Prescaler Select for Clock B 0
PWMPRCLK_PCKB1:     equ    5                                         ; Prescaler Select for Clock B 1
PWMPRCLK_PCKB2:     equ    6                                         ; Prescaler Select for Clock B 2
; bit position masks
mPWMPRCLK_PCKA0:    equ    %00000001
mPWMPRCLK_PCKA1:    equ    %00000010
mPWMPRCLK_PCKA2:    equ    %00000100
mPWMPRCLK_PCKB0:    equ    %00010000
mPWMPRCLK_PCKB1:    equ    %00100000
mPWMPRCLK_PCKB2:    equ    %01000000


;*** PWMCAE - PWM Center Align Enable Register; 0x00000304 ***
PWMCAE:             equ    $00000304                                ;*** PWMCAE - PWM Center Align Enable Register; 0x00000304 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PWMCAE_CAE0:        equ    0                                         ; Center Aligned Output Mode on channel 0
PWMCAE_CAE1:        equ    1                                         ; Center Aligned Output Mode on channel 1
PWMCAE_CAE2:        equ    2                                         ; Center Aligned Output Mode on channel 2
PWMCAE_CAE3:        equ    3                                         ; Center Aligned Output Mode on channel 3
PWMCAE_CAE4:        equ    4                                         ; Center Aligned Output Mode on channel 4
PWMCAE_CAE5:        equ    5                                         ; Center Aligned Output Mode on channel 5
PWMCAE_CAE6:        equ    6                                         ; Center Aligned Output Mode on channel 6
PWMCAE_CAE7:        equ    7                                         ; Center Aligned Output Mode on channel 7
; bit position masks
mPWMCAE_CAE0:       equ    %00000001
mPWMCAE_CAE1:       equ    %00000010
mPWMCAE_CAE2:       equ    %00000100
mPWMCAE_CAE3:       equ    %00001000
mPWMCAE_CAE4:       equ    %00010000
mPWMCAE_CAE5:       equ    %00100000
mPWMCAE_CAE6:       equ    %01000000
mPWMCAE_CAE7:       equ    %10000000


;*** PWMCTL - PWM Control Register; 0x00000305 ***
PWMCTL:             equ    $00000305                                ;*** PWMCTL - PWM Control Register; 0x00000305 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PWMCTL_PFRZ:        equ    2                                         ; PWM Counters Stop in Freeze Mode
PWMCTL_PSWAI:       equ    3                                         ; PWM Stops in Wait Mode
PWMCTL_CON01:       equ    4                                         ; Concatenate channels 0 and 1
PWMCTL_CON23:       equ    5                                         ; Concatenate channels 2 and 3
PWMCTL_CON45:       equ    6                                         ; Concatenate channels 4 and 5
PWMCTL_CON67:       equ    7                                         ; Concatenate channels 6 and 7
; bit position masks
mPWMCTL_PFRZ:       equ    %00000100
mPWMCTL_PSWAI:      equ    %00001000
mPWMCTL_CON01:      equ    %00010000
mPWMCTL_CON23:      equ    %00100000
mPWMCTL_CON45:      equ    %01000000
mPWMCTL_CON67:      equ    %10000000


;*** PWMSCLA - PWM Scale A Register; 0x00000308 ***
PWMSCLA:            equ    $00000308                                ;*** PWMSCLA - PWM Scale A Register; 0x00000308 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PWMSCLA_BIT0:       equ    0                                         ; PWM Scale A Bit 0
PWMSCLA_BIT1:       equ    1                                         ; PWM Scale A Bit 1
PWMSCLA_BIT2:       equ    2                                         ; PWM Scale A Bit 2
PWMSCLA_BIT3:       equ    3                                         ; PWM Scale A Bit 3
PWMSCLA_BIT4:       equ    4                                         ; PWM Scale A Bit 4
PWMSCLA_BIT5:       equ    5                                         ; PWM Scale A Bit 5
PWMSCLA_BIT6:       equ    6                                         ; PWM Scale A Bit 6
PWMSCLA_BIT7:       equ    7                                         ; PWM Scale A Bit 7
; bit position masks
mPWMSCLA_BIT0:      equ    %00000001
mPWMSCLA_BIT1:      equ    %00000010
mPWMSCLA_BIT2:      equ    %00000100
mPWMSCLA_BIT3:      equ    %00001000
mPWMSCLA_BIT4:      equ    %00010000
mPWMSCLA_BIT5:      equ    %00100000
mPWMSCLA_BIT6:      equ    %01000000
mPWMSCLA_BIT7:      equ    %10000000


;*** PWMSCLB - PWM Scale B Register; 0x00000309 ***
PWMSCLB:            equ    $00000309                                ;*** PWMSCLB - PWM Scale B Register; 0x00000309 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PWMSCLB_BIT0:       equ    0                                         ; PWM Scale B Bit 0
PWMSCLB_BIT1:       equ    1                                         ; PWM Scale B Bit 1
PWMSCLB_BIT2:       equ    2                                         ; PWM Scale B Bit 2
PWMSCLB_BIT3:       equ    3                                         ; PWM Scale B Bit 3
PWMSCLB_BIT4:       equ    4                                         ; PWM Scale B Bit 4
PWMSCLB_BIT5:       equ    5                                         ; PWM Scale B Bit 5
PWMSCLB_BIT6:       equ    6                                         ; PWM Scale B Bit 6
PWMSCLB_BIT7:       equ    7                                         ; PWM Scale B Bit 7
; bit position masks
mPWMSCLB_BIT0:      equ    %00000001
mPWMSCLB_BIT1:      equ    %00000010
mPWMSCLB_BIT2:      equ    %00000100
mPWMSCLB_BIT3:      equ    %00001000
mPWMSCLB_BIT4:      equ    %00010000
mPWMSCLB_BIT5:      equ    %00100000
mPWMSCLB_BIT6:      equ    %01000000
mPWMSCLB_BIT7:      equ    %10000000


;*** PWMCNT01 - PWM Channel Counter 01 Register; 0x0000030C ***
PWMCNT01:           equ    $0000030C                                ;*** PWMCNT01 - PWM Channel Counter 01 Register; 0x0000030C ***


;*** PWMCNT0 - PWM Channel Counter 0 Register; 0x0000030C ***
PWMCNT0:            equ    $0000030C                                ;*** PWMCNT0 - PWM Channel Counter 0 Register; 0x0000030C ***


;*** PWMCNT1 - PWM Channel Counter 1 Register; 0x0000030D ***
PWMCNT1:            equ    $0000030D                                ;*** PWMCNT1 - PWM Channel Counter 1 Register; 0x0000030D ***


;*** PWMCNT23 - PWM Channel Counter 23 Register; 0x0000030E ***
PWMCNT23:           equ    $0000030E                                ;*** PWMCNT23 - PWM Channel Counter 23 Register; 0x0000030E ***


;*** PWMCNT2 - PWM Channel Counter 2 Register; 0x0000030E ***
PWMCNT2:            equ    $0000030E                                ;*** PWMCNT2 - PWM Channel Counter 2 Register; 0x0000030E ***


;*** PWMCNT3 - PWM Channel Counter 3 Register; 0x0000030F ***
PWMCNT3:            equ    $0000030F                                ;*** PWMCNT3 - PWM Channel Counter 3 Register; 0x0000030F ***


;*** PWMCNT45 - PWM Channel Counter 45 Register; 0x00000310 ***
PWMCNT45:           equ    $00000310                                ;*** PWMCNT45 - PWM Channel Counter 45 Register; 0x00000310 ***


;*** PWMCNT4 - PWM Channel Counter 4 Register; 0x00000310 ***
PWMCNT4:            equ    $00000310                                ;*** PWMCNT4 - PWM Channel Counter 4 Register; 0x00000310 ***


;*** PWMCNT5 - PWM Channel Counter 5 Register; 0x00000311 ***
PWMCNT5:            equ    $00000311                                ;*** PWMCNT5 - PWM Channel Counter 5 Register; 0x00000311 ***


;*** PWMCNT67 - PWM Channel Counter 67 Register; 0x00000312 ***
PWMCNT67:           equ    $00000312                                ;*** PWMCNT67 - PWM Channel Counter 67 Register; 0x00000312 ***


;*** PWMCNT6 - PWM Channel Counter 6 Register; 0x00000312 ***
PWMCNT6:            equ    $00000312                                ;*** PWMCNT6 - PWM Channel Counter 6 Register; 0x00000312 ***


;*** PWMCNT7 - PWM Channel Counter 7 Register; 0x00000313 ***
PWMCNT7:            equ    $00000313                                ;*** PWMCNT7 - PWM Channel Counter 7 Register; 0x00000313 ***


;*** PWMPER01 - PWM Channel Period 01 Register; 0x00000314 ***
PWMPER01:           equ    $00000314                                ;*** PWMPER01 - PWM Channel Period 01 Register; 0x00000314 ***


;*** PWMPER0 - PWM Channel Period 0 Register; 0x00000314 ***
PWMPER0:            equ    $00000314                                ;*** PWMPER0 - PWM Channel Period 0 Register; 0x00000314 ***


;*** PWMPER1 - PWM Channel Period 1 Register; 0x00000315 ***
PWMPER1:            equ    $00000315                                ;*** PWMPER1 - PWM Channel Period 1 Register; 0x00000315 ***


;*** PWMPER23 - PWM Channel Period 23 Register; 0x00000316 ***
PWMPER23:           equ    $00000316                                ;*** PWMPER23 - PWM Channel Period 23 Register; 0x00000316 ***


;*** PWMPER2 - PWM Channel Period 2 Register; 0x00000316 ***
PWMPER2:            equ    $00000316                                ;*** PWMPER2 - PWM Channel Period 2 Register; 0x00000316 ***


;*** PWMPER3 - PWM Channel Period 3 Register; 0x00000317 ***
PWMPER3:            equ    $00000317                                ;*** PWMPER3 - PWM Channel Period 3 Register; 0x00000317 ***


;*** PWMPER45 - PWM Channel Period 45 Register; 0x00000318 ***
PWMPER45:           equ    $00000318                                ;*** PWMPER45 - PWM Channel Period 45 Register; 0x00000318 ***


;*** PWMPER4 - PWM Channel Period 4 Register; 0x00000318 ***
PWMPER4:            equ    $00000318                                ;*** PWMPER4 - PWM Channel Period 4 Register; 0x00000318 ***


;*** PWMPER5 - PWM Channel Period 5 Register; 0x00000319 ***
PWMPER5:            equ    $00000319                                ;*** PWMPER5 - PWM Channel Period 5 Register; 0x00000319 ***


;*** PWMPER67 - PWM Channel Period 67 Register; 0x0000031A ***
PWMPER67:           equ    $0000031A                                ;*** PWMPER67 - PWM Channel Period 67 Register; 0x0000031A ***


;*** PWMPER6 - PWM Channel Period 6 Register; 0x0000031A ***
PWMPER6:            equ    $0000031A                                ;*** PWMPER6 - PWM Channel Period 6 Register; 0x0000031A ***


;*** PWMPER7 - PWM Channel Period 7 Register; 0x0000031B ***
PWMPER7:            equ    $0000031B                                ;*** PWMPER7 - PWM Channel Period 7 Register; 0x0000031B ***


;*** PWMDTY01 - PWM Channel Duty 01 Register; 0x0000031C ***
PWMDTY01:           equ    $0000031C                                ;*** PWMDTY01 - PWM Channel Duty 01 Register; 0x0000031C ***


;*** PWMDTY0 - PWM Channel Duty 0 Register; 0x0000031C ***
PWMDTY0:            equ    $0000031C                                ;*** PWMDTY0 - PWM Channel Duty 0 Register; 0x0000031C ***


;*** PWMDTY1 - PWM Channel Duty 1 Register; 0x0000031D ***
PWMDTY1:            equ    $0000031D                                ;*** PWMDTY1 - PWM Channel Duty 1 Register; 0x0000031D ***


;*** PWMDTY23 - PWM Channel Duty 23 Register; 0x0000031E ***
PWMDTY23:           equ    $0000031E                                ;*** PWMDTY23 - PWM Channel Duty 23 Register; 0x0000031E ***


;*** PWMDTY2 - PWM Channel Duty 2 Register; 0x0000031E ***
PWMDTY2:            equ    $0000031E                                ;*** PWMDTY2 - PWM Channel Duty 2 Register; 0x0000031E ***


;*** PWMDTY3 - PWM Channel Duty 3 Register; 0x0000031F ***
PWMDTY3:            equ    $0000031F                                ;*** PWMDTY3 - PWM Channel Duty 3 Register; 0x0000031F ***


;*** PWMDTY45 - PWM Channel Duty 45 Register; 0x00000320 ***
PWMDTY45:           equ    $00000320                                ;*** PWMDTY45 - PWM Channel Duty 45 Register; 0x00000320 ***


;*** PWMDTY4 - PWM Channel Duty 4 Register; 0x00000320 ***
PWMDTY4:            equ    $00000320                                ;*** PWMDTY4 - PWM Channel Duty 4 Register; 0x00000320 ***


;*** PWMDTY5 - PWM Channel Duty 5 Register; 0x00000321 ***
PWMDTY5:            equ    $00000321                                ;*** PWMDTY5 - PWM Channel Duty 5 Register; 0x00000321 ***


;*** PWMDTY67 - PWM Channel Duty 67 Register; 0x00000322 ***
PWMDTY67:           equ    $00000322                                ;*** PWMDTY67 - PWM Channel Duty 67 Register; 0x00000322 ***


;*** PWMDTY6 - PWM Channel Duty 6 Register; 0x00000322 ***
PWMDTY6:            equ    $00000322                                ;*** PWMDTY6 - PWM Channel Duty 6 Register; 0x00000322 ***


;*** PWMDTY7 - PWM Channel Duty 7 Register; 0x00000323 ***
PWMDTY7:            equ    $00000323                                ;*** PWMDTY7 - PWM Channel Duty 7 Register; 0x00000323 ***


;*** PWMSDN - PWM Shutdown Register; 0x00000324 ***
PWMSDN:             equ    $00000324                                ;*** PWMSDN - PWM Shutdown Register; 0x00000324 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PWMSDN_PWM7ENA:     equ    0                                         ; PWM emergency shutdown Enable
PWMSDN_PWM7INL:     equ    1                                         ; PWM shutdown active input level for ch. 7
PWMSDN_PWM7IN:      equ    2                                         ; PWM channel 7 input status
PWMSDN_PWMLVL:      equ    4                                         ; PWM shutdown output Level
PWMSDN_PWMRSTRT:    equ    5                                         ; PWM Restart
PWMSDN_PWMIE:       equ    6                                         ; PWM Interrupt Enable
PWMSDN_PWMIF:       equ    7                                         ; PWM Interrupt Flag
; bit position masks
mPWMSDN_PWM7ENA:    equ    %00000001
mPWMSDN_PWM7INL:    equ    %00000010
mPWMSDN_PWM7IN:     equ    %00000100
mPWMSDN_PWMLVL:     equ    %00010000
mPWMSDN_PWMRSTRT:   equ    %00100000
mPWMSDN_PWMIE:      equ    %01000000
mPWMSDN_PWMIF:      equ    %10000000


;*** PITCFLMT - PIT Control and Force Load Micro Timer Register; 0x00000340 ***
PITCFLMT:           equ    $00000340                                ;*** PITCFLMT - PIT Control and Force Load Micro Timer Register; 0x00000340 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PITCFLMT_PFLMT0:    equ    0                                         ; PIT Force Load Bits for Micro Timer 0
PITCFLMT_PFLMT1:    equ    1                                         ; PIT Force Load Bits for Micro Timer 1
PITCFLMT_PITFRZ:    equ    5                                         ; PIT Counter Freeze while in Freeze Mode Bit
PITCFLMT_PITSWAI:   equ    6                                         ; PIT Stop in Wait Mode Bit
PITCFLMT_PITE:      equ    7                                         ; PIT Module Enable Bit
; bit position masks
mPITCFLMT_PFLMT0:   equ    %00000001
mPITCFLMT_PFLMT1:   equ    %00000010
mPITCFLMT_PITFRZ:   equ    %00100000
mPITCFLMT_PITSWAI:  equ    %01000000
mPITCFLMT_PITE:     equ    %10000000


;*** PITFLT - PIT Force Load Timer Register; 0x00000341 ***
PITFLT:             equ    $00000341                                ;*** PITFLT - PIT Force Load Timer Register; 0x00000341 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PITFLT_PFLT0:       equ    0                                         ; PIT Force Load Bits for Timer 0
PITFLT_PFLT1:       equ    1                                         ; PIT Force Load Bits for Timer 1
PITFLT_PFLT2:       equ    2                                         ; PIT Force Load Bits for Timer 2
PITFLT_PFLT3:       equ    3                                         ; PIT Force Load Bits for Timer 3
; bit position masks
mPITFLT_PFLT0:      equ    %00000001
mPITFLT_PFLT1:      equ    %00000010
mPITFLT_PFLT2:      equ    %00000100
mPITFLT_PFLT3:      equ    %00001000


;*** PITCE - PIT Channel Enable Register; 0x00000342 ***
PITCE:              equ    $00000342                                ;*** PITCE - PIT Channel Enable Register; 0x00000342 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PITCE_PCE0:         equ    0                                         ; PIT Enable Bits for Timer Channel 0
PITCE_PCE1:         equ    1                                         ; PIT Enable Bits for Timer Channel 1
PITCE_PCE2:         equ    2                                         ; PIT Enable Bits for Timer Channel 2
PITCE_PCE3:         equ    3                                         ; PIT Enable Bits for Timer Channel 3
; bit position masks
mPITCE_PCE0:        equ    %00000001
mPITCE_PCE1:        equ    %00000010
mPITCE_PCE2:        equ    %00000100
mPITCE_PCE3:        equ    %00001000


;*** PITMUX - PIT Multiplex Register; 0x00000343 ***
PITMUX:             equ    $00000343                                ;*** PITMUX - PIT Multiplex Register; 0x00000343 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PITMUX_PMUX0:       equ    0                                         ; PIT Multiplex Bits for Timer Channel 0
PITMUX_PMUX1:       equ    1                                         ; PIT Multiplex Bits for Timer Channel 1
PITMUX_PMUX2:       equ    2                                         ; PIT Multiplex Bits for Timer Channel 2
PITMUX_PMUX3:       equ    3                                         ; PIT Multiplex Bits for Timer Channel 3
; bit position masks
mPITMUX_PMUX0:      equ    %00000001
mPITMUX_PMUX1:      equ    %00000010
mPITMUX_PMUX2:      equ    %00000100
mPITMUX_PMUX3:      equ    %00001000


;*** PITINTE - PIT Interrupt Enable Register; 0x00000344 ***
PITINTE:            equ    $00000344                                ;*** PITINTE - PIT Interrupt Enable Register; 0x00000344 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PITINTE_PINTE0:     equ    0                                         ; PIT Time-out Interrupt Enable Bits for Timer Channel 0
PITINTE_PINTE1:     equ    1                                         ; PIT Time-out Interrupt Enable Bits for Timer Channel 1
PITINTE_PINTE2:     equ    2                                         ; PIT Time-out Interrupt Enable Bits for Timer Channel 2
PITINTE_PINTE3:     equ    3                                         ; PIT Time-out Interrupt Enable Bits for Timer Channel 3
; bit position masks
mPITINTE_PINTE0:    equ    %00000001
mPITINTE_PINTE1:    equ    %00000010
mPITINTE_PINTE2:    equ    %00000100
mPITINTE_PINTE3:    equ    %00001000


;*** PITTF - PIT Time-out Flag Register; 0x00000345 ***
PITTF:              equ    $00000345                                ;*** PITTF - PIT Time-out Flag Register; 0x00000345 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PITTF_PTF0:         equ    0                                         ; PIT Time-out Flag Bits for Timer Channel 0
PITTF_PTF1:         equ    1                                         ; PIT Time-out Flag Bits for Timer Channel 1
PITTF_PTF2:         equ    2                                         ; PIT Time-out Flag Bits for Timer Channel 2
PITTF_PTF3:         equ    3                                         ; PIT Time-out Flag Bits for Timer Channel 3
; bit position masks
mPITTF_PTF0:        equ    %00000001
mPITTF_PTF1:        equ    %00000010
mPITTF_PTF2:        equ    %00000100
mPITTF_PTF3:        equ    %00001000


;*** PITMTLD0 - PIT Micro Timer Load Register 0; 0x00000346 ***
PITMTLD0:           equ    $00000346                                ;*** PITMTLD0 - PIT Micro Timer Load Register 0; 0x00000346 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PITMTLD0_PMTLD0:    equ    0                                         ; PIT Micro Timer Load Bit 0
PITMTLD0_PMTLD1:    equ    1                                         ; PIT Micro Timer Load Bit 1
PITMTLD0_PMTLD2:    equ    2                                         ; PIT Micro Timer Load Bit 2
PITMTLD0_PMTLD3:    equ    3                                         ; PIT Micro Timer Load Bit 3
PITMTLD0_PMTLD4:    equ    4                                         ; PIT Micro Timer Load Bit 4
PITMTLD0_PMTLD5:    equ    5                                         ; PIT Micro Timer Load Bit 5
PITMTLD0_PMTLD6:    equ    6                                         ; PIT Micro Timer Load Bit 6
PITMTLD0_PMTLD7:    equ    7                                         ; PIT Micro Timer Load Bit 7
; bit position masks
mPITMTLD0_PMTLD0:   equ    %00000001
mPITMTLD0_PMTLD1:   equ    %00000010
mPITMTLD0_PMTLD2:   equ    %00000100
mPITMTLD0_PMTLD3:   equ    %00001000
mPITMTLD0_PMTLD4:   equ    %00010000
mPITMTLD0_PMTLD5:   equ    %00100000
mPITMTLD0_PMTLD6:   equ    %01000000
mPITMTLD0_PMTLD7:   equ    %10000000


;*** PITMTLD1 - PIT Micro Timer Load Register 1; 0x00000347 ***
PITMTLD1:           equ    $00000347                                ;*** PITMTLD1 - PIT Micro Timer Load Register 1; 0x00000347 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PITMTLD1_PMTLD0:    equ    0                                         ; PIT Micro Timer Load Bit 0
PITMTLD1_PMTLD1:    equ    1                                         ; PIT Micro Timer Load Bit 1
PITMTLD1_PMTLD2:    equ    2                                         ; PIT Micro Timer Load Bit 2
PITMTLD1_PMTLD3:    equ    3                                         ; PIT Micro Timer Load Bit 3
PITMTLD1_PMTLD4:    equ    4                                         ; PIT Micro Timer Load Bit 4
PITMTLD1_PMTLD5:    equ    5                                         ; PIT Micro Timer Load Bit 5
PITMTLD1_PMTLD6:    equ    6                                         ; PIT Micro Timer Load Bit 6
PITMTLD1_PMTLD7:    equ    7                                         ; PIT Micro Timer Load Bit 7
; bit position masks
mPITMTLD1_PMTLD0:   equ    %00000001
mPITMTLD1_PMTLD1:   equ    %00000010
mPITMTLD1_PMTLD2:   equ    %00000100
mPITMTLD1_PMTLD3:   equ    %00001000
mPITMTLD1_PMTLD4:   equ    %00010000
mPITMTLD1_PMTLD5:   equ    %00100000
mPITMTLD1_PMTLD6:   equ    %01000000
mPITMTLD1_PMTLD7:   equ    %10000000


;*** PITLD0 - PIT Load Register 0; 0x00000348 ***
PITLD0:             equ    $00000348                                ;*** PITLD0 - PIT Load Register 0; 0x00000348 ***


;*** PITCNT0 - PIT Count Register 0; 0x0000034A ***
PITCNT0:            equ    $0000034A                                ;*** PITCNT0 - PIT Count Register 0; 0x0000034A ***


;*** PITLD1 - PIT Load Register 1; 0x0000034C ***
PITLD1:             equ    $0000034C                                ;*** PITLD1 - PIT Load Register 1; 0x0000034C ***


;*** PITCNT1 - PIT Count Register 1; 0x0000034E ***
PITCNT1:            equ    $0000034E                                ;*** PITCNT1 - PIT Count Register 1; 0x0000034E ***


;*** PITLD2 - PIT Load Register 2; 0x00000350 ***
PITLD2:             equ    $00000350                                ;*** PITLD2 - PIT Load Register 2; 0x00000350 ***


;*** PITCNT2 - PIT Count Register 2; 0x00000352 ***
PITCNT2:            equ    $00000352                                ;*** PITCNT2 - PIT Count Register 2; 0x00000352 ***


;*** PITLD3 - PIT Load Register 3; 0x00000354 ***
PITLD3:             equ    $00000354                                ;*** PITLD3 - PIT Load Register 3; 0x00000354 ***


;*** PITCNT3 - PIT Count Register 3; 0x00000356 ***
PITCNT3:            equ    $00000356                                ;*** PITCNT3 - PIT Count Register 3; 0x00000356 ***


;*** BAKEY0 - Backdoor Comparison Key 0; 0x0000FF00 ***
BAKEY0:             equ    $0000FF00                                ;*** BAKEY0 - Backdoor Comparison Key 0; 0x0000FF00 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
BAKEY0_KEY:         equ    0                                         ; Backdoor Comparison Key Bits
; bit position masks
mBAKEY0_KEY:        equ    %1111111111111111


;*** BAKEY1 - Backdoor Comparison Key 1; 0x0000FF02 ***
BAKEY1:             equ    $0000FF02                                ;*** BAKEY1 - Backdoor Comparison Key 1; 0x0000FF02 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
BAKEY1_KEY:         equ    0                                         ; Backdoor Comparison Key Bits
; bit position masks
mBAKEY1_KEY:        equ    %1111111111111111


;*** BAKEY2 - Backdoor Comparison Key 2; 0x0000FF04 ***
BAKEY2:             equ    $0000FF04                                ;*** BAKEY2 - Backdoor Comparison Key 2; 0x0000FF04 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
BAKEY2_KEY:         equ    0                                         ; Backdoor Comparison Key Bits
; bit position masks
mBAKEY2_KEY:        equ    %1111111111111111


;*** BAKEY3 - Backdoor Comparison Key 3; 0x0000FF06 ***
BAKEY3:             equ    $0000FF06                                ;*** BAKEY3 - Backdoor Comparison Key 3; 0x0000FF06 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
BAKEY3_KEY:         equ    0                                         ; Backdoor Comparison Key Bits
; bit position masks
mBAKEY3_KEY:        equ    %1111111111111111


;*** NVFPROT - Non Volatile P-Flash Protection Register; 0x0000FF0C ***
NVFPROT:            equ    $0000FF0C                                ;*** NVFPROT - Non Volatile P-Flash Protection Register; 0x0000FF0C ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NVFPROT_FPLS0:      equ    0                                         ; Flash Protection Lower Address Size Bit 0
NVFPROT_FPLS1:      equ    1                                         ; Flash Protection Lower Address Size Bit 1
NVFPROT_FPLDIS:     equ    2                                         ; Flash Protection Lower Address Range Disable
NVFPROT_FPHS0:      equ    3                                         ; Flash Protection Higher Address Size Bit 0
NVFPROT_FPHS1:      equ    4                                         ; Flash Protection Higher Address Size Bit 1
NVFPROT_FPHDIS:     equ    5                                         ; Flash Protection Higher Address Range Disable
NVFPROT_RNV6:       equ    6                                         ; Reserved Nonvolatile Bit
NVFPROT_FPOPEN:     equ    7                                         ; Flash Protection Operation Enable
; bit position masks
mNVFPROT_FPLS0:     equ    %00000001
mNVFPROT_FPLS1:     equ    %00000010
mNVFPROT_FPLDIS:    equ    %00000100
mNVFPROT_FPHS0:     equ    %00001000
mNVFPROT_FPHS1:     equ    %00010000
mNVFPROT_FPHDIS:    equ    %00100000
mNVFPROT_RNV6:      equ    %01000000
mNVFPROT_FPOPEN:    equ    %10000000


;*** NVDFPROT - Non Volatile D-Flash Protection Register; 0x0000FF0D ***
NVDFPROT:           equ    $0000FF0D                                ;*** NVDFPROT - Non Volatile D-Flash Protection Register; 0x0000FF0D ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NVDFPROT_DPS0:      equ    0                                         ; D-Flash Protection Size Bit 0
NVDFPROT_DPS1:      equ    1                                         ; D-Flash Protection Size Bit 1
NVDFPROT_DPS2:      equ    2                                         ; D-Flash Protection Size Bit 2
NVDFPROT_DPS3:      equ    3                                         ; D-Flash Protection Size Bit 3
NVDFPROT_DPS4:      equ    4                                         ; D-Flash Protection Size Bit 4
NVDFPROT_DPOPEN:    equ    7                                         ; D-Flash Protection Control
; bit position masks
mNVDFPROT_DPS0:     equ    %00000001
mNVDFPROT_DPS1:     equ    %00000010
mNVDFPROT_DPS2:     equ    %00000100
mNVDFPROT_DPS3:     equ    %00001000
mNVDFPROT_DPS4:     equ    %00010000
mNVDFPROT_DPOPEN:   equ    %10000000


;*** NVFOPT - Non Volatile Flash Option Register; 0x0000FF0E ***
NVFOPT:             equ    $0000FF0E                                ;*** NVFOPT - Non Volatile Flash Option Register; 0x0000FF0E ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NVFOPT_NV0:         equ    0                                         ; Nonvolatile Bit 0
NVFOPT_NV1:         equ    1                                         ; Nonvolatile Bit 1
NVFOPT_NV2:         equ    2                                         ; Nonvolatile Bit 2
NVFOPT_NV3:         equ    3                                         ; Nonvolatile Bit 3
NVFOPT_NV4:         equ    4                                         ; Nonvolatile Bit 4
NVFOPT_NV5:         equ    5                                         ; Nonvolatile Bit 5
NVFOPT_NV6:         equ    6                                         ; Nonvolatile Bit 6
NVFOPT_NV7:         equ    7                                         ; Nonvolatile Bit 7
; bit position masks
mNVFOPT_NV0:        equ    %00000001
mNVFOPT_NV1:        equ    %00000010
mNVFOPT_NV2:        equ    %00000100
mNVFOPT_NV3:        equ    %00001000
mNVFOPT_NV4:        equ    %00010000
mNVFOPT_NV5:        equ    %00100000
mNVFOPT_NV6:        equ    %01000000
mNVFOPT_NV7:        equ    %10000000


;*** NVFSEC - Non Volatile Flash Security Register; 0x0000FF0F ***
NVFSEC:             equ    $0000FF0F                                ;*** NVFSEC - Non Volatile Flash Security Register; 0x0000FF0F ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NVFSEC_SEC0:        equ    0                                         ; Flash Security Bit 0
NVFSEC_SEC1:        equ    1                                         ; Flash Security Bit 1
NVFSEC_RNV2:        equ    2                                         ; Reserved Nonvolatile Bit 2
NVFSEC_RNV3:        equ    3                                         ; Reserved Nonvolatile Bit 3
NVFSEC_RNV4:        equ    4                                         ; Reserved Nonvolatile Bit 4
NVFSEC_RNV5:        equ    5                                         ; Reserved Nonvolatile Bit 5
NVFSEC_KEYEN0:      equ    6                                         ; Backdoor Key Security Enable Bit 0
NVFSEC_KEYEN1:      equ    7                                         ; Backdoor Key Security Enable Bit 1
; bit position masks
mNVFSEC_SEC0:       equ    %00000001
mNVFSEC_SEC1:       equ    %00000010
mNVFSEC_RNV2:       equ    %00000100
mNVFSEC_RNV3:       equ    %00001000
mNVFSEC_RNV4:       equ    %00010000
mNVFSEC_RNV5:       equ    %00100000
mNVFSEC_KEYEN0:     equ    %01000000
mNVFSEC_KEYEN1:     equ    %10000000



;***********************************************
;**   D E P R E C I A T E D   S Y M B O L S   **
;***********************************************
        IFNDEF  __GENERATE_APPLICATION__                            ; not supported for absolute assembler
                    XREF    This_symb_has_been_depreciated
        ENDIF
; ---------------------------------------------------------------------------
; The following symbols were removed, because they were invalid or irrelevant
; ---------------------------------------------------------------------------



; **** 20.2.2008 7:32:00

        IFNDEF __GENERATE_APPLICATION__
FSTAT_RSVD:                              equ        This_symb_has_been_depreciated
mFSTAT_RSVD:                             equ        This_symb_has_been_depreciated
        ENDIF
	
; **** 17.4.2008 11:27:59

TCNTH:                                   equ        TCNTHi
TCNTL:                                   equ        TCNTLo
TC0H:                                    equ        TC0Hi
TC0L:                                    equ        TC0Lo
TC1H:                                    equ        TC1Hi
TC1L:                                    equ        TC1Lo
TC2H:                                    equ        TC2Hi
TC2L:                                    equ        TC2Lo
TC3H:                                    equ        TC3Hi
TC3L:                                    equ        TC3Lo
TC4H:                                    equ        TC4Hi
TC4L:                                    equ        TC4Lo
TC5H:                                    equ        TC5Hi
TC5L:                                    equ        TC5Lo
TC6H:                                    equ        TC6Hi
TC6L:                                    equ        TC6Lo
TC7H:                                    equ        TC7Hi
TC7L:                                    equ        TC7Lo

; **** 22.5.2008 14:43:20

VReserved65:                             equ        Vhti


; EOF
