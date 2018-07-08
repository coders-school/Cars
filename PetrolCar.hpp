#pragma once
#include "PetrolEngine.hpp"
#include  "Car.hpp"

class PetrolCar : public Car
{
public:
    PetrolCar(PetrolEngine* engine) 
        : engine_(engine)
    {}
    ~PetrolCar() {}
    void refill()
    {
        refuel();
    }
private:
    void refuel() {}
    PetrolEngine* engine_;
};

