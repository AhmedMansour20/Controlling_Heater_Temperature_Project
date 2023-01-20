 

#ifndef INCFILE1_H_
#define INCFILE1_H_

//used data type
typedef unsigned char uint8; //** take care at any loop from variable sign **
typedef signed  short uint16;
typedef unsigned long uint32;

// EEPROM REGETERS
#define EEARL_  *((volatile uint8 *)0x3e)//$1E ($3E) EEARL
#define EEDR_   *((volatile uint8 *)0x3d)//$1D ($3D) EEDR
#define EECR_   *((volatile uint8 *)0x3c)//$1C ($3C) EECR
#define SPMCR_  *((volatile uint8 *)0x57)//$37 ($57) SPMCR



//used functions
/*
function : save data to any EEPROM location
argument : user can pass wanted location to save data & the data in 8 bits  form
return   : no return
*/
void eeprom_write (uint16 eeprom_add, uint8 data);
/*
function : read data from any EEPROM location by pass wanted EEPROM location you want to read 
argument : user can pass wanted location to read data  
return   : return wanted data from the previously passed EEPROM address
*/
uint8 eeprom_read( uint16 eeprom_add);





#endif 