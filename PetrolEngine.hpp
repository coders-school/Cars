#pragma once
#include <stdexcept>
#include <string>

#include "HorsePower.hpp"
class InvalidGear : public std::invalid_argument {
   public:
    InvalidGear() :
            std::invalid_argument("You cannot change gear from 5 to R!\n") {}
};

class PetrolEngine {
    HorsePower power_;  // HP
    float capacity_;    // in ccm
    int gears_;
    int currentGear_;

   public:
    PetrolEngine(HorsePower power, float capacity, int gears);
    ~PetrolEngine();
    void changeGear(int gear);
    const HorsePower& getPower() { return power_; };
};
