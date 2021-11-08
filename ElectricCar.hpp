#pragma once
#include "ElectricEngine.hpp"
#include "Car.hpp"

class ElectricCar : virtual public Car
{
public:
    ElectricCar(ElectricEngine* engine);
    ~ElectricCar();
    void changeEngine(ElectricEngine* engine);
    void refill() override;
private:
    void charge();
    ElectricEngine* engine_;
};

