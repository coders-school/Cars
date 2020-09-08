#pragma once
#include "Car.hpp"
#include "PetrolEngine.hpp"

class PetrolCar : virtual public Car {
public:
    PetrolCar(PetrolEngine* engine);
    ~PetrolCar();
    void restore() override;  // Car
    PetrolEngine* getPetrol() const { return engine_; };

protected:
    void refuel();

private:
    PetrolEngine* engine_;
};
