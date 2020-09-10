#include "PetrolCar.hpp"
#include <iostream>

PetrolCar::PetrolCar(PetrolEngine* engine)
    : petrolEngine_(engine) {
    std::cout << __FUNCTION__ << std::endl;
}

PetrolCar::~PetrolCar() {
    std::cout << __FUNCTION__ << std::endl;
}
void PetrolCar::refill() {
    std::cout << __FUNCTION__ << std::endl;
    refuel();
}
void PetrolCar::refuel() {
    std::cout << __FUNCTION__ << std::endl;
}

void PetrolCar::changeEngine(Engine* petrolEngine) {
    std::cout << __FUNCTION__ << std::endl;

    if (typeid(*petrolEngine) == typeid(PetrolEngine)) {
        delete petrolEngine_;
        petrolEngine_ = static_cast<PetrolEngine*>(petrolEngine);
        ;
    }
}