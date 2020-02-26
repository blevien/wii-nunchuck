#include <math.h>

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

  Serial.print(chuck.readRoll());
    Serial.print(", ");  
  Serial.print(chuck.readPitch());
    Serial.print(", ");  

    Serial.print((int)chuck.readAccelX()); 
    Serial.print(", ");  
    Serial.print((int)chuck.readAccelY()); 
    Serial.print(", ");  

    Serial.print((int)chuck.readAccelZ()); 
    Serial.println();
}
