#pragma once

#include "Engine.hpp"

class PetrolEngine  : public Engine
{
public:
    PetrolEngine(int power, float capacity, int gears);
    ~PetrolEngine() override = default;
    void changeGear(int gear);

    int power_;         // in HP
    float capacity_;    // in ccm
    int gears_;
    int currentGear_;
};
