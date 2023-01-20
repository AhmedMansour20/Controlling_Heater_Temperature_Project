



#ifndef WDT_H_
#define WDT_H_

	//used data type
	typedef unsigned char uint8; //** take care at any loop from variable sign **
	typedef signed short uint16;
	typedef unsigned long uint32;
	

	//WDT registers
	#define  WDTCR_ *((volatile uint8 *)0x41)//Watchdog Timer Control Register –WDTCR ( $21 ($41) WDTCR )

	//used fnctions 
	void WDT_on();
	void WDT_off();





#endif /* WDT_H_ */