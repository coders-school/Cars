#pragma once
#include "Car.hpp"
#include "PetrolEngine.hpp"

class PetrolCar : virtual public Car {
public:
    PetrolCar(PetrolEngine* engine);
    ~PetrolCar();
    void restore() override;
    int getGear() const;
    void setGear(int);
    PetrolEngine* engine_;

private:
    void refuel();
};
