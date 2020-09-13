#pragma once

#include <stdexcept>

class ToLowSpeedError : public std::logic_error {
public:
    ToLowSpeedError(std::string speed);
};

class ToHighSpeedError : public std::logic_error {
public:
    ToHighSpeedError(std::string speed);
};

class AccelerateToLoweSpeedError : public std::logic_error {
public:
    AccelerateToLoweSpeedError(std::string speed);
};

class BreakeToHigherSpeedError : public std::logic_error {
public:
    BreakeToHigherSpeedError(std::string speed);
};

class InvalidGearError : public std::logic_error {
public:
    InvalidGearError(std::string gear);
};
