#pragma once

#include <stdexcept>
#include <string>

class InvalidGear : public std::runtime_error {
public:
    InvalidGear(const std::string& msg);
};

class InvalidEngineChange : public std::runtime_error {
public:
    InvalidEngineChange(const std::string& msg);
};

class InvalidAcceleration : public std::runtime_error {
public:
    InvalidAcceleration(const std::string& msg);
};
