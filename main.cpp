#include <iostream>

#include "Domain/ILightingDevice.hpp"
#include "Domain/Impl/LightingDevice.hpp"
#include "Domain/Impl/IPerformer.hpp"
#include "Domain/Performers/YeelightPerformer/PerformerImpl.hpp"
#include "Domain/Impl/LightGroupImpl.hpp"

#include <thread>

int main() {
    auto performer1 = std::make_unique<PerformerImpl>();
    auto performer2 = std::make_unique<PerformerImpl>();
    auto performer3 = std::make_unique<PerformerImpl>();

    BasicDeviceInfo bulbInfo1 {.deviceName = "bulb1", .deviceAddr = "192.168.100.6"};
    BasicDeviceInfo bulbInfo2 {.deviceName = "bulb2", .deviceAddr = "192.168.100.7"};
    BasicDeviceInfo bulbInfo3 {.deviceName = "bulb3", .deviceAddr = "192.168.100.8"};

    auto bulb1 = std::make_unique<LightingDevice>(std::make_unique<PerformerImpl>(), bulbInfo1);
    auto bulb2 = std::make_unique<LightingDevice>(std::make_unique<PerformerImpl>(), bulbInfo2);
    auto bulb3 = std::make_unique<LightingDevice>(std::make_unique<PerformerImpl>(), bulbInfo3);

    LightGroupImpl lightGroup;
    lightGroup.add(std::move(bulb1));
    lightGroup.add(std::move(bulb2));
    lightGroup.add(std::move(bulb3));


    BasicDeviceInfo vacuumInfo {.deviceName = "cleaner", .deviceAddr = "192.168.100.15"};
    auto vacuum = std::make_unique<LightingDevice>(std::make_unique<PerformerImpl>(), vacuumInfo);

    std::string option;

    while(true) {
        std::cin >> option;
        if (option == "on") {
            auto result = lightGroup.turnOn();
            //std::cout << result.getMessage() << std::endl;
        }
        else if (option == "c")
            break;
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
