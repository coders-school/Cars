#include "PetrolEngine.hpp"
#include"Car.hpp"
#pragma once


class PetrolCar : virtual public Car
{
public:
    PetrolCar(PetrolEngine* engine);
    ~PetrolCar();
    void refuel();

    PetrolEngine* engine_;
};

