#include "PetrolCar.hpp"
#include <iostream>
 
PetrolCar::PetrolCar(PetrolEngine* engine)
    : engine_(engine)
{
    std::cout << __FUNCTION__ << std::endl;
}

PetrolCar::~PetrolCar()         { delete engine_; std::cout << __FUNCTION__ << std::endl; }
void PetrolCar::refuel()        { std::cout << __FUNCTION__ << std::endl; }
void PetrolCar::feed()          { refuel(); }
void PetrolCar::changeEngine(int power, float capacity, int gears) 
{
    if(!velocity)
    {    engine_ = new PetrolEngine(power, capacity, gears);
        std::cout << "Engine has been changed." << std::endl;
    }

    if(velocity)
        std::cout << "Change engine is impossible." << std::endl;
}



