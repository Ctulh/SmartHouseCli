//
// Created by ctuh on 2/1/23.
//

#include "Domain/Performers/XiaomiPerformer/ResponseParser.hpp"
#include "Utils/JsonParser.hpp"
#include "Utils/StringOperations.hpp"

struct ResponseParser::Impl {
    Impl(std::string const& jsonData): jsonParser(jsonData) {}
    JsonParser jsonParser;
};

ResponseParser::~ResponseParser() = default;

ResponseParser::ResponseParser(std::string const& response) {
    m_jsonData = std::make_unique<Impl>(response);
}

std::optional<int> ResponseParser::getId() const {
    auto result = m_jsonData->jsonParser["id"];
    if(!result.has_value())
        return {};

    try {
        return std::stoi(result.value());
    }
    catch (std::exception& e) {
        return {};
    }
}

std::optional<std::vector<std::string>> ResponseParser::getResult() const {
    auto result = m_jsonData->jsonParser["result"];
    if(not result.has_value())
        return {};

    return StringOperations::split(result.value(), ',');
}
