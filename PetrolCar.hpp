#pragma once
#include "PetrolEngine.hpp"
#include "Car.hpp"

class PetrolCar : virtual public Car
{
public:
    PetrolCar(PetrolEngine* petrolEngine);
    ~PetrolCar();
    void reFill() override {refuel();};
    void changeEngine(PetrolEngine* engine) override {engine_ = engine;};
    PetrolEngine* getEngine() const {return engine_;};
protected:
    PetrolEngine* engine_;   
private:
    void refuel();

};

