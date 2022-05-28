#pragma once
#include <iostream>
#include <memory>
#include "Car.hpp"
#include "PetrolEngine.hpp"



class PetrolCar : virtual public Car
{
public:
    PetrolCar(std::shared_ptr<PetrolEngine> engine);
    ~PetrolCar();

    void changeEngine(std::shared_ptr<PetrolEngine> pe);
    void refill() override;

private:
    void refuel();
    std::shared_ptr<PetrolEngine> engine_;
};
