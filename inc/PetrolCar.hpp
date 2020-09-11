#pragma once

#include "Car.hpp"
#include "PetrolEngine.hpp"

class PetrolCar : virtual public Car {
public:
    PetrolCar(PetrolEngine* engine);
    ~PetrolCar();

    //override from Car
    void restore() override;
    void changeEngine(Engine* engine) override;
    int getEnginePower() const override { return petrolEngine_->getPower(); }

    void setGear(int gear) { petrolEngine_->setGear(gear); }
    int getGear() const { return petrolEngine_->getCurrentGear(); }

protected:
    PetrolEngine* petrolEngine_;

private:
    void refuel();
};
