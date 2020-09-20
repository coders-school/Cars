#include "PetrolEngine.hpp"
#include "ExceptionsCars.hpp"

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
        throw InvalidGear("Just " + std::to_string(gears_) + " gears!");
    }
    else if ((int(gear) > (int)currentGear_ + 1) || (int(gear) < (int)currentGear_ - 1)) {
        throw InvalidGear("Do you want to destroy your gear box?! Current gear " + std::to_string((int)currentGear_) + " and try to set " + std::to_string((int)gear));
    }
    currentGear_ = gear;
    std::cout << __FUNCTION__ << std::endl;
}
