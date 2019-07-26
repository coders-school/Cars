#include "PetrolCar.hpp"
#include "ElectricCar.hpp"
#include "HybridCar.hpp"
#include <iostream>
// YOO
//siema
int main()
{
    Car* car = nullptr;
    std::cout << std::endl << "OPEL" << std::endl;
    PetrolCar opel(new PetrolEngine(120, 1800, 6));
    car = &opel;
    car->accelerate(50);
    car->brake();
    car->accelerate(-900);
    car->feed();

    std::cout << std::endl << "NISSAN" << std::endl;
    ElectricCar nissan(new ElectricEngine(130, 650));
    car = &nissan;
    car->feed();
    car->accelerate(80);
   
    delete nissan.engine_;
    nissan.engine_ = new ElectricEngine(150, 700);  // Changing an engine during driving is not safe
    car->turnLeft();
    
    std::cout << std::endl << "TOYOTA" << std::endl;
    auto* pe = new PetrolEngine(80, 1400, 5);
    HybridCar toyota(pe, new ElectricEngine(100, 540));
    car = &toyota;
    car->accelerate(100);
    car->brake();
    car->feed();
    
    
}
