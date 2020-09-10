#pragma once

#include "Car.hpp"
#include "PetrolEngine.hpp"

class PetrolCar : virtual public Car {
public:
    PetrolCar(PetrolEngine* engine);
    ~PetrolCar();
    void refill() override;
    void changeEngine(Engine* petrolEngine) override;

protected:
    void refuel();
    PetrolEngine* petrolEngine_;
};
