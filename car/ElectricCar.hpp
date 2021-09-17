#pragma once

#include "Car.hpp"
#include "../engine/ElectricEngine.hpp"

class ElectricCar : virtual public Car
{
public:
    ElectricCar(ElectricEngine* engine);
    ~ElectricCar();
    
    void charge();
    void restore() override;

private:
    ElectricEngine* engine_;
};

