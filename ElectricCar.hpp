#pragma once

#include "Car.hpp"
#include "ElectricEngine.hpp"

class ElectricCar : virtual public Car {
public:
    ElectricCar(ElectricEngine* engine);
    ~ElectricCar() override;
    void restore() override;
    void changeEngine(int power, int batteryCapacity);

private:
    ElectricEngine* engine_;
    void charge();
};
