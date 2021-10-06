#include "ElectricCar.hpp"
#include <iostream>

ElectricCar::ElectricCar(ElectricEngine* engine)
    : engine_(engine)
{
    std::cout << __FUNCTION__ << std::endl;
}

ElectricCar::~ElectricCar() {
    std::cout << __FUNCTION__ << std::endl;
    delete engine_;
}

void ElectricCar::charge()        { std::cout << __FUNCTION__ << std::endl; }

void ElectricCar::refill() {
    charge();
}

void ElectricCar::changeEngine(ElectricEngine* engine) {
    if (isStopped()) {
        if (engine) {
            delete engine_;
            engine_ = engine;
        }
    } else {
        std::cout << "You have to stop the car before changing the engine.\n";
    }
}
