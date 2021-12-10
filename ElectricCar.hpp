#pragma once

#include <memory>

#include "Car.hpp"
#include "ElectricEngine.hpp"

class ElectricCar : virtual public Car {
public:
    ElectricCar(std::unique_ptr<ElectricEngine> engine);
    ~ElectricCar();
    void refill() override;

protected:
    void charge();
    std::unique_ptr<ElectricEngine> engine_;
};
