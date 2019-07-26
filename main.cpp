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
    car->accelerate(50);
    car->brake(60);
    car->accelerate(-900);
    opel.PetrolEngineChange(119, 1700, 5);
    car->feed();
    opel.setGear(4);
    opel.getGear();
    opel.setGear(7);
    

    std::cout << std::endl<< std::endl<< "NISSAN" << std::endl;
    ElectricCar nissan(new ElectricEngine(130, 650));
    car = &nissan;
    car->feed();
    car->accelerate(80);
    nissan.ElectricEngineChange(150,700);
    car->turnLeft();


    std::cout << std::endl << std::endl <<"TOYOTA" << std::endl;
    HybridCar toyota(new PetrolEngine(80, 1400, 5), new ElectricEngine(100, 540));
    car=&toyota;
    car->accelerate(100);
    car->brake(0);
    toyota.PetrolEngineChange(90, 1400, 6);
    toyota.ElectricEngineChange(100, 540);
    car->feed();
    std::cout<<" "<<std::endl;
 
}

