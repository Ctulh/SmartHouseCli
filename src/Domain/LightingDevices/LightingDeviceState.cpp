//
// Created by ctuh on 2/8/23.
//

#include "Domain/LightingDevices/LightingDeviceState.hpp"
#include "Utils/StringOperations.hpp"
#include "Utils/RGBOperations.hpp"

LightingDeviceState::LightingDeviceState(const StateValueType &deviceState) {
    if(deviceState.find(DeviceProperty::POWER) != deviceState.end()) {
        auto powerValue = deviceState.at(DeviceProperty::POWER);
        isTurnedOn = (powerValue == "on");
    }
    if(deviceState.find(DeviceProperty::BRIGHT) != deviceState.end()) {
        auto brightnessValue = deviceState.at(DeviceProperty::BRIGHT);
        if(StringOperations::isStringANumber(brightnessValue)) {
            brightness = std::stoi(brightnessValue);
        }
        else {
            brightness = 0;
        }
    }
    if(deviceState.find(DeviceProperty::COLOR_TEMPERATURE) != deviceState.end()) {
        auto colorTemperatureValue = deviceState.at(DeviceProperty::COLOR_TEMPERATURE);
        if(StringOperations::isStringANumber(colorTemperatureValue)) {
            colorTemperature = std::stoi(colorTemperatureValue);
        }
        else {
            colorTemperature = 0;
        }
    }
    if(deviceState.find(DeviceProperty::POWER) != deviceState.end()) {
        auto rgbValue = deviceState.at(DeviceProperty::COLOR);
        if(StringOperations::isStringANumber(rgbValue)) {
            auto result  = RGBOperations::IntToRGB(std::stoi(rgbValue));
            color.red   = get<0>(result);
            color.green = get<1>(result);
            color.blue  = get<2>(result);
        }
    }
}