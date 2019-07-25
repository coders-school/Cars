#include "HybridCar.hpp"
#include <iostream>

HybridCar::HybridCar(Engine* elEngine, PetrolEngine* petrolEng)
    : ElectricCar(elEngine), engine_(petrolEng) {
    std::cout << __FUNCTION__ << std::endl;
}

HybridCar::~HybridCar()       {std::cout << __FUNCTION__ << std::endl; }
void HybridCar::feed() {
    ElectricCar::feed();
 }

void HybridCar::changeEngine(Engine *engine) {

    if (velocity != 0)
        throw std::logic_error( "Car is moving now! Engine exchange impossible ");
    
    auto* engineE = dynamic_cast<ElectricEngine*>(engine);
    if (engineE != nullptr) {
        ElectricCar::changeEngine(engine);
        delete (engineE);
    }

    auto* engineP = dynamic_cast<PetrolEngine*>(engine);
    if (engineP != nullptr) {
        throw std::runtime_error("Change of petrol engine failed");
    }
}
