#pragma once
#include "Car.hpp"
#include "Engine.hpp"
#include "ElectricEngine.hpp"

class ElectricCar : virtual public Car
{
public:
    ElectricCar(Engine* engine);
    // ElectricCar(ElectricEngine* engine);
    ~ElectricCar();
    // void turnLeft();
    // void turnLeft();
    // void turnRight();
    // void brake();
    // void accelerate(int speed);
    void refill() override;

    // void changeEngine(Engine* engine) override;
    
// 
private:
    void charge();
    // ElectricEngine* engine_;
    Engine* engine_;
};
