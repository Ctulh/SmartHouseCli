
#pragma once

#include "Adapters/IDeviceManipulator.hpp"

class DeviceManipulatorImpl final: public IDeviceManipulator {
    ResultObject turnOn() override;
    ResultObject turnOff() override;
    DeviceMethods getDeviceMethods() override;
};