#pragma once
#include "Car.hpp"
#include "PetrolEngine.hpp"

class PetrolCar : virtual public Car
{
public:
    PetrolCar(PetrolEngine* engine);
    ~PetrolCar();
    // void turnLeft();
    // void turnRight();
    // void brake();
    // void accelerate(int speed);
    void refill() override;
    void changeGear(const int& gear);
    void changeEngine(PetrolEngine* engine);

private:
    void refuel();
    PetrolEngine* engine_;
};
