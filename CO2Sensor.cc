#include <Arduino.h>

// define code structure for sensor
class CO2Sensor {
private:
  int pin;

public:
  CO2Sensor(int pin) {
    this->pin = pin;
  }

  int read() {
    int val;
    val = analogRead(pin);  //Read Gas value from analog 0
    int pollution = map(val, 0, 1023, 20, 2000);
    return pollution;
  }
};