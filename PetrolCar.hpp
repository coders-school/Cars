#pragma once

#include "PetrolEngine.hpp"
#include "Car.hpp"

class PetrolCar : virtual public Car
{
public:
    PetrolCar(PetrolEngine* engine);
    ~PetrolCar();
    
    void restore() override;

    PetrolEngine* engine_;

private:
    void refuel();
};

