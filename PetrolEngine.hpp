#pragma once
#include "Engine.hpp"

class PetrolEngine : public Engine {
public:
    PetrolEngine(int power, float capacity, int gears);
    virtual ~PetrolEngine();
    void changeGear(int gear);
    
protected:
    float capacity_;  // in ccm
    int gears_;
    int currentGear_;
};
