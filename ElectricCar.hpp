#pragma once
#include "ElectricEngine.hpp"
#include "Car.h"

class ElectricCar : virtual public Car
{
public:
    ElectricCar(ElectricEngine* engine);
    ~ElectricCar();
    void charge();
    void feed();
    void setEngine(Engine* e);

private:
    ElectricEngine* engine_;
};

