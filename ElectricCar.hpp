#include "ElectricEngine.hpp"
#include "Car.hpp"
#pragma once

class ElectricCar : virtual public Car
{
public:
    ElectricCar(ElectricEngine* engine);
    virtual ~ElectricCar();

    void charge();
    ElectricEngine* changeEngine (int, int);
protected:
    ElectricEngine* engine_;
};

