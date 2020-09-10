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

protected:
    PetrolEngine* petrolEngine_;

private:
    void refuel();
};
