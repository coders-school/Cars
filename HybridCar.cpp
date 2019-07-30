#include "HybridCar.hpp"
#include <iostream>

HybridCar::HybridCar(PetrolEngine *petrolEng, ElectricEngine *electricEng)
    : PetrolCar(petrolEng), ElectricCar(electricEng)
{
    std::cout << __FUNCTION__ << std::endl;
}

HybridCar::~HybridCar() { std::cout << __FUNCTION__ << std::endl; }

void HybridCar::addEnergy() { refuel(), charge(); }
void HybridCar::changeEngine(PetrolEngine *petrolEngine, ElectricEngine *electricEngine)
{
    if (velocity == 0)
    {
        delete this->petrolEngine_;
        delete this->electricEngine_;

        this->electricEngine_ = electricEngine;
        this->petrolEngine_ = petrolEngine;
        std::cout<<"Engine change"<< std::endl;
    }
    else
    {
        std::cout << "You cannot do this during the ride!" << std::endl;
    }
}

