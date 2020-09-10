#include "HybridCar.hpp"
#include "MovingCar.hpp"
#include "InvalidEngine.hpp"

#include <iostream>

HybridCar::HybridCar(PetrolEngine* petrolEng, ElectricEngine* electricEng)
    : ElectricCar(electricEng)
    , PetrolCar(petrolEng) {
    std::cout << __FUNCTION__ << std::endl;
}

HybridCar::~HybridCar() {
    std::cout << __FUNCTION__ << std::endl;
}

void HybridCar::restore() {
    std::cout << __FUNCTION__ << std::endl;
    PetrolCar::restore();
    ElectricCar::restore();
}

void HybridCar::changeEngine(Engine* engine) {
    if (speed_ != 0) {
        throw MovingCar("Car is in move");
    } else if (typeid(*engine) == typeid(ElectricEngine)) {
        delete electricEngine_;
        electricEngine_ = static_cast<ElectricEngine*>(engine);
    } else if (typeid(*engine) == typeid(PetrolEngine)) {
        delete petrolEngine_;
        petrolEngine_ = static_cast<PetrolEngine*>(engine);    
    } else {
        throw InvalidEngine("Invalid engine type");
    }
}
