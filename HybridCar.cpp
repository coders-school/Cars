#include "Exceptions.hpp"
#include "HybridCar.hpp"
#include <algorithm>
#include <iostream>

HybridCar::HybridCar(std::unique_ptr<PetrolEngine> petrolEng, std::unique_ptr<ElectricEngine> electricEng)
    : PetrolCar(std::move(petrolEng)), ElectricCar(std::move(electricEng)) {
    std::cout << __FUNCTION__ << std::endl;
}
HybridCar::~HybridCar() {
    std::cout << __FUNCTION__ << std::endl;
}
void HybridCar::restore() {
    ElectricCar::restore();
    PetrolCar::restore();
}
void HybridCar::changeEngine(std::unique_ptr<ElectricEngine> newElectricEngine,
                             std::unique_ptr<PetrolEngine> newPetrolEngine) {
    std::swap(electricEngine_, newElectricEngine);
    std::swap(petrolEngine_, newPetrolEngine);
}
void HybridCar::changeDriveMode(int mode) {
    if (driveMode_.contains(mode)) {  //c++20
        currentMode_ = mode;
    } else {
        throw InvalidDriveMode("That mode doesn't exist");
    }
    std::cout << __FUNCTION__ << std::endl;
}