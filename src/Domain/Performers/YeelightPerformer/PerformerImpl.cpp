//
// Created by ctuh on 2/1/23.
//

#include "Domain/Performers/YeelightPerformer/PerformerImpl.hpp"
#include "Domain/Performers/YeelightPerformer/RequestCreator.hpp"
#include "Domain/Performers/YeelightPerformer/RequestSender.hpp"
#include "Domain/Performers/YeelightPerformer/ResponseParser.hpp"

#include <algorithm>

ResultObject PerformerImpl::createResponse(std::string const& response) {

    ResponseParser parser(response);
    auto result = parser.getResult();
    return ResultObject(true, response);
}

ResultObject PerformerImpl::turnOn(BasicDeviceInfo const& deviceInfo) {
    auto request = RequestCreator::turnOn();
    auto result = RequestSender::send(deviceInfo.deviceAddr, request);
    return createResponse(result);
}

ResultObject PerformerImpl::turnOff(BasicDeviceInfo const& deviceInfo) {
    auto request = RequestCreator::turnOff();
    auto result  = RequestSender::send(deviceInfo.deviceAddr, request);
    return createResponse(result);
}

ResultObject PerformerImpl::toggle(BasicDeviceInfo const& deviceInfo) {
    auto request = RequestCreator::toggle();
    auto result  = RequestSender::send(deviceInfo.deviceAddr, request);
    return createResponse(result);
}

ResultObject PerformerImpl::setBrightness(BasicDeviceInfo const& deviceInfo, int percents) {
    auto request = RequestCreator::setBrightness(percents);
    auto result  = RequestSender::send(deviceInfo.deviceAddr, request);
    return createResponse(result);
}