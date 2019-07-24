#include "ElectricCar.hpp"
#include <iostream>

ElectricCar::ElectricCar(ElectricEngine* engine)
    : engine_(engine)
{
    std::cout << __FUNCTION__ << std::endl;
}

ElectricCar::~ElectricCar()
{
    delete engine_;
    std::cout << __FUNCTION__ << std::endl;
}
void ElectricCar::charge()
{
    if(Car::velocity == 0)
        std::cout << __FUNCTION__ << std::endl;
    else
        std::cout << "You can't charge Your car while driving!" << std::endl;
}
void ElectricCar::changeElectricEngine(ElectricEngine* engine)
{
    if(velocity!=0)
        std::cout<<"You can't change engine while driving!"<<std::endl;
    else
        engine_ = engine;
}
void ElectricCar::feed()          { charge(); }
