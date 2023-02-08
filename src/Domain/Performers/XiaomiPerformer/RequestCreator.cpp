//
// Created by ctuh on 2/1/23.
//

#include <sstream>

#include "Domain/Performers/XiaomiPerformer/RequestCreator.hpp"
#include "Utils/RGBOperations.hpp"

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
    auto colorValue = RGBOperations::RGBToInt(red, green, blue);
    std::stringstream ss;
    ss << "{"
          "\"id\":1,"
          "\"method\":\"set_rgb\","
          "\"params\":[" + std::to_string(colorValue) + ", \"" + effect + "\", " + std::to_string(duration) + "]"
                                                                                                           "}\r\n";
    return ss.str();
}

std::string RequestCreator::getDeviceProperties(DeviceProperties const& deviceProperties) {
    std::stringstream ss;
    ss << "{"
          "\"id\":1,"
          "\"method\":\"get_prop\","
          "\"params\":[";

        for(auto property: deviceProperties) {
            ss << "\"" << devicePropertyToString(property) << "\"" << ",";
        }

        auto stringWithoutLastComma = ss.str().substr(0, ss.str().size()-1);
        ss.str("");
        ss << stringWithoutLastComma;

       ss <<"]"
           "}\r\n";
    return ss.str();
}

std::string RequestCreator::devicePropertyToString(DeviceProperty deviceProperty) {
    switch(deviceProperty) {
        case DeviceProperty::POWER: return "power";
        case DeviceProperty::BRIGHT: return "bright";
        case DeviceProperty::COLOR_TEMPERATURE: return "ct";
        case DeviceProperty::COLOR: return "rgb";
        case DeviceProperty::HUE: return "hue";
        case DeviceProperty::SATURATION: return "sat";
        case DeviceProperty::COLOR_MODE: return "color_mode";
        default: return "not_exist";
    }
}
