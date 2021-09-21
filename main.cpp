#include "PetrolCar.hpp"
#include "ElectricCar.hpp"
#include "HybridCar.hpp"
#include "ElectricEngine.hpp"
#include "PetrolEngine.hpp"
#include "Car.hpp"
#include <iostream>

int main()
{
    Car* car;
    std::cout << std::endl << "OPEL" << std::endl;
    PetrolCar opel(new PetrolEngine(80, 1400, 5));
    car = &opel;
    car->accelerate(50);
    car->brake();
    car->accelerate(-900);
    opel.refuel();


    // std::cout << std::endl << "NISSAN" << std::endl;
    // ElectricCar nissan(new ElectricEngine(130, 650));
    // car = &nissan;
    // car->charge();
    // car->accelerate(80);
    // nissan.engine_ = new ElectricEngine(150, 700);  // Changing an engine during driving is not safe
    // nissan.turnLeft();

    // std::cout << std::endl << "TOYOTA" << std::endl;
    // HybridCar toyota(new PetrolEngine(80, 1400, 5), new ElectricEngine(100, 540));
    // toyota.accelerate(100);
    // toyota.brake();
    // toyota.charge();
    // toyota.refuel();
}
