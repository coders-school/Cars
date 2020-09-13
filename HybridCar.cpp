#include "HybridCar.hpp"

#include <iostream>

#include "WrongEngine.hpp"
#include "CarHaveMove.hpp"

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
            throw InvalidEngine("Wrong type of Engine");
        }
    } else {
       throw MovingCar("Can you switch your Engine while u driving? Respect+");
    }
}