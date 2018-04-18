// Example 1a: Turn on every other segment on 7-seg display
#include <hidef.h>      /* common defines and macros */
#include <mc9s12dg256.h>     /* derivative information */
#pragma LINK_INFO DERIVATIVE "mc9s12dg256b"

#include "main_asm.h" /* interface to the assembly module */
void half_sec_delay(void);
unsigned short ticks,tick0;
int period;
int pwidth;
int i;
int bogit;
unsigned short ticks;
void interrupt 14 handler(){
 ptrain6(period,pwidth);
  
}
void interrupt 7 handler1(){
  if(bogit < 1000)
  {    
     if(ticks < 100)
     {  
        ticks++;
     } 
     else
     {    
        ticks = 0;
     }
  }
  else 
  {
    bogit = 0;
    if(PORTB != 0xFF)
    {
      led_on(0xFF);
    } 
    else 
    {
      led_off(0xFF); 
    }    
  } 
}

void main(void) {
  /* put your own code here */
  PLL_init();        // set system clock frequency to 24 MHz 
  i = 0;
  ptrain6_init();
  led_enable();
  sound_init();
  period = 5734;
  pwidth = 2867;
  while(1){
     
  }
}
  
//void half_sec_delay(){
   //tick0 = ticks;
   //while((ticks-tick0)> 49){
   //} 
   //led_off(i);
  //}
