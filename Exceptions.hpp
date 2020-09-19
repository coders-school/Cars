#pragma once

#include <stdexcept>

class InvalidGear : public std::logic_error {
public:
    InvalidGear(const std::string& what_arg);
};

class InvalidAcceleration : public std::logic_error {
public:
    InvalidAcceleration(const std::string& what_arg);
};

class InvalidEngineChange : public std::logic_error {
public:
    InvalidEngineChange(const std::string& what_arg);
};

class InvalidParameter : public std::logic_error {
public:
    InvalidParameter(const std::string& what_arg);
};
