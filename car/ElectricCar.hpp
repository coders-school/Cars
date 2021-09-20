#pragma once

#include <memory>

#include "car/Car.hpp"
#include "engine/ElectricEngine.hpp"

class ElectricCar : virtual public Car
{
public:
    ElectricCar(std::unique_ptr<ElectricEngine> engine);
    ~ElectricCar();
    
    void charge();
    void restore() override;
    void changeEngine(std::unique_ptr<ElectricEngine>  engine);

private:
    std::unique_ptr<ElectricEngine> engine_;
};

