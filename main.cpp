#include <iostream>
#include "Car.hpp"
#include "ElectricCar.hpp"
#include "HybridCar.hpp"
#include "PetrolCar.hpp"

int main() {
    std::cout << std::endl
              << "OPEL" << std::endl;
    PetrolCar opel(std::make_unique<PetrolEngine>(120, 1800, 6));
    Car* car = &opel;
    car->accelerate(50);
    car->brake();
    car->accelerate(60);
    car->reFill();

    std::cout << std::endl
              << "NISSAN" << std::endl;
    ElectricCar nissan(std::make_unique<ElectricEngine>(130, 650));
    car = &nissan;
    car->reFill();
    car->accelerate(80);
    car->changeEngine(std::make_unique<ElectricEngine>(150, 700));  // Changing an engine during driving is not safe
    car->turnLeft();

    std::cout << std::endl
              << "TOYOTA" << std::endl;
    HybridCar toyota(std::make_unique<PetrolEngine>(80, 1400, 5), std::make_unique<ElectricEngine>(100, 540));
    car = &toyota;
    car->changeEngine(std::make_unique<ElectricEngine>(100, 600));
    car->changeEngine(std::make_unique<PetrolEngine>(90, 1600, 6));
    car->accelerate(100);
    car->brake();
    car->reFill();
}
