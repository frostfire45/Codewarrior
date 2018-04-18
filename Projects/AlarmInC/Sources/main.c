// Example 1a: Turn on every other segment on 7-seg display
#include <hidef.h>      /* common defines and macros */
#include <mc9s12dg256.h>     /* derivative information */
#pragma LINK_INFO DERIVATIVE "mc9s12dg256b"

#include "main_asm.h" /* interface to the assembly module */

void full_sec_delay(void); 
unsigned short ticks,ticks0;

void interrupt 16 handler(){
	EC_COUNTER();
	
} 

void main(void) {
  PLL_init();// set system clock frequency to 24 MHz
  RTI_init();
  lcd_init();
  ClockStart();
  for(;;){
  	 DisplayTime();
	}

}

void DisplayTime()
{
	int i = 0;
	int j = 0;
	char hour ;//= '0';
	char min ;//= '0'; 
	min = getMin();
	hour = getHour();	
    
  	set_lcd_addr(0x00);
    printfLCD();
  	set_lcd_addr(0x40);
  	
}
void full_sec_delay(){
 ticks0 = ticks;
 while((ticks-ticks0)<99){
  
 }
}