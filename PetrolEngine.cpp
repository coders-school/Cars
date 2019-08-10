#include "PetrolEngine.hpp"
#include <iostream>
#include "Car.hpp"
PetrolEngine::PetrolEngine(int power, float capacity, int gears)
    : power_(power)
    , capacity_(capacity)
    , gears_(gears)
    , currentGear_(0)
{
try
{
    if(power_<0)
    {   
        throw std::runtime_error("There is impossible to be power less than 0.");
    }
    else if(power_>200)
    {   
        throw std::runtime_error("There is impossible to be power more than 200.");
    }
    else
        power=this->power_;
    if(capacity_<0)
    {
        throw std::runtime_error("There is impossible to be capacity less than 0.");
    }
    if(capacity_>6000)
    {
        throw std::runtime_error("There is impossible to be capacity more than 6000.");
    }
    else
        capacity=this->capacity_;

    if(gears_<1)
    {
        throw std::runtime_error("There is impossible. The engine has minimum 1 gear.");    
    }
}
catch (const char* msg)
    {
        std::cout << msg << std::endl;
    }

    std::cout << __FUNCTION__ << std::endl;
}
void PetrolEngine::changeGear(int gear)
{
    // TODO: Add checking if gear is between -1 and gears_
    // -1 is for REAR
    // 0 is for NEUTRAL
    try
    {
        if(gear<-1 && gear>gears_)
        {
            throw std::runtime_error("Invalid gear.");
        }
        else if(currentGear_>0 && gear==-1)
        {
            throw std::runtime_error("Invalid gear. You can't change gear on REAR if you are driving forward.");
        }
        else
            currentGear_ = gear;
    }
    catch (const char* msg)
    {
        std::cout << msg << std::endl;
    }
        std::cout << __FUNCTION__ << std::endl;
    
    
}
