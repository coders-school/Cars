#pragma once
#include <memory>
#include "Car.hpp"
#include "ElectricEngine.hpp"

class ElectricCar : virtual public Car {
public:
    ElectricCar(std::unique_ptr<ElectricEngine> engine);
    ~ElectricCar();
    void reFill() override { charge(); };
    virtual void changeEngine(std::unique_ptr<ElectricEngine> engine) override ;
    ElectricEngine* getEngine() const {return engine_.get();};
    int getCharge(){return charge_;};

protected:
    std::unique_ptr<ElectricEngine> engine_;
    int charge_;

private:
    void charge();
};
