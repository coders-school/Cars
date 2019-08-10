#include "ElectricEngine.hpp"
#include <iostream>

ElectricEngine::ElectricEngine(int power, int batteryCapacity)
    : power_(power)
    , batteryCapacity_(batteryCapacity)
{
try
{
    if(power_<0)
    {
        throw std::runtime_error("There is impossible to be power less than 0.");
    }
    else if(power_>500)
    {
        throw std::runtime_error("There is impossible to be power more than 500.");
    }
    else
        power=this->power_;

    if(batteryCapacity_<0)
    {
        throw std::runtime_error("There is impossible to be capacity less than 0%.");
    }
    if(batteryCapacity_>100)
    {
        throw std::runtime_error("There is impossible to be capacity more than 100%. ");
    }
    else
        batteryCapacity=this->batteryCapacity_;
}
    catch (const char* msg)
    {
        std::cout << msg << std::endl;
    }
    std::cout << __FUNCTION__ << std::endl;
}
