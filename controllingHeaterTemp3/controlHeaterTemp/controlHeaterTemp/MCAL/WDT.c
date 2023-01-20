 #include "WDT.h"
 #include "configure.h"
 
 
 
 
 
 void WDT_on(){ // WDT activation
	 SET(WDTCR_,3);// Bit 3 – WDE: Watchdog Enable -->When the WDE is written to logic one, the Watchdog Timer is enabled
	 CLR(WDTCR_,0);SET(WDTCR_,1);CLR(WDTCR_,2);// Bits [2:0] – WDP2, WDP1, WDP0: Watchdog Timer Prescaler 2, 1, and 65 ms
}



 void WDT_off(){ // WDT disable
	 
	  SET(WDTCR_,3);SET(WDTCR_,4);//set WDTOE & WDE in same step
	  CLR(WDTCR_,3);// clear WDE in WDTCR register
	 
 }