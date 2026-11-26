#include "CO2Sensor.cc"
#include "PH_Sensor.cc"
#include "Communication_manager.cc"
#include "Motor_Controller.h"


// create sensor
CO2Sensor co2Sensor(A0);
PHsensor phsensor(A1);
CommunicationManager communicationmanager = CommunicationManager();

//Create Motor
Motors motorController = Motors();

void setup() {
  Serial.begin(9600);
  communicationmanager.setup();
  motorController.motorSetup();
}
void loop() {
  int pollution = co2Sensor.read();
  Serial.println(pollution);
  if (communicationmanager.hasCentral()) {
    communicationmanager.updateCOCharacteristic(co2Sensor);
    communicationmanager.updatePHCharacteristic(phsensor);
  }

  // delay(100);

  int ph = phsensor.read();
  Serial.println(ph);

  motorController.motorLoop();
}
