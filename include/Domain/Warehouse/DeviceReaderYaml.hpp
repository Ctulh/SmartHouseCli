
#pragma once

#include "IDeviceReader.hpp"

class DeviceReaderYaml final: public IDeviceReader {
public:
    IBasicDevices read(std::istream &input) override;
};
