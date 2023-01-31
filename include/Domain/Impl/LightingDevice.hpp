
#pragma once

#include <concepts>

#include "Domain/ILightingDevice.hpp"
#include "IPerformer.hpp"

template <typename Performer>
concept PerformerBase = std::is_base_of_v<IPerformer, Performer> && std::is_default_constructible_v<Performer>;

template<PerformerBase Performer>
class LightingDevice final: public ILightingDevice {
public:
    ResultObject setBrightness(int brightnessPercents) override;
    ResultObject turnOn() override;
    ResultObject turnOff() override;
    ResultObject toggle() override;
    BasicDeviceInfo getDeviceInfo() override;
private:
    BasicDeviceInfo m_info;
};

template<PerformerBase Performer>
ResultObject LightingDevice<Performer>::turnOn() {
    return Performer().turnOn(m_info);
}

template<PerformerBase Performer>
ResultObject LightingDevice<Performer>::turnOff() {
    return Performer().turnOff(m_info);
}

template<PerformerBase Performer>
ResultObject LightingDevice<Performer>::toggle() {
    return Performer().toggle(m_info);
}

template<PerformerBase Performer>
ResultObject LightingDevice<Performer>::setBrightness(int brightnessPercents) {
    return Performer().setBrightness(m_info, brightnessPercents);
}

template<PerformerBase Performer>
BasicDeviceInfo LightingDevice<Performer>::getDeviceInfo() {
    return m_info;
}
