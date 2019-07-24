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

void PetrolCar::refuel()        { std::cout << __FUNCTION__ << std::endl; }

PetrolEngine * PetrolCar::changeEngine(int power,float capacity,int gears)
{
    if (velocity!=0)
    {
        std::cout<< "Imposible"<<std::endl;
        return this->engine_;
    }
    else
    {
        std::cout << __FUNCTION__ << std::endl;
	delete engine_;
        this->engine_ = new PetrolEngine(power,capacity,gears);
        std::cout <<" Power: "   <<this->engine_->power_
                  <<" Capacity: "<<this->engine_->capacity_
                  <<" Gears: "   <<this->engine_->gears_ <<std::endl;
        return this->engine_;
    }



}
