//
// Created by ctuh on 2/1/23.
//

#include "Domain/Performers/YeelightPerformer/ResponseParser.hpp"

#include <nlohmann/json.hpp>

struct ResponseParser::Impl {
    nlohmann::json data;
};

ResponseParser::~ResponseParser() = default;

ResponseParser::ResponseParser(std::string const& response) {
    m_jsonData = std::make_unique<Impl>();
    m_jsonData->data = nlohmann::json::parse(response);
}

std::optional<int> ResponseParser::getId() const {
    auto result = m_jsonData->data["id"];
    if(result.is_number_integer()) {
        try {
            return {result.get<int>()};
        }
        catch (std::exception &e) {
            return {};
        }
    }
    return {};
}

std::optional<std::vector<std::string>> ResponseParser::getResult() const {
    try {
        return m_jsonData->data["result"];
    }
    catch (std::exception& e) {
        return {};
    }
}
