#pragma once
#include <memory>
#include "Car.hpp"
#include "PetrolEngine.hpp"

class PetrolCar : virtual public Car {
public:
    PetrolCar(std::unique_ptr<PetrolEngine> petrolEngine);
    ~PetrolCar();

    void changeEngine(std::unique_ptr<PetrolEngine> petrolEngine);
    void refill() override;
    void changeGear(int);

private:
    void refuel();
    std::unique_ptr<PetrolEngine> petrolEngine_;
};
