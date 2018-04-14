;**************************************************************
;* LBE_Dragon12_Plus_Rev4                                     *
;* Assembly language routines for C function calls            *
;* Learning By Example Using C                                *
;* -- Programming the Dragon12-Plus Using CodeWarrior         *
;* by Richard E. Haskell                                      *
;* Copyright 2008                                             *
;**************************************************************


; export symbols
            XDEF MemMerge
            XDEF asm_main, PLL_init;               
            XDEF ms_delay            
            XDEF data8,intToChar,lcd_init,clear_lcd, set_lcd_addr
            XDEF hex2lcd,hex2asc
            XDEF type_lcd, write_int_lcd    
            
            XDEF number 
            XDEF ad0_enable, ad0conv, ad1_enable, ad1conv          
            XDEF RTI_init, clear_RTI_flag, RTI_disable            
            XDEF ptrain6_init, ptrain6
            XDEF sound_init, sound_on, sound_off, tone
            XDEF HILO1_init, HILOtimes1
            XDEF get_HI_time1, get_LO_time1
            XDEF tHour,tSec,getHour,getMin,getDay
            XDEF EC_COUNTER


; include derivative specific macros
            INCLUDE 'mc9s12dg256.inc'

; variable/data section
MY_EXTENDED_RAM: SECTION
ONE_MS:		equ	4000	; 4000 x 250ns = 1 ms at 24 MHz bus speed
FIVE_MS:	equ	20000
TEN_MS:		equ	40000
FIFTY_US:	equ	200
DB2		    equ     4       ; 00000100
DB3:		  equ	8       ; 00001000
REG_SEL:	equ	DB3	; 0=reg, 1=data
NOT_REG_SEL:	equ	$F7     ; 11110111
ENABLE:		equ     DB2
NOT_ENABLE: 	equ     $FB     ; 11111011
LCD:		  equ	PTM
LCD_RS:		equ	PTM
LCD_EN:		equ	PTM
REGBLK:		equ	$0
bas10:    	equ	10

temp:     	rmb 1
pmimg:		rmb	1
temp1:		rmb	1
bas:      	rmb 2
dnum:	    rmb	2
buff:	    rmb	12
pad:	    rmb	1
TC1old:   	rmb 2
LO_time1  	rmb 2
HI_time1  	rmb 2
LCDimg:		equ	pmimg
LCD_RSimg:	equ	pmimg
LCD_ENimg:	equ	pmimg
BOTLINE:      rmb       16
BOTSPACE:   RMB     3
MCount:     RMB     2
MemLoc:     RMB     2
MemLoc_1    RMB     2
MemLoc_2    RMB      2
NumInMem_1  RMB     2
NumInMem_2  RMB     2
tDay:		RMB		3
clkMax:		equ		$3C
tSec:		RMB		2

; code section
MyCode:     SECTION

TopMSG:		FCC		"     "
tHour:		DC.B	"00"		
Colon:		DC.B	':'
tMin:		DC.B	"00"
DayC:		DC.B	" AM"
			DC.B	0
MS_TICK:	DC.B	" "
PM:			DC.B	" PM"
			DC.B	0
AM:			DC.B	" AM"
			DC.B	0
;**********************************
Day:		DC.B	$0
D0:			DC.B	"Mon " ; 
			DC.B	0
D1			DC.B	"Tue " ; 
			DC.B	0
D2			DC.B	"Wen " ; 
			DC.B	0
D3			DC.B	"Thu " ; day3
			DC.B	0
D4			DC.B	"Fri " ; day4
			DC.B	0
D5			DC.B	"Sat " ; day5
			DC.B	0
D6			DC.B	"Sun " ; day6
			DC.B	0
;**********************************			
ClockStart:	MOVB	#$00,tSec
			MOVB	#$87,TSCR2
			MOVB	#$80,TSCR1
			CLI
			RTS
;**********************************			
EC_COUNTER: LDAA	MS_TICK
			CMPA	$03
			BEQ		MS_RESET
			ADDA	#1
			STAA	MS_TICK
			RTI
						
MS_RESET:	LDAB	tSec
			CMPB	#60
			BEQ		MS_S_RST
			ADDB	#1
			STAB	tSec
			RTI
			
MS_S_RST:	LDAB	#$00
			STAB	tSec
			STAB	MS_TICK
			LDAB	tMin
			ADDB	#1
			CMPB	#60
			BEQ		MS_M_RST
			STAB	tMin
			RTI

MS_M_RST:	LDAB	#$00
			STAB	tMin
			LDAB	tHour
			ADDB	#1
			CMPB	#60
			BEQ		MS_H_RST
			STAB	tHour
			RTI
			
MS_H_RST:   LDAB	#$00
			STAB	tHour
			LDAB	tDay
			ADDB	#1
			CMPB	#7
			BEQ		MS_D_RST
			STAB	tDay
			RTI

MS_D_RST:   LDAB	#$00
			STAB	tDay
			RTI
;***********************************
getHour:	LDD		tHour
			RTS
getMin:		LDD		tMin
			RTS
getDay:		LDAB	tHour
			CMPB	12
			BLO		setMorn
			LDX		#PM
			RTS
setMorn:	LDX		#AM
			RTS

										
MemMerge:          ;input (char*, int, char*,int)  -> char* in D; int -> 2,SP, char* - > 4,SP, int ->6,SP  
            LEAS    -20,SP
            STS    	MemLoc
            TFR     D,X                                           
                                
            LDAA   	23,SP
            STAA  	MCount
MemM1:      LDAB  	1,X+
            PSHB
            DBNE   	A,MemM1
                                
            LDX     24,SP
            LDAA  	27,SP
            PSHA
            LDAB    MCount
            ABA
            STAA    MCount
            PULA
MemM2:      LDAB  	1,X+
            PSHB
            DBNE 	A,MemM2
            LDD    	#MCount
            LDX    	#MemLoc
            LDY    	#MemLoc
            LEAS  	0, X  
            RTS
;***************************************
;ByteArray:	L			
;	        TFR		D,X
	                               
;DispTime:	LDX		#TOPLINE
;			LDY		#TopMSG
;			MOVB	1,Y+,1,X+
;			JSR		type_lcd
;			RTS			

;IncTime:	
			
			;LDX		#TopMSG
			;JSR		type_lcd		
;  			RTS
asm_main:

PLL_init:
          movb    #$02,SYNR         ;PLLOSC = 48 MHz
          movb    #$00,REFDV
          clr     CLKSEL
          movb    #$F1,PLLCTL
pll1:     brclr   CRGFLG,#$08,pll1  ;wait for PLL to lock
          movb    #$80,CLKSEL       ;select PLLCLK
          rts
            
;       ms_delay                              
;       input: D = no. of milliseconds to delay
;       clock = 24 MHz
ms_delay:
          pshx
          pshy
          tfr     D,Y
md1:      ldx     #5999   ; N = (24000 - 5)/4
md2:      dex             ; 1 ccycle
          bne     md2     ; 3 ccycle
          dey             
          bne     md1     ; Y ms
          puly
          pulx
          rts

lcd_init:
	      ldaa	#$ff
	      staa	DDRK		              ; port K = output
       	ldx	  #init_codes 	        ; point to init. codes.
	      pshb            	          ; output instruction command.
       	ldab   	1,x+                ; no. of codes
lcdi1:	ldaa   	1,x+                ; get next code
       	jsr    	write_instr_nibble 	; initiate write pulse.
       	pshd
       	ldd     #5
       	jsr     ms_delay		;delay 5 ms
       	puld
       	decb                    ; in reset sequence to simplify coding
       	bne    	lcdi1
       	pulb
       	rts

; Initialization codes for 4-bit mode      	
; uses only data in high nibble
init_codes: 
        fcb	12		; number of high nibbles
	      fcb	$30		; 1st reset code, must delay 4.1ms after sending
        fcb	$30		; 2nd reste code, must delay 100us after sending
        ;  following 10 nibbles must  delay 40us each after sending
	      fcb $30   ; 3rd reset code,
	      fcb	$20		; 4th reste code,
        fcb	$20   ; 4 bit mode, 2 line, 5X7 dot
	      fcb	$80   ; 4 bit mode, 2 line, 5X7 dot
        fcb	$00		; cursor increment, disable display shift
	      fcb	$60		; cursor increment, disable display shift
        fcb	$00		; display on, cursor off, no blinking
	      fcb	$C0		; display on, cursor off, no blinking
	      fcb	$00		; clear display memory, set cursor to home pos
	      fcb	$10		; clear display memory, set cursor to home pos

; write instruction upper nibble
write_instr_nibble:
        anda    #$F0
        lsra
        lsra            ; nibble in PK2-PK5
        oraa    #$02    ; E = 1 in PK1; RS = 0 in PK0
        staa    PORTK
        ldy     #10
win     dey
        bne     win
        anda    #$FC    ; E = 0 in PK1; RS = 0 in PK0
        staa    PORTK
        rts

; write data upper nibble
write_data_nibble:
        anda    #$F0
        lsra
        lsra            ; nibble in PK2-PK5
        oraa    #$03    ; E = 1 in PK1; RS = 1 in PK0
        staa    PORTK
        ldy     #10
wdn     dey
        bne     wdn
        anda    #$FD    ; E = 0 in PK1; RS = 1 in PK0
        staa    PORTK
        rts

; write instruction byte
write_instr_byte:
        psha
        jsr     write_instr_nibble
        pula
        asla
        asla
        asla
        asla
        jsr     write_instr_nibble
        rts

;write data byte
write_data_byte:
        psha
        jsr     write_data_nibble
        pula
        asla
        asla
        asla
        asla
        jsr     write_data_nibble
        rts
        
;   write instruction byte B to LCD
instr8:
            tba
;            jsr   sel_inst
            jsr   write_instr_byte
            ldd     #10
            jsr     ms_delay
            rts

;   write data byte B to LCD
data8:
            tba
;            jsr   sel_data
            jsr   write_data_byte
            ldd     #10
            jsr     ms_delay
            rts
            
intToChar:  ;tba
            cpd     #$000F
            blo     singInt
            ldx     #$0A      ; Value 10
            idiv                   ; 
            xgdx
            addb    #$30
            tba
            pshx
            jsr     write_data_byte
            ldd     #10
            jsr     ms_delay
            pulx
            xgdx
            clra
singInt:    addb    #$30
            tba
            jsr     write_data_byte
            ldd     #10
            jsr     ms_delay
            rts

;   set address to B
set_lcd_addr:
            orab    #$80
            tba
            jsr     write_instr_byte
            ldd     #10
            jsr     ms_delay
            rts

;   clear LCD
clear_lcd:
            ldaa    #$01
            jsr     write_instr_byte
            ldd     #10
            jsr     ms_delay
            rts
                                    
;	display hex value in B on LCD 
hex2lcd:  
	          bsr	hex2asc		  ;convert to ascii
	          jsr	data8		    ;display it
	          rts

;       Hex to ascii subroutine
;       input: B = hex value
;       output: B = ascii value of lower nibble of input
hex2asc:
     	      andb    #$0f    	;mask upper nibble
            cmpb    #$9     	;if B > 9
            bls     ha1     
          	addb    #$37    	; add $37
           	rts             	  ;else
ha1     	  addb    #$30    	; add $30
            rts

;	display asciiz string on LCD
;	D -> asciiz string 
type_lcd:
            pshx              ;save X
            tfr     D,X       ;X -> asciiz string
next_char   ldaa	  1,X+		  ;get next char
	        beq	    done		  ;if null, quit
	        jsr	    write_data_byte	;else display it
            ldd     #10
            jsr     ms_delay
	        bra	    next_char	;and repeat
done	    pulx              ;restore X
            rts

;   write an integer to the LCD display
;   write_int_lcd(int);
write_int_lcd:
            pshd              ;save D
            bsr     blank_pad ;fill pad with blanks
            puld              ;get D
            std     dnum+2
            clr     dnum
            clr     dnum+1
            ldx     #pad
            jsr     sharps
            ldx     #pad-5 
wl1	        ldab	  1,x+
	          jsr	    data8		;display the ascii string
	          cpx	    #pad
	          blo	    wl1
	          rts


;   blank pad
blank_pad:
            ldx     #buff
            ldab    #13
            ldaa    #$20    ;ascii blank
bp1:        staa    1,x+
            decb
            bne     bp1
            rts            
                                                                     

;	double division  32 / 16 = 32  16 rem
;	numH:numL / denom = quotH:qoutL  remL
;	Y:D / X = Y:D  rem X
;	use EDIV twice  Y:D / X = Y   rem D
ddiv:
	          pshd		        ;save numL
	          tfr	  y,d	      ;d = numH
	          ldy	  #0	      ;0:numH / denom
	          ediv		        ;y = quotH, d = remH
	          bcc	  dd1	      ;if div by 0
	          puld	
	          ldd	  #$FFFF	  ;quot = $FFFFFFFF
	          tfr	  d,y
	          tfr	  d,x	      ;rem = $FFFF
	          rts
dd1	        sty	  2,-sp	    ;save quotH on stack
	          tfr	  d,y	      ;y = remH
	          ldd	  2,sp	    ;d = numL
	          ediv		        ;remH:numL/denom  Y = quotL  D = remL
	          tfr	  d,x	      ;x = remL
	          tfr	  y,d	      ;d = quotL
	          puly		        ;y = quotH
	          leas	2,sp	    ;fix stack
	          rts

;   Binary number to ASCII string conversion
;	  x -> ascii buffer
sharp:
	          pshd			      ;save regs
	          pshy			      
	          pshx			      ;save ptr
	          ldy	  dnum
	          ldd	  dnum+2
	          ldx	  #bas10
	          jsr	  ddiv		  ;dnum/base rem in X
	          sty	  dnum		  ; => dnum
	          std	  dnum+2
	          tfr	  x,d		    ;b = rem
	          cmpb	#9		    ;if rem > 9
	          bls	  shp1
	          addb	#7		    ; add 7
shp1	      addb	#$30		  ;conv to ascii
	          pulx			      ;restore ptr
	          stab	1,-x		  ;store digit
	          puly			      ;restore regs
	          puld
	          rts

;	input: x -> pad (ascii buffer)
;	output: x -> first char in ascii string
sharps:
	          bsr	  sharp		  ;do next digit
	          ldd	  dnum		  ;repeat until
          	bne	  sharps		; quot = 0
	          ldd	  dnum+2
	          bne	  sharps
	          rts


;	input: A = ascii code of char
;	output: if carry=0 A=valid hex value of char
;	        if carry=1 A=invalid char in current base
digit:
	          pshb
	          psha
	          suba	#$30		  ;ascii codes < 30
	          blo	  dgt2		  ; are invalid
	          cmpa	#9		    ;char between
	          bls	  dgt1		  ; 9 and A
	          cmpa	#17		    ; are invalid
	          blo	  dgt2		  ;fill gap
	          suba	#7		    ; between 9&A
dgt1	      cmpa	bas+1		;digit must be
	          bhs	  dgt2		  ; < base
	          andcc	#$FE		  ;clear carry (valid)
	          pulb			      ;pop old A
          	pulb			      ;restore B
	          rts
dgt2	      pula			      ;restore A
	          pulb			      ;restore B
	          orcc	#$01		  ;set carry (invalid)
	          rts
      
;	input:  D -> ascii number string buffer
; output: X:D is long int number
number:
	          pshy
	          tfr   d,y       ;y -> kbuf
	          ldd   #bas10
	          std   bas       ;base = 10
	          ldx	  #bas	    ;x -> base
	          ldd	  #0
	          std	  2,x	      ;clear dnum
	          std	  4,x
num1	      ldaa	1,y+	    ;get next digit
	          jsr	  digit	    ;conv to value
	          bcs	  num2
	          jsr	  dumul	    ;mult dnum by base
	          adda	5,x	      ;add digit value
	          staa	5,x
	          ldaa	4,x
	          adca	#0
	          staa	4,x
	          ldaa	3,x
	          adca	#0
          	staa	3,x
	          ldaa	2,x
	          adca	#0
	          staa	2,x
	          bra	  num1	    ;do until invalid digit
num2	      ldx   dnum      
            ldd   dnum+2    ; X:D = dnum
            puly
    	      rts
      
;	32 x 16 = 32 unsigned multiply
;	A:B x C = pH:pL
;	A x C = ACH:ACL  (drop ACH)
;	B x C = BCH:BCL
;	pL= BCL
;	pH = ALC + BCH
; C	rmb	2
; A	rmb	2
; B	rmb	2

dumul:
            psha            ;save A
            pshy						;save Y
	          ldd	  0,x		    ;D = C
	          ldy	  2,x		    ;Y = A
	          emul			      ;Y = ACH, D = ACL
	          std	  2,x		    ;save ACL
	          ldd	  0,x		    ;D = C
	          ldy	  4,x		    ;Y = B
	          emul			      ;Y = BCH, D = BCL
	          std	  4,x		    ;save pL = BCL
	          tfr	  y,d		    ;D = BCH
	          addd	2,x		    ;D = BCH+ACL = pH
	          std	  2,x		    ;save pH
	          puly            ;restore Y
	          pula						;restore A
	          rts
      
; A/D converter PADD0-PADD7
;   ad0_enable();
ad0_enable:
	          ldaa	#$0B		    ;10-bit resolution  /24 clock
	          staa	ATD0CTL4
	          ldaa	#$c0		    ;set ADPU & AFFC
	          staa	ATD0CTL2
	          rts
      
;   int adconv(char ch#)
ad0conv:
	          andb	#$07		    ;ch. 0 - 7 
          	orab	#$80		    ;right just  SCAN=0  MULT=0
	          stab	ATD0CTL5 
ad01	      ldaa	ATD0STAT0	  ;wait for conv
	          anda	#$80
	          beq 	ad01
	          bsr	  avg40
	          rts
            
avg40:
	          pshx			        ;save reg
	          ldx	  #ATD0DR0H
	          ldd	  2,x+		    ;adr0
	          addd	2,x+		    ;+adr1
	          addd	2,x+		    ;+adr2
	          addd	2,x+		    ;+adr3
	          lsrd
	          lsrd			        ;divide by 4
	          pulx			        ;restore reg
	          rts

; A/D converter PAD8-PAD15
;   ad1_enable();
ad1_enable:
	          ldaa	#$0B		    ;10-bit resolution  /24 clock
	          staa	ATD1CTL4
	          ldaa	#$c0		    ;set ADPU & AFFC
	          staa	ATD1CTL2
	          rts
      
;   int adconv(char ch#)
ad1conv:
	          andb	#$07		    ;ch. 0 - 7 
          	orab	#$80		    ;right just  SCAN=0  MULT=0
	          stab	ATD1CTL5 
ad11	      ldaa	ATD1STAT0	  ;wait for conv
	          anda	#$80
	          beq 	ad11
	          bsr	  avg41
	          rts
            
avg41:
	          pshx			        ;save reg
	          ldx	  #ATD1DR0H
	          ldd	  2,x+		    ;adr0
	          addd	2,x+		    ;+adr1
	          addd	2,x+		    ;+adr2
	          addd	2,x+		    ;+adr3
	          lsrd
	          lsrd			        ;divide by 4
	          pulx			        ;restore reg
	          rts


            
;   Real-time interrupt
;   RTI_init();
RTI_init:
  	        sei			          ;disable interrupts
		        ldaa	#$54
		        staa	RTICTL	    ;set rti to 10.24 ms
		        ldaa	#$80
		        staa	CRGINT	    ;enable rti
		        cli			          ;enable interrupts
		        rts

;   clear_RTI_flag();
clear_RTI_flag:
		        ldaa	#$80
		        staa	CRGFLG	    ;clear rti flag
		        rts

;   disable RTI
;   RTI_disable():
RTI_disable:
            clr   CRGINT      ;disable rti
            rts
                        


;  ptrain6_init()
ptrain6_init:
            movb  #$FF,DDRT   ;outputs
            movb  #$C0,TIOS   ;select output compares 6 & 7
            movb  #$04,TSCR2  ;div by 16: 24MHz/16 = 1.5 MHz
            movb  #$80,TSCR1  ;enable timer
            ldd   TCNT
            std   TC6 
            std   TC7					;init cnt in TC6 & TC7
            bset  OC7M,#$40   ;pulse train out PT6
            bset  OC7D,#$40   ;PT6 goes high on TC7 match
            bset  TCTL1,#$20  ;PT6 low on TC6  match
            bclr  TCTL1,#$10
            bset  TIE,#$40    ;enable TC6 interrupts
            cli               ;enable interrupts
            rts
;  ptrain01_64_init()
               ;enable interrupts
              
; void ptrain(int period, int pwidth);
; pwidth is in D
; period is at 2,sp
; return address is at 0,sp
ptrain6:
            pshd              ;save pwidth
            ldd   4,sp        ;D = period
            addd  TC7
            std   TC7         ;TC7new =TC7old + period
            addd  0,sp        ;add pwidth 
            std   TC6         ;TC6new =TC7new + pwidth
            puld              ;restore D
            movb  #$C0,TFLG1  ;clear both C7F and C6F
            rts
            
;  sound_init()
sound_init:
            movb  #$A0,TIOS   ;select output compares 5 & 7
            movb  #$04,TSCR2  ;div by 16: 24MHz/16 = 1.5 MHz
            movb  #$80,TSCR1  ;enable timer
            ldd   TCNT
            std   TC5 
            std   TC7					;init cnt in TC5 & TC7
            bset  OC7M,#$20   ;pulse train out PT5
            bset  OC7D,#$20   ;PT5 goes high on TC7 match
            bset  TCTL1,#$08  ;PT5 low on TC5  match
            bclr  TCTL1,#$04
            rts

;  sound_on()
sound_on:
            movb  #$80,TSCR1  ;enable timer
            bset  TIE,#$20    ;enable TC5 interrupts
            cli               ;enable interrupts
            rts

;  sound_off()
sound_off:
            sei
            clr   TSCR1       ;disable timer
            bclr  TIE,#$20    ;disable TC5 interrupts
            rts
            
; void tone(int pitch);
; pitch is in D
tone:
            pshd              ;save pitch
            addd  TC5
            std   TC7         ;TC7new =TC6old + pitch
            puld              ;get pitch
            addd  TC7         ;add pitch 
            std   TC5         ;TC6new =TC7new + pitch
            movb  #$A0,TFLG1  ;clear both C7F and C5F
            rts
            
; calc HI-LO times of pulse train on Ch 1 
;   and store results in HI_time1 and LO_time1            
; void HILO1_init(void);
HILO1_init:
            bclr  TIOS,#$02   ;select input capture 1
            movb  #$04,TSCR2  ;div by 16: 24MHz/16 = 1.5 MHz
            movb  #$80,TSCR1  ;enable timer
            ldd   TCNT
            std   TC1 				;init cnt in TC1
            bset  TCTL4,#$0C  ;interrupt on both edges of Ch 1
						movb  #$02,TFLG1  ;clear any old flag on Ch 1
            bset  TIE,#$02    ;enable TC1 interrupts
            cli               ;enable interrupts
						rts

; calc HI-LO times of pulse train on Ch 1 
;   and store results in HI_time1 and LO_time1            
; void getHILOtimes1(void);
HILOtimes1:
						brclr PTT,$02,HL1 ;if PTT1 is hi, rising edge
						ldd   TC1
						pshd              ;save TC1
						subd  TC1old      ;LO_time'
            std   LO_time1;   ;store LO_time1
            puld              ;get TC1
            std   TC1old;     ;TC1old = TC1
            bra   HL2
HL1:        ldd   TC1					;else, falling edge
						pshd              ;save TC1
						subd  TC1old      ;HI_time'
            std   HI_time1;   ;save HI_time1
            puld              ;get TC1
            std   TC1old;     ;TC1old = TC1
HL2:        bset  TFLG1, #$02 ;clear int flag            
            rts

; int get_HI_time1(void);
get_HI_time1:
            ldd   HI_time1
            rts
     
; int get_LO_time1(void);
get_LO_time1:
            ldd   LO_time1
            rts
            

                          
                        
            					