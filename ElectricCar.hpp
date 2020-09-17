#pragma once

#include "ElectricEngine.hpp"
#include "Car.hpp"

#include <memory>

class ElectricCar : virtual public Car
{
public:
    ElectricCar(std::unique_ptr<ElectricEngine> engine_);
    ~ElectricCar();
    void restore() override;
    void changeEngine(std::unique_ptr<ElectricEngine> engine);

    std::unique_ptr<ElectricEngine> engine_;
private:
    void charge();
};

