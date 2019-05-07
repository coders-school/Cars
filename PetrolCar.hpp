#pragma once
#include "PetrolEngine.hpp"
#include "Car.h"

class PetrolCar : virtual public Car
{
public:
    PetrolCar(PetrolEngine* engine);
    ~PetrolCar();
    void refuel();
    void setEngine(Engine* e);
    void feed();

private:
    PetrolEngine* engine_;
};

