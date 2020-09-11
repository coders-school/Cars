#pragma once
#include <iostream>
#include <memory>

#include "Car.hpp"
#include "ElectricEngine.hpp"

class ElectricCar : virtual public Car {
public:
    ElectricCar(std::shared_ptr<ElectricEngine> engine);
    ~ElectricCar();
    void restore() override;  // Car
    std::shared_ptr<ElectricEngine> getElectricEngine() const { return engine_; };
    void setElectricEngine(std::shared_ptr<ElectricEngine> engine) {
        if (this->getSpeed() != 0) {
            std::cout << "You cannot change engine during the ride!" << '\n';
        } else {
            this->engine_ = engine;
        }
    }

protected:
    void charge();

private:
    std::shared_ptr<ElectricEngine> engine_;
};
