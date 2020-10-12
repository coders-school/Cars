#include "HybridCar.hpp"
#include <iostream>

HybridCar::HybridCar(std::unique_ptr<PetrolEngine> petrolEng,
                     std::unique_ptr<ElectricEngine> electricEng)
    : PetrolCar(std::move(petrolEng)), ElectricCar(std::move(electricEng)) {
  std::cout << __FUNCTION__ << std::endl;
}

HybridCar::~HybridCar() { std::cout << __FUNCTION__ << std::endl; }

/* PetrolEngine *PetrolCar::getPetrolEngineData() const { return engine_.get(); }

std::unique_ptr<PetrolEngine> PetrolCar::pullOutPetrolEngine() {
  return std::move(engine_);
}

void PetrolCar::putInPetrolEngine(
    std::unique_ptr<PetrolEngine> newEngine) {
  if (engine_ != nullptr) {
    std::cout << "There is an engine in car!\n";
  } else {
    engine_.swap(newEngine);
  }
}

ElectricEngine *ElectricCar::getElectricEngineData() const {
  if (engine_ != nullptr)
    return engine_.get();
  else
    throw std::runtime_error(
        "You can't get to data, because engine doesn't exists\n");
}

std::unique_ptr<ElectricEngine> ElectricCar::pullOutElectricEngine() {
  if (speed == 0) {
    std::cout << "Electric engine is pulled out\n";
    return std::move(engine_);
  } else
    throw std::runtime_error("This car is moving, you can't pull out engine\n");
}

void ElectricCar::putInElectricEngine(
    std::unique_ptr<ElectricEngine> newEngine) {
  if (engine_ != nullptr) {
    std::cout << "There is an engine in car!\n";
  } else
    engine_.swap(newEngine);
} */

void HybridCar::restore() {
  ElectricCar::restore();
  PetrolCar::restore();
}

void HybridCar::accelerate(int requiredSpeed) {
  if (PetrolCar::getPetrolEngineData() &&
      ElectricCar::getElectricEngineData()) {
    if (requiredSpeed > 0) {
      std::cout << "\nAccelerate to: " << requiredSpeed << "km\\h\n";
    } else { 
      throw std::invalid_argument("\nInvalid speed, can't be negative\n");
    }
  } else {
    std::cout << "\nThis car doesn't have an engine!\n";   
  }
}


