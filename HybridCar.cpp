#include "HybridCar.hpp"
#include <iostream>
#include "InvalidEngine.hpp"
#include "MovingCar.hpp"

//HybridCar::HybridCar(PetrolEngine* petrolEng, ElectricEngine* electricEng)
HybridCar::HybridCar(std::shared_ptr<PetrolEngine> petrolEng, std::shared_ptr<ElectricEngine> electricEng)
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

void HybridCar::changeEngine(std::shared_ptr<ElectricEngine> electricEngine, std::shared_ptr<PetrolEngine> petrolEngine) {
    ElectricCar::changeEngine(electricEngine);
    PetrolCar::changeEngine(petrolEngine);
}
////tak lub nie
void HybridCar::changeEngine(std::shared_ptr<ElectricEngine> electricEngine) {
    ElectricCar::changeEngine(electricEngine);
}

void HybridCar::changeEngine(std::shared_ptr<PetrolEngine> petrolEngine) {
    PetrolCar::changeEngine(petrolEngine);
}
