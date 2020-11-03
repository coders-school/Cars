#include "HybridCar.hpp"
#include <iostream>

HybridCar::HybridCar(std::unique_ptr<IEngine> petrolEng,
                     std::unique_ptr<IEngine> electricEng)
    : petrolEngine_(std::move(petrolEng)),
      electricEngine_(std::move(electricEng)) {}

HybridCar::~HybridCar() {}
void HybridCar::fill() {
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

void HybridCar::charge() {
  std::cout << __FUNCTION__ << ": " << __FILE__ << ": " << __LINE__
            << std::endl;
}
void HybridCar::refuel() {
  std::cout << __FUNCTION__ << ": " << __FILE__ << ": " << __LINE__
            << std::endl;
}

