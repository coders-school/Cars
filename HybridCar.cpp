#include "HybridCar.hpp"
#include <iostream>

HybridCar::HybridCar(PetrolEngine* petrolEng, ElectricEngine* electricEng) :
        PetrolCar(petrolEng, Litre(60)),
        ElectricCar(electricEng) {
}

HybridCar::~HybridCar() {
}

void HybridCar::restore() {
    PetrolCar::restore();
    ElectricCar::restore();
}
