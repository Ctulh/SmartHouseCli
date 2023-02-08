//
// Created by ctuh on 2/8/23.
//

#include "Utils/RGBOperations.hpp"

std::tuple<uint8_t, uint8_t, uint8_t> RGBOperations::IntToRGB(uint32_t rgbValue) {
    uint8_t red   = (rgbValue >> 16);
    uint8_t green = (rgbValue >> 8);
    uint8_t blue  = (rgbValue);
    return {red, green, blue};
}

uint32_t RGBOperations::RGBToInt(uint8_t red, uint8_t green, uint8_t blue) {
    uint32_t result = 0;
    auto eightBitPtr = static_cast<char*>(static_cast<void*>(&result));
    result = (result << 8) + red;
    result = (result << 8) + green;
    result = (result << 8) + blue;
    return result;
}