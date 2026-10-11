#include "BMESPIInterface.h"

#include <BMEConstants.h>

BMESPIInterface::BMESPIInterface()
    : sensor(BME280_SPI_CHIP_SELECT_PIN) {}

bool BMESPIInterface::begin() {
    return sensor.begin();
}

float BMESPIInterface::readTemperatureCelsius() {
    return sensor.readTemperature();
}
