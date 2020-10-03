#include "HybridCar.hpp"
#include <iostream>

HybridCar::HybridCar(std::unique_ptr<IEngine> petrolEng, std::unique_ptr<IEngine> electricEng)
    : petrolEngine_(std::move(petrolEng)), electricEngine_(std::move(electricEng)) {
  std::cout << __FUNCTION__ << ": " <<  __FILE__  << ": " <<  __LINE__  << std::endl;
}

HybridCar::~HybridCar() { std::cout << __FUNCTION__ << ": " <<  __FILE__  << ": " <<  __LINE__  << std::endl; }
void HybridCar::turnLeft() const { std::cout << __FUNCTION__ << ": " <<  __FILE__  << ": " <<  __LINE__  << std::endl; }
void HybridCar::turnRight() const { std::cout << __FUNCTION__ << ": " <<  __FILE__  << ": " <<  __LINE__  << std::endl; }
void HybridCar::brake() const { std::cout << __FUNCTION__ << ": " <<  __FILE__  << ": " <<  __LINE__  << std::endl; }
void HybridCar::accelerate(Speed speed) const {
  std::cout << __FUNCTION__ << ": " <<  __FILE__  << ": " <<  __LINE__  << std::endl;
}
void HybridCar::charge() const { std::cout << __FUNCTION__ << ": " <<  __FILE__  << ": " <<  __LINE__  << std::endl; }
void HybridCar::refuel() const { std::cout << __FUNCTION__ << ": " <<  __FILE__  << ": " <<  __LINE__  << std::endl; }
void HybridCar::fill() const { 
    charge();
    refuel();
    std::cout << __FUNCTION__ << ": " <<  __FILE__  << ": " <<  __LINE__  << std::endl; }

void HybridCar::start_engine() const {
  std::cout << __FUNCTION__ << ": " <<  __FILE__  << ": " <<  __LINE__  << std::endl;
    petrolEngine_->start();
    electricEngine_->start();
}
void HybridCar::stop_engine() const {
  std::cout << __FUNCTION__ << ": " <<  __FILE__  << ": " <<  __LINE__  << std::endl;
    petrolEngine_->stop();
    electricEngine_->stop();
}

