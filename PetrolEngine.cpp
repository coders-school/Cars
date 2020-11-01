#include "PetrolEngine.hpp"
#include <algorithm>
#include <iostream>
#include "Exceptions.hpp"

PetrolEngine::PetrolEngine(int power, float capacity, int gears, int maxFuelTank)
    : power_(power)
    , capacity_(capacity)
    , gears_(gears), currentGear_(0)
    , maxFuelTank_(maxFuelTank)
    , currentFuelTank_(0) {
        std::cout << __FUNCTION__ << std::endl;
}
void PetrolEngine::changeGear(int gear) {
    if (gearBoxMap_.contains(gear)) {  //c++20
        currentGear_ = gear;
    } else {
        throw InvalidGear("That gear doesn't exist");
    }
    std::cout << __FUNCTION__ << std::endl;
}
