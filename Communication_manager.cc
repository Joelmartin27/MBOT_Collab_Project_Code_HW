#include <Arduino.h>
#include <ArduinoBLE.h>
#include "CO2Sensor.cc"
#include "PH_Sensor.cc"

class CommunicationManager {

private:
  BLEService sensorService = BLEService("4bf6ccce-1ff5-4268-ba69-299822b58095");
  BLEByteCharacteristic phCharacteristic = BLEByteCharacteristic("8e5b1341-36a3-4cc3-be1a-94d84b0c7b30", BLERead);
  BLEByteCharacteristic coCharacteristic = BLEByteCharacteristic("6ccd8da6-f004-4bdf-af31-c8423474392f", BLERead);
  BLEDevice central;

public:

  CommunicationManager() {}

  void setup() {
    BLE.begin();
    BLE.setLocalName("DWALL-E");
    BLE.setAdvertisedService(sensorService);
    sensorService.addCharacteristic(phCharacteristic);
    sensorService.addCharacteristic(coCharacteristic);
    BLE.addService(sensorService);
    BLE.advertise();
  }

  bool hasCentral() {
    // if (central) return true;
    // listen for Bluetooth® Low Energy peripherals to connect:
    central = BLE.central();

    // if a central is connected to peripheral:
    if (central) {
      // Serial.print("Connected to central: ");
      // print the central's MAC address:
      // Serial.println(central.address());
      return true;
    }
    return false;
  }

  void updateCOCharacteristic(CO2Sensor co2Sensor) {
    coCharacteristic.writeValue(co2Sensor.read());
  }

  void updatePHCharacteristic(PHsensor phsensor) {
    phCharacteristic.writeValue(phsensor.read());
  }
};