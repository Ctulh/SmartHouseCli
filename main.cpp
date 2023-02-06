#include <iostream>

#include "Domain/ILightingDevice.hpp"
#include "Domain/Impl/LightingDevice.hpp"
#include "Domain/Impl/IPerformer.hpp"
#include "Domain/Performers/YeelightPerformer/XiaomiPerformer.hpp"
#include "Domain/Impl/LightGroupImpl.hpp"
#include "Domain/Impl/LightingDeviceColor.hpp"
#include <signal.h>
#include <thread>

int main() {
    signal(SIGPIPE, SIG_IGN);
    auto performer1 = std::make_unique<XiaomiPerformer>();
    auto performer2 = std::make_unique<XiaomiPerformer>();
    auto performer3 = std::make_unique<XiaomiPerformer>();

    BasicDeviceInfo bulbInfo1 {.deviceName = "bulb1", .deviceAddr = "192.168.100.6"};
    BasicDeviceInfo bulbInfo2 {.deviceName = "bulb2", .deviceAddr = "192.168.100.7"};
    BasicDeviceInfo bulbInfo3 {.deviceName = "bulb3", .deviceAddr = "192.168.100.8"};

    auto bulb1 = std::make_unique<LightingDeviceColor>(std::make_unique<XiaomiPerformer>(), bulbInfo1);
    auto bulb2 = std::make_unique<LightingDeviceColor>(std::make_unique<XiaomiPerformer>(), bulbInfo2);
    auto bulb3 = std::make_unique<LightingDeviceColor>(std::make_unique<XiaomiPerformer>(), bulbInfo3);

    LightGroupImpl lightGroup;
    lightGroup.add(std::move(bulb1));
    lightGroup.add(std::move(bulb2));
    lightGroup.add(std::move(bulb3));


    BasicDeviceInfo vacuumInfo {.deviceName = "cleaner", .deviceAddr = "192.168.100.15"};
    auto vacuum = std::make_unique<LightingDevice>(std::make_unique<XiaomiPerformer>(), vacuumInfo);

    std::string option;

    while(true) {
        std::cin >> option;
        if (option == "on") {
            auto result = lightGroup.turnOn();
        }
        else if (option == "-b") {
                int brightness;
                std::cin >> brightness;
               auto result = lightGroup.setBrightness(brightness);
        }
        else if(option == "-c") {
            int red;
            int green;
            int blue;
            std::cin >> red;
            std::cin >> green;
            std::cin >> blue;

            auto result = lightGroup.setColor(red, green, blue);
        }
        else if(option == "-k") {
            int colorTemperature;
            std::cin >> colorTemperature;
            auto result = lightGroup.setColorTemperature(colorTemperature);
        }
        else if (option == "off") {
            auto result = lightGroup.turnOff();
            //std::cout << result.getMessage() << std::endl;
        }
        else {
            auto result = lightGroup.setBrightness(std::stoi(option));
            //std::cout << result.getMessage() << std::endl;
        }
    }
}
