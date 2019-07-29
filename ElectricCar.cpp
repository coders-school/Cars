#include "ElectricCar.hpp"
#include <iostream>

ElectricCar::ElectricCar(ElectricEngine* engine)
    : engine_(engine)
{
    std::cout << __FUNCTION__ << std::endl;
    this -> velocity = 0;
}
ElectricCar::~ElectricCar()       
{ 
    std::cout << __FUNCTION__ << std::endl; 
     delete engine_ ;
}
void ElectricCar::charge()        { std::cout << __FUNCTION__ << std::endl; }
void ElectricCar::feed()          {charge();}
void ElectricCar::ElectricEngineChange(int power, int batteryCapacity)
{
   if (this->velocity == 0)
    {
        delete this->engine_ ;
        this->engine_ = new ElectricEngine(power, batteryCapacity);
        std::cout<< "Engine was changed properly."<<std::endl;
    }
    else std::cout<< "Changing an electric engine during driving is not safe."<<std::endl;
}