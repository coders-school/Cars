#pragma once

#include "Car.hpp"
#include "PetrolEngine.hpp"

class PetrolCar : virtual public Car {
public:
    PetrolCar(PetrolEngine* petrolEngine);
    void changeGear(int gear);

    //Override from car
    ~PetrolCar() override;
    void restore() override;
    void carInfo() override;
    uint16_t getEnginePower() const override;
    void changeEngine(Engine* engine) override;

protected:
    PetrolEngine* petrolEngine_;

private:
    void refuel();
};
