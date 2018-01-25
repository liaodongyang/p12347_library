#include "p12347_library.h"

byte bytes[9];

p12347::p12347(void){
	//start;
}

//I2C write
int p12347::p12347_sensor_init(void)
{
	uint8_t tmp[2];
	tmp[0]= REG_CONTROL;

	tmp[1]= FirstWrite;
	Wire.beginTransmission(P12347_I2C_Addr);
	int check;
	if (Wire.write(tmp, 2) == 2) {
    	check = Wire.endTransmission();
 	}
 	if(check > 0){
 		Serial.println("Error\n");
 		while(1);
 	}

 	delay(100);

 	tmp[1]= 0x01;
 	Wire.beginTransmission(P12347_I2C_Addr);
	if (Wire.write(tmp, 2) == 2) {
    	check = Wire.endTransmission();
 	}
 	if(check > 0){
 		Serial.println("Error\n");
 		while(1);
 	}

	delay(300);

	boolean ret;

	Wire.beginTransmission(P12347_I2C_Addr);
	uint8_t readwritemode;
	readwritemode = 0x03;
	if (Wire.write(readwritemode) == 1)
	{
		/* code */
		Wire.endTransmission(false);
		int Sizes = 8;
		Wire.requestFrom((uint8_t)P12347_I2C_Addr, (uint8_t)Sizes);
		if (Wire.available() == Sizes)
		{
			/* code */
			for (int i = 0; i < Sizes; ++i)
			{
				/* code */
				bytes[i] = Wire.read();
			}
			ret = true;
		} else{
			ret = false;
		}

	}else{
		ret = false;
	}
	check = Wire.endTransmission();
	if (!ret) check = -check; 
  	return check;
}

void p12347::p12347_led_init(void)
{

}

uint16_t p12347::readred()
{
	uint8_t redhigh = bytes[0];
	uint8_t redlow = bytes[1];
	uint16_t redval = (redhigh << 8) | redlow;
	return redval;
}

uint16_t p12347::readgreen()
{
	uint8_t greenhigh = bytes[2];
	uint8_t greenlow = bytes[3];
	uint16_t greenval = (greenhigh << 8) | greenlow;
	return greenval;
}

uint16_t p12347::readblue()
{
	uint8_t bluehigh = bytes[4];
	uint8_t bluelow = bytes[5];
	uint16_t blueval = (bluehigh << 8) | bluelow;
	return blueval;
}

uint16_t p12347::readinfrared()
{
	uint8_t infraredhigh = bytes[6];
	uint8_t infraredlow = bytes[7];
	uint16_t infraredval = (infraredhigh << 8) | infraredlow;
	return infraredval;
}

void p12347::makered(uint8_t LEDintensity){
	if( (LEDControl & 0x2 ) != 0){
		if(LEDintensity > 3){
			Serial.println("current may too large?");
			while(1);
		}
	}
	
	byte tmp[3];
	tmp[0]= LEDAddr;
	tmp[1]= LEDControl | LEDintensity;  //Red
	tmp[2]= 0x00;
	Wire.beginTransmission(P12347_I2C_Addr);
	int check;
  	if (Wire.write(tmp, 3) == 3) {
    	check = Wire.endTransmission();
  	}
  	if(check != 0){
  		Serial.println("LED write false:1?");
  		while(1);
  	}

  	delay(100);

  	byte tmp2[2];
  	tmp2[0]= LEDAddr;
  	tmp2[1]= LEDwake;
  	Wire.beginTransmission(P12347_I2C_Addr);
  	if (Wire.write(tmp2, 2) == 2) {
    	check = Wire.endTransmission();
  	}
  	if(check != 0){
  		Serial.println("LED write false:2?");
  		while(1);
  	}

}

void p12347::makegreen(uint8_t LEDintensity)
{
	if( (LEDControl & 0x2 ) != 0){
		if(LEDintensity > 3){
			Serial.println("current may too large?");
			while(1);
		}
	}

	byte tmp[3];
	tmp[0]= LEDAddr;
	tmp[1]= LEDControl | 0x00;  
	tmp[2]= (LEDintensity << 4) | 0x00; //Green

	Wire.beginTransmission(P12347_I2C_Addr);
	int check;
  	if (Wire.write(tmp, 3) == 3) {
    	check = Wire.endTransmission();
  	}
  	if(check != 0){
  		Serial.println("LED write false:1?");
  		while(1);
  	}

  	delay(100);

  	byte tmp2[2];
  	tmp2[0]= LEDAddr;
  	tmp2[1]= LEDwake;
  	Wire.beginTransmission(P12347_I2C_Addr);
  	if (Wire.write(tmp2, 2) == 2) {
    	check = Wire.endTransmission();
  	}
  	if(check != 0){
  		Serial.println("LED write false:2?");
  		while(1);
  	}
}

void p12347::makeblue(uint8_t LEDintensity)
{
	if( (LEDControl & 0x2 ) != 0){
		if(LEDintensity > 3){
			Serial.println("current may too large?");
			while(1);
		}
	}

	byte tmp[3];
	tmp[0]= LEDAddr;
	tmp[1]= LEDControl | 0x00;  
	tmp[2]= 0x00 | LEDintensity; //Green

	Wire.beginTransmission(P12347_I2C_Addr);
	int check;
  	if (Wire.write(tmp, 3) == 3) {
    	check = Wire.endTransmission();
  	}
  	if(check != 0){
  		Serial.println("LED write false:1?");
  		while(1);
  	}

  	delay(100);

  	byte tmp2[2];
  	tmp2[0]= LEDAddr;
  	tmp2[1]= LEDwake;
  	Wire.beginTransmission(P12347_I2C_Addr);
  	if (Wire.write(tmp2, 2) == 2) {
    	check = Wire.endTransmission();
  	}
  	if(check != 0){
  		Serial.println("LED write false:2?");
  		while(1);
  	}
}

void p12347::turnoffled(void)
{
	byte tmp[2];
	tmp[0]= LEDAddr;
	tmp[1]= LEDsleep;
	int check;
	Wire.beginTransmission(P12347_I2C_Addr);
  	if (Wire.write(tmp, 2) == 2) {
    	check = Wire.endTransmission();
  	}
  	if(check != 0){
  		Serial.println("LED write false:2?");
  		while(1);
  	}
}

void p12347::makeLEDmisc(uint8_t LEDredin, uint8_t LEDgreenin, uint8_t LEDbluein)
{
	if( (LEDControl & 0x2 ) != 0){
		if(LEDredin > 3){
			Serial.println("current may too large?");
			while(1);
		}
		if(LEDgreenin > 3){
			Serial.println("current may too large?");
			while(1);
		}
		if(LEDbluein > 3){
			Serial.println("current may too large?");
			while(1);
		}
	}

	byte tmp[3];
	tmp[0]= LEDAddr;
	tmp[1]= LEDControl | LEDredin;  
	tmp[2]= (LEDgreenin << 4) | LEDbluein; //Green

	Wire.beginTransmission(P12347_I2C_Addr);
	int check;
  	if (Wire.write(tmp, 3) == 3) {
    	check = Wire.endTransmission();
  	}
  	if(check != 0){
  		Serial.println("LED write false:1?");
  		while(1);
  	}

  	delay(100);

  	byte tmp2[2];
  	tmp2[0]= LEDAddr;
  	tmp2[1]= LEDwake;
  	Wire.beginTransmission(P12347_I2C_Addr);
  	if (Wire.write(tmp2, 2) == 2) {
    	check = Wire.endTransmission();
  	}
  	if(check != 0){
  		Serial.println("LED write false:2?");
  		while(1);
  	}
}