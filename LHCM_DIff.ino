#include "Adafruit_MCP9601.h"

#define NUM_SENSORS 7
#define ThermA (0x60) //ADR to ground -   !!Closest to Cooling Loop!!
#define ThermB (0x61) //R2 2.2kΩ - Red
#define ThermC (0x62) //R2  4.3kΩ - Yellow
#define ThermDE (0x63) //R2 7.5kΩ          !!Sample Lower!!
#define ThermF (0x64) //22k jumper closed - Blue
#define ThermG (0x65) //43k jumper closed - Green
#define ThermH (0x66) //default -         !!Closest to Heater!!

Adafruit_MCP9601 mcp[NUM_SENSORS];
const byte mcpADDR[NUM_SENSORS] = {ThermA, ThermB, ThermC, ThermDE, ThermF, ThermG, ThermH};
float initial[NUM_SENSORS] = {0};


// Steady State Variables
unsigned long duration = 5 * 60 * 1000; // 5 minutes in milliseconds
float tolerance = 3; // 2 degrees C

void setup() {
  Serial.begin(2400);
  while (!Serial) {delay(5);}
  Serial.println("...loading...");
  Serial.println("I2C Addresses Connecting...");

  for (byte s=0; s < NUM_SENSORS; s++){
    mcp[s].setADCresolution(MCP9600_ADCRESOLUTION_18);
    if(! mcp[s].begin(mcpADDR[s])){
      Serial.print("Could not find 0x6");
      Serial.println(s, HEX);
      Serial.println("Please check wiring!");
      while(1);
    }
    Serial.print("Found 0x6");
    Serial.println(s, HEX);
    mcp[s].setThermocoupleType(MCP9600_TYPE_J);
  }

  delay(3000);
}

void loop() {
  Serial.print("$");
  Serial.print(millis());
  Serial.print(":");
  for(byte s=0; s<NUM_SENSORS; s++) {
    if(s==3){
      Serial.print(mcp[s].readADC()*2);
      Serial.print("uV,");
    }else {
      Serial.print(mcp[s].readThermocouple());
      Serial.print("C,");
    }
  }
  Serial.println("");
  delay(100);
}

