#include "Car.cpp"
#include "PetrolCar.hpp"
#include "ElectricCar.hpp"
#include "HybridCar.hpp"
#include <iostream>

int main()
{
    std::cout << std::endl << "OPEL" << std::endl;
    PetrolCar opel(new PetrolEngine(120, 1800, 6));
    Car* car = &opel;
    car->accelerate(80);
    car->brake();
    car->refill();
    car->turnLeft();
    car->turnRight();
    if(dynamic_cast<PetrolCar*>(car))
    {
        PetrolCar* petrolCar = dynamic_cast<PetrolCar*>(car);
        petrolCar->shift(3);
    }

    std::cout << std::endl << "NISSAN" << std::endl;
    ElectricCar nissan(new ElectricEngine(130, 650));
    car = &nissan;
    car->accelerate(80);
    car->brake();
    car->refill();
    car->turnLeft();
    car->turnRight();
    if(dynamic_cast<PetrolCar*>(car))
    {
        PetrolCar* petrolCar = dynamic_cast<PetrolCar*>(car);
        petrolCar->shift(3);
    }

    std::cout << std::endl << "TOYOTA" << std::endl;
    HybridCar toyota(new PetrolEngine(80, 1400, 5), new ElectricEngine(100, 540));
    car = &toyota;
    car->accelerate(100);
    car->brake();
    car->refill();
    car->turnLeft();
    car->turnRight();
    if(dynamic_cast<PetrolCar*>(car))
    {
        PetrolCar* petrolCar = dynamic_cast<PetrolCar*>(car);
        petrolCar->shift(3);
    }
}
