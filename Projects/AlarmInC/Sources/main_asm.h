#ifndef _MAIN_ASM_H
#define _MAIN_ASM_H

#ifdef __cplusplus
    extern "C" { /* our assembly functions have C calling convention */
#endif
  //char* TOPLINE;
char TLINE[17] = 
	{ "    00:00 AM    " };
	// 012345678901234
char BLINE[17] = 
	{ "Mon  Alarm: Off "};
void ClockStart(void);
void printfLCD(void);	
char getHour(void);
char	getMin(void);
char* getDay(void);
void EC_COUNTER(void);  
void compTime(int hour,int min,int tDay);
void asm_main(void);
void PLL_init(void);
void ms_delay(int);
void  instr8(char);
void  data8(char);
void  intToChar(int);
void  lcd_init(void);
void  clear_lcd(void);
void  hex2lcd(char);
char  hex2asc(char);
void  type_lcd(char*);
void  write_int_lcd(int);        
void  set_lcd_addr(char);
long  number(char*);
void  ad0_enable(void);
int   ad0conv(char);
void  ad1_enable(void);
int   ad1conv(char);
void  RTI_init(void);
void  clear_RTI_flag(void);
void  RTI_disable(void);
void  ptrain6_init(void);
void  ptrain6(int,int);
void  sound_init(void);
void  sound_on(void);
void  sound_off(void);
void  tone(int);
void  HILO1_init(void);
void  HILOtimes1(void);
int   get_HI_time1(void);
int   get_LO_time1(void);
void DisplayTime(void);
void FullSec_Delay(void);

#ifdef __cplusplus
    }
#endif

#endif /* _MAIN_ASM_H */
