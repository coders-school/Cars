#pragma once
#include "Engine.hpp"
#include "Gearable.hpp"

class PetrolEngine : virtual Engine, public Gearable {
public:
    PetrolEngine(int power, float capacity, int gears);
    ~PetrolEngine() override;
    
    void changeGear(int gear) override;

protected:
    float capacity_;  // in ccm
    const int gears_;
    int currentGear_ = 0;
};
