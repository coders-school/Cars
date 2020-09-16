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
    throw InvalidGear("You could set " + std::to_string(static_cast<int>(gear)) + "gear, "
    " but electric car has no gearbox");
}