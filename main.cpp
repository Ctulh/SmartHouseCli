#include <iostream>

#include "Domain/LightingDevices/ILightingDevice.hpp"
#include "Domain/LightingDevices/Impl/LightingDevice.hpp"
#include "Domain/Impl/IPerformer.hpp"
#include "Domain/Performers/XiaomiPerformer/XiaomiPerformer.hpp"
#include "Domain/LightingDevices/Impl/LightGroupImpl.hpp"
#include "Domain/LightingDevices/Impl/LightingDeviceColor.hpp"
#include <signal.h>
#include <thread>

#include "Application/IApplication.hpp"
#include "Application/Impl/ApplicationImpl.hpp"

#include "Domain/IDeviceContainer.hpp"
#include "Domain/Impl/DeviceContainer.hpp"

#include "Adapters/IDeviceManager.hpp"
#include "Adapters/IDeviceManipulator.hpp"
#include "Adapters/Impl/DeviceManagerImpl.hpp"
#include "Adapters/Impl/DeviceManipulatorImpl.hpp"

#include "Domain/CastOrNullptr.hpp"

int main() {
    signal(SIGPIPE, SIG_IGN);

    std::unique_ptr<IDeviceContainer> deviceContainer = std::make_unique<DeviceContainer>();
    std::shared_ptr<IApplication> application = std::make_shared<ApplicationImpl>(std::move(deviceContainer));
    std::unique_ptr<IDeviceManager> deviceManager = std::make_unique<DeviceManager>(application);

    deviceManager->addNewDevice({.deviceName = "bulb1", .deviceAddr = "192.168.100.6"}, DeviceFamily::XIAOMI, DeviceType::XIAOMI_LIGHTING_DEVICE_COLOR);
    deviceManager->addNewDevice({.deviceName = "bulb2", .deviceAddr = "192.168.100.7"}, DeviceFamily::XIAOMI, DeviceType::XIAOMI_LIGHTING_DEVICE_COLOR);
    deviceManager->addNewDevice({.deviceName = "bulb3", .deviceAddr = "192.168.100.8"}, DeviceFamily::XIAOMI, DeviceType::XIAOMI_LIGHTING_DEVICE_COLOR);

    application->createLightGroup({"bulb1", "bulb2", "bulb3"});

    std::string option;

    while(true) {
        std::cin >> option;
        if (option == "on") {
                deviceManager->getDevice("LightGroup")->turnOn();
        }
        else if (option == "-b") {
                int brightness;
                std::cin >> brightness;
                auto lightingDevice = CastOrNullptr<ILightingDevice>(deviceManager->getDevice("LightGroup"));
                if(lightingDevice)
                    lightingDevice->setBrightness(brightness);
        }
        else if(option == "-c") {
            int red;
            int green;
            int blue;
            std::cin >> red;
            std::cin >> green;
            std::cin >> blue;
            auto lightingDevice = CastOrNullptr<ILightingDeviceColor>(deviceManager->getDevice("LightGroup"));
            if(lightingDevice)
                lightingDevice->setColor(red, green, blue);
        }
        else if(option == "-k") {
            int colorTemperature;
            std::cin >> colorTemperature;
            auto lightingDevice = CastOrNullptr<ILightingDevice>(deviceManager->getDevice("LightGroup"));
            if(lightingDevice)
                lightingDevice->setColorTemperature(colorTemperature);

        }
        else if(option == "-s") {
            auto result = std::dynamic_pointer_cast<ILightingDeviceColor>(deviceManager->getDevice("LightGroup"))->getDeviceState();
            std::cout << result.brightness << " " << result.colorTemperature << " " << (int)result.color.red << " " << (int)result.color.green << " " << (int)result.color.blue << '\n';
        }
        else if (option == "off") {
            deviceManager->getDevice("LightGroup")->turnOff();
        }
        else {
        }
    }
}
