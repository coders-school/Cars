#include "PetrolCar.hpp"
#include <iostream>
 
PetrolCar::PetrolCar(std::unique_ptr<PetrolEngine> engine)
    : engine_(std::move(engine))
{
    std::cout << __FUNCTION__ << ": " <<  __FILE__  << ": " <<  __LINE__  << std::endl;
}

PetrolCar::~PetrolCar()          { std::cout << __FUNCTION__ << ": " <<  __FILE__  << ": " <<  __LINE__  << std::endl; }
void PetrolCar::turnLeft() const      { std::cout << __FUNCTION__ << ": " <<  __FILE__  << ": " <<  __LINE__  << std::endl; }
void PetrolCar::turnRight() const    { std::cout << __FUNCTION__ << ": " <<  __FILE__  << ": " <<  __LINE__  << std::endl; }
void PetrolCar::brake()     const   { std::cout << __FUNCTION__ << ": " <<  __FILE__  << ": " <<  __LINE__  << std::endl; }
void PetrolCar::accelerate(Speed speed) const { std::cout << __FUNCTION__ << ": " <<  __FILE__  << ": " <<  __LINE__  << std::endl; }
void PetrolCar::refuel()        { std::cout << __FUNCTION__ << ": " <<  __FILE__  << ": " <<  __LINE__  << std::endl; }

