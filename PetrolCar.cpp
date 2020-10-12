#include "PetrolCar.hpp"
#include <iostream>

PetrolCar::PetrolCar(std::unique_ptr<PetrolEngine> engine)
    : engine_(std::move(engine)) {
  std::cout << __FUNCTION__ << std::endl;
}

PetrolCar::~PetrolCar() { std::cout << __FUNCTION__ << std::endl; }

void PetrolCar::refuel() { std::cout << __FUNCTION__ << std::endl; }

void PetrolCar::restore() { refuel(); }

PetrolEngine *PetrolCar::getPetrolEngineData() const {
  if (engine_ != nullptr)
    return engine_.get();
  else
    throw std::runtime_error(
        "You can't get to data, because engine doesn't exists\n");
}

std::unique_ptr<PetrolEngine> PetrolCar::pullOutPetrolEngine() {
  if (speed == 0) {
    std::cout << "Petrol engine is pulled out\n";
    return std::move(engine_);
  } else
    throw std::runtime_error("This car is moving, you can't pull out engine\n");
}


void PetrolCar::putInPetrolEngine(
    std::unique_ptr<PetrolEngine> newEngine) {
  if (engine_ != nullptr) {
    std::cout << "There is an engine in car!\n";
  } else {
    engine_.swap(newEngine);
  }
}

void PetrolCar::accelerate(int a) {
  if (engine_) {
    if (a >= 0) {
      speed = a;
      std::cout << "Accelerate to: " << a << "km\\h\n";
    } else {
      throw std::invalid_argument("Invalid speed, can't be negative\n"); 
    }
  } else {
    std::cout << "This car doesn't have an engine!\n";
  }
}

