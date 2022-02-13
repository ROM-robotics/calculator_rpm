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

//#define right_encoderA      3
//#define right_encoderB      2
//#define ENA1 10
//#define Right_in1 8
//#define Right_in2 9

unsigned long lastMilli = 0;       // loop timing
int PWM_right = 0;

int V_12 = 255;
int V_6  = 128;
int V_3  = 64;

volatile long right_count = 0;
long prev_right_count = 0;

double RPM_act_right = 0;

void setup() {
  Serial.begin(9600);
  setupMotors();
  setupEncoders();
}
void loop() {  
  analogWrite(ENA1, 255);
    
  unsigned long time_ = millis();
  if (time_ - lastMilli >= 100)   
  {  // enter timed loop ( 100 ms or greater)
    
    int x = time_ - lastMilli;
    getMotorData(x);  

    lastMilli = time_;
    Serial.print("      ");Serial.print(RPM_act_right);
    //Serial.print("      ");Serial.print(right_count);
    Serial.println("      ");   
  }
  
   
}
