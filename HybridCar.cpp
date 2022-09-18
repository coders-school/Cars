#include "HybridCar.hpp"

#include <iostream>

HybridCar::HybridCar(int maxSpeed,
                     int maxReverseSpeed,
                     const PetrolEngine& petrolEng,
                     const ElectricEngine& electricEng)
    : Car(maxSpeed, maxReverseSpeed)
    , ElectricCar(maxSpeed, maxReverseSpeed, electricEng)
    , PetrolCar(maxSpeed, maxReverseSpeed, petrolEng)

{
    std::cout << "HybridCar::" << __FUNCTION__ << " (copying engines)" << std::endl;
}

HybridCar::HybridCar(int maxSpeed,
                     int maxReverseSpeed,
                     PetrolEngine&& petrolEng,
                     ElectricEngine&& electricEng)
    : Car(maxSpeed, maxReverseSpeed)
    , ElectricCar(maxSpeed, maxReverseSpeed, std::move(electricEng))
    , PetrolCar(maxSpeed, maxReverseSpeed, std::move(petrolEng))
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

void HybridCar::replaceElectricEngine(ElectricEngine&& newEngine)
{
    ElectricCar::replaceEngine(std::move(newEngine));
}

void HybridCar::replacePetrolEngine(PetrolEngine&& newEngine)
{
    PetrolCar::replaceEngine(std::move(newEngine));
}