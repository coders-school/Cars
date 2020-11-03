#include "ElectricCar.hpp"
#include <iostream>

ElectricCar::ElectricCar(std::unique_ptr<IEngine> engine)
    : engine_(std::move(engine)) {}

ElectricCar::~ElectricCar() {}
void ElectricCar::start_engine() const { engine_->start(); }
void ElectricCar::stop_engine() const { engine_->stop(); }

void ElectricCar::charge() {
  std::cout << __FUNCTION__ << ": " << __FILE__ << ": " << __LINE__
              << std::endl;
}
void ElectricCar::fill() { charge(); }
