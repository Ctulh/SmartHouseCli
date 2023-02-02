#include <iostream>

#include "Domain/ILightingDevice.hpp"
#include "Domain/Impl/LightingDevice.hpp"
#include "Domain/Impl/IPerformer.hpp"
#include "Domain/Performers/YeelightPerformer/PerformerImpl.hpp"

#include <thread>

int main() {
    auto performer = std::make_unique<PerformerImpl>();
    BasicDeviceInfo bulbInfo {.deviceName = "bulb1", .deviceAddr = "192.168.100.6"};

    auto bulb = std::make_unique<LightingDevice>(std::move(performer), bulbInfo);
    std::string option;

    while(true) {
        std::cin >> option;
        if (option == "on") {
            auto result = bulb->turnOn();
            std::cout << result.getMessage() << std::endl;
        }
        else if (option == "c")
            break;
        else if (option == "off") {
            auto result = bulb->turnOff();
            std::cout << result.getMessage() << std::endl;
        }
        else {
            auto result = bulb->setBrightness(std::stoi(option));
            std::cout << result.getMessage() << std::endl;
        }
    }
}
