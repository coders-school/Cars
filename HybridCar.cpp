#include "HybridCar.hpp"
#include <iostream>

HybridCar::HybridCar(std::unique_ptr<PetrolEngine> petrolEng,
                     std::unique_ptr<ElectricEngine> electricEng)
    : PetrolCar(std::move(petrolEng)), ElectricCar(std::move(electricEng)) {
  std::cout << __FUNCTION__ << std::endl;
}

HybridCar::~HybridCar() { std::cout << __FUNCTION__ << std::endl; }

void HybridCar::restore() {
  ElectricCar::restore();
  PetrolCar::restore();
}

void HybridCar::accelerate(int requiredSpeed) {
  if (PetrolCar::getPetrolEngineData() &&
      ElectricCar::getElectricEngineData()) {
    if (requiredSpeed >= 0) {
      speed = requiredSpeed;
      std::cout << "\nAccelerate to: " << requiredSpeed << "km\\h\n";
    } else { 
      throw std::invalid_argument("\nInvalid speed, can't be negative\n");
    }
  } else {
    std::cout << "\nThis car doesn't have an engine!\n";   
  }
}


