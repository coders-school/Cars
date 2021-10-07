#pragma once
#include "Car.hpp"
#include "ElectricEngine.hpp"

class ElectricCar : public Car {
public:
    ElectricCar(std::unique_ptr<ElectricEngine> engine);
    virtual ~ElectricCar();

    void powerSuply() override;
    void changeEngine(int, float, int = 0, int = 0, int = 0) override;

    const std::unique_ptr<ElectricEngine>& getElectricEngine();

private:
    std::unique_ptr<ElectricEngine> electricEngine_;
    void charge();
};