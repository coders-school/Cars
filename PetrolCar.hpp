#pragma once

#include "Car.hpp"
#include "PetrolEngine.hpp"

class PetrolCar : virtual public Car {
public:
    PetrolCar(PetrolEngine* engine);
    ~PetrolCar();
    void changeGear(int gear);

    //Override from car
    void restore() override;

protected:
    PetrolEngine* engine_;

private:
    void refuel();
};
