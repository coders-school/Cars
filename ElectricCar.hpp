#pragma once
#include "ElectricEngine.hpp"
#include "Car.hpp"

class ElectricCar : public Car
{
public:
    ElectricCar(ElectricEngine* engine);
    ~ElectricCar();
    void brake() override;
    void accelerate(int speed) override;
    void topUp() override;

private:
    void charge();

    ElectricEngine* engine_;
};

