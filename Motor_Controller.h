class Motors {

  void motorSetup();
  void motorLoop(motorSpeed);
  wait();
  turnLeft();
  turnRight();
  pivotLeft();
  pivotRight();
  forward();
  reverse();
  stop();


private:
  int motorSpeed = 255;
};
