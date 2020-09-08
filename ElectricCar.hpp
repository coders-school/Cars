#pragma once

#include "Car.hpp"
#include "ElectricEngine.hpp"

class ElectricCar : virtual public Car
{
public:
    ElectricCar(ElectricEngine* engine);
    ~ElectricCar();
    void restore();
    void setEngine(int power, int batteryCapacity);
    int getEnginePower();
private:
    void charge();
    ElectricEngine* engine_;
};

