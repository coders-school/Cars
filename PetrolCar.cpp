#include "PetrolCar.hpp"
#include <iostream>
 
// PetrolCar::PetrolCar(Engine* engine)
PetrolCar::PetrolCar(PetrolEngine* engine)
    : engine_(engine)
{
    std::cout << __FUNCTION__ << std::endl;
}

PetrolCar::~PetrolCar() {
    std::cout << __FUNCTION__ << std::endl;
    delete engine_;
}

// void PetrolCar::turnLeft()      { std::cout << __FUNCTION__ << std::endl; }
// void PetrolCar::turnRight()     { std::cout << __FUNCTION__ << std::endl; }
// void PetrolCar::brake()         { std::cout << __FUNCTION__ << std::endl; }
// void PetrolCar::accelerate(int) { std::cout << __FUNCTION__ << std::endl; }
void PetrolCar::refuel()        { std::cout << __FUNCTION__ << std::endl; }

void PetrolCar::refill() {
    refuel();
}

void PetrolCar::changeGear(const int& gear) {
    std::cout << "petrolcar changes gear to: " << gear <<  '\n';
    // engine_->changeGear(gear);
}

void PetrolCar::changeEngine(PetrolEngine* engine) {
    if (engine) {
        delete engine_;
        engine_ = engine;
    }
}
