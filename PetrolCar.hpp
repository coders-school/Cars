#pragma once

#include <iostream>
#include <memory>

#include "Car.hpp"
#include "PetrolEngine.hpp"

class PetrolCar : virtual public Car {
public:
    PetrolCar(std::shared_ptr<PetrolEngine> engine);
    ~PetrolCar();
    void restore() override;  // Car
    std::shared_ptr<PetrolEngine> getPetrolEngine() const { return engine_; };
    void setPetrolEngine(std::shared_ptr<PetrolEngine> engine) {
        if (this->getSpeed() != 0) {
            std::cout << "You cannot change engine during the ride!";
        } else {
            this->engine_ = engine;
        }
    }

protected:
    void refuel();

private:
    std::shared_ptr<PetrolEngine> engine_;
};
