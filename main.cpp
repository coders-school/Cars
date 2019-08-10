#include "PetrolCar.hpp"
#include "ElectricCar.hpp"
#include "HybridCar.hpp"
#include <iostream>
#include <assert.h>
bool isCorrectVelocity(Car& car)
{
    if(car.getVelocity()>220 || car.getVelocity()<0)
        return 0;
    return 1;
}
int main()
{
    Car* car;
    std::cout << std::endl << "OPEL" << std::endl;
    PetrolCar opel(new PetrolEngine(120, 1800, 6));
    car = &opel;
    car->accelerate(10);
    assert(isCorrectVelocity(*car));
    car->accelerate(10);
    assert(isCorrectVelocity(*car));
    car->accelerate(70);
    assert(isCorrectVelocity(*car));
    car->accelerate(60);
    assert(isCorrectVelocity(*car));
    car->accelerate(1);
    assert(isCorrectVelocity(*car));
    car->accelerate(-390);
    assert(isCorrectVelocity(*car));
    opel.changeEngine(120, 1500, 5);
    car->brake();
    opel.changeEngine(120, 1500, 5);
    car->accelerate(-900);
    car->feed();

    std::cout << std::endl << "NISSAN" << std::endl;
    ElectricCar nissan(new ElectricEngine(130, 650));
    car = &nissan;
    car->feed();
    car->accelerate(80);
    nissan.changeEngine(150, 750);
    car->turnLeft();
    std::cout << std::endl << "TOYOTA" << std::endl;
    HybridCar toyota(new PetrolEngine(80, 1400, 5), new ElectricEngine(100, 540));
    car = &toyota;
    car->accelerate(100);
    car->brake();
    car->feed();
}
