#include "ElectricCar.hpp"
#include <iostream>
#include <memory>
#include <utility>
#include "ElectricEngine.hpp"

ElectricCar::ElectricCar(std::unique_ptr<ElectricEngine> engine)
    : engine_(std::move(engine)) {
    engine_->attach(this);
    std::cout << __FUNCTION__ << std::endl;
}

ElectricCar::~ElectricCar() {
    std::cout << __FUNCTION__ << std::endl;
}

void ElectricCar::refill() {
    this->charge();
}

void ElectricCar::changeEngine(std::unique_ptr<PetrolEngine>) {
    throw std::invalid_argument("Cannot change petrol engine in electric car");
}
void ElectricCar::changeEngine(std::unique_ptr<ElectricEngine> engine) {
    std::cout << __FUNCTION__ << std::endl;
    engine_.reset();
    engine_ = std::move(engine);
}

void ElectricCar::charge() {
    std::cout << __FUNCTION__ << std::endl;
}
