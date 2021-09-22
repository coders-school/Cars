#include <iostream>
#include <memory>
#include <utility>

#include "ElectricCar.hpp"
#include "ElectricEngine.hpp"
#include "Exeptions.hpp"

ElectricCar::ElectricCar(std::unique_ptr<ElectricEngine> engine)
    : engine_(std::move(engine)) {
    std::cout << __FUNCTION__ << std::endl;
}

ElectricCar::~ElectricCar() {
    std::cout << __FUNCTION__ << std::endl;
}
void ElectricCar::charge() {
    std::cout << __FUNCTION__ << std::endl;
}

void ElectricCar::changeEngine(std::unique_ptr<ElectricEngine> ee) {
    std::cout << __FUNCTION__ << std::endl;
    if (!ee) {
        throw InvalidParameter("Invalid engine to electrical car.");
    }
    engine_.reset();
    engine_ = std::move(ee);
}

void ElectricCar::refill() {
    charge();
}
