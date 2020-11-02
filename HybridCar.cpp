#include "HybridCar.hpp"
#include <iostream>

HybridCar::HybridCar(std::unique_ptr<IEngine> petrolEng,
                     std::unique_ptr<IEngine> electricEng)
    : petrolEngine_(std::move(petrolEng)),
      electricEngine_(std::move(electricEng)) {}

HybridCar::~HybridCar() {}
void HybridCar::turnLeft() const {}
void HybridCar::turnRight() const {}
void HybridCar::brake() const {}
void HybridCar::accelerate(Speed speed) const {}
void HybridCar::charge() const {}
void HybridCar::refuel() const {}
void HybridCar::fill() const {
  charge();
  refuel();
}

void HybridCar::start_engine() const {
  petrolEngine_->start();
  electricEngine_->start();
}
void HybridCar::stop_engine() const {
  petrolEngine_->stop();
  electricEngine_->stop();
}
