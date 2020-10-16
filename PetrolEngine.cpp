#include "PetrolEngine.hpp"

#include <iostream>

#include "Exception.hpp"

constexpr int rearGear = -1;

PetrolEngine::PetrolEngine(int power, float capacity, int gears)
    : Engine(power), capacity_(capacity), gears_(gears) {}

void PetrolEngine::changeGear(int gear) {
    if (gear < rearGear || gear > gears_) {
        throw InvalidGear("This car does not have this gear.");
    } else if (getCurrentGear() == gears_ && gear == rearGear) {
        throw InvalidGear("Changing gears like that is not good idea.");
    }
    currentGear_ = gear;
    std::cout << __FUNCTION__ << std::endl;
}
