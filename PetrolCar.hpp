#pragma once
#include "Car.hpp"
#include "PetrolEngine.hpp"

class PetrolCar : virtual public Car {
public:
    PetrolCar(PetrolEngine* engine);
    virtual ~PetrolCar();
    void refill() override;

private:
    void refuel();
    PetrolEngine* engine_;
};
