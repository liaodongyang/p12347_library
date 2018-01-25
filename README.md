# p12347_library
*p12347_library - Library for sensor p12347.*
*Created by Dongyang Liao, January 26, 2018.*

![Alt text](https://www.hamamatsu.com/blobs/1328779685689?blobheadername1=content-disposition&blobheadervalue1=inline%3Bfilename%3D1328482657394.jpg&ssbinary=true)

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

####  Default: Fixed time mode

> Refer to https://www.hamamatsu.com/resources/pdf/ssd/p12347-01ct_kpic1084e.pdf
