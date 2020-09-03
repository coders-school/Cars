#pragma once

#include "Car.hpp"
#include "ElectricEngine.hpp"

class ElectricCar : virtual public Car {
public:
    ElectricCar(ElectricEngine* engine);

    // Override from Car
    ~ElectricCar() override;
    void restore() override;
    void changeEngine(Engine* engine) override;

    int getBatteryCapacity() const;
    int getElectricPower() const;

protected:
    void charge();

    ElectricEngine* electricEngine_;
};
