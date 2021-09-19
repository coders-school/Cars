#pragma once

#include <memory>

#include "Car.hpp"
#include "../engine/ElectricEngine.hpp"

class ElectricCar : virtual public Car
{
public:
    ElectricCar(std::unique_ptr<ElectricEngine> engine);
    ~ElectricCar();
    
    void charge();
    void restore() override;

private:
    std::unique_ptr<ElectricEngine> engine_;
};

