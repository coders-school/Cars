#pragma once

#include <stdexcept>
#include <string>

class MovingCar : public std::logic_error {
public:
    MovingCar(const std::string& message)
    : std::logic_error(message) {}
};
