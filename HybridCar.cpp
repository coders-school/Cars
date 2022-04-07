#include "HybridCar.hpp"
#include <iostream>

HybridCar::HybridCar(PetrolEngine *petrolEng, ElectricEngine *electricEng)
    : ElectricCar(electricEng), PetrolCar(petrolEng)
{
    std::cout << __FUNCTION__ << std::endl;
}

HybridCar::~HybridCar() { std::cout << __FUNCTION__ << std::endl; }

void HybridCar::refill()
{
    ElectricCar::refill();
    PetrolCar::refill();
    std::cout << __FUNCTION__ << std::endl;
}

void HybridCar::changeEngine(Engine *engine)
{
    ElectricEngine *ee{nullptr};
    PetrolEngine *pe{nullptr};

    ee = dynamic_cast<ElectricEngine *>(engine);
    pe = dynamic_cast<PetrolEngine *>(engine);

    if (ee != nullptr)
    {
        delete ElectricCar::engine_;
        ElectricCar::engine_ = ee;
        std::cout << __FUNCTION__ << std::endl;
    }
    else if (pe != nullptr)
    {
        delete PetrolCar::engine_;
        PetrolCar::engine_ = pe;
        std::cout << __FUNCTION__ << std::endl;
    }
}
