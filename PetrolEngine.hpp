#pragma once

#include "Engine.h"

class PetrolEngine : public Engine
{
public:
    PetrolEngine(int power, float capacity, int gears);
    void changeGear(int gear);

    int power_;         // in HP
    float capacity_;    // in ccm
    int gears_;
    int currentGear_;
};
