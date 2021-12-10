#pragma once

#include <stdexcept>

class InvalidGear : public std::logic_error {
public:
    InvalidGear(const std::string& message)
        : std::logic_error { "Invalid gear :" + message }
    {
    }
};
