#pragma once
#include "PetrolEngine.hpp"
#include "Car.hpp"

class PetrolCar : virtual public Car
{
public:
    PetrolCar(PetrolEngine* petrolEngine);
    ~PetrolCar();
    void reFill() override {refuel();};
    virtual void changeEngine(PetrolEngine* engine) override {engine_ = engine;};
protected:
    PetrolEngine* engine_;   
private:
    void refuel();

};

