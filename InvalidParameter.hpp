#pragma once 

#include "stdexcept"
#include "string"

class InvalidParameter : std::logic_error {
public:
    InvalidParameter(const std::string& msg);
};