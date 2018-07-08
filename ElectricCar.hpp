#pragma once
#include "ElectricEngine.hpp"
#include "Car.hpp"

class ElectricCar : public Car
{
public:
    ElectricCar(ElectricEngine* engine)
        : engine_(engine)
    {}
    ~ElectricCar() {}
    void refill()
    {
        charge();
    }
private:
    void charge() {}
    ElectricEngine* engine_;
};

