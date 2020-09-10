#include "ElectricCar.hpp"

#include <iostream>

ElectricCar::ElectricCar(ElectricEngine* engine) : engine_(engine) {
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

void ElectricCar::changeEngine(Engine* engine) {
    if (this->getSpeed() == 0) {
        if (typeid(*engine) != typeid(ElectricEngine)) {
            std::cout << "Wrong type of engine\n";
            return;
        }

        delete engine_;
        engine_ = static_cast<ElectricEngine*>(engine);
        std::cout << "Changed electric engine\n";
    } else {
        std::cout << "Can't change engine during driving\n";
    }
}
