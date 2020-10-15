#pragma once

#include <stdexcept>
#include <string>

class InvalidSpeed : public std::logic_error {
public:
    InvalidSpeed(const std::string& errorMsg)
        : std::logic_error(errorMsg) {}
};
