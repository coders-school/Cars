#pragma once
#include "PetrolEngine.hpp"
#include "Car.hpp"

class PetrolCar : virtual public Car
{
protected:
    void refuel();
public:
    PetrolCar(PetrolEngine* engine);
    ~PetrolCar();
    void feed() override;

    PetrolEngine* engine_;
    void set_petrol_engine(int, float ,int);
};

