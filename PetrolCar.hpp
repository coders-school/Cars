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
	PetrolEngine* changeEngine(int, float, int);

protected:
    PetrolEngine *petrolEngine_;
    void refuel();
};
