void setupMotors() {
  RPM_act_right = 0;
  

  digitalWrite(Right_in1, LOW);
  digitalWrite(Right_in2, HIGH);
}
void getMotorData(unsigned long time)  {
  RPM_act_right = double((right_count - prev_right_count) * 60000) / double(time * enc_ticks);
  prev_right_count = right_count;
}

int updatePid(int old_pwm, double targetRPM, double currentRPM) {
  double pidTerm = 0; 
  double error = 0;
  double new_rpm = 0;
  double new_pwm = 0;
  static double last_error = 0;
  static double int_error = 0;

  error = targetRPM - currentRPM;   
    int_error += error;
    if(int_error > 1000) { int_error = 1000;}
    else if(int_error < -1000) {int_error=-1000;}    
    pidTerm = Kp * error + Ki * int_error + Kd * (error - last_error);    
    last_error = error;
  new_pwm = constrain(double(old_pwm) + pidTerm, -MAX_RPM, MAX_RPM);
  
  return int(new_pwm);
}

void Forward() {
  digitalWrite(Right_in1, LOW);
  digitalWrite(Right_in2, HIGH);  
  analogWrite(ENA1, abs(PWM_right));  
}

void Backward() {
  digitalWrite(Right_in1, HIGH);
  digitalWrite(Right_in2, LOW);
  analogWrite(ENA1, abs(PWM_right));
}

void Release() {
  digitalWrite(Right_in1, LOW);
  digitalWrite(Right_in2, LOW);
  analogWrite(ENA1, 0);
}

//  float Kp = 0.47;    // Left
//  float Ki =  0.00052;
//  float Kd =   1.9;
//  float p =   0.65;
//  float i =   0.00005;
//  float d =   0.6;
