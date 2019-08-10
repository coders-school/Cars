#pragma once
#include "PetrolEngine.hpp"
#include "Car.hpp"
class PetrolCar : public virtual Car
{
protected:
    void refuel();
    PetrolEngine* engine_;
public:
    PetrolCar(PetrolEngine* engine);
    ~PetrolCar();
    void feed() override;
    void changeEngine(int power, float capacity, int gears) ;
};

