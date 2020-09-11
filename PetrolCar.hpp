#pragma once

#include "Car.hpp"
#include "PetrolEngine.hpp"

class PetrolCar : virtual public Car {
public:
    PetrolCar(PetrolEngine* engine);
    ~PetrolCar() override;
    void restore() override;
    void shiftGear(int gear);
private:
    PetrolEngine* engine_;
    void refuel();
};
