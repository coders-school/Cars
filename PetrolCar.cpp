#include "PetrolCar.hpp"
#include <iostream>
 
PetrolCar::PetrolCar(std::unique_ptr<PetrolEngine>engine)
    : engine_(std::move(engine))
{
    std::cout << __FUNCTION__ << std::endl;
}

PetrolCar::~PetrolCar()         { std::cout << __FUNCTION__ << std::endl; }
void PetrolCar::turnLeft()      { std::cout << __FUNCTION__ << std::endl; }
void PetrolCar::turnRight()     { std::cout << __FUNCTION__ << std::endl; }
void PetrolCar::brake()         { std::cout << "brake petrol car \n" << std::endl; }
void PetrolCar::accelerate(int) { std::cout << __FUNCTION__ << std::endl; }
void PetrolCar::refuel()        { std::cout << __FUNCTION__ << std::endl; }

const std::unique_ptr<PetrolEngine>& PetrolCar::getEngine(){
   return engine_;
} 