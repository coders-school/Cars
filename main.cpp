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
    car->brake(42);
    car->accelerate(-900);
    car->feed();
    try
    {
        car->changeGear(7);
    }
    catch(GearChangeFailure FirstFailure)
    {
        std::cout << "No such gear! Available gears: from -1 to 5" << std::endl;
    }
    try
    {
        car->changeGear(1);
        car->changeGear(2);
        car->changeGear(3);
        car->changeGear(4);
        car->changeGear(5);
        car->changeGear(-1);
    }
    catch(GearChangeFailure InvalidGear)
    {
        std::cout << "Can't change gear 5 to reverse!" << std::endl;
    }  

    std::cout << std::endl << "NISSAN" << std::endl;
    ElectricCar nissan(new ElectricEngine(130, 650));
    car = &nissan;
    car->feed();
    car->accelerate(80);
    //nissan.engine_= new ElectricEngine(150, 700);  // Changing an engine during driving is not safe
    car->turnLeft();

    std::cout << std::endl << "TOYOTA" << std::endl;
    auto* pe = new PetrolEngine(80, 1400, 5);
    HybridCar toyota(pe, new ElectricEngine(100, 540));
    car = &toyota;
    car->accelerate(100);
    car->brake(10);
    car->feed();
}
