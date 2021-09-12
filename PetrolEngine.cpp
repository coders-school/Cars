#include "PetrolEngine.hpp"
#include <iostream>
#include "Engine.hpp"

bool PetrolEngine::Gear::operator==(const Gear& other) const {
    return this->gear_ == other.gear_;
}

PetrolEngine::PetrolEngine(Engine::HorsePower power, CubicCentimetre capacity, Gear maxGear)
    : Engine(power), capacity_(capacity), maxGear_(maxGear), currentGear_(0) {
    std::cout << __FUNCTION__ << std::endl;
}

void PetrolEngine::changeGear(Gear gear) {
    // TODO: Add checking if gear is between -1 and gears_
    // -1 is for REAR
    // 0 is for NEUTRAL
    currentGear_ = gear;
    std::cout << __FUNCTION__ << std::endl;
}
