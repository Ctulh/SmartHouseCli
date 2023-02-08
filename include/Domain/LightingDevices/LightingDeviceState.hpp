
#pragma once

#include <cstdint>
#include <algorithm>

#include "Domain/BasicDeviceInfo.hpp"
#include "Domain/DeviceProperty.hpp"

struct RGB {
    uint8_t red = 0;
    uint8_t green = 0;
    uint8_t blue = 0;
};

struct LightingDeviceState {
    LightingDeviceState() = default;
    LightingDeviceState(StateValueType const& deviceState);

public:
    bool isTurnedOn;
    uint16_t brightness;
    uint16_t colorTemperature;
    RGB color;
};