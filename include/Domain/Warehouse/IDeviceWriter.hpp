
#pragma once

#include "Domain/IBasicDevice.hpp"

class IDeviceWriter {
public:
    virtual ~IDeviceWriter() = default;

public:
    virtual void write(IBasicDevices const& devices, std::ostream& output) = 0;
};
