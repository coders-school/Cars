#pragma once

#include "Engine.hpp"

class PetrolEngine : public Engine {
public:
    PetrolEngine(int power, float capacity, int gears);
    ~PetrolEngine() override;

    void changeGear(int gear);
    int getCurrentGear() const;
    int getGears() const;
    float getCapacity() const;

private:
    float capacity_;  // in ccm
    int gears_;
    int currentGear_ = 0;
};
