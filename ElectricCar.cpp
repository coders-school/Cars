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
    if(speed = 0){
  return std::move(engine_);
    } else std::cout << "This car is moving, you can't pull out engine\n";
    return std::unique_ptr<ElectricEngine>(nullptr);
}

void ElectricCar::restore(){
    charge();
}

void ElectricCar::accelerate(int a) {
  if (engine_) {
    if (a > 0) {
      std::cout << "\nAccelerate to: " << a << "km\\h\n";
      speed = a;
    } else
      throw std::invalid_argument("\nInvalid speed, can't be negative\n");
  } else
    std::cout << "\nThis car doesn't have an engine!\n";
}

void ElectricCar::putInElectricEngine(std::unique_ptr<ElectricEngine> newEngine){
  engine_.swap(newEngine);
}