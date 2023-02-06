
#pragma once

#include <string>

namespace {
    constexpr int defaultDuration = 500;
    constexpr auto defaultEffect = "smooth";
}

class RequestCreator {
public:
    RequestCreator() = delete;
public:
    static std::string turnOn(std::string const& effect = ::defaultEffect, int duration = ::defaultDuration);
    static std::string turnOff(std::string const& effect = ::defaultEffect, int duration = ::defaultDuration);
    static std::string toggle();
    static std::string setBrightness(int brightness, std::string const& effect = ::defaultEffect, int duration = ::defaultDuration);
    static std::string setColorTemperature(int ctValue, std::string const& effect = ::defaultEffect, int duration = ::defaultDuration);
    static std::string setColor(uint8_t red, uint8_t  green, uint8_t  blue, std::string const& effect = ::defaultEffect, int duration = ::defaultDuration);

public:
    static uint32_t getIntFromRGB(uint8_t red, uint8_t green, uint8_t blue);
};
