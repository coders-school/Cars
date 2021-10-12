#pragma once
#include <memory>
#include "PetrolEngine.hpp"
#include "Car.hpp"


class PetrolCar : virtual public Car
{
public:
    PetrolCar(std::unique_ptr<PetrolEngine> petrolEngine);
    ~PetrolCar();
    void reFill() override {refuel();};
    virtual void changeEngine(std::unique_ptr<PetrolEngine> engine) override;
    PetrolEngine* getEngine() const {return engine_.get();};
    int getFuel(){return fuel_;};
protected:
    std::unique_ptr<PetrolEngine> engine_;
    int fuel_;   
private:
    void refuel();

};