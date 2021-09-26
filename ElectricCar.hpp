#pragma once
#include "Car.hpp"
#include "ElectricEngine.hpp"

class ElectricCar : virtual public Car {
public:
    ElectricCar(ElectricEngine* engine);
    ~ElectricCar();
    void reFill() override { charge(); };
    virtual void changeEngine(ElectricEngine* engine) override { engine_ = engine; };

protected:
    ElectricEngine* engine_;

private:
    void charge();
};
