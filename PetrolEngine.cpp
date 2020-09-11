#include <iostream>

#include "PetrolEngine.hpp"
#include "exceptions.hpp"

PetrolEngine::PetrolEngine(int power, float capacity, int gears)
    : power_(power), capacity_(capacity), gears_(gears), currentGear_(0) {
    std::cout << __FUNCTION__ << std::endl;
}

void PetrolEngine::changeGear(int gear) {
    if (gear < -1 || gear > gears_) {
        throw InvalidGearRangeException();
    }

    if (currentGear_ != 0 && gear == -1) {
        throw RearGearChangeException();
    }
    currentGear_ = gear;
    std::cout << __FUNCTION__ << std::endl;
}
