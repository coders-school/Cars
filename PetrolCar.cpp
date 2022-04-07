#include <iostream>
#include "PetrolCar.hpp"

PetrolCar::PetrolCar(std::unique_ptr<Engine> engine)
    : engine_(std::move(engine))
{
    std::cout << __FUNCTION__ << std::endl;
}

PetrolCar::~PetrolCar() { std::cout << __FUNCTION__ << std::endl; }
void PetrolCar::refuel() { std::cout << __FUNCTION__ << std::endl; }

void PetrolCar::changeEngine(std::unique_ptr<Engine> engine)
{
    engine_ = std::move(engine);
    std::cout << __FUNCTION__ << std::endl;
}

void PetrolCar::refill()
{
    refuel();
    std::cout << __FUNCTION__ << std::endl;
}
