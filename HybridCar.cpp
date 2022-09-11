#include "HybridCar.hpp"

#include <iostream>

HybridCar::HybridCar(const PetrolEngine& petrolEng, ElectricEngine& electricEng)
    : ElectricCar(electricEng)
    , PetrolCar(petrolEng)
{
    std::cout << "HybridCar::" << __FUNCTION__ << " (copying engines)" << std::endl;
}

HybridCar::HybridCar(PetrolEngine&& petrolEng, ElectricEngine&& electricEng)
    : ElectricCar(std::move(electricEng))
    , PetrolCar(std::move(petrolEng))
{
    std::cout << "HybridCar::" << __FUNCTION__ << " (moving engines)" << std::endl;
}

HybridCar::~HybridCar()
{
    std::cout << __FUNCTION__ << std::endl;
}

void HybridCar::refill()
{
    std::cout << "HybridCar::" << __FUNCTION__ << std::endl;
    ElectricCar::refill();
    PetrolCar::refill();
}
