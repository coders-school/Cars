#include "PetrolCar.hpp"
#include <iostream>

PetrolCar::PetrolCar(std::unique_ptr<IEngine> engine)
    : engine_(std::move(engine)) {}

PetrolCar::~PetrolCar() {}
void PetrolCar::refuel() {
  std::cout << __FUNCTION__ << ": " << __FILE__ << ": " << __LINE__
            << std::endl;
}
void PetrolCar::fill() { refuel(); }

void PetrolCar::start_engine() const { engine_->start(); }
void PetrolCar::stop_engine() const { engine_->stop(); }
