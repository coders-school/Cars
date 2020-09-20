#pragma once

#include "Car.hpp"
#include "PetrolEngine.hpp"

class PetrolCar : public virtual Car {
public:
    PetrolCar(PetrolEngine* engine);
    virtual ~PetrolCar();
    void refuel();
    void changePetrolEngine(PetrolEngine* engine);
    
protected:
    PetrolEngine* engine_;
};
