#include <iostream>
#include "PetrolCar.hpp"

PetrolCar::PetrolCar(PetrolEngine *engine)
    : engine_(engine)
{
    std::cout << __FUNCTION__ << std::endl;
}

PetrolCar::~PetrolCar() { std::cout << __FUNCTION__ << std::endl; }
void PetrolCar::refuel() { std::cout << __FUNCTION__ << std::endl; }

void PetrolCar::changeEngine(Engine *engine)
{
    delete engine_;
    engine_ = engine;
    std::cout << __FUNCTION__ << std::endl;
}

void PetrolCar::refill()
{
    refuel();
    std::cout << __FUNCTION__ << std::endl;
}
