#pragma once
#include <memory>
#include "Car.hpp"
#include "ElectricEngine.hpp"

class ElectricCar : public virtual Car {
public:
    ElectricCar(std::unique_ptr<ElectricEngine> electricEngine);
    ~ElectricCar();
    void changeEngine(std::unique_ptr<ElectricEngine> electricEngine);
    void refill() override;

private:
    void charge();
    std::unique_ptr<ElectricEngine> electricEngine_;
};
