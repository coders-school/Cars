#pragma once

#include "Car.hpp"
#include "ElectricEngine.hpp"

class ElectricCar : virtual public Car {
private:
    ElectricEngine* engine_;
    void charge();
public:
    ElectricCar(ElectricEngine* engine);
    ~ElectricCar();
    void restore() override;

};
