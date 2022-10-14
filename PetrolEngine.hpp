#pragma once

#include "Engine.hpp"
#include <stdexcept>

struct InvalidGear : public std::logic_error {
    InvalidGear() : std::logic_error("Invalid gear") {}

    InvalidGear(std::string message) : std::logic_error(message) {}
};

class PetrolEngine : public Engine {
public:
    PetrolEngine(int power, float capacity, int gears);

    void changeGear(int gear);

private:
    float capacity_;    // in ccm
    int gears_;
    int currentGear_;
};
