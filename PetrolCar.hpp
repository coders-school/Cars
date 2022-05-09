#pragma once
#include <iostream>
#include <memory>
#include "Car.hpp"
#include "ElectricEngine.hpp"
#include "PetrolEngine.hpp"
#include "InvalidGear.hpp"

class PetrolCar : virtual public Car
{
public:
    PetrolCar(std::unique_ptr<PetrolEngine> engine);
    ~PetrolCar();
    void changeEngine(std::unique_ptr<PetrolEngine> engine) override;
    void changeEngine(std::unique_ptr<ElectricEngine> engine) override;
    void refill() override;
    void changeGear(int gear);

protected:
    void refuel();
    std::unique_ptr<PetrolEngine> engine_;
};
