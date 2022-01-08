#pragma once
#include "PetrolEngine.hpp"
#include "Car.hpp"
#include <memory>


class PetrolCar : virtual public Car
{
public:
    PetrolCar(std::unique_ptr<PetrolEngine> engine);
    ~PetrolCar();

    int GetFuelLvl(){return fuelLevel_;}
    void changeGear(int gear){
        auto newGear = gear;
        engine_->changeGear(newGear);
    }
    
    void changeEngine(std::unique_ptr<PetrolEngine> pe);
    void refill() override;

private:
    void refuel();
    int fuelLevel_ = 15;
    std::unique_ptr<PetrolEngine> engine_;
};
