#pragma once

#include "Car.hpp"
#include "ElectricEngine.hpp"

class ElectricCar : public Car
{
public:
    ElectricCar(ElectricEngine* engine);
    ~ElectricCar();
    void charge();

    ElectricEngine* engine_;
};

