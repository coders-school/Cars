#pragma once
#include "ElectricEngine.hpp"
#include "Car.hpp"

class ElectricCar : public virtual Car
{
protected:
    ElectricEngine* engine_;
    void charge();
public:
    ElectricCar(ElectricEngine* engine);
    ~ElectricCar();
    void feed();
    void setElectricEngine(int, int);
};

