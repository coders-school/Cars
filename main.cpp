#include <iostream>
#include "ElectricCar.hpp"
#include "HybridCar.hpp"
#include "InvalidGear.hpp"
#include "PetrolCar.hpp"
#include "PetrolEngine.hpp"

int main() {
    Car* car = nullptr;
    std::cout << std::endl
              << "OPEL" << std::endl;
    PetrolCar opel(std::make_shared<PetrolEngine>(120, 1800, 6));
    car = &opel;
    car->accelerate(50);
    car->brake();
    car->accelerate(-900);
    car->restore();

    std::cout << std::endl
              << "NISSAN" << std::endl;
    ElectricCar nissan(std::make_shared<ElectricEngine>(130, 650));
    car = &nissan;
    car->restore();
    car->accelerate(80);
    car->turnLeft();

    std::cout << std::endl
              << "TOYOTA" << std::endl;
    HybridCar toyota(std::make_shared<PetrolEngine>(80, 1400, 5), std::make_shared<ElectricEngine>(100, 540));
    car = &toyota;
    car->accelerate(100);
    car->brake();
    car->restore();
}
