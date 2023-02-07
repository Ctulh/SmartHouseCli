
#pragma once

#include "Domain/Impl/IPerformer.hpp"

class XiaomiPerformer final: public IPerformer {
public:
    ResultObject turnOn(BasicDeviceInfo const&) override;
    ResultObject turnOff(BasicDeviceInfo const&) override;
    ResultObject toggle(BasicDeviceInfo const&) override;
    ResultObject setBrightness(BasicDeviceInfo const&, int) override;
    ResultObject setColorTemperature(const BasicDeviceInfo &, int) override;
    ResultObject setColor(const BasicDeviceInfo &, int, int, int) override;
    StateValueType getDeviceState(BasicDeviceInfo const& deviceInfo, DeviceProperties const& properties);
private:
    static ResultObject createResponse(std::string const&);
};
