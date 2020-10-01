#include "ElectricCar.hpp"
#include <iostream>

ElectricCar::ElectricCar(std::unique_ptr<ElectricEngine> engine) : engine_(std::move(engine)) {
  std::cout << __FUNCTION__ << ": " <<  __FILE__  << ": " <<  __LINE__  << std::endl;
}

ElectricCar::~ElectricCar() { std::cout << __FUNCTION__ << ": " <<  __FILE__  << ": " <<  __LINE__  << std::endl; }
void ElectricCar::turnLeft() const { std::cout << __FUNCTION__ << ": " <<  __FILE__  << ": " <<  __LINE__  << std::endl; }
void ElectricCar::turnRight() const { std::cout << __FUNCTION__ << ": " <<  __FILE__  << ": " <<  __LINE__  << std::endl; }
void ElectricCar::brake() const { std::cout << __FUNCTION__ << ": " <<  __FILE__  << ": " <<  __LINE__  << std::endl; }
void ElectricCar::accelerate(unsigned int) const {
  std::cout << __FUNCTION__ << ": " <<  __FILE__  << ": " <<  __LINE__  << std::endl;
}
void ElectricCar::charge()        { std::cout << __FUNCTION__ << ": " <<  __FILE__  << ": " <<  __LINE__  << std::endl; }
