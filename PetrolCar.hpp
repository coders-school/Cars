#pragma once
#include "PetrolEngine.hpp"
#include "Car.hpp"

class PetrolCar : virtual public Car
{
protected:
    void refuel();
    PetrolEngine* engine_;
public:
    PetrolCar(PetrolEngine* engine);
    ~PetrolCar();
    void feed() override;

    void setPetrolEngine(int, float ,int);
    void showGear();
    void setGear(int);

};

