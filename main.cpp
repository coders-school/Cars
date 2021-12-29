#include <iostream>
#include "Car.hpp"
#include "ElectricCar.hpp"
#include "HybridCar.hpp"
#include "PetrolCar.hpp"
#include <memory>

int main() {
    std::cout << std::endl
              << "OPEL" << std::endl;
    PetrolCar opel(std::make_unique<PetrolEngine>(120, 1800, 6));
    Car* car = &opel;
    car->setSpeed(50);
    car->brake();
    car->setSpeed(-900);
    car->refill();
    // car->changeEngine(new PetrolEngine(150, 700, 7));
    opel.changeGear(2);

    std::cout << std::endl
              << "NISSAN" << std::endl;
    ElectricCar nissan(std::make_unique<ElectricEngine>(130, 650));
    car = &nissan;
    car->refill();
    car->setSpeed(80);
    // nissan.engine_ = new ElectricEngine(150, 700);  // Changing an engine during driving is not safe
    // car->changeEngine(new ElectricEngine(150, 700));
    car->turnLeft();

    std::cout << std::endl
              << "TOYOTA" << std::endl;
    HybridCar toyota(std::make_unique<PetrolEngine>(80, 1400, 5), std::make_unique<ElectricEngine>(100, 540));
    car = &toyota;
    car->setSpeed(100);
    car->brake();
    car->refill();
    toyota.changeGear(2);

    std::cout << std::endl;
}
