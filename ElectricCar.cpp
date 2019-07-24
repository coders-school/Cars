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
    std::cout << __FUNCTION__ << std::endl; 
}

ElectricEngine* ElectricCar::changeEngine (int power, int batteryCapacity)
{
    if (velocity!=0)
    {
        std::cout<< "Imposible"<<std::endl;
        return this->engine_;
    }
    else
    {
        std::cout << __FUNCTION__ << std::endl;
	delete engine_;
        this->engine_ = new ElectricEngine(power,batteryCapacity);
        std::cout << "Power: "<<this->engine_->power_<<" Battery: "<<this->engine_->batteryCapacity_<< std::endl;
        return this->engine_;
    }
}
