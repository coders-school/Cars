#include "PetrolEngine.hpp"
#include <iostream>
#include <stdexcept>

PetrolEngine::PetrolEngine(int power, float capacity, int gears)
    : power_(power), capacity_(capacity), gears_(gears), currentGear_(0) {
    std::cout << __FUNCTION__ << std::endl;
}

void PetrolEngine::changeGear(int newGear) {
    // -1 is for REAR
    // 0 is for NEUTRAL
    if (newGear < gears_ && newGear >= -1) {
        try {
            if (newGear == -1 && currentGear_ != 0) {
                throw std::out_of_range("Invalid Gear - gear -1 can be set only when current gear is equal to 0.");
            }

            currentGear_ = newGear;
            std::cout << __FUNCTION__ << std::endl;
            std::cout << "Gear was changed to: " << currentGear_ << std::endl;
        } catch (const std::exception& exeption) {
            std::cerr << exeption.what() << '\n';
        }
    }
}

int PetrolEngine::getCurrentGear() const {
    return gears_;
}
