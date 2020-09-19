#pragma once

#include "Exceptions.hpp"

class PetrolEngine {
public:
    PetrolEngine(int power, float capacity, int gears);
    void changeGear(int gear);
    int getPower() { return power_; };
    int getCurrentGear() const;
    float getCapacity() { return capacity_; }

private:
    int power_;       // in HP
    float capacity_;  // in ccm
    int gears_;
    int currentGear_;
};
