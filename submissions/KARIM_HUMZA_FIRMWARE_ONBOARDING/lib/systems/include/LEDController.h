#pragma once

#include <Arduino.h>

class LEDController {
public:
    void begin();
    void setTemperature(float temperatureCelsius);
    void update();

private:
    uint32_t blinkInterval = 1000;
    uint32_t lastToggleMillis = 0;
    bool ledIsOn = false;
};
