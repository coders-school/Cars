#include "PetrolCar.hpp"
#include "ElectricCar.hpp"
#include "HybridCar.hpp"
#include <iostream>
#include <memory>

int main()
{
    std::cout << std::endl << "OPEL" << std::endl;
    PetrolCar opel(std::make_unique<PetrolEngine>(PetrolEngine(120, 1800, 6)));
    Car* car = &opel;
    car->accelerate(50);
    car->brake();
    car->accelerate(-900);
    car->refill();
    car->changeEngine(std::make_unique<PetrolEngine>(PetrolEngine(150, 700, 7)));

    std::cout << std::endl << "NISSAN" << std::endl;
    ElectricCar nissan(std::make_unique<ElectricEngine>(ElectricEngine(130, 650)));
    car = &nissan;
    car->refill();
    car->accelerate(80);
    //nissan.engine_ = new ElectricEngine(150, 700);  // Changing an engine during driving is not safe
    car->changeEngine(std::make_unique<ElectricEngine>(ElectricEngine(150, 700)));
    car->turnLeft();

    std::cout << std::endl << "TOYOTA" << std::endl;
    HybridCar toyota(std::make_unique<PetrolEngine>(PetrolEngine(80, 1400, 5)), std::make_unique<ElectricEngine>(ElectricEngine(100, 540)));
    car = &toyota;
    car->accelerate(100);
    car->brake();
    car->changeEngine(std::make_unique<ElectricEngine>(ElectricEngine(200, 800)));
    car->refill();
}
