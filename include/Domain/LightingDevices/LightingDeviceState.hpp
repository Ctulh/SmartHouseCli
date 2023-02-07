
#pragma once

#include <stdint.h>

struct RGB {
    uint8_t red;
    uint8_t green;
    uint8_t blue;
};

struct LightingDeviceState {
    uint8_t brightness;
    uint16_t colorTemperature;
    RGB color;
};