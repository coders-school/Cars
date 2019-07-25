#pragma once
#include "ElectricEngine.hpp"
#include "Car.hpp"

class ElectricCar : virtual public Car
{
protected:
     void charge();
public:
    ElectricCar(ElectricEngine *engine);
    ElectricCar()= default;
    ~ElectricCar();

    
    void accelerate(int moreSpeed);
    void brake();
    void addEnergy() override;
   

    ElectricEngine *engine_;
};
