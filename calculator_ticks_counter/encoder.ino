void setupEncoders() {

  right_count = 0;

  pinMode(right_encoderA, INPUT);
  pinMode(right_encoderB, INPUT);

  digitalWrite(right_encoderA, LOW);
  digitalWrite(right_encoderB, LOW);

  attachInterrupt(digitalPinToInterrupt(right_encoderA), calculate_right_A, CHANGE);
  attachInterrupt(digitalPinToInterrupt(right_encoderB), calculate_right_B, CHANGE);
}

void calculate_right_A() {
  if (digitalRead(right_encoderA) == digitalRead(right_encoderB)) {
    right_count = right_count - 1;
  }
  else                                                     {
    right_count = right_count + 1;
  }
}
void calculate_right_B() {
  if (digitalRead(right_encoderA) == digitalRead(right_encoderB)) {
    right_count = right_count + 1;
  }
  else                                                     {
    right_count = right_count - 1;
  }
}
