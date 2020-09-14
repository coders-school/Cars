#pragma once
#include "Car.hpp"
#include "ElectricEngine.hpp"

class ElectricCar : virtual public Car {
public:
    ElectricCar(ElectricEngine* engine);
    ~ElectricCar();
    void restore() override;
    void changeEngine(Engine* electricEngine) override;
    void setGear(int gear) override;
    int getElectricEnginePower() const;
    int getElectricEngineBatteryCapacity() const;

private:
    void charge();
    ElectricEngine* electricEngine_;
};
