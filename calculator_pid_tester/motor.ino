void setupMotors() {
  actual_rpm = 0;
  

  digitalWrite(Right_in1, LOW);
  digitalWrite(Right_in2, HIGH);
}

void getMotorData(unsigned long time_t)  
{
  actual_rpm = double( (encoder_ticks - prev_encoder_ticks) * 60000 ) / double( time_t * enc_ticks );  
  prev_encoder_ticks = encoder_ticks;
}

int updatePid(int old_pwm, double targetRPM, double currentRPM,long dT) {
  double pidTerm = 0; 
  double error = 0;
  double new_rpm = 0;
  double new_pwm = 0;
  static double last_error = 0;
  static double int_error = 0;
  float dt = dT/1000.0;
  error = targetRPM - currentRPM;   
    int_error += (error*dt);    
    pidTerm = Kp * error + Ki * int_error + Kd * ((error - last_error)/dt);    
    last_error = error;
  new_pwm = constrain(double(old_pwm) + pidTerm, -255, 255);
  
  return int(new_pwm);
}

void Forward() {
  digitalWrite(Right_in1, LOW);
  digitalWrite(Right_in2, HIGH);  
  analogWrite(ENA1, abs(pwm_value));  
}

void Backward() {
  digitalWrite(Right_in1, HIGH);
  digitalWrite(Right_in2, LOW);
  analogWrite(ENA1, abs(pwm_value));
}

void Release() {
  digitalWrite(Right_in1, LOW);
  digitalWrite(Right_in2, LOW);
  analogWrite(ENA1, 0);
}
