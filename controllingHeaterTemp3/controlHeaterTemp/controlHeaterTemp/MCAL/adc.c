 /** 
 *****************************************************************************************
 * @file 	   : adc.c
 * @author 	   : Ahmed Mansour
 * @brief      : ADC module initializing & set its configuration
 *************s****************************************************************************
*/
 /* ********************* Include section start ******************************************/
  #include "configure.h" // contain registers names and locations.
  #include "adc.h"  // contain (ADC_init_) & (adc_read) declaration.
 /* ********************* Include section end ********************************************/
 
 
 
 
/* *********** Sub_programs section start *************************************************/

void  ADC_init_(){//contain all ADC basic settings
	SET(ADCSRA_,7); // Bit 7 – ADEN: ADC Enable
	// Bits 2:0 – ADPS2:0: ADC Prescaler Select Bits
	CLR(ADCSRA_,0);CLR(ADCSRA_,1);CLR(ADCSRA_,2);
	/*This bit is set when an ADC conversion completes
		and the Data Registers are updated */
	SET(ADMUX_,6);CLR(ADMUX_,7);//select REF--> AVCC with external capacitor at AREF pin	
}

uint16 adc_read(){// contain conversion part.
	SET(ADMUX_,0);//select ADC1 channel
	/*ADSC will read as one as long as a conversion is in progress.
	When the conversion is complete,it returns to zero.
	Writing zero to this bit has no effect*/
	SET(ADCSRA_,6);//Bit 6 – ADSC: ADC Start Conversion
	while( RED(ADCSRA_,4) == 0){}// Bit 4 – ADIF: ADC Interrupt Flag
	SET(ADCSRA_,4);// to clear interrupt flag after each polling operation
	//ADC_  = pick_up_ADC_data_registers();
	return ADC;
}

/********************** Sub_programs section end ******************************************/
















