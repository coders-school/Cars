#pragma once

#include "Engine.hpp"

class PetrolEngine : public Engine {
private:
    float capacity_;  // in ccm
    int gears_;
    int currentGear_;

public:
    PetrolEngine(int power, float capacity, int gears);
    int getCurrentGear() const { return currentGear_; }
    int getGears() const { return gears_; }
    float getCapacity() const { return capacity_; }
    void changeGear(int gear);
    ~PetrolEngine() {}

};
