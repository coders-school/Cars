#pragma once

#include "Car.hpp"
#include "../engine/PetrolEngine.hpp"

class PetrolCar : virtual public Car
{
public:
    PetrolCar(PetrolEngine* engine);
    ~PetrolCar();

    void refuel();
    void restore() override;

private:
    PetrolEngine* engine_;
};
