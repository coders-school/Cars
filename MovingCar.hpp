#pragma once

#include <stdexcept>
#include <string>

class MovingCar : public std::logic_error {
public:
    MovingCar(const std::string& errorMsg)
        : std::logic_error(errorMsg) {}
};
