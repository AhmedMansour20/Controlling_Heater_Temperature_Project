#include "lcd.h"



void lcd_init(void){
	//$18 ($38) PORTB
	DDIRCB |=0b11111100;
	//wait 4mill sec ??
	lcd_write_cmd(0x3); //??
	lcd_write_cmd(0x2);  // 0x2 sent to enable 4_bit mode
	lcd_write_cmd(0x28); // to access lines (1&2) together
	lcd_write_cmd(0x08); // cursor off
	lcd_write_cmd(0x01); // to clear LCD
	lcd_write_cmd(0x06); // to make cursor increment to right
	lcd_write_cmd(0x0c); // to turn on display
	_delay_ms(20);
}

void lcd_write_cmd(uint8 hex_cmd){//0X25
	RS3(0);// RS3 = 0
	//reading most nibble
	D7( RED(hex_cmd,7) );
	D6( RED(hex_cmd,6) );
	D5( RED(hex_cmd,5) );
	D4( RED(hex_cmd,4) );
	EN2(1);_delay_ms(1);EN2(0);_delay_ms(1);
	//reading least  nibble
	D7( RED(hex_cmd,3) );
	D6( RED(hex_cmd,2) );
	D5( RED(hex_cmd,1) );
	D4( RED(hex_cmd,0) );
	EN2(1);_delay_ms(1);EN2(0);_delay_ms(1);
}
 

void lcd_write_char(uint8 hex_data){
	RS3(1);// RS3 = 1
	//reading most nibble
	D7( RED(hex_data,7) );
	D6( RED(hex_data,6) );
	D5( RED(hex_data,5) );
	D4( RED(hex_data,4) );
	EN2(1);_delay_ms(1);EN2(0);_delay_ms(1); // put high then low to send data to lcd
	//reading least  nibble
	D7( RED(hex_data,3) );
	D6( RED(hex_data,2) );
	D5( RED(hex_data,1) );
	D4( RED(hex_data,0) );
	EN2(1);_delay_ms(1);EN2(0);_delay_ms(1);// put high then low to send data to lcd
 
}
 void convert_num_to_hex(uint16 num){

uint8 i, j, k;// 3 counters
uint16 m; // counter for filled array "new array" digit_store[m]
uint8 digit_store[5]; // array stores remainder
	 
	if(num <= 80000){ // check number value to be in acceptable storage range 8 bit unsinged
		 //lcd_write_cmd(0x86);// determine printing position
		 for (i = 0; i <= 4; i++){
			 if ( num / 10.0 < 1 ){
				 digit_store[i] = num;
				 break;
			 }
			 digit_store[i] = num % 10;// take first num
			 num = (num / 10);// delet last number from the original one
		 }
		 // print number on lcd digit by digit from the filled array " digit_store[m] "
		 for(m = i; m >= 0 ; m--){
			 for ( j = 0x30; j <= 0x40; j++){// its idea is to find digit and its value in hexadecimal
				 if (digit_store[m] == k){
					 lcd_write_char(j);
					 break;
				 }
				 k++;
			  }
		  k = 0;
		 }
	}


}
 
 
 
 
void lcd_write_string_( uint8 str[50] ){//***  i think error
uint8 i = 0;
   // loop until print all string in lcd
	 for (i = 0; i != 0x30; i++){ //char ascii Nul = 0x30
		   if(i < 12){//start writing in first line
				lcd_write_char( str[i]  );
            }
	 }
 
     
} 
 
  
 
void white_spaces(uint8 cmd ){
uint8 i = 0;//white space counter
	if(cmd == LINE1){
		lcd_write_cmd(LINE1);
		for ( i = 0; i < 15; i++){
			lcd_write_char(' ');
		}
		
	}else if (cmd == LINE2){
		lcd_write_cmd(LINE2);
		for ( i = 0; i < 15; i++){
		   lcd_write_char(' ');
	    }
	} 

	 

} 

 
 
 
 
 /* ************ run corrrectly with some errors **********
 void convert_num_to_hex(uint8 num){

	 uint8 i, j, k;
	 uint16 m;
	 uint8 new_pos = 0;// enable me to write at new cell
	 uint8 digit_store[3]; // store remainder
	 if(num <= 255){
		 for (i = 0; i <= 2; i++){
			 digit_store[i] = num % 10;
			 num = (num / 10.0) - (digit_store[i] * 0.1);
		 }
		 
		 for(m = 2; m >= 0 ; m--){
			 for ( j = 0x30; j <= 0x39; j++){
				 if (digit_store[m] == k){
					 digit_store[m] = j;
					 lcd_write_cmd(0x80 + new_pos);
					 lcd_write_char(digit_store[m]);
					 new_pos++;
					 break;
				 }
				 k++;
			 }
			 k = 0;
		 }
		 new_pos = 0;// note it is must be cleared "because it is static" to be ZER0 for second call
	 }
 }
 
 
 
 */
 
/* ****************************** last error 29/9/2020 *****************






*/ 
 