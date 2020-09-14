#include "PetrolEngine.hpp"
#include "Errors.hpp"

#include <iostream>
#include <stdexcept>

PetrolEngine::PetrolEngine(int power, float capacity, int gears)
    : Engine(power), capacity_(capacity), gears_(gears), currentGear_(0) {
    std::cout << __FUNCTION__ << std::endl;
}

PetrolEngine::~PetrolEngine() {
    std::cout << __FUNCTION__ << std::endl;
}

void PetrolEngine::changeGear(int newGear) {
    // -1 is for REAR
    // 0 is for NEUTRAL
    if (newGear < gears_ && newGear >= -1) {
        try {
            if (newGear == -1 && currentGear_ != 0) {
                throw InvalidGearError{std::to_string(currentGear_)};
            }

            currentGear_ = newGear;
            std::cout << __FUNCTION__ << std::endl;
            std::cout << "Gear was changed to: " << currentGear_ << std::endl;
        } catch (InvalidGearError& currentGear_) {
            std::cerr << currentGear_.what() << "\n";
        }
    }
    std::cout << "Gear out of range - you cannot change gear for " << newGear << '\n';
}

int PetrolEngine::getCurrentGear() const {
    return currentGear_;
}

int PetrolEngine::getGears() const {
    return gears_;
}
float PetrolEngine::getCapacity() const {
    return capacity_;
}
