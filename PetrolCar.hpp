#pragma once

#include "Car.hpp"
#include "ElectricEngine.hpp"
#include "PetrolEngine.hpp"

class PetrolCar : virtual public Car {
public:
    PetrolCar(PetrolEngine* engine);
    ~PetrolCar();

    void restore() override;
    void changeEngine(Engine* engine) override;
    void setGear(int gear) override;
    int getGear() const;
    int getPetrolEnginePower() const;
    float getPetrolEngineCapacity() const;

private:
    void refuel();
    PetrolEngine* petrolEngine_;
};
