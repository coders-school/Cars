#pragma once

#include "Car.hpp"
#include "../engine/PetrolEngine.hpp"

class PetrolCar : virtual public Car
{
public:
    PetrolCar(PetrolEngine* engine);
    ~PetrolCar();

    void refuel();
    void changeGear(int gear);
    void restore() override;
    int getCurrentGear();
    
private:
    PetrolEngine* engine_;
};
