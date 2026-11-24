#include <Arduino.h>

class PHsensor {
  private:
  int pin;

  public:
  PHsensor(int pin) {
    this->pin = pin;
  }

  int read(){
    int val;
    val = analogRead(pin);
    int ph = map(val, 0, 1023, 0, 14);
    return ph;
  }
};
