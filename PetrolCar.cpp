#include "PetrolCar.hpp"
#include <iostream>
#include <utility>
 
PetrolCar::PetrolCar(std::unique_ptr<PetrolEngine> engine)
    : engine_(std::move(engine))
{
    // engine_->attached(this);
    std::cout << __FUNCTION__ << std::endl;
}

PetrolCar::~PetrolCar()         { std::cout << __FUNCTION__ << std::endl; }
void PetrolCar::refuel()        { std::cout << __FUNCTION__ << std::endl; }

void PetrolCar::changeEngine(std::unique_ptr<PetrolEngine> ee) {
    
}

void PetrolCar::refill() {
    refuel();
}

