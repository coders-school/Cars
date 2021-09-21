#pragma once
#include "PetrolEngine.hpp"
#include "Car.hpp"
class PetrolCar : public Car
{
public:
    PetrolCar(PetrolEngine* petrolEngine);
    ~PetrolCar();
    void accelerate(int speed);
    void refuel();

private:
    PetrolEngine* petrolEngine_;
};

