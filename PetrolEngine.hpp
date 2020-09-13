#pragma once

#include "Engine.hpp"

class PetrolEngine : public Engine {
public:
    PetrolEngine(int power, float capacity, int gears);
    
    int getCurrentGear() const;
    int getGears() const;
    float getCapacity() const;

    void setCurrentGear(int gear);


    // Override from Engine
    ~PetrolEngine() override;

private:
    float capacity_;  // in ccm
    int gears_;
    int currentGear_;
};