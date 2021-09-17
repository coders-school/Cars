#pragma once

#include "ElectricCar.hpp"
#include "PetrolCar.hpp"
#include "../engine/PetrolEngine.hpp"
#include "../engine/ElectricEngine.hpp"

class HybridCar : public ElectricCar
                , public PetrolCar
{
public:
    HybridCar(PetrolEngine* petrolEng, ElectricEngine* electricEng);
    ~HybridCar();

    void restore() override;

private:
    PetrolEngine* petrolEngine_;
    ElectricEngine* electricEngine_;
};
