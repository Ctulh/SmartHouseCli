
#pragma once

#include "Domain/IBasicDevice.hpp"

class IDeviceReader {
public:
    virtual ~IDeviceReader() = default;

public:
    virtual IBasicDevices read(std::istream& input) = 0;
};
