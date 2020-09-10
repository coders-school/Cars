#pragma once
#include <stdexcept>

class InvalidGear : public std::logic_error {
public:
    InvalidGear() : std::logic_error("Invalid Gear") {}
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
