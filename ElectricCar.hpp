#pragma once
#include "Car.hpp"
#include "ElectricEngine.hpp"

class ElectricCar : virtual public Car
{
public:
    ElectricCar(ElectricEngine* engine);
    ~ElectricCar();
    // void turnLeft();
    // void turnLeft();
    // void turnRight();
    // void brake();
    // void accelerate(int speed);
    void refill() override;

    void changeEngine(ElectricEngine* engine);
    
// 
private:
    void charge();
    ElectricEngine* engine_;
};
