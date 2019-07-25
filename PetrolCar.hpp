#pragma once
#include "PetrolEngine.hpp"
#include "Car.hpp"

class PetrolCar : virtual public Car
{
protected:
     void refuel();
 
public:
    PetrolCar(PetrolEngine *engine);
    PetrolCar()= default;
    ~PetrolCar();
    void addEnergy() override;
   
   int getGear();
   void setGear(int value);

    PetrolEngine *engine_;
};
