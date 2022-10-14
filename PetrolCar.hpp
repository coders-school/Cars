#pragma once

#include "PetrolEngine.hpp"
#include "Car.hpp"


class PetrolCar : virtual public Car {
public:
    PetrolCar(PetrolEngine* engine);

    ~PetrolCar() override;

    void changeEngine(PetrolEngine* pe) override;

    void refill() override;

private:
    void refuel();

    PetrolEngine* engine_;
};
