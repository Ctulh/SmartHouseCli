
#pragma once

#include <string>

namespace {
    int defaultDuration = 500;
}

class RequestCreator {
public:
    RequestCreator() = delete;
public:
    static std::string turnOn(std::string const& effect = "smooth", int duration = ::defaultDuration);
    static std::string turnOff(std::string const& effect = "smooth", int duration = ::defaultDuration);
    static std::string toggle();
    static std::string setBrightness(int brightness, std::string const& effect = "smooth", int duration = ::defaultDuration);
};
