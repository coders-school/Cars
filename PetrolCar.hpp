#pragma once
#include "Car.hpp"
#include "PetrolEngine.hpp"
class PetrolCar : virtual public Car
{
public:
    PetrolCar(PetrolEngine* engine);
    ~PetrolCar();

    void changeEngine(PetrolEngine* pe);
    void refill() override;
private:
    void refuel();
    PetrolEngine* engine_;
};

