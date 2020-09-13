#pragma once
#include "Car.hpp"
#include "ElectricEngine.hpp"

class ElectricCar : virtual public Car {
public:
    ElectricCar(ElectricEngine* engine);
    ~ElectricCar();
    void restore() override;
    void changeEngine(Engine* engine) override;
    void setGear(int gear) override;

private:
    void charge();
    ElectricEngine* electricEngine_;
};
