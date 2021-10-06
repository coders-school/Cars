#include "PetrolEngine.hpp"
#include <iostream>
#include "Exceptions.hpp"

PetrolEngine::PetrolEngine(int power, float capacity, int gears)
    : power_(power)
    , capacity_(capacity)
    , gears_(gears)
    , currentGear_(0)
{
    std::cout << __FUNCTION__ << std::endl;
}

PetrolEngine::~PetrolEngine() {
    std::cout << __FUNCTION__ << std::endl;
}

int PetrolEngine::getCurrentGear() {
    return currentGear_;
}

void PetrolEngine::changeGear(int gear) {
    std::cout << __FUNCTION__ << std::endl;
    if (gear >= -1 && gear <= gears_) {
        if ((gear == -1) && currentGear_ > 0) {
            throw InvalidGear("Can't change gear from " + std::to_string(currentGear_) + " to R.");
        } else {
            currentGear_ = gear;
        }
    } else {
        throw InvalidGear("Invalid gear.");
    }
}
