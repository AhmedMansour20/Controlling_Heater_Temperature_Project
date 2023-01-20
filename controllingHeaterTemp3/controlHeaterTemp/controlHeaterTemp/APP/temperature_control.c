 #include "configure.h"
 
 
 
uint8 temp_value(){ // 35 c = level # 72 "at ADC data register "
	// setting default maximum temperature limit in EEPROM Module
	//eeprom_write(0, 50);//50 Cecilius degree
	uint8 temp = 0;
	uint16 current_temp = 0;
	current_temp = adc_read(); //72 of ADC value = 35 c 
	/*temperature monitoring*/
	temp =  ( (adc_read() * 0.488) );// convert adc level to volt, then convert volt to temp. in celusius
	return temp;
 	    
}
 
  