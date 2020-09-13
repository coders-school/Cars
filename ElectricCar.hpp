#pragma once

#include "Car.hpp"
#include "ElectricEngine.hpp"

class ElectricCar : virtual public Car {
public:
    ElectricCar(ElectricEngine* engine);

    int getBatteryCapacity() const;
    int getElectricPower() const;

    // Override from Car
    ~ElectricCar() override;
    void restore() override;
    void changeEngine(Engine* engine) override;
    
protected:
    void charge();

    ElectricEngine* electricEngine_;
};