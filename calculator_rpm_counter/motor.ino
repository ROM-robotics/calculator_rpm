void setupMotors() {
  RPM_act_right = 0;

  pinMode(Right_in1, OUTPUT);
  pinMode(Right_in2, OUTPUT);
  
  digitalWrite(Right_in1, LOW);
  digitalWrite(Right_in2, HIGH);
}
void getMotorData(unsigned long time)  {
  RPM_act_right = int(double((right_count - prev_right_count) * 60000) / double(time * enc_ticks));
  prev_right_count = right_count;
}
