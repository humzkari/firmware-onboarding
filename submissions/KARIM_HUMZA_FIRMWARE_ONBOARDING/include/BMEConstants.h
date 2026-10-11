#pragma once

#include <Arduino.h>

// Use address 0x76 with SDO connected to ground.
constexpr uint8_t BME280_I2C_ADDRESS = 0x76;

// SPI uses Uno pins 11, 12, and 13, with pin 10 for chip select.
constexpr uint8_t BME280_SPI_CHIP_SELECT_PIN = 10;
