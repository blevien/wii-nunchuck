#include "Wire.h"
#include "WiiChuck.h"

WiiChuck chuck = WiiChuck();

void setup() {
  Serial.begin(115200);
  chuck.begin();
  chuck.update();
}

void loop() {
  
  delay(20);
  chuck.update(); 

  int pitch = chuck.readPitch();
  int roll = chuck.readRoll();
  
  // Public Variables from WiiChuck Object
  //int chuck.joyX
  //int chuck.intjoyY
  //bool chuck.buttonZ
  //bool chuck.buttonC  


  pitch = constrain(pitch, 40, 120);
  roll = constrain(roll, -70, 70);

  pitch = map(pitch, 40, 120, 180, 0);
  roll = map(roll, -70, 70, 0, 180);  

  
  Serial.print(roll);
  Serial.print(", ");
  Serial.print(pitch);
  Serial.print(", ");  
  Serial.print(chuck.joyX);
  Serial.print(", ");    
  Serial.print(chuck.joyY); 
  Serial.print(", ");    
  Serial.print(chuck.buttonC); 
  Serial.print(", ");    
  Serial.print(chuck.buttonZ); 
  Serial.println();



    
}
