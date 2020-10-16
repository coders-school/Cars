#include "PetrolEngine.hpp"
#include <iostream>

constexpr int reverseGear = -1;
constexpr int maxDiffrenceChangeGear = 2;

PetrolEngine::PetrolEngine(int power, float capacity, int gears)
    : power_(power), capacity_(capacity), gears_(gears), currentGear_(0) {
    std::cout << __FUNCTION__ << std::endl;
}

PetrolEngine::~PetrolEngine() {
    std::cout << __FUNCTION__ << std::endl;
}

void PetrolEngine::changeGear(int gear) {
    if (gear < reverseGear || gear > gears_) {
        throw InvalidGear("Wrong gear");
    } else if (abs(gear - currentGear_) > maxDiffrenceChangeGear) {
        throw InvalidGear("Not allowed gears changing more two");
    }
    currentGear_ = gear;
    std::cout << __FUNCTION__ << std::endl;
}

void PetrolEngine::showCurrentGear() const {
    std::cout << "Current gear = " << currentGear_ << "\n";
}

int PetrolEngine::getCurrentGear() {
    return currentGear_;
}

void PetrolEngine::printInfoEngine() const {
    std::cout << "Petrol Engine: \n";
    std::cout << "Power = " << power_ << "\n";
    std::cout << "Capacity = " << capacity_ << "\n";
    std::cout << "Gears = " << gears_ << "\n";
    std::cout << "Current gear = " << currentGear_ << "\n";
}