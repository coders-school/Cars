#pragma once

#include <memory>

#include "Car.hpp"
#include "ElectricEngine.hpp"

#include "Exceptions.hpp"

class ElectricCar : virtual public Car {
public:
    ElectricCar(std::unique_ptr<ElectricEngine> engine);
    ~ElectricCar();

    void restore() override;
    void changeEngine(std::unique_ptr<ElectricEngine> engine);
    int getPower() { return engine_->getPower(); }
    int getBatteryCapacity() { return engine_->getBatteryCapacity(); }

protected:
    std::unique_ptr<ElectricEngine> engine_;
    void charge();
};
