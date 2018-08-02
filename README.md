# p12347_library
*p12347_library - Library for sensor p12347.*
*Created by Dongyang Liao, January 26, 2018.*

![Alt text](https://www.azosensors.com/images/equipments/EquipmentImage_1465.jpg)

This is a nultifunctional sensor that incorporates a color sensor, proximity sensor, and 3-color LED in a small package

### I2C communiation
  
### Declaration (Arduino)

###### &nbsp;&nbsp;&nbsp;&nbsp;   p12347 XXXX

### Usage
*   XXXX.p12347_sensor_init();
*   uint16_t redval = XXXX.readred();
*  	XXXX.makegreen(); //LED
*  	...

### Function introduction
*  p12347_sensor_init() ... Initial the Sensor register;
*  readred()... Read the red value after Initialization; (Return uint16_t)
*  readgreen()...Read the green value after Initialization; (Return uint16_t)
*  readblue()...Read the blue value after Initialization; (Return uint16_t)
*  readinfrared()...Read the infrared value after Initialization; (Return uint16_t)

*  makegreen(uint8_t LEDintensity)...Set the LED green;
*  makeblue(uint8_t LEDintensity)...Set the LED blue;
*  makered(uint8_t LEDintensity)...Set the LED red;
*  makeLEDmisc(uint8_t LEDredin, uint8_t LEDgreenin, uint8_t LEDbluein)...Set the LED ;
*  turnoffled()...Turn off LED

####  About the desciption 
Default: safe mode 
Fixed time mode (No enough)
Issue: Something weird in datasheet, about the control current
> Refer to datasheet https://www.hamamatsu.com/resources/pdf/ssd/p12347-01ct_kpic1084e.pdf


2018/08/02 Excmples correction (Thanks for reminding to @per1234)
