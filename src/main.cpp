#include "Car.hpp"
#include "ElectricCar.hpp"
#include "HybridCar.hpp"
#include "InvalidGear.hpp"
#include "PetrolCar.hpp"
#include "PetrolEngine.hpp"

#include <iostream>

int main()
{
    Car* car = nullptr;
    std::cout << std::endl << "OPEL" << std::endl;
    PetrolCar opel(new PetrolEngine(120, 1800, 6));
    car = &opel;
    car->accelerate(50);
    car->brake();
    car->accelerate(-900);
    car->restore(); //car->refuel();

    std::cout << std::endl << "NISSAN" << std::endl;
    ElectricCar nissan(new ElectricEngine(130, 650));
    car = &nissan;
    car->restore(); //car->charge();
    car->accelerate(80);
    // nissan.engine_ = new ElectricEngine(150, 700);  // Changing an engine during driving is not safe
    car->turnLeft();

    std::cout << std::endl << "TOYOTA" << std::endl;
    HybridCar toyota(new PetrolEngine(80, 1400, 5), new ElectricEngine(100, 540));
    car = &toyota;
    car->accelerate(100);
    car->brake();
    car->restore(); 
    //car->charge();
    //car->refuel();

    PetrolEngine petrolEng{100, 50, 5};
    try {
        petrolEng.setGear(-1);
        petrolEng.setGear(0);
        petrolEng.setGear(1);
        petrolEng.setGear(-1);
    } catch (const InvalidGear& ex) {
        std::cout << ex.what() << "\n";
    }
}
