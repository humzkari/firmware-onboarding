#include "BMEI2CInterface.h"

#include <BMEConstants.h>
#include <Wire.h>

bool BMEI2CInterface::begin() {
    Wire.begin();
    return sensor.begin(BME280_I2C_ADDRESS, &Wire);
}

float BMEI2CInterface::readTemperatureCelsius() {
    return sensor.readTemperature();
}
