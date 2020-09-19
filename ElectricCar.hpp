#pragma once

#include <memory>

#include "Car.hpp"
#include "ElectricEngine.hpp"
#include "Engine.hpp"

class ElectricCar : virtual public Car {
public:
    ElectricCar(std::unique_ptr<ElectricEngine> engine);
    ~ElectricCar();
    void restore() override;
    void changeEngine(std::unique_ptr<ElectricEngine> engine);
    int getPower();
    int getBatteryCapacity();

protected:
    void charge();
    std::unique_ptr<ElectricEngine> engine_;
};
