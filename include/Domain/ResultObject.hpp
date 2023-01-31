
#pragma once

#include <string>

class ResultObject {
public:
    explicit ResultObject(bool isSuccess): m_isSuccess(isSuccess) {};
    explicit ResultObject(bool isSuccess, std::string const& message): m_isSuccess(isSuccess), m_message(message) {};
    ResultObject() = default;
    ResultObject(ResultObject const& other) = default;
    ResultObject(ResultObject&& other) = default;
    ResultObject& operator=(ResultObject const& other) = default;
    ResultObject& operator=(ResultObject&& other) = default;


public:
    operator bool() const {
        return m_isSuccess;
    }

    std::string getMessage() {
        return m_message;
    }

private:
    std::string m_message;
    bool m_isSuccess;
};
