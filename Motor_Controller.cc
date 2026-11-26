#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "Motor_Controller.h"

Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_DCMotor *lMotor = AFMS.getMotor(1);
Adafruit_DCMotor *rMotor = AFMS.getMotor(2);




void Motors::motorSetup() {

  AFMS.begin();
  lMotor->setSpeed(motorSpeed);
  rMotor->setSpeed(motorSpeed);
  time = millis();
  timeSinceDelay = millis();
}

void Motors::motorLoop() {
  timeSinceDelay = millis();
  wait();
  forward();
  wait();
  wait();
  reverse();
  wait();
  stop();
}

bool Motors::wait() {
  if (time - timeSinceDelay <= delay) return true;
  timeSinceDelay = millis();
  return false;
}

void Motors::forward() {
  lMotor->run(FORWARD);
  rMotor->run(FORWARD);
}

void Motors::reverse() {
  lMotor->run(BACKWARD);
  rMotor->run(BACKWARD);
}

void Motors::pivotLeft() {
  lMotor->run(BACKWARD);
  rMotor->run(FORWARD);
}

void Motors::pivotRight() {
  lMotor->run(FORWARD);
  rMotor->run(BACKWARD);
}

void Motors::turnLeft() {
  lMotor->setSpeed(0);
  rMotor->run(FORWARD);
}

void Motors::turnRight() {
  lMotor->run(FORWARD);
  rMotor->setSpeed(0);
}

void Motors::stop() {
  lMotor->setSpeed(0);
  rMotor->setSpeed(0);
}