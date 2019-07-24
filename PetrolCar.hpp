#pragma once
#include "PetrolEngine.hpp"
#include "Car.hpp"

class PetrolCar : virtual public Car
{
public:
    PetrolCar(PetrolEngine *engine);
    PetrolCar()= default;
    ~PetrolCar();
    void addEnergy();
    void refuel();

    int petrolCondition;
    PetrolEngine *engine_;
};
