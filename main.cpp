#include "Car.hpp"
#include "ElectricCar.hpp"
#include "PetrolCar.hpp"
#include "HybridCar.hpp"
#include <iostream>

int main()
{
    Car* car;
    std::cout << std::endl << "OPEL" << std::endl;
    PetrolCar opel(new PetrolEngine(120, 1800, 6));
    // opel.accelerate(50);
    // opel.brake();
    // opel.accelerate(-900);
    // opel.refill();
    car = &opel;
    car->accelerate(50);
    car->brake();
    car->accelerate(-900);
    car->refill();
    // (*car).changeGear(5);
    // opel.changeGear(5);
    // opel.changeGear(-1);
    opel.changeEngine(new PetrolEngine(90, 1500, 4));



    std::cout << std::endl << "NISSAN" << std::endl;
    ElectricCar nissan(new ElectricEngine(130, 650));
    // nissan.refill();
    // nissan.accelerate(80);
    // // nissan.engine_ = new ElectricEngine(150, 700);  // Changing an engine during driving is not safe
    // nissan.turnLeft();
    car = &nissan;
    car->refill();
    car->accelerate(80);
    car->turnLeft();
    // nissan.changeEngine(new ElectricEngine(150, 700));

  

    std::cout << std::endl << "TOYOTA" << std::endl;
    HybridCar toyota(new PetrolEngine(80, 1400, 5), new ElectricEngine(100, 540));
    car = &toyota;
    // toyota.accelerate(100);
    // toyota.brake();
    // toyota.refill();
    car->accelerate(100);
    car->brake();
    car->refill();
    // toyota.changeEngine(new PetrolEngine(90, 1500, 4));
}
