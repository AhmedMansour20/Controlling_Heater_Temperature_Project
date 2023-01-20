


#ifndef CONFIGURE_H_
#define CONFIGURE_H_
    
	
	//used data type
	typedef unsigned char uint8; //** take care at any loop from variable sign **
	typedef signed short uint16;
	typedef unsigned long uint32;
	
	// IDE libiraries
	#define F_CPU 8000000UL
	#include <util/delay.h>
	#include <avr/interrupt.h>

 
	// macros for dealing with registeRS3
	#define SET(REGNAME,BITNUM)  (REGNAME |=   (1 << BITNUM))
	#define CLR(REGNAME,BITNUM)  (REGNAME &=  ~(1 << BITNUM))
	#define TGGL(REGNAME,BITNUM) (REGNAME ^=  (1 << BITNUM))
	#define RED(REGNAME,BITNUM)  ((REGNAME >> BITNUM) & (1<<0))

    // I/O  registerS
	#define PRTB    *((volatile uint8 *)0x38) //($38) PORTB
	#define DDIRCB  *((volatile uint8 *)0x37) //$17 ($37) DDRB
	#define PRTC    *((volatile uint8 *)0x35)//$15 ($35) PORTC
	#define PRTD    *((volatile uint8 *)0x32) //($32) PORTD
	#define DDIRCC  *((volatile uint8 *)0x34)//$14 ($34) DDRC
	#define DDIRCD  *((volatile uint8 *)0x31) //($31)data direction selection
	#define PINCREG *((volatile uint8 *)0x33)//$13 ($33) PINC
    #define PINDREG *((volatile uint8 *)0x30) //($30) PIND  used to read  portd "read only"
    // interrupt 
	#define GICR_   *((volatile uint8 *)0x5b) //GICR ($5B) for external int (pin int)
	#define SREG_   *((volatile uint8 *)0x5F) //SREG_ for enable global interrupts
	#define MCUCR_  *((volatile uint8 *)0x55) // ($55) MCUCR for interrupt case
	
	//timer2 configure
	#define TCCR2_ *((volatile uint8 *)0x45)  //$25 ($45) TCCR2 to configure timer2 modes
	#define OCR2_ *((volatile uint8 *)0x43)//$23 ($43) OCR2 Timer/Counter2 Output Compare Register
	
	
	


#endif 