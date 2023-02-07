
#pragma once

#include "IFactory.hpp"
#include "Domain/DeviceFamily.hpp"

class AbstractFactory {
public:
    AbstractFactory(DeviceFamily) = delete;
public:
    static IFactoryPtr createFactory(DeviceFamily);
};