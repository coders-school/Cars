#pragma once
#include "Car.hpp"
#include "Engine.hpp"
#include "PetrolEngine.hpp"

class PetrolCar : virtual public Car
{
public:
    PetrolCar(PetrolEngine *engine);
    ~PetrolCar();
    virtual void changeEngine(Engine *engine) override;
    void refill() override;

protected:
    void refuel();
    Engine *engine_;
};
