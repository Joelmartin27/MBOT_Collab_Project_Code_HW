#include "CO2Sensor.cc"

// create sensor
CO2Sensor co2Sensor(A0);

void setup() {
  Serial.begin(9600);
}
void loop() {
  int pollution = co2Sensor.read();
  Serial.println(pollution);
  delay(100);
}
