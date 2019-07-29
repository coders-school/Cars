#include "PetrolCar.hpp"
#include "Exceptions.hpp"

#include <iostream>
 
PetrolCar::PetrolCar(PetrolEngine* engine)
    : engine_(engine)
{
    std::cout << __FUNCTION__ << std::endl;
}

PetrolCar::~PetrolCar() { 
    delete engine_; 
    std::cout << __FUNCTION__ << std::endl;
}

void PetrolCar::fill()
{ 
    std::cout << "from PetrolCar: " << __FUNCTION__ << std::endl; 
}


PetrolEngine PetrolCar::GetPetrolEngine() const
{ 
    return *engine_;
}

void PetrolCar::ChangePetrolEngine(PetrolEngine* engine)
{
    if(getCurrentVelocity() > 0) {
        new SpeedIsNotZero();
    }
    delete engine_;
    engine_ = engine;
}
