
#pragma once
#include "Car.hpp"
#include "PetrolEngine.hpp"

class PetrolCar : virtual public Car {
private:
    PetrolEngine* engine_;
public:
    PetrolCar(PetrolEngine* engine);
    ~PetrolCar();
    void refuel();
};
