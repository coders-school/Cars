#include "PetrolCar.hpp"
#include "ElectricCar.hpp"
#include "HybridCar.hpp"
#include <iostream>

int main()
{
    //test commit
    Car* car = nullptr;
    std::cout << std::endl << "OPEL" << std::endl;
    PetrolCar opel(new PetrolEngine(120, 1800, 6));
    car = &opel;
    car->accelerate(50);
    opel.set_petrol_engine(100,1500,5);
    car->brake(50);
    opel.set_petrol_engine(100,1500,5);
    car->accelerate(-900);
    car->feed();

    std::cout << std::endl << "NISSAN" << std::endl;
    ElectricCar nissan(new ElectricEngine(130, 650));
    car = &nissan;
    car->feed();
    car->accelerate(80);
    car->get_speed();
    car->brake(80);
    car->get_speed();
    nissan.set_electric_engine(150,700);
    car->turnLeft();

    std::cout << std::endl << "TOYOTA" << std::endl; 
    HybridCar toyota(new PetrolEngine(80, 1400, 5), new ElectricEngine(100, 540));
    car = &toyota;
    toyota.set_petrol_engine(100,1500,6);
    car->accelerate(100);
    car->brake(10);
    car->feed();
}
