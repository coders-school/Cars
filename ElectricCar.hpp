#pragma once
#include "Car.hpp"
#include "ElectricEngine.hpp"
#include <memory>

class ElectricCar : public virtual Car
{
public:
    ElectricCar(std::unique_ptr<ElectricEngine> engine);
    ~ElectricCar();

    void changeEngine(std::unique_ptr<ElectricEngine> ee);
    void refill() override;

private:
    void charge();
    int energyLevel_ = 10;
    std::unique_ptr<ElectricEngine> engine_;
};
