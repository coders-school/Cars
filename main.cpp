#include "PetrolCar.hpp"
#include "ElectricCar.hpp"
#include "HybridCar.hpp"
#include <iostream>
#include <cassert>

int main()
{
    Car* car = nullptr;
    std::cout << std::endl << "OPEL" << std::endl;
    PetrolCar opel(new PetrolEngine(120, 1800, 6));
    car = &opel;
    car->changeGear(1);
    assert(car->getCurrentGear() == "1");
    car->accelerate(50);
    assert(car->getCurrentSpeed() == 50);
    car->brake();
    assert(car->getCurrentSpeed() == 0);
    car->changeGear(0);
    assert(car->getCurrentGear() == "0");
    car->changeGear("R");
    assert(car->getCurrentGear() == "R");
    car->accelerate(-9);
    assert(car->getCurrentSpeed() == -9);
    car->feed();

    std::cout << std::endl << "NISSAN" << std::endl;
    ElectricCar nissan(new ElectricEngine(130, 650));
    car = &nissan;
    assert(car->getCurrentSpeed() == 0);
    car->feed();
    car->accelerate(80);
    assert(car->getCurrentSpeed() == 80);
    car->brake();
    assert(car->getCurrentSpeed() == 0);
    nissan.changeEngine(new ElectricEngine(150, 700));  // Changing an engine during driving is not safe # DONE
    car->turnLeft();

    std::cout << std::endl << "TOYOTA" << std::endl;
    HybridCar toyota(new ElectricEngine(100, 540), new PetrolEngine(80, 1400, 5));
    car = &toyota;
    car->accelerate(100);
    car->brake();
    car->feed();
}
