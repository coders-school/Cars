#pragma once

#include <memory>
#include "ICar.hpp"
#include "ElectricEngine.hpp"

class ElectricCar : public ICar
{
public:
    ElectricCar(std::unique_ptr<ElectricEngine> engine);
    ~ElectricCar();
    void turnLeft() const override;
    void turnRight() const override;
    void brake() const override;
    void accelerate(Speed speed) const override;
    void charge();

private:
    std::unique_ptr<ElectricEngine> engine_ = nullptr;
};


