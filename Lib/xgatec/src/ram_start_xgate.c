extern void main(void);

interrupt void _Startup(void); /* prototype in scope required for compliance with MISRA rule 8.1 REQ */

interrupt void _Startup(void) {
  main();
}  

/*lint -esym(754, pc) , struct Entry is used within this module */
/*lint -esym(754, dataptr) , struct Entry is used within this module */
typedef struct {
  void (*pc)(void);
  int dataptr;
} Entry;

const Entry vectors[0x80] = {
                  /* Channel # = Vector address / 2 */
  {_Startup, 0},  /* Channel 00 - Reserved */
  {_Startup, 0},  /* Channel 01 - Reserved */
  {_Startup, 0},  /* Channel 02 - Reserved */
  {_Startup, 0},  /* Channel 03 - Reserved */
  {_Startup, 0},  /* Channel 04 - Reserved */
  {_Startup, 0},  /* Channel 05 - Reserved */
  {_Startup, 0},  /* Channel 06 - Reserved */
  {_Startup, 0},  /* Channel 07 - Reserved */
  {_Startup, 0},  /* Channel 08 - Spurious Interrupt */
  {_Startup, 0},  /* Channel 09 - Reserved */
  {_Startup, 0},  /* Channel 0A - Reserved */
  {_Startup, 0},  /* Channel 0B - Reserved */
  {_Startup, 0},  /* Channel 0C - Reserved */
  {_Startup, 0},  /* Channel 0D - Reserved */
  {_Startup, 0},  /* Channel 0E - Reserved */
  {_Startup, 0},  /* Channel 0F - Reserved */
  {_Startup, 0},  /* Channel 10 - Reserved */
  {_Startup, 0},  /* Channel 11 - Reserved */
  {_Startup, 0},  /* Channel 12 - Reserved */
  {_Startup, 0},  /* Channel 13 - Reserved */
  {_Startup, 0},  /* Channel 14 - Reserved */
  {_Startup, 0},  /* Channel 15 - Reserved */
  {_Startup, 0},  /* Channel 16 - Reserved */
  {_Startup, 0},  /* Channel 17 - Reserved */
  {_Startup, 0},  /* Channel 18 - Reserved */
  {_Startup, 0},  /* Channel 19 - Reserved */
  {_Startup, 0},  /* Channel 1A - Reserved */
  {_Startup, 0},  /* Channel 1B - Reserved */
  {_Startup, 0},  /* Channel 1C - Reserved */
  {_Startup, 0},  /* Channel 1D - Reserved */
  {_Startup, 0},  /* Channel 1E - Reserved */
  {_Startup, 0},  /* Channel 1F - Reserved */
  {_Startup, 0},  /* Channel 20 - Reserved */
  {_Startup, 0},  /* Channel 21 - Reserved */
  {_Startup, 0},  /* Channel 22 - Reserved */
  {_Startup, 0},  /* Channel 23 - Reserved */
  {_Startup, 0},  /* Channel 24 - Reserved */
  {_Startup, 0},  /* Channel 25 - Reserved */
  {_Startup, 0},  /* Channel 26 - Reserved */
  {_Startup, 0},  /* Channel 27 - Reserved */
  {_Startup, 0},  /* Channel 28 - Reserved */
  {_Startup, 0},  /* Channel 29 - Reserved */
  {_Startup, 0},  /* Channel 2A - Reserved */
  {_Startup, 0},  /* Channel 2B - Reserved */
  {_Startup, 0},  /* Channel 2C - Reserved */
  {_Startup, 0},  /* Channel 2D - Reserved */
  {_Startup, 0},  /* Channel 2E - Reserved */
  {_Startup, 0},  /* Channel 2F - Reserved */
  {_Startup, 0},  /* Channel 30 - XSRAM20K Access Violation */
  {_Startup, 0},  /* Channel 31 - XGATE Software Error Interrupt      */
  {_Startup, 0},  /* Channel 32 - XGATE Software Trigger 7            */
  {_Startup, 0},  /* Channel 33 - XGATE Software Trigger 6            */
  {_Startup, 0},  /* Channel 34 - XGATE Software Trigger 5            */
  {_Startup, 0},  /* Channel 35 - XGATE Software Trigger 4            */
  {_Startup, 0},  /* Channel 36 - XGATE Software Trigger 3            */
  {_Startup, 0},  /* Channel 37 - XGATE Software Trigger 2            */
  {_Startup, 0},  /* Channel 38 - XGATE Software Trigger 1            */
  {_Startup, 0},  /* Channel 39 - XGATE Software Trigger 0            */
  {_Startup, 0},  /* Channel 3A - Periodic Interrupt Timer            */
  {_Startup, 0},  /* Channel 3B - Periodic Interrupt Timer            */
  {_Startup, 0},  /* Channel 3C - Periodic Interrupt Timer            */
  {_Startup, 0},  /* Channel 3D - Periodic Interrupt Timer            */
  {_Startup, 0},  /* Channel 3E - Reserved                            */
  {_Startup, 0},  /* Channel 3F - Autonomous Periodical interrupt API */
  {_Startup, 0},  /* Channel 40 - Low Voltage interrupt LVI */
  {_Startup, 0},  /* Channel 41 - IIC1 Bus                  */
  {_Startup, 0},  /* Channel 42 - SCI5                      */
  {_Startup, 0},  /* Channel 43 - SCI4                      */
  {_Startup, 0},  /* Channel 44 - SCI3                      */
  {_Startup, 0},  /* Channel 45 - SCI2                      */
  {_Startup, 0},  /* Channel 46 - PWM Emergency Shutdown    */
  {_Startup, 0},  /* Channel 47 - Port P Interrupt          */
  {_Startup, 0},  /* Channel 48 - CAN4 transmit             */
  {_Startup, 0},  /* Channel 49 - CAN4 receive              */
  {_Startup, 0},  /* Channel 4A - CAN4 errors               */
  {_Startup, 0},  /* Channel 4B - CAN4 wake-up              */
  {_Startup, 0},  /* Channel 4C - CAN3 transmit             */
  {_Startup, 0},  /* Channel 4D - CAN3 receive              */
  {_Startup, 0},  /* Channel 4E - CAN3 errors               */
  {_Startup, 0},  /* Channel 4F - CAN3 wake-up              */
  {_Startup, 0},  /* Channel 50 - CAN2 transmit */
  {_Startup, 0},  /* Channel 51 - CAN2 receive  */
  {_Startup, 0},  /* Channel 52 - CAN2 errors   */
  {_Startup, 0},  /* Channel 53 - CAN2 wake-up  */
  {_Startup, 0},  /* Channel 54 - CAN1 transmit */
  {_Startup, 0},  /* Channel 55 - CAN1 receive  */
  {_Startup, 0},  /* Channel 56 - CAN1 errors   */
  {_Startup, 0},  /* Channel 57 - CAN1 wake-up  */
  {_Startup, 0},  /* Channel 58 - CAN0 transmit */
  {_Startup, 0},  /* Channel 59 - CAN0 receive  */
  {_Startup, 0},  /* Channel 5A - CAN0 errors   */
  {_Startup, 0},  /* Channel 5B - CAN0 wake-up  */
  {_Startup, 0},  /* Channel 5C - FLASH  */
  {_Startup, 0},  /* Channel 5D - EEPROM */
  {_Startup, 0},  /* Channel 5E - SPI2   */
  {_Startup, 0},  /* Channel 5F - SPI1 */
  {_Startup, 0},  /* Channel 60 - IIC0 Bus                          */
  {_Startup, 0},  /* Channel 61 - Reserved                          */
  {_Startup, 0},  /* Channel 62 - CRG Self Clock Mode               */
  {_Startup, 0},  /* Channel 63 - CRG PLL lock                      */
  {_Startup, 0},  /* Channel 64 - Pulse Accumulator B Overflow      */
  {_Startup, 0},  /* Channel 65 - Modulus Down Counter underflow    */
  {_Startup, 0},  /* Channel 66 - Port H                            */
  {_Startup, 0},  /* Channel 67 - Port J                            */
  {_Startup, 0},  /* Channel 68 - ATD1                              */
  {_Startup, 0},  /* Channel 69 - ATD0                              */
  {_Startup, 0},  /* Channel 6A - SCI1                              */
  {_Startup, 0},  /* Channel 6B - SCI0                              */
  {_Startup, 0},  /* Channel 6C - SPI0                              */
  {_Startup, 0},  /* Channel 6D - Pulse accumulator input edge      */
  {_Startup, 0},  /* Channel 6E - Pulse accumulator A overflow      */
  {_Startup, 0},  /* Channel 6F - Enhanced Capture Timer overflow   */
  {_Startup, 0},  /* Channel 70 - Enhanced Capture Timer channel 7  */
  {_Startup, 0},  /* Channel 71 - Enhanced Capture Timer channel 6  */
  {_Startup, 0},  /* Channel 72 - Enhanced Capture Timer channel 5  */
  {_Startup, 0},  /* Channel 73 - Enhanced Capture Timer channel 4  */
  {_Startup, 0},  /* Channel 74 - Enhanced Capture Timer channel 3  */
  {_Startup, 0},  /* Channel 75 - Enhanced Capture Timer channel 2  */
  {_Startup, 0},  /* Channel 76 - Enhanced Capture Timer channel 1  */
  {_Startup, 0},  /* Channel 77 - Enhanced Capture Timer channel 0  */
  {_Startup, 0},  /* Channel 78 - Real Time Interrupt  */
  {_Startup, 0},  /* Channel 79 - Reserved */
  {_Startup, 0},  /* Channel 7A - Reserved */
  {_Startup, 0},  /* Channel 7B - Reserved */
  {_Startup, 0},  /* Channel 7C - Reserved */
  {_Startup, 0},  /* Channel 7D - Reserved */
  {_Startup, 0},  /* Channel 7E - Reserved */
  {_Startup, 0},  /* Channel 7F - Reserved   */
};
