#pragma once
#include <memory>
#include "Car.hpp"
#include "ElectricEngine.hpp"

class ElectricCar : virtual public Car {
private:
    std::shared_ptr<ElectricEngine> engine_;
    void charge();
public:
    ElectricCar(std::shared_ptr<ElectricEngine> engine);
    ~ElectricCar();

    void changeEngine(std::shared_ptr<ElectricEngine> newEngine);
    void refill() override;
    
};
