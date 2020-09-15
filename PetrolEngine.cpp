#include "PetrolEngine.hpp"
#include <iostream>

PetrolEngine::PetrolEngine(HorsePower power, CubicCentimetre capacity, int gears) :
        power_(power),
        capacity_(capacity),
        gears_(gears),
        currentGear_(0) {
    std::cout << __FUNCTION__ << std::endl;
}

void PetrolEngine::changeGear(int gear) {
    if (gear < -1 || gear > gears_) {
        return;
    }
    if (currentGear_ == 5 && gear == -1) {
        throw InvalidGear();
    }
    currentGear_ = gear;
    std::cout << __FUNCTION__ << std::endl;
}

PetrolEngine::~PetrolEngine() {
    std::cout << __FUNCTION__ << std::endl;
}
