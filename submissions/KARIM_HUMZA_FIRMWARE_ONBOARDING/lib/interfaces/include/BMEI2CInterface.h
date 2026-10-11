#pragma once

#include <Adafruit_BME280.h>

class BMEI2CInterface {
public:
    bool begin();
    float readTemperatureCelsius();

private:
    Adafruit_BME280 sensor;
};
