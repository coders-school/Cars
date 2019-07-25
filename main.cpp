#include "PetrolCar.hpp"
#include "ElectricCar.hpp"
#include "HybridCar.hpp"
#include <iostream>

int main()
{
    Car* car = nullptr;
    std::cout << std::endl << "OPEL" << std::endl;
    PetrolCar opel(new PetrolEngine(120, 1800, 6));
    car = &opel;
    car->accelerate(50);
    car->brake();
    car->accelerate(-900);
    car->feed();

    std::cout << std::endl << "NISSAN" << std::endl;
    ElectricCar nissan(new ElectricEngine(130, 650));
    car = &nissan;
    car->feed();
    car->accelerate(80);
    car->brake();
    nissan.changeEngine(new ElectricEngine(150, 700));  // Changing an engine during driving is not safe # DONE
    car->turnLeft();

    std::cout << std::endl << "TOYOTA" << std::endl;
    HybridCar toyota(new ElectricEngine(100, 540), new PetrolEngine(80, 1400, 5));
    car = &toyota;
    car->accelerate(100);
    car->brake();
    car->feed();
}
