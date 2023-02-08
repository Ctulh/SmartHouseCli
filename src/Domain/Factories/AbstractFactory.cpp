//
// Created by ctuh on 2/6/23.
//

#include "Domain/Factories/AbstractFactory.hpp"
#include "Domain/Factories/XiaomiFactory.hpp"

IFactoryPtr AbstractFactory::createFactory(DeviceFamily deviceFamily) {
    switch(deviceFamily) {
        case DeviceFamily::XIAOMI: return std::make_unique<XiaomiFactory>();
        default: return nullptr;
    }
}
