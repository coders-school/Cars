#include <iostream>
#include "ElectricCar.hpp"
#include "HybridCar.hpp"
#include "InvalidGear.hpp"
#include "PetrolCar.hpp"

#include "PetrolEngine.hpp"

int main() {
    Car* car = nullptr;
    std::cout << std::endl
              << "OPEL" << std::endl;
    PetrolCar opel(std::make_shared<PetrolEngine>(120, 1800, 6));
    car = &opel;
    car->accelerate(50);
    car->brake();
    car->accelerate(-900);
    //car->refuel();
    car->restore();

    std::cout << std::endl
              << "NISSAN" << std::endl;
    ElectricCar nissan(std::make_shared<ElectricEngine>(130, 650));
    car = &nissan;
    //car->charge();
    car->restore();
    car->accelerate(80);
    //car->engine_ = new ElectricEngine(150, 700);  // Changing an engine during driving is not safe
    car->turnLeft();

    std::cout << std::endl
              << "TOYOTA" << std::endl;
    HybridCar toyota(std::make_shared<PetrolEngine>(80, 1400, 5), std::make_shared<ElectricEngine>(100, 540));
    car = &toyota;
    car->accelerate(100);
    car->brake();
    //car->charge();
    //car->refuel();
    car->restore();

    ////
    /*PetrolEngine petrolEngine(100, 50, 5);
    try {
        petrolEngine.changeGear(-1);
        petrolEngine.changeGear(0);
        petrolEngine.changeGear(2);
        petrolEngine.changeGear(-1);
    } catch (const InvalidGear& ex) {
        std::cout << ex.what() << '\n';
    }*/
}
