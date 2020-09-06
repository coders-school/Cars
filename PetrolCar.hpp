#pragma once

#include "Car.hpp"
#include "PetrolEngine.hpp"

class PetrolCar : public Car
{
public:
    PetrolCar(PetrolEngine* engine);
    ~PetrolCar();
    void refuel();

    PetrolEngine* engine_;
};

