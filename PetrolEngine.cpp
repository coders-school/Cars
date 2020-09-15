#include "PetrolEngine.hpp"
#include <iostream>

PetrolEngine::PetrolEngine(HorsePower power, CubicCentimetre capacity, Gear gears) :
        power_(power),
        capacity_(capacity),
        gears_(gears),
        currentGear_(0) {
    std::cout << __FUNCTION__ << std::endl;
}

void PetrolEngine::changeGear(Gear gear) {
    if (gear.value_ < -1 || gear.value_ > gears_.value_) {
        return;
    }
    if (currentGear_.value_ == 5 && gear.value_ == -1) {
        throw InvalidGear();
    }
    currentGear_ = gear;
    std::cout << __FUNCTION__ << std::endl;
}

PetrolEngine::~PetrolEngine() {
    std::cout << __FUNCTION__ << std::endl;
}
