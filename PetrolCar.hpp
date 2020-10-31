#pragma once
#include <memory>
#include "Car.hpp"
#include "PetrolEngine.hpp"

class PetrolCar : virtual public Car {
public:
    PetrolCar(std::unique_ptr<PetrolEngine> engine);
    ~PetrolCar();
    virtual void restore() override;
    void refuel();
    void printInfoEngine() const override;
    void changeEngine(std::unique_ptr<PetrolEngine> engine);
    int getGear();
    void showGear();
    void setGear(int gear);

private:
    std::unique_ptr<PetrolEngine> engine_;
};