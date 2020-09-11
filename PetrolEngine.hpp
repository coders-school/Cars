#pragma once

#include "Engine.hpp"

class PetrolEngine : public Engine {
public:
    PetrolEngine(int power, float capacity, int gears);
    int getGears() { return gears_; }
    int getCurrentGear() { return currentGear_; }
    void setCurrentGear(int gear);

private:
    float capacity_;  // in ccm
    int gears_;
    int currentGear_;
};
