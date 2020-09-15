#pragma once

#include "Car.hpp"
#include "ElectricEngine.hpp"

class ElectricCar : virtual public Car {
public:
    ElectricCar(ElectricEngine* electricEngine);
    uint16_t getBatteryCapacity() const;

    // Override from Car
    ~ElectricCar() override;
    uint16_t getEnginePower() const override;
    void restore() override;
    void changeEngine(Engine* engine) override;
    void carInfo() override;

protected:
    void charge();
    ElectricEngine* electricEngine_;
};
