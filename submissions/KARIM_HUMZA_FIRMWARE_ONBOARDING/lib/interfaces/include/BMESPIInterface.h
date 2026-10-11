#pragma once

#include <Adafruit_BME280.h>

class BMESPIInterface {
public:
    BMESPIInterface();

    bool begin();
    float readTemperatureCelsius();

private:
    Adafruit_BME280 sensor;
};
