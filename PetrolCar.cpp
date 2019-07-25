#include "PetrolCar.hpp"
#include <iostream>
 
PetrolCar::PetrolCar(Engine *engine) : Car(engine) {
    std::cout << __FUNCTION__ << std::endl;
}

PetrolCar::~PetrolCar()         {
    delete(engine_);
    engine_ = nullptr;
    std::cout << __FUNCTION__ << std::endl; }
void PetrolCar::refuel()        { std::cout << __FUNCTION__ << std::endl; }
void PetrolCar::feed()          { refuel(); }

void PetrolCar::changeEngine(Engine* newEngine) {
    if (velocity != 0) {
        throw std::logic_error( "Car is moving now! Engine exchange impossible ");
    }
    delete(engine_);
    engine_ = dynamic_cast<PetrolEngine*>(newEngine);
    if (not engine_) {
        throw std::runtime_error("Assembly of motor failed");
    }
}
