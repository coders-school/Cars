#include "PetrolEngine.hpp"
#include <iostream>

PetrolEngine::PetrolEngine(int power, float capacity, int gears)
    : power_(power)
    , capacity_(capacity)
    , gears_(gears)
    , currentGear_(0)
{
    std::cout << "* " << __FUNCTION__ << std::endl;
}

PetrolEngine::~PetrolEngine() {
    std::cout << "* " << __FUNCTION__ << std::endl;
}

void PetrolEngine::changeGear(int gear) {
    currentGear_ = gear;
}

int PetrolEngine::getGears() {
    return gears_;
}

int PetrolEngine::getPower() {
    return power_;
}
