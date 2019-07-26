#include "ElectricCar.hpp"
#include <iostream>

ElectricCar::ElectricCar(ElectricEngine* engine) : engine_(engine)
{
    std::cout << __FUNCTION__ << std::endl;
}

ElectricCar::~ElectricCar()
{
    std::cout << __FUNCTION__ << std::endl;
    delete engine_;
}
void ElectricCar::charge()        { std::cout << __FUNCTION__ << std::endl; }
void ElectricCar::feed()          { charge(); }

void ElectricCar::changeElectricEngine(ElectricEngine* newEngine)
{
    if(getVelocity()!=0)
    {
        std::cout << "You can't replace your engine on the run!\n";
    }
    else
    {
        delete engine_;
        engine_ = newEngine;
        std::cout << "You've changed your electric engine!\n";
    }
}