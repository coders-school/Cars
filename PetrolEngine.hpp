#pragma once

#include "Exception.hpp"
class PetrolEngine {
   public:
    PetrolEngine(int power, float capacity, int gears);
    void changeGear(int gear);
    int getCurrentGear() const;

    int power_;       // in HP
    float capacity_;  // in ccm
    int gears_;
    int currentGear_;
};
