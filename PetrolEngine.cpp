#include "PetrolEngine.hpp"
#include <iostream>

PetrolEngine::PetrolEngine(int power, float capacity, int gears)
    : Engine(power), capacity_(capacity), gears_(gears), currentGear_(GearBox::neutral)
{
    std::cout << __FUNCTION__ << std::endl;
}
PetrolEngine::~PetrolEngine()
{
    std::cout << __FUNCTION__ << std::endl;
}

void PetrolEngine::setGear(GearBox gear)
{
    if ((int(gear) > gears_) || (gear < GearBox::rear)) {
        std::cout << "Bad change!";
    }
    else if ((int(gear) > (int)currentGear_ + 1) || (int(gear) < (int)currentGear_ - 1)) {
        std::cout << "How you can do that?!";
    }
    currentGear_ = gear;
    std::cout << __FUNCTION__ << std::endl;
}
