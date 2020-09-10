#pragma once

#include <stdexcept>
#include <string>

class CarInMovementExcept : std::logic_error {
public:
    CarInMovementExcept(const std::string& what);
};
