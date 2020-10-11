#pragma once

#include "Car.hpp"
#include "ElectricEngine.hpp"

class ElectricCar : virtual public Car {
private:
    std::unique_ptr<ElectricEngine> engine_{};
    void charge();
public:
    ElectricCar(std::unique_ptr<ElectricEngine> engine);
    ~ElectricCar();
    void restore() override;
    void changeEngine(std::unique_ptr<ElectricEngine> newEngine);

    ElectricEngine* getEngine() const { return engine_.get(); }

};
