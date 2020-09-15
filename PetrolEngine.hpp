#pragma once
#include <stdexcept>
#include <string>

#include "HorsePower.hpp"
class InvalidGear : public std::invalid_argument {
   public:
    InvalidGear() :
            std::invalid_argument("You cannot change gear from 5 to R!\n") {}
};

class CubicCentimetre {
   public:
    float value_;
    explicit CubicCentimetre(float value) :
            value_(value) {}
};

class Gear {
   public:
    int value_;
    explicit Gear(int value) :
            value_(value) {}
};
class PetrolEngine {
    HorsePower power_;
    CubicCentimetre capacity_;
    Gear gears_;
    Gear currentGear_;

   public:
    PetrolEngine(HorsePower power, CubicCentimetre capacity, Gear gears);
    ~PetrolEngine();
    void changeGear(Gear gear);
    HorsePower getPower() const { return power_; };
    CubicCentimetre getCapacity() const { return capacity_; };
    Gear getCurrentGear() const { return currentGear_; };
    Gear getMaximumGear() const { return gears_; };
    
};
