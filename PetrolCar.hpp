#pragma once
#include "Car.hpp"
#include "ElectricEngine.hpp"
#include "PetrolEngine.hpp"

class PetrolCar : virtual public Car {
public:
    PetrolCar(PetrolEngine* engine);
    ~PetrolCar();
    void restore() override;
    int getGear() const;
    void changeEngine(Engine* engine) override;
    //void setGear(int gear) override;
    void setGear(int gear);

private:
    void refuel();
    PetrolEngine* petrolEngine_;
};
