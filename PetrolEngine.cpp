#include "PetrolEngine.hpp"
#include <iostream>
#include <stdexcept>

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
    // TODO: Add checking if gear is between -1 and gears_
    // -1 is for REAR
    // 0 is for NEUTRAL
 
 /*
    try
    {
        if (gear >= -1 && gear < gears_)
        {
            currentGear_ = gear;
            std::cout << __FUNCTION__ << std::endl;
        }
        
        else throw std::out_of_range ("Invalid Gear - out of range");
    }

    catch (std::out_of_range  &text) { std::cout<<text.what()<<std::endl;}
 */
    if (gear >= -1 && gear < gears_)
    {
        try
        {
            if(gear == -1 && currentGear_!=0) 
            {
                throw std::out_of_range ("Invalid Gear - You can change gear to R only from 0 gear.");
            }
            else 
            {
                currentGear_ = gear;
                std::cout << __FUNCTION__ ;
                std::cout<<"Current gear: "<<currentGear_<<std::endl;
            }

        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
    }
    else std::cout<<"Wrong gear value. Current gear: "<< currentGear_<<std::endl; 


}
int PetrolEngine::getCurrentGear()
{
    return currentGear_;
}


