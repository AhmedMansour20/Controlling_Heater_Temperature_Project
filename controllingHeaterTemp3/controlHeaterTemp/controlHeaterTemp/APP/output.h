/*
 * alarm.h
 
 *
 * Created: 12/28/2022 2:27:30 AM
 *  Author: AhmedMansour
 */ 


#ifndef OUTPUT_H_
#define OUTPUT_H_
#define USED_keys '0'||'1'||'2'||'3'||'4'||'5'||'6'||'7'||'8'||'9'||'c'
/* ********************* Definition section start ******************************************/
#define SENSOR_MAX_TEMP 101 // store the maximum temperature that temp. sensor can not reach
/* ********************* Definition section end ********************************************/

//this function fired when controller is forced to restart
//generate alarm in PD0pin
void alarm_on(void);
void alarm_off(void);
//fire red led
void red_on(void);
void red_off(void);

//fire green led
void green_on(void);
void green_off(void);

void output_indicator_init(void);
uint8 str_to_num(void);

/*
#if  0 
 final system operation
#endif*/
void monitoring ( void );
//show data on LCD 
void show ( void );
// change maximum temperature 
void system_temperature_settings( void );

	

#endif /* ALARM_H_ */