#include "HybridCar.hpp"

#include <iostream>

HybridCar::HybridCar(PetrolEngine* petrolEng, ElectricEngine* electricEng)
    : ElectricCar(electricEng), PetrolCar(petrolEng) {
    std::cout << __FUNCTION__ << std::endl;
}

HybridCar::~HybridCar() {
    std::cout << __FUNCTION__ << std::endl;
}

void HybridCar::restore() {
    std::cout << __FUNCTION__ << std::endl;
    charge();
    refuel();
}

void HybridCar::changeEngine(Engine* engine) {
    if (speed_ == 0) {
        if (typeid(*engine) == typeid(PetrolEngine)) {
            delete petrolEngine_;
            petrolEngine_ = static_cast<PetrolEngine*>(engine);
            std::cout << "Changed petrol engine\n";
        } else if (typeid(*engine) == typeid(ElectricEngine)) {
            delete electricEngine_;
            electricEngine_ = static_cast<ElectricEngine*>(engine);
            std::cout << "Changed electric engine\n";
        } else {
            std::cout << "Wrong type of engine\n";
            delete engine;
        }
    } else {
        std::cout << "Can't change engine during driving\n";
        delete engine;
    }
}
