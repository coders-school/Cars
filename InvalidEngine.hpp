#pragma once

#include <stdexcept>
#include <string>

class InvalidEngine : public std::logic_error {
public:
    InvalidEngine(const std::string& errorMsg)
        : std::logic_error(errorMsg) {}
};
