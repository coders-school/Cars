#pragma once

#include <stdexcept>

class InvalidSpeed : public std::logic_error {
public:
    InvalidSpeed(const std::string& msg);
};