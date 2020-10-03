#pragma once

#include "ICar.hpp"
#include "ElectricEngine.hpp"
#include "PetrolEngine.hpp"
#include <memory>

class HybridCar :  public ICar
{
public:
    HybridCar(std::unique_ptr<IEngine> petrolEng, std::unique_ptr<IEngine> electricEng);
    ~HybridCar();
    void turnLeft() const override;
    void turnRight() const override;
    void brake() const override;
    void accelerate(Speed speed) const override;
    void charge() const ;
    void refuel() const ;
    void start_engine() const override;
    void stop_engine() const override;
    void fill() const override;




private:
    std::unique_ptr<IEngine> petrolEngine_ = nullptr;
    std::unique_ptr<IEngine> electricEngine_ = nullptr;
};

