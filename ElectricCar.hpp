#pragma once

#include "Car.hpp"
#include "ElectricEngine.hpp"

#include <memory>

class ElectricCar : virtual public Car {
public:
    ElectricCar(std::unique_ptr<ElectricEngine> engine);
    ~ElectricCar();

    void restore() override;

private:
    std::unique_ptr<ElectricEngine> engine_;
    void charge();
};
