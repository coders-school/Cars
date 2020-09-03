#pragma once
#include "PetrolEngine.hpp"
#include "Car.hpp"
class PetrolCar : virtual public Car
{
public:
    PetrolCar(PetrolEngine *engine);
    ~PetrolCar();
    void refuel();
    void restore() override;

private:
    PetrolEngine *petrolEngine_;
};
