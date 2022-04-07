#include "HybridCar.hpp"
#include <iostream>

HybridCar::HybridCar(std::unique_ptr<Engine> petrolEng, std::unique_ptr<Engine> electricEng)
    : ElectricCar(std::move(electricEng)), PetrolCar(std::move(petrolEng))
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

void HybridCar::changeEngine(std::unique_ptr<Engine> engine)
{
    ElectricEngine *ee{nullptr};
    PetrolEngine *pe{nullptr};

    ee = dynamic_cast<ElectricEngine *>(engine.get());
    pe = dynamic_cast<PetrolEngine *>(engine.get());

    if (ee != nullptr)
    {
        ElectricCar::engine_ = std::move(engine);
        std::cout << __FUNCTION__ << std::endl;
    }
    else if (pe != nullptr)
    {
        PetrolCar::engine_ = std::move(engine);
        std::cout << __FUNCTION__ << std::endl;
    }
}
