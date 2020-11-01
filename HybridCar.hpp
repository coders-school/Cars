#pragma once
#include <map>
#include <memory>
#include "ElectricCar.hpp"
#include "ElectricEngine.hpp"
#include "PetrolCar.hpp"
#include "PetrolEngine.hpp"

class HybridCar : public PetrolCar, public ElectricCar {
public:
    HybridCar(std::unique_ptr<PetrolEngine> petrolEng, std::unique_ptr<ElectricEngine> electricEng);
    ~HybridCar();
    void restore() override;
    void changeEngine(std::unique_ptr<ElectricEngine> newElectricEngine, std::unique_ptr<PetrolEngine> newPetrolEngine);
    void changeGear(int gear) = delete;
    void changeDriveMode(int mode);

protected:
    std::map<int, std::string> driveMode_ = {{-1, "backward"}, {0, "handbrake"}, {1, "forward"}};
    int currentMode_ = 0;
};
