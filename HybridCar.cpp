#include "HybridCar.hpp"

#include <iostream>

#include "exception/InvalidEngineChange.hpp"

HybridCar::HybridCar(std::unique_ptr<PetrolEngine> petrolEng, std::unique_ptr<ElectricEngine> electricEng)
    : ElectricCar(std::move(electricEng)), PetrolCar(std::move(petrolEng))
{
    std::cout << __FUNCTION__ << std::endl;
}

HybridCar::~HybridCar()         { std::cout << __FUNCTION__ << std::endl; }
 void HybridCar::restore() {
     PetrolCar::refuel();
     HybridCar::charge();
 }

void HybridCar::changePetrolEngine(std::unique_ptr<PetrolEngine> engine) {
    if (speed_ > 0) {
        throw InvalidEngineChange("> cannot change engine while driving!");
    }
    std::swap(petrolEngine_, engine);
}

void HybridCar::changeElectricEngine(std::unique_ptr<ElectricEngine> engine) {
    if (speed_ > 0) {
        throw InvalidEngineChange("> cannot change engine while driving!");
    }
    std::swap(electricEngine_, engine);
}
