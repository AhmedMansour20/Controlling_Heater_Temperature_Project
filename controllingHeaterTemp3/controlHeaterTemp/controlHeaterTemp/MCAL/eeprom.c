#include "eeprom.h"
#include "configure.h"

/* *********** Sub_programs section start *************************************************/

void eeprom_write (uint16 eeprom_add, uint8 data){

	while(RED(EECR_, 1) == 1){}// EEWE: check eeprom ready to write(1. Wait until EEWE becomes zero )-->1
	EEARL_ = eeprom_add;// EEPROM address register-->2
	
	//EEDR_ = 0x00; //clear eeprom undefined data-->3
	
	EEDR_ = data; // your data will be written-->4
	//5. Write a logical one to the EEMWE bit while writing a zero to EEWE in EECR.
	SET(EECR_,2);//CLR(EECR_,1); //  Bit 2 – EEMWE: EEPROM Master Write Enable, enable writing to eeprom-->5
	SET(EECR_,1);// 6. Within four clock cycles after setting EEMWE, write a logical one to EEWE. -->6
}


uint8 eeprom_read( uint16 eeprom_add){

	 
	while(RED(EECR_,1) == 1){}// chech eeprom ready to write(1. Wait until EEWE becomes zero )-->1
	EEARL_ = eeprom_add;//-->2
	SET(EECR_,0); // enable reading from eeprom by  EERE(set EECR bit0 )-->3
	
	return EEDR_;
}


/* *********** Sub_programs section end *************************************************/











