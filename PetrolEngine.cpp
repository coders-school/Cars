#include "PetrolEngine.hpp"

#include <iostream>
#include <string>

constexpr int rearGear = -1;
constexpr int neutralGear = 0;

PetrolEngine::PetrolEngine(int power, float capacity, int gears)
    : power_(power)
    , capacity_(capacity)
    , gears_(gears)
    , currentGear_(0)
{
    std::cout << __FUNCTION__ << std::endl;
}

void PetrolEngine::changeGear(int gear)
{
    if (gear < -1 || gear > gears_) {
        auto throwMessage = "Cannot shift to " + std::to_string(gear)
            + " you are limited to gears from " + std::to_string(rearGear)
            + " to " + std::to_string(gears_);
        throw InvalidGear { throwMessage };
    } else if (gear == rearGear && currentGear_ != neutralGear) {
        auto throwMessage = "Rear gear can be shift only from neutral gear";
        throw InvalidGear { throwMessage };
    }

    currentGear_ = gear;
    std::cout << __FUNCTION__ << std::endl;
}
