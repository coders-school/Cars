#pragma once
#include "ElectricEngine.hpp"
#include "Car.hpp"

class ElectricCar : public virtual Car
{
protected:
    void charge();
public:
    ElectricCar(ElectricEngine* engine);
    ~ElectricCar();
    void feed() override;
private:
    ElectricEngine* engine_;
    
};

