#include "HybridCar.hpp"
#include <iostream>

HybridCar::HybridCar(std::unique_ptr<PetrolEngine> petrolEng, std::unique_ptr<ElectricEngine> electricEng)
    : petrolEngine_(std::move(petrolEng)), electricEngine_(std::move(electricEng)) {
  std::cout << __FUNCTION__ << std::endl;
}

HybridCar::~HybridCar() { std::cout << __FUNCTION__ << std::endl; }
void HybridCar::turnLeft() const { std::cout << __FUNCTION__ << std::endl; }
void HybridCar::turnRight() const { std::cout << __FUNCTION__ << std::endl; }
void HybridCar::brake() const { std::cout << __FUNCTION__ << std::endl; }
void HybridCar::accelerate(unsigned int) const {
  std::cout << __FUNCTION__ << std::endl;
}
void HybridCar::charge() { std::cout << __FUNCTION__ << std::endl; }
void HybridCar::refuel() { std::cout << __FUNCTION__ << std::endl; }
