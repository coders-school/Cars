#include "PetrolCar.hpp"

#include <iostream>
 
PetrolCar::PetrolCar(Engine* engine)
    : Car(engine)
{
    std::cout << __FUNCTION__ << std::endl;
    engine->getPower();
}

PetrolCar::~PetrolCar() { 
    std::cout << __FUNCTION__ << std::endl; 
}

void PetrolCar::changeGear(int gear, PetrolEngine & petrolEngine) {
    petrolEngine.changeGear(gear);
}
