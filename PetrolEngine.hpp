#pragma once
#include "Engine.hpp"
#include "Gearable.hpp"
#include "PetrolCapacity.hpp"

class PetrolEngine : virtual Engine, public Gearable {
public:
    PetrolEngine(Power power, PetrolCapacity capacity, ManualGear gears);
    ~PetrolEngine() override;
    
    void changeGear(ManualGear gear) override;

protected:
    PetrolCapacity capacity_;  // in ccm
    const ManualGear gears_;
    ManualGear currentGear_ = ManualGear::neutral;
};