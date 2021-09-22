#pragma once

#include <stdexcept>
#include "Exeptions.hpp"


class PetrolEngine {
public:
    PetrolEngine(int power, float capacity, int gears);
    void changeGear(int gear);
    int getGears() const;
    int getPower() const;
    float getCapacity() const;
    int getCurrentGear() const;
    
private:
    int power_;       // in HP
    float capacity_;  // in ccm
    int gears_;
    int currentGear_;
};
