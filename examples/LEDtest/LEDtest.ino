#include "p12347_library.h"

p12347 p12347test;

void setup() {
  // put your setup code here, to run once:
  delay(1000);
  Wire.begin();
  delay(1000);
  Serial.begin(74880);
  //Set the LED (red,green,blue)
}

void loop() {
  
  //Set the LED (red,green,blue)
  p12347test.makeLEDmisc(0x2,0x2,0x2);
  delay(5000);
  
  //turn LED off
  p12347test.turnoffled();
  delay(5000);
  
}
