#pragma once
#include "Car.hpp"
#include "Chargeable.hpp"
#include <memory>

class ElectricEngine;
class ElectricCar : virtual public Car, public Chargeable {
public:
    ElectricCar(std::unique_ptr<ElectricEngine> engine);
    ~ElectricCar() override;

    void charge() override;

    void engineSwap(std::unique_ptr<ElectricEngine>& engine) {
        engine_.swap(engine);
    }

protected:
    std::unique_ptr<ElectricEngine> engine_;
};