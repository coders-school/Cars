#pragma once

#include "Engine.hpp"
#include "InvalidGear.hpp"
class PetrolEngine : public Engine {
public:
    PetrolEngine(int power, float capacity, int gears);
    void changeGear(int gear);
    int getCurrentGear();

private:
    float capacity_;  // in ccm
    int gears_;
    int currentGear_;
};
