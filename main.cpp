#include <iostream>

#include "ElectricCar.hpp"
#include "HybridCar.hpp"
#include "PetrolCar.hpp"

int main() {
    Car* car = nullptr;

    std::cout << std::endl
              << "OPEL" << std::endl;
    PetrolCar opel(std::make_unique<PetrolEngine>(120, 1800, 6));
    car = &opel;
    car->accelerate(50);
    car->brake();

    try {
        car->accelerate(-900);

    } catch (const InvalidAccelerationException& err) {
        std::cerr << err.what() << '\n';
    }

    car->restore();

    std::cout << std::endl
              << "NISSAN" << std::endl;
    ElectricCar nissan(std::make_unique<ElectricEngine>(130, 650));
    car = &nissan;
    car->restore();
    car->accelerate(80);
    car->brake();
    car->turnLeft();
    //nissan.engine_ = new ElectricEngine(150, 700);  // now it is throwing an error

    std::cout << std::endl
              << "TOYOTA" << std::endl;
    HybridCar toyota(std::make_unique<PetrolEngine>(80, 1400, 5), std::make_unique<ElectricEngine>(100, 540));
    car = &toyota;

    car->accelerate(100);
    car->brake();
    car->restore();
}
