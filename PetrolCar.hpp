#pragma once
#include "Car.hpp"
#include "PetrolEngine.hpp"

class PetrolCar : virtual public Car {
public:
    PetrolCar(PetrolEngine* petrolEngine);
    ~PetrolCar();

    void changeEngine(PetrolEngine* petrolEngine);
    void refill() override;
    void changeGear(int);

private:
    void refuel();
    PetrolEngine* petrolEngine_;
};
