#include "PetrolCar.hpp"
#include "ElectricCar.hpp"
#include "HybridCar.hpp"
#include <iostream>

int main()
{
    Car* car = nullptr;
    std::cout << std::endl << "OPEL" << std::endl;
    PetrolCar opel(new PetrolEngine(120, 1800, 6));
    car = &opel;
    car->Accelerate(50);
    car->Brake(10);
    car->Accelerate(-900);
    car->feed();
    car->Velocity(35.5);

    std::cout << std::endl << "NISSAN" << std::endl;
    ElectricCar nissan(new ElectricEngine(130, 650));
    car = &nissan;
    car->feed();
    car->Accelerate(80);
    //nissan.engine_= new ElectricEngine(150, 700);  // Changing an engine during driving is not safe
    car->turnLeft();

    std::cout << std::endl << "TOYOTA" << std::endl;
    auto* pe = new PetrolEngine(80, 1400, 5);
    HybridCar toyota(pe, new ElectricEngine(100, 540));
    car = &toyota;
    car->Accelerate(100);
    car->Brake(10);
    car->feed();
}
