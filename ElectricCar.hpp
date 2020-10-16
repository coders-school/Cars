#pragma once
#include <iostream>
#include <memory>
#include "Car.hpp"
#include "ElectricEngine.hpp"

class ElectricCar : virtual public Car {
public:
    ElectricCar(std::unique_ptr<ElectricEngine> engine);
    ~ElectricCar();
    virtual void restore() override;
    void charge();
    void changeEngine(std::unique_ptr<ElectricEngine> engine);
    void printInfoEngine() const override;

private:
    std::unique_ptr<ElectricEngine> engine_;
};