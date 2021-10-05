#include "PetrolEngine.hpp"
#include <iostream>
#include "Exceptions.hpp"

PetrolEngine::PetrolEngine(int power, float capacity, int gears)
    // : Engine(power)
    : power_(power)
    , capacity_(capacity)
    , gears_(gears)
    , currentGear_(0)
{
    std::cout << __FUNCTION__ << std::endl;
}

void PetrolEngine::changeGear(int gear)
{
    // TODO: Add checking if gear is between -1 and gears_
    // -1 is for REAR
    // 0 is for NEUTRAL
    constexpr int maxGearToR = 2;

    try {
        std::cout << "petrolengine: " << gear <<  '\n';
        if (gear >= -1 && gear <= gears_) {
            if ((gear == -1) && currentGear_ > maxGearToR) {
                throw InvalidGear("Can't change gear from " + std::to_string(currentGear_) + " to R.");
            } else {
                currentGear_ = gear;
            }
        } else {
            throw InvalidGear("Invalid gear.");
        }
    } catch(InvalidGear& excpt) {
        std::cout << excpt.what() << '\n';
    }
    std::cout << __FUNCTION__ << std::endl;
}
