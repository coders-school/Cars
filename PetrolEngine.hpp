#pragma once

#include "Engine.hpp"
#include "Errors.hpp"

class PetrolEngine : public Engine {
public:
    PetrolEngine(int power, float capacity, int gears);
    ~PetrolEngine();

    void changeGear(int gear);
    int getCurrentGear() const;
    int getPower() const;
    int getGears() const;
    float getCapacity() const;

private:
    int power_;       // in HP
    float capacity_;  // in ccm
    int gears_;
    int currentGear_;
};
