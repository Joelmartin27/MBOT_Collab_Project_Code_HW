class Motors {
public:
  void motorSetup();
  void motorLoop();
  bool wait();
  void turnLeft();
  void turnRight();
  void pivotLeft();
  void pivotRight();
  void forward();
  void reverse();
  void stop();


private:
  int motorSpeed = 0;
  int time = 0;
  const int delay = 1000;
  int timeSinceDelay;
};
