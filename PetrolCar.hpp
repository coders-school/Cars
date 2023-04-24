#pragma once
#include "PetrolEngine.hpp"
#include "Car.hpp"
class PetrolCar : virtual public Car
{
public:
    PetrolCar(PetrolEngine *engine);
    ~PetrolCar() override;
    void refill() override;
    void shift(int);

private:
    void refuel();
    PetrolEngine *engine_;
};
