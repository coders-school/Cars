#pragma once
#include "Car.hpp"
#include "Engine.hpp"
#include "PetrolEngine.hpp"

class PetrolCar : virtual public Car
{
public:
    PetrolCar(PetrolEngine* engine);
    // PetrolCar(Engine* engine);
    ~PetrolCar();
    // void turnLeft();
    // void turnRight();
    // void brake();
    // void accelerate(int speed);
    void refill() override;
    void changeGear(const int& gear);
    // void changeEngine(Engine* engine) override;

private:
    void refuel();
    PetrolEngine* engine_;
    // Engine* engine_;
};
