#pragma once

#include <stdexcept>
#include <string>

class InvalidGear : public std::runtime_error {
public:
    InvalidGear(const std::string& msg);
};
