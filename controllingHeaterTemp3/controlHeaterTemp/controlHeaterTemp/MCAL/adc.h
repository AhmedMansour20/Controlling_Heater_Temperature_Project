 

#ifndef ADC_H_
#define ADC_H_
  
	//ADC configure
	#define ADCSRA_  *((volatile uint8 *)0x26)//$06 ($26) ADCSRA  "ADC Control and Status Register A –ADCSRA"
	#define ADMUX_   *((volatile uint8 *)0x27)//$07 ($27) ADMUX
	#define ADCL_    *((volatile uint8 *)0x24)//$04 ($24) ADCL ADC Data Register Low Byte
    #define ADCH_    *((volatile uint8 *)0x25)//$05 ($25) ADCH ADC Data Register High Byte
	

	void  ADC_init_();
	uint16 adc_read();
	


#endif  