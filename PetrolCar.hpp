#pragma once

#include "Car.hpp"
#include "Engine.hpp"
#include "PetrolEngine.hpp"

class PetrolCar : virtual public Car {
public:
    PetrolCar(PetrolEngine* engine);
    ~PetrolCar();
    void restore() override;
    void changeEngine(Engine* engine) override;

    PetrolEngine* engine_;

private:
    void refuel();
};
