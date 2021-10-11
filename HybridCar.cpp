#include "HybridCar.hpp"
#include <iostream>
#include <typeinfo>

HybridCar::HybridCar(std::unique_ptr<PetrolEngine> petrolEng, std::unique_ptr<ElectricEngine> electricEng)
    : PetrolCar::PetrolCar(std::move(petrolEng)), ElectricCar::ElectricCar(std::move(electricEng)) {
    std::cout << __FUNCTION__ << std::endl;
}

HybridCar::~HybridCar() {
    std::cout << __FUNCTION__ << std::endl;
}



