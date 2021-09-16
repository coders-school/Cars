#pragma once
#include <memory>
#include "Car.hpp"
#include "ElectricEngine.hpp"

class PetrolEngine;

class ElectricCar : virtual public Car {
public:
    ElectricCar(std::unique_ptr<ElectricEngine> engine);
    virtual ~ElectricCar();
    void refill() override;
    void changeEngine(std::unique_ptr<PetrolEngine>) override;
    void changeEngine(std::unique_ptr<ElectricEngine> engine) override;

private:
    void charge();
    std::unique_ptr<ElectricEngine> engine_;
};
