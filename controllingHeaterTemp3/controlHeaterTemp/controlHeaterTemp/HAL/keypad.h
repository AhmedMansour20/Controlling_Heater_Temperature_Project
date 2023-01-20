 

#ifndef KEPAD_H_
#define KEPAD_H_
 
	//used data type
	typedef unsigned char uint8; //** take care at any loop from variable sign **
	typedef signed  short uint16;
	typedef unsigned long uint32;
 
    // used functions
    void keypad_init(void);
    uint8 key_value(void);

	//keypad general settings
	#define PRTN PRTC //determine port name
	#define DDIRCN DDIRCC //determine port name
	#define PINN PINCREG //read register bits
	#define DELAY 1 //delay for ignore denouncing

	
 
 
#endif  