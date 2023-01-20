 

#ifndef LCD_H_
#define LCD_H_
   
 #include "configure.h"
    // LCD command
	#define LINE1 0x80
	#define LINE1_END 0x95
	#define LINE2 0xc0
	#define LINE2_END 0xd5
	
	#define CLEAR 0x01
	#define SHIFT_RIGHT 0x18
	#define SHIFT_LEFT 0x1c
	
	//used functions
	/* 
	function    :  enable 4_bit mode & access lines (1&2) together to access lines (1&2) together
	               & cursor off/on & clear LCD & make cursor increment to right to make cursor increment to right
	return      : nothing
	parameters  : nothing	 
	*/		  
	void lcd_init(void);
	
	/* 
	function    : reading most nibble & reading least  nibble  
	return      : nothing
	parameters  : hex. command from user	"developer" 
	*/	
	
	void lcd_write_cmd(uint8 hex_cmd);
	
	/* 
	function    : reading most nibble & reading least  nibble  of ASCII of charecters or shapes
	return      : nothing
	parameters  : hex. data from user	"developer" 
	*/
	void lcd_write_char(uint8 hex_data);
	
	void convert_num_to_hex(uint16 num);
	void lcd_write_string_(  uint8 str[50] );
	
	void white_spaces(uint8 cmd );
	// lcd pins
	#define EN2(x) if(x == 1) SET(PRTB,2);else CLR(PRTB,2); //EN  enable pin2 "portb"
	#define RS3(x) if(x == 1) SET(PRTB,3);else CLR(PRTB,3); //RS  pin3 "portb"
	#define D4(x)  if(x == 1) SET(PRTB,4);else CLR(PRTB,4);
	#define D5(x)  if(x == 1) SET(PRTB,5);else CLR(PRTB,5);
	#define D6(x)  if(x == 1) SET(PRTB,6);else CLR(PRTB,6);
	#define D7(x)  if(x == 1) SET(PRTB,7);else CLR(PRTB,7);
	
	// statement
	



#endif /* LCD_H_ */