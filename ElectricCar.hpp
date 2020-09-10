#pragma once

#include "Car.hpp"
#include "ElectricEngine.hpp"

class ElectricCar : virtual public Car {
public:
    ElectricCar(ElectricEngine* engine);
    ~ElectricCar();
    void refill() override;
    void changeEngine(Engine* electricEngine) override;
    int getEnginePower() override;

        protected : void charge();
    ElectricEngine* electricEngine_;
};
