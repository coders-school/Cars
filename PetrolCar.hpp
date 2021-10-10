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
    void changeEngine(std::unique_ptr<PetrolEngine> engine) override {engine_ = std::move(engine);};
    PetrolEngine* getEngine() const {return engine_.get();};
protected:
    std::unique_ptr<PetrolEngine> engine_;   
private:
    void refuel();

};

