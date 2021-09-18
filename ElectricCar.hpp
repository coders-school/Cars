#pragma once
#include <memory>
#include "Car.hpp"
#include "ElectricEngine.hpp"

class ElectricCar : virtual public Car {
private:
    std::shared_ptr<ElectricEngine> engine_;
public:
    ElectricCar(std::shared_ptr<ElectricEngine> engine);
    ~ElectricCar();
    void charge();
};
