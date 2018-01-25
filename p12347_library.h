/*
  p12347_library - Library for sensor p12347.
  Created by Dongyang Liao, January 26, 2018.

  I2C communiation
  
  Declaration (Arduino)
  	p12347 XXXX

  Usage
	XXXX.p12347_sensor_init();
	uint16_t redval = XXXX.readred();
	//LED
	XXXX.makegreen();
	...

  p12347_sensor_init() ... Initial the Sensor register;
  readred()... Read the red value after Initialization; (Return uint16_t)
  readgreen()...Read the green value after Initialization; (Return uint16_t)
  readblue()...Read the blue value after Initialization; (Return uint16_t)
  readinfrared()...Read the infrared value after Initialization; (Return uint16_t)

  makegreen(uint8_t LEDintensity)...Set the LED green;
  makeblue(uint8_t LEDintensity)...Set the LED blue;
  makered(uint8_t LEDintensity)...Set the LED red;
  makeLEDmisc(uint8_t LEDredin, uint8_t LEDgreenin, uint8_t LEDbluein)...Set the LED ;
  turnoffled()...Turn off LED

  Default: Fixed time mode

  Refer to https://www.hamamatsu.com/resources/pdf/ssd/p12347-01ct_kpic1084e.pdf

*/


#ifndef __P12347.h__
#define __P12347.h__ 1

#include <Arduino.h>
#include <Wire.h>

#define P12347_I2C_Addr 0x2A
//---------------------initial_setting----------------------->>
#ifndef initial_setting
//#define initial_setting 1
#define REG_CONTROL 0x00  // センサーの制御レジスタ(1 byte)
#define FirstWrite 0x84
#define SecondWrite 0x04
#define ReadMode 0x03

#endif
//-----------------------------------------------------------<<

//-------------------------Fixed time mode------------------->>

#ifndef Fixed_time_mode
#define Fixed_time_mode 1
#define REG_CONTROL 0x00  // センサーの制御レジスタ(1 byte)
#define FirstWrite 0x81
#define SecondWrite 0x01
#define ReadMode 0x03

#endif
//-----------------------------------------------------------<<

//------------------------LED-------------------------------->>
//#define LEDControl 0xa0
#define LEDControl 0x80
#define LEDAddr 0x0e
#define LEDsleep 0xc1
#define LEDwake 0x01
//-----------------------------------------------------------<<


class p12347
{
public:
	p12347(void);
	int p12347_sensor_init(void);
	void p12347_led_init(void); // NO used
	uint16_t readred();
	uint16_t readgreen();
	uint16_t readblue();
	uint16_t readinfrared();
	void makegreen(uint8_t LEDintensity);  //LED
	void makered(uint8_t LEDintensity);    //LED
	void makeblue(uint8_t LEDintensity);   //LED
	void makeLEDmisc(uint8_t LEDredin, uint8_t LEDgreenin, uint8_t LEDbluein);  //LED
	void turnoffled(void); //LED

};




#endif