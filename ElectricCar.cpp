#include "ElectricCar.hpp"
#include <iostream>
#include <memory>
#include <utility>
#include "ElectricEngine.hpp"
#include "MyExceptions.hpp"

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

void ElectricCar::changeEngine(std::unique_ptr<ElectricEngine> engine) {
    std::cout << __FUNCTION__ << std::endl;
    if (!engine) {
        throw InvalidEngine("Invalid engine provided to ElectricCar::changeEngine");
    }
    engine_->detach();  // Redundant for now
    engine_.reset();
    engine_ = std::move(engine);
    engine_->attach(this);
}

void ElectricCar::charge() {
    std::cout << __FUNCTION__ << std::endl;
}
