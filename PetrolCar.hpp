#pragma once
#include <memory>
#include <utility>
#include "PetrolEngine.hpp"
#include "Car.hpp"


class PetrolCar : virtual public Car
{
public:
    PetrolCar(std::unique_ptr<PetrolEngine> petrolEngine);
    ~PetrolCar();

    void changeEngine(std::unique_ptr<PetrolEngine> petrolEngine);
    void refill() override;

private:
    void refuel();
    //PetrolEngine* engine_;
    std::unique_ptr<PetrolEngine> engine_;
};
