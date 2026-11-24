#include <Arduino.h>

class PHsensor {
private:
  int pin;

public:
  PHsensor(int pin) {
    this->pin = pin;
  }

  int read() {
    // int val;
    // val = analogRead(pin);
    // int ph = map(val, 0, 1023, 0, 14);
    // return ph;
    float measure = analogRead(pin);       //Read pin A0
    double voltage = measure * 5 / 1024;  //Analog-to-Digital Conversion

    // PH_step (Voltage/pH Unit) = (Voltage@PH7-Voltage@PH4)/(PH7 - PH4)
    float pH = 7 + ((2.5 - voltage) / 0.1841);
    return pH;
  }
};
