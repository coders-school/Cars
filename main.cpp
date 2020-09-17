#include <iostream>

#include "PetrolCar.hpp"
#include "ElectricCar.hpp"
#include "HybridCar.hpp"

int main()
{
    Car* car = nullptr;

    std::cout << std::endl << "OPEL" << std::endl;
    PetrolCar opel(std::make_unique<PetrolEngine>(120, 1800, 6));
    // opel.accelerate(50);
    // opel.brake();
    // opel.accelerate(-900);
    // opel.refuel();
    car = &opel;
    car->accelerate(50);
    car->brake();
    car->accelerate(-900);
    car->restore();

    std::cout << std::endl << "NISSAN" << std::endl;
    ElectricCar nissan(std::make_unique<ElectricEngine>(130, 650));
    car = &nissan;
    car->restore();
    car->accelerate(80);
    car->brake();
    car->turnLeft();
    //nissan.engine_ = new ElectricEngine(150, 700);  // now it is throwing an error

    std::cout << std::endl << "TOYOTA" << std::endl;
    HybridCar toyota(std::make_unique<PetrolEngine>(80, 1400, 5), std::make_unique<ElectricEngine>(100, 540));
    car = &toyota;
    
    car->accelerate(100);
    car->brake();
    car->restore();

}
