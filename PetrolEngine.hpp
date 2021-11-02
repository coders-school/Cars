#pragma once
#include "Engine.hpp"

class PetrolEngine : public Engine
{
public:
    PetrolEngine(int power, float capacity, int gears);
    ~PetrolEngine() override;
    
    void changeGear(int gear);

private:
    float capacity_;    // in ccm
    int gears_;
    int currentGear_;
};
