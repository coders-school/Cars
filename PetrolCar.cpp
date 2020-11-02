#include "PetrolCar.hpp"
#include <iostream>

PetrolCar::PetrolCar(std::unique_ptr<IEngine> engine)
    : engine_(std::move(engine)) {}

PetrolCar::~PetrolCar() {}
void PetrolCar::turnLeft() const {}
void PetrolCar::turnRight() const {}
void PetrolCar::brake() const {}
void PetrolCar::accelerate(Speed speed) const {}
void PetrolCar::refuel() {}
void PetrolCar::fill() const {}

void PetrolCar::start_engine() const { engine_->start(); }
void PetrolCar::stop_engine() const { engine_->stop(); }
