#pragma once

#include <stdexcept>
#include <string>

class InvalidEngine : public std::logic_error {
public:
    InvalidEngine(const std::string& message)
    : std::logic_error(message) {}
};
