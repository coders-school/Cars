#pragma once
#include <memory>
#include "Car.hpp"
#include "ElectricEngine.hpp"

class ElectricCar : virtual public Car {
public:
    ElectricCar(std::unique_ptr<ElectricEngine> engine);
    ~ElectricCar();
    void reFill() override { charge(); };
    void changeEngine(std::unique_ptr<ElectricEngine> engine) override ;
    ElectricEngine* getEngine() const {return engine_.get();};

protected:
    std::unique_ptr<ElectricEngine> engine_;

private:
    void charge();
};
