#include "PetrolEngine.hpp"
#include <iostream>
#include "Car.hpp"
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

PetrolEngine::PetrolEngine(const Engine::HorsePower& power, const CubicCentimetre& capacity, const Gear& maxGear)
    : Engine(power), capacity_(capacity), maxGear_(maxGear), currentGear_(0) {
    std::cout << __FUNCTION__ << std::endl;
}

void PetrolEngine::changeGear(Gear gear) {
    std::cout << __FUNCTION__ << std::endl;
    if (!this->car_) {
        std::cout << "Tried to change gear on engie without a car\n";
        return;
    }
    if (gear > this->maxGear_ || gear < Gear(-1)) {
        // throw
        std::cout << gear.val << " does not exist\n";
        return;
    }
    if (gear == Gear(-1) && this->car_->getSpeed() != Car::Speed(0)) {
        // throw
        std::cout << "Unsafe to change gear\n";
        return;
    }
    currentGear_ = gear;
}
