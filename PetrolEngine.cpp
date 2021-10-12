#include "PetrolEngine.hpp"
#include <iostream>

PetrolEngine::PetrolEngine(int power, float capacity, int gears)
    : power_(power), capacity_(capacity), gears_(gears), currentGear_(0) {
    std::cout << __FUNCTION__ << std::endl;
}

PetrolEngine::~PetrolEngine(){
    std::cout << __FUNCTION__ << std::endl;
}

void PetrolEngine::changeGear(int nextGear) {
    if (!gearIsValid(nextGear) || (nextGear == -1 && currentGear_ != 0)) {
        throw InvalidGear("Not possible to change the gear!!!");
    };
    std::cout << __FUNCTION__ << std::endl;
    currentGear_ = nextGear;
}

bool PetrolEngine::gearIsValid(const int& gear) {
    return gear <= gears_ && gear >= -1;
};