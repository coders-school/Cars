#pragma once

#include "Car.hpp"
#include "ElectricEngine.hpp"

class ElectricCar : virtual public Car {
public:
    ElectricCar(ElectricEngine* engine);
    ~ElectricCar();

    //override from Car
    void restore() override;
    void changeEngine(Engine* engine) override;
    int getEnginePower() const override { return electricEngine_->getPower(); }

protected:
    ElectricEngine* electricEngine_;

private:
    void charge();
};
