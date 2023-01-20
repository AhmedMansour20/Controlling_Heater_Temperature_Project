#include "keypad.h"
#include "configure.h"
#include "lcd.h"




//keypad buttons values
uint8 butn_value [16] = {     'c',   '0',  '=',  '+',
	                          '1',   '2',  '3',  '-',
	                          '4',   '5',  '6',  'x',
	                          '7',   '8',  '9',  '/'
                         };
 
 
//I will connect k.pad on port C
 void keypad_init(void){//DDIRCC
	 DDIRCN   = 0xf0;// (pin0...3): output = 1 & (pin4...7): input = 0
	 PRTN |= 0x0f; // pull up activation**
}

uint8 key_value(void){//return value of keypad pressed key
	
	PRTN = 0b11101111;//working on 1st row 
	//working on all columns & return value of keypad pressed key 
	if( RED(PINN, 0) == 0 )     {_delay_ms( DELAY ); return butn_value [0];} 
	else if ( RED(PINN, 1) == 0){_delay_ms( DELAY ); return butn_value [1];}
    else if ( RED(PINN, 2) == 0){_delay_ms( DELAY ); return butn_value [2];}
	else if ( RED(PINN, 3) == 0){_delay_ms( DELAY ); return butn_value [3];}
	_delay_ms( DELAY );	
	
    PRTN = 0b11011111;//working on 2st row
	//working on all columns & return value of keypad pressed key 
    if( RED(PINN, 0) == 0)      {_delay_ms( DELAY ); return  butn_value[4];}//read column number & return value of keypad pressed key
	else if ( RED(PINN, 1) == 0){_delay_ms( DELAY ); return butn_value [5];}
    else if ( RED(PINN, 2) == 0){_delay_ms( DELAY ); return butn_value [6];}
	else if ( RED(PINN, 3) == 0){_delay_ms( DELAY ); return butn_value [7];}
	_delay_ms( DELAY );
	
	PRTN = 0b10111111;//working on 3st row
	//working on all columns & return value of keypad pressed key
	if( RED(PINN, 0) == 0)      {_delay_ms( DELAY ); return butn_value [8];}//read column number & return value of keypad pressed key
	else if ( RED(PINN, 1) == 0){_delay_ms( DELAY ); return butn_value [9];}
	else if ( RED(PINN, 2) == 0){_delay_ms( DELAY ); return butn_value [10];}
	else if ( RED(PINN, 3) == 0){_delay_ms( DELAY ); return butn_value [11];}
	_delay_ms( DELAY );
	
	PRTN = 0b01111111;//working on 3st row
	//working on all columns & return value of keypad pressed key
	if( RED(PINN, 0) == 0)      {_delay_ms( DELAY ); return butn_value [12];}//read column number & return value of keypad pressed key
	else if ( RED(PINN, 1) == 0){_delay_ms( DELAY ); return butn_value [13];}
	else if ( RED(PINN, 2) == 0){_delay_ms( DELAY ); return butn_value [14];}
	else if ( RED(PINN, 3) == 0){_delay_ms( DELAY ); return butn_value [15];}
	_delay_ms( DELAY );
	
	return '&';
	
}
 
/*


// convert receiving pressed value from keypad as decimal value
uint8 str_to_num( void ){
uint16 sum = 0;//final result .. do not put static here !!!!! my first bug.
uint8 key = 0;
	while(  1 ){
		key = key_value();//wait until button pressed
		while ( key == '&'){ key = key_value(); }// loop until any key pressed
		if ( 0 ){//key == 'c' *not used (spaire)
			white_spaces(LINE2);
			lcd_write_cmd(LINE2);
			lcd_write_char('T');
			lcd_write_char('=');
			lcd_write_char(' ');
			convert_num_to_hex( sum );
			lcd_write_char(' ');
			lcd_write_char('C');
			return sum;
		}else if (key == 'c'){ return sum;}
		sum = (sum*10) + ( key - 48);//combine keypad pressed buttons
		white_spaces(LINE2);
		lcd_write_cmd(LINE2);
		convert_num_to_hex( sum );// show entered num. in 2nd line
		while ( key != '&'){ key = key_value(); }// key is released
    }
    
}

*/

