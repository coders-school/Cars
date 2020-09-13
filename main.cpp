#include <iostream>
#include "ElectricCar.hpp"
#include "HybridCar.hpp"
#include "PetrolCar.hpp"

int main() {
    Car* car = nullptr;
    std::cout << std::endl
              << "OPEL" << std::endl;
    PetrolCar opel(new PetrolEngine(120, 1800, 6));
    car = &opel;
    car->accelerate(100);
    car->accelerate(50);
    car->brake(50);
    car->accelerate(900);
    //car->setGear(4);
    car->restore();
    opel.setGear(-1);

    std::cout << std::endl
              << "NISSAN" << std::endl;
    ElectricCar nissan(new ElectricEngine(130, 650));
    car = &nissan;
    car->restore();
    car->accelerate(80);
    car->brake(100);
    car->changeEngine(new ElectricEngine(150, 700));
    car->turnLeft();

    std::cout << std::endl
              << "TOYOTA" << std::endl;
    HybridCar toyota(new PetrolEngine(80, 1400, 5), new ElectricEngine(100, 540));
    car = &toyota;
    car->accelerate(-100);
    car->brake(50);
    car->restore();
    car->restore();
}
