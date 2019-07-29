#include "PetrolCar.hpp"
#include <iostream>
 
PetrolCar::PetrolCar(PetrolEngine* engine)
    : engine_(engine)
{
    std::cout << __FUNCTION__ << std::endl;
    this -> velocity = 0;
}

PetrolCar::~PetrolCar()
{ 
    std::cout << __FUNCTION__ << std::endl; 
    delete engine_;
   
}
void PetrolCar::refuel()        { std::cout << __FUNCTION__ << std::endl; }
void PetrolCar::feed()          { refuel();};
void PetrolCar::PetrolEngineChange(int power, float capacity, int gears)
{
    if (this->velocity == 0)
    {
        delete this->engine_ ;
        this->engine_ = new PetrolEngine(power, capacity, gears);
        std::cout<< "Engine was changed properly." << std::endl;
    }
    else std::cout<< "Changing an petrol engine during driving is not safe."<<std::endl;
}
int PetrolCar::getGear()const
{
    return this->engine_->getCurrentGear();
}
void PetrolCar::setGear(int gear)
{
    this->engine_->changeGear(gear);
}
