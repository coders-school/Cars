#pragma once
#include "Engine.hpp"
#include "Gearable.hpp"
#include "PetrolCapacity.hpp"

class PetrolEngine : virtual Engine, public Gearable {
public:
    PetrolEngine(Power power, PetrolCapacity capacity, int gears);
    ~PetrolEngine() override;
    
    void changeGear(int gear) override;

protected:
    PetrolCapacity capacity_;  // in ccm
    const int gears_;
    int currentGear_ = 0;
};
