#pragma once

#include <stdexcept>

class InvalidGear : public std::runtime_error {
public:
    InvalidGear() : std::runtime_error("Invalid Gear\n") {}
};

class PetrolEngine
{
public:
    PetrolEngine(int power, float capacity, int gears);
    void changeGear(int gear);

    int power_;         // in HP
    float capacity_;    // in ccm
    int gears_;
    int currentGear_;
};
