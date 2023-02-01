
#pragma once

#include "Domain/Impl/IPerformer.hpp"

class PerformerImpl final: public IPerformer {
public:
    ResultObject turnOn(BasicDeviceInfo const&) override;
    ResultObject turnOff(BasicDeviceInfo const&) override;
    ResultObject toggle(BasicDeviceInfo const&) override;
    ResultObject setBrightness(BasicDeviceInfo const&, int) override;
};
