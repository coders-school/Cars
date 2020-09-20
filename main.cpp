#include <iostream>
#include "ElectricCar.hpp"
#include "HybridCar.hpp"
#include "PetrolCar.hpp"

int main()
{
    Car* car;
    std::cout << std::endl
              << "OPEL" << std::endl;
    PetrolCar opel(new PetrolEngine(120, 1800, 6));
    car = &opel;

    car->accelerate(50);
    car->brake();
    try {
        opel.changeGear(GearBox::first);
        opel.changeGear(GearBox::second);
        opel.changeGear(GearBox::third);
        opel.changeGear(GearBox::fourth);
        opel.changeGear(GearBox::sixth);
    }
    catch (const std::logic_error& err) {
        std::cout << err.what() << "\n";
    }
    try {
        opel.changeGear(GearBox::second);
    }
    catch (const std::logic_error& err) {
        std::cout << err.what() << "\n";
    }
    try {
        car->accelerate(-900);
    }
    catch (const std::logic_error& err) {
        std::cout << err.what() << "\n";
    }
    opel.changePetrolEngine(new PetrolEngine(150, 700, 5));
    try {
        opel.changeGear(GearBox::first);
        opel.changeGear(GearBox::second);
        opel.changeGear(GearBox::third);
        opel.changeGear(GearBox::fourth);
        opel.changeGear(GearBox::fifth);
        opel.changeGear(GearBox::sixth);
    }
    catch (const std::logic_error& err) {
        std::cout << err.what() << "\n";
    }
    opel.refuel();

    std::cout << std::endl
              << "NISSAN" << std::endl;
    ElectricCar nissan(new ElectricEngine(130, 650));
    car = &nissan;
    nissan.charge();
    car->accelerate(80);
    nissan.changeElectricEngine(new ElectricEngine(150, 700));
    car->turnLeft();

    std::cout << std::endl
              << "TOYOTA" << std::endl;
    HybridCar toyota(new PetrolEngine(80, 1400, 5), new ElectricEngine(100, 540));
    car = &toyota;
    car->accelerate(100);
    toyota.changeElectricEngine(new ElectricEngine(150, 700));
    toyota.changePetrolEngine(new PetrolEngine(150, 700, 3));
    car->brake();
    toyota.charge();
    toyota.refuel();

    return 0;
}
