//
// Created by ctuh on 2/1/23.
//

#include "Domain/Performer/PerformerImpl.hpp"
#include "Domain/Performer/RequestCreator.hpp"
#include "Domain/Performer/RequestSender.hpp"

ResultObject PerformerImpl::turnOn(BasicDeviceInfo const& deviceInfo) {
    auto request = RequestCreator::turnOn();
    auto result = RequestSender::send(deviceInfo.deviceAddr, request);
    return ResultObject(true);
}

ResultObject PerformerImpl::turnOff(BasicDeviceInfo const& deviceInfo) {
    auto request = RequestCreator::turnOff();
    auto result  = RequestSender::send(deviceInfo.deviceAddr, request);
    return ResultObject(true);
}

ResultObject PerformerImpl::toggle(BasicDeviceInfo const& deviceInfo) {
    auto request = RequestCreator::toggle();
    auto result  = RequestSender::send(deviceInfo.deviceAddr, request);
    return ResultObject(true);
}

ResultObject PerformerImpl::setBrightness(BasicDeviceInfo const& deviceInfo, int percents) {
    auto request = RequestCreator::setBrightness(percents);
    auto result  = RequestSender::send(deviceInfo.deviceAddr, request);
    return ResultObject(true);
}