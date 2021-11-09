#include "Car.hpp"
#include "PetrolCar.hpp"
#include "ElectricCar.hpp"
#include "HybridCar.hpp"
#include <iostream>

int main()
{

    std::cout << std::endl << "OPEL" << std::endl;
    PetrolCar opel(new PetrolEngine(120, 1800, 6));
    Car* car = &opel;
    car->accelerate(50);
    car->brake();
    car->accelerate(-900);
    car->refill();
    // car->changeEngine(new PetrolEngine(150, 700, 7));

    std::cout << std::endl << "NISSAN" << std::endl;
    ElectricCar nissan(new ElectricEngine(130, 650));
    car = &nissan;
    car->refill();
    car->accelerate(80);
    // nissan.engine_ = new ElectricEngine(150, 700);  // Changing an engine during driving is not safe
    // car->changeEngine(new ElectricEngine(150, 700));
    car->turnLeft();

    std::cout << std::endl << "TOYOTA" << std::endl;
    HybridCar toyota(new PetrolEngine(80, 1400, 5), new ElectricEngine(100, 540));
    car = &toyota;
    car->accelerate(100);
    car->brake();
    car->refill();

    PetrolEngine pt(100, 2.0, 5);
    
    pt.changeGear(1);
    pt.changeGear(2);
    try {
        pt.changeGear(0);
    } catch(InvalidGear const& ig) {
        std::cout << ig.what() << '\n';
    }

}
