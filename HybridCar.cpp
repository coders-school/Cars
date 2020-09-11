#include "HybridCar.hpp"
#include <iostream>

HybridCar::HybridCar(std::shared_ptr<PetrolEngine> petrolEng,
                     std::shared_ptr<ElectricEngine> electricEng)
    : PetrolCar(petrolEng), ElectricCar(electricEng) {
    std::cout << __FUNCTION__ << std::endl;
}

HybridCar::~HybridCar() {
    std::cout << __FUNCTION__ << std::endl;
}

void HybridCar::restore() {
    this->refuel();
    this->charge();
}
