#pragma once
#include "ElectricEngine.hpp"
#include "Car.hpp"

class ElectricCar : virtual public Car
{
public:
    ElectricCar(ElectricEngine *engine, int electricCondition=50);
    ElectricCar()= default;
    ~ElectricCar();

    int electricCondition;
    void addEnergy();
    void charge();

    ElectricEngine *engine_;
};
