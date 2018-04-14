// Example 1a: Turn on every other segment on 7-seg display
#include <hidef.h>      /* common defines and macros */
#include <mc9s12dg256.h>     /* derivative information */
#pragma LINK_INFO DERIVATIVE "mc9s12dg256b"

#include "main_asm.h" /* interface to the assembly module */ 

void interrupt 16 time_hndl(){
	EC_COUNTER();
}
void main(void) { 
  PLL_init();// set system clock frequency to 24 MHz
  lcd_init();;
  for(;;){    
  	DisplayTime();   
	}
	
}

void DisplayTime()
{ 	
	int i;
	int j;
	int min = getMin();
	int hour = getHour();
	char* Day = getDay();   
  	set_lcd_addr(0x00);  	

  	set_lcd_addr(0x40);
  	for(i = 0;i < 16;i++){
  		
  		j = BLINE[i];
  		//data8(j);  		
  	}
}
void FullSec_Delay(void){
		
}