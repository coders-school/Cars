#include "Car.hpp"
#include <iostream>
#include "ElectricCar.hpp"
#include "HybridCar.hpp"
#include "PetrolCar.hpp"

int main()
{
    Car* car;
    std::cout << std::endl << "OPEL" << std::endl;
    PetrolCar opel(new PetrolEngine(120, 1800, 6));
    car = &opel;
    car->accelerate(50);
    car->brake();
    // car->accelerate(-900);
    car->refill();
    // opel.changeGear(-1);
    // opel.changeEngine(new PetrolEngine(90, 1500, 4));

    std::cout << std::endl << "NISSAN" << std::endl;
    ElectricCar nissan(new ElectricEngine(130, 650));
    car = &nissan;
    car->refill();
    car->accelerate(80);
    car->turnLeft();
    // car->brake();
    nissan.changeEngine(new ElectricEngine(150, 700));

    std::cout << std::endl << "TOYOTA" << std::endl;
    HybridCar toyota(new PetrolEngine(80, 1400, 5), new ElectricEngine(100, 540));
    car = &toyota;
    car->accelerate(100);
    car->brake();
    car->refill();
    // toyota.changeEngine(new PetrolEngine(90, 1500, 4));
    // toyota.changeEngine(new ElectricEngine(120, 600));
}
