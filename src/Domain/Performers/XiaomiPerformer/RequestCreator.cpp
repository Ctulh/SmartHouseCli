//
// Created by ctuh on 2/1/23.
//

#include <sstream>

#include "Domain/Performers/XiaomiPerformer/RequestCreator.hpp"

std::string RequestCreator::turnOn(std::string const& effect, int duration) {
    std::stringstream ss;
    ss << "{"
             "\"id\":1,"
             "\"method\":\"set_power\","
             "\"params\":[\"on\", \"" + effect + "\", " + std::to_string(duration) + "]"
          "}\r\n";
    return ss.str();
}

std::string RequestCreator::turnOff(const std::string &effect, int duration) {
    std::stringstream ss;
    ss << "{"
             "\"id\":1,"
             "\"method\":\"set_power\","
             "\"params\":[\"off\", \"" + effect + "\", " + std::to_string(duration) + "]"
          "}\r\n";
    return ss.str();
}

std::string RequestCreator::toggle() {
    std::stringstream ss;
    ss << "{"
             "\"id\":1,"
             "\"method\":\"toggle\","
             "\"params\":[]"
          "}\r\n";
    return ss.str();
}

std::string RequestCreator::setBrightness(int brightness, const std::string &effect, int duration) {
    if(brightness <= 0)
        brightness = 1;

    std::stringstream ss;
    ss << "{"
            "\"id\":1,"
            "\"method\":\"set_bright\","
            "\"params\":[" + std::to_string(brightness) + ", \"" + effect + "\", " + std::to_string(duration) + "]"
          "}\r\n";
    return ss.str();
}

std::string RequestCreator::setColorTemperature(int ctValue, const std::string &effect, int duration) {
    if(ctValue < 1700)
        ctValue = 1700;
    else if(ctValue > 6500)
        ctValue = 6500;

    std::stringstream ss;
    ss << "{"
          "\"id\":1,"
          "\"method\":\"set_ct_abx\","
          "\"params\":[" + std::to_string(ctValue) + ", \"" + effect + "\", " + std::to_string(duration) + "]"
                                                                                                              "}\r\n";
    return ss.str();
}

std::string RequestCreator::setColor(uint8_t red, uint8_t green, uint8_t blue, const std::string &effect, int duration) {
    auto colorValue = getIntFromRGB(red, green, blue);
    std::stringstream ss;
    ss << "{"
          "\"id\":1,"
          "\"method\":\"set_rgb\","
          "\"params\":[" + std::to_string(colorValue) + ", \"" + effect + "\", " + std::to_string(duration) + "]"
                                                                                                           "}\r\n";
    return ss.str();
}

uint32_t RequestCreator::getIntFromRGB(uint8_t red, uint8_t green, uint8_t blue) {
    uint32_t result = 0;

    auto eightBitPtr = static_cast<char*>(static_cast<void*>(&result));
    *(eightBitPtr++) = blue;
    *(eightBitPtr++) = green;
    *(eightBitPtr) = red;
    return result;
}