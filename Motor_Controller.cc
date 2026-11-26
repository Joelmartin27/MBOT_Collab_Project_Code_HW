#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "Motor_Controller.h"
 
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
Adafruit_DCMotor *lMotor = AFMS.getMotor(1);
Adafruit_DCMotor *rMotor = AFMS.getMotor(2);

int time = millis();
int delay = 1000;
int timeSinceDelay;

void Motors::motorSetup(){

  AFMS.begin();
  lMotor->setSpeed(motorSpeed);
  rMotor ->setSpeed(motorSpeed);
  time = millis();
  timeSinceDelay = millis();

}

void Motors::motorLoop(){
  timeSinceDelay = millis();
Motors::wait();
Motors::forward();
Motors::wait();
Motors::wait();
Motors::reverse();
Motors::wait();
Motors::stop();
}

Motors::wait(){
  if(timeSinceDelay - time <= delay){
    return
  }else{
    timeSinceDelay = millis();
  }
}

Motors::forward(){
  lMotor->run(FORWARD);
  rMotor->run(FORWARD);
}

Motors::reverse(){
  lMotor->run(BACKWARD);
  rMotor->run(BACKWARD);
}

Motors::pivotLeft(){
  lMotor->run(BACKWARD);
  rMotor->run(FORWARD);
}

Motors::pivotRight(){
  lMotor->run(FORWARD);
  rMotor->run(BACKWARD);
}

Motors::turnLeft(){
  lMotor->setSpeed(0);
  rMotor->run(FORWARD);
}

Motors::turnRight(){
  lMotor->run(FORWARD);
  rMotor->setSpeed(0);
}

Motors::stop(){
  lMotor->setSpeed(0);
  rMotor->setSpeed(0);
}