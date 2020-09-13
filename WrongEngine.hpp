#pragma once

#include <stdexcept>
#include <string>

class InvalidEngine : public std::logic_error {
public:
    InvalidEngine(const std::string& errMessage)
    : std::logic_error(errMessage) {}
};