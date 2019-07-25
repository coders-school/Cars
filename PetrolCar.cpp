#include "PetrolCar.hpp"
#include <iostream>
 
PetrolCar::PetrolCar(PetrolEngine* engine)
    : engine_(engine)
{
    std::cout << __FUNCTION__ << std::endl;
}

PetrolCar::~PetrolCar()        
{
    delete this;
    std::cout << __FUNCTION__ << std::endl; 
}
void PetrolCar::refuel()        { std::cout << __FUNCTION__ << std::endl; }
void PetrolCar::feed()          { refuel(); }
