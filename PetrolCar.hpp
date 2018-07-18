#pragma once
#include "PetrolEngine.hpp"
#include "Car.hpp"

class PetrolCar : public Car
{
public:
    PetrolCar(PetrolEngine* engine);
    ~PetrolCar();
    void brake() override;
    void accelerate(int speed) override;
    void topUp() override;

private:
    void refuel();

    PetrolEngine* engine_;
};

