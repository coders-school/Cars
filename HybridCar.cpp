#include "HybridCar.hpp"

#include <iostream>

HybridCar::HybridCar(PetrolEngine* petrolEng, ElectricEngine* electricEng)
    : PetrolCar(petrolEng), ElectricCar(electricEng) {
    std::cout << __FUNCTION__ << std::endl;
}

HybridCar::~HybridCar() {
    std::cout << __FUNCTION__ << std::endl;
}

void HybridCar::restore() {
    ElectricCar::restore();
    PetrolCar::restore();
}

void HybridCar::changeEngine(Engine* engine) {
    if (typeid(*engine) == typeid(ElectricEngine)) {
        ElectricCar::changeEngine(engine);
    }
    if (typeid(*engine) == typeid(PetrolEngine)) {
        PetrolCar::changeEngine(engine);
    }
}

void HybridCar::setGear(int gear) {
    PetrolCar::setGear(gear);
}
