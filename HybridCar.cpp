#include "HybridCar.hpp"
#include <iostream>

HybridCar::HybridCar(PetrolEngine *petrolEng, ElectricEngine *electricEng)
    : PetrolCar(petrolEng), ElectricCar(electricEng)
{
    std::cout << __FUNCTION__ << std::endl;
}

HybridCar::~HybridCar() {std::cout << __FUNCTION__ << std::endl; }

void HybridCar::addEnergy() {refuel(), charge();}
void HybridCar::changeEngine(int pow, float cap, int g)
{
	PetrolCar::changeEngine(pow, cap, g);
}
void HybridCar::changeEngine(int pow, int bat)
{
	ElectricCar::changeEngine(pow, bat);
}