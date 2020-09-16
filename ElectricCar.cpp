#include "ElectricCar.hpp"
#include <iostream>
#include <string>
#include "ExceptionsClass.hpp"
#include "PetrolCar.hpp"

ElectricCar::ElectricCar(std::unique_ptr<ElectricEngine> engine)
    : electricEngine_(std::move(engine)) {
    std::cout << __FUNCTION__ << std::endl;
}

ElectricCar::~ElectricCar() {
    std::cout << __FUNCTION__ << std::endl;
}
void ElectricCar::charge() {
    std::cout << __FUNCTION__ << std::endl;
}
void ElectricCar::restore() {
    charge();
}
void ElectricCar::changeGear(GearBox gear) {
    throw InvalidGear("You could set " + std::to_string(static_cast<int>(gear)) +
                      "gear, "
                      " but electric car has no gearbox");
}

std::unique_ptr<ElectricEngine> ElectricCar::changeEngine(std::unique_ptr<ElectricEngine> newEngine) {
    if (speed_ != 0) {
        throw InvalidChangeEngine("You have to stop the car if you would like change engine");
    }

    std::unique_ptr<ElectricEngine> tmp = std::move(newEngine);
    std::swap(tmp, electricEngine_);
    return tmp;
}
