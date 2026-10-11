#include "LEDController.h"

namespace {
constexpr float MIN_TEMPERATURE_CELSIUS = -10.0F;
constexpr float MAX_TEMPERATURE_CELSIUS = 50.0F;
constexpr uint32_t SLOW_BLINK_INTERVAL_MS = 1000;
constexpr uint32_t FAST_BLINK_INTERVAL_MS = 100;
}

void LEDController::begin() {
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, LOW);
    ledIsOn = false;
    lastToggleMillis = millis();
}

void LEDController::setTemperature(float temperatureCelsius) {
    if (temperatureCelsius < MIN_TEMPERATURE_CELSIUS) {
        temperatureCelsius = MIN_TEMPERATURE_CELSIUS;
    } else if (temperatureCelsius > MAX_TEMPERATURE_CELSIUS) {
        temperatureCelsius = MAX_TEMPERATURE_CELSIUS;
    }

    const float tempRange =
        MAX_TEMPERATURE_CELSIUS - MIN_TEMPERATURE_CELSIUS;
    const float tempRatio =
        (temperatureCelsius - MIN_TEMPERATURE_CELSIUS) / tempRange;
    const float intervalRange =
        SLOW_BLINK_INTERVAL_MS - FAST_BLINK_INTERVAL_MS;

    // A higher temperature gives a shorter blink interval.
    blinkInterval = static_cast<uint32_t>(
        SLOW_BLINK_INTERVAL_MS - tempRatio * intervalRange);
}

void LEDController::update() {
    const uint32_t currentMillis = millis();
    if (currentMillis - lastToggleMillis < blinkInterval) {
        return;
    }

    ledIsOn = !ledIsOn;
    digitalWrite(LED_BUILTIN, ledIsOn ? HIGH : LOW);
    lastToggleMillis = currentMillis;
}
