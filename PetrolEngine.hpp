#pragma once
#include "Engine.hpp"
#include "Refuelable.hpp"
#include "Gearable.hpp"

class PetrolEngine : virtual Engine, public Refuelable, public Gearable {
public:
    PetrolEngine(int power, float capacity, int gears);
    ~PetrolEngine() override;
    
    void refuel() override;
    void changeGear(int gear) override;

protected:
    float capacity_;  // in ccm
    int gears_;
    int currentGear_ = 0;
};
