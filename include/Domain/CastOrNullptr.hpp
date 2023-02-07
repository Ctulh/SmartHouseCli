
#pragma once

#include <memory>

template<typename ResultType, typename ArgumentType>
ResultType CastOrNullptr(ArgumentType argument) {
    return dynamic_cast<ResultType>(argument);
}

template<typename ResultType, typename ArgumentType>
std::shared_ptr<ResultType> CastOrNullptr(std::shared_ptr<ArgumentType> argument) {
    return std::dynamic_pointer_cast<ResultType>(argument);
}