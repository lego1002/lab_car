#include <AFMotor.h>

AF_DCMotor motor(3);
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor4(4);

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  motor.setSpeed(200);
  motor1.setSpeed(200);
  motor2.setSpeed(200);
  motor4.setSpeed(200);

  motor.run(FORWARD);
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor4.run(FORWARD);

  delay(2000);

  motor.run(RELEASE);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor4.run(RELEASE);

  delay(1000);

  motor.run(BACKWARD);
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor4.run(BACKWARD);

  delay(2000);

  motor.run(RELEASE);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor4.run(RELEASE);

  delay(1000);

}
