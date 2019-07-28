#include "PetrolCar.hpp"
#include <iostream>
 
PetrolCar::PetrolCar(PetrolEngine* engine)
    : engine_(engine)
{
    std::cout << __FUNCTION__ << std::endl;
}

PetrolCar::~PetrolCar()
{
    std::cout << __FUNCTION__ << std::endl;
    delete engine_; 
}
void PetrolCar::refuel()        { std::cout << __FUNCTION__ << std::endl; }

void PetrolCar::feed()          
{
    refuel();
    std::cout << "Thanks bro! All my " << engine_->getEnginePower() << " horses are happy now!"<<std::endl;
}

void PetrolCar::changePetrolEngine(PetrolEngine* newEngine)
{
    if(getVelocity()!=0)
    {
        std::cout << "You can't replace your engine on the run!\n";
    }
    else
    {
        delete engine_;
        engine_ = newEngine;
        std::cout << "You've changed your PetrolEngine!\n";
    }
}

int PetrolCar::getGear() const
{
    return engine_->getCurrentGear();
}

void PetrolCar::setGear(int value)
{
   engine_->changeGear(value); 
}