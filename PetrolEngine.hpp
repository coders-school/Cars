#pragma once
#include "carExceptions.hpp"

class PetrolEngine
{
public:
    PetrolEngine(int power, float capacity, int gears);
    void changeGear(int gear);

private:
    int power_;         // in HP
    float capacity_;    // in ccm
    int gears_;
    int currentGear_;
};
