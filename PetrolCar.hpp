#pragma once
#include "PetrolEngine.hpp"
#include "Car.hpp"


class PetrolCar : virtual public Car
{
public:
    PetrolCar(PetrolEngine* engine);
    ~PetrolCar();

    void changeEngine(PetrolEngine* pe);
    void refill() override;


    void refuel();
    PetrolEngine* engine_;
};
