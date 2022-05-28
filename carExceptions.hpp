#pragma once
#include <stdexcept>

class InvalidGear : public std::logic_error {
public:
    InvalidGear(const std::string & msg) : std::logic_error(msg) {}
};

class CarLogicError : public std::logic_error {
public:
    CarLogicError(const std::string & msg) : std::logic_error(msg) {}
};