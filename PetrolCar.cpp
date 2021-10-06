#include "PetrolCar.hpp"
#include <iostream>
#include "Exceptions.hpp"
 
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

// int PetrolCar::getCurrentGear() {
//     return engine_->getCurrentGear();
// }

void PetrolCar::changeGear(const int& gear) {
    std::cout << "petrolcar changes gear to: " << gear <<  '\n';
    try {
        engine_->changeGear(gear);
    } catch(InvalidGear& excpt) {
        std::cout << excpt.what() << '\n';
    }
}

void PetrolCar::changeEngine(PetrolEngine* engine) {
    if (isStopped()) {
        if (engine) {
            delete engine_;
            engine_ = engine;
        }
    } else {
        std::cout << "You have to stop the car before changing engine.\n";
    }
}
