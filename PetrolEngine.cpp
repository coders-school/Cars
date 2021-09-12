#include "PetrolEngine.hpp"
#include <iostream>
#include "Engine.hpp"

PetrolEngine::PetrolEngine(Engine::HorsePower power, float capacity, int gears)
    : Engine(power), capacity_(capacity), gears_(gears), currentGear_(0) {
    std::cout << __FUNCTION__ << std::endl;
}

void PetrolEngine::changeGear(int gear) {
    // TODO: Add checking if gear is between -1 and gears_
    // -1 is for REAR
    // 0 is for NEUTRAL
    currentGear_ = gear;
    std::cout << __FUNCTION__ << std::endl;
}
