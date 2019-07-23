#include "HybridCar.hpp"
#include <iostream>

HybridCar::HybridCar(PetrolEngine* petrolEng, ElectricEngine* electricEng)
    : PetrolCar(petrolEng)
    , ElectricCar(electricEng)
{
    std::cout << __FUNCTION__ << std::endl;
}

HybridCar::~HybridCar()       {std::cout << __FUNCTION__ << std::endl; }
void HybridCar::feed() {
    PetrolCar::feed();
    ElectricCar::feed();
 }

void HybridCar::changeEngine(Engine *engine) {

    if (velocity != 0)
        throw std::logic_error( "Car is moving now! Engine exchange impossible ");
    
    ElectricEngine* engineE;
    engineE = dynamic_cast<ElectricEngine*>(engine);
    if (engineE != nullptr)
        ElectricCar::changeEngine(engine);

    PetrolEngine* engineP;
    engineP = dynamic_cast<PetrolEngine*>(engine);
    if (engineP != nullptr)
        PetrolCar::changeEngine(engine);
}
