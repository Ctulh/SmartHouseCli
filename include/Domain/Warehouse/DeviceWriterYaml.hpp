
#pragma once

#include "IDeviceWriter.hpp"

class DeviceWriterYaml final : public IDeviceWriter {
public:
    void write(const IBasicDevices &devices, std::ostream &output) override;
};
