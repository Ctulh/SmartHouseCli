#include <iostream>

#include "Domain/ILightingDevice.hpp"
#include "Domain/Impl/LightingDevice.hpp"
#include "Domain/Impl/IPerformer.hpp"
#include "Domain/Performer/PerformerImpl.hpp"

#include <thread>

int main() {
    auto performer = std::make_unique<PerformerImpl>();
    BasicDeviceInfo bulbInfo {.deviceName = "bulb1", .deviceAddr = "192.168.100.6"};

    auto bulb = std::make_unique<LightingDevice>(std::move(performer), bulbInfo);
    std::string option;

    while(true) {
        std::cin >> option;
        if (option == "on")
            bulb->turnOn();
        else if (option == "c")
            break;
        else if (option == "off")
            bulb->turnOff();
        else {
            bulb->setBrightness(std::stoi(option));
        }
    }
}
