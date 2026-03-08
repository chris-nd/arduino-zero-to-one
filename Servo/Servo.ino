#include <Servo.h>;

Servo servoMotor;

int pos = 9;


void setup() {
  // put your setup code here, to run once:
  servoMotor.attach(9);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (pos=0; pos <= 180; pos++) {
    servoMotor.write(pos);
    delay(5);
  }

  for (pos; pos >= 0; pos--) {
    servoMotor.write(pos);
    delay(5);
  }
  
}
