#pragma once
#include "Car.hpp"
#include "ElectricEngine.hpp"

class ElectricCar : public Car {
public:
    ElectricCar(std::unique_ptr<ElectricEngine> engine);
    virtual ~ElectricCar();

    void turnLeft() override;
    void turnRight() override;
    void brake() override;
    void accelerate(int) override;
    void charge();

    const std::unique_ptr<ElectricEngine>& getElectricEngine();

private:
    std::unique_ptr<ElectricEngine> electricEngine_;
};
