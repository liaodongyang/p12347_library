#include "p12347_library.h"

p12347 p12347test;

void setup() {
  
  delay(1000);
  Wire.begin();
  delay(4000);
  Serial.begin(74880);
  //Set the LED (red,green,blue)
  p12347test.makeLEDmisc(0x0,0x2,0x2);
  delay(5000);
  
}

void loop() {
  // Sensor Read
  int p12347check = p12347test.p12347_sensor_init();
  // If return value is not 0, may error;
  if(p12347check != 0){
     Serial.println("Error\n");
    while(1);
  }
  uint16_t reddata = p12347test.readred();
  Serial.print("Red: ");
  Serial.print(reddata);
  Serial.println(" lx");
  uint16_t greendata = p12347test.readgreen();
  Serial.print("Green: ");
  Serial.print(greendata);
  Serial.println(" lx");
  uint16_t bluedata = p12347test.readblue();
  Serial.print("Blue: ");
  Serial.print(bluedata);
  Serial.println(" lx");
  uint16_t infdata = p12347test.readinfrared();
  Serial.print("infrared: ");
  Serial.print(infdata);
  Serial.println(" lx");

  p12347test.turnoffled();
  
  delay(2000);
}
