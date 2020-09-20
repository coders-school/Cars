#pragma once

#include "ElectricEngine.hpp"
#include "Car.hpp"

class ElectricCar : public virtual Car
{
public:
    ElectricCar(ElectricEngine* engine);
    virtual ~ElectricCar();
    void charge();
    void changeElectricEngine(ElectricEngine* engine);
    
protected:
    ElectricEngine* engine_;
};

