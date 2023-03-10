//
// Created by ctuh on 2/1/23.
//

#include "Domain/Performers/XiaomiPerformer/XiaomiPerformer.hpp"
#include "Domain/Performers/XiaomiPerformer/RequestCreator.hpp"
#include "Domain/Performers/XiaomiPerformer/RequestSender.hpp"
#include "Domain/Performers/XiaomiPerformer/ResponseParser.hpp"

#include <algorithm>

ResultObject XiaomiPerformer::createResponse(std::string const& response) {
    ResponseParser parser(response);
    auto result = parser.getVector("result");
    return ResultObject(true, response);
}

StateValueType XiaomiPerformer::parseDeviceState(const std::string &response, const DeviceProperties &properties) {
    StateValueType output;
    ResponseParser parser(response);

    auto parameters = parser.getVector("result");
    if(not parameters.has_value())
        return {};

    auto parametersValue = parameters.value();
    for(int i = 0; i < std::min(properties.size(), parametersValue.size()); i++) {
        output[properties[i]] = parametersValue[i];
    }
    return output;
}

StateValueType XiaomiPerformer::getDeviceState(const BasicDeviceInfo &deviceInfo, DeviceProperties const& properties) {
    auto request = RequestCreator::getDeviceProperties(properties);
    auto response = RequestSender::send(deviceInfo.deviceAddr, request);
    return parseDeviceState(response, properties);
}

ResultObject XiaomiPerformer::turnOn(BasicDeviceInfo const& deviceInfo) {
    auto request = RequestCreator::turnOn();
    auto result = RequestSender::send(deviceInfo.deviceAddr, request);
    return createResponse(result);
}

ResultObject XiaomiPerformer::turnOff(BasicDeviceInfo const& deviceInfo) {
    auto request = RequestCreator::turnOff();
    auto result  = RequestSender::send(deviceInfo.deviceAddr, request);
    return createResponse(result);
}

ResultObject XiaomiPerformer::toggle(BasicDeviceInfo const& deviceInfo) {
    auto request = RequestCreator::toggle();
    auto result  = RequestSender::send(deviceInfo.deviceAddr, request);
    return createResponse(result);
}

ResultObject XiaomiPerformer::setBrightness(BasicDeviceInfo const& deviceInfo, int percents) {
    auto request = RequestCreator::setBrightness(percents);
    auto result  = RequestSender::send(deviceInfo.deviceAddr, request);
    return createResponse(result);
}

ResultObject XiaomiPerformer::setColorTemperature(BasicDeviceInfo const& deviceInfo, int colorTemperature) {
    auto request = RequestCreator::setColorTemperature(colorTemperature);
    auto result  = RequestSender::send(deviceInfo.deviceAddr, request);
    return createResponse(result);
}

ResultObject XiaomiPerformer::setColor(BasicDeviceInfo const& deviceInfo, int red, int green, int blue) {
    auto request = RequestCreator::setColor(red, green, blue);
    auto result  = RequestSender::send(deviceInfo.deviceAddr, request);
    return createResponse(result);
}