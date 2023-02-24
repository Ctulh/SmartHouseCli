//
// Created by ctuh on 2/24/23.
//

#include "Domain/Warehouse/DeviceWriterYaml.hpp"
#include <iostream>
#include <yaml-cpp/yaml.h>
#include "Domain/ILightGroup.hpp"

namespace {
    void writeToYaml(YAML::Emitter& yaml, BasicDeviceInfo info) {
        yaml << YAML::BeginMap;
        auto fields = info.toMap();
        for(auto&& [key, value] : fields) {
            yaml << YAML::Key << key << YAML::Value << value;
        }
        yaml << YAML::EndMap;
    }
}

void DeviceWriterYaml::write(const IBasicDevices &devices, std::ostream &output) {
    YAML::Emitter yaml;
    yaml << YAML::Key << "Devices";
    yaml << YAML::BeginSeq;
//yaml << YAML::Flow;

    for(auto const& device: devices) {
        if(device->getInfo().deviceType == DeviceType::LIGHT_GROUP) {
            auto lightGroup = std::dynamic_pointer_cast<ILightGroup>(device);
            for(auto const& info: lightGroup->getDevicesInfo()) {
                writeToYaml(yaml, info);
            }
        }
        else {
            writeToYaml(yaml, device->getInfo());
        }
    }
    yaml << YAML::EndSeq;

    output << yaml.c_str();
}
