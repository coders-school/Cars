#include "HybridCar.hpp"
#include <iostream>
#include "InvalidEngine.hpp"
#include "MovingCar.hpp"

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
// void HybridCar::changeEngine(std::shared_ptr<ElectricEngine> electricEngine) {
//     ElectricCar::changeEngine(electricEngine);
// }

// void HybridCar::changeEngine(std::shared_ptr<PetrolEngine> petrolEngine) {
//     PetrolCar::changeEngine(petrolEngine);
// }
int HybridCar::getPower() const {
    return ElectricCar::getPower() + PetrolCar::getPower();
}

int HybridCar::getBatteryCapacity() const {
    return ElectricCar::getBatteryCapacity();
}

float HybridCar::getCapacity() const {
    return PetrolCar::getCapacity();
}


//     void changeGear(int gear);
//     int getGears() const;
//     int getCurrentGear() const;
