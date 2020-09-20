#pragma once
#include <stdexcept>
#include <string>

class InvalidGear : public std::logic_error {
public:
    InvalidGear(const std::string& what) : std::logic_error(what) {}
};

class InvalidSpeed : public std::logic_error {
public:
    InvalidSpeed(const std::string& what) : std::logic_error(what) {}
};

class InvalidEngine : public std::logic_error {
public:
    InvalidEngine(const std::string& what) : std::logic_error(what) {}
};