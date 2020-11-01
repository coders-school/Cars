#pragma once
#include "PetrolEngine.hpp"
#include "Car.hpp"
#include <memory>

class PetrolCar : virtual public Car
{
public:
    PetrolCar(std::unique_ptr<PetrolEngine> engine);
    ~PetrolCar();
    void restore() override;
    void changePetrolEngine(std::unique_ptr<PetrolEngine> newEngine);

protected:
    void refuel();
    std::unique_ptr<PetrolEngine> petrolEngine_;
};
