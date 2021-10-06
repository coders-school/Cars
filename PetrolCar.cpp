#include "PetrolCar.hpp"
#include <iostream>
#include "Exceptions.hpp"
 
PetrolCar::PetrolCar(PetrolEngine* engine)
    : engine_(engine)
{
    std::cout << __FUNCTION__ << std::endl;
}

PetrolCar::~PetrolCar() {
    std::cout << __FUNCTION__ << std::endl;
    delete engine_;
}

void PetrolCar::refuel()        { std::cout << __FUNCTION__ << std::endl; }

void PetrolCar::refill() {
    refuel();
}

void PetrolCar::changeGear(const int& gear) {
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
        std::cout << "You have to stop the car before changing the engine.\n";
    }
}
