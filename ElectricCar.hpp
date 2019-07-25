#pragma once
#include "ElectricEngine.hpp"
#include "Car.hpp"

class ElectricCar : virtual public Car
{
protected:
    void charge();
    ElectricEngine* engine_;


public:
    ElectricCar(ElectricEngine* engine);
    ~ElectricCar();
    void feed() override;
    void ElectricEngineChange(int, int);
};



