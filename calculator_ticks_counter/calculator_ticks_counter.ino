/* Author: Pyae Soan Aung (Ghostman @ greenhackers)
*/
#if (ARDUINO >= 100)
#include <Arduino.h>
#else
#include <WProgram.h>
#endif
#include <Wire.h>
#include "robot_specs.h"

#define right_encoderA      19     // (interrupt numbers 0)
#define right_encoderB      18    // (interrupt numbers 1)

#define ENA1 5
#define Right_in1 6
#define Right_in2 7

volatile long right_count = 0;

void setup() {
  Serial.begin(9600);
  setupEncoders();
}
void loop() {  
  
  
   Serial.print("      ");Serial.print(right_count);
   Serial.println("      ");   
}
