#pragma once

#include <stdexcept>
#include <string>

class InvalidParameter : public std::logic_error {
public:
    InvalidParameter(const std::string& message);
};
