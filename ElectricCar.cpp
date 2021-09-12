#include "ElectricCar.hpp"
#include <iostream>
#include <memory>
#include <utility>
#include "ElectricEngine.hpp"

ElectricCar::ElectricCar(std::unique_ptr<ElectricEngine> engine)
    : electricEngine_(std::move(engine)) {
    electricEngine_->attach(this);
    std::cout << __FUNCTION__ << std::endl;
}

ElectricCar::~ElectricCar() {
    std::cout << __FUNCTION__ << std::endl;
}

void ElectricCar::refill() {
    this->charge();
}

void ElectricCar::charge() {
    std::cout << __FUNCTION__ << std::endl;
}
