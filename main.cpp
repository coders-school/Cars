
#include <iostream>

#include "ElectricCar.hpp"
#include "HybridCar.hpp"
#include "PetrolCar.hpp"

int main() {
    Car *car = nullptr;
    std::cout << std::endl
              << "OPEL" << std::endl;
    PetrolCar opel(new PetrolEngine(120, 1800, 6));
    car = &opel;
    car->accelerate(50);
    car->brake();
    try {
        car->accelerate(-900);
    } catch (std::range_error &err) {
        std::cerr << err.what() << '\n';
    }
    car->restore();

    std::cout << std::endl
              << "NISSAN" << std::endl;
    ElectricCar nissan(new ElectricEngine(130, 650));
    car = &nissan;

    car->restore();
    car->accelerate(80);
    //car->engine_ = new ElectricEngine(150, 700);  // Changing an engine during driving is not safe

    car->turnLeft();

    std::cout << std::endl
              << "TOYOTA" << std::endl;
    HybridCar toyota(new PetrolEngine(80, 1400, 5), new ElectricEngine(100, 540));
    car = &toyota;
    car->accelerate(100);
    car->brake();

    car->restore();
}
