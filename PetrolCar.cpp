#include "PetrolCar.hpp"

#include <iostream>

PetrolCar::PetrolCar(PetrolEngine* engine) : engine_(engine) {
    std::cout << __FUNCTION__ << std::endl;
}

PetrolCar::~PetrolCar() {
    std::cout << __FUNCTION__ << std::endl;
}
void PetrolCar::refuel() {
    std::cout << __FUNCTION__ << std::endl;
}
void PetrolCar::restore() {
    refuel();
}

void PetrolCar::changeEngine(Engine* engine) {
    if (this->getSpeed() == 0) {
        if (typeid(*engine) != typeid(PetrolEngine)) {
            std::cout << "Wrong type of engine\n";
            return;
        }

        delete engine_;
        engine_ = static_cast<PetrolEngine*>(engine);
        std::cout << "Changed petrol engine\n";
    } else {
        std::cout << "Can't change engine during driving\n";
    }
}
