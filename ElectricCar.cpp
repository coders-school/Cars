#include "ElectricCar.hpp"
#include <iostream>

ElectricCar::ElectricCar(std::unique_ptr<ElectricEngine> engine)
    : engine_(std::move(engine)) {
  std::cout << __FUNCTION__ << std::endl;
}

ElectricCar::~ElectricCar() { std::cout << __FUNCTION__ << std::endl; }

void ElectricCar::charge() { std::cout << __FUNCTION__ << std::endl; }

ElectricEngine *ElectricCar::getElectricEngineData() const {
  return engine_.get();
}

std::unique_ptr<ElectricEngine> ElectricCar::pullOutElectricEngine() {
  return std::move(engine_);
}