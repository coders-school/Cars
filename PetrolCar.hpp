#include "PetrolEngine.hpp"
#include"Car.hpp"
#pragma once


class PetrolCar : virtual public Car
{
public:
    PetrolCar(PetrolEngine* engine);
    virtual ~PetrolCar();

    void refuel();

    PetrolEngine * changeEngine (int ,float ,int );
protected:
    PetrolEngine* engine_;
};

