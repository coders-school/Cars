#pragma once
#include "Car.hpp"
#include "ElectricEngine.hpp"
#include "PetrolEngine.hpp"
class HybridCar : public Car {
public:
    HybridCar(std::unique_ptr<PetrolEngine> petrolEng, std::unique_ptr<ElectricEngine> electricEng);
    virtual ~HybridCar();
   
   
    void powerSuply() override;
    const std::unique_ptr<ElectricEngine>& getElectricEngine();
    const std::unique_ptr<PetrolEngine>& getPetrolEngine();
    void changeEngine(int,float,int=0,int=0,int=0)override;

private:
    std::unique_ptr<PetrolEngine> petrolEngine_;
    std::unique_ptr<ElectricEngine> electricEngine_;
    
    void charge();
    void refuel();
};
