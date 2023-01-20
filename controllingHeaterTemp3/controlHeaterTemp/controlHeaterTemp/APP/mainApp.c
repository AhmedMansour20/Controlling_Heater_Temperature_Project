 /** 
 *****************************************************************************************
 * @file 	   : mainAPP.c
 * @author 	   : AhmedMansour
 * @Created    : 12/28/2022 2:26:41 AM
 * @brief      : the main application file that control all other project files. 
 *****************************************************************************************
*/


/* ********************* Include section start ******************************************/
#include "configure.h"  // contain registers names and locations.
#include "lcd.h" // contain functions of LCD module.
/* ********************* Include section end ********************************************/




/* ********************* Global section start ******************************************/
extern  uint8 certain_temp = 0; // store the maximum temperature that entered from system user.
/* ********************* Global section end ********************************************/



int main(void){
	
ADC_init_();                    //initialize ADC registers
lcd_init();                    //initialize lcd with 4 bit mode
keypad_init();                //configure key pad pin direction
output_indicator_init();     //set leds & alarm pins direction


/* ********************* Program super loop section start ******************************************/
    while(1) {                               // super loop
		monitoring ();                      // system monitoring & taking an action according to modified certain(max.) temp
		show();                            //show data on LCD  
		system_temperature_settings();    // Entering to setting mode by press '-' key 
    }
 /* ********************* Program super loop section end ******************************************/		  

}



