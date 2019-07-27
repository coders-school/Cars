#pragma once
#include "PetrolEngine.hpp"
#include "Car.hpp"

class PetrolCar : virtual public Car
{
protected:    
    void refuel();
    PetrolEngine* engine_;
public:
    PetrolCar(PetrolEngine* engine);
    ~PetrolCar();
    void feed() override;
    void PetrolEngineChange(int, float, int);
    int getGear() const; 
    void setGear(int);
  
};

