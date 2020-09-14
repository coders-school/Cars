#include <iostream>

#include "HybridCar.hpp"

HybridCar::HybridCar(PetrolEngine* petrolEngine, ElectricEngine* electricEngine)
    : PetrolCar(petrolEngine),
      ElectricCar(electricEngine),
      petrolEngine_(petrolEngine),
      electricEngine_(electricEngine)
{
    std::cout << "* " << __FUNCTION__ << std::endl;
}

HybridCar::~HybridCar() {
    std::cout << "* " << __FUNCTION__ << std::endl;
}

void HybridCar::restore() {
    PetrolCar::restore();
    ElectricCar::restore();
}

void HybridCar::changeGear(int gear) {
    std::cout << __FUNCTION__ << " : automatic transmission" << std::endl;
    (void)gear;
}

void HybridCar::setEngine(PetrolEngine* petrolEngine, ElectricEngine* electricEngine) {
    std::cout << __FUNCTION__;
    if (!getSpeed()) {
        std::cout << " : engine changed" << std::endl;
        // * cannot delete old resources assigned while creating HybridCar object *
        // delete petrolEngine_;        // free(): double free detected in tcache 2
        // delete electricEngine_;      // free(): double free detected in tcache 2
        petrolEngine_ = petrolEngine;
        electricEngine_ = electricEngine;
        std::cout << "@ petrol power: " << petrolEngine_->getPower() << std::endl;
        std::cout << "@ electric power: " << electricEngine_->getPower() << std::endl;
    } else {
        std::cout << " : not possible unless stopped" << std::endl;
        delete petrolEngine;
        delete electricEngine;
    }
}
void HybridCar::setEngine(PetrolEngine*) {}
void HybridCar::setEngine(ElectricEngine*) {}
