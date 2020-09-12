#pragma once
#include "Car.hpp"
#include "ElectricEngine.hpp"

class ElectricCar : virtual public Car {
public:
    ElectricCar(ElectricEngine* engine);
    ~ElectricCar();
    void restore() override;

private:
    void charge();
    ElectricEngine* engine_;
};
