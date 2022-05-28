#pragma once
#include <iostream>
#include <memory>
#include "Car.hpp"
#include "ElectricEngine.hpp"

class ElectricCar : public virtual Car
{
public:
    ElectricCar(std::shared_ptr<ElectricEngine> engine);
    ~ElectricCar();

    void changeEngine(std::shared_ptr<ElectricEngine> ee);
    void refill() override;

private:
    void charge();
    std::shared_ptr<ElectricEngine> engine_;
};
