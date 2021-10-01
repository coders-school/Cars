#pragma once
#include "ElectricEngine.hpp"
#include "Car.hpp"

class ElectricCar : virtual public Car
{
public:
    // ElectricCar(ElectricEngine* engine);
    ElectricCar(Engine* engine);
    ~ElectricCar();
    // void turnLeft();
    // void turnLeft();
    // void turnRight();
    // void brake();
    // void accelerate(int speed);
    void refill() override;
    
// 
private:
    void charge();
    // ElectricEngine* engine_;
    Engine* engine_;
};

