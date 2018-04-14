; Based on CPU DB MC9S12VR64_48, version 3.00.014 (RegistersPrg V2.33)

; ###################################################################
;     Filename  : mc9s12vr64.inc
;     Processor : MC9S12VR64MLF
;     FileFormat: V2.33
;     DataSheet : MC9S12VRRMV3 Rev. 3.1 November 20, 2012
;     Compiler  : CodeWarrior compiler
;     Date/Time : 1/24/2013, 2:11 PM
;     Abstract  :
;         This header implements the mapping of I/O devices.
;
;     Copyright : 1997 - 2012 Freescale Semiconductor, Inc. All Rights Reserved.
;     
;     http      : www.freescale.com
;     mail      : support@freescale.com
;
;     CPU Registers Revisions:
;      - 29.3.2011, V3.00.0:
;              - Corrected names of bits HSSR[HSOL1:0],HSIF[HSOCIF1:0].
;      - 30.6.2011, V3.00.1:
;              - Added registers for PWM channels 2-7. Added bit CSAD in register CPMUCLKS.
;              - Added bit BVLS[1] in register BATE. BVHS moved to register bit 6.
;              - Renamed routing register(PTTRR) to MODRR. Added bits PTADIRL,PTABYPL,PTPSL,PTTEL in register PTAL.
;      - 30.11.2011, V3.00.2:
;              - Renamed routing register PTSRR to MODRR2.
;      - 20.12.2011, V3.00.3:
;              - New features : SCI V6, OC_Masking on HSDRV, LINPHY V2 coresp to LIN spec 2.2
;
;     File-Format-Revisions:
;      - 15.09.2010, V2.33 :
;               - Empty union is not generated for data overlapping registers, cause there is no bit access
;
;     Not all general-purpose I/O pins are available on all packages or on all mask sets of a specific
;     derivative device. To avoid extra current drain from floating input pins, the user’s reset
;     initialization routine in the application program must either enable on-chip pull-up devices
;     or change the direction of unconnected pins to outputs so the pins do not float.
; ###################################################################

;*** Memory Map and Interrupt Vectors
;******************************************
RAMStart:           equ   $00003800
RAMEnd:             equ   $00003FFF
DFLASHStart:        equ   $00000400
DFLASHEnd:          equ   $000005FF
ROM_0600Start:      equ   $00000600
ROM_0600End:        equ   $000037FF
ROM_4000Start:      equ   $00004000
ROM_4000End:        equ   $00007FFF
ROM_C000Start:      equ   $0000C000
ROM_C000End:        equ   $0000FEFF
PAGE_0CStart:       equ   $00030000
PAGE_0CEnd:         equ   $000305FF
PAGE_0C_B800Start:  equ   $00033800
PAGE_0C_B800End:    equ   $00033FFF
PAGE_0EStart:       equ   $00038000
PAGE_0EEnd:         equ   $0003BFFF
;
Vsi:                equ   $0000FF80
Vportad:            equ   $0000FF82
Vatdcompare:        equ   $0000FF84
Vhti:               equ   $0000FF86
Vapi:               equ   $0000FF88
Vlvi:               equ   $0000FF8A
Vportp2:            equ   $0000FF8C
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
Vbats:              equ   $0000FFA8
Vlinphy:            equ   $0000FFAA
Vlsdrv:             equ   $0000FFAC
Vhsdrv:             equ   $0000FFAE
VReserved43:        equ   $0000FFB0
VReserved42:        equ   $0000FFB2
VReserved41:        equ   $0000FFB4
VReserved40:        equ   $0000FFB6
Vflash:             equ   $0000FFB8
Vflashfd:           equ   $0000FFBA
VReserved33:        equ   $0000FFBC
VReserved32:        equ   $0000FFBE
VReserved31:        equ   $0000FFC0
VReserved30:        equ   $0000FFC2
VReserved29:        equ   $0000FFC4
Vcpmuplllck:        equ   $0000FFC6
Vcpmuocsns:         equ   $0000FFC8
VReserved26:        equ   $0000FFCA
VReserved25:        equ   $0000FFCC
Vportl:             equ   $0000FFCE
VReserved23:        equ   $0000FFD0
Vatd:               equ   $0000FFD2
Vsci1:              equ   $0000FFD4
Vsci0:              equ   $0000FFD6
Vspi:               equ   $0000FFD8
VReserved18:        equ   $0000FFDA
VReserved17:        equ   $0000FFDC
Vtimovf:            equ   $0000FFDE
VReserved15:        equ   $0000FFE0
VReserved14:        equ   $0000FFE2
VReserved13:        equ   $0000FFE4
VReserved12:        equ   $0000FFE6
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


;*** PORTE - Port E Data Register; 0x00000008 ***
PORTE:              equ    $00000008                                ;*** PORTE - Port E Data Register; 0x00000008 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PORTE_PE0:          equ    0                                         ; Port E Bit 0
PORTE_PE1:          equ    1                                         ; Port E Bit 1
; bit position masks
mPORTE_PE0:         equ    %00000001
mPORTE_PE1:         equ    %00000010


;*** DDRE - Port E Data Direction Register; 0x00000009 ***
DDRE:               equ    $00000009                                ;*** DDRE - Port E Data Direction Register; 0x00000009 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DDRE_DDRE0:         equ    0                                         ; Data Direction Port E Bit 0
DDRE_DDRE1:         equ    1                                         ; Data Direction Port E Bit 1
; bit position masks
mDDRE_DDRE0:        equ    %00000001
mDDRE_DDRE1:        equ    %00000010


;*** MODE - Mode Register; 0x0000000B ***
MODE:               equ    $0000000B                                ;*** MODE - Mode Register; 0x0000000B ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
MODE_MODC:          equ    7                                         ; Mode Select Bit
; bit position masks
mMODE_MODC:         equ    %10000000


;*** PUCR - Pull-Up Control Register; 0x0000000C ***
PUCR:               equ    $0000000C                                ;*** PUCR - Pull-Up Control Register; 0x0000000C ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PUCR_PDPEE:         equ    4                                         ; Pull-up Port E Enable
PUCR_BKPUE:         equ    6                                         ; BKGD and VREGEN Pin Pull-up Enable
; bit position masks
mPUCR_PDPEE:        equ    %00010000
mPUCR_BKPUE:        equ    %01000000


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
MMCCTL1_NVMRES:     equ    0                                         ; Map internal NVM resources into the global memory map
; bit position masks
mMMCCTL1_NVMRES:    equ    %00000001


;*** PPAGE - Program Page Index Register; 0x00000015 ***
PPAGE:              equ    $00000015                                ;*** PPAGE - Program Page Index Register; 0x00000015 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PPAGE_PIX0:         equ    0                                         ; Program Page Index Bit 0
PPAGE_PIX1:         equ    1                                         ; Program Page Index Bit 1
PPAGE_PIX2:         equ    2                                         ; Program Page Index Bit 2
PPAGE_PIX3:         equ    3                                         ; Program Page Index Bit 3
; bit position masks
mPPAGE_PIX0:        equ    %00000001
mPPAGE_PIX1:        equ    %00000010
mPPAGE_PIX2:        equ    %00000100
mPPAGE_PIX3:        equ    %00001000


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
ECLKCTL_NECLK:      equ    7                                         ; No ECLK
; bit position masks
mECLKCTL_NECLK:     equ    %10000000


;*** PIMMISC - PIM Miscellaneous Register; 0x0000001D ***
PIMMISC:            equ    $0000001D                                ;*** PIMMISC - PIM Miscellaneous Register; 0x0000001D ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PIMMISC_OCPE:       equ    7                                         ; Over-Current Protection Enable
; bit position masks
mPIMMISC_OCPE:      equ    %10000000


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
DBGC1_COMRV0:       equ    0                                         ; Comparator Register Visibility Bits, bit 0
DBGC1_COMRV1:       equ    1                                         ; Comparator Register Visibility Bits, bit 1
DBGC1_DBGBRK:       equ    3                                         ; S12XDBG Breakpoint Enable Bit 1
DBGC1_BDM:          equ    4                                         ; Background Debug Mode Enable
DBGC1_TRIG:         equ    6                                         ; Immediate Trigger Request Bit
DBGC1_ARM:          equ    7                                         ; Arm Bit
; bit position masks
mDBGC1_COMRV0:      equ    %00000001
mDBGC1_COMRV1:      equ    %00000010
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
DBGTCR_TALIGN:      equ    0                                         ; Trigger Align Bit
DBGTCR_TRCMOD0:     equ    2                                         ; Trace Mode Bits, bit 0
DBGTCR_TRCMOD1:     equ    3                                         ; Trace Mode Bits, bit 1
DBGTCR_TSOURCE:     equ    6                                         ; Trace Source Control Bits
; bit position masks
mDBGTCR_TALIGN:     equ    %00000001
mDBGTCR_TRCMOD0:    equ    %00000100
mDBGTCR_TRCMOD1:    equ    %00001000
mDBGTCR_TSOURCE:    equ    %01000000


;*** DBGC2 - Debug Control Register 2; 0x00000023 ***
DBGC2:              equ    $00000023                                ;*** DBGC2 - Debug Control Register 2; 0x00000023 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DBGC2_ABCM0:        equ    0                                         ; A and B Comparator Match Control, bit 0
DBGC2_ABCM1:        equ    1                                         ; A and B Comparator Match Control, bit 1
; bit position masks
mDBGC2_ABCM0:       equ    %00000001
mDBGC2_ABCM1:       equ    %00000010


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
DBGCNT_CNT0:        equ    0                                         ; Count Value, bit 0
DBGCNT_CNT1:        equ    1                                         ; Count Value, bit 1
DBGCNT_CNT2:        equ    2                                         ; Count Value, bit 2
DBGCNT_CNT3:        equ    3                                         ; Count Value, bit 3
DBGCNT_CNT4:        equ    4                                         ; Count Value, bit 4
DBGCNT_CNT5:        equ    5                                         ; Count Value, bit 5
DBGCNT_TBF:         equ    7                                         ; Trace Buffer Full
; bit position masks
mDBGCNT_CNT0:       equ    %00000001
mDBGCNT_CNT1:       equ    %00000010
mDBGCNT_CNT2:       equ    %00000100
mDBGCNT_CNT3:       equ    %00001000
mDBGCNT_CNT4:       equ    %00010000
mDBGCNT_CNT5:       equ    %00100000
mDBGCNT_TBF:        equ    %10000000


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
; bit position masks
mDBGMFR_MC0:        equ    %00000001
mDBGMFR_MC1:        equ    %00000010
mDBGMFR_MC2:        equ    %00000100


;*** DBGXCTL - Debug Comparator Control Register; 0x00000028 ***
DBGXCTL:            equ    $00000028                                ;*** DBGXCTL - Debug Comparator Control Register; 0x00000028 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DBGXCTL_COMPE:      equ    0                                         ; Determines if comparator is enabled
DBGXCTL_NDB:        equ    1                                         ; Not Data Bus(Comparators A and C), Size Comparator Value Bit(Comparators B and D)
DBGXCTL_RWE:        equ    2                                         ; Read/Write Enable Bit
DBGXCTL_RW:         equ    3                                         ; Read/Write Comparator Value Bit
DBGXCTL_BRK:        equ    4                                         ; Break
DBGXCTL_TAG:        equ    5                                         ; Tag Select
DBGXCTL_SZ:         equ    6                                         ; Size Comparator Value Bit
DBGXCTL_SZE:        equ    7                                         ; Size Comparator Enable Bit
; bit position masks
mDBGXCTL_COMPE:     equ    %00000001
mDBGXCTL_NDB:       equ    %00000010
mDBGXCTL_RWE:       equ    %00000100
mDBGXCTL_RW:        equ    %00001000
mDBGXCTL_BRK:       equ    %00010000
mDBGXCTL_TAG:       equ    %00100000
mDBGXCTL_SZ:        equ    %01000000
mDBGXCTL_SZE:       equ    %10000000


;*** DBGXAH - Debug Comparator Address High Register; 0x00000029 ***
DBGXAH:             equ    $00000029                                ;*** DBGXAH - Debug Comparator Address High Register; 0x00000029 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DBGXAH_BIT16:       equ    0                                         ; Comparator Address High Compare Bits
DBGXAH_BIT17:       equ    1                                         ; Comparator Address High Compare Bit 17
; bit position masks
mDBGXAH_BIT16:      equ    %00000001
mDBGXAH_BIT17:      equ    %00000010


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


;*** DBGADH - Debug Comparator Data High Register; 0x0000002C ***
DBGADH:             equ    $0000002C                                ;*** DBGADH - Debug Comparator Data High Register; 0x0000002C ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DBGADH_BIT8:        equ    0                                         ; Comparator Data High Compare Bit 8
DBGADH_BIT9:        equ    1                                         ; Comparator Data High Compare Bit 9
DBGADH_BIT10:       equ    2                                         ; Comparator Data High Compare Bit 10
DBGADH_BIT11:       equ    3                                         ; Comparator Data High Compare Bit 11
DBGADH_BIT12:       equ    4                                         ; Comparator Data High Compare Bit 12
DBGADH_BIT13:       equ    5                                         ; Comparator Data High Compare Bit 13
DBGADH_BIT14:       equ    6                                         ; Comparator Data High Compare Bit 14
DBGADH_BIT15:       equ    7                                         ; Comparator Data High Compare Bit 15
; bit position masks
mDBGADH_BIT8:       equ    %00000001
mDBGADH_BIT9:       equ    %00000010
mDBGADH_BIT10:      equ    %00000100
mDBGADH_BIT11:      equ    %00001000
mDBGADH_BIT12:      equ    %00010000
mDBGADH_BIT13:      equ    %00100000
mDBGADH_BIT14:      equ    %01000000
mDBGADH_BIT15:      equ    %10000000


;*** DBGADL - Debug Comparator Data Low Register; 0x0000002D ***
DBGADL:             equ    $0000002D                                ;*** DBGADL - Debug Comparator Data Low Register; 0x0000002D ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DBGADL_BIT0:        equ    0                                         ; Comparator Data Low Compare Bit 0
DBGADL_BIT1:        equ    1                                         ; Comparator Data Low Compare Bit 1
DBGADL_BIT2:        equ    2                                         ; Comparator Data Low Compare Bit 2
DBGADL_BIT3:        equ    3                                         ; Comparator Data Low Compare Bit 3
DBGADL_BIT4:        equ    4                                         ; Comparator Data Low Compare Bit 4
DBGADL_BIT5:        equ    5                                         ; Comparator Data Low Compare Bit 5
DBGADL_BIT6:        equ    6                                         ; Comparator Data Low Compare Bit 6
DBGADL_BIT7:        equ    7                                         ; Comparator Data Low Compare Bit 7
; bit position masks
mDBGADL_BIT0:       equ    %00000001
mDBGADL_BIT1:       equ    %00000010
mDBGADL_BIT2:       equ    %00000100
mDBGADL_BIT3:       equ    %00001000
mDBGADL_BIT4:       equ    %00010000
mDBGADL_BIT5:       equ    %00100000
mDBGADL_BIT6:       equ    %01000000
mDBGADL_BIT7:       equ    %10000000


;*** DBGADHM - Debug Comparator Data High Mask Register; 0x0000002E ***
DBGADHM:            equ    $0000002E                                ;*** DBGADHM - Debug Comparator Data High Mask Register; 0x0000002E ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DBGADHM_BIT8:       equ    0                                         ; Comparator Data High Mask Bit 8
DBGADHM_BIT9:       equ    1                                         ; Comparator Data High Mask Bit 9
DBGADHM_BIT10:      equ    2                                         ; Comparator Data High Mask Bit 10
DBGADHM_BIT11:      equ    3                                         ; Comparator Data High Mask Bit 11
DBGADHM_BIT12:      equ    4                                         ; Comparator Data High Mask Bit 12
DBGADHM_BIT13:      equ    5                                         ; Comparator Data High Mask Bit 13
DBGADHM_BIT14:      equ    6                                         ; Comparator Data High Mask Bit 14
DBGADHM_BIT15:      equ    7                                         ; Comparator Data High Mask Bit 15
; bit position masks
mDBGADHM_BIT8:      equ    %00000001
mDBGADHM_BIT9:      equ    %00000010
mDBGADHM_BIT10:     equ    %00000100
mDBGADHM_BIT11:     equ    %00001000
mDBGADHM_BIT12:     equ    %00010000
mDBGADHM_BIT13:     equ    %00100000
mDBGADHM_BIT14:     equ    %01000000
mDBGADHM_BIT15:     equ    %10000000


;*** DBGADLM - Debug Comparator Data Low Mask Register; 0x0000002F ***
DBGADLM:            equ    $0000002F                                ;*** DBGADLM - Debug Comparator Data Low Mask Register; 0x0000002F ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DBGADLM_BIT0:       equ    0                                         ; Comparator Data Low Mask Bit 0
DBGADLM_BIT1:       equ    1                                         ; Comparator Data Low Mask Bit 1
DBGADLM_BIT2:       equ    2                                         ; Comparator Data Low Mask Bit 2
DBGADLM_BIT3:       equ    3                                         ; Comparator Data Low Mask Bit 3
DBGADLM_BIT4:       equ    4                                         ; Comparator Data Low Mask Bit 4
DBGADLM_BIT5:       equ    5                                         ; Comparator Data Low Mask Bit 5
DBGADLM_BIT6:       equ    6                                         ; Comparator Data Low Mask Bit 6
DBGADLM_BIT7:       equ    7                                         ; Comparator Data Low Mask Bit 7
; bit position masks
mDBGADLM_BIT0:      equ    %00000001
mDBGADLM_BIT1:      equ    %00000010
mDBGADLM_BIT2:      equ    %00000100
mDBGADLM_BIT3:      equ    %00001000
mDBGADLM_BIT4:      equ    %00010000
mDBGADLM_BIT5:      equ    %00100000
mDBGADLM_BIT6:      equ    %01000000
mDBGADLM_BIT7:      equ    %10000000


;*** CPMUSYNR - S12CPMU Synthesizer Register; 0x00000034 ***
CPMUSYNR:           equ    $00000034                                ;*** CPMUSYNR - S12CPMU Synthesizer Register; 0x00000034 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CPMUSYNR_SYNDIV0:   equ    0                                         ; Multiplication factor of the IPLL bit 0
CPMUSYNR_SYNDIV1:   equ    1                                         ; Multiplication factor of the IPLL bit 1
CPMUSYNR_SYNDIV2:   equ    2                                         ; Multiplication factor of the IPLL bit 2
CPMUSYNR_SYNDIV3:   equ    3                                         ; Multiplication factor of the IPLL bit 3
CPMUSYNR_SYNDIV4:   equ    4                                         ; Multiplication factor of the IPLL bit 4
CPMUSYNR_SYNDIV5:   equ    5                                         ; Multiplication factor of the IPLL bit 5
CPMUSYNR_VCOFRQ0:   equ    6                                         ; VCO frequency range bit 0
CPMUSYNR_VCOFRQ1:   equ    7                                         ; VCO frequency range bit 1
; bit position masks
mCPMUSYNR_SYNDIV0:  equ    %00000001
mCPMUSYNR_SYNDIV1:  equ    %00000010
mCPMUSYNR_SYNDIV2:  equ    %00000100
mCPMUSYNR_SYNDIV3:  equ    %00001000
mCPMUSYNR_SYNDIV4:  equ    %00010000
mCPMUSYNR_SYNDIV5:  equ    %00100000
mCPMUSYNR_VCOFRQ0:  equ    %01000000
mCPMUSYNR_VCOFRQ1:  equ    %10000000


;*** CPMUREFDIV - S12CPMU Reference Divider Register; 0x00000035 ***
CPMUREFDIV:         equ    $00000035                                ;*** CPMUREFDIV - S12CPMU Reference Divider Register; 0x00000035 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CPMUREFDIV_REFDIV0: equ    0                                         ; Finer granularity for the IPLL multiplier steps bit 0
CPMUREFDIV_REFDIV1: equ    1                                         ; Finer granularity for the IPLL multiplier steps bit 1
CPMUREFDIV_REFDIV2: equ    2                                         ; Finer granularity for the IPLL multiplier steps bit 2
CPMUREFDIV_REFDIV3: equ    3                                         ; Finer granularity for the IPLL multiplier steps bit 3
CPMUREFDIV_REFFRQ0: equ    6                                         ; IPLL optimal stability and lock time configuration bit 0
CPMUREFDIV_REFFRQ1: equ    7                                         ; IPLL optimal stability and lock time configuration bit 1
; bit position masks
mCPMUREFDIV_REFDIV0: equ    %00000001
mCPMUREFDIV_REFDIV1: equ    %00000010
mCPMUREFDIV_REFDIV2: equ    %00000100
mCPMUREFDIV_REFDIV3: equ    %00001000
mCPMUREFDIV_REFFRQ0: equ    %01000000
mCPMUREFDIV_REFFRQ1: equ    %10000000


;*** CPMUPOSTDIV - S12CPMU Post Divider Register; 0x00000036 ***
CPMUPOSTDIV:        equ    $00000036                                ;*** CPMUPOSTDIV - S12CPMU Post Divider Register; 0x00000036 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CPMUPOSTDIV_POSTDIV0: equ    0                                       ; Frequency ratio between the VCOCLK and PLLCLK control bit 0
CPMUPOSTDIV_POSTDIV1: equ    1                                       ; Frequency ratio between the VCOCLK and PLLCLK control bit 1
CPMUPOSTDIV_POSTDIV2: equ    2                                       ; Frequency ratio between the VCOCLK and PLLCLK control bit 2
CPMUPOSTDIV_POSTDIV3: equ    3                                       ; Frequency ratio between the VCOCLK and PLLCLK control bit 3
CPMUPOSTDIV_POSTDIV4: equ    4                                       ; Frequency ratio between the VCOCLK and PLLCLK control bit 4
; bit position masks
mCPMUPOSTDIV_POSTDIV0: equ    %00000001
mCPMUPOSTDIV_POSTDIV1: equ    %00000010
mCPMUPOSTDIV_POSTDIV2: equ    %00000100
mCPMUPOSTDIV_POSTDIV3: equ    %00001000
mCPMUPOSTDIV_POSTDIV4: equ    %00010000


;*** CPMUFLG - S12CPMU Flags Register; 0x00000037 ***
CPMUFLG:            equ    $00000037                                ;*** CPMUFLG - S12CPMU Flags Register; 0x00000037 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CPMUFLG_UPOSC:      equ    0                                         ; Oscillator Status Bit
CPMUFLG_OSCIF:      equ    1                                         ; Oscillator Interrupt Flag
CPMUFLG_ILAF:       equ    2                                         ; Illegal Address Reset Flag
CPMUFLG_LOCK:       equ    3                                         ; Lock Status Bit
CPMUFLG_LOCKIF:     equ    4                                         ; IPLL Lock Interrupt Flag
CPMUFLG_LVRF:       equ    5                                         ; Low Voltage Reset Flag
CPMUFLG_PORF:       equ    6                                         ; Power on Reset Flag
CPMUFLG_RTIF:       equ    7                                         ; Real Time Interrupt Flag
; bit position masks
mCPMUFLG_UPOSC:     equ    %00000001
mCPMUFLG_OSCIF:     equ    %00000010
mCPMUFLG_ILAF:      equ    %00000100
mCPMUFLG_LOCK:      equ    %00001000
mCPMUFLG_LOCKIF:    equ    %00010000
mCPMUFLG_LVRF:      equ    %00100000
mCPMUFLG_PORF:      equ    %01000000
mCPMUFLG_RTIF:      equ    %10000000


;*** CPMUINT - S12CPMU Interrupt Enable Register; 0x00000038 ***
CPMUINT:            equ    $00000038                                ;*** CPMUINT - S12CPMU Interrupt Enable Register; 0x00000038 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CPMUINT_OSCIE:      equ    1                                         ; Oscillator Corrupt Interrupt Enable Bit
CPMUINT_LOCKIE:     equ    4                                         ; Lock Interrupt Enable Bit
CPMUINT_RTIE:       equ    7                                         ; Real Time Interrupt Enable Bit
; bit position masks
mCPMUINT_OSCIE:     equ    %00000010
mCPMUINT_LOCKIE:    equ    %00010000
mCPMUINT_RTIE:      equ    %10000000


;*** CPMUCLKS - S12CPMU Clock Select Register; 0x00000039 ***
CPMUCLKS:           equ    $00000039                                ;*** CPMUCLKS - S12CPMU Clock Select Register; 0x00000039 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CPMUCLKS_COPOSCSEL0: equ    0                                        ; COP Clock Select 0
CPMUCLKS_RTIOSCSEL: equ    1                                         ; RTI Clock Select
CPMUCLKS_PCE:       equ    2                                         ; COP Enable During Pseudo Stop Bit
CPMUCLKS_PRE:       equ    3                                         ; RTI Enable During Pseudo Stop Bit
CPMUCLKS_COPOSCSEL1: equ    4                                        ; COP Clock Select 1
CPMUCLKS_CSAD:      equ    5                                         ; COP in Stop Mode ACLK Disable
CPMUCLKS_PSTP:      equ    6                                         ; Pseudo Stop Bit
CPMUCLKS_PLLSEL:    equ    7                                         ; PLL Select Bit
; bit position masks
mCPMUCLKS_COPOSCSEL0: equ    %00000001
mCPMUCLKS_RTIOSCSEL: equ    %00000010
mCPMUCLKS_PCE:      equ    %00000100
mCPMUCLKS_PRE:      equ    %00001000
mCPMUCLKS_COPOSCSEL1: equ    %00010000
mCPMUCLKS_CSAD:     equ    %00100000
mCPMUCLKS_PSTP:     equ    %01000000
mCPMUCLKS_PLLSEL:   equ    %10000000


;*** CPMUPLL - S12CPMU PLL Control Register; 0x0000003A ***
CPMUPLL:            equ    $0000003A                                ;*** CPMUPLL - S12CPMU PLL Control Register; 0x0000003A ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CPMUPLL_FM0:        equ    4                                         ; PLL Frequency Modulation Enable Bit 0
CPMUPLL_FM1:        equ    5                                         ; PLL Frequency Modulation Enable Bit 1
; bit position masks
mCPMUPLL_FM0:       equ    %00010000
mCPMUPLL_FM1:       equ    %00100000


;*** CPMURTI - CPMU RTI Control Register; 0x0000003B ***
CPMURTI:            equ    $0000003B                                ;*** CPMURTI - CPMU RTI Control Register; 0x0000003B ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CPMURTI_RTR0:       equ    0                                         ; Real Time Interrupt Modulus Counter Select Bit 0
CPMURTI_RTR1:       equ    1                                         ; Real Time Interrupt Modulus Counter Select Bit 1
CPMURTI_RTR2:       equ    2                                         ; Real Time Interrupt Modulus Counter Select Bit 2
CPMURTI_RTR3:       equ    3                                         ; Real Time Interrupt Modulus Counter Select Bit 3
CPMURTI_RTR4:       equ    4                                         ; Real Time Interrupt Prescale Rate Select Bit 4
CPMURTI_RTR5:       equ    5                                         ; Real Time Interrupt Prescale Rate Select Bit 5
CPMURTI_RTR6:       equ    6                                         ; Real Time Interrupt Prescale Rate Select Bit 6
CPMURTI_RTDEC:      equ    7                                         ; Decimal or Binary Divider Select Bit
; bit position masks
mCPMURTI_RTR0:      equ    %00000001
mCPMURTI_RTR1:      equ    %00000010
mCPMURTI_RTR2:      equ    %00000100
mCPMURTI_RTR3:      equ    %00001000
mCPMURTI_RTR4:      equ    %00010000
mCPMURTI_RTR5:      equ    %00100000
mCPMURTI_RTR6:      equ    %01000000
mCPMURTI_RTDEC:     equ    %10000000


;*** CPMUCOP - CPMU COP Control Register; 0x0000003C ***
CPMUCOP:            equ    $0000003C                                ;*** CPMUCOP - CPMU COP Control Register; 0x0000003C ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CPMUCOP_CR0:        equ    0                                         ; COP Watchdog Timer Rate select Bit 0
CPMUCOP_CR1:        equ    1                                         ; COP Watchdog Timer Rate select Bit 1
CPMUCOP_CR2:        equ    2                                         ; COP Watchdog Timer Rate select Bit 2
CPMUCOP_WRTMASK:    equ    5                                         ; Write Mask for WCOP
CPMUCOP_RSBCK:      equ    6                                         ; COP and RTI stop in Active BDM mode Bit
CPMUCOP_WCOP:       equ    7                                         ; Window COP mode
; bit position masks
mCPMUCOP_CR0:       equ    %00000001
mCPMUCOP_CR1:       equ    %00000010
mCPMUCOP_CR2:       equ    %00000100
mCPMUCOP_WRTMASK:   equ    %00100000
mCPMUCOP_RSBCK:     equ    %01000000
mCPMUCOP_WCOP:      equ    %10000000


;*** CPMUARMCOP - CPMU COP Timer Arm/Reset Register; 0x0000003F ***
CPMUARMCOP:         equ    $0000003F                                ;*** CPMUARMCOP - CPMU COP Timer Arm/Reset Register; 0x0000003F ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CPMUARMCOP_BIT0:    equ    0                                         ; CPMU COP Timer Arm/Reset Bit 0
CPMUARMCOP_BIT1:    equ    1                                         ; CPMU COP Timer Arm/Reset Bit 1
CPMUARMCOP_BIT2:    equ    2                                         ; CPMU COP Timer Arm/Reset Bit 2
CPMUARMCOP_BIT3:    equ    3                                         ; CPMU COP Timer Arm/Reset Bit 3
CPMUARMCOP_BIT4:    equ    4                                         ; CPMU COP Timer Arm/Reset Bit 4
CPMUARMCOP_BIT5:    equ    5                                         ; CPMU COP Timer Arm/Reset Bit 5
CPMUARMCOP_BIT6:    equ    6                                         ; CPMU COP Timer Arm/Reset Bit 6
CPMUARMCOP_BIT7:    equ    7                                         ; CPMU COP Timer Arm/Reset Bit 7
; bit position masks
mCPMUARMCOP_BIT0:   equ    %00000001
mCPMUARMCOP_BIT1:   equ    %00000010
mCPMUARMCOP_BIT2:   equ    %00000100
mCPMUARMCOP_BIT3:   equ    %00001000
mCPMUARMCOP_BIT4:   equ    %00010000
mCPMUARMCOP_BIT5:   equ    %00100000
mCPMUARMCOP_BIT6:   equ    %01000000
mCPMUARMCOP_BIT7:   equ    %10000000


;*** TIOS - Timer Input Capture/Output Compare Select; 0x00000040 ***
TIOS:               equ    $00000040                                ;*** TIOS - Timer Input Capture/Output Compare Select; 0x00000040 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TIOS_IOS0:          equ    0                                         ; Input Capture or Output Compare Channel Configuration Bit 0
TIOS_IOS1:          equ    1                                         ; Input Capture or Output Compare Channel Configuration Bit 1
TIOS_IOS2:          equ    2                                         ; Input Capture or Output Compare Channel Configuration Bit 2
TIOS_IOS3:          equ    3                                         ; Input Capture or Output Compare Channel Configuration Bit 3
; bit position masks
mTIOS_IOS0:         equ    %00000001
mTIOS_IOS1:         equ    %00000010
mTIOS_IOS2:         equ    %00000100
mTIOS_IOS3:         equ    %00001000


;*** CFORC - Timer Compare Force Register; 0x00000041 ***
CFORC:              equ    $00000041                                ;*** CFORC - Timer Compare Force Register; 0x00000041 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CFORC_FOC0:         equ    0                                         ; Force Output Compare Action for Channel 0
CFORC_FOC1:         equ    1                                         ; Force Output Compare Action for Channel 1
CFORC_FOC2:         equ    2                                         ; Force Output Compare Action for Channel 2
CFORC_FOC3:         equ    3                                         ; Force Output Compare Action for Channel 3
; bit position masks
mCFORC_FOC0:        equ    %00000001
mCFORC_FOC1:        equ    %00000010
mCFORC_FOC2:        equ    %00000100
mCFORC_FOC3:        equ    %00001000


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
; bit position masks
mTTOV_TOV0:         equ    %00000001
mTTOV_TOV1:         equ    %00000010
mTTOV_TOV2:         equ    %00000100
mTTOV_TOV3:         equ    %00001000


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
; bit position masks
mTIE_C0I:           equ    %00000001
mTIE_C1I:           equ    %00000010
mTIE_C2I:           equ    %00000100
mTIE_C3I:           equ    %00001000


;*** TSCR2 - Timer System Control Register 2; 0x0000004D ***
TSCR2:              equ    $0000004D                                ;*** TSCR2 - Timer System Control Register 2; 0x0000004D ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TSCR2_PR0:          equ    0                                         ; Timer Prescaler Select Bit 0
TSCR2_PR1:          equ    1                                         ; Timer Prescaler Select Bit 1
TSCR2_PR2:          equ    2                                         ; Timer Prescaler Select Bit 2
TSCR2_TOI:          equ    7                                         ; Timer Overflow Interrupt Enable
; bit position masks
mTSCR2_PR0:         equ    %00000001
mTSCR2_PR1:         equ    %00000010
mTSCR2_PR2:         equ    %00000100
mTSCR2_TOI:         equ    %10000000


;*** TFLG1 - Main Timer Interrupt Flag 1; 0x0000004E ***
TFLG1:              equ    $0000004E                                ;*** TFLG1 - Main Timer Interrupt Flag 1; 0x0000004E ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TFLG1_C0F:          equ    0                                         ; Input Capture/Output Compare Channel Flag 0
TFLG1_C1F:          equ    1                                         ; Input Capture/Output Compare Channel Flag 1
TFLG1_C2F:          equ    2                                         ; Input Capture/Output Compare Channel Flag 2
TFLG1_C3F:          equ    3                                         ; Input Capture/Output Compare Channel Flag 3
; bit position masks
mTFLG1_C0F:         equ    %00000001
mTFLG1_C1F:         equ    %00000010
mTFLG1_C2F:         equ    %00000100
mTFLG1_C3F:         equ    %00001000


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


;*** OCPD - Output Compare Pin Disconnect Register; 0x0000006C ***
OCPD:               equ    $0000006C                                ;*** OCPD - Output Compare Pin Disconnect Register; 0x0000006C ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
OCPD_OCPD0:         equ    0                                         ; Output Compare Pin Disconnect Bit 0
OCPD_OCPD1:         equ    1                                         ; Output Compare Pin Disconnect Bit 1
OCPD_OCPD2:         equ    2                                         ; Output Compare Pin Disconnect Bit 2
OCPD_OCPD3:         equ    3                                         ; Output Compare Pin Disconnect Bit 3
; bit position masks
mOCPD_OCPD0:        equ    %00000001
mOCPD_OCPD1:        equ    %00000010
mOCPD_OCPD2:        equ    %00000100
mOCPD_OCPD3:        equ    %00001000


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


;*** ATDCTL01 - ATD  Control Register 01; 0x00000070 ***
ATDCTL01:           equ    $00000070                                ;*** ATDCTL01 - ATD  Control Register 01; 0x00000070 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ATDCTL01_ETRIGCH0:  equ    0                                         ; External Trigger Channel Select Bit 0
ATDCTL01_ETRIGCH1:  equ    1                                         ; External Trigger Channel Select Bit 1
ATDCTL01_ETRIGCH2:  equ    2                                         ; External Trigger Channel Select Bit 2
ATDCTL01_ETRIGCH3:  equ    3                                         ; External Trigger Channel Select Bit 3
ATDCTL01_SMP_DIS:   equ    4                                         ; Discharge Before Sampling Bit
ATDCTL01_SRES0:     equ    5                                         ; A/D Resolution Select Bit 0
ATDCTL01_SRES1:     equ    6                                         ; A/D Resolution Select Bit 1
ATDCTL01_ETRIGSEL:  equ    7                                         ; External Trigger Source Select
ATDCTL01_WRAP0:     equ    8                                         ; Wrap Around Channel Select Bit 0
ATDCTL01_WRAP1:     equ    9                                         ; Wrap Around Channel Select Bit 1
ATDCTL01_WRAP2:     equ    10                                        ; Wrap Around Channel Select Bit 2
ATDCTL01_WRAP3:     equ    11                                        ; Wrap Around Channel Select Bit 3
; bit position masks
mATDCTL01_ETRIGCH0: equ    %00000001
mATDCTL01_ETRIGCH1: equ    %00000010
mATDCTL01_ETRIGCH2: equ    %00000100
mATDCTL01_ETRIGCH3: equ    %00001000
mATDCTL01_SMP_DIS:  equ    %00010000
mATDCTL01_SRES0:    equ    %00100000
mATDCTL01_SRES1:    equ    %01000000
mATDCTL01_ETRIGSEL: equ    %10000000
mATDCTL01_WRAP0:    equ    %100000000
mATDCTL01_WRAP1:    equ    %1000000000
mATDCTL01_WRAP2:    equ    %10000000000
mATDCTL01_WRAP3:    equ    %100000000000


;*** ATDCTL0 - ATD  Control Register 0; 0x00000070 ***
ATDCTL0:            equ    $00000070                                ;*** ATDCTL0 - ATD  Control Register 0; 0x00000070 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ATDCTL0_WRAP0:      equ    0                                         ; Wrap Around Channel Select Bit 0
ATDCTL0_WRAP1:      equ    1                                         ; Wrap Around Channel Select Bit 1
ATDCTL0_WRAP2:      equ    2                                         ; Wrap Around Channel Select Bit 2
ATDCTL0_WRAP3:      equ    3                                         ; Wrap Around Channel Select Bit 3
; bit position masks
mATDCTL0_WRAP0:     equ    %00000001
mATDCTL0_WRAP1:     equ    %00000010
mATDCTL0_WRAP2:     equ    %00000100
mATDCTL0_WRAP3:     equ    %00001000


;*** ATDCTL1 - ATD  Control Register 1; 0x00000071 ***
ATDCTL1:            equ    $00000071                                ;*** ATDCTL1 - ATD  Control Register 1; 0x00000071 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ATDCTL1_ETRIGCH0:   equ    0                                         ; External Trigger Channel Select Bit 0
ATDCTL1_ETRIGCH1:   equ    1                                         ; External Trigger Channel Select Bit 1
ATDCTL1_ETRIGCH2:   equ    2                                         ; External Trigger Channel Select Bit 2
ATDCTL1_ETRIGCH3:   equ    3                                         ; External Trigger Channel Select Bit 3
ATDCTL1_SMP_DIS:    equ    4                                         ; Discharge Before Sampling Bit
ATDCTL1_SRES0:      equ    5                                         ; A/D Resolution Select Bit 0
ATDCTL1_SRES1:      equ    6                                         ; A/D Resolution Select Bit 1
ATDCTL1_ETRIGSEL:   equ    7                                         ; External Trigger Source Select
; bit position masks
mATDCTL1_ETRIGCH0:  equ    %00000001
mATDCTL1_ETRIGCH1:  equ    %00000010
mATDCTL1_ETRIGCH2:  equ    %00000100
mATDCTL1_ETRIGCH3:  equ    %00001000
mATDCTL1_SMP_DIS:   equ    %00010000
mATDCTL1_SRES0:     equ    %00100000
mATDCTL1_SRES1:     equ    %01000000
mATDCTL1_ETRIGSEL:  equ    %10000000


;*** ATDCTL23 - ATD  Control Register 23; 0x00000072 ***
ATDCTL23:           equ    $00000072                                ;*** ATDCTL23 - ATD  Control Register 23; 0x00000072 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ATDCTL23_FRZ0:      equ    0                                         ; Background Debug Freeze Enable Bit 0
ATDCTL23_FRZ1:      equ    1                                         ; Background Debug Freeze Enable Bit 1
ATDCTL23_FIFO:      equ    2                                         ; Result Register FIFO Mode
ATDCTL23_S1C:       equ    3                                         ; Conversion Sequence Length 1
ATDCTL23_S2C:       equ    4                                         ; Conversion Sequence Length 2
ATDCTL23_S4C:       equ    5                                         ; Conversion Sequence Length 4
ATDCTL23_S8C:       equ    6                                         ; Conversion Sequence Length 8
ATDCTL23_DJM:       equ    7                                         ; Result Register Data Justification
ATDCTL23_ACMPIE:    equ    8                                         ; ATD Compare Interrupt Enable
ATDCTL23_ASCIE:     equ    9                                         ; ATD Sequence Complete Interrupt Enable
ATDCTL23_ETRIGE:    equ    10                                        ; External Trigger Mode enable
ATDCTL23_ETRIGP:    equ    11                                        ; External Trigger Polarity
ATDCTL23_ETRIGLE:   equ    12                                        ; External Trigger Level/Edge control
ATDCTL23_AFFC:      equ    14                                        ; ATD Fast Conversion Complete Flag Clear
; bit position masks
mATDCTL23_FRZ0:     equ    %00000001
mATDCTL23_FRZ1:     equ    %00000010
mATDCTL23_FIFO:     equ    %00000100
mATDCTL23_S1C:      equ    %00001000
mATDCTL23_S2C:      equ    %00010000
mATDCTL23_S4C:      equ    %00100000
mATDCTL23_S8C:      equ    %01000000
mATDCTL23_DJM:      equ    %10000000
mATDCTL23_ACMPIE:   equ    %100000000
mATDCTL23_ASCIE:    equ    %1000000000
mATDCTL23_ETRIGE:   equ    %10000000000
mATDCTL23_ETRIGP:   equ    %100000000000
mATDCTL23_ETRIGLE:  equ    %1000000000000
mATDCTL23_AFFC:     equ    %100000000000000


;*** ATDCTL2 - ATD  Control Register 2; 0x00000072 ***
ATDCTL2:            equ    $00000072                                ;*** ATDCTL2 - ATD  Control Register 2; 0x00000072 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ATDCTL2_ACMPIE:     equ    0                                         ; ATD Compare Interrupt Enable
ATDCTL2_ASCIE:      equ    1                                         ; ATD Sequence Complete Interrupt Enable
ATDCTL2_ETRIGE:     equ    2                                         ; External Trigger Mode enable
ATDCTL2_ETRIGP:     equ    3                                         ; External Trigger Polarity
ATDCTL2_ETRIGLE:    equ    4                                         ; External Trigger Level/Edge control
ATDCTL2_AFFC:       equ    6                                         ; ATD Fast Conversion Complete Flag Clear
; bit position masks
mATDCTL2_ACMPIE:    equ    %00000001
mATDCTL2_ASCIE:     equ    %00000010
mATDCTL2_ETRIGE:    equ    %00000100
mATDCTL2_ETRIGP:    equ    %00001000
mATDCTL2_ETRIGLE:   equ    %00010000
mATDCTL2_AFFC:      equ    %01000000


;*** ATDCTL3 - ATD  Control Register 3; 0x00000073 ***
ATDCTL3:            equ    $00000073                                ;*** ATDCTL3 - ATD  Control Register 3; 0x00000073 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ATDCTL3_FRZ0:       equ    0                                         ; Background Debug Freeze Enable Bit 0
ATDCTL3_FRZ1:       equ    1                                         ; Background Debug Freeze Enable Bit 1
ATDCTL3_FIFO:       equ    2                                         ; Result Register FIFO Mode
ATDCTL3_S1C:        equ    3                                         ; Conversion Sequence Length 1
ATDCTL3_S2C:        equ    4                                         ; Conversion Sequence Length 2
ATDCTL3_S4C:        equ    5                                         ; Conversion Sequence Length 4
ATDCTL3_S8C:        equ    6                                         ; Conversion Sequence Length 8
ATDCTL3_DJM:        equ    7                                         ; Result Register Data Justification
; bit position masks
mATDCTL3_FRZ0:      equ    %00000001
mATDCTL3_FRZ1:      equ    %00000010
mATDCTL3_FIFO:      equ    %00000100
mATDCTL3_S1C:       equ    %00001000
mATDCTL3_S2C:       equ    %00010000
mATDCTL3_S4C:       equ    %00100000
mATDCTL3_S8C:       equ    %01000000
mATDCTL3_DJM:       equ    %10000000


;*** ATDCTL45 - ATD  Control Register 45; 0x00000074 ***
ATDCTL45:           equ    $00000074                                ;*** ATDCTL45 - ATD  Control Register 45; 0x00000074 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ATDCTL45_CA:        equ    0                                         ; Analog Input Channel Select Code A
ATDCTL45_CB:        equ    1                                         ; Analog Input Channel Select Code B
ATDCTL45_CC:        equ    2                                         ; Analog Input Channel Select Code C
ATDCTL45_CD:        equ    3                                         ; Analog Input Channel Select Code D
ATDCTL45_MULT:      equ    4                                         ; Multi-Channel Sample Mode
ATDCTL45_SCAN:      equ    5                                         ; Continuous Conversion Sequence Mode
ATDCTL45_SC:        equ    6                                         ; Special Channel Conversion Bit
ATDCTL45_PRS0:      equ    8                                         ; ATD Clock Prescaler 0
ATDCTL45_PRS1:      equ    9                                         ; ATD Clock Prescaler 1
ATDCTL45_PRS2:      equ    10                                        ; ATD Clock Prescaler 2
ATDCTL45_PRS3:      equ    11                                        ; ATD Clock Prescaler 3
ATDCTL45_PRS4:      equ    12                                        ; ATD Clock Prescaler 4
ATDCTL45_SMP0:      equ    13                                        ; Sample Time Select 0
ATDCTL45_SMP1:      equ    14                                        ; Sample Time Select 1
ATDCTL45_SMP2:      equ    15                                        ; Sample Time Select 2
; bit position masks
mATDCTL45_CA:       equ    %00000001
mATDCTL45_CB:       equ    %00000010
mATDCTL45_CC:       equ    %00000100
mATDCTL45_CD:       equ    %00001000
mATDCTL45_MULT:     equ    %00010000
mATDCTL45_SCAN:     equ    %00100000
mATDCTL45_SC:       equ    %01000000
mATDCTL45_PRS0:     equ    %100000000
mATDCTL45_PRS1:     equ    %1000000000
mATDCTL45_PRS2:     equ    %10000000000
mATDCTL45_PRS3:     equ    %100000000000
mATDCTL45_PRS4:     equ    %1000000000000
mATDCTL45_SMP0:     equ    %10000000000000
mATDCTL45_SMP1:     equ    %100000000000000
mATDCTL45_SMP2:     equ    %1000000000000000


;*** ATDCTL4 - ATD  Control Register 4; 0x00000074 ***
ATDCTL4:            equ    $00000074                                ;*** ATDCTL4 - ATD  Control Register 4; 0x00000074 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ATDCTL4_PRS0:       equ    0                                         ; ATD Clock Prescaler 0
ATDCTL4_PRS1:       equ    1                                         ; ATD Clock Prescaler 1
ATDCTL4_PRS2:       equ    2                                         ; ATD Clock Prescaler 2
ATDCTL4_PRS3:       equ    3                                         ; ATD Clock Prescaler 3
ATDCTL4_PRS4:       equ    4                                         ; ATD Clock Prescaler 4
ATDCTL4_SMP0:       equ    5                                         ; Sample Time Select 0
ATDCTL4_SMP1:       equ    6                                         ; Sample Time Select 1
ATDCTL4_SMP2:       equ    7                                         ; Sample Time Select 2
; bit position masks
mATDCTL4_PRS0:      equ    %00000001
mATDCTL4_PRS1:      equ    %00000010
mATDCTL4_PRS2:      equ    %00000100
mATDCTL4_PRS3:      equ    %00001000
mATDCTL4_PRS4:      equ    %00010000
mATDCTL4_SMP0:      equ    %00100000
mATDCTL4_SMP1:      equ    %01000000
mATDCTL4_SMP2:      equ    %10000000


;*** ATDCTL5 - ATD  Control Register 5; 0x00000075 ***
ATDCTL5:            equ    $00000075                                ;*** ATDCTL5 - ATD  Control Register 5; 0x00000075 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ATDCTL5_CA:         equ    0                                         ; Analog Input Channel Select Code A
ATDCTL5_CB:         equ    1                                         ; Analog Input Channel Select Code B
ATDCTL5_CC:         equ    2                                         ; Analog Input Channel Select Code C
ATDCTL5_CD:         equ    3                                         ; Analog Input Channel Select Code D
ATDCTL5_MULT:       equ    4                                         ; Multi-Channel Sample Mode
ATDCTL5_SCAN:       equ    5                                         ; Continuous Conversion Sequence Mode
ATDCTL5_SC:         equ    6                                         ; Special Channel Conversion Bit
; bit position masks
mATDCTL5_CA:        equ    %00000001
mATDCTL5_CB:        equ    %00000010
mATDCTL5_CC:        equ    %00000100
mATDCTL5_CD:        equ    %00001000
mATDCTL5_MULT:      equ    %00010000
mATDCTL5_SCAN:      equ    %00100000
mATDCTL5_SC:        equ    %01000000


;*** ATDSTAT0 - ATD  Status Register 0; 0x00000076 ***
ATDSTAT0:           equ    $00000076                                ;*** ATDSTAT0 - ATD  Status Register 0; 0x00000076 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ATDSTAT0_CC0:       equ    0                                         ; Conversion Counter 0
ATDSTAT0_CC1:       equ    1                                         ; Conversion Counter 1
ATDSTAT0_CC2:       equ    2                                         ; Conversion Counter 2
ATDSTAT0_CC3:       equ    3                                         ; Conversion Counter 3
ATDSTAT0_FIFOR:     equ    4                                         ; FIFO Over Run Flag
ATDSTAT0_ETORF:     equ    5                                         ; External Trigger Overrun Flag
ATDSTAT0_SCF:       equ    7                                         ; Sequence Complete Flag
; bit position masks
mATDSTAT0_CC0:      equ    %00000001
mATDSTAT0_CC1:      equ    %00000010
mATDSTAT0_CC2:      equ    %00000100
mATDSTAT0_CC3:      equ    %00001000
mATDSTAT0_FIFOR:    equ    %00010000
mATDSTAT0_ETORF:    equ    %00100000
mATDSTAT0_SCF:      equ    %10000000


;*** ATDCMPE - ATD  Compare Enable Register; 0x00000078 ***
ATDCMPE:            equ    $00000078                                ;*** ATDCMPE - ATD  Compare Enable Register; 0x00000078 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ATDCMPE_CMPE0:      equ    0                                         ; Compare Enable for Conversion Number 0 of a Sequence
ATDCMPE_CMPE1:      equ    1                                         ; Compare Enable for Conversion Number 1 of a Sequence
ATDCMPE_CMPE2:      equ    2                                         ; Compare Enable for Conversion Number 2 of a Sequence
ATDCMPE_CMPE3:      equ    3                                         ; Compare Enable for Conversion Number 3 of a Sequence
ATDCMPE_CMPE4:      equ    4                                         ; Compare Enable for Conversion Number 4 of a Sequence
ATDCMPE_CMPE5:      equ    5                                         ; Compare Enable for Conversion Number 5 of a Sequence
; bit position masks
mATDCMPE_CMPE0:     equ    %00000001
mATDCMPE_CMPE1:     equ    %00000010
mATDCMPE_CMPE2:     equ    %00000100
mATDCMPE_CMPE3:     equ    %00001000
mATDCMPE_CMPE4:     equ    %00010000
mATDCMPE_CMPE5:     equ    %00100000


;*** ATDCMPEH - ATD  Compare Enable Register High; 0x00000078 ***
ATDCMPEH:           equ    $00000078                                ;*** ATDCMPEH - ATD  Compare Enable Register High; 0x00000078 ***


;*** ATDCMPEL - ATD  Compare Enable Register Low; 0x00000079 ***
ATDCMPEL:           equ    $00000079                                ;*** ATDCMPEL - ATD  Compare Enable Register Low; 0x00000079 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ATDCMPEL_CMPE0:     equ    0                                         ; Compare Enable for Conversion Number 0 of a Sequence
ATDCMPEL_CMPE1:     equ    1                                         ; Compare Enable for Conversion Number 1 of a Sequence
ATDCMPEL_CMPE2:     equ    2                                         ; Compare Enable for Conversion Number 2 of a Sequence
ATDCMPEL_CMPE3:     equ    3                                         ; Compare Enable for Conversion Number 3 of a Sequence
ATDCMPEL_CMPE4:     equ    4                                         ; Compare Enable for Conversion Number 4 of a Sequence
ATDCMPEL_CMPE5:     equ    5                                         ; Compare Enable for Conversion Number 5 of a Sequence
; bit position masks
mATDCMPEL_CMPE0:    equ    %00000001
mATDCMPEL_CMPE1:    equ    %00000010
mATDCMPEL_CMPE2:    equ    %00000100
mATDCMPEL_CMPE3:    equ    %00001000
mATDCMPEL_CMPE4:    equ    %00010000
mATDCMPEL_CMPE5:    equ    %00100000


;*** ATDSTAT2 - ATD  Status Register 2; 0x0000007A ***
ATDSTAT2:           equ    $0000007A                                ;*** ATDSTAT2 - ATD  Status Register 2; 0x0000007A ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ATDSTAT2_CCF0:      equ    0                                         ; Conversion Complete Flag 0
ATDSTAT2_CCF1:      equ    1                                         ; Conversion Complete Flag 1
ATDSTAT2_CCF2:      equ    2                                         ; Conversion Complete Flag 2
ATDSTAT2_CCF3:      equ    3                                         ; Conversion Complete Flag 3
ATDSTAT2_CCF4:      equ    4                                         ; Conversion Complete Flag 4
ATDSTAT2_CCF5:      equ    5                                         ; Conversion Complete Flag 5
; bit position masks
mATDSTAT2_CCF0:     equ    %00000001
mATDSTAT2_CCF1:     equ    %00000010
mATDSTAT2_CCF2:     equ    %00000100
mATDSTAT2_CCF3:     equ    %00001000
mATDSTAT2_CCF4:     equ    %00010000
mATDSTAT2_CCF5:     equ    %00100000


;*** ATDSTAT2H - ATD  Status Register 2 High; 0x0000007A ***
ATDSTAT2H:          equ    $0000007A                                ;*** ATDSTAT2H - ATD  Status Register 2 High; 0x0000007A ***


;*** ATDSTAT2L - ATD  Status Register 2 Low; 0x0000007B ***
ATDSTAT2L:          equ    $0000007B                                ;*** ATDSTAT2L - ATD  Status Register 2 Low; 0x0000007B ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ATDSTAT2L_CCF0:     equ    0                                         ; Conversion Complete Flag 0
ATDSTAT2L_CCF1:     equ    1                                         ; Conversion Complete Flag 1
ATDSTAT2L_CCF2:     equ    2                                         ; Conversion Complete Flag 2
ATDSTAT2L_CCF3:     equ    3                                         ; Conversion Complete Flag 3
ATDSTAT2L_CCF4:     equ    4                                         ; Conversion Complete Flag 4
ATDSTAT2L_CCF5:     equ    5                                         ; Conversion Complete Flag 5
; bit position masks
mATDSTAT2L_CCF0:    equ    %00000001
mATDSTAT2L_CCF1:    equ    %00000010
mATDSTAT2L_CCF2:    equ    %00000100
mATDSTAT2L_CCF3:    equ    %00001000
mATDSTAT2L_CCF4:    equ    %00010000
mATDSTAT2L_CCF5:    equ    %00100000


;*** ATDDIEN - ATD  Input Enable Register; 0x0000007C ***
ATDDIEN:            equ    $0000007C                                ;*** ATDDIEN - ATD  Input Enable Register; 0x0000007C ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ATDDIEN_IEN0:       equ    0                                         ; ATD Digital Input Enable on channel 0
ATDDIEN_IEN1:       equ    1                                         ; ATD Digital Input Enable on channel 1
ATDDIEN_IEN2:       equ    2                                         ; ATD Digital Input Enable on channel 2
ATDDIEN_IEN3:       equ    3                                         ; ATD Digital Input Enable on channel 3
ATDDIEN_IEN4:       equ    4                                         ; ATD Digital Input Enable on channel 4
ATDDIEN_IEN5:       equ    5                                         ; ATD Digital Input Enable on channel 5
; bit position masks
mATDDIEN_IEN0:      equ    %00000001
mATDDIEN_IEN1:      equ    %00000010
mATDDIEN_IEN2:      equ    %00000100
mATDDIEN_IEN3:      equ    %00001000
mATDDIEN_IEN4:      equ    %00010000
mATDDIEN_IEN5:      equ    %00100000


;*** ATDDIENH - ATD  Input Enable Register High; 0x0000007C ***
ATDDIENH:           equ    $0000007C                                ;*** ATDDIENH - ATD  Input Enable Register High; 0x0000007C ***


;*** ATDDIENL - ATD  Input Enable Register Low; 0x0000007D ***
ATDDIENL:           equ    $0000007D                                ;*** ATDDIENL - ATD  Input Enable Register Low; 0x0000007D ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ATDDIENL_IEN0:      equ    0                                         ; ATD Digital Input Enable on channel 0
ATDDIENL_IEN1:      equ    1                                         ; ATD Digital Input Enable on channel 1
ATDDIENL_IEN2:      equ    2                                         ; ATD Digital Input Enable on channel 2
ATDDIENL_IEN3:      equ    3                                         ; ATD Digital Input Enable on channel 3
ATDDIENL_IEN4:      equ    4                                         ; ATD Digital Input Enable on channel 4
ATDDIENL_IEN5:      equ    5                                         ; ATD Digital Input Enable on channel 5
; bit position masks
mATDDIENL_IEN0:     equ    %00000001
mATDDIENL_IEN1:     equ    %00000010
mATDDIENL_IEN2:     equ    %00000100
mATDDIENL_IEN3:     equ    %00001000
mATDDIENL_IEN4:     equ    %00010000
mATDDIENL_IEN5:     equ    %00100000


;*** ATDCMPHT - ATD  Compare Higher Than Register; 0x0000007E ***
ATDCMPHT:           equ    $0000007E                                ;*** ATDCMPHT - ATD  Compare Higher Than Register; 0x0000007E ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ATDCMPHT_CMPHT0:    equ    0                                         ; Compare Operation Higher Than Enable for Conversion Number 0 of a Sequence
ATDCMPHT_CMPHT1:    equ    1                                         ; Compare Operation Higher Than Enable for Conversion Number 1 of a Sequence
ATDCMPHT_CMPHT2:    equ    2                                         ; Compare Operation Higher Than Enable for Conversion Number 2 of a Sequence
ATDCMPHT_CMPHT3:    equ    3                                         ; Compare Operation Higher Than Enable for Conversion Number 3 of a Sequence
ATDCMPHT_CMPHT4:    equ    4                                         ; Compare Operation Higher Than Enable for Conversion Number 4 of a Sequence
ATDCMPHT_CMPHT5:    equ    5                                         ; Compare Operation Higher Than Enable for Conversion Number 5 of a Sequence
; bit position masks
mATDCMPHT_CMPHT0:   equ    %00000001
mATDCMPHT_CMPHT1:   equ    %00000010
mATDCMPHT_CMPHT2:   equ    %00000100
mATDCMPHT_CMPHT3:   equ    %00001000
mATDCMPHT_CMPHT4:   equ    %00010000
mATDCMPHT_CMPHT5:   equ    %00100000


;*** ATDCMPHTH - ATD  Compare Higher Than Register High; 0x0000007E ***
ATDCMPHTH:          equ    $0000007E                                ;*** ATDCMPHTH - ATD  Compare Higher Than Register High; 0x0000007E ***


;*** ATDCMPHTL - ATD  Compare Higher Than Register Low; 0x0000007F ***
ATDCMPHTL:          equ    $0000007F                                ;*** ATDCMPHTL - ATD  Compare Higher Than Register Low; 0x0000007F ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ATDCMPHTL_CMPHT0:   equ    0                                         ; Compare Operation Higher Than Enable for Conversion Number 0 of a Sequence
ATDCMPHTL_CMPHT1:   equ    1                                         ; Compare Operation Higher Than Enable for Conversion Number 1 of a Sequence
ATDCMPHTL_CMPHT2:   equ    2                                         ; Compare Operation Higher Than Enable for Conversion Number 2 of a Sequence
ATDCMPHTL_CMPHT3:   equ    3                                         ; Compare Operation Higher Than Enable for Conversion Number 3 of a Sequence
ATDCMPHTL_CMPHT4:   equ    4                                         ; Compare Operation Higher Than Enable for Conversion Number 4 of a Sequence
ATDCMPHTL_CMPHT5:   equ    5                                         ; Compare Operation Higher Than Enable for Conversion Number 5 of a Sequence
; bit position masks
mATDCMPHTL_CMPHT0:  equ    %00000001
mATDCMPHTL_CMPHT1:  equ    %00000010
mATDCMPHTL_CMPHT2:  equ    %00000100
mATDCMPHTL_CMPHT3:  equ    %00001000
mATDCMPHTL_CMPHT4:  equ    %00010000
mATDCMPHTL_CMPHT5:  equ    %00100000


;*** ATDDR0 - ATD  Conversion Result Register 0; 0x00000080 ***
ATDDR0:             equ    $00000080                                ;*** ATDDR0 - ATD  Conversion Result Register 0; 0x00000080 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ATDDR0_BIT0:        equ    0                                         ; Bit 0
ATDDR0_BIT1:        equ    1                                         ; Bit 1
ATDDR0_BIT2:        equ    2                                         ; Bit 2
ATDDR0_BIT3:        equ    3                                         ; Bit 3
ATDDR0_BIT4:        equ    4                                         ; Bit 4
ATDDR0_BIT5:        equ    5                                         ; Bit 5
ATDDR0_BIT6:        equ    6                                         ; Bit 6
ATDDR0_BIT7:        equ    7                                         ; Bit 7
ATDDR0_BIT8:        equ    8                                         ; Bit 8
ATDDR0_BIT9:        equ    9                                         ; Bit 9
ATDDR0_BIT10:       equ    10                                        ; Bit 10
ATDDR0_BIT11:       equ    11                                        ; Bit 11
ATDDR0_BIT12:       equ    12                                        ; Bit 12
ATDDR0_BIT13:       equ    13                                        ; Bit 13
ATDDR0_BIT14:       equ    14                                        ; Bit 14
ATDDR0_BIT15:       equ    15                                        ; Bit 15
; bit position masks
mATDDR0_BIT0:       equ    %00000001
mATDDR0_BIT1:       equ    %00000010
mATDDR0_BIT2:       equ    %00000100
mATDDR0_BIT3:       equ    %00001000
mATDDR0_BIT4:       equ    %00010000
mATDDR0_BIT5:       equ    %00100000
mATDDR0_BIT6:       equ    %01000000
mATDDR0_BIT7:       equ    %10000000
mATDDR0_BIT8:       equ    %100000000
mATDDR0_BIT9:       equ    %1000000000
mATDDR0_BIT10:      equ    %10000000000
mATDDR0_BIT11:      equ    %100000000000
mATDDR0_BIT12:      equ    %1000000000000
mATDDR0_BIT13:      equ    %10000000000000
mATDDR0_BIT14:      equ    %100000000000000
mATDDR0_BIT15:      equ    %1000000000000000


;*** ATDDR0H - ATD  Conversion Result Register 0 High; 0x00000080 ***
ATDDR0H:            equ    $00000080                                ;*** ATDDR0H - ATD  Conversion Result Register 0 High; 0x00000080 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ATDDR0H_BIT8:       equ    0                                         ; Bit 8
ATDDR0H_BIT9:       equ    1                                         ; Bit 9
ATDDR0H_BIT10:      equ    2                                         ; Bit 10
ATDDR0H_BIT11:      equ    3                                         ; Bit 11
ATDDR0H_BIT12:      equ    4                                         ; Bit 12
ATDDR0H_BIT13:      equ    5                                         ; Bit 13
ATDDR0H_BIT14:      equ    6                                         ; Bit 14
ATDDR0H_BIT15:      equ    7                                         ; Bit 15
; bit position masks
mATDDR0H_BIT8:      equ    %00000001
mATDDR0H_BIT9:      equ    %00000010
mATDDR0H_BIT10:     equ    %00000100
mATDDR0H_BIT11:     equ    %00001000
mATDDR0H_BIT12:     equ    %00010000
mATDDR0H_BIT13:     equ    %00100000
mATDDR0H_BIT14:     equ    %01000000
mATDDR0H_BIT15:     equ    %10000000


;*** ATDDR0L - ATD  Conversion Result Register 0 Low; 0x00000081 ***
ATDDR0L:            equ    $00000081                                ;*** ATDDR0L - ATD  Conversion Result Register 0 Low; 0x00000081 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ATDDR0L_BIT0:       equ    0                                         ; Bit 0
ATDDR0L_BIT1:       equ    1                                         ; Bit 1
ATDDR0L_BIT2:       equ    2                                         ; Bit 2
ATDDR0L_BIT3:       equ    3                                         ; Bit 3
ATDDR0L_BIT4:       equ    4                                         ; Bit 4
ATDDR0L_BIT5:       equ    5                                         ; Bit 5
ATDDR0L_BIT6:       equ    6                                         ; Bit 6
ATDDR0L_BIT7:       equ    7                                         ; Bit 7
; bit position masks
mATDDR0L_BIT0:      equ    %00000001
mATDDR0L_BIT1:      equ    %00000010
mATDDR0L_BIT2:      equ    %00000100
mATDDR0L_BIT3:      equ    %00001000
mATDDR0L_BIT4:      equ    %00010000
mATDDR0L_BIT5:      equ    %00100000
mATDDR0L_BIT6:      equ    %01000000
mATDDR0L_BIT7:      equ    %10000000


;*** ATDDR1 - ATD  Conversion Result Register 1; 0x00000082 ***
ATDDR1:             equ    $00000082                                ;*** ATDDR1 - ATD  Conversion Result Register 1; 0x00000082 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ATDDR1_BIT0:        equ    0                                         ; Bit 0
ATDDR1_BIT1:        equ    1                                         ; Bit 1
ATDDR1_BIT2:        equ    2                                         ; Bit 2
ATDDR1_BIT3:        equ    3                                         ; Bit 3
ATDDR1_BIT4:        equ    4                                         ; Bit 4
ATDDR1_BIT5:        equ    5                                         ; Bit 5
ATDDR1_BIT6:        equ    6                                         ; Bit 6
ATDDR1_BIT7:        equ    7                                         ; Bit 7
ATDDR1_BIT8:        equ    8                                         ; Bit 8
ATDDR1_BIT9:        equ    9                                         ; Bit 9
ATDDR1_BIT10:       equ    10                                        ; Bit 10
ATDDR1_BIT11:       equ    11                                        ; Bit 11
ATDDR1_BIT12:       equ    12                                        ; Bit 12
ATDDR1_BIT13:       equ    13                                        ; Bit 13
ATDDR1_BIT14:       equ    14                                        ; Bit 14
ATDDR1_BIT15:       equ    15                                        ; Bit 15
; bit position masks
mATDDR1_BIT0:       equ    %00000001
mATDDR1_BIT1:       equ    %00000010
mATDDR1_BIT2:       equ    %00000100
mATDDR1_BIT3:       equ    %00001000
mATDDR1_BIT4:       equ    %00010000
mATDDR1_BIT5:       equ    %00100000
mATDDR1_BIT6:       equ    %01000000
mATDDR1_BIT7:       equ    %10000000
mATDDR1_BIT8:       equ    %100000000
mATDDR1_BIT9:       equ    %1000000000
mATDDR1_BIT10:      equ    %10000000000
mATDDR1_BIT11:      equ    %100000000000
mATDDR1_BIT12:      equ    %1000000000000
mATDDR1_BIT13:      equ    %10000000000000
mATDDR1_BIT14:      equ    %100000000000000
mATDDR1_BIT15:      equ    %1000000000000000


;*** ATDDR1H - ATD  Conversion Result Register 1 High; 0x00000082 ***
ATDDR1H:            equ    $00000082                                ;*** ATDDR1H - ATD  Conversion Result Register 1 High; 0x00000082 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ATDDR1H_BIT8:       equ    0                                         ; Bit 8
ATDDR1H_BIT9:       equ    1                                         ; Bit 9
ATDDR1H_BIT10:      equ    2                                         ; Bit 10
ATDDR1H_BIT11:      equ    3                                         ; Bit 11
ATDDR1H_BIT12:      equ    4                                         ; Bit 12
ATDDR1H_BIT13:      equ    5                                         ; Bit 13
ATDDR1H_BIT14:      equ    6                                         ; Bit 14
ATDDR1H_BIT15:      equ    7                                         ; Bit 15
; bit position masks
mATDDR1H_BIT8:      equ    %00000001
mATDDR1H_BIT9:      equ    %00000010
mATDDR1H_BIT10:     equ    %00000100
mATDDR1H_BIT11:     equ    %00001000
mATDDR1H_BIT12:     equ    %00010000
mATDDR1H_BIT13:     equ    %00100000
mATDDR1H_BIT14:     equ    %01000000
mATDDR1H_BIT15:     equ    %10000000


;*** ATDDR1L - ATD  Conversion Result Register 1 Low; 0x00000083 ***
ATDDR1L:            equ    $00000083                                ;*** ATDDR1L - ATD  Conversion Result Register 1 Low; 0x00000083 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ATDDR1L_BIT0:       equ    0                                         ; Bit 0
ATDDR1L_BIT1:       equ    1                                         ; Bit 1
ATDDR1L_BIT2:       equ    2                                         ; Bit 2
ATDDR1L_BIT3:       equ    3                                         ; Bit 3
ATDDR1L_BIT4:       equ    4                                         ; Bit 4
ATDDR1L_BIT5:       equ    5                                         ; Bit 5
ATDDR1L_BIT6:       equ    6                                         ; Bit 6
ATDDR1L_BIT7:       equ    7                                         ; Bit 7
; bit position masks
mATDDR1L_BIT0:      equ    %00000001
mATDDR1L_BIT1:      equ    %00000010
mATDDR1L_BIT2:      equ    %00000100
mATDDR1L_BIT3:      equ    %00001000
mATDDR1L_BIT4:      equ    %00010000
mATDDR1L_BIT5:      equ    %00100000
mATDDR1L_BIT6:      equ    %01000000
mATDDR1L_BIT7:      equ    %10000000


;*** ATDDR2 - ATD  Conversion Result Register 2; 0x00000084 ***
ATDDR2:             equ    $00000084                                ;*** ATDDR2 - ATD  Conversion Result Register 2; 0x00000084 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ATDDR2_BIT0:        equ    0                                         ; Bit 0
ATDDR2_BIT1:        equ    1                                         ; Bit 1
ATDDR2_BIT2:        equ    2                                         ; Bit 2
ATDDR2_BIT3:        equ    3                                         ; Bit 3
ATDDR2_BIT4:        equ    4                                         ; Bit 4
ATDDR2_BIT5:        equ    5                                         ; Bit 5
ATDDR2_BIT6:        equ    6                                         ; Bit 6
ATDDR2_BIT7:        equ    7                                         ; Bit 7
ATDDR2_BIT8:        equ    8                                         ; Bit 8
ATDDR2_BIT9:        equ    9                                         ; Bit 9
ATDDR2_BIT10:       equ    10                                        ; Bit 10
ATDDR2_BIT11:       equ    11                                        ; Bit 11
ATDDR2_BIT12:       equ    12                                        ; Bit 12
ATDDR2_BIT13:       equ    13                                        ; Bit 13
ATDDR2_BIT14:       equ    14                                        ; Bit 14
ATDDR2_BIT15:       equ    15                                        ; Bit 15
; bit position masks
mATDDR2_BIT0:       equ    %00000001
mATDDR2_BIT1:       equ    %00000010
mATDDR2_BIT2:       equ    %00000100
mATDDR2_BIT3:       equ    %00001000
mATDDR2_BIT4:       equ    %00010000
mATDDR2_BIT5:       equ    %00100000
mATDDR2_BIT6:       equ    %01000000
mATDDR2_BIT7:       equ    %10000000
mATDDR2_BIT8:       equ    %100000000
mATDDR2_BIT9:       equ    %1000000000
mATDDR2_BIT10:      equ    %10000000000
mATDDR2_BIT11:      equ    %100000000000
mATDDR2_BIT12:      equ    %1000000000000
mATDDR2_BIT13:      equ    %10000000000000
mATDDR2_BIT14:      equ    %100000000000000
mATDDR2_BIT15:      equ    %1000000000000000


;*** ATDDR2H - ATD  Conversion Result Register 2 High; 0x00000084 ***
ATDDR2H:            equ    $00000084                                ;*** ATDDR2H - ATD  Conversion Result Register 2 High; 0x00000084 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ATDDR2H_BIT8:       equ    0                                         ; Bit 8
ATDDR2H_BIT9:       equ    1                                         ; Bit 9
ATDDR2H_BIT10:      equ    2                                         ; Bit 10
ATDDR2H_BIT11:      equ    3                                         ; Bit 11
ATDDR2H_BIT12:      equ    4                                         ; Bit 12
ATDDR2H_BIT13:      equ    5                                         ; Bit 13
ATDDR2H_BIT14:      equ    6                                         ; Bit 14
ATDDR2H_BIT15:      equ    7                                         ; Bit 15
; bit position masks
mATDDR2H_BIT8:      equ    %00000001
mATDDR2H_BIT9:      equ    %00000010
mATDDR2H_BIT10:     equ    %00000100
mATDDR2H_BIT11:     equ    %00001000
mATDDR2H_BIT12:     equ    %00010000
mATDDR2H_BIT13:     equ    %00100000
mATDDR2H_BIT14:     equ    %01000000
mATDDR2H_BIT15:     equ    %10000000


;*** ATDDR2L - ATD  Conversion Result Register 2 Low; 0x00000085 ***
ATDDR2L:            equ    $00000085                                ;*** ATDDR2L - ATD  Conversion Result Register 2 Low; 0x00000085 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ATDDR2L_BIT0:       equ    0                                         ; Bit 0
ATDDR2L_BIT1:       equ    1                                         ; Bit 1
ATDDR2L_BIT2:       equ    2                                         ; Bit 2
ATDDR2L_BIT3:       equ    3                                         ; Bit 3
ATDDR2L_BIT4:       equ    4                                         ; Bit 4
ATDDR2L_BIT5:       equ    5                                         ; Bit 5
ATDDR2L_BIT6:       equ    6                                         ; Bit 6
ATDDR2L_BIT7:       equ    7                                         ; Bit 7
; bit position masks
mATDDR2L_BIT0:      equ    %00000001
mATDDR2L_BIT1:      equ    %00000010
mATDDR2L_BIT2:      equ    %00000100
mATDDR2L_BIT3:      equ    %00001000
mATDDR2L_BIT4:      equ    %00010000
mATDDR2L_BIT5:      equ    %00100000
mATDDR2L_BIT6:      equ    %01000000
mATDDR2L_BIT7:      equ    %10000000


;*** ATDDR3 - ATD  Conversion Result Register 3; 0x00000086 ***
ATDDR3:             equ    $00000086                                ;*** ATDDR3 - ATD  Conversion Result Register 3; 0x00000086 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ATDDR3_BIT0:        equ    0                                         ; Bit 0
ATDDR3_BIT1:        equ    1                                         ; Bit 1
ATDDR3_BIT2:        equ    2                                         ; Bit 2
ATDDR3_BIT3:        equ    3                                         ; Bit 3
ATDDR3_BIT4:        equ    4                                         ; Bit 4
ATDDR3_BIT5:        equ    5                                         ; Bit 5
ATDDR3_BIT6:        equ    6                                         ; Bit 6
ATDDR3_BIT7:        equ    7                                         ; Bit 7
ATDDR3_BIT8:        equ    8                                         ; Bit 8
ATDDR3_BIT9:        equ    9                                         ; Bit 9
ATDDR3_BIT10:       equ    10                                        ; Bit 10
ATDDR3_BIT11:       equ    11                                        ; Bit 11
ATDDR3_BIT12:       equ    12                                        ; Bit 12
ATDDR3_BIT13:       equ    13                                        ; Bit 13
ATDDR3_BIT14:       equ    14                                        ; Bit 14
ATDDR3_BIT15:       equ    15                                        ; Bit 15
; bit position masks
mATDDR3_BIT0:       equ    %00000001
mATDDR3_BIT1:       equ    %00000010
mATDDR3_BIT2:       equ    %00000100
mATDDR3_BIT3:       equ    %00001000
mATDDR3_BIT4:       equ    %00010000
mATDDR3_BIT5:       equ    %00100000
mATDDR3_BIT6:       equ    %01000000
mATDDR3_BIT7:       equ    %10000000
mATDDR3_BIT8:       equ    %100000000
mATDDR3_BIT9:       equ    %1000000000
mATDDR3_BIT10:      equ    %10000000000
mATDDR3_BIT11:      equ    %100000000000
mATDDR3_BIT12:      equ    %1000000000000
mATDDR3_BIT13:      equ    %10000000000000
mATDDR3_BIT14:      equ    %100000000000000
mATDDR3_BIT15:      equ    %1000000000000000


;*** ATDDR3H - ATD  Conversion Result Register 3 High; 0x00000086 ***
ATDDR3H:            equ    $00000086                                ;*** ATDDR3H - ATD  Conversion Result Register 3 High; 0x00000086 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ATDDR3H_BIT8:       equ    0                                         ; Bit 8
ATDDR3H_BIT9:       equ    1                                         ; Bit 9
ATDDR3H_BIT10:      equ    2                                         ; Bit 10
ATDDR3H_BIT11:      equ    3                                         ; Bit 11
ATDDR3H_BIT12:      equ    4                                         ; Bit 12
ATDDR3H_BIT13:      equ    5                                         ; Bit 13
ATDDR3H_BIT14:      equ    6                                         ; Bit 14
ATDDR3H_BIT15:      equ    7                                         ; Bit 15
; bit position masks
mATDDR3H_BIT8:      equ    %00000001
mATDDR3H_BIT9:      equ    %00000010
mATDDR3H_BIT10:     equ    %00000100
mATDDR3H_BIT11:     equ    %00001000
mATDDR3H_BIT12:     equ    %00010000
mATDDR3H_BIT13:     equ    %00100000
mATDDR3H_BIT14:     equ    %01000000
mATDDR3H_BIT15:     equ    %10000000


;*** ATDDR3L - ATD  Conversion Result Register 3 Low; 0x00000087 ***
ATDDR3L:            equ    $00000087                                ;*** ATDDR3L - ATD  Conversion Result Register 3 Low; 0x00000087 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ATDDR3L_BIT0:       equ    0                                         ; Bit 0
ATDDR3L_BIT1:       equ    1                                         ; Bit 1
ATDDR3L_BIT2:       equ    2                                         ; Bit 2
ATDDR3L_BIT3:       equ    3                                         ; Bit 3
ATDDR3L_BIT4:       equ    4                                         ; Bit 4
ATDDR3L_BIT5:       equ    5                                         ; Bit 5
ATDDR3L_BIT6:       equ    6                                         ; Bit 6
ATDDR3L_BIT7:       equ    7                                         ; Bit 7
; bit position masks
mATDDR3L_BIT0:      equ    %00000001
mATDDR3L_BIT1:      equ    %00000010
mATDDR3L_BIT2:      equ    %00000100
mATDDR3L_BIT3:      equ    %00001000
mATDDR3L_BIT4:      equ    %00010000
mATDDR3L_BIT5:      equ    %00100000
mATDDR3L_BIT6:      equ    %01000000
mATDDR3L_BIT7:      equ    %10000000


;*** ATDDR4 - ATD  Conversion Result Register 4; 0x00000088 ***
ATDDR4:             equ    $00000088                                ;*** ATDDR4 - ATD  Conversion Result Register 4; 0x00000088 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ATDDR4_BIT0:        equ    0                                         ; Bit 0
ATDDR4_BIT1:        equ    1                                         ; Bit 1
ATDDR4_BIT2:        equ    2                                         ; Bit 2
ATDDR4_BIT3:        equ    3                                         ; Bit 3
ATDDR4_BIT4:        equ    4                                         ; Bit 4
ATDDR4_BIT5:        equ    5                                         ; Bit 5
ATDDR4_BIT6:        equ    6                                         ; Bit 6
ATDDR4_BIT7:        equ    7                                         ; Bit 7
ATDDR4_BIT8:        equ    8                                         ; Bit 8
ATDDR4_BIT9:        equ    9                                         ; Bit 9
ATDDR4_BIT10:       equ    10                                        ; Bit 10
ATDDR4_BIT11:       equ    11                                        ; Bit 11
ATDDR4_BIT12:       equ    12                                        ; Bit 12
ATDDR4_BIT13:       equ    13                                        ; Bit 13
ATDDR4_BIT14:       equ    14                                        ; Bit 14
ATDDR4_BIT15:       equ    15                                        ; Bit 15
; bit position masks
mATDDR4_BIT0:       equ    %00000001
mATDDR4_BIT1:       equ    %00000010
mATDDR4_BIT2:       equ    %00000100
mATDDR4_BIT3:       equ    %00001000
mATDDR4_BIT4:       equ    %00010000
mATDDR4_BIT5:       equ    %00100000
mATDDR4_BIT6:       equ    %01000000
mATDDR4_BIT7:       equ    %10000000
mATDDR4_BIT8:       equ    %100000000
mATDDR4_BIT9:       equ    %1000000000
mATDDR4_BIT10:      equ    %10000000000
mATDDR4_BIT11:      equ    %100000000000
mATDDR4_BIT12:      equ    %1000000000000
mATDDR4_BIT13:      equ    %10000000000000
mATDDR4_BIT14:      equ    %100000000000000
mATDDR4_BIT15:      equ    %1000000000000000


;*** ATDDR4H - ATD  Conversion Result Register 4 High; 0x00000088 ***
ATDDR4H:            equ    $00000088                                ;*** ATDDR4H - ATD  Conversion Result Register 4 High; 0x00000088 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ATDDR4H_BIT8:       equ    0                                         ; Bit 8
ATDDR4H_BIT9:       equ    1                                         ; Bit 9
ATDDR4H_BIT10:      equ    2                                         ; Bit 10
ATDDR4H_BIT11:      equ    3                                         ; Bit 11
ATDDR4H_BIT12:      equ    4                                         ; Bit 12
ATDDR4H_BIT13:      equ    5                                         ; Bit 13
ATDDR4H_BIT14:      equ    6                                         ; Bit 14
ATDDR4H_BIT15:      equ    7                                         ; Bit 15
; bit position masks
mATDDR4H_BIT8:      equ    %00000001
mATDDR4H_BIT9:      equ    %00000010
mATDDR4H_BIT10:     equ    %00000100
mATDDR4H_BIT11:     equ    %00001000
mATDDR4H_BIT12:     equ    %00010000
mATDDR4H_BIT13:     equ    %00100000
mATDDR4H_BIT14:     equ    %01000000
mATDDR4H_BIT15:     equ    %10000000


;*** ATDDR4L - ATD  Conversion Result Register 4 Low; 0x00000089 ***
ATDDR4L:            equ    $00000089                                ;*** ATDDR4L - ATD  Conversion Result Register 4 Low; 0x00000089 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ATDDR4L_BIT0:       equ    0                                         ; Bit 0
ATDDR4L_BIT1:       equ    1                                         ; Bit 1
ATDDR4L_BIT2:       equ    2                                         ; Bit 2
ATDDR4L_BIT3:       equ    3                                         ; Bit 3
ATDDR4L_BIT4:       equ    4                                         ; Bit 4
ATDDR4L_BIT5:       equ    5                                         ; Bit 5
ATDDR4L_BIT6:       equ    6                                         ; Bit 6
ATDDR4L_BIT7:       equ    7                                         ; Bit 7
; bit position masks
mATDDR4L_BIT0:      equ    %00000001
mATDDR4L_BIT1:      equ    %00000010
mATDDR4L_BIT2:      equ    %00000100
mATDDR4L_BIT3:      equ    %00001000
mATDDR4L_BIT4:      equ    %00010000
mATDDR4L_BIT5:      equ    %00100000
mATDDR4L_BIT6:      equ    %01000000
mATDDR4L_BIT7:      equ    %10000000


;*** ATDDR5 - ATD  Conversion Result Register 5; 0x0000008A ***
ATDDR5:             equ    $0000008A                                ;*** ATDDR5 - ATD  Conversion Result Register 5; 0x0000008A ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ATDDR5_BIT0:        equ    0                                         ; Bit 0
ATDDR5_BIT1:        equ    1                                         ; Bit 1
ATDDR5_BIT2:        equ    2                                         ; Bit 2
ATDDR5_BIT3:        equ    3                                         ; Bit 3
ATDDR5_BIT4:        equ    4                                         ; Bit 4
ATDDR5_BIT5:        equ    5                                         ; Bit 5
ATDDR5_BIT6:        equ    6                                         ; Bit 6
ATDDR5_BIT7:        equ    7                                         ; Bit 7
ATDDR5_BIT8:        equ    8                                         ; Bit 8
ATDDR5_BIT9:        equ    9                                         ; Bit 9
ATDDR5_BIT10:       equ    10                                        ; Bit 10
ATDDR5_BIT11:       equ    11                                        ; Bit 11
ATDDR5_BIT12:       equ    12                                        ; Bit 12
ATDDR5_BIT13:       equ    13                                        ; Bit 13
ATDDR5_BIT14:       equ    14                                        ; Bit 14
ATDDR5_BIT15:       equ    15                                        ; Bit 15
; bit position masks
mATDDR5_BIT0:       equ    %00000001
mATDDR5_BIT1:       equ    %00000010
mATDDR5_BIT2:       equ    %00000100
mATDDR5_BIT3:       equ    %00001000
mATDDR5_BIT4:       equ    %00010000
mATDDR5_BIT5:       equ    %00100000
mATDDR5_BIT6:       equ    %01000000
mATDDR5_BIT7:       equ    %10000000
mATDDR5_BIT8:       equ    %100000000
mATDDR5_BIT9:       equ    %1000000000
mATDDR5_BIT10:      equ    %10000000000
mATDDR5_BIT11:      equ    %100000000000
mATDDR5_BIT12:      equ    %1000000000000
mATDDR5_BIT13:      equ    %10000000000000
mATDDR5_BIT14:      equ    %100000000000000
mATDDR5_BIT15:      equ    %1000000000000000


;*** ATDDR5H - ATD  Conversion Result Register 5 High; 0x0000008A ***
ATDDR5H:            equ    $0000008A                                ;*** ATDDR5H - ATD  Conversion Result Register 5 High; 0x0000008A ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ATDDR5H_BIT8:       equ    0                                         ; Bit 8
ATDDR5H_BIT9:       equ    1                                         ; Bit 9
ATDDR5H_BIT10:      equ    2                                         ; Bit 10
ATDDR5H_BIT11:      equ    3                                         ; Bit 11
ATDDR5H_BIT12:      equ    4                                         ; Bit 12
ATDDR5H_BIT13:      equ    5                                         ; Bit 13
ATDDR5H_BIT14:      equ    6                                         ; Bit 14
ATDDR5H_BIT15:      equ    7                                         ; Bit 15
; bit position masks
mATDDR5H_BIT8:      equ    %00000001
mATDDR5H_BIT9:      equ    %00000010
mATDDR5H_BIT10:     equ    %00000100
mATDDR5H_BIT11:     equ    %00001000
mATDDR5H_BIT12:     equ    %00010000
mATDDR5H_BIT13:     equ    %00100000
mATDDR5H_BIT14:     equ    %01000000
mATDDR5H_BIT15:     equ    %10000000


;*** ATDDR5L - ATD  Conversion Result Register 5 Low; 0x0000008B ***
ATDDR5L:            equ    $0000008B                                ;*** ATDDR5L - ATD  Conversion Result Register 5 Low; 0x0000008B ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ATDDR5L_BIT0:       equ    0                                         ; Bit 0
ATDDR5L_BIT1:       equ    1                                         ; Bit 1
ATDDR5L_BIT2:       equ    2                                         ; Bit 2
ATDDR5L_BIT3:       equ    3                                         ; Bit 3
ATDDR5L_BIT4:       equ    4                                         ; Bit 4
ATDDR5L_BIT5:       equ    5                                         ; Bit 5
ATDDR5L_BIT6:       equ    6                                         ; Bit 6
ATDDR5L_BIT7:       equ    7                                         ; Bit 7
; bit position masks
mATDDR5L_BIT0:      equ    %00000001
mATDDR5L_BIT1:      equ    %00000010
mATDDR5L_BIT2:      equ    %00000100
mATDDR5L_BIT3:      equ    %00001000
mATDDR5L_BIT4:      equ    %00010000
mATDDR5L_BIT5:      equ    %00100000
mATDDR5L_BIT6:      equ    %01000000
mATDDR5L_BIT7:      equ    %10000000


;*** PWME - PWM Enable Register; 0x000000A0 ***
PWME:               equ    $000000A0                                ;*** PWME - PWM Enable Register; 0x000000A0 ***
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


;*** PWMPOL - PWM Polarity Register; 0x000000A1 ***
PWMPOL:             equ    $000000A1                                ;*** PWMPOL - PWM Polarity Register; 0x000000A1 ***
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


;*** PWMCLK - PWM Clock Select Register; 0x000000A2 ***
PWMCLK:             equ    $000000A2                                ;*** PWMCLK - PWM Clock Select Register; 0x000000A2 ***
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


;*** PWMPRCLK - PWM Prescale Clock Select Register; 0x000000A3 ***
PWMPRCLK:           equ    $000000A3                                ;*** PWMPRCLK - PWM Prescale Clock Select Register; 0x000000A3 ***
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


;*** PWMCAE - PWM Center Align Enable Register; 0x000000A4 ***
PWMCAE:             equ    $000000A4                                ;*** PWMCAE - PWM Center Align Enable Register; 0x000000A4 ***
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


;*** PWMCTL - PWM Control Register; 0x000000A5 ***
PWMCTL:             equ    $000000A5                                ;*** PWMCTL - PWM Control Register; 0x000000A5 ***
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


;*** PWMCLKAB - PWM Clock Select Register; 0x000000A6 ***
PWMCLKAB:           equ    $000000A6                                ;*** PWMCLKAB - PWM Clock Select Register; 0x000000A6 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PWMCLKAB_PCLKAB0:   equ    0                                         ; Pulse Width Channel 0 Clock A/B Select
PWMCLKAB_PCLKAB1:   equ    1                                         ; Pulse Width Channel 1 Clock A/B Select
PWMCLKAB_PCLKAB2:   equ    2                                         ; Pulse Width Channel 2 Clock A/B Select
PWMCLKAB_PCLKAB3:   equ    3                                         ; Pulse Width Channel 3 Clock A/B Select
PWMCLKAB_PCLKAB4:   equ    4                                         ; Pulse Width Channel 4 Clock A/B Select
PWMCLKAB_PCLKAB5:   equ    5                                         ; Pulse Width Channel 5 Clock A/B Select
PWMCLKAB_PCLKAB6:   equ    6                                         ; Pulse Width Channel 6 Clock A/B Select
PWMCLKAB_PCLKAB7:   equ    7                                         ; Pulse Width Channel 7 Clock A/B Select
; bit position masks
mPWMCLKAB_PCLKAB0:  equ    %00000001
mPWMCLKAB_PCLKAB1:  equ    %00000010
mPWMCLKAB_PCLKAB2:  equ    %00000100
mPWMCLKAB_PCLKAB3:  equ    %00001000
mPWMCLKAB_PCLKAB4:  equ    %00010000
mPWMCLKAB_PCLKAB5:  equ    %00100000
mPWMCLKAB_PCLKAB6:  equ    %01000000
mPWMCLKAB_PCLKAB7:  equ    %10000000


;*** PWMSCLA - PWM Scale A Register; 0x000000A8 ***
PWMSCLA:            equ    $000000A8                                ;*** PWMSCLA - PWM Scale A Register; 0x000000A8 ***
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


;*** PWMSCLB - PWM Scale B Register; 0x000000A9 ***
PWMSCLB:            equ    $000000A9                                ;*** PWMSCLB - PWM Scale B Register; 0x000000A9 ***
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


;*** PWMCNT01 - PWM Channel Counter 01 Register; 0x000000AC ***
PWMCNT01:           equ    $000000AC                                ;*** PWMCNT01 - PWM Channel Counter 01 Register; 0x000000AC ***


;*** PWMCNT0 - PWM Channel Counter 0 Register; 0x000000AC ***
PWMCNT0:            equ    $000000AC                                ;*** PWMCNT0 - PWM Channel Counter 0 Register; 0x000000AC ***


;*** PWMCNT1 - PWM Channel Counter 1 Register; 0x000000AD ***
PWMCNT1:            equ    $000000AD                                ;*** PWMCNT1 - PWM Channel Counter 1 Register; 0x000000AD ***


;*** PWMCNT23 - PWM Channel Counter 23 Register; 0x000000AE ***
PWMCNT23:           equ    $000000AE                                ;*** PWMCNT23 - PWM Channel Counter 23 Register; 0x000000AE ***


;*** PWMCNT2 - PWM Channel Counter 2 Register; 0x000000AE ***
PWMCNT2:            equ    $000000AE                                ;*** PWMCNT2 - PWM Channel Counter 2 Register; 0x000000AE ***


;*** PWMCNT3 - PWM Channel Counter 3 Register; 0x000000AF ***
PWMCNT3:            equ    $000000AF                                ;*** PWMCNT3 - PWM Channel Counter 3 Register; 0x000000AF ***


;*** PWMCNT45 - PWM Channel Counter 45 Register; 0x000000B0 ***
PWMCNT45:           equ    $000000B0                                ;*** PWMCNT45 - PWM Channel Counter 45 Register; 0x000000B0 ***


;*** PWMCNT4 - PWM Channel Counter 4 Register; 0x000000B0 ***
PWMCNT4:            equ    $000000B0                                ;*** PWMCNT4 - PWM Channel Counter 4 Register; 0x000000B0 ***


;*** PWMCNT5 - PWM Channel Counter 5 Register; 0x000000B1 ***
PWMCNT5:            equ    $000000B1                                ;*** PWMCNT5 - PWM Channel Counter 5 Register; 0x000000B1 ***


;*** PWMCNT67 - PWM Channel Counter 67 Register; 0x000000B2 ***
PWMCNT67:           equ    $000000B2                                ;*** PWMCNT67 - PWM Channel Counter 67 Register; 0x000000B2 ***


;*** PWMCNT6 - PWM Channel Counter 6 Register; 0x000000B2 ***
PWMCNT6:            equ    $000000B2                                ;*** PWMCNT6 - PWM Channel Counter 6 Register; 0x000000B2 ***


;*** PWMCNT7 - PWM Channel Counter 7 Register; 0x000000B3 ***
PWMCNT7:            equ    $000000B3                                ;*** PWMCNT7 - PWM Channel Counter 7 Register; 0x000000B3 ***


;*** PWMPER01 - PWM Channel Period 01 Register; 0x000000B4 ***
PWMPER01:           equ    $000000B4                                ;*** PWMPER01 - PWM Channel Period 01 Register; 0x000000B4 ***


;*** PWMPER0 - PWM Channel Period 0 Register; 0x000000B4 ***
PWMPER0:            equ    $000000B4                                ;*** PWMPER0 - PWM Channel Period 0 Register; 0x000000B4 ***


;*** PWMPER1 - PWM Channel Period 1 Register; 0x000000B5 ***
PWMPER1:            equ    $000000B5                                ;*** PWMPER1 - PWM Channel Period 1 Register; 0x000000B5 ***


;*** PWMPER23 - PWM Channel Period 23 Register; 0x000000B6 ***
PWMPER23:           equ    $000000B6                                ;*** PWMPER23 - PWM Channel Period 23 Register; 0x000000B6 ***


;*** PWMPER2 - PWM Channel Period 2 Register; 0x000000B6 ***
PWMPER2:            equ    $000000B6                                ;*** PWMPER2 - PWM Channel Period 2 Register; 0x000000B6 ***


;*** PWMPER3 - PWM Channel Period 3 Register; 0x000000B7 ***
PWMPER3:            equ    $000000B7                                ;*** PWMPER3 - PWM Channel Period 3 Register; 0x000000B7 ***


;*** PWMPER45 - PWM Channel Period 45 Register; 0x000000B8 ***
PWMPER45:           equ    $000000B8                                ;*** PWMPER45 - PWM Channel Period 45 Register; 0x000000B8 ***


;*** PWMPER4 - PWM Channel Period 4 Register; 0x000000B8 ***
PWMPER4:            equ    $000000B8                                ;*** PWMPER4 - PWM Channel Period 4 Register; 0x000000B8 ***


;*** PWMPER5 - PWM Channel Period 5 Register; 0x000000B9 ***
PWMPER5:            equ    $000000B9                                ;*** PWMPER5 - PWM Channel Period 5 Register; 0x000000B9 ***


;*** PWMPER67 - PWM Channel Period 67 Register; 0x000000BA ***
PWMPER67:           equ    $000000BA                                ;*** PWMPER67 - PWM Channel Period 67 Register; 0x000000BA ***


;*** PWMPER6 - PWM Channel Period 6 Register; 0x000000BA ***
PWMPER6:            equ    $000000BA                                ;*** PWMPER6 - PWM Channel Period 6 Register; 0x000000BA ***


;*** PWMPER7 - PWM Channel Period 7 Register; 0x000000BB ***
PWMPER7:            equ    $000000BB                                ;*** PWMPER7 - PWM Channel Period 7 Register; 0x000000BB ***


;*** PWMDTY01 - PWM Channel Duty 01 Register; 0x000000BC ***
PWMDTY01:           equ    $000000BC                                ;*** PWMDTY01 - PWM Channel Duty 01 Register; 0x000000BC ***


;*** PWMDTY0 - PWM Channel Duty 0 Register; 0x000000BC ***
PWMDTY0:            equ    $000000BC                                ;*** PWMDTY0 - PWM Channel Duty 0 Register; 0x000000BC ***


;*** PWMDTY1 - PWM Channel Duty 1 Register; 0x000000BD ***
PWMDTY1:            equ    $000000BD                                ;*** PWMDTY1 - PWM Channel Duty 1 Register; 0x000000BD ***


;*** PWMDTY23 - PWM Channel Duty 23 Register; 0x000000BE ***
PWMDTY23:           equ    $000000BE                                ;*** PWMDTY23 - PWM Channel Duty 23 Register; 0x000000BE ***


;*** PWMDTY2 - PWM Channel Duty 2 Register; 0x000000BE ***
PWMDTY2:            equ    $000000BE                                ;*** PWMDTY2 - PWM Channel Duty 2 Register; 0x000000BE ***


;*** PWMDTY3 - PWM Channel Duty 3 Register; 0x000000BF ***
PWMDTY3:            equ    $000000BF                                ;*** PWMDTY3 - PWM Channel Duty 3 Register; 0x000000BF ***


;*** PWMDTY45 - PWM Channel Duty 45 Register; 0x000000C0 ***
PWMDTY45:           equ    $000000C0                                ;*** PWMDTY45 - PWM Channel Duty 45 Register; 0x000000C0 ***


;*** PWMDTY4 - PWM Channel Duty 4 Register; 0x000000C0 ***
PWMDTY4:            equ    $000000C0                                ;*** PWMDTY4 - PWM Channel Duty 4 Register; 0x000000C0 ***


;*** PWMDTY5 - PWM Channel Duty 5 Register; 0x000000C1 ***
PWMDTY5:            equ    $000000C1                                ;*** PWMDTY5 - PWM Channel Duty 5 Register; 0x000000C1 ***


;*** PWMDTY67 - PWM Channel Duty 67 Register; 0x000000C2 ***
PWMDTY67:           equ    $000000C2                                ;*** PWMDTY67 - PWM Channel Duty 67 Register; 0x000000C2 ***


;*** PWMDTY6 - PWM Channel Duty 6 Register; 0x000000C2 ***
PWMDTY6:            equ    $000000C2                                ;*** PWMDTY6 - PWM Channel Duty 6 Register; 0x000000C2 ***


;*** PWMDTY7 - PWM Channel Duty 7 Register; 0x000000C3 ***
PWMDTY7:            equ    $000000C3                                ;*** PWMDTY7 - PWM Channel Duty 7 Register; 0x000000C3 ***


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
SCI0BD_SBR13:       equ    13                                        ; SCI Baud Rate Bit 13
SCI0BD_SBR14:       equ    14                                        ; SCI Baud Rate Bit 14
SCI0BD_SBR15:       equ    15                                        ; SCI Baud Rate Bit 15
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
mSCI0BD_SBR13:      equ    %10000000000000
mSCI0BD_SBR14:      equ    %100000000000000
mSCI0BD_SBR15:      equ    %1000000000000000


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
SCI0BDH_SBR13:      equ    5                                         ; SCI Baud Rate Bit 13
SCI0BDH_SBR14:      equ    6                                         ; SCI Baud Rate Bit 14
SCI0BDH_SBR15:      equ    7                                         ; SCI Baud Rate Bit 15
; bit position masks
mSCI0BDH_SBR8:      equ    %00000001
mSCI0BDH_SBR9:      equ    %00000010
mSCI0BDH_SBR10:     equ    %00000100
mSCI0BDH_SBR11:     equ    %00001000
mSCI0BDH_SBR12:     equ    %00010000
mSCI0BDH_SBR13:     equ    %00100000
mSCI0BDH_SBR14:     equ    %01000000
mSCI0BDH_SBR15:     equ    %10000000


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
SCI0ACR2_TNP0:      equ    5                                         ; Transmitter Narrow Pulse Bit 0
SCI0ACR2_TNP1:      equ    6                                         ; Transmitter Narrow Pulse Bit 1
SCI0ACR2_IREN:      equ    7                                         ; Infrared Enable Bit
; bit position masks
mSCI0ACR2_BKDFE:    equ    %00000001
mSCI0ACR2_BERRM0:   equ    %00000010
mSCI0ACR2_BERRM1:   equ    %00000100
mSCI0ACR2_TNP0:     equ    %00100000
mSCI0ACR2_TNP1:     equ    %01000000
mSCI0ACR2_IREN:     equ    %10000000


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
SCI1BD_SBR13:       equ    13                                        ; SCI Baud Rate Bit 13
SCI1BD_SBR14:       equ    14                                        ; SCI Baud Rate Bit 14
SCI1BD_SBR15:       equ    15                                        ; SCI Baud Rate Bit 15
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
mSCI1BD_SBR13:      equ    %10000000000000
mSCI1BD_SBR14:      equ    %100000000000000
mSCI1BD_SBR15:      equ    %1000000000000000


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
SCI1BDH_SBR13:      equ    5                                         ; SCI Baud Rate Bit 13
SCI1BDH_SBR14:      equ    6                                         ; SCI Baud Rate Bit 14
SCI1BDH_SBR15:      equ    7                                         ; SCI Baud Rate Bit 15
; bit position masks
mSCI1BDH_SBR8:      equ    %00000001
mSCI1BDH_SBR9:      equ    %00000010
mSCI1BDH_SBR10:     equ    %00000100
mSCI1BDH_SBR11:     equ    %00001000
mSCI1BDH_SBR12:     equ    %00010000
mSCI1BDH_SBR13:     equ    %00100000
mSCI1BDH_SBR14:     equ    %01000000
mSCI1BDH_SBR15:     equ    %10000000


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
SCI1ACR2_TNP0:      equ    5                                         ; Transmitter Narrow Pulse Bit 0
SCI1ACR2_TNP1:      equ    6                                         ; Transmitter Narrow Pulse Bit 1
SCI1ACR2_IREN:      equ    7                                         ; Infrared Enable Bit
; bit position masks
mSCI1ACR2_BKDFE:    equ    %00000001
mSCI1ACR2_BERRM0:   equ    %00000010
mSCI1ACR2_BERRM1:   equ    %00000100
mSCI1ACR2_TNP0:     equ    %00100000
mSCI1ACR2_TNP1:     equ    %01000000
mSCI1ACR2_IREN:     equ    %10000000


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


;*** SPICR1 - SPI  Control Register 1; 0x000000D8 ***
SPICR1:             equ    $000000D8                                ;*** SPICR1 - SPI  Control Register 1; 0x000000D8 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPICR1_LSBFE:       equ    0                                         ; SPI LSB-First Enable
SPICR1_SSOE:        equ    1                                         ; Slave Select Output Enable
SPICR1_CPHA:        equ    2                                         ; SPI Clock Phase Bit
SPICR1_CPOL:        equ    3                                         ; SPI Clock Polarity Bit
SPICR1_MSTR:        equ    4                                         ; SPI Master/Slave Mode Select Bit
SPICR1_SPTIE:       equ    5                                         ; SPI Transmit Interrupt Enable
SPICR1_SPE:         equ    6                                         ; SPI System Enable Bit
SPICR1_SPIE:        equ    7                                         ; SPI Interrupt Enable Bit
; bit position masks
mSPICR1_LSBFE:      equ    %00000001
mSPICR1_SSOE:       equ    %00000010
mSPICR1_CPHA:       equ    %00000100
mSPICR1_CPOL:       equ    %00001000
mSPICR1_MSTR:       equ    %00010000
mSPICR1_SPTIE:      equ    %00100000
mSPICR1_SPE:        equ    %01000000
mSPICR1_SPIE:       equ    %10000000


;*** SPICR2 - SPI  Control Register 2; 0x000000D9 ***
SPICR2:             equ    $000000D9                                ;*** SPICR2 - SPI  Control Register 2; 0x000000D9 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPICR2_SPC0:        equ    0                                         ; Serial Pin Control Bit 0
SPICR2_SPISWAI:     equ    1                                         ; SPI Stop in Wait Mode Bit
SPICR2_BIDIROE:     equ    3                                         ; Output enable in the Bidirectional mode of operation
SPICR2_MODFEN:      equ    4                                         ; Mode Fault Enable Bit
SPICR2_XFRW:        equ    6                                         ; Transfer Width
; bit position masks
mSPICR2_SPC0:       equ    %00000001
mSPICR2_SPISWAI:    equ    %00000010
mSPICR2_BIDIROE:    equ    %00001000
mSPICR2_MODFEN:     equ    %00010000
mSPICR2_XFRW:       equ    %01000000


;*** SPIBR - SPI  Baud Rate Register; 0x000000DA ***
SPIBR:              equ    $000000DA                                ;*** SPIBR - SPI  Baud Rate Register; 0x000000DA ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPIBR_SPR0:         equ    0                                         ; SPI Baud Rate Selection Bit 0
SPIBR_SPR1:         equ    1                                         ; SPI Baud Rate Selection Bit 1
SPIBR_SPR2:         equ    2                                         ; SPI Baud Rate Selection Bit 2
SPIBR_SPPR0:        equ    4                                         ; SPI Baud Rate Preselection Bits 0
SPIBR_SPPR1:        equ    5                                         ; SPI Baud Rate Preselection Bits 1
SPIBR_SPPR2:        equ    6                                         ; SPI Baud Rate Preselection Bits 2
; bit position masks
mSPIBR_SPR0:        equ    %00000001
mSPIBR_SPR1:        equ    %00000010
mSPIBR_SPR2:        equ    %00000100
mSPIBR_SPPR0:       equ    %00010000
mSPIBR_SPPR1:       equ    %00100000
mSPIBR_SPPR2:       equ    %01000000


;*** SPISR - SPI  Status Register; 0x000000DB ***
SPISR:              equ    $000000DB                                ;*** SPISR - SPI  Status Register; 0x000000DB ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPISR_MODF:         equ    4                                         ; Mode Fault Flag
SPISR_SPTEF:        equ    5                                         ; SPI Transmit Empty Interrupt Flag
SPISR_SPIF:         equ    7                                         ; SPIF Receive Interrupt Flag
; bit position masks
mSPISR_MODF:        equ    %00010000
mSPISR_SPTEF:       equ    %00100000
mSPISR_SPIF:        equ    %10000000


;*** SPIDR - SPI  Data Register; 0x000000DC ***
SPIDR:              equ    $000000DC                                ;*** SPIDR - SPI  Data Register; 0x000000DC ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPIDR_R0_T0:        equ    0                                         ; SPI  Data Bit 0
SPIDR_R1_T1:        equ    1                                         ; SPI  Data Bit 1
SPIDR_R2_T2:        equ    2                                         ; SPI  Data Bit 2
SPIDR_R3_T3:        equ    3                                         ; SPI  Data Bit 3
SPIDR_R4_T4:        equ    4                                         ; SPI  Data Bit 4
SPIDR_R5_T5:        equ    5                                         ; SPI  Data Bit 5
SPIDR_R6_T6:        equ    6                                         ; SPI  Data Bit 6
SPIDR_R7_T7:        equ    7                                         ; SPI  Data Bit 7
SPIDR_R8_T8:        equ    8                                         ; SPI  Data Bit 8
SPIDR_R9_T9:        equ    9                                         ; SPI  Data Bit 9
SPIDR_R10_T10:      equ    10                                        ; SPI  Data Bit 10
SPIDR_R11_T11:      equ    11                                        ; SPI  Data Bit 11
SPIDR_R12_T12:      equ    12                                        ; SPI  Data Bit 12
SPIDR_R13_T13:      equ    13                                        ; SPI  Data Bit 13
SPIDR_R14_T14:      equ    14                                        ; SPI  Data Bit 14
SPIDR_R15_T15:      equ    15                                        ; SPI  Data Bit 15
; bit position masks
mSPIDR_R0_T0:       equ    %00000001
mSPIDR_R1_T1:       equ    %00000010
mSPIDR_R2_T2:       equ    %00000100
mSPIDR_R3_T3:       equ    %00001000
mSPIDR_R4_T4:       equ    %00010000
mSPIDR_R5_T5:       equ    %00100000
mSPIDR_R6_T6:       equ    %01000000
mSPIDR_R7_T7:       equ    %10000000
mSPIDR_R8_T8:       equ    %100000000
mSPIDR_R9_T9:       equ    %1000000000
mSPIDR_R10_T10:     equ    %10000000000
mSPIDR_R11_T11:     equ    %100000000000
mSPIDR_R12_T12:     equ    %1000000000000
mSPIDR_R13_T13:     equ    %10000000000000
mSPIDR_R14_T14:     equ    %100000000000000
mSPIDR_R15_T15:     equ    %1000000000000000


;*** SPIDRH - SPI  Data Register High; 0x000000DC ***
SPIDRH:             equ    $000000DC                                ;*** SPIDRH - SPI  Data Register High; 0x000000DC ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPIDRH_R8_T8:       equ    0                                         ; SPI  Data Bit 8
SPIDRH_R9_T9:       equ    1                                         ; SPI  Data Bit 9
SPIDRH_R10_T10:     equ    2                                         ; SPI  Data Bit 10
SPIDRH_R11_T11:     equ    3                                         ; SPI  Data Bit 11
SPIDRH_R12_T12:     equ    4                                         ; SPI  Data Bit 12
SPIDRH_R13_T13:     equ    5                                         ; SPI  Data Bit 13
SPIDRH_R14_T14:     equ    6                                         ; SPI  Data Bit 14
SPIDRH_R15_T15:     equ    7                                         ; SPI  Data Bit 15
; bit position masks
mSPIDRH_R8_T8:      equ    %00000001
mSPIDRH_R9_T9:      equ    %00000010
mSPIDRH_R10_T10:    equ    %00000100
mSPIDRH_R11_T11:    equ    %00001000
mSPIDRH_R12_T12:    equ    %00010000
mSPIDRH_R13_T13:    equ    %00100000
mSPIDRH_R14_T14:    equ    %01000000
mSPIDRH_R15_T15:    equ    %10000000


;*** SPIDRL - SPI  Data Register Low; 0x000000DD ***
SPIDRL:             equ    $000000DD                                ;*** SPIDRL - SPI  Data Register Low; 0x000000DD ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPIDRL_R0_T0:       equ    0                                         ; SPI  Data Bit 0
SPIDRL_R1_T1:       equ    1                                         ; SPI  Data Bit 1
SPIDRL_R2_T2:       equ    2                                         ; SPI  Data Bit 2
SPIDRL_R3_T3:       equ    3                                         ; SPI  Data Bit 3
SPIDRL_R4_T4:       equ    4                                         ; SPI  Data Bit 4
SPIDRL_R5_T5:       equ    5                                         ; SPI  Data Bit 5
SPIDRL_R6_T6:       equ    6                                         ; SPI  Data Bit 6
SPIDRL_R7_T7:       equ    7                                         ; SPI  Data Bit 7
; bit position masks
mSPIDRL_R0_T0:      equ    %00000001
mSPIDRL_R1_T1:      equ    %00000010
mSPIDRL_R2_T2:      equ    %00000100
mSPIDRL_R3_T3:      equ    %00001000
mSPIDRL_R4_T4:      equ    %00010000
mSPIDRL_R5_T5:      equ    %00100000
mSPIDRL_R6_T6:      equ    %01000000
mSPIDRL_R7_T7:      equ    %10000000


;*** FCLKDIV - Flash Clock Divider Register; 0x00000100 ***
FCLKDIV:            equ    $00000100                                ;*** FCLKDIV - Flash Clock Divider Register; 0x00000100 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FCLKDIV_FDIV0:      equ    0                                         ; Clock Divider Bit 0
FCLKDIV_FDIV1:      equ    1                                         ; Clock Divider Bit 1
FCLKDIV_FDIV2:      equ    2                                         ; Clock Divider Bit 2
FCLKDIV_FDIV3:      equ    3                                         ; Clock Divider Bit 3
FCLKDIV_FDIV4:      equ    4                                         ; Clock Divider Bit 4
FCLKDIV_FDIV5:      equ    5                                         ; Clock Divider Bit 5
FCLKDIV_FDIVLCK:    equ    6                                         ; Clock divider locked
FCLKDIV_FDIVLD:     equ    7                                         ; Clock Divider Loaded
; bit position masks
mFCLKDIV_FDIV0:     equ    %00000001
mFCLKDIV_FDIV1:     equ    %00000010
mFCLKDIV_FDIV2:     equ    %00000100
mFCLKDIV_FDIV3:     equ    %00001000
mFCLKDIV_FDIV4:     equ    %00010000
mFCLKDIV_FDIV5:     equ    %00100000
mFCLKDIV_FDIVLCK:   equ    %01000000
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
DFPROT_DPOPEN:      equ    7                                         ; D-Flash Protection Control
; bit position masks
mDFPROT_DPS0:       equ    %00000001
mDFPROT_DPS1:       equ    %00000010
mDFPROT_DPS2:       equ    %00000100
mDFPROT_DPS3:       equ    %00001000
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


;*** IVBR - Interrupt Vector Base Register; 0x00000120 ***
IVBR:               equ    $00000120                                ;*** IVBR - Interrupt Vector Base Register; 0x00000120 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IVBR_IVB_ADDR0:     equ    0                                         ; Interrupt Vector Base Address Bits, bit 0
IVBR_IVB_ADDR1:     equ    1                                         ; Interrupt Vector Base Address Bits, bit 1
IVBR_IVB_ADDR2:     equ    2                                         ; Interrupt Vector Base Address Bits, bit 2
IVBR_IVB_ADDR3:     equ    3                                         ; Interrupt Vector Base Address Bits, bit 3
IVBR_IVB_ADDR4:     equ    4                                         ; Interrupt Vector Base Address Bits, bit 4
IVBR_IVB_ADDR5:     equ    5                                         ; Interrupt Vector Base Address Bits, bit 5
IVBR_IVB_ADDR6:     equ    6                                         ; Interrupt Vector Base Address Bits, bit 6
IVBR_IVB_ADDR7:     equ    7                                         ; Interrupt Vector Base Address Bits, bit 7
; bit position masks
mIVBR_IVB_ADDR0:    equ    %00000001
mIVBR_IVB_ADDR1:    equ    %00000010
mIVBR_IVB_ADDR2:    equ    %00000100
mIVBR_IVB_ADDR3:    equ    %00001000
mIVBR_IVB_ADDR4:    equ    %00010000
mIVBR_IVB_ADDR5:    equ    %00100000
mIVBR_IVB_ADDR6:    equ    %01000000
mIVBR_IVB_ADDR7:    equ    %10000000


;*** HSDR - Port HS Data Register; 0x00000140 ***
HSDR:               equ    $00000140                                ;*** HSDR - Port HS Data Register; 0x00000140 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
HSDR_HSDR0:         equ    0                                         ; Port HS Data Bit 0
HSDR_HSDR1:         equ    1                                         ; Port HS Data Bit 1
; bit position masks
mHSDR_HSDR0:        equ    %00000001
mHSDR_HSDR1:        equ    %00000010


;*** HSCR - HSDRV Configuration Register; 0x00000141 ***
HSCR:               equ    $00000141                                ;*** HSCR - HSDRV Configuration Register; 0x00000141 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
HSCR_HSE0:          equ    0                                         ; HSDRV Enable Bit 0
HSCR_HSE1:          equ    1                                         ; HSDRV Enable Bit 1
HSCR_HSOLE0:        equ    2                                         ; HSDRV High-Load resistance Open-Load Detection Enable Bit 0
HSCR_HSOLE1:        equ    3                                         ; HSDRV High-Load resistance Open-Load Detection Enable Bit 1
HSCR_HSOCME0:       equ    4                                         ; HSDRV Over-Current Mask Enable Bit0
HSCR_HSOCME1:       equ    5                                         ; HSDRV Over-Current Mask Enable Bit1
; bit position masks
mHSCR_HSE0:         equ    %00000001
mHSCR_HSE1:         equ    %00000010
mHSCR_HSOLE0:       equ    %00000100
mHSCR_HSOLE1:       equ    %00001000
mHSCR_HSOCME0:      equ    %00010000
mHSCR_HSOCME1:      equ    %00100000


;*** HSSR - HSDRV Open Load Status Register; 0x00000145 ***
HSSR:               equ    $00000145                                ;*** HSSR - HSDRV Open Load Status Register; 0x00000145 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
HSSR_HSOL0:         equ    0                                         ; HSDRV Open-Load Status Bit 0
HSSR_HSOL1:         equ    1                                         ; HSDRV Open-Load Status Bit 1
; bit position masks
mHSSR_HSOL0:        equ    %00000001
mHSSR_HSOL1:        equ    %00000010


;*** HSIE - HSDRV Over Current Interrupt Enable Register; 0x00000146 ***
HSIE:               equ    $00000146                                ;*** HSIE - HSDRV Over Current Interrupt Enable Register; 0x00000146 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
HSIE_HSOCIE:        equ    7                                         ; HSDRV Over-Current Interrupt Enable
; bit position masks
mHSIE_HSOCIE:       equ    %10000000


;*** HSIF - HSDRV Over Current Interrupt Flag Register; 0x00000147 ***
HSIF:               equ    $00000147                                ;*** HSIF - HSDRV Over Current Interrupt Flag Register; 0x00000147 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
HSIF_HSOCIF0:       equ    0                                         ; HSDRV Over-Current Interrupt Flag 0
HSIF_HSOCIF1:       equ    1                                         ; HSDRV Over-Current Interrupt Flag 1
; bit position masks
mHSIF_HSOCIF0:      equ    %00000001
mHSIF_HSOCIF1:      equ    %00000010


;*** LSDR - Port LS Data Register; 0x00000150 ***
LSDR:               equ    $00000150                                ;*** LSDR - Port LS Data Register; 0x00000150 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LSDR_LSDR0:         equ    0                                         ; Port LS Data Bit 0
LSDR_LSDR1:         equ    1                                         ; Port LS Data Bit 1
; bit position masks
mLSDR_LSDR0:        equ    %00000001
mLSDR_LSDR1:        equ    %00000010


;*** LSCR - LSDRV Configuration Register; 0x00000151 ***
LSCR:               equ    $00000151                                ;*** LSCR - LSDRV Configuration Register; 0x00000151 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LSCR_LSE0:          equ    0                                         ; LSDRV Enable Bit 0
LSCR_LSE1:          equ    1                                         ; LSDRV Enable Bit 1
LSCR_LSOLE0:        equ    2                                         ; LSDRV High-Load resistance Open-Load Detection Enable Bit 0
LSCR_LSOLE1:        equ    3                                         ; LSDRV High-Load resistance Open-Load Detection Enable Bit 1
; bit position masks
mLSCR_LSE0:         equ    %00000001
mLSCR_LSE1:         equ    %00000010
mLSCR_LSOLE0:       equ    %00000100
mLSCR_LSOLE1:       equ    %00001000


;*** LSSR - LSDRV Open Load Status Register; 0x00000155 ***
LSSR:               equ    $00000155                                ;*** LSSR - LSDRV Open Load Status Register; 0x00000155 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LSSR_LSOL0:         equ    0                                         ; LSDRV Open-Load Status Bit 0
LSSR_LSOL1:         equ    1                                         ; LSDRV Open-Load Status Bit 1
; bit position masks
mLSSR_LSOL0:        equ    %00000001
mLSSR_LSOL1:        equ    %00000010


;*** LSIE - LSDRV Over Current Interrupt Enable Register; 0x00000156 ***
LSIE:               equ    $00000156                                ;*** LSIE - LSDRV Over Current Interrupt Enable Register; 0x00000156 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LSIE_LSOCIE:        equ    7                                         ; LSDRV Over-Current Interrupt Enable
; bit position masks
mLSIE_LSOCIE:       equ    %10000000


;*** LSIF - LSDRV Over Current Interrupt Flag Register; 0x00000157 ***
LSIF:               equ    $00000157                                ;*** LSIF - LSDRV Over Current Interrupt Flag Register; 0x00000157 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LSIF_LSOCIF0:       equ    0                                         ; LSDRV Over-Current Interrupt Flag 0
LSIF_LSOCIF1:       equ    1                                         ; LSDRV Over-Current Interrupt Flag 1
; bit position masks
mLSIF_LSOCIF0:      equ    %00000001
mLSIF_LSOCIF1:      equ    %00000010


;*** LPDR - Port LP Data Register; 0x00000160 ***
LPDR:               equ    $00000160                                ;*** LPDR - Port LP Data Register; 0x00000160 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LPDR_LPDR0:         equ    0                                         ; LIN Rx data
LPDR_LPDR1:         equ    1                                         ; LIN Tx data
; bit position masks
mLPDR_LPDR0:        equ    %00000001
mLPDR_LPDR1:        equ    %00000010


;*** LPCR - LIN Control Register; 0x00000161 ***
LPCR:               equ    $00000161                                ;*** LPCR - LIN Control Register; 0x00000161 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LPCR_LPPUE:         equ    0                                         ; LIN pull-up enable
LPCR_LPWUE:         equ    1                                         ; LIN wake-up enable
LPCR_RXONLY:        equ    2                                         ; Receive only mode
LPCR_LPE:           equ    3                                         ; LIN enable
; bit position masks
mLPCR_LPPUE:        equ    %00000001
mLPCR_LPWUE:        equ    %00000010
mLPCR_RXONLY:       equ    %00000100
mLPCR_LPE:          equ    %00001000


;*** LPSLRM - LIN Slew Rate Register; 0x00000163 ***
LPSLRM:             equ    $00000163                                ;*** LPSLRM - LIN Slew Rate Register; 0x00000163 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LPSLRM_LPSLR:       equ    0                                         ; Slew rate select
LPSLRM_LPDTDIS:     equ    7                                         ; TxD-dominant timeout disable
; bit position masks
mLPSLRM_LPSLR:      equ    %00000011
mLPSLRM_LPDTDIS:    equ    %10000000


;*** LPSR - LIN Status Register; 0x00000165 ***
LPSR:               equ    $00000165                                ;*** LPSR - LIN Status Register; 0x00000165 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LPSR_LPDT:          equ    7                                         ; LIN Transmitter TxD-dominant timeout Status
; bit position masks
mLPSR_LPDT:         equ    %10000000


;*** LPIE - LIN Interrupt Enable Register; 0x00000166 ***
LPIE:               equ    $00000166                                ;*** LPIE - LIN Interrupt Enable Register; 0x00000166 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LPIE_LPOCIE:        equ    6                                         ; LIN over-current interrupt enable
LPIE_LPDTIE:        equ    7                                         ; LIN TxD-dominant timeout Interrupt Enable
; bit position masks
mLPIE_LPOCIE:       equ    %01000000
mLPIE_LPDTIE:       equ    %10000000


;*** LPIF - LIN Interrupt Flags Register; 0x00000167 ***
LPIF:               equ    $00000167                                ;*** LPIF - LIN Interrupt Flags Register; 0x00000167 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LPIF_LPOCIF:        equ    6                                         ; LIN transmitter over-current interrupt flag
LPIF_LPDTIF:        equ    7                                         ; LIN Transmitter TxD-dominant timeout Interrupt Flag
; bit position masks
mLPIF_LPOCIF:       equ    %01000000
mLPIF_LPDTIF:       equ    %10000000


;*** BATE - BATS Module Enable Register; 0x00000170 ***
BATE:               equ    $00000170                                ;*** BATE - BATS Module Enable Register; 0x00000170 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
BATE_BSESE:         equ    0                                         ; BATS VSENSE Level Sense Enable
BATE_BSEAE:         equ    1                                         ; BATS VSENSE ADC Connection Enable
BATE_BSUSE:         equ    2                                         ; BATS VSUP Level Sense Enable
BATE_BSUAE:         equ    3                                         ; BATS VSUP ADC Connection Enable
BATE_BVLS:          equ    4                                         ; BATS Voltage Low Select
BATE_BVHS:          equ    6                                         ; BATS Voltage High Select
; bit position masks
mBATE_BSESE:        equ    %00000001
mBATE_BSEAE:        equ    %00000010
mBATE_BSUSE:        equ    %00000100
mBATE_BSUAE:        equ    %00001000
mBATE_BVLS:         equ    %00110000
mBATE_BVHS:         equ    %01000000


;*** BATSR - BATS Module Status Register; 0x00000171 ***
BATSR:              equ    $00000171                                ;*** BATSR - BATS Module Status Register; 0x00000171 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
BATSR_BVLC:         equ    0                                         ; BATS Voltage Sense Low Condition Bit
BATSR_BVHC:         equ    1                                         ; BATS Voltage Sense High Condition Bit
; bit position masks
mBATSR_BVLC:        equ    %00000001
mBATSR_BVHC:        equ    %00000010


;*** BATIE - BATS Interrupt Enable Register; 0x00000172 ***
BATIE:              equ    $00000172                                ;*** BATIE - BATS Interrupt Enable Register; 0x00000172 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
BATIE_BVLIE:        equ    0                                         ; BATS Interrupt Enable Low
BATIE_BVHIE:        equ    1                                         ; BATS Interrupt Enable High
; bit position masks
mBATIE_BVLIE:       equ    %00000001
mBATIE_BVHIE:       equ    %00000010


;*** BATIF - BATS Interrupt Flag Register; 0x00000173 ***
BATIF:              equ    $00000173                                ;*** BATIF - BATS Interrupt Flag Register; 0x00000173 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
BATIF_BVLIF:        equ    0                                         ; BATS Interrupt Flag Low Detect
BATIF_BVHIF:        equ    1                                         ; BATS Interrupt Flag High Detect
; bit position masks
mBATIF_BVLIF:       equ    %00000001
mBATIF_BVHIF:       equ    %00000010


;*** PTT - Port T Data Register; 0x00000240 ***
PTT:                equ    $00000240                                ;*** PTT - Port T Data Register; 0x00000240 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTT_PTT0:           equ    0                                         ; Port T general purpose input/output data bit 0
PTT_PTT1:           equ    1                                         ; Port T general purpose input/output data bit 1
PTT_PTT2:           equ    2                                         ; Port T general purpose input/output data bit 2
PTT_PTT3:           equ    3                                         ; Port T general purpose input/output data bit 3
; bit position masks
mPTT_PTT0:          equ    %00000001
mPTT_PTT1:          equ    %00000010
mPTT_PTT2:          equ    %00000100
mPTT_PTT3:          equ    %00001000


;*** PTIT - Port T Input Register; 0x00000241 ***
PTIT:               equ    $00000241                                ;*** PTIT - Port T Input Register; 0x00000241 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTIT_PTIT0:         equ    0                                         ; Port T input data bit 0
PTIT_PTIT1:         equ    1                                         ; Port T input data bit 1
PTIT_PTIT2:         equ    2                                         ; Port T input data bit 2
PTIT_PTIT3:         equ    3                                         ; Port T input data bit 3
; bit position masks
mPTIT_PTIT0:        equ    %00000001
mPTIT_PTIT1:        equ    %00000010
mPTIT_PTIT2:        equ    %00000100
mPTIT_PTIT3:        equ    %00001000


;*** DDRT - Port T Data Direction Register; 0x00000242 ***
DDRT:               equ    $00000242                                ;*** DDRT - Port T Data Direction Register; 0x00000242 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DDRT_DDRT0:         equ    0                                         ; Port T data direction bit 0
DDRT_DDRT1:         equ    1                                         ; Port T data direction bit 1
DDRT_DDRT2:         equ    2                                         ; Port T data direction bit 2
DDRT_DDRT3:         equ    3                                         ; Port T data direction bit 3
; bit position masks
mDDRT_DDRT0:        equ    %00000001
mDDRT_DDRT1:        equ    %00000010
mDDRT_DDRT2:        equ    %00000100
mDDRT_DDRT3:        equ    %00001000


;*** PERT - Port T Pull Device Enable Register; 0x00000244 ***
PERT:               equ    $00000244                                ;*** PERT - Port T Pull Device Enable Register; 0x00000244 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PERT_PERT0:         equ    0                                         ; Port T pull device enable bit 0
PERT_PERT1:         equ    1                                         ; Port T pull device enable bit 1
PERT_PERT2:         equ    2                                         ; Port T pull device enable bit 2
PERT_PERT3:         equ    3                                         ; Port T pull device enable bit 3
; bit position masks
mPERT_PERT0:        equ    %00000001
mPERT_PERT1:        equ    %00000010
mPERT_PERT2:        equ    %00000100
mPERT_PERT3:        equ    %00001000


;*** PPST - Port T Polarity Select Register; 0x00000245 ***
PPST:               equ    $00000245                                ;*** PPST - Port T Polarity Select Register; 0x00000245 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PPST_PPST0:         equ    0                                         ; Port T pull device select bit 0
PPST_PPST1:         equ    1                                         ; Port T pull device select bit 1
PPST_PPST2:         equ    2                                         ; Port T pull device select bit 2
PPST_PPST3:         equ    3                                         ; Port T pull device select bit 3
; bit position masks
mPPST_PPST0:        equ    %00000001
mPPST_PPST1:        equ    %00000010
mPPST_PPST2:        equ    %00000100
mPPST_PPST3:        equ    %00001000


;*** MODRR - Port T Routing Register; 0x00000246 ***
MODRR:              equ    $00000246                                ;*** MODRR - Port T Routing Register; 0x00000246 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
MODRR_MODRR00:      equ    0                                         ; Port T  routing
MODRR_MODRR01:      equ    1                                         ; Port T  routing
MODRR_MODRR02:      equ    2                                         ; Port T  routing
MODRR_MODRR03:      equ    3                                         ; Port T  routing
MODRR_MODRR04:      equ    4                                         ; Port T  routing
MODRR_MODRR05:      equ    5                                         ; Port T  routing
MODRR_MODRR06:      equ    6                                         ; Port T  routing
MODRR_MODRR07:      equ    7                                         ; Port T  routing
MODRR_MODRR14:      equ    12                                        ; Port T  routing
MODRR_MODRR15:      equ    13                                        ; Port T  routing
; bit position masks
mMODRR_MODRR00:     equ    %00000001
mMODRR_MODRR01:     equ    %00000010
mMODRR_MODRR02:     equ    %00000100
mMODRR_MODRR03:     equ    %00001000
mMODRR_MODRR04:     equ    %00010000
mMODRR_MODRR05:     equ    %00100000
mMODRR_MODRR06:     equ    %01000000
mMODRR_MODRR07:     equ    %10000000
mMODRR_MODRR14:     equ    %1000000000000
mMODRR_MODRR15:     equ    %10000000000000


;*** MODRR0 - Port T Routing Register Low; 0x00000246 ***
MODRR0:             equ    $00000246                                ;*** MODRR0 - Port T Routing Register Low; 0x00000246 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
MODRR0_MODRR00:     equ    0                                         ; Port T  routing
MODRR0_MODRR01:     equ    1                                         ; Port T  routing
MODRR0_MODRR02:     equ    2                                         ; Port T  routing
MODRR0_MODRR03:     equ    3                                         ; Port T  routing
MODRR0_MODRR04:     equ    4                                         ; Port T  routing
MODRR0_MODRR05:     equ    5                                         ; Port T  routing
MODRR0_MODRR06:     equ    6                                         ; Port T  routing
MODRR0_MODRR07:     equ    7                                         ; Port T  routing
; bit position masks
mMODRR0_MODRR00:    equ    %00000001
mMODRR0_MODRR01:    equ    %00000010
mMODRR0_MODRR02:    equ    %00000100
mMODRR0_MODRR03:    equ    %00001000
mMODRR0_MODRR04:    equ    %00010000
mMODRR0_MODRR05:    equ    %00100000
mMODRR0_MODRR06:    equ    %01000000
mMODRR0_MODRR07:    equ    %10000000


;*** MODRR1 - Port T Routing Register High; 0x00000247 ***
MODRR1:             equ    $00000247                                ;*** MODRR1 - Port T Routing Register High; 0x00000247 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
MODRR1_MODRR14:     equ    4                                         ; Port T  routing
MODRR1_MODRR15:     equ    5                                         ; Port T  routing
; bit position masks
mMODRR1_MODRR14:    equ    %00010000
mMODRR1_MODRR15:    equ    %00100000


;*** PTS - Port S Data Register; 0x00000248 ***
PTS:                equ    $00000248                                ;*** PTS - Port S Data Register; 0x00000248 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTS_PTS0:           equ    0                                         ; Port S general purpose input/output data bit 0
PTS_PTS1:           equ    1                                         ; Port S general purpose input/output data bit 1
PTS_PTS2:           equ    2                                         ; Port S general purpose input/output data bit 2
PTS_PTS3:           equ    3                                         ; Port S general purpose input/output data bit 3
PTS_PTS4:           equ    4                                         ; Port S general purpose input/output data bit 4
PTS_PTS5:           equ    5                                         ; Port S general purpose input/output data bit 5
; bit position masks
mPTS_PTS0:          equ    %00000001
mPTS_PTS1:          equ    %00000010
mPTS_PTS2:          equ    %00000100
mPTS_PTS3:          equ    %00001000
mPTS_PTS4:          equ    %00010000
mPTS_PTS5:          equ    %00100000


;*** PTIS - Port S Input Register; 0x00000249 ***
PTIS:               equ    $00000249                                ;*** PTIS - Port S Input Register; 0x00000249 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTIS_PTIS0:         equ    0                                         ; Port S input data bit 0
PTIS_PTIS1:         equ    1                                         ; Port S input data bit 1
PTIS_PTIS2:         equ    2                                         ; Port S input data bit 2
PTIS_PTIS3:         equ    3                                         ; Port S input data bit 3
PTIS_PTIS4:         equ    4                                         ; Port S input data bit 4
PTIS_PTIS5:         equ    5                                         ; Port S input data bit 5
; bit position masks
mPTIS_PTIS0:        equ    %00000001
mPTIS_PTIS1:        equ    %00000010
mPTIS_PTIS2:        equ    %00000100
mPTIS_PTIS3:        equ    %00001000
mPTIS_PTIS4:        equ    %00010000
mPTIS_PTIS5:        equ    %00100000


;*** DDRS - Port S Data Direction Register; 0x0000024A ***
DDRS:               equ    $0000024A                                ;*** DDRS - Port S Data Direction Register; 0x0000024A ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DDRS_DDRS0:         equ    0                                         ; Port S data direction bit 0
DDRS_DDRS1:         equ    1                                         ; Port S data direction bit 1
DDRS_DDRS2:         equ    2                                         ; Port S data direction bit 2
DDRS_DDRS3:         equ    3                                         ; Port S data direction bit 3
DDRS_DDRS4:         equ    4                                         ; Port S data direction bit 4
DDRS_DDRS5:         equ    5                                         ; Port S data direction bit 5
; bit position masks
mDDRS_DDRS0:        equ    %00000001
mDDRS_DDRS1:        equ    %00000010
mDDRS_DDRS2:        equ    %00000100
mDDRS_DDRS3:        equ    %00001000
mDDRS_DDRS4:        equ    %00010000
mDDRS_DDRS5:        equ    %00100000


;*** PERS - Port S Pull Device Enable Register; 0x0000024C ***
PERS:               equ    $0000024C                                ;*** PERS - Port S Pull Device Enable Register; 0x0000024C ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PERS_PERS0:         equ    0                                         ; Port S pull device enable bit 0
PERS_PERS1:         equ    1                                         ; Port S pull device enable bit 1
PERS_PERS2:         equ    2                                         ; Port S pull device enable bit 2
PERS_PERS3:         equ    3                                         ; Port S pull device enable bit 3
PERS_PERS4:         equ    4                                         ; Port S pull device enable bit 4
PERS_PERS5:         equ    5                                         ; Port S pull device enable bit 5
; bit position masks
mPERS_PERS0:        equ    %00000001
mPERS_PERS1:        equ    %00000010
mPERS_PERS2:        equ    %00000100
mPERS_PERS3:        equ    %00001000
mPERS_PERS4:        equ    %00010000
mPERS_PERS5:        equ    %00100000


;*** PPSS - Port S Polarity Select Register; 0x0000024D ***
PPSS:               equ    $0000024D                                ;*** PPSS - Port S Polarity Select Register; 0x0000024D ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PPSS_PPSS0:         equ    0                                         ; Port S pull device select bit 0
PPSS_PPSS1:         equ    1                                         ; Port S pull device select bit 1
PPSS_PPSS2:         equ    2                                         ; Port S pull device select bit 2
PPSS_PPSS3:         equ    3                                         ; Port S pull device select bit 3
PPSS_PPSS4:         equ    4                                         ; Port S pull device select bit 4
PPSS_PPSS5:         equ    5                                         ; Port S pull device select bit 5
; bit position masks
mPPSS_PPSS0:        equ    %00000001
mPPSS_PPSS1:        equ    %00000010
mPPSS_PPSS2:        equ    %00000100
mPPSS_PPSS3:        equ    %00001000
mPPSS_PPSS4:        equ    %00010000
mPPSS_PPSS5:        equ    %00100000


;*** WOMS - Port S Wired-Or Mode Register; 0x0000024E ***
WOMS:               equ    $0000024E                                ;*** WOMS - Port S Wired-Or Mode Register; 0x0000024E ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
WOMS_WOMS0:         equ    0                                         ; Port S wired-or mode bit 0
WOMS_WOMS1:         equ    1                                         ; Port S wired-or mode bit 1
WOMS_WOMS2:         equ    2                                         ; Port S wired-or mode bit 2
WOMS_WOMS3:         equ    3                                         ; Port S wired-or mode bit 3
WOMS_WOMS4:         equ    4                                         ; Port S wired-or mode bit 4
WOMS_WOMS5:         equ    5                                         ; Port S wired-or mode bit 5
; bit position masks
mWOMS_WOMS0:        equ    %00000001
mWOMS_WOMS1:        equ    %00000010
mWOMS_WOMS2:        equ    %00000100
mWOMS_WOMS3:        equ    %00001000
mWOMS_WOMS4:        equ    %00010000
mWOMS_WOMS5:        equ    %00100000


;*** MODRR2 - Module Routing Register; 0x0000024F ***
MODRR2:             equ    $0000024F                                ;*** MODRR2 - Module Routing Register; 0x0000024F ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
MODRR2_MODRR20:     equ    0                                         ; Module Routing bit 0
MODRR2_MODRR21:     equ    1                                         ; Module Routing bit 1
MODRR2_MODRR22:     equ    2                                         ; Module Routing bit 2
MODRR2_MODRR23:     equ    3                                         ; Module Routing bit 3
MODRR2_MODRR24:     equ    4                                         ; Module Routing bit 4
MODRR2_MODRR25:     equ    5                                         ; Module Routing bit 5
MODRR2_MODRR27:     equ    7                                         ; Module Routing bit 7
; bit position masks
mMODRR2_MODRR20:    equ    %00000001
mMODRR2_MODRR21:    equ    %00000010
mMODRR2_MODRR22:    equ    %00000100
mMODRR2_MODRR23:    equ    %00001000
mMODRR2_MODRR24:    equ    %00010000
mMODRR2_MODRR25:    equ    %00100000
mMODRR2_MODRR27:    equ    %10000000


;*** PTP - Port P Data Register; 0x00000258 ***
PTP:                equ    $00000258                                ;*** PTP - Port P Data Register; 0x00000258 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTP_PTP0:           equ    0                                         ; Port P general purpose input/output data bit 0
PTP_PTP1:           equ    1                                         ; Port P general purpose input/output data bit 1
PTP_PTP2:           equ    2                                         ; Port P general purpose input/output data bit 2
PTP_PTP3:           equ    3                                         ; Port P general purpose input/output data bit 3
PTP_PTP4:           equ    4                                         ; Port P general purpose input/output data bit 4
PTP_PTP5:           equ    5                                         ; Port P general purpose input/output data bit 5
; bit position masks
mPTP_PTP0:          equ    %00000001
mPTP_PTP1:          equ    %00000010
mPTP_PTP2:          equ    %00000100
mPTP_PTP3:          equ    %00001000
mPTP_PTP4:          equ    %00010000
mPTP_PTP5:          equ    %00100000


;*** PTIP - Port P Input Register; 0x00000259 ***
PTIP:               equ    $00000259                                ;*** PTIP - Port P Input Register; 0x00000259 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTIP_PTIP0:         equ    0                                         ; Port P input data bit 0
PTIP_PTIP1:         equ    1                                         ; Port P input data bit 1
PTIP_PTIP2:         equ    2                                         ; Port P input data bit 2
PTIP_PTIP3:         equ    3                                         ; Port P input data bit 3
PTIP_PTIP4:         equ    4                                         ; Port P input data bit 4
PTIP_PTIP5:         equ    5                                         ; Port P input data bit 5
; bit position masks
mPTIP_PTIP0:        equ    %00000001
mPTIP_PTIP1:        equ    %00000010
mPTIP_PTIP2:        equ    %00000100
mPTIP_PTIP3:        equ    %00001000
mPTIP_PTIP4:        equ    %00010000
mPTIP_PTIP5:        equ    %00100000


;*** DDRP - Port P Data Direction Register; 0x0000025A ***
DDRP:               equ    $0000025A                                ;*** DDRP - Port P Data Direction Register; 0x0000025A ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DDRP_DDRP0:         equ    0                                         ; Port P data direction bit 0
DDRP_DDRP1:         equ    1                                         ; Port P data direction bit 1
DDRP_DDRP2:         equ    2                                         ; Port P data direction bit 2
DDRP_DDRP3:         equ    3                                         ; Port P data direction bit 3
DDRP_DDRP4:         equ    4                                         ; Port P data direction bit 4
DDRP_DDRP5:         equ    5                                         ; Port P data direction bit 5
; bit position masks
mDDRP_DDRP0:        equ    %00000001
mDDRP_DDRP1:        equ    %00000010
mDDRP_DDRP2:        equ    %00000100
mDDRP_DDRP3:        equ    %00001000
mDDRP_DDRP4:        equ    %00010000
mDDRP_DDRP5:        equ    %00100000


;*** RDRP - Port P Reduced Drive Register; 0x0000025B ***
RDRP:               equ    $0000025B                                ;*** RDRP - Port P Reduced Drive Register; 0x0000025B ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
RDRP_RDRP0:         equ    0                                         ; Port P reduced drive bit 0
RDRP_RDRP1:         equ    1                                         ; Port P reduced drive bit 1
RDRP_RDRP2:         equ    2                                         ; Port P reduced drive bit 2
; bit position masks
mRDRP_RDRP0:        equ    %00000001
mRDRP_RDRP1:        equ    %00000010
mRDRP_RDRP2:        equ    %00000100


;*** PERP - Port P Pull Device Enable Register; 0x0000025C ***
PERP:               equ    $0000025C                                ;*** PERP - Port P Pull Device Enable Register; 0x0000025C ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PERP_PERP0:         equ    0                                         ; Port P pull device enable bit 0
PERP_PERP1:         equ    1                                         ; Port P pull device enable bit 1
PERP_PERP2:         equ    2                                         ; Port P pull device enable bit 2
PERP_PERP3:         equ    3                                         ; Port P pull device enable bit 3
PERP_PERP4:         equ    4                                         ; Port P pull device enable bit 4
PERP_PERP5:         equ    5                                         ; Port P pull device enable bit 5
; bit position masks
mPERP_PERP0:        equ    %00000001
mPERP_PERP1:        equ    %00000010
mPERP_PERP2:        equ    %00000100
mPERP_PERP3:        equ    %00001000
mPERP_PERP4:        equ    %00010000
mPERP_PERP5:        equ    %00100000


;*** PPSP - Port P Polarity Select Register; 0x0000025D ***
PPSP:               equ    $0000025D                                ;*** PPSP - Port P Polarity Select Register; 0x0000025D ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PPSP_PPSP0:         equ    0                                         ; Port P pull device select bit 0
PPSP_PPSP1:         equ    1                                         ; Port P pull device select bit 1
PPSP_PPSP2:         equ    2                                         ; Port P pull device select bit 2
PPSP_PPSP3:         equ    3                                         ; Port P pull device select bit 3
PPSP_PPSP4:         equ    4                                         ; Port P pull device select bit 4
PPSP_PPSP5:         equ    5                                         ; Port P pull device select bit 5
; bit position masks
mPPSP_PPSP0:        equ    %00000001
mPPSP_PPSP1:        equ    %00000010
mPPSP_PPSP2:        equ    %00000100
mPPSP_PPSP3:        equ    %00001000
mPPSP_PPSP4:        equ    %00010000
mPPSP_PPSP5:        equ    %00100000


;*** PIEP - Port P Interrupt Enable Register; 0x0000025E ***
PIEP:               equ    $0000025E                                ;*** PIEP - Port P Interrupt Enable Register; 0x0000025E ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PIEP_PIEP0:         equ    0                                         ; Port P interrupt enable bit 0
PIEP_PIEP1:         equ    1                                         ; Port P interrupt enable bit 1
PIEP_PIEP2:         equ    2                                         ; Port P interrupt enable bit 2
PIEP_PIEP3:         equ    3                                         ; Port P interrupt enable bit 3
PIEP_PIEP4:         equ    4                                         ; Port P interrupt enable bit 4
PIEP_PIEP5:         equ    5                                         ; Port P interrupt enable bit 5
PIEP_OCIE:          equ    7                                         ; Over-Current Interrupt Enable
; bit position masks
mPIEP_PIEP0:        equ    %00000001
mPIEP_PIEP1:        equ    %00000010
mPIEP_PIEP2:        equ    %00000100
mPIEP_PIEP3:        equ    %00001000
mPIEP_PIEP4:        equ    %00010000
mPIEP_PIEP5:        equ    %00100000
mPIEP_OCIE:         equ    %10000000


;*** PIFP - Port P Interrupt Flag Register; 0x0000025F ***
PIFP:               equ    $0000025F                                ;*** PIFP - Port P Interrupt Flag Register; 0x0000025F ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PIFP_PIFP0:         equ    0                                         ; Port P interrupt flag bit 0
PIFP_PIFP1:         equ    1                                         ; Port P interrupt flag bit 1
PIFP_PIFP2:         equ    2                                         ; Port P interrupt flag bit 2
PIFP_PIFP3:         equ    3                                         ; Port P interrupt flag bit 3
PIFP_PIFP4:         equ    4                                         ; Port P interrupt flag bit 4
PIFP_PIFP5:         equ    5                                         ; Port P interrupt flag bit 5
PIFP_OCIF:          equ    7                                         ; Over-Current Interrupt Flag
; bit position masks
mPIFP_PIFP0:        equ    %00000001
mPIFP_PIFP1:        equ    %00000010
mPIFP_PIFP2:        equ    %00000100
mPIFP_PIFP3:        equ    %00001000
mPIFP_PIFP4:        equ    %00010000
mPIFP_PIFP5:        equ    %00100000
mPIFP_OCIF:         equ    %10000000


;*** PTIL - Port L Input Register; 0x00000269 ***
PTIL:               equ    $00000269                                ;*** PTIL - Port L Input Register; 0x00000269 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTIL_PTIL0:         equ    0                                         ; Port L Bit 0
PTIL_PTIL1:         equ    1                                         ; Port L Bit 1
PTIL_PTIL2:         equ    2                                         ; Port L Bit 2
PTIL_PTIL3:         equ    3                                         ; Port L Bit 3
; bit position masks
mPTIL_PTIL0:        equ    %00000001
mPTIL_PTIL1:        equ    %00000010
mPTIL_PTIL2:        equ    %00000100
mPTIL_PTIL3:        equ    %00001000


;*** DIENL - Port L Digital Input Enable Register; 0x0000026A ***
DIENL:              equ    $0000026A                                ;*** DIENL - Port L Digital Input Enable Register; 0x0000026A ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DIENL_DIENL0:       equ    0                                         ; Digital Input Enable Port L Bit 0
DIENL_DIENL1:       equ    1                                         ; Digital Input Enable Port L Bit 1
DIENL_DIENL2:       equ    2                                         ; Digital Input Enable Port L Bit 2
DIENL_DIENL3:       equ    3                                         ; Digital Input Enable Port L Bit 3
; bit position masks
mDIENL_DIENL0:      equ    %00000001
mDIENL_DIENL1:      equ    %00000010
mDIENL_DIENL2:      equ    %00000100
mDIENL_DIENL3:      equ    %00001000


;*** PTAL - Port L Analog Access Register; 0x0000026B ***
PTAL:               equ    $0000026B                                ;*** PTAL - Port L Analog Access Register; 0x0000026B ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTAL_PTAL0:         equ    0                                         ; Port ADC connection selector, bit 0
PTAL_PTAL1:         equ    1                                         ; Port ADC connection selector, bit 1
PTAL_PTAENL:        equ    3                                         ; Port ADC connection enable
PTAL_PTADIRL:       equ    4                                         ; Port ADC direct connection
PTAL_PTABYPL:       equ    5                                         ; Port ADC connection bypass
PTAL_PTPSL:         equ    6                                         ; Port pull select
PTAL_PTTEL:         equ    7                                         ; Port test enable
; bit position masks
mPTAL_PTAL0:        equ    %00000001
mPTAL_PTAL1:        equ    %00000010
mPTAL_PTAENL:       equ    %00001000
mPTAL_PTADIRL:      equ    %00010000
mPTAL_PTABYPL:      equ    %00100000
mPTAL_PTPSL:        equ    %01000000
mPTAL_PTTEL:        equ    %10000000


;*** PIRL - Port L Input Divider Ratio Selection Register; 0x0000026C ***
PIRL:               equ    $0000026C                                ;*** PIRL - Port L Input Divider Ratio Selection Register; 0x0000026C ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PIRL_PIRL0:         equ    0                                         ; Port L Input Divider Ratio SelectBit 0
PIRL_PIRL1:         equ    1                                         ; Port L Input Divider Ratio SelectBit 1
PIRL_PIRL2:         equ    2                                         ; Port L Input Divider Ratio SelectBit 2
PIRL_PIRL3:         equ    3                                         ; Port L Input Divider Ratio SelectBit 3
; bit position masks
mPIRL_PIRL0:        equ    %00000001
mPIRL_PIRL1:        equ    %00000010
mPIRL_PIRL2:        equ    %00000100
mPIRL_PIRL3:        equ    %00001000


;*** PPSL - Port L Polarity Select Register; 0x0000026D ***
PPSL:               equ    $0000026D                                ;*** PPSL - Port L Polarity Select Register; 0x0000026D ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PPSL_PPSL0:         equ    0                                         ; Pin Interrupt Polarity Select Port L Bit 0
PPSL_PPSL1:         equ    1                                         ; Pin Interrupt Polarity Select Port L Bit 1
PPSL_PPSL2:         equ    2                                         ; Pin Interrupt Polarity Select Port L Bit 2
PPSL_PPSL3:         equ    3                                         ; Pin Interrupt Polarity Select Port L Bit 3
; bit position masks
mPPSL_PPSL0:        equ    %00000001
mPPSL_PPSL1:        equ    %00000010
mPPSL_PPSL2:        equ    %00000100
mPPSL_PPSL3:        equ    %00001000


;*** PIEL - Port L Interrupt Enable Register; 0x0000026E ***
PIEL:               equ    $0000026E                                ;*** PIEL - Port L Interrupt Enable Register; 0x0000026E ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PIEL_PIEL0:         equ    0                                         ; Interrupt Enable Port L Bit 0
PIEL_PIEL1:         equ    1                                         ; Interrupt Enable Port L Bit 1
PIEL_PIEL2:         equ    2                                         ; Interrupt Enable Port L Bit 2
PIEL_PIEL3:         equ    3                                         ; Interrupt Enable Port L Bit 3
; bit position masks
mPIEL_PIEL0:        equ    %00000001
mPIEL_PIEL1:        equ    %00000010
mPIEL_PIEL2:        equ    %00000100
mPIEL_PIEL3:        equ    %00001000


;*** PIFL - Port L Interrupt Flag Register; 0x0000026F ***
PIFL:               equ    $0000026F                                ;*** PIFL - Port L Interrupt Flag Register; 0x0000026F ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PIFL_PIFL0:         equ    0                                         ; Interrupt Flags Port L Bit 0
PIFL_PIFL1:         equ    1                                         ; Interrupt Flags Port L Bit 1
PIFL_PIFL2:         equ    2                                         ; Interrupt Flags Port L Bit 2
PIFL_PIFL3:         equ    3                                         ; Interrupt Flags Port L Bit 3
; bit position masks
mPIFL_PIFL0:        equ    %00000001
mPIFL_PIFL1:        equ    %00000010
mPIFL_PIFL2:        equ    %00000100
mPIFL_PIFL3:        equ    %00001000


;*** PT1AD - Port ADL Data Register; 0x00000271 ***
PT1AD:              equ    $00000271                                ;*** PT1AD - Port ADL Data Register; 0x00000271 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PT1AD_PT1AD0:       equ    0                                         ; Port AD data bit 0
PT1AD_PT1AD1:       equ    1                                         ; Port AD data bit 1
PT1AD_PT1AD2:       equ    2                                         ; Port AD data bit 2
PT1AD_PT1AD3:       equ    3                                         ; Port AD data bit 3
PT1AD_PT1AD4:       equ    4                                         ; Port AD data bit 4
PT1AD_PT1AD5:       equ    5                                         ; Port AD data bit 5
; bit position masks
mPT1AD_PT1AD0:      equ    %00000001
mPT1AD_PT1AD1:      equ    %00000010
mPT1AD_PT1AD2:      equ    %00000100
mPT1AD_PT1AD3:      equ    %00001000
mPT1AD_PT1AD4:      equ    %00010000
mPT1AD_PT1AD5:      equ    %00100000


;*** PTI1AD - Port ADL Input Register; 0x00000273 ***
PTI1AD:             equ    $00000273                                ;*** PTI1AD - Port ADL Input Register; 0x00000273 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTI1AD_PTI1AD0:     equ    0                                         ; Port ADL Bit 0
PTI1AD_PTI1AD1:     equ    1                                         ; Port ADL Bit 1
PTI1AD_PTI1AD2:     equ    2                                         ; Port ADL Bit 2
PTI1AD_PTI1AD3:     equ    3                                         ; Port ADL Bit 3
PTI1AD_PTI1AD4:     equ    4                                         ; Port ADL Bit 4
PTI1AD_PTI1AD5:     equ    5                                         ; Port ADL Bit 5
; bit position masks
mPTI1AD_PTI1AD0:    equ    %00000001
mPTI1AD_PTI1AD1:    equ    %00000010
mPTI1AD_PTI1AD2:    equ    %00000100
mPTI1AD_PTI1AD3:    equ    %00001000
mPTI1AD_PTI1AD4:    equ    %00010000
mPTI1AD_PTI1AD5:    equ    %00100000


;*** DDR1AD - Port ADL Data Direction Register; 0x00000275 ***
DDR1AD:             equ    $00000275                                ;*** DDR1AD - Port ADL Data Direction Register; 0x00000275 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DDR1AD_DDR1AD0:     equ    0                                         ; Port AD data direction bit 0
DDR1AD_DDR1AD1:     equ    1                                         ; Port AD data direction bit 1
DDR1AD_DDR1AD2:     equ    2                                         ; Port AD data direction bit 2
DDR1AD_DDR1AD3:     equ    3                                         ; Port AD data direction bit 3
DDR1AD_DDR1AD4:     equ    4                                         ; Port AD data direction bit 4
DDR1AD_DDR1AD5:     equ    5                                         ; Port AD data direction bit 5
; bit position masks
mDDR1AD_DDR1AD0:    equ    %00000001
mDDR1AD_DDR1AD1:    equ    %00000010
mDDR1AD_DDR1AD2:    equ    %00000100
mDDR1AD_DDR1AD3:    equ    %00001000
mDDR1AD_DDR1AD4:    equ    %00010000
mDDR1AD_DDR1AD5:    equ    %00100000


;*** PER1AD - Port ADL Pull Up Enable Register; 0x00000279 ***
PER1AD:             equ    $00000279                                ;*** PER1AD - Port ADL Pull Up Enable Register; 0x00000279 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PER1AD_PER1AD0:     equ    0                                         ; Port ADL pull up enable bit 0
PER1AD_PER1AD1:     equ    1                                         ; Port ADL pull up enable bit 1
PER1AD_PER1AD2:     equ    2                                         ; Port ADL pull up enable bit 2
PER1AD_PER1AD3:     equ    3                                         ; Port ADL pull up enable bit 3
PER1AD_PER1AD4:     equ    4                                         ; Port ADL pull up enable bit 4
PER1AD_PER1AD5:     equ    5                                         ; Port ADL pull up enable bit 5
; bit position masks
mPER1AD_PER1AD0:    equ    %00000001
mPER1AD_PER1AD1:    equ    %00000010
mPER1AD_PER1AD2:    equ    %00000100
mPER1AD_PER1AD3:    equ    %00001000
mPER1AD_PER1AD4:    equ    %00010000
mPER1AD_PER1AD5:    equ    %00100000


;*** PPS1AD - Port ADL Polarity Select Register; 0x0000027B ***
PPS1AD:             equ    $0000027B                                ;*** PPS1AD - Port ADL Polarity Select Register; 0x0000027B ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PPS1AD_PPS1AD0:     equ    0                                         ; Port ADL Polarity Select Bit 0
PPS1AD_PPS1AD1:     equ    1                                         ; Port ADL Polarity Select Bit 1
PPS1AD_PPS1AD2:     equ    2                                         ; Port ADL Polarity Select Bit 2
PPS1AD_PPS1AD3:     equ    3                                         ; Port ADL Polarity Select Bit 3
PPS1AD_PPS1AD4:     equ    4                                         ; Port ADL Polarity Select Bit 4
PPS1AD_PPS1AD5:     equ    5                                         ; Port ADL Polarity Select Bit 5
; bit position masks
mPPS1AD_PPS1AD0:    equ    %00000001
mPPS1AD_PPS1AD1:    equ    %00000010
mPPS1AD_PPS1AD2:    equ    %00000100
mPPS1AD_PPS1AD3:    equ    %00001000
mPPS1AD_PPS1AD4:    equ    %00010000
mPPS1AD_PPS1AD5:    equ    %00100000


;*** PIE1AD - Port ADL Interrupt Enable Register; 0x0000027D ***
PIE1AD:             equ    $0000027D                                ;*** PIE1AD - Port ADL Interrupt Enable Register; 0x0000027D ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PIE1AD_PIE1AD0:     equ    0                                         ; Port ADL Interrupt Enable Bit 0
PIE1AD_PIE1AD1:     equ    1                                         ; Port ADL Interrupt Enable Bit 1
PIE1AD_PIE1AD2:     equ    2                                         ; Port ADL Interrupt Enable Bit 2
PIE1AD_PIE1AD3:     equ    3                                         ; Port ADL Interrupt Enable Bit 3
PIE1AD_PIE1AD4:     equ    4                                         ; Port ADL Interrupt Enable Bit 4
PIE1AD_PIE1AD5:     equ    5                                         ; Port ADL Interrupt Enable Bit 5
; bit position masks
mPIE1AD_PIE1AD0:    equ    %00000001
mPIE1AD_PIE1AD1:    equ    %00000010
mPIE1AD_PIE1AD2:    equ    %00000100
mPIE1AD_PIE1AD3:    equ    %00001000
mPIE1AD_PIE1AD4:    equ    %00010000
mPIE1AD_PIE1AD5:    equ    %00100000


;*** PIF1AD - Port ADL Interrupt Flag Register; 0x0000027F ***
PIF1AD:             equ    $0000027F                                ;*** PIF1AD - Port ADL Interrupt Flag Register; 0x0000027F ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PIF1AD_PIF1AD0:     equ    0                                         ; Port ADL Bit 0
PIF1AD_PIF1AD1:     equ    1                                         ; Port ADL Bit 1
PIF1AD_PIF1AD2:     equ    2                                         ; Port ADL Bit 2
PIF1AD_PIF1AD3:     equ    3                                         ; Port ADL Bit 3
PIF1AD_PIF1AD4:     equ    4                                         ; Port ADL Bit 4
PIF1AD_PIF1AD5:     equ    5                                         ; Port ADL Bit 5
; bit position masks
mPIF1AD_PIF1AD0:    equ    %00000001
mPIF1AD_PIF1AD1:    equ    %00000010
mPIF1AD_PIF1AD2:    equ    %00000100
mPIF1AD_PIF1AD3:    equ    %00001000
mPIF1AD_PIF1AD4:    equ    %00010000
mPIF1AD_PIF1AD5:    equ    %00100000


;*** CPMUHTCTL - High Temperature Control Register; 0x000002F0 ***
CPMUHTCTL:          equ    $000002F0                                ;*** CPMUHTCTL - High Temperature Control Register; 0x000002F0 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CPMUHTCTL_HTIF:     equ    0                                         ; High Temperature Interrupt Flag
CPMUHTCTL_HTIE:     equ    1                                         ; High Temperature Interrupt Enable Bit
CPMUHTCTL_HTDS:     equ    2                                         ; High Temperature Detect Status Bi
CPMUHTCTL_HTE:      equ    3                                         ; High Temperature Enable Bit
CPMUHTCTL_VSEL:     equ    5                                         ; Voltage Access Select Bit
; bit position masks
mCPMUHTCTL_HTIF:    equ    %00000001
mCPMUHTCTL_HTIE:    equ    %00000010
mCPMUHTCTL_HTDS:    equ    %00000100
mCPMUHTCTL_HTE:     equ    %00001000
mCPMUHTCTL_VSEL:    equ    %00100000


;*** CPMULVCTL - Low Voltage Control Register; 0x000002F1 ***
CPMULVCTL:          equ    $000002F1                                ;*** CPMULVCTL - Low Voltage Control Register; 0x000002F1 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CPMULVCTL_LVIF:     equ    0                                         ; Low-Voltage Interrupt Flag
CPMULVCTL_LVIE:     equ    1                                         ; Low-Voltage Interrupt Enable Bit
CPMULVCTL_LVDS:     equ    2                                         ; Low-Voltage Detect Status Bit
; bit position masks
mCPMULVCTL_LVIF:    equ    %00000001
mCPMULVCTL_LVIE:    equ    %00000010
mCPMULVCTL_LVDS:    equ    %00000100


;*** CPMUAPICTL - Autonomous Periodical Interrupt Control Register; 0x000002F2 ***
CPMUAPICTL:         equ    $000002F2                                ;*** CPMUAPICTL - Autonomous Periodical Interrupt Control Register; 0x000002F2 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CPMUAPICTL_APIF:    equ    0                                         ; Autonomous Periodical Interrupt Flag
CPMUAPICTL_APIE:    equ    1                                         ; Autonomous Periodical Interrupt Enable Bit
CPMUAPICTL_APIFE:   equ    2                                         ; Autonomous Periodical Interrupt Feature Enable Bit
CPMUAPICTL_APICLK:  equ    7                                         ; Autonomous Periodical Interrupt Clock Select Bit
; bit position masks
mCPMUAPICTL_APIF:   equ    %00000001
mCPMUAPICTL_APIE:   equ    %00000010
mCPMUAPICTL_APIFE:  equ    %00000100
mCPMUAPICTL_APICLK: equ    %10000000


;*** CPMUACLKTR - Autonomous Clock Trimming Register; 0x000002F3 ***
CPMUACLKTR:         equ    $000002F3                                ;*** CPMUACLKTR - Autonomous Clock Trimming Register; 0x000002F3 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CPMUACLKTR_ACLKTR0: equ    2                                         ; Autonomous Periodical Interrupt Period Trimming Bit 0
CPMUACLKTR_ACLKTR1: equ    3                                         ; Autonomous Periodical Interrupt Period Trimming Bit 1
CPMUACLKTR_ACLKTR2: equ    4                                         ; Autonomous Periodical Interrupt Period Trimming Bit 2
CPMUACLKTR_ACLKTR3: equ    5                                         ; Autonomous Periodical Interrupt Period Trimming Bit 3
CPMUACLKTR_ACLKTR4: equ    6                                         ; Autonomous Periodical Interrupt Period Trimming Bit 4
CPMUACLKTR_ACLKTR5: equ    7                                         ; Autonomous Periodical Interrupt Period Trimming Bit 5
; bit position masks
mCPMUACLKTR_ACLKTR0: equ    %00000100
mCPMUACLKTR_ACLKTR1: equ    %00001000
mCPMUACLKTR_ACLKTR2: equ    %00010000
mCPMUACLKTR_ACLKTR3: equ    %00100000
mCPMUACLKTR_ACLKTR4: equ    %01000000
mCPMUACLKTR_ACLKTR5: equ    %10000000


;*** CPMUAPIR - Autonomous Periodical Interrupt Rate Register; 0x000002F4 ***
CPMUAPIR:           equ    $000002F4                                ;*** CPMUAPIR - Autonomous Periodical Interrupt Rate Register; 0x000002F4 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CPMUAPIR_APIR0:     equ    0                                         ; Autonomous Periodical Interrupt Rate Bit 0
CPMUAPIR_APIR1:     equ    1                                         ; Autonomous Periodical Interrupt Rate Bit 1
CPMUAPIR_APIR2:     equ    2                                         ; Autonomous Periodical Interrupt Rate Bit 2
CPMUAPIR_APIR3:     equ    3                                         ; Autonomous Periodical Interrupt Rate Bit 3
CPMUAPIR_APIR4:     equ    4                                         ; Autonomous Periodical Interrupt Rate Bit 4
CPMUAPIR_APIR5:     equ    5                                         ; Autonomous Periodical Interrupt Rate Bit 5
CPMUAPIR_APIR6:     equ    6                                         ; Autonomous Periodical Interrupt Rate Bit 6
CPMUAPIR_APIR7:     equ    7                                         ; Autonomous Periodical Interrupt Rate Bit 7
CPMUAPIR_APIR8:     equ    8                                         ; Autonomous Periodical Interrupt Rate Bit 8
CPMUAPIR_APIR9:     equ    9                                         ; Autonomous Periodical Interrupt Rate Bit 9
CPMUAPIR_APIR10:    equ    10                                        ; Autonomous Periodical Interrupt Rate Bit 10
CPMUAPIR_APIR11:    equ    11                                        ; Autonomous Periodical Interrupt Rate Bit 11
CPMUAPIR_APIR12:    equ    12                                        ; Autonomous Periodical Interrupt Rate Bit 12
CPMUAPIR_APIR13:    equ    13                                        ; Autonomous Periodical Interrupt Rate Bit 13
CPMUAPIR_APIR14:    equ    14                                        ; Autonomous Periodical Interrupt Rate Bit 14
CPMUAPIR_APIR15:    equ    15                                        ; Autonomous Periodical Interrupt Rate Bit 15
; bit position masks
mCPMUAPIR_APIR0:    equ    %00000001
mCPMUAPIR_APIR1:    equ    %00000010
mCPMUAPIR_APIR2:    equ    %00000100
mCPMUAPIR_APIR3:    equ    %00001000
mCPMUAPIR_APIR4:    equ    %00010000
mCPMUAPIR_APIR5:    equ    %00100000
mCPMUAPIR_APIR6:    equ    %01000000
mCPMUAPIR_APIR7:    equ    %10000000
mCPMUAPIR_APIR8:    equ    %100000000
mCPMUAPIR_APIR9:    equ    %1000000000
mCPMUAPIR_APIR10:   equ    %10000000000
mCPMUAPIR_APIR11:   equ    %100000000000
mCPMUAPIR_APIR12:   equ    %1000000000000
mCPMUAPIR_APIR13:   equ    %10000000000000
mCPMUAPIR_APIR14:   equ    %100000000000000
mCPMUAPIR_APIR15:   equ    %1000000000000000


;*** CPMUAPIRH - Autonomous Periodical Interrupt Rate Register High; 0x000002F4 ***
CPMUAPIRH:          equ    $000002F4                                ;*** CPMUAPIRH - Autonomous Periodical Interrupt Rate Register High; 0x000002F4 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CPMUAPIRH_APIR8:    equ    0                                         ; Autonomous Periodical Interrupt Rate Bit 8
CPMUAPIRH_APIR9:    equ    1                                         ; Autonomous Periodical Interrupt Rate Bit 9
CPMUAPIRH_APIR10:   equ    2                                         ; Autonomous Periodical Interrupt Rate Bit 10
CPMUAPIRH_APIR11:   equ    3                                         ; Autonomous Periodical Interrupt Rate Bit 11
CPMUAPIRH_APIR12:   equ    4                                         ; Autonomous Periodical Interrupt Rate Bit 12
CPMUAPIRH_APIR13:   equ    5                                         ; Autonomous Periodical Interrupt Rate Bit 13
CPMUAPIRH_APIR14:   equ    6                                         ; Autonomous Periodical Interrupt Rate Bit 14
CPMUAPIRH_APIR15:   equ    7                                         ; Autonomous Periodical Interrupt Rate Bit 15
; bit position masks
mCPMUAPIRH_APIR8:   equ    %00000001
mCPMUAPIRH_APIR9:   equ    %00000010
mCPMUAPIRH_APIR10:  equ    %00000100
mCPMUAPIRH_APIR11:  equ    %00001000
mCPMUAPIRH_APIR12:  equ    %00010000
mCPMUAPIRH_APIR13:  equ    %00100000
mCPMUAPIRH_APIR14:  equ    %01000000
mCPMUAPIRH_APIR15:  equ    %10000000


;*** CPMUAPIRL - Autonomous Periodical Interrupt Rate Register Low; 0x000002F5 ***
CPMUAPIRL:          equ    $000002F5                                ;*** CPMUAPIRL - Autonomous Periodical Interrupt Rate Register Low; 0x000002F5 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CPMUAPIRL_APIR0:    equ    0                                         ; Autonomous Periodical Interrupt Rate Bit 0
CPMUAPIRL_APIR1:    equ    1                                         ; Autonomous Periodical Interrupt Rate Bit 1
CPMUAPIRL_APIR2:    equ    2                                         ; Autonomous Periodical Interrupt Rate Bit 2
CPMUAPIRL_APIR3:    equ    3                                         ; Autonomous Periodical Interrupt Rate Bit 3
CPMUAPIRL_APIR4:    equ    4                                         ; Autonomous Periodical Interrupt Rate Bit 4
CPMUAPIRL_APIR5:    equ    5                                         ; Autonomous Periodical Interrupt Rate Bit 5
CPMUAPIRL_APIR6:    equ    6                                         ; Autonomous Periodical Interrupt Rate Bit 6
CPMUAPIRL_APIR7:    equ    7                                         ; Autonomous Periodical Interrupt Rate Bit 7
; bit position masks
mCPMUAPIRL_APIR0:   equ    %00000001
mCPMUAPIRL_APIR1:   equ    %00000010
mCPMUAPIRL_APIR2:   equ    %00000100
mCPMUAPIRL_APIR3:   equ    %00001000
mCPMUAPIRL_APIR4:   equ    %00010000
mCPMUAPIRL_APIR5:   equ    %00100000
mCPMUAPIRL_APIR6:   equ    %01000000
mCPMUAPIRL_APIR7:   equ    %10000000


;*** CPMUHTTR - High Temperature Trimming Register; 0x000002F7 ***
CPMUHTTR:           equ    $000002F7                                ;*** CPMUHTTR - High Temperature Trimming Register; 0x000002F7 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CPMUHTTR_HTTR0:     equ    0                                         ; High Temperature Trimming Bits, bit 0
CPMUHTTR_HTTR1:     equ    1                                         ; High Temperature Trimming Bits, bit 1
CPMUHTTR_HTTR2:     equ    2                                         ; High Temperature Trimming Bits, bit 2
CPMUHTTR_HTTR3:     equ    3                                         ; High Temperature Trimming Bits, bit 3
CPMUHTTR_HTOE:      equ    7                                         ; High Temperature Offeset Enable Bit
; bit position masks
mCPMUHTTR_HTTR0:    equ    %00000001
mCPMUHTTR_HTTR1:    equ    %00000010
mCPMUHTTR_HTTR2:    equ    %00000100
mCPMUHTTR_HTTR3:    equ    %00001000
mCPMUHTTR_HTOE:     equ    %10000000


;*** CPMUIRCTRIM - S12CPMU IRC1M Trim Registers; 0x000002F8 ***
CPMUIRCTRIM:        equ    $000002F8                                ;*** CPMUIRCTRIM - S12CPMU IRC1M Trim Registers; 0x000002F8 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CPMUIRCTRIM_IRCTRIM0: equ    0                                       ; IRC1M Frequency Trim Bit 0
CPMUIRCTRIM_IRCTRIM1: equ    1                                       ; IRC1M Frequency Trim Bit 1
CPMUIRCTRIM_IRCTRIM2: equ    2                                       ; IRC1M Frequency Trim Bit 2
CPMUIRCTRIM_IRCTRIM3: equ    3                                       ; IRC1M Frequency Trim Bit 3
CPMUIRCTRIM_IRCTRIM4: equ    4                                       ; IRC1M Frequency Trim Bit 4
CPMUIRCTRIM_IRCTRIM5: equ    5                                       ; IRC1M Frequency Trim Bit 5
CPMUIRCTRIM_IRCTRIM6: equ    6                                       ; IRC1M Frequency Trim Bit 6
CPMUIRCTRIM_IRCTRIM7: equ    7                                       ; IRC1M Frequency Trim Bit 7
CPMUIRCTRIM_IRCTRIM8: equ    8                                       ; IRC1M Frequency Trim Bit 8
CPMUIRCTRIM_IRCTRIM9: equ    9                                       ; IRC1M Frequency Trim Bit 9
CPMUIRCTRIM_TCTRIM0: equ    11                                       ; IRC1M temperature coeficient Trim Bit 0
CPMUIRCTRIM_TCTRIM1: equ    12                                       ; IRC1M temperature coeficient Trim Bit 1
CPMUIRCTRIM_TCTRIM2: equ    13                                       ; IRC1M temperature coeficient Trim Bit 2
CPMUIRCTRIM_TCTRIM3: equ    14                                       ; IRC1M temperature coeficient Trim Bit 3
CPMUIRCTRIM_TCTRIM4: equ    15                                       ; IRC1M temperature coeficient Trim Bit 4
; bit position masks
mCPMUIRCTRIM_IRCTRIM0: equ    %00000001
mCPMUIRCTRIM_IRCTRIM1: equ    %00000010
mCPMUIRCTRIM_IRCTRIM2: equ    %00000100
mCPMUIRCTRIM_IRCTRIM3: equ    %00001000
mCPMUIRCTRIM_IRCTRIM4: equ    %00010000
mCPMUIRCTRIM_IRCTRIM5: equ    %00100000
mCPMUIRCTRIM_IRCTRIM6: equ    %01000000
mCPMUIRCTRIM_IRCTRIM7: equ    %10000000
mCPMUIRCTRIM_IRCTRIM8: equ    %100000000
mCPMUIRCTRIM_IRCTRIM9: equ    %1000000000
mCPMUIRCTRIM_TCTRIM0: equ    %100000000000
mCPMUIRCTRIM_TCTRIM1: equ    %1000000000000
mCPMUIRCTRIM_TCTRIM2: equ    %10000000000000
mCPMUIRCTRIM_TCTRIM3: equ    %100000000000000
mCPMUIRCTRIM_TCTRIM4: equ    %1000000000000000


;*** CPMUIRCTRIMH - S12CPMU IRC1M Trim Registers High; 0x000002F8 ***
CPMUIRCTRIMH:       equ    $000002F8                                ;*** CPMUIRCTRIMH - S12CPMU IRC1M Trim Registers High; 0x000002F8 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CPMUIRCTRIMH_IRCTRIM8: equ    0                                      ; IRC1M Frequency Trim Bit 8
CPMUIRCTRIMH_IRCTRIM9: equ    1                                      ; IRC1M Frequency Trim Bit 9
CPMUIRCTRIMH_TCTRIM0: equ    3                                       ; IRC1M temperature coeficient Trim Bit 0
CPMUIRCTRIMH_TCTRIM1: equ    4                                       ; IRC1M temperature coeficient Trim Bit 1
CPMUIRCTRIMH_TCTRIM2: equ    5                                       ; IRC1M temperature coeficient Trim Bit 2
CPMUIRCTRIMH_TCTRIM3: equ    6                                       ; IRC1M temperature coeficient Trim Bit 3
CPMUIRCTRIMH_TCTRIM4: equ    7                                       ; IRC1M temperature coeficient Trim Bit 4
; bit position masks
mCPMUIRCTRIMH_IRCTRIM8: equ    %00000001
mCPMUIRCTRIMH_IRCTRIM9: equ    %00000010
mCPMUIRCTRIMH_TCTRIM0: equ    %00001000
mCPMUIRCTRIMH_TCTRIM1: equ    %00010000
mCPMUIRCTRIMH_TCTRIM2: equ    %00100000
mCPMUIRCTRIMH_TCTRIM3: equ    %01000000
mCPMUIRCTRIMH_TCTRIM4: equ    %10000000


;*** CPMUIRCTRIML - S12CPMU IRC1M Trim Registers Low; 0x000002F9 ***
CPMUIRCTRIML:       equ    $000002F9                                ;*** CPMUIRCTRIML - S12CPMU IRC1M Trim Registers Low; 0x000002F9 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CPMUIRCTRIML_IRCTRIM0: equ    0                                      ; IRC1M Frequency Trim Bit 0
CPMUIRCTRIML_IRCTRIM1: equ    1                                      ; IRC1M Frequency Trim Bit 1
CPMUIRCTRIML_IRCTRIM2: equ    2                                      ; IRC1M Frequency Trim Bit 2
CPMUIRCTRIML_IRCTRIM3: equ    3                                      ; IRC1M Frequency Trim Bit 3
CPMUIRCTRIML_IRCTRIM4: equ    4                                      ; IRC1M Frequency Trim Bit 4
CPMUIRCTRIML_IRCTRIM5: equ    5                                      ; IRC1M Frequency Trim Bit 5
CPMUIRCTRIML_IRCTRIM6: equ    6                                      ; IRC1M Frequency Trim Bit 6
CPMUIRCTRIML_IRCTRIM7: equ    7                                      ; IRC1M Frequency Trim Bit 7
; bit position masks
mCPMUIRCTRIML_IRCTRIM0: equ    %00000001
mCPMUIRCTRIML_IRCTRIM1: equ    %00000010
mCPMUIRCTRIML_IRCTRIM2: equ    %00000100
mCPMUIRCTRIML_IRCTRIM3: equ    %00001000
mCPMUIRCTRIML_IRCTRIM4: equ    %00010000
mCPMUIRCTRIML_IRCTRIM5: equ    %00100000
mCPMUIRCTRIML_IRCTRIM6: equ    %01000000
mCPMUIRCTRIML_IRCTRIM7: equ    %10000000


;*** CPMUOSC - S12CPMU Oscillator Register; 0x000002FA ***
CPMUOSC:            equ    $000002FA                                ;*** CPMUOSC - S12CPMU Oscillator Register; 0x000002FA ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CPMUOSC_OSCE:       equ    7                                         ; Oscillator Enable Bit
; bit position masks
mCPMUOSC_OSCE:      equ    %10000000


;*** CPMUPROT - S12CPMUV1 Protection Register; 0x000002FB ***
CPMUPROT:           equ    $000002FB                                ;*** CPMUPROT - S12CPMUV1 Protection Register; 0x000002FB ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CPMUPROT_PROT:      equ    0                                         ; Clock Configuration Registers Protection Bit
; bit position masks
mCPMUPROT_PROT:     equ    %00000001


;*** BAKEY0 - Backdoor Comparison Key 0; 0x0000FF00 ***
BAKEY0:             equ    $0000FF00                                ;*** BAKEY0 - Backdoor Comparison Key 0; 0x0000FF00 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
BAKEY0_KEY0:        equ    0                                         ; Backdoor Comparison Key Bits, bit 0
BAKEY0_KEY1:        equ    1                                         ; Backdoor Comparison Key Bits, bit 1
BAKEY0_KEY2:        equ    2                                         ; Backdoor Comparison Key Bits, bit 2
BAKEY0_KEY3:        equ    3                                         ; Backdoor Comparison Key Bits, bit 3
BAKEY0_KEY4:        equ    4                                         ; Backdoor Comparison Key Bits, bit 4
BAKEY0_KEY5:        equ    5                                         ; Backdoor Comparison Key Bits, bit 5
BAKEY0_KEY6:        equ    6                                         ; Backdoor Comparison Key Bits, bit 6
BAKEY0_KEY7:        equ    7                                         ; Backdoor Comparison Key Bits, bit 7
BAKEY0_KEY8:        equ    8                                         ; Backdoor Comparison Key Bits, bit 8
BAKEY0_KEY9:        equ    9                                         ; Backdoor Comparison Key Bits, bit 9
BAKEY0_KEY10:       equ    10                                        ; Backdoor Comparison Key Bits, bit 10
BAKEY0_KEY11:       equ    11                                        ; Backdoor Comparison Key Bits, bit 11
BAKEY0_KEY12:       equ    12                                        ; Backdoor Comparison Key Bits, bit 12
BAKEY0_KEY13:       equ    13                                        ; Backdoor Comparison Key Bits, bit 13
BAKEY0_KEY14:       equ    14                                        ; Backdoor Comparison Key Bits, bit 14
BAKEY0_KEY15:       equ    15                                        ; Backdoor Comparison Key Bits, bit 15
; bit position masks
mBAKEY0_KEY0:       equ    %00000001
mBAKEY0_KEY1:       equ    %00000010
mBAKEY0_KEY2:       equ    %00000100
mBAKEY0_KEY3:       equ    %00001000
mBAKEY0_KEY4:       equ    %00010000
mBAKEY0_KEY5:       equ    %00100000
mBAKEY0_KEY6:       equ    %01000000
mBAKEY0_KEY7:       equ    %10000000
mBAKEY0_KEY8:       equ    %100000000
mBAKEY0_KEY9:       equ    %1000000000
mBAKEY0_KEY10:      equ    %10000000000
mBAKEY0_KEY11:      equ    %100000000000
mBAKEY0_KEY12:      equ    %1000000000000
mBAKEY0_KEY13:      equ    %10000000000000
mBAKEY0_KEY14:      equ    %100000000000000
mBAKEY0_KEY15:      equ    %1000000000000000


;*** BAKEY1 - Backdoor Comparison Key 1; 0x0000FF02 ***
BAKEY1:             equ    $0000FF02                                ;*** BAKEY1 - Backdoor Comparison Key 1; 0x0000FF02 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
BAKEY1_KEY0:        equ    0                                         ; Backdoor Comparison Key Bits, bit 0
BAKEY1_KEY1:        equ    1                                         ; Backdoor Comparison Key Bits, bit 1
BAKEY1_KEY2:        equ    2                                         ; Backdoor Comparison Key Bits, bit 2
BAKEY1_KEY3:        equ    3                                         ; Backdoor Comparison Key Bits, bit 3
BAKEY1_KEY4:        equ    4                                         ; Backdoor Comparison Key Bits, bit 4
BAKEY1_KEY5:        equ    5                                         ; Backdoor Comparison Key Bits, bit 5
BAKEY1_KEY6:        equ    6                                         ; Backdoor Comparison Key Bits, bit 6
BAKEY1_KEY7:        equ    7                                         ; Backdoor Comparison Key Bits, bit 7
BAKEY1_KEY8:        equ    8                                         ; Backdoor Comparison Key Bits, bit 8
BAKEY1_KEY9:        equ    9                                         ; Backdoor Comparison Key Bits, bit 9
BAKEY1_KEY10:       equ    10                                        ; Backdoor Comparison Key Bits, bit 10
BAKEY1_KEY11:       equ    11                                        ; Backdoor Comparison Key Bits, bit 11
BAKEY1_KEY12:       equ    12                                        ; Backdoor Comparison Key Bits, bit 12
BAKEY1_KEY13:       equ    13                                        ; Backdoor Comparison Key Bits, bit 13
BAKEY1_KEY14:       equ    14                                        ; Backdoor Comparison Key Bits, bit 14
BAKEY1_KEY15:       equ    15                                        ; Backdoor Comparison Key Bits, bit 15
; bit position masks
mBAKEY1_KEY0:       equ    %00000001
mBAKEY1_KEY1:       equ    %00000010
mBAKEY1_KEY2:       equ    %00000100
mBAKEY1_KEY3:       equ    %00001000
mBAKEY1_KEY4:       equ    %00010000
mBAKEY1_KEY5:       equ    %00100000
mBAKEY1_KEY6:       equ    %01000000
mBAKEY1_KEY7:       equ    %10000000
mBAKEY1_KEY8:       equ    %100000000
mBAKEY1_KEY9:       equ    %1000000000
mBAKEY1_KEY10:      equ    %10000000000
mBAKEY1_KEY11:      equ    %100000000000
mBAKEY1_KEY12:      equ    %1000000000000
mBAKEY1_KEY13:      equ    %10000000000000
mBAKEY1_KEY14:      equ    %100000000000000
mBAKEY1_KEY15:      equ    %1000000000000000


;*** BAKEY2 - Backdoor Comparison Key 2; 0x0000FF04 ***
BAKEY2:             equ    $0000FF04                                ;*** BAKEY2 - Backdoor Comparison Key 2; 0x0000FF04 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
BAKEY2_KEY0:        equ    0                                         ; Backdoor Comparison Key Bits, bit 0
BAKEY2_KEY1:        equ    1                                         ; Backdoor Comparison Key Bits, bit 1
BAKEY2_KEY2:        equ    2                                         ; Backdoor Comparison Key Bits, bit 2
BAKEY2_KEY3:        equ    3                                         ; Backdoor Comparison Key Bits, bit 3
BAKEY2_KEY4:        equ    4                                         ; Backdoor Comparison Key Bits, bit 4
BAKEY2_KEY5:        equ    5                                         ; Backdoor Comparison Key Bits, bit 5
BAKEY2_KEY6:        equ    6                                         ; Backdoor Comparison Key Bits, bit 6
BAKEY2_KEY7:        equ    7                                         ; Backdoor Comparison Key Bits, bit 7
BAKEY2_KEY8:        equ    8                                         ; Backdoor Comparison Key Bits, bit 8
BAKEY2_KEY9:        equ    9                                         ; Backdoor Comparison Key Bits, bit 9
BAKEY2_KEY10:       equ    10                                        ; Backdoor Comparison Key Bits, bit 10
BAKEY2_KEY11:       equ    11                                        ; Backdoor Comparison Key Bits, bit 11
BAKEY2_KEY12:       equ    12                                        ; Backdoor Comparison Key Bits, bit 12
BAKEY2_KEY13:       equ    13                                        ; Backdoor Comparison Key Bits, bit 13
BAKEY2_KEY14:       equ    14                                        ; Backdoor Comparison Key Bits, bit 14
BAKEY2_KEY15:       equ    15                                        ; Backdoor Comparison Key Bits, bit 15
; bit position masks
mBAKEY2_KEY0:       equ    %00000001
mBAKEY2_KEY1:       equ    %00000010
mBAKEY2_KEY2:       equ    %00000100
mBAKEY2_KEY3:       equ    %00001000
mBAKEY2_KEY4:       equ    %00010000
mBAKEY2_KEY5:       equ    %00100000
mBAKEY2_KEY6:       equ    %01000000
mBAKEY2_KEY7:       equ    %10000000
mBAKEY2_KEY8:       equ    %100000000
mBAKEY2_KEY9:       equ    %1000000000
mBAKEY2_KEY10:      equ    %10000000000
mBAKEY2_KEY11:      equ    %100000000000
mBAKEY2_KEY12:      equ    %1000000000000
mBAKEY2_KEY13:      equ    %10000000000000
mBAKEY2_KEY14:      equ    %100000000000000
mBAKEY2_KEY15:      equ    %1000000000000000


;*** BAKEY3 - Backdoor Comparison Key 3; 0x0000FF06 ***
BAKEY3:             equ    $0000FF06                                ;*** BAKEY3 - Backdoor Comparison Key 3; 0x0000FF06 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
BAKEY3_KEY0:        equ    0                                         ; Backdoor Comparison Key Bits, bit 0
BAKEY3_KEY1:        equ    1                                         ; Backdoor Comparison Key Bits, bit 1
BAKEY3_KEY2:        equ    2                                         ; Backdoor Comparison Key Bits, bit 2
BAKEY3_KEY3:        equ    3                                         ; Backdoor Comparison Key Bits, bit 3
BAKEY3_KEY4:        equ    4                                         ; Backdoor Comparison Key Bits, bit 4
BAKEY3_KEY5:        equ    5                                         ; Backdoor Comparison Key Bits, bit 5
BAKEY3_KEY6:        equ    6                                         ; Backdoor Comparison Key Bits, bit 6
BAKEY3_KEY7:        equ    7                                         ; Backdoor Comparison Key Bits, bit 7
BAKEY3_KEY8:        equ    8                                         ; Backdoor Comparison Key Bits, bit 8
BAKEY3_KEY9:        equ    9                                         ; Backdoor Comparison Key Bits, bit 9
BAKEY3_KEY10:       equ    10                                        ; Backdoor Comparison Key Bits, bit 10
BAKEY3_KEY11:       equ    11                                        ; Backdoor Comparison Key Bits, bit 11
BAKEY3_KEY12:       equ    12                                        ; Backdoor Comparison Key Bits, bit 12
BAKEY3_KEY13:       equ    13                                        ; Backdoor Comparison Key Bits, bit 13
BAKEY3_KEY14:       equ    14                                        ; Backdoor Comparison Key Bits, bit 14
BAKEY3_KEY15:       equ    15                                        ; Backdoor Comparison Key Bits, bit 15
; bit position masks
mBAKEY3_KEY0:       equ    %00000001
mBAKEY3_KEY1:       equ    %00000010
mBAKEY3_KEY2:       equ    %00000100
mBAKEY3_KEY3:       equ    %00001000
mBAKEY3_KEY4:       equ    %00010000
mBAKEY3_KEY5:       equ    %00100000
mBAKEY3_KEY6:       equ    %01000000
mBAKEY3_KEY7:       equ    %10000000
mBAKEY3_KEY8:       equ    %100000000
mBAKEY3_KEY9:       equ    %1000000000
mBAKEY3_KEY10:      equ    %10000000000
mBAKEY3_KEY11:      equ    %100000000000
mBAKEY3_KEY12:      equ    %1000000000000
mBAKEY3_KEY13:      equ    %10000000000000
mBAKEY3_KEY14:      equ    %100000000000000
mBAKEY3_KEY15:      equ    %1000000000000000


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
NVDFPROT_DPOPEN:    equ    7                                         ; D-Flash Protection Control
; bit position masks
mNVDFPROT_DPS0:     equ    %00000001
mNVDFPROT_DPS1:     equ    %00000010
mNVDFPROT_DPS2:     equ    %00000100
mNVDFPROT_DPS3:     equ    %00001000
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



; **** 30.3.2011 10:50:14

HSSR_HS0OL:                              equ        HSSR_HSOL0
HSSR_HS1OL:                              equ        HSSR_HSOL1
mHSSR_HS0OL:                             equ        mHSSR_HSOL0
mHSSR_HS1OL:                             equ        mHSSR_HSOL1
HSIF_HS0OCIF:                            equ        HSIF_HSOCIF0
HSIF_HS1OCIF:                            equ        HSIF_HSOCIF1
mHSIF_HS0OCIF:                           equ        mHSIF_HSOCIF0
mHSIF_HS1OCIF:                           equ        mHSIF_HSOCIF1
LSSR_LS0OL:                              equ        LSSR_LSOL0
LSSR_LS1OL:                              equ        LSSR_LSOL1
mLSSR_LS0OL:                             equ        mLSSR_LSOL0
mLSSR_LS1OL:                             equ        mLSSR_LSOL1
LSIF_LS0OCIF:                            equ        LSIF_LSOCIF0
LSIF_LS1OCIF:                            equ        LSIF_LSOCIF1
mLSIF_LS0OCIF:                           equ        mLSIF_LSOCIF0
mLSIF_LS1OCIF:                           equ        mLSIF_LSOCIF1


; **** 30.6.2011 15:35:19

PTTRR:                                   equ        MODRR
PTTRR_PTTRR00:                           equ        MODRR_MODRR00
PTTRR_PTTRR01:                           equ        MODRR_MODRR01
PTTRR_PTTRR02:                           equ        MODRR_MODRR02
PTTRR_PTTRR03:                           equ        MODRR_MODRR03
PTTRR_PTTRR04:                           equ        MODRR_MODRR04
PTTRR_PTTRR05:                           equ        MODRR_MODRR05
PTTRR_PTTRR06:                           equ        MODRR_MODRR06
PTTRR_PTTRR07:                           equ        MODRR_MODRR07
PTTRR_PTTRR14:                           equ        MODRR_MODRR14
PTTRR_PTTRR15:                           equ        MODRR_MODRR15
mPTTRR_PTTRR00:                          equ        mMODRR_MODRR00
mPTTRR_PTTRR01:                          equ        mMODRR_MODRR01
mPTTRR_PTTRR02:                          equ        mMODRR_MODRR02
mPTTRR_PTTRR03:                          equ        mMODRR_MODRR03
mPTTRR_PTTRR04:                          equ        mMODRR_MODRR04
mPTTRR_PTTRR05:                          equ        mMODRR_MODRR05
mPTTRR_PTTRR06:                          equ        mMODRR_MODRR06
mPTTRR_PTTRR07:                          equ        mMODRR_MODRR07
mPTTRR_PTTRR14:                          equ        mMODRR_MODRR14
mPTTRR_PTTRR15:                          equ        mMODRR_MODRR15
PTTRR0:                                  equ        MODRR0
PTTRR0_PTTRR00:                          equ        MODRR0_MODRR00
PTTRR0_PTTRR01:                          equ        MODRR0_MODRR01
PTTRR0_PTTRR02:                          equ        MODRR0_MODRR02
PTTRR0_PTTRR03:                          equ        MODRR0_MODRR03
PTTRR0_PTTRR04:                          equ        MODRR0_MODRR04
PTTRR0_PTTRR05:                          equ        MODRR0_MODRR05
PTTRR0_PTTRR06:                          equ        MODRR0_MODRR06
PTTRR0_PTTRR07:                          equ        MODRR0_MODRR07
mPTTRR0_PTTRR00:                         equ        mMODRR0_MODRR00
mPTTRR0_PTTRR01:                         equ        mMODRR0_MODRR01
mPTTRR0_PTTRR02:                         equ        mMODRR0_MODRR02
mPTTRR0_PTTRR03:                         equ        mMODRR0_MODRR03
mPTTRR0_PTTRR04:                         equ        mMODRR0_MODRR04
mPTTRR0_PTTRR05:                         equ        mMODRR0_MODRR05
mPTTRR0_PTTRR06:                         equ        mMODRR0_MODRR06
mPTTRR0_PTTRR07:                         equ        mMODRR0_MODRR07
PTTRR1:                                  equ        MODRR1
PTTRR1_PTTRR14:                          equ        MODRR1_MODRR14
PTTRR1_PTTRR15:                          equ        MODRR1_MODRR15
mPTTRR1_PTTRR14:                         equ        mMODRR1_MODRR14
mPTTRR1_PTTRR15:                         equ        mMODRR1_MODRR15


; **** 11/8/2011 1:07:46 PM

PTSRR:                                   equ        MODRR2
PTSRR_PTSRR0:                            equ        MODRR2_MODRR20
PTSRR_PTSRR1:                            equ        MODRR2_MODRR21
PTSRR_PTSRR2:                            equ        MODRR2_MODRR22
PTSRR_PTSRR3:                            equ        MODRR2_MODRR23
PTSRR_PTSRR4:                            equ        MODRR2_MODRR24
PTSRR_PTSRR5:                            equ        MODRR2_MODRR25
PTSRR_PTSRR7:                            equ        MODRR2_MODRR27
mPTSRR_PTSRR0:                           equ        mMODRR2_MODRR20
mPTSRR_PTSRR1:                           equ        mMODRR2_MODRR21
mPTSRR_PTSRR2:                           equ        mMODRR2_MODRR22
mPTSRR_PTSRR3:                           equ        mMODRR2_MODRR23
mPTSRR_PTSRR4:                           equ        mMODRR2_MODRR24
mPTSRR_PTSRR5:                           equ        mMODRR2_MODRR25
mPTSRR_PTSRR7:                           equ        mMODRR2_MODRR27

; /* **** 20/12/2012  */
        IFNDEF __GENERATE_APPLICATION__
LPSLRSTR:                               equ         This_symb_has_been_depreciated
LPSLR_LPSLR:                            equ         This_symb_has_been_depreciated
LPSLR_LPSLRWD:                          equ         This_symb_has_been_depreciated
LPSLR_LPSLR_MASK:                       equ         This_symb_has_been_depreciated
LPSLR_LPSLR_BITNUM:                     equ         This_symb_has_been_depreciated
LPSLR_LPSLRWD_MASK:                     equ         This_symb_has_been_depreciated
LPSR_LPOC:                              equ         This_symb_has_been_depreciated
LPSR_LPOC_MASK                          equ         This_symb_has_been_depreciated
        ENDIF    

; EOF
