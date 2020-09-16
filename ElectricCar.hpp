#pragma once
#include <memory>
#include "Car.hpp"
#include "ElectricEngine.hpp"

class ElectricCar : virtual public Car {
public:
    ElectricCar(std::unique_ptr<ElectricEngine> engine);
    ~ElectricCar();
    void restore() override;

private:
    void charge();

    std::unique_ptr<ElectricEngine> electricEngine_;
};
