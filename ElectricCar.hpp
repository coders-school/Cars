#pragma once
#include "ElectricEngine.hpp"
#include "Vehicle.hpp"

class ElectricCar : virtual public Vehicle
{
public:
    ElectricCar(ElectricEngine* engine);
    ~ElectricCar();
    void turnLeft() override;
    void turnRight() override;
    void brake() override;
    void accelerate(int speed) override;
    void charge();

};

