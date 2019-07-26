#include "PetrolCar.hpp"
#include "ElectricCar.hpp"
#include "HybridCar.hpp"
#include <iostream>

int main()
{
    Car* car = nullptr;
    std::cout << std::endl << "OPEL" << std::endl;
    auto* PE = new PetrolEngine(120, 1800, 6);
    PetrolCar opel(PE);
    car = &opel;
    car->Vmax = 200;
    car->accelerate(50);
    PE->changeGear(6);
    car->brake(1);
    car->accelerate(-900);
    car->feed();
    car->brake(20);
    opel.changePetrolEngine(new PetrolEngine(210,2000,6));

    std::cout << std::endl << "NISSAN" << std::endl;
    ElectricCar nissan(new ElectricEngine(130, 650));
    car = &nissan;
    car->feed();
    car->Vmax = 240;
    car->accelerate(80);
    nissan.changeElectricEngine(new ElectricEngine(200, 850));
    car->brake(30);
    car->turnLeft();

    std::cout << std::endl << "TOYOTA" << std::endl;
    auto* pe = new PetrolEngine(80, 1400, 5);
    HybridCar toyota(pe, new ElectricEngine(100, 540));
    car = &toyota;
    car->Vmax = 220;
    car->accelerate(300);
    car->brake(1);
    car->feed();
    pe->changeGear(1);
    toyota.changeElectricEngine(new ElectricEngine(200, 340));
    toyota.changePetrolEngine(new PetrolEngine(400,4500,7));
}
