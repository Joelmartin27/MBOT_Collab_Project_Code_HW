#include "CO2Sensor.cc"
#include "PH_Sensor.cc"

// create sensor
CO2Sensor co2Sensor(A0);
PHsensor phsensor(A1);

void setup() {
  Serial.begin(9600);
}
void loop() {
  int pollution = co2Sensor.read();
  Serial.println(pollution);
  delay(100);
  int ph = phsensor.read();
  Serial.println(ph);
}
