#include "PetrolCar.hpp"
#include <iostream>
 
PetrolCar::PetrolCar(PetrolEngine* engine, int maxSpeed)
    : Car(maxSpeed)
    , engine_(engine)
{
    std::cout << __FUNCTION__ << std::endl;
}

PetrolCar::~PetrolCar()         
{ 
    std::cout << __FUNCTION__ << std::endl;
    delete engine_;
}
void PetrolCar::refuel()        { std::cout << __FUNCTION__ << std::endl; }
void PetrolCar::feed()          { refuel(); }

void PetrolCar::changeGear(int gear)
{
    if(gear == -1 && getVelocity() != 0)    
    {
        throw MyException();
    }
    else
    {
        engine_->changeGear(gear);
    }
}

int PetrolCar::getCurrentGear() const
{
    return engine_->getCurrentGear();
}    

