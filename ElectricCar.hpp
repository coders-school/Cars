#include "ElectricEngine.hpp"
#include "Car.hpp"
#pragma once

class ElectricCar : virtual public Car
{
public:
    ElectricCar(ElectricEngine* engine);
    ~ElectricCar();
    void charge();
    ElectricEngine* changeElectricEngine (int, int);
protected:
    ElectricEngine* engine_;
};

