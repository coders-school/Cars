#include "PetrolCar.hpp"
#include "ElectricCar.hpp"
#include "HybridCar.hpp"
#include <iostream>
#include <cassert>

int main()
{
    Car* car = nullptr;
    std::cout << std::endl << "OPEL" << std::endl;
    PetrolCar opel(new PetrolEngine(120, 1800, 6), 230);
    car = &opel;
    try
    {
        car->accelerate(80);
        car->accelerate(-900);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    assert(car->getVelocity() == 80);
    car->brake();
    assert(car->getVelocity() == 0);
    try
    {
        opel.changeGear(4);
        opel.changeGear(8);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    assert(opel.getCurrentGear() == 4);
    car->feed();
    car->turnRight();

    std::cout << std::endl << "NISSAN" << std::endl;
    ElectricCar nissan(new ElectricEngine(130, 650), 210);
    car = &nissan;
    try
    {
        car->accelerate(50);
        car->accelerate(300);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    assert(car->getVelocity() == 50);
    car->brake();
    assert(car->getVelocity() == 0);
    //nissan.engine_ = new ElectricEngine(150, 700);  // /home/natalia/CPP_training/Cars/ElectricCar.hpp:14:21: note: declared private here: ElectricEngine* engine_;
    car->feed();
    car->turnLeft();

    std::cout << std::endl << "TOYOTA" << std::endl;
    auto* pe = new PetrolEngine(80, 1400, 5);
    HybridCar toyota(pe, new ElectricEngine(100, 540), 220);
    car = &toyota;
    try
    {
        car->accelerate(20);
        car->accelerate(300);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    assert(car->getVelocity() == 20);
    car->brake();
    assert(car->getVelocity() == 0);
    try
    {
        toyota.changeGear(-1);
        toyota.changeGear(-3);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    assert(toyota.getCurrentGear() == -1);
    car->feed();
    car->turnRight();
}
