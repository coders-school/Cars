#include "PetrolCar.hpp"
#include "PetrolEngine.hpp"
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
void PetrolCar::feed()          { refuel(); }
void PetrolCar::setPetrolEngine(int power, float capacity, int gears)
{
    if  (this->velocity !=0)
         std::cout<<"Engine change imppossible, stop the car!"<<std::endl;
    else {
       delete this->engine_;
       this->engine_=new PetrolEngine(power, capacity,gears);
    std::cout<<"New engine!"<<std::endl;
        }
}

void PetrolCar::showGear(){std::cout << "Your gear is: " << this->engine_->returnGear() << std::endl;}
void PetrolCar::setGear(int g){this->engine_->changeGear(g);}
