#pragma once
#include <memory>
#include "Car.hpp"
#include "PetrolEngine.hpp"

class ElectricEngine;

class PetrolCar : virtual public Car {
public:
    PetrolCar(std::unique_ptr<PetrolEngine> engine);
    virtual ~PetrolCar();
    void refill() override;
    void changeEngine(std::unique_ptr<PetrolEngine> engine) override;
    void changeEngine(std::unique_ptr<ElectricEngine>) override;

private:
    void refuel();
    std::unique_ptr<PetrolEngine> engine_;
};
