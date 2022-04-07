#pragma once
#include <memory>
#include "Car.hpp"
#include "Engine.hpp"
#include "PetrolEngine.hpp"

class PetrolCar : virtual public Car
{
public:
    PetrolCar(std::unique_ptr<Engine> engine);
    ~PetrolCar();
    virtual void changeEngine(std::unique_ptr<Engine> engine) override;
    void refill() override;

protected:
    void refuel();
    std::unique_ptr<Engine> engine_;
};
