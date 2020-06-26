void setupMotors() {
  RPM_act_right = 0;
  PWM_right = V_12;

  digitalWrite(Right_in1, LOW);
  digitalWrite(Right_in2, HIGH);
}
void getMotorData(unsigned long time)  {
  RPM_act_right = double((right_count - prev_right_count) * 60000) / double(time * enc_ticks);
  prev_right_count = right_count;
}
