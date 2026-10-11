#include <Arduino.h>

#include <BMESPIInterface.h>
#include <LEDController.h>

namespace {
BMESPIInterface temperatureSensor;
LEDController ledController;
uint32_t lastReadMillis = 0;
constexpr uint32_t TEMPERATURE_READ_INTERVAL_MS = 1000;
}

void setup() {
    Serial.begin(115200);

    if (!temperatureSensor.begin()) {
        Serial.println("Could not find a BME280 sensor over SPI.");
        while (true) {
        }
    }

    ledController.begin();
    lastReadMillis = millis();
}

void loop() {
    const uint32_t currentMillis = millis();
    if (currentMillis - lastReadMillis >=
        TEMPERATURE_READ_INTERVAL_MS) {
        const float temperature =
            temperatureSensor.readTemperatureCelsius();
        ledController.setTemperature(temperature);

        Serial.print("Temperature: ");
        Serial.print(temperature);
        Serial.println(" C");

        lastReadMillis = currentMillis;
    }

    ledController.update();
}
