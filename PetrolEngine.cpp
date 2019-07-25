#include "PetrolEngine.hpp"
#include "InvalidGear.hpp"
#include <iostream>

PetrolEngine::PetrolEngine(int power, float capacity, int gears)
    : power_(power), capacity_(capacity), gears_(gears), currentGear_(0)
{
    std::cout << __FUNCTION__ << std::endl;
}
PetrolEngine::~PetrolEngine()
{
    std::cout << __FUNCTION__ << std::endl;
};

void PetrolEngine::changeGear(int gear)
{
    // TODO: Add checking if gear is between -1 and gears_
    // -1 is for REAR
    // 0 is for NEUTRAL
    if (gear <= gears_ && gear >= -1)
    {
        try
        {
            if (currentGear_ > 0 && gear == -1)
            {
                throw InvalidGear();
            }
            else
            {
                currentGear_ = gear;
                std::cout << __FUNCTION__ << std::endl;
            }
        }
        catch (InvalidGear &exception)
        {
             std::cout << exception.what() << '\n';
        }
    }
    else
    {
        std::cout << "There is not an avaible gear" << std::endl;
    }
}
int PetrolEngine::getCurrentGear()
{
    return currentGear_;
}