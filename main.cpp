#include "ElectricCar.hpp"
#include "HybridCar.hpp"
#include "PetrolCar.hpp"

#include <iostream>

int main() {
    Car* car = nullptr;
    std::cout << std::endl
              << "OPEL" << std::endl;
    PetrolCar opel(new PetrolEngine(120, 1800, 6));
    car = &opel;
    car->accelerate(100);
    try {
        car->accelerate(50);
    } catch (AccelerateToLoweSpeedError& speed) {
        std::cerr << speed.what() << "\n";
    }
    car->brake(50);
    try {
        car->accelerate(900);
    } catch (ToHighSpeedError& speed) {
        std::cerr << speed.what() << "\n";
    }
    car->setGear(4);
    car->restore();
    try {
        opel.setGear(-1);

    } catch (InvalidGearError& currentGear_) {
        std::cerr << currentGear_.what() << "\n";
    }

    std::cout << std::endl
              << "NISSAN" << std::endl;
    ElectricCar nissan(new ElectricEngine(130, 650));
    car = &nissan;
    car->restore();
    car->accelerate(80);
    try {
        car->brake(100);
    } catch (BrakeToHigherSpeedError& speed) {
        std::cerr << speed.what() << "\n";
    }
    car->setGear(4);
    car->changeEngine(new ElectricEngine(150, 700));
    car->setSpeed(0);
    car->changeEngine(new ElectricEngine(150, 700));
    car->turnLeft();

    std::cout << std::endl
              << "TOYOTA" << std::endl;
    HybridCar toyota(new PetrolEngine(80, 1400, 5), new ElectricEngine(100, 540));
    car = &toyota;
    try {
        car->accelerate(-100);
    } catch (ToLowSpeedError& speed) {
        std::cerr << speed.what() << "\n";
    }
    try {
        car->brake(50);
    } catch (BrakeToHigherSpeedError& speed) {
        std::cerr << speed.what() << "\n";
    }
    car->restore();
}
