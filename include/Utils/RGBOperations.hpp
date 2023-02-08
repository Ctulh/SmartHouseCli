
#pragma once

#include <cinttypes>
#include <tuple>

class RGBOperations {
public:
    RGBOperations() = delete;
public:
    static uint32_t RGBToInt(uint8_t red, uint8_t green, uint8_t blue);
    static std::tuple<uint8_t, uint8_t, uint8_t> IntToRGB(uint32_t rgbValue);
};