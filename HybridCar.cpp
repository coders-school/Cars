#include "HybridCar.hpp"
#include <iostream>
#include <typeinfo>

HybridCar::HybridCar(PetrolEngine* petrolEng, ElectricEngine* electricEng)
    : PetrolCar::PetrolCar(petrolEng), ElectricCar::ElectricCar(electricEng) {
    std::cout << __FUNCTION__ << std::endl;
}

HybridCar::~HybridCar() {
    std::cout << __FUNCTION__ << std::endl;
}
