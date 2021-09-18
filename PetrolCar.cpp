#include "PetrolCar.hpp"
#include <iostream>
 
PetrolCar::PetrolCar(std::shared_ptr<PetrolEngine> engine)
    : engine_(engine)
{
    std::cout << __FUNCTION__ << std::endl;
}

PetrolCar::~PetrolCar()         { std::cout << __FUNCTION__ << std::endl; }
void PetrolCar::refuel()        { std::cout << __FUNCTION__ << std::endl; }
void PetrolCar::changeGear(int gear)        { if (engine_) {engine_->changeGear(gear);}  }

