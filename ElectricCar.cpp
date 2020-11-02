#include "ElectricCar.hpp"
#include <iostream>

ElectricCar::ElectricCar(std::unique_ptr<IEngine> engine)
    : engine_(std::move(engine)) {}

ElectricCar::~ElectricCar() {}
void ElectricCar::turnLeft() const {}
void ElectricCar::turnRight() const {}
void ElectricCar::brake() const {}
void ElectricCar::accelerate(Speed speed) const {}
void ElectricCar::start_engine() const { engine_->start(); }
void ElectricCar::stop_engine() const { engine_->stop(); }

void ElectricCar::charge() {}
void ElectricCar::fill() const {}
