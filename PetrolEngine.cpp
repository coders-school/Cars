#include "PetrolEngine.hpp"

#include <cmath>
#include <iostream>

PetrolEngine::PetrolEngine(int power, float capacity, int gears)
    : Engine(power, capacity)
    , gears_(gears)
    , currentGear_(0)
{
    std::cout << __FUNCTION__ << std::endl;
}

PetrolEngine::~PetrolEngine() {

}

void PetrolEngine::fillUp() {
    std::cout << __FUNCTION__ << std::endl;
}

void PetrolEngine::changeGear(int gear)
{
    if (gear < -1) {
        throw PetrolEngine::InvalidGear("To low");
    } else if (gear > gears_) {
        throw PetrolEngine::InvalidGear("To high");  
    } else if (std::abs(currentGear_ - gear) != 1) {
        throw PetrolEngine::InvalidGear("Error, you try change gear to fast");
    } else {
        currentGear_ = gear;
        std::cout << __FUNCTION__ << std::endl;
    }
}

int PetrolEngine::getMaxSpeed() {
    return (power_ * capacity_ + (gears_ * 10))/ 500;
}

int PetrolEngine::getMaxReverseSpeed() {
    return getMaxSpeed() / 6 * (-1);
}