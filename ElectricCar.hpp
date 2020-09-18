#pragma once

#include <memory>

#include "Car.hpp"
#include "ElectricEngine.hpp"

#include "Exceptions.hpp"

class ElectricCar : virtual public Car {
public:
    ElectricCar(std::unique_ptr<ElectricEngine> engine);
    ~ElectricCar();

    void restore() override;
    void changeEngine(std::unique_ptr<ElectricEngine> engine);

protected:
    std::unique_ptr<ElectricEngine> engine_;
    void charge();
};
