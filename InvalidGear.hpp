#pragma once

#include <stdexcept>
#include <string>

class InvalidGear : public std::logic_error {
public:
    InvalidGear(const std::string& errorMsg)
        : std::logic_error(errorMsg) {}
};
