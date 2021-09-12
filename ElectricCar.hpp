#pragma once
#include "Car.hpp"
#include "ElectricEngine.hpp"

class ElectricCar : virtual public Car {
public:
    ElectricCar(ElectricEngine* engine);
    virtual ~ElectricCar();
    void refill() override;

private:
    void charge();
    ElectricEngine* engine_;
};
