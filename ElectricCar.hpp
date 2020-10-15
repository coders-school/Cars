#pragma once

#include "Car.hpp"
#include "ElectricEngine.hpp"

class ElectricCar : virtual public Car {
public:
    ElectricCar(std::shared_ptr<ElectricEngine> engine);
    ~ElectricCar();
    void restore() override;
    void changeEngine(std::shared_ptr<ElectricEngine>);
    int getPower() const;
    int getBatteryCapacity() const;

private:
    std::shared_ptr<ElectricEngine> engine_;
    void charge();
};
