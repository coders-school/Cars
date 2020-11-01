#pragma once
#include <stdexcept>
#include <string>

class InvalidDriveMode : public std::logic_error {
public:
    InvalidDriveMode(const std::string& arg);
};

class InvalidGear : public std::logic_error {
public:
    InvalidGear(const std::string& arg);
};

class InvalidRestore : public std::logic_error {
public:
    InvalidRestore(const std::string& arg);
};

class InvalidSpeed : public std::logic_error {
public:
    InvalidSpeed(const std::string& arg);
};
