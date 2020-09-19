#pragma once

#include <memory>

#include "Car.hpp"
#include "Engine.hpp"
#include "PetrolEngine.hpp"

class PetrolCar : virtual public Car {
public:
    PetrolCar(std::unique_ptr<PetrolEngine> engine);
    ~PetrolCar();
    void restore() override;
    void changeEngine(std::unique_ptr<PetrolEngine> engine);
    int getPower();
    float getCapacity();
    int getGears();
    void setGear(int gear);
    int getCurrentGear();
    std::unique_ptr<PetrolEngine> getEngine();

protected:
    void refuel();
    std::unique_ptr<PetrolEngine> engine_;
};
