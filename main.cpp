#include <iostream>
#include "Car.hpp"
#include "ElectricCar.hpp"
#include "HybridCar.hpp"
#include "PetrolCar.hpp"

int main() {
    std::cout << std::endl
              << "OPEL" << std::endl;
    PetrolCar opel(new PetrolEngine(120, 1800, 6));
    Car* car = &opel;
    car->accelerate(50);
    car->brake();
    car->accelerate(60);
    car->reFill();

    std::cout << std::endl
              << "NISSAN" << std::endl;
    ElectricCar nissan(new ElectricEngine(130, 650));
    car = &nissan;
    car->reFill();
    car->accelerate(80);
    car->changeEngine(new ElectricEngine(150, 700));  // Changing an engine during driving is not safe
    car->turnLeft();

    std::cout << std::endl
              << "TOYOTA" << std::endl;
    HybridCar toyota(new PetrolEngine(80, 1400, 5), new ElectricEngine(100, 540));
    car = &toyota;
    car->changeEngine(new ElectricEngine(100, 600));
    car->changeEngine(new PetrolEngine(90, 1600, 6));
    car->accelerate(100);
    car->accelerate(-1100);
    car->brake();
    car->reFill();
}
