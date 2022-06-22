#pragma once
#include "PetrolEngine.hpp"
#include "Car.hpp"

class PetrolCar : virtual public Car
{
public:
    PetrolCar(PetrolEngine* engine);
    ~PetrolCar();

    void changeEngine(PetrolEngine* engine);
    void refill() override; 
private:
    void refuel();
    PetrolEngine* engine_;
};

