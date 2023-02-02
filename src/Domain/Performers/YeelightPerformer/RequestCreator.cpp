//
// Created by ctuh on 2/1/23.
//

#include <sstream>

#include "Domain/Performers/YeelightPerformer/RequestCreator.hpp"

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
