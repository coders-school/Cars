#include "PetrolCar.hpp"
#include <iostream>
 
PetrolCar::PetrolCar(PetrolEngine* engine)
    : engine_(engine)
{
    std::cout << __FUNCTION__ << std::endl;
}

PetrolCar::~PetrolCar()
{
    delete engine_;
    std::cout << __FUNCTION__ << std::endl;
}
void PetrolCar::refuel()
{
if(Car::velocity == 0)
    std::cout << __FUNCTION__ << std::endl;
else
    std::cout << "You can't refuel Your car while driving!" << std::endl;
}
void PetrolCar::changePetrolEngine(PetrolEngine* engine)
{
    if(velocity!=0)
        std::cout<<"You can't change engine while driving!"<<std::endl;
    else
        engine_ = engine;
}
void PetrolCar::feed()          { refuel(); }
