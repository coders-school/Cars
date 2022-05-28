#include "HybridCar.hpp"

HybridCar::HybridCar(std::shared_ptr<PetrolEngine> petrolEng, std::shared_ptr<ElectricEngine> electricEng)
    : ElectricCar(electricEng)
    , PetrolCar(petrolEng)
{std::cout << __FUNCTION__ << std::endl;}

HybridCar::~HybridCar() {std::cout << __FUNCTION__ << std::endl;}
void HybridCar::refill() {
    ElectricCar::refill();
    PetrolCar::refill();
}