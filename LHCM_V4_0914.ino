#include "Adafruit_MCP9601.h"

#define NUM_SENSORS 8
#define ThermA (0x60) //ADR to ground -   !!Closest to Cooling Loop!!
#define ThermB (0x61) //R2 2.2kΩ - Red
#define ThermC (0x62) //R2  4.3kΩ - Yellow
#define ThermD (0x63) //R2 7.5kΩ          !!Sample Lower!!
#define ThermE (0x64) //R2 13kΩ  (13.3kΩ) !! Sample Upper !!
#define ThermF (0x65) //22k jumper closed - Blue
#define ThermG (0x66) //43k jumper closed - Green
#define ThermH (0x67) //default -         !!Closest to Heater!!

Adafruit_MCP9601 mcp[NUM_SENSORS];
const byte mcpADDR[NUM_SENSORS] = {ThermA, ThermB, ThermC, ThermD, ThermE, ThermF, ThermG, ThermH};

void setup() {
  Serial.begin(115200);
  while (!Serial) {delay(5);}
  Serial.println("...loading...");
  Serial.println("I2C Addresses Connecting...");
  
  for (byte s=0; s < NUM_SENSORS; s++){
    if(! mcp[s].begin(mcpADDR[s])){
      Serial.print("Could not find 0x6");
      Serial.println(s, HEX);
      Serial.println("Please check wiring!");
      while(1);
    }
    Serial.print("Found 0x6");
    Serial.println(s, HEX);
    mcp[s].setThermocoupleType(MCP9600_TYPE_T);
  }
  delay(3000);
}

void loop() {
  Serial.print("$");
  Serial.print(millis());
  for(byte s=0; s<NUM_SENSORS; s++) {
    Serial.print(",");
    Serial.print(mcp[s].readThermocouple(), 2);
  }
  Serial.println("%");
  delay(100);
}
