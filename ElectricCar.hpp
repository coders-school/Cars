#pragma once

#include "Car.hpp"
#include "ElectricEngine.hpp"
#include "Engine.hpp"

class ElectricCar : virtual public Car {
public:
    ElectricCar(ElectricEngine* engine);
    ~ElectricCar();
    void restore() override;
    void changeEngine(Engine* engine) override;

    ElectricEngine* engine_;

private:
    void charge();
};
