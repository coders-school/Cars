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

void ElectricCar::charge()        { std::cout << __FUNCTION__ << std::endl; }
void ElectricCar::feed()
{
    if (velocity == 0) charge(); 
}
void ElectricCar::setElectricEngine(int power, int batteryCapacity)
{
    if  (this->velocity !=0)
         std::cout<<"Engine change imppossible, stop the car!"<<std::endl;
    else {
        delete this->engine_;
        this->engine_=new ElectricEngine(power, batteryCapacity);
        std::cout<<"New engine!"<<std::endl;
         }
}
