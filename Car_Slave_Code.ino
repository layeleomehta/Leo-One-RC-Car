#include<AFMotor.h>

AF_DCMotor motor1(1); //front right wheel
AF_DCMotor motor2(2); //front left wheel
AF_DCMotor motor3(3); //back left wheel
AF_DCMotor motor4(4); //back right wheel

int ascii_reader = 0; 


void setup() {
  // put your setup code here, to run once:

  Serial.begin(38400);
}

void loop() {
  // put your main code here, to run repeatedly:

  if(Serial.available() > 0)
  {
    ascii_reader = Serial.read(); 
  }

  
  if(ascii_reader == '4') //don't move at all
  {
    motor1.run(RELEASE); 
    motor2.run(RELEASE); 
    motor3.run(RELEASE); 
    motor4.run(RELEASE); 
    motor1.setSpeed(0); 
    motor2.setSpeed(0); 
    motor3.setSpeed(0); 
    motor4.setSpeed(0);
    ascii_reader = 0; 
    delay(2000); 
  }
  
  else if(ascii_reader == '0') //move fwd
  {
    motor1.run(FORWARD); 
    motor2.run(FORWARD); 
    motor3.run(FORWARD); 
    motor4.run(FORWARD);
    motor1.setSpeed(150); 
    motor2.setSpeed(150); 
    motor3.setSpeed(150); 
    motor4.setSpeed(150); 
    ascii_reader = 0; 
    delay(1000);
  }

  else if(ascii_reader == '1') //move bckwd
  {
    motor1.run(BACKWARD); 
    motor2.run(BACKWARD); 
    motor3.run(BACKWARD); 
    motor4.run(BACKWARD);
    motor1.setSpeed(150); 
    motor2.setSpeed(150); 
    motor3.setSpeed(150); 
    motor4.setSpeed(150); 
    ascii_reader = 0; 
    delay(1000);
  }

  else if(ascii_reader == '2') //move fwd right
  {
    motor1.run(RELEASE); //turn off front right motor, so car turns fwd right. 
    motor2.run(FORWARD); 
    motor3.run(FORWARD); 
    motor4.run(FORWARD);
    motor1.setSpeed(0); 
    motor2.setSpeed(150); 
    motor3.setSpeed(150); 
    motor4.setSpeed(150);
    ascii_reader = 0; 
    delay(1000);
  }

  else if(ascii_reader == '3') //move fwd left
  {
    motor1.run(FORWARD); 
    motor2.run(RELEASE); //turn off front left motor, so car turns fwd right. 
    motor3.run(FORWARD); 
    motor4.run(FORWARD);
    motor1.setSpeed(150); 
    motor2.setSpeed(0); 
    motor3.setSpeed(150); 
    motor4.setSpeed(150);
    ascii_reader = 0; 
    delay(1000);
  }

}
