#include "PetrolCar.hpp"
#include "ElectricCar.hpp"
#include "HybridCar.hpp"
#include <iostream>

int main()
{
    std::cout << std::endl << "OPEL" << std::endl;
    PetrolCar opel(new PetrolEngine(120, 1800, 6));
    opel.accelerate(50);
    opel.brake();
    opel.accelerate(-900);
    opel.changePetrolEngine(new PetrolEngine(150, 700, 5));  
    opel.refuel();

    std::cout << std::endl << "NISSAN" << std::endl;
    ElectricCar nissan(new ElectricEngine(130, 650));
    nissan.charge();
    nissan.accelerate(80);
    nissan.changeElectricEngine(new ElectricEngine(150, 700)); 
    nissan.turnLeft();

    std::cout << std::endl << "TOYOTA" << std::endl;
    HybridCar toyota(new PetrolEngine(80, 1400, 5), new ElectricEngine(100, 540));
    toyota.accelerate(100);
    toyota.changeElectricEngine(new ElectricEngine(150, 700)); 
    toyota.changePetrolEngine(new PetrolEngine(150, 700, 3)); 
    toyota.brake();
    toyota.charge();
    toyota.refuel();
}
