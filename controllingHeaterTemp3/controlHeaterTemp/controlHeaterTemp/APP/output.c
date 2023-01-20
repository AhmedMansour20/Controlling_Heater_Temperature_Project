/*
 * CFile1.c
 *
 * Created: 12/28/2022 2:26:41 AM
 *  Author: AhmedMansour
 */ 
#include "configure.h"
#include "output.h"
#include "lcd.h"

/* ********************* Global section declaration start ******************************************/
extern uint8 certain_temp ; // store the maximum temperature that entered from system user.
/* ********************* Global section declaration end ********************************************/


void output_indicator_init(void){//setting alarm & leds data direction
		DDIRCD |= 0xFF;//  o/p
}

//called when system failure occur
void alarm_on(void){
	SET (PRTD, 0); //generate alarm in PD3 pin after WDT restart the controller
}
void alarm_off(void){
	CLR (PRTD, 0); //generate alarm in PD3 pin after WDT restart the controller
}
//called when AC heater pass modified certain temp
void red_on(void){	
	SET (PRTD, 2);
}
void red_off(void){
    CLR (PRTD, 2);
}

//fire green led
void green_on(void){
	SET(PRTD, 1);
}
void green_off(void){
	CLR(PRTD, 1);
}




// convert receiving pressed value from keypad as decimal value
uint8 str_to_num( void ){
	uint16 sum = 0;//final result .. do not put static here !!!!! my first bug.
	uint8 key = 0;
	
	while(1){
		
	key = key_value();//wait until button pressed
	while ( key == '&' ){ key = key_value(); }// loop until any key pressed
		
		if ( (key < 58) && (key > 47) ){  // entering number only
			sum = (sum*10) + (key - 48); //combine keypad pressed buttons
			white_spaces(LINE2);
			lcd_write_cmd(LINE2);
			convert_num_to_hex( sum );// show entered num. in 2nd line
		   
		} else if (key == 'c' ){ return sum; }//else {continue;}

	while ( key != '&'){ key = key_value(); }// key is released
    }
    
}



 
// final system operation
void monitoring ( void ){
	
/* ********************* Local section start ******************************************/
static uint8 current_temp = 0;  // store the returned temp. value from ( adc_read ) function.
static uint8 max_temp = 0;     //store the returned maximum temp. value from ( eeprom_read ) function.
/* ********************* Local section end ********************************************/
	
	current_temp = temp_value();
	max_temp = eeprom_read(0);
	if ( current_temp >= max_temp ){//heater shut down
		red_on();// indicate heater pass max. temp
		green_off();// indicate heater not pass max. temp
	}else if ( current_temp < max_temp ){//heater on
		green_on();
		red_off();
	}
	if ( current_temp >= SENSOR_MAX_TEMP ){//to safe heater from damage
		alarm_on();// alternate to WDT
		red_off();
	}else if ( current_temp < SENSOR_MAX_TEMP ){
		alarm_off();
	}

}
//show data on LCD 
void show ( void ){
	lcd_write_cmd(LINE1); //start writing from line 1
	lcd_write_string_("Max.Temp:   ");
	convert_num_to_hex( eeprom_read(0) );
	lcd_write_char(' ');
	lcd_write_char('C');
	lcd_write_cmd(LINE2);
	lcd_write_string_("ForSetting:-");
	_delay_ms(600);
	
	//lcd_write_cmd(CLEAR);
	white_spaces( LINE1 );
	lcd_write_cmd(LINE1);
	lcd_write_string_("Temp. now:   ");
	convert_num_to_hex( temp_value() );
	lcd_write_char(' ');
	lcd_write_char('C');
	_delay_ms(600);
}
// change maximum temperature 
void system_temperature_settings( void ){
				if (key_value() == '-'){//go to set temp. value
				lcd_write_cmd(CLEAR);
				lcd_write_cmd(LINE1);
				lcd_write_string_("ENTR MAX.Val");
				_delay_ms(2000);
				white_spaces(LINE1);
				lcd_write_cmd(LINE1);
				lcd_write_string_("ToSave:C       ");
			while (key_value() != '&'){}//wait until button released
			certain_temp = str_to_num();
		/*	if ( certain_temp > 255 ){
				continue;;
				;
			}else */if ( certain_temp < 255 ){
				//store max. temp in EEPROM
				eeprom_write(0, certain_temp);
				lcd_write_cmd(CLEAR);
				lcd_write_cmd(LINE1);
				lcd_write_string_("Saving...      ");
				_delay_ms(1000);
			}

		}//if '-' end
}





