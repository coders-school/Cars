#pragma once

#include <memory>
#include "ICar.hpp"
#include "ElectricEngine.hpp"

class ElectricCar : public ICar
{
public:
    ElectricCar(std::unique_ptr<IEngine> engine);
    ~ElectricCar();
    void turnLeft() const override;
    void turnRight() const override;
    void brake() const override;
    void accelerate(Speed speed) const override;
    void charge();
    void start_engine() const override;
    void stop_engine() const override;
    void fill() const override;


private:
    std::unique_ptr<IEngine> engine_ = nullptr;
};


