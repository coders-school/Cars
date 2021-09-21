#pragma once
#include "ElectricEngine.hpp"
#include "Car.hpp"
class ElectricCar : public virtual Car
{
public:
    ElectricCar(ElectricEngine* engine);
    ~ElectricCar();
 
    void changeEngine(ElectricEngine* ee) override;
    void refill() override;
private:
    void charge();
    ElectricEngine* engine_;
};

