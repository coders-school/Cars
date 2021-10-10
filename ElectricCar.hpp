#pragma once
#include "Car.hpp"
#include "ElectricEngine.hpp"

class ElectricCar : virtual public Car {
public:
    ElectricCar(ElectricEngine* engine);
    ~ElectricCar();
    void reFill() override { charge(); };
    void changeEngine(ElectricEngine* engine) override { engine_ = engine; };
    ElectricEngine* getEngine() const {return engine_;};

protected:
    ElectricEngine* engine_;

private:
    void charge();
};
