#pragma once

#include "Car.hpp"
#include "PetrolEngine.hpp"

class PetrolCar : virtual public Car {
public:
    PetrolCar(PetrolEngine* engine);
    ~PetrolCar();
    void restore() override;

    void changeGear(int gear);
    int getGear() const;

private:
    PetrolEngine* engine_;
    void refuel();
};
