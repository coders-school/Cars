#include "PetrolCar.hpp"
#include "GearException.hpp"
#include "SpeedException.hpp"
#include <iostream>
 
PetrolCar::PetrolCar(std::unique_ptr<PetrolEngine> engine)
    : engine_(std::move(engine))
{
    std::cout << __FUNCTION__ << std::endl;
}

PetrolCar::~PetrolCar()         { std::cout << __FUNCTION__ << std::endl; }
void PetrolCar::refuel()        { std::cout << __FUNCTION__ << std::endl; }
void PetrolCar::restore()       { refuel(); }

void PetrolCar::changeGear(int gear){
    engine_->changeGear(gear);
}

void PetrolCar::changeEngine(std::unique_ptr<PetrolEngine> engine) {
    if(getCurrentSpeed() > 0){
        throw SpeedException("Cannot change engine while driving.\n");
    }
    engine_ = std::move(engine);
}