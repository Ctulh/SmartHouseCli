
#pragma once

#include <string>

class RequestSender {
public:
    RequestSender() = delete;

public:
    static std::string send(std::string const& deviceAddr, std::string const& request);
};
