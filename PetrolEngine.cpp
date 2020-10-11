#include "PetrolEngine.hpp"

#include <iostream>

#include "Exception.hpp"

PetrolEngine::PetrolEngine(int power, float capacity, int gears)
    : Engine(power), capacity_(capacity), gears_(gears) {}

void PetrolEngine::changeGear(int gear) {
    if (gear < -1 || gear > gears_) {
        throw InvalidGear("This car does not have this gear.");
    } else if (getCurrentGear() == 5 && gear == -1) {
        throw InvalidGear("Changing gears like taht is not good idea.");
    }
    currentGear_ = gear;
    std::cout << __FUNCTION__ << std::endl;
}
