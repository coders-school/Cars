#pragma once
#include <memory>
#include "Car.hpp"
#include "ElectricEngine.hpp"

class ElectricCar : virtual public Car {
public:
    ElectricCar(std::unique_ptr<ElectricEngine> engine);
    ~ElectricCar();
    void restore() override;
    void changeGear(GearBox gear) override;
    std::unique_ptr<ElectricEngine> changeEngine(std::unique_ptr<ElectricEngine> newEngine);

private:
    void charge();
    std::unique_ptr<ElectricEngine> electricEngine_;
};
