#pragma once

#include <memory>

#include "Car.hpp"
#include "ElectricEngine.hpp"

class ElectricCar : virtual public Car {
private:
    std::unique_ptr<Engine> engine_{};
    void charge();
public:
    ElectricCar(std::unique_ptr<Engine> engine);
    ~ElectricCar();
    void restore() override;

};
