#include "HybridCar.hpp"
#include <iostream>

HybridCar::HybridCar(PetrolEngine* petrolEng, ElectricEngine* electricEng) :
        PetrolCar(petrolEng),
        ElectricCar(electricEng) {
    std::cout << __FUNCTION__ << std::endl;
}

HybridCar::~HybridCar() {
    std::cout << __FUNCTION__ << std::endl;
}
void HybridCar::turnLeft() {
    std::cout << __FUNCTION__ << std::endl;
}
void HybridCar::turnRight() {
    std::cout << __FUNCTION__ << std::endl;
}
void HybridCar::brake() {
    std::cout << __FUNCTION__ << std::endl;
}
void HybridCar::accelerate(int) {
    std::cout << __FUNCTION__ << std::endl;
}
