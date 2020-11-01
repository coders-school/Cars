#pragma once
#include "Car.hpp"
#include "ElectricEngine.hpp"
#include <memory>

class ElectricCar : virtual public Car
{
public:
    ElectricCar(std::unique_ptr<ElectricEngine> engine);
    ~ElectricCar();
    void restore() override;
    void changeElectricEngine(std::unique_ptr<ElectricEngine> newEngine);

protected:
    void charge();
    std::unique_ptr<ElectricEngine> electricEngine_;
};
