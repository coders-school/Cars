#include "ElectricCar.hpp"
#include <iostream>

ElectricCar::ElectricCar(ElectricEngine* engine)
    : engine_(engine)
{
    std::cout << __FUNCTION__ << std::endl;
}

ElectricCar::~ElectricCar()       { delete engine_; std::cout << __FUNCTION__ << std::endl; }
void ElectricCar::charge()        { std::cout << __FUNCTION__ << std::endl; }
void ElectricCar::feed()          { charge(); }
void ElectricCar::changeEngine(int power, int batteryCapacity)
{
   if(!velocity)
    {    engine_ = new ElectricEngine(power, batteryCapacity);
        std::cout << "Engine has been changed." << std::endl;
    }

    if(velocity)
        std::cout << "Change engine is impossible." << std::endl;
}
