#pragma once

#include "Engine.hpp"

class PetrolEngine : public Engine
{
public:
    PetrolEngine(int power, float capacity, int gears);
    
    void changeGear(int gear);
    float getCapacity() const { return capacity_; }
    int getTotalGears() const { return gears_; }
    int getCurrentGear() const { return currentGear_; }

private:
    float capacity_;    // in ccm
    int gears_;
    int currentGear_;
};
