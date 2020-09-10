#pragma once

#include "PetrolEngine.hpp"
#include "Vehicle.hpp"
class PetrolCar : virtual public Vehicle
{
public:
    PetrolCar(PetrolEngine* engine);
    ~PetrolCar();
    void turnLeft() override;
    void turnRight() override;
    void brake() override;
    void accelerate(int speed) override;
    void refuel();

};

