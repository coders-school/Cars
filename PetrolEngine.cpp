#include "PetrolEngine.hpp"
#include <iostream>
#include <stdexcept>

class InvalidGearError : public std::logic_error {
public:
    InvalidGearError(std::string gear)
        : std::logic_error("Invalid Gear - REAR gear cannot be set from " + gear + " gear.") {}
};

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
                //throw std::out_of_range("Invalid Gear - gear -1 can be set only when current gear is equal to 0.");
                throw InvalidGearError{std::to_string(currentGear_)};
            }

            currentGear_ = newGear;
            std::cout << __FUNCTION__ << std::endl;
            std::cout << "Gear was changed to: " << currentGear_ << std::endl;
        } catch (InvalidGearError& currentGear_) {
            std::cerr << currentGear_.what() << "\n";
        }
    }
}

int PetrolEngine::getCurrentGear() const {
    return gears_;
}
