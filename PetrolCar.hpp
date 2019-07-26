#pragma once
#include "PetrolEngine.hpp"
#include "Car.hpp"

class PetrolCar : virtual public Car
{
public:
    PetrolCar(PetrolEngine *engine);
    PetrolCar() = default;
    ~PetrolCar();
    void addEnergy() override;
    PetrolEngine *changeEngine(int, float, int);
    int getGear();
    void setGear(int value);

protected:
    PetrolEngine *petrolEngine_;
    void refuel();
};
