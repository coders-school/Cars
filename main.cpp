#include "Car.hpp"
#include "PetrolCar.hpp"
#include "ElectricCar.hpp"
#include "HybridCar.hpp"
#include <iostream>

int main()
{
    // Petrol Car
    std::cout << std::endl << "OPEL" << std::endl;
    PetrolCar opel(std::make_unique<PetrolEngine>(120, 1800, 6));
    // Car* car = &opel;
    // //car->accelerate(50);
    // car->brake();
    // //car->accelerate(-900);
    // //car->accelerate(900);
    // car->refill();
    // std::cout << "Speed = " << car->getSpeed();
    // car->changeEngine(std::make_unique<PetrolEngine>(150, 700, 7));
    opel.changeGear(-1);

    //car->changeEngine(std::make_unique<ElectricEngine>(150, 700));

    // Electric Car
    // std::cout << std::endl << "NISSAN" << std::endl;
    // ElectricCar nissan(std::make_unique<ElectricEngine>(130, 650));
    // Car* car = &nissan;
    // car->refill();
    // car->accelerate(80);
    // // nissan.engine_ = new ElectricEngine(150, 700);  // Changing an engine during driving is not safe
    // //car->changeEngine(std::make_unique<ElectricEngine>(150, 700));
    // car->changeEngine(std::make_unique<PetrolEngine>(150, 700, 7));
    // car->turnLeft();

    // Hybrid Car
    // std::cout << std::endl << "TOYOTA" << std::endl;
    // HybridCar toyota(std::make_unique<PetrolEngine>(80, 1400, 5), std::make_unique<ElectricEngine>(100, 540));
    // car = &toyota;
    // car->accelerate(100);
    // car->brake();
    // car->refill();

    // Petrol Engine
    // PetrolEngine pt(100, 2.0, 5);  
    // pt.changeGear(1);
    // pt.changeGear(2);
    // try {
    //     pt.changeGear(0);
    // } catch(InvalidGear const& ig) {
    //     std::cout << ig.what() << '\n';
    // }

}
