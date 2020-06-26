/* Author: Pyae Soan Aung (Ghostman @ greenhackers)
*/
#if (ARDUINO >= 100)
#include <Arduino.h>
#else
#include <WProgram.h>
#endif
#include <Wire.h>
#include "robot_specs.h"

#define right_encoderA      19    // (interrupt numbers 0)
#define right_encoderB      18    // (interrupt numbers 1)

#define ENA1 5                    // PWM
#define Right_in1 6
#define Right_in2 7

// ********************* PID ******************** //
  float Kp = 0.32355;    
  //float Ki = 0.0;
  float Ki = 0.00000001;
  float Kd = 1.1;
 
/*
 * float Kp = 0.750
 * float Kd = 1.55;; 
 */
// ********************************************** //

unsigned long lastMilli = 0;       // loop timing
int PWM_right = 0;

volatile long right_count = 0;
long prev_right_count = 0;

double RPM_act_right = 0;  // Actual
double RPM_req_right_1 = 100; // Desire
//double RPM_req_right_2 = 50; // Desire
//double RPM_req_right_3 = 150; // Desire
//double RPM_req_right_4 = 80; // Desire
void setup() {  
  //TCCR0B = TCCR0B & B11111000 | B00000001;   // 62500
  //TCCR0B = TCCR0B & B11111000 | B00000010;     // 7812
  //TCCR0B = TCCR0B & B11111000 | B00000011;     // 976
  //TCCR0B = TCCR0B & B11111000 | B00000100;     // 244
  //TCCR0B = TCCR0B & B11111000 | B00000101;     // 61
  //TCCR5B = TCCR5B & B11111000 | B00000101;     // 30
  Serial.begin(9600);
  setupMotors();
  setupEncoders();
}
void loop() {  

    
  unsigned long time_ = millis();
  if (time_ - lastMilli >= 100)   
  {     
    int x = time_ - lastMilli;
    getMotorData(x);  

    PWM_right = updatePid(PWM_right, RPM_req_right_1, RPM_act_right);

    if (PWM_right > 0 ) {
      Forward();
    }
    else if (PWM_right < 0 ) {
      Backward();
    }

    if (PWM_right == 0 ) {
      Release();
    }
    
    lastMilli = time_;
  }
  
   Serial.print("      ");Serial.print(int(RPM_act_right));
   Serial.print("      ");Serial.print(int(RPM_req_right_1));
   Serial.println("      ");   
}
