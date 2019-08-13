#pragma once
#include "PetrolEngine.hpp"
#include "Car.hpp"
#include "ExceptionCar.hpp"

class PetrolCar : virtual public Car
{
protected:
    void refuel();
public:
    PetrolCar(PetrolEngine* engine, int maxSpeed);
    ~PetrolCar();
    void feed() override;
    void changeGear(int gear);
    int getGear() const;
    int getCurrentGear() const;
private:
    PetrolEngine* engine_;
 

    
};

