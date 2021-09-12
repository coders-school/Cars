#include "PetrolEngine.hpp"
#include <iostream>
#include "Engine.hpp"

bool PetrolEngine::Gear::operator==(const Gear& other) const {
    return this->val == other.val;
}

bool PetrolEngine::Gear::operator>(const Gear& other) const {
    return this->val > other.val;
}

bool PetrolEngine::Gear::operator<(const Gear& other) const {
    return this->val < other.val;
}

PetrolEngine::PetrolEngine(Engine::HorsePower power, CubicCentimetre capacity, Gear maxGear)
    : Engine(power), capacity_(capacity), maxGear_(maxGear), currentGear_(0) {
    std::cout << __FUNCTION__ << std::endl;
}

void PetrolEngine::changeGear(Gear gear) {
    std::cout << __FUNCTION__ << std::endl;
    if (gear > this->maxGear_ || gear < Gear(-1)) {
        // throw
    }
    if (gear == Gear(-1) && this->currentGear_ > Gear(1)) {
        // throw
    }
    currentGear_ = gear;
}
