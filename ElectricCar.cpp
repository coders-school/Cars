#include "ElectricCar.hpp"
#include <iostream>

ElectricCar::ElectricCar(Engine* engine) : Car(engine) {
    std::cout << __FUNCTION__ << std::endl;
}

void ElectricCar::charge()        { std::cout << __FUNCTION__ << std::endl; }
void ElectricCar::feed()          { charge(); }

void ElectricCar::changeEngine(Engine* newEngine) {
    if (velocity != 0) {
        throw std::logic_error("Car is moving now! Engine exchange impossible ");
    }
    delete(engine_);
    engine_ = dynamic_cast<ElectricEngine*>(newEngine);
    if (not engine_) {
        throw std::runtime_error("Assembly of motor failed");
    }
}