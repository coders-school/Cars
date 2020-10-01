#include "HybridCar.hpp"
#include <iostream>

HybridCar::HybridCar(PetrolEngine *petrolEng, ElectricEngine *electricEng)
    : petrolEngine_(petrolEng), electricEngine_(electricEng) {
  std::cout << __FUNCTION__ << std::endl;
}

HybridCar::~HybridCar() { std::cout << __FUNCTION__ << std::endl; }
void HybridCar::turnLeft() const { std::cout << __FUNCTION__ << std::endl; }
void HybridCar::turnRight() const { std::cout << __FUNCTION__ << std::endl; }
void HybridCar::brake() const { std::cout << __FUNCTION__ << std::endl; }
void HybridCar::accelerate(int) const {
  std::cout << __FUNCTION__ << std::endl;
}
void HybridCar::charge() { std::cout << __FUNCTION__ << std::endl; }
void HybridCar::refuel() { std::cout << __FUNCTION__ << std::endl; }
