#include <iostream>

#include "HybridCar.hpp"

HybridCar::HybridCar(std::shared_ptr<PetrolEngine> petrolEngine, std::shared_ptr<ElectricEngine> electricEngine)
    : PetrolCar(petrolEngine), ElectricCar(electricEngine)
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

void HybridCar::setEngine(std::shared_ptr<PetrolEngine> petrolEngine) {
    PetrolCar::setEngine(petrolEngine);
}

void HybridCar::setEngine(std::shared_ptr<ElectricEngine> electricEngine) {
    ElectricCar::setEngine(electricEngine);
}

void HybridCar::setEngine(std::shared_ptr<PetrolEngine> petrolEngine, std::shared_ptr<ElectricEngine> electricEngine) {
    PetrolCar::setEngine(petrolEngine);
    ElectricCar::setEngine(electricEngine);
}
