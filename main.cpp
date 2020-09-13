#include <iostream>

#include "Car.hpp"
#include "ElectricCar.hpp"
#include "HybridCar.hpp"
#include "InvalidGear.hpp"
#include "PetrolCar.hpp"

int main()
{

    std::cout << std::endl << "OPEL" << std::endl;
    PetrolCar opel(new PetrolEngine(120, 1800, 6));
    Car* car = &opel;
    car->accelerate(50);
    car->brake();
    car->accelerate(-900);
    car->restore();

    std::cout << std::endl << "NISSAN" << std::endl;
    ElectricCar nissan(new ElectricEngine(130, 650));
    car = &nissan;
    car->restore();
    car->accelerate(80);
    car->changeEngine(new ElectricEngine(150, 700));
    car->turnLeft();

    std::cout << std::endl << "TOYOTA" << std::endl;
    HybridCar toyota(new PetrolEngine(80, 1400, 5), new ElectricEngine(100, 540));
    car = &toyota;
    car->accelerate(100);
    car->brake();
    car->restore();
    car->restore();
}
