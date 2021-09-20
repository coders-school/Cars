#pragma once
#include "Car.hpp"
#include "ElectricEngine.hpp"
#include "PetrolEngine.hpp"
class HybridCar : public Car {
public:
    HybridCar(std::unique_ptr<PetrolEngine> petrolEng, std::unique_ptr<ElectricEngine> electricEng);
    virtual ~HybridCar();
    void turnLeft() override;
    void turnRight() override;
    void brake() override;
    void accelerate(int speed) override;
    void charge();
    void refuel();
 
 const std::unique_ptr<ElectricEngine>& getElectricEngine();
 const std::unique_ptr<PetrolEngine>& getPetrolEngine();   

private:
    std::unique_ptr<PetrolEngine> petrolEngine_;
    std::unique_ptr<ElectricEngine> electricEngine_;
};
