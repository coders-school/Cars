#include "PetrolEngine.hpp"
#include <iostream>
#include <string>
#include "InvalidGear.hpp"

PetrolEngine::PetrolEngine(int power, float capacity, int gears)
    : power_(power), capacity_(capacity), gears_(gears), currentGear_(GearBox::neutral) {
    std::cout << __FUNCTION__ << std::endl;
}

void PetrolEngine::setGear(GearBox gear) {
    if (gear == GearBox::rear && currentGear_ != GearBox::neutral) {
        throw InvalidGear("You should change gear to neutral before use read gear");
    }

    if (static_cast<int>(gear) > gears_) {
        throw InvalidGear("This engine has only " + std::to_string(gears_) + " gears");
    }

    currentGear_ = gear;
    std::cout << __FUNCTION__ << std::endl;
}
