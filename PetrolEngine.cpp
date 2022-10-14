#include "PetrolEngine.hpp"
#include <iostream>
#include <stdexcept>

struct InvalidGear : public std::logic_error {
    [[maybe_unused]] InvalidGear() : std::logic_error("Invalid gear") {}

    [[maybe_unused]] InvalidGear(std::string message) : std::logic_error(message) {}
};

PetrolEngine::PetrolEngine(int power, float capacity, int gears)
        : Engine(power), capacity_(capacity), gears_(gears), currentGear_(0) {
    std::cout << __FUNCTION__ << std::endl;
}

void PetrolEngine::changeGear(int gear) {
    if (gear < -1) {
        throw InvalidGear("Gear can't be less than -1");
    }
    if (gear > gears_) {
        throw InvalidGear("Gear can't be greater than " + std::to_string(gears_));
    }
    if (gear == -1 && currentGear_ > 1) {
        throw InvalidGear("Can't change gear to reverse from gear greater than 1");
    }
    currentGear_ = gear;
    std::cout << __FUNCTION__ << std::endl;
}
