#pragma once

#include "Car.hpp"
#include "PetrolEngine.hpp"

class PetrolCar : virtual public Car {
private:
    std::unique_ptr<PetrolEngine> engine_;
    void refuel();
public:
    PetrolCar(std::unique_ptr<PetrolEngine> engine);
    ~PetrolCar();
    void restore() override;
    void changeEngine(std::unique_ptr<PetrolEngine> newEngine); 
    
    PetrolEngine* getEngine() const { return engine_.get(); }
};
