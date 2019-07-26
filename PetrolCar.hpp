#pragma once
#include "PetrolEngine.hpp"
#include "Car.hpp"

class PetrolCar : public virtual Car
{
protected:
    void refuel();
public:
    explicit PetrolCar(Engine* engine);
    ~PetrolCar();

    void feed() override;
    void changeEngine(Engine* engine) override;
};

