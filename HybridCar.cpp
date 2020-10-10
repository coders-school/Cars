#include "HybridCar.hpp"
#include <iostream>

HybridCar::HybridCar(std::unique_ptr<Engine> petrolEng, std::unique_ptr<Engine> secondEng)
    : PetrolCar(std::move(petrolEng)), ElectricCar(std::move(secondEng)) {}

HybridCar::~HybridCar() {
    std::cout << __FUNCTION__ << std::endl;
}

void HybridCar::restore() {
    PetrolCar::restore();
    ElectricCar::restore();
}
