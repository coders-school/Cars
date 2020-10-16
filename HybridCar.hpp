#pragma once

#include "ElectricCar.hpp"
#include "ElectricEngine.hpp"
#include "PetrolCar.hpp"
#include "PetrolEngine.hpp"


class HybridCar : public PetrolCar, public ElectricCar {
public:
    HybridCar(std::shared_ptr<PetrolEngine>petrolEng, std::shared_ptr<ElectricEngine>electricEng);
    ~HybridCar();
    void restore() override;
    //void changeEngine(std::shared_ptr<PetrolEngine>);
    //void changeEngine(std::shared_ptr<ElectricEngine>);
    void changeEngine(std::shared_ptr<ElectricEngine>, std::shared_ptr<PetrolEngine>);

    ////int getPower() const override;
    int getPower() const;// override;
    int getBatteryCapacity() const;
    // void changeGear(int gear);
    // int getGears() const;
    float getCapacity() const;
    // int getCurrentGear() const;

};
