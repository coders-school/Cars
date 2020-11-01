#pragma once
#include <stdexcept>
#include <string>

class InvalidGear : public std::logic_error {
public:
    InvalidGear(const std::string & arg);
};

class InvalidSpeed : public std::logic_error {
public:
    InvalidSpeed(const std::string & arg);
};
