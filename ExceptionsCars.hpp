#pragma once
#include <stdexcept>

class InvalidGear : public std::logic_error {
public:
    InvalidGear(const std::string& err);
};

class InvalidAccelerate : public std::logic_error {
public:
    InvalidAccelerate(const std::string& err);
};