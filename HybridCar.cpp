#include "HybridCar.hpp"

#include <iostream>

HybridCar::HybridCar(Engine* electricEng, Engine* petrolEng)
    : Car(electricEng)
    , petrolEngine_(petrolEng)
{
    std::cout << __FUNCTION__ << std::endl;
}

HybridCar::~HybridCar() { 
    std::cout << __FUNCTION__ << std::endl; 
}

void HybridCar::accelerate(int) { 
    std::cout << __FUNCTION__ << std::endl; 
}

void HybridCar::changeGear(int gear, PetrolEngine & petrolEngine) {
    petrolEngine.changeGear(gear);
}

