#pragma once

#include "Car.hpp"
#include "ElectricEngine.hpp"

class ElectricCar : virtual public Car
{
public:
    ElectricCar(ElectricEngine* engine);
    ~ElectricCar();
    void charge();
    void setEngine(int power, int batteryCapacity);
private:
    ElectricEngine* engine_;
};

