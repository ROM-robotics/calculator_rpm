/* Author: Pyae Soan Aung (ROM Robotics) */


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
int pwm_value = 0;

volatile long encoder_ticks = 0;
long prev_encoder_ticks = 0;

double actual_rpm = 0;  
double desire_rpm = 20; 

void setup() {  
  //changePwmFrequency();
  Serial.begin(9600);
  setupMotors();
  setupEncoders();
}
void loop() {  

    
  unsigned long time_ = millis();
  if (time_ - lastMilli >= 100)   
  {     
    long delta_t = time_ - lastMilli;
    getMotorData(delta_t);  

    //pwm_value = 100;
    pwm_value = updatePid(pwm_value, desire_rpm, actual_rpm,delta_t);

    if (pwm_value > 0 ) {
      Forward();
    }
    else if (pwm_value < 0 ) {
      Backward();
    }

    if (pwm_value == 0 ) {
      Release();
    }
    
    lastMilli = time_;
    
  }
   //Serial.print("      ");Serial.print(0);
   //Serial.print("      ");Serial.print(100);  
   
   //Serial.print("      ");Serial.print(time_);  
   Serial.print("      ");Serial.print(int(actual_rpm));
   Serial.print("      ");Serial.print(int(desire_rpm));
   Serial.println("      ");   
}
