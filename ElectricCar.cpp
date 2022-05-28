#include "ElectricCar.hpp"

ElectricCar::ElectricCar(std::shared_ptr<ElectricEngine> engine)
    : engine_(engine)
{std::cout << __FUNCTION__ << std::endl;}

ElectricCar::~ElectricCar() {std::cout << __FUNCTION__ << std::endl;}
void ElectricCar::charge() {std::cout << __FUNCTION__ << std::endl;}
void ElectricCar::changeEngine(std::shared_ptr<ElectricEngine> ee) {
    engine_ = ee;
}
void ElectricCar::refill() {
    charge();
}
