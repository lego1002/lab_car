#include <AFMotor.h>

AF_DCMotor LF_motor(1);  // 左前
AF_DCMotor LB_motor(2);  // 左后
AF_DCMotor RB_motor(3);  // 右后
AF_DCMotor RF_motor(4);  // 右前

void mecanum_drive(int speed_FL, int speed_FR, int speed_RL, int speed_RR) {
  if (speed_FL >= 0) {
    LF_motor.run(BACKWARD);  // LF backward is forward
    LF_motor.setSpeed(speed_FL);
  } else {
    LF_motor.run(FORWARD);  // LF forward is backward
    LF_motor.setSpeed(-speed_FL);
  }

  if (speed_FR >= 0) {
    LB_motor.run(FORWARD);
    LB_motor.setSpeed(speed_FR);
  } else {
    LB_motor.run(BACKWARD);
    LB_motor.setSpeed(-speed_FR);
  }

  if (speed_RL >= 0) {
    RF_motor.run(FORWARD);
    RF_motor.setSpeed(speed_RL);
  } else {
    RF_motor.run(BACKWARD);
    RF_motor.setSpeed(-speed_RL);
  }

  if (speed_RR >= 0) {
    RB_motor.run(BACKWARD);  // RB backward is forward
    RB_motor.setSpeed(speed_RR);
  } else {
    RB_motor.run(FORWARD);  // RB forward is backward
    RB_motor.setSpeed(-speed_RR);
  }
}

void setup() {
  Serial.begin(115200);

  LF_motor.setSpeed(0);
  LB_motor.setSpeed(0);
  RF_motor.setSpeed(0);
  RB_motor.setSpeed(0);
}

void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read();

    // 根據接收到的指令進行遙控車的控制
    switch (command) {
      case 't':
        mecanum_drive(-130, 130, 130, -130);   // 向前
        break;
      case 'b':
        mecanum_drive(130, -130, -130, 130);   // 向後
        break;
      case 'r':
        mecanum_drive(-130, 130, 0, 0);        // 左前
        break;
      case 'y':
        mecanum_drive(0, 0, 130, -130);        // 右前
        break;
      case 'f':
        mecanum_drive(130, 0, -130, 0);        // 左移
        break;
      case 'h':
        mecanum_drive(0, -130, 0, 130);        // 右移
        break;
      case 'v':
        mecanum_drive(0, 0, 130, -130);        // 左後
        break;
      case 'n':
        mecanum_drive(130, -130, 0, 0);        // 右後
        break;
      case 'g':
        mecanum_drive(0, 0, 0, 0);    // 停止
        break;
      default:
        mecanum_drive(0, 0, 0, 0);    // 默認為停止
        break;
    }
    delay(1500);  // 控制响应时间
  }
}
www