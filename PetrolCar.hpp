#pragma once

#include "Car.hpp"
#include "PetrolEngine.hpp"

class PetrolCar : virtual public Car {
public:
    PetrolCar(PetrolEngine* engine);

    void changeGear(int gear);

    // Override from Car
    ~PetrolCar() override;
    void restore() override;
    void changeEngine(Engine* engine) override;

    int getCurrentGear() const;
    int getPetrolPower() const;

protected:
    void refuel();

    PetrolEngine* petrolEngine_;
};
