
#pragma once

#include <string>
#include <optional>
#include <memory>
#include <vector>

class ResponseParser {
public:
    ResponseParser(std::string const& response);
    ~ResponseParser();
public:
    std::optional<int> getId() const;
    std::optional<std::vector<std::string>> getVector(std::string const& fieldName) const;

private:
    struct Impl;
private:
    std::unique_ptr<Impl> m_jsonData;
};
