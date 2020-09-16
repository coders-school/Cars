#pragma once

#include <stdexcept>

class InvalidChangeEngine : public std::logic_error {
public:
    InvalidChangeEngine(const std::string& msg);
};

class InvalidSpeed : public std::logic_error {
public:
    InvalidSpeed(const std::string& msg);
};

class InvalidGear : public std::logic_error {
public:
    InvalidGear(const std::string& msg);
};

class InvalidCharge : public std::logic_error {
public:
    InvalidCharge(const std::string& msg);
};